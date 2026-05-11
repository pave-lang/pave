#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_IMPL_CONST
#define PAVE_HASH_MAP_BUCKET_STR_REF_IMPL_CONST

#include <std/str.h>
struct ImplConst;
struct HashMapBucket_str_ref_ImplConst;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_ImplConst {
    struct str key;
    struct ImplConst* value;
    struct HashMapBucket_str_ref_ImplConst* next;
};

#endif
