#ifndef PAVE_MODULE
#define PAVE_MODULE

#include <stdbool.h>

#include <stdio.h>

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
};

#include <std/str.h>
struct Namespace;
struct Module;
struct NamespacePath;
struct Type;
struct Trait;
struct Array_Type;
struct Primitive;

#line 27 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path);

#line 53 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self);

#line 198 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self);

#line 208 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path);

#line 240 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self);

#line 268 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self);

#line 309 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self);

#line 360 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self);

#line 402 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self);

#line 425 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name);

#line 448 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name);

#line 463 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name);

#line 478 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name);

#line 487 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types);

#line 492 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name);

#endif
