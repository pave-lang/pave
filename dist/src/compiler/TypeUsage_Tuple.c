#include <stdint.h>

#include <stdio.h>

#include <compiler/TypeUsage_Tuple.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Tuple.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/TypeUsage_Tuple.h>

#include <compiler/TypeUsage_Tuple.h>

#line 110 "src/compiler/Usages.pv"
struct TypeUsage_Tuple TypeUsage_Tuple__new(struct ArenaAllocator* allocator, struct Tuple* type) {
    #line 111 "src/compiler/Usages.pv"
    return (struct TypeUsage_Tuple) {
        .allocator = allocator,
        .type = type,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_dynamic_usage = false,
    };
}

#line 119 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Tuple__add_usage(struct TypeUsage_Tuple* self, struct GenericMap* generic_map) {
    #line 120 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 121 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 122 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
