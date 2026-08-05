#ifndef PAVE_TRAIT_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO
#define PAVE_TRAIT_MAP_STR_ARRAY_MEMBER_COMPLETION_INFO

#include <stdbool.h>

#include <std/str.h>
#include <std/Array_MemberCompletionInfo.h>
struct str;
struct Array_MemberCompletionInfo;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_MemberCompletionInfoVTable {
    #line 2 "src/std/Map.pv"
    struct Array_MemberCompletionInfo* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_MemberCompletionInfo* (*fn_insert)(void* __self, struct str key, struct Array_MemberCompletionInfo value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_MemberCompletionInfo {
    const struct trait_Map_str_Array_MemberCompletionInfoVTable* vtable;
    void* instance;
};

#endif
