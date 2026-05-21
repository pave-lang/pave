#ifndef PAVE_ENUM_CVALUE
#define PAVE_ENUM_CVALUE

#include <stdint.h>

#include <std/str.h>
struct EnumC;

#line 3 "src/analyzer/c/EnumCValue.pv"
struct EnumCValue {
    struct EnumC* parent;
    struct str name;
    int64_t value;
};

#endif
