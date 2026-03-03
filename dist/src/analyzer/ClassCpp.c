#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <analyzer/NamespaceCpp.h>
#include <stdbool.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Allocator.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>

#include <analyzer/ClassCpp.h>

#line 783 "src/analyzer/Include.pv"
struct ClassCpp* ClassCpp__new(struct Include* include, char const* name, struct NamespaceCpp* namespace, bool is_struct) {
    #line 784 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 786 "src/analyzer/Include.pv"
    return ArenaAllocator__store_ClassCpp(allocator, (struct ClassCpp) {
        .include = include,
        .is_struct = is_struct,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .fields = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .namespace = namespace,
    });
}
