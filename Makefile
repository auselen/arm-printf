CROSSCOMPILE ?= arm-linux-gnueabihf-

PRINTF_NAME = test_printf
PRINTF_PUTC = test_putc

printf.o: printf.h printf.c 
	$(CROSSCOMPILE)gcc -O2 -Wall -nostdlib -DPRINTF_NAME=$(PRINTF_NAME) -DPRINTF_PUTC=$(PRINTF_PUTC) -c printf.c

clean:
	rm printf.o
