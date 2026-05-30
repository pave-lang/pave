#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Type.h>
#include <analyzer/statement/ReturnStatement.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/statement/ReturnStatement.h>

#include <analyzer/statement/ReturnStatement.h>

#line 11 "src/analyzer/statement/ReturnStatement.pv"
struct ReturnStatement* ReturnStatement__parse(struct Context* context, struct Generics* generics) {
    #line 12 "src/analyzer/statement/ReturnStatement.pv"
    struct Token* first_token = Context__current(context);
    #line 13 "src/analyzer/statement/ReturnStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "return")) {
        #line 13 "src/analyzer/statement/ReturnStatement.pv"
        return 0;
    }

    #line 15 "src/analyzer/statement/ReturnStatement.pv"
    struct Function* function = context->function;
    #line 16 "src/analyzer/statement/ReturnStatement.pv"
    if (function == 0) {
        #line 16 "src/analyzer/statement/ReturnStatement.pv"
        return 0;
    }

    #line 18 "src/analyzer/statement/ReturnStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 19 "src/analyzer/statement/ReturnStatement.pv"
        if (!Type__is_void(&function->return_type)) {
            #line 20 "src/analyzer/statement/ReturnStatement.pv"
            Context__error_token(context, first_token, "Return statement is blank but function has a return type");
        }

        #line 23 "src/analyzer/statement/ReturnStatement.pv"
        return ArenaAllocator__store_ReturnStatement(context->allocator, (struct ReturnStatement[]){(struct ReturnStatement) { .expression = 0 }});
    }

    #line 28 "src/analyzer/statement/ReturnStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 29 "src/analyzer/statement/ReturnStatement.pv"
    if (expression == 0) {
        #line 29 "src/analyzer/statement/ReturnStatement.pv"
        return 0;
    }
    #line 30 "src/analyzer/statement/ReturnStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 30 "src/analyzer/statement/ReturnStatement.pv"
        return 0;
    }

    #line 32 "src/analyzer/statement/ReturnStatement.pv"
    Expression__validate_type(expression, context, &function->return_type, true);

    #line 34 "src/analyzer/statement/ReturnStatement.pv"
    if (Type__is_void(&function->return_type)) {
        #line 35 "src/analyzer/statement/ReturnStatement.pv"
        Context__error_token(context, first_token, "Function does not have a return type");
    }

    #line 38 "src/analyzer/statement/ReturnStatement.pv"
    return ArenaAllocator__store_ReturnStatement(context->allocator, (struct ReturnStatement[]){(struct ReturnStatement) { .expression = expression }});
}
