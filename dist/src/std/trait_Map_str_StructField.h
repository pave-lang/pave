#ifndef PAVE_TRAIT_MAP_STR_STRUCT_FIELD
#define PAVE_TRAIT_MAP_STR_STRUCT_FIELD

#include <stdbool.h>

#include <std/str.h>
#include <analyzer/types/StructField.h>
struct str;
struct StructField;

#line 1 "src/std/Map.pv"
struct trait_Map_str_StructFieldVTable {
    #line 2 "src/std/Map.pv"
    struct StructField* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct StructField* (*fn_insert)(void* __self, struct str key, struct StructField value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_StructField {
    const struct trait_Map_str_StructFieldVTable* vtable;
    void* instance;
};

#endif
