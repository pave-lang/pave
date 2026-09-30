#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/HashSet_u32.h>
#include <std/test_HashSet__an_empty_set_literal_takes_inserts.test.h>

#line 1 "src/std/HashSet.pv"
void test_HashSet__an_empty_set_literal_takes_inserts() {
    #line 160 "src/std/HashSet.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 161 "src/std/HashSet.pv"
    if (allocator_ptr == 0) {
        #line 161 "src/std/HashSet.pv"
        abort();
    }
    #line 162 "src/std/HashSet.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 163 "src/std/HashSet.pv"

    #line 165 "src/std/HashSet.pv"
    struct HashSet_u32 empty = (struct HashSet_u32) { .allocator = allocator, .buckets = 0, .data = 0, .capacity = 0, .length = 0 };
    #line 166 "src/std/HashSet.pv"
    if (HashSet_u32__has(&empty, (uint32_t[]){(uint32_t)(3)})) {
        #line 166 "src/std/HashSet.pv"
        abort();
    }
    #line 167 "src/std/HashSet.pv"
    if (!HashSet_u32__insert(&empty, 3) || !HashSet_u32__has(&empty, (uint32_t[]){(uint32_t)(3)})) {
        #line 167 "src/std/HashSet.pv"
        abort();
    }
    ArenaAllocator__destroy(allocator);
}
