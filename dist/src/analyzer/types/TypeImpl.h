#ifndef PAVE_TYPE_IMPL
#define PAVE_TYPE_IMPL

#include <analyzer/types/Type.h>
struct Impl;

#line 4 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl {
    struct Type type;
    struct Impl* impl_info;
};

#include <analyzer/types/Type.h>
#include <analyzer/types/TypeImpl.h>
struct ArenaAllocator;
struct Impl;

#line 10 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl TypeImpl__new(struct ArenaAllocator* allocator, struct Type type, struct Impl* impl_info);

#endif
