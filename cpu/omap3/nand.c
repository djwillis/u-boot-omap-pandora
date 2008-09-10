/*
 * (C) Copyright 2004-2008 Texas Instruments, <www.ti.com>
 * Rohit Choraria <rohitkc@ti.com>
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
#include <asm/arch/mem.h>
#include <linux/mtd/nand_ecc.h>

#if defined(CONFIG_CMD_NAND)

#include <nand.h>

unsigned char cs;
volatile unsigned long gpmc_cs_base_add;

#define GPMC_BUF_EMPTY 0
#define GPMC_BUF_FULL 1

#define ECC_P1_128_E(val)    ((val)  & 0x000000FF)	/* Bit 0 to 7 */
#define ECC_P512_2048_E(val) (((val) & 0x00000F00)>>8)	/* Bit 8 to 11 */
#define ECC_P1_128_O(val)    (((val) & 0x00FF0000)>>16)	/* Bit 16 to Bit 23 */
#define ECC_P512_2048_O(val) (((val) & 0x0F000000)>>24)	/* Bit 24 to Bit 27 */

/*
 * omap_nand_hwcontrol - Set the address pointers corretly for the
 *			following address/data/command operation
 */
static void omap_nand_hwcontrol(struct mtd_info *mtd, int cmd,
				unsigned int ctrl)
{
	register struct nand_chip *this = mtd->priv;

	/* Point the IO_ADDR to DATA and ADDRESS registers instead
	   of chip address */
	switch (ctrl) {
	case NAND_CTRL_CHANGE | NAND_CTRL_CLE:
		this->IO_ADDR_W = (void *) gpmc_cs_base_add + GPMC_NAND_CMD;
		this->IO_ADDR_R = (void *) gpmc_cs_base_add + GPMC_NAND_DAT;
		break;
	case NAND_CTRL_CHANGE | NAND_CTRL_ALE:
		this->IO_ADDR_W = (void *) gpmc_cs_base_add + GPMC_NAND_ADR;
		this->IO_ADDR_R = (void *) gpmc_cs_base_add + GPMC_NAND_DAT;
		break;
	case NAND_CTRL_CHANGE | NAND_NCE:
		this->IO_ADDR_W = (void *) gpmc_cs_base_add + GPMC_NAND_DAT;
		this->IO_ADDR_R = (void *) gpmc_cs_base_add + GPMC_NAND_DAT;
		break;
	}

	if (cmd != NAND_CMD_NONE)
		writeb(cmd, this->IO_ADDR_W);
}

/*
 * omap_nand_wait - called primarily after a program/erase operation
 *			so that we access NAND again only after the device
 *			is ready again.
 * @mtd:        MTD device structure
 * @chip:	nand_chip structure
 */
static int omap_nand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
	register struct nand_chip *this = mtd->priv;
	int status = 0;

	this->IO_ADDR_W = (void *) gpmc_cs_base_add + GPMC_NAND_CMD;
	this->IO_ADDR_R = (void *) gpmc_cs_base_add + GPMC_NAND_DAT;
	/* Send the status command and loop until the device is free */
	while (!(status & 0x40)) {
		__raw_writeb(NAND_CMD_STATUS & 0xFF, this->IO_ADDR_W);
		status = __raw_readb(this->IO_ADDR_R);
	}
	return status;
}

#ifdef CFG_NAND_WIDTH_16
/*
 * omap_nand_write_buf16 - [DEFAULT] write buffer to chip
 * @mtd:	MTD device structure
 * @buf:	data buffer
 * @len:	number of bytes to write
 *
 * Default write function for 16bit buswith
 */
static void omap_nand_write_buf(struct mtd_info *mtd, const u_char *buf,
				int len)
{
	int i;
	struct nand_chip *this = mtd->priv;
	u16 *p = (u16 *) buf;
	len >>= 1;

	for (i = 0; i < len; i++) {
		writew(p[i], this->IO_ADDR_W);
		while (GPMC_BUF_EMPTY == (readl(GPMC_STATUS) & GPMC_BUF_FULL)) ;
	}
}

/*
 * nand_read_buf16 - [DEFAULT] read chip data into buffer
 * @mtd:	MTD device structure
 * @buf:	buffer to store date
 * @len:	number of bytes to read
 *
 * Default read function for 16bit buswith
 */
static void omap_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
	int i;
	struct nand_chip *this = mtd->priv;
	u16 *p = (u16 *) buf;
	len >>= 1;

	for (i = 0; i < len; i++)
		p[i] = readw(this->IO_ADDR_R);
}

#else
/*
 * omap_nand_write_buf -  write buffer to NAND controller
 * @mtd:        MTD device structure
 * @buf:        data buffer
 * @len:        number of bytes to write
 *
 */
static void omap_nand_write_buf(struct mtd_info *mtd, const uint8_t *buf,
				int len)
{
	int i;
	int j = 0;
	struct nand_chip *chip = mtd->priv;

	for (i = 0; i < len; i++) {
		writeb(buf[i], chip->IO_ADDR_W);
		for (j = 0; j < 10; j++) ;
	}

}

