#include <stdio.h>

#include <std/Allocator.h>
#include <analyzer/types/Type.h>
#include <stdint.h>
#include <analyzer/types/IndirectType.h>

#include <analyzer/types/Indirect.h>

#line 19 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct Allocator allocator, struct Type to) {
    #line 20 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 21 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = to };
    #line 22 "src/analyzer/types/Type.pv"
    return result;
}

#line 25 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct Allocator allocator, struct Type to) {
    #line 26 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 27 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__DYNAMIC_DISPATCH, .to = to };
    #line 28 "src/analyzer/types/Type.pv"
    return result;
}

#line 31 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct Allocator allocator, struct Type to) {
    #line 32 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 33 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = to };
    #line 34 "src/analyzer/types/Type.pv"
    return result;
}

#line 37 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct Allocator allocator, struct Type to) {
    #line 38 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 39 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = to };
    #line 40 "src/analyzer/types/Type.pv"
    return result;
}
