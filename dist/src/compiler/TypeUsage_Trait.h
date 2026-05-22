#ifndef PAVE_TYPE_USAGE_TRAIT
#define PAVE_TYPE_USAGE_TRAIT

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct Trait;

#line 102 "src/compiler/Usages.pv"
struct TypeUsage_Trait {
    struct ArenaAllocator* allocator;
    struct Trait* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Trait.h>
struct ArenaAllocator;
struct Trait;
struct TypeUsage_Trait;
struct GenericMap;
struct UsageContext;

#line 110 "src/compiler/Usages.pv"
struct TypeUsage_Trait TypeUsage_Trait__new(struct ArenaAllocator* allocator, struct Trait* type);

#line 119 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Trait__add_usage(struct TypeUsage_Trait* self, struct GenericMap* generic_map);

#endif
