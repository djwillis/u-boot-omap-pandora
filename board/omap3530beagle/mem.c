/*
 * (C) Copyright 2008
 * Texas Instruments, <www.ti.com>
 *
 * Initial Code from:
 *     Richard Woodruff <r-woodruff2@ti.com>
 *     Syed Mohammed Khasim <khasim@ti.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/io.h>
#include <asm/arch/bits.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <command.h>

/* Only One NAND allowed on board at a time.
 * The GPMC CS Base for the same
 */
unsigned int nand_cs_base;
unsigned int boot_flash_base;
unsigned int boot_flash_off;
unsigned int boot_flash_sec;
unsigned int boot_flash_type;
volatile unsigned int boot_flash_env_addr;

/* help common/env_flash.c */
#ifdef ENV_IS_VARIABLE

uchar(*boot_env_get_char_spec) (int index);
int (*boot_env_init) (void);
int (*boot_saveenv) (void);
void (*boot_env_relocate_spec) (void);

/* 16 bit NAND */
uchar env_get_char_spec(int index);
int env_init(void);
int saveenv(void);
void env_relocate_spec(void);
extern char *env_name_spec;

u8 is_nand;

#endif /* ENV_IS_VARIABLE */

static u32 gpmc_m_nand[GPMC_MAX_REG] = {
	M_NAND_GPMC_CONFIG1,
	M_NAND_GPMC_CONFIG2,
	M_NAND_GPMC_CONFIG3,
	M_NAND_GPMC_CONFIG4,
	M_NAND_GPMC_CONFIG5,
	M_NAND_GPMC_CONFIG6, 0
};

/**************************************************************************
 * make_cs1_contiguous() - for es2 and above remap cs1 behind cs0 to allow
 *  command line mem=xyz use all memory with out discontinuous support
 *  compiled in.  Could do it at the ATAG, but there really is two banks...
 * Called as part of 2nd phase DDR init.
 **************************************************************************/
void make_cs1_contiguous(void)
{
	u32 size, a_add_low, a_add_high;

	size = get_sdr_cs_size(SDRC_CS0_OSET);
	size /= SZ_32M;		        /* find size to offset CS1 */
	a_add_high = (size & 3) << 8;	/* set up low field */
	a_add_low = (size & 0x3C) >> 2;	/* set up high field */
	__raw_writel((a_add_high | a_add_low), SDRC_CS_CFG);

}

/********************************************************
 *  mem_ok() - test used to see if timings are correct
 *             for a part. Helps in guessing which part
 *             we are currently using.
 *******************************************************/
u32 mem_ok(void)
{
	u32 val1, val2, addr;
	u32 pattern = 0x12345678;

	addr = OMAP34XX_SDRC_CS0;

	__raw_writel(0x0, addr + 0x400);  /* clear pos A */
	__raw_writel(pattern, addr);	  /* pattern to pos B */
	__raw_writel(0x0, addr + 4);	  /* remove pattern off the bus */
	val1 = __raw_readl(addr + 0x400); /* get pos A value */
	val2 = __raw_readl(addr);	  /* get val2 */

	if ((val1 != 0) || (val2 != pattern))  /* see if pos A value changed */
		return (0);
	else
		return (1);
}

/********************************************************
 *  sdrc_init() - init the sdrc chip selects CS0 and CS1
 *  - early init routines, called from flash or
 *  SRAM.
 *******************************************************/
void sdrc_init(void)
{
	/* only init up first bank here */
	do_sdrc_init(SDRC_CS0_OSET, EARLY_INIT);
}

/*************************************************************************
 * do_sdrc_init(): initialize the SDRAM for use.
 *  -code sets up SDRAM basic SDRC timings for CS0
 *  -optimal settings can be placed here, or redone after i2c
 *      inspection of board info
 *
 *  - code called ones in C-Stack only context for CS0 and a possible 2nd
 *      time depending on memory configuration from stack+global context
 **************************************************************************/

