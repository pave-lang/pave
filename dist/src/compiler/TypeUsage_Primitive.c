#include <stdint.h>

#include <stdio.h>

#include <compiler/TypeUsage_Primitive.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Primitive.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/TypeUsage_Primitive.h>

#include <compiler/TypeUsage_Primitive.h>

#line 124 "src/compiler/Usages.pv"
struct TypeUsage_Primitive TypeUsage_Primitive__new(struct ArenaAllocator* allocator, struct Primitive* type) {
    #line 125 "src/compiler/Usages.pv"
    return (struct TypeUsage_Primitive) {
        .allocator = allocator,
        .type = type,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_dynamic_usage = false,
        .any_usage = false,
    };
}

#line 134 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Primitive__add_usage(struct TypeUsage_Primitive* self, struct GenericMap* generic_map) {
    #line 135 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 136 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 137 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
