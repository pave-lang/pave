#ifndef PAVE_ENUM_VARIANT_PARAMETER
#define PAVE_ENUM_VARIANT_PARAMETER

#include <stdbool.h>

#include <std/str.h>
struct Token;

#line 5 "src/analyzer/types/Enum.pv"
struct EnumVariantParameter {
    bool ref;
    struct Token* variable;
    struct str field_name;
};

#endif
