#ifndef PAVE_ARRAY_ITER_REF_NAMESPACE_PATH
#define PAVE_ARRAY_ITER_REF_NAMESPACE_PATH

#include <stdint.h>
#include <stdbool.h>

struct NamespacePath;
struct IterEnumerate_ref_NamespacePath;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_NamespacePath {
    intptr_t step;
    struct NamespacePath* iter;
    struct NamespacePath* start;
    struct NamespacePath* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_NamespacePath ArrayIter_ref_NamespacePath__new(struct NamespacePath* start, struct NamespacePath* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_NamespacePath ArrayIter_ref_NamespacePath__reverse(struct ArrayIter_ref_NamespacePath self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_NamespacePath ArrayIter_ref_NamespacePath__skip(struct ArrayIter_ref_NamespacePath self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_NamespacePath__next(struct ArrayIter_ref_NamespacePath* self);

#line 43 "src/std/Array.pv"
struct NamespacePath* ArrayIter_ref_NamespacePath__value(struct ArrayIter_ref_NamespacePath* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_NamespacePath ArrayIter_ref_NamespacePath__enumerate(struct ArrayIter_ref_NamespacePath self);

#endif
