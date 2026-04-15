#ifndef PAVE_HASH_MAP_BUCKET_STR_GENERATOR_INCLUDE
#define PAVE_HASH_MAP_BUCKET_STR_GENERATOR_INCLUDE

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_GeneratorInclude;
#include <std/str.h>
#include <compiler/GeneratorInclude.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_GeneratorInclude {
    struct str key;
    struct GeneratorInclude value;
    struct HashMapBucket_str_GeneratorInclude* next;
};

#endif
