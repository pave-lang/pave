#ifndef PAVE_TRAIT_MAP_STR_STR
#define PAVE_TRAIT_MAP_STR_STR

#include <stdbool.h>

#include <std/trait_Map_str_str.h>
#include <std/str.h>
struct str;

#line 1 "src/std/Map.pv"
struct trait_Map_str_strVTable {
    #line 2 "src/std/Map.pv"
    struct str* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct str* (*fn_insert)(void* __self, struct str key, struct str value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_str {
    const struct trait_Map_str_strVTable* vtable;
    void* instance;
};

#endif
