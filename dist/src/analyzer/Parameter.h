#ifndef PAVE_PARAMETER
#define PAVE_PARAMETER

#include <analyzer/Type.h>

struct Token;

#include <stdio.h>

#line 5 "src/analyzer/Function.pv"
struct Parameter {
    struct Token* name;
    struct Type type;
};

#endif
