#ifndef PAVE_FUNCTION_C
#define PAVE_FUNCTION_C

#include <std/str.h>
#include <std/Array_ref_Expression.h>
#include <analyzer/types/Type.h>

struct Include;
struct Expression;
struct Type;

#line 5 "src/analyzer/c/FunctionC.pv"
struct FunctionC {
    struct Include* include;
    struct str name;
    struct Array_ref_Expression arguments;
    struct Type return_type;
};

#line 13 "src/analyzer/c/FunctionC.pv"
struct FunctionC* FunctionC__new(struct Include* include, char const* name, struct Type* return_type);

#endif
