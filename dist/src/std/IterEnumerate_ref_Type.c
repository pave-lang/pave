#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/ArrayIter_ref_Type.h>
#include <analyzer/types/Type.h>
#include <stdint.h>
#include <tuple_usize_ref_Type.h>

#include <std/IterEnumerate_ref_Type.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Type__next(struct IterEnumerate_ref_Type* self) {
    #line 59 "src/std/Array.pv"
    if (!ArrayIter_ref_Type__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Type IterEnumerate_ref_Type__value(struct IterEnumerate_ref_Type* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_Type) { ._0 = self->index - 1, ._1 = ArrayIter_ref_Type__value(&self->iter) };
}
