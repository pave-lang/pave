#ifndef PAVE_ITER_REF_REF_TRAIT
#define PAVE_ITER_REF_REF_TRAIT

#include <stdint.h>
#include <stdbool.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Trait {
    intptr_t step;
    struct Trait** iter;
    struct Trait** start;
    struct Trait** end;
};

#include <std/Iter_ref_ref_Trait.h>
#include <std/IterEnumerate_ref_ref_Trait.h>
struct Iter_ref_ref_Trait;

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Trait Iter_ref_ref_Trait__new(struct Trait** start, struct Trait** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Trait Iter_ref_ref_Trait__reverse(struct Iter_ref_ref_Trait self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Trait Iter_ref_ref_Trait__skip(struct Iter_ref_ref_Trait self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Trait__next(struct Iter_ref_ref_Trait* self);

#line 43 "src/std/Array.pv"
struct Trait** Iter_ref_ref_Trait__value(struct Iter_ref_ref_Trait* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Trait Iter_ref_ref_Trait__enumerate(struct Iter_ref_ref_Trait self);

#endif
