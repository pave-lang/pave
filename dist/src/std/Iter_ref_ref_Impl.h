#ifndef PAVE_ITER_REF_REF_IMPL
#define PAVE_ITER_REF_REF_IMPL

#include <stdint.h>
#include <stdbool.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Impl {
    intptr_t step;
    struct Impl** iter;
    struct Impl** start;
    struct Impl** end;
};

#include <std/Iter_ref_ref_Impl.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
struct Iter_ref_ref_Impl;

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Impl Iter_ref_ref_Impl__new(struct Impl** start, struct Impl** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Impl Iter_ref_ref_Impl__reverse(struct Iter_ref_ref_Impl self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Impl Iter_ref_ref_Impl__skip(struct Iter_ref_ref_Impl self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Impl__next(struct Iter_ref_ref_Impl* self);

#line 43 "src/std/Array.pv"
struct Impl** Iter_ref_ref_Impl__value(struct Iter_ref_ref_Impl* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Impl Iter_ref_ref_Impl__enumerate(struct Iter_ref_ref_Impl self);

#endif
