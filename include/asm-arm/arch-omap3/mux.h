/*
 * (C) Copyright 2006-2008
 * Texas Instruments, <www.ti.com>
 * Syed Mohammed Khasim <x0khasim@ti.com>
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
#ifndef _MUX_H_
#define _MUX_H_

/*
 * IEN  - Input Enable
 * IDIS - Input Disable
 * PTD  - Pull type Down
 * PTU  - Pull type Up
 * DIS  - Pull type selection is inactive
 * EN   - Pull type selection is active
 * M0   - Mode 0
 */

#define  IEN	(1 << 8)

#define  IDIS	(0 << 8)
#define  PTU	(1 << 4)
#define  PTD	(0 << 4)
#define  EN		(1 << 3)
#define  DIS	(0 << 3)

#define  M0	0
#define  M1	1
#define  M2	2
#define  M3	3
#define  M4	4
#define  M5	5
#define  M6	6
#define  M7	7

/*
 * To get the actual address the offset has to added
 * with OMAP34XX_CTRL_BASE to get the actual address
 */

 /*SDRC*/
#define  CONTROL_PADCONF_SDRC_D0             0x0030
#define  CONTROL_PADCONF_SDRC_D1             0x0032
#define  CONTROL_PADCONF_SDRC_D2             0x0034
#define  CONTROL_PADCONF_SDRC_D3             0x0036
#define  CONTROL_PADCONF_SDRC_D4             0x0038
#define  CONTROL_PADCONF_SDRC_D5             0x003A
#define  CONTROL_PADCONF_SDRC_D6             0x003C
#define  CONTROL_PADCONF_SDRC_D7             0x003E
#define  CONTROL_PADCONF_SDRC_D8             0x0040
#define  CONTROL_PADCONF_SDRC_D9             0x0042
#define  CONTROL_PADCONF_SDRC_D10            0x0044
#define  CONTROL_PADCONF_SDRC_D11            0x0046
#define  CONTROL_PADCONF_SDRC_D12            0x0048
#define  CONTROL_PADCONF_SDRC_D13            0x004A
#define  CONTROL_PADCONF_SDRC_D14            0x004C
#define  CONTROL_PADCONF_SDRC_D15            0x004E
#define  CONTROL_PADCONF_SDRC_D16            0x0050
#define  CONTROL_PADCONF_SDRC_D17            0x0052
#define  CONTROL_PADCONF_SDRC_D18            0x0054
#define  CONTROL_PADCONF_SDRC_D19            0x0056
#define  CONTROL_PADCONF_SDRC_D20            0x0058
#define  CONTROL_PADCONF_SDRC_D21            0x005A
#define  CONTROL_PADCONF_SDRC_D22            0x005C
#define  CONTROL_PADCONF_SDRC_D23            0x005E
#define  CONTROL_PADCONF_SDRC_D24            0x0060
#define  CONTROL_PADCONF_SDRC_D25            0x0062
#define  CONTROL_PADCONF_SDRC_D26            0x0064
#define  CONTROL_PADCONF_SDRC_D27            0x0066
#define  CONTROL_PADCONF_SDRC_D28            0x0068
#define  CONTROL_PADCONF_SDRC_D29            0x006A
#define  CONTROL_PADCONF_SDRC_D30            0x006C
#define  CONTROL_PADCONF_SDRC_D31            0x006E
#define  CONTROL_PADCONF_SDRC_CLK            0x0070
#define  CONTROL_PADCONF_SDRC_DQS0           0x0072
#define  CONTROL_PADCONF_SDRC_DQS1           0x0074
#define  CONTROL_PADCONF_SDRC_DQS2           0x0076
#define  CONTROL_PADCONF_SDRC_DQS3           0x0078
     /*GPMC*/
#define  CONTROL_PADCONF_GPMC_A1             0x007A
#define  CONTROL_PADCONF_GPMC_A2             0x007C
#define  CONTROL_PADCONF_GPMC_A3             0x007E
#define  CONTROL_PADCONF_GPMC_A4             0x0080
#define  CONTROL_PADCONF_GPMC_A5             0x0082
#define  CONTROL_PADCONF_GPMC_A6             0x0084
#define  CONTROL_PADCONF_GPMC_A7             0x0086
#define  CONTROL_PADCONF_GPMC_A8             0x0088
#define  CONTROL_PADCONF_GPMC_A9             0x008A
#define  CONTROL_PADCONF_GPMC_A10            0x008C
#define  CONTROL_PADCONF_GPMC_D0             0x008E
#define  CONTROL_PADCONF_GPMC_D1             0x0090
#define  CONTROL_PADCONF_GPMC_D2             0x0092
#define  CONTROL_PADCONF_GPMC_D3             0x0094
#define  CONTROL_PADCONF_GPMC_D4             0x0096
#define  CONTROL_PADCONF_GPMC_D5             0x0098
#define  CONTROL_PADCONF_GPMC_D6             0x009A
#define  CONTROL_PADCONF_GPMC_D7             0x009C
#define  CONTROL_PADCONF_GPMC_D8             0x009E
#define  CONTROL_PADCONF_GPMC_D9             0x00A0
#define  CONTROL_PADCONF_GPMC_D10            0x00A2
#define  CONTROL_PADCONF_GPMC_D11            0x00A4
#define  CONTROL_PADCONF_GPMC_D12            0x00A6
#define  CONTROL_PADCONF_GPMC_D13            0x00A8
#define  CONTROL_PADCONF_GPMC_D14            0x00AA
#define  CONTROL_PADCONF_GPMC_D15            0x00AC
#define  CONTROL_PADCONF_GPMC_nCS0           0x00AE
#define  CONTROL_PADCONF_GPMC_nCS1           0x00B0
#define  CONTROL_PADCONF_GPMC_nCS2           0x00B2
#define  CONTROL_PADCONF_GPMC_nCS3           0x00B4
#define  CONTROL_PADCONF_GPMC_nCS4           0x00B6
#define  CONTROL_PADCONF_GPMC_nCS5           0x00B8
#define  CONTROL_PADCONF_GPMC_nCS6           0x00BA
#define  CONTROL_PADCONF_GPMC_nCS7           0x00BC
#define  CONTROL_PADCONF_GPMC_CLK            0x00BE
#define  CONTROL_PADCONF_GPMC_nADV_ALE       0x00C0
#define  CONTROL_PADCONF_GPMC_nOE            0x00C2
#define  CONTROL_PADCONF_GPMC_nWE            0x00C4
#define  CONTROL_PADCONF_GPMC_nBE0_CLE       0x00C6
#define  CONTROL_PADCONF_GPMC_nBE1           0x00C8
#define  CONTROL_PADCONF_GPMC_nWP            0x00CA
#define  CONTROL_PADCONF_GPMC_WAIT0          0x00CC
#define  CONTROL_PADCONF_GPMC_WAIT1          0x00CE
#define  CONTROL_PADCONF_GPMC_WAIT2          0x00D0
#define  CONTROL_PADCONF_GPMC_WAIT3          0x00D2
     /*DSS*/
#define  CONTROL_PADCONF_DSS_PCLK            0x00D4
#define  CONTROL_PADCONF_DSS_HSYNC           0x00D6
#define  CONTROL_PADCONF_DSS_VSYNC           0x00D8
#define  CONTROL_PADCONF_DSS_ACBIAS          0x00DA
#define  CONTROL_PADCONF_DSS_DATA0           0x00DC
#define  CONTROL_PADCONF_DSS_DATA1           0x00DE
#define  CONTROL_PADCONF_DSS_DATA2           0x00E0
#define  CONTROL_PADCONF_DSS_DATA3           0x00E2
#define  CONTROL_PADCONF_DSS_DATA4           0x00E4
#define  CONTROL_PADCONF_DSS_DATA5           0x00E6
#define  CONTROL_PADCONF_DSS_DATA6           0x00E8
#define  CONTROL_PADCONF_DSS_DATA7           0x00EA
#define  CONTROL_PADCONF_DSS_DATA8           0x00EC
#define  CONTROL_PADCONF_DSS_DATA9           0x00EE
#define  CONTROL_PADCONF_DSS_DATA10          0x00F0
#define  CONTROL_PADCONF_DSS_DATA11          0x00F2
#define  CONTROL_PADCONF_DSS_DATA12          0x00F4
#define  CONTROL_PADCONF_DSS_DATA13          0x00F6
#define  CONTROL_PADCONF_DSS_DATA14          0x00F8
#define  CONTROL_PADCONF_DSS_DATA15          0x00FA
#define  CONTROL_PADCONF_DSS_DATA16          0x00FC
#define  CONTROL_PADCONF_DSS_DATA17          0x00FE
#define  CONTROL_PADCONF_DSS_DATA18          0x0100
#define  CONTROL_PADCONF_DSS_DATA19          0x0102
#define  CONTROL_PADCONF_DSS_DATA20          0x0104
#define  CONTROL_PADCONF_DSS_DATA21          0x0106
#define  CONTROL_PADCONF_DSS_DATA22          0x0108
#define  CONTROL_PADCONF_DSS_DATA23          0x010A
     /*CAMERA*/
