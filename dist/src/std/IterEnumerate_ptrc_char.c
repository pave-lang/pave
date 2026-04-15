#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ptrc_char.h>
#include <std/IterEnumerate_ptrc_char.h>
#include <tuple_usize_ptrc_char.h>

#include <std/IterEnumerate_ptrc_char.h>

#include <std/IterEnumerate_ptrc_char.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ptrc_char__next(struct IterEnumerate_ptrc_char* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ptrc_char__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ptrc_char IterEnumerate_ptrc_char__value(struct IterEnumerate_ptrc_char* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ptrc_char) { ._0 = self->index - 1, ._1 = Iter_ptrc_char__value(&self->iter) };
}
