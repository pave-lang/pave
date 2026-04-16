#ifndef PAVE_MATCH_STATEMENT
#define PAVE_MATCH_STATEMENT

#include <std/Array_MatchCase.h>
struct Expression;

#line 7 "src/analyzer/statement/MatchStatement.pv"
struct MatchStatement {
    struct Expression* expression;
    struct Array_MatchCase cases;
};

struct Context;
struct Generics;
struct MatchStatement;

#line 13 "src/analyzer/statement/MatchStatement.pv"
struct MatchStatement* MatchStatement__parse(struct Context* context, struct Generics* generics);

#endif
