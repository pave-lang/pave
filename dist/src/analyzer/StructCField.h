#ifndef PAVE_STRUCT_CFIELD
#define PAVE_STRUCT_CFIELD

#include <std/str.h>
#include <analyzer/Type.h>

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 801 "src/analyzer/Include.pv"
struct StructCField {
    struct str name;
    struct Type type;
};

#endif
