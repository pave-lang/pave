#ifndef PAVE_ITER_ENUMERATE_REF_STRING
#define PAVE_ITER_ENUMERATE_REF_STRING

#include <stdint.h>
#include <std/ArrayIter_ref_String.h>
#include <stdbool.h>

struct String;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_String {
    uintptr_t index;
    struct ArrayIter_ref_String iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_String__next(struct IterEnumerate_ref_String* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_String IterEnumerate_ref_String__value(struct IterEnumerate_ref_String* self);

#endif
