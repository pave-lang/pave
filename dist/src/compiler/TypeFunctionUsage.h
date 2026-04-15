#ifndef PAVE_TYPE_FUNCTION_USAGE
#define PAVE_TYPE_FUNCTION_USAGE

#include <stdbool.h>

#include <stdio.h>

struct Function;
#include <std/Array_UsageContext.h>
#include <compiler/FunctionContext.h>

#line 9 "src/compiler/Usages.pv"
struct TypeFunctionUsage {
    struct Function* type;
    struct Array_UsageContext usage_contexts;
    struct FunctionContext function_context;
    bool impl_dynamic_function;
};

struct ArenaAllocator;
struct Function;
struct TypeFunctionUsage;
struct GenericMap;
struct UsageContext;
#include <compiler/TypeFunctionUsage.h>

#line 17 "src/compiler/Usages.pv"
struct TypeFunctionUsage TypeFunctionUsage__new(struct ArenaAllocator* allocator, struct Function* type);

#line 26 "src/compiler/Usages.pv"
struct UsageContext* TypeFunctionUsage__add_usage(struct TypeFunctionUsage* self, struct GenericMap* generic_map);

#endif
