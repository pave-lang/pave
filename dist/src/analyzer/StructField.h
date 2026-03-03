#ifndef PAVE_STRUCT_FIELD
#define PAVE_STRUCT_FIELD

#include <analyzer/Type.h>

struct Token;

#line 3 "src/analyzer/Struct.pv"
struct StructField {
    struct Token* name;
    struct Type type;
};

#endif
