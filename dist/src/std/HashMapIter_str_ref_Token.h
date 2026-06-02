#ifndef PAVE_HASH_MAP_ITER_STR_REF_TOKEN
#define PAVE_HASH_MAP_ITER_STR_REF_TOKEN

#include <stdbool.h>

struct HashMapBucket_str_ref_Token;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Token {
    struct HashMapBucket_str_ref_Token* iter;
    struct HashMapBucket_str_ref_Token* end;
};

struct HashMapIter_str_ref_Token;

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Token__next(struct HashMapIter_str_ref_Token* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Token* HashMapIter_str_ref_Token__value(struct HashMapIter_str_ref_Token* self);

#endif
