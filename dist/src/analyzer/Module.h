#ifndef PAVE_MODULE
#define PAVE_MODULE

#include <stdbool.h>

#include <std/str.h>
#include <std/Array_NamespacePath.h>
#include <std/Array_ref_Namespace.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_Enum.h>
#include <std/HashMap_str_Struct.h>
#include <std/HashMap_str_Trait.h>
#include <std/Array_Impl.h>
#include <std/HashMap_str_Function.h>
#include <std/Array_TypeImpl.h>
#include <analyzer/Context.h>
#include <std/Array_Token.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMap_str_ref_Global.h>
struct Root;
struct Namespace;

#line 7 "src/analyzer/Module.pv"
struct Module {
    struct Root* root;
    struct Namespace* namespace;
    struct str path;
    struct Array_NamespacePath use_namespaces;
    struct Array_ref_Namespace used_namespaces;
    struct HashMap_str_Type types;
    struct HashMap_str_Enum enums;
    struct HashMap_str_Struct structs;
    struct HashMap_str_Trait traits;
    struct Array_Impl impls;
    struct HashMap_str_Function functions;
    struct Array_TypeImpl type_impls;
    struct Context context;
    struct Array_Token tokens;
    bool mode_cpp;
    struct HashMap_str_ref_Include includes;
    struct HashMap_str_ref_Global globals;
    struct HashMap_str_Type global_types;
};

#include <std/str.h>
struct Namespace;
struct Module;
struct NamespacePath;
struct Type;
struct Trait;
struct Array_Type;
struct Primitive;

#line 29 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path);

#line 57 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self);

#line 225 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self);

#line 235 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path);

#line 267 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self);

#line 300 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self);

#line 341 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self);

#line 392 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self);

#line 438 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self);

#line 454 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self);

#line 481 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name);

#line 504 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name);

#line 519 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name);

#line 534 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name);

#line 553 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types);

#line 558 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name);

#endif
