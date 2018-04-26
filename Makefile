obj-m+=modulo_propio.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules 
modulo_propio.o:modulo_propio.c linux/init.h linux/module.h linux/kernel.h
	gcc -c modulo_propio.c
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
