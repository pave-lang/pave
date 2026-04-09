#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/Iter_ref_Statement.h>
#include <analyzer/statement/Statement.h>
#include <stdint.h>
#include <tuple_usize_ref_Statement.h>

#include <std/IterEnumerate_ref_Statement.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Statement__next(struct IterEnumerate_ref_Statement* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_Statement__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Statement IterEnumerate_ref_Statement__value(struct IterEnumerate_ref_Statement* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_Statement) { ._0 = self->index - 1, ._1 = Iter_ref_Statement__value(&self->iter) };
}
