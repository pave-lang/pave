#ifndef PAVE_TRAIT_MAP_STR_STRUCT_CFIELD
#define PAVE_TRAIT_MAP_STR_STRUCT_CFIELD

#include <stdbool.h>

#include <std/str.h>
#include <analyzer/c/StructCField.h>
struct str;
struct StructCField;

#line 1 "src/std/Map.pv"
struct trait_Map_str_StructCFieldVTable {
    #line 2 "src/std/Map.pv"
    struct StructCField* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct StructCField* (*fn_insert)(void* __self, struct str key, struct StructCField value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_StructCField {
    const struct trait_Map_str_StructCFieldVTable* vtable;
    void* instance;
};

#endif
