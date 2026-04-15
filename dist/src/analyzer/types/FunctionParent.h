#ifndef PAVE_FUNCTION_PARENT
#define PAVE_FUNCTION_PARENT

#include <stdint.h>

#include <stdio.h>

struct Primitive;
struct Trait;
struct Enum;
struct Struct;
struct Type;
#line 11 "src/analyzer/types/Function.pv"
struct FunctionParent {
    enum {
        FUNCTION_PARENT__NONE,
        FUNCTION_PARENT__PRIMITIVE,
        FUNCTION_PARENT__ENUM,
        FUNCTION_PARENT__STRUCT,
        FUNCTION_PARENT__TRAIT,
        FUNCTION_PARENT__TYPE,
    } type;

    union {
        struct { struct Primitive* _0; uintptr_t _1; struct Trait* _2; } primitive_value;
        struct { struct Enum* _0; uintptr_t _1; struct Trait* _2; } enum_value;
        struct { struct Struct* _0; uintptr_t _1; struct Trait* _2; } struct_value;
        struct Trait* trait_value;
        struct { struct Type* _0; uintptr_t _1; struct Trait* _2; } type_value;
    };
};


#endif
