#ifndef PAVE_ITER_REF_TYPE
#define PAVE_ITER_REF_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Type;

#line 4 "src/std/Array.pv"
struct Iter_ref_Type {
    intptr_t step;
    struct Type* iter;
    struct Type* start;
    struct Type* end;
};

struct Type;
struct Iter_ref_Type;
#include <std/Iter_ref_Type.h>
#include <std/IterEnumerate_ref_Type.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_Type Iter_ref_Type__new(struct Type* start, struct Type* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Type Iter_ref_Type__reverse(struct Iter_ref_Type self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Type Iter_ref_Type__skip(struct Iter_ref_Type self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Type__next(struct Iter_ref_Type* self);

#line 43 "src/std/Array.pv"
struct Type* Iter_ref_Type__value(struct Iter_ref_Type* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Type Iter_ref_Type__enumerate(struct Iter_ref_Type self);

#endif
