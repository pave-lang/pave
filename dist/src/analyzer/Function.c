#include <stdio.h>

#include <analyzer/Context.h>
#include <analyzer/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_Parameter.h>
#include <analyzer/Parameter.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <stdbool.h>
#include <analyzer/FunctionType.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <analyzer/Type.h>
#include <analyzer/Indirect.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/Block.h>

#include <analyzer/Function.h>

#line 42 "src/analyzer/Function.pv"
struct Function Function__new(struct Context* context) {
    #line 43 "src/analyzer/Function.pv"
    return (struct Function) {
        .context = context,
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .parameters = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 50 "src/analyzer/Function.pv"
struct Function Function__new_allocator(struct Allocator allocator) {
    #line 51 "src/analyzer/Function.pv"
    return (struct Function) {
        .generics = Generics__new(allocator),
        .parameters = Array_Parameter__new(allocator),
    };
}

#line 57 "src/analyzer/Function.pv"
struct Function Function__parse(struct Context* context) {
    #line 58 "src/analyzer/Function.pv"
    return Function__parse_inner(context, false);
}

#line 61 "src/analyzer/Function.pv"
struct Function Function__parse_optional_body(struct Context* context) {
    #line 62 "src/analyzer/Function.pv"
    return Function__parse_inner(context, true);
}

#line 65 "src/analyzer/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional) {
    #line 66 "src/analyzer/Function.pv"
    struct Function node = Function__new(context);

    #line 68 "src/analyzer/Function.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "co")) {
        #line 69 "src/analyzer/Function.pv"
        node.type = FUNCTION_TYPE__COROUTINE;
    } else if (!Context__check_next(context, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 71 "src/analyzer/Function.pv"
        Context__error(context, "Expected fn or co keywords");
        #line 72 "src/analyzer/Function.pv"
        return node;
    }

    #line 75 "src/analyzer/Function.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 76 "src/analyzer/Function.pv"
    if (name == 0) {
        #line 76 "src/analyzer/Function.pv"
        return node;
    }

    #line 78 "src/analyzer/Function.pv"
    node.declaration_start = context->pos;

    #line 80 "src/analyzer/Function.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 81 "src/analyzer/Function.pv"
        Context__next_token(context);
    }

    #line 84 "src/analyzer/Function.pv"
    if (body_optional && Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 85 "src/analyzer/Function.pv"
        node.declaration_end = context->pos - 1;
        #line 86 "src/analyzer/Function.pv"
        node.token_start = context->pos;
        #line 87 "src/analyzer/Function.pv"
        node.token_end = context->pos;
        #line 88 "src/analyzer/Function.pv"
        node.name = name;
        #line 89 "src/analyzer/Function.pv"
        return node;
    }

    #line 92 "src/analyzer/Function.pv"
    if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 92 "src/analyzer/Function.pv"
        return node;
    }

    #line 94 "src/analyzer/Function.pv"
    node.token_start = context->pos;
    #line 95 "src/analyzer/Function.pv"
    if (Context__skip_brackets(context, "{", "}") == 0) {
        #line 95 "src/analyzer/Function.pv"
        return node;
    }
    #line 96 "src/analyzer/Function.pv"
    node.token_end = context->pos;
    #line 97 "src/analyzer/Function.pv"
    node.name = name;
    #line 98 "src/analyzer/Function.pv"
    return node;
}

#line 101 "src/analyzer/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics) {
    #line 102 "src/analyzer/Function.pv"
    struct Context* context = self->context;
    #line 103 "src/analyzer/Function.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
        #line 103 "src/analyzer/Function.pv"
        return 0;
    }

    #line 105 "src/analyzer/Function.pv"
    while (context->pos < context->length && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
        #line 106 "src/analyzer/Function.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "&")) {
            #line 107 "src/analyzer/Function.pv"
            struct Token* name = &context->tokens[context->pos];

            #line 109 "src/analyzer/Function.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "self")) {
                #line 110 "src/analyzer/Function.pv"
                return false;
            }

            #line 113 "src/analyzer/Function.pv"
            struct Parameter parameter = (struct Parameter) {
                .type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_self) },
                .name = name,
            };

            #line 118 "src/analyzer/Function.pv"
            if (parameter.name == 0) {
                #line 119 "src/analyzer/Function.pv"
                return false;
            }

            #line 122 "src/analyzer/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        } else {
            #line 124 "src/analyzer/Function.pv"
            struct Parameter parameter = (struct Parameter) { .name = Context__expect(context, TOKEN_TYPE__IDENTIFIER) };

            #line 128 "src/analyzer/Function.pv"
            if (parameter.name == 0) {
                #line 129 "src/analyzer/Function.pv"
                return 0;
            }

            #line 132 "src/analyzer/Function.pv"
            bool has_type = false;

            #line 134 "src/analyzer/Function.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 135 "src/analyzer/Function.pv"
                if (!Context__parse_type(context, &parameter.type, generics)) {
                    #line 135 "src/analyzer/Function.pv"
                    return false;
                }
                #line 136 "src/analyzer/Function.pv"
                has_type = true;
            }

            #line 139 "src/analyzer/Function.pv"
            if (!has_type && str__eq(parameter.name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
                #line 140 "src/analyzer/Function.pv"
                parameter.type = (struct Type) { .type = TYPE__SELF };
                #line 141 "src/analyzer/Function.pv"
                has_type = true;
            }

            #line 144 "src/analyzer/Function.pv"
            if (!has_type) {
                #line 145 "src/analyzer/Function.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":");
                #line 146 "src/analyzer/Function.pv"
                return false;
            }

            #line 149 "src/analyzer/Function.pv"
            Array_Parameter__append(&self->parameters, parameter);
        }

        #line 152 "src/analyzer/Function.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 153 "src/analyzer/Function.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
        }
    }

    #line 157 "src/analyzer/Function.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
        #line 157 "src/analyzer/Function.pv"
        return 0;
    }

    #line 159 "src/analyzer/Function.pv"
    return true;
}

