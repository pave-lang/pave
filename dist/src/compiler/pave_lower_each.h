#ifndef PAVE_PAVE_LOWER_EACH
#define PAVE_PAVE_LOWER_EACH

#include <stdint.h>

#include <slice_i32.h>
struct pave_lower_each {
    int32_t _state;
    int32_t _value;

    struct slice_i32 items;
    uintptr_t __iter;
    int32_t item;
};

#include <std/trait_Iter_i32.h>
int32_t pave_lower_each__value(void* ctx);
extern struct trait_Iter_i32VTable pave_lower_each__VTABLE__ITER;
#line 77 "src/compiler/LoweringTest.pv"
bool pave_lower_each__next(void* _ctx);

#endif
