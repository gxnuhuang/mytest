obj-m += modmy1.o
modmy1-y := mod1.o

KVERSION = $(shell uname -r)

all: 
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
    
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	rm -f *.o *.ko *.cmd
