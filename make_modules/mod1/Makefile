obj-m += modmy1.o
modmy1-y := mod1.o

#KVERSION = $(shell uname -r)

source_code=/home/gxnuhuang/irt_group/src
#too-arm
#ARM_TOOL="/home/gxnuhuang/tool-arm/gcc-linaro-arm-linux-gnueabihf-4.8-2013.04-20130417_linux/bin/arm-linux-gnueabihf-"
#ti-7
#ARM_TOOL="/home/gxnuhuang/ti-sdk-am335x-evm-07.00.00.00/linux-devkit/sysroots/i686-arago-linux/usr/bin/arm-linux-gnueabihf-"
##
ARM_TOOL="/home/gxnuhuang/ti-sdk-am335x-evm-06.00.00.00/linux-devkit/sysroots/i686-arago-linux/usr/bin/arm-linux-gnueabihf-"

all: 
	make  ARCH=arm CROSS_COMPILE=${ARM_TOOL}  -C ${source_code} M=$(PWD) modules
clean:
	make  ARCH=arm CROSS_COMPILE=${ARM_TOOL}  -C ${source_code} M=$(PWD)  clean
	rm -f *.o  *.cmd
