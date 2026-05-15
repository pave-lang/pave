#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <string.h>
#include <std/str.h>
#include <std/Iter_ptrc_char.h>
#include <std/Range_ptrc_char.h>
#include <std/Range_usize.h>
#include <std/trait_Hash.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>
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
bool str__eq(struct str self, struct str s) {
    #line 22 "src/std/str.pv"
    if (self.length != s.length) {
        #line 22 "src/std/str.pv"
        return false;
    }

    #line 24 "src/std/str.pv"
    return strncmp(self.ptr, s.ptr, self.length) == 0;
}

#line 27 "src/std/str.pv"
bool str__eq_len(struct str self, char const* s, uintptr_t len) {
    #line 28 "src/std/str.pv"
    if (len > self.length) {
        #line 28 "src/std/str.pv"
        return false;
    }
    #line 29 "src/std/str.pv"
    return strncmp(self.ptr, s, len) == 0;
}

#line 32 "src/std/str.pv"
bool str__contains(struct str self, char const* substring) {
    #line 33 "src/std/str.pv"
    uintptr_t sub_len = strlen(substring);
    #line 34 "src/std/str.pv"
    if (sub_len > self.length) {
        #line 34 "src/std/str.pv"
        return false;
    }

    #line 36 "src/std/str.pv"
    uintptr_t i = 0;
    #line 37 "src/std/str.pv"
    while (i <= self.length - sub_len) {
        #line 38 "src/std/str.pv"
        if (strncmp(self.ptr + i, substring, sub_len) == 0) {
            #line 39 "src/std/str.pv"
            return true;
        }
        #line 41 "src/std/str.pv"
        i = i + 1;
    }
    #line 43 "src/std/str.pv"
    return false;
}

#line 46 "src/std/str.pv"
bool str__starts_with(struct str self, char const* prefix) {
    #line 47 "src/std/str.pv"
    uint64_t prefix_len = strlen(prefix);
    #line 48 "src/std/str.pv"
    if (self.length < prefix_len) {
        #line 48 "src/std/str.pv"
        return false;
    }

    #line 50 "src/std/str.pv"
    return strncmp(self.ptr, prefix, prefix_len) == 0;
}

#line 53 "src/std/str.pv"
bool str__ends_with(struct str self, char const* suffix) {
    #line 54 "src/std/str.pv"
    uint64_t suffix_len = strlen(suffix);
    #line 55 "src/std/str.pv"
    if (self.length < suffix_len) {
        #line 55 "src/std/str.pv"
        return false;
    }

    #line 57 "src/std/str.pv"
    return strncmp(self.ptr + self.length - suffix_len, suffix, suffix_len) == 0;
}

#line 60 "src/std/str.pv"
struct Iter_ptrc_char str__iter(struct str self) {
    #line 61 "src/std/str.pv"
    return Iter_ptrc_char__new(self.ptr, self.ptr + self.length);
}

#line 64 "src/std/str.pv"
intptr_t str__index_of(struct str self, char ch) {
    #line 65 "src/std/str.pv"
    return str__index_of_start(self, ch, 0);
}

#line 68 "src/std/str.pv"
intptr_t str__index_of_start(struct str self, char ch, uintptr_t start) {
    #line 69 "src/std/str.pv"
    char const* s = self.ptr + start;
    #line 70 "src/std/str.pv"
    char const* e = self.ptr + self.length;

    #line 72 "src/std/str.pv"
    for (char const* ptr = s; ptr < e; ptr++) {
        #line 73 "src/std/str.pv"
        if (*ptr == ch) {
            #line 74 "src/std/str.pv"
            return ptr - self.ptr;
        }
    }

    #line 78 "src/std/str.pv"
    return -1;
}

#line 81 "src/std/str.pv"
intptr_t str__index_of_last(struct str self, char ch) {
    #line 82 "src/std/str.pv"
    char const* s = self.ptr;

    #line 84 "src/std/str.pv"
    for (uintptr_t i = 0; i < self.length; i++) {
        #line 85 "src/std/str.pv"
        char const* ptr = self.ptr + self.length - 1 - i;
        #line 86 "src/std/str.pv"
        if (*ptr == ch) {
            #line 87 "src/std/str.pv"
            return ptr - self.ptr;
        }
    }

    #line 91 "src/std/str.pv"
    return -1;
}

#line 94 "src/std/str.pv"
bool str__is_whitespace(char ch) {
    #line 95 "src/std/str.pv"
    return (ch == ' ') || (ch == '\r') || (ch == '\n') || (ch == '\t');
}

#line 98 "src/std/str.pv"
struct str str__trim(struct str self) {
    #line 99 "src/std/str.pv"
    uintptr_t start = 0;
    #line 100 "src/std/str.pv"
    uintptr_t end = self.length;

    #line 102 "src/std/str.pv"
    while (start < end && str__is_whitespace(self.ptr[start])) {
        #line 103 "src/std/str.pv"
        start = start + 1;
    }

    #line 106 "src/std/str.pv"
    while (end > start && str__is_whitespace(self.ptr[end - 1])) {
        #line 107 "src/std/str.pv"
        end = end - 1;
    }

    #line 110 "src/std/str.pv"
    return str__slice(self, start, end);
}

#line 115 "src/std/str.pv"
Hashed str__Hash__hash(void* __self) {
    struct str* self = __self; (void)self;
    #line 115 "src/std/str.pv"
    return Fnv1a__hash(self->ptr, self->length);
}

struct trait_HashVTable STR__VTABLE__HASH = { .hash = &str__Hash__hash };
