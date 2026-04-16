#ifndef PAVE_ENUM_VARIANT_RESULT
#define PAVE_ENUM_VARIANT_RESULT

struct EnumVariant;
struct EnumCValue;
struct Function;
struct GenericMap;
#line 5 "src/analyzer/expression/EnumVariantResult.pv"
struct EnumVariantResult {
    enum {
        ENUM_VARIANT_RESULT__NONE,
        ENUM_VARIANT_RESULT__ENUM_VARIANT,
        ENUM_VARIANT_RESULT__ENUM_CVALUE,
        ENUM_VARIANT_RESULT__FUNCTION,
    } type;

    union {
        struct EnumVariant* enumvariant_value;
        struct EnumCValue* enumcvalue_value;
        struct { struct Function* _0; struct GenericMap* _1; } function_value;
    };
};


#endif
