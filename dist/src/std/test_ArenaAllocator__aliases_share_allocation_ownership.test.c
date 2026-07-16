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
#include <std/test_ArenaAllocator__aliases_share_allocation_ownership.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__aliases_share_allocation_ownership() {
    #line 406 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 407 "src/std/ArenaAllocator.pv"
    if (allocator_ptr == 0) {
        #line 407 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 408 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 409 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* alias = allocator;

    #line 411 "src/std/ArenaAllocator.pv"
    void* allocation = ArenaAllocator__Allocator__alloc(alias, 300);
    #line 412 "src/std/ArenaAllocator.pv"
    if (allocation == 0) {
        #line 412 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 413 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__Allocator__free(allocator, allocation)) {
        #line 413 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 415 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(allocator);
}
