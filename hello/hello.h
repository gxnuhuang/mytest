#ifndef _HELLO_ANDROID_H_
#define _HELLO_ANDROID_H_

#include <linux/cdev.h>
#include <linux/semaphore.h>
#if 1
#define HELLO_DEVICE_NODE_NAME  "hello"
#define HELLO_DEVICE_FILE_NAME  "hello"
#define HELLO_DEVICE_PROC_NAME  "hello"
#define HELLO_DEVICE_CLASS_NAME "hello"
#else
#define HELLO_DEVICE_NODE_NAME  "hello_node"
#define HELLO_DEVICE_FILE_NAME  "hello_file"
#define HELLO_DEVICE_PROC_NAME  "hello_proc"
#define HELLO_DEVICE_CLASS_NAME "hello_class"
#endif
#define VAL_SIZE 20
struct hello_android_dev {  
	unsigned char val[VAL_SIZE];
	char *name;
    struct semaphore sem;  
    struct cdev dev;  
};  
#endif 

