#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Allocator.h>
#include <std/str.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/StructCField.h>

#include <analyzer/StructC.h>

#line 758 "src/analyzer/Include.pv"
struct StructC* StructC__new(struct Include* include, char const* name) {
    #line 759 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 761 "src/analyzer/Include.pv"
    return ArenaAllocator__store_StructC(allocator, (struct StructC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .fields = HashMap_str_StructCField__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
