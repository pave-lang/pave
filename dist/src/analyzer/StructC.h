#ifndef PAVE_STRUCT_C
#define PAVE_STRUCT_C

#include <std/str.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/StructCField.h>

struct Include;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 922 "src/analyzer/Include.pv"
struct StructC {
    struct Include* include;
    struct str name;
    struct HashMap_str_StructCField fields;
};

#line 929 "src/analyzer/Include.pv"
struct StructC* StructC__new(struct Include* include, char const* name);

#endif
