#ifndef PAVE_ITER_REF_TUPLE_USIZE_STR_TYPE_ID
#define PAVE_ITER_REF_TUPLE_USIZE_STR_TYPE_ID

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>


#line 4 "src/std/Array.pv"
struct Iter_ref_tuple_usize_str_TypeId {
    intptr_t step;
    struct tuple_usize_str_TypeId* iter;
    struct tuple_usize_str_TypeId* start;
    struct tuple_usize_str_TypeId* end;
};
struct Iter_ref_tuple_usize_str_TypeId;
#include <std/Iter_ref_tuple_usize_str_TypeId.h>
#include <std/IterEnumerate_ref_tuple_usize_str_TypeId.h>


#line 12 "src/std/Array.pv"
struct Iter_ref_tuple_usize_str_TypeId Iter_ref_tuple_usize_str_TypeId__new(struct tuple_usize_str_TypeId* start, struct tuple_usize_str_TypeId* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_tuple_usize_str_TypeId Iter_ref_tuple_usize_str_TypeId__reverse(struct Iter_ref_tuple_usize_str_TypeId self);

#line 33 "src/std/Array.pv"
struct Iter_ref_tuple_usize_str_TypeId Iter_ref_tuple_usize_str_TypeId__skip(struct Iter_ref_tuple_usize_str_TypeId self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_tuple_usize_str_TypeId__next(struct Iter_ref_tuple_usize_str_TypeId* self);

#line 43 "src/std/Array.pv"
struct tuple_usize_str_TypeId* Iter_ref_tuple_usize_str_TypeId__value(struct Iter_ref_tuple_usize_str_TypeId* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_tuple_usize_str_TypeId Iter_ref_tuple_usize_str_TypeId__enumerate(struct Iter_ref_tuple_usize_str_TypeId self);

#endif
