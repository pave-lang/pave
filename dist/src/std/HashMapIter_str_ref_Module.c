#include <stdio.h>
#include <string.h>

#include <std/HashMapBucket_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>

#include <std/HashMapIter_str_ref_Module.h>

#include <std/HashMapIter_str_ref_Module.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Module__next(struct HashMapIter_str_ref_Module* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_ref_Module* HashMapIter_str_ref_Module__value(struct HashMapIter_str_ref_Module* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_ref_Module*)(self->iter);
}
