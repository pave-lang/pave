#ifndef PAVE_YIELD_STATEMENT
#define PAVE_YIELD_STATEMENT

struct Expression;
struct YieldStatement;
struct Context;
struct Generics;

#line 5 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement {
    struct Expression* expression;
};

#line 10 "src/analyzer/statement/YieldStatement.pv"
struct YieldStatement* YieldStatement__parse(struct Context* context, struct Generics* generics);

#endif
