#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_DIAGNOSTIC
#define PAVE_HASH_MAP_ITER_STR_ARRAY_DIAGNOSTIC

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_Array_Diagnostic;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Array_Diagnostic {
    struct HashMapBucket_str_Array_Diagnostic* iter;
    struct HashMapBucket_str_Array_Diagnostic* end;
};
struct HashMapIter_str_Array_Diagnostic;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Array_Diagnostic__next(struct HashMapIter_str_Array_Diagnostic* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Array_Diagnostic* HashMapIter_str_Array_Diagnostic__value(struct HashMapIter_str_Array_Diagnostic* self);

#endif
