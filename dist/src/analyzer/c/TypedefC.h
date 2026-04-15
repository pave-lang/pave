#ifndef PAVE_TYPEDEF_C
#define PAVE_TYPEDEF_C

struct Include;
struct Type;
#include <std/str.h>

#line 4 "src/analyzer/c/TypedefC.pv"
struct TypedefC {
    struct Include* include;
    struct str name;
    struct Type* type;
};
struct Include;
struct Type;
struct TypedefC;


#line 11 "src/analyzer/c/TypedefC.pv"
struct TypedefC* TypedefC__new(struct Include* include, char const* name, struct Type* type);

#endif
