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
struct Token;
struct NamespacePath;
struct Array_Token;
struct Type;
struct Trait;
struct Array_Type;
struct Primitive;

#line 35 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path);

#line 69 "src/analyzer/Module.pv"
bool Module__add_module(struct Module* self, struct Token* name_token, struct str name);

#line 81 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self);

#line 389 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self);

#line 399 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path);

#line 431 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self);

#line 489 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self);

#line 535 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self);

#line 610 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self);

#line 665 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self);

#line 681 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self);

#line 713 "src/analyzer/Module.pv"
bool Module__parse_functions_if_path(struct Module* self, struct str path);

#line 719 "src/analyzer/Module.pv"
uint64_t Module__compute_declaration_fingerprint(struct Array_Token* tokens);

#line 772 "src/analyzer/Module.pv"
uint64_t Module__declaration_fingerprint(struct Module* self);

#line 779 "src/analyzer/Module.pv"
void Module__retokenize_for_bodies(struct Module* self);

#line 934 "src/analyzer/Module.pv"
void Module__update_function_tokens(struct Module* self, struct str name, uintptr_t token_start, uintptr_t token_end);

#line 954 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name, uintptr_t arity);

#line 977 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name, uintptr_t arity);

#line 989 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name);

#line 1004 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name);

#line 1023 "src/analyzer/Module.pv"
int64_t* Module__find_macro_value(struct Module* self, struct str name);

#line 1031 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types);

#line 1037 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name);

#endif
