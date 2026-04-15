#ifndef PAVE_TYPE_USAGE_ENUM
#define PAVE_TYPE_USAGE_ENUM

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

struct ArenaAllocator;
struct Enum;
#include <std/Array_UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>

#line 63 "src/compiler/Usages.pv"
struct TypeUsage_Enum {
    struct ArenaAllocator* allocator;
    struct Enum* type;
    struct Array_UsageContext usage_contexts;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
};

struct ArenaAllocator;
struct Enum;
struct TypeUsage_Enum;
struct GenericMap;
struct UsageContext;
#include <compiler/TypeUsage_Enum.h>

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Enum TypeUsage_Enum__new(struct ArenaAllocator* allocator, struct Enum* type, uintptr_t impl_count);

#line 92 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Enum__add_usage(struct TypeUsage_Enum* self, struct GenericMap* generic_map);

#endif
