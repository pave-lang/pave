#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Block.h>
#include <analyzer/types/Type.h>
#include <std/str.h>
#include <analyzer/statement/WhileStatement.h>
#include <std/ArenaAllocator.h>
#include <analyzer/statement/WhileStatement.h>

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
    #line 21 "src/analyzer/statement/WhileStatement.pv"
    struct Type* narrow_true = Expression__detect_null_narrowing(context, expression, true);
    #line 22 "src/analyzer/statement/WhileStatement.pv"
    if (narrow_true != 0) {
        #line 23 "src/analyzer/statement/WhileStatement.pv"
        struct str var_name = Expression__narrowed_var_name(context, expression, true);
        #line 24 "src/analyzer/statement/WhileStatement.pv"
        Context__push_scope(context, block);
        #line 25 "src/analyzer/statement/WhileStatement.pv"
        Context__set_narrowed(context, var_name, narrow_true);
        #line 26 "src/analyzer/statement/WhileStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 26 "src/analyzer/statement/WhileStatement.pv"
            Context__pop_scope(context);
            #line 26 "src/analyzer/statement/WhileStatement.pv"
            return 0;
        }
        #line 27 "src/analyzer/statement/WhileStatement.pv"
        Context__pop_scope(context);
    } else {
        #line 29 "src/analyzer/statement/WhileStatement.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 29 "src/analyzer/statement/WhileStatement.pv"
            return 0;
        }
    }

    #line 32 "src/analyzer/statement/WhileStatement.pv"
    return ArenaAllocator__store_WhileStatement(context->allocator, (struct WhileStatement[]){(struct WhileStatement) {
        .expression = expression,
        .block = block,
    }});
}
