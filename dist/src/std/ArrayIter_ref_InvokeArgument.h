#ifndef PAVE_ARRAY_ITER_REF_INVOKE_ARGUMENT
#define PAVE_ARRAY_ITER_REF_INVOKE_ARGUMENT

#include <stdint.h>
#include <stdbool.h>

struct InvokeArgument;
struct IterEnumerate_ref_InvokeArgument;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_InvokeArgument {
    intptr_t step;
    struct InvokeArgument* iter;
    struct InvokeArgument* start;
    struct InvokeArgument* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_InvokeArgument ArrayIter_ref_InvokeArgument__new(struct InvokeArgument* start, struct InvokeArgument* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_InvokeArgument ArrayIter_ref_InvokeArgument__reverse(struct ArrayIter_ref_InvokeArgument self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_InvokeArgument ArrayIter_ref_InvokeArgument__skip(struct ArrayIter_ref_InvokeArgument self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_InvokeArgument__next(struct ArrayIter_ref_InvokeArgument* self);

#line 43 "src/std/Array.pv"
struct InvokeArgument* ArrayIter_ref_InvokeArgument__value(struct ArrayIter_ref_InvokeArgument* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_InvokeArgument ArrayIter_ref_InvokeArgument__enumerate(struct ArrayIter_ref_InvokeArgument self);

#endif
