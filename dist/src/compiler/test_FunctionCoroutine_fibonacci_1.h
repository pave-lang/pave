#ifndef PAVE_TEST_FUNCTION_COROUTINE_FIBONACCI_1
#define PAVE_TEST_FUNCTION_COROUTINE_FIBONACCI_1

#include <stdint.h>

struct test_FunctionCoroutine_fibonacci_1 {
    int32_t _state;
    uint64_t _value;

    uintptr_t n;
    uint64_t a;
    uint64_t b;
    uintptr_t i;
    uint64_t tmp;
};

#include <std/trait_Iter_u64.h>
uint64_t test_FunctionCoroutine_fibonacci_1__value(void* ctx);
extern struct trait_Iter_u64VTable TEST_FUNCTION_COROUTINE_FIBONACCI_1__VTABLE__ITER;
#line 20 "src/compiler/FunctionCoroutine.pv"
bool test_FunctionCoroutine_fibonacci_1__next(void* _ctx);

#endif
