#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <analyzer/types/Function.h>
#include <analyzer/Context.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/Block.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Function.h>

#include <analyzer/types/Function.h>

#line 44 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context) {
    #line 45 "src/analyzer/types/Function.pv"
    return (struct Function) {
        .context = context,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .parameters = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .name = 0,
        .declaration_start = 0,
        .declaration_end = 0,
        .token_start = 0,
        .token_end = 0,
        .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE },
        .type = FUNCTION_TYPE__STANDARD,
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .body = 0,
    };
}

#line 61 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct trait_Allocator allocator) {
    #line 62 "src/analyzer/types/Function.pv"
    return (struct Function) {
        .generics = Generics__new(allocator),
        .parameters = Array_Parameter__new(allocator),
        .name = 0,
        .context = 0,
        .declaration_start = 0,
        .declaration_end = 0,
        .token_start = 0,
        .token_end = 0,
        .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE },
        .type = FUNCTION_TYPE__STANDARD,
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .body = 0,
    };
}

#line 78 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context) {
    #line 79 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, false);
}

#line 82 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context) {
    #line 83 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, true);
}

#line 86 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional) {
    #line 87 "src/analyzer/types/Function.pv"
    struct Function node = Function__new(context);

    #line 89 "src/analyzer/types/Function.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "co")) {
        #line 90 "src/analyzer/types/Function.pv"
        node.type = FUNCTION_TYPE__COROUTINE;
    } else if (!Context__check_next(context, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 92 "src/analyzer/types/Function.pv"
        Context__error(context, "Expected fn or co keywords");
        #line 93 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 96 "src/analyzer/types/Function.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 97 "src/analyzer/types/Function.pv"
    if (name == 0) {
        #line 97 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 99 "src/analyzer/types/Function.pv"
    node.declaration_start = context->pos;

    #line 101 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 102 "src/analyzer/types/Function.pv"
        Context__next_token(context);
    }

    #line 105 "src/analyzer/types/Function.pv"
    if (body_optional && Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 106 "src/analyzer/types/Function.pv"
        node.declaration_end = context->pos - 1;
        #line 107 "src/analyzer/types/Function.pv"
        node.token_start = context->pos;
        #line 108 "src/analyzer/types/Function.pv"
        node.token_end = context->pos;
        #line 109 "src/analyzer/types/Function.pv"
        node.name = name;
        #line 110 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 113 "src/analyzer/types/Function.pv"
    if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 113 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 115 "src/analyzer/types/Function.pv"
    node.token_start = context->pos;
    #line 116 "src/analyzer/types/Function.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 116 "src/analyzer/types/Function.pv"
        return node;
    }
    #line 117 "src/analyzer/types/Function.pv"
    node.token_end = context->pos;
    #line 118 "src/analyzer/types/Function.pv"
    node.name = name;
    #line 119 "src/analyzer/types/Function.pv"
    return node;
}

#line 122 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics) {
    #line 123 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 124 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 124 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 126 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 127 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "&")) {
            #line 128 "src/analyzer/types/Function.pv"
            struct Token* name = &context->tokens[context->pos];

            #line 130 "src/analyzer/types/Function.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "self")) {
                #line 131 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 134 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_self) },
                .name = name,
            };

            #line 139 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 140 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 143 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        } else {
            #line 145 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .name = Context__expect(context, TOKEN_TYPE__IDENTIFIER),
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            };

            #line 150 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 151 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 154 "src/analyzer/types/Function.pv"
            bool has_type = false;

            #line 156 "src/analyzer/types/Function.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 157 "src/analyzer/types/Function.pv"
                if (!Context__parse_type(context, &parameter.type, generics)) {
                    #line 157 "src/analyzer/types/Function.pv"
                    return false;
                }
                #line 158 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 161 "src/analyzer/types/Function.pv"
            if (!has_type && str__eq(parameter.name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
                #line 162 "src/analyzer/types/Function.pv"
                parameter.type = (struct Type) { .type = TYPE__SELF };
                #line 163 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 166 "src/analyzer/types/Function.pv"
            if (!has_type) {
                #line 167 "src/analyzer/types/Function.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":");
                #line 168 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 171 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        }

        #line 174 "src/analyzer/types/Function.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 175 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }
    }

    #line 179 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 179 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 181 "src/analyzer/types/Function.pv"
    return true;
}

#line 184 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics) {
    #line 185 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;

    #line 187 "src/analyzer/types/Function.pv"
    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "->")) {
        #line 188 "src/analyzer/types/Function.pv"
        self->return_type = self->context->root->type_void;
        #line 189 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 192 "src/analyzer/types/Function.pv"
    return Context__parse_type(context, &self->return_type, &self->generics);
}

#line 195 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics) {
    #line 196 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 198 "src/analyzer/types/Function.pv"
    if (self->type == FUNCTION_TYPE__TEST) {
        #line 199 "src/analyzer/types/Function.pv"
        self->return_type = self->context->root->type_void;
        #line 200 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 203 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 204 "src/analyzer/types/Function.pv"
    context->pos = self->declaration_start;

    #line 206 "src/analyzer/types/Function.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 206 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 208 "src/analyzer/types/Function.pv"
    if (!Function__parse_parameters(self, &self->generics)) {
        #line 208 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 209 "src/analyzer/types/Function.pv"
    if (!Function__parse_return_type(self, &self->generics)) {
        #line 209 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 211 "src/analyzer/types/Function.pv"
    if (context->pos != self->declaration_end) {
        #line 212 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 215 "src/analyzer/types/Function.pv"
    return true;
}

#line 218 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics) {
    #line 219 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 221 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 222 "src/analyzer/types/Function.pv"
    context->pos = self->token_start;
    #line 223 "src/analyzer/types/Function.pv"
    struct Block* block = Block__new_ptr(context);
    #line 224 "src/analyzer/types/Function.pv"
    Context__push_scope(context, 0);
    #line 225 "src/analyzer/types/Function.pv"
    context->function = self;

    #line 227 "src/analyzer/types/Function.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&self->parameters);
    #line 227 "src/analyzer/types/Function.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 227 "src/analyzer/types/Function.pv"
        struct Parameter* param_info = Iter_ref_Parameter__value(&__iter);

        #line 228 "src/analyzer/types/Function.pv"
        if (!Context__set_value(context, param_info->name, &param_info->type)) {
            #line 228 "src/analyzer/types/Function.pv"
            Context__pop_scope(context);
            #line 228 "src/analyzer/types/Function.pv"
            return true;
        }
    } }

    #line 231 "src/analyzer/types/Function.pv"
    bool block_result = Block__parse(block, context, &self->generics, true);
    #line 232 "src/analyzer/types/Function.pv"
    if (!block_result) {
        #line 232 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 232 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 234 "src/analyzer/types/Function.pv"
    self->body = block;

    #line 236 "src/analyzer/types/Function.pv"
    if (context->pos != self->token_end) {
        #line 236 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 236 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 238 "src/analyzer/types/Function.pv"
    context->function = 0;
    #line 239 "src/analyzer/types/Function.pv"
    Context__pop_scope(context);
    #line 240 "src/analyzer/types/Function.pv"
    return false;
}
