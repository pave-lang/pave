#include <stdint.h>
#include <string.h>

#include <compiler/FunctionContext.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Function.h>
#include <std/trait_Allocator.h>
#include <std/HashMap_str_ref_Type.h>
#include <analyzer/types/FunctionType.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/Token.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <compiler/FunctionScope.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/Iter_ref_FunctionScope.h>
#include <std/Iter_ref_DeferStatement.h>
#include <std/HashMap_str_str.h>
#include <std/String.h>
#include <i32.h>
#include <std/Array_char.h>
#include <compiler/FunctionContext.h>

#include <compiler/FunctionContext.h>

#line 14 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes) {
    #line 15 "src/compiler/FunctionContext.pv"
    struct FunctionContext self = (struct FunctionContext) {
        .allocator = allocator,
        .func_info = func_info,
        .use_scopes = use_scopes,
        .scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .coroutine = (struct FunctionCoroutine) { .yield_count = 0, .variables = (struct HashMap_str_ref_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
    };

    #line 23 "src/compiler/FunctionContext.pv"
    if (self.use_scopes) {
        #line 24 "src/compiler/FunctionContext.pv"
        self.scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 25 "src/compiler/FunctionContext.pv"
        FunctionContext__push_scope(&self, false, false);
    }

    #line 28 "src/compiler/FunctionContext.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 29 "src/compiler/FunctionContext.pv"
        self.coroutine = FunctionCoroutine__new(allocator);
        #line 30 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 30 "src/compiler/FunctionContext.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 30 "src/compiler/FunctionContext.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 31 "src/compiler/FunctionContext.pv"
            struct Token* name = param->name;
            #line 32 "src/compiler/FunctionContext.pv"
            if (name == 0) {
                #line 32 "src/compiler/FunctionContext.pv"
                continue;
            }
            #line 33 "src/compiler/FunctionContext.pv"
            FunctionContext__add_variable(&self, name->value, &param->type);
        } }
    }

    #line 37 "src/compiler/FunctionContext.pv"
    return self;
}

#line 40 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new_const(struct ArenaAllocator* allocator) {
    #line 41 "src/compiler/FunctionContext.pv"
    return (struct FunctionContext) {
        .allocator = allocator,
        .func_info = 0,
        .use_scopes = false,
        .scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .coroutine = (struct FunctionCoroutine) { .yield_count = 0, .variables = (struct HashMap_str_ref_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
    };
}

#line 50 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target) {
    #line 51 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__append(&self->scopes, FunctionScope__new(self->allocator, break_target, continue_target));
}

#line 54 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self) {
    #line 55 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__remove_back(&self->scopes);
}

#line 58 "src/compiler/FunctionContext.pv"
void FunctionContext__push_defer(struct FunctionContext* self, struct DeferStatement stmt) {
    #line 59 "src/compiler/FunctionContext.pv"
    struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
    #line 60 "src/compiler/FunctionContext.pv"
    if (scope == 0) {
        #line 60 "src/compiler/FunctionContext.pv"
        return;
    }
    #line 61 "src/compiler/FunctionContext.pv"
    Array_DeferStatement__append(&scope->defer_statements, stmt);
}

#line 64 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_all_defer_statements(struct FunctionContext* self) {
    #line 65 "src/compiler/FunctionContext.pv"
    struct Array_DeferStatement result = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 66 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 66 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 66 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 67 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&scope->defer_statements));
        #line 67 "src/compiler/FunctionContext.pv"
        while (Iter_ref_DeferStatement__next(&__iter)) {
            #line 67 "src/compiler/FunctionContext.pv"
            struct DeferStatement* stmt = Iter_ref_DeferStatement__value(&__iter);

            #line 68 "src/compiler/FunctionContext.pv"
            Array_DeferStatement__append(&result, *stmt);
        } }
    } }
    #line 71 "src/compiler/FunctionContext.pv"
    return result;
}