#define  CONTROL_PADCONF_CAM_HS              0x010C
#define  CONTROL_PADCONF_CAM_VS              0x010E
#define  CONTROL_PADCONF_CAM_XCLKA           0x0110
#define  CONTROL_PADCONF_CAM_PCLK            0x0112
#define  CONTROL_PADCONF_CAM_FLD             0x0114
#define  CONTROL_PADCONF_CAM_D0              0x0116
#define  CONTROL_PADCONF_CAM_D1              0x0118
#define  CONTROL_PADCONF_CAM_D2              0x011A
#define  CONTROL_PADCONF_CAM_D3              0x011C
#define  CONTROL_PADCONF_CAM_D4              0x011E
#define  CONTROL_PADCONF_CAM_D5              0x0120
#define  CONTROL_PADCONF_CAM_D6              0x0122
#define  CONTROL_PADCONF_CAM_D7              0x0124
#define  CONTROL_PADCONF_CAM_D8              0x0126
#define  CONTROL_PADCONF_CAM_D9              0x0128
#define  CONTROL_PADCONF_CAM_D10             0x012A
#define  CONTROL_PADCONF_CAM_D11             0x012C
#define  CONTROL_PADCONF_CAM_XCLKB           0x012E
#define  CONTROL_PADCONF_CAM_WEN             0x0130
#define  CONTROL_PADCONF_CAM_STROBE          0x0132
#define  CONTROL_PADCONF_CSI2_DX0            0x0134
#define  CONTROL_PADCONF_CSI2_DY0            0x0136
#define  CONTROL_PADCONF_CSI2_DX1            0x0138
#define  CONTROL_PADCONF_CSI2_DY1            0x013A
/*Audio Interface */
#define  CONTROL_PADCONF_McBSP2_FSX          0x013C
#define  CONTROL_PADCONF_McBSP2_CLKX         0x013E
#define  CONTROL_PADCONF_McBSP2_DR           0x0140
#define  CONTROL_PADCONF_McBSP2_DX           0x0142
#define  CONTROL_PADCONF_MMC1_CLK            0x0144
#define  CONTROL_PADCONF_MMC1_CMD            0x0146
#define  CONTROL_PADCONF_MMC1_DAT0           0x0148
#define  CONTROL_PADCONF_MMC1_DAT1           0x014A
#define  CONTROL_PADCONF_MMC1_DAT2           0x014C
#define  CONTROL_PADCONF_MMC1_DAT3           0x014E
#define  CONTROL_PADCONF_MMC1_DAT4           0x0150
#define  CONTROL_PADCONF_MMC1_DAT5           0x0152
#define  CONTROL_PADCONF_MMC1_DAT6           0x0154
#define  CONTROL_PADCONF_MMC1_DAT7           0x0156
/*Wireless LAN */
#define  CONTROL_PADCONF_MMC2_CLK            0x0158
#define  CONTROL_PADCONF_MMC2_CMD            0x015A
#define  CONTROL_PADCONF_MMC2_DAT0           0x015C
#define  CONTROL_PADCONF_MMC2_DAT1           0x015E
#define  CONTROL_PADCONF_MMC2_DAT2           0x0160
#define  CONTROL_PADCONF_MMC2_DAT3           0x0162
#define  CONTROL_PADCONF_MMC2_DAT4           0x0164
#define  CONTROL_PADCONF_MMC2_DAT5           0x0166
#define  CONTROL_PADCONF_MMC2_DAT6           0x0168
#define  CONTROL_PADCONF_MMC2_DAT7           0x016A
/*Bluetooth*/
#define  CONTROL_PADCONF_McBSP3_DX           0x016C
#define  CONTROL_PADCONF_McBSP3_DR           0x016E
#define  CONTROL_PADCONF_McBSP3_CLKX         0x0170
#define  CONTROL_PADCONF_McBSP3_FSX          0x0172
#define  CONTROL_PADCONF_UART2_CTS           0x0174
#define  CONTROL_PADCONF_UART2_RTS           0x0176
#define  CONTROL_PADCONF_UART2_TX            0x0178
#define  CONTROL_PADCONF_UART2_RX            0x017A
/*Modem Interface */
#define  CONTROL_PADCONF_UART1_TX            0x017C
#define  CONTROL_PADCONF_UART1_RTS           0x017E
#define  CONTROL_PADCONF_UART1_CTS           0x0180
#define  CONTROL_PADCONF_UART1_RX            0x0182
#define  CONTROL_PADCONF_McBSP4_CLKX         0x0184
#define  CONTROL_PADCONF_McBSP4_DR           0x0186
#define  CONTROL_PADCONF_McBSP4_DX           0x0188
#define  CONTROL_PADCONF_McBSP4_FSX          0x018A
#define  CONTROL_PADCONF_McBSP1_CLKR         0x018C
#define  CONTROL_PADCONF_McBSP1_FSR          0x018E
#define  CONTROL_PADCONF_McBSP1_DX           0x0190
#define  CONTROL_PADCONF_McBSP1_DR           0x0192
#define  CONTROL_PADCONF_McBSP_CLKS          0x0194
#define  CONTROL_PADCONF_McBSP1_FSX          0x0196
#define  CONTROL_PADCONF_McBSP1_CLKX         0x0198
/*Serial Interface*/
#define  CONTROL_PADCONF_UART3_CTS_RCTX      0x019A
#define  CONTROL_PADCONF_UART3_RTS_SD        0x019C
#define  CONTROL_PADCONF_UART3_RX_IRRX       0x019E
#define  CONTROL_PADCONF_UART3_TX_IRTX       0x01A0
#define  CONTROL_PADCONF_HSUSB0_CLK          0x01A2
#define  CONTROL_PADCONF_HSUSB0_STP          0x01A4
#define  CONTROL_PADCONF_HSUSB0_DIR          0x01A6
#define  CONTROL_PADCONF_HSUSB0_NXT          0x01A8
#define  CONTROL_PADCONF_HSUSB0_DATA0        0x01AA
#define  CONTROL_PADCONF_HSUSB0_DATA1        0x01AC
#define  CONTROL_PADCONF_HSUSB0_DATA2        0x01AE
#define  CONTROL_PADCONF_HSUSB0_DATA3        0x01B0
#define  CONTROL_PADCONF_HSUSB0_DATA4        0x01B2
#define  CONTROL_PADCONF_HSUSB0_DATA5        0x01B4
#define  CONTROL_PADCONF_HSUSB0_DATA6        0x01B6
#define  CONTROL_PADCONF_HSUSB0_DATA7        0x01B8
#define  CONTROL_PADCONF_I2C1_SCL            0x01BA
#define  CONTROL_PADCONF_I2C1_SDA            0x01BC
#define  CONTROL_PADCONF_I2C2_SCL            0x01BE
#define  CONTROL_PADCONF_I2C2_SDA            0x01C0
#define  CONTROL_PADCONF_I2C3_SCL            0x01C2
#define  CONTROL_PADCONF_I2C3_SDA            0x01C4
#define  CONTROL_PADCONF_I2C4_SCL            0x0A00
#define  CONTROL_PADCONF_I2C4_SDA            0x0A02
#define  CONTROL_PADCONF_HDQ_SIO             0x01C6
#define  CONTROL_PADCONF_McSPI1_CLK          0x01C8
#define  CONTROL_PADCONF_McSPI1_SIMO         0x01CA
#define  CONTROL_PADCONF_McSPI1_SOMI         0x01CC
#define  CONTROL_PADCONF_McSPI1_CS0          0x01CE
#define  CONTROL_PADCONF_McSPI1_CS1          0x01D0
#define  CONTROL_PADCONF_McSPI1_CS2          0x01D2
#define  CONTROL_PADCONF_McSPI1_CS3          0x01D4
#define  CONTROL_PADCONF_McSPI2_CLK          0x01D6
#define  CONTROL_PADCONF_McSPI2_SIMO         0x01D8
#define  CONTROL_PADCONF_McSPI2_SOMI         0x01DA
#define  CONTROL_PADCONF_McSPI2_CS0          0x01DC
#define  CONTROL_PADCONF_McSPI2_CS1          0x01DE
/*Control and debug */
#define  CONTROL_PADCONF_SYS_32K             0x0A04
#define  CONTROL_PADCONF_SYS_CLKREQ          0x0A06
#define  CONTROL_PADCONF_SYS_nIRQ            0x01E0
#define  CONTROL_PADCONF_SYS_BOOT0           0x0A0A
#define  CONTROL_PADCONF_SYS_BOOT1           0x0A0C
#define  CONTROL_PADCONF_SYS_BOOT2           0x0A0E
#define  CONTROL_PADCONF_SYS_BOOT3           0x0A10
#define  CONTROL_PADCONF_SYS_BOOT4           0x0A12
#define  CONTROL_PADCONF_SYS_BOOT5           0x0A14
#define  CONTROL_PADCONF_SYS_BOOT6           0x0A16
#define  CONTROL_PADCONF_SYS_OFF_MODE        0x0A18
#define  CONTROL_PADCONF_SYS_CLKOUT1         0x0A1A
#define  CONTROL_PADCONF_SYS_CLKOUT2         0x01E2
#define  CONTROL_PADCONF_JTAG_nTRST          0x0A1C
#define  CONTROL_PADCONF_JTAG_TCK            0x0A1E
#define  CONTROL_PADCONF_JTAG_TMS            0x0A20
#define  CONTROL_PADCONF_JTAG_TDI            0x0A22
#define  CONTROL_PADCONF_JTAG_EMU0           0x0A24
#define  CONTROL_PADCONF_JTAG_EMU1           0x0A26
#define  CONTROL_PADCONF_ETK_CLK             0x0A28
#define  CONTROL_PADCONF_ETK_CTL             0x0A2A
#define  CONTROL_PADCONF_ETK_D0              0x0A2C
#define  CONTROL_PADCONF_ETK_D1              0x0A2E
#define  CONTROL_PADCONF_ETK_D2              0x0A30
#define  CONTROL_PADCONF_ETK_D3              0x0A32
#define  CONTROL_PADCONF_ETK_D4              0x0A34
#define  CONTROL_PADCONF_ETK_D5              0x0A36
#define  CONTROL_PADCONF_ETK_D6              0x0A38
#define  CONTROL_PADCONF_ETK_D7              0x0A3A
#define  CONTROL_PADCONF_ETK_D8              0x0A3C
#define  CONTROL_PADCONF_ETK_D9              0x0A3E
#define  CONTROL_PADCONF_ETK_D10             0x0A40
#define  CONTROL_PADCONF_ETK_D11             0x0A42
#define  CONTROL_PADCONF_ETK_D12             0x0A44
#define  CONTROL_PADCONF_ETK_D13             0x0A46
#define  CONTROL_PADCONF_ETK_D14             0x0A48
#define  CONTROL_PADCONF_ETK_D15             0x0A4A
#define  CONTROL_PADCONF_ETK_CLK_ES2         0x05D8
#define  CONTROL_PADCONF_ETK_CTL_ES2         0x05DA
#define  CONTROL_PADCONF_ETK_D0_ES2          0x05DC
#define  CONTROL_PADCONF_ETK_D1_ES2          0x05DE
#define  CONTROL_PADCONF_ETK_D2_ES2          0x05E0
#define  CONTROL_PADCONF_ETK_D3_ES2          0x05E2
#define  CONTROL_PADCONF_ETK_D4_ES2          0x05E4
#define  CONTROL_PADCONF_ETK_D5_ES2          0x05E6
#define  CONTROL_PADCONF_ETK_D6_ES2          0x05E8
#define  CONTROL_PADCONF_ETK_D7_ES2          0x05EA
#define  CONTROL_PADCONF_ETK_D8_ES2          0x05EC
#define  CONTROL_PADCONF_ETK_D9_ES2          0x05EE
#define  CONTROL_PADCONF_ETK_D10_ES2         0x05F0
#define  CONTROL_PADCONF_ETK_D11_ES2         0x05F2
#define  CONTROL_PADCONF_ETK_D12_ES2         0x05F4
#define  CONTROL_PADCONF_ETK_D13_ES2         0x05F6
#define  CONTROL_PADCONF_ETK_D14_ES2         0x05F8
#define  CONTROL_PADCONF_ETK_D15_ES2         0x05FA
/*Die to Die */
#define  CONTROL_PADCONF_d2d_mcad0           0x01E4
#define  CONTROL_PADCONF_d2d_mcad1           0x01E6
#define  CONTROL_PADCONF_d2d_mcad2           0x01E8
#define  CONTROL_PADCONF_d2d_mcad3           0x01EA
#define  CONTROL_PADCONF_d2d_mcad4           0x01EC
#define  CONTROL_PADCONF_d2d_mcad5           0x01EE
#define  CONTROL_PADCONF_d2d_mcad6           0x01F0
#define  CONTROL_PADCONF_d2d_mcad7           0x01F2
#define  CONTROL_PADCONF_d2d_mcad8           0x01F4
#define  CONTROL_PADCONF_d2d_mcad9           0x01F6
#define  CONTROL_PADCONF_d2d_mcad10          0x01F8
#define  CONTROL_PADCONF_d2d_mcad11          0x01FA
#define  CONTROL_PADCONF_d2d_mcad12          0x01FC
#define  CONTROL_PADCONF_d2d_mcad13          0x01FE
#define  CONTROL_PADCONF_d2d_mcad14          0x0200
#define  CONTROL_PADCONF_d2d_mcad15          0x0202
#define  CONTROL_PADCONF_d2d_mcad16          0x0204
#define  CONTROL_PADCONF_d2d_mcad17          0x0206
#define  CONTROL_PADCONF_d2d_mcad18          0x0208
#define  CONTROL_PADCONF_d2d_mcad19          0x020A
#define  CONTROL_PADCONF_d2d_mcad20          0x020C
#define  CONTROL_PADCONF_d2d_mcad21          0x020E
#define  CONTROL_PADCONF_d2d_mcad22          0x0210
#define  CONTROL_PADCONF_d2d_mcad23          0x0212
#define  CONTROL_PADCONF_d2d_mcad24          0x0214
#define  CONTROL_PADCONF_d2d_mcad25          0x0216
#define  CONTROL_PADCONF_d2d_mcad26          0x0218
#define  CONTROL_PADCONF_d2d_mcad27          0x021A
#define  CONTROL_PADCONF_d2d_mcad28          0x021C
#define  CONTROL_PADCONF_d2d_mcad29          0x021E
#define  CONTROL_PADCONF_d2d_mcad30          0x0220
#define  CONTROL_PADCONF_d2d_mcad31          0x0222
#define  CONTROL_PADCONF_d2d_mcad32          0x0224
#define  CONTROL_PADCONF_d2d_mcad33          0x0226
#define  CONTROL_PADCONF_d2d_mcad34          0x0228
#define  CONTROL_PADCONF_d2d_mcad35          0x022A
#define  CONTROL_PADCONF_d2d_mcad36          0x022C
#define  CONTROL_PADCONF_d2d_clk26mi         0x022E
#define  CONTROL_PADCONF_d2d_nrespwron       0x0230
#define  CONTROL_PADCONF_d2d_nreswarm        0x0232
#define  CONTROL_PADCONF_d2d_arm9nirq        0x0234
#define  CONTROL_PADCONF_d2d_uma2p6fiq       0x0236
#define  CONTROL_PADCONF_d2d_spint           0x0238
#define  CONTROL_PADCONF_d2d_frint           0x023A
#define  CONTROL_PADCONF_d2d_dmareq0         0x023C
#define  CONTROL_PADCONF_d2d_dmareq1         0x023E
#define  CONTROL_PADCONF_d2d_dmareq2         0x0240
#define  CONTROL_PADCONF_d2d_dmareq3         0x0242
#define  CONTROL_PADCONF_d2d_n3gtrst         0x0244
#define  CONTROL_PADCONF_d2d_n3gtdi          0x0246
#define  CONTROL_PADCONF_d2d_n3gtdo          0x0248
#define  CONTROL_PADCONF_d2d_n3gtms          0x024A
#define  CONTROL_PADCONF_d2d_n3gtck          0x024C
#define  CONTROL_PADCONF_d2d_n3grtck         0x024E
#define  CONTROL_PADCONF_d2d_mstdby          0x0250
#define  CONTROL_PADCONF_d2d_swakeup         0x0A4C
#define  CONTROL_PADCONF_d2d_idlereq         0x0252
#define  CONTROL_PADCONF_d2d_idleack         0x0254
#define  CONTROL_PADCONF_d2d_mwrite          0x0256
#define  CONTROL_PADCONF_d2d_swrite          0x0258
#define  CONTROL_PADCONF_d2d_mread           0x025A
#define  CONTROL_PADCONF_d2d_sread           0x025C
#define  CONTROL_PADCONF_d2d_mbusflag        0x025E
#define  CONTROL_PADCONF_d2d_sbusflag        0x0260
#define  CONTROL_PADCONF_sdrc_cke0	     0x0262
#define  CONTROL_PADCONF_sdrc_cke1	     0x0264

#define 	MUX_VAL(OFFSET,VALUE)\
		__raw_writew((VALUE), OMAP34XX_CTRL_BASE + (OFFSET));

#define		CP(x)	(CONTROL_PADCONF_##x)

