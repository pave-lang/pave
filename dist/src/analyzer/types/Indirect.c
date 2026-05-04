#include <stdint.h>

#include <stdio.h>

#include <analyzer/types/Indirect.h>
#include <std/trait_Allocator.h>
#include <analyzer/types/Indirect.h>

#include <analyzer/types/Indirect.h>

#line 20 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct trait_Allocator allocator, struct Type to) {
    #line 21 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 22 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = to };
    #line 23 "src/analyzer/types/Type.pv"
    return result;
}

#line 26 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct trait_Allocator allocator, struct Type to) {
    #line 27 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 28 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__DYNAMIC_DISPATCH, .to = to };
    #line 29 "src/analyzer/types/Type.pv"
    return result;
}

#line 32 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 33 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 34 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = to };
    #line 35 "src/analyzer/types/Type.pv"
    return result;
}

#line 38 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 39 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->alloc(allocator.instance, sizeof(struct Indirect));
    #line 40 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = to };
    #line 41 "src/analyzer/types/Type.pv"
    return result;
}
