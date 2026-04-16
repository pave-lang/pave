#include <compiler/FunctionScope.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <compiler/FunctionScope.h>

#include <compiler/FunctionScope.h>

#line 12 "src/compiler/FunctionScope.pv"
struct FunctionScope FunctionScope__new(struct ArenaAllocator* allocator, bool break_target, bool continue_target) {
    #line 13 "src/compiler/FunctionScope.pv"
    return (struct FunctionScope) {
        .break_target = break_target,
        .continue_target = continue_target,
        .defer_statements = Array_ref_Expression__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .variable_replacements = HashMap_str_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}
