#ifndef PAVE_TYPE_USAGE_TYPE_IMPL
#define PAVE_TYPE_USAGE_TYPE_IMPL

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct TypeImpl;

#line 115 "src/compiler/Usages.pv"
struct TypeUsage_TypeImpl {
    struct ArenaAllocator* allocator;
    struct TypeImpl* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
    bool any_usage;
};

#include <compiler/TypeUsage_TypeImpl.h>
struct ArenaAllocator;
struct TypeImpl;
struct TypeUsage_TypeImpl;
struct GenericMap;
struct UsageContext;

#line 124 "src/compiler/Usages.pv"
struct TypeUsage_TypeImpl TypeUsage_TypeImpl__new(struct ArenaAllocator* allocator, struct TypeImpl* type);

#line 134 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_TypeImpl__add_usage(struct TypeUsage_TypeImpl* self, struct GenericMap* generic_map);

#endif
