#ifndef PAVE_SLICE_SIGNATURE_INFO
#define PAVE_SLICE_SIGNATURE_INFO

#include <analyzer/SignatureInfo.h>
#include <std/Iter_ref_SignatureInfo.h>
struct slice_SignatureInfo { struct SignatureInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_SignatureInfo slice_SignatureInfo__iter(struct slice_SignatureInfo self);

#endif
