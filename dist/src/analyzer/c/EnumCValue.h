#ifndef PAVE_ENUM_CVALUE
#define PAVE_ENUM_CVALUE

struct EnumC;
#include <std/str.h>

#line 3 "src/analyzer/c/EnumCValue.pv"
struct EnumCValue {
    struct EnumC* parent;
    struct str name;
};

#endif
