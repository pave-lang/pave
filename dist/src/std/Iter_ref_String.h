#ifndef PAVE_ITER_REF_STRING
#define PAVE_ITER_REF_STRING

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct String;

#line 4 "src/std/Array.pv"
struct Iter_ref_String {
    intptr_t step;
    struct String* iter;
    struct String* start;
    struct String* end;
};

#include <std/Iter_ref_String.h>
#include <std/IterEnumerate_ref_String.h>
struct String;
struct Iter_ref_String;

#line 12 "src/std/Array.pv"
struct Iter_ref_String Iter_ref_String__new(struct String* start, struct String* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_String Iter_ref_String__reverse(struct Iter_ref_String self);

#line 33 "src/std/Array.pv"
struct Iter_ref_String Iter_ref_String__skip(struct Iter_ref_String self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_String__next(struct Iter_ref_String* self);

#line 43 "src/std/Array.pv"
struct String* Iter_ref_String__value(struct Iter_ref_String* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_String Iter_ref_String__enumerate(struct Iter_ref_String self);

#endif
