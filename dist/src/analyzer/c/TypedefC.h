#ifndef PAVE_TYPEDEF_C
#define PAVE_TYPEDEF_C

#include <std/str.h>
struct Include;
struct Type;

#line 4 "src/analyzer/c/TypedefC.pv"
struct TypedefC {
    struct Include* include;
    struct str name;
    struct Type* type;
};

#include <std/str.h>
struct Include;
struct Type;
struct TypedefC;

#line 11 "src/analyzer/c/TypedefC.pv"
struct TypedefC* TypedefC__new(struct Include* include, struct str name, struct Type* type);

#endif
