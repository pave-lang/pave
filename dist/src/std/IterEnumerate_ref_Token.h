#ifndef PAVE_ITER_ENUMERATE_REF_TOKEN
#define PAVE_ITER_ENUMERATE_REF_TOKEN

#include <stdint.h>
#include <std/ArrayIter_ref_Token.h>
#include <stdbool.h>

struct Token;

#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Token {
    uintptr_t index;
    struct ArrayIter_ref_Token iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Token__next(struct IterEnumerate_ref_Token* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Token IterEnumerate_ref_Token__value(struct IterEnumerate_ref_Token* self);

#endif
