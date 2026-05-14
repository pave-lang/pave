#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generics.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/IfStatement.h>

#include <analyzer/statement/IfStatement.h>

#line 14 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 15 "src/analyzer/statement/IfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 15 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 17 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* pattern = 0;
    #line 18 "src/analyzer/statement/IfStatement.pv"
    struct Expression* expression = 0;
    #line 19 "src/analyzer/statement/IfStatement.pv"
    struct Block* block = Block__new_ptr(context);

    #line 21 "src/analyzer/statement/IfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 22 "src/analyzer/statement/IfStatement.pv"
        Context__push_scope(context, block);
        #line 23 "src/analyzer/statement/IfStatement.pv"
        struct MatchPattern p = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 24 "src/analyzer/statement/IfStatement.pv"
        if (!MatchPattern__parse(context, generics, &p)) {
            #line 24 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 24 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 25 "src/analyzer/statement/IfStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 25 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 25 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 26 "src/analyzer/statement/IfStatement.pv"
        pattern = ArenaAllocator__store_MatchPattern(context->allocator, &p);
        #line 27 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 28 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 28 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 28 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 29 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 29 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 29 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 30 "src/analyzer/statement/IfStatement.pv"
        Context__pop_scope(context);
    } else {
        #line 32 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 33 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 33 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 34 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 34 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
    }

    #line 37 "src/analyzer/statement/IfStatement.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 38 "src/analyzer/statement/IfStatement.pv"
    struct Expression* else_expression = 0;
    #line 39 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* else_pattern = 0;
    #line 40 "src/analyzer/statement/IfStatement.pv"
    struct Block* else_block = 0;
    #line 41 "src/analyzer/statement/IfStatement.pv"
    bool else_end = false;

    #line 43 "src/analyzer/statement/IfStatement.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 44 "src/analyzer/statement/IfStatement.pv"
        else_expression = 0;
        #line 45 "src/analyzer/statement/IfStatement.pv"
        else_pattern = 0;

        #line 47 "src/analyzer/statement/IfStatement.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 48 "src/analyzer/statement/IfStatement.pv"
            if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
                #line 49 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 50 "src/analyzer/statement/IfStatement.pv"
                Context__push_scope(context, else_block);
                #line 51 "src/analyzer/statement/IfStatement.pv"
                struct MatchPattern ep = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
                #line 52 "src/analyzer/statement/IfStatement.pv"
                if (!MatchPattern__parse(context, generics, &ep)) {
                    #line 52 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 52 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 53 "src/analyzer/statement/IfStatement.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
                    #line 53 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 53 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 54 "src/analyzer/statement/IfStatement.pv"
                else_pattern = ArenaAllocator__store_MatchPattern(context->allocator, &ep);
                #line 55 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 56 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 56 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 56 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 57 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, false)) {
                    #line 57 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 57 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 58 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
            } else {
                #line 60 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 61 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 61 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 62 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 63 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, true)) {
                    #line 63 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            }
        } else {
            #line 66 "src/analyzer/statement/IfStatement.pv"
            else_end = true;
            #line 67 "src/analyzer/statement/IfStatement.pv"
            else_block = Block__new_ptr(context);
            #line 68 "src/analyzer/statement/IfStatement.pv"
            if (!Block__parse(else_block, context, generics, true)) {
                #line 68 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
        }

        #line 71 "src/analyzer/statement/IfStatement.pv"
        Array_ElseStatement__append(&else_statements, (struct ElseStatement) {
            .pattern = else_pattern,
            .expression = else_expression,
            .block = else_block,
        });
    }

    #line 78 "src/analyzer/statement/IfStatement.pv"
    return ArenaAllocator__store_IfStatement(context->allocator, (struct IfStatement[]){(struct IfStatement) {
        .pattern = pattern,
        .expression = expression,
        .block = block,
        .else_statements = else_statements,
    }});
}
