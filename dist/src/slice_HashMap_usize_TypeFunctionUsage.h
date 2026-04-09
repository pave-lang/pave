#ifndef PAVE_SLICE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE
#define PAVE_SLICE_HASH_MAP_USIZE_TYPE_FUNCTION_USAGE

#include <stdint.h>

struct HashMap_usize_TypeFunctionUsage;
struct TypeFunctionUsage;

struct slice_HashMap_usize_TypeFunctionUsage { struct HashMap_usize_TypeFunctionUsage* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_HashMap_usize_TypeFunctionUsage slice_HashMap_usize_TypeFunctionUsage__iter(struct slice_HashMap_usize_TypeFunctionUsage self);

#endif
