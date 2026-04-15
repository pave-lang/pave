#ifndef PAVE_SLICE_ENUM_VARIANT_PARAMETER
#define PAVE_SLICE_ENUM_VARIANT_PARAMETER

#include <analyzer/types/EnumVariantParameter.h>
#include <std/Iter_ref_EnumVariantParameter.h>
struct slice_EnumVariantParameter { struct EnumVariantParameter* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_EnumVariantParameter slice_EnumVariantParameter__iter(struct slice_EnumVariantParameter self);

#endif
