#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/IterEnumerate_ref_DeferStatement.h>
#include <std/Iter_ref_DeferStatement.h>

#include <std/Iter_ref_DeferStatement.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_DeferStatement Iter_ref_DeferStatement__new(struct DeferStatement* start, struct DeferStatement* end) {
    #line 13 "src/std/Array.pv"
    return (struct Iter_ref_DeferStatement) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct Iter_ref_DeferStatement Iter_ref_DeferStatement__reverse(struct Iter_ref_DeferStatement self) {
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
struct Iter_ref_DeferStatement Iter_ref_DeferStatement__skip(struct Iter_ref_DeferStatement self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool Iter_ref_DeferStatement__next(struct Iter_ref_DeferStatement* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
struct DeferStatement* Iter_ref_DeferStatement__value(struct Iter_ref_DeferStatement* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_DeferStatement Iter_ref_DeferStatement__enumerate(struct Iter_ref_DeferStatement self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_ref_DeferStatement) { .index = 0, .iter = self };
}
