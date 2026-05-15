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
    struct Generics generics;
    struct HashMap_str_Function functions;
    struct HashMap_str_usize typedefs;
    struct Type type_self;
};

#include <analyzer/types/Trait.h>
#include <analyzer/types/FunctionParent.h>
struct Module;
struct Trait;

#line 16 "src/analyzer/types/Trait.pv"
struct Trait Trait__new(struct Module* module);

#line 27 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module);

#line 48 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent);

#line 81 "src/analyzer/types/Trait.pv"
bool Trait__has_typedefs(struct Trait* self);

#line 85 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self);

#endif
