#ifndef PAVE_GENERIC
#define PAVE_GENERIC

#include <stdbool.h>

#include <std/Array_Type.h>
struct Token;

#line 4 "src/analyzer/types/Generics.pv"
struct Generic {
    struct Token* name;
    struct Array_Type traits;
};

#include <std/trait_Allocator.h>
struct Context;
struct Generics;

#line 10 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct trait_Allocator allocator);

#line 14 "src/analyzer/types/Generics.pv"
bool Generic__parse_traits(struct Generic* self, struct Context* context, struct Generics* generics);

#endif