/*
 * IEN  - Input Enable
 * IDIS - Input Disable
 * PTD  - Pull type Down
 * PTU  - Pull type Up
 * DIS  - Pull type selection is inactive
 * EN   - Pull type selection is active
 * M0   - Mode 0
 * The commented string gives the final mux configuration for that pin
 */
#define MUX_DEFAULT_ES2() \
	/*SDRC*/\
	MUX_VAL(CP(SDRC_D0),        (IEN  | PTD | DIS | M0)) /*SDRC_D0*/\
	MUX_VAL(CP(SDRC_D1),        (IEN  | PTD | DIS | M0)) /*SDRC_D1*/\
	MUX_VAL(CP(SDRC_D2),        (IEN  | PTD | DIS | M0)) /*SDRC_D2*/\
	MUX_VAL(CP(SDRC_D3),        (IEN  | PTD | DIS | M0)) /*SDRC_D3*/\
	MUX_VAL(CP(SDRC_D4),        (IEN  | PTD | DIS | M0)) /*SDRC_D4*/\
	MUX_VAL(CP(SDRC_D5),        (IEN  | PTD | DIS | M0)) /*SDRC_D5*/\
	MUX_VAL(CP(SDRC_D6),        (IEN  | PTD | DIS | M0)) /*SDRC_D6*/\
	MUX_VAL(CP(SDRC_D7),        (IEN  | PTD | DIS | M0)) /*SDRC_D7*/\
	MUX_VAL(CP(SDRC_D8),        (IEN  | PTD | DIS | M0)) /*SDRC_D8*/\
	MUX_VAL(CP(SDRC_D9),        (IEN  | PTD | DIS | M0)) /*SDRC_D9*/\
	MUX_VAL(CP(SDRC_D10),       (IEN  | PTD | DIS | M0)) /*SDRC_D10*/\
	MUX_VAL(CP(SDRC_D11),       (IEN  | PTD | DIS | M0)) /*SDRC_D11*/\
	MUX_VAL(CP(SDRC_D12),       (IEN  | PTD | DIS | M0)) /*SDRC_D12*/\
	MUX_VAL(CP(SDRC_D13),       (IEN  | PTD | DIS | M0)) /*SDRC_D13*/\
	MUX_VAL(CP(SDRC_D14),       (IEN  | PTD | DIS | M0)) /*SDRC_D14*/\
	MUX_VAL(CP(SDRC_D15),       (IEN  | PTD | DIS | M0)) /*SDRC_D15*/\
	MUX_VAL(CP(SDRC_D16),       (IEN  | PTD | DIS | M0)) /*SDRC_D16*/\
	MUX_VAL(CP(SDRC_D17),       (IEN  | PTD | DIS | M0)) /*SDRC_D17*/\
	MUX_VAL(CP(SDRC_D18),       (IEN  | PTD | DIS | M0)) /*SDRC_D18*/\
	MUX_VAL(CP(SDRC_D19),       (IEN  | PTD | DIS | M0)) /*SDRC_D19*/\
	MUX_VAL(CP(SDRC_D20),       (IEN  | PTD | DIS | M0)) /*SDRC_D20*/\
	MUX_VAL(CP(SDRC_D21),       (IEN  | PTD | DIS | M0)) /*SDRC_D21*/\
	MUX_VAL(CP(SDRC_D22),       (IEN  | PTD | DIS | M0)) /*SDRC_D22*/\
	MUX_VAL(CP(SDRC_D23),       (IEN  | PTD | DIS | M0)) /*SDRC_D23*/\
	MUX_VAL(CP(SDRC_D24),       (IEN  | PTD | DIS | M0)) /*SDRC_D24*/\
	MUX_VAL(CP(SDRC_D25),       (IEN  | PTD | DIS | M0)) /*SDRC_D25*/\
	MUX_VAL(CP(SDRC_D26),       (IEN  | PTD | DIS | M0)) /*SDRC_D26*/\
	MUX_VAL(CP(SDRC_D27),       (IEN  | PTD | DIS | M0)) /*SDRC_D27*/\
	MUX_VAL(CP(SDRC_D28),       (IEN  | PTD | DIS | M0)) /*SDRC_D28*/\
	MUX_VAL(CP(SDRC_D29),       (IEN  | PTD | DIS | M0)) /*SDRC_D29*/\
	MUX_VAL(CP(SDRC_D30),       (IEN  | PTD | DIS | M0)) /*SDRC_D30*/\
	MUX_VAL(CP(SDRC_D31),       (IEN  | PTD | DIS | M0)) /*SDRC_D31*/\
	MUX_VAL(CP(SDRC_CLK),       (IEN  | PTD | DIS | M0)) /*SDRC_CLK*/\
	MUX_VAL(CP(SDRC_DQS0),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS0*/\
	MUX_VAL(CP(SDRC_DQS1),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS1*/\
	MUX_VAL(CP(SDRC_DQS2),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS2*/\
	MUX_VAL(CP(SDRC_DQS3),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS3*/\
	/*GPMC*/\
	MUX_VAL(CP(GPMC_A1),        (IDIS | PTD | DIS | M0)) /*GPMC_A1*/\
	MUX_VAL(CP(GPMC_A2),        (IDIS | PTD | DIS | M0)) /*GPMC_A2*/\
	MUX_VAL(CP(GPMC_A3),        (IDIS | PTD | DIS | M0)) /*GPMC_A3*/\
	MUX_VAL(CP(GPMC_A4),        (IDIS | PTD | DIS | M0)) /*GPMC_A4*/\
	MUX_VAL(CP(GPMC_A5),        (IDIS | PTD | DIS | M0)) /*GPMC_A5*/\
	MUX_VAL(CP(GPMC_A6),        (IDIS | PTD | DIS | M0)) /*GPMC_A6*/\
	MUX_VAL(CP(GPMC_A7),        (IDIS | PTD | DIS | M0)) /*GPMC_A7*/\
	MUX_VAL(CP(GPMC_A8),        (IDIS | PTD | DIS | M0)) /*GPMC_A8*/\
	MUX_VAL(CP(GPMC_A9),        (IDIS | PTD | DIS | M0)) /*GPMC_A9*/\
	MUX_VAL(CP(GPMC_A10),       (IDIS | PTD | DIS | M0)) /*GPMC_A10*/\
	MUX_VAL(CP(GPMC_D0),        (IEN  | PTD | DIS | M0)) /*GPMC_D0*/\
	MUX_VAL(CP(GPMC_D1),        (IEN  | PTD | DIS | M0)) /*GPMC_D1*/\
	MUX_VAL(CP(GPMC_D2),        (IEN  | PTD | DIS | M0)) /*GPMC_D2*/\
	MUX_VAL(CP(GPMC_D3),        (IEN  | PTD | DIS | M0)) /*GPMC_D3*/\
	MUX_VAL(CP(GPMC_D4),        (IEN  | PTD | DIS | M0)) /*GPMC_D4*/\
	MUX_VAL(CP(GPMC_D5),        (IEN  | PTD | DIS | M0)) /*GPMC_D5*/\
	MUX_VAL(CP(GPMC_D6),        (IEN  | PTD | DIS | M0)) /*GPMC_D6*/\
	MUX_VAL(CP(GPMC_D7),        (IEN  | PTD | DIS | M0)) /*GPMC_D7*/\
	MUX_VAL(CP(GPMC_D8),        (IEN  | PTD | DIS | M0)) /*GPMC_D8*/\
	MUX_VAL(CP(GPMC_D9),        (IEN  | PTD | DIS | M0)) /*GPMC_D9*/\
	MUX_VAL(CP(GPMC_D10),       (IEN  | PTD | DIS | M0)) /*GPMC_D10*/\
	MUX_VAL(CP(GPMC_D11),       (IEN  | PTD | DIS | M0)) /*GPMC_D11*/\
	MUX_VAL(CP(GPMC_D12),       (IEN  | PTD | DIS | M0)) /*GPMC_D12*/\
	MUX_VAL(CP(GPMC_D13),       (IEN  | PTD | DIS | M0)) /*GPMC_D13*/\
	MUX_VAL(CP(GPMC_D14),       (IEN  | PTD | DIS | M0)) /*GPMC_D14*/\
	MUX_VAL(CP(GPMC_D15),       (IEN  | PTD | DIS | M0)) /*GPMC_D15*/\
	MUX_VAL(CP(GPMC_nCS0),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS0*/\
	MUX_VAL(CP(GPMC_nCS1),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS1*/\
	MUX_VAL(CP(GPMC_nCS2),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS2*/\
	MUX_VAL(CP(GPMC_nCS3),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS3*/\
	/* For Beagle Rev 2 boards*/\
	MUX_VAL(CP(GPMC_nCS4),      (IDIS | PTU | EN  | M0))\
	MUX_VAL(CP(GPMC_nCS5),      (IDIS | PTD | DIS | M0))\
	MUX_VAL(CP(GPMC_nCS6),      (IEN  | PTD | DIS | M1))\
	MUX_VAL(CP(GPMC_nCS7),      (IEN  | PTU | EN  | M1))\
	MUX_VAL(CP(GPMC_nBE1),      (IEN  | PTD | DIS | M0))\
	MUX_VAL(CP(GPMC_WAIT2),     (IEN  | PTU | EN  | M0))\
	MUX_VAL(CP(GPMC_WAIT3),     (IEN  | PTU | EN  | M0))\
	/* till here */							\
	MUX_VAL(CP(GPMC_CLK),       (IDIS | PTD | DIS | M0)) /*GPMC_CLK*/\
	MUX_VAL(CP(GPMC_nADV_ALE),  (IDIS | PTD | DIS | M0)) /*GPMC_nADV_ALE*/\
	MUX_VAL(CP(GPMC_nOE),       (IDIS | PTD | DIS | M0)) /*GPMC_nOE*/\
	MUX_VAL(CP(GPMC_nWE),       (IDIS | PTD | DIS | M0)) /*GPMC_nWE*/\
	MUX_VAL(CP(GPMC_nBE0_CLE),  (IDIS | PTD | DIS | M0)) /*GPMC_nBE0_CLE*/\
	MUX_VAL(CP(GPMC_nWP),       (IEN  | PTD | DIS | M0)) /*GPMC_nWP*/\
	MUX_VAL(CP(GPMC_WAIT0),     (IEN  | PTU | EN  | M0)) /*GPMC_WAIT0*/\
	MUX_VAL(CP(GPMC_WAIT1),     (IEN  | PTU | EN  | M0)) /*GPMC_WAIT1*/\
	/*DSS*/\
	MUX_VAL(CP(DSS_PCLK),       (IDIS | PTD | DIS | M0)) /*DSS_PCLK*/\
	MUX_VAL(CP(DSS_HSYNC),      (IDIS | PTD | DIS | M0)) /*DSS_HSYNC*/\
	MUX_VAL(CP(DSS_VSYNC),      (IDIS | PTD | DIS | M0)) /*DSS_VSYNC*/\
	MUX_VAL(CP(DSS_ACBIAS),     (IDIS | PTD | DIS | M0)) /*DSS_ACBIAS*/\
	MUX_VAL(CP(DSS_DATA0),      (IDIS | PTD | DIS | M0)) /*DSS_DATA0*/\
	MUX_VAL(CP(DSS_DATA1),      (IDIS | PTD | DIS | M0)) /*DSS_DATA1*/\
	MUX_VAL(CP(DSS_DATA2),      (IDIS | PTD | DIS | M0)) /*DSS_DATA2*/\
	MUX_VAL(CP(DSS_DATA3),      (IDIS | PTD | DIS | M0)) /*DSS_DATA3*/\
	MUX_VAL(CP(DSS_DATA4),      (IDIS | PTD | DIS | M0)) /*DSS_DATA4*/\
	MUX_VAL(CP(DSS_DATA5),      (IDIS | PTD | DIS | M0)) /*DSS_DATA5*/\
	MUX_VAL(CP(DSS_DATA6),      (IDIS | PTD | DIS | M0)) /*DSS_DATA6*/\
	MUX_VAL(CP(DSS_DATA7),      (IDIS | PTD | DIS | M0)) /*DSS_DATA7*/\
	MUX_VAL(CP(DSS_DATA8),      (IDIS | PTD | DIS | M0)) /*DSS_DATA8*/\
	MUX_VAL(CP(DSS_DATA9),      (IDIS | PTD | DIS | M0)) /*DSS_DATA9*/\
	MUX_VAL(CP(DSS_DATA10),     (IDIS | PTD | DIS | M0)) /*DSS_DATA10*/\
	MUX_VAL(CP(DSS_DATA11),     (IDIS | PTD | DIS | M0)) /*DSS_DATA11*/\
	MUX_VAL(CP(DSS_DATA12),     (IDIS | PTD | DIS | M0)) /*DSS_DATA12*/\
	MUX_VAL(CP(DSS_DATA13),     (IDIS | PTD | DIS | M0)) /*DSS_DATA13*/\
	MUX_VAL(CP(DSS_DATA14),     (IDIS | PTD | DIS | M0)) /*DSS_DATA14*/\
	MUX_VAL(CP(DSS_DATA15),     (IDIS | PTD | DIS | M0)) /*DSS_DATA15*/\
	MUX_VAL(CP(DSS_DATA16),     (IDIS | PTD | DIS | M0)) /*DSS_DATA16*/\
	MUX_VAL(CP(DSS_DATA17),     (IDIS | PTD | DIS | M0)) /*DSS_DATA17*/\
	MUX_VAL(CP(DSS_DATA18),     (IDIS | PTD | DIS | M0)) /*DSS_DATA18*/\
	MUX_VAL(CP(DSS_DATA19),     (IDIS | PTD | DIS | M0)) /*DSS_DATA19*/\
	MUX_VAL(CP(DSS_DATA20),     (IDIS | PTD | DIS | M0)) /*DSS_DATA20*/\
	MUX_VAL(CP(DSS_DATA21),     (IDIS | PTD | DIS | M0)) /*DSS_DATA21*/\
	MUX_VAL(CP(DSS_DATA22),     (IDIS | PTD | DIS | M0)) /*DSS_DATA22*/\
	MUX_VAL(CP(DSS_DATA23),     (IDIS | PTD | DIS | M0)) /*DSS_DATA23*/\
	/*CAMERA*/\
	MUX_VAL(CP(CAM_HS),         (IEN  | PTU | EN  | M0)) /*CAM_HS */\
	MUX_VAL(CP(CAM_VS),         (IEN  | PTU | EN  | M0)) /*CAM_VS */\
	MUX_VAL(CP(CAM_XCLKA),      (IDIS | PTD | DIS | M0)) /*CAM_XCLKA*/\
	MUX_VAL(CP(CAM_PCLK),       (IEN  | PTU | EN  | M0)) /*CAM_PCLK*/\
	MUX_VAL(CP(CAM_FLD),        (IDIS | PTD | DIS | M4)) /*GPIO_98*/\
							     /* - CAM_RESET*/\
	MUX_VAL(CP(CAM_D0),         (IEN  | PTD | DIS | M0)) /*CAM_D0*/\
	MUX_VAL(CP(CAM_D1),         (IEN  | PTD | DIS | M0)) /*CAM_D1*/\
	MUX_VAL(CP(CAM_D2),         (IEN  | PTD | DIS | M0)) /*CAM_D2*/\
	MUX_VAL(CP(CAM_D3),         (IEN  | PTD | DIS | M0)) /*CAM_D3*/\
	MUX_VAL(CP(CAM_D4),         (IEN  | PTD | DIS | M0)) /*CAM_D4*/\
	MUX_VAL(CP(CAM_D5),         (IEN  | PTD | DIS | M0)) /*CAM_D5*/\
	MUX_VAL(CP(CAM_D6),         (IEN  | PTD | DIS | M0)) /*CAM_D6*/\
	MUX_VAL(CP(CAM_D7),         (IEN  | PTD | DIS | M0)) /*CAM_D7*/\
	MUX_VAL(CP(CAM_D8),         (IEN  | PTD | DIS | M0)) /*CAM_D8*/\
	MUX_VAL(CP(CAM_D9),         (IEN  | PTD | DIS | M0)) /*CAM_D9*/\
	MUX_VAL(CP(CAM_D10),        (IEN  | PTD | DIS | M0)) /*CAM_D10*/\
	MUX_VAL(CP(CAM_D11),        (IEN  | PTD | DIS | M0)) /*CAM_D11*/\
	MUX_VAL(CP(CAM_XCLKB),      (IDIS | PTD | DIS | M0)) /*CAM_XCLKB*/\
	MUX_VAL(CP(CAM_WEN),        (IEN  | PTD | DIS | M4)) /*GPIO_167*/\
	MUX_VAL(CP(CAM_STROBE),     (IDIS | PTD | DIS | M0)) /*CAM_STROBE*/\
	MUX_VAL(CP(CSI2_DX0),       (IEN  | PTD | DIS | M0)) /*CSI2_DX0*/\
	MUX_VAL(CP(CSI2_DY0),       (IEN  | PTD | DIS | M0)) /*CSI2_DY0*/\
	MUX_VAL(CP(CSI2_DX1),       (IEN  | PTD | DIS | M0)) /*CSI2_DX1*/\
	MUX_VAL(CP(CSI2_DY1),       (IEN  | PTD | DIS | M0)) /*CSI2_DY1*/\
	/*Audio Interface */\
	MUX_VAL(CP(McBSP2_FSX),     (IEN  | PTD | DIS | M0)) /*McBSP2_FSX*/\
	MUX_VAL(CP(McBSP2_CLKX),    (IEN  | PTD | DIS | M0)) /*McBSP2_CLKX*/\
	MUX_VAL(CP(McBSP2_DR),      (IEN  | PTD | DIS | M0)) /*McBSP2_DR*/\
	MUX_VAL(CP(McBSP2_DX),      (IDIS | PTD | DIS | M0)) /*McBSP2_DX*/\
	/*Expansion card  */\
	MUX_VAL(CP(MMC1_CLK),       (IDIS | PTU | EN  | M0)) /*MMC1_CLK*/\
	MUX_VAL(CP(MMC1_CMD),       (IEN  | PTU | EN  | M0)) /*MMC1_CMD*/\
	MUX_VAL(CP(MMC1_DAT0),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT0*/\
	MUX_VAL(CP(MMC1_DAT1),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT1*/\
	MUX_VAL(CP(MMC1_DAT2),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT2*/\
	MUX_VAL(CP(MMC1_DAT3),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT3*/\
	MUX_VAL(CP(MMC1_DAT4),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT4*/\
	MUX_VAL(CP(MMC1_DAT5),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT5*/\
	MUX_VAL(CP(MMC1_DAT6),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT6*/\
	MUX_VAL(CP(MMC1_DAT7),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT7*/\
	/*Wireless LAN */\
	MUX_VAL(CP(MMC2_CLK),       (IEN  | PTU | EN  | M4)) /*GPIO_130*/\
	MUX_VAL(CP(MMC2_CMD),       (IEN  | PTU | EN  | M4)) /*GPIO_131*/\
	MUX_VAL(CP(MMC2_DAT0),      (IEN  | PTU | EN  | M4)) /*GPIO_132*/\
	MUX_VAL(CP(MMC2_DAT1),      (IEN  | PTU | EN  | M4)) /*GPIO_133*/\
	MUX_VAL(CP(MMC2_DAT2),      (IEN  | PTU | EN  | M4)) /*GPIO_134*/\
	MUX_VAL(CP(MMC2_DAT3),      (IEN  | PTU | EN  | M4)) /*GPIO_135*/\
	MUX_VAL(CP(MMC2_DAT4),      (IEN  | PTU | EN  | M4)) /*GPIO_136*/\
	MUX_VAL(CP(MMC2_DAT5),      (IEN  | PTU | EN  | M4)) /*GPIO_137*/\
	MUX_VAL(CP(MMC2_DAT6),      (IEN  | PTU | EN  | M4)) /*GPIO_138*/\
	MUX_VAL(CP(MMC2_DAT7),      (IEN  | PTU | EN  | M4)) /*GPIO_139*/\
	/*Bluetooth*/\
	MUX_VAL(CP(McBSP3_DX),      (IDIS | PTD | DIS | M4)) /*GPIO_140*/\
	MUX_VAL(CP(McBSP3_DR),      (IDIS | PTD | DIS | M4)) /*GPIO_142*/\
	MUX_VAL(CP(McBSP3_CLKX),    (IDIS | PTD | DIS | M4)) /*GPIO_141*/\
	MUX_VAL(CP(McBSP3_FSX),     (IDIS | PTD | DIS | M4)) /*GPIO_143*/\
	MUX_VAL(CP(UART2_CTS),      (IEN  | PTU | EN  | M0)) /*UART2_CTS*/\
	MUX_VAL(CP(UART2_RTS),      (IDIS | PTD | DIS | M0)) /*UART2_RTS*/\
	MUX_VAL(CP(UART2_TX),       (IDIS | PTD | DIS | M0)) /*UART2_TX*/\
	MUX_VAL(CP(UART2_RX),       (IEN  | PTD | DIS | M0)) /*UART2_RX*/\
	/*Modem Interface */\
	MUX_VAL(CP(UART1_TX),       (IDIS | PTD | DIS | M0)) /*UART1_TX*/\
	MUX_VAL(CP(UART1_RTS),      (IDIS | PTD | DIS | M4)) /*GPIO_149*/ \
	MUX_VAL(CP(UART1_CTS),      (IDIS | PTD | DIS | M4)) /*GPIO_150*/ \
	MUX_VAL(CP(UART1_RX),       (IEN  | PTD | DIS | M0)) /*UART1_RX*/\
	MUX_VAL(CP(McBSP4_CLKX),    (IEN  | PTD | DIS | M1)) /*SSI1_DAT_RX*/\
	MUX_VAL(CP(McBSP4_DR),      (IEN  | PTD | DIS | M1)) /*SSI1_FLAG_RX*/\
	MUX_VAL(CP(McBSP4_DX),      (IEN  | PTD | DIS | M1)) /*SSI1_RDY_RX*/\
	MUX_VAL(CP(McBSP4_FSX),     (IEN  | PTD | DIS | M1)) /*SSI1_WAKE*/\
	MUX_VAL(CP(McBSP1_CLKR),    (IDIS | PTD | DIS | M4)) /*GPIO_156*/\
	MUX_VAL(CP(McBSP1_FSR),     (IDIS | PTU | EN  | M4)) /*GPIO_157*/\
							     /* - BT_WAKEUP*/\
	MUX_VAL(CP(McBSP1_DX),      (IDIS | PTD | DIS | M4)) /*GPIO_158*/\
	MUX_VAL(CP(McBSP1_DR),      (IDIS | PTD | DIS | M4)) /*GPIO_159*/\
	MUX_VAL(CP(McBSP_CLKS),     (IEN  | PTU | DIS | M0)) /*McBSP_CLKS*/\
	MUX_VAL(CP(McBSP1_FSX),     (IDIS | PTD | DIS | M4)) /*GPIO_161*/\
	MUX_VAL(CP(McBSP1_CLKX),    (IDIS | PTD | DIS | M4)) /*GPIO_162*/\
	/*Serial Interface*/\
	MUX_VAL(CP(UART3_CTS_RCTX), (IEN  | PTD | EN  | M0)) /*UART3_CTS_*/\
							     /* RCTX*/\
	MUX_VAL(CP(UART3_RTS_SD),   (IDIS | PTD | DIS | M0)) /*UART3_RTS_SD */\
	MUX_VAL(CP(UART3_RX_IRRX),  (IEN  | PTD | DIS | M0)) /*UART3_RX_IRRX*/\
	MUX_VAL(CP(UART3_TX_IRTX),  (IDIS | PTD | DIS | M0)) /*UART3_TX_IRTX*/\
	MUX_VAL(CP(HSUSB0_CLK),     (IEN  | PTD | DIS | M0)) /*HSUSB0_CLK*/\
	MUX_VAL(CP(HSUSB0_STP),     (IDIS | PTU | EN  | M0)) /*HSUSB0_STP*/\
	MUX_VAL(CP(HSUSB0_DIR),     (IEN  | PTD | DIS | M0)) /*HSUSB0_DIR*/\
	MUX_VAL(CP(HSUSB0_NXT),     (IEN  | PTD | DIS | M0)) /*HSUSB0_NXT*/\
	MUX_VAL(CP(HSUSB0_DATA0),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA0*/\
	MUX_VAL(CP(HSUSB0_DATA1),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA1*/\
	MUX_VAL(CP(HSUSB0_DATA2),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA2*/\
	MUX_VAL(CP(HSUSB0_DATA3),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA3*/\
	MUX_VAL(CP(HSUSB0_DATA4),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA4*/\
	MUX_VAL(CP(HSUSB0_DATA5),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA5*/\
	MUX_VAL(CP(HSUSB0_DATA6),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA6*/\
	MUX_VAL(CP(HSUSB0_DATA7),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA7*/\
	MUX_VAL(CP(I2C1_SCL),       (IEN  | PTU | EN  | M0)) /*I2C1_SCL*/\
	MUX_VAL(CP(I2C1_SDA),       (IEN  | PTU | EN  | M0)) /*I2C1_SDA*/\
	MUX_VAL(CP(I2C2_SCL),       (IEN  | PTU | EN  | M4)) /*GPIO_168*/\
	MUX_VAL(CP(I2C2_SDA),       (IEN  | PTU | EN  | M4)) /*GPIO_183*/\
	MUX_VAL(CP(I2C3_SCL),       (IEN  | PTU | EN  | M0)) /*I2C3_SCL*/\
	MUX_VAL(CP(I2C3_SDA),       (IEN  | PTU | EN  | M0)) /*I2C3_SDA*/\
	MUX_VAL(CP(I2C4_SCL),       (IEN  | PTU | EN  | M0)) /*I2C4_SCL*/\
	MUX_VAL(CP(I2C4_SDA),       (IEN  | PTU | EN  | M0)) /*I2C4_SDA*/\
	MUX_VAL(CP(HDQ_SIO),        (IDIS | PTU | EN  | M4)) /*HDQ_SIO*/\
	MUX_VAL(CP(McSPI1_CLK),     (IEN  | PTD | DIS | M0)) /*McSPI1_CLK*/\
	MUX_VAL(CP(McSPI1_SIMO),    (IEN  | PTD | DIS | M0)) /*McSPI1_SIMO  */\
	MUX_VAL(CP(McSPI1_SOMI),    (IEN  | PTD | DIS | M0)) /*McSPI1_SOMI  */\
	MUX_VAL(CP(McSPI1_CS0),     (IEN  | PTD | EN  | M0)) /*McSPI1_CS0*/\
	MUX_VAL(CP(McSPI1_CS1),     (IDIS | PTD | EN  | M0)) /*McSPI1_CS1*/\
	MUX_VAL(CP(McSPI1_CS2),     (IDIS | PTD | DIS | M4)) /*GPIO_176*/\
							     /* - NOR_DPD*/\
	MUX_VAL(CP(McSPI1_CS3),     (IEN  | PTD | EN  | M0)) /*McSPI1_CS3*/\
	MUX_VAL(CP(McSPI2_CLK),     (IEN  | PTD | DIS | M0)) /*McSPI2_CLK*/\
	MUX_VAL(CP(McSPI2_SIMO),    (IEN  | PTD | DIS | M0)) /*McSPI2_SIMO*/\
	MUX_VAL(CP(McSPI2_SOMI),    (IEN  | PTD | DIS | M0)) /*McSPI2_SOMI*/\
	MUX_VAL(CP(McSPI2_CS0),     (IEN  | PTD | EN  | M0)) /*McSPI2_CS0*/\
	MUX_VAL(CP(McSPI2_CS1),     (IEN  | PTD | EN  | M0)) /*McSPI2_CS1*/\
	/*Control and debug */\
	MUX_VAL(CP(SYS_32K),        (IEN  | PTD | DIS | M0)) /*SYS_32K*/\
	MUX_VAL(CP(SYS_CLKREQ),     (IEN  | PTD | DIS | M0)) /*SYS_CLKREQ*/\
	MUX_VAL(CP(SYS_nIRQ),       (IEN  | PTU | EN  | M0)) /*SYS_nIRQ*/\
	MUX_VAL(CP(SYS_BOOT0),      (IEN  | PTD | DIS | M4)) /*GPIO_2*/\
							     /* - PEN_IRQ */\
	MUX_VAL(CP(SYS_BOOT1),      (IEN  | PTD | DIS | M4)) /*GPIO_3 */\
	MUX_VAL(CP(SYS_BOOT2),      (IEN  | PTD | DIS | M4)) /*GPIO_4*/\
							     /* - MMC1_WP */\
	MUX_VAL(CP(SYS_BOOT3),      (IEN  | PTD | DIS | M4)) /*GPIO_5*/\
							     /* - LCD_ENVDD*/\
	MUX_VAL(CP(SYS_BOOT4),      (IEN  | PTD | DIS | M4)) /*GPIO_6*/\
							     /* - LAN_INTR0*/\
	MUX_VAL(CP(SYS_BOOT5),      (IEN  | PTD | DIS | M4)) /*GPIO_7*/\
							     /* - MMC2_WP*/\
	MUX_VAL(CP(SYS_BOOT6),      (IDIS  | PTD | DIS | M4)) /*GPIO_8*/\
							     /* - LCD_ENBKL*/\
	MUX_VAL(CP(SYS_OFF_MODE),   (IEN  | PTD | DIS | M0)) /*SYS_OFF_MODE*/\
	MUX_VAL(CP(SYS_CLKOUT1),    (IEN  | PTD | DIS | M0)) /*SYS_CLKOUT1*/\
	MUX_VAL(CP(SYS_CLKOUT2),    (IEN  | PTU | EN  | M4)) /*GPIO_186*/\
	MUX_VAL(CP(ETK_CLK_ES2),    (IDIS | PTU | EN  | M3)) /*HSUSB1_STP*/\
	MUX_VAL(CP(ETK_CTL_ES2),    (IDIS | PTD | DIS | M3)) /*HSUSB1_CLK*/\
	MUX_VAL(CP(ETK_D0_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA0*/\
	MUX_VAL(CP(ETK_D1_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA1*/\
	MUX_VAL(CP(ETK_D2_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA2*/\
	MUX_VAL(CP(ETK_D3_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA7*/\
	MUX_VAL(CP(ETK_D4_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA4*/\
	MUX_VAL(CP(ETK_D5_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA5*/\
	MUX_VAL(CP(ETK_D6_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA6*/\
	MUX_VAL(CP(ETK_D7_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DATA3*/\
	MUX_VAL(CP(ETK_D8_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_DIR*/\
	MUX_VAL(CP(ETK_D9_ES2),     (IEN  | PTD | DIS | M3)) /*HSUSB1_NXT*/\
	MUX_VAL(CP(ETK_D10_ES2),    (IDIS | PTU | EN  | M4)) /*GPIO_24*/\
	MUX_VAL(CP(ETK_D15),        (IEN  | PTU | EN  | M4)) /*GPIO_29*/\
	MUX_VAL(CP(d2d_mcad1),      (IEN  | PTD | EN  | M0)) /*d2d_mcad1*/\
	MUX_VAL(CP(d2d_mcad2),      (IEN  | PTD | EN  | M0)) /*d2d_mcad2*/\
	MUX_VAL(CP(d2d_mcad3),      (IEN  | PTD | EN  | M0)) /*d2d_mcad3*/\
	MUX_VAL(CP(d2d_mcad4),      (IEN  | PTD | EN  | M0)) /*d2d_mcad4*/\
	MUX_VAL(CP(d2d_mcad5),      (IEN  | PTD | EN  | M0)) /*d2d_mcad5*/\
	MUX_VAL(CP(d2d_mcad6),      (IEN  | PTD | EN  | M0)) /*d2d_mcad6*/\
	MUX_VAL(CP(d2d_mcad7),      (IEN  | PTD | EN  | M0)) /*d2d_mcad7*/\
	MUX_VAL(CP(d2d_mcad8),      (IEN  | PTD | EN  | M0)) /*d2d_mcad8*/\
	MUX_VAL(CP(d2d_mcad9),      (IEN  | PTD | EN  | M0)) /*d2d_mcad9*/\
	MUX_VAL(CP(d2d_mcad10),     (IEN  | PTD | EN  | M0)) /*d2d_mcad10*/\
	MUX_VAL(CP(d2d_mcad11),     (IEN  | PTD | EN  | M0)) /*d2d_mcad11*/\
	MUX_VAL(CP(d2d_mcad12),     (IEN  | PTD | EN  | M0)) /*d2d_mcad12*/\
	MUX_VAL(CP(d2d_mcad13),     (IEN  | PTD | EN  | M0)) /*d2d_mcad13*/\
	MUX_VAL(CP(d2d_mcad14),     (IEN  | PTD | EN  | M0)) /*d2d_mcad14*/\
	MUX_VAL(CP(d2d_mcad15),     (IEN  | PTD | EN  | M0)) /*d2d_mcad15*/\
	MUX_VAL(CP(d2d_mcad16),     (IEN  | PTD | EN  | M0)) /*d2d_mcad16*/\
	MUX_VAL(CP(d2d_mcad17),     (IEN  | PTD | EN  | M0)) /*d2d_mcad17*/\
	MUX_VAL(CP(d2d_mcad18),     (IEN  | PTD | EN  | M0)) /*d2d_mcad18*/\
	MUX_VAL(CP(d2d_mcad19),     (IEN  | PTD | EN  | M0)) /*d2d_mcad19*/\
	MUX_VAL(CP(d2d_mcad20),     (IEN  | PTD | EN  | M0)) /*d2d_mcad20*/\
	MUX_VAL(CP(d2d_mcad21),     (IEN  | PTD | EN  | M0)) /*d2d_mcad21*/\
	MUX_VAL(CP(d2d_mcad22),     (IEN  | PTD | EN  | M0)) /*d2d_mcad22*/\
	MUX_VAL(CP(d2d_mcad23),     (IEN  | PTD | EN  | M0)) /*d2d_mcad23*/\
	MUX_VAL(CP(d2d_mcad24),     (IEN  | PTD | EN  | M0)) /*d2d_mcad24*/\
	MUX_VAL(CP(d2d_mcad25),     (IEN  | PTD | EN  | M0)) /*d2d_mcad25*/\
	MUX_VAL(CP(d2d_mcad26),     (IEN  | PTD | EN  | M0)) /*d2d_mcad26*/\
	MUX_VAL(CP(d2d_mcad27),     (IEN  | PTD | EN  | M0)) /*d2d_mcad27*/\
	MUX_VAL(CP(d2d_mcad28),     (IEN  | PTD | EN  | M0)) /*d2d_mcad28*/\
	MUX_VAL(CP(d2d_mcad29),     (IEN  | PTD | EN  | M0)) /*d2d_mcad29*/\
	MUX_VAL(CP(d2d_mcad30),     (IEN  | PTD | EN  | M0)) /*d2d_mcad30*/\
	MUX_VAL(CP(d2d_mcad31),     (IEN  | PTD | EN  | M0)) /*d2d_mcad31*/\
	MUX_VAL(CP(d2d_mcad32),     (IEN  | PTD | EN  | M0)) /*d2d_mcad32*/\
	MUX_VAL(CP(d2d_mcad33),     (IEN  | PTD | EN  | M0)) /*d2d_mcad33*/\
	MUX_VAL(CP(d2d_mcad34),     (IEN  | PTD | EN  | M0)) /*d2d_mcad34*/\
	MUX_VAL(CP(d2d_mcad35),     (IEN  | PTD | EN  | M0)) /*d2d_mcad35*/\
	MUX_VAL(CP(d2d_mcad36),     (IEN  | PTD | EN  | M0)) /*d2d_mcad36*/\
	MUX_VAL(CP(d2d_clk26mi),    (IEN  | PTD | DIS | M0)) /*d2d_clk26mi*/\
	MUX_VAL(CP(d2d_nrespwron),  (IEN  | PTD | EN  | M0)) /*d2d_nrespwron*/\
	MUX_VAL(CP(d2d_nreswarm),   (IEN  | PTU | EN  | M0)) /*d2d_nreswarm */\
	MUX_VAL(CP(d2d_arm9nirq),   (IEN  | PTD | DIS | M0)) /*d2d_arm9nirq */\
	MUX_VAL(CP(d2d_uma2p6fiq),  (IEN  | PTD | DIS | M0)) /*d2d_uma2p6fiq*/\
	MUX_VAL(CP(d2d_spint),      (IEN  | PTD | EN  | M0)) /*d2d_spint*/\
	MUX_VAL(CP(d2d_frint),      (IEN  | PTD | EN  | M0)) /*d2d_frint*/\
	MUX_VAL(CP(d2d_dmareq0),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq0*/\
	MUX_VAL(CP(d2d_dmareq1),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq1*/\
	MUX_VAL(CP(d2d_dmareq2),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq2*/\
	MUX_VAL(CP(d2d_dmareq3),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq3*/\
	MUX_VAL(CP(d2d_n3gtrst),    (IEN  | PTD | DIS | M0)) /*d2d_n3gtrst*/\
	MUX_VAL(CP(d2d_n3gtdi),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtdi*/\
	MUX_VAL(CP(d2d_n3gtdo),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtdo*/\
	MUX_VAL(CP(d2d_n3gtms),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtms*/\
	MUX_VAL(CP(d2d_n3gtck),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtck*/\
	MUX_VAL(CP(d2d_n3grtck),    (IEN  | PTD | DIS | M0)) /*d2d_n3grtck*/\
	MUX_VAL(CP(d2d_mstdby),     (IEN  | PTU | EN  | M0)) /*d2d_mstdby*/\
	MUX_VAL(CP(d2d_swakeup),    (IEN  | PTD | EN  | M0)) /*d2d_swakeup*/\
	MUX_VAL(CP(d2d_idlereq),    (IEN  | PTD | DIS | M0)) /*d2d_idlereq*/\
	MUX_VAL(CP(d2d_idleack),    (IEN  | PTU | EN  | M0)) /*d2d_idleack*/\
	MUX_VAL(CP(d2d_mwrite),     (IEN  | PTD | DIS | M0)) /*d2d_mwrite*/\
	MUX_VAL(CP(d2d_swrite),     (IEN  | PTD | DIS | M0)) /*d2d_swrite*/\
	MUX_VAL(CP(d2d_mread),      (IEN  | PTD | DIS | M0)) /*d2d_mread*/\
	MUX_VAL(CP(d2d_sread),      (IEN  | PTD | DIS | M0)) /*d2d_sread*/\
	MUX_VAL(CP(d2d_mbusflag),   (IEN  | PTD | DIS | M0)) /*d2d_mbusflag*/\
	MUX_VAL(CP(d2d_sbusflag),   (IEN  | PTD | DIS | M0)) /*d2d_sbusflag*/\
	MUX_VAL(CP(sdrc_cke0),      (IDIS | PTU | EN  | M0)) /*sdrc_cke0*/\
	MUX_VAL(CP(sdrc_cke1),      (IDIS | PTD | DIS | M7)) /*sdrc_cke1*/\

#define MUX_DEFAULT_OVERO() \
	/*SDRC*/\
	MUX_VAL(CP(SDRC_D0),        (IEN  | PTD | DIS | M0)) /*SDRC_D0*/\
	MUX_VAL(CP(SDRC_D1),        (IEN  | PTD | DIS | M0)) /*SDRC_D1*/\
	MUX_VAL(CP(SDRC_D2),        (IEN  | PTD | DIS | M0)) /*SDRC_D2*/\
	MUX_VAL(CP(SDRC_D3),        (IEN  | PTD | DIS | M0)) /*SDRC_D3*/\
	MUX_VAL(CP(SDRC_D4),        (IEN  | PTD | DIS | M0)) /*SDRC_D4*/\
	MUX_VAL(CP(SDRC_D5),        (IEN  | PTD | DIS | M0)) /*SDRC_D5*/\
	MUX_VAL(CP(SDRC_D6),        (IEN  | PTD | DIS | M0)) /*SDRC_D6*/\
	MUX_VAL(CP(SDRC_D7),        (IEN  | PTD | DIS | M0)) /*SDRC_D7*/\
	MUX_VAL(CP(SDRC_D8),        (IEN  | PTD | DIS | M0)) /*SDRC_D8*/\
	MUX_VAL(CP(SDRC_D9),        (IEN  | PTD | DIS | M0)) /*SDRC_D9*/\
	MUX_VAL(CP(SDRC_D10),       (IEN  | PTD | DIS | M0)) /*SDRC_D10*/\
	MUX_VAL(CP(SDRC_D11),       (IEN  | PTD | DIS | M0)) /*SDRC_D11*/\
	MUX_VAL(CP(SDRC_D12),       (IEN  | PTD | DIS | M0)) /*SDRC_D12*/\
	MUX_VAL(CP(SDRC_D13),       (IEN  | PTD | DIS | M0)) /*SDRC_D13*/\
	MUX_VAL(CP(SDRC_D14),       (IEN  | PTD | DIS | M0)) /*SDRC_D14*/\
	MUX_VAL(CP(SDRC_D15),       (IEN  | PTD | DIS | M0)) /*SDRC_D15*/\
	MUX_VAL(CP(SDRC_D16),       (IEN  | PTD | DIS | M0)) /*SDRC_D16*/\
	MUX_VAL(CP(SDRC_D17),       (IEN  | PTD | DIS | M0)) /*SDRC_D17*/\
	MUX_VAL(CP(SDRC_D18),       (IEN  | PTD | DIS | M0)) /*SDRC_D18*/\
	MUX_VAL(CP(SDRC_D19),       (IEN  | PTD | DIS | M0)) /*SDRC_D19*/\
	MUX_VAL(CP(SDRC_D20),       (IEN  | PTD | DIS | M0)) /*SDRC_D20*/\
	MUX_VAL(CP(SDRC_D21),       (IEN  | PTD | DIS | M0)) /*SDRC_D21*/\
	MUX_VAL(CP(SDRC_D22),       (IEN  | PTD | DIS | M0)) /*SDRC_D22*/\
	MUX_VAL(CP(SDRC_D23),       (IEN  | PTD | DIS | M0)) /*SDRC_D23*/\
	MUX_VAL(CP(SDRC_D24),       (IEN  | PTD | DIS | M0)) /*SDRC_D24*/\
	MUX_VAL(CP(SDRC_D25),       (IEN  | PTD | DIS | M0)) /*SDRC_D25*/\
	MUX_VAL(CP(SDRC_D26),       (IEN  | PTD | DIS | M0)) /*SDRC_D26*/\
	MUX_VAL(CP(SDRC_D27),       (IEN  | PTD | DIS | M0)) /*SDRC_D27*/\
	MUX_VAL(CP(SDRC_D28),       (IEN  | PTD | DIS | M0)) /*SDRC_D28*/\
	MUX_VAL(CP(SDRC_D29),       (IEN  | PTD | DIS | M0)) /*SDRC_D29*/\
	MUX_VAL(CP(SDRC_D30),       (IEN  | PTD | DIS | M0)) /*SDRC_D30*/\
	MUX_VAL(CP(SDRC_D31),       (IEN  | PTD | DIS | M0)) /*SDRC_D31*/\
	MUX_VAL(CP(SDRC_CLK),       (IEN  | PTD | DIS | M0)) /*SDRC_CLK*/\
	MUX_VAL(CP(SDRC_DQS0),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS0*/\
	MUX_VAL(CP(SDRC_DQS1),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS1*/\
	MUX_VAL(CP(SDRC_DQS2),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS2*/\
	MUX_VAL(CP(SDRC_DQS3),      (IEN  | PTD | DIS | M0)) /*SDRC_DQS3*/\
	/*GPMC*/\
	MUX_VAL(CP(GPMC_A1),        (IDIS | PTD | DIS | M0)) /*GPMC_A1*/\
	MUX_VAL(CP(GPMC_A2),        (IDIS | PTD | DIS | M0)) /*GPMC_A2*/\
	MUX_VAL(CP(GPMC_A3),        (IDIS | PTD | DIS | M0)) /*GPMC_A3*/\
	MUX_VAL(CP(GPMC_A4),        (IDIS | PTD | DIS | M0)) /*GPMC_A4*/\
	MUX_VAL(CP(GPMC_A5),        (IDIS | PTD | DIS | M0)) /*GPMC_A5*/\
	MUX_VAL(CP(GPMC_A6),        (IDIS | PTD | DIS | M0)) /*GPMC_A6*/\
	MUX_VAL(CP(GPMC_A7),        (IDIS | PTD | DIS | M0)) /*GPMC_A7*/\
	MUX_VAL(CP(GPMC_A8),        (IDIS | PTD | DIS | M0)) /*GPMC_A8*/\
	MUX_VAL(CP(GPMC_A9),        (IDIS | PTD | DIS | M0)) /*GPMC_A9*/\
	MUX_VAL(CP(GPMC_A10),       (IDIS | PTD | DIS | M0)) /*GPMC_A10*/\
	MUX_VAL(CP(GPMC_D0),        (IEN  | PTD | DIS | M0)) /*GPMC_D0*/\
	MUX_VAL(CP(GPMC_D1),        (IEN  | PTD | DIS | M0)) /*GPMC_D1*/\
	MUX_VAL(CP(GPMC_D2),        (IEN  | PTD | DIS | M0)) /*GPMC_D2*/\
	MUX_VAL(CP(GPMC_D3),        (IEN  | PTD | DIS | M0)) /*GPMC_D3*/\
	MUX_VAL(CP(GPMC_D4),        (IEN  | PTD | DIS | M0)) /*GPMC_D4*/\
	MUX_VAL(CP(GPMC_D5),        (IEN  | PTD | DIS | M0)) /*GPMC_D5*/\
	MUX_VAL(CP(GPMC_D6),        (IEN  | PTD | DIS | M0)) /*GPMC_D6*/\
	MUX_VAL(CP(GPMC_D7),        (IEN  | PTD | DIS | M0)) /*GPMC_D7*/\
	MUX_VAL(CP(GPMC_D8),        (IEN  | PTD | DIS | M0)) /*GPMC_D8*/\
	MUX_VAL(CP(GPMC_D9),        (IEN  | PTD | DIS | M0)) /*GPMC_D9*/\
	MUX_VAL(CP(GPMC_D10),       (IEN  | PTD | DIS | M0)) /*GPMC_D10*/\
	MUX_VAL(CP(GPMC_D11),       (IEN  | PTD | DIS | M0)) /*GPMC_D11*/\
	MUX_VAL(CP(GPMC_D12),       (IEN  | PTD | DIS | M0)) /*GPMC_D12*/\
	MUX_VAL(CP(GPMC_D13),       (IEN  | PTD | DIS | M0)) /*GPMC_D13*/\
	MUX_VAL(CP(GPMC_D14),       (IEN  | PTD | DIS | M0)) /*GPMC_D14*/\
	MUX_VAL(CP(GPMC_D15),       (IEN  | PTD | DIS | M0)) /*GPMC_D15*/\
	MUX_VAL(CP(GPMC_nCS0),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS0*/\
	MUX_VAL(CP(GPMC_nCS1),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS1*/\
	MUX_VAL(CP(GPMC_nCS2),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS2*/\
	MUX_VAL(CP(GPMC_nCS3),      (IEN  | PTU | EN  | M4)) /*GPIO_54*/\
							     /* - MMC1_WP*/\
	MUX_VAL(CP(GPMC_nCS4),      (IDIS | PTU | EN  | M0)) /*GPMC_nCS4*/\
	MUX_VAL(CP(GPMC_nCS5),      (IDIS | PTD | DIS | M0)) /*GPMC_nCS5*/\
	MUX_VAL(CP(GPMC_nCS6),      (IEN  | PTD | DIS | M0)) /*GPMC_nCS6*/\
	MUX_VAL(CP(GPMC_nCS7),      (IEN  | PTU | EN  | M0)) /*GPMC_nCS7*/\
	MUX_VAL(CP(GPMC_nBE1),      (IEN  | PTD | DIS | M0)) /*GPMC_nCS3*/\
	MUX_VAL(CP(GPMC_CLK),       (IDIS | PTD | DIS | M0)) /*GPMC_CLK*/\
	MUX_VAL(CP(GPMC_nADV_ALE),  (IDIS | PTD | DIS | M0)) /*GPMC_nADV_ALE*/\
	MUX_VAL(CP(GPMC_nOE),       (IDIS | PTD | DIS | M0)) /*GPMC_nOE*/\
	MUX_VAL(CP(GPMC_nWE),       (IDIS | PTD | DIS | M0)) /*GPMC_nWE*/\
	MUX_VAL(CP(GPMC_nBE0_CLE),  (IDIS | PTD | DIS | M0)) /*GPMC_nBE0_CLE*/\
	MUX_VAL(CP(GPMC_nWP),       (IEN  | PTD | DIS | M0)) /*GPMC_nWP*/\
	MUX_VAL(CP(GPMC_WAIT0),     (IEN  | PTU | EN  | M0)) /*GPMC_WAIT0*/\
	MUX_VAL(CP(GPMC_WAIT1),     (IEN  | PTU | EN  | M0)) /*GPMC_WAIT1*/\
	MUX_VAL(CP(GPMC_WAIT2),     (IEN  | PTU | EN  | M0)) /*GPMC_nCS3*/\
	MUX_VAL(CP(GPMC_WAIT3),     (IEN  | PTU | EN  | M0)) /*GPMC_nCS3*/\
	/*DSS*/\
	MUX_VAL(CP(DSS_PCLK),       (IDIS | PTD | DIS | M0)) /*DSS_PCLK*/\
	MUX_VAL(CP(DSS_HSYNC),      (IDIS | PTD | DIS | M0)) /*DSS_HSYNC*/\
	MUX_VAL(CP(DSS_VSYNC),      (IDIS | PTD | DIS | M0)) /*DSS_VSYNC*/\
	MUX_VAL(CP(DSS_ACBIAS),     (IDIS | PTD | DIS | M0)) /*DSS_ACBIAS*/\
	MUX_VAL(CP(DSS_DATA0),      (IDIS | PTD | DIS | M0)) /*DSS_DATA0*/\
	MUX_VAL(CP(DSS_DATA1),      (IDIS | PTD | DIS | M0)) /*DSS_DATA1*/\
	MUX_VAL(CP(DSS_DATA2),      (IDIS | PTD | DIS | M0)) /*DSS_DATA2*/\
	MUX_VAL(CP(DSS_DATA3),      (IDIS | PTD | DIS | M0)) /*DSS_DATA3*/\
	MUX_VAL(CP(DSS_DATA4),      (IDIS | PTD | DIS | M0)) /*DSS_DATA4*/\
	MUX_VAL(CP(DSS_DATA5),      (IDIS | PTD | DIS | M0)) /*DSS_DATA5*/\
	MUX_VAL(CP(DSS_DATA6),      (IDIS | PTD | DIS | M0)) /*DSS_DATA6*/\
	MUX_VAL(CP(DSS_DATA7),      (IDIS | PTD | DIS | M0)) /*DSS_DATA7*/\
	MUX_VAL(CP(DSS_DATA8),      (IDIS | PTD | DIS | M0)) /*DSS_DATA8*/\
	MUX_VAL(CP(DSS_DATA9),      (IDIS | PTD | DIS | M0)) /*DSS_DATA9*/\
	MUX_VAL(CP(DSS_DATA10),     (IDIS | PTD | DIS | M0)) /*DSS_DATA10*/\
	MUX_VAL(CP(DSS_DATA11),     (IDIS | PTD | DIS | M0)) /*DSS_DATA11*/\
	MUX_VAL(CP(DSS_DATA12),     (IDIS | PTD | DIS | M0)) /*DSS_DATA12*/\
	MUX_VAL(CP(DSS_DATA13),     (IDIS | PTD | DIS | M0)) /*DSS_DATA13*/\
	MUX_VAL(CP(DSS_DATA14),     (IDIS | PTD | DIS | M0)) /*DSS_DATA14*/\
	MUX_VAL(CP(DSS_DATA15),     (IDIS | PTD | DIS | M0)) /*DSS_DATA15*/\
	MUX_VAL(CP(DSS_DATA16),     (IDIS | PTD | DIS | M0)) /*DSS_DATA16*/\
	MUX_VAL(CP(DSS_DATA17),     (IDIS | PTD | DIS | M0)) /*DSS_DATA17*/\
	MUX_VAL(CP(DSS_DATA18),     (IDIS | PTD | DIS | M0)) /*DSS_DATA18*/\
	MUX_VAL(CP(DSS_DATA19),     (IDIS | PTD | DIS | M0)) /*DSS_DATA19*/\
	MUX_VAL(CP(DSS_DATA20),     (IDIS | PTD | DIS | M0)) /*DSS_DATA20*/\
	MUX_VAL(CP(DSS_DATA21),     (IDIS | PTD | DIS | M0)) /*DSS_DATA21*/\
	MUX_VAL(CP(DSS_DATA22),     (IDIS | PTD | DIS | M0)) /*DSS_DATA22*/\
	MUX_VAL(CP(DSS_DATA23),     (IDIS | PTD | DIS | M0)) /*DSS_DATA23*/\
	/*CAMERA*/\
	MUX_VAL(CP(CAM_HS),         (IEN  | PTU | EN  | M0)) /*CAM_HS */\
	MUX_VAL(CP(CAM_VS),         (IEN  | PTU | EN  | M0)) /*CAM_VS */\
	MUX_VAL(CP(CAM_XCLKA),      (IDIS | PTD | DIS | M0)) /*CAM_XCLKA*/\
	MUX_VAL(CP(CAM_PCLK),       (IEN  | PTU | EN  | M0)) /*CAM_PCLK*/\
	MUX_VAL(CP(CAM_FLD),        (IDIS | PTD | DIS | M4)) /*CAM_FLD*/\
	MUX_VAL(CP(CAM_D0),         (IEN  | PTD | DIS | M0)) /*CAM_D0*/\
	MUX_VAL(CP(CAM_D1),         (IEN  | PTD | DIS | M0)) /*CAM_D1*/\
	MUX_VAL(CP(CAM_D2),         (IEN  | PTD | DIS | M0)) /*CAM_D2*/\
	MUX_VAL(CP(CAM_D3),         (IEN  | PTD | DIS | M0)) /*CAM_D3*/\
	MUX_VAL(CP(CAM_D4),         (IEN  | PTD | DIS | M0)) /*CAM_D4*/\
	MUX_VAL(CP(CAM_D5),         (IEN  | PTD | DIS | M0)) /*CAM_D5*/\
	MUX_VAL(CP(CAM_D6),         (IEN  | PTD | DIS | M0)) /*CAM_D6*/\
	MUX_VAL(CP(CAM_D7),         (IEN  | PTD | DIS | M0)) /*CAM_D7*/\
	MUX_VAL(CP(CAM_D8),         (IEN  | PTD | DIS | M0)) /*CAM_D8*/\
	MUX_VAL(CP(CAM_D9),         (IEN  | PTD | DIS | M0)) /*CAM_D9*/\
	MUX_VAL(CP(CAM_D10),        (IEN  | PTD | DIS | M0)) /*CAM_D10*/\
	MUX_VAL(CP(CAM_D11),        (IEN  | PTD | DIS | M0)) /*CAM_D11*/\
	MUX_VAL(CP(CAM_XCLKB),      (IDIS | PTD | DIS | M0)) /*CAM_XCLKB*/\
	MUX_VAL(CP(CAM_WEN),        (IEN  | PTD | DIS | M0)) /*CAM_WEN*/\
	MUX_VAL(CP(CAM_STROBE),     (IDIS | PTD | DIS | M0)) /*CAM_STROBE*/\
	MUX_VAL(CP(CSI2_DX0),       (IEN  | PTD | DIS | M0)) /*CSI2_DX0*/\
	MUX_VAL(CP(CSI2_DY0),       (IEN  | PTD | DIS | M0)) /*CSI2_DY0*/\
	MUX_VAL(CP(CSI2_DX1),       (IEN  | PTD | DIS | M0)) /*CSI2_DX1*/\
	MUX_VAL(CP(CSI2_DY1),       (IEN  | PTU | EN  | M4)) /*GPIO_115*/\
	/*Audio Interface */\
	MUX_VAL(CP(McBSP2_FSX),     (IEN  | PTD | DIS | M0)) /*McBSP2_FSX*/\
	MUX_VAL(CP(McBSP2_CLKX),    (IEN  | PTD | DIS | M0)) /*McBSP2_CLKX*/\
	MUX_VAL(CP(McBSP2_DR),      (IEN  | PTD | DIS | M0)) /*McBSP2_DR*/\
	MUX_VAL(CP(McBSP2_DX),      (IDIS | PTD | DIS | M0)) /*McBSP2_DX*/\
	/*Expansion card  */\
	MUX_VAL(CP(MMC1_CLK),       (IDIS | PTU | EN  | M0)) /*MMC1_CLK*/\
	MUX_VAL(CP(MMC1_CMD),       (IEN  | PTU | EN  | M0)) /*MMC1_CMD*/\
	MUX_VAL(CP(MMC1_DAT0),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT0*/\
	MUX_VAL(CP(MMC1_DAT1),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT1*/\
	MUX_VAL(CP(MMC1_DAT2),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT2*/\
	MUX_VAL(CP(MMC1_DAT3),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT3*/\
	MUX_VAL(CP(MMC1_DAT4),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT4*/\
	MUX_VAL(CP(MMC1_DAT5),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT5*/\
	MUX_VAL(CP(MMC1_DAT6),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT6*/\
	MUX_VAL(CP(MMC1_DAT7),      (IEN  | PTU | EN  | M0)) /*MMC1_DAT7*/\
	/*Wireless LAN */\
	MUX_VAL(CP(MMC2_CLK),       (IEN  | PTU | EN  | M0)) /*MMC2_CLK*/\
	MUX_VAL(CP(MMC2_CMD),       (IEN  | PTU | EN  | M0)) /*MMC2_CMD*/\
	MUX_VAL(CP(MMC2_DAT0),      (IEN  | PTU | EN  | M0)) /*MMC2_DAT0*/\
	MUX_VAL(CP(MMC2_DAT1),      (IEN  | PTU | EN  | M0)) /*MMC2_DAT1*/\
	MUX_VAL(CP(MMC2_DAT2),      (IEN  | PTU | EN  | M0)) /*MMC2_DAT2*/\
	MUX_VAL(CP(MMC2_DAT3),      (IEN  | PTU | EN  | M0)) /*MMC2_DAT3*/\
	MUX_VAL(CP(MMC2_DAT4),      (IEN  | PTU | EN  | M1)) /*MMC2_DIR_DAT0*/\
	MUX_VAL(CP(MMC2_DAT5),      (IEN  | PTU | EN  | M1)) /*MMC2_DIR_DAT1*/\
	MUX_VAL(CP(MMC2_DAT6),      (IEN  | PTU | EN  | M1)) /*MMC2_DIR_CMD*/\
	MUX_VAL(CP(MMC2_DAT7),      (IEN  | PTU | EN  | M1)) /*MMC2_CLKIN*/\
	/*Bluetooth*/\
	MUX_VAL(CP(McBSP3_DX),      (IEN  | PTD | DIS | M1)) /*UART2_CTS*/\
	MUX_VAL(CP(McBSP3_DR),      (IDIS | PTD | DIS | M1)) /*UART2_RTS*/\
	MUX_VAL(CP(McBSP3_CLKX),    (IDIS | PTD | DIS | M1)) /*UART2_TX*/\
	MUX_VAL(CP(McBSP3_FSX),     (IEN  | PTD | DIS | M1)) /*UART2_RX*/\
	MUX_VAL(CP(UART2_CTS),      (IDIS | PTD | DIS | M4)) /*GPIO_144*/\
							     /* - LCD_EN*/\
	MUX_VAL(CP(UART2_RTS),      (IDIS | PTD | DIS | M4)) /*GPIO_145*/\
	MUX_VAL(CP(UART2_TX),       (IDIS | PTD | DIS | M4)) /*GPIO_146*/\
	MUX_VAL(CP(UART2_RX),       (IDIS | PTD | DIS | M4)) /*GPIO_147*/\
	MUX_VAL(CP(UART1_TX),       (IDIS | PTD | DIS | M0)) /*UART1_TX*/\
	MUX_VAL(CP(UART1_RTS),      (IEN  | PTU | DIS | M4)) /*GPIO_149*/ \
	MUX_VAL(CP(UART1_CTS),      (IEN  | PTU | DIS | M4)) /*GPIO_150*/ \
							     /* - MMC3_WP*/\
	MUX_VAL(CP(UART1_RX),       (IEN  | PTD | DIS | M0)) /*UART1_RX*/\
	MUX_VAL(CP(McBSP4_CLKX),    (IEN  | PTD | DIS | M0)) /*McBSP4_CLKX*/\
	MUX_VAL(CP(McBSP4_DR),      (IEN  | PTD | DIS | M0)) /*McBSP4_DR*/\
	MUX_VAL(CP(McBSP4_DX),      (IEN  | PTD | DIS | M0)) /*McBSP4_DX*/\
	MUX_VAL(CP(McBSP4_FSX),     (IEN  | PTD | DIS | M0)) /*McBSP4_FSX*/\
	MUX_VAL(CP(McBSP1_CLKR),    (IEN  | PTD | DIS | M0)) /*McBSP1_CLKR*/\
	MUX_VAL(CP(McBSP1_FSR),     (IEN  | PTD | DIS | M0)) /*McBSP1_FSR*/\
	MUX_VAL(CP(McBSP1_DX),      (IEN  | PTD | DIS | M0)) /*McBSP1_DX*/\
	MUX_VAL(CP(McBSP1_DR),      (IEN  | PTD | DIS | M0)) /*McBSP1_DR*/\
	MUX_VAL(CP(McBSP_CLKS),     (IEN  | PTU | DIS | M0)) /*McBSP_CLKS*/\
	MUX_VAL(CP(McBSP1_FSX),     (IEN  | PTD | DIS | M0)) /*McBSP1_FSX*/\
	MUX_VAL(CP(McBSP1_CLKX),    (IEN  | PTD | DIS | M0)) /*McBSP1_CLKX*/\
	/*Serial Interface*/\
	MUX_VAL(CP(UART3_CTS_RCTX), (IEN  | PTD | EN  | M0)) /*UART3_CTS_*/\
							     /* RCTX*/\
	MUX_VAL(CP(UART3_RTS_SD),   (IEN  | PTU | EN  | M4)) /*GPIO_164 */\
							     /* - W2W_BT_NRESET*/\
	MUX_VAL(CP(UART3_RX_IRRX),  (IEN  | PTU | EN  | M0)) /*UART3_RX_IRRX*/\
	MUX_VAL(CP(UART3_TX_IRTX),  (IDIS | PTD | DIS | M0)) /*UART3_TX_IRTX*/\
	MUX_VAL(CP(HSUSB0_CLK),     (IEN  | PTD | DIS | M0)) /*HSUSB0_CLK*/\
	MUX_VAL(CP(HSUSB0_STP),     (IDIS | PTU | EN  | M0)) /*HSUSB0_STP*/\
	MUX_VAL(CP(HSUSB0_DIR),     (IEN  | PTD | DIS | M0)) /*HSUSB0_DIR*/\
	MUX_VAL(CP(HSUSB0_NXT),     (IEN  | PTD | DIS | M0)) /*HSUSB0_NXT*/\
	MUX_VAL(CP(HSUSB0_DATA0),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA0*/\
	MUX_VAL(CP(HSUSB0_DATA1),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA1*/\
	MUX_VAL(CP(HSUSB0_DATA2),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA2*/\
	MUX_VAL(CP(HSUSB0_DATA3),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA3*/\
	MUX_VAL(CP(HSUSB0_DATA4),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA4*/\
	MUX_VAL(CP(HSUSB0_DATA5),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA5*/\
	MUX_VAL(CP(HSUSB0_DATA6),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA6*/\
	MUX_VAL(CP(HSUSB0_DATA7),   (IEN  | PTD | DIS | M0)) /*HSUSB0_DATA7*/\
	MUX_VAL(CP(I2C1_SCL),       (IEN  | PTU | EN  | M0)) /*I2C1_SCL*/\
	MUX_VAL(CP(I2C1_SDA),       (IEN  | PTU | EN  | M0)) /*I2C1_SDA*/\
	MUX_VAL(CP(I2C2_SCL),       (IEN  | PTU | EN  | M4)) /*GPIO_168*/\
							     /* - USBH_CPEN*/\
	MUX_VAL(CP(I2C2_SDA),       (IEN  | PTU | EN  | M4)) /*GPIO_183*/\
							     /* - USBH_RESET*/\
	MUX_VAL(CP(I2C3_SCL),       (IEN  | PTU | EN  | M0)) /*I2C3_SCL*/\
	MUX_VAL(CP(I2C3_SDA),       (IEN  | PTU | EN  | M0)) /*I2C3_SDA*/\
	MUX_VAL(CP(I2C4_SCL),       (IEN  | PTU | EN  | M0)) /*I2C4_SCL*/\
	MUX_VAL(CP(I2C4_SDA),       (IEN  | PTU | EN  | M0)) /*I2C4_SDA*/\
	MUX_VAL(CP(HDQ_SIO),        (IDIS | PTU | EN  | M4)) /*HDQ_SIO*/\
	MUX_VAL(CP(McSPI1_CLK),     (IEN  | PTD | DIS | M0)) /*McSPI1_CLK*/\
	MUX_VAL(CP(McSPI1_SIMO),    (IEN  | PTD | DIS | M0)) /*McSPI1_SIMO  */\
	MUX_VAL(CP(McSPI1_SOMI),    (IEN  | PTD | DIS | M0)) /*McSPI1_SOMI  */\
	MUX_VAL(CP(McSPI1_CS0),     (IEN  | PTD | EN  | M0)) /*McSPI1_CS0*/\
	MUX_VAL(CP(McSPI1_CS1),     (IDIS | PTD | EN  | M0)) /*McSPI1_CS1*/\
	MUX_VAL(CP(McSPI1_CS2),     (IDIS | PTD | DIS | M4)) /*GPIO_176*/\
	MUX_VAL(CP(McSPI1_CS3),     (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA2*/\
	MUX_VAL(CP(McSPI2_CLK),     (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA7*/\
	MUX_VAL(CP(McSPI2_SIMO),    (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA4*/\
	MUX_VAL(CP(McSPI2_SOMI),    (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA5*/\
	MUX_VAL(CP(McSPI2_CS0),     (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA6*/\
	MUX_VAL(CP(McSPI2_CS1),     (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA3*/\
	/*Control and debug */\
	MUX_VAL(CP(SYS_32K),        (IEN  | PTD | DIS | M0)) /*SYS_32K*/\
	MUX_VAL(CP(SYS_CLKREQ),     (IEN  | PTD | DIS | M0)) /*SYS_CLKREQ*/\
	MUX_VAL(CP(SYS_nIRQ),       (IEN  | PTU | EN  | M0)) /*SYS_nIRQ*/\
	MUX_VAL(CP(SYS_BOOT0),      (IEN  | PTD | DIS | M4)) /*GPIO_2*/\
	MUX_VAL(CP(SYS_BOOT1),      (IEN  | PTD | DIS | M4)) /*GPIO_3 */\
	MUX_VAL(CP(SYS_BOOT2),      (IEN  | PTD | DIS | M4)) /*GPIO_4*/\
							     /* - MMC1_WP */\
	MUX_VAL(CP(SYS_BOOT3),      (IEN  | PTD | DIS | M4)) /*GPIO_5*/\
	MUX_VAL(CP(SYS_BOOT4),      (IEN  | PTD | DIS | M4)) /*GPIO_6*/\
	MUX_VAL(CP(SYS_BOOT5),      (IEN  | PTD | DIS | M4)) /*GPIO_7*/\
	MUX_VAL(CP(SYS_BOOT6),      (IDIS | PTD | DIS | M4)) /*GPIO_8*/\
	MUX_VAL(CP(SYS_OFF_MODE),   (IEN  | PTD | DIS | M0)) /*SYS_OFF_MODE*/\
	MUX_VAL(CP(SYS_CLKOUT1),    (IEN  | PTD | DIS | M0)) /*SYS_CLKOUT1*/\
	MUX_VAL(CP(SYS_CLKOUT2),    (IEN  | PTU | EN  | M4)) /*GPIO_186*/\
	MUX_VAL(CP(ETK_CLK_ES2),    (IDIS | PTU | EN  | M2)) /*MMC3_CLK*/\
	MUX_VAL(CP(ETK_CTL_ES2),    (IEN  | PTU | EN  | M2)) /*MMC3_CMD*/\
	MUX_VAL(CP(ETK_D0_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT4*/\
	MUX_VAL(CP(ETK_D1_ES2),     (IEN  | PTU | EN  | M4)) /*GPIO_15*/\
							     /* - MMC1-CD*/\
	MUX_VAL(CP(ETK_D2_ES2),     (IEN  | PTU | EN  | M4)) /*GPIO_16*/\
							     /* - W2W_NRESET*/\
	MUX_VAL(CP(ETK_D3_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT3*/\
	MUX_VAL(CP(ETK_D4_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT0*/\
	MUX_VAL(CP(ETK_D5_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT1*/\
	MUX_VAL(CP(ETK_D6_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT2*/\
	MUX_VAL(CP(ETK_D7_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT7*/\
	MUX_VAL(CP(ETK_D8_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT6*/\
	MUX_VAL(CP(ETK_D9_ES2),     (IEN  | PTU | EN  | M2)) /*MMC3_DAT5*/\
	MUX_VAL(CP(ETK_D10_ES2),    (IDIS | PTD | DIS | M3)) /*HSUSB2_CLK*/\
	MUX_VAL(CP(ETK_D11_ES2),    (IDIS | PTU | EN  | M3)) /*HSUSB2_STP*/\
	MUX_VAL(CP(ETK_D12_ES2),    (IEN  | PTD | DIS | M3)) /*HSUSB2_DIR*/\
	MUX_VAL(CP(ETK_D13_ES2),    (IEN  | PTD | DIS | M3)) /*HSUSB2_NXT*/\
	MUX_VAL(CP(ETK_D14_ES2),    (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA0*/\
	MUX_VAL(CP(ETK_D15_ES2),    (IEN  | PTD | DIS | M3)) /*HSUSB2_DATA1*/\
	/* die to die */\
	MUX_VAL(CP(d2d_mcad1),      (IEN  | PTD | EN  | M0)) /*d2d_mcad1*/\
	MUX_VAL(CP(d2d_mcad2),      (IEN  | PTD | EN  | M0)) /*d2d_mcad2*/\
	MUX_VAL(CP(d2d_mcad3),      (IEN  | PTD | EN  | M0)) /*d2d_mcad3*/\
	MUX_VAL(CP(d2d_mcad4),      (IEN  | PTD | EN  | M0)) /*d2d_mcad4*/\
	MUX_VAL(CP(d2d_mcad5),      (IEN  | PTD | EN  | M0)) /*d2d_mcad5*/\
	MUX_VAL(CP(d2d_mcad6),      (IEN  | PTD | EN  | M0)) /*d2d_mcad6*/\
	MUX_VAL(CP(d2d_mcad7),      (IEN  | PTD | EN  | M0)) /*d2d_mcad7*/\
	MUX_VAL(CP(d2d_mcad8),      (IEN  | PTD | EN  | M0)) /*d2d_mcad8*/\
	MUX_VAL(CP(d2d_mcad9),      (IEN  | PTD | EN  | M0)) /*d2d_mcad9*/\
	MUX_VAL(CP(d2d_mcad10),     (IEN  | PTD | EN  | M0)) /*d2d_mcad10*/\
	MUX_VAL(CP(d2d_mcad11),     (IEN  | PTD | EN  | M0)) /*d2d_mcad11*/\
	MUX_VAL(CP(d2d_mcad12),     (IEN  | PTD | EN  | M0)) /*d2d_mcad12*/\
	MUX_VAL(CP(d2d_mcad13),     (IEN  | PTD | EN  | M0)) /*d2d_mcad13*/\
	MUX_VAL(CP(d2d_mcad14),     (IEN  | PTD | EN  | M0)) /*d2d_mcad14*/\
	MUX_VAL(CP(d2d_mcad15),     (IEN  | PTD | EN  | M0)) /*d2d_mcad15*/\
	MUX_VAL(CP(d2d_mcad16),     (IEN  | PTD | EN  | M0)) /*d2d_mcad16*/\
	MUX_VAL(CP(d2d_mcad17),     (IEN  | PTD | EN  | M0)) /*d2d_mcad17*/\
	MUX_VAL(CP(d2d_mcad18),     (IEN  | PTD | EN  | M0)) /*d2d_mcad18*/\
	MUX_VAL(CP(d2d_mcad19),     (IEN  | PTD | EN  | M0)) /*d2d_mcad19*/\
	MUX_VAL(CP(d2d_mcad20),     (IEN  | PTD | EN  | M0)) /*d2d_mcad20*/\
	MUX_VAL(CP(d2d_mcad21),     (IEN  | PTD | EN  | M0)) /*d2d_mcad21*/\
	MUX_VAL(CP(d2d_mcad22),     (IEN  | PTD | EN  | M0)) /*d2d_mcad22*/\
	MUX_VAL(CP(d2d_mcad23),     (IEN  | PTD | EN  | M0)) /*d2d_mcad23*/\
	MUX_VAL(CP(d2d_mcad24),     (IEN  | PTD | EN  | M0)) /*d2d_mcad24*/\
	MUX_VAL(CP(d2d_mcad25),     (IEN  | PTD | EN  | M0)) /*d2d_mcad25*/\
	MUX_VAL(CP(d2d_mcad26),     (IEN  | PTD | EN  | M0)) /*d2d_mcad26*/\
	MUX_VAL(CP(d2d_mcad27),     (IEN  | PTD | EN  | M0)) /*d2d_mcad27*/\
	MUX_VAL(CP(d2d_mcad28),     (IEN  | PTD | EN  | M0)) /*d2d_mcad28*/\
	MUX_VAL(CP(d2d_mcad29),     (IEN  | PTD | EN  | M0)) /*d2d_mcad29*/\
	MUX_VAL(CP(d2d_mcad30),     (IEN  | PTD | EN  | M0)) /*d2d_mcad30*/\
	MUX_VAL(CP(d2d_mcad31),     (IEN  | PTD | EN  | M0)) /*d2d_mcad31*/\
	MUX_VAL(CP(d2d_mcad32),     (IEN  | PTD | EN  | M0)) /*d2d_mcad32*/\
	MUX_VAL(CP(d2d_mcad33),     (IEN  | PTD | EN  | M0)) /*d2d_mcad33*/\
	MUX_VAL(CP(d2d_mcad34),     (IEN  | PTD | EN  | M0)) /*d2d_mcad34*/\
	MUX_VAL(CP(d2d_mcad35),     (IEN  | PTD | EN  | M0)) /*d2d_mcad35*/\
	MUX_VAL(CP(d2d_mcad36),     (IEN  | PTD | EN  | M0)) /*d2d_mcad36*/\
	MUX_VAL(CP(d2d_clk26mi),    (IEN  | PTD | DIS | M0)) /*d2d_clk26mi*/\
	MUX_VAL(CP(d2d_nrespwron),  (IEN  | PTD | EN  | M0)) /*d2d_nrespwron*/\
	MUX_VAL(CP(d2d_nreswarm),   (IEN  | PTU | EN  | M0)) /*d2d_nreswarm */\
	MUX_VAL(CP(d2d_arm9nirq),   (IEN  | PTD | DIS | M0)) /*d2d_arm9nirq */\
	MUX_VAL(CP(d2d_uma2p6fiq),  (IEN  | PTD | DIS | M0)) /*d2d_uma2p6fiq*/\
	MUX_VAL(CP(d2d_spint),      (IEN  | PTD | EN  | M0)) /*d2d_spint*/\
	MUX_VAL(CP(d2d_frint),      (IEN  | PTD | EN  | M0)) /*d2d_frint*/\
	MUX_VAL(CP(d2d_dmareq0),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq0*/\
	MUX_VAL(CP(d2d_dmareq1),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq1*/\
	MUX_VAL(CP(d2d_dmareq2),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq2*/\
	MUX_VAL(CP(d2d_dmareq3),    (IEN  | PTD | DIS | M0)) /*d2d_dmareq3*/\
	MUX_VAL(CP(d2d_n3gtrst),    (IEN  | PTD | DIS | M0)) /*d2d_n3gtrst*/\
	MUX_VAL(CP(d2d_n3gtdi),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtdi*/\
	MUX_VAL(CP(d2d_n3gtdo),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtdo*/\
	MUX_VAL(CP(d2d_n3gtms),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtms*/\
	MUX_VAL(CP(d2d_n3gtck),     (IEN  | PTD | DIS | M0)) /*d2d_n3gtck*/\
	MUX_VAL(CP(d2d_n3grtck),    (IEN  | PTD | DIS | M0)) /*d2d_n3grtck*/\
	MUX_VAL(CP(d2d_mstdby),     (IEN  | PTU | EN  | M0)) /*d2d_mstdby*/\
	MUX_VAL(CP(d2d_swakeup),    (IEN  | PTD | EN  | M0)) /*d2d_swakeup*/\
	MUX_VAL(CP(d2d_idlereq),    (IEN  | PTD | DIS | M0)) /*d2d_idlereq*/\
	MUX_VAL(CP(d2d_idleack),    (IEN  | PTU | EN  | M0)) /*d2d_idleack*/\
	MUX_VAL(CP(d2d_mwrite),     (IEN  | PTD | DIS | M0)) /*d2d_mwrite*/\
	MUX_VAL(CP(d2d_swrite),     (IEN  | PTD | DIS | M0)) /*d2d_swrite*/\
	MUX_VAL(CP(d2d_mread),      (IEN  | PTD | DIS | M0)) /*d2d_mread*/\
	MUX_VAL(CP(d2d_sread),      (IEN  | PTD | DIS | M0)) /*d2d_sread*/\
	MUX_VAL(CP(d2d_mbusflag),   (IEN  | PTD | DIS | M0)) /*d2d_mbusflag*/\
	MUX_VAL(CP(d2d_sbusflag),   (IEN  | PTD | DIS | M0)) /*d2d_sbusflag*/\
	MUX_VAL(CP(sdrc_cke0),      (IDIS | PTU | EN  | M0)) /*sdrc_cke0*/\
	MUX_VAL(CP(sdrc_cke1),      (IDIS | PTD | DIS | M7)) /*sdrc_cke1*/\

#endif
