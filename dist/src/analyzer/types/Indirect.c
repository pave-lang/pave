#include <stdint.h>

#include <stdio.h>

#include <std/trait_Allocator.h>
#include <analyzer/types/Indirect.h>

#include <analyzer/types/Indirect.h>

#line 22 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct trait_Allocator allocator, struct Type to) {
    #line 23 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 24 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = to };
    #line 25 "src/analyzer/types/Type.pv"
    return result;
}

#line 28 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct trait_Allocator allocator, struct Type to) {
    #line 29 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 30 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__DYNAMIC_DISPATCH, .to = to };
    #line 31 "src/analyzer/types/Type.pv"
    return result;
}

#line 34 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 35 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 36 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__DYNAMIC_DISPATCH_POINTER, .to = to };
    #line 37 "src/analyzer/types/Type.pv"
    return result;
}

#line 40 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 41 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 42 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = to };
    #line 43 "src/analyzer/types/Type.pv"
    return result;
}

#line 46 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct trait_Allocator allocator, struct Type to) {
    #line 47 "src/analyzer/types/Type.pv"
    struct Indirect* result = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct Indirect));
    #line 48 "src/analyzer/types/Type.pv"
    *result = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = to };
    #line 49 "src/analyzer/types/Type.pv"
    return result;
}
