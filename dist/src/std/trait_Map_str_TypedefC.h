#ifndef PAVE_TRAIT_MAP_STR_TYPEDEF_C
#define PAVE_TRAIT_MAP_STR_TYPEDEF_C

#include <stdbool.h>

#include <std/str.h>
#include <analyzer/c/TypedefC.h>
struct str;
struct TypedefC;

#line 1 "src/std/Map.pv"
struct trait_Map_str_TypedefCVTable {
    #line 2 "src/std/Map.pv"
    struct TypedefC* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct TypedefC* (*fn_insert)(void* __self, struct str key, struct TypedefC value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_TypedefC {
    const struct trait_Map_str_TypedefCVTable* vtable;
    void* instance;
};

#endif
