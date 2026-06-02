#ifndef PAVE_ITER_ENUMERATE_REF_POSITION
#define PAVE_ITER_ENUMERATE_REF_POSITION

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_Position.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Position {
    uintptr_t index;
    struct Iter_ref_Position iter;
};

#include <tuple_usize_ref_Position.h>
struct IterEnumerate_ref_Position;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Position__next(struct IterEnumerate_ref_Position* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Position IterEnumerate_ref_Position__value(struct IterEnumerate_ref_Position* self);

#endif
