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
#include <std/test_ArenaAllocator__guarded_allocations_reject_interior_pointers.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__guarded_allocations_reject_interior_pointers() {
    #line 448 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__guarded_backend()) {
        #line 449 "src/std/ArenaAllocator.pv"
        struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
        #line 450 "src/std/ArenaAllocator.pv"
        uint8_t* allocation = ArenaAllocator__Allocator__alloc(&allocator, 16);
        #line 451 "src/std/ArenaAllocator.pv"
        if (allocation == 0) {
            #line 451 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 452 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__free(&allocator, allocation + 1)) {
            #line 452 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 453 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__free(&allocator, allocation - 1)) {
            #line 453 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 454 "src/std/ArenaAllocator.pv"
        if (!ArenaAllocator__Allocator__free(&allocator, allocation)) {
            #line 454 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 455 "src/std/ArenaAllocator.pv"
        ArenaAllocator__destroy(&allocator);
    }
}
