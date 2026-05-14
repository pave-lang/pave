#ifndef PAVE_DATA1
#define PAVE_DATA1

#include <stdint.h>

struct Data1 {
    float a;
    int32_t b;
};

#include <traits/trait_Print.h>
struct Data1;

void Data1__Print__print(void* __self);

extern struct trait_PrintVTable DATA1__VTABLE__PRINT;

#endif
