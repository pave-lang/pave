#ifndef PAVE_NULL_NARROWING
#define PAVE_NULL_NARROWING

#include <std/str.h>
struct Type;

#line 5 "src/analyzer/expression/BinaryExpression.pv"
struct NullNarrowing {
    struct str path;
    struct Type* type;
};

#endif
