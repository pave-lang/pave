#ifndef PAVE_IF_STATEMENT
#define PAVE_IF_STATEMENT

#include <stdbool.h>

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

#include <std/str.h>
struct Context;
struct Expression;
struct Type;
struct Generics;
struct IfStatement;

#line 17 "src/analyzer/statement/IfStatement.pv"
struct Type* IfStatement__detect_null_narrowing(struct Context* context, struct Expression* expr, bool narrow_on_true);

#line 72 "src/analyzer/statement/IfStatement.pv"
struct str IfStatement__narrowed_var_name(struct Expression* expr);

#line 94 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics);

#endif
