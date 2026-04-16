#include <stdint.h>

#include <std/IterEnumerate_ref_ElseStatement.h>
#include <tuple_usize_ref_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/IterEnumerate_ref_ElseStatement.h>

#include <std/IterEnumerate_ref_ElseStatement.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ElseStatement__next(struct IterEnumerate_ref_ElseStatement* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_ElseStatement__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ElseStatement IterEnumerate_ref_ElseStatement__value(struct IterEnumerate_ref_ElseStatement* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ElseStatement) { ._0 = self->index - 1, ._1 = Iter_ref_ElseStatement__value(&self->iter) };
}
