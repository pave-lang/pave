#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchStatement.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <std/Array_MatchCase.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/statement/MatchCase.h>
#include <analyzer/statement/MatchStatement.h>

#include <analyzer/statement/MatchStatement.h>

#line 13 "src/analyzer/statement/MatchStatement.pv"
struct MatchStatement* MatchStatement__parse(struct Context* context, struct Generics* generics) {
    #line 14 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match")) {
        #line 14 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 16 "src/analyzer/statement/MatchStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 17 "src/analyzer/statement/MatchStatement.pv"
    if (expression == 0) {
        #line 17 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 19 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 19 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 21 "src/analyzer/statement/MatchStatement.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 23 "src/analyzer/statement/MatchStatement.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 24 "src/analyzer/statement/MatchStatement.pv"
        struct MatchCase match_case;
        #line 25 "src/analyzer/statement/MatchStatement.pv"
        if (!MatchCase__parse(&match_case, context, generics)) {
            #line 25 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }

        #line 27 "src/analyzer/statement/MatchStatement.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 29 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 30 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 31 "src/analyzer/statement/MatchStatement.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 32 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }
    }

    #line 36 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 36 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 38 "src/analyzer/statement/MatchStatement.pv"
    return ArenaAllocator__store_MatchStatement(context->allocator, (struct MatchStatement) {
        .expression = expression,
        .cases = cases,
    });
}
