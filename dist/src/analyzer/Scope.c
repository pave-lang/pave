#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Block.h>
#include <analyzer/Scope.h>

#include <analyzer/Scope.h>

#line 12 "src/analyzer/Scope.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block) {
    #line 13 "src/analyzer/Scope.pv"
    return (struct Scope) {
        .values = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .narrow_originals = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .definition_tokens = HashMap_str_ref_Token__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .block = block,
    };
}
