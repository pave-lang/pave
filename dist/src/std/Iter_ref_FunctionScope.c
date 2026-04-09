#include <stdlib.h>
#include <string.h>

#include <compiler/FunctionScope.h>
#include <stdint.h>
#include <stdbool.h>
#include <std/IterEnumerate_ref_FunctionScope.h>

#include <std/Iter_ref_FunctionScope.h>

#line 12 "src/std/Array.pv"
struct Iter_ref_FunctionScope Iter_ref_FunctionScope__new(struct FunctionScope* start, struct FunctionScope* end) {
    #line 13 "src/std/Array.pv"
    return (struct Iter_ref_FunctionScope) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct Iter_ref_FunctionScope Iter_ref_FunctionScope__reverse(struct Iter_ref_FunctionScope self) {
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
struct Iter_ref_FunctionScope Iter_ref_FunctionScope__skip(struct Iter_ref_FunctionScope self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool Iter_ref_FunctionScope__next(struct Iter_ref_FunctionScope* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
struct FunctionScope* Iter_ref_FunctionScope__value(struct Iter_ref_FunctionScope* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_FunctionScope Iter_ref_FunctionScope__enumerate(struct Iter_ref_FunctionScope self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_ref_FunctionScope) { .iter = self };
}
