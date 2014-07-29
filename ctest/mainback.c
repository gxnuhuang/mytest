/*************************************************************************
	> File Name: main.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2013年12月11日 星期三 19时37分24秒
 ************************************************************************/

#include<stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#define debug_msg(format,...) do \
			  {  \
				printf("FILE %s LINE %d FUNC %s ",__FILE__,__LINE__,__FUNCTION__);\
				printf(format,## __VA_ARGS__);\
			  }while(0)
int main(void)
{

	int huan;
	int fd;
	printf("huang1zhonghaida\n");
	debug_msg("zhonghaida %d \n",10);
	fd = open("/dev/spidev1.0", O_RDWR);
	if (fd < 0)
		printf("hzqcan't open device");
	printf("fd %d \n",fd);
	while(1);
	return 0 ;
}
