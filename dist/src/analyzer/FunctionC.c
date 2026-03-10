#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Allocator.h>
#include <std/str.h>
#include <std/Array_ref_Expression.h>
#include <analyzer/Expression.h>

#include <analyzer/FunctionC.h>

#line 859 "src/analyzer/Include.pv"
struct FunctionC* FunctionC__new(struct Include* include, char const* name) {
    #line 860 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 862 "src/analyzer/Include.pv"
    return ArenaAllocator__store_FunctionC(allocator, (struct FunctionC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .arguments = Array_ref_Expression__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
