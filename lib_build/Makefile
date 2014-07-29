TARGET_RTK :=spidevtest
CC=arm-arago-linux-gnueabi-gcc
INSTALL_DIR=/home/gxnuhuang/nfsroot/sbin/
$(TARGET_RTK) : spidev_test.o 
	$(CC)  -o $(TARGET_RTK) spidev_test.o
spidev_test.o :
	$(CC) -c -g  spidev_test.c
install :
	cp -arv $(TARGET_RTK) $(INSTALL_DIR)
.PHONY : clean
clean :
	- rm *.o $(TARGET_RTK)  *~ 
