#ifndef PAVE_ARRAY_ITER_REF_STRING
#define PAVE_ARRAY_ITER_REF_STRING

#include <stdint.h>
#include <stdbool.h>

struct String;
struct IterEnumerate_ref_String;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct ArrayIter_ref_String {
    intptr_t step;
    struct String* iter;
    struct String* start;
    struct String* end;
};

#line 12 "src/std/Array.pv"
struct ArrayIter_ref_String ArrayIter_ref_String__new(struct String* start, struct String* end);

#line 21 "src/std/Array.pv"
struct ArrayIter_ref_String ArrayIter_ref_String__reverse(struct ArrayIter_ref_String self);

#line 33 "src/std/Array.pv"
struct ArrayIter_ref_String ArrayIter_ref_String__skip(struct ArrayIter_ref_String self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool ArrayIter_ref_String__next(struct ArrayIter_ref_String* self);

#line 43 "src/std/Array.pv"
struct String* ArrayIter_ref_String__value(struct ArrayIter_ref_String* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_String ArrayIter_ref_String__enumerate(struct ArrayIter_ref_String self);

#endif
