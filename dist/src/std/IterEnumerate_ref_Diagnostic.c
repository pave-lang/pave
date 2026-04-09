#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/Iter_ref_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <stdint.h>
#include <tuple_usize_ref_Diagnostic.h>

#include <std/IterEnumerate_ref_Diagnostic.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Diagnostic__next(struct IterEnumerate_ref_Diagnostic* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_Diagnostic__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Diagnostic IterEnumerate_ref_Diagnostic__value(struct IterEnumerate_ref_Diagnostic* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_Diagnostic) { ._0 = self->index - 1, ._1 = Iter_ref_Diagnostic__value(&self->iter) };
}
