#ifndef PAVE_ITER_REF_REF_ENUM
#define PAVE_ITER_REF_REF_ENUM

#include <stdint.h>
#include <stdbool.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Enum {
    intptr_t step;
    struct Enum** iter;
    struct Enum** start;
    struct Enum** end;
};

#include <std/IterEnumerate_ref_ref_Enum.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Enum Iter_ref_ref_Enum__new(struct Enum** start, struct Enum** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Enum Iter_ref_ref_Enum__reverse(struct Iter_ref_ref_Enum self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Enum Iter_ref_ref_Enum__skip(struct Iter_ref_ref_Enum self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Enum__next(struct Iter_ref_ref_Enum* self);

#line 43 "src/std/Array.pv"
struct Enum** Iter_ref_ref_Enum__value(struct Iter_ref_ref_Enum* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Enum Iter_ref_ref_Enum__enumerate(struct Iter_ref_ref_Enum self);

#endif
