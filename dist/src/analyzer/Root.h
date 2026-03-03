#ifndef PAVE_ROOT
#define PAVE_ROOT

#include <std/HashMap_str_ref_Namespace.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/Primitive.h>
#include <std/HashMap_str_TypedefC.h>
#include <analyzer/TypedefC.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/Array_ptrc_char.h>
#include <analyzer/Function.h>
#include <analyzer/Naming.h>
#include <std/HashMap_str_ref_Include.h>
#include <stdbool.h>
#include <stdint.h>

struct ArenaAllocator;
struct Namespace;
struct Trait;
struct Analysis;
struct Primitive;
struct TypeImpl;
struct Include;
struct Array_ptrc_char;
struct str;
struct Type;

#include <stdio.h>
#include <string.h>

#line 6 "src/analyzer/Root.pv"
struct Root {
    struct ArenaAllocator* allocator;
    struct HashMap_str_ref_Namespace children;
    struct HashMap_str_Type types;
    struct HashMap_str_Primitive primitives;
    struct HashMap_str_TypedefC ctypes;
    struct HashMap_str_ref_Trait traits;
    struct HashMap_str_Type functions;
    struct Array_ptrc_char clang_args;
    struct Analysis* analysis;
    struct Primitive* primitive_bool;
    struct Primitive* primitive_usize;
    struct Primitive* primitive_void;
    struct Type type_void;
    struct Type type_self;
    struct Type type_ref_self;
    struct Type type_usize;
    struct Function func_next;
    struct Function func_value;
    struct Naming naming_decl;
    struct TypeImpl* hack_type_impl;
    struct HashMap_str_ref_Include includes_c;
    struct HashMap_str_ref_Include includes_cpp;
};

#line 33 "src/analyzer/Root.pv"
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Array_ptrc_char* clang_args, struct Analysis* analysis);

#line 115 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name);

#line 119 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name);

#line 126 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path);

#line 140 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name);

#line 147 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self);

#line 155 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self);

#line 163 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self);

#line 171 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self);

#line 190 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self);

#line 204 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name);

#line 208 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name);

#line 214 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name);

#line 218 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, char const* name);

#line 222 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message);

#endif
