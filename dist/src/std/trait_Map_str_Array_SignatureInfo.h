#ifndef PAVE_TRAIT_MAP_STR_ARRAY_SIGNATURE_INFO
#define PAVE_TRAIT_MAP_STR_ARRAY_SIGNATURE_INFO

#include <stdbool.h>

#include <std/str.h>
#include <std/Array_SignatureInfo.h>
struct str;
struct Array_SignatureInfo;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_SignatureInfoVTable {
    #line 2 "src/std/Map.pv"
    struct Array_SignatureInfo* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_SignatureInfo* (*fn_insert)(void* __self, struct str key, struct Array_SignatureInfo value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_SignatureInfo {
    const struct trait_Map_str_Array_SignatureInfoVTable* vtable;
    void* instance;
};

#endif
