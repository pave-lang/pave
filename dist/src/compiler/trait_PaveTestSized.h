#ifndef PAVE_TRAIT_PAVE_TEST_SIZED
#define PAVE_TRAIT_PAVE_TEST_SIZED

#include <stdint.h>


#line 19 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestSizedVTable {
    #line 19 "src/compiler/TraitImplTest.pv"
    int32_t (*fn_size)(void* __self);
};

#line 19 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestSized {
    const struct trait_PaveTestSizedVTable* vtable;
    void* instance;
};

#endif
