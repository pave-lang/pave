#ifndef PAVE_FUNCTION_TEMP
#define PAVE_FUNCTION_TEMP

#include <std/str.h>
struct Type;

#line 5 "src/compiler/FunctionContext.pv"
struct FunctionTemp {
    struct str name;
    struct Type* type;
};

#endif
