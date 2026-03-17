#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Include.h>
#include <analyzer/Type.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/str.h>

#include <analyzer/TypedefC.h>

#line 885 "src/analyzer/Include.pv"
struct TypedefC* TypedefC__new(struct Include* include, char const* name, struct Type* type) {
    #line 886 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 888 "src/analyzer/Include.pv"
    return ArenaAllocator__store_TypedefC(allocator, (struct TypedefC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .type = type,
    });
}
