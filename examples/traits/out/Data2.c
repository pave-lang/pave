#include <stdio.h>

#include <stdint.h>

#include <traits/Data2.h>

void Data2__Print__print(void* __self) {
    struct Data2* self = __self; (void)self;
    printf("%d %.2f\n", self->a, self->b);
}

struct PrintVTable DATA2__VTABLE__PRINT = { .print = &Data2__Print__print };
