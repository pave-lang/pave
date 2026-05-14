#ifndef PAVE_DATA2
#define PAVE_DATA2

#include <stdint.h>

struct Data2 {
    int32_t a;
    float b;
};

#include <traits/trait_Print.h>
struct Data2;

void Data2__Print__print(void* __self);

extern struct trait_PrintVTable DATA2__VTABLE__PRINT;

#endif
