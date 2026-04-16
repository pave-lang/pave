#ifndef PAVE_ITER_REF_REF_NAMESPACE
#define PAVE_ITER_REF_REF_NAMESPACE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Namespace {
    intptr_t step;
    struct Namespace** iter;
    struct Namespace** start;
    struct Namespace** end;
};

struct Iter_ref_ref_Namespace;
#include <std/Iter_ref_ref_Namespace.h>
#include <std/IterEnumerate_ref_ref_Namespace.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Namespace Iter_ref_ref_Namespace__new(struct Namespace** start, struct Namespace** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Namespace Iter_ref_ref_Namespace__reverse(struct Iter_ref_ref_Namespace self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Namespace Iter_ref_ref_Namespace__skip(struct Iter_ref_ref_Namespace self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Namespace__next(struct Iter_ref_ref_Namespace* self);

#line 43 "src/std/Array.pv"
struct Namespace** Iter_ref_ref_Namespace__value(struct Iter_ref_ref_Namespace* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Namespace Iter_ref_ref_Namespace__enumerate(struct Iter_ref_ref_Namespace self);

#endif
