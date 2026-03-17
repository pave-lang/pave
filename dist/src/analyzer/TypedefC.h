#ifndef PAVE_TYPEDEF_C
#define PAVE_TYPEDEF_C

#include <std/str.h>

struct Include;
struct Type;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 878 "src/analyzer/Include.pv"
struct TypedefC {
    struct Include* include;
    struct str name;
    struct Type* type;
};

#line 885 "src/analyzer/Include.pv"
struct TypedefC* TypedefC__new(struct Include* include, char const* name, struct Type* type);

#endif
