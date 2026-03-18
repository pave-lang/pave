#ifndef PAVE_TRAIT
#define PAVE_TRAIT

#include <stdint.h>
#include <analyzer/types/Generics.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Type.h>
#include <stdbool.h>

struct Token;
struct Module;
struct FunctionParent;

#line 4 "src/analyzer/types/Trait.pv"
struct Trait {
    struct Token* name;
    struct Module* module;
    uintptr_t token_start;
    uintptr_t token_end;
    struct Generics generics;
    struct HashMap_str_Function functions;
    struct Type type_self;
};

#line 15 "src/analyzer/types/Trait.pv"
struct Trait Trait__new(struct Module* module);

#line 25 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module);

#line 46 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent);

#line 66 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self);

#endif
