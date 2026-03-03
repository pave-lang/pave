#ifndef PAVE_CPP_EXPRESSION
#define PAVE_CPP_EXPRESSION

#include <stdlib.h>

struct Expression;

#line 10 "src/analyzer/Expression.pv"
struct CppExpression {
    enum {
        CPP_EXPRESSION__NEW,
        CPP_EXPRESSION__DELETE,
    } type;

    union {
        struct { struct Expression* _0; struct Expression* _1; } new_value;
        struct Expression* delete_value;
    };
};

#endif
