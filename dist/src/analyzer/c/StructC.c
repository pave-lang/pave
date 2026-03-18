#include <analyzer/c/Include.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Allocator.h>
#include <std/str.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/c/StructCField.h>

#include <analyzer/c/StructC.h>

#line 10 "src/analyzer/c/StructC.pv"
struct StructC* StructC__new(struct Include* include, char const* name) {
    #line 11 "src/analyzer/c/StructC.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 13 "src/analyzer/c/StructC.pv"
    return ArenaAllocator__store_StructC(allocator, (struct StructC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .fields = HashMap_str_StructCField__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
