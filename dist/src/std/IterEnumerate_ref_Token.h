#ifndef PAVE_ITER_ENUMERATE_REF_TOKEN
#define PAVE_ITER_ENUMERATE_REF_TOKEN

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include <std/Iter_ref_Token.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_Token {
    uintptr_t index;
    struct Iter_ref_Token iter;
};
struct IterEnumerate_ref_Token;
#include <tuple_usize_ref_Token.h>


#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_Token__next(struct IterEnumerate_ref_Token* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_Token IterEnumerate_ref_Token__value(struct IterEnumerate_ref_Token* self);

#endif
