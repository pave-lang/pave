#ifndef PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_SEQUENCE
#define PAVE_TRAIT_MAP_USIZE_TYPE_USAGE_SEQUENCE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Map_usize_TypeUsage_Sequence.h>
#include <compiler/TypeUsage_Sequence.h>
struct TypeUsage_Sequence;

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_SequenceVTable {
    #line 2 "src/std/Map.pv"
    struct TypeUsage_Sequence* (*fn_find)(void* __self, uintptr_t* key);
    #line 3 "src/std/Map.pv"
    struct TypeUsage_Sequence* (*fn_insert)(void* __self, uintptr_t key, struct TypeUsage_Sequence value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uintptr_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_usize_TypeUsage_Sequence {
    const struct trait_Map_usize_TypeUsage_SequenceVTable* vtable;
    void* instance;
};

#endif
