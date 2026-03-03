#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <std/ArenaAllocator.h>
#include <stdbool.h>
#include <std/Array_ref_Expression.h>
#include <analyzer/Expression.h>
#include <std/Allocator.h>
#include <std/HashMap_str_str.h>
#include <std/str.h>

#include <compiler/FunctionScope.h>

#line 16 "src/compiler/Generator.pv"
struct FunctionScope FunctionScope__new(struct ArenaAllocator* allocator, bool break_target, bool continue_target) {
    #line 17 "src/compiler/Generator.pv"
    return (struct FunctionScope) {
        .break_target = break_target,
        .continue_target = continue_target,
        .defer_statements = Array_ref_Expression__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .variable_replacements = HashMap_str_str__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}
