#include <stdint.h>

#include <stdio.h>

#include <analyzer/types/Indirect.h>
#include <std/trait_Allocator.h>
#include <analyzer/types/Indirect.h>

#include <analyzer/types/Indirect.h>

#line 21 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct trait_Allocator allocator, struct Type to) {
    #line 22 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 23 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = to };
    #line 24 "src/analyzer/types/Type.pv"
    return result;
}

#line 27 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct trait_Allocator allocator, struct Type to) {
    #line 28 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 29 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__DYNAMIC_DISPATCH, .to = to };
    #line 30 "src/analyzer/types/Type.pv"
    return result;
}

#line 33 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 34 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 35 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = to };
    #line 36 "src/analyzer/types/Type.pv"
    return result;
}

#line 39 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 40 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 41 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = to };
    #line 42 "src/analyzer/types/Type.pv"
    return result;
}
