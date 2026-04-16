#ifndef PAVE_FUNCTION_COROUTINE
#define PAVE_FUNCTION_COROUTINE

#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <std/HashMap_str_ref_Type.h>

#line 30 "src/compiler/Generator.pv"
struct FunctionCoroutine {
    uintptr_t yield_count;
    struct HashMap_str_ref_Type variables;
};

#include <compiler/FunctionCoroutine.h>
struct ArenaAllocator;

#line 36 "src/compiler/Generator.pv"
struct FunctionCoroutine FunctionCoroutine__new(struct ArenaAllocator* allocator);

#endif
