#ifndef PAVE_ITER_REF_REF_GENERIC_MAP
#define PAVE_ITER_REF_REF_GENERIC_MAP

#include <stdint.h>
#include <stdbool.h>

struct GenericMap;
struct IterEnumerate_ref_ref_GenericMap;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_GenericMap {
    intptr_t step;
    struct GenericMap** iter;
    struct GenericMap** start;
    struct GenericMap** end;
};

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_GenericMap Iter_ref_ref_GenericMap__new(struct GenericMap** start, struct GenericMap** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_GenericMap Iter_ref_ref_GenericMap__reverse(struct Iter_ref_ref_GenericMap self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_GenericMap Iter_ref_ref_GenericMap__skip(struct Iter_ref_ref_GenericMap self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_GenericMap__next(struct Iter_ref_ref_GenericMap* self);

#line 43 "src/std/Array.pv"
struct GenericMap** Iter_ref_ref_GenericMap__value(struct Iter_ref_ref_GenericMap* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_GenericMap Iter_ref_ref_GenericMap__enumerate(struct Iter_ref_ref_GenericMap self);

#endif
