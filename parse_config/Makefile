CC	= arm-arago-linux-gnueabi-gcc
#CC	= gcc
parse : main.o parse_rtk.o str_conver_rtk.o
	$(CC)  -o parse  str_conver_rtk.o parse_rtk.o main.o
parse_rtk.o :
	$(CC)   -c -g parse_rtk.c
main.o :
	$(CC)   -c -g  main.c
str_conver_rtk.o :
	$(CC)   -c -g  str_conver_rtk.c

.PHONY : clean
clean :
	- rm *.o parse *~ 
