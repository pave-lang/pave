#ifndef PAVE_USAGE_CONTEXT
#define PAVE_USAGE_CONTEXT

#include <std/HashMap_str_ref_Type.h>
#include <std/str.h>

struct Type;
struct ArenaAllocator;

#include <stdio.h>

#line 31 "src/compiler/Usages.pv"
struct UsageContext {
    struct HashMap_str_ref_Type cpp_usages;
};

#line 36 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator);

#endif
