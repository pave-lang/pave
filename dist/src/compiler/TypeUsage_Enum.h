#ifndef PAVE_TYPE_USAGE_ENUM
#define PAVE_TYPE_USAGE_ENUM

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct Enum;

#line 115 "src/compiler/Usages.pv"
struct TypeUsage_Enum {
    struct ArenaAllocator* allocator;
    struct Enum* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Enum.h>
struct ArenaAllocator;
struct Enum;
struct TypeUsage_Enum;
struct GenericMap;
struct UsageContext;

#line 123 "src/compiler/Usages.pv"
struct TypeUsage_Enum TypeUsage_Enum__new(struct ArenaAllocator* allocator, struct Enum* type);

#line 132 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Enum__add_usage(struct TypeUsage_Enum* self, struct GenericMap* generic_map);

#endif
