#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <compiler/FunctionCoroutine.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>

#include <compiler/FunctionCoroutine.h>

#include <compiler/FunctionCoroutine.h>

#line 36 "src/compiler/Generator.pv"
struct FunctionCoroutine FunctionCoroutine__new(struct ArenaAllocator* allocator) {
    #line 37 "src/compiler/Generator.pv"
    return (struct FunctionCoroutine) { .variables = HashMap_str_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}
