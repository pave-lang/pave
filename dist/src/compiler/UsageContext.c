#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <compiler/UsageContext.h>

#include <compiler/UsageContext.h>

#line 50 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator, struct GenericMap* generic_map) {
    #line 51 "src/compiler/Usages.pv"
    return (struct UsageContext) {
        .generic_map = generic_map,
        .primitive_header = HashSet_str__new(allocator),
        .primitive_code = HashSet_str__new(allocator),
        .layout = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .signature = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .body = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .cpp_usages = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}
