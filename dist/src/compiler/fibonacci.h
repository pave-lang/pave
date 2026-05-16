#ifndef PAVE_FIBONACCI
#define PAVE_FIBONACCI

#include <stdint.h>

struct fibonacci {
    int32_t _state;
    uint64_t _value;

    uintptr_t n;
    uint64_t a;
    uint64_t b;
    uintptr_t i;
    uint64_t value;
    uint64_t tmp;
};

#include <std/trait_Iter_u64.h>
uint64_t fibonacci__value(void* ctx);
extern struct trait_Iter_u64VTable FIBONACCI__VTABLE__ITER;
#line 19 "src/compiler/FunctionCoroutine.pv"
bool fibonacci__next(void* _ctx);

#endif
