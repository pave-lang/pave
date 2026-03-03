#ifndef PAVE_TYPE
#define PAVE_TYPE

#include <stdio.h>

#include <std/str.h>
#include <std/Array_Type.h>
#include <analyzer/Type.h>
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

#line 80 "src/analyzer/Type.pv"
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

#line 103 "src/analyzer/Type.pv"
char const* Type__name(struct Type* self);
#line 127 "src/analyzer/Type.pv"
struct Type* Type__deref(struct Type* self);
#line 136 "src/analyzer/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self);
#line 145 "src/analyzer/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self);
#line 165 "src/analyzer/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator);
#line 173 "src/analyzer/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context);
#line 185 "src/analyzer/Type.pv"
bool Type__eq(struct Type* self, struct Type* other);
#line 209 "src/analyzer/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other);
#line 220 "src/analyzer/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq);
#line 231 "src/analyzer/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple);
#line 253 "src/analyzer/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other);
#line 263 "src/analyzer/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics);
#line 274 "src/analyzer/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics);
#line 289 "src/analyzer/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics);
#line 299 "src/analyzer/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic);
#line 310 "src/analyzer/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics);
#line 322 "src/analyzer/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other);
#line 331 "src/analyzer/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other);
#line 340 "src/analyzer/Type.pv"
bool Type__eq_self(struct Type* self);
#line 352 "src/analyzer/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other);
#line 362 "src/analyzer/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum);
#line 372 "src/analyzer/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct);
#line 382 "src/analyzer/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union);
#line 392 "src/analyzer/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class);
#line 402 "src/analyzer/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace);
#line 412 "src/analyzer/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function);
#line 422 "src/analyzer/Type.pv"
bool Type__is_void(struct Type* self);
#line 431 "src/analyzer/Type.pv"
bool Type__is_enum(struct Type* self);
#line 438 "src/analyzer/Type.pv"
bool Type__is_indirect(struct Type* self);
#line 445 "src/analyzer/Type.pv"
bool Type__is_trait(struct Type* self);
#line 452 "src/analyzer/Type.pv"
bool Type__is_tuple(struct Type* self);
#line 459 "src/analyzer/Type.pv"
struct Type* Type__deref_1(struct Type* self);
#line 466 "src/analyzer/Type.pv"
bool Type__is_fat_pointer(struct Type* self);
#line 477 "src/analyzer/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self);
#line 487 "src/analyzer/Type.pv"
bool Type__is_iterator(struct Type* self);
#line 496 "src/analyzer/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other);
#line 547 "src/analyzer/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self);
#line 562 "src/analyzer/Type.pv"
struct Module* Type__get_module(struct Type* self);

#endif
