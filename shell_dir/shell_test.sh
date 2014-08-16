#!/bin/sh

#数组定义
arry=( menuconfig uImage modules ) #数组下标从0开始
echo "${arry[1]}" #显示arry[1]的内容那

#if 条件判断
#if [ $1 == "?" ]
#then

#echo -e "\033[41;20m cmd is 0=mrproper 1=am335x_evm_defconfig 2=menuconfig 3=uImage 4=modules \033[0m"
#else
#echo ".....................hzq:it will be builded for ${arry[$1]} ..................................."
#make O=$(pwd)/out ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- ${arry[S1]}
#fi

#case语句


