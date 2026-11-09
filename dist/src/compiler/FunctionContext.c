#include <stdint.h>
#include <string.h>

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
#include <usize.h>
#include <std/String.h>
#include <compiler/FunctionTemp.h>
#include <std/HashMap_str_str.h>
#include <i32.h>
#include <std/Array_char.h>
#include <compiler/FunctionContext.h>

#include <compiler/FunctionContext.h>

#line 25 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new(struct ArenaAllocator* allocator, struct Function* func_info, bool use_scopes) {
    #line 26 "src/compiler/FunctionContext.pv"
    struct FunctionContext self = (struct FunctionContext) {
        .allocator = allocator,
        .func_info = func_info,
        .use_scopes = use_scopes,
        .scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .coroutine = (struct FunctionCoroutine) { .yield_count = 0, .variables = (struct HashMap_str_ref_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
        .temps = Array_FunctionTemp__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .temp_count = 0,
        .temps_enabled = false,
        .label_count = 0,
    };

    #line 38 "src/compiler/FunctionContext.pv"
    if (self.use_scopes) {
        #line 39 "src/compiler/FunctionContext.pv"
        self.scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 40 "src/compiler/FunctionContext.pv"
        FunctionContext__push_scope(&self, false, false);
    }

    #line 43 "src/compiler/FunctionContext.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 44 "src/compiler/FunctionContext.pv"
        self.coroutine = FunctionCoroutine__new(allocator);
        #line 45 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 45 "src/compiler/FunctionContext.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 45 "src/compiler/FunctionContext.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 46 "src/compiler/FunctionContext.pv"
            struct Token* name = param->name;
            #line 47 "src/compiler/FunctionContext.pv"
            if (name == 0) {
                #line 47 "src/compiler/FunctionContext.pv"
                continue;
            }
            #line 48 "src/compiler/FunctionContext.pv"
            FunctionContext__add_variable(&self, name->value, &param->type);
        } }
    }

    #line 52 "src/compiler/FunctionContext.pv"
    return self;
}

#line 55 "src/compiler/FunctionContext.pv"
struct FunctionContext FunctionContext__new_const(struct ArenaAllocator* allocator) {
    #line 56 "src/compiler/FunctionContext.pv"
    return (struct FunctionContext) {
        .allocator = allocator,
        .func_info = 0,
        .use_scopes = false,
        .scopes = Array_FunctionScope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .coroutine = (struct FunctionCoroutine) { .yield_count = 0, .variables = (struct HashMap_str_ref_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
        .temps = Array_FunctionTemp__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .temp_count = 0,
        .temps_enabled = false,
        .label_count = 0,
    };
}

#line 69 "src/compiler/FunctionContext.pv"
void FunctionContext__push_scope(struct FunctionContext* self, bool break_target, bool continue_target) {
    #line 70 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__append(&self->scopes, FunctionScope__new(self->allocator, break_target, continue_target));
}

#line 73 "src/compiler/FunctionContext.pv"
void FunctionContext__pop_scope(struct FunctionContext* self) {
    #line 74 "src/compiler/FunctionContext.pv"
    Array_FunctionScope__remove_back(&self->scopes);
}

#line 77 "src/compiler/FunctionContext.pv"
void FunctionContext__push_defer(struct FunctionContext* self, struct DeferStatement stmt) {
    #line 78 "src/compiler/FunctionContext.pv"
    struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
    #line 79 "src/compiler/FunctionContext.pv"
    if (scope == 0) {
        #line 79 "src/compiler/FunctionContext.pv"
        return;
    }
    #line 80 "src/compiler/FunctionContext.pv"
    Array_DeferStatement__append(&scope->defer_statements, stmt);
}

#line 83 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_all_defer_statements(struct FunctionContext* self) {
    #line 84 "src/compiler/FunctionContext.pv"
    struct Array_DeferStatement result = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 85 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 85 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 85 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 86 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&scope->defer_statements));
        #line 86 "src/compiler/FunctionContext.pv"
        while (Iter_ref_DeferStatement__next(&__iter)) {
            #line 86 "src/compiler/FunctionContext.pv"
            struct DeferStatement* stmt = Iter_ref_DeferStatement__value(&__iter);

            #line 87 "src/compiler/FunctionContext.pv"
            Array_DeferStatement__append(&result, *stmt);
        } }
    } }
    #line 90 "src/compiler/FunctionContext.pv"
    return result;
}

