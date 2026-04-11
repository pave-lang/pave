#ifndef PAVE_WHILE_STATEMENT
#define PAVE_WHILE_STATEMENT

struct Expression;
struct Block;
struct WhileStatement;
struct Context;
struct Generics;

#line 5 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement {
    struct Expression* expression;
    struct Block* block;
};

#line 11 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement* WhileStatement__parse(struct Context* context, struct Generics* generics);

#endif
