#ifndef PAVE_STRUCT_C
#define PAVE_STRUCT_C

struct Include;
#include <std/str.h>
#include <std/HashMap_str_StructCField.h>

#line 3 "src/analyzer/c/StructC.pv"
struct StructC {
    struct Include* include;
    struct str name;
    struct HashMap_str_StructCField fields;
};
struct Include;
struct StructC;


#line 10 "src/analyzer/c/StructC.pv"
struct StructC* StructC__new(struct Include* include, char const* name);

#endif
