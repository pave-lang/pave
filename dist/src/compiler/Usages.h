#ifndef PAVE_USAGES
#define PAVE_USAGES

#include <stdio.h>

struct ArenaAllocator;
struct Generator;
struct Root;
struct UsageContext;
struct FunctionContext;
struct Namespace;
#include <std/Array_Type.h>
#include <std/HashSet_str.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>
#include <std/HashMap_usize_TypeUsage_Tuple.h>
#include <compiler/UsageMode.h>

#line 99 "src/compiler/Usages.pv"
struct Usages {
    struct ArenaAllocator* allocator;
    struct Generator* generator;
    struct Root* root;
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
    enum UsageMode usage_mode;
    struct UsageContext* usage_context;
    struct FunctionContext* function_context;
    struct Namespace* std_namespace;
};

struct Generator;
struct Usages;
struct HashMap_str_ref_Namespace;
struct Module;
struct Type;
struct GenericMap;
struct Primitive;
struct Sequence;
struct Tuple;
struct Struct;
struct Enum;
struct Trait;
struct Function;
struct Block;
struct Expression;
#include <compiler/Usages.h>

#line 124 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator);

#line 181 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children);

#line 191 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module);

#line 257 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map);

#line 375 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info);

#line 386 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence);

#line 416 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple);

#line 438 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map);

#line 465 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map);

#line 492 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map);

#line 498 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map);

#line 579 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map);

#line 661 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map);

#line 810 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self);

#endif
