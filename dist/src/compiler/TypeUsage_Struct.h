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
};

#include <compiler/TypeUsage_Struct.h>
struct ArenaAllocator;
struct Struct;
struct TypeUsage_Struct;
struct GenericMap;
struct UsageContext;

#line 123 "src/compiler/Usages.pv"
struct TypeUsage_Struct TypeUsage_Struct__new(struct ArenaAllocator* allocator, struct Struct* type);

#line 132 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Struct__add_usage(struct TypeUsage_Struct* self, struct GenericMap* generic_map);

#endif
