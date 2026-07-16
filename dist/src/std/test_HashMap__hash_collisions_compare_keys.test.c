#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/HashMap_HashMapCollisionKey_i32.h>
#include <std/HashMapCollisionKey.h>
#include <std/test_HashMap__hash_collisions_compare_keys.test.h>

#line 1 "src/std/HashMap.pv"
void test_HashMap__hash_collisions_compare_keys() {
    #line 283 "src/std/HashMap.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 284 "src/std/HashMap.pv"
    if (allocator_ptr == 0) {
        #line 284 "src/std/HashMap.pv"
        abort();
    }
    #line 285 "src/std/HashMap.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 286 "src/std/HashMap.pv"

    #line 288 "src/std/HashMap.pv"
    struct HashMap_HashMapCollisionKey_i32 map = HashMap_HashMapCollisionKey_i32__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 289 "src/std/HashMap.pv"
    HashMapCollisionKey first = 1;
    #line 290 "src/std/HashMap.pv"
    HashMapCollisionKey second = 2;

    #line 292 "src/std/HashMap.pv"
    HashMap_HashMapCollisionKey_i32__insert(&map, first, 10);
    #line 293 "src/std/HashMap.pv"
    HashMap_HashMapCollisionKey_i32__insert(&map, second, 20);

    #line 295 "src/std/HashMap.pv"
    int32_t* first_value = HashMap_HashMapCollisionKey_i32__find(&map, &first);
    #line 296 "src/std/HashMap.pv"
    int32_t* second_value = HashMap_HashMapCollisionKey_i32__find(&map, &second);
    #line 297 "src/std/HashMap.pv"
    if (first_value == 0 || *first_value != 10) {
        #line 297 "src/std/HashMap.pv"
        abort();
    }
    #line 298 "src/std/HashMap.pv"
    if (second_value == 0 || *second_value != 20) {
        #line 298 "src/std/HashMap.pv"
        abort();
    }

    #line 300 "src/std/HashMap.pv"
    if (!HashMap_HashMapCollisionKey_i32__remove(&map, &first)) {
        #line 300 "src/std/HashMap.pv"
        abort();
    }
    #line 301 "src/std/HashMap.pv"
    if (HashMap_HashMapCollisionKey_i32__find(&map, &first) != 0) {
        #line 301 "src/std/HashMap.pv"
        abort();
    }

    #line 303 "src/std/HashMap.pv"
    second_value = HashMap_HashMapCollisionKey_i32__find(&map, &second);
    #line 304 "src/std/HashMap.pv"
    if (second_value == 0 || *second_value != 20) {
        #line 304 "src/std/HashMap.pv"
        abort();
    }
    ArenaAllocator__destroy(allocator);
}
