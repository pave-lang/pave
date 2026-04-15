#ifndef PAVE_PARAMETER
#define PAVE_PARAMETER

#include <stdio.h>

struct Token;
#include <analyzer/types/Type.h>

#line 6 "src/analyzer/types/Function.pv"
struct Parameter {
    struct Token* name;
    struct Type type;
};

#endif
