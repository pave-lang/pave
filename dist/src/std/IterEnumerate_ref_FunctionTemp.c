#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <tuple_usize_ref_FunctionTemp.h>
#include <compiler/FunctionTemp.h>
#include <std/IterEnumerate_ref_FunctionTemp.h>

#include <std/IterEnumerate_ref_FunctionTemp.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_FunctionTemp__next(struct IterEnumerate_ref_FunctionTemp* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_FunctionTemp__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_FunctionTemp IterEnumerate_ref_FunctionTemp__value(struct IterEnumerate_ref_FunctionTemp* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_FunctionTemp) { ._0 = self->index - 1, ._1 = Iter_ref_FunctionTemp__value(&self->iter) };
}
