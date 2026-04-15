#ifndef PAVE_ITER_ENUMERATE_REF_STRING
#define PAVE_ITER_ENUMERATE_REF_STRING

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_String.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_String {
    uintptr_t index;
    struct Iter_ref_String iter;
};
struct IterEnumerate_ref_String;
#include <tuple_usize_ref_String.h>


#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_String__next(struct IterEnumerate_ref_String* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_String IterEnumerate_ref_String__value(struct IterEnumerate_ref_String* self);

#endif
