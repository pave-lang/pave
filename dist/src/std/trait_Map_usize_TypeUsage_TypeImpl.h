#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_TYPE_IMPL
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_TYPE_IMPL

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Map_usize_TypeUsage_TypeImpl.h>
#include <compiler/TypeUsage_TypeImpl.h>
struct TypeUsage_TypeImpl;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_TypeImplVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_TypeImpl* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_TypeImpl* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_TypeImpl value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_TypeImpl {
    const struct trait_Map_usize_TypeUsage_TypeImplVTable* vtable;
    void* instance;
};

#endif
