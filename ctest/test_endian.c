/*******************
 * 文件名：endian.c
 ******************/
#include <stdio.h>
 
/*********************************************************
 * 使用类型的强制转换实现little-endian与big-endian的判断 
 *********************************************************
 * 返回值：                                              
 *          1 表示是小端字节序。                         
 *          0 表示不是小端字节序。                       
 *********************************************************/
int is_little_endian_a(void)
{ 
    unsigned short flag = 0x4321;
    if(*(unsigned char*)&flag == 0x21)
        return 1;
    else
        return 0;
}
 
/*********************************************************************************
 * 利用联合的特点来判断little-endian与big-endian
 *********************************************************************************
 * 返回值： 
 *          1   表示是小端字节序。
 *          0   表示是大端字节序。
 *          -1  表示不能使用这种方法确定字节序。比如有的机器的 short 长度不是 2 。
 ********************************************************************************/
int is_little_endian_b(void)
{
    union endian_un{
        short var;
        char bits[sizeof(short)];
    };
 
    union endian_un flag;
    flag.var=0x0102;
 
    //判断低位和高位的存储内容，确定是何种方式
    if(sizeof(short) == 2){
        if(flag.bits[0] == 1 && flag.bits[1] == 2)
            return 0;
        else if(flag.bits[0] == 2 && flag.bits[1] == 1)
            return 1;
        else
            return -1;
    } 
     
    return -1;
}
 
int main(void)
{
    int type = 0;
 
    type = is_little_endian_a();
    if (1 == type)
        printf("judged by first method, little-endian\n");
    else if (0 == type)
        printf("judged by first method, big-endian\n");
 
    type = is_little_endian_b();
    if (1 == type)
        printf("judged by second method, little-endian\n");
    else if (0 == type)
        printf("judged by second method, big-endian\n");
    else
        printf("can't judge it\n");
 
    return 0;
}
