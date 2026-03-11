#ifndef PAVE_ENUM_C
#define PAVE_ENUM_C

#include <std/str.h>
#include <analyzer/ParentCpp.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/EnumCValue.h>

struct Include;
struct ParentCpp;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 895 "src/analyzer/Include.pv"
struct EnumC {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_EnumCValue values;
};

#line 903 "src/analyzer/Include.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
