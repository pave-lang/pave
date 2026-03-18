#ifndef PAVE_MATCH_PATTERN
#define PAVE_MATCH_PATTERN

#include <std/Array_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>

struct Token;
struct EnumVariant;
struct EnumCValue;
struct Expression;

#line 6 "src/analyzer/statement/MatchPattern.pv"
struct MatchPattern {
    enum {
        MATCH_PATTERN__DEFAULT,
        MATCH_PATTERN__STATIC_VALUE,
        MATCH_PATTERN__ENUM_VARIANT,
        MATCH_PATTERN__ENUM_CVALUE,
        MATCH_PATTERN__EXPRESSION,
    } type;

    union {
        struct Token* staticvalue_value;
        struct { struct EnumVariant* _0; struct Array_EnumVariantParameter _1; } enumvariant_value;
        struct EnumCValue* enumcvalue_value;
        struct Expression* expression_value;
    };
};

#endif
