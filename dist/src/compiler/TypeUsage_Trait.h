#ifndef PAVE_TYPE_USAGE_TRAIT
#define PAVE_TYPE_USAGE_TRAIT

#include <stdbool.h>
#include <stdint.h>

#include <std/Array_UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
struct ArenaAllocator;
struct Trait;

#line 63 "src/compiler/Usages.pv"
struct TypeUsage_Trait {
    struct ArenaAllocator* allocator;
    struct Trait* type;
    struct Array_UsageContext usage_contexts;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
};

#include <compiler/TypeUsage_Trait.h>
struct ArenaAllocator;
struct Trait;
struct TypeUsage_Trait;
struct GenericMap;
struct UsageContext;

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Trait TypeUsage_Trait__new(struct ArenaAllocator* allocator, struct Trait* type, uintptr_t impl_count);

#line 94 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Trait__add_usage(struct TypeUsage_Trait* self, struct GenericMap* generic_map);

#endif
