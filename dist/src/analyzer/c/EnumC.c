#include <string.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/EnumC.h>
#include <std/trait_Allocator.h>
#include <analyzer/c/EnumC.h>

#include <analyzer/c/EnumC.h>

#line 11 "src/analyzer/c/EnumC.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name, struct ParentCpp parent) {
    #line 12 "src/analyzer/c/EnumC.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 14 "src/analyzer/c/EnumC.pv"
    return ArenaAllocator__store_EnumC(allocator, (struct EnumC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .parent = parent,
        .values = HashMap_str_EnumCValue__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
