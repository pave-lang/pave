#ifndef PAVE_PARAMETER
#define PAVE_PARAMETER

#include <analyzer/types/Type.h>
struct Token;

#line 6 "src/analyzer/types/Function.pv"
struct Parameter {
    struct Token* name;
    struct Type type;
};

#endif
