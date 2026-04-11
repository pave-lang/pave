#ifndef PAVE_LET_STATEMENT
#define PAVE_LET_STATEMENT

#include <stdbool.h>

struct Token;
struct Type;
struct Expression;
struct LetStatement;
struct Context;
struct Generics;

#line 5 "src/analyzer/statement/LetStatement.pv"
struct LetStatement {
    bool is_static;
    struct Token* name;
    struct Type* type;
    struct Expression* value;
};

#line 13 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse(struct Context* context, struct Generics* generics);

#endif
