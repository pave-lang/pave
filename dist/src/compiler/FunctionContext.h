#ifndef PAVE_FUNCTION_CONTEXT
#define PAVE_FUNCTION_CONTEXT

#include <stdbool.h>
#include <std/Array_FunctionScope.h>
#include <compiler/FunctionScope.h>
#include <compiler/FunctionCoroutine.h>

struct ArenaAllocator;
struct Function;
struct str;
struct Type;

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#line 41 "src/compiler/Generator.pv"
struct FunctionContext {
    struct ArenaAllocator* allocator;
    struct Function* func_info;
    bool use_scopes;
    struct Array_FunctionScope scopes;
    struct FunctionCoroutine coroutine;
};

#line 50 "src/compiler/Generator.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes);

#line 73 "src/compiler/Generator.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target);

#line 77 "src/compiler/Generator.pv"
void FunctionContext__pop_scope(struct FunctionContext* self);

#line 81 "src/compiler/Generator.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name);

#line 92 "src/compiler/Generator.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type);

#endif
