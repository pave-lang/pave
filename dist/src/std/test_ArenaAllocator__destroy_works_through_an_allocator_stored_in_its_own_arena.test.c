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
#include <std/test_ArenaAllocator__destroy_works_through_an_allocator_stored_in_its_own_arena.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__destroy_works_through_an_allocator_stored_in_its_own_arena() {
    #line 456 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 457 "src/std/ArenaAllocator.pv"
    if (allocator_ptr == 0) {
        #line 457 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 458 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 459 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator** stored = ArenaAllocator__store_ptr_ArenaAllocator(allocator, &allocator_ptr);
    #line 460 "src/std/ArenaAllocator.pv"
    if (stored == 0) {
        #line 460 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 461 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* stored_ptr = *stored;
    #line 462 "src/std/ArenaAllocator.pv"
    if (stored_ptr == 0) {
        #line 462 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 463 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* stored_ref = stored_ptr;

    #line 465 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(stored_ref);
}
