#ifndef PAVE_ENUM_C
#define PAVE_ENUM_C

#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_EnumCValue.h>
struct Include;

#line 3 "src/analyzer/c/EnumC.pv"
struct EnumC {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_EnumCValue values;
};

#include <analyzer/c/ParentCpp.h>
struct Include;
struct EnumC;

#line 11 "src/analyzer/c/EnumC.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
