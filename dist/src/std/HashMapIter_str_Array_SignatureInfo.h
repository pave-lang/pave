#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_SIGNATURE_INFO
#define PAVE_HASH_MAP_ITER_STR_ARRAY_SIGNATURE_INFO

#include <stdbool.h>

struct HashMapBucket_str_Array_SignatureInfo;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_Array_SignatureInfo {
    struct HashMapBucket_str_Array_SignatureInfo* iter;
    struct HashMapBucket_str_Array_SignatureInfo* end;
};

struct HashMapIter_str_Array_SignatureInfo;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Array_SignatureInfo__next(struct HashMapIter_str_Array_SignatureInfo* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_Array_SignatureInfo* HashMapIter_str_Array_SignatureInfo__value(struct HashMapIter_str_Array_SignatureInfo* self);

#endif
