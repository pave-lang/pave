#ifndef PAVE_FUNCTION_SCOPE
#define PAVE_FUNCTION_SCOPE

#include <stdbool.h>
#include <stdint.h>

#include <std/Array_DeferStatement.h>
#include <std/HashMap_str_str.h>

#line 5 "src/compiler/FunctionScope.pv"
struct FunctionScope {
    bool break_target;
    bool continue_target;
    uintptr_t break_label;
    struct Array_DeferStatement defer_statements;
    struct HashMap_str_str variable_replacements;
};

struct ArenaAllocator;

#line 15 "src/compiler/FunctionScope.pv"
struct FunctionScope FunctionScope__new(struct ArenaAllocator* allocator, bool break_target, bool continue_target);

#endif
