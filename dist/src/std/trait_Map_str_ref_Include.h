#ifndef PAVE_TRAIT_MAP_STR_REF_INCLUDE
#define PAVE_TRAIT_MAP_STR_REF_INCLUDE

#include <stdbool.h>

#include <std/trait_Map_str_ref_Include.h>
#include <std/str.h>
struct str;
struct Include;

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_IncludeVTable {
    #line 2 "src/std/Map.pv"
    struct Include** (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Include** (*fn_insert)(void* __self, struct str key, struct Include* value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_Include {
    const struct trait_Map_str_ref_IncludeVTable* vtable;
    void* instance;
};

#endif
