#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/ArrayIter_ref_TypeImpl.h>
#include <analyzer/types/TypeImpl.h>
#include <stdint.h>
#include <tuple_usize_ref_TypeImpl.h>

#include <std/IterEnumerate_ref_TypeImpl.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_TypeImpl__next(struct IterEnumerate_ref_TypeImpl* self) {
    #line 59 "src/std/Array.pv"
    if (!ArrayIter_ref_TypeImpl__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_TypeImpl IterEnumerate_ref_TypeImpl__value(struct IterEnumerate_ref_TypeImpl* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_TypeImpl) { ._0 = self->index - 1, ._1 = ArrayIter_ref_TypeImpl__value(&self->iter) };
}
