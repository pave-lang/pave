#ifndef PAVE_STR
#define PAVE_STR

#include <stdint.h>
#include <stdbool.h>

#include <string.h>

#line 3 "src/std/str.pv"
struct str {
    char const* ptr;
    uintptr_t length;
};

struct str;
#include <std/str.h>
#include <std/Iter_ptrc_char.h>
#include <std/Hashed.h>

#line 9 "src/std/str.pv"
struct str str__new(char const* ptr);

#line 13 "src/std/str.pv"
struct str str__slice(struct str self, uintptr_t start, uintptr_t end);

#line 20 "src/std/str.pv"
bool str__eq(struct str self, struct str s);

#line 26 "src/std/str.pv"
bool str__eq_len(struct str self, char const* s, uintptr_t len);

#line 31 "src/std/str.pv"
bool str__contains(struct str self, char const* substring);

#line 45 "src/std/str.pv"
bool str__starts_with(struct str self, char const* prefix);

#line 52 "src/std/str.pv"
bool str__ends_with(struct str self, char const* suffix);

#line 59 "src/std/str.pv"
struct Iter_ptrc_char str__iter(struct str self);

#line 63 "src/std/str.pv"
intptr_t str__index_of(struct str self, char ch);

#line 67 "src/std/str.pv"
intptr_t str__index_of_start(struct str self, char ch, uintptr_t start);

#line 80 "src/std/str.pv"
bool str__is_whitespace(char ch);

#line 84 "src/std/str.pv"
struct str str__trim(struct str self);

#line 101 "src/std/str.pv"
Hashed str__Hash__hash(void* __self);

extern struct trait_HashVTable STR__VTABLE__HASH;

#endif
