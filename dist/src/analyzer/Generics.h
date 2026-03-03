#ifndef PAVE_GENERICS
#define PAVE_GENERICS

#include <std/Array_Generic.h>
#include <analyzer/Generic.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <std/Allocator.h>
#include <stdbool.h>

struct Generics;
struct str;
struct Generic;
struct Context;

#line 41 "src/analyzer/Generics.pv"
struct Generics {
    struct Generics* parent;
    struct Array_Generic array;
    struct HashMap_str_usize map;
};

#line 48 "src/analyzer/Generics.pv"
struct Generics Generics__new(struct Allocator allocator);

#line 55 "src/analyzer/Generics.pv"
bool Generics__has(struct Generics* self, struct str name);

#line 62 "src/analyzer/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name);

#line 74 "src/analyzer/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context);

#endif
