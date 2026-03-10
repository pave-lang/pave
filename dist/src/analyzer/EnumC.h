#ifndef PAVE_ENUM_C
#define PAVE_ENUM_C

#include <std/str.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/EnumCValue.h>

struct Include;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 873 "src/analyzer/Include.pv"
struct EnumC {
    struct Include* include;
    struct str name;
    struct HashMap_str_EnumCValue values;
};

#line 880 "src/analyzer/Include.pv"
struct EnumC* EnumC__new(struct Include* include, char const* name);

#endif
