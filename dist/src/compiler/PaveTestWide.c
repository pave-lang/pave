#include <stdlib.h>

#include <compiler/PaveTestWide.h>

#include <compiler/PaveTestWide.h>

#line 35 "src/compiler/TraitImplTest.pv"
int32_t PaveTestWide__PaveTestStatic__kind() {
    #line 35 "src/compiler/TraitImplTest.pv"
    return 4;
}

#line 28 "src/compiler/TraitImplTest.pv"
uintptr_t PaveTestWide__PaveTestStatic__bytes() {
    #line 28 "src/compiler/TraitImplTest.pv"
    return sizeof(struct PaveTestWide);
}

struct trait_PaveTestStaticVTable PAVE_TEST_WIDE__VTABLE__PAVE_TEST_STATIC = { .fn_bytes = &PaveTestWide__PaveTestStatic__bytes, .fn_kind = &PaveTestWide__PaveTestStatic__kind };
