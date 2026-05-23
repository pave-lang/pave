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

#line 45 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context) {
    #line 46 "src/analyzer/types/Function.pv"
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
        .variadic = false,
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .body = 0,
    };
}

#line 63 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct trait_Allocator allocator) {
    #line 64 "src/analyzer/types/Function.pv"
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
        .variadic = false,
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .body = 0,
    };
}

#line 81 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context) {
    #line 82 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, false);
}

#line 85 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context) {
    #line 86 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, true);
}

#line 89 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional) {
    #line 90 "src/analyzer/types/Function.pv"
    struct Function node = Function__new(context);

    #line 92 "src/analyzer/types/Function.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "co")) {
        #line 93 "src/analyzer/types/Function.pv"
        node.type = FUNCTION_TYPE__COROUTINE;
    } else if (!Context__check_next(context, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 95 "src/analyzer/types/Function.pv"
        Context__error(context, "Expected fn or co keywords");
        #line 96 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 99 "src/analyzer/types/Function.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 100 "src/analyzer/types/Function.pv"
    if (name == 0) {
        #line 100 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 102 "src/analyzer/types/Function.pv"
    node.declaration_start = context->pos;

    #line 104 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 105 "src/analyzer/types/Function.pv"
        Context__next_token(context);
    }

    #line 108 "src/analyzer/types/Function.pv"
    if (body_optional && Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 109 "src/analyzer/types/Function.pv"
        node.declaration_end = context->pos - 1;
        #line 110 "src/analyzer/types/Function.pv"
        node.token_start = context->pos;
        #line 111 "src/analyzer/types/Function.pv"
        node.token_end = context->pos;
        #line 112 "src/analyzer/types/Function.pv"
        node.name = name;
        #line 113 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 116 "src/analyzer/types/Function.pv"
    if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 116 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 118 "src/analyzer/types/Function.pv"
    node.token_start = context->pos;
    #line 119 "src/analyzer/types/Function.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 119 "src/analyzer/types/Function.pv"
        return node;
    }
    #line 120 "src/analyzer/types/Function.pv"
    node.token_end = context->pos;
    #line 121 "src/analyzer/types/Function.pv"
    node.name = name;
    #line 122 "src/analyzer/types/Function.pv"
    return node;
}

#line 125 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics) {
    #line 126 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 127 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 127 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 128 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 128 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 130 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 131 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "...")) {
            #line 132 "src/analyzer/types/Function.pv"
            if (self->parameters.length == 0) {
                #line 133 "src/analyzer/types/Function.pv"
                Context__error_token(context, &context->tokens[context->pos - 1], "Variadic functions require at least one named parameter");
                #line 134 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 137 "src/analyzer/types/Function.pv"
            self->variadic = true;
            #line 138 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }

        #line 141 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "&")) {
            #line 142 "src/analyzer/types/Function.pv"
            struct Token* name = &context->tokens[context->pos];

            #line 144 "src/analyzer/types/Function.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "self")) {
                #line 145 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 148 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_self) },
                .name = name,
            };

            #line 153 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 154 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 157 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        } else {
            #line 159 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .name = Context__expect(context, TOKEN_TYPE__IDENTIFIER),
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            };

            #line 164 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 165 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 168 "src/analyzer/types/Function.pv"
            bool has_type = false;

            #line 170 "src/analyzer/types/Function.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 171 "src/analyzer/types/Function.pv"
                if (!Context__parse_type(context, &parameter.type, generics)) {
                    #line 171 "src/analyzer/types/Function.pv"
                    return false;
                }
                #line 172 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 175 "src/analyzer/types/Function.pv"
            if (!has_type && str__Eq_str__eq(&parameter.name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
                #line 176 "src/analyzer/types/Function.pv"
                parameter.type = (struct Type) { .type = TYPE__SELF };
                #line 177 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 180 "src/analyzer/types/Function.pv"
            if (!has_type) {
                #line 181 "src/analyzer/types/Function.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":");
                #line 182 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 185 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        }

        #line 188 "src/analyzer/types/Function.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 189 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }
    }

    #line 193 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 193 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 195 "src/analyzer/types/Function.pv"
    return true;
}

#line 198 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics) {
    #line 199 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 200 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 200 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 202 "src/analyzer/types/Function.pv"
    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "->")) {
        #line 203 "src/analyzer/types/Function.pv"
        self->return_type = context->root->type_void;
        #line 204 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 207 "src/analyzer/types/Function.pv"
    return Context__parse_type(context, &self->return_type, &self->generics);
}

#line 210 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics) {
    #line 211 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 213 "src/analyzer/types/Function.pv"
    if (self->context == 0) {
        #line 213 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 215 "src/analyzer/types/Function.pv"
    if (self->type == FUNCTION_TYPE__TEST) {
        #line 216 "src/analyzer/types/Function.pv"
        self->return_type = self->context->root->type_void;
        #line 217 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 220 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 221 "src/analyzer/types/Function.pv"
    context->pos = self->declaration_start;

    #line 223 "src/analyzer/types/Function.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 223 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 225 "src/analyzer/types/Function.pv"
    if (!Function__parse_parameters(self, &self->generics)) {
        #line 225 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 226 "src/analyzer/types/Function.pv"
    if (!Function__parse_return_type(self, &self->generics)) {
        #line 226 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 228 "src/analyzer/types/Function.pv"
    if (context->pos != self->declaration_end) {
        #line 229 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 232 "src/analyzer/types/Function.pv"
    return true;
}

#line 235 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics) {
    #line 236 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 238 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 239 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 239 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 240 "src/analyzer/types/Function.pv"
    context->pos = self->token_start;
    #line 241 "src/analyzer/types/Function.pv"
    struct Block* block = Block__new_ptr(context);
    #line 242 "src/analyzer/types/Function.pv"
    Context__push_scope(context, 0);
    #line 243 "src/analyzer/types/Function.pv"
    context->function = self;

    #line 245 "src/analyzer/types/Function.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&self->parameters);
    #line 245 "src/analyzer/types/Function.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 245 "src/analyzer/types/Function.pv"
        struct Parameter* param_info = Iter_ref_Parameter__value(&__iter);

        #line 246 "src/analyzer/types/Function.pv"
        if (!Context__set_value(context, param_info->name, &param_info->type)) {
            #line 246 "src/analyzer/types/Function.pv"
            Context__pop_scope(context);
            #line 246 "src/analyzer/types/Function.pv"
            return true;
        }
    } }

    #line 249 "src/analyzer/types/Function.pv"
    bool block_result = Block__parse(block, context, &self->generics, true);
    #line 250 "src/analyzer/types/Function.pv"
    if (!block_result) {
        #line 250 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 250 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 252 "src/analyzer/types/Function.pv"
    self->body = block;

    #line 254 "src/analyzer/types/Function.pv"
    if (context->pos != self->token_end) {
        #line 254 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 254 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 256 "src/analyzer/types/Function.pv"
    context->function = 0;
    #line 257 "src/analyzer/types/Function.pv"
    Context__pop_scope(context);
    #line 258 "src/analyzer/types/Function.pv"
    return false;
}
