#ifndef PAVE_USAGE_CONTEXT
#define PAVE_USAGE_CONTEXT

#include <std/HashSet_str.h>
#include <std/HashMap_str_Type.h>
struct GenericMap;

#line 39 "src/compiler/Usages.pv"
struct UsageContext {
    struct GenericMap* generic_map;
    struct HashSet_str primitive_header;
    struct HashSet_str primitive_code;
    struct HashMap_str_Type layout;
    struct HashMap_str_Type signature;
    struct HashMap_str_Type body;
    struct HashMap_str_Type cpp_usages;
};

#include <compiler/UsageContext.h>
struct ArenaAllocator;
struct GenericMap;

#line 50 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator, struct GenericMap* generic_map);

#endif
