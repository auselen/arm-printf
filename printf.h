#ifndef PRINTF_H
#define PRINTF_H

/* 
    Only prerequisite is a putc function with signature "void putc(int c)",
    which delivers a character to desired medium, PRINTF_PUTC needs to be
    defined with the same name.

    putc function needs to handle \n character, meaning
    if \n needs to be represented as \r\n then it's putc's responsibility
    to put a \r before \n. This is generally implemented as a recursive call:

    void putc(int c) {
        if (c == '\n')
            putc('\r');
        ...
*/

#ifndef PRINTF_PUTC
#error "PRINTF_PUTC is not defined."
#endif

/*
    PRINTF_NAME is the function you want to use printf as.
*/    

#ifndef PRINTF_NAME
#error "PRINTF_NAME is not defined."
#endif

void PRINTF_NAME(const char *fmt, ...);

#endif
