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
#include <analyzer/Token.h>
#include <analyzer/expression/Expression.h>
#include <stdint.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Type.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/Scope.h>
#include <std/Iter_ref_Scope.h>
#include <std/Array_Scope.h>
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
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 30 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 31 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 32 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 32 "src/analyzer/Block.pv"
        return false;
    }

    #line 34 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 35 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 36 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 36 "src/analyzer/Block.pv"
            return false;
        }

        #line 38 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 39 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 39 "src/analyzer/Block.pv"
            return false;
        }

        #line 41 "src/analyzer/Block.pv"
        Expression__validate_type(value, context, &expression->return_type, true);

        #line 43 "src/analyzer/Block.pv"
        struct AssignmentStatement* assignment = ArenaAllocator__store_AssignmentStatement(context->allocator, (struct AssignmentStatement) { .left = expression, .operator = operator, .right = value });
        #line 44 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = assignment }));
    } else {
        #line 46 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression }));
    }

    #line 49 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 49 "src/analyzer/Block.pv"
        return false;
    }

    #line 51 "src/analyzer/Block.pv"
    return true;
}

#line 54 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 55 "src/analyzer/Block.pv"
    bool top_block_found = false;
    #line 56 "src/analyzer/Block.pv"
    { struct Iter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 56 "src/analyzer/Block.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 56 "src/analyzer/Block.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 57 "src/analyzer/Block.pv"
        if (top_block_found) {
        } else {
            #line 59 "src/analyzer/Block.pv"
            struct Block* top_block = scope->block;
            #line 60 "src/analyzer/Block.pv"
            if (top_block != 0) {
                #line 61 "src/analyzer/Block.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 62 "src/analyzer/Block.pv"
                top_block_found = true;
            }
        }
    } }

    #line 67 "src/analyzer/Block.pv"
    if (!top_block_found) {
        #line 67 "src/analyzer/Block.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 69 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer")) {
        #line 69 "src/analyzer/Block.pv"
        return false;
    }

    #line 71 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 72 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 73 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 73 "src/analyzer/Block.pv"
            return false;
        }
        #line 74 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = block });
    } else {
        #line 76 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 77 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 77 "src/analyzer/Block.pv"
            return false;
        }
        #line 78 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
        #line 79 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 79 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 82 "src/analyzer/Block.pv"
    return true;
}

#line 85 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 86 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 86 "src/analyzer/Block.pv"
        return false;
    }
    #line 87 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 87 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 89 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 90 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 91 "src/analyzer/Block.pv"
        bool result = true;

        #line 93 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 94 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 95 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 96 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, true);
            #line 97 "src/analyzer/Block.pv"
            if (result) {
                #line 97 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 99 "src/analyzer/Block.pv"
            result = DeferStatement__parse(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 101 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 102 "src/analyzer/Block.pv"
            struct LetStatement* let_statement = LetStatement__parse(context, generics);
            #line 103 "src/analyzer/Block.pv"
            if (let_statement) {
                #line 103 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));
            }
            #line 104 "src/analyzer/Block.pv"
            result = let_statement != 0;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 106 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 107 "src/analyzer/Block.pv"
            struct ReturnStatement* ret = ReturnStatement__parse(context, generics);
            #line 108 "src/analyzer/Block.pv"
            result = ret != 0;
            #line 109 "src/analyzer/Block.pv"
            if (result) {
                #line 109 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = ret }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 111 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 112 "src/analyzer/Block.pv"
            struct YieldStatement* yield_stmt = YieldStatement__parse(context, generics);
            #line 113 "src/analyzer/Block.pv"
            result = yield_stmt != 0;
            #line 114 "src/analyzer/Block.pv"
            if (result) {
                #line 114 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = yield_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 116 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 117 "src/analyzer/Block.pv"
            struct IfStatement* if_stmt = IfStatement__parse(context, generics);
            #line 118 "src/analyzer/Block.pv"
            result = if_stmt != 0;
            #line 119 "src/analyzer/Block.pv"
            if (result) {
                #line 119 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = if_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 121 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 122 "src/analyzer/Block.pv"
            struct MatchStatement* match_stmt = MatchStatement__parse(context, generics);
            #line 123 "src/analyzer/Block.pv"
            result = match_stmt != 0;
            #line 124 "src/analyzer/Block.pv"
            if (result) {
                #line 124 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = match_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 126 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 127 "src/analyzer/Block.pv"
            struct WhileStatement* while_stmt = WhileStatement__parse(context, generics);
            #line 128 "src/analyzer/Block.pv"
            result = while_stmt != 0;
            #line 129 "src/analyzer/Block.pv"
            if (result) {
                #line 129 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = while_stmt }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 131 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 132 "src/analyzer/Block.pv"
            struct ForStatement* for_statement = ForStatement__parse(self, context, generics);
            #line 133 "src/analyzer/Block.pv"
            if (for_statement) {
                #line 133 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = for_statement }));
            }
            #line 134 "src/analyzer/Block.pv"
            result = for_statement != 0;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 136 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 137 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 137 "src/analyzer/Block.pv"
                return false;
            }
            #line 138 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 140 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 141 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 141 "src/analyzer/Block.pv"
                return false;
            }
            #line 142 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 144 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics);
        }

        #line 147 "src/analyzer/Block.pv"
        if (!result) {
            #line 148 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 148 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 149 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 153 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 154 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 157 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 157 "src/analyzer/Block.pv"
        return false;
    }

    #line 159 "src/analyzer/Block.pv"
    return true;
}
