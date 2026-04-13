#ifndef PAVE_TYPE_USAGE_STRUCT
#define PAVE_TYPE_USAGE_STRUCT

#include <std/Array_ref_GenericMap.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <stdint.h>
#include <compiler/TypeFunctionUsage.h>
#include <stdbool.h>
#include <compiler/UsageContext.h>

struct Struct;
struct GenericMap;
struct ArenaAllocator;

#include <stdio.h>

#line 53 "src/compiler/Usages.pv"
struct TypeUsage_Struct {
    struct Struct* type;
    struct Array_ref_GenericMap generic_maps;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
    bool impl_dynamic_usage;
    struct UsageContext usage_context;
};

#line 62 "src/compiler/Usages.pv"
struct TypeUsage_Struct TypeUsage_Struct__new(struct ArenaAllocator* allocator, struct Struct* type, uintptr_t impl_count);

#endif
