#include <stdint.h>

#include <stdio.h>

#include <compiler/TypeUsage_Struct.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Struct.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/TypeUsage_Struct.h>

#include <compiler/TypeUsage_Struct.h>

#line 124 "src/compiler/Usages.pv"
struct TypeUsage_Struct TypeUsage_Struct__new(struct ArenaAllocator* allocator, struct Struct* type) {
    #line 125 "src/compiler/Usages.pv"
    return (struct TypeUsage_Struct) {
        .allocator = allocator,
        .type = type,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_dynamic_usage = false,
        .sized_usage = false,
    };
}

#line 134 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Struct__add_usage(struct TypeUsage_Struct* self, struct GenericMap* generic_map) {
    #line 135 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 136 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 137 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
