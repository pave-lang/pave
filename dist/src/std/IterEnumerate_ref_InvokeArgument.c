#include <stdint.h>

#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>

#include <std/IterEnumerate_ref_InvokeArgument.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_InvokeArgument__next(struct IterEnumerate_ref_InvokeArgument* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_InvokeArgument__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_InvokeArgument IterEnumerate_ref_InvokeArgument__value(struct IterEnumerate_ref_InvokeArgument* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_InvokeArgument) { ._0 = self->index - 1, ._1 = Iter_ref_InvokeArgument__value(&self->iter) };
}
