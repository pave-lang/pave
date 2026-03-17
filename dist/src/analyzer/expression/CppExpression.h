#ifndef PAVE_CPP_EXPRESSION
#define PAVE_CPP_EXPRESSION

struct Expression;

#line 1 "src/analyzer/expression/CppExpression.pv"
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
