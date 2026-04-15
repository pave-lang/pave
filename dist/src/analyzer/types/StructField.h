#ifndef PAVE_STRUCT_FIELD
#define PAVE_STRUCT_FIELD

struct Token;
#include <analyzer/types/Type.h>

#line 4 "src/analyzer/types/Struct.pv"
struct StructField {
    struct Token* name;
    struct Type type;
};

#endif
