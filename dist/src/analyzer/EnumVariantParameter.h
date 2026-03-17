#ifndef PAVE_ENUM_VARIANT_PARAMETER
#define PAVE_ENUM_VARIANT_PARAMETER

#include <stdbool.h>

struct Token;

#line 4 "src/analyzer/Enum.pv"
struct EnumVariantParameter {
    bool ref;
    struct Token* variable;
};

#endif
