VERSION = $(shell uname -r)
obj-m += hello.o
modules:
#	make -C  /lib/modules/$(VERSION)/build M=$(PWD)  modules
	make -C /home/gxnuhuang/kernel_am335x M=$(shell pwd)  ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- modules
clean:
	-rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.order *.symvers *_log *.orig
