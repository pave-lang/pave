#include <std/ArenaAllocator.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <stdint.h>
#include <analyzer/Block.h>

#include <analyzer/statement/WhileStatement.h>

#line 11 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement* WhileStatement__parse(struct Context* context, struct Generics* generics) {
    #line 12 "src/analyzer/statement/WhileStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while")) {
        #line 12 "src/analyzer/statement/WhileStatement.pv"
        return 0;
    }

    #line 14 "src/analyzer/statement/WhileStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 15 "src/analyzer/statement/WhileStatement.pv"
    if (expression == 0) {
        #line 15 "src/analyzer/statement/WhileStatement.pv"
        return 0;
    }

    #line 17 "src/analyzer/statement/WhileStatement.pv"
    struct Block* block = Block__new_ptr(context);
    #line 18 "src/analyzer/statement/WhileStatement.pv"
    block->is_loop = true;
    #line 19 "src/analyzer/statement/WhileStatement.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 19 "src/analyzer/statement/WhileStatement.pv"
        return 0;
    }

    #line 21 "src/analyzer/statement/WhileStatement.pv"
    return ArenaAllocator__store_WhileStatement(context->allocator, (struct WhileStatement) {
        .expression = expression,
        .block = block,
    });
}
