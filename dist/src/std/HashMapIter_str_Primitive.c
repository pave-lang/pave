#include <stdio.h>
#include <string.h>

#include <std/HashMapBucket_str_Primitive.h>
#include <std/HashMapIter_str_Primitive.h>
#include <tuple_str_Primitive.h>

#include <std/HashMapIter_str_Primitive.h>

#include <std/HashMapIter_str_Primitive.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Primitive__next(struct HashMapIter_str_Primitive* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_Primitive* HashMapIter_str_Primitive__value(struct HashMapIter_str_Primitive* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_Primitive*)(self->iter);
}
