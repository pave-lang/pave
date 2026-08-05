#ifndef PAVE_TRAIT_MAP_STR_ENUM_VARIANT
#define PAVE_TRAIT_MAP_STR_ENUM_VARIANT

#include <stdbool.h>

#include <std/str.h>
#include <analyzer/types/EnumVariant.h>
struct str;
struct EnumVariant;

#line 1 "src/std/Map.pv"
struct trait_Map_str_EnumVariantVTable {
    #line 2 "src/std/Map.pv"
    struct EnumVariant* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct EnumVariant* (*fn_insert)(void* __self, struct str key, struct EnumVariant value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_EnumVariant {
    const struct trait_Map_str_EnumVariantVTable* vtable;
    void* instance;
};

#endif
