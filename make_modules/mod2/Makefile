obj-m += modmy2.o
modmy2-y := mod2.o

KVERSION = $(shell uname -r)

all: 
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
    
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	rm -f *.o *.ko *.cmd
