#ifndef PAVE_INVOKE_ARGUMENT
#define PAVE_INVOKE_ARGUMENT

struct Token;
struct Expression;

#line 3 "src/analyzer/expression/InvokeArgument.pv"
struct InvokeArgument {
    struct Token* name;
    struct Expression* value;
};

#endif
