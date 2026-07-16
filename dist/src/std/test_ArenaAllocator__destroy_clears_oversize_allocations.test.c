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
#include <std/ArenaOversize.h>
#include <std/test_ArenaAllocator__destroy_clears_oversize_allocations.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__destroy_clears_oversize_allocations() {
    #line 335 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);

    #line 337 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__Allocator__alloc(&allocator, 300) == 0) {
        #line 337 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 338 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__Allocator__alloc(&allocator, 400) == 0) {
        #line 338 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 340 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(&allocator);

    #line 342 "src/std/ArenaAllocator.pv"
    if (allocator.last_oversize != 0) {
        #line 342 "src/std/ArenaAllocator.pv"
        abort();
    }
}
