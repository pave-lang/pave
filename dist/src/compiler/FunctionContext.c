#include <stdint.h>
#include <string.h>

#include <compiler/FunctionContext.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Function.h>
#include <std/trait_Allocator.h>
#include <analyzer/types/FunctionType.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/str.h>
#include <analyzer/Token.h>
#include <analyzer/types/Type.h>
#include <compiler/FunctionScope.h>
#include <std/Iter_ref_FunctionScope.h>
#include <std/HashMap_str_str.h>
#include <std/String.h>
#include <std/HashMap_str_ref_Type.h>
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
    };

    #line 21 "src/compiler/FunctionContext.pv"
    if (self.use_scopes) {
        #line 22 "src/compiler/FunctionContext.pv"
        self.scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 23 "src/compiler/FunctionContext.pv"
        FunctionContext__push_scope(&self, false, false);
    }

    #line 26 "src/compiler/FunctionContext.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 27 "src/compiler/FunctionContext.pv"
        self.coroutine = FunctionCoroutine__new(allocator);
        #line 28 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 28 "src/compiler/FunctionContext.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 28 "src/compiler/FunctionContext.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 29 "src/compiler/FunctionContext.pv"
            FunctionContext__add_variable(&self, param->name->value, &param->type);
        } }
    }

    #line 33 "src/compiler/FunctionContext.pv"
    return self;
}

#line 36 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target) {
    #line 37 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__append(&self->scopes, FunctionScope__new(self->allocator, break_target, continue_target));
}

#line 40 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self) {
    #line 41 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__remove_back(&self->scopes);
}

#line 44 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name) {
    #line 45 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 45 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 45 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 46 "src/compiler/FunctionContext.pv"
        struct str* variable = HashMap_str_str__find(&scope->variable_replacements, &name);
        #line 47 "src/compiler/FunctionContext.pv"
        if (variable != 0) {
            #line 48 "src/compiler/FunctionContext.pv"
            return *variable;
        }
    } }

    #line 52 "src/compiler/FunctionContext.pv"
    return name;
}

#line 55 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type) {
    #line 56 "src/compiler/FunctionContext.pv"
    if (self->func_info->type != FUNCTION_TYPE__COROUTINE) {
        #line 57 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 60 "src/compiler/FunctionContext.pv"
    struct String new_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 61 "src/compiler/FunctionContext.pv"
    String__append(&new_name, name);

    #line 63 "src/compiler/FunctionContext.pv"
    if (HashMap_str_ref_Type__find(&self->coroutine.variables, &name) == 0) {
        #line 64 "src/compiler/FunctionContext.pv"
        HashMap_str_ref_Type__insert(&self->coroutine.variables, name, type);

        #line 66 "src/compiler/FunctionContext.pv"
        if (self->use_scopes) {
            #line 67 "src/compiler/FunctionContext.pv"
            struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
            #line 68 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 69 "src/compiler/FunctionContext.pv"
            HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
        }

        #line 72 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 75 "src/compiler/FunctionContext.pv"
    String__append(&new_name, (struct str){ .ptr = "_x", .length = strlen("_x") });
    #line 76 "src/compiler/FunctionContext.pv"
    int32_t i = 1;
    #line 77 "src/compiler/FunctionContext.pv"
    while (true) {
        #line 78 "src/compiler/FunctionContext.pv"
        if (i == 10) {
            #line 78 "src/compiler/FunctionContext.pv"
            String__append(&new_name, (struct str){ .ptr = "x", .length = strlen("x") });
        }
        #line 79 "src/compiler/FunctionContext.pv"
        if (i > 9) {
            #line 80 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 2] = '0' + (i / 10);
            #line 81 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + (i % 10);
        } else {
            #line 83 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + i;
        }

        #line 86 "src/compiler/FunctionContext.pv"
        struct str new_name_str = String__as_str(&new_name);
        #line 87 "src/compiler/FunctionContext.pv"
        if (HashMap_str_ref_Type__find(&self->coroutine.variables, &new_name_str) == 0) {
            #line 88 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 89 "src/compiler/FunctionContext.pv"
            new_name_str = String__as_str(&new_name);
            #line 90 "src/compiler/FunctionContext.pv"
            HashMap_str_ref_Type__insert(&self->coroutine.variables, str__slice(new_name_str, 5, new_name_str.length), type);

            #line 92 "src/compiler/FunctionContext.pv"
            if (self->use_scopes) {
                #line 93 "src/compiler/FunctionContext.pv"
                struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
                #line 94 "src/compiler/FunctionContext.pv"
                HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
            }
            #line 96 "src/compiler/FunctionContext.pv"
            return;
        }
        #line 98 "src/compiler/FunctionContext.pv"
        i += 1;
    }
}
