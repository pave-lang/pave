#include <stdbool.h>
#include <stdint.h>

#include <std/Array_Scope.h>
#include <analyzer/Context.h>
#include <std/Iter_ref_Scope.h>
#include <analyzer/Scope.h>
#include <analyzer/Block.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Generics.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/statement/DeferStatement.h>

#include <analyzer/statement/DeferStatement.h>

#line 11 "src/analyzer/statement/DeferStatement.pv"
struct DeferStatement* DeferStatement__parse(struct Block* parent_block, struct Context* context, struct Generics* generics) {
    #line 12 "src/analyzer/statement/DeferStatement.pv"
    bool top_block_found = false;
    #line 13 "src/analyzer/statement/DeferStatement.pv"
    { struct Iter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 13 "src/analyzer/statement/DeferStatement.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 13 "src/analyzer/statement/DeferStatement.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 14 "src/analyzer/statement/DeferStatement.pv"
        if (top_block_found) {
        } else {
            #line 16 "src/analyzer/statement/DeferStatement.pv"
            struct Block* top_block = scope->block;
            #line 17 "src/analyzer/statement/DeferStatement.pv"
            if (top_block != 0) {
                #line 18 "src/analyzer/statement/DeferStatement.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 19 "src/analyzer/statement/DeferStatement.pv"
                top_block_found = true;
            }
        }
    } }

    #line 24 "src/analyzer/statement/DeferStatement.pv"
    if (!top_block_found) {
        #line 24 "src/analyzer/statement/DeferStatement.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 26 "src/analyzer/statement/DeferStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer")) {
        #line 26 "src/analyzer/statement/DeferStatement.pv"
        return 0;
    }

    #line 28 "src/analyzer/statement/DeferStatement.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 29 "src/analyzer/statement/DeferStatement.pv"
        struct Block* defer_block = Block__new_ptr(context);
        #line 30 "src/analyzer/statement/DeferStatement.pv"
        if (!Block__parse(defer_block, context, generics, true)) {
            #line 30 "src/analyzer/statement/DeferStatement.pv"
            return 0;
        }
        #line 31 "src/analyzer/statement/DeferStatement.pv"
        return ArenaAllocator__store_DeferStatement(context->allocator, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = defer_block });
    } else {
        #line 33 "src/analyzer/statement/DeferStatement.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 34 "src/analyzer/statement/DeferStatement.pv"
        if (expression == 0) {
            #line 34 "src/analyzer/statement/DeferStatement.pv"
            return 0;
        }
        #line 35 "src/analyzer/statement/DeferStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 35 "src/analyzer/statement/DeferStatement.pv"
            return 0;
        }
        #line 36 "src/analyzer/statement/DeferStatement.pv"
        return ArenaAllocator__store_DeferStatement(context->allocator, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
    }
}
