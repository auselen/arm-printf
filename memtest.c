#include "printf.h"

char membuf[512];
int memi;

void memreset() {
    memi = 0;
}

void memc(int c) {
    if (c == '\n')
        memc('\r');
    if (memi == (sizeof(membuf) / sizeof(membuf[0])))
        return;
    membuf[memi++] = c;
}

int memtest(const char *s) {
    const char *t = membuf;

    while (*s) {
        if (*s++ != *t++)
            return 1;
    }

    return 0;
}

int main(void) {
    memf("test %d 0x%x %c %s", 13, 0xABCDEF09, '@', ">!");
    return memtest("test 13 0xABCDEF09 @ >!");
}
