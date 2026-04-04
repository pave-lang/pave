#ifndef PAVE_STRUCT
#define PAVE_STRUCT

#include <stdint.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/StructType.h>
#include <std/HashMap_str_StructField.h>
#include <std/str.h>
#include <analyzer/types/StructField.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/Array_ref_Impl.h>
#include <stdbool.h>

struct Token;
struct Module;
struct Trait;
struct Type;
struct Impl;
struct Struct;

#line 15 "src/analyzer/types/Struct.pv"
struct Struct {
    struct Token* name;
    struct Module* module;
    uintptr_t token_start;
    uintptr_t token_end;
    struct Generics generics;
    enum StructType type;
    struct HashMap_str_StructField fields;
    struct HashMap_str_tuple_ref_Trait_ref_Type traits;
    struct Array_ref_Impl impls;
};

#line 28 "src/analyzer/types/Struct.pv"
struct Struct Struct__new(struct Module* module);

#line 40 "src/analyzer/types/Struct.pv"
struct Struct Struct__parse(struct Module* module);

#line 69 "src/analyzer/types/Struct.pv"
bool Struct__prefill_types(struct Struct* self);

#line 82 "src/analyzer/types/Struct.pv"
bool Struct__fill_types(struct Struct* self);

#line 95 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_field(struct Struct* self);

#line 140 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self);

#line 183 "src/analyzer/types/Struct.pv"
bool Struct__is_newtype(struct Struct* self);

#endif
