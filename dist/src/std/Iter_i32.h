#ifndef PAVE_ITER_I32
#define PAVE_ITER_I32

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_i32 {
    intptr_t step;
    int32_t iter;
    int32_t start;
    int32_t end;
};

#include <std/Iter_i32.h>
#include <std/IterEnumerate_i32.h>
struct Iter_i32;

#line 12 "src/std/Array.pv"
struct Iter_i32 Iter_i32__new(int32_t start, int32_t end);

#line 21 "src/std/Array.pv"
struct Iter_i32 Iter_i32__reverse(struct Iter_i32 self);

#line 33 "src/std/Array.pv"
struct Iter_i32 Iter_i32__skip(struct Iter_i32 self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_i32__next(struct Iter_i32* self);

#line 43 "src/std/Array.pv"
int32_t Iter_i32__value(struct Iter_i32* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_i32 Iter_i32__enumerate(struct Iter_i32 self);

#endif
