#include <std/ArenaAllocator.h>
#include <analyzer/Block.h>
#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>

#include <analyzer/Scope.h>

#line 10 "src/analyzer/Scope.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block) {
    #line 11 "src/analyzer/Scope.pv"
    return (struct Scope) {
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .block = block,
    };
}
