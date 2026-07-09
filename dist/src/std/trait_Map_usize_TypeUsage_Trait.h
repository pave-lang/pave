#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_TRAIT
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Map_usize_TypeUsage_Trait.h>
#include <compiler/TypeUsage_Trait.h>
struct TypeUsage_Trait;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_TraitVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_Trait* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_Trait* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_Trait value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_Trait {
    const struct trait_Map_usize_TypeUsage_TraitVTable* vtable;
    void* instance;
};

#endif
