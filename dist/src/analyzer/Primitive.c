#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Trait.h>
#include <std/Allocator.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>

#include <analyzer/Primitive.h>

#line 10 "src/analyzer/Primitive.pv"
struct Primitive Primitive__new(struct ArenaAllocator* allocator, char const* name) {
    #line 11 "src/analyzer/Primitive.pv"
    return (struct Primitive) {
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_ref_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}
