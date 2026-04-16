#include <compiler/FunctionCoroutine.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <compiler/FunctionCoroutine.h>

#include <compiler/FunctionCoroutine.h>

#line 10 "src/compiler/FunctionCoroutine.pv"
struct FunctionCoroutine FunctionCoroutine__new(struct ArenaAllocator* allocator) {
    #line 11 "src/compiler/FunctionCoroutine.pv"
    return (struct FunctionCoroutine) { .variables = HashMap_str_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}
