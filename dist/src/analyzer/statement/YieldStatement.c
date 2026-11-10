#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionType.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Type.h>
#include <analyzer/statement/YieldStatement.h>

#include <analyzer/statement/YieldStatement.h>

#line 10 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement* YieldStatement__parse(struct Context* context, struct Generics* generics) {
    #line 11 "src/analyzer/statement/YieldStatement.pv"
    struct Token* keyword = Context__current(context);
    #line 12 "src/analyzer/statement/YieldStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield")) {
        #line 12 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 14 "src/analyzer/statement/YieldStatement.pv"
    struct Function* yielding = context->function;
    #line 15 "src/analyzer/statement/YieldStatement.pv"
    if (yielding == 0 || yielding->type != FUNCTION_TYPE__COROUTINE) {
        #line 16 "src/analyzer/statement/YieldStatement.pv"
        Context__error_token(context, keyword, "yield is only for a co function");
        #line 17 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 20 "src/analyzer/statement/YieldStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 21 "src/analyzer/statement/YieldStatement.pv"
        return ArenaAllocator__store_YieldStatement(context->allocator, (struct YieldStatement[]){(struct YieldStatement) { .expression = 0 }});
    }

    #line 24 "src/analyzer/statement/YieldStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 25 "src/analyzer/statement/YieldStatement.pv"
    if (expression == 0) {
        #line 25 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }
    #line 26 "src/analyzer/statement/YieldStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 26 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 28 "src/analyzer/statement/YieldStatement.pv"
    struct Function* function = context->function;
    #line 29 "src/analyzer/statement/YieldStatement.pv"
    if (function == 0) {
        #line 29 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }
    #line 30 "src/analyzer/statement/YieldStatement.pv"
    Expression__validate_type(expression, context, &function->return_type, true);

    #line 32 "src/analyzer/statement/YieldStatement.pv"
    return ArenaAllocator__store_YieldStatement(context->allocator, (struct YieldStatement[]){(struct YieldStatement) { .expression = expression }});
}
