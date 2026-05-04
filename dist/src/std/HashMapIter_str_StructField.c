#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>

#include <std/HashMapIter_str_StructField.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_StructField__next(struct HashMapIter_str_StructField* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_StructField* HashMapIter_str_StructField__value(struct HashMapIter_str_StructField* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_StructField*)(self->iter);
}
