./scripts/driver-select wl12xx
export KLIB_BUILD=/home/gxnuhuang/myitrk2_kernel
export KLIB=/home/gxnuhuang/wifi_0506/install
sed -i -e 's/^MODPROBE.*/MODPROBE := \/sbin\/modprobe.sh/g' Makefile
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
#make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- install-modules
