#ifndef PAVE_TRAIT_MAP_STR_TYPE
#define PAVE_TRAIT_MAP_STR_TYPE

#include <stdbool.h>

#include <std/trait_Map_str_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
struct str;
struct Type;

#line 1 "src/std/Map.pv"
struct trait_Map_str_TypeVTable {
    #line 2 "src/std/Map.pv"
    struct Type* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Type* (*fn_insert)(void* __self, struct str key, struct Type value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Type {
    const struct trait_Map_str_TypeVTable* vtable;
    void* instance;
};

#endif
