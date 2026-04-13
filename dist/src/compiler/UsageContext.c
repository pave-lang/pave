#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <std/trait_Allocator.h>

#include <compiler/UsageContext.h>

#line 42 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator) {
    #line 43 "src/compiler/Usages.pv"
    return (struct UsageContext) {
        .layout = HashMap_str_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .signature = HashMap_str_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .body = HashMap_str_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .cpp_usages = HashMap_str_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}
