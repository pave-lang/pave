#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Function.h>
#include <stdbool.h>
#include <std/Array_FunctionScope.h>
#include <compiler/FunctionScope.h>
#include <std/Allocator.h>
#include <std/Array_char.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/Parameter.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <std/str.h>
#include <analyzer/Type.h>
#include <analyzer/Token.h>
#include <analyzer/FunctionType.h>
#include <stdint.h>
#include <std/ArrayIter_ref_FunctionScope.h>
#include <std/HashMap_str_str.h>
#include <std/String.h>
#include <std/HashMap_str_ref_Type.h>

#include <compiler/FunctionContext.h>

#line 48 "src/compiler/Generator.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes) {
    #line 49 "src/compiler/Generator.pv"
    struct FunctionContext self = (struct FunctionContext) {
        .allocator = allocator,
        .func_info = func_info,
        .use_scopes = use_scopes,
        .scopes = Array_FunctionScope__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 56 "src/compiler/Generator.pv"
    if (self.use_scopes) {
        #line 57 "src/compiler/Generator.pv"
        self.scopes = Array_FunctionScope__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 58 "src/compiler/Generator.pv"
        FunctionContext__push_scope(&self, false, false);
    }

    #line 61 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 62 "src/compiler/Generator.pv"
        self.coroutine = FunctionCoroutine__new(allocator);
        #line 63 "src/compiler/Generator.pv"
        { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 63 "src/compiler/Generator.pv"
        while (ArrayIter_ref_Parameter__next(&__iter)) {
            #line 63 "src/compiler/Generator.pv"
            struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

            #line 64 "src/compiler/Generator.pv"
            FunctionContext__add_variable(&self, param->name->value, &param->type);
        } }
    }

    #line 68 "src/compiler/Generator.pv"
    return self;
}

#line 71 "src/compiler/Generator.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target) {
    #line 72 "src/compiler/Generator.pv"
    Array_FunctionScope__append(&self->scopes, FunctionScope__new(self->allocator, break_target, continue_target));
}

#line 75 "src/compiler/Generator.pv"
void FunctionContext__pop_scope(struct FunctionContext* self) {
    #line 76 "src/compiler/Generator.pv"
    Array_FunctionScope__remove_back(&self->scopes);
}

#line 79 "src/compiler/Generator.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name) {
    #line 80 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_FunctionScope __iter = ArrayIter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 80 "src/compiler/Generator.pv"
    while (ArrayIter_ref_FunctionScope__next(&__iter)) {
        #line 80 "src/compiler/Generator.pv"
        struct FunctionScope* scope = ArrayIter_ref_FunctionScope__value(&__iter);

        #line 81 "src/compiler/Generator.pv"
        struct str* variable = HashMap_str_str__find(&scope->variable_replacements, &name);
        #line 82 "src/compiler/Generator.pv"
        if (variable != 0) {
            #line 83 "src/compiler/Generator.pv"
            return *variable;
        }
    } }

    #line 87 "src/compiler/Generator.pv"
    return name;
}

#line 90 "src/compiler/Generator.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type) {
    #line 91 "src/compiler/Generator.pv"
    if (self->func_info->type != FUNCTION_TYPE__COROUTINE) {
        #line 92 "src/compiler/Generator.pv"
        return;
    }

    #line 95 "src/compiler/Generator.pv"
    struct String new_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 96 "src/compiler/Generator.pv"
    String__append(&new_name, name);

    #line 98 "src/compiler/Generator.pv"
    if (HashMap_str_ref_Type__find(&self->coroutine.variables, &name) == 0) {
        #line 99 "src/compiler/Generator.pv"
        HashMap_str_ref_Type__insert(&self->coroutine.variables, name, type);

        #line 101 "src/compiler/Generator.pv"
        if (self->use_scopes) {
            #line 102 "src/compiler/Generator.pv"
            struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
            #line 103 "src/compiler/Generator.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 104 "src/compiler/Generator.pv"
            HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
        }

        #line 107 "src/compiler/Generator.pv"
        return;
    }

    #line 110 "src/compiler/Generator.pv"
    String__append(&new_name, (struct str){ .ptr = "_x", .length = strlen("_x") });
    #line 111 "src/compiler/Generator.pv"
    int32_t i = 1;
    #line 112 "src/compiler/Generator.pv"
    while (true) {
        #line 113 "src/compiler/Generator.pv"
        if (i == 10) {
            #line 113 "src/compiler/Generator.pv"
            String__append(&new_name, (struct str){ .ptr = "x", .length = strlen("x") });
        }
        #line 114 "src/compiler/Generator.pv"
        if (i > 9) {
            #line 115 "src/compiler/Generator.pv"
            new_name.array.data[String__length(&new_name) - 2] = '0' + (i / 10);
            #line 116 "src/compiler/Generator.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + (i % 10);
        } else {
            #line 118 "src/compiler/Generator.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + i;
        }

        #line 121 "src/compiler/Generator.pv"
        struct str new_name_str = String__as_str(&new_name);
        #line 122 "src/compiler/Generator.pv"
        if (HashMap_str_ref_Type__find(&self->coroutine.variables, &new_name_str) == 0) {
            #line 123 "src/compiler/Generator.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 124 "src/compiler/Generator.pv"
            new_name_str = String__as_str(&new_name);
            #line 125 "src/compiler/Generator.pv"
            HashMap_str_ref_Type__insert(&self->coroutine.variables, str__slice(new_name_str, 5, new_name_str.length), type);

            #line 127 "src/compiler/Generator.pv"
            if (self->use_scopes) {
                #line 128 "src/compiler/Generator.pv"
                struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
                #line 129 "src/compiler/Generator.pv"
                HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
            }
            #line 131 "src/compiler/Generator.pv"
            return;
        }
        #line 133 "src/compiler/Generator.pv"
        i += 1;
    }
}
