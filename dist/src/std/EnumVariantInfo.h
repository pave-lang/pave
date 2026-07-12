#ifndef PAVE_ENUM_VARIANT_INFO
#define PAVE_ENUM_VARIANT_INFO

#include <stdint.h>

#include <std/str.h>

#line 1 "src/std/Enum.pv"
struct EnumVariantInfo {
    uintptr_t index;
    struct str key;
    struct str label;
};

#endif
