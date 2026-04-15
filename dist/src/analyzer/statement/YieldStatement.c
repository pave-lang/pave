#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/YieldStatement.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Function.h>
#include <analyzer/statement/YieldStatement.h>

#include <analyzer/statement/YieldStatement.h>

#line 10 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement* YieldStatement__parse(struct Context* context, struct Generics* generics) {
    #line 11 "src/analyzer/statement/YieldStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield")) {
        #line 11 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 13 "src/analyzer/statement/YieldStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 14 "src/analyzer/statement/YieldStatement.pv"
        return ArenaAllocator__store_YieldStatement(context->allocator, (struct YieldStatement) { .expression = 0 });
    }

    #line 17 "src/analyzer/statement/YieldStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 18 "src/analyzer/statement/YieldStatement.pv"
    if (expression == 0) {
        #line 18 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }
    #line 19 "src/analyzer/statement/YieldStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 19 "src/analyzer/statement/YieldStatement.pv"
        return 0;
    }

    #line 21 "src/analyzer/statement/YieldStatement.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 23 "src/analyzer/statement/YieldStatement.pv"
    return ArenaAllocator__store_YieldStatement(context->allocator, (struct YieldStatement) { .expression = expression });
}
