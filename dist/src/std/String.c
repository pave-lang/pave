#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/Allocator.h>
#include <std/Array_char.h>
#include <stdint.h>
#include <stdbool.h>
#include <std/str.h>

#include <std/String.h>

#line 10 "src/std/String.pv"
struct String String__new(struct Allocator allocator) {
    #line 11 "src/std/String.pv"
    return (struct String) { .array = Array_char__new(allocator) };
}

#line 14 "src/std/String.pv"
void String__ensure_can_hold(struct String* self, uintptr_t length) {
    #line 15 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 17 "src/std/String.pv"
    if ((array->length + length >= array->capacity)) {
        #line 18 "src/std/String.pv"
        uintptr_t reserve = array->length + length + 1;

        #line 20 "src/std/String.pv"
        if (reserve < array->capacity) {
            #line 21 "src/std/String.pv"
            reserve = array->capacity;
        }

        #line 24 "src/std/String.pv"
        Array_char__reserve(array, array->capacity + reserve);
    }
}

#line 28 "src/std/String.pv"
void String__append_sized(struct String* self, char const* ptr, uintptr_t length) {
    #line 29 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 31 "src/std/String.pv"
    String__ensure_can_hold(self, length);

    #line 33 "src/std/String.pv"
    memcpy(array->data + array->length, ptr, length);
    #line 34 "src/std/String.pv"
    array->length += length;

    #line 36 "src/std/String.pv"
    array->data[array->length] = 0;
}

#line 39 "src/std/String.pv"
void String__append_sized_lowercase(struct String* self, char const* ptr, uintptr_t length) {
    #line 40 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 42 "src/std/String.pv"
    String__ensure_can_hold(self, length);

    #line 44 "src/std/String.pv"
    uintptr_t i = 0;

    #line 46 "src/std/String.pv"
    while (i < length) {
        #line 47 "src/std/String.pv"
        char c = ptr[i];

        #line 49 "src/std/String.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 50 "src/std/String.pv"
            array->data[array->length] = c + 32;
        } else {
            #line 52 "src/std/String.pv"
            array->data[array->length] = c;
        }

        #line 55 "src/std/String.pv"
        i += 1;
        #line 56 "src/std/String.pv"
        array->length += 1;
    }

    #line 59 "src/std/String.pv"
    array->data[array->length] = 0;
}

#line 62 "src/std/String.pv"
void String__append_f64(struct String* self, double value) {
    #line 63 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 65 "src/std/String.pv"
    if (value == 0) {
        #line 66 "src/std/String.pv"
        String__ensure_can_hold(self, 1);
        #line 67 "src/std/String.pv"
        array->data[array->length] = '0';
        #line 68 "src/std/String.pv"
        array->length += 1;
        #line 69 "src/std/String.pv"
        return;
    }

    #line 72 "src/std/String.pv"
    String__ensure_can_hold(self, 20);

    #line 74 "src/std/String.pv"
    array->length += snprintf(array->data + array->length, 20, "%g", value);
}

#line 77 "src/std/String.pv"
void String__append_u64(struct String* self, uint64_t value) {
    #line 78 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 80 "src/std/String.pv"
    if (value == 0) {
        #line 81 "src/std/String.pv"
        String__ensure_can_hold(self, 1);
        #line 82 "src/std/String.pv"
        array->data[array->length] = '0';
        #line 83 "src/std/String.pv"
        array->length += 1;
        #line 84 "src/std/String.pv"
        return;
    }

    #line 87 "src/std/String.pv"
    String__ensure_can_hold(self, 20);

    #line 89 "src/std/String.pv"
    array->length += snprintf(array->data + array->length, 20, "%zu", value);
}

#line 92 "src/std/String.pv"
void String__append_usize(struct String* self, uintptr_t value) {
    #line 93 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 95 "src/std/String.pv"
    if (value == 0) {
        #line 96 "src/std/String.pv"
        String__ensure_can_hold(self, 1);
        #line 97 "src/std/String.pv"
        array->data[array->length] = '0';
        #line 98 "src/std/String.pv"
        array->length += 1;
        #line 99 "src/std/String.pv"
        return;
    }

    #line 102 "src/std/String.pv"
    String__ensure_can_hold(self, 20);

    #line 104 "src/std/String.pv"
    array->length += snprintf(array->data + array->length, 20, "%zu", value);
}

#line 107 "src/std/String.pv"
void String__append(struct String* self, struct str value) {
    #line 108 "src/std/String.pv"
    String__append_sized(self, value.ptr, value.length);
}

#line 111 "src/std/String.pv"
void String__append_string(struct String* self, struct String* value) {
    #line 112 "src/std/String.pv"
    String__append(self, String__as_str(value));
}

#line 115 "src/std/String.pv"
void String__append_str_lowercase(struct String* self, struct str value) {
    #line 116 "src/std/String.pv"
    String__append_sized_lowercase(self, value.ptr, value.length);
}

#line 119 "src/std/String.pv"
void String__prepend_sized(struct String* self, char const* ptr, uintptr_t length) {
    #line 120 "src/std/String.pv"
    struct Array_char* array = &self->array;

    #line 122 "src/std/String.pv"
    String__ensure_can_hold(self, length);

    #line 124 "src/std/String.pv"
    memmove(array->data + length, array->data, array->length + 1);
    #line 125 "src/std/String.pv"
    memcpy(array->data, ptr, length);
    #line 126 "src/std/String.pv"
    array->length += length;
}

#line 129 "src/std/String.pv"
void String__prepend(struct String* self, struct str s) {
    #line 130 "src/std/String.pv"
    String__prepend_sized(self, s.ptr, s.length);
}

#line 133 "src/std/String.pv"
void String__clear(struct String* self) {
    #line 134 "src/std/String.pv"
    Array_char__clear(&self->array);
}

#line 137 "src/std/String.pv"
void String__release(struct String* self) {
    #line 138 "src/std/String.pv"
    Array_char__release(&self->array);
}

#line 141 "src/std/String.pv"
struct str String__as_str(struct String* self) {
    #line 142 "src/std/String.pv"
    struct Array_char* array = &self->array;
    #line 143 "src/std/String.pv"
    return (struct str) { .ptr = array->data, .length = array->length };
}

#line 146 "src/std/String.pv"
char const* String__c_str(struct String* self) {
    #line 147 "src/std/String.pv"
    return self->array.data;
}

#line 150 "src/std/String.pv"
bool String__eq(struct String* self, char const* s) {
    #line 151 "src/std/String.pv"
    uintptr_t length = strlen(s);

    #line 153 "src/std/String.pv"
    if (self->array.length != length) {
        #line 153 "src/std/String.pv"
        return false;
    }

    #line 155 "src/std/String.pv"
    return strncmp(self->array.data, s, length) == 0;
}

#line 158 "src/std/String.pv"
uintptr_t String__length(struct String* self) {
    #line 159 "src/std/String.pv"
    return self->array.length;
}

#line 162 "src/std/String.pv"
int32_t String__len_i32(struct String* self) {
    #line 163 "src/std/String.pv"
    return self->array.length;
}
