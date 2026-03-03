#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/ArrayIter_ref_ref_GenericMap.h>
#include <analyzer/GenericMap.h>
#include <stdint.h>
#include <tuple_usize_ref_ref_GenericMap.h>

#include <std/IterEnumerate_ref_ref_GenericMap.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_GenericMap__next(struct IterEnumerate_ref_ref_GenericMap* self) {
    #line 59 "src/std/Array.pv"
    if (!ArrayIter_ref_ref_GenericMap__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_GenericMap IterEnumerate_ref_ref_GenericMap__value(struct IterEnumerate_ref_ref_GenericMap* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ref_GenericMap) { ._0 = self->index - 1, ._1 = ArrayIter_ref_ref_GenericMap__value(&self->iter) };
}
