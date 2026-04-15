#ifndef PAVE_ENUM_VARIANT
#define PAVE_ENUM_VARIANT

struct Token;
struct Enum;
struct Expression;
#include <std/Array_Type.h>

#line 10 "src/analyzer/types/Enum.pv"
struct EnumVariant {
    struct Token* name;
    struct Array_Type types;
    struct Enum* parent;
    struct Expression* value;
};

#endif
