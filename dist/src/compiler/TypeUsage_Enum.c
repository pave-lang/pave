#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <analyzer/types/Enum.h>
#include <stdint.h>
#include <std/Array_ref_GenericMap.h>
#include <analyzer/types/GenericMap.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <stdbool.h>

#include <compiler/TypeUsage_Enum.h>

#line 61 "src/compiler/Usages.pv"
struct TypeUsage_Enum TypeUsage_Enum__new(struct ArenaAllocator* allocator, struct Enum* type, uintptr_t impl_count) {
    #line 62 "src/compiler/Usages.pv"
    struct TypeUsage_Enum self = (struct TypeUsage_Enum) {
        .type = type,
        .generic_maps = Array_ref_GenericMap__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .usage_context = UsageContext__new(allocator),
    };

    #line 68 "src/compiler/Usages.pv"
    if (impl_count > 0) {
        #line 69 "src/compiler/Usages.pv"
        self.impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 70 "src/compiler/Usages.pv"
        Array_HashMap_usize_TypeFunctionUsage__reserve(&self.impl_functions, impl_count);
        #line 71 "src/compiler/Usages.pv"
        self.impl_functions.length = impl_count;

        #line 73 "src/compiler/Usages.pv"
        for (uintptr_t i = 0; i < impl_count; i++) {
            #line 74 "src/compiler/Usages.pv"
            self.impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        }
    }

    #line 78 "src/compiler/Usages.pv"
    return self;
}
