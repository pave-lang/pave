#ifndef PAVE_SLICE_REF_TRAIT_FORMAT
#define PAVE_SLICE_REF_TRAIT_FORMAT

#include <std/trait_Format.h>
#include <std/Iter_ref_ref_trait_Format.h>
struct slice_ref_trait_Format { struct trait_Format* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_trait_Format slice_ref_trait_Format__iter(struct slice_ref_trait_Format self);

#endif
