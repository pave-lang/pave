#ifndef PAVE_ENUM_C
#define PAVE_ENUM_C

struct Include;
#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_EnumCValue.h>

#line 3 "src/analyzer/c/EnumC.pv"
struct EnumC {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_EnumCValue values;
};
struct Include;
struct EnumC;
#include <analyzer/c/ParentCpp.h>


#line 11 "src/analyzer/c/EnumC.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
