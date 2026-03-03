#ifndef PAVE_ITER_ENUMERATE_REF_INVOKE_ARGUMENT
#define PAVE_ITER_ENUMERATE_REF_INVOKE_ARGUMENT

#include <stdint.h>
#include <std/ArrayIter_ref_InvokeArgument.h>
#include <stdbool.h>

struct InvokeArgument;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_InvokeArgument {
    uintptr_t index;
    struct ArrayIter_ref_InvokeArgument iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_InvokeArgument__next(struct IterEnumerate_ref_InvokeArgument* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_InvokeArgument IterEnumerate_ref_InvokeArgument__value(struct IterEnumerate_ref_InvokeArgument* self);

#endif
