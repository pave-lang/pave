#ifndef PAVE_GENERIC
#define PAVE_GENERIC

#include <std/Array_ref_Trait.h>
#include <std/Allocator.h>
#include <stdbool.h>

struct Token;
struct Trait;
struct Context;

#line 3 "src/analyzer/Generics.pv"
struct Generic {
    struct Token* name;
    struct Array_ref_Trait traits;
};

#line 9 "src/analyzer/Generics.pv"
struct Generic Generic__new(struct Allocator allocator);

#line 13 "src/analyzer/Generics.pv"
bool Generic__parse(struct Generic* self, struct Context* context);

#endif
