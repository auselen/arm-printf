arm-printf
==========

Standalone simple printf implementation using GCC for ARM.

It doesn't require any external library including standard C library.

It doesn't use stdarg.h / varargs to implement. 

It doesn't support printing floating-points (yet).

usage
=====
printf.c and its header file is all needed. You need to define `PRINTF_NAME` to name printf instance (to avoid possible name conflicts) and provide a `PRINTF_PUTC` implementation which should deliver a single char to requested medium. `PRINTF_PUTC` should gracefully handle `\n` that is if `\n` needs to be swapped with `\r\n`, it is `PRINTF_PUTC`'s task to do that.

See Makefile for examples, it comes with some example builds like `linux` and `memtest`.

`linux` target is a standalone application using system calls to print directly to stdout.

`memtest` target is a simple application using a buffer to test functionality of printf implementation.
