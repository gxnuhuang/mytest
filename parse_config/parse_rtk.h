#ifndef __PARSE_RTK_H
#define __PARSE_RTK_H

#include"common_rtk.h"
#define MAX_SIZE       1024
#define MAX_DEV_SIZE   10
#define NAME_SIZE      10
struct i2c_dev_info{
char  dev_name[NAME_SIZE];
unsigned char id;
unsigned int dev_addr;
unsigned int dev_reg;
unsigned int dev_reg_value;
};
typedef struct i2c_dev_info i2c_info_t;

void printf_parse(void);
void ParseI2cDevInfo(FILE *fp);

#endif




