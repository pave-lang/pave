#ifndef PAVE_ENUM_VARIANT
#define PAVE_ENUM_VARIANT

#include <std/Array_Type.h>
#include <analyzer/Type.h>

struct Token;
struct Enum;
struct Expression;

#line 8 "src/analyzer/Enum.pv"
struct EnumVariant {
    struct Token* name;
    struct Array_Type types;
    struct Enum* parent;
    struct Expression* value;
};

#endif
