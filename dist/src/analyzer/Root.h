#ifndef PAVE_ROOT
#define PAVE_ROOT

#include <stdbool.h>
#include <stdint.h>

#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMap_str_Array_Type.h>
#include <std/HashMap_str_Primitive.h>
#include <std/HashMap_str_TypedefC.h>
#include <std/HashMap_str_Array_ref_Trait.h>
#include <std/HashMap_str_Type.h>
#include <std/Array_ptrc_char.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Function.h>
#include <analyzer/Naming.h>
#include <std/Array_TypeImpl.h>
#include <std/HashMap_str_ref_Include.h>
struct ArenaAllocator;
struct Analysis;
struct Primitive;
struct TypeImpl;

#line 8 "src/analyzer/Root.pv"
struct Root {
    struct ArenaAllocator* allocator;
    struct HashMap_str_ref_Namespace children;
    struct HashMap_str_Array_Type types;
    struct HashMap_str_Primitive primitives;
    struct HashMap_str_TypedefC ctypes;
    struct HashMap_str_Array_ref_Trait traits;
    struct HashMap_str_Type functions;
    struct Array_ptrc_char clang_args;
    char const* c_std_arg;
    char const* cpp_std_arg;
    struct Analysis* analysis;
    struct Primitive* primitive_bool;
    struct Primitive* primitive_usize;
    struct Primitive* primitive_void;
    struct Type type_void;
    struct Type type_bool;
    struct Type type_unknown;
    struct Type type_self;
    struct Type type_ref_self;
    struct Type type_usize;
    struct Function func_next;
    struct Function func_value;
    struct Naming naming_decl;
    struct Array_TypeImpl type_impls;
    struct TypeImpl* hack_type_impl;
    struct HashMap_str_ref_Include includes_c;
    struct HashMap_str_ref_Include includes_cpp;
    bool mode_cpp;
};

#include <analyzer/types/Type.h>
#include <std/str.h>
struct ArenaAllocator;
struct Array_ptrc_char;
struct Analysis;
struct Root;
struct Primitive;
struct Impl;
struct Type;
struct TypeImpl;
struct GenericMap;
struct Function;
struct Namespace;
struct Module;
struct Trait;
struct Array_Type;

#line 40 "src/analyzer/Root.pv"
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Array_ptrc_char* clang_args, char const* c_std_arg, char const* cpp_std_arg, struct Analysis* analysis);

#line 163 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name);

#line 167 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name);

#line 174 "src/analyzer/Root.pv"
uintptr_t Root__add_type_impl(struct Root* self, struct Type type, struct Impl* impl_info);

#line 180 "src/analyzer/Root.pv"
struct TypeImpl* Root__get_type_impl(struct Root* self, struct Type* type, uintptr_t impl_index);

#line 188 "src/analyzer/Root.pv"
struct Function* Root__find_type_impl_function(struct Root* self, struct Type* type, struct str name, struct GenericMap* generic_map);

#line 205 "src/analyzer/Root.pv"
bool Root__type_impl_target_eq(struct Root* self, struct Type* left, struct Type* right);

#line 319 "src/analyzer/Root.pv"
bool Root__type_impl_generics_eq(struct Root* self, struct GenericMap* left, struct GenericMap* right);

#line 330 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path);

#line 344 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name);

#line 351 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self);

#line 359 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self);

#line 367 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self);

#line 375 "src/analyzer/Root.pv"
bool Root__prefill_types_impl(struct Root* self);

#line 383 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self);

#line 402 "src/analyzer/Root.pv"
bool Root__parse_globals(struct Root* self);

#line 410 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self);

#line 424 "src/analyzer/Root.pv"
bool Root__parse_functions_if_path(struct Root* self, struct str path);

#line 441 "src/analyzer/Root.pv"
struct Module* Root__find_module_by_path(struct Root* self, struct str path);

#line 449 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name, uintptr_t arity);

#line 460 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name, uintptr_t arity);

#line 472 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name);

#line 476 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, struct str name);

#line 480 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message);

#line 507 "src/analyzer/Root.pv"
struct Type* Root__make_type_usage(struct Root* self, struct Type* type, struct Array_Type* usage_types);

#endif
