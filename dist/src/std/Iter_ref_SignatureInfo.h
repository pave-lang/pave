#ifndef PAVE_ITER_REF_SIGNATURE_INFO
#define PAVE_ITER_REF_SIGNATURE_INFO

#include <stdint.h>
#include <stdbool.h>

struct SignatureInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_SignatureInfo {
    intptr_t step;
    struct SignatureInfo* iter;
    struct SignatureInfo* start;
    struct SignatureInfo* end;
};

#include <std/Iter_ref_SignatureInfo.h>
#include <std/IterEnumerate_ref_SignatureInfo.h>
struct SignatureInfo;
struct Iter_ref_SignatureInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_SignatureInfo Iter_ref_SignatureInfo__new(struct SignatureInfo* start, struct SignatureInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_SignatureInfo Iter_ref_SignatureInfo__reverse(struct Iter_ref_SignatureInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_SignatureInfo Iter_ref_SignatureInfo__skip(struct Iter_ref_SignatureInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_SignatureInfo__next(struct Iter_ref_SignatureInfo* self);

#line 43 "src/std/Array.pv"
struct SignatureInfo* Iter_ref_SignatureInfo__value(struct Iter_ref_SignatureInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_SignatureInfo Iter_ref_SignatureInfo__enumerate(struct Iter_ref_SignatureInfo self);

#endif
