#ifndef PAVE_STRUCT_C
#define PAVE_STRUCT_C

#include <std/str.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/c/StructCField.h>

struct Include;

#line 3 "src/analyzer/c/StructC.pv"
struct StructC {
    struct Include* include;
    struct str name;
    struct HashMap_str_StructCField fields;
};

#line 10 "src/analyzer/c/StructC.pv"
struct StructC* StructC__new(struct Include* include, char const* name);

#endif
