#ifndef PAVE_SLICE_TUPLE_USIZE_STR_TYPE_ID
#define PAVE_SLICE_TUPLE_USIZE_STR_TYPE_ID

#include <tuple_usize_str_TypeId.h>
#include <std/Iter_ref_tuple_usize_str_TypeId.h>
struct slice_tuple_usize_str_TypeId { struct tuple_usize_str_TypeId* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_tuple_usize_str_TypeId slice_tuple_usize_str_TypeId__iter(struct slice_tuple_usize_str_TypeId self);

#endif
