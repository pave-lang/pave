#ifndef PAVE_TRAIT_MAP_STR_REF_PRIMITIVE
#define PAVE_TRAIT_MAP_STR_REF_PRIMITIVE

#include <stdbool.h>

#include <std/trait_Map_str_ref_Primitive.h>
#include <std/str.h>
struct str;
struct Primitive;

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_PrimitiveVTable {
    #line 2 "src/std/Map.pv"
    struct Primitive** (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Primitive** (*fn_insert)(void* __self, struct str key, struct Primitive* value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_Primitive {
    const struct trait_Map_str_ref_PrimitiveVTable* vtable;
    void* instance;
};

#endif
