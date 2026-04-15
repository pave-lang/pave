#ifndef PAVE_ITER_ENUMERATE_I32
#define PAVE_ITER_ENUMERATE_I32

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_i32.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_i32 {
    uintptr_t index;
    struct Iter_i32 iter;
};

struct IterEnumerate_i32;
#include <tuple_usize_i32.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_i32__next(struct IterEnumerate_i32* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_i32 IterEnumerate_i32__value(struct IterEnumerate_i32* self);

#endif
