#include <stdint.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_usize.h>
#include <std/IterEnumerate_usize.h>
#include <std/Iter_usize.h>

#include <std/Iter_usize.h>

#line 12 "src/std/Array.pv"
struct Iter_usize Iter_usize__new(uintptr_t start, uintptr_t end) {
    #line 13 "src/std/Array.pv"
    return (struct Iter_usize) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct Iter_usize Iter_usize__reverse(struct Iter_usize self) {
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
struct Iter_usize Iter_usize__skip(struct Iter_usize self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool Iter_usize__next(struct Iter_usize* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
uintptr_t Iter_usize__value(struct Iter_usize* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_usize Iter_usize__enumerate(struct Iter_usize self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_usize) { .index = 0, .iter = self };
}
