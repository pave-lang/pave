#include <stdlib.h>
#include <string.h>

#include <analyzer/types/Type.h>
#include <stdint.h>
#include <stdbool.h>
#include <std/IterEnumerate_ref_Type.h>

#include <std/ArrayIter_ref_Type.h>

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_Type ArrayIter_ref_Type__new(struct Type* start, struct Type* end) {
    #line 13 "src/std/Array.pv"
    return (struct ArrayIter_ref_Type) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_Type ArrayIter_ref_Type__reverse(struct ArrayIter_ref_Type self) {
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
struct ArrayIter_ref_Type ArrayIter_ref_Type__skip(struct ArrayIter_ref_Type self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_Type__next(struct ArrayIter_ref_Type* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
struct Type* ArrayIter_ref_Type__value(struct ArrayIter_ref_Type* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Type ArrayIter_ref_Type__enumerate(struct ArrayIter_ref_Type self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_ref_Type) { .iter = self };
}
