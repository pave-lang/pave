#ifndef PAVE_HASH_MAP_ITER_STR_GENERATOR_INCLUDE
#define PAVE_HASH_MAP_ITER_STR_GENERATOR_INCLUDE

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct HashMapBucket_str_GeneratorInclude;

#line 10 "src/std/HashMap.pv"
struct HashMapIter_str_GeneratorInclude {
    struct HashMapBucket_str_GeneratorInclude* iter;
    struct HashMapBucket_str_GeneratorInclude* end;
};
struct HashMapIter_str_GeneratorInclude;


#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_GeneratorInclude__next(struct HashMapIter_str_GeneratorInclude* self);

#line 21 "src/std/HashMap.pv"
struct tuple_str_GeneratorInclude* HashMapIter_str_GeneratorInclude__value(struct HashMapIter_str_GeneratorInclude* self);

#endif
