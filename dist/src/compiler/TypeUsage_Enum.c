#include <stdint.h>

#include <stdio.h>

#include <compiler/TypeUsage_Enum.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Enum.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/TypeUsage_Enum.h>

#include <compiler/TypeUsage_Enum.h>

#line 123 "src/compiler/Usages.pv"
struct TypeUsage_Enum TypeUsage_Enum__new(struct ArenaAllocator* allocator, struct Enum* type) {
    #line 124 "src/compiler/Usages.pv"
    return (struct TypeUsage_Enum) {
        .allocator = allocator,
        .type = type,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_dynamic_usage = false,
    };
}

#line 132 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Enum__add_usage(struct TypeUsage_Enum* self, struct GenericMap* generic_map) {
    #line 133 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 134 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 135 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
