CROSSCOMPILE ?= arm-linux-gnueabihf-

CFLAGS = -O2 -Wall -marm

all: linux memtest

linux: linux.c printf.c
	$(CROSSCOMPILE)gcc $(CFLAGS) -nostartfiles -nodefaultlibs -fno-stack-protector -DPRINTF_NAME=linuxf -DPRINTF_PUTC=linuxc linux.c printf.c -o $@

memtest: memtest.c printf.c
	$(CROSSCOMPILE)gcc $(CFLAGS) -static -DPRINTF_NAME=memf -DPRINTF_PUTC=memc memtest.c printf.c -o $@

clean:
	rm linux memtest
