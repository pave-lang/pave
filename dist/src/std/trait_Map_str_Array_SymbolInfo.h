#ifndef PAVE_TRAIT_MAP_STR_ARRAY_SYMBOL_INFO
#define PAVE_TRAIT_MAP_STR_ARRAY_SYMBOL_INFO

#include <stdbool.h>

#include <std/trait_Map_str_Array_SymbolInfo.h>
#include <std/str.h>
#include <std/Array_SymbolInfo.h>
struct str;
struct Array_SymbolInfo;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_SymbolInfoVTable {
    #line 2 "src/std/Map.pv"
    struct Array_SymbolInfo* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_SymbolInfo* (*fn_insert)(void* __self, struct str key, struct Array_SymbolInfo value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_SymbolInfo {
    const struct trait_Map_str_Array_SymbolInfoVTable* vtable;
    void* instance;
};

#endif
