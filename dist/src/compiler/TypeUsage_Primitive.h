#ifndef PAVE_TYPE_USAGE_PRIMITIVE
#define PAVE_TYPE_USAGE_PRIMITIVE

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct Primitive;

#line 115 "src/compiler/Usages.pv"
struct TypeUsage_Primitive {
    struct ArenaAllocator* allocator;
    struct Primitive* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
    bool any_usage;
};

struct ArenaAllocator;
struct Primitive;
struct GenericMap;
struct UsageContext;

#line 124 "src/compiler/Usages.pv"
struct TypeUsage_Primitive TypeUsage_Primitive__new(struct ArenaAllocator* allocator, struct Primitive* type);

#line 134 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Primitive__add_usage(struct TypeUsage_Primitive* self, struct GenericMap* generic_map);

#endif
