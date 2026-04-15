#ifndef PAVE_TUPLE
#define PAVE_TUPLE

#include <stdio.h>

#include <std/Array_Type.h>

#line 72 "src/analyzer/types/Type.pv"
struct Tuple {
    struct Array_Type elements;
};

struct Tuple;
#include <std/trait_Allocator.h>
#include <analyzer/types/Tuple.h>

#line 77 "src/analyzer/types/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct trait_Allocator allocator);

#endif
