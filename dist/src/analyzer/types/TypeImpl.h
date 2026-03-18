#ifndef PAVE_TYPE_IMPL
#define PAVE_TYPE_IMPL

#include <analyzer/types/Type.h>

struct Impl;
struct ArenaAllocator;
struct Type;

#line 4 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl {
    struct Type type;
    struct Impl* impl_info;
};

#line 10 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl TypeImpl__new(struct ArenaAllocator* allocator, struct Type type, struct Impl* impl_info);

#endif
