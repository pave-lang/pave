#include <stdlib.h>
#include <string.h>

#include <analyzer/types/TypeImpl.h>
#include <stdint.h>
#include <stdbool.h>
#include <std/IterEnumerate_ref_TypeImpl.h>

#include <std/ArrayIter_ref_TypeImpl.h>

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl ArrayIter_ref_TypeImpl__new(struct TypeImpl* start, struct TypeImpl* end) {
    #line 13 "src/std/Array.pv"
    return (struct ArrayIter_ref_TypeImpl) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl ArrayIter_ref_TypeImpl__reverse(struct ArrayIter_ref_TypeImpl self) {
    #line 22 "src/std/Array.pv"
    self.step = -self.step;

    #line 24 "src/std/Array.pv"
    if (self.step < 0) {
        #line 25 "src/std/Array.pv"
        self.iter = self.end;
    } else {
        #line 27 "src/std/Array.pv"
        self.iter = self.start - self.step;
    }

    #line 30 "src/std/Array.pv"
    return self;
}

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_TypeImpl ArrayIter_ref_TypeImpl__skip(struct ArrayIter_ref_TypeImpl self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_TypeImpl__next(struct ArrayIter_ref_TypeImpl* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
struct TypeImpl* ArrayIter_ref_TypeImpl__value(struct ArrayIter_ref_TypeImpl* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_TypeImpl ArrayIter_ref_TypeImpl__enumerate(struct ArrayIter_ref_TypeImpl self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_ref_TypeImpl) { .iter = self };
}
