#include <stdio.h>

#include <std/Allocator.h>
#include <analyzer/Type.h>
#include <stdint.h>
#include <analyzer/IndirectType.h>

#include <analyzer/Indirect.h>

#line 17 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_reference(struct Allocator allocator, struct Type to) {
    #line 18 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 19 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = to };
    #line 20 "src/analyzer/Type.pv"
    return result;
}

#line 23 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_pointer(struct Allocator allocator, struct Type to) {
    #line 24 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 25 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = to };
    #line 26 "src/analyzer/Type.pv"
    return result;
}

#line 29 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct Allocator allocator, struct Type to) {
    #line 30 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 31 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = to };
    #line 32 "src/analyzer/Type.pv"
    return result;
}
