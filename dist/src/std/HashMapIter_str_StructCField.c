#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_str_StructCField.h>
#include <std/HashMapIter_str_StructCField.h>
#include <tuple_str_StructCField.h>
#include <std/HashMapIter_str_StructCField.h>

#include <std/HashMapIter_str_StructCField.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_StructCField__next(struct HashMapIter_str_StructCField* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_str_StructCField* HashMapIter_str_StructCField__value(struct HashMapIter_str_StructCField* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_str_StructCField*)(self->iter);
}