#line 94 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_continue_defer_statements(struct FunctionContext* self) {
    #line 95 "src/compiler/FunctionContext.pv"
    struct Array_DeferStatement result = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 96 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 96 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 96 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 97 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&scope->defer_statements));
        #line 97 "src/compiler/FunctionContext.pv"
        while (Iter_ref_DeferStatement__next(&__iter)) {
            #line 97 "src/compiler/FunctionContext.pv"
            struct DeferStatement* stmt = Iter_ref_DeferStatement__value(&__iter);

            #line 98 "src/compiler/FunctionContext.pv"
            Array_DeferStatement__append(&result, *stmt);
        } }
        #line 100 "src/compiler/FunctionContext.pv"
        if (scope->continue_target) {
            #line 100 "src/compiler/FunctionContext.pv"
            return result;
        }
    } }
    #line 102 "src/compiler/FunctionContext.pv"
    return result;
}

#line 109 "src/compiler/FunctionContext.pv"
struct Array_DeferStatement FunctionContext__get_break_defer_statements(struct FunctionContext* self, uintptr_t* label) {
    #line 110 "src/compiler/FunctionContext.pv"
    struct Array_DeferStatement result = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 111 "src/compiler/FunctionContext.pv"
    *label = 0;

    #line 113 "src/compiler/FunctionContext.pv"
    bool in_loop = false;
    #line 114 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Array_FunctionScope__iter(&self->scopes);
    #line 114 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 114 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 115 "src/compiler/FunctionContext.pv"
        if (scope->continue_target) {
            #line 115 "src/compiler/FunctionContext.pv"
            in_loop = true;
        }
    } }

    #line 118 "src/compiler/FunctionContext.pv"
    bool in_switch = false;
    #line 119 "src/compiler/FunctionContext.pv"
    uintptr_t i = self->scopes.length;
    #line 120 "src/compiler/FunctionContext.pv"
    while (i > 0) {
        #line 121 "src/compiler/FunctionContext.pv"
        i -= 1;
        #line 122 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = &self->scopes.data[i];
        #line 123 "src/compiler/FunctionContext.pv"
        { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&scope->defer_statements));
        #line 123 "src/compiler/FunctionContext.pv"
        while (Iter_ref_DeferStatement__next(&__iter)) {
            #line 123 "src/compiler/FunctionContext.pv"
            struct DeferStatement* stmt = Iter_ref_DeferStatement__value(&__iter);

            #line 124 "src/compiler/FunctionContext.pv"
            Array_DeferStatement__append(&result, *stmt);
        } }

        #line 127 "src/compiler/FunctionContext.pv"
        if (scope->continue_target) {
            #line 128 "src/compiler/FunctionContext.pv"
            if (in_switch) {
                #line 129 "src/compiler/FunctionContext.pv"
                if (usize__Eq_usize__eq(scope->break_label, 0)) {
                    #line 130 "src/compiler/FunctionContext.pv"
                    self->label_count += 1;
                    #line 131 "src/compiler/FunctionContext.pv"
                    scope->break_label = self->label_count;
                }
                #line 133 "src/compiler/FunctionContext.pv"
                *label = scope->break_label;
            }
            #line 135 "src/compiler/FunctionContext.pv"
            return result;
        }

        #line 138 "src/compiler/FunctionContext.pv"
        if (scope->break_target) {
            #line 139 "src/compiler/FunctionContext.pv"
            if (!in_loop) {
                #line 139 "src/compiler/FunctionContext.pv"
                return result;
            }
            #line 140 "src/compiler/FunctionContext.pv"
            in_switch = true;
        }
    }
    #line 143 "src/compiler/FunctionContext.pv"
    return result;
}

#line 147 "src/compiler/FunctionContext.pv"
struct str FunctionContext__make_temp_name(struct FunctionContext* self) {
    #line 148 "src/compiler/FunctionContext.pv"
    struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 149 "src/compiler/FunctionContext.pv"
    String__append(&name, (struct str){ .ptr = "__pave_tmp_", .length = strlen("__pave_tmp_") });
    #line 150 "src/compiler/FunctionContext.pv"
    String__append_usize(&name, self->temp_count);
    #line 151 "src/compiler/FunctionContext.pv"
    self->temp_count += 1;
    #line 152 "src/compiler/FunctionContext.pv"
    return String__as_str(&name);
}

#line 158 "src/compiler/FunctionContext.pv"
struct str FunctionContext__add_temp(struct FunctionContext* self, struct Type* type) {
    #line 159 "src/compiler/FunctionContext.pv"
    if (!self->temps_enabled) {
        #line 159 "src/compiler/FunctionContext.pv"
        return (struct str){ .ptr = "", .length = strlen("") };
    }

    #line 161 "src/compiler/FunctionContext.pv"
    struct str name = FunctionContext__make_temp_name(self);
    #line 162 "src/compiler/FunctionContext.pv"
    Array_FunctionTemp__append(&self->temps, (struct FunctionTemp) { .name = name, .type = type });
    #line 163 "src/compiler/FunctionContext.pv"
    FunctionContext__add_variable(self, name, type);
    #line 164 "src/compiler/FunctionContext.pv"
    return name;
}

