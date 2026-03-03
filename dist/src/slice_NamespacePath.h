#ifndef PAVE_SLICE_NAMESPACE_PATH
#define PAVE_SLICE_NAMESPACE_PATH

#include <stdint.h>

struct NamespacePath;

struct slice_NamespacePath { struct NamespacePath* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_NamespacePath slice_NamespacePath__iter(struct slice_NamespacePath self);

#endif
