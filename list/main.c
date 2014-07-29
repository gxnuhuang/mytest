#include"common_rtk.h"
#include"list.h"




char *arr_name[]={
"name0",
"name1",
"name2",
"name3",
};
char arr_name1[4][20]={
"name0",
"name1",
"name2",
"name3",
};
static LIST_HEAD(mem_RTK_list);

void add_mem_list(char id)
{
	struct mem_RTK *s_mem_dev=NULL;
	s_mem_dev=malloc(sizeof(*s_mem_dev));
	if(NULL == s_mem_dev){
	printf("malloc fail!\n");
	}
	s_mem_dev->id = id;
	s_mem_dev->name1=arr_name[id];
	list_add_tail(&s_mem_dev->list,&mem_RTK_list);
}
struct mem_RTK * find_mem(char id)
{
	struct mem_RTK *s_mem_dev;
#if 1
	list_for_each_entry(s_mem_dev, &mem_RTK_list, list) {
		if (s_mem_dev->id == id){
		debug_msg("find id %d \n",s_mem_dev->id);
		goto found;
		}
			
	}
#endif
	printf("has not id %d in list\n",id);
	s_mem_dev=NULL;
found:
	return s_mem_dev;
}
//struct mem_RTK mem_g;
int main(int argc, char *argv[])
{
	int i;
	struct mem_RTK *mem_dev[4];
	debug_msg("hello %s %s\n",__DATE__,__TIME__);
	for(i=0;i<4;i++){
	debug_msg("%s\n",arr_name[i]);
	}

	for(i=0;i<4;i++){
	add_mem_list(i);
	}
#if 0
	mem_dev[0]=find_mem(0);
	printf("mem_dev.id %d name %s\n",mem_dev[0]->id,mem_dev[0]->name1);
	mem_dev[1]=find_mem(1);
	printf("mem_dev.id %d name %s\n",mem_dev[1]->id,mem_dev[1]->name1);
		mem_dev[2]=find_mem(2);
	printf("mem_dev.id %d name %s\n",mem_dev[2]->id,mem_dev[2]->name1);
		mem_dev[3]=find_mem(3);
	printf("mem_dev.id %d name %s\n",mem_dev[3]->id,mem_dev[3]->name1);	
	//mem_dev[4]=find_mem(4);
	//printf("mem_dev.id %d name %s\n",mem_dev[4]->id,mem_dev[4]->name1);
#endif	
#if 1
	for(i=0;i<4;i++){
		mem_dev[i]=find_mem(i);
		if(!mem_dev[i]){
		printf("find_mem fail %d\n",i);
		//return 0;
		}else{
		printf("mem_dev.id %d name %s\n",mem_dev[i]->id,mem_dev[i]->name1);
		list_del(&mem_dev[i]->list);//has to firt del list before call the following free function
		free(mem_dev[i]);
		}
		
		
	}
#endif
	exit(0);
	//return 0 ;
}
