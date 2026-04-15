#ifndef PAVE_FUNCTION_CONTEXT
#define PAVE_FUNCTION_CONTEXT

#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

struct ArenaAllocator;
struct Function;
#include <std/Array_FunctionScope.h>
#include <compiler/FunctionCoroutine.h>

#line 43 "src/compiler/Generator.pv"
struct FunctionContext {
    struct ArenaAllocator* allocator;
    struct Function* func_info;
    bool use_scopes;
    struct Array_FunctionScope scopes;
    struct FunctionCoroutine coroutine;
};

struct ArenaAllocator;
struct Function;
struct FunctionContext;
struct Type;
#include <compiler/FunctionContext.h>
#include <std/str.h>

#line 52 "src/compiler/Generator.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes);

#line 75 "src/compiler/Generator.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target);

#line 79 "src/compiler/Generator.pv"
void FunctionContext__pop_scope(struct FunctionContext* self);

#line 83 "src/compiler/Generator.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name);

#line 94 "src/compiler/Generator.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type);

#endif
