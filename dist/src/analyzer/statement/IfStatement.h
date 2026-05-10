#ifndef PAVE_IF_STATEMENT
#define PAVE_IF_STATEMENT

#include <std/Array_ElseStatement.h>
struct MatchPattern;
struct Expression;
struct Block;

#line 6 "src/analyzer/statement/IfStatement.pv"
struct IfStatement {
    struct MatchPattern* pattern;
    struct Expression* expression;
    struct Block* block;
    struct Array_ElseStatement else_statements;
};

struct Context;
struct Generics;
struct IfStatement;

#line 14 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics);

#endif
