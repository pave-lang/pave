#ifndef PAVE_NAMESPACE
#define PAVE_NAMESPACE

#include <stdbool.h>

#include <std/str.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_ref_Trait.h>
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
    struct HashMap_str_Type types;
    struct HashMap_str_ref_Trait traits;
    struct HashMap_str_Type functions;
};

#include <std/str.h>
struct Root;
struct Namespace;
struct Type;
struct Trait;

#line 19 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__new(struct Root* root, struct Namespace* parent, struct str name, struct str path);

#line 38 "src/analyzer/Namespace.pv"
bool Namespace__parse(struct Namespace* self);

#line 42 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace(struct Namespace* self, struct str name, struct str path);

#line 48 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace_subfolder(struct Namespace* self, struct str name);

#line 56 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__find_namespace(struct Namespace* self, struct str name);

#line 67 "src/analyzer/Namespace.pv"
bool Namespace__add_module(struct Namespace* self, struct str name);

#line 88 "src/analyzer/Namespace.pv"
bool Namespace__add_use_namespaces(struct Namespace* self);

#line 100 "src/analyzer/Namespace.pv"
bool Namespace__fill_namespace(struct Namespace* self);

#line 114 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types(struct Namespace* self);

#line 126 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types_impl(struct Namespace* self);

#line 138 "src/analyzer/Namespace.pv"
bool Namespace__parse_declarations(struct Namespace* self);

#line 150 "src/analyzer/Namespace.pv"
bool Namespace__parse_consts(struct Namespace* self);

#line 162 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions(struct Namespace* self);

#line 174 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_type(struct Namespace* self, struct str name);

#line 178 "src/analyzer/Namespace.pv"
struct Trait* Namespace__find_trait(struct Namespace* self, struct str name);

#line 184 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_function(struct Namespace* self, struct str name);

#endif
