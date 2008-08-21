/*
 * (C) Copyright 2004-2008
 * Texas Instruments, <www.ti.com>
 *
 * Author :
 *      Manikandan Pillai <mani.pillai@ti.com>
 *
 * Derived from Beagle Board and 3430 SDP code by
 *      Richard Woodruff <r-woodruff2@ti.com>
 *      Syed Mohammed Khasim <khasim@ti.com>
 *
 *
 * See file CREDITS for list of people who contributed to this
 * project.
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
#include <asm/io.h>
#include <asm/arch/bits.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <i2c.h>
#include <asm/mach-types.h>

#if (CONFIG_COMMANDS & CFG_CMD_NAND) && defined(CFG_NAND_LEGACY)
#include <linux/mtd/nand_legacy.h>
extern struct nand_chip nand_dev_desc[CFG_MAX_NAND_DEVICE];
#endif

#define NOT_EARLY 0

/* Permission values for registers -Full fledged permissions to all */
#define UNLOCK_1 0xFFFFFFFF
#define UNLOCK_2 0x00000000
#define UNLOCK_3 0x0000FFFF

const omap3_sysinfo sysinfo = {
	OMAP3EVM_V1,
	OMAP3EVM_V2,
	"35X-Family",
	"OMAP3 EVM board",
};

static int setup_net_chip(void);

/******************************************************************************
 * Routine: delay
 * Description: spinning delay to use before udelay works
 *****************************************************************************/
static inline void delay(unsigned long loops)
{
	__asm__ volatile ("1:\n" "subs %0, %1, #1\n"
			  "bne 1b":"=r" (loops):"0"(loops));
}

/******************************************************************************
 * Routine: board_init
 * Description: Early hardware init.
 *****************************************************************************/
int board_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;

	gpmc_init(); /* in SRAM or SDRAM, finish GPMC */
	/* board id for Linux */
	gd->bd->bi_arch_number = MACH_TYPE_OMAP3EVM;
	/* boot param addr */
	gd->bd->bi_boot_params = (OMAP34XX_SDRC_CS0 + 0x100);

	return 0;
}

/******************************************************************************
 * Routine: secure_unlock
 * Description: Setup security registers for access
 *              (GP Device only)
 *****************************************************************************/
void secure_unlock_mem(void)
{
	/* Protection Module Register Target APE (PM_RT) */
	__raw_writel(UNLOCK_1, RT_REQ_INFO_PERMISSION_1);
	__raw_writel(UNLOCK_1, RT_READ_PERMISSION_0);
	__raw_writel(UNLOCK_1, RT_WRITE_PERMISSION_0);
	__raw_writel(UNLOCK_2, RT_ADDR_MATCH_1);

	__raw_writel(UNLOCK_3, GPMC_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, GPMC_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, GPMC_WRITE_PERMISSION_0);

	__raw_writel(UNLOCK_3, OCM_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, OCM_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, OCM_WRITE_PERMISSION_0);
	__raw_writel(UNLOCK_2, OCM_ADDR_MATCH_2);

	/* IVA Changes */
	__raw_writel(UNLOCK_3, IVA2_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, IVA2_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, IVA2_WRITE_PERMISSION_0);

	__raw_writel(UNLOCK_1, SMS_RG_ATT0);	/* SDRC region 0 public */
}

/******************************************************************************
 * Routine: secureworld_exit()
 * Description: If chip is EMU and boot type is external
 *		configure secure registers and exit secure world
 *              general use.
 *****************************************************************************/
void secureworld_exit()
{
	unsigned long i;

	/* configrue non-secure access control register */
	__asm__ __volatile__("mrc p15, 0, %0, c1, c1, 2":"=r"(i));
	/* enabling co-processor CP10 and CP11 accesses in NS world */
	__asm__ __volatile__("orr %0, %0, #0xC00":"=r"(i));
	/* allow allocation of locked TLBs and L2 lines in NS world */
	/* allow use of PLE registers in NS world also */
	__asm__ __volatile__("orr %0, %0, #0x70000":"=r"(i));
	__asm__ __volatile__("mcr p15, 0, %0, c1, c1, 2":"=r"(i));

	/* Enable ASA in ACR register */
	__asm__ __volatile__("mrc p15, 0, %0, c1, c0, 1":"=r"(i));
	__asm__ __volatile__("orr %0, %0, #0x10":"=r"(i));
	__asm__ __volatile__("mcr p15, 0, %0, c1, c0, 1":"=r"(i));

	/* Exiting secure world */
	__asm__ __volatile__("mrc p15, 0, %0, c1, c1, 0":"=r"(i));
	__asm__ __volatile__("orr %0, %0, #0x31":"=r"(i));
	__asm__ __volatile__("mcr p15, 0, %0, c1, c1, 0":"=r"(i));
}

