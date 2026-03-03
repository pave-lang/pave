#ifndef PAVE_STRUCT
#define PAVE_STRUCT

#include <stdint.h>
#include <analyzer/Generics.h>
#include <analyzer/StructType.h>
#include <std/HashMap_str_StructField.h>
#include <std/str.h>
#include <analyzer/StructField.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/Array_ref_Impl.h>
#include <stdbool.h>

struct Token;
struct Module;
struct Trait;
struct Impl;
struct Struct;

#line 14 "src/analyzer/Struct.pv"
struct Struct {
    struct Token* name;
    struct Module* module;
    uintptr_t token_start;
    uintptr_t token_end;
    struct Generics generics;
    enum StructType type;
    struct HashMap_str_StructField fields;
    struct HashMap_str_ref_Trait traits;
    struct Array_ref_Impl impls;
};

#line 27 "src/analyzer/Struct.pv"
struct Struct Struct__new(struct Module* module);

#line 39 "src/analyzer/Struct.pv"
struct Struct Struct__parse(struct Module* module);

#line 68 "src/analyzer/Struct.pv"
bool Struct__prefill_types(struct Struct* self);

#line 81 "src/analyzer/Struct.pv"
bool Struct__fill_types(struct Struct* self);

#line 94 "src/analyzer/Struct.pv"
bool Struct__fill_types_field(struct Struct* self);

#line 139 "src/analyzer/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self);

#line 182 "src/analyzer/Struct.pv"
bool Struct__is_newtype(struct Struct* self);

#endif
