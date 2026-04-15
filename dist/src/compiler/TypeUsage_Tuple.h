#ifndef PAVE_TYPE_USAGE_TUPLE
#define PAVE_TYPE_USAGE_TUPLE

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

struct ArenaAllocator;
struct Tuple;
#include <std/Array_UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>

#line 63 "src/compiler/Usages.pv"
struct TypeUsage_Tuple {
    struct ArenaAllocator* allocator;
    struct Tuple* type;
    struct Array_UsageContext usage_contexts;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
};

struct ArenaAllocator;
struct Tuple;
struct TypeUsage_Tuple;
struct GenericMap;
struct UsageContext;
#include <compiler/TypeUsage_Tuple.h>

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Tuple TypeUsage_Tuple__new(struct ArenaAllocator* allocator, struct Tuple* type, uintptr_t impl_count);

#line 92 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Tuple__add_usage(struct TypeUsage_Tuple* self, struct GenericMap* generic_map);

#endif