/******************************************************************************
 * Routine: setup_auxcr()
 * Description: Write to AuxCR desired value using SMI.
 *              general use.
 *****************************************************************************/
void setup_auxcr()
{
	unsigned long i;
	volatile unsigned int j;
	/* Save r0, r12 and restore them after usage */
	__asm__ __volatile__("mov %0, r12":"=r"(j));
	__asm__ __volatile__("mov %0, r0":"=r"(i));

	/* GP Device ROM code API usage here */
	/* r12 = AUXCR Write function and r0 value */
	__asm__ __volatile__("mov r12, #0x3");
	__asm__ __volatile__("mrc p15, 0, r0, c1, c0, 1");
	/* Enabling ASA */
	__asm__ __volatile__("orr r0, r0, #0x10");
	/* SMI instruction to call ROM Code API */
	__asm__ __volatile__(".word 0xE1600070");
	__asm__ __volatile__("mov r0, %0":"=r"(i));
	__asm__ __volatile__("mov r12, %0":"=r"(j));
}

/******************************************************************************
 * Routine: try_unlock_sram()
 * Description: If chip is GP/EMU(special) type, unlock the SRAM for
 *              general use.
 *****************************************************************************/
void try_unlock_memory()
{
	int mode;
	int in_sdram = running_in_sdram();

	/* if GP device unlock device SRAM for general use */
	/* secure code breaks for Secure/Emulation device - HS/E/T */
	mode = get_device_type();
	if (mode == GP_DEVICE)
		secure_unlock_mem();

	/* If device is EMU and boot is XIP external booting
	 * Unlock firewalls and disable L2 and put chip
	 * out of secure world
	 */
	/* Assuming memories are unlocked by the demon who put us in SDRAM */
	if ((mode <= EMU_DEVICE) && (get_boot_type() == 0x1F)
	    && (!in_sdram)) {
		secure_unlock_mem();
		secureworld_exit();
	}

	return;
}

/******************************************************************************
 * Routine: s_init
 * Description: Does early system init of muxing and clocks.
 *              - Called path is with SRAM stack.
 *****************************************************************************/
void s_init(void)
{
	int in_sdram = running_in_sdram();

	watchdog_init();

	try_unlock_memory();

	/* Right now flushing at low MPU speed.
	   Need to move after clock init */
	v7_flush_dcache_all(get_device_type());
#ifndef CONFIG_ICACHE_OFF
	icache_enable();
#endif

#ifdef CONFIG_L2_OFF
	l2cache_disable();
#else
	l2cache_enable();
#endif
	/* Writing to AuxCR in U-boot using SMI for GP DEV */
	/* Currently SMI in Kernel on ES2 devices seems to have an isse
	 * Once that is resolved, we can postpone this config to kernel
	 */
	if (get_device_type() == GP_DEVICE)
		setup_auxcr();

	set_muxconf_regs();
	delay(100);

	prcm_init();

	per_clocks_enable();

	if (!in_sdram)
		sdrc_init();
}

/******************************************************************************
 * Routine: misc_init_r
 * Description: Init ethernet (done here so udelay works)
 *****************************************************************************/
int misc_init_r(void)
{

	unsigned char byte;

#ifdef CONFIG_DRIVER_OMAP34XX_I2C
	i2c_init(CFG_I2C_SPEED, CFG_I2C_SLAVE);
#endif

#if defined(CONFIG_CMD_NET)
	setup_net_chip();
#endif

	return 0;
}


/******************************************************************************
 * Routine: wait_for_command_complete
 * Description: Wait for posting to finish on watchdog
 *****************************************************************************/
void wait_for_command_complete(unsigned int wd_base)
{
	int pending = 1;
	do {
		pending = __raw_readl(wd_base + WWPS);
	} while (pending);
}

/******************************************************************************
 * Routine: watchdog_init
 * Description: Shut down watch dogs
 *****************************************************************************/
