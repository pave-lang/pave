#ifndef PAVE_TYPE_USAGE_PRIMITIVE
#define PAVE_TYPE_USAGE_PRIMITIVE

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

#include <std/Array_UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
struct ArenaAllocator;
struct Primitive;

#line 63 "src/compiler/Usages.pv"
struct TypeUsage_Primitive {
    struct ArenaAllocator* allocator;
    struct Primitive* type;
    struct Array_UsageContext usage_contexts;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Primitive.h>
struct ArenaAllocator;
struct Primitive;
struct TypeUsage_Primitive;
struct GenericMap;
struct UsageContext;

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Primitive TypeUsage_Primitive__new(struct ArenaAllocator* allocator, struct Primitive* type, uintptr_t impl_count);

#line 92 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Primitive__add_usage(struct TypeUsage_Primitive* self, struct GenericMap* generic_map);

#endif
