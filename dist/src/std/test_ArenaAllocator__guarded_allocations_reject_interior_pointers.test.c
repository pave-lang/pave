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
    #line 435 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__guarded_backend()) {
        #line 436 "src/std/ArenaAllocator.pv"
        struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
        #line 437 "src/std/ArenaAllocator.pv"
        if (allocator_ptr == 0) {
            #line 437 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 438 "src/std/ArenaAllocator.pv"
        struct ArenaAllocator* allocator = allocator_ptr;
        #line 439 "src/std/ArenaAllocator.pv"
        uint8_t* allocation = ArenaAllocator__Allocator__alloc(allocator, 16);
        #line 440 "src/std/ArenaAllocator.pv"
        if (allocation == 0) {
            #line 440 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 441 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__free(allocator, allocation + 1)) {
            #line 441 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 442 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__free(allocator, allocation - 1)) {
            #line 442 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 443 "src/std/ArenaAllocator.pv"
        if (!ArenaAllocator__Allocator__free(allocator, allocation)) {
            #line 443 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 444 "src/std/ArenaAllocator.pv"
        ArenaAllocator__destroy(allocator);
    }
}
