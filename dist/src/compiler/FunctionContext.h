#ifndef PAVE_FUNCTION_CONTEXT
#define PAVE_FUNCTION_CONTEXT

#include <stdbool.h>
#include <stdint.h>

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
    uintptr_t optional_temp_count;
};

#include <compiler/FunctionContext.h>
#include <std/str.h>
struct ArenaAllocator;
struct Function;
struct FunctionContext;
struct Type;

#line 14 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes);

#line 39 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new_const(struct ArenaAllocator* allocator);

#line 50 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target);

#line 54 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self);

#line 58 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name);

#line 69 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type);

#endif
