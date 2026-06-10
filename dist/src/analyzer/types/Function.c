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
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/IndirectType.h>
#include <std/str.h>
#include <analyzer/Block.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Function.h>

#include <analyzer/types/Function.h>

#line 46 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context) {
    #line 47 "src/analyzer/types/Function.pv"
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
        .typed_variadic = false,
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .body = 0,
    };
}

#line 65 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct trait_Allocator allocator) {
    #line 66 "src/analyzer/types/Function.pv"
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
        .typed_variadic = false,
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .body = 0,
    };
}

#line 84 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context) {
    #line 85 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, false);
}

#line 88 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context) {
    #line 89 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, true);
}

#line 92 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional) {
    #line 93 "src/analyzer/types/Function.pv"
    struct Function node = Function__new(context);

    #line 95 "src/analyzer/types/Function.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "co")) {
        #line 96 "src/analyzer/types/Function.pv"
        node.type = FUNCTION_TYPE__COROUTINE;
    } else if (!Context__check_next(context, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 98 "src/analyzer/types/Function.pv"
        Context__error(context, "Expected fn or co keywords");
        #line 99 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 102 "src/analyzer/types/Function.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 103 "src/analyzer/types/Function.pv"
    if (name == 0) {
        #line 103 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 105 "src/analyzer/types/Function.pv"
    node.declaration_start = context->pos;

    #line 107 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 108 "src/analyzer/types/Function.pv"
        Context__next_token(context);
    }

    #line 111 "src/analyzer/types/Function.pv"
    if (body_optional && Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 112 "src/analyzer/types/Function.pv"
        node.declaration_end = context->pos;
        #line 113 "src/analyzer/types/Function.pv"
        Context__next_token(context);
        #line 114 "src/analyzer/types/Function.pv"
        node.token_start = context->pos;
        #line 115 "src/analyzer/types/Function.pv"
        node.token_end = context->pos;
        #line 116 "src/analyzer/types/Function.pv"
        node.name = name;
        #line 117 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 120 "src/analyzer/types/Function.pv"
    if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 120 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 122 "src/analyzer/types/Function.pv"
    node.token_start = context->pos;
    #line 123 "src/analyzer/types/Function.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 123 "src/analyzer/types/Function.pv"
        return node;
    }
    #line 124 "src/analyzer/types/Function.pv"
    node.token_end = context->pos;
    #line 125 "src/analyzer/types/Function.pv"
    node.name = name;
    #line 126 "src/analyzer/types/Function.pv"
    return node;
}

#line 129 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics) {
    #line 130 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 131 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 131 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 132 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 132 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 134 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 135 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "...")) {
            #line 136 "src/analyzer/types/Function.pv"
            if (self->parameters.length == 0) {
                #line 137 "src/analyzer/types/Function.pv"
                Context__error_token(context, &context->tokens[context->pos - 1], "Variadic functions require at least one named parameter");
                #line 138 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 141 "src/analyzer/types/Function.pv"
            self->variadic = true;
            #line 142 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }

        #line 145 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "&")) {
            #line 146 "src/analyzer/types/Function.pv"
            struct Token* name = &context->tokens[context->pos];

            #line 148 "src/analyzer/types/Function.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "self")) {
                #line 149 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 152 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_self) },
                .name = name,
            };

            #line 157 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 158 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 161 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        } else {
            #line 163 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .name = Context__expect(context, TOKEN_TYPE__IDENTIFIER),
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            };

            #line 168 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 169 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 172 "src/analyzer/types/Function.pv"
            bool has_type = false;

            #line 174 "src/analyzer/types/Function.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 175 "src/analyzer/types/Function.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "...")) {
                    #line 176 "src/analyzer/types/Function.pv"
                    if (self->variadic) {
                        #line 177 "src/analyzer/types/Function.pv"
                        Context__error_token(context, parameter.name, "Only one variadic parameter is allowed");
                        #line 178 "src/analyzer/types/Function.pv"
                        return false;
                    }

                    #line 181 "src/analyzer/types/Function.pv"
                    struct Type element_type;
                    #line 182 "src/analyzer/types/Function.pv"
                    if (!Context__parse_type(context, &element_type, generics)) {
                        #line 182 "src/analyzer/types/Function.pv"
                        return false;
                    }

                    #line 184 "src/analyzer/types/Function.pv"
                    struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) {
                        .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                        .element = element_type,
                        .element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = element_type }}) },
                    }});
                    #line 189 "src/analyzer/types/Function.pv"
                    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
                    #line 190 "src/analyzer/types/Function.pv"
                    parameter.type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, sequence_type) };
                    #line 191 "src/analyzer/types/Function.pv"
                    self->variadic = true;
                    #line 192 "src/analyzer/types/Function.pv"
                    self->typed_variadic = true;
                } else {
                    #line 194 "src/analyzer/types/Function.pv"
                    if (!Context__parse_type(context, &parameter.type, generics)) {
                        #line 194 "src/analyzer/types/Function.pv"
                        return false;
                    }
                }
                #line 196 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 199 "src/analyzer/types/Function.pv"
            if (!has_type && str__Eq_str__eq(&parameter.name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
                #line 200 "src/analyzer/types/Function.pv"
                parameter.type = (struct Type) { .type = TYPE__SELF };
                #line 201 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 204 "src/analyzer/types/Function.pv"
            if (!has_type) {
                #line 205 "src/analyzer/types/Function.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":");
                #line 206 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 209 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        }

        #line 212 "src/analyzer/types/Function.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 213 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        } else if (self->typed_variadic) {
            #line 215 "src/analyzer/types/Function.pv"
            Context__error_token(context, &context->tokens[context->pos - 1], "Typed variadic parameter must be last");
            #line 216 "src/analyzer/types/Function.pv"
            return false;
        }
    }

    #line 220 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 220 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 222 "src/analyzer/types/Function.pv"
    return true;
}

