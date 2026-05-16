#ifndef PAVE_IMPL
#define PAVE_IMPL

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Generics.h>
#include <std/Array_ImplNode.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <std/HashMap_str_usize.h>
#include <std/HashMap_str_Type.h>
struct Context;
struct Token;
struct Trait;

#line 61 "src/analyzer/Impl.pv"
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
    struct HashMap_str_ref_ImplConst consts;
    struct HashMap_str_usize typedef_starts;
    struct HashMap_str_Type typedefs;
};

#include <analyzer/Impl.h>
#include <analyzer/types/FunctionParent.h>
#include <std/str.h>
struct Context;
struct Impl;
struct Function;

#line 80 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context);

#line 109 "src/analyzer/Impl.pv"
bool Impl__skip_to_open_brace(struct Impl* self);

#line 123 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self);

#line 153 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent);

#line 220 "src/analyzer/Impl.pv"
struct Function* Impl__find_function(struct Impl* self, struct str name);

#line 231 "src/analyzer/Impl.pv"
bool Impl__parse_consts(struct Impl* self);

#line 238 "src/analyzer/Impl.pv"
bool Impl__parse_typedefs(struct Impl* self);

#line 277 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self);

#endif
