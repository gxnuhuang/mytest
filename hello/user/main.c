#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

unsigned char write_buf[20]="1nihaoya";
unsigned char read_buf[20];
int main(int argc , char **argv)
{
    int fd=0 ;
    int wcount=0,rcount=0;
    fd = open("/dev/hello", O_RDWR);\
    printf("huang: fd =%d \n",fd); 
    wcount=write(fd, write_buf, strlen(write_buf));
    printf("huang:wcount =%d write_buf is %s \n\n",wcount,write_buf);
    close(fd);
//
    sleep(1);
    fd = open("/dev/hello", O_RDWR);\
    printf("huang: fd =%d \n",fd); 
    rcount=read(fd, read_buf, strlen(write_buf));
    printf("huang:rcount =%d read_buf=%s\n\n",rcount,read_buf);
    close(fd);
    return 0;
}
