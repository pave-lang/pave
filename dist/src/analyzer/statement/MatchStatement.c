#include <analyzer/statement/MatchPattern.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <stdint.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/Block.h>
#include <std/Array_MatchPattern.h>

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
        struct Token* first_match_token = Context__current(context);

        #line 26 "src/analyzer/statement/MatchStatement.pv"
        struct Block* block = Block__new_ptr(context);
        #line 27 "src/analyzer/statement/MatchStatement.pv"
        Context__push_scope(context, block);

        #line 29 "src/analyzer/statement/MatchStatement.pv"
        struct Array_MatchPattern patterns = Array_MatchPattern__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 31 "src/analyzer/statement/MatchStatement.pv"
        while (patterns.length == 0 || Context__check_next(context, TOKEN_TYPE__SYMBOL, "|")) {
            #line 32 "src/analyzer/statement/MatchStatement.pv"
            struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
            #line 33 "src/analyzer/statement/MatchStatement.pv"
            if (!MatchPattern__parse(context, generics, &pattern)) {
                #line 33 "src/analyzer/statement/MatchStatement.pv"
                return 0;
            }

            #line 35 "src/analyzer/statement/MatchStatement.pv"
            Array_MatchPattern__append(&patterns, pattern);
        }

        #line 38 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>")) {
            #line 38 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 38 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }

        #line 40 "src/analyzer/statement/MatchStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 40 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 40 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }

        #line 42 "src/analyzer/statement/MatchStatement.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .patterns = patterns,
            .body = block,
        };

        #line 48 "src/analyzer/statement/MatchStatement.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 50 "src/analyzer/statement/MatchStatement.pv"
        Context__pop_scope(context);

        #line 52 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 53 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 54 "src/analyzer/statement/MatchStatement.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 55 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }
    }

    #line 59 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 59 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 61 "src/analyzer/statement/MatchStatement.pv"
    return ArenaAllocator__store_MatchStatement(context->allocator, (struct MatchStatement) {
        .expression = expression,
        .cases = cases,
    });
}
