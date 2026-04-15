#ifndef PAVE_TYPE_USAGE_SEQUENCE
#define PAVE_TYPE_USAGE_SEQUENCE

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

struct ArenaAllocator;
struct Sequence;
#include <std/Array_UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>

#line 63 "src/compiler/Usages.pv"
struct TypeUsage_Sequence {
    struct ArenaAllocator* allocator;
    struct Sequence* type;
    struct Array_UsageContext usage_contexts;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
};
struct ArenaAllocator;
struct Sequence;
struct TypeUsage_Sequence;
struct GenericMap;
struct UsageContext;
#include <compiler/TypeUsage_Sequence.h>


#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Sequence TypeUsage_Sequence__new(struct ArenaAllocator* allocator, struct Sequence* type, uintptr_t impl_count);

#line 92 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Sequence__add_usage(struct TypeUsage_Sequence* self, struct GenericMap* generic_map);

#endif
