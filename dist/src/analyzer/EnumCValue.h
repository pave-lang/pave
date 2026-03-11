#ifndef PAVE_ENUM_CVALUE
#define PAVE_ENUM_CVALUE

#include <std/str.h>

struct EnumC;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 915 "src/analyzer/Include.pv"
struct EnumCValue {
    struct EnumC* parent;
    struct str name;
};

#endif
