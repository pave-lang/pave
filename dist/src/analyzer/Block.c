#include <stdio.h>

#include <analyzer/Context.h>
#include <std/Array_Statement.h>
#include <analyzer/statement/Statement.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <analyzer/statement/ForStatement.h>
#include <stdbool.h>
#include <analyzer/types/Generics.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/expression/Expression.h>
#include <stdint.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Type.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/statement/ReturnStatement.h>
#include <analyzer/statement/YieldStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/MatchStatement.h>
#include <analyzer/statement/WhileStatement.h>

#include <analyzer/Block.h>

#line 17 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context) {
    #line 18 "src/analyzer/Block.pv"
    return (struct Block) {
        .context = context,
        .statements = Array_Statement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 25 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context) {
    #line 26 "src/analyzer/Block.pv"
    return ArenaAllocator__store_Block(context->allocator, Block__new(context));
}

#line 29 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics, struct StatementData* data) {
    #line 30 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 31 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 31 "src/analyzer/Block.pv"
        return false;
    }

    #line 33 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 34 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 35 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 35 "src/analyzer/Block.pv"
            return false;
        }

        #line 37 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 38 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 38 "src/analyzer/Block.pv"
            return false;
        }

        #line 40 "src/analyzer/Block.pv"
        Expression__validate_type(value, context, &expression->return_type, true);

        #line 42 "src/analyzer/Block.pv"
        struct AssignmentStatement* assignment = ArenaAllocator__store_AssignmentStatement(context->allocator, (struct AssignmentStatement) { .left = expression, .operator = operator, .right = value });
        #line 43 "src/analyzer/Block.pv"
        *data = (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = assignment };
    } else {
        #line 45 "src/analyzer/Block.pv"
        *data = (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression };
    }

    #line 48 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 48 "src/analyzer/Block.pv"
        return false;
    }

    #line 50 "src/analyzer/Block.pv"
    return true;
}

#line 53 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 54 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 54 "src/analyzer/Block.pv"
        return false;
    }
    #line 55 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 55 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 57 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 58 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 59 "src/analyzer/Block.pv"
        bool result = true;

        #line 61 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 62 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 63 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 64 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, true);
            #line 65 "src/analyzer/Block.pv"
            if (result) {
                #line 65 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 67 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 68 "src/analyzer/Block.pv"
            struct DeferStatement* defer_stmt = DeferStatement__parse(self, context, generics);
            #line 69 "src/analyzer/Block.pv"
            result = defer_stmt != 0;
            #line 70 "src/analyzer/Block.pv"
            if (result) {
                #line 70 "src/analyzer/Block.pv"
                Array_DeferStatement__append(&self->defer_statements, *defer_stmt);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 72 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 73 "src/analyzer/Block.pv"
            struct LetStatement* let_statement = LetStatement__parse(context, generics);
            #line 74 "src/analyzer/Block.pv"
            if (let_statement) {
                #line 74 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));
            }
            #line 75 "src/analyzer/Block.pv"
            result = let_statement != 0;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 77 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 78 "src/analyzer/Block.pv"
            struct ReturnStatement* ret = ReturnStatement__parse(context, generics);
            #line 79 "src/analyzer/Block.pv"
            result = ret != 0;
            #line 80 "src/analyzer/Block.pv"
            if (result) {
                #line 80 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = ret }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 82 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 83 "src/analyzer/Block.pv"
            struct YieldStatement* yield_stmt = YieldStatement__parse(context, generics);
            #line 84 "src/analyzer/Block.pv"
            result = yield_stmt != 0;
            #line 85 "src/analyzer/Block.pv"
            if (result) {
                #line 85 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = yield_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 87 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 88 "src/analyzer/Block.pv"
            struct IfStatement* if_stmt = IfStatement__parse(context, generics);
            #line 89 "src/analyzer/Block.pv"
            result = if_stmt != 0;
            #line 90 "src/analyzer/Block.pv"
            if (result) {
                #line 90 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = if_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 92 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 93 "src/analyzer/Block.pv"
            struct MatchStatement* match_stmt = MatchStatement__parse(context, generics);
            #line 94 "src/analyzer/Block.pv"
            result = match_stmt != 0;
            #line 95 "src/analyzer/Block.pv"
            if (result) {
                #line 95 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = match_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 97 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 98 "src/analyzer/Block.pv"
            struct WhileStatement* while_stmt = WhileStatement__parse(context, generics);
            #line 99 "src/analyzer/Block.pv"
            result = while_stmt != 0;
            #line 100 "src/analyzer/Block.pv"
            if (result) {
                #line 100 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = while_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 102 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 103 "src/analyzer/Block.pv"
            struct ForStatement* for_statement = ForStatement__parse(self, context, generics);
            #line 104 "src/analyzer/Block.pv"
            if (for_statement) {
                #line 104 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = for_statement }));
            }
            #line 105 "src/analyzer/Block.pv"
            result = for_statement != 0;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 107 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 108 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 108 "src/analyzer/Block.pv"
                return false;
            }
            #line 109 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 111 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 112 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 112 "src/analyzer/Block.pv"
                return false;
            }
            #line 113 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 115 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 116 "src/analyzer/Block.pv"
            struct StatementData data = (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = 0 };
            #line 117 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics, &data);
            #line 118 "src/analyzer/Block.pv"
            if (result) {
                #line 118 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), data));
            }
        }

        #line 121 "src/analyzer/Block.pv"
        if (!result) {
            #line 122 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 122 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 123 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 127 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 128 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 131 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 131 "src/analyzer/Block.pv"
        return false;
    }

    #line 133 "src/analyzer/Block.pv"
    return true;
}
