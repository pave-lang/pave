#include <std/ArenaAllocator.h>
#include <analyzer/Type.h>
#include <analyzer/Impl.h>

#include <analyzer/TypeImpl.h>

#line 9 "src/analyzer/TypeImpl.pv"
struct TypeImpl TypeImpl__new(struct ArenaAllocator* allocator, struct Type type, struct Impl* impl_info) {
    #line 10 "src/analyzer/TypeImpl.pv"
    return (struct TypeImpl) {
        .type = type,
        .impl_info = impl_info,
    };
}
