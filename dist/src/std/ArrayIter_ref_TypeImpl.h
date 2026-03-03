#ifndef PAVE_ARRAY_ITER_REF_TYPE_IMPL
#define PAVE_ARRAY_ITER_REF_TYPE_IMPL

#include <stdint.h>
#include <stdbool.h>

struct TypeImpl;
struct IterEnumerate_ref_TypeImpl;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl {
    intptr_t step;
    struct TypeImpl* iter;
    struct TypeImpl* start;
    struct TypeImpl* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl ArrayIter_ref_TypeImpl__new(struct TypeImpl* start, struct TypeImpl* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl ArrayIter_ref_TypeImpl__reverse(struct ArrayIter_ref_TypeImpl self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl ArrayIter_ref_TypeImpl__skip(struct ArrayIter_ref_TypeImpl self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_TypeImpl__next(struct ArrayIter_ref_TypeImpl* self);

#line 43 "src/std/Array.pv"
struct TypeImpl* ArrayIter_ref_TypeImpl__value(struct ArrayIter_ref_TypeImpl* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_TypeImpl ArrayIter_ref_TypeImpl__enumerate(struct ArrayIter_ref_TypeImpl self);

#endif
