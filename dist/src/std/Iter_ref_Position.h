#ifndef PAVE_ITER_REF_POSITION
#define PAVE_ITER_REF_POSITION

#include <stdint.h>
#include <stdbool.h>

struct Position;

#line 4 "src/std/Array.pv"
struct Iter_ref_Position {
    intptr_t step;
    struct Position* iter;
    struct Position* start;
    struct Position* end;
};

#include <std/IterEnumerate_ref_Position.h>
struct Position;

#line 12 "src/std/Array.pv"
struct Iter_ref_Position Iter_ref_Position__new(struct Position* start, struct Position* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_Position Iter_ref_Position__reverse(struct Iter_ref_Position self);

#line 33 "src/std/Array.pv"
struct Iter_ref_Position Iter_ref_Position__skip(struct Iter_ref_Position self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_Position__next(struct Iter_ref_Position* self);

#line 43 "src/std/Array.pv"
struct Position* Iter_ref_Position__value(struct Iter_ref_Position* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_Position Iter_ref_Position__enumerate(struct Iter_ref_Position self);

#endif
