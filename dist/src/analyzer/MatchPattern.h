#ifndef PAVE_MATCH_PATTERN
#define PAVE_MATCH_PATTERN

#include <std/Array_EnumVariantParameter.h>
#include <analyzer/EnumVariantParameter.h>

struct EnumVariant;
struct Token;

#line 3 "src/analyzer/Statement.pv"
struct MatchPattern {
    enum {
        MATCH_PATTERN__ENUM_VARIANT,
        MATCH_PATTERN__ENUM_CVALUE,
        MATCH_PATTERN__DEFAULT,
    } type;

    union {
        struct { struct EnumVariant* _0; struct Array_EnumVariantParameter _1; } enumvariant_value;
        struct Token* enumcvalue_value;
    };
};

#endif
