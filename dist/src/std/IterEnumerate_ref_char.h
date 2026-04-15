#ifndef PAVE_ITER_ENUMERATE_REF_CHAR
#define PAVE_ITER_ENUMERATE_REF_CHAR

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_char.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_char {
    uintptr_t index;
    struct Iter_ref_char iter;
};

struct IterEnumerate_ref_char;
#include <tuple_usize_ref_char.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_char__next(struct IterEnumerate_ref_char* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_char IterEnumerate_ref_char__value(struct IterEnumerate_ref_char* self);

#endif
