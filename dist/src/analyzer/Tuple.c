#include <stdio.h>

#include <std/Allocator.h>
#include <std/Array_Type.h>
#include <analyzer/Type.h>

#include <analyzer/Tuple.h>

#line 75 "src/analyzer/Type.pv"
struct Tuple Tuple__clone(struct Tuple* self, struct Allocator allocator) {
    #line 76 "src/analyzer/Type.pv"
    return (struct Tuple) { .elements = Array_Type__clone(&self->elements, allocator) };
}
