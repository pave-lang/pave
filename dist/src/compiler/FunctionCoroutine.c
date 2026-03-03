#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <std/ArenaAllocator.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/str.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>

#include <compiler/FunctionCoroutine.h>

#line 32 "src/compiler/Generator.pv"
struct FunctionCoroutine FunctionCoroutine__new(struct ArenaAllocator* allocator) {
    #line 33 "src/compiler/Generator.pv"
    return (struct FunctionCoroutine) { .variables = HashMap_str_ref_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}
