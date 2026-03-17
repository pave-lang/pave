#ifndef PAVE_ELSE_STATEMENT
#define PAVE_ELSE_STATEMENT

struct Expression;
struct Block;

#line 3 "src/analyzer/statement/ElseStatement.pv"
struct ElseStatement {
    struct Expression* expression;
    struct Block* block;
};

#endif
