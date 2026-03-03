#ifndef PAVE_STATEMENT_DATA
#define PAVE_STATEMENT_DATA

#include <std/Array_DeferStatement.h>
#include <analyzer/DeferStatement.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/ElseStatement.h>
#include <std/Array_MatchCase.h>
#include <analyzer/MatchCase.h>

struct Block;
struct LetStatement;
struct Expression;
struct ForStatement;
struct Token;

#line 60 "src/analyzer/Statement.pv"
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
        struct { struct Expression* _0; struct Array_DeferStatement _1; } returnstatement_value;
        struct Expression* yieldstatement_value;
        struct { struct Expression* _0; struct Block* _1; struct Array_ElseStatement _2; } ifstatement_value;
        struct { struct Expression* _0; struct Array_MatchCase _1; } matchstatement_value;
        struct { struct Expression* _0; struct Block* _1; } whilestatement_value;
        struct ForStatement* forstatement_value;
        struct { struct Expression* _0; struct Token* _1; struct Expression* _2; } assignmentstatement_value;
        struct Expression* expressionstatement_value;
        struct Array_DeferStatement breakstatement_value;
        struct Array_DeferStatement continuestatement_value;
    };
};

#endif
