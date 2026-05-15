#ifndef PAVE_ITER_ENUMERATE_REF_STR
#define PAVE_ITER_ENUMERATE_REF_STR

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_str.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_str {
    uintptr_t index;
    struct Iter_ref_str iter;
};

#include <tuple_usize_ref_str.h>
struct IterEnumerate_ref_str;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_str__next(struct IterEnumerate_ref_str* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_str IterEnumerate_ref_str__value(struct IterEnumerate_ref_str* self);

#endif
