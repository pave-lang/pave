#ifndef PAVE_FUNCTION_CONTEXT
#define PAVE_FUNCTION_CONTEXT

#include <stdbool.h>

#include <std/Array_FunctionScope.h>
#include <compiler/FunctionCoroutine.h>
struct ArenaAllocator;
struct Function;

#line 4 "src/compiler/FunctionContext.pv"
struct FunctionContext {
    struct ArenaAllocator* allocator;
    struct Function* func_info;
    bool use_scopes;
    struct Array_FunctionScope scopes;
    struct FunctionCoroutine coroutine;
};

#include <compiler/FunctionContext.h>
#include <std/str.h>
struct ArenaAllocator;
struct Function;
struct FunctionContext;
struct Type;

#line 13 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes);

#line 36 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target);

#line 40 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self);

#line 44 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name);

#line 55 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type);

#endif
