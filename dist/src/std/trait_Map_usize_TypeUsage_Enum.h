#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_ENUM
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <compiler/TypeUsage_Enum.h>
struct TypeUsage_Enum;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_EnumVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_Enum* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_Enum* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_Enum value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_Enum {
    const struct trait_Map_usize_TypeUsage_EnumVTable* vtable;
    void* instance;
};

#endif
