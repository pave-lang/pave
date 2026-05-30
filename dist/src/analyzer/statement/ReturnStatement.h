#ifndef PAVE_RETURN_STATEMENT
#define PAVE_RETURN_STATEMENT

struct Expression;

#line 6 "src/analyzer/statement/ReturnStatement.pv"
struct ReturnStatement {
    struct Expression* expression;
};

struct Context;
struct Generics;
struct ReturnStatement;

#line 11 "src/analyzer/statement/ReturnStatement.pv"
struct ReturnStatement* ReturnStatement__parse(struct Context* context, struct Generics* generics);

#endif
