#ifndef PAVE_ITER_REF_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_ITER_REF_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <stdbool.h>

struct HashMap_usize_TypeFunctionUsage;
struct TypeFunctionUsage;
struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_HashMap_usize_TypeFunctionUsage {
    intptr_t step;
    struct HashMap_usize_TypeFunctionUsage* iter;
    struct HashMap_usize_TypeFunctionUsage* start;
    struct HashMap_usize_TypeFunctionUsage* end;
};

#line 12 "src/std/Array.pv"
struct Iter_ref_HashMap_usize_TypeFunctionUsage Iter_ref_HashMap_usize_TypeFunctionUsage__new(struct HashMap_usize_TypeFunctionUsage* start, struct HashMap_usize_TypeFunctionUsage* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_HashMap_usize_TypeFunctionUsage Iter_ref_HashMap_usize_TypeFunctionUsage__reverse(struct Iter_ref_HashMap_usize_TypeFunctionUsage self);

#line 33 "src/std/Array.pv"
struct Iter_ref_HashMap_usize_TypeFunctionUsage Iter_ref_HashMap_usize_TypeFunctionUsage__skip(struct Iter_ref_HashMap_usize_TypeFunctionUsage self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_HashMap_usize_TypeFunctionUsage__next(struct Iter_ref_HashMap_usize_TypeFunctionUsage* self);

#line 43 "src/std/Array.pv"
struct HashMap_usize_TypeFunctionUsage* Iter_ref_HashMap_usize_TypeFunctionUsage__value(struct Iter_ref_HashMap_usize_TypeFunctionUsage* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_HashMap_usize_TypeFunctionUsage Iter_ref_HashMap_usize_TypeFunctionUsage__enumerate(struct Iter_ref_HashMap_usize_TypeFunctionUsage self);

#endif
