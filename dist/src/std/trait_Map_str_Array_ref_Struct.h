#ifndef PAVE_TRAIT_MAP_STR_ARRAY_REF_STRUCT
#define PAVE_TRAIT_MAP_STR_ARRAY_REF_STRUCT

#include <stdbool.h>

#include <std/trait_Map_str_Array_ref_Struct.h>
#include <std/str.h>
#include <std/Array_ref_Struct.h>
struct str;
struct Array_ref_Struct;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_ref_StructVTable {
    #line 2 "src/std/Map.pv"
    struct Array_ref_Struct* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_ref_Struct* (*fn_insert)(void* __self, struct str key, struct Array_ref_Struct value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_ref_Struct {
    const struct trait_Map_str_Array_ref_StructVTable* vtable;
    void* instance;
};

#endif
