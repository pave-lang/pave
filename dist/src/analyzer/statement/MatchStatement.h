#ifndef PAVE_MATCH_STATEMENT
#define PAVE_MATCH_STATEMENT

#include <std/Array_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <stdbool.h>

struct Expression;
struct Context;
struct Generics;
struct MatchPattern;
struct MatchStatement;

#line 7 "src/analyzer/statement/MatchStatement.pv"
struct MatchStatement {
    struct Expression* expression;
    struct Array_MatchCase cases;
};

#line 13 "src/analyzer/statement/MatchStatement.pv"
bool MatchStatement__parse_pattern(struct Context* context, struct Generics* generics, struct MatchPattern* pattern);

#line 148 "src/analyzer/statement/MatchStatement.pv"
struct MatchStatement* MatchStatement__parse(struct Context* context, struct Generics* generics);

#endif
