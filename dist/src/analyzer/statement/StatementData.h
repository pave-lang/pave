#ifndef PAVE_STATEMENT_DATA
#define PAVE_STATEMENT_DATA

#include <std/Array_DeferStatement.h>
struct Block;
struct LetStatement;
struct ReturnStatement;
struct YieldStatement;
struct IfStatement;
struct MatchStatement;
struct WhileStatement;
struct ForStatement;
struct AssignmentStatement;
struct Expression;
#line 5 "src/analyzer/statement/StatementData.pv"
struct StatementData {
    enum {
        STATEMENT_DATA__BLOCK_STATEMENT,
        STATEMENT_DATA__LET_STATEMENT,
        STATEMENT_DATA__RETURN_STATEMENT,
        STATEMENT_DATA__YIELD_STATEMENT,
        STATEMENT_DATA__IF_STATEMENT,
        STATEMENT_DATA__MATCH_STATEMENT,
        STATEMENT_DATA__WHILE_STATEMENT,
        STATEMENT_DATA__FOR_STATEMENT,
        STATEMENT_DATA__ASSIGNMENT_STATEMENT,
        STATEMENT_DATA__EXPRESSION_STATEMENT,
        STATEMENT_DATA__BREAK_STATEMENT,
        STATEMENT_DATA__CONTINUE_STATEMENT,
    } type;

    union {
        struct Block* blockstatement_value;
        struct LetStatement* letstatement_value;
        struct ReturnStatement* returnstatement_value;
        struct YieldStatement* yieldstatement_value;
        struct IfStatement* ifstatement_value;
        struct MatchStatement* matchstatement_value;
        struct WhileStatement* whilestatement_value;
        struct ForStatement* forstatement_value;
        struct AssignmentStatement* assignmentstatement_value;
        struct Expression* expressionstatement_value;
        struct Array_DeferStatement breakstatement_value;
        struct Array_DeferStatement continuestatement_value;
    };
};


#endif
