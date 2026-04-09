#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/Iter_ref_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <stdint.h>
#include <tuple_usize_ref_EnumVariantParameter.h>

#include <std/IterEnumerate_ref_EnumVariantParameter.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_EnumVariantParameter__next(struct IterEnumerate_ref_EnumVariantParameter* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_EnumVariantParameter__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_EnumVariantParameter IterEnumerate_ref_EnumVariantParameter__value(struct IterEnumerate_ref_EnumVariantParameter* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_EnumVariantParameter) { ._0 = self->index - 1, ._1 = Iter_ref_EnumVariantParameter__value(&self->iter) };
}
