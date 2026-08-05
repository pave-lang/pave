#ifndef PAVE_TUPLE
#define PAVE_TUPLE

#include <std/Array_Type.h>

#line 80 "src/analyzer/types/Type.pv"
struct Tuple {
    struct Array_Type elements;
};

#include <std/trait_Allocator.h>

#line 90 "src/analyzer/types/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct trait_Allocator allocator);

#endif
