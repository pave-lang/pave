#include <stdio.h>

#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <stdbool.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/Block.h>

#include <analyzer/types/Function.h>

#line 43 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context) {
    #line 44 "src/analyzer/types/Function.pv"
    return (struct Function) {
        .context = context,
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .parameters = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 51 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct Allocator allocator) {
    #line 52 "src/analyzer/types/Function.pv"
    return (struct Function) {
        .generics = Generics__new(allocator),
        .parameters = Array_Parameter__new(allocator),
    };
}

#line 58 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context) {
    #line 59 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, false);
}

#line 62 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context) {
    #line 63 "src/analyzer/types/Function.pv"
    return Function__parse_inner(context, true);
}

#line 66 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional) {
    #line 67 "src/analyzer/types/Function.pv"
    struct Function node = Function__new(context);

    #line 69 "src/analyzer/types/Function.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "co")) {
        #line 70 "src/analyzer/types/Function.pv"
        node.type = FUNCTION_TYPE__COROUTINE;
    } else if (!Context__check_next(context, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 72 "src/analyzer/types/Function.pv"
        Context__error(context, "Expected fn or co keywords");
        #line 73 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 76 "src/analyzer/types/Function.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 77 "src/analyzer/types/Function.pv"
    if (name == 0) {
        #line 77 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 79 "src/analyzer/types/Function.pv"
    node.declaration_start = context->pos;

    #line 81 "src/analyzer/types/Function.pv"
    while ((context->pos < context->length) && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 82 "src/analyzer/types/Function.pv"
        Context__next_token(context);
    }

    #line 85 "src/analyzer/types/Function.pv"
    if (body_optional && Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 86 "src/analyzer/types/Function.pv"
        node.declaration_end = context->pos - 1;
        #line 87 "src/analyzer/types/Function.pv"
        node.token_start = context->pos;
        #line 88 "src/analyzer/types/Function.pv"
        node.token_end = context->pos;
        #line 89 "src/analyzer/types/Function.pv"
        node.name = name;
        #line 90 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 93 "src/analyzer/types/Function.pv"
    if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 93 "src/analyzer/types/Function.pv"
        return node;
    }

    #line 95 "src/analyzer/types/Function.pv"
    node.token_start = context->pos;
    #line 96 "src/analyzer/types/Function.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 96 "src/analyzer/types/Function.pv"
        return node;
    }
    #line 97 "src/analyzer/types/Function.pv"
    node.token_end = context->pos;
    #line 98 "src/analyzer/types/Function.pv"
    node.name = name;
    #line 99 "src/analyzer/types/Function.pv"
    return node;
}

#line 102 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics) {
    #line 103 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 104 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 104 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 106 "src/analyzer/types/Function.pv"
    while ((context->pos < context->length) && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 107 "src/analyzer/types/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "&")) {
            #line 108 "src/analyzer/types/Function.pv"
            struct Token* name = &context->tokens[context->pos];

            #line 110 "src/analyzer/types/Function.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "self")) {
                #line 111 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 114 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_self) },
                .name = name,
            };

            #line 119 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 120 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 123 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        } else {
            #line 125 "src/analyzer/types/Function.pv"
            struct Parameter parameter = (struct Parameter) { .name = Context__expect(context, TOKEN_TYPE__IDENTIFIER) };

            #line 129 "src/analyzer/types/Function.pv"
            if (parameter.name == 0) {
                #line 130 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 133 "src/analyzer/types/Function.pv"
            bool has_type = false;

            #line 135 "src/analyzer/types/Function.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 136 "src/analyzer/types/Function.pv"
                if (!Context__parse_type(context, &parameter.type, generics)) {
                    #line 136 "src/analyzer/types/Function.pv"
                    return false;
                }
                #line 137 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 140 "src/analyzer/types/Function.pv"
            if (!has_type && str__eq(parameter.name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
                #line 141 "src/analyzer/types/Function.pv"
                parameter.type = (struct Type) { .type = TYPE__SELF };
                #line 142 "src/analyzer/types/Function.pv"
                has_type = true;
            }

            #line 145 "src/analyzer/types/Function.pv"
            if (!has_type) {
                #line 146 "src/analyzer/types/Function.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":");
                #line 147 "src/analyzer/types/Function.pv"
                return false;
            }

            #line 150 "src/analyzer/types/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        }

        #line 153 "src/analyzer/types/Function.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 154 "src/analyzer/types/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }
    }

    #line 158 "src/analyzer/types/Function.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 158 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 160 "src/analyzer/types/Function.pv"
    return true;
}

#line 163 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics) {
    #line 164 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;

    #line 166 "src/analyzer/types/Function.pv"
    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "->")) {
        #line 166 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 168 "src/analyzer/types/Function.pv"
    return Context__parse_type(context, &self->return_type, &self->generics);
}

#line 171 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics) {
    #line 172 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 174 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 175 "src/analyzer/types/Function.pv"
    context->pos = self->declaration_start;

    #line 177 "src/analyzer/types/Function.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 177 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 179 "src/analyzer/types/Function.pv"
    if (!Function__parse_parameters(self, &self->generics)) {
        #line 179 "src/analyzer/types/Function.pv"
        return false;
    }
    #line 180 "src/analyzer/types/Function.pv"
    if (!Function__parse_return_type(self, &self->generics)) {
        #line 180 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 182 "src/analyzer/types/Function.pv"
    if (context->pos != self->declaration_end) {
        #line 183 "src/analyzer/types/Function.pv"
        return false;
    }

    #line 186 "src/analyzer/types/Function.pv"
    return true;
}

#line 189 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics) {
    #line 190 "src/analyzer/types/Function.pv"
    self->generics.parent = generics;

    #line 192 "src/analyzer/types/Function.pv"
    struct Context* context = self->context;
    #line 193 "src/analyzer/types/Function.pv"
    context->pos = self->token_start;
    #line 194 "src/analyzer/types/Function.pv"
    struct Block* block = Block__new_ptr(context);
    #line 195 "src/analyzer/types/Function.pv"
    Context__push_scope(context, 0);
    #line 196 "src/analyzer/types/Function.pv"
    context->function = self;

    #line 198 "src/analyzer/types/Function.pv"
    { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&self->parameters);
    #line 198 "src/analyzer/types/Function.pv"
    while (ArrayIter_ref_Parameter__next(&__iter)) {
        #line 198 "src/analyzer/types/Function.pv"
        struct Parameter* param_info = ArrayIter_ref_Parameter__value(&__iter);

        #line 199 "src/analyzer/types/Function.pv"
        if (!Context__set_value(context, param_info->name, &param_info->type)) {
            #line 199 "src/analyzer/types/Function.pv"
            Context__pop_scope(context);
            #line 199 "src/analyzer/types/Function.pv"
            return true;
        }
    } }

    #line 202 "src/analyzer/types/Function.pv"
    bool block_result = Block__parse(block, context, &self->generics, true);
    #line 203 "src/analyzer/types/Function.pv"
    if (!block_result) {
        #line 203 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 203 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 205 "src/analyzer/types/Function.pv"
    self->body = block;

    #line 207 "src/analyzer/types/Function.pv"
    if (context->pos != self->token_end) {
        #line 207 "src/analyzer/types/Function.pv"
        Context__pop_scope(context);
        #line 207 "src/analyzer/types/Function.pv"
        return true;
    }

    #line 209 "src/analyzer/types/Function.pv"
    context->function = 0;
    #line 210 "src/analyzer/types/Function.pv"
    Context__pop_scope(context);
    #line 211 "src/analyzer/types/Function.pv"
    return false;
}
