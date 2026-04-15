#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_Generic.h>
#include <std/IterEnumerate_ref_Generic.h>
#include <tuple_usize_ref_Generic.h>
#include <analyzer/types/Generic.h>
#include <std/IterEnumerate_ref_Generic.h>

#include <std/IterEnumerate_ref_Generic.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Generic__next(struct IterEnumerate_ref_Generic* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_Generic__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Generic IterEnumerate_ref_Generic__value(struct IterEnumerate_ref_Generic* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_Generic) { ._0 = self->index - 1, ._1 = Iter_ref_Generic__value(&self->iter) };
}
