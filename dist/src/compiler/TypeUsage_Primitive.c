#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <analyzer/types/Primitive.h>
#include <stdint.h>
#include <std/Array_ref_GenericMap.h>
#include <analyzer/types/GenericMap.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <stdbool.h>

#include <compiler/TypeUsage_Primitive.h>

#line 55 "src/compiler/Usages.pv"
struct TypeUsage_Primitive TypeUsage_Primitive__new(struct ArenaAllocator* allocator, struct Primitive* type, uintptr_t impl_count) {
    #line 56 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive self = (struct TypeUsage_Primitive) {
        .type = type,
        .generic_maps = Array_ref_GenericMap__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .usage_context = UsageContext__new(allocator),
    };

    #line 62 "src/compiler/Usages.pv"
    if (impl_count > 0) {
        #line 63 "src/compiler/Usages.pv"
        self.impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 64 "src/compiler/Usages.pv"
        Array_HashMap_usize_TypeFunctionUsage__reserve(&self.impl_functions, impl_count);
        #line 65 "src/compiler/Usages.pv"
        self.impl_functions.length = impl_count;

        #line 67 "src/compiler/Usages.pv"
        for (uintptr_t i = 0; i < impl_count; i++) {
            #line 68 "src/compiler/Usages.pv"
            self.impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        }
    }

    #line 72 "src/compiler/Usages.pv"
    return self;
}