void watchdog_init(void)
{
	/* There are 3 watch dogs WD1=Secure, WD2=MPU, WD3=IVA. WD1 is
	 * either taken care of by ROM (HS/EMU) or not accessible (GP).
	 * We need to take care of WD2-MPU or take a PRCM reset. WD3
	 * should not be running and does not generate a PRCM reset.
	 */

	sr32(CM_FCLKEN_WKUP, 5, 1, 1);
	sr32(CM_ICLKEN_WKUP, 5, 1, 1);
	wait_on_value(BIT5, 0x20, CM_IDLEST_WKUP, 5);	/* some issue here */

	__raw_writel(WD_UNLOCK1, WD2_BASE + WSPR);
	wait_for_command_complete(WD2_BASE);
	__raw_writel(WD_UNLOCK2, WD2_BASE + WSPR);
}

/******************************************************************************
 * Routine: dram_init
 * Description: sets uboots idea of sdram size
 *****************************************************************************/
int dram_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;
	unsigned int size0 = 0, size1 = 0;
	u32 mtype, btype;

	btype = get_board_type();
	mtype = get_mem_type();

	display_board_info(btype);

	/* If a second bank of DDR is attached to CS1 this is
	 * where it can be started.  Early init code will init
	 * memory on CS0.
	 */
	if ((mtype == DDR_COMBO) || (mtype == DDR_STACKED))
		do_sdrc_init(SDRC_CS1_OSET, NOT_EARLY);

	size0 = get_sdr_cs_size(SDRC_CS0_OSET);
	size1 = get_sdr_cs_size(SDRC_CS1_OSET);

	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = size0;
	gd->bd->bi_dram[1].start = PHYS_SDRAM_1 + size0;
	gd->bd->bi_dram[1].size = size1;

	return 0;
}

/******************************************************************************
 * Routine: set_muxconf_regs
 * Description: Setting up the configuration Mux registers specific to the
 *              hardware. Many pins need to be moved from protect to primary
 *              mode.
 *****************************************************************************/
void set_muxconf_regs(void)
{
	MUX_DEFAULT_ES2();
}

#if (CONFIG_COMMANDS & CFG_CMD_NAND) && defined(CFG_NAND_LEGACY)
/******************************************************************************
 * Routine: nand+_init
 * Description: Set up nand for nand and jffs2 commands
 *****************************************************************************/
void nand_init(void)
{
	extern flash_info_t flash_info[];

	nand_probe(CFG_NAND_ADDR);
	if (nand_dev_desc[0].ChipID != NAND_ChipID_UNKNOWN)
		print_size(nand_dev_desc[0].totlen, "\n");

#ifdef CFG_JFFS2_MEM_NAND
	flash_info[CFG_JFFS2_FIRST_BANK].flash_id = nand_dev_desc[0].id;
	/* only read kernel single meg partition */
	flash_info[CFG_JFFS2_FIRST_BANK].size = 1024 * 1024 * 2;
	/* 1024 blocks in 16meg chip (use less for raw/copied partition) */
	flash_info[CFG_JFFS2_FIRST_BANK].sector_count = 1024;
	/* ?, ram for now, open question, copy to RAM or adapt for NAND */
	flash_info[CFG_JFFS2_FIRST_BANK].start[0] = 0x80200000;
#endif
}
#endif

/******************************************************************************
 * Dummy function to handle errors for EABI incompatibility
 *****************************************************************************/
void raise(void)
{
}

/******************************************************************************
 * Dummy function to handle errors for EABI incompatibility
 *****************************************************************************/
void abort(void)
{
}


/******************************************************************************
 * Routine: setup_net_chip
 * Description: Setting up the configuration GPMC registers specific to the
 *              Ethernet hardware. Pin Muxing for the SMC9118 is initialized
 *              here.
 *****************************************************************************/
