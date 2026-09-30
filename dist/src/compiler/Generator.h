#ifndef PAVE_GENERATOR
#define PAVE_GENERATOR

#include <stdint.h>
#include <stdbool.h>

#include <std/HashMap_str_str.h>
#include <std/Array_String.h>
#include <compiler/FileWriter.h>
#include <analyzer/Naming.h>
#include <std/Array_str.h>
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
    struct Array_str game_namespaces;
    bool current_host;
    struct Array_String host_files;
    struct Array_String game_files;
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
struct Trait;
struct ArenaAllocator;
struct Root;

#line 36 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file);

#line 44 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s);

#line 50 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s);

#line 54 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s);

#line 80 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s);

#line 99 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token);

#line 103 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 114 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union_no_indirect(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 124 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 131 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 138 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics);

#line 151 "src/compiler/Generator.pv"
void Generator__write_array_decl_suffix(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 168 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 177 "src/compiler/Generator.pv"
bool Generator__write_dynamic_vtable_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 186 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type);

#line 194 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 202 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map);

#line 321 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant);

#line 332 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 347 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics);

#line 352 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 373 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value);

#line 408 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 419 "src/compiler/Generator.pv"
bool Generator__write_typename(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 430 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token);

#line 439 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes);

#line 452 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls);

#line 467 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives);

#line 486 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics);

#line 516 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self);

#line 521 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name);

#line 528 "src/compiler/Generator.pv"
bool Generator__namespace_is_game(struct Generator* self, struct Module* module);

#line 547 "src/compiler/Generator.pv"
bool Generator__generics_are_game(struct Generator* self, struct GenericMap* generics, uint32_t depth);

#line 558 "src/compiler/Generator.pv"
bool Generator__type_is_game(struct Generator* self, struct Type* type, uint32_t depth);

#line 594 "src/compiler/Generator.pv"
void Generator__begin_file(struct Generator* self, struct Type* type, struct GenericMap* generics, struct Module* module);

#line 601 "src/compiler/Generator.pv"
void Generator__add_code_file(struct Generator* self, struct String code);

#line 609 "src/compiler/Generator.pv"
void Generator__write_extern(struct Generator* self, FILE* file);

#line 614 "src/compiler/Generator.pv"
bool Generator__write_file_list(struct Generator* self, char const* name, struct Array_String* files);

#line 629 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 636 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 654 "src/compiler/Generator.pv"
void Generator__collect_primitive_includes(struct Generator* self, struct Type* type, struct GenericMap* generics, struct HashSet_str* out);

#line 667 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics);

#line 705 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Array_str game_namespaces, struct Root* root);

#endif
