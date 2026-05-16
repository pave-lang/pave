#include <stdint.h>

#include <stdio.h>

#include <compiler/TypeUsage_Primitive.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Primitive.h>
#include <std/trait_Allocator.h>
#include <std/Range_usize.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/TypeUsage_Primitive.h>

#include <compiler/TypeUsage_Primitive.h>

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Primitive TypeUsage_Primitive__new(struct ArenaAllocator* allocator, struct Primitive* type, uintptr_t impl_count) {
    #line 73 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive self = (struct TypeUsage_Primitive) {
        .allocator = allocator,
        .type = type,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 },
        .impl_dynamic_usage = false,
    };

    #line 81 "src/compiler/Usages.pv"
    if (impl_count > 0) {
        #line 82 "src/compiler/Usages.pv"
        self.impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 83 "src/compiler/Usages.pv"
        Array_HashMap_usize_TypeFunctionUsage__reserve(&self.impl_functions, impl_count);
        #line 84 "src/compiler/Usages.pv"
        self.impl_functions.length = impl_count;

        #line 86 "src/compiler/Usages.pv"
        for (uintptr_t i = 0; i < impl_count; i++) {
            #line 87 "src/compiler/Usages.pv"
            self.impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        }
    }

    #line 91 "src/compiler/Usages.pv"
    return self;
}

#line 94 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Primitive__add_usage(struct TypeUsage_Primitive* self, struct GenericMap* generic_map) {
    #line 95 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 96 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 97 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
