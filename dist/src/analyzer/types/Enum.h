#ifndef PAVE_ENUM
#define PAVE_ENUM

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/EnumType.h>
#include <analyzer/types/Generics.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/Array_ref_Impl.h>
struct Token;
struct Context;

#line 24 "src/analyzer/types/Enum.pv"
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

#include <analyzer/types/Enum.h>
struct Context;
struct Enum;

#line 37 "src/analyzer/types/Enum.pv"
struct Enum Enum__new(struct Context* context);

#line 51 "src/analyzer/types/Enum.pv"
struct Enum Enum__parse(struct Context* context);

#line 70 "src/analyzer/types/Enum.pv"
bool Enum__prefill_types(struct Enum* self);

#line 80 "src/analyzer/types/Enum.pv"
bool Enum__fill_variants(struct Enum* self);

#line 99 "src/analyzer/types/Enum.pv"
bool Enum__parse_variant(struct Enum* self);

#line 163 "src/analyzer/types/Enum.pv"
bool Enum__is_discriminated_union(struct Enum* self);

#endif
