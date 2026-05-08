#ifndef PAVE_HASH_MAP_BUCKET_STR_REF_CONST_VARIABLE
#define PAVE_HASH_MAP_BUCKET_STR_REF_CONST_VARIABLE

#include <std/str.h>
struct ConstVariable;
struct HashMapBucket_str_ref_ConstVariable;

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_ConstVariable {
    struct str key;
    struct ConstVariable* value;
    struct HashMapBucket_str_ref_ConstVariable* next;
};

#endif
