#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/ArenaState.h>
#include <std/test_ArenaAllocator__copies_share_allocation_ownership.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__copies_share_allocation_ownership() {
    #line 422 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 423 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator copy = allocator;
    #line 424 "src/std/ArenaAllocator.pv"
    if (allocator.state == 0 || copy.state != allocator.state) {
        #line 424 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 426 "src/std/ArenaAllocator.pv"
    void* allocation = ArenaAllocator__Allocator__alloc(&copy, 300);
    #line 427 "src/std/ArenaAllocator.pv"
    if (allocation == 0) {
        #line 427 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 428 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__Allocator__free(&allocator, allocation)) {
        #line 428 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 430 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(&allocator);
}
