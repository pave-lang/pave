#ifndef PAVE_GENERICS
#define PAVE_GENERICS

#include <std/Array_Generic.h>
#include <analyzer/types/Generic.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <std/trait_Allocator.h>
#include <stdbool.h>

struct Generics;
struct str;
struct Generic;
struct Context;

#line 42 "src/analyzer/types/Generics.pv"
struct Generics {
    struct Generics* parent;
    struct Array_Generic array;
    struct HashMap_str_usize map;
};

#line 49 "src/analyzer/types/Generics.pv"
struct Generics Generics__new(struct trait_Allocator allocator);

#line 56 "src/analyzer/types/Generics.pv"
bool Generics__has(struct Generics* self, struct str name);

#line 63 "src/analyzer/types/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name);

#line 75 "src/analyzer/types/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context);

#endif
