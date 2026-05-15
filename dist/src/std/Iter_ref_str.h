#ifndef PAVE_ITER_REF_STR
#define PAVE_ITER_REF_STR

#include <stdint.h>
#include <stdbool.h>

struct str;

#line 4 "src/std/Array.pv"
struct Iter_ref_str {
    intptr_t step;
    struct str* iter;
    struct str* start;
    struct str* end;
};

#include <std/Iter_ref_str.h>
#include <std/IterEnumerate_ref_str.h>
struct str;
struct Iter_ref_str;

#line 12 "src/std/Array.pv"
struct Iter_ref_str Iter_ref_str__new(struct str* start, struct str* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_str Iter_ref_str__reverse(struct Iter_ref_str self);

#line 33 "src/std/Array.pv"
struct Iter_ref_str Iter_ref_str__skip(struct Iter_ref_str self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_str__next(struct Iter_ref_str* self);

#line 43 "src/std/Array.pv"
struct str* Iter_ref_str__value(struct Iter_ref_str* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_str Iter_ref_str__enumerate(struct Iter_ref_str self);

#endif
