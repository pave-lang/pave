#ifndef PAVE_SLICE_ENUM_VARIANT_PARAM_INFO
#define PAVE_SLICE_ENUM_VARIANT_PARAM_INFO

#include <std/EnumVariantParamInfo.h>
#include <std/Iter_ref_EnumVariantParamInfo.h>
struct slice_EnumVariantParamInfo { struct EnumVariantParamInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_EnumVariantParamInfo slice_EnumVariantParamInfo__iter(struct slice_EnumVariantParamInfo self);

#endif
