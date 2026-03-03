#ifndef PAVE_HASH_MAP_BUCKET_STR_GENERATOR_INCLUDE
#define PAVE_HASH_MAP_BUCKET_STR_GENERATOR_INCLUDE

#include <std/str.h>
#include <compiler/GeneratorInclude.h>

struct HashMapBucket_str_GeneratorInclude;
struct str;
struct GeneratorInclude;

#include <stdio.h>
#include <string.h>

#line 4 "src/std/HashMap.pv"
struct HashMapBucket_str_GeneratorInclude {
    struct str key;
    struct GeneratorInclude value;
    struct HashMapBucket_str_GeneratorInclude* next;
};

#endif
