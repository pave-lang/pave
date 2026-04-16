#ifndef PAVE_ITER_REF_INVOKE_ARGUMENT
#define PAVE_ITER_REF_INVOKE_ARGUMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct InvokeArgument;

#line 4 "src/std/Array.pv"
struct Iter_ref_InvokeArgument {
    intptr_t step;
    struct InvokeArgument* iter;
    struct InvokeArgument* start;
    struct InvokeArgument* end;
};

#include <std/Iter_ref_InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
struct InvokeArgument;
struct Iter_ref_InvokeArgument;

#line 12 "src/std/Array.pv"
struct Iter_ref_InvokeArgument Iter_ref_InvokeArgument__new(struct InvokeArgument* start, struct InvokeArgument* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_InvokeArgument Iter_ref_InvokeArgument__reverse(struct Iter_ref_InvokeArgument self);

#line 33 "src/std/Array.pv"
struct Iter_ref_InvokeArgument Iter_ref_InvokeArgument__skip(struct Iter_ref_InvokeArgument self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_InvokeArgument__next(struct Iter_ref_InvokeArgument* self);

#line 43 "src/std/Array.pv"
struct InvokeArgument* Iter_ref_InvokeArgument__value(struct Iter_ref_InvokeArgument* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_InvokeArgument Iter_ref_InvokeArgument__enumerate(struct Iter_ref_InvokeArgument self);

#endif
