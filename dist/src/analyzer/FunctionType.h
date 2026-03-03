#ifndef PAVE_FUNCTION_TYPE
#define PAVE_FUNCTION_TYPE

#include <stdio.h>

#line 19 "src/analyzer/Function.pv"
enum FunctionType {
    FUNCTION_TYPE__STANDARD,
    FUNCTION_TYPE__COROUTINE,
    FUNCTION_TYPE__BUILTIN,
    FUNCTION_TYPE__METHOD_CPP,
};

#endif
