#ifndef PAVE_TRAIT_MAP_STR_BOOL
#define PAVE_TRAIT_MAP_STR_BOOL

#include <stdbool.h>

#include <std/str.h>
struct str;

#line 1 "src/std/Map.pv"
struct trait_Map_str_boolVTable {
    #line 2 "src/std/Map.pv"
    bool* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    bool* (*fn_insert)(void* __self, struct str key, bool value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_bool {
    const struct trait_Map_str_boolVTable* vtable;
    void* instance;
};

#endif
