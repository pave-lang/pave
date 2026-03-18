#ifndef PAVE_ENUM
#define PAVE_ENUM

#include <stdint.h>
#include <analyzer/types/EnumType.h>
#include <analyzer/types/Generics.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/str.h>
#include <analyzer/types/EnumVariant.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/Array_ref_Impl.h>
#include <stdbool.h>

struct Token;
struct Context;
struct Trait;
struct Impl;
struct Enum;

#line 22 "src/analyzer/types/Enum.pv"
struct Enum {
    struct Token* name;
    struct Context* context;
    uintptr_t token_start;
    uintptr_t token_end;
    enum EnumType type;
    struct Generics generics;
    struct HashMap_str_EnumVariant variants;
    struct HashMap_str_ref_Trait traits;
    struct Array_ref_Impl impls;
};

#line 35 "src/analyzer/types/Enum.pv"
struct Enum Enum__new(struct Context* context);

#line 45 "src/analyzer/types/Enum.pv"
struct Enum Enum__parse(struct Context* context);

#line 64 "src/analyzer/types/Enum.pv"
bool Enum__prefill_types(struct Enum* self);

#line 74 "src/analyzer/types/Enum.pv"
bool Enum__fill_variants(struct Enum* self);

#line 93 "src/analyzer/types/Enum.pv"
bool Enum__parse_variant(struct Enum* self);

#endif
