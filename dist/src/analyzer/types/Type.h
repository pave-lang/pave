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
struct Type* Type__deref_reference(struct Type* self);

#line 160 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self);

#line 169 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self);

#line 178 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self);

#line 198 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator);

#line 206 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context);

#line 219 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other);

#line 252 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other);

#line 263 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq);

#line 274 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple);

#line 296 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other);

#line 307 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics);

#line 325 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics);

#line 346 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics);

#line 362 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic);

#line 372 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other);

#line 383 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other);

#line 392 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other);

#line 401 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self);

#line 413 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other);

#line 422 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum);

#line 431 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct);

#line 440 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union);

#line 449 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class);

#line 458 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace);

#line 467 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function);

#line 476 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self);

#line 486 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self);

#line 494 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self);

#line 501 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self);

#line 509 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self);

#line 516 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self);

#line 525 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self);

#line 532 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self);

#line 539 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self);

#line 546 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self);

#line 553 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self);

#line 560 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self);

#line 567 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self);

#line 574 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self);

#line 585 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self);

#line 595 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self);

#line 604 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other);

#line 655 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self);

#line 663 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self);

#line 676 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self);

#endif
