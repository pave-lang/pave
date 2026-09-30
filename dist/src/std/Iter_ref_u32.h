#ifndef PAVE_ITER_REF_U32
#define PAVE_ITER_REF_U32

#include <stdint.h>
#include <stdbool.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_u32 {
    intptr_t step;
    uint32_t* iter;
    uint32_t* start;
    uint32_t* end;
};

#include <std/IterEnumerate_ref_u32.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_u32 Iter_ref_u32__new(uint32_t* start, uint32_t* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_u32 Iter_ref_u32__reverse(struct Iter_ref_u32 self);

#line 33 "src/std/Array.pv"
struct Iter_ref_u32 Iter_ref_u32__skip(struct Iter_ref_u32 self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_u32__next(struct Iter_ref_u32* self);

#line 43 "src/std/Array.pv"
uint32_t* Iter_ref_u32__value(struct Iter_ref_u32* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_u32 Iter_ref_u32__enumerate(struct Iter_ref_u32 self);

#endif
