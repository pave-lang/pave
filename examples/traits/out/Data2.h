#ifndef PAVE_DATA2
#define PAVE_DATA2

#include <stdint.h>
#include <traits/Print.h>

#include <stdio.h>

struct Data2 {
    int32_t a;
    float b;
};

void Data2__Print__print(void* __self);

extern struct PrintVTable DATA2__VTABLE__PRINT;

#endif
