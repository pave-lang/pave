#ifndef PAVE_TRAIT_MAP_U32_I32
#define PAVE_TRAIT_MAP_U32_I32

#include <stdint.h>
#include <stdbool.h>


#line 1 "src/std/Map.pv"
struct trait_Map_u32_i32VTable {
    #line 2 "src/std/Map.pv"
    int32_t* (*fn_find)(void* __self, uint32_t* key);
    #line 3 "src/std/Map.pv"
    int32_t* (*fn_insert)(void* __self, uint32_t key, int32_t value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, uint32_t* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_u32_i32 {
    const struct trait_Map_u32_i32VTable* vtable;
    void* instance;
};

#endif
