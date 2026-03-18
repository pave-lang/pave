#ifndef PAVE_FUNCTION_TYPE
#define PAVE_FUNCTION_TYPE

#include <stdio.h>

#line 20 "src/analyzer/types/Function.pv"
enum FunctionType {
    FUNCTION_TYPE__STANDARD,
    FUNCTION_TYPE__COROUTINE,
    FUNCTION_TYPE__BUILTIN,
    FUNCTION_TYPE__METHOD_CPP,
};

#endif
