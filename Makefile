obj-m := choo_kernel.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	rm	-rf *.ko
	rm	-rf *.mod.*
	rm	-rf .*.cmd
	rm	-rf *.o
	rm	-rf .tmp_versions

