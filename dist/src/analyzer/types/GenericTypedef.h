#ifndef PAVE_GENERIC_TYPEDEF
#define PAVE_GENERIC_TYPEDEF

#include <std/str.h>
struct Generic;

#line 77 "src/analyzer/types/Type.pv"
struct GenericTypedef {
    struct Generic* generic;
    struct str typedef_name;
};

#endif
