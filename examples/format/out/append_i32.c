#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/String.h>
#include <std/trait_Allocator.h>
#include <std/Array_char.h>
#include <std/str.h>
#include <std/trait_Writer.h>
#include <format/append_i32.h>

void append_i32(struct trait_Writer out, int32_t value, struct str info) {
    struct GeneralPurposeAllocator* allocator = GeneralPurposeAllocator__default();
    struct String buffer = String__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    struct Array_char* array = &buffer.array;

    String__ensure_can_hold(&buffer, 20);
    if (str__Eq_str__eq(&info, (struct str){ .ptr = "x", .length = strlen("x") }) || str__Eq_str__eq(&info, (struct str){ .ptr = "hex", .length = strlen("hex") })) {
        array->length += snprintf(array->data + array->length, 20, "%x", value);
    } else {
        array->length += snprintf(array->data + array->length, 20, "%d", value);
    }
    array->data[array->length] = 0;

    out.vtable->fn_write(out.instance, String__as_str(&buffer));
    String__release(&buffer);
}
