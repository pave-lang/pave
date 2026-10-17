#ifndef PAVE_TRAIT_PAVE_TEST_STATIC
#define PAVE_TRAIT_PAVE_TEST_STATIC

#include <stdint.h>


#line 27 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestStaticVTable {
    #line 28 "src/compiler/TraitImplTest.pv"
    uintptr_t (*fn_bytes)();
    #line 29 "src/compiler/TraitImplTest.pv"
    int32_t (*fn_kind)();
};

#line 27 "src/compiler/TraitImplTest.pv"
struct trait_PaveTestStatic {
    const struct trait_PaveTestStaticVTable* vtable;
    void* instance;
};

#endif
