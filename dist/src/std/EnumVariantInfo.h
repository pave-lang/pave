#ifndef PAVE_ENUM_VARIANT_INFO
#define PAVE_ENUM_VARIANT_INFO

#include <stdint.h>

#include <std/str.h>
#include <std/EnumVariantKind.h>
#include <slice_EnumVariantParamInfo.h>

#line 14 "src/std/Enum.pv"
struct EnumVariantInfo {
    uintptr_t index;
    struct str key;
    struct str label;
    enum EnumVariantKind kind;
    struct slice_EnumVariantParamInfo params;
};

#endif
