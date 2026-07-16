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
#include <std/ArenaState.h>
#include <std/test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert() {
    #line 460 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__guarded_backend()) {
        #line 461 "src/std/ArenaAllocator.pv"
        struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1);
        #line 462 "src/std/ArenaAllocator.pv"
        if (allocator.state != 0) {
            #line 462 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 463 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__alloc(&allocator, 1) != 0) {
            #line 463 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 464 "src/std/ArenaAllocator.pv"
        ArenaAllocator__destroy(&allocator);
    }
}
