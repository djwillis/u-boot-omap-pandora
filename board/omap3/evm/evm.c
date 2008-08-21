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
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <i2c.h>
#include <asm/mach-types.h>

const omap3_sysinfo sysinfo = {
	OMAP3EVM_V1,
	OMAP3EVM_V2,
	"35X-Family",
	"OMAP3 EVM board",
};

static int setup_net_chip(void);

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
 * Routine: set_muxconf_regs
 * Description: Setting up the configuration Mux registers specific to the
 *              hardware. Many pins need to be moved from protect to primary
 *              mode.
 *****************************************************************************/
void set_muxconf_regs(void)
{
	MUX_DEFAULT_ES2();
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

