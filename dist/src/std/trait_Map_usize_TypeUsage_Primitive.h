#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_PRIMITIVE
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_PRIMITIVE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Map_usize_TypeUsage_Primitive.h>
#include <compiler/TypeUsage_Primitive.h>
struct TypeUsage_Primitive;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_PrimitiveVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_Primitive* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_Primitive* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_Primitive value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_Primitive {
    const struct trait_Map_usize_TypeUsage_PrimitiveVTable* vtable;
    void* instance;
};

#endif
