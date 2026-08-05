#ifndef PAVE_TRAIT_MAP_STR_USIZE
#define PAVE_TRAIT_MAP_STR_USIZE

#include <stdint.h>
#include <stdbool.h>

#include <std/str.h>
struct str;

#line 1 "src/std/Map.pv"
struct trait_Map_str_usizeVTable {
    #line 2 "src/std/Map.pv"
    uintptr_t* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    uintptr_t* (*fn_insert)(void* __self, struct str key, uintptr_t value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_usize {
    const struct trait_Map_str_usizeVTable* vtable;
    void* instance;
};

#endif
