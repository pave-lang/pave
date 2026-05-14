#include <string.h>

#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/UnknownC.h>
#include <std/trait_Allocator.h>
#include <analyzer/c/UnknownC.h>

#include <analyzer/c/UnknownC.h>

#line 11 "src/analyzer/c/UnknownC.pv"
struct UnknownC* UnknownC__new(struct Include* include, char const* name) {
    #line 12 "src/analyzer/c/UnknownC.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 14 "src/analyzer/c/UnknownC.pv"
    return ArenaAllocator__store_UnknownC(allocator, (struct UnknownC[]){(struct UnknownC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .generics = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    }});
}
