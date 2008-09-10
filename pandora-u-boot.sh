#!/bin/sh
make CROSS_COMPILE=arm-none-linux-gnueabi- distclean 
make CROSS_COMPILE=arm-none-linux-gnueabi- omap3_pandora_config
make CROSS_COMPILE=arm-none-linux-gnueabi- 
cp u-boot.bin ../u-boot.bin
