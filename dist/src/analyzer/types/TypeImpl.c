#include <std/ArenaAllocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/Impl.h>

#include <analyzer/types/TypeImpl.h>

#line 10 "src/analyzer/types/TypeImpl.pv"
struct TypeImpl TypeImpl__new(struct ArenaAllocator* allocator, struct Type type, struct Impl* impl_info) {
    #line 11 "src/analyzer/types/TypeImpl.pv"
    return (struct TypeImpl) {
        .type = type,
        .impl_info = impl_info,
    };
}
