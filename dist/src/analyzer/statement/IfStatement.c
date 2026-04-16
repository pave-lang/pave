#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Block.h>
#include <std/Array_ElseStatement.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/IfStatement.h>

#include <analyzer/statement/IfStatement.h>

#line 13 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 14 "src/analyzer/statement/IfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 14 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 16 "src/analyzer/statement/IfStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 17 "src/analyzer/statement/IfStatement.pv"
    if (expression == 0) {
        #line 17 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 19 "src/analyzer/statement/IfStatement.pv"
    struct Block* block = Block__new_ptr(context);
    #line 20 "src/analyzer/statement/IfStatement.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 20 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 22 "src/analyzer/statement/IfStatement.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 23 "src/analyzer/statement/IfStatement.pv"
    struct Expression* else_expression = 0;
    #line 24 "src/analyzer/statement/IfStatement.pv"
    struct Block* else_block = 0;
    #line 25 "src/analyzer/statement/IfStatement.pv"
    bool else_end = false;

    #line 27 "src/analyzer/statement/IfStatement.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 28 "src/analyzer/statement/IfStatement.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 29 "src/analyzer/statement/IfStatement.pv"
            else_expression = Expression__parse(context, generics);
            #line 30 "src/analyzer/statement/IfStatement.pv"
            if (else_expression == 0) {
                #line 30 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
        } else {
            #line 32 "src/analyzer/statement/IfStatement.pv"
            else_expression = 0;
            #line 33 "src/analyzer/statement/IfStatement.pv"
            else_end = true;
        }

        #line 36 "src/analyzer/statement/IfStatement.pv"
        else_block = Block__new_ptr(context);
        #line 37 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(else_block, context, generics, true)) {
            #line 37 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }

        #line 39 "src/analyzer/statement/IfStatement.pv"
        struct ElseStatement else_statement = (struct ElseStatement) {
            .expression = else_expression,
            .block = else_block,
        };

        #line 44 "src/analyzer/statement/IfStatement.pv"
        Array_ElseStatement__append(&else_statements, else_statement);
    }

    #line 47 "src/analyzer/statement/IfStatement.pv"
    return ArenaAllocator__store_IfStatement(context->allocator, (struct IfStatement) {
        .expression = expression,
        .block = block,
        .else_statements = else_statements,
    });
}
