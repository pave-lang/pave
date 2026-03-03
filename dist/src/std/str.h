#ifndef PAVE_STR
#define PAVE_STR

#include <stdint.h>
#include <std/Hash.h>
#include <stdbool.h>

struct str;
struct ArrayIter_ptrc_char;
typedef uint64_t Hashed;

#include <string.h>

#line 3 "src/std/str.pv"
struct str {
    char const* ptr;
    uintptr_t length;
};

#line 9 "src/std/str.pv"
struct str str__new(char const* ptr);

#line 13 "src/std/str.pv"
struct str str__slice(struct str self, uintptr_t start, uintptr_t end);

#line 20 "src/std/str.pv"
bool str__eq(struct str self, struct str s);

#line 28 "src/std/str.pv"
bool str__eq_len(struct str self, char const* s, uintptr_t len);

#line 33 "src/std/str.pv"
bool str__contains(struct str self, char const* substring);

#line 47 "src/std/str.pv"
bool str__starts_with(struct str self, char const* prefix);

#line 54 "src/std/str.pv"
bool str__ends_with(struct str self, char const* suffix);

#line 61 "src/std/str.pv"
struct ArrayIter_ptrc_char str__iter(struct str self);

#line 65 "src/std/str.pv"
intptr_t str__index_of(struct str self, char ch);

#line 69 "src/std/str.pv"
intptr_t str__index_of_start(struct str self, char ch, uintptr_t start);

#line 82 "src/std/str.pv"
bool str__is_whitespace(char ch);

#line 86 "src/std/str.pv"
struct str str__trim(struct str self);

#line 103 "src/std/str.pv"
Hashed str__Hash__hash(void* __self);

extern struct HashVTable STR__VTABLE__HASH;

#endif
