#ifndef PAVE_ITER_REF_NAMESPACE_PATH
#define PAVE_ITER_REF_NAMESPACE_PATH

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct NamespacePath;

#line 4 "src/std/Array.pv"
struct Iter_ref_NamespacePath {
    intptr_t step;
    struct NamespacePath* iter;
    struct NamespacePath* start;
    struct NamespacePath* end;
};

struct NamespacePath;
struct Iter_ref_NamespacePath;
#include <std/Iter_ref_NamespacePath.h>
#include <std/IterEnumerate_ref_NamespacePath.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_NamespacePath Iter_ref_NamespacePath__new(struct NamespacePath* start, struct NamespacePath* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_NamespacePath Iter_ref_NamespacePath__reverse(struct Iter_ref_NamespacePath self);

#line 33 "src/std/Array.pv"
struct Iter_ref_NamespacePath Iter_ref_NamespacePath__skip(struct Iter_ref_NamespacePath self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_NamespacePath__next(struct Iter_ref_NamespacePath* self);

#line 43 "src/std/Array.pv"
struct NamespacePath* Iter_ref_NamespacePath__value(struct Iter_ref_NamespacePath* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_NamespacePath Iter_ref_NamespacePath__enumerate(struct Iter_ref_NamespacePath self);

#endif
