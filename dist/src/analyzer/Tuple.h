#ifndef PAVE_TUPLE
#define PAVE_TUPLE

#include <std/Array_Type.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>

#include <stdio.h>

#line 63 "src/analyzer/Type.pv"
struct Tuple {
    struct Array_Type elements;
};

#line 68 "src/analyzer/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct Allocator allocator);

#endif
