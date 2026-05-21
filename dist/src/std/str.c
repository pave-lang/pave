#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <string.h>
#include <std/str.h>
#include <std/Iter_ptrc_char.h>
#include <std/Range_ptrc_char.h>
#include <std/Range_usize.h>
#include <std/trait_Hash.h>
#include <std/Hash.h>
#include <std/Fnv1a.h>
#include <std/trait_Eq_str.h>
#include <std/trait_Eq_ref_str.h>
#include <std/str.h>

#include <std/str.h>

#line 10 "src/std/str.pv"
struct str str__new(char const* ptr) {
    #line 11 "src/std/str.pv"
    return (struct str) { .ptr = ptr, .length = strlen(ptr) };
}

#line 14 "src/std/str.pv"
struct str str__slice(struct str self, uintptr_t start, uintptr_t end) {
    #line 15 "src/std/str.pv"
    return (struct str) {
        .ptr = self.ptr + start,
        .length = end - start,
    };
}

#line 21 "src/std/str.pv"
bool str__eq_len(struct str self, char const* s, uintptr_t len) {
    #line 22 "src/std/str.pv"
    if (len > self.length) {
        #line 22 "src/std/str.pv"
        return false;
    }
    #line 23 "src/std/str.pv"
    return strncmp(self.ptr, s, len) == 0;
}

#line 26 "src/std/str.pv"
bool str__contains(struct str self, char const* substring) {
    #line 27 "src/std/str.pv"
    uintptr_t sub_len = strlen(substring);
    #line 28 "src/std/str.pv"
    if (sub_len > self.length) {
        #line 28 "src/std/str.pv"
        return false;
    }

    #line 30 "src/std/str.pv"
    uintptr_t i = 0;
    #line 31 "src/std/str.pv"
    while (i <= self.length - sub_len) {
        #line 32 "src/std/str.pv"
        if (strncmp(self.ptr + i, substring, sub_len) == 0) {
            #line 33 "src/std/str.pv"
            return true;
        }
        #line 35 "src/std/str.pv"
        i = i + 1;
    }
    #line 37 "src/std/str.pv"
    return false;
}

#line 40 "src/std/str.pv"
bool str__starts_with(struct str self, char const* prefix) {
    #line 41 "src/std/str.pv"
    uint64_t prefix_len = strlen(prefix);
    #line 42 "src/std/str.pv"
    if (self.length < prefix_len) {
        #line 42 "src/std/str.pv"
        return false;
    }

    #line 44 "src/std/str.pv"
    return strncmp(self.ptr, prefix, prefix_len) == 0;
}

#line 47 "src/std/str.pv"
bool str__ends_with(struct str self, char const* suffix) {
    #line 48 "src/std/str.pv"
    uint64_t suffix_len = strlen(suffix);
    #line 49 "src/std/str.pv"
    if (self.length < suffix_len) {
        #line 49 "src/std/str.pv"
        return false;
    }

    #line 51 "src/std/str.pv"
    return strncmp(self.ptr + self.length - suffix_len, suffix, suffix_len) == 0;
}

#line 54 "src/std/str.pv"
struct Iter_ptrc_char str__iter(struct str self) {
    #line 55 "src/std/str.pv"
    return Iter_ptrc_char__new(self.ptr, self.ptr + self.length);
}

#line 58 "src/std/str.pv"
intptr_t str__index_of(struct str self, char ch) {
    #line 59 "src/std/str.pv"
    return str__index_of_start(self, ch, 0);
}

#line 62 "src/std/str.pv"
intptr_t str__index_of_start(struct str self, char ch, uintptr_t start) {
    #line 63 "src/std/str.pv"
    char const* s = self.ptr + start;
    #line 64 "src/std/str.pv"
    char const* e = self.ptr + self.length;

    #line 66 "src/std/str.pv"
    for (char const* ptr = s; ptr < e; ptr++) {
        #line 67 "src/std/str.pv"
        if (*ptr == ch) {
            #line 68 "src/std/str.pv"
            return ptr - self.ptr;
        }
    }

    #line 72 "src/std/str.pv"
    return -1;
}

#line 75 "src/std/str.pv"
intptr_t str__index_of_last(struct str self, char ch) {
    #line 76 "src/std/str.pv"
    for (uintptr_t i = 0; i < self.length; i++) {
        #line 77 "src/std/str.pv"
        char const* ptr = self.ptr + self.length - 1 - i;
        #line 78 "src/std/str.pv"
        if (*ptr == ch) {
            #line 79 "src/std/str.pv"
            return ptr - self.ptr;
        }
    }

    #line 83 "src/std/str.pv"
    return -1;
}

#line 86 "src/std/str.pv"
bool str__is_whitespace(char ch) {
    #line 87 "src/std/str.pv"
    return (ch == ' ') || (ch == '\r') || (ch == '\n') || (ch == '\t');
}

#line 90 "src/std/str.pv"
struct str str__trim(struct str self) {
    #line 91 "src/std/str.pv"
    uintptr_t start = 0;
    #line 92 "src/std/str.pv"
    uintptr_t end = self.length;

    #line 94 "src/std/str.pv"
    while (start < end && str__is_whitespace(self.ptr[start])) {
        #line 95 "src/std/str.pv"
        start = start + 1;
    }

    #line 98 "src/std/str.pv"
    while (end > start && str__is_whitespace(self.ptr[end - 1])) {
        #line 99 "src/std/str.pv"
        end = end - 1;
    }

    #line 102 "src/std/str.pv"
    return str__slice(self, start, end);
}

#line 107 "src/std/str.pv"
Hash str__Hash__hash(void* __self) {
    struct str* self = __self; (void)self;
    #line 107 "src/std/str.pv"
    return Fnv1a__hash(self->ptr, self->length);
}

#line 111 "src/std/str.pv"
bool str__Eq_str__eq(void* __self, struct str other) {
    struct str* self = __self; (void)self;
    #line 112 "src/std/str.pv"
    if (self->length != other.length) {
        #line 112 "src/std/str.pv"
        return false;
    }

    #line 114 "src/std/str.pv"
    return strncmp(self->ptr, other.ptr, self->length) == 0;
}

#line 119 "src/std/str.pv"
bool str__Eq_ref_str__eq(void* __self, struct str* other) {
    struct str* self = __self; (void)self;
    #line 120 "src/std/str.pv"
    if (self->length != other->length) {
        #line 120 "src/std/str.pv"
        return false;
    }

    #line 122 "src/std/str.pv"
    return strncmp(self->ptr, other->ptr, self->length) == 0;
}

struct trait_HashVTable STR__VTABLE__HASH = { .fn_hash = &str__Hash__hash };
struct trait_Eq_ref_strVTable STR__VTABLE__EQ = { .fn_eq = &str__Eq_ref_str__eq };
