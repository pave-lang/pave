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
    if (body_optional && Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 112 "src/analyzer/types/Function.pv"
        node.declaration_end = context->pos - 1;
        #line 113 "src/analyzer/types/Function.pv"
        node.token_start = context->pos;
        #line 114 "src/analyzer/types/Function.pv"
        node.token_end = context->pos;
        #line 115 "src/analyzer/types/Function.pv"
        node.name = name;
        #line 116 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 119 "src/analyzer/types/Function.pv"
    if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 119 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 121 "src/analyzer/types/Function.pv"
    node.token_start = context->pos;
    #line 122 "src/analyzer/types/Function.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 122 "src/analyzer/types/Function.pv"
        return node;
    }
    #line 123 "src/analyzer/types/Function.pv"
    node.token_end = context->pos;
    #line 124 "src/analyzer/types/Function.pv"
    node.name = name;
    #line 125 "src/analyzer/types/Function.pv"
    return node;
}

#line 128 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics) {
    #line 129 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 130 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 130 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 131 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 131 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 133 "src/analyzer/types/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 134 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "...")) {
            #line 135 "src/analyzer/types/Function.pv"
            if (self->parameters.length == 0) {
                #line 136 "src/analyzer/types/Function.pv"
                Context__error_token(context, &context->tokens[context->pos - 1], "Variadic functions require at least one named parameter");
                #line 137 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 140 "src/analyzer/types/Function.pv"
            self->variadic = true;
            #line 141 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }

        #line 144 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "&")) {
            #line 145 "src/analyzer/types/Function.pv"
            struct Token* name = &context->tokens[context->pos];

            #line 147 "src/analyzer/types/Function.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "self")) {
                #line 148 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 151 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_self) },
                .name = name,
            };

            #line 156 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 157 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 160 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        } else {
            #line 162 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .name = Context__expect(context, TOKEN_TYPE__IDENTIFIER),
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            };

            #line 167 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 168 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 171 "src/analyzer/types/Function.pv"
            bool has_type = false;

            #line 173 "src/analyzer/types/Function.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 174 "src/analyzer/types/Function.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "...")) {
                    #line 175 "src/analyzer/types/Function.pv"
                    if (self->variadic) {
                        #line 176 "src/analyzer/types/Function.pv"
                        Context__error_token(context, parameter.name, "Only one variadic parameter is allowed");
                        #line 177 "src/analyzer/types/Function.pv"
                        return false;
                    }

                    #line 180 "src/analyzer/types/Function.pv"
                    struct Type element_type;
                    #line 181 "src/analyzer/types/Function.pv"
                    if (!Context__parse_type(context, &element_type, generics)) {
                        #line 181 "src/analyzer/types/Function.pv"
                        return false;
                    }

                    #line 183 "src/analyzer/types/Function.pv"
                    struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) {
                        .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                        .element = element_type,
                        .element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = element_type }}) },
                    }});
                    #line 188 "src/analyzer/types/Function.pv"
                    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
                    #line 189 "src/analyzer/types/Function.pv"
                    parameter.type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, sequence_type) };
                    #line 190 "src/analyzer/types/Function.pv"
                    self->variadic = true;
                    #line 191 "src/analyzer/types/Function.pv"
                    self->typed_variadic = true;
                } else {
                    #line 193 "src/analyzer/types/Function.pv"
                    if (!Context__parse_type(context, &parameter.type, generics)) {
                        #line 193 "src/analyzer/types/Function.pv"
                        return false;
                    }
                }
                #line 195 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 198 "src/analyzer/types/Function.pv"
            if (!has_type && str__Eq_str__eq(&parameter.name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
                #line 199 "src/analyzer/types/Function.pv"
                parameter.type = (struct Type) { .type = TYPE__SELF };
                #line 200 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 203 "src/analyzer/types/Function.pv"
            if (!has_type) {
                #line 204 "src/analyzer/types/Function.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":");
                #line 205 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 208 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        }

        #line 211 "src/analyzer/types/Function.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 212 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        } else if (self->typed_variadic) {
            #line 214 "src/analyzer/types/Function.pv"
            Context__error_token(context, &context->tokens[context->pos - 1], "Typed variadic parameter must be last");
            #line 215 "src/analyzer/types/Function.pv"
            return false;
        }
    }

    #line 219 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 219 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 221 "src/analyzer/types/Function.pv"
    return true;
}

#line 224 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics) {
    #line 225 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 226 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 226 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 228 "src/analyzer/types/Function.pv"
    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "->")) {
        #line 229 "src/analyzer/types/Function.pv"
        self->return_type = context->root->type_void;
        #line 230 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 233 "src/analyzer/types/Function.pv"
    return Context__parse_type(context, &self->return_type, &self->generics);
}

#line 236 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics) {
    #line 237 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 239 "src/analyzer/types/Function.pv"
    if (self->context == 0) {
        #line 239 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 241 "src/analyzer/types/Function.pv"
    if (self->type == FUNCTION_TYPE__TEST) {
        #line 242 "src/analyzer/types/Function.pv"
        self->return_type = self->context->root->type_void;
        #line 243 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 246 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 247 "src/analyzer/types/Function.pv"
    context->pos = self->declaration_start;

    #line 249 "src/analyzer/types/Function.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 249 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 251 "src/analyzer/types/Function.pv"
    if (!Function__parse_parameters(self, &self->generics)) {
        #line 251 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 252 "src/analyzer/types/Function.pv"
    if (!Function__parse_return_type(self, &self->generics)) {
        #line 252 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 254 "src/analyzer/types/Function.pv"
    if (context->pos != self->declaration_end) {
        #line 255 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 258 "src/analyzer/types/Function.pv"
    return true;
}

#line 261 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics) {
    #line 262 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 264 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 265 "src/analyzer/types/Function.pv"
    if (context == 0) {
        #line 265 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 266 "src/analyzer/types/Function.pv"
    context->pos = self->token_start;
    #line 267 "src/analyzer/types/Function.pv"
    struct Block* block = Block__new_ptr(context);
    #line 268 "src/analyzer/types/Function.pv"
    Context__push_scope(context, 0);
    #line 269 "src/analyzer/types/Function.pv"
    context->function = self;

    #line 271 "src/analyzer/types/Function.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&self->parameters);
    #line 271 "src/analyzer/types/Function.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 271 "src/analyzer/types/Function.pv"
        struct Parameter* param_info = Iter_ref_Parameter__value(&__iter);

        #line 272 "src/analyzer/types/Function.pv"
        if (!Context__set_value(context, param_info->name, &param_info->type)) {
            #line 272 "src/analyzer/types/Function.pv"
            Context__pop_scope(context);
            #line 272 "src/analyzer/types/Function.pv"
            return true;
        }
    } }

    #line 275 "src/analyzer/types/Function.pv"
    bool block_result = Block__parse(block, context, &self->generics, true);
    #line 276 "src/analyzer/types/Function.pv"
    if (!block_result) {
        #line 276 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 276 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 278 "src/analyzer/types/Function.pv"
    self->body = block;

    #line 280 "src/analyzer/types/Function.pv"
    if (context->pos != self->token_end) {
        #line 280 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 280 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 282 "src/analyzer/types/Function.pv"
    context->function = 0;
    #line 283 "src/analyzer/types/Function.pv"
    Context__pop_scope(context);
    #line 284 "src/analyzer/types/Function.pv"
    return false;
}
