#ifndef PAVE_TRAIT
#define PAVE_TRAIT

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/Generics.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/Type.h>
struct Token;
struct Module;

#line 4 "src/analyzer/types/Trait.pv"
struct Trait {
    struct Token* name;
    struct Module* module;
    uintptr_t token_start;
    uintptr_t token_end;
    uintptr_t generic_arity;
    struct Generics generics;
    struct HashMap_str_Function functions;
    struct HashMap_str_usize typedefs;
    struct Type type_self;
};

#include <analyzer/types/Trait.h>
#include <analyzer/types/FunctionParent.h>
#include <std/trait_Allocator.h>
#include <std/str.h>
struct Module;
struct Trait;

#line 17 "src/analyzer/types/Trait.pv"
struct Trait Trait__new(struct Module* module);

#line 33 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module);

#line 55 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent);

#line 88 "src/analyzer/types/Trait.pv"
struct str Trait__get_key(struct Trait* self, struct trait_Allocator allocator);

#line 99 "src/analyzer/types/Trait.pv"
bool Trait__has_dynamic_dispatch(struct Trait* self);

#line 112 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self);

#endif
