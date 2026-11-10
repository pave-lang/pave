#include <stdint.h>

#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <compiler/FunctionScope.h>

#include <compiler/FunctionScope.h>

#line 15 "src/compiler/FunctionScope.pv"
struct FunctionScope FunctionScope__new(struct ArenaAllocator* allocator, bool break_target, bool continue_target) {
    #line 16 "src/compiler/FunctionScope.pv"
    return (struct FunctionScope) {
        .break_target = break_target,
        .continue_target = continue_target,
        .break_label = 0,
        .defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .variable_replacements = HashMap_str_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}
