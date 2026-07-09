#ifndef PAVE_TRAIT_MAP_U32_TYPE
#define PAVE_TRAIT_MAP_U32_TYPE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Map_u32_Type.h>
#include <analyzer/types/Type.h>
struct Type;

#line 1 "src/std/Map.pv"
struct trait_Map_u32_TypeVTable {
    #line 2 "src/std/Map.pv"
    struct Type* (*fn_find)(void* __self, uint32_t* key);
    #line 3 "src/std/Map.pv"
    struct Type* (*fn_insert)(void* __self, uint32_t key, struct Type value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uint32_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_u32_Type {
    const struct trait_Map_u32_TypeVTable* vtable;
    void* instance;
};

#endif
