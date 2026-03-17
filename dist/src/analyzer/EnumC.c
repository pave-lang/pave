#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <analyzer/ParentCpp.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Allocator.h>
#include <std/str.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/EnumCValue.h>

#include <analyzer/EnumC.h>

#line 904 "src/analyzer/Include.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name, struct ParentCpp parent) {
    #line 905 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 907 "src/analyzer/Include.pv"
    return ArenaAllocator__store_EnumC(allocator, (struct EnumC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .parent = parent,
        .values = HashMap_str_EnumCValue__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