/*
 * omap_nand_read_buf - read data from NAND controller into buffer
 * @mtd:        MTD device structure
 * @buf:        buffer to store date
 * @len:        number of bytes to read
 *
 */
static void omap_nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
	int i;
	int j = 0;
	struct nand_chip *chip = mtd->priv;

	for (i = 0; i < len; i++) {
		buf[i] = readb(chip->IO_ADDR_R);
		while (GPMC_BUF_EMPTY == (readl(GPMC_STATUS) & GPMC_BUF_FULL));
	}
}
#endif /* CFG_NAND_WIDTH_16 */

/*
 * omap_hwecc_init - Initialize the Hardware ECC for NAND flash in
 *                   GPMC controller
 * @mtd:        MTD device structure
 *
 */
static void omap_hwecc_init(struct nand_chip *chip)
{
	unsigned long val = 0x0;

	/* Init ECC Control Register */
	/* Clear all ECC  | Enable Reg1 */
	val = ((0x00000001 << 8) | 0x00000001);
	__raw_writel(val, GPMC_BASE + GPMC_ECC_CONTROL);
	__raw_writel(0x3fcff000, GPMC_BASE + GPMC_ECC_SIZE_CONFIG);
}

/*
 * omap_correct_data - Compares the ecc read from nand spare area with
 *                     ECC registers values
 *			and corrects one bit error if it has occured
 * @mtd:		 MTD device structure
 * @dat:		 page data
 * @read_ecc:		 ecc read from nand flash
 * @calc_ecc: 		 ecc read from ECC registers
 */
static int omap_correct_data(struct mtd_info *mtd, u_char *dat,
			     u_char *read_ecc, u_char *calc_ecc)
{
	return 0;
}

/*
 *  omap_calculate_ecc - Generate non-inverted ECC bytes.
 *
 *  Using noninverted ECC can be considered ugly since writing a blank
 *  page ie. padding will clear the ECC bytes. This is no problem as
 *  long nobody is trying to write data on the seemingly unused page.
 *  Reading an erased page will produce an ECC mismatch between
 *  generated and read ECC bytes that has to be dealt with separately.
 *  @mtd:	MTD structure
 *  @dat:	unused
 *  @ecc_code:	ecc_code buffer
 */
static int omap_calculate_ecc(struct mtd_info *mtd, const u_char *dat,
			      u_char *ecc_code)
{
	unsigned long val = 0x0;
	unsigned long reg;

	/* Start Reading from HW ECC1_Result = 0x200 */
	reg = (unsigned long) (GPMC_BASE + GPMC_ECC1_RESULT);
	val = __raw_readl(reg);

	*ecc_code++ = ECC_P1_128_E(val);
	*ecc_code++ = ECC_P1_128_O(val);
	*ecc_code++ = ECC_P512_2048_E(val) | ECC_P512_2048_O(val) << 4;

	return 0;
}

/*
 * omap_enable_ecc - This function enables the hardware ecc functionality
 * @mtd:        MTD device structure
 * @mode:       Read/Write mode
 */
static void omap_enable_hwecc(struct mtd_info *mtd, int mode)
{
	struct nand_chip *chip = mtd->priv;
	unsigned int val = __raw_readl(GPMC_BASE + GPMC_ECC_CONFIG);
	unsigned int dev_width = (chip->options & NAND_BUSWIDTH_16) >> 1;

	switch (mode) {
	case NAND_ECC_READ:
		__raw_writel(0x101, GPMC_BASE + GPMC_ECC_CONTROL);
		/* ECC col width | CS | ECC Enable */
		val = (dev_width << 7) | (cs << 1) | (0x1);
		break;
	case NAND_ECC_READSYN:
		__raw_writel(0x100, GPMC_BASE + GPMC_ECC_CONTROL);
		/* ECC col width | CS | ECC Enable */
		val = (dev_width << 7) | (cs << 1) | (0x1);
		break;
	case NAND_ECC_WRITE:
		__raw_writel(0x101, GPMC_BASE + GPMC_ECC_CONTROL);
		/* ECC col width | CS | ECC Enable */
		val = (dev_width << 7) | (cs << 1) | (0x1);
		break;
	default:
		printf("Error: Unrecognized Mode[%d]!\n", mode);
		break;
	}

	__raw_writel(val, GPMC_BASE + GPMC_ECC_CONFIG);
}

static struct nand_ecclayout hw_nand_oob_64 = {
	.eccbytes = 12,
	.eccpos = {
		   2, 3, 4, 5,
		   6, 7, 8, 9,
		   10, 11, 12, 13},
	.oobfree = { {20, 50} }	/* don't care */
};

