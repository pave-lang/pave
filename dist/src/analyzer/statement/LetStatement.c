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

#line 21 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse(struct Context* context, struct Generics* generics) {
    #line 22 "src/analyzer/statement/LetStatement.pv"
    struct Token* first_token = Context__current(context);
    #line 23 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 23 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 25 "src/analyzer/statement/LetStatement.pv"
    bool is_static = Context__check_next(context, TOKEN_TYPE__KEYWORD, "static");

    #line 27 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 28 "src/analyzer/statement/LetStatement.pv"
        return LetStatement__parse_destructure(context, generics, first_token, is_static);
    }

    #line 31 "src/analyzer/statement/LetStatement.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 32 "src/analyzer/statement/LetStatement.pv"
    if (name == 0) {
        #line 32 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 34 "src/analyzer/statement/LetStatement.pv"
    struct Type* type = 0;

    #line 36 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 37 "src/analyzer/statement/LetStatement.pv"
        type = Context__parse_type2(context, generics);
        #line 38 "src/analyzer/statement/LetStatement.pv"
        if (type == 0) {
            #line 38 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
    }

    #line 41 "src/analyzer/statement/LetStatement.pv"
    struct Expression* expression = 0;

    #line 43 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 44 "src/analyzer/statement/LetStatement.pv"
        expression = Expression__parse(context, generics);
        #line 45 "src/analyzer/statement/LetStatement.pv"
        if (expression == 0) {
            #line 45 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }

        #line 47 "src/analyzer/statement/LetStatement.pv"
        if (type == 0) {
            #line 48 "src/analyzer/statement/LetStatement.pv"
            type = &expression->return_type;

            #line 50 "src/analyzer/statement/LetStatement.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 51 "src/analyzer/statement/LetStatement.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 52 "src/analyzer/statement/LetStatement.pv"
            Context__inlay_hint(context, name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 54 "src/analyzer/statement/LetStatement.pv"
            Expression__validate_type(expression, context, type, true);
        }
    }

    #line 58 "src/analyzer/statement/LetStatement.pv"
    if (!Context__set_value(context, name, type)) {
        #line 58 "src/analyzer/statement/LetStatement.pv"
        Context__error(context, "set_value");
        #line 58 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }
    #line 62 "src/analyzer/statement/LetStatement.pv"
    if (expression != 0) {
        #line 63 "src/analyzer/statement/LetStatement.pv"
        switch (expression->data.type) {
            #line 64 "src/analyzer/statement/LetStatement.pv"
            case EXPRESSION_DATA__VARIABLE: {
                #line 64 "src/analyzer/statement/LetStatement.pv"
                struct str src_name = expression->data.variable_value;
                #line 65 "src/analyzer/statement/LetStatement.pv"
                struct Type* src_original = Context__get_broadened_type(context, src_name);
                #line 66 "src/analyzer/statement/LetStatement.pv"
                if (src_original != 0) {
                    #line 67 "src/analyzer/statement/LetStatement.pv"
                    struct Scope* scope = Array_Scope__back(&context->scopes);
                    #line 68 "src/analyzer/statement/LetStatement.pv"
                    if (scope == 0) {
                        #line 68 "src/analyzer/statement/LetStatement.pv"
                        return 0;
                    }
                    #line 69 "src/analyzer/statement/LetStatement.pv"
                    HashMap_str_Type__insert(&scope->narrow_originals, name->value, *src_original);
                }
            } break;
            #line 72 "src/analyzer/statement/LetStatement.pv"
            default: {
            } break;
        }
    }

    #line 76 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 76 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 78 "src/analyzer/statement/LetStatement.pv"
    if (type == 0) {
        #line 78 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 80 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_unknown(type)) {
        #line 81 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 84 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_void(type)) {
        #line 85 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement cannot have void type");
    }

    #line 88 "src/analyzer/statement/LetStatement.pv"
    return ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement[]){(struct LetStatement) {
        .is_static = is_static,
        .token = first_token,
        .name = name,
        .type = type,
        .value = expression,
        .destructure = Array_DestructureBinding__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    }});
}

