#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_Type.h>
#include <std/trait_Allocator.h>

#include <analyzer/c/NamespaceCpp.h>

#include <analyzer/c/NamespaceCpp.h>

#line 13 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct ParentCpp parent) {
    #line 14 "src/analyzer/c/NamespaceCpp.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 16 "src/analyzer/c/NamespaceCpp.pv"
    return ArenaAllocator__store_NamespaceCpp(allocator, (struct NamespaceCpp) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .parent = parent,
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .values = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