static struct nand_ecclayout sw_nand_oob_64 = {
	.eccbytes = 24,
	.eccpos = {
		   40, 41, 42, 43, 44, 45, 46, 47,
		   48, 49, 50, 51, 52, 53, 54, 55,
		   56, 57, 58, 59, 60, 61, 62, 63},
	.oobfree = { {2, 38} }
};

void omap_nand_switch_ecc(struct mtd_info *mtd, int hardware)
{
	struct nand_chip *nand = mtd->priv;

	if (!hardware) {
		nand->ecc.mode = NAND_ECC_SOFT;
		nand->ecc.layout = &sw_nand_oob_64;
		nand->ecc.size = 256;	/* set default eccsize */
		nand->ecc.bytes = 3;
		nand->ecc.steps = 8;
		nand->ecc.hwctl = 0;
		nand->ecc.calculate = nand_calculate_ecc;
		nand->ecc.correct = nand_correct_data;
	} else {
		nand->ecc.mode = NAND_ECC_HW;
		nand->ecc.layout = &hw_nand_oob_64;
		nand->ecc.size = 512;
		nand->ecc.bytes = 3;
		nand->ecc.steps = 4;
		nand->ecc.hwctl = omap_enable_hwecc;
		nand->ecc.correct = omap_correct_data;
		nand->ecc.calculate = omap_calculate_ecc;
		omap_hwecc_init(nand);
	}
	nand_switch_ecc(mtd);

	if (nand->options & NAND_BUSWIDTH_16) {
		mtd->oobavail = mtd->oobsize - (nand->ecc.layout->eccbytes + 2);
		if (nand->ecc.layout->eccbytes & 0x01)
			mtd->oobavail--;
	} else
		mtd->oobavail = mtd->oobsize - (nand->ecc.layout->eccbytes + 1);
}

/*
 * Board-specific NAND initialization. The following members of the
 * argument are board-specific (per include/linux/mtd/nand_new.h):
 * - IO_ADDR_R?: address to read the 8 I/O lines of the flash device
 * - IO_ADDR_W?: address to write the 8 I/O lines of the flash device
 * - hwcontrol: hardwarespecific function for accesing control-lines
 * - dev_ready: hardwarespecific function for  accesing device ready/busy line
 * - enable_hwecc?: function to enable (reset)  hardware ecc generator. Must
 *   only be provided if a hardware ECC is available
 * - eccmode: mode of ecc, see defines
 * - chip_delay: chip dependent delay for transfering data from array to
 *   read regs (tR)
 * - options: various chip options. They can partly be set to inform
 *   nand_scan about special functionality. See the defines for further
 *   explanation
 * Members with a "?" were not set in the merged testing-NAND branch,
 * so they are not set here either.
 */
int board_nand_init(struct nand_chip *nand)
{
	int gpmc_config = 0;
	cs = 0;
	while (cs <= GPMC_MAX_CS) {
		/* Each GPMC set for a single CS is at offset 0x30 */
		/* already remapped for us */
		gpmc_cs_base_add = (GPMC_CONFIG_CS0 + (cs * 0x30));
		/* xloader/Uboot would have written the NAND type for us
		 * NOTE: This is a temporary measure and cannot handle ONENAND.
		 * The proper way of doing this is to pass the setup of
		 * u-boot up to kernel using kernel params - something on
		 * the lines of machineID
		 */
		/* Check if NAND type is set */
		if ((__raw_readl(gpmc_cs_base_add + GPMC_CONFIG1) & 0xC00) ==
		    0x800) {
			/* Found it!! */
			break;
		}
		cs++;
	}
	if (cs > GPMC_MAX_CS) {
		printf("NAND: Unable to find NAND settings in " \
		       "GPMC Configuration - quitting\n");
	}

	gpmc_config = __raw_readl(GPMC_CONFIG);
	/* Disable Write protect */
	gpmc_config |= 0x10;
	__raw_writel(gpmc_config, GPMC_CONFIG);

	nand->IO_ADDR_R = (int *) gpmc_cs_base_add + GPMC_NAND_DAT;
	nand->IO_ADDR_W = (int *) gpmc_cs_base_add + GPMC_NAND_CMD;

	nand->cmd_ctrl = omap_nand_hwcontrol;
	nand->options = NAND_NO_PADDING | NAND_CACHEPRG | NAND_NO_AUTOINCR |
			NAND_BUSWIDTH_16 | NAND_NO_AUTOINCR;
	nand->read_buf = omap_nand_read_buf;
	nand->write_buf = omap_nand_write_buf;
	nand->ecc.mode = NAND_ECC_SOFT;
	/* if RDY/BSY line is connected to OMAP then use the omap ready
	 * function and the generic nand_wait function which reads the
	 * status register after monitoring the RDY/BSY line. Otherwise
	 * use a standard chip delay which is slightly more than tR
	 * (AC Timing) of the NAND device and read the status register
	 * until you get a failure or success
	 */
	nand->waitfunc = omap_nand_wait;
	nand->chip_delay = 50;

	return 0;
}
#endif /* CONFIG_CMD_NAND */
