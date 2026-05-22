#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <std/IterEnumerate_ref_ref_Struct.h>
#include <tuple_usize_ref_ref_Struct.h>
#include <std/IterEnumerate_ref_ref_Struct.h>

#include <std/IterEnumerate_ref_ref_Struct.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Struct__next(struct IterEnumerate_ref_ref_Struct* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_ref_Struct__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Struct IterEnumerate_ref_ref_Struct__value(struct IterEnumerate_ref_ref_Struct* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ref_Struct) { ._0 = self->index - 1, ._1 = Iter_ref_ref_Struct__value(&self->iter) };
}
