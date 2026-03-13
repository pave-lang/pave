#include <stdlib.h>
#include <string.h>

#include <stdint.h>
#include <stdbool.h>
#include <std/IterEnumerate_ptrc_char.h>

#include <std/ArrayIter_ptrc_char.h>

#line 12 "src/std/Array.pv"
struct ArrayIter_ptrc_char ArrayIter_ptrc_char__new(char const* start, char const* end) {
    #line 13 "src/std/Array.pv"
    return (struct ArrayIter_ptrc_char) {
        .step = 1,
        .iter = start - 1,
        .start = start,
        .end = end,
    };
}

#line 21 "src/std/Array.pv"
struct ArrayIter_ptrc_char ArrayIter_ptrc_char__reverse(struct ArrayIter_ptrc_char self) {
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
struct ArrayIter_ptrc_char ArrayIter_ptrc_char__skip(struct ArrayIter_ptrc_char self, intptr_t steps) {
    #line 34 "src/std/Array.pv"
    self.iter = self.iter + steps * self.step;
    #line 35 "src/std/Array.pv"
    return self;
}

#line 38 "src/std/Array.pv"
bool ArrayIter_ptrc_char__next(struct ArrayIter_ptrc_char* self) {
    #line 39 "src/std/Array.pv"
    self->iter = self->iter + self->step;
    #line 40 "src/std/Array.pv"
    return (self->start <= self->iter) && (self->iter < self->end);
}

#line 43 "src/std/Array.pv"
char const* ArrayIter_ptrc_char__value(struct ArrayIter_ptrc_char* self) {
    #line 44 "src/std/Array.pv"
    return self->iter;
}

#line 47 "src/std/Array.pv"
struct IterEnumerate_ptrc_char ArrayIter_ptrc_char__enumerate(struct ArrayIter_ptrc_char self) {
    #line 48 "src/std/Array.pv"
    return (struct IterEnumerate_ptrc_char) { .iter = self };
}
