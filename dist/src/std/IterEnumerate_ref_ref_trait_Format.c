#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <tuple_usize_ref_ref_trait_Format.h>
#include <std/trait_Format.h>
#include <std/IterEnumerate_ref_ref_trait_Format.h>

#include <std/IterEnumerate_ref_ref_trait_Format.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_trait_Format__next(struct IterEnumerate_ref_ref_trait_Format* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_ref_trait_Format__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_trait_Format IterEnumerate_ref_ref_trait_Format__value(struct IterEnumerate_ref_ref_trait_Format* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ref_trait_Format) { ._0 = self->index - 1, ._1 = Iter_ref_ref_trait_Format__value(&self->iter) };
}
