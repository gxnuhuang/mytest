#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/ioctl.h>
#include <linux/string.h>
#include "hello.h"

#define DEBUG_HELLO
#ifdef DEBUG_HELLO
#define debug_hello(msg...)  do { printk( KERN_CRIT "hzq:" msg); }while(0)
#else
#define debug_hello(msg...) do {}while(0)
#endif

//for sem
//#define SUPPORT_SMEM
/*主设备和从设备号变量*/
static int hello_major = 0;
static int hello_minor = 0;

/*设备类别和设备变量*/
static struct class* hello_class = NULL; 
static struct hello_android_dev* hello_dev = NULL; 
/*传统的设备文件操作方法*/ 
static int hello_open(struct inode* inode, struct file* filp);
static int hello_release(struct inode* inode, struct file* filp); 
static ssize_t hello_read(struct file *filp, char __user *buf, size_t size,loff_t *ppos);
static ssize_t hello_write(struct file *filp, const char __user *buf, size_t size, loff_t *ppos);

/*设备文件操作方法表*/
static struct file_operations hello_fops = {  
    .owner = THIS_MODULE,  
    .open = hello_open,  
    .release = hello_release,  
    .read = hello_read,  
    .write = hello_write,   
};  
/*************定义传统的设备文件访问方法 start*****************/
/*打开设备方法*/  
static int hello_open(struct inode* inode, struct file* filp) {  
    struct hello_android_dev* dev;          
      
    /*将自定义设备结构体保存在文件指针的私有数据域中，以便访问设备时拿来用*/  
    dev = container_of(inode->i_cdev, struct hello_android_dev, dev);  
    filp->private_data = dev;  
    debug_hello(" %s in dev name is %s \n",__func__,dev->name);
    return 0;  
} 
/*设备文件释放时调用，空实现*/  
static int hello_release(struct inode* inode, struct file* filp) {  
    return 0;  
}  
/*读取设备的寄存器val的值*/  
static ssize_t hello_read(struct file *filp, char __user *buf, size_t size,
                          loff_t *ppos)
{  
    ssize_t err = 0;  
    struct hello_android_dev* dev = filp->private_data;    
#ifdef SUPPORT_SMEM
    /*同步访问*/  
    if(down_interruptible(&(dev->sem))) {  
        return -ERESTARTSYS;  
    }  
  
    if(size < sizeof(dev->val)) {  
        goto out;  
    }          
#endif  
    debug_hello("%s in name is %s \n",__func__,dev->name);
    debug_hello("you want to readb buf is %s num is %ld\n",dev->val,sizeof(dev->val));
    /*将寄存器val的值拷贝到用户提供的缓冲区*/  
    if(copy_to_user(buf, (dev->val), sizeof(dev->val))) {  
        err = -EFAULT; 
        printk(KERN_ALERT "hello read wrong!\n"); 
        goto out;  
    }  
    debug_hello("hello read secussful val is %s buf is %s \n",dev->val,buf);
    err=size;
out:  
#ifdef SUPPORT_SMEM 
   up(&(dev->sem));  
#endif
    return err;  
}  
/*写设备的寄存器值val*/  
static ssize_t hello_write(struct file *filp, const char __user *buf,
                           size_t size, loff_t *ppos) 
{  
    struct hello_android_dev* dev = filp->private_data;  
    ssize_t err = 0;    
#ifdef SUPPORT_SMEM 
    /*同步访问*/  
    if(down_interruptible(&(dev->sem))) {  
        return -ERESTARTSYS;          
    }          
  
    if(size != sizeof(dev->val)) {  
        goto out;          
    }          
#endif 
   // debug_hello("%s in write buf is %s, num is %ld  befor wirete is %s \n",__func__,buf,sizeof(buf),dev->val);
    debug_hello("write buf num is %ld size is %ld \n",sizeof(buf),size);
    memset(dev->val, '\0', VAL_SIZE);
    //return 0 ;
    /*将用户提供的缓冲区的值写到设备寄存器去*/  
    if(copy_from_user((dev->val), buf, size/*sizeof(buf)*/)) {  
        err = -EFAULT; 
         printk(KERN_ALERT"hello write wrong!\n"); 
        goto out;  
    }  
   debug_hello("hello write secussful val is %s \n",dev->val); 
   err=size;
out:  
#ifdef SUPPORT_SMEM
    up(&(dev->sem)); 
#endif 
    return err;  
}  
/*************定义传统的设备文件访问方法 end*****************/

