#ifndef PAVE_TRAIT_MAP_STR_ARRAY_REF_TRAIT
#define PAVE_TRAIT_MAP_STR_ARRAY_REF_TRAIT

#include <stdbool.h>

#include <std/trait_Map_str_Array_ref_Trait.h>
#include <std/str.h>
#include <std/Array_ref_Trait.h>
struct str;
struct Array_ref_Trait;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_ref_TraitVTable {
    #line 2 "src/std/Map.pv"
    struct Array_ref_Trait* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_ref_Trait* (*fn_insert)(void* __self, struct str key, struct Array_ref_Trait value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_ref_Trait {
    const struct trait_Map_str_Array_ref_TraitVTable* vtable;
    void* instance;
};

#endif
