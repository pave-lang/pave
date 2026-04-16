#include <stdint.h>

#include <std/IterEnumerate_i32.h>
#include <tuple_usize_i32.h>
#include <std/IterEnumerate_i32.h>

#include <std/IterEnumerate_i32.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_i32__next(struct IterEnumerate_i32* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_i32__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_i32 IterEnumerate_i32__value(struct IterEnumerate_i32* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_i32) { ._0 = self->index - 1, ._1 = Iter_i32__value(&self->iter) };
}
