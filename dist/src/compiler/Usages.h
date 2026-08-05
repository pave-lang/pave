#ifndef PAVE_USAGES
#define PAVE_USAGES

#include <stdint.h>
#include <stdbool.h>

#include <std/Array_Type.h>
#include <std/HashSet_str.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>
#include <std/HashMap_usize_TypeUsage_Tuple.h>
#include <std/HashMap_usize_TypeUsage_TypeImpl.h>
#include <std/HashSet_usize.h>
#include <compiler/UsageMode.h>
struct ArenaAllocator;
struct Generator;
struct Root;
struct Naming;
struct UsageContext;
struct FunctionContext;
struct Namespace;

#line 141 "src/compiler/Usages.pv"
struct Usages {
    struct ArenaAllocator* allocator;
    struct Generator* generator;
    struct Root* root;
    struct Naming* naming_ident;
    struct Array_Type usages;
    struct HashSet_str usage_types;
    struct HashSet_str usage_traits;
    struct HashMap_usize_TypeUsage_Primitive primitives;
    struct HashMap_usize_TypeFunctionUsage functions;
    struct HashMap_usize_TypeUsage_Struct structs;
    struct HashMap_usize_TypeUsage_Enum enums;
    struct HashMap_usize_TypeUsage_Trait traits;
    struct HashMap_usize_TypeUsage_Sequence sequences;
    struct HashMap_usize_TypeUsage_Tuple tuples;
    struct HashMap_usize_TypeUsage_TypeImpl type_impls;
    struct HashSet_usize dynamic_impl_functions;
    enum UsageMode usage_mode;
    struct UsageContext* usage_context;
    struct FunctionContext* function_context;
    uintptr_t active_impl_index;
    struct Namespace* std_namespace;
};

struct Generator;
struct HashMap_str_ref_Namespace;
struct Module;
struct Type;
struct GenericMap;
struct Array_ref_Impl;
struct TypeImpl;
struct Primitive;
struct Sequence;
struct Tuple;
struct Struct;
struct Enum;
struct Trait;
struct UsageContext;
struct Generics;
struct Function;
struct Block;
struct Expression;

#line 170 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator);

#line 248 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children);

#line 258 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module);

#line 317 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map);

#line 457 "src/compiler/Usages.pv"
void Usages__add_type_impl_header(struct Usages* self, struct Type* self_type);

#line 465 "src/compiler/Usages.pv"
void Usages__process_impls(struct Usages* self, struct Array_ref_Impl* impls, struct GenericMap* generic_map);

#line 510 "src/compiler/Usages.pv"
void Usages__process_type_impl(struct Usages* self, struct TypeImpl* type_impl);

#line 533 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info);

#line 554 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence);

#line 607 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple);

#line 631 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map);

#line 670 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map);

#line 694 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map);

#line 711 "src/compiler/Usages.pv"
bool Usages__usage_context_matches(struct UsageContext* uc, struct Generics* generics, struct GenericMap* generic_map);

#line 725 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map);

#line 736 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map);

#line 747 "src/compiler/Usages.pv"
void Usages__mark_any_usage(struct Usages* self, struct Type* type);

#line 769 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_primitive(struct Usages* self, struct Primitive* primitive_info, struct GenericMap* generic_map);

#line 780 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map);

#line 911 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map);

#line 1030 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map);

#line 1338 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self);

#endif
