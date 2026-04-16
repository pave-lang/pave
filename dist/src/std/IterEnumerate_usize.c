#include <stdint.h>

#include <std/IterEnumerate_usize.h>
#include <tuple_usize_usize.h>
#include <std/IterEnumerate_usize.h>

#include <std/IterEnumerate_usize.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_usize__next(struct IterEnumerate_usize* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_usize__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_usize IterEnumerate_usize__value(struct IterEnumerate_usize* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_usize) { ._0 = self->index - 1, ._1 = Iter_usize__value(&self->iter) };
}
