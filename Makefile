obj-m  := kbdklog.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install: copy depmod

uninstall: delete depmod

copy:
	cp kbdklog.ko /lib/modules/$(shell uname -r)/kernel/drivers

delete:
	rm /lib/modules/$(shell uname -r)/kernel/drivers/kbdklog.ko
		
depmod:
	$(shell depmod -a)
