/*
 *  Header file for OneNAND support for U-Boot
 *
 *  Adaptation from kernel to U-Boot
 *
 *  Copyright (C) 2005-2007 Samsung Electronics
 *  Kyungmin Park <kyungmin.park@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __UBOOT_ONENAND_H
#define __UBOOT_ONENAND_H

#include <linux/types.h>

struct kvec {
	void *iov_base;
	size_t iov_len;
};

typedef int spinlock_t;
typedef int wait_queue_head_t;

struct mtd_info;
struct erase_info;

#define ONENAND_SCRUB  0x10

/* Functions */
extern void onenand_init(void);
extern int onenand_read(struct mtd_info *mtd, loff_t from, size_t len,
			size_t * retlen, u_char * buf);
extern int onenand_read_oob(struct mtd_info *mtd, loff_t from,
			struct mtd_oob_ops *oob_ops);
extern int onenand_write_oob(struct mtd_info *mtd, loff_t to,
			struct mtd_oob_ops *oob_ops);
extern int onenand_write(struct mtd_info *mtd, loff_t from, size_t len,
			 size_t * retlen, const u_char * buf);
extern int onenand_erase(struct mtd_info *mtd, struct erase_info *instr);

extern int onenand_unlock(struct mtd_info *mtd, loff_t ofs, size_t len);

extern char *onenand_print_device_info(int device);

extern int onenand_block_markbad(struct mtd_info *mtd, loff_t ofs);
extern int onenand_block_isbad(struct mtd_info *mtd, loff_t ofs);

#endif /* __UBOOT_ONENAND_H */
