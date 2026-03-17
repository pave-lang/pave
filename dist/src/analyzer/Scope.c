#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Block.h>
#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>

#include <analyzer/Scope.h>

#line 14 "src/analyzer/Context.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block) {
    #line 15 "src/analyzer/Context.pv"
    return (struct Scope) {
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .block = block,
    };
}
