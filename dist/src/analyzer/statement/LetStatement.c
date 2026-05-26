#include <stdint.h>
#include <string.h>

#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Type.h>
#include <analyzer/expression/Expression.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/Scope.h>
#include <std/Array_Scope.h>
#include <std/HashMap_str_Type.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/Array_ref_Token.h>
#include <analyzer/types/Tuple.h>
#include <std/Array_Type.h>
#include <analyzer/statement/DestructureBinding.h>
#include <analyzer/statement/LetStatement.h>

#include <analyzer/statement/LetStatement.h>

#line 20 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse(struct Context* context, struct Generics* generics) {
    #line 21 "src/analyzer/statement/LetStatement.pv"
    struct Token* first_token = Context__current(context);
    #line 22 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 22 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 24 "src/analyzer/statement/LetStatement.pv"
    bool is_static = Context__check_next(context, TOKEN_TYPE__KEYWORD, "static");

    #line 26 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 27 "src/analyzer/statement/LetStatement.pv"
        return LetStatement__parse_destructure(context, generics, first_token, is_static);
    }

    #line 30 "src/analyzer/statement/LetStatement.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 31 "src/analyzer/statement/LetStatement.pv"
    if (name == 0) {
        #line 31 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 33 "src/analyzer/statement/LetStatement.pv"
    struct Type* type = 0;

    #line 35 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 36 "src/analyzer/statement/LetStatement.pv"
        type = Context__parse_type2(context, generics);
        #line 37 "src/analyzer/statement/LetStatement.pv"
        if (type == 0) {
            #line 37 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
    }

    #line 40 "src/analyzer/statement/LetStatement.pv"
    struct Expression* expression = 0;

    #line 42 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 43 "src/analyzer/statement/LetStatement.pv"
        expression = Expression__parse(context, generics);
        #line 44 "src/analyzer/statement/LetStatement.pv"
        if (expression == 0) {
            #line 44 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }

        #line 46 "src/analyzer/statement/LetStatement.pv"
        if (type == 0) {
            #line 47 "src/analyzer/statement/LetStatement.pv"
            type = &expression->return_type;

            #line 49 "src/analyzer/statement/LetStatement.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 50 "src/analyzer/statement/LetStatement.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 51 "src/analyzer/statement/LetStatement.pv"
            Context__inlay_hint(context, name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 53 "src/analyzer/statement/LetStatement.pv"
            Expression__validate_type(expression, context, type, true);
        }
    }

    #line 57 "src/analyzer/statement/LetStatement.pv"
    if (!Context__set_value(context, name, type)) {
        #line 57 "src/analyzer/statement/LetStatement.pv"
        Context__error(context, "set_value");
        #line 57 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }
    #line 61 "src/analyzer/statement/LetStatement.pv"
    if (expression != 0) {
        #line 62 "src/analyzer/statement/LetStatement.pv"
        switch (expression->data.type) {
            #line 63 "src/analyzer/statement/LetStatement.pv"
            case EXPRESSION_DATA__VARIABLE: {
                #line 63 "src/analyzer/statement/LetStatement.pv"
                struct str src_name = expression->data.variable_value;
                #line 64 "src/analyzer/statement/LetStatement.pv"
                struct Type* src_original = Context__get_broadened_type(context, src_name);
                #line 65 "src/analyzer/statement/LetStatement.pv"
                if (src_original != 0) {
                    #line 66 "src/analyzer/statement/LetStatement.pv"
                    struct Scope* scope = Array_Scope__back(&context->scopes);
                    #line 67 "src/analyzer/statement/LetStatement.pv"
                    if (scope == 0) {
                        #line 67 "src/analyzer/statement/LetStatement.pv"
                        return 0;
                    }
                    #line 68 "src/analyzer/statement/LetStatement.pv"
                    HashMap_str_Type__insert(&scope->narrow_originals, name->value, *src_original);
                }
            } break;
            #line 71 "src/analyzer/statement/LetStatement.pv"
            default: {
            } break;
        }
    }

    #line 75 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 75 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 77 "src/analyzer/statement/LetStatement.pv"
    if (type == 0) {
        #line 77 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 79 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_unknown(type)) {
        #line 80 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 83 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_void(type)) {
        #line 84 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement cannot have void type");
    }

    #line 87 "src/analyzer/statement/LetStatement.pv"
    return ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement[]){(struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
        .destructure = Array_DestructureBinding__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    }});
}

