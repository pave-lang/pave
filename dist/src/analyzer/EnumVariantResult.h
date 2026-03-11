#ifndef PAVE_ENUM_VARIANT_RESULT
#define PAVE_ENUM_VARIANT_RESULT

#include <stdlib.h>

struct EnumVariant;
struct EnumCValue;

#line 37 "src/analyzer/Expression.pv"
struct EnumVariantResult {
    enum {
        ENUM_VARIANT_RESULT__NONE,
        ENUM_VARIANT_RESULT__ENUM_VARIANT,
        ENUM_VARIANT_RESULT__ENUM_CVALUE,
    } type;

    union {
        struct EnumVariant* enumvariant_value;
        struct EnumCValue* enumcvalue_value;
    };
};

#endif
