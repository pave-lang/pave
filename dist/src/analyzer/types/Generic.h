#ifndef PAVE_GENERIC
#define PAVE_GENERIC

#include <stdbool.h>

#include <std/Array_ref_Trait.h>
struct Token;

#line 4 "src/analyzer/types/Generics.pv"
struct Generic {
    struct Token* name;
    struct Array_ref_Trait traits;
};

#include <std/trait_Allocator.h>
#include <analyzer/types/Generic.h>
struct Generic;
struct Context;

#line 10 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct trait_Allocator allocator);

#line 14 "src/analyzer/types/Generics.pv"
bool Generic__parse(struct Generic* self, struct Context* context);

#endif
