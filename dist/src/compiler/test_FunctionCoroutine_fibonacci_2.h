#ifndef PAVE_TEST_FUNCTION_COROUTINE_FIBONACCI_2
#define PAVE_TEST_FUNCTION_COROUTINE_FIBONACCI_2

#include <stdint.h>

struct test_FunctionCoroutine_fibonacci_2 {
    int32_t _state;
    uint64_t _value;

    uintptr_t n;
    uint64_t a;
    uint64_t b;
    uintptr_t i;
    uint64_t tmp;
};

#include <std/trait_Iter_u64.h>
uint64_t test_FunctionCoroutine_fibonacci_2__value(void* ctx);
extern struct trait_Iter_u64VTable TEST_FUNCTION_COROUTINE_FIBONACCI_2__VTABLE__ITER;
#line 31 "src/compiler/FunctionCoroutine.pv"
bool test_FunctionCoroutine_fibonacci_2__next(void* _ctx);

#endif
