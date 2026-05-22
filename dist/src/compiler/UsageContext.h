#ifndef PAVE_USAGE_CONTEXT
#define PAVE_USAGE_CONTEXT

#include <compiler/FunctionContext.h>
#include <std/HashSet_str.h>
#include <std/HashMap_str_Type.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
struct GenericMap;

#line 40 "src/compiler/Usages.pv"
struct UsageContext {
    struct GenericMap* generic_map;
    struct FunctionContext function_context;
    struct HashSet_str primitive_header;
    struct HashSet_str primitive_code;
    struct HashMap_str_Type layout;
    struct HashMap_str_Type signature;
    struct HashMap_str_Type body;
    struct HashMap_str_Type cpp_usages;
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions;
};

#include <compiler/UsageContext.h>
struct ArenaAllocator;
struct GenericMap;
struct UsageContext;
struct Array_ref_Impl;
struct Trait;

#line 53 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator, struct GenericMap* generic_map);

#line 67 "src/compiler/Usages.pv"
void UsageContext__populate_impls(struct UsageContext* self, struct ArenaAllocator* allocator, struct Array_ref_Impl* impls);

#line 90 "src/compiler/Usages.pv"
void UsageContext__populate_trait_functions(struct UsageContext* self, struct ArenaAllocator* allocator, struct Trait* trait_info);

#endif
