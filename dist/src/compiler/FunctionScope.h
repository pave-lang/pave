#ifndef PAVE_FUNCTION_SCOPE
#define PAVE_FUNCTION_SCOPE

#include <stdbool.h>

#include <std/Array_DeferStatement.h>
#include <std/HashMap_str_str.h>

#line 5 "src/compiler/FunctionScope.pv"
struct FunctionScope {
    bool break_target;
    bool continue_target;
    struct Array_DeferStatement defer_statements;
    struct HashMap_str_str variable_replacements;
};

#include <compiler/FunctionScope.h>
struct ArenaAllocator;

#line 13 "src/compiler/FunctionScope.pv"
struct FunctionScope FunctionScope__new(struct ArenaAllocator* allocator, bool break_target, bool continue_target);

#endif
