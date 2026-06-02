#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_SYMBOL_INFO
#define PAVE_HASH_MAP_ITER_STR_ARRAY_SYMBOL_INFO

#include <stdbool.h>

struct HashMapBucket_str_Array_SymbolInfo;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Array_SymbolInfo {
    struct HashMapBucket_str_Array_SymbolInfo* iter;
    struct HashMapBucket_str_Array_SymbolInfo* end;
};

struct HashMapIter_str_Array_SymbolInfo;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Array_SymbolInfo__next(struct HashMapIter_str_Array_SymbolInfo* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Array_SymbolInfo* HashMapIter_str_Array_SymbolInfo__value(struct HashMapIter_str_Array_SymbolInfo* self);

#endif
