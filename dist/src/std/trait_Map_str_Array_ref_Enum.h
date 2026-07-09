#ifndef PAVE_TRAIT_MAP_STR_ARRAY_REF_ENUM
#define PAVE_TRAIT_MAP_STR_ARRAY_REF_ENUM

#include <stdbool.h>

#include <std/trait_Map_str_Array_ref_Enum.h>
#include <std/str.h>
#include <std/Array_ref_Enum.h>
struct str;
struct Array_ref_Enum;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_ref_EnumVTable {
    #line 2 "src/std/Map.pv"
    struct Array_ref_Enum* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_ref_Enum* (*fn_insert)(void* __self, struct str key, struct Array_ref_Enum value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_ref_Enum {
    const struct trait_Map_str_Array_ref_EnumVTable* vtable;
    void* instance;
};

#endif
