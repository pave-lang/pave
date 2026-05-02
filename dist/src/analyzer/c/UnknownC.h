#ifndef PAVE_UNKNOWN_C
#define PAVE_UNKNOWN_C

#include <std/str.h>
#include <std/Array_Type.h>
struct Include;

#line 4 "src/analyzer/c/UnknownC.pv"
struct UnknownC {
    struct Include* include;
    struct str name;
    struct Array_Type generics;
};

struct Include;
struct UnknownC;

#line 11 "src/analyzer/c/UnknownC.pv"
struct UnknownC* UnknownC__new(struct Include* include, char const* name);

#endif
