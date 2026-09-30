#ifndef PAVE_TRAIT_PAVE_TEST_NAMED
#define PAVE_TRAIT_PAVE_TEST_NAMED

#include <stdint.h>


#line 18 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestNamedVTable {
    #line 18 "src/compiler/TraitImplTest.pv"
    int32_t (*fn_name)(void* __self);
};

#line 18 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestNamed {
    const struct trait_PaveTestNamedVTable* vtable;
    void* instance;
};

#endif
