#ifndef PAVE_TYPE
#define PAVE_TYPE

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
struct GenericTypedef;
struct Function;
struct TypedefC;
struct EnumC;
struct StructC;
struct FunctionC;
struct ClassCpp;
struct UnknownC;
struct NamespaceCpp;
struct Global;
#line 87 "src/analyzer/types/Type.pv"
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
        TYPE__GENERIC_TYPEDEF,
        TYPE__FUNCTION,
        TYPE__COROUTINE_INSTANCE,
        TYPE__SELF,
        TYPE__TYPEDEF_C,
        TYPE__ENUM_C,
        TYPE__STRUCT_C,
        TYPE__UNION_C,
        TYPE__FUNCTION_C,
        TYPE__CLASS_CPP,
        TYPE__UNKNOWN_C,
        TYPE__NAMESPACE_CPP,
        TYPE__GLOBAL,
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
        struct GenericTypedef* generictypedef_value;
        struct { struct Function* _0; struct GenericMap* _1; } function_value;
        struct { struct Function* _0; struct GenericMap* _1; } coroutineinstance_value;
        struct TypedefC* typedefc_value;
        struct EnumC* enumc_value;
        struct StructC* structc_value;
        struct StructC* unionc_value;
        struct FunctionC* functionc_value;
        struct ClassCpp* classcpp_value;
        struct UnknownC* unknownc_value;
        struct NamespaceCpp* namespacecpp_value;
        struct Global* global_value;
    };
};

#include <std/Array_Type.h>
struct Type;
struct ArenaAllocator;
struct Context;
struct Module;

#line 112 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self);

#line 138 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self);

#line 147 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self);

#line 156 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self);

#line 165 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self);

#line 185 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator);

#line 193 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context);

#line 206 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other);

#line 239 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other);

#line 250 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq);

#line 261 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple);

#line 283 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other);

#line 294 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics);

#line 312 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics);

#line 333 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics);

#line 349 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic);

#line 359 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other);

#line 370 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other);

#line 379 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other);

#line 388 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self);

#line 400 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other);

#line 409 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum);

#line 418 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct);

#line 427 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union);

#line 436 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class);

#line 445 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace);

#line 454 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function);

#line 463 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self);

#line 470 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self);

#line 478 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self);

#line 485 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self);

#line 493 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self);

#line 500 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self);

#line 509 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self);

#line 516 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self);

#line 523 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self);

#line 530 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self);

#line 537 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self);

#line 544 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self);

#line 551 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self);

#line 562 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self);

#line 572 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self);

#line 581 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other);

#line 632 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self);

#line 647 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self);

#endif
