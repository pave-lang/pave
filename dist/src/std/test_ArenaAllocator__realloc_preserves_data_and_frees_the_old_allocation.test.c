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
#include <std/test_ArenaAllocator__realloc_preserves_data_and_frees_the_old_allocation.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__realloc_preserves_data_and_frees_the_old_allocation() {
    #line 419 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 420 "src/std/ArenaAllocator.pv"
    if (allocator_ptr == 0) {
        #line 420 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 421 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 422 "src/std/ArenaAllocator.pv"
    uint8_t* allocation = ArenaAllocator__Allocator__alloc(allocator, 8);
    #line 423 "src/std/ArenaAllocator.pv"
    if (allocation == 0) {
        #line 423 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 424 "src/std/ArenaAllocator.pv"
    allocation[0] = 17;
    #line 425 "src/std/ArenaAllocator.pv"
    allocation[7] = 29;

    #line 427 "src/std/ArenaAllocator.pv"
    uint8_t* grown = ArenaAllocator__Allocator__realloc(allocator, allocation, 32);
    #line 428 "src/std/ArenaAllocator.pv"
    if (grown == 0 || grown[0] != 17 || grown[7] != 29) {
        #line 428 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 429 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__Allocator__free(allocator, grown)) {
        #line 429 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 431 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(allocator);
}
