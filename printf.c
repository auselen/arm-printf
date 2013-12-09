#include "printf.h"

extern void PRINTF_PUTC(int c);

void PRINTF_NAME(const char *fmt, ...) {
    int *stack_head = __builtin_frame_address(0);
    stack_head += 2;

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt++) {
                case 'c':
                    PRINTF_PUTC(*stack_head++);
                    break;
                case 's': {
                    const char *s = (char *) *stack_head++;
                    while (*s) {
                        PRINTF_PUTC(*s++);
                    }
                    break;
                }
                case 'x': {
                    int num = *stack_head++;
                    int shift = 28;
                    while (shift >= 0) {
                        int hd = (num >> shift) & 0xf;
                        if (hd > 9)
                            hd += 'A' - 10;
                        else
                            hd += '0';
                        PRINTF_PUTC(hd);
                        shift -= 4;
                    }
                    break;
                }
                case 'd': {
                    int num = *stack_head++;
                    char buf[16];
                    char *s = buf + (sizeof(buf) / sizeof(buf[0])) - 1;
                    char *e = s;

                    do {
                        *--s = '0' + num % 10;
                    } while (num /= 10);

                    while (s < e)
                        PRINTF_PUTC(*s++);

                    break;
                }
                default:
                    PRINTF_PUTC('?');
            }
        } else {
            PRINTF_PUTC(*fmt++);
        }
    }
}

