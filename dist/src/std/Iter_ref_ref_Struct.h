#ifndef PAVE_ITER_REF_REF_STRUCT
#define PAVE_ITER_REF_REF_STRUCT

#include <stdint.h>
#include <stdbool.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Struct {
    intptr_t step;
    struct Struct** iter;
    struct Struct** start;
    struct Struct** end;
};

#include <std/IterEnumerate_ref_ref_Struct.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Struct Iter_ref_ref_Struct__new(struct Struct** start, struct Struct** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Struct Iter_ref_ref_Struct__reverse(struct Iter_ref_ref_Struct self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Struct Iter_ref_ref_Struct__skip(struct Iter_ref_ref_Struct self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Struct__next(struct Iter_ref_ref_Struct* self);

#line 43 "src/std/Array.pv"
struct Struct** Iter_ref_ref_Struct__value(struct Iter_ref_ref_Struct* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Struct Iter_ref_ref_Struct__enumerate(struct Iter_ref_ref_Struct self);

#endif
