#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_TUPLE
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_TUPLE

#include <stdint.h>
#include <stdbool.h>

#include <compiler/TypeUsage_Tuple.h>
struct TypeUsage_Tuple;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_TupleVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_Tuple* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_Tuple* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_Tuple value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_Tuple {
    const struct trait_Map_usize_TypeUsage_TupleVTable* vtable;
    void* instance;
};

#endif
