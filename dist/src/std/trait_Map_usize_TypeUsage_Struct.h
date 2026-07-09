#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_STRUCT
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Map_usize_TypeUsage_Struct.h>
#include <compiler/TypeUsage_Struct.h>
struct TypeUsage_Struct;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_StructVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_Struct* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_Struct* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_Struct value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_Struct {
    const struct trait_Map_usize_TypeUsage_StructVTable* vtable;
    void* instance;
};

#endif
