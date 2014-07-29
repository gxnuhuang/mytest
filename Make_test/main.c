/*************************************************************************
	> File Name: main.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年01月04日 星期六 21时17分46秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char src[10]="hello";
    char des[10]={0};
    char *p=NULL;
   // *p="hellp";
   // printf("p is %d\n",*p);
   // strcpy(NULL,src);
   #ifdef HDEBUG
   printf("heihei\n");
   #endif
    printf("str is %s and %s \n",src,des);
}
