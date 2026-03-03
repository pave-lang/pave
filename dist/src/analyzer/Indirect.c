#include <stdio.h>

#include <std/Allocator.h>
#include <analyzer/Type.h>
#include <stdint.h>
#include <analyzer/IndirectType.h>

#include <analyzer/Indirect.h>

#line 18 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_reference(struct Allocator allocator, struct Type to) {
    #line 19 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 20 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = to };
    #line 21 "src/analyzer/Type.pv"
    return result;
}

#line 24 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct Allocator allocator, struct Type to) {
    #line 25 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 26 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__DYNAMIC_DISPATCH, .to = to };
    #line 27 "src/analyzer/Type.pv"
    return result;
}

#line 30 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_pointer(struct Allocator allocator, struct Type to) {
    #line 31 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 32 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = to };
    #line 33 "src/analyzer/Type.pv"
    return result;
}

#line 36 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct Allocator allocator, struct Type to) {
    #line 37 "src/analyzer/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 38 "src/analyzer/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = to };
    #line 39 "src/analyzer/Type.pv"
    return result;
}
