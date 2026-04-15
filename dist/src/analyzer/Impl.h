#ifndef PAVE_IMPL
#define PAVE_IMPL

#include <stdint.h>
#include <stdbool.h>

struct Context;
struct Token;
struct Trait;
#include <analyzer/types/Type.h>
#include <analyzer/types/Generics.h>
#include <std/Array_ImplNode.h>
#include <std/HashMap_str_Function.h>

#line 8 "src/analyzer/Impl.pv"
struct Impl {
    struct Type type;
    struct Context* context;
    struct Token* token;
    uintptr_t token_start;
    uintptr_t token_end;
    bool has_trait;
    struct Trait* trait_;
    struct Token* trait_name;
    struct Type trait_type;
    struct Generics generics;
    struct Array_ImplNode nodes;
    struct HashMap_str_Function functions;
};

struct Context;
struct Impl;
struct Function;
#include <analyzer/Impl.h>
#include <analyzer/types/FunctionParent.h>
#include <std/str.h>

#line 24 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context);

#line 43 "src/analyzer/Impl.pv"
bool Impl__skip_to_open_brace(struct Impl* self);

#line 57 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self);

#line 87 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent);

#line 114 "src/analyzer/Impl.pv"
struct Function* Impl__find_function(struct Impl* self, struct str name);

#line 125 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self);

#endif
