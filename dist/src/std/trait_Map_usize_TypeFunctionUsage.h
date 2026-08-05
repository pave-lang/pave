#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_TRAIT_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>
#include <stdbool.h>

#include <compiler/TypeFunctionUsage.h>
struct TypeFunctionUsage;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeFunctionUsageVTable {
    #line 2 "src/std/Map.pv"
    struct TypeFunctionUsage* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeFunctionUsage* (*fn_insert)(void* __self, uintptr_t key, struct TypeFunctionUsage value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeFunctionUsage {
    const struct trait_Map_usize_TypeFunctionUsageVTable* vtable;
    void* instance;
};

#endif
