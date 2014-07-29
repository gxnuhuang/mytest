#include"common_rtk.h"
#include"parse_rtk.h"

char *filename="test.conf";
char *conf_file_name;
int main(int argc, char *argv[])
{
	FILE *fp;
	char c;
	fp=fopen(filename,"r");
	if(NULL==fp){
	printf("hzq:open %s is fail !\n",filename);
	exit(1);
	}
	debug_msg("open %s sucess\n",filename);
	printf_parse();
	ParseI2cDevInfo(fp);
	
	fclose(fp);
	while(1){
	c = getopt(argc, argv, "b:Bc:C:D:de:f:g:hi:KLNo:O:p:P:qstuvW");
	if (c < 0)
			break;
		switch (c) {
		case 'c':
			conf_file_name = optarg;
			break;
		default :
			debug_msg("please insert a name\n");
			break;
		}
	}
	debug_msg("filename %s\n",conf_file_name);

	fp=fopen(conf_file_name,"r");
	if(NULL==fp){
	printf("hzq:open %s is fail !\n",conf_file_name);
	exit(1);
	}
	debug_msg("open %s sucess\n",conf_file_name);
	ParseI2cDevInfo(fp);
	fclose(fp);
	return 0 ;
}
