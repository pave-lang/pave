#include <stdint.h>
#include <string.h>

#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Generics.h>
#include <analyzer/expression/Expression.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/statement/LetStatement.h>
#include <std/ArenaAllocator.h>
#include <analyzer/statement/LetStatement.h>

#include <analyzer/statement/LetStatement.h>

#line 13 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse(struct Context* context, struct Generics* generics) {
    #line 14 "src/analyzer/statement/LetStatement.pv"
    struct Token* first_token = Context__current(context);
    #line 15 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 15 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 17 "src/analyzer/statement/LetStatement.pv"
    bool is_static = Context__check_next(context, TOKEN_TYPE__KEYWORD, "static");

    #line 19 "src/analyzer/statement/LetStatement.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 20 "src/analyzer/statement/LetStatement.pv"
    if (name == 0) {
        #line 20 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 22 "src/analyzer/statement/LetStatement.pv"
    struct Type* type = 0;

    #line 24 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 25 "src/analyzer/statement/LetStatement.pv"
        type = Context__parse_type2(context, generics);
        #line 26 "src/analyzer/statement/LetStatement.pv"
        if (type == 0) {
            #line 26 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }
    }

    #line 29 "src/analyzer/statement/LetStatement.pv"
    struct Expression* expression = 0;

    #line 31 "src/analyzer/statement/LetStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 32 "src/analyzer/statement/LetStatement.pv"
        expression = Expression__parse(context, generics);
        #line 33 "src/analyzer/statement/LetStatement.pv"
        if (expression == 0) {
            #line 33 "src/analyzer/statement/LetStatement.pv"
            return 0;
        }

        #line 35 "src/analyzer/statement/LetStatement.pv"
        if (type == 0) {
            #line 36 "src/analyzer/statement/LetStatement.pv"
            type = &expression->return_type;

            #line 38 "src/analyzer/statement/LetStatement.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 39 "src/analyzer/statement/LetStatement.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 40 "src/analyzer/statement/LetStatement.pv"
            Context__inlay_hint(context, name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 42 "src/analyzer/statement/LetStatement.pv"
            Expression__validate_type(expression, context, type, true);
        }
    }

    #line 46 "src/analyzer/statement/LetStatement.pv"
    if (!Context__set_value(context, name, type)) {
        #line 46 "src/analyzer/statement/LetStatement.pv"
        Context__error(context, "set_value");
        #line 46 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }
    #line 47 "src/analyzer/statement/LetStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 47 "src/analyzer/statement/LetStatement.pv"
        return 0;
    }

    #line 49 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_unknown(type)) {
        #line 50 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 53 "src/analyzer/statement/LetStatement.pv"
    if (Type__is_void(type)) {
        #line 54 "src/analyzer/statement/LetStatement.pv"
        Context__error_token(context, first_token, "Let statement cannot have void type");
    }

    #line 57 "src/analyzer/statement/LetStatement.pv"
    return ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
    });
}
