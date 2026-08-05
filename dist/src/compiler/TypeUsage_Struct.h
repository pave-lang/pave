#ifndef PAVE_TYPE_USAGE_STRUCT
#define PAVE_TYPE_USAGE_STRUCT

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct Struct;

#line 115 "src/compiler/Usages.pv"
struct TypeUsage_Struct {
    struct ArenaAllocator* allocator;
    struct Struct* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
    bool any_usage;
};

struct ArenaAllocator;
struct Struct;
struct GenericMap;
struct UsageContext;

#line 124 "src/compiler/Usages.pv"
struct TypeUsage_Struct TypeUsage_Struct__new(struct ArenaAllocator* allocator, struct Struct* type);

#line 134 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Struct__add_usage(struct TypeUsage_Struct* self, struct GenericMap* generic_map);

#endif
