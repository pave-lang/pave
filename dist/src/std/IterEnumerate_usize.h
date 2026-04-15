#ifndef PAVE_ITER_ENUMERATE_USIZE
#define PAVE_ITER_ENUMERATE_USIZE

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_usize.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_usize {
    uintptr_t index;
    struct Iter_usize iter;
};
struct IterEnumerate_usize;
#include <tuple_usize_usize.h>


#line 58 "src/std/Array.pv"
bool IterEnumerate_usize__next(struct IterEnumerate_usize* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_usize IterEnumerate_usize__value(struct IterEnumerate_usize* self);

#endif
