#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Trait.h>
#include <stdint.h>
#include <std/Array_ref_GenericMap.h>
#include <analyzer/GenericMap.h>
#include <std/Allocator.h>
#include <compiler/UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <stdbool.h>

#include <compiler/TypeUsage_Trait.h>

#line 54 "src/compiler/Usages.pv"
struct TypeUsage_Trait TypeUsage_Trait__new(struct ArenaAllocator* allocator, struct Trait* type, uintptr_t impl_count) {
    #line 55 "src/compiler/Usages.pv"
    struct TypeUsage_Trait self = (struct TypeUsage_Trait) {
        .type = type,
        .generic_maps = Array_ref_GenericMap__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .usage_context = UsageContext__new(allocator),
    };

    #line 61 "src/compiler/Usages.pv"
    if (impl_count > 0) {
        #line 62 "src/compiler/Usages.pv"
        self.impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 63 "src/compiler/Usages.pv"
        Array_HashMap_usize_TypeFunctionUsage__reserve(&self.impl_functions, impl_count);
        #line 64 "src/compiler/Usages.pv"
        self.impl_functions.length = impl_count;

        #line 66 "src/compiler/Usages.pv"
        for (uintptr_t i = 0; i < impl_count; i++) {
            #line 67 "src/compiler/Usages.pv"
            self.impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        }
    }

    #line 71 "src/compiler/Usages.pv"
    return self;
}
