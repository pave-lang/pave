#ifndef PAVE_SLICE_STRUCT_TRAIT_INFO
#define PAVE_SLICE_STRUCT_TRAIT_INFO

#include <std/StructTraitInfo.h>
#include <std/Iter_ref_StructTraitInfo.h>
struct slice_StructTraitInfo { struct StructTraitInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_StructTraitInfo slice_StructTraitInfo__iter(struct slice_StructTraitInfo self);

#endif
