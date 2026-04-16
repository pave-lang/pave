#include <std/HashSetBucket_str.h>
#include <std/HashSetIter_str.h>
#include <std/str.h>
#include <std/HashSetIter_str.h>

#include <std/HashSetIter_str.h>

#line 15 "src/std/HashSet.pv"
bool HashSetIter_str__next(struct HashSetIter_str* self) {
    #line 16 "src/std/HashSet.pv"
    self->iter += 1;
    #line 17 "src/std/HashSet.pv"
    return self->iter < self->end;
}

#line 20 "src/std/HashSet.pv"
struct str* HashSetIter_str__value(struct HashSetIter_str* self) {
    #line 21 "src/std/HashSet.pv"
    return (struct str*)(self->iter);
}
