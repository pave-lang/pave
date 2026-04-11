#ifndef PAVE_RETURN_STATEMENT
#define PAVE_RETURN_STATEMENT

#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>

struct Expression;
struct ReturnStatement;
struct Context;
struct Generics;

#line 6 "src/analyzer/statement/ReturnStatement.pv"
struct ReturnStatement {
    struct Expression* expression;
    struct Array_DeferStatement defer_statements;
};

#line 12 "src/analyzer/statement/ReturnStatement.pv"
struct ReturnStatement* ReturnStatement__parse(struct Context* context, struct Generics* generics);

#endif
