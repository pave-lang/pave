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
struct Trait;
struct ArenaAllocator;
struct Root;

#line 29 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file);

#line 37 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s);

#line 43 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s);

#line 47 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s);

#line 73 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s);

#line 92 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token);

#line 96 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 107 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union_no_indirect(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 117 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 124 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 131 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics);

#line 144 "src/compiler/Generator.pv"
void Generator__write_array_decl_suffix(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 161 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 170 "src/compiler/Generator.pv"
bool Generator__write_dynamic_vtable_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics);

#line 179 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type);

#line 187 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics);

#line 195 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map);

#line 314 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant);

#line 325 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 340 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics);

#line 345 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 366 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value);

#line 401 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 412 "src/compiler/Generator.pv"
bool Generator__write_typename(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics);

#line 423 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token);

#line 432 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes);

#line 445 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls);

#line 460 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives);

#line 479 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics);

#line 509 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self);

#line 514 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name);

#line 521 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 528 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext);

#line 546 "src/compiler/Generator.pv"
void Generator__collect_primitive_includes(struct Generator* self, struct Type* type, struct GenericMap* generics, struct HashSet_str* out);

#line 559 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics);

#line 597 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Root* root);

#endif
