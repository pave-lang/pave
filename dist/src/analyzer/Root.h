#ifndef PAVE_ROOT
#define PAVE_ROOT

#include <stdbool.h>
#include <stdint.h>

#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMap_str_Array_Type.h>
#include <std/HashMap_str_ref_Primitive.h>
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
    struct HashMap_str_ref_Primitive primitives;
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
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Analysis* analysis);

#line 173 "src/analyzer/Root.pv"
void Root__add_clang_arg(struct Root* self, char const* arg);

#line 183 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name);

#line 189 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name);

#line 198 "src/analyzer/Root.pv"
uintptr_t Root__add_type_impl(struct Root* self, struct Type type, struct Impl* impl_info);

#line 204 "src/analyzer/Root.pv"
struct TypeImpl* Root__get_type_impl(struct Root* self, struct Type* type, uintptr_t impl_index);

#line 212 "src/analyzer/Root.pv"
struct Function* Root__find_type_impl_function(struct Root* self, struct Type* type, struct str name, struct GenericMap* generic_map);

#line 229 "src/analyzer/Root.pv"
bool Root__type_impl_target_eq(struct Root* self, struct Type* left, struct Type* right);

#line 343 "src/analyzer/Root.pv"
bool Root__type_impl_generics_eq(struct Root* self, struct GenericMap* left, struct GenericMap* right);

#line 354 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path);

#line 368 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name);

#line 375 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self);

#line 385 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self);

#line 393 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self);

#line 401 "src/analyzer/Root.pv"
bool Root__prefill_types_impl(struct Root* self);

#line 409 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self);

#line 428 "src/analyzer/Root.pv"
bool Root__parse_globals(struct Root* self);

#line 436 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self);

#line 450 "src/analyzer/Root.pv"
bool Root__parse_functions_if_path(struct Root* self, struct str path);

#line 467 "src/analyzer/Root.pv"
struct Module* Root__find_module_by_path(struct Root* self, struct str path);

#line 475 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name, uintptr_t arity);

#line 486 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name, uintptr_t arity);

#line 498 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name);

#line 502 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, struct str name);

#line 508 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message);

#line 535 "src/analyzer/Root.pv"
struct Type* Root__make_type_usage(struct Root* self, struct Type* type, struct Array_Type* usage_types);

#endif