#line 225 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics) {
    #line 226 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 227 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 227 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 229 "src/analyzer/types/Function.pv"
    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "->")) {
        #line 230 "src/analyzer/types/Function.pv"
        self->return_type = context->root->type_void;
        #line 231 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 234 "src/analyzer/types/Function.pv"
    return Context__parse_type(context, &self->return_type, &self->generics);
}

#line 237 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics) {
    #line 238 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 240 "src/analyzer/types/Function.pv"
    if (self->context == 0) {
        #line 240 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 242 "src/analyzer/types/Function.pv"
    if (self->type == FUNCTION_TYPE__TEST) {
        #line 243 "src/analyzer/types/Function.pv"
        self->return_type = self->context->root->type_void;
        #line 244 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 247 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 248 "src/analyzer/types/Function.pv"
    context->pos = self->declaration_start;

    #line 250 "src/analyzer/types/Function.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 250 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 252 "src/analyzer/types/Function.pv"
    if (!Function__parse_parameters(self, &self->generics)) {
        #line 252 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 253 "src/analyzer/types/Function.pv"
    if (!Function__parse_return_type(self, &self->generics)) {
        #line 253 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 255 "src/analyzer/types/Function.pv"
    if (context->pos != self->declaration_end) {
        #line 256 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 259 "src/analyzer/types/Function.pv"
    return true;
}

#line 262 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics) {
    #line 263 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 265 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 266 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 266 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 267 "src/analyzer/types/Function.pv"
    context->pos = self->token_start;
    #line 268 "src/analyzer/types/Function.pv"
    struct Block* block = Block__new_ptr(context);
    #line 269 "src/analyzer/types/Function.pv"
    Context__push_scope(context, 0);
    #line 270 "src/analyzer/types/Function.pv"
    context->function = self;

    #line 272 "src/analyzer/types/Function.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&self->parameters);
    #line 272 "src/analyzer/types/Function.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 272 "src/analyzer/types/Function.pv"
        struct Parameter* param_info = Iter_ref_Parameter__value(&__iter);

        #line 273 "src/analyzer/types/Function.pv"
        if (!Context__set_value(context, param_info->name, &param_info->type)) {
            #line 273 "src/analyzer/types/Function.pv"
            Context__pop_scope(context);
            #line 273 "src/analyzer/types/Function.pv"
            return true;
        }
    } }

    #line 276 "src/analyzer/types/Function.pv"
    bool block_result = Block__parse(block, context, &self->generics, true);
    #line 277 "src/analyzer/types/Function.pv"
    if (!block_result) {
        #line 277 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 277 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 279 "src/analyzer/types/Function.pv"
    self->body = block;

    #line 281 "src/analyzer/types/Function.pv"
    if (context->pos != self->token_end) {
        #line 281 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 281 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 283 "src/analyzer/types/Function.pv"
    context->function = 0;
    #line 284 "src/analyzer/types/Function.pv"
    Context__pop_scope(context);
    #line 285 "src/analyzer/types/Function.pv"
    return false;
}
