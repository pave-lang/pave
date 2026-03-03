#ifndef PAVE_MODULE
#define PAVE_MODULE

#include <std/str.h>
#include <std/Array_NamespacePath.h>
#include <analyzer/NamespacePath.h>
#include <std/Array_ref_Namespace.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/HashMap_str_Enum.h>
#include <analyzer/Enum.h>
#include <std/HashMap_str_Struct.h>
#include <analyzer/Struct.h>
#include <std/HashMap_str_Trait.h>
#include <analyzer/Trait.h>
#include <std/Array_Impl.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/Function.h>
#include <std/Array_TypeImpl.h>
#include <analyzer/TypeImpl.h>
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

#line 5 "src/analyzer/Module.pv"
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

#line 25 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path);

#line 51 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self);

#line 195 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self);

#line 205 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path);

#line 237 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self);

#line 266 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self);

#line 311 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self);

#line 421 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self);

#line 458 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name);

#line 481 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name);

#line 496 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name);

#line 511 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name);

#line 520 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types);

#line 525 "src/analyzer/Module.pv"
struct Type* Module__make_type_usage(struct Module* self, struct Type* type, struct Array_Type* usage_types);

#line 562 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, char const* name);

#endif
