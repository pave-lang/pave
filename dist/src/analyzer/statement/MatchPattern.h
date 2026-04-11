#ifndef PAVE_MATCH_PATTERN
#define PAVE_MATCH_PATTERN

#include <std/Array_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <analyzer/types/Type.h>
#include <stdbool.h>

struct Expression;
struct Type;
struct EnumVariant;
struct EnumCValue;
struct Context;
struct Generics;
struct MatchPattern;

#line 7 "src/analyzer/statement/MatchPattern.pv"
struct MatchPattern {
    enum {
        MATCH_PATTERN__DEFAULT,
        MATCH_PATTERN__STATIC_VALUE,
        MATCH_PATTERN__ENUM_VARIANT,
        MATCH_PATTERN__ENUM_CVALUE,
        MATCH_PATTERN__TYPE_ID,
    } type;

    union {
        struct Expression* staticvalue_value;
        struct { struct Type* _0; struct EnumVariant* _1; struct Array_EnumVariantParameter _2; } enumvariant_value;
        struct EnumCValue* enumcvalue_value;
        struct Type typeid_value;
    };
};

#line 16 "src/analyzer/statement/MatchPattern.pv"
bool MatchPattern__parse(struct Context* context, struct Generics* generics, struct MatchPattern* pattern);

#endif
