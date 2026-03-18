#ifndef PAVE_ENUM_C
#define PAVE_ENUM_C

#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/EnumCValue.h>

struct Include;
struct ParentCpp;

#line 3 "src/analyzer/c/EnumC.pv"
struct EnumC {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_EnumCValue values;
};

#line 11 "src/analyzer/c/EnumC.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
