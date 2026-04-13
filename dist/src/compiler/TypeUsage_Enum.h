#ifndef PAVE_TYPE_USAGE_ENUM
#define PAVE_TYPE_USAGE_ENUM

#include <std/Array_ref_GenericMap.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <stdint.h>
#include <compiler/TypeFunctionUsage.h>
#include <stdbool.h>
#include <compiler/UsageContext.h>

struct Enum;
struct GenericMap;
struct ArenaAllocator;

#include <stdio.h>

#line 52 "src/compiler/Usages.pv"
struct TypeUsage_Enum {
    struct Enum* type;
    struct Array_ref_GenericMap generic_maps;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
    struct UsageContext usage_context;
};

#line 61 "src/compiler/Usages.pv"
struct TypeUsage_Enum TypeUsage_Enum__new(struct ArenaAllocator* allocator, struct Enum* type, uintptr_t impl_count);

#endif
