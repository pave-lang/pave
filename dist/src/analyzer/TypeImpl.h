#ifndef PAVE_TYPE_IMPL
#define PAVE_TYPE_IMPL

#include <analyzer/Type.h>

struct Impl;
struct ArenaAllocator;
struct Type;

#line 3 "src/analyzer/TypeImpl.pv"
struct TypeImpl {
    struct Type type;
    struct Impl* impl_info;
};

#line 9 "src/analyzer/TypeImpl.pv"
struct TypeImpl TypeImpl__new(struct ArenaAllocator* allocator, struct Type type, struct Impl* impl_info);

#endif
