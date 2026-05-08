#ifndef PAVE_GENERATOR
#define PAVE_GENERATOR

#include <stdint.h>
#include <stdbool.h>

#include <std/HashMap_str_str.h>
#include <std/Array_String.h>
#include <compiler/FileWriter.h>
#include <analyzer/Naming.h>
struct ArenaAllocator;
struct Root;
struct Naming;
struct FunctionContext;

#line 12 "src/compiler/Generator.pv"
struct Generator {
    struct ArenaAllocator* allocator;
    char const* path;
    struct Root* root;
    struct HashMap_str_str primitives;
    struct HashMap_str_str primitive_includes;
    int16_t indent;
    struct Array_String code_files;
    struct FileWriter error;
    bool output_line_directives;
    struct Naming* naming_decl;
    struct Naming naming_ident;
    struct Naming naming_c99;
    struct FunctionContext* function_context;
};

#include <stdio.h>
#include <std/str.h>
#include <std/String.h>
struct Generator;
struct String;
struct Token;
struct Type;
struct GenericMap;
struct Function;
struct EnumVariant;
struct Context;
struct Expression;
struct Sequence;
struct Array_InvokeArgument;
struct Array_DeferStatement;
struct Block;
struct HashMap_str_ref_Include;
struct Array_ref_Impl;
struct HashSet_str;
struct Parameter;
struct TypeFunctionUsage;
struct UsageContext;
struct Enum;
struct TypeUsage_Enum;
struct IncludeWriter;
struct Struct;
struct TypeUsage_Struct;
struct Impl;
struct Primitive;
struct Trait;
struct Module;
struct Array_HashMap_usize_TypeFunctionUsage;
struct TypeUsage_Primitive;
struct TypeUsage_Sequence;
struct TypeUsage_Tuple;
struct TypeUsage_Trait;
struct HashMap_str_ref_Namespace;
struct ArenaAllocator;
struct Root;

#line 29 "src/compiler/Generator.pv"
bool Generator__overwrite_if_different(struct Generator* self, char const* file_name, FILE* source);

#line 64 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file);

#line 73 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s);

#line 79 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s);

#line 83 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s);

#line 109 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s);

#line 128 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token);

#line 132 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 143 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 150 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 157 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics);

#line 167 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 176 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type);

#line 184 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 192 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map);

#line 312 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant);

#line 323 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 338 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics);

#line 344 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 365 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value);

#line 380 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 391 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token);

#line 400 "src/compiler/Generator.pv"
void Generator__write_str_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference);

#line 409 "src/compiler/Generator.pv"
void Generator__write_trait_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics);

#line 473 "src/compiler/Generator.pv"
void Generator__write_sequence_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics);

#line 528 "src/compiler/Generator.pv"
bool Generator__write_struct_construction(struct Generator* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics);

#line 582 "src/compiler/Generator.pv"
bool Generator__write_enum_variant(struct Generator* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 632 "src/compiler/Generator.pv"
bool Generator__write_coroutine_invoke(struct Generator* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 678 "src/compiler/Generator.pv"
bool Generator__write_builtin_function_invoke(struct Generator* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics);

#line 721 "src/compiler/Generator.pv"
bool Generator__write_invoke(struct Generator* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 950 "src/compiler/Generator.pv"
bool Generator__write_expression(struct Generator* self, FILE* file, struct Expression* expression, struct GenericMap* generics);

#line 1108 "src/compiler/Generator.pv"
bool Generator__write_defer_statements(struct Generator* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics);

#line 1128 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self);

#line 1132 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name);

#line 1137 "src/compiler/Generator.pv"
bool Generator__write_block(struct Generator* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets);

#line 1693 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes);

#line 1706 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls);

#line 1720 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives);

#line 1739 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics);

#line 1768 "src/compiler/Generator.pv"
bool Generator__write_function_definition(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name);

#line 1814 "src/compiler/Generator.pv"
bool Generator__generate_function_loop(struct Generator* self, struct TypeFunctionUsage* usage);

#line 1824 "src/compiler/Generator.pv"
bool Generator__write_function_block(struct Generator* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct TypeFunctionUsage* function_usage);

#line 1910 "src/compiler/Generator.pv"
bool Generator__write_function_coroutine(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 1958 "src/compiler/Generator.pv"
bool Generator__generate_function(struct Generator* self, struct TypeFunctionUsage* usage, struct UsageContext* usage_context);

#line 2035 "src/compiler/Generator.pv"
bool Generator__write_enum_definition(struct Generator* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer);

#line 2206 "src/compiler/Generator.pv"
bool Generator__generate_enum_loop(struct Generator* self, struct TypeUsage_Enum* usage);

#line 2216 "src/compiler/Generator.pv"
bool Generator__generate_enum(struct Generator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context);

#line 2272 "src/compiler/Generator.pv"
bool Generator__write_struct_definition(struct Generator* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context);

#line 2436 "src/compiler/Generator.pv"
bool Generator__write_impl_definition(struct Generator* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics);

#line 2475 "src/compiler/Generator.pv"
bool Generator__write_primitive_definition(struct Generator* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics);

#line 2497 "src/compiler/Generator.pv"
bool Generator__write_trait_definition(struct Generator* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics);

#line 2542 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Function* func_info, struct GenericMap* generics);

#line 2554 "src/compiler/Generator.pv"
bool Generator__write_impls(struct Generator* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer);

#line 2941 "src/compiler/Generator.pv"
bool Generator__generate_struct_loop(struct Generator* self, struct TypeUsage_Struct* usage);

#line 2951 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 2958 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 2975 "src/compiler/Generator.pv"
bool Generator__generate_struct(struct Generator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context);

#line 3268 "src/compiler/Generator.pv"
bool Generator__generate_primitive_loop(struct Generator* self, struct TypeUsage_Primitive* usage);

#line 3278 "src/compiler/Generator.pv"
bool Generator__generate_primitive(struct Generator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context);

#line 3360 "src/compiler/Generator.pv"
bool Generator__generate_sequence(struct Generator* self, struct TypeUsage_Sequence* usage);

#line 3375 "src/compiler/Generator.pv"
bool Generator__generate_slice(struct Generator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context);

#line 3444 "src/compiler/Generator.pv"
bool Generator__generate_tuple_loop(struct Generator* self, struct TypeUsage_Tuple* usage);

#line 3454 "src/compiler/Generator.pv"
bool Generator__generate_tuple(struct Generator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context);

#line 3507 "src/compiler/Generator.pv"
bool Generator__generate_trait_loop(struct Generator* self, struct TypeUsage_Trait* usage);

#line 3517 "src/compiler/Generator.pv"
bool Generator__generate_trait(struct Generator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context);

#line 3561 "src/compiler/Generator.pv"
void Generator__create_directories(struct Generator* self, struct str base_path, struct HashMap_str_ref_Namespace* children);

#line 3573 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Root* root);

#endif
