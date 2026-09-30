#ifndef PAVE_ITER_REF_ARRAY_U32
#define PAVE_ITER_REF_ARRAY_U32

#include <stdint.h>
#include <stdbool.h>

struct Array_u32;

#line 4 "src/std/Array.pv"
struct Iter_ref_Array_u32 {
    intptr_t step;
    struct Array_u32* iter;
    struct Array_u32* start;
    struct Array_u32* end;
};

#include <std/IterEnumerate_ref_Array_u32.h>
struct Array_u32;

#line 12 "src/std/Array.pv"
struct Iter_ref_Array_u32 Iter_ref_Array_u32__new(struct Array_u32* start, struct Array_u32* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Array_u32 Iter_ref_Array_u32__reverse(struct Iter_ref_Array_u32 self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Array_u32 Iter_ref_Array_u32__skip(struct Iter_ref_Array_u32 self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Array_u32__next(struct Iter_ref_Array_u32* self);

#line 43 "src/std/Array.pv"
struct Array_u32* Iter_ref_Array_u32__value(struct Iter_ref_Array_u32* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Array_u32 Iter_ref_Array_u32__enumerate(struct Iter_ref_Array_u32 self);

#endif
