#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>

#include <std/HashMapIter_str_EnumVariant.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_EnumVariant__next(struct HashMapIter_str_EnumVariant* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_str_EnumVariant* HashMapIter_str_EnumVariant__value(struct HashMapIter_str_EnumVariant* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_str_EnumVariant*)(self->iter);
}
