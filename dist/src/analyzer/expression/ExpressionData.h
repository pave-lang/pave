#ifndef PAVE_EXPRESSION_DATA
#define PAVE_EXPRESSION_DATA

#include <std/str.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>

struct EnumVariant;
struct Type;
struct Expression;

#line 5 "src/analyzer/expression/ExpressionData.pv"
struct ExpressionData {
    enum {
        EXPRESSION_DATA__ENUM_VARIANT,
        EXPRESSION_DATA__TYPE,
        EXPRESSION_DATA__LITERAL,
        EXPRESSION_DATA__VARIABLE,
        EXPRESSION_DATA__BINARY_EXPRESSION,
        EXPRESSION_DATA__UNARY_EXPRESSION,
        EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION,
        EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION,
        EXPRESSION_DATA__INDEX_EXPRESSION,
        EXPRESSION_DATA__PARENTHESIZED_EXPRESSION,
        EXPRESSION_DATA__CPP_EXPRESSION,
        EXPRESSION_DATA__IMPLICIT_CAST,
        EXPRESSION_DATA__INVOKE,
    } type;

    union {
        struct EnumVariant* enumvariant_value;
        struct Type* type_value;
        struct str literal_value;
        struct str variable_value;
        struct { struct Expression* _0; struct str _1; struct Expression* _2; } binaryexpression_value;
        struct { struct str _0; struct Expression* _1; } unaryexpression_value;
        struct { struct Expression* _0; struct str _1; } memberstaticexpression_value;
        struct { struct Expression* _0; struct str _1; } memberinstanceexpression_value;
        struct { struct Expression* _0; struct Expression* _1; } indexexpression_value;
        struct Expression* parenthesizedexpression_value;
        struct CppExpression cppexpression_value;
        struct Expression* implicitcast_value;
        struct { struct Expression* _0; struct Array_InvokeArgument _1; } invoke_value;
    };
};

#endif
