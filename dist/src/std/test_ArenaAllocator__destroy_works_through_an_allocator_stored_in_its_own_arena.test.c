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
    #line 469 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 470 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* stored = ArenaAllocator__store_ArenaAllocator(&allocator, &allocator);
    #line 471 "src/std/ArenaAllocator.pv"
    if (stored == 0) {
        #line 471 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 472 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* stored_ref = stored;

    #line 474 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(stored_ref);
}
