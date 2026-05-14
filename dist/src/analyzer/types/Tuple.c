#include <stdio.h>

#include <analyzer/types/Tuple.h>
#include <std/trait_Allocator.h>
#include <analyzer/types/Tuple.h>

#include <analyzer/types/Tuple.h>

#line 82 "src/analyzer/types/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct trait_Allocator allocator) {
    #line 83 "src/analyzer/types/Type.pv"
    return (struct Tuple) { .elements = Array_Type__clone(&self->elements, allocator) };
}
