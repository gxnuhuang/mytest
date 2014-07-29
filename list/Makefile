TARGET_RTK :=list
#CC	= arm-arago-linux-gnueabi-gcc
CC	= gcc
$(TARGET_RTK) : main.o str_conver_rtk.o
	$(CC)  -o $(TARGET_RTK) str_conver_rtk.o main.o
main.o :
	$(CC)  -c -g  main.c
str_conver_rtk.o :
	$(CC)  -c -g str_conver_rtk.c
.PHONY : clean
clean :
	- rm *.o $(TARGET_RTK)  *~ 
