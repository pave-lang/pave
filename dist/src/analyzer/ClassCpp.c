#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <analyzer/ParentCpp.h>
#include <stdbool.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Array_Type.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>

#include <analyzer/ClassCpp.h>

#line 955 "src/analyzer/Include.pv"
struct ClassCpp* ClassCpp__new(struct Include* include, char const* name, struct ParentCpp parent, bool is_struct) {
    #line 956 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 958 "src/analyzer/Include.pv"
    return ArenaAllocator__store_ClassCpp(allocator, (struct ClassCpp) {
        .include = include,
        .is_struct = is_struct,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .parent = parent,
        .fields = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .bases = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
