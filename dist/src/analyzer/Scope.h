#ifndef PAVE_SCOPE
#define PAVE_SCOPE

#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/Type.h>

struct Block;
struct ArenaAllocator;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#line 7 "src/analyzer/Context.pv"
struct Scope {
    struct HashMap_str_Type values;
    struct Block* block;
};

#line 13 "src/analyzer/Context.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block);

#endif
