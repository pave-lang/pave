#ifndef PAVE_PAVE_TEST_WIDE
#define PAVE_PAVE_TEST_WIDE

#include <stdint.h>

#line 32 "src/compiler/TraitImplTest.pv"
struct PaveTestWide {
    int64_t a;
    int64_t b;
};

#include <compiler/trait_PaveTestStatic.h>

#line 35 "src/compiler/TraitImplTest.pv"
int32_t PaveTestWide__PaveTestStatic__kind();

#line 28 "src/compiler/TraitImplTest.pv"
uintptr_t PaveTestWide__PaveTestStatic__bytes();

extern struct trait_PaveTestStaticVTable PAVE_TEST_WIDE__VTABLE__PAVE_TEST_STATIC;

#endif
