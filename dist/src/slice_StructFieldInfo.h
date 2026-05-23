#ifndef PAVE_SLICE_STRUCT_FIELD_INFO
#define PAVE_SLICE_STRUCT_FIELD_INFO

#include <std/StructFieldInfo.h>
#include <std/Iter_ref_StructFieldInfo.h>
struct slice_StructFieldInfo { struct StructFieldInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_StructFieldInfo slice_StructFieldInfo__iter(struct slice_StructFieldInfo self);

#endif
