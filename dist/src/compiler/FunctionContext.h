#ifndef PAVE_FUNCTION_CONTEXT
#define PAVE_FUNCTION_CONTEXT

#include <stdbool.h>
#include <stdint.h>

#include <std/Array_FunctionScope.h>
#include <compiler/FunctionCoroutine.h>
#include <std/Array_FunctionTemp.h>
struct ArenaAllocator;
struct Function;

#line 10 "src/compiler/FunctionContext.pv"
struct FunctionContext {
    struct ArenaAllocator* allocator;
    struct Function* func_info;
    bool use_scopes;
    struct Array_FunctionScope scopes;
    struct FunctionCoroutine coroutine;
    struct Array_FunctionTemp temps;
    uintptr_t temp_count;
    bool temps_enabled;
    uintptr_t label_count;
};

#include <analyzer/statement/DeferStatement.h>
#include <std/Array_DeferStatement.h>
#include <std/str.h>
struct ArenaAllocator;
struct Function;
struct Type;

#line 25 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes);

#line 55 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new_const(struct ArenaAllocator* allocator);

#line 69 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target);

#line 73 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self);

#line 77 "src/compiler/FunctionContext.pv"
void FunctionContext__push_defer(struct FunctionContext* self, struct DeferStatement stmt);

#line 83 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_all_defer_statements(struct FunctionContext* self);

#line 94 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_continue_defer_statements(struct FunctionContext* self);

#line 109 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_break_defer_statements(struct FunctionContext* self, uintptr_t* label);

#line 147 "src/compiler/FunctionContext.pv"
struct str FunctionContext__make_temp_name(struct FunctionContext* self);

#line 158 "src/compiler/FunctionContext.pv"
struct str FunctionContext__add_temp(struct FunctionContext* self, struct Type* type);

#line 167 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name);

#line 178 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type);

#endif
