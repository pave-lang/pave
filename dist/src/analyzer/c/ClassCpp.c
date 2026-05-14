#include <string.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/ClassCpp.h>
#include <std/trait_Allocator.h>
#include <analyzer/c/ClassCpp.h>

#include <analyzer/c/ClassCpp.h>

#line 16 "src/analyzer/c/ClassCpp.pv"
struct ClassCpp* ClassCpp__new(struct Include* include, char const* name, struct ParentCpp parent, bool is_struct) {
    #line 17 "src/analyzer/c/ClassCpp.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 19 "src/analyzer/c/ClassCpp.pv"
    return ArenaAllocator__store_ClassCpp(allocator, (struct ClassCpp[]){(struct ClassCpp) {
        .include = include,
        .is_struct = is_struct,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .parent = parent,
        .fields = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .values = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .bases = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    }});
}
