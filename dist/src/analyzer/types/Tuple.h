#ifndef PAVE_TUPLE
#define PAVE_TUPLE

#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>

#include <stdio.h>

#line 71 "src/analyzer/types/Type.pv"
struct Tuple {
    struct Array_Type elements;
};

#line 76 "src/analyzer/types/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct Allocator allocator);

#endif
