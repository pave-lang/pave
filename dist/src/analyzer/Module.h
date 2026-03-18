#ifndef PAVE_MODULE
#define PAVE_MODULE

#include <std/str.h>
#include <std/Array_NamespacePath.h>
#include <analyzer/NamespacePath.h>
#include <std/Array_ref_Namespace.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/Type.h>
#include <std/HashMap_str_Enum.h>
#include <analyzer/types/Enum.h>
#include <std/HashMap_str_Struct.h>
#include <analyzer/types/Struct.h>
#include <std/HashMap_str_Trait.h>
#include <analyzer/types/Trait.h>
#include <std/Array_Impl.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/types/Function.h>
#include <std/Array_TypeImpl.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/Context.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <stdbool.h>
#include <std/HashMap_str_ref_Include.h>

struct Root;
struct Namespace;
struct Include;
struct str;
struct NamespacePath;
struct Type;
struct Trait;
struct Array_Type;
struct Primitive;

#include <stdio.h>

#line 6 "src/analyzer/Module.pv"
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

#line 26 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path);

#line 52 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self);

#line 197 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self);

#line 207 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path);

#line 239 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self);

#line 267 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self);

#line 312 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self);

#line 436 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self);

#line 473 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name);

#line 496 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name);

#line 511 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name);

#line 526 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name);

#line 535 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types);

#line 540 "src/analyzer/Module.pv"
struct Type* Module__make_type_usage(struct Module* self, struct Type* type, struct Array_Type* usage_types);

#line 577 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, char const* name);

#endif
