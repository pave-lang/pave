#ifndef PAVE_TYPE_IMPL
#define PAVE_TYPE_IMPL

struct Impl;
#include <analyzer/types/Type.h>

#line 4 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl {
    struct Type type;
    struct Impl* impl_info;
};
struct ArenaAllocator;
struct Impl;
#include <analyzer/types/Type.h>
#include <analyzer/types/TypeImpl.h>


#line 10 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl TypeImpl__new(struct ArenaAllocator* allocator, struct Type type, struct Impl* impl_info);

#endif
