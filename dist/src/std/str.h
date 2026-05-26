#ifndef PAVE_STR
#define PAVE_STR

#include <stdint.h>
#include <stdbool.h>

#line 4 "src/std/str.pv"
struct str {
    char const* ptr;
    uintptr_t length;
};

#include <std/str.h>
#include <std/Iter_ptrc_char.h>
#include <std/Hash.h>
struct str;

#line 10 "src/std/str.pv"
struct str str__new(char const* ptr);

#line 14 "src/std/str.pv"
struct str str__slice(struct str self, uintptr_t start, uintptr_t end);

#line 21 "src/std/str.pv"
bool str__eq_len(struct str self, char const* s, uintptr_t len);

#line 26 "src/std/str.pv"
bool str__contains(struct str self, char const* substring);

#line 40 "src/std/str.pv"
bool str__starts_with(struct str self, char const* prefix);

#line 47 "src/std/str.pv"
bool str__ends_with(struct str self, char const* suffix);

#line 54 "src/std/str.pv"
struct Iter_ptrc_char str__iter(struct str self);

#line 58 "src/std/str.pv"
intptr_t str__index_of(struct str self, char ch);

#line 62 "src/std/str.pv"
intptr_t str__index_of_start(struct str self, char ch, uintptr_t start);

#line 75 "src/std/str.pv"
intptr_t str__index_of_last(struct str self, char ch);

#line 86 "src/std/str.pv"
bool str__is_whitespace(char ch);

#line 90 "src/std/str.pv"
struct str str__trim(struct str self);

#line 107 "src/std/str.pv"
Hash str__Hash__hash(void* __self);

#line 111 "src/std/str.pv"
bool str__Eq_str__eq(void* __self, struct str other);

#line 119 "src/std/str.pv"
bool str__Eq_ptrc_char__eq(void* __self, char const* other);

extern struct trait_HashVTable STR__VTABLE__HASH;
extern struct trait_Eq_ptrc_charVTable STR__VTABLE__EQ;

#endif
