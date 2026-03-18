#ifndef PAVE_ENUM_VARIANT_RESULT
#define PAVE_ENUM_VARIANT_RESULT

struct EnumVariant;
struct EnumCValue;

#line 4 "src/analyzer/expression/EnumVariantResult.pv"
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
