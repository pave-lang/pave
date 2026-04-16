#ifndef PAVE_STRING
#define PAVE_STRING

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/Array_char.h>

#line 5 "src/std/String.pv"
struct String {
    struct Array_char array;
};

#include <std/trait_Allocator.h>
#include <std/String.h>
#include <std/str.h>
struct String;

#line 10 "src/std/String.pv"
struct String String__new(struct trait_Allocator allocator);

#line 14 "src/std/String.pv"
void String__ensure_can_hold(struct String* self, uintptr_t length);

#line 28 "src/std/String.pv"
void String__append_sized(struct String* self, char const* ptr, uintptr_t length);

#line 39 "src/std/String.pv"
void String__append_sized_lowercase(struct String* self, char const* ptr, uintptr_t length);

#line 62 "src/std/String.pv"
void String__append_f64(struct String* self, double value);

#line 77 "src/std/String.pv"
void String__append_u64(struct String* self, uint64_t value);

#line 92 "src/std/String.pv"
void String__append_usize(struct String* self, uintptr_t value);

#line 107 "src/std/String.pv"
void String__append(struct String* self, struct str value);

#line 111 "src/std/String.pv"
void String__append_string(struct String* self, struct String* value);

#line 115 "src/std/String.pv"
void String__append_str_lowercase(struct String* self, struct str value);

#line 119 "src/std/String.pv"
void String__prepend_sized(struct String* self, char const* ptr, uintptr_t length);

#line 129 "src/std/String.pv"
void String__prepend(struct String* self, struct str s);

#line 133 "src/std/String.pv"
void String__clear(struct String* self);

#line 137 "src/std/String.pv"
void String__release(struct String* self);

#line 141 "src/std/String.pv"
struct str String__as_str(struct String* self);

#line 146 "src/std/String.pv"
char const* String__c_str(struct String* self);

#line 150 "src/std/String.pv"
bool String__eq(struct String* self, char const* s);

#line 158 "src/std/String.pv"
uintptr_t String__length(struct String* self);

#line 162 "src/std/String.pv"
int32_t String__len_i32(struct String* self);

#endif
