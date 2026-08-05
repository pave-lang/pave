#include <stdint.h>

#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <analyzer/types/Function.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/FunctionContext.h>
#include <compiler/TypeFunctionUsage.h>

#include <compiler/TypeFunctionUsage.h>

#line 17 "src/compiler/Usages.pv"
struct TypeFunctionUsage TypeFunctionUsage__new(struct ArenaAllocator* allocator, struct Function* type) {
    #line 18 "src/compiler/Usages.pv"
    return (struct TypeFunctionUsage) {
        .allocator = allocator,
        .type = type,
        .impl_dynamic_function = false,
        .usage_contexts = Array_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}

#line 26 "src/compiler/Usages.pv"
struct UsageContext* TypeFunctionUsage__add_usage(struct TypeFunctionUsage* self, struct GenericMap* generic_map) {
    #line 27 "src/compiler/Usages.pv"
    struct UsageContext usage_context = UsageContext__new(self->allocator, generic_map);
    #line 28 "src/compiler/Usages.pv"
    usage_context.function_context = FunctionContext__new(self->allocator, self->type, false);
    #line 29 "src/compiler/Usages.pv"
    usage_context.impl_dynamic_function = self->impl_dynamic_function;
    #line 30 "src/compiler/Usages.pv"
    uintptr_t index = Array_UsageContext__append(&self->usage_contexts, usage_context);
    #line 31 "src/compiler/Usages.pv"
    return &self->usage_contexts.data[index];
}
