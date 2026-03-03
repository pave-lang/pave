#ifndef PAVE_NAMESPACE
#define PAVE_NAMESPACE

#include <std/str.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/HashMap_str_ref_Trait.h>
#include <stdbool.h>

struct Root;
struct Namespace;
struct Module;
struct Trait;
struct str;
struct Type;

#include <fs.h>

#line 5 "src/analyzer/Namespace.pv"
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

#line 18 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__new(struct Root* root, struct Namespace* parent, struct str name, struct str path);

#line 37 "src/analyzer/Namespace.pv"
bool Namespace__parse(struct Namespace* self);

#line 41 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace(struct Namespace* self, struct str name, struct str path);

#line 47 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace_subfolder(struct Namespace* self, struct str name);

#line 55 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__find_namespace(struct Namespace* self, struct str name);

#line 66 "src/analyzer/Namespace.pv"
bool Namespace__add_module(struct Namespace* self, struct str name);

#line 87 "src/analyzer/Namespace.pv"
bool Namespace__add_use_namespaces(struct Namespace* self);

#line 99 "src/analyzer/Namespace.pv"
bool Namespace__fill_namespace(struct Namespace* self);

#line 113 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types(struct Namespace* self);

#line 125 "src/analyzer/Namespace.pv"
bool Namespace__parse_declarations(struct Namespace* self);

#line 137 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions(struct Namespace* self);

#line 149 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_type(struct Namespace* self, struct str name);

#line 153 "src/analyzer/Namespace.pv"
struct Trait* Namespace__find_trait(struct Namespace* self, struct str name);

#line 159 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_function(struct Namespace* self, struct str name);

#endif
