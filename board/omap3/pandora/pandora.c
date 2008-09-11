/*
 * Maintainer : John Willis <source@distant-earth.com>
 *
 * Derived from Beagle Board, 3430 SDP, and OMAP3EVM code by
 *      Richard Woodruff <r-woodruff2@ti.com>
 *      Syed Mohammed Khasim <khasim@ti.com>
 *      Sunil Kumar <sunilsaini05@gmail.com>
 *      Shashi Ranjan <shashiranjanmca05@gmail.com>
 *
 * (C) Copyright 2004-2008
 * Texas Instruments, <www.ti.com>
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
	"Pandora Handheld Console",
};

static void sendLcdSpiCommand(uint data)
{
	*((uint *) 0x480BA038) = data;

	do
	{
		data  = *((uint *) 0x480BA018);
		data &= (0x1);
	}
	while (!data);

	do
	{
		data  = *((uint *) 0x480BA030);
		data &= (1<<1);
	}
	while (!data);
	*((uint *) 0x480BA018) = 0xFFFFFFFF;
}

static void dss_lcd_init(void)
{
	*((uint *) 0x48004D44) = 0x0001b00c; //DPLL4 multiplier/divider (CM_CLKSEL2_PLL)
	*((uint *) 0x48004E40) = 0x00001006; //TV clock = DPLL4/16
	*((uint *) 0x48004D00) = 0x00370037; //control DPLL3/4 (CM_CLKEN_PLL)
//	*((uint *) 0x48050C00) = 0x00000002; //This is READ ONLY!
	*((uint *) 0x48050C04) = 0x0000001B; //Closed caption
	*((uint *) 0x48050C08) = 0x00000040; //TV color stuff
	*((uint *) 0x48050C0C) = 0x00000000; //NOT DOCUMENTED!!!!?????
	*((uint *) 0x48050C10) = 0x00000000; //54MHz, 4x oversampling
	*((uint *) 0x48050C14) = 0x00008000;
	*((uint *) 0x48050C18) = 0x00000000;
	*((uint *) 0x48050C1C) = 0x00008359;
	*((uint *) 0x48050C20) = 0x0000020C;
	*((uint *) 0x48050C24) = 0x00000000;
	*((uint *) 0x48050C28) = 0x043F2631;
	*((uint *) 0x48050C2C) = 0x00000024;
	*((uint *) 0x48050C30) = 0x00000130;
	*((uint *) 0x48050C34) = 0x00000198;
	*((uint *) 0x48050C38) = 0x000001C0;
	*((uint *) 0x48050C3C) = 0x0000006A;
	*((uint *) 0x48050C40) = 0x0000005C;
	*((uint *) 0x48050C44) = 0x00000000;
	*((uint *) 0x48050C48) = 0x00000001;
	*((uint *) 0x48050C4C) = 0x0000003F;
	*((uint *) 0x48050C50) = 0x21F07C1F;
	*((uint *) 0x48050C54) = 0x00000000;
	*((uint *) 0x48050C58) = 0x00000015;
	*((uint *) 0x48050C5C) = 0x00001400;
	*((uint *) 0x48050C60) = 0x00000000;
	*((uint *) 0x48050C64) = 0x069300F4;
	*((uint *) 0x48050C68) = 0x0016020C;
	*((uint *) 0x48050C6C) = 0x00060107;
	*((uint *) 0x48050C70) = 0x008D034E;
	*((uint *) 0x48050C74) = 0x000F0359;
	*((uint *) 0x48050C78) = 0x01A00000;
	*((uint *) 0x48050C7C) = 0x020501A0;
	*((uint *) 0x48050C80) = 0x01AC0024;
	*((uint *) 0x48050C84) = 0x020D01AC;
	*((uint *) 0x48050C88) = 0x00000006;
	*((uint *) 0x48050C8C) = 0x00000000;
	*((uint *) 0x48050C90) = 0x03480079;
	*((uint *) 0x48050C94) = 0x02040024;
	*((uint *) 0x48050C98) = 0x00000000;
	*((uint *) 0x48050C9C) = 0x00000000;
	*((uint *) 0x48050CA0) = 0x0001008A;
	*((uint *) 0x48050CA4) = 0x01AC0106;
	*((uint *) 0x48050CA8) = 0x01060006;
	*((uint *) 0x48050CAC) = 0x00000000;
	*((uint *) 0x48050CB0) = 0x00140001;
	*((uint *) 0x48050CB4) = 0x00010001;
	*((uint *) 0x48050CB8) = 0x00FF0000;
	*((uint *) 0x48050CBC) = 0x00000000;
	*((uint *) 0x48050CC0) = 0x00000000;
	*((uint *) 0x48050CC4) = 0x0000000D;
	*((uint *) 0x48050CC8) = 0x00000000;
	*((uint *) 0x48050010) = 0x00000001;
	*((uint *) 0x48050040) = 0x00000078;
	*((uint *) 0x48050044) = 0x00000000;
	*((uint *) 0x48050048) = 0x00000000;
	*((uint *) 0x48050050) = 0x00000000;
	*((uint *) 0x48050058) = 0x00000000;
	*((uint *) 0x48050410) = 0x00002015;
//	*((uint *) 0x48050414) = 0x00000001; //Read only
	*((uint *) 0x48050444) = 0x00000004;
	*((uint *) 0x4805044c) = 0xFFFFFFFF;
	*((uint *) 0x48050450) = 0x00000000;
	*((uint *) 0x48050454) = 0x00000000;
	*((uint *) 0x48050458) = 0x00000000;
//	*((uint *) 0x48050464) = 0x0D702700; //HORIZONTAL TIMING
	*((uint *) 0x48050464) = 0x0D602700;
//	*((uint *) 0x48050468) = 0x02300A00; //VERTICAL TIMING
	*((uint *) 0x48050468) = 0x02200A00;
	*((uint *) 0x4805046c) = 0x00007000; //POLARITIES

//	*((uint *) 0x48050464) = 0x0ff03f31;
//	*((uint *) 0x48050468) = 0x01400504;
//	*((uint *) 0x4805046c) = 0x00007028;

	*((uint *) 0x48050470) = 0x00020002;//0x00010003;

	*((uint *) 0x4805047c) = 0x01DF031F; //DISPLAY SIZE
	*((uint *) 0x48050478) = 0x00ef027f;
//	*((uint *) 0x4805047c) = 0x02cf04ff;
	*((uint *) 0x48050480) = 0x80500000;
	*((uint *) 0x48050484) = 0x80500000;
	*((uint *) 0x48050488) = 0x00000000;
//	*((uint *) 0x4805048c) = 0x02cf04ff;
	*((uint *) 0x4805048c) = 0x01DF031F;
	*((uint *) 0x480504a0) = 0x0000008d;
	*((uint *) 0x480504a4) = 0x03fc03bc;
	*((uint *) 0x480504a8) = 0x00000400;
	*((uint *) 0x480504ac) = 0x00000001;
	*((uint *) 0x480504b0) = 0x00000001;
	*((uint *) 0x480504b4) = 0x00000000;
	*((uint *) 0x480504b8) = 0x807ff000;
	udelay(1000);
	*((uint *) 0x48050440) = 0x3001836b;
	udelay(1000);
	*((uint *) 0x48050440) = 0x3001836b;
	udelay(1000);
	*((uint *) 0x48050440) = 0x3001836b;
	udelay(1000);
}

// TPO LCD GAMMA VALUES
#define g0  106
#define g1  200
#define g2  289
#define g3  375
#define g4  460
#define g5  543
#define g6  625
#define g7  705
#define g8  785
#define g9  864
#define g10 942
#define g11 1020

static void lcd_init(void)
{
	unsigned char byte;
	uint i;

	/* Set GPIOs on T2 (Turn on LCD BL) */
	byte = 0xC0;
	i2c_write(0x49, 0x9B, 1, &byte, 1); // 155
	byte = 0xC0;
	i2c_write(0x49, 0x9E, 1, &byte, 1); // 158

	/* VAUX1 = 3.0V    (LCD) */
	byte = 0x20;
	i2c_write(0x4B, 0x72, 1, &byte, 1);
	byte = 0x04;
	i2c_write(0x4B, 0x75, 1, &byte, 1);

	/* Clear frame buffer */
	memset((void *)0x80500000, 0, 800*480*2);

	udelay(11000); // Wait at least 10ms after power on before leaving reset
	*((uint *) 0x49056094) = 0x20000000; // Bring LCD out of reset (29+4*32=157)
	udelay(2000); // Need to wait at least 1ms after reset to start sending signals

	dss_lcd_init();

	udelay(100); // Wait a bit to start turning LCD charge pumps and display on

	i = (0x11 << 10) + (0x01 << 8) + ((g0 & 0x300) >> 2) + ((g1 & 0x300) >> 4) + ((g2 & 0x300) >> 6) + ((g3 & 0x300) >> 8);
	sendLcdSpiCommand(i);
	i = (0x12 << 10) + (0x01 << 8) + ((g4 & 0x300) >> 2) + ((g5 & 0x300) >> 4) + ((g6 & 0x300) >> 6) + ((g7 & 0x300) >> 8);
	sendLcdSpiCommand(i);
	i = (0x13 << 10) + (0x01 << 8) + ((g8 & 0x300) >> 2) + ((g9 & 0x300) >> 4) + ((g10 & 0x300) >> 6) + ((g11 & 0x300) >> 8);
	sendLcdSpiCommand(i);
	i = (0x14 << 10) + (0x01 << 8) + (g0 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x15 << 10) + (0x01 << 8) + (g1 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x16 << 10) + (0x01 << 8) + (g2 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x17 << 10) + (0x01 << 8) + (g3 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x18 << 10) + (0x01 << 8) + (g4 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x19 << 10) + (0x01 << 8) + (g5 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x1A << 10) + (0x01 << 8) + (g6 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x1B << 10) + (0x01 << 8) + (g7 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x1C << 10) + (0x01 << 8) + (g8 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x1D << 10) + (0x01 << 8) + (g9 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x1E << 10) + (0x01 << 8) + (g10 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x1F << 10) + (0x01 << 8) + (g11 & 0x0FF);
	sendLcdSpiCommand(i);
	i = (0x20 << 10) + (0x01 << 8) + 0xF0;
	sendLcdSpiCommand(i);
	i = (0x21 << 10) + (0x01 << 8) + 0xF0;
	sendLcdSpiCommand(i);
	i = (0x03 << 10) + (0x01 << 8) + 0xDF;
	sendLcdSpiCommand(i);
	i = (0x02 << 10) + (0x01 << 8) + 0x07;
	sendLcdSpiCommand(i);
	i = (0x04 << 10) + (0x01 << 8) + (0x05 << 2) + 3;
	sendLcdSpiCommand(i);
	*((uint *) 0x480BA034) = 0x00000000; // Disable SPI4
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
	gd->bd->bi_arch_number = MACH_TYPE_OMAP3_PANDORA;
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
	uint i, val;

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

	/* set vaux4 to 2.8V (TOUCH,NUBS,RS-232 TRANSCEIVER) */
	byte = 0x20;
	i2c_write(0x4B, 0x7E, 1, &byte, 1);
	byte = 0x0A;
	i2c_write(0x4B, 0x81, 1, &byte, 1);

	/* Enable clocks for SPI1 and SPI4 */
	val = *((uint *) 0x48004A00);
	val |= (1<<21) + (1<<18);
	*((uint *) 0x48004A00) = val;
	val = *((uint *) 0x48004A10);
	val |= (1<<21) + (1<<18);
	*((uint *) 0x48004A10) = val;

	/* GPIO OE */
        *((uint *) 0x48310034) = 0xFF7F3FFF; // GPIO1
        *((uint *) 0x49056034) = 0x5FF5DFFC; // GPIO5
        *((uint *) 0x49058034) = 0xFFFFFFEB; // GPIO6

	/* GPIO CLEARDATAOUT */
	*((uint *) 0x48310090) = 0x0080C000;
	*((uint *) 0x49056090) = 0x20000003;
	*((uint *) 0x49058090) = 0x00002004;

	/* GPIO SETDATAOUT */
	*((uint *) 0x49058094) = 0x00000010;

	/* SPI4 (LCD) */
	*((uint *) 0x480BA010) = 0x00000002; // Reset module
	do
	{
		i = *((uint *) 0x480BA014);
		i &= 1;
	} while (!i);

	*((uint *) 0x480BA034) = 0x00000000;
	*((uint *) 0x480BA01C) = 0x00000000;
	*((uint *) 0x480BA018) = 0xFFFFFFFF;
	*((uint *) 0x480BA024) = 0x00000000;
	*((uint *) 0x480BA028) = 0x00000000;
	*((uint *) 0x480BA010) = 0x00000308;
	*((uint *) 0x480BA02C) = 0x020127DC;//0x020127D4;
	*((uint *) 0x480BA034) = 0x00000001;

	lcd_init();

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
	MUX_DEFAULT_PANDORA();
}