#line 162 "src/analyzer/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics) {
    #line 163 "src/analyzer/Function.pv"
    struct Context* context = self->context;

    #line 165 "src/analyzer/Function.pv"
    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "->")) {
        #line 165 "src/analyzer/Function.pv"
        return true;
    }

    #line 167 "src/analyzer/Function.pv"
    return Context__parse_type(context, &self->return_type, &self->generics);
}

#line 170 "src/analyzer/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics) {
    #line 171 "src/analyzer/Function.pv"
    self->generics.parent = generics;

    #line 173 "src/analyzer/Function.pv"
    struct Context* context = self->context;
    #line 174 "src/analyzer/Function.pv"
    context->pos = self->declaration_start;

    #line 176 "src/analyzer/Function.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 176 "src/analyzer/Function.pv"
        return false;
    }

    #line 178 "src/analyzer/Function.pv"
    if (!Function__parse_parameters(self, &self->generics)) {
        #line 178 "src/analyzer/Function.pv"
        return false;
    }
    #line 179 "src/analyzer/Function.pv"
    if (!Function__parse_return_type(self, &self->generics)) {
        #line 179 "src/analyzer/Function.pv"
        return false;
    }

    #line 181 "src/analyzer/Function.pv"
    if (context->pos != self->declaration_end) {
        #line 182 "src/analyzer/Function.pv"
        return false;
    }

    #line 185 "src/analyzer/Function.pv"
    return true;
}

#line 188 "src/analyzer/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics) {
    #line 189 "src/analyzer/Function.pv"
    self->generics.parent = generics;

    #line 191 "src/analyzer/Function.pv"
    struct Context* context = self->context;
    #line 192 "src/analyzer/Function.pv"
    context->pos = self->token_start;
    #line 193 "src/analyzer/Function.pv"
    struct Block* block = Block__new_ptr(context);
    #line 194 "src/analyzer/Function.pv"
    Context__push_scope(context, 0);
    #line 195 "src/analyzer/Function.pv"
    context->function = self;

    #line 197 "src/analyzer/Function.pv"
    { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&self->parameters);
    #line 197 "src/analyzer/Function.pv"
    while (ArrayIter_ref_Parameter__next(&__iter)) {
        #line 197 "src/analyzer/Function.pv"
        struct Parameter* param_info = ArrayIter_ref_Parameter__value(&__iter);

        #line 198 "src/analyzer/Function.pv"
        if (Context__set_value(context, param_info->name, &param_info->type) == 0) {
            #line 198 "src/analyzer/Function.pv"
            Context__pop_scope(context);
            #line 198 "src/analyzer/Function.pv"
            return true;
        }
    } }

    #line 201 "src/analyzer/Function.pv"
    bool block_result = Block__parse(block, context, &self->generics, 1);

    #line 203 "src/analyzer/Function.pv"
    if (block_result == 0) {
        #line 203 "src/analyzer/Function.pv"
        Context__pop_scope(context);
        #line 203 "src/analyzer/Function.pv"
        return true;
    }

    #line 205 "src/analyzer/Function.pv"
    self->body = block;

    #line 207 "src/analyzer/Function.pv"
    if (context->pos != self->token_end) {
        #line 207 "src/analyzer/Function.pv"
        Context__pop_scope(context);
        #line 207 "src/analyzer/Function.pv"
        return true;
    }

    #line 209 "src/analyzer/Function.pv"
    context->function = 0;
    #line 210 "src/analyzer/Function.pv"
    Context__pop_scope(context);
    #line 211 "src/analyzer/Function.pv"
    return false;
}
