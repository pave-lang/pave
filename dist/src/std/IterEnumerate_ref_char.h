#ifndef PAVE_ITER_ENUMERATE_REF_CHAR
#define PAVE_ITER_ENUMERATE_REF_CHAR

#include <stdint.h>
#include <std/ArrayIter_ref_char.h>
#include <stdbool.h>


#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_char {
    uintptr_t index;
    struct ArrayIter_ref_char iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_char__next(struct IterEnumerate_ref_char* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_char IterEnumerate_ref_char__value(struct IterEnumerate_ref_char* self);

#endif
