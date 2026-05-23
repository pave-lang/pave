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
#include <std/Iter_ref_FunctionScope.h>
#include <std/HashMap_str_str.h>
#include <std/String.h>
#include <std/Array_char.h>
#include <compiler/FunctionContext.h>

#include <compiler/FunctionContext.h>

#line 13 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes) {
    #line 14 "src/compiler/FunctionContext.pv"
    struct FunctionContext self = (struct FunctionContext) {
        .allocator = allocator,
        .func_info = func_info,
        .use_scopes = use_scopes,
        .scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .coroutine = (struct FunctionCoroutine) { .yield_count = 0, .variables = (struct HashMap_str_ref_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
    };

    #line 22 "src/compiler/FunctionContext.pv"
    if (self.use_scopes) {
        #line 23 "src/compiler/FunctionContext.pv"
        self.scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 24 "src/compiler/FunctionContext.pv"
        FunctionContext__push_scope(&self, false, false);
    }

    #line 27 "src/compiler/FunctionContext.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 28 "src/compiler/FunctionContext.pv"
        self.coroutine = FunctionCoroutine__new(allocator);
        #line 29 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 29 "src/compiler/FunctionContext.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 29 "src/compiler/FunctionContext.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 30 "src/compiler/FunctionContext.pv"
            struct Token* name = param->name;
            #line 31 "src/compiler/FunctionContext.pv"
            if (name == 0) {
                #line 31 "src/compiler/FunctionContext.pv"
                continue;
            }
            #line 32 "src/compiler/FunctionContext.pv"
            FunctionContext__add_variable(&self, name->value, &param->type);
        } }
    }

    #line 36 "src/compiler/FunctionContext.pv"
    return self;
}

#line 39 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new_const(struct ArenaAllocator* allocator) {
    #line 40 "src/compiler/FunctionContext.pv"
    return (struct FunctionContext) {
        .allocator = allocator,
        .func_info = 0,
        .use_scopes = false,
        .scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .coroutine = (struct FunctionCoroutine) { .yield_count = 0, .variables = (struct HashMap_str_ref_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
    };
}

#line 49 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target) {
    #line 50 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__append(&self->scopes, FunctionScope__new(self->allocator, break_target, continue_target));
}

#line 53 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self) {
    #line 54 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__remove_back(&self->scopes);
}

#line 57 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name) {
    #line 58 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 58 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 58 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 59 "src/compiler/FunctionContext.pv"
        struct str* variable = HashMap_str_str__find(&scope->variable_replacements, &name);
        #line 60 "src/compiler/FunctionContext.pv"
        if (variable != 0) {
            #line 61 "src/compiler/FunctionContext.pv"
            return *variable;
        }
    } }

    #line 65 "src/compiler/FunctionContext.pv"
    return name;
}

#line 68 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type) {
    #line 69 "src/compiler/FunctionContext.pv"
    struct Function* func_info = self->func_info;
    #line 70 "src/compiler/FunctionContext.pv"
    if (func_info == 0 || func_info->type != FUNCTION_TYPE__COROUTINE) {
        #line 70 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 72 "src/compiler/FunctionContext.pv"
    struct String new_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 73 "src/compiler/FunctionContext.pv"
    String__append(&new_name, name);

    #line 75 "src/compiler/FunctionContext.pv"
    if (HashMap_str_ref_Type__find(&self->coroutine.variables, &name) == 0) {
        #line 76 "src/compiler/FunctionContext.pv"
        HashMap_str_ref_Type__insert(&self->coroutine.variables, name, type);

        #line 78 "src/compiler/FunctionContext.pv"
        if (self->use_scopes) {
            #line 79 "src/compiler/FunctionContext.pv"
            struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
            #line 80 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 81 "src/compiler/FunctionContext.pv"
            HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
        }

        #line 84 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 87 "src/compiler/FunctionContext.pv"
    String__append(&new_name, (struct str){ .ptr = "_x", .length = strlen("_x") });
    #line 88 "src/compiler/FunctionContext.pv"
    int32_t i = 1;
    #line 89 "src/compiler/FunctionContext.pv"
    while (true) {
        #line 90 "src/compiler/FunctionContext.pv"
        if (i == 10) {
            #line 90 "src/compiler/FunctionContext.pv"
            String__append(&new_name, (struct str){ .ptr = "x", .length = strlen("x") });
        }
        #line 91 "src/compiler/FunctionContext.pv"
        if (i > 9) {
            #line 92 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 2] = '0' + (i / 10);
            #line 93 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + (i % 10);
        } else {
            #line 95 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + i;
        }

        #line 98 "src/compiler/FunctionContext.pv"
        struct str new_name_str = String__as_str(&new_name);
        #line 99 "src/compiler/FunctionContext.pv"
        if (HashMap_str_ref_Type__find(&self->coroutine.variables, &new_name_str) == 0) {
            #line 100 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 101 "src/compiler/FunctionContext.pv"
            new_name_str = String__as_str(&new_name);
            #line 102 "src/compiler/FunctionContext.pv"
            HashMap_str_ref_Type__insert(&self->coroutine.variables, str__slice(new_name_str, 5, new_name_str.length), type);

            #line 104 "src/compiler/FunctionContext.pv"
            if (self->use_scopes) {
                #line 105 "src/compiler/FunctionContext.pv"
                struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
                #line 106 "src/compiler/FunctionContext.pv"
                HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
            }
            #line 108 "src/compiler/FunctionContext.pv"
            return;
        }
        #line 110 "src/compiler/FunctionContext.pv"
        i += 1;
    }
}
