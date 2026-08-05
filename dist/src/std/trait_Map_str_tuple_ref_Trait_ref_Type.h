#ifndef PAVE_TRAIT_MAP_STR_TUPLE_REF_TRAIT_REF_TYPE
#define PAVE_TRAIT_MAP_STR_TUPLE_REF_TRAIT_REF_TYPE

#include <stdbool.h>

#include <std/str.h>
#include <tuple_ref_Trait_ref_Type.h>
struct str;

#line 1 "src/std/Map.pv"
struct trait_Map_str_tuple_ref_Trait_ref_TypeVTable {
    #line 2 "src/std/Map.pv"
    struct tuple_ref_Trait_ref_Type* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct tuple_ref_Trait_ref_Type* (*fn_insert)(void* __self, struct str key, struct tuple_ref_Trait_ref_Type value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_tuple_ref_Trait_ref_Type {
    const struct trait_Map_str_tuple_ref_Trait_ref_TypeVTable* vtable;
    void* instance;
};

#endif
