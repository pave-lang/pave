#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <std/ArrayIter_ref_MatchCase.h>
#include <analyzer/MatchCase.h>
#include <stdint.h>
#include <tuple_usize_ref_MatchCase.h>

#include <std/IterEnumerate_ref_MatchCase.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_MatchCase__next(struct IterEnumerate_ref_MatchCase* self) {
    #line 59 "src/std/Array.pv"
    if (!ArrayIter_ref_MatchCase__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_MatchCase IterEnumerate_ref_MatchCase__value(struct IterEnumerate_ref_MatchCase* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_MatchCase) { ._0 = self->index - 1, ._1 = ArrayIter_ref_MatchCase__value(&self->iter) };
}
