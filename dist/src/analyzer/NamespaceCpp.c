#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <analyzer/ParentCpp.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Allocator.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/Type.h>

#include <analyzer/NamespaceCpp.h>

#line 1001 "src/analyzer/Include.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct ParentCpp parent) {
    #line 1002 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 1004 "src/analyzer/Include.pv"
    return ArenaAllocator__store_NamespaceCpp(allocator, (struct NamespaceCpp) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .parent = parent,
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
