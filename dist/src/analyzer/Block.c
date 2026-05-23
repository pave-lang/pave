#include <stdint.h>

#include <stdio.h>

#include <analyzer/Block.h>
#include <analyzer/Context.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/ExpressionData.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <analyzer/Token.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <analyzer/statement/StatementData.h>
#include <std/Hash.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/statement/ReturnStatement.h>
#include <analyzer/statement/YieldStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/MatchStatement.h>
#include <analyzer/statement/WhileStatement.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/Block.h>

#include <analyzer/Block.h>

#line 17 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context) {
    #line 18 "src/analyzer/Block.pv"
    return (struct Block) {
        .context = context,
        .statements = Array_Statement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .is_top_level_and_has_defer_statements_inside = false,
        .is_loop = false,
    };
}

#line 27 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context) {
    #line 28 "src/analyzer/Block.pv"
    struct Block block = Block__new(context);
    #line 29 "src/analyzer/Block.pv"
    return ArenaAllocator__store_Block(context->allocator, &block);
}

#line 32 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics, struct StatementData* data) {
    #line 33 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 34 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 34 "src/analyzer/Block.pv"
        return false;
    }

    #line 36 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 39 "src/analyzer/Block.pv"
        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 40 "src/analyzer/Block.pv"
            switch (expression->data.type) {
                #line 41 "src/analyzer/Block.pv"
                case EXPRESSION_DATA__VARIABLE: {
                    #line 41 "src/analyzer/Block.pv"
                    struct str var_name = expression->data.variable_value;
                    #line 42 "src/analyzer/Block.pv"
                    if (Context__broaden_if_narrowed(context, var_name)) {
                        #line 43 "src/analyzer/Block.pv"
                        struct Type* restored = Context__get_value(context, var_name);
                        #line 44 "src/analyzer/Block.pv"
                        if (restored != 0) {
                            #line 44 "src/analyzer/Block.pv"
                            expression->return_type = *restored;
                        }
                    }
                } break;
                #line 47 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        }

        #line 51 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 52 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 52 "src/analyzer/Block.pv"
            return false;
        }

        #line 54 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 55 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 55 "src/analyzer/Block.pv"
            return false;
        }

        #line 57 "src/analyzer/Block.pv"
        bool is_pointer_arithmetic = (Token__eq(operator, TOKEN_TYPE__SYMBOL, "+=") || Token__eq(operator, TOKEN_TYPE__SYMBOL, "-=")) && Type__is_pointer(&expression->return_type) && Type__is_number(&value->return_type);

        #line 59 "src/analyzer/Block.pv"
        if (!is_pointer_arithmetic) {
            #line 60 "src/analyzer/Block.pv"
            Expression__validate_type(value, context, &expression->return_type, true);
        }

        #line 63 "src/analyzer/Block.pv"
        struct AssignmentStatement* assignment = ArenaAllocator__store_AssignmentStatement(context->allocator, (struct AssignmentStatement[]){(struct AssignmentStatement) { .left = expression, .operator = operator, .right = value }});
        #line 64 "src/analyzer/Block.pv"
        *data = (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = assignment };
    } else {
        #line 66 "src/analyzer/Block.pv"
        *data = (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression };
    }

    #line 69 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 69 "src/analyzer/Block.pv"
        return false;
    }

    #line 71 "src/analyzer/Block.pv"
    return true;
}