static int setup_net_chip(void)
{
	int i = 0;

	/* Configure GPMC registers */
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x0150)) = 0x00001000;
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x0154)) = 0x001e1e01;
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x0158)) = 0x00080300;
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x015C)) = 0x1c091c09;
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x0160)) = 0x04181f1f;
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x0164)) = 0x00000FCF;
	(*(volatile int *)(OMAP34XX_GPMC_BASE + 0x0168)) = 0x00000f6c;

	/* Configure PIN MUX registers */
	/* Enable GPMC Pin Mux Registers */
	/* Enable GPMC_CLK Pin in CONTROL_PADCONF_gpmc_ncs7 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xBC)) |= 0x00180000;
	/* Enable CS5 Pin in CONTROL_PADCONF_gpmc_ncs5 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xB8)) |= 0x00000018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xB8)) &= 0xFFFFFFF8;
	/* Enable offmode for nwe in CONTROL_PADCONF_GPMC_NWE register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xC4)) |= 0x00000F00;
	/* En off mode for noe and ale in CONTROL_PADCONF_GPMC_NADV_ALE reg */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xC0)) |= 0x0E000E00;
	/* Enable gpmc_nbe0_cle in CONTROL_PADCONF_GPMC_NWE register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xC4)) |= 0x00180000;

	/* Enable gpmc_nbe1 in CONTROL_PADCONF_GPMC_NBE1 register and
	configuring the mux mode to 0 */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xC8)) |= 0x00000018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xC8)) &= 0xFFFFFFF8;
	/* Enable d15 in CONTROL_PADCONF_GPMC_D15 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xAC)) |= 0x00000018;
	/* Enable d14 - d13 in CONTROL_PADCONF_GPMC_D13 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xA8)) |= 0x00180018;
	/* Enable d12 - d11 in CONTROL_PADCONF_GPMC_D11 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xA4)) |= 0x00180018;
	/* Enable d10 - d9 in CONTROL_PADCONF_GPMC_D9 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xA0)) |= 0x00180018;
	/* Enable d8 - d7 in CONTROL_PADCONF_GPMC_D7 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x9C)) |= 0x00180018;
	/* Enable d6 - d5 in CONTROL_PADCONF_GPMC_D5 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x98)) |= 0x00180018;
	/* Enable d4 - d3 in CONTROL_PADCONF_GPMC_D3 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x94)) |= 0x00180018;
	/* Enable d2 - d1 in CONTROL_PADCONF_GPMC_D1 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x90)) |= 0x00180018;
	/* Enable d0 and a10 in CONTROL_PADCONF_GPMC_a10 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x8C)) |= 0x00180018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x8C)) &= 0xFFFFFFF8;
	/* Enable a9 - a8 in CONTROL_PADCONF_GPMC_a8 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x88)) |= 0x00180018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x88)) &= 0xFFF8FFF8;
	/* Enable a7 - a6 in CONTROL_PADCONF_GPMC_a6 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x84)) |= 0x00180018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x84)) &= 0xFFF8FFF8;
	/* Enable a5 - a4 in CONTROL_PADCONF_GPMC_a4 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x80)) |= 0x00180018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x80)) &= 0xFFF8FFF8;
	/* Enable a3 - a2 in CONTROL_PADCONF_GPMC_a2 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x7C)) |= 0x00180018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x7C)) &= 0xFFF8FFF8;
	/* Enable a1 - a0 in CONTROL_PADCONF_GPMC_a0 register */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x78)) |= 0x00000018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x78)) &= 0xFFFFFFF8;

#if defined(CPU_3430_ES1) || defined(CPU_3430_ES2)
	/* GPIO 64 configuration in CONTROL_PADCONF_GPMC_WAIT2
	register mux mode is 4. */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xD0)) |= 0x00000018;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xD0)) &= 0xFFFFFFF8;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0xD0)) |= 0x00000004;

	/* Configure GPIO 176 in CONTROL_PADCONF_MCSPI1_CS1
	register for ethernet ISR mux mode is 4 */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x1D0)) |= 0x00180000;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x1D0)) &= 0xFFF8FFFF;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x1D0)) |= 0x00040000;

	/* Enable Clock for GPIO 1-6 module in CM_FCLKEN_PER
	and CM_ICLKEN_PER registers */
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x5000)) |= 0x0003E800;
	(*(volatile int *)(OMAP34XX_CTRL_BASE + 0x5010)) |= 0x0003E800;

	/* Make GPIO 64 as output pin */
	(*(volatile int *)(OMAP34XX_GPIO3_BASE + 0x34)) &= ~(0x00000001);

	/* Now send a pulse on the GPIO pin */
	(*(volatile int *)(OMAP34XX_GPIO3_BASE + 0x3C)) |= 0x00000001;
	for (i = 0; i < 99 ; i++);
	(*(volatile int *)(OMAP34XX_GPIO3_BASE + 0x3C)) &= ~(0x00000001);
	for (i = 0; i < 99 ; i++);
	(*(volatile int *)(OMAP34XX_GPIO3_BASE + 0x3C)) |= 0x00000001;
#else
	printf("Unknown revision... \n\n");
#endif
	return 0;
}

