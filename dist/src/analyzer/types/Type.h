#ifndef PAVE_TYPE
#define PAVE_TYPE

#include <stdio.h>

#include <std/str.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <stdbool.h>

struct Primitive;
struct Indirect;
struct Sequence;
struct Tuple;
struct Enum;
struct GenericMap;
struct Struct;
struct Trait;
struct Generic;
struct Function;
struct TypedefC;
struct EnumC;
struct StructC;
struct FunctionC;
struct ClassCpp;
struct NamespaceCpp;
struct Type;
struct ArenaAllocator;
struct Context;
struct Array_Type;
struct str;
struct Module;

#line 81 "src/analyzer/types/Type.pv"
struct Type {
    enum {
        TYPE__PRIMITIVE,
        TYPE__INDIRECT,
        TYPE__SEQUENCE,
        TYPE__TUPLE,
        TYPE__ENUM,
        TYPE__STRUCT,
        TYPE__TRAIT,
        TYPE__GENERIC,
        TYPE__UNKNOWN,
        TYPE__FUNCTION,
        TYPE__COROUTINE_INSTANCE,
        TYPE__SELF,
        TYPE__TYPEDEF_C,
        TYPE__ENUM_C,
        TYPE__STRUCT_C,
        TYPE__UNION_C,
        TYPE__FUNCTION_C,
        TYPE__CLASS_CPP,
        TYPE__NAMESPACE_CPP,
    } type;

    union {
        struct Primitive* primitive_value;
        struct Indirect* indirect_value;
        struct Sequence* sequence_value;
        struct Tuple* tuple_value;
        struct { struct Enum* _0; struct GenericMap* _1; } enum_value;
        struct { struct Struct* _0; struct GenericMap* _1; } struct_value;
        struct { struct Trait* _0; struct GenericMap* _1; } trait_value;
        struct Generic* generic_value;
        struct { struct str _0; struct Array_Type _1; } unknown_value;
        struct { struct Function* _0; struct GenericMap* _1; } function_value;
        struct { struct Function* _0; struct GenericMap* _1; } coroutineinstance_value;
        struct TypedefC* typedefc_value;
        struct EnumC* enumc_value;
        struct StructC* structc_value;
        struct StructC* unionc_value;
        struct FunctionC* functionc_value;
        struct ClassCpp* classcpp_value;
        struct NamespaceCpp* namespacecpp_value;
    };
};

#line 104 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self);
#line 128 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self);
#line 137 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self);
#line 146 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self);
#line 166 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator);
#line 174 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context);
#line 186 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other);
#line 210 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other);
#line 221 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq);
#line 232 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple);
#line 254 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other);
#line 264 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics);
#line 275 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics);
#line 290 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics);
#line 300 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic);
#line 311 "src/analyzer/types/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics);
#line 323 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other);
#line 332 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other);
#line 341 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self);
#line 353 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other);
#line 363 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum);
#line 373 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct);
#line 383 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union);
#line 393 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class);
#line 403 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace);
#line 413 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function);
#line 423 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self);
#line 432 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self);
#line 440 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self);
#line 448 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self);
#line 455 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self);
#line 462 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self);
#line 469 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self);
#line 476 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self);
#line 483 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self);
#line 494 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self);
#line 504 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self);
#line 513 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other);
#line 564 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self);
#line 579 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self);

#endif
