#ifndef PAVE_ITER_REF_STRUCT_FIELD_INFO
#define PAVE_ITER_REF_STRUCT_FIELD_INFO

#include <stdint.h>
#include <stdbool.h>

struct StructFieldInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_StructFieldInfo {
    intptr_t step;
    struct StructFieldInfo* iter;
    struct StructFieldInfo* start;
    struct StructFieldInfo* end;
};

#include <std/Iter_ref_StructFieldInfo.h>
#include <std/IterEnumerate_ref_StructFieldInfo.h>
struct StructFieldInfo;
struct Iter_ref_StructFieldInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_StructFieldInfo Iter_ref_StructFieldInfo__new(struct StructFieldInfo* start, struct StructFieldInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_StructFieldInfo Iter_ref_StructFieldInfo__reverse(struct Iter_ref_StructFieldInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_StructFieldInfo Iter_ref_StructFieldInfo__skip(struct Iter_ref_StructFieldInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_StructFieldInfo__next(struct Iter_ref_StructFieldInfo* self);

#line 43 "src/std/Array.pv"
struct StructFieldInfo* Iter_ref_StructFieldInfo__value(struct Iter_ref_StructFieldInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_StructFieldInfo Iter_ref_StructFieldInfo__enumerate(struct Iter_ref_StructFieldInfo self);

#endif
