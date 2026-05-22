#ifndef PAVE_ITER_ENUMERATE_REF_REF_ENUM
#define PAVE_ITER_ENUMERATE_REF_REF_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_ref_Enum.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Enum {
    uintptr_t index;
    struct Iter_ref_ref_Enum iter;
};

#include <tuple_usize_ref_ref_Enum.h>
struct IterEnumerate_ref_ref_Enum;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Enum__next(struct IterEnumerate_ref_ref_Enum* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Enum IterEnumerate_ref_ref_Enum__value(struct IterEnumerate_ref_ref_Enum* self);

#endif
