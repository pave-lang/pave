#include <stdio.h>

#include <stdint.h>
#include <std/Array_i32.h>
#include <std/Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/ArrayIter_ref_i32.h>
#include <std/Array_tuple_ptrc_char_i32_f32.h>
#include <tuple_ptrc_char_i32_f32.h>
#include <std/ArrayIter_ref_tuple_ptrc_char_i32_f32.h>
#include <std/HashMap_str_i32.h>
#include <std/str.h>
#include <tuple_str_i32.h>
#include <std/HashMapIter_str_i32.h>

#include <iterators/main.h>

int32_t main(int32_t argc, char const** argv) {
    for (int32_t i = 0; i < 10; i++) {
        printf("index: %d\n", i);
    }

    struct Array_i32 array = Array_i32__new((struct Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() });
    Array_i32__append(&array, 3);
    Array_i32__append(&array, 4);
    Array_i32__append(&array, 1);
    { struct ArrayIter_ref_i32 __iter = Array_i32__iter(&array);
    while (ArrayIter_ref_i32__next(&__iter)) {
        int32_t a = *ArrayIter_ref_i32__value(&__iter);

        printf("array: %d\n", a);
    } }

    struct Array_tuple_ptrc_char_i32_f32 array_tuple = Array_tuple_ptrc_char_i32_f32__new((struct Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() });
    Array_i32__append(&array, (struct tuple_ptrc_char_i32_f32) { ._0 = "hello", ._1 = 3, ._2 = 1.5f });
    Array_i32__append(&array, (struct tuple_ptrc_char_i32_f32) { ._0 = "world", ._1 = 4, ._2 = 2.0f });
    Array_i32__append(&array, (struct tuple_ptrc_char_i32_f32) { ._0 = "!", ._1 = 1, ._2 = 1.0f });
    { struct ArrayIter_ref_tuple_ptrc_char_i32_f32 __iter = Array_tuple_ptrc_char_i32_f32__iter(&array_tuple);
    while (ArrayIter_ref_tuple_ptrc_char_i32_f32__next(&__iter)) {
        char const* a = ArrayIter_ref_tuple_ptrc_char_i32_f32__value(&__iter)->_0;
        int32_t b = ArrayIter_ref_tuple_ptrc_char_i32_f32__value(&__iter)->_1;
        float c = ArrayIter_ref_tuple_ptrc_char_i32_f32__value(&__iter)->_2;

        printf("tuple: %s %d %.2f\n", a, b, c);
    } }

    struct HashMap_str_i32 hashmap = HashMap_str_i32__new((struct Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() });
    HashMap_str_i32__insert(&hashmap, (struct str){ .ptr = "hello", .length = strlen("hello") }, 3);
    HashMap_str_i32__insert(&hashmap, (struct str){ .ptr = "world", .length = strlen("world") }, 4);
    HashMap_str_i32__insert(&hashmap, (struct str){ .ptr = "!", .length = strlen("!") }, 1);
    { struct HashMapIter_str_i32 __iter = HashMap_str_i32__iter(&hashmap);
    while (HashMapIter_str_i32__next(&__iter)) {
        struct str key = HashMapIter_str_i32__value(&__iter)->_0;
        int32_t value = HashMapIter_str_i32__value(&__iter)->_1;

        printf("hashmap key: %.*s, value: %d\n", (int32_t)(key.length), key.ptr, value);
    } }

    return 0;
}
