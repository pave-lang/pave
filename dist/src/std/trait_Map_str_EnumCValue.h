#ifndef PAVE_TRAIT_MAP_STR_ENUM_CVALUE
#define PAVE_TRAIT_MAP_STR_ENUM_CVALUE

#include <stdbool.h>

#include <std/trait_Map_str_EnumCValue.h>
#include <std/str.h>
#include <analyzer/c/EnumCValue.h>
struct str;
struct EnumCValue;

#line 1 "src/std/Map.pv"
struct trait_Map_str_EnumCValueVTable {
    #line 2 "src/std/Map.pv"
    struct EnumCValue* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct EnumCValue* (*fn_insert)(void* __self, struct str key, struct EnumCValue value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_EnumCValue {
    const struct trait_Map_str_EnumCValueVTable* vtable;
    void* instance;
};

#endif
