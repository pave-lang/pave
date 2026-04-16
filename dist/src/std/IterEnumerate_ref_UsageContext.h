#ifndef PAVE_ITER_ENUMERATE_REF_USAGE_CONTEXT
#define PAVE_ITER_ENUMERATE_REF_USAGE_CONTEXT

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_UsageContext.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_UsageContext {
    uintptr_t index;
    struct Iter_ref_UsageContext iter;
};

#include <tuple_usize_ref_UsageContext.h>
struct IterEnumerate_ref_UsageContext;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_UsageContext__next(struct IterEnumerate_ref_UsageContext* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_UsageContext IterEnumerate_ref_UsageContext__value(struct IterEnumerate_ref_UsageContext* self);

#endif
