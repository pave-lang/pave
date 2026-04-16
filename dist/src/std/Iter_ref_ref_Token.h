#ifndef PAVE_ITER_REF_REF_TOKEN
#define PAVE_ITER_REF_REF_TOKEN

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#line 4 "src/std/Array.pv"
struct Iter_ref_ref_Token {
    intptr_t step;
    struct Token** iter;
    struct Token** start;
    struct Token** end;
};

#include <std/Iter_ref_ref_Token.h>
#include <std/IterEnumerate_ref_ref_Token.h>
struct Iter_ref_ref_Token;

#line 12 "src/std/Array.pv"
struct Iter_ref_ref_Token Iter_ref_ref_Token__new(struct Token** start, struct Token** end);

#line 21 "src/std/Array.pv"
struct Iter_ref_ref_Token Iter_ref_ref_Token__reverse(struct Iter_ref_ref_Token self);

#line 33 "src/std/Array.pv"
struct Iter_ref_ref_Token Iter_ref_ref_Token__skip(struct Iter_ref_ref_Token self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_ref_Token__next(struct Iter_ref_ref_Token* self);

#line 43 "src/std/Array.pv"
struct Token** Iter_ref_ref_Token__value(struct Iter_ref_ref_Token* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_ref_Token Iter_ref_ref_Token__enumerate(struct Iter_ref_ref_Token self);

#endif
