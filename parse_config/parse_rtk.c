#include"parse_rtk.h"
#include"str_conver_rtk.h"

i2c_info_t i2c_dev[MAX_DEV_SIZE];

static char * i2c_config_get_line(char *s, int size, FILE *stream, int *line,
				  char **_pos)
{
	return RTK_config_get_line(s, size, stream, line,_pos);
}

void i2c_set_config(char *pos,char *posstr,unsigned int *vaule)
{
	char *pfirst_pos,*end,*plast_pos;
	debug_msg("%s in pos  %s  inpos %s\n",__func__,pos,posstr);
		if (strncmp(pos, posstr,sizeof(posstr)-1) == 0) {
			pfirst_pos = RTK_strchr(pos, '=');
			if(NULL==pfirst_pos){

			return 0;
			}
			*pfirst_pos++ = '\0';
			debug_i2c("pfirst_pos is %s\n",pfirst_pos);
			if(pfirst_pos=='"'){
				plast_pos=RTK_strchr(pfirst_pos+1,'"');
				plast_pos='\0';
			}else{
				*vaule=strtol(pfirst_pos,&end,0);//conver 
				if(*end){
				printf("conver fail\n");
				}
				debug_i2c("conver value %x \n",*vaule);
			}
			
		}else{
		printf("%s not equare %s \n",pos,posstr);
		}
}


void i2c_config_read_device(FILE *fp, int *line, int id)
{
	int errors = 0, end = 0;
	char content_buf[256], *pos, *pname_firt_pos,*pname_last_pos;
	
	while (i2c_config_get_line(content_buf, sizeof(content_buf), fp, line, &pos)) {
		if (RTK_strcmp(pos, "}") == 0) {
			end = 1;
			printf("end done\n");
			break;
		}

		i2c_dev[id].id=id;
		/*set i2c dev name*/
		if (strncmp(content_buf, "dev_name=",sizeof("dev_name=")-1) == 0) {
			pname_firt_pos = RTK_strchr(content_buf, '=');
			if(NULL==pname_firt_pos){
			printf("cannot find = for dev_name!\n");
			return 0;
			}
			*pname_firt_pos++ = '\0';
			debug_i2c("name_firt_pos is %s\n",pname_firt_pos);
			if (*pname_firt_pos == '"') {
				pname_firt_pos++;	//del '"'
				//debug_msg("set name\n");
				pname_last_pos=RTK_strchr(pname_firt_pos+1,'"');//then pname_last_pos= '"'
				*pname_last_pos='\0';
				debug_msg("pname_firt_pos %s \n",pname_firt_pos);
				sscanf(pname_firt_pos,"%s",i2c_dev[id].dev_name);//copy the name to  i2c_dev.name			
			}else{
			
			}
			
		}
		if (strncmp(content_buf, "dev_addr=",sizeof("dev_addr=")-1) == 0) {
		i2c_set_config(content_buf,"dev_addr=",&i2c_dev[id].dev_addr);
		debug_i2c("dev_addr=%x\n",i2c_dev[id].dev_addr);
		}

		if (strncmp(content_buf, "dev_reg=",sizeof("dev_reg=")-1) == 0) {
		i2c_set_config(content_buf,"dev_reg=",&i2c_dev[id].dev_reg);
		debug_i2c("dev_reg=%x\n\n",i2c_dev[id].dev_reg);
		}

		if (strncmp(content_buf, "dev_reg_value=",sizeof("dev_reg_value=")-1) == 0) {
		i2c_set_config(content_buf,"dev_reg_value=",&i2c_dev[id].dev_reg_value);
		debug_i2c("reg_value=%x\n\n",i2c_dev[id].dev_reg_value);
		}

	}
}
void printf_parse(void)
{
	printf("hello\n");
}
void ParseI2cDevInfo(FILE *fp)
{
	char content_buf[MAX_SIZE], *pfirst_pos;
	int line=0,i;
	static int i2c_dev_count=0;
	debug_msg("%s in \n",__func__);
	while(i2c_config_get_line(content_buf,MAX_SIZE,fp,&line,&pfirst_pos)){
		if (RTK_strcmp(pfirst_pos, "i2c_device={") == 0) {
		i2c_config_read_device(fp,&line,i2c_dev_count);
		i2c_dev_count++;
		}

	}
	for(i=0;i<i2c_dev_count;i++){
	debug_msg("i2c_dev[%d].name is %s  \naddr=%x reg=%x reg_value=%x\n",
		i,i2c_dev[i].dev_name,i2c_dev[i].dev_addr,i2c_dev[i].dev_reg,i2c_dev[i].dev_reg_value);
	}
	
}




