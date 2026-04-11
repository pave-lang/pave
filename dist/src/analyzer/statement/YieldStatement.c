#include <analyzer/types/Function.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/Expression.h>
#include <stdint.h>
#include <analyzer/types/Type.h>

#include <analyzer/statement/YieldStatement.h>

#line 10 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement* YieldStatement__parse(struct Context* context, struct Generics* generics) {
    #line 11 "src/analyzer/statement/YieldStatement.pv"
    struct Token* first_token = Context__current(context);
    #line 12 "src/analyzer/statement/YieldStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield")) {
        #line 12 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 14 "src/analyzer/statement/YieldStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 15 "src/analyzer/statement/YieldStatement.pv"
        return ArenaAllocator__store_YieldStatement(context->allocator, (struct YieldStatement) { .expression = 0 });
    }

    #line 18 "src/analyzer/statement/YieldStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 19 "src/analyzer/statement/YieldStatement.pv"
    if (expression == 0) {
        #line 19 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }
    #line 20 "src/analyzer/statement/YieldStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 20 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 22 "src/analyzer/statement/YieldStatement.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 24 "src/analyzer/statement/YieldStatement.pv"
    return ArenaAllocator__store_YieldStatement(context->allocator, (struct YieldStatement) { .expression = expression });
}
