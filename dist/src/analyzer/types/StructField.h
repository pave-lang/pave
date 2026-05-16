#ifndef PAVE_STRUCT_FIELD
#define PAVE_STRUCT_FIELD

#include <stdint.h>

#include <analyzer/types/Type.h>
struct Token;

#line 4 "src/analyzer/types/Struct.pv"
struct StructField {
    struct Token* name;
    struct Type type;
    uintptr_t default_token_start;
};

#endif
