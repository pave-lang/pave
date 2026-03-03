#ifndef PAVE_ELSE_STATEMENT
#define PAVE_ELSE_STATEMENT

struct Expression;
struct Block;

#line 16 "src/analyzer/Statement.pv"
struct ElseStatement {
    struct Expression* expression;
    struct Block* block;
};

#endif
