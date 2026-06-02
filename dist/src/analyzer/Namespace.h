#ifndef PAVE_NAMESPACE
#define PAVE_NAMESPACE

#include <stdbool.h>
#include <stdint.h>

#include <std/str.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMap_str_Array_Type.h>
#include <std/HashMap_str_Array_ref_Trait.h>
#include <std/HashMap_str_Type.h>
struct Root;
struct Namespace;

#line 6 "src/analyzer/Namespace.pv"
struct Namespace {
    struct Root* root;
    struct Namespace* parent;
    struct str name;
    struct str path;
    struct HashMap_str_ref_Namespace children;
    struct HashMap_str_ref_Module modules;
    struct HashMap_str_Array_Type types;
    struct HashMap_str_Array_ref_Trait traits;
    struct HashMap_str_Type functions;
};

#include <std/str.h>
#include <analyzer/types/Type.h>
struct Root;
struct Namespace;
struct Trait;
struct Module;
struct Type;

#line 19 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__new(struct Root* root, struct Namespace* parent, struct str name, struct str path);

#line 38 "src/analyzer/Namespace.pv"
bool Namespace__add_type(struct Namespace* self, struct str name, struct Type type);

#line 56 "src/analyzer/Namespace.pv"
bool Namespace__add_trait(struct Namespace* self, struct str name, struct Trait* trait_info);

#line 73 "src/analyzer/Namespace.pv"
bool Namespace__parse(struct Namespace* self);

#line 77 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace(struct Namespace* self, struct str name, struct str path);

#line 83 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace_subfolder(struct Namespace* self, struct str name);

#line 91 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__find_namespace(struct Namespace* self, struct str name);

#line 102 "src/analyzer/Namespace.pv"
bool Namespace__add_module(struct Namespace* self, struct str name);

#line 123 "src/analyzer/Namespace.pv"
bool Namespace__add_use_namespaces(struct Namespace* self);

#line 135 "src/analyzer/Namespace.pv"
bool Namespace__fill_namespace(struct Namespace* self);

#line 149 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types(struct Namespace* self);

#line 161 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types_impl(struct Namespace* self);

#line 173 "src/analyzer/Namespace.pv"
bool Namespace__parse_declarations(struct Namespace* self);

#line 185 "src/analyzer/Namespace.pv"
bool Namespace__parse_globals(struct Namespace* self);

#line 197 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions(struct Namespace* self);

#line 209 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions_if_path(struct Namespace* self, struct str path);

#line 221 "src/analyzer/Namespace.pv"
struct Module* Namespace__find_module_by_path(struct Namespace* self, struct str path);

#line 232 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_type(struct Namespace* self, struct str name, uintptr_t arity);

#line 243 "src/analyzer/Namespace.pv"
struct Trait* Namespace__find_trait(struct Namespace* self, struct str name, uintptr_t arity);

#line 255 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_function(struct Namespace* self, struct str name);

#endif
