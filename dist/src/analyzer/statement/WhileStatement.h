#ifndef PAVE_WHILE_STATEMENT
#define PAVE_WHILE_STATEMENT

struct Expression;
struct Block;

#line 6 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement {
    struct Expression* expression;
    struct Block* block;
};

struct Context;
struct Generics;

#line 12 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement* WhileStatement__parse(struct Context* context, struct Generics* generics);

#endif
