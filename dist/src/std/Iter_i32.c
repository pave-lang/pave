#include <std/Iter_i32.h>
#include <std/IterEnumerate_i32.h>
#include <std/Iter_i32.h>

#include <std/Iter_i32.h>

#line 12 "src/std/Array.pv"
struct Iter_i32 Iter_i32__new(int32_t start, int32_t end) {
    #line 13 "src/std/Array.pv"
    return (struct Iter_i32) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct Iter_i32 Iter_i32__reverse(struct Iter_i32 self) {
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
struct Iter_i32 Iter_i32__skip(struct Iter_i32 self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool Iter_i32__next(struct Iter_i32* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
int32_t Iter_i32__value(struct Iter_i32* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_i32 Iter_i32__enumerate(struct Iter_i32 self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_i32) { .iter = self };
}
