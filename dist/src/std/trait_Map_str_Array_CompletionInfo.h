#ifndef PAVE_TRAIT_MAP_STR_ARRAY_COMPLETION_INFO
#define PAVE_TRAIT_MAP_STR_ARRAY_COMPLETION_INFO

#include <stdbool.h>

#include <std/str.h>
#include <std/Array_CompletionInfo.h>
struct str;
struct Array_CompletionInfo;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_CompletionInfoVTable {
    #line 2 "src/std/Map.pv"
    struct Array_CompletionInfo* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_CompletionInfo* (*fn_insert)(void* __self, struct str key, struct Array_CompletionInfo value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_CompletionInfo {
    const struct trait_Map_str_Array_CompletionInfoVTable* vtable;
    void* instance;
};

#endif
