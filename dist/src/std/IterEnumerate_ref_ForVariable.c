#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/ArrayIter_ref_ForVariable.h>
#include <analyzer/ForVariable.h>
#include <stdint.h>
#include <tuple_usize_ref_ForVariable.h>

#include <std/IterEnumerate_ref_ForVariable.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ForVariable__next(struct IterEnumerate_ref_ForVariable* self) {
    #line 59 "src/std/Array.pv"
    if (!ArrayIter_ref_ForVariable__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ForVariable IterEnumerate_ref_ForVariable__value(struct IterEnumerate_ref_ForVariable* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ForVariable) { ._0 = self->index - 1, ._1 = ArrayIter_ref_ForVariable__value(&self->iter) };
}
