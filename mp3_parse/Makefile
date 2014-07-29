TARGET_RTK :=hello
CC=gcc
INSTALL_DIR=$(shell pwd)install
$(TARGET_RTK) : main.o 
	$(CC)  -o $(TARGET_RTK) main.o
main.o :
	$(CC) -c -g  main.c
install :
	cp -arv $(TARGET_RTK) $(INSTALL_DIR)
.PHONY : clean
clean :
	- rm *.o $(TARGET_RTK)  *~ 
