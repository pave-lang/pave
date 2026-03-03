#ifndef PAVE_DATA1
#define PAVE_DATA1

#include <stdint.h>
#include <traits/Print.h>

#include <stdio.h>

struct Data1 {
    float a;
    int32_t b;
};

void Data1__Print__print(void* __self);

extern struct PrintVTable DATA1__VTABLE__PRINT;

#endif
