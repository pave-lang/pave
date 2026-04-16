#ifndef PAVE_ITER_REF_TYPE_ID
#define PAVE_ITER_REF_TYPE_ID

#include <stdint.h>
#include <stdbool.h>

typedef uint64_t TypeId;

#line 4 "src/std/Array.pv"
struct Iter_ref_TypeId {
    intptr_t step;
    TypeId* iter;
    TypeId* start;
    TypeId* end;
};

#include <std/Iter_ref_TypeId.h>
#include <std/IterEnumerate_ref_TypeId.h>
typedef uint64_t TypeId;
struct Iter_ref_TypeId;

#line 12 "src/std/Array.pv"
struct Iter_ref_TypeId Iter_ref_TypeId__new(TypeId* start, TypeId* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_TypeId Iter_ref_TypeId__reverse(struct Iter_ref_TypeId self);

#line 33 "src/std/Array.pv"
struct Iter_ref_TypeId Iter_ref_TypeId__skip(struct Iter_ref_TypeId self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_TypeId__next(struct Iter_ref_TypeId* self);

#line 43 "src/std/Array.pv"
TypeId* Iter_ref_TypeId__value(struct Iter_ref_TypeId* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_TypeId Iter_ref_TypeId__enumerate(struct Iter_ref_TypeId self);

#endif
