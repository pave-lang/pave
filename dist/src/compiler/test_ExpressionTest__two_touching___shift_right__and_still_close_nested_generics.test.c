#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>

#include <stdlib.h>
#include <std/Array_Array_u32.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <compiler/test_ExpressionTest__two_touching___shift_right__and_still_close_nested_generics.test.h>

#line 1 "src/compiler/ExpressionTest.pv"
void test_ExpressionTest__two_touching___shift_right__and_still_close_nested_generics() {
    #line 9 "src/compiler/ExpressionTest.pv"
    uint32_t word = 197121u;
    #line 10 "src/compiler/ExpressionTest.pv"
    struct Array_Array_u32 nested = Array_Array_u32__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() });
    #line 11 "src/compiler/ExpressionTest.pv"
    if (((word >> 8) & 255u) != 2 || (word >> 16) != 3 || nested.length != 0) {
        #line 11 "src/compiler/ExpressionTest.pv"
        abort();
    }
    #line 12 "src/compiler/ExpressionTest.pv"
    if (!(word > 3)) {
        #line 12 "src/compiler/ExpressionTest.pv"
        abort();
    }
}
