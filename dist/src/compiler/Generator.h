#ifndef PAVE_GENERATOR
#define PAVE_GENERATOR

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <std/HashMap_str_str.h>
#include <std/Array_String.h>
#include <compiler/FileWriter.h>
#include <analyzer/Naming.h>
#include <std/Array_str.h>
#include <std/HashSet_str.h>
struct ArenaAllocator;
struct Root;
struct Naming;
struct FunctionContext;
struct HashMap_usize_TypeUsage_TypeImpl;

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
    FILE* scratch;
    struct Array_str game_namespaces;
    bool current_host;
    struct Array_String host_files;
    struct Array_String game_files;
    struct HashMap_usize_TypeUsage_TypeImpl* type_impl_usages;
    struct HashSet_str type_impl_paths;
    bool test_mode;
};

#include <stdio.h>
#include <std/str.h>
#include <std/String.h>
#include <std/Array_str.h>
struct String;
struct Token;
struct Type;
struct GenericMap;
struct Function;
struct EnumVariant;
struct Context;
struct HashMap_str_ref_Include;
struct Array_ref_Impl;
struct HashSet_str;
struct Parameter;
struct Module;
struct Array_String;
struct Impl;
struct Trait;
struct ArenaAllocator;
struct Root;

#line 45 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file);

#line 53 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s);

#line 59 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s);

#line 63 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s);

#line 89 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s);

#line 108 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token);

#line 112 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 123 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union_no_indirect(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 133 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 140 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 147 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics);

#line 160 "src/compiler/Generator.pv"
void Generator__write_array_decl_suffix(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 177 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 186 "src/compiler/Generator.pv"
bool Generator__write_dynamic_vtable_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 195 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type);

#line 203 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 211 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map);

#line 330 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant);

#line 341 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 356 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics);

#line 361 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 382 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value);

#line 423 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 434 "src/compiler/Generator.pv"
bool Generator__write_typename(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 445 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token);

#line 454 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes);

#line 467 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls);

#line 482 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives);

#line 501 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics);

#line 531 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self);

#line 537 "src/compiler/Generator.pv"
FILE* Generator__scratch_file(struct Generator* self);

#line 543 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name);

#line 550 "src/compiler/Generator.pv"
bool Generator__namespace_is_game(struct Generator* self, struct Module* module);

#line 569 "src/compiler/Generator.pv"
bool Generator__generics_are_game(struct Generator* self, struct GenericMap* generics, uint32_t depth);

#line 580 "src/compiler/Generator.pv"
bool Generator__type_is_game(struct Generator* self, struct Type* type, uint32_t depth);

#line 616 "src/compiler/Generator.pv"
void Generator__begin_file(struct Generator* self, struct Type* type, struct GenericMap* generics, struct Module* module);

#line 623 "src/compiler/Generator.pv"
void Generator__add_code_file(struct Generator* self, struct String code);

#line 631 "src/compiler/Generator.pv"
void Generator__write_extern(struct Generator* self, FILE* file);

#line 636 "src/compiler/Generator.pv"
bool Generator__write_file_list(struct Generator* self, char const* name, struct Array_String* files);

#line 655 "src/compiler/Generator.pv"
struct GenericMap* Generator__trait_default_generics(struct Generator* self, struct Impl* impl_info, struct GenericMap* generics);

#line 678 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 685 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 703 "src/compiler/Generator.pv"
void Generator__collect_primitive_includes(struct Generator* self, struct Type* type, struct GenericMap* generics, struct HashSet_str* out);

#line 716 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics);

#line 754 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Array_str game_namespaces, bool test_mode, struct Root* root);

#endif