/*最后，定义模块加载和卸载方法，这里只要是执行设备注册和初始化操作：*/
static int  __hello_setup_dev(struct hello_android_dev* dev) 
{  
    int err;  
    dev_t devno = MKDEV(hello_major, hello_minor);  
  
    memset(dev, 0, sizeof(struct hello_android_dev));  
#ifdef SUPPORT_SMEM  
    sema_init(&(dev->sem),1);  
#endif  
    cdev_init(&(dev->dev), &hello_fops);  
    dev->dev.owner = THIS_MODULE;  
    dev->dev.ops = &hello_fops;
    dev->name="hello";
  
    /*注册字符设备*/  
    err = cdev_add(&(dev->dev),devno, 1);  
    if(err) {  
        return err;  
    }          
  
    /*初始化信号量和寄存器val的值*/
#ifdef SUPPORT_SMEM  
    sema_init(&(dev->sem),1);  
#endif
  
    return 0;  
}  
/*模块加载方法*/  
static int __init hello_init(void)
{   
    int err = -1;  
    dev_t dev = 0;  
    struct device* temp = NULL;  
  
    printk(KERN_ALERT"Initializing hello device.\n");          
  
    /*动态分配主设备和从设备号*/  
    err = alloc_chrdev_region(&dev, 0, 1, HELLO_DEVICE_NODE_NAME);  
    if(err < 0) {  
        printk(KERN_ALERT"Failed to alloc char dev region.\n");  
        goto fail;  
    }  
  
    hello_major = MAJOR(dev);  
    hello_minor = MINOR(dev);          
    printk("hello major is %d minor is %d \n",hello_major,hello_minor);
    /*分配helo设备结构体变量*/  
    hello_dev = kmalloc(sizeof(struct hello_android_dev), GFP_KERNEL);  
    if(!hello_dev) {  
        err = -ENOMEM;  
        printk(KERN_ALERT"Failed to alloc hello_dev.\n");  
        goto unregister;  
    }          
    memset(hello_dev, 0, sizeof(struct hello_android_dev));
    /*初始化设备*/  
    err = __hello_setup_dev(hello_dev);  
    if(err) {  
        printk(KERN_ALERT"Failed to setup dev: %d.\n", err);  
        goto cleanup;  
    }          
  
    /*在/sys/class/目录下创建设备类别目录hello*/  
    hello_class = class_create(THIS_MODULE, HELLO_DEVICE_CLASS_NAME);  
    if(IS_ERR(hello_class)) {  
        err = PTR_ERR(hello_class);  
        printk(KERN_ALERT"Failed to create hello class.\n");  
        goto destroy_cdev;  
    }          
  
    /*在/dev/目录和/sys/class/hello目录下分别创建设备文件hello*/  
    temp = device_create(hello_class, NULL, dev, "%s", HELLO_DEVICE_FILE_NAME);  
    if(IS_ERR(temp)) {  
        err = PTR_ERR(temp);  
        printk(KERN_ALERT"Failed to create hello device.");  
        goto destroy_class;  
    }          

#if 0 
    /*在/sys/class/hello/hello目录下创建属性文件val*/  
    err = device_create_file(temp, &dev_attr_val);  
    if(err < 0) {  
        printk(KERN_ALERT"Failed to create attribute val.");                  
        goto destroy_device;  
    }  
#endif  
    dev_set_drvdata(temp, hello_dev);          
  
    printk(KERN_ALERT"Succedded to initialize hello device.\n");  
    return 0;  
#if 0
destroy_device:  
    device_destroy(hello_class, dev);  
#endif 
destroy_class:  
    class_destroy(hello_class);  
  
destroy_cdev:  
    cdev_del(&(hello_dev->dev));  
  
cleanup:  
    kfree(hello_dev);  
  
unregister:  
    unregister_chrdev_region(MKDEV(hello_major, hello_minor), 1);  
  
fail:  
    return err;  
}  
/*模块卸载方法*/  
static void __exit hello_exit(void) {  
    dev_t devno = MKDEV(hello_major, hello_minor);  
  
    printk(KERN_ALERT"Destroy hello device.\n");          
         
  
    /*销毁设备类别和设备*/  
    if(hello_class) {  
        device_destroy(hello_class, MKDEV(hello_major, hello_minor));  
        class_destroy(hello_class);  
    }          
  
    /*删除字符设备和释放设备内存*/  
    if(hello_dev) {  
        cdev_del(&(hello_dev->dev));  
        kfree(hello_dev);  
    }          
  
    /*释放设备号*/  
    unregister_chrdev_region(devno, 1);  
}  
  
MODULE_LICENSE("GPL");  
MODULE_DESCRIPTION("First Android Driver");  
  
module_init(hello_init);  
module_exit(hello_exit); 






 
