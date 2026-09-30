#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/HashMap_u32_i32.h>
#include <std/test_HashMap__an_empty_map_literal_and_its_clone_take_inserts.test.h>

#line 1 "src/std/HashMap.pv"
void test_HashMap__an_empty_map_literal_and_its_clone_take_inserts() {
    #line 316 "src/std/HashMap.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 317 "src/std/HashMap.pv"
    if (allocator_ptr == 0) {
        #line 317 "src/std/HashMap.pv"
        abort();
    }
    #line 318 "src/std/HashMap.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 319 "src/std/HashMap.pv"

    #line 321 "src/std/HashMap.pv"
    struct HashMap_u32_i32 empty = (struct HashMap_u32_i32) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 };
    #line 322 "src/std/HashMap.pv"
    if (HashMap_u32_i32__find(&empty, (uint32_t[]){(uint32_t)(1)}) != 0) {
        #line 322 "src/std/HashMap.pv"
        abort();
    }
    #line 323 "src/std/HashMap.pv"
    struct HashMap_u32_i32 copy = HashMap_u32_i32__clone(&empty, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 324 "src/std/HashMap.pv"
    HashMap_u32_i32__insert(&copy, 1, 10);
    #line 325 "src/std/HashMap.pv"
    HashMap_u32_i32__insert(&empty, 2, 20);
    #line 326 "src/std/HashMap.pv"
    int32_t* one = HashMap_u32_i32__find(&copy, (uint32_t[]){(uint32_t)(1)});
    #line 327 "src/std/HashMap.pv"
    int32_t* two = HashMap_u32_i32__find(&empty, (uint32_t[]){(uint32_t)(2)});
    #line 328 "src/std/HashMap.pv"
    if (one == 0 || *one != 10) {
        #line 328 "src/std/HashMap.pv"
        abort();
    }
    #line 329 "src/std/HashMap.pv"
    if (two == 0 || *two != 20) {
        #line 329 "src/std/HashMap.pv"
        abort();
    }
    ArenaAllocator__destroy(allocator);
}
