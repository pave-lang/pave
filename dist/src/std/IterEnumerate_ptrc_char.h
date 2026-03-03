#ifndef PAVE_ITER_ENUMERATE_PTRC_CHAR
#define PAVE_ITER_ENUMERATE_PTRC_CHAR

#include <stdint.h>
#include <std/ArrayIter_ptrc_char.h>
#include <stdbool.h>


#include <stdlib.h>
#include <string.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ptrc_char {
    uintptr_t index;
    struct ArrayIter_ptrc_char iter;
};

#line 58 "src/std/Array.pv"
bool IterEnumerate_ptrc_char__next(struct IterEnumerate_ptrc_char* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ptrc_char IterEnumerate_ptrc_char__value(struct IterEnumerate_ptrc_char* self);

#endif
