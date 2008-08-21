/*
 * (C) Copyright 2004-2008
 * Texas Instruments, <www.ti.com>
 *
 * Author :
 *      Sunil Kumar <sunilsaini05@gmail.com>
 *      Shashi Ranjan <shashiranjanmca05@gmail.com>
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
	SDP_3430_V1,
	SDP_3430_V2,
	"3530",
	"OMAP3 Beagle board",
};

/******************************************************************************
 * Routine: board_init
 * Description: Early hardware init.
 *****************************************************************************/
int board_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;

	gpmc_init(); /* in SRAM or SDRAM, finish GPMC */
	/* board id for Linux */
	gd->bd->bi_arch_number = MACH_TYPE_OMAP3_BEAGLE;
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
	/* set vaux3 to 2.8V */
	byte = 0x20;
	i2c_write(0x4B, 0x7A, 1, &byte, 1);
	byte = 0x03;
	i2c_write(0x4B, 0x7D, 1, &byte, 1);

	/* set vpll2 to 1.8V */
	byte = 0xE0;
	i2c_write(0x4B, 0x8E, 1, &byte, 1);
	byte = 0x05;
	i2c_write(0x4B, 0x91, 1, &byte, 1);

	/* set VDAC to 1.8V */
	byte = 0x20;
	i2c_write(0x4B, 0x96, 1, &byte, 1);
	byte = 0x03;
	i2c_write(0x4B, 0x99, 1, &byte, 1);

	byte = 0x33;
	i2c_write(0x4A, 0xEE, 1, &byte, 1);

	*((uint *) 0x49058034) = 0xFFFFFAF9;
	*((uint *) 0x49056034) = 0x0F9F0FFF;
	*((uint *) 0x49058094) = 0x00000506;
	*((uint *) 0x49056094) = 0xF060F000;

	return (0);
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
