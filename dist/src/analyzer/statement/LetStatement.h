#ifndef PAVE_LET_STATEMENT
#define PAVE_LET_STATEMENT

#include <stdbool.h>

struct Token;
struct Type;
struct Expression;

#line 3 "src/analyzer/statement/LetStatement.pv"
struct LetStatement {
    bool is_static;
    struct Token* name;
    struct Type* type;
    struct Expression* value;
};

#endif
