#ifndef PAVE_GENERICS
#define PAVE_GENERICS

#include <stdbool.h>

#include <std/Array_Generic.h>
#include <std/HashMap_str_usize.h>
struct Generics;

#line 42 "src/analyzer/types/Generics.pv"
struct Generics {
    struct Generics* parent;
    struct Array_Generic array;
    struct HashMap_str_usize map;
};

#include <std/trait_Allocator.h>
#include <analyzer/types/Generics.h>
#include <std/str.h>
struct Generics;
struct Generic;
struct Context;

#line 49 "src/analyzer/types/Generics.pv"
struct Generics Generics__new(struct trait_Allocator allocator);

#line 56 "src/analyzer/types/Generics.pv"
bool Generics__has(struct Generics* self, struct str name);

#line 63 "src/analyzer/types/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name);

#line 75 "src/analyzer/types/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context);

#endif
