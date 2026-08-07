#ifndef PAVE_GENERIC
#define PAVE_GENERIC

#include <stdbool.h>

#include <std/Array_Type.h>
struct Token;
struct Type;

#line 4 "src/analyzer/types/Generics.pv"
struct Generic {
    struct Token* name;
    struct Array_Type traits;
    struct Type* const_type;
};

#include <std/trait_Allocator.h>
struct Context;
struct Generics;

#line 11 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct trait_Allocator allocator);

#line 15 "src/analyzer/types/Generics.pv"
bool Generic__is_const(struct Generic* self);

#line 19 "src/analyzer/types/Generics.pv"
bool Generic__parse_const_type(struct Generic* self, struct Context* context, struct Generics* generics);

#line 50 "src/analyzer/types/Generics.pv"
bool Generic__parse_traits(struct Generic* self, struct Context* context, struct Generics* generics);

#endif
