#ifndef PAVE_FUNCTION_C
#define PAVE_FUNCTION_C

#include <std/str.h>
#include <std/Array_ref_Expression.h>
#include <analyzer/Type.h>

struct Include;
struct Expression;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 797 "src/analyzer/Include.pv"
struct FunctionC {
    struct Include* include;
    struct str name;
    struct Array_ref_Expression arguments;
    struct Type return_type;
};

#line 805 "src/analyzer/Include.pv"
struct FunctionC* FunctionC__new(struct Include* include, char const* name);

#endif