#line 74 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_loop_defer_statements(struct FunctionContext* self) {
    #line 75 "src/compiler/FunctionContext.pv"
    struct Array_DeferStatement result = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 76 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 76 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 76 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 77 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&scope->defer_statements));
        #line 77 "src/compiler/FunctionContext.pv"
        while (Iter_ref_DeferStatement__next(&__iter)) {
            #line 77 "src/compiler/FunctionContext.pv"
            struct DeferStatement* stmt = Iter_ref_DeferStatement__value(&__iter);

            #line 78 "src/compiler/FunctionContext.pv"
            Array_DeferStatement__append(&result, *stmt);
        } }
        #line 80 "src/compiler/FunctionContext.pv"
        if (scope->break_target) {
            #line 80 "src/compiler/FunctionContext.pv"
            return result;
        }
    } }
    #line 82 "src/compiler/FunctionContext.pv"
    return result;
}

#line 85 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name) {
    #line 86 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 86 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 86 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 87 "src/compiler/FunctionContext.pv"
        struct str* variable = HashMap_str_str__find(&scope->variable_replacements, &name);
        #line 88 "src/compiler/FunctionContext.pv"
        if (variable != 0) {
            #line 89 "src/compiler/FunctionContext.pv"
            return *variable;
        }
    } }

    #line 93 "src/compiler/FunctionContext.pv"
    return name;
}

#line 96 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type) {
    #line 97 "src/compiler/FunctionContext.pv"
    struct Function* func_info = self->func_info;
    #line 98 "src/compiler/FunctionContext.pv"
    if (func_info == 0 || func_info->type != FUNCTION_TYPE__COROUTINE) {
        #line 98 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 100 "src/compiler/FunctionContext.pv"
    struct String new_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 101 "src/compiler/FunctionContext.pv"
    String__append(&new_name, name);

    #line 103 "src/compiler/FunctionContext.pv"
    if (HashMap_str_ref_Type__find(&self->coroutine.variables, &name) == 0) {
        #line 104 "src/compiler/FunctionContext.pv"
        HashMap_str_ref_Type__insert(&self->coroutine.variables, name, type);

        #line 106 "src/compiler/FunctionContext.pv"
        if (self->use_scopes) {
            #line 107 "src/compiler/FunctionContext.pv"
            struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
            #line 108 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });

            #line 110 "src/compiler/FunctionContext.pv"
            if (scope == 0) {
                #line 110 "src/compiler/FunctionContext.pv"
                return;
            }
            #line 111 "src/compiler/FunctionContext.pv"
            HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
        }

        #line 114 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 117 "src/compiler/FunctionContext.pv"
    String__append(&new_name, (struct str){ .ptr = "_x", .length = strlen("_x") });
    #line 118 "src/compiler/FunctionContext.pv"
    int32_t i = 1;
    #line 119 "src/compiler/FunctionContext.pv"
    while (true) {
        #line 120 "src/compiler/FunctionContext.pv"
        if (i32__Eq_i32__eq(i, 10)) {
            #line 120 "src/compiler/FunctionContext.pv"
            String__append(&new_name, (struct str){ .ptr = "x", .length = strlen("x") });
        }
        #line 121 "src/compiler/FunctionContext.pv"
        if (i > 9) {
            #line 122 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 2] = '0' + (i / 10);
            #line 123 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + (i % 10);
        } else {
            #line 125 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + i;
        }

        #line 128 "src/compiler/FunctionContext.pv"
        struct str new_name_str = String__as_str(&new_name);
        #line 129 "src/compiler/FunctionContext.pv"
        if (HashMap_str_ref_Type__find(&self->coroutine.variables, &new_name_str) == 0) {
            #line 130 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 131 "src/compiler/FunctionContext.pv"
            new_name_str = String__as_str(&new_name);
            #line 132 "src/compiler/FunctionContext.pv"
            HashMap_str_ref_Type__insert(&self->coroutine.variables, str__slice(new_name_str, 5, new_name_str.length), type);

            #line 134 "src/compiler/FunctionContext.pv"
            if (self->use_scopes) {
                #line 135 "src/compiler/FunctionContext.pv"
                struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
                #line 136 "src/compiler/FunctionContext.pv"
                if (scope == 0) {
                    #line 136 "src/compiler/FunctionContext.pv"
                    return;
                }
                #line 137 "src/compiler/FunctionContext.pv"
                HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
            }
            #line 139 "src/compiler/FunctionContext.pv"
            return;
        }
        #line 141 "src/compiler/FunctionContext.pv"
        i += 1;
    }
}
