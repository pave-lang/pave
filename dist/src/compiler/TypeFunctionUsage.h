#ifndef PAVE_TYPE_FUNCTION_USAGE
#define PAVE_TYPE_FUNCTION_USAGE

#include <std/Array_ref_GenericMap.h>
#include <compiler/FunctionContext.h>
#include <stdbool.h>
#include <compiler/UsageContext.h>

struct Function;
struct GenericMap;
struct ArenaAllocator;

#include <stdio.h>

#line 8 "src/compiler/Usages.pv"
struct TypeFunctionUsage {
    struct Function* type;
    struct Array_ref_GenericMap generic_maps;
    struct FunctionContext function_context;
    bool impl_dynamic_function;
    struct UsageContext usage_context;
};

#line 17 "src/compiler/Usages.pv"
struct TypeFunctionUsage TypeFunctionUsage__new(struct ArenaAllocator* allocator, struct Function* type);

#endif
