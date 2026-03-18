#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>

#include <compiler/UsageContext.h>

#line 39 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator) {
    #line 40 "src/compiler/Usages.pv"
    return (struct UsageContext) { .cpp_usages = HashMap_str_ref_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}
