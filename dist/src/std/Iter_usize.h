#ifndef PAVE_ITER_USIZE
#define PAVE_ITER_USIZE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_usize {
    intptr_t step;
    uintptr_t iter;
    uintptr_t start;
    uintptr_t end;
};

struct Iter_usize;
#include <std/Iter_usize.h>
#include <std/IterEnumerate_usize.h>

#line 12 "src/std/Array.pv"
struct Iter_usize Iter_usize__new(uintptr_t start, uintptr_t end);

#line 21 "src/std/Array.pv"
struct Iter_usize Iter_usize__reverse(struct Iter_usize self);

#line 33 "src/std/Array.pv"
struct Iter_usize Iter_usize__skip(struct Iter_usize self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_usize__next(struct Iter_usize* self);

#line 43 "src/std/Array.pv"
uintptr_t Iter_usize__value(struct Iter_usize* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_usize Iter_usize__enumerate(struct Iter_usize self);

#endif
