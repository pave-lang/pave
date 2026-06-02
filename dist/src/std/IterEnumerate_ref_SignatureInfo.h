#ifndef PAVE_ITER_ENUMERATE_REF_SIGNATURE_INFO
#define PAVE_ITER_ENUMERATE_REF_SIGNATURE_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_SignatureInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_SignatureInfo {
    uintptr_t index;
    struct Iter_ref_SignatureInfo iter;
};

#include <tuple_usize_ref_SignatureInfo.h>
struct IterEnumerate_ref_SignatureInfo;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_SignatureInfo__next(struct IterEnumerate_ref_SignatureInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_SignatureInfo IterEnumerate_ref_SignatureInfo__value(struct IterEnumerate_ref_SignatureInfo* self);

#endif
