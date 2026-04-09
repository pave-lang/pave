#ifndef PAVE_NAMESPACE_PATH
#define PAVE_NAMESPACE_PATH

#include <stdbool.h>
#include <std/Array_ref_Token.h>
#include <std/trait_Allocator.h>

struct Token;
struct Context;

#line 3 "src/analyzer/NamespacePath.pv"
struct NamespacePath {
    bool root;
    struct Array_ref_Token parts;
};

#line 9 "src/analyzer/NamespacePath.pv"
struct NamespacePath NamespacePath__new(struct trait_Allocator allocator);

#line 13 "src/analyzer/NamespacePath.pv"
bool NamespacePath__parse(struct NamespacePath* self, struct Context* context);

#endif
