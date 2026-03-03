#ifndef PAVE_RUNNING_TOTAL
#define PAVE_RUNNING_TOTAL

#include <stdio.h>

#include <stdint.h>

struct running_total {
    int32_t _state;
    float _value;

    uintptr_t steps;
    float increment;
    float total;
    uintptr_t i;
};

#include <std/Iter_f32.h>
float running_total__value(void* ctx);
extern struct Iter_f32VTable RUNNING_TOTAL__VTABLE__ITER;
bool running_total__next(void* _ctx);

#endif
