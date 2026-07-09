#ifndef PAVE_TRAIT_MAP_STR_REF_GLOBAL
#define PAVE_TRAIT_MAP_STR_REF_GLOBAL

#include <stdbool.h>

#include <std/trait_Map_str_ref_Global.h>
#include <std/str.h>
struct str;
struct Global;

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_GlobalVTable {
    #line 2 "src/std/Map.pv"
    struct Global** (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Global** (*fn_insert)(void* __self, struct str key, struct Global* value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_Global {
    const struct trait_Map_str_ref_GlobalVTable* vtable;
    void* instance;
};

#endif