#line 96 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse_destructure(struct Context* context, struct Generics* generics, struct Token* first_token, bool is_static) {
    #line 97 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 97 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 99 "src/analyzer/statement/LetStatement.pv"
    struct Array_ref_Token names = Array_ref_Token__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 100 "src/analyzer/statement/LetStatement.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 101 "src/analyzer/statement/LetStatement.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 102 "src/analyzer/statement/LetStatement.pv"
        if (name == 0) {
            #line 102 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
        #line 103 "src/analyzer/statement/LetStatement.pv"
        Array_ref_Token__append(&names, name);

        #line 105 "src/analyzer/statement/LetStatement.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 106 "src/analyzer/statement/LetStatement.pv"
            Context__error(context, "Expected , or )");
            #line 107 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
    }
    #line 110 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 110 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 112 "src/analyzer/statement/LetStatement.pv"
    if (names.length == 0) {
        #line 113 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Destructuring let requires at least one binding");
        #line 114 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 117 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 117 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 119 "src/analyzer/statement/LetStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 120 "src/analyzer/statement/LetStatement.pv"
    if (expression == 0) {
        #line 120 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 122 "src/analyzer/statement/LetStatement.pv"
    struct Type* value_type = &expression->return_type;
    #line 123 "src/analyzer/statement/LetStatement.pv"
    struct Type* deref_type = Type__deref(value_type);

    #line 125 "src/analyzer/statement/LetStatement.pv"
    struct Tuple* tuple_ref = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple[]){(struct Tuple) { .elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) }});
    #line 126 "src/analyzer/statement/LetStatement.pv"
    bool is_tuple = false;
    #line 127 "src/analyzer/statement/LetStatement.pv"
    switch (deref_type->type) {
        #line 128 "src/analyzer/statement/LetStatement.pv"
        case TYPE__TUPLE: {
            #line 128 "src/analyzer/statement/LetStatement.pv"
            struct Tuple* t = deref_type->tuple_value;
            #line 128 "src/analyzer/statement/LetStatement.pv"
            tuple_ref = t;
            #line 128 "src/analyzer/statement/LetStatement.pv"
            is_tuple = true;
        } break;
        #line 129 "src/analyzer/statement/LetStatement.pv"
        default: {
        } break;
    }
    #line 131 "src/analyzer/statement/LetStatement.pv"
    if (!is_tuple) {
        #line 132 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Destructuring let requires a tuple value");
        #line 133 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 136 "src/analyzer/statement/LetStatement.pv"
    if (tuple_ref->elements.length != names.length) {
        #line 137 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Destructuring let arity does not match tuple arity");
        #line 138 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 141 "src/analyzer/statement/LetStatement.pv"
    struct Array_DestructureBinding bindings = Array_DestructureBinding__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 142 "src/analyzer/statement/LetStatement.pv"
    uintptr_t bi = 0;
    #line 143 "src/analyzer/statement/LetStatement.pv"
    while (bi < names.length) {
        #line 144 "src/analyzer/statement/LetStatement.pv"
        struct Token* name_token = names.data[bi];
        #line 145 "src/analyzer/statement/LetStatement.pv"
        struct Type* element_type = &tuple_ref->elements.data[bi];
        #line 146 "src/analyzer/statement/LetStatement.pv"
        if (!str__Eq_str__eq(&name_token->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
            #line 147 "src/analyzer/statement/LetStatement.pv"
            if (!Context__set_value(context, name_token, element_type)) {
                #line 147 "src/analyzer/statement/LetStatement.pv"
                Context__error(context, "set_value");
                #line 147 "src/analyzer/statement/LetStatement.pv"
                return 0;
            }
        }
        #line 149 "src/analyzer/statement/LetStatement.pv"
        Array_DestructureBinding__append(&bindings, (struct DestructureBinding) { .name = name_token, .type = element_type });
        #line 150 "src/analyzer/statement/LetStatement.pv"
        bi += 1;
    }

    #line 153 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 153 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 155 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_unknown(value_type)) {
        #line 156 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 159 "src/analyzer/statement/LetStatement.pv"
    struct String temp_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 160 "src/analyzer/statement/LetStatement.pv"
    String__append(&temp_name, (struct str){ .ptr = "__pave_destructure_", .length = strlen("__pave_destructure_") });
    #line 161 "src/analyzer/statement/LetStatement.pv"
    String__append_usize(&temp_name, first_token->start_line);
    #line 162 "src/analyzer/statement/LetStatement.pv"
    String__append(&temp_name, (struct str){ .ptr = "_", .length = strlen("_") });
    #line 163 "src/analyzer/statement/LetStatement.pv"
    String__append_usize(&temp_name, first_token->start_column);

    #line 165 "src/analyzer/statement/LetStatement.pv"
    struct Token* temp_token = ArenaAllocator__store_Token(context->allocator, (struct Token[]){(struct Token) {
        .type = TOKEN_TYPE__IDENTIFIER,
        .value = String__as_str(&temp_name),
        .start_line = first_token->start_line,
        .start_column = first_token->start_column,
        .end_line = first_token->end_line,
        .end_column = first_token->end_column,
    }});

    #line 174 "src/analyzer/statement/LetStatement.pv"
    return ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement[]){(struct LetStatement) {
        .is_static = is_static,
        .name = temp_token,
        .type = value_type,
        .value = expression,
        .destructure = bindings,
    }});
}
