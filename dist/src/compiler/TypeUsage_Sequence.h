#ifndef PAVE_TYPE_USAGE_SEQUENCE
#define PAVE_TYPE_USAGE_SEQUENCE

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct Sequence;

#line 102 "src/compiler/Usages.pv"
struct TypeUsage_Sequence {
    struct ArenaAllocator* allocator;
    struct Sequence* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Sequence.h>
struct ArenaAllocator;
struct Sequence;
struct TypeUsage_Sequence;
struct GenericMap;
struct UsageContext;

#line 110 "src/compiler/Usages.pv"
struct TypeUsage_Sequence TypeUsage_Sequence__new(struct ArenaAllocator* allocator, struct Sequence* type);

#line 119 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Sequence__add_usage(struct TypeUsage_Sequence* self, struct GenericMap* generic_map);

#endif
