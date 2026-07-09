#ifndef PAVE_TRAIT_MAP_STR_REF_IMPL_CONST
#define PAVE_TRAIT_MAP_STR_REF_IMPL_CONST

#include <stdbool.h>

#include <std/trait_Map_str_ref_ImplConst.h>
#include <std/str.h>
struct str;
struct ImplConst;

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_ImplConstVTable {
    #line 2 "src/std/Map.pv"
    struct ImplConst** (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct ImplConst** (*fn_insert)(void* __self, struct str key, struct ImplConst* value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_ImplConst {
    const struct trait_Map_str_ref_ImplConstVTable* vtable;
    void* instance;
};

#endif
