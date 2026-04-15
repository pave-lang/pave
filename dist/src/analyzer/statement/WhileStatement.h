#ifndef PAVE_WHILE_STATEMENT
#define PAVE_WHILE_STATEMENT

struct Expression;
struct Block;

#line 5 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement {
    struct Expression* expression;
    struct Block* block;
};

struct Context;
struct Generics;
struct WhileStatement;

#line 11 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement* WhileStatement__parse(struct Context* context, struct Generics* generics);

#endif
