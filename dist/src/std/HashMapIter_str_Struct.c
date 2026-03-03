#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <std/HashMapBucket_str_Struct.h>
#include <std/str.h>
#include <analyzer/Struct.h>
#include <stdint.h>
#include <tuple_str_Struct.h>

#include <std/HashMapIter_str_Struct.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Struct__next(struct HashMapIter_str_Struct* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_Struct* HashMapIter_str_Struct__value(struct HashMapIter_str_Struct* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_Struct*)(self->iter);
}
