export KLIB_BUILD=/home/gxnuhuang/kernel_am335x
export KLIB=/home/gxnuhuang/wifi_driver/install
./scripts/driver-select wl12xx
sed -i -e 's/^MODPROBE.*/MODPROBE := \/sbin\/modprobe.sh/g' Makefile
make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi-
#make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- install-modules
