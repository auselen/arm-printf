#include "printf.h"

void linuxc(int c) {
    if (c == '\n')
        linuxc('\r');
    asm volatile(
        "mov r0, #1\n"     /* stdout        */
        "mov r1, %[buf]\n" /* write buffer  */
        "mov r2, #1\n"     /* size          */
        "mov r7, #4\n"     /* write syscall */
        "svc #0\n"
        : /* output */ : [buf] "r" (&c) : "r0", "r1", "r2", "r7", "memory"
    );
}

const char *c_str = "constant_string";
int main(void) {
    linuxf("Hello world and\n decimal %d\n character %c\n hexadecimal %x"
            "\n string in stack %s\n string in heap %s\n!\n",
            42, 'x', 0xCAFEBABE, "stack_string", c_str);
    return 42;
}

void _start() __attribute__ ((naked));
void _start() {
    main();
    asm volatile(
        "mov r7, #1\n" /* exit */
        "svc #0\n"
    );
}
