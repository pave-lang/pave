#ifndef PAVE_IMPL
#define PAVE_IMPL

#include <stdint.h>
#include <analyzer/Generics.h>
#include <std/Array_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/Function.h>
#include <analyzer/Type.h>
#include <stdbool.h>

struct Token;
struct Type;
struct Context;
struct Trait;
struct Impl;
struct FunctionParent;

#line 7 "src/analyzer/Impl.pv"
struct Impl {
    struct Token* name;
    struct Type* type;
    struct Context* context;
    uintptr_t declaration_start;
    uintptr_t declaration_end;
    uintptr_t token_start;
    uintptr_t token_end;
    struct Token* trait_name;
    struct Type* trait_type;
    struct Generics impl_generics;
    struct Generics trait_generics;
    struct Generics struct_generics;
    struct Trait* trait_;
    struct Array_ImplNode nodes;
    struct HashMap_str_Function functions;
    struct Type type_self;
};

#line 27 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context);

#line 46 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self);

#line 84 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent);

#line 111 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self);

#endif
