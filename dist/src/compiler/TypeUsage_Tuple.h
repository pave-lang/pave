#ifndef PAVE_TYPE_USAGE_TUPLE
#define PAVE_TYPE_USAGE_TUPLE

#include <stdbool.h>

#include <std/Array_UsageContext.h>
struct ArenaAllocator;
struct Tuple;

#line 102 "src/compiler/Usages.pv"
struct TypeUsage_Tuple {
    struct ArenaAllocator* allocator;
    struct Tuple* type;
    struct Array_UsageContext usage_contexts;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Tuple.h>
struct ArenaAllocator;
struct Tuple;
struct TypeUsage_Tuple;
struct GenericMap;
struct UsageContext;

#line 110 "src/compiler/Usages.pv"
struct TypeUsage_Tuple TypeUsage_Tuple__new(struct ArenaAllocator* allocator, struct Tuple* type);

#line 119 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Tuple__add_usage(struct TypeUsage_Tuple* self, struct GenericMap* generic_map);

#endif
