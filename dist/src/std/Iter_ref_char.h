#ifndef PAVE_ITER_REF_CHAR
#define PAVE_ITER_REF_CHAR

#include <stdint.h>
#include <stdbool.h>

struct IterEnumerate_ref_char;

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_char {
    intptr_t step;
    char* iter;
    char* start;
    char* end;
};

#line 12 "src/std/Array.pv"
struct Iter_ref_char Iter_ref_char__new(char* start, char* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_char Iter_ref_char__reverse(struct Iter_ref_char self);

#line 33 "src/std/Array.pv"
struct Iter_ref_char Iter_ref_char__skip(struct Iter_ref_char self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_char__next(struct Iter_ref_char* self);

#line 43 "src/std/Array.pv"
char* Iter_ref_char__value(struct Iter_ref_char* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_char Iter_ref_char__enumerate(struct Iter_ref_char self);

#endif
