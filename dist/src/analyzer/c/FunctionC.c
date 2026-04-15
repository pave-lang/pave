#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/FunctionC.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <std/Array_ref_Expression.h>
#include <std/trait_Allocator.h>
#include <analyzer/c/FunctionC.h>

#include <analyzer/c/FunctionC.h>

#line 13 "src/analyzer/c/FunctionC.pv"
struct FunctionC* FunctionC__new(struct Include* include, char const* name, struct Type* return_type) {
    #line 14 "src/analyzer/c/FunctionC.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 16 "src/analyzer/c/FunctionC.pv"
    return ArenaAllocator__store_FunctionC(allocator, (struct FunctionC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .return_type = *return_type,
        .arguments = Array_ref_Expression__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    });
}
