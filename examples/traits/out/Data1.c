#include <stdio.h>

#include <stdint.h>

#include <traits/Data1.h>

void Data1__Print__print(void* __self) {
    struct Data1* self = __self; (void)self;
    printf("%.2f %d\n", self->a, self->b);
}

struct PrintVTable DATA1__VTABLE__PRINT = { .print = &Data1__Print__print };
