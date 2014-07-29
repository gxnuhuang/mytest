#include"common_rtk.h"
extern **environ;
int main(int argc, char *argv[])
{
	char *ptr=(char *)malloc(1024);
	char *pfree;
	ptr[0]=0;
	printf("environ is %s\n",(char *)*environ);
	debug_msg("hello\n");
	pfree=getenv("DESKTOP_SESSION");
	printf("DESKTOP is %s\n",pfree);
	free(ptr);
	while(1){
	debug_msg("hello\n");
	}
	return 0 ;
}
