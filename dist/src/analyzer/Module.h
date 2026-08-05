#ifndef PAVE_MODULE
#define PAVE_MODULE

#include <stdbool.h>
#include <stdint.h>

#include <std/str.h>
#include <std/Array_NamespacePath.h>
#include <std/Array_ref_Namespace.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_Array_ref_Enum.h>
#include <std/HashMap_str_Array_ref_Struct.h>
#include <std/HashMap_str_Array_ref_Trait.h>
#include <std/Array_Impl.h>
#include <std/HashMap_str_Function.h>
#include <std/Array_TypeImpl.h>
#include <analyzer/Context.h>
#include <std/Array_Token.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMap_str_ref_Global.h>
#include <std/Array_TestInfo.h>
struct Root;
struct Namespace;

#line 12 "src/analyzer/Module.pv"
struct Module {
    struct Root* root;
    struct Namespace* namespace;
    struct str path;
    struct Array_NamespacePath use_namespaces;
    struct Array_ref_Namespace used_namespaces;
    struct HashMap_str_Type types;
    struct HashMap_str_Array_ref_Enum enums;
    struct HashMap_str_Array_ref_Struct structs;
    struct HashMap_str_Array_ref_Trait traits;
    struct Array_Impl impls;
    struct HashMap_str_Function functions;
    struct Array_TypeImpl type_impls;
    struct Context context;
    struct Array_Token tokens;
    bool mode_cpp;
    struct HashMap_str_ref_Include includes;
    struct HashMap_str_ref_Global globals;
    struct HashMap_str_Type global_types;
    struct Array_TestInfo tests;
};

#include <std/str.h>
struct Namespace;
struct NamespacePath;
struct Array_Token;
struct Type;
struct Trait;
struct Array_Type;
struct Primitive;

#line 35 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path);

#line 67 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self);

#line 361 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self);

#line 371 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path);

#line 403 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self);

#line 461 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self);

#line 507 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self);

#line 575 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self);

#line 627 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self);

#line 643 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self);

#line 672 "src/analyzer/Module.pv"
bool Module__parse_functions_if_path(struct Module* self, struct str path);

#line 678 "src/analyzer/Module.pv"
uint64_t Module__compute_declaration_fingerprint(struct Array_Token* tokens);

#line 731 "src/analyzer/Module.pv"
uint64_t Module__declaration_fingerprint(struct Module* self);

#line 738 "src/analyzer/Module.pv"
void Module__retokenize_for_bodies(struct Module* self);

#line 893 "src/analyzer/Module.pv"
void Module__update_function_tokens(struct Module* self, struct str name, uintptr_t token_start, uintptr_t token_end);

#line 913 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name, uintptr_t arity);

#line 936 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name, uintptr_t arity);

#line 951 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name);

#line 966 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name);

#line 985 "src/analyzer/Module.pv"
int64_t* Module__find_macro_value(struct Module* self, struct str name);

#line 993 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types);

#line 999 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name);

#endif
