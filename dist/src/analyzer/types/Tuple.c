#include <stdio.h>

#include <std/Allocator.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>

#include <analyzer/types/Tuple.h>

#line 77 "src/analyzer/types/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct Allocator allocator) {
    #line 78 "src/analyzer/types/Type.pv"
    return (struct Tuple) { .elements = Array_Type__clone(&self->elements, allocator) };
}
