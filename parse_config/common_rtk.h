#ifndef __COMMON_RTK_H
#define __COMMON_RTK_H

#include<stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>

/*hzq debug define*/
#if 1
#define debug_msg(msg...)  do { printf("hzq:"msg); }while(0)
#define debug_i2c(msg...)  do { printf("hzq:"msg); }while(0)
#else
#define h_dbg(msg...)  do {}while(0)
#endif /*  */

#endif



