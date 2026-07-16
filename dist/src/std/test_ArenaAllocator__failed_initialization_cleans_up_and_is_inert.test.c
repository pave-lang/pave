#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert() {
    #line 449 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__guarded_backend()) {
        #line 450 "src/std/ArenaAllocator.pv"
        struct ArenaAllocator* allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1);
        #line 451 "src/std/ArenaAllocator.pv"
        if (allocator != 0) {
            #line 451 "src/std/ArenaAllocator.pv"
            abort();
        }
    }
}
