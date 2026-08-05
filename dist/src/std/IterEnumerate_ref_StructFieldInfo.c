#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <tuple_usize_ref_StructFieldInfo.h>
#include <std/StructFieldInfo.h>
#include <std/IterEnumerate_ref_StructFieldInfo.h>

#include <std/IterEnumerate_ref_StructFieldInfo.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_StructFieldInfo__next(struct IterEnumerate_ref_StructFieldInfo* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_StructFieldInfo__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_StructFieldInfo IterEnumerate_ref_StructFieldInfo__value(struct IterEnumerate_ref_StructFieldInfo* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_StructFieldInfo) { ._0 = self->index - 1, ._1 = Iter_ref_StructFieldInfo__value(&self->iter) };
}
