#ifndef PAVE_TRAIT_MAP_STR_ARRAY_TYPE
#define PAVE_TRAIT_MAP_STR_ARRAY_TYPE

#include <stdbool.h>

#include <std/trait_Map_str_Array_Type.h>
#include <std/str.h>
#include <std/Array_Type.h>
struct str;
struct Array_Type;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_TypeVTable {
    #line 2 "src/std/Map.pv"
    struct Array_Type* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_Type* (*fn_insert)(void* __self, struct str key, struct Array_Type value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_Type {
    const struct trait_Map_str_Array_TypeVTable* vtable;
    void* instance;
};

#endif
