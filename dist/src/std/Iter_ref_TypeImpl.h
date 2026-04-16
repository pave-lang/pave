#ifndef PAVE_ITER_REF_TYPE_IMPL
#define PAVE_ITER_REF_TYPE_IMPL

#include <stdint.h>
#include <stdbool.h>

struct TypeImpl;

#line 4 "src/std/Array.pv"
struct Iter_ref_TypeImpl {
    intptr_t step;
    struct TypeImpl* iter;
    struct TypeImpl* start;
    struct TypeImpl* end;
};

#include <std/Iter_ref_TypeImpl.h>
#include <std/IterEnumerate_ref_TypeImpl.h>
struct TypeImpl;
struct Iter_ref_TypeImpl;

#line 12 "src/std/Array.pv"
struct Iter_ref_TypeImpl Iter_ref_TypeImpl__new(struct TypeImpl* start, struct TypeImpl* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_TypeImpl Iter_ref_TypeImpl__reverse(struct Iter_ref_TypeImpl self);

#line 33 "src/std/Array.pv"
struct Iter_ref_TypeImpl Iter_ref_TypeImpl__skip(struct Iter_ref_TypeImpl self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_TypeImpl__next(struct Iter_ref_TypeImpl* self);

#line 43 "src/std/Array.pv"
struct TypeImpl* Iter_ref_TypeImpl__value(struct Iter_ref_TypeImpl* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_TypeImpl Iter_ref_TypeImpl__enumerate(struct Iter_ref_TypeImpl self);

#endif
