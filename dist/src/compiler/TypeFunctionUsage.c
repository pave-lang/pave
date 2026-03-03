#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Function.h>
#include <std/Array_ref_GenericMap.h>
#include <analyzer/GenericMap.h>
#include <std/Allocator.h>
#include <compiler/FunctionContext.h>
#include <stdbool.h>

#include <compiler/TypeFunctionUsage.h>

#line 15 "src/compiler/Usages.pv"
struct TypeFunctionUsage TypeFunctionUsage__new(struct ArenaAllocator* allocator, struct Function* type) {
    #line 16 "src/compiler/Usages.pv"
    return (struct TypeFunctionUsage) {
        .type = type,
        .generic_maps = Array_ref_GenericMap__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .function_context = FunctionContext__new(allocator, type, false),
        .impl_dynamic_function = false,
    };
}
