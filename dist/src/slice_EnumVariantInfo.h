#ifndef PAVE_SLICE_ENUM_VARIANT_INFO
#define PAVE_SLICE_ENUM_VARIANT_INFO

#include <std/EnumVariantInfo.h>
#include <std/Iter_ref_EnumVariantInfo.h>
struct slice_EnumVariantInfo { struct EnumVariantInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_EnumVariantInfo slice_EnumVariantInfo__iter(struct slice_EnumVariantInfo self);

#endif
