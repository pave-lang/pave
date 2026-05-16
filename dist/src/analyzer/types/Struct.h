#ifndef PAVE_STRUCT
#define PAVE_STRUCT

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/Generics.h>
#include <analyzer/types/StructType.h>
#include <std/HashMap_str_StructField.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/Array_ref_Impl.h>
struct Token;
struct Module;

#line 16 "src/analyzer/types/Struct.pv"
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

#include <analyzer/types/Struct.h>
struct Module;
struct Struct;

#line 29 "src/analyzer/types/Struct.pv"
struct Struct Struct__new(struct Module* module);

#line 41 "src/analyzer/types/Struct.pv"
struct Struct Struct__parse(struct Module* module);

#line 70 "src/analyzer/types/Struct.pv"
bool Struct__prefill_types(struct Struct* self);

#line 83 "src/analyzer/types/Struct.pv"
bool Struct__fill_types(struct Struct* self);

#line 96 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_field(struct Struct* self);

#line 163 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self);

#line 207 "src/analyzer/types/Struct.pv"
bool Struct__is_newtype(struct Struct* self);

#endif
