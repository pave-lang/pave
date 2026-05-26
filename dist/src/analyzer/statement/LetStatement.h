#ifndef PAVE_LET_STATEMENT
#define PAVE_LET_STATEMENT

#include <stdbool.h>

#include <std/Array_DestructureBinding.h>
struct Token;
struct Type;
struct Expression;

#line 11 "src/analyzer/statement/LetStatement.pv"
struct LetStatement {
    bool is_static;
    struct Token* name;
    struct Type* type;
    struct Expression* value;
    struct Array_DestructureBinding destructure;
};

struct Context;
struct Generics;
struct LetStatement;
struct Token;

#line 20 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse(struct Context* context, struct Generics* generics);

#line 96 "src/analyzer/statement/LetStatement.pv"
struct LetStatement* LetStatement__parse_destructure(struct Context* context, struct Generics* generics, struct Token* first_token, bool is_static);

#endif
