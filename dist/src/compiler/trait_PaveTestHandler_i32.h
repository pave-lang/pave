#ifndef PAVE_TRAIT_PAVE_TEST_HANDLER_I32
#define PAVE_TRAIT_PAVE_TEST_HANDLER_I32

#include <stdint.h>


#line 7 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestHandler_i32VTable {
    #line 8 "src/compiler/TraitImplTest.pv"
    int32_t (*fn_handle)(void* __self, int32_t* value);
    #line 9 "src/compiler/TraitImplTest.pv"
    int32_t (*fn_doubled)(void* __self, int32_t* value);
};

#line 7 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestHandler_i32 {
    const struct trait_PaveTestHandler_i32VTable* vtable;
    void* instance;
};

#endif
