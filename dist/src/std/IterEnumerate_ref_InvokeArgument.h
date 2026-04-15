#ifndef PAVE_ITER_ENUMERATE_REF_INVOKE_ARGUMENT
#define PAVE_ITER_ENUMERATE_REF_INVOKE_ARGUMENT

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_InvokeArgument.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_InvokeArgument {
    uintptr_t index;
    struct Iter_ref_InvokeArgument iter;
};

struct IterEnumerate_ref_InvokeArgument;
#include <tuple_usize_ref_InvokeArgument.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_InvokeArgument__next(struct IterEnumerate_ref_InvokeArgument* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_InvokeArgument IterEnumerate_ref_InvokeArgument__value(struct IterEnumerate_ref_InvokeArgument* self);

#endif
