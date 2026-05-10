#ifndef PAVE_ELSE_STATEMENT
#define PAVE_ELSE_STATEMENT

struct MatchPattern;
struct Expression;
struct Block;

#line 4 "src/analyzer/statement/ElseStatement.pv"
struct ElseStatement {
    struct MatchPattern* pattern;
    struct Expression* expression;
    struct Block* block;
};

#endif
