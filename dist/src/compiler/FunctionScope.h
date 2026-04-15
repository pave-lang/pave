#ifndef PAVE_FUNCTION_SCOPE
#define PAVE_FUNCTION_SCOPE

#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <std/Array_ref_Expression.h>
#include <std/HashMap_str_str.h>

#line 12 "src/compiler/Generator.pv"
struct FunctionScope {
    bool break_target;
    bool continue_target;
    struct Array_ref_Expression defer_statements;
    struct HashMap_str_str variable_replacements;
};

struct ArenaAllocator;
#include <compiler/FunctionScope.h>

#line 20 "src/compiler/Generator.pv"
struct FunctionScope FunctionScope__new(struct ArenaAllocator* allocator, bool break_target, bool continue_target);

#endif
