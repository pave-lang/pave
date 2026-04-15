#include <stdint.h>

#include <stdio.h>

#include <compiler/TypeUsage_Struct.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Struct.h>
#include <std/Array_UsageContext.h>
#include <std/trait_Allocator.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/Range_usize.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>

#include <compiler/TypeUsage_Struct.h>

#include <compiler/TypeUsage_Struct.h>

#line 72 "src/compiler/Usages.pv"
struct TypeUsage_Struct TypeUsage_Struct__new(struct ArenaAllocator* allocator, struct Struct* type, uintptr_t impl_count) {
    #line 73 "src/compiler/Usages.pv"
    struct TypeUsage_Struct self = (struct TypeUsage_Struct) {
        .allocator = allocator,
        .type = type,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 79 "src/compiler/Usages.pv"
    if (impl_count > 0) {
        #line 80 "src/compiler/Usages.pv"
        self.impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 81 "src/compiler/Usages.pv"
        Array_HashMap_usize_TypeFunctionUsage__reserve(&self.impl_functions, impl_count);
        #line 82 "src/compiler/Usages.pv"
        self.impl_functions.length = impl_count;

        #line 84 "src/compiler/Usages.pv"
        for (uintptr_t i = 0; i < impl_count; i++) {
            #line 85 "src/compiler/Usages.pv"
            self.impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        }
    }

    #line 89 "src/compiler/Usages.pv"
    return self;
}

#line 92 "src/compiler/Usages.pv"
struct UsageContext* TypeUsage_Struct__add_usage(struct TypeUsage_Struct* self, struct GenericMap* generic_map) {
    #line 93 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 94 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 95 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
