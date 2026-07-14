#ifndef PAVE_ENUM_VARIANT_PARAM_INFO
#define PAVE_ENUM_VARIANT_PARAM_INFO

#include <stdint.h>

#include <std/str.h>
#include <std/TypeId.h>

#line 7 "src/std/Enum.pv"
struct EnumVariantParamInfo {
    uintptr_t index;
    struct str name;
    TypeId type_id;
    char const* type_name;
};

#endif
