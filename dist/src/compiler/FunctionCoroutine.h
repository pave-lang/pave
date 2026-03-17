#ifndef PAVE_FUNCTION_COROUTINE
#define PAVE_FUNCTION_COROUTINE

#include <stdint.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/str.h>

struct Type;
struct ArenaAllocator;

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#line 27 "src/compiler/Generator.pv"
struct FunctionCoroutine {
    uintptr_t yield_count;
    struct HashMap_str_ref_Type variables;
};

#line 33 "src/compiler/Generator.pv"
struct FunctionCoroutine FunctionCoroutine__new(struct ArenaAllocator* allocator);

#endif
