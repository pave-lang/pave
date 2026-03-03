#ifndef PAVE_INVOKE_ARGUMENT
#define PAVE_INVOKE_ARGUMENT

struct Token;
struct Expression;

#include <stdlib.h>

#line 5 "src/analyzer/Expression.pv"
struct InvokeArgument {
    struct Token* name;
    struct Expression* value;
};

#endif
