#ifndef PAVE_ITER_ENUMERATE_REF_REF_GENERIC_MAP
#define PAVE_ITER_ENUMERATE_REF_REF_GENERIC_MAP

#include <stdint.h>
#include <std/Iter_ref_ref_GenericMap.h>
#include <stdbool.h>

struct GenericMap;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_ref_GenericMap {
    uintptr_t index;
    struct Iter_ref_ref_GenericMap iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_GenericMap__next(struct IterEnumerate_ref_ref_GenericMap* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_GenericMap IterEnumerate_ref_ref_GenericMap__value(struct IterEnumerate_ref_ref_GenericMap* self);

#endif
