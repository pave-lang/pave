#ifndef PAVE_GENERIC
#define PAVE_GENERIC

#include <std/Array_ref_Trait.h>
#include <std/Allocator.h>
#include <stdbool.h>

struct Token;
struct Trait;
struct Context;

#line 4 "src/analyzer/types/Generics.pv"
struct Generic {
    struct Token* name;
    struct Array_ref_Trait traits;
};

#line 10 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct Allocator allocator);

#line 14 "src/analyzer/types/Generics.pv"
bool Generic__parse(struct Generic* self, struct Context* context);

#endif
