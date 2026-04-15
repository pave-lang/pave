#ifndef PAVE_YIELD_STATEMENT
#define PAVE_YIELD_STATEMENT

struct Expression;

#line 5 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement {
    struct Expression* expression;
};

struct Context;
struct Generics;
struct YieldStatement;

#line 10 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement* YieldStatement__parse(struct Context* context, struct Generics* generics);

#endif