void do_sdrc_init(u32 offset, u32 early)
{

	/* reset sdrc controller */
	__raw_writel(SOFTRESET, SDRC_SYSCONFIG);
	wait_on_value(BIT0, BIT0, SDRC_STATUS, 12000000);
	__raw_writel(0, SDRC_SYSCONFIG);

	/* setup sdrc to ball mux */
	__raw_writel(SDP_SDRC_SHARING, SDRC_SHARING);

	/* SDRC_MCFG0 register */
	(*(unsigned int *) 0x6D000080) = 0x02584099; /* from Micron */

	/* SDRC_RFR_CTRL0 register */
	(*(unsigned int *) 0x6D0000a4) = 0x54601;    /* for 166M */

	/* SDRC_ACTIM_CTRLA0 register */
	(*(unsigned int *) 0x6D00009c) = 0xa29db4c6; /* for 166M */

	/* SDRC_ACTIM_CTRLB0 register */
	(*(unsigned int *) 0x6D0000a0) = 0x12214;    /* for 166M */

	/* Disble Power Down of CKE cuz of 1 CKE on combo part */
	(*(unsigned int *) 0x6D000070) = 0x00000081;

	/* SDRC_Manual command register */
	(*(unsigned int *) 0x6D0000a8) = 0x00000000; /* NOP command */
	(*(unsigned int *) 0x6D0000a8) = 0x00000001; /* Precharge command */
	(*(unsigned int *) 0x6D0000a8) = 0x00000002; /* Auto-refresh command */
	(*(unsigned int *) 0x6D0000a8) = 0x00000002; /* Auto-refresh command */

	/* SDRC MR0 register */
	(*(int *) 0x6D000084) = 0x00000032;	/*  Burst length = 4 */
	/* CAS latency = 3, Write Burst = Read Burst Serial Mode */

	/* SDRC DLLA control register */
	(*(unsigned int *) 0x6D000060) = 0x0000A;
	sdelay(0x20000);
}

void enable_gpmc_config(u32 *gpmc_config, u32 gpmc_base, u32 base, u32 size)
{
	__raw_writel(0, GPMC_CONFIG7 + gpmc_base);
	sdelay(1000);
	/* Delay for settling */
	__raw_writel(gpmc_config[0], GPMC_CONFIG1 + gpmc_base);
	__raw_writel(gpmc_config[1], GPMC_CONFIG2 + gpmc_base);
	__raw_writel(gpmc_config[2], GPMC_CONFIG3 + gpmc_base);
	__raw_writel(gpmc_config[3], GPMC_CONFIG4 + gpmc_base);
	__raw_writel(gpmc_config[4], GPMC_CONFIG5 + gpmc_base);
	__raw_writel(gpmc_config[5], GPMC_CONFIG6 + gpmc_base);
	/* Enable the config */
	__raw_writel((((size & 0xF) << 8) | ((base >> 24) & 0x3F) |
		      (1 << 6)), GPMC_CONFIG7 + gpmc_base);
	sdelay(2000);
}

/*****************************************************
 * gpmc_init(): init gpmc bus
 * Init GPMC for x16, MuxMode (SDRAM in x32).
 * This code can only be executed from SRAM or SDRAM.
 *****************************************************/
void gpmc_init(void)
{
	/* putting a blanket check on GPMC based on ZeBu for now */
	u32 mux = 0, mwidth;
	u32 *gpmc_config = NULL;
	u32 gpmc_base = 0;
	u32 base = 0;
	u32 size = 0;
	u32 f_off = CFG_MONITOR_LEN;
	u32 f_sec = 0;
	u32 config = 0;

	mux = BIT9;
	mwidth = get_gpmc0_width();

	/* global settings */
	__raw_writel(0x0, GPMC_IRQENABLE);	/* isr's sources masked */
	__raw_writel(0, GPMC_TIMEOUT_CONTROL);	/* timeout disable */

	config = __raw_readl(GPMC_CONFIG);
	config &= (~0xf00);
	__raw_writel(config, GPMC_CONFIG);

	/* Disable the GPMC0 config set by ROM code
	 * It conflicts with our MPDB (both at 0x08000000)
	 */
	__raw_writel(0, GPMC_CONFIG7 + GPMC_CONFIG_CS0);
	sdelay(1000);

	/* CS 0 */
	gpmc_config = gpmc_m_nand;
	gpmc_base = GPMC_CONFIG_CS0 + (0 * GPMC_CONFIG_WIDTH);
	base = PISMO1_NAND_BASE;
	size = PISMO1_NAND_SIZE;
	enable_gpmc_config(gpmc_config, gpmc_base, base, size);

	f_off = SMNAND_ENV_OFFSET;
	f_sec = SZ_128K;
	is_nand = 1;
	nand_cs_base = gpmc_base;

	/* env setup */
	boot_flash_base = base;
	boot_flash_off = f_off;
	boot_flash_sec = f_sec;
	boot_flash_env_addr = f_off;

#ifdef ENV_IS_VARIABLE
	boot_env_get_char_spec = env_get_char_spec;
	boot_env_init = env_init;
	boot_saveenv = saveenv;
	boot_env_relocate_spec = env_relocate_spec;
#endif

}
