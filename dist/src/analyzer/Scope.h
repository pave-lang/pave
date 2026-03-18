#ifndef PAVE_SCOPE
#define PAVE_SCOPE

#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/types/Type.h>

struct Block;
struct ArenaAllocator;

#line 4 "src/analyzer/Scope.pv"
struct Scope {
    struct HashMap_str_Type values;
    struct Block* block;
};

#line 10 "src/analyzer/Scope.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block);

#endif
