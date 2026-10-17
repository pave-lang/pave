#ifndef PAVE_PAVE_TEST_COUNTER
#define PAVE_PAVE_TEST_COUNTER

#include <stdint.h>

#line 13 "src/compiler/TraitImplTest.pv"
struct PaveTestCounter {
    int32_t count;
};

#include <compiler/trait_PaveTestHandler_i32.h>

#line 16 "src/compiler/TraitImplTest.pv"
int32_t PaveTestCounter__PaveTestHandler_i32__handle(void* __self, int32_t* value);

#line 10 "src/compiler/TraitImplTest.pv"
int32_t PaveTestCounter__PaveTestHandler_i32__doubled(void* __self, int32_t* value);

extern struct trait_PaveTestHandler_i32VTable PAVE_TEST_COUNTER__VTABLE__PAVE_TEST_HANDLER;

#endif
