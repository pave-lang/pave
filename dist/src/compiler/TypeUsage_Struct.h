#ifndef PAVE_TYPE_USAGE_STRUCT
#define PAVE_TYPE_USAGE_STRUCT

#include <stdbool.h>
#include <stdint.h>

#include <std/Array_UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
struct ArenaAllocator;
struct Struct;

#line 63 "src/compiler/Usages.pv"
struct TypeUsage_Struct {
    struct ArenaAllocator* allocator;
    struct Struct* type;
    struct Array_UsageContext usage_contexts;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Struct.h>
struct ArenaAllocator;
struct Struct;
struct TypeUsage_Struct;
struct GenericMap;
struct UsageContext;

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Struct TypeUsage_Struct__new(struct ArenaAllocator* allocator, struct Struct* type, uintptr_t impl_count);

#line 94 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Struct__add_usage(struct TypeUsage_Struct* self, struct GenericMap* generic_map);

#endif
