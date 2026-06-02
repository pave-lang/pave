#ifndef PAVE_HASH_MAP_BUCKET_STR_ARRAY_SYMBOL_INFO
#define PAVE_HASH_MAP_BUCKET_STR_ARRAY_SYMBOL_INFO

#include <std/str.h>
#include <std/Array_SymbolInfo.h>
struct HashMapBucket_str_Array_SymbolInfo;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_SymbolInfo {
    struct str key;
    struct Array_SymbolInfo value;
    struct HashMapBucket_str_Array_SymbolInfo* next;
};

#endif