#line 74 "src/analyzer/Block.pv"
bool Block__parse_keyword(struct Block* self, struct Context* context, struct Generics* generics, struct Token* first_token, struct StatementData* data) {
    #line 75 "src/analyzer/Block.pv"
    switch (str__Hash__hash(&first_token->value)) {
        #line 76 "src/analyzer/Block.pv"
        case 1329270083436697466ULL: {
            #line 77 "src/analyzer/Block.pv"
            struct LetStatement* let_statement = LetStatement__parse(context, generics);
            #line 78 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement };
            #line 79 "src/analyzer/Block.pv"
            return let_statement != 0;
        } break;
        #line 81 "src/analyzer/Block.pv"
        case 14251563519059995999ULL: {
            #line 82 "src/analyzer/Block.pv"
            struct ReturnStatement* ret = ReturnStatement__parse(context, generics);
            #line 83 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = ret };
            #line 84 "src/analyzer/Block.pv"
            return ret != 0;
        } break;
        #line 86 "src/analyzer/Block.pv"
        case 2964518896692351214ULL: {
            #line 87 "src/analyzer/Block.pv"
            struct YieldStatement* yield_stmt = YieldStatement__parse(context, generics);
            #line 88 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = yield_stmt };
            #line 89 "src/analyzer/Block.pv"
            return yield_stmt != 0;
        } break;
        #line 91 "src/analyzer/Block.pv"
        case 628023482707099174ULL: {
            #line 92 "src/analyzer/Block.pv"
            struct IfStatement* if_stmt = IfStatement__parse(context, generics);
            #line 93 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = if_stmt };
            #line 94 "src/analyzer/Block.pv"
            return if_stmt != 0;
        } break;
        #line 96 "src/analyzer/Block.pv"
        case 14105242855728223222ULL: {
            #line 97 "src/analyzer/Block.pv"
            struct MatchStatement* match_stmt = MatchStatement__parse(context, generics);
            #line 98 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = match_stmt };
            #line 99 "src/analyzer/Block.pv"
            return match_stmt != 0;
        } break;
        #line 101 "src/analyzer/Block.pv"
        case 14882043299657492846ULL: {
            #line 102 "src/analyzer/Block.pv"
            struct WhileStatement* while_stmt = WhileStatement__parse(context, generics);
            #line 103 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = while_stmt };
            #line 104 "src/analyzer/Block.pv"
            return while_stmt != 0;
        } break;
        #line 106 "src/analyzer/Block.pv"
        case 15902905282948881040ULL: {
            #line 107 "src/analyzer/Block.pv"
            struct ForStatement* for_statement = ForStatement__parse(self, context, generics);
            #line 108 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = for_statement };
            #line 109 "src/analyzer/Block.pv"
            return for_statement != 0;
        } break;
        #line 111 "src/analyzer/Block.pv"
        case 15186091406668687012ULL: {
            #line 112 "src/analyzer/Block.pv"
            Context__next_token(context);
            #line 113 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) };
            #line 114 "src/analyzer/Block.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";");
        } break;
        #line 116 "src/analyzer/Block.pv"
        case 10644074229358120504ULL: {
            #line 117 "src/analyzer/Block.pv"
            Context__next_token(context);
            #line 118 "src/analyzer/Block.pv"
            *data = (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) };
            #line 119 "src/analyzer/Block.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";");
        } break;
        #line 121 "src/analyzer/Block.pv"
        default: {
            #line 122 "src/analyzer/Block.pv"
            Context__error_token(context, first_token, "Unexpected keyword");
            #line 123 "src/analyzer/Block.pv"
            return false;
        } break;
    }
}

#line 128 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 129 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 129 "src/analyzer/Block.pv"
        return false;
    }
    #line 130 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 130 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 132 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 133 "src/analyzer/Block.pv"
        struct Token* first_token = Context__current(context);
        #line 134 "src/analyzer/Block.pv"
        struct StatementData data;
        #line 135 "src/analyzer/Block.pv"
        bool result = true;

        #line 137 "src/analyzer/Block.pv"
        if (Token__eq(first_token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 138 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 139 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, true);
            #line 140 "src/analyzer/Block.pv"
            data = (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block };
        } else if (Token__eq(first_token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 142 "src/analyzer/Block.pv"
            struct DeferStatement* defer_stmt = DeferStatement__parse(self, context, generics);
            #line 143 "src/analyzer/Block.pv"
            if (defer_stmt == 0) {
                #line 144 "src/analyzer/Block.pv"
                if (new_scope) {
                    #line 144 "src/analyzer/Block.pv"
                    Context__pop_scope(context);
                }
                #line 145 "src/analyzer/Block.pv"
                return false;
            }
            #line 147 "src/analyzer/Block.pv"
            Array_DeferStatement__append(&self->defer_statements, *defer_stmt);
            #line 148 "src/analyzer/Block.pv"
            continue;
        } else if (first_token->type == TOKEN_TYPE__KEYWORD) {
            #line 150 "src/analyzer/Block.pv"
            result = Block__parse_keyword(self, context, generics, first_token, &data);
        } else {
            #line 152 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics, &data);
        }

        #line 155 "src/analyzer/Block.pv"
        if (!result) {
            #line 156 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 156 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 157 "src/analyzer/Block.pv"
            return false;
        }

        #line 160 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), data));
    }

    #line 163 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 164 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 167 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 167 "src/analyzer/Block.pv"
        return false;
    }

    #line 169 "src/analyzer/Block.pv"
    return true;
}