#line 167 "src/compiler/FunctionContext.pv"
struct str FunctionContext__get_variable_replacement(struct FunctionContext* self, struct str name) {
    #line 168 "src/compiler/FunctionContext.pv"
    { struct Iter_ref_FunctionScope __iter = Iter_ref_FunctionScope__reverse(Array_FunctionScope__iter(&self->scopes));
    #line 168 "src/compiler/FunctionContext.pv"
    while (Iter_ref_FunctionScope__next(&__iter)) {
        #line 168 "src/compiler/FunctionContext.pv"
        struct FunctionScope* scope = Iter_ref_FunctionScope__value(&__iter);

        #line 169 "src/compiler/FunctionContext.pv"
        struct str* variable = HashMap_str_str__find(&scope->variable_replacements, &name);
        #line 170 "src/compiler/FunctionContext.pv"
        if (variable != 0) {
            #line 171 "src/compiler/FunctionContext.pv"
            return *variable;
        }
    } }

    #line 175 "src/compiler/FunctionContext.pv"
    return name;
}

#line 178 "src/compiler/FunctionContext.pv"
void FunctionContext__add_variable(struct FunctionContext* self, struct str name, struct Type* type) {
    #line 179 "src/compiler/FunctionContext.pv"
    struct Function* func_info = self->func_info;
    #line 180 "src/compiler/FunctionContext.pv"
    if (func_info == 0 || func_info->type != FUNCTION_TYPE__COROUTINE) {
        #line 180 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 182 "src/compiler/FunctionContext.pv"
    struct String new_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 183 "src/compiler/FunctionContext.pv"
    String__append(&new_name, name);

    #line 185 "src/compiler/FunctionContext.pv"
    if (HashMap_str_ref_Type__find(&self->coroutine.variables, &name) == 0) {
        #line 186 "src/compiler/FunctionContext.pv"
        HashMap_str_ref_Type__insert(&self->coroutine.variables, name, type);

        #line 188 "src/compiler/FunctionContext.pv"
        if (self->use_scopes) {
            #line 189 "src/compiler/FunctionContext.pv"
            struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
            #line 190 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });

            #line 192 "src/compiler/FunctionContext.pv"
            if (scope == 0) {
                #line 192 "src/compiler/FunctionContext.pv"
                return;
            }
            #line 193 "src/compiler/FunctionContext.pv"
            HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
        }

        #line 196 "src/compiler/FunctionContext.pv"
        return;
    }

    #line 199 "src/compiler/FunctionContext.pv"
    String__append(&new_name, (struct str){ .ptr = "_x", .length = strlen("_x") });
    #line 200 "src/compiler/FunctionContext.pv"
    int32_t i = 1;
    #line 201 "src/compiler/FunctionContext.pv"
    while (true) {
        #line 202 "src/compiler/FunctionContext.pv"
        if (i32__Eq_i32__eq(i, 10)) {
            #line 202 "src/compiler/FunctionContext.pv"
            String__append(&new_name, (struct str){ .ptr = "x", .length = strlen("x") });
        }
        #line 203 "src/compiler/FunctionContext.pv"
        if (i > 9) {
            #line 204 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 2] = '0' + (i / 10);
            #line 205 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + (i % 10);
        } else {
            #line 207 "src/compiler/FunctionContext.pv"
            new_name.array.data[String__length(&new_name) - 1] = '0' + i;
        }

        #line 210 "src/compiler/FunctionContext.pv"
        struct str new_name_str = String__as_str(&new_name);
        #line 211 "src/compiler/FunctionContext.pv"
        if (HashMap_str_ref_Type__find(&self->coroutine.variables, &new_name_str) == 0) {
            #line 212 "src/compiler/FunctionContext.pv"
            String__prepend(&new_name, (struct str){ .ptr = "ctx->", .length = strlen("ctx->") });
            #line 213 "src/compiler/FunctionContext.pv"
            new_name_str = String__as_str(&new_name);
            #line 214 "src/compiler/FunctionContext.pv"
            HashMap_str_ref_Type__insert(&self->coroutine.variables, str__slice(new_name_str, 5, new_name_str.length), type);

            #line 216 "src/compiler/FunctionContext.pv"
            if (self->use_scopes) {
                #line 217 "src/compiler/FunctionContext.pv"
                struct FunctionScope* scope = Array_FunctionScope__back(&self->scopes);
                #line 218 "src/compiler/FunctionContext.pv"
                if (scope == 0) {
                    #line 218 "src/compiler/FunctionContext.pv"
                    return;
                }
                #line 219 "src/compiler/FunctionContext.pv"
                HashMap_str_str__insert(&scope->variable_replacements, name, String__as_str(&new_name));
            }
            #line 221 "src/compiler/FunctionContext.pv"
            return;
        }
        #line 223 "src/compiler/FunctionContext.pv"
        i += 1;
    }
}
