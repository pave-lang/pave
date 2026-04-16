#ifndef PAVE_ITER_REF_USAGE_CONTEXT
#define PAVE_ITER_REF_USAGE_CONTEXT

#include <stdint.h>
#include <stdbool.h>

struct UsageContext;

#line 4 "src/std/Array.pv"
struct Iter_ref_UsageContext {
    intptr_t step;
    struct UsageContext* iter;
    struct UsageContext* start;
    struct UsageContext* end;
};

#include <std/Iter_ref_UsageContext.h>
#include <std/IterEnumerate_ref_UsageContext.h>
struct UsageContext;
struct Iter_ref_UsageContext;

#line 12 "src/std/Array.pv"
struct Iter_ref_UsageContext Iter_ref_UsageContext__new(struct UsageContext* start, struct UsageContext* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_UsageContext Iter_ref_UsageContext__reverse(struct Iter_ref_UsageContext self);

#line 33 "src/std/Array.pv"
struct Iter_ref_UsageContext Iter_ref_UsageContext__skip(struct Iter_ref_UsageContext self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_UsageContext__next(struct Iter_ref_UsageContext* self);

#line 43 "src/std/Array.pv"
struct UsageContext* Iter_ref_UsageContext__value(struct Iter_ref_UsageContext* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_UsageContext Iter_ref_UsageContext__enumerate(struct Iter_ref_UsageContext self);

#endif
