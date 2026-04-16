#ifndef PAVE_FUNCTION_COROUTINE
#define PAVE_FUNCTION_COROUTINE

#include <stdint.h>

#include <std/HashMap_str_ref_Type.h>

#line 4 "src/compiler/FunctionCoroutine.pv"
struct FunctionCoroutine {
    uintptr_t yield_count;
    struct HashMap_str_ref_Type variables;
};

#include <compiler/FunctionCoroutine.h>
struct ArenaAllocator;

#line 10 "src/compiler/FunctionCoroutine.pv"
struct FunctionCoroutine FunctionCoroutine__new(struct ArenaAllocator* allocator);

#endif
