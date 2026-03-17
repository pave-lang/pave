#include <std/ArenaAllocator.h>
#include <std/Array_ForVariable.h>
#include <analyzer/statement/ForVariable.h>
#include <std/Allocator.h>

#include <analyzer/statement/ForStatement.h>

#line 15 "src/analyzer/statement/ForStatement.pv"
struct ForStatement ForStatement__new(struct ArenaAllocator* allocator) {
    #line 16 "src/analyzer/statement/ForStatement.pv"
    return (struct ForStatement) { .variables = Array_ForVariable__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}
