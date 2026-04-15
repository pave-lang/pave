#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_TypeId.h>
#include <std/IterEnumerate_ref_TypeId.h>
#include <tuple_usize_ref_TypeId.h>
#include <std/TypeId.h>
#include <std/IterEnumerate_ref_TypeId.h>

#include <std/IterEnumerate_ref_TypeId.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_TypeId__next(struct IterEnumerate_ref_TypeId* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_TypeId__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_TypeId IterEnumerate_ref_TypeId__value(struct IterEnumerate_ref_TypeId* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_TypeId) { ._0 = self->index - 1, ._1 = Iter_ref_TypeId__value(&self->iter) };
}
