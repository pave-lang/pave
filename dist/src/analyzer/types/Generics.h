#ifndef PAVE_GENERICS
#define PAVE_GENERICS

#include <stdbool.h>

#include <std/Array_Generic.h>
#include <std/HashMap_str_usize.h>

#line 50 "src/analyzer/types/Generics.pv"
struct Generics {
    struct Generics* parent;
    struct Array_Generic array;
    struct HashMap_str_usize map;
};

#include <std/trait_Allocator.h>
#include <std/str.h>
struct Generic;
struct Context;

#line 57 "src/analyzer/types/Generics.pv"
struct Generics Generics__new(struct trait_Allocator allocator);

#line 65 "src/analyzer/types/Generics.pv"
bool Generics__has(struct Generics* self, struct str name);

#line 72 "src/analyzer/types/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name);

#line 84 "src/analyzer/types/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context);

#line 108 "src/analyzer/types/Generics.pv"
bool Generics__is_empty(struct Generics* self);

#endif
