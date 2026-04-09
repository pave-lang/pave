#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/Iter_ref_ref_Expression.h>
#include <analyzer/expression/Expression.h>
#include <stdint.h>
#include <tuple_usize_ref_ref_Expression.h>

#include <std/IterEnumerate_ref_ref_Expression.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ref_Expression__next(struct IterEnumerate_ref_ref_Expression* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_ref_Expression__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ref_Expression IterEnumerate_ref_ref_Expression__value(struct IterEnumerate_ref_ref_Expression* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ref_Expression) { ._0 = self->index - 1, ._1 = Iter_ref_ref_Expression__value(&self->iter) };
}