#line 98 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse_destructure(struct Context* context, struct Generics* generics, struct Token* first_token, bool is_static) {
    #line 99 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 99 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 101 "src/analyzer/statement/LetStatement.pv"
    struct Array_ref_Token names = Array_ref_Token__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 102 "src/analyzer/statement/LetStatement.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 103 "src/analyzer/statement/LetStatement.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 104 "src/analyzer/statement/LetStatement.pv"
        if (name == 0) {
            #line 104 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
        #line 105 "src/analyzer/statement/LetStatement.pv"
        Array_ref_Token__append(&names, name);

        #line 107 "src/analyzer/statement/LetStatement.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 108 "src/analyzer/statement/LetStatement.pv"
            Context__error(context, "Expected , or )");
            #line 109 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
    }
    #line 112 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 112 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 114 "src/analyzer/statement/LetStatement.pv"
    if (names.length == 0) {
        #line 115 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Destructuring let requires at least one binding");
        #line 116 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 119 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 119 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 121 "src/analyzer/statement/LetStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 122 "src/analyzer/statement/LetStatement.pv"
    if (expression == 0) {
        #line 122 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 124 "src/analyzer/statement/LetStatement.pv"
    struct Type* value_type = &expression->return_type;
    #line 125 "src/analyzer/statement/LetStatement.pv"
    struct Type* deref_type = Type__deref(value_type);

    #line 127 "src/analyzer/statement/LetStatement.pv"
    struct Tuple* tuple_ref = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple[]){(struct Tuple) { .elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) }});
    #line 128 "src/analyzer/statement/LetStatement.pv"
    bool is_tuple = false;
    #line 129 "src/analyzer/statement/LetStatement.pv"
    switch (deref_type->type) {
        #line 130 "src/analyzer/statement/LetStatement.pv"
        case TYPE__TUPLE: {
            #line 130 "src/analyzer/statement/LetStatement.pv"
            struct Tuple* t = deref_type->tuple_value;
            #line 130 "src/analyzer/statement/LetStatement.pv"
            tuple_ref = t;
            #line 130 "src/analyzer/statement/LetStatement.pv"
            is_tuple = true;
        } break;
        #line 131 "src/analyzer/statement/LetStatement.pv"
        default: {
        } break;
    }
    #line 133 "src/analyzer/statement/LetStatement.pv"
    if (!is_tuple) {
        #line 134 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Destructuring let requires a tuple value");
        #line 135 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 138 "src/analyzer/statement/LetStatement.pv"
    if (tuple_ref->elements.length != names.length) {
        #line 139 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Destructuring let arity does not match tuple arity");
        #line 140 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 143 "src/analyzer/statement/LetStatement.pv"
    struct Array_DestructureBinding bindings = Array_DestructureBinding__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 144 "src/analyzer/statement/LetStatement.pv"
    uintptr_t bi = 0;
    #line 145 "src/analyzer/statement/LetStatement.pv"
    while (bi < names.length) {
        #line 146 "src/analyzer/statement/LetStatement.pv"
        struct Token* name_token = names.data[bi];
        #line 147 "src/analyzer/statement/LetStatement.pv"
        struct Type* element_type = &tuple_ref->elements.data[bi];
        #line 148 "src/analyzer/statement/LetStatement.pv"
        if (!str__Eq_str__eq(&name_token->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
            #line 149 "src/analyzer/statement/LetStatement.pv"
            if (!Context__set_value(context, name_token, element_type)) {
                #line 149 "src/analyzer/statement/LetStatement.pv"
                Context__error(context, "set_value");
                #line 149 "src/analyzer/statement/LetStatement.pv"
                return 0;
            }
        }
        #line 151 "src/analyzer/statement/LetStatement.pv"
        Array_DestructureBinding__append(&bindings, (struct DestructureBinding) { .name = name_token, .type = element_type });
        #line 152 "src/analyzer/statement/LetStatement.pv"
        bi += 1;
    }

    #line 155 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 155 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 157 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_unknown(value_type)) {
        #line 158 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 161 "src/analyzer/statement/LetStatement.pv"
    return ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement[]){(struct LetStatement) {
        .is_static = is_static,
        .token = first_token,
        .name = 0,
        .type = value_type,
        .value = expression,
        .destructure = bindings,
    }});
}
