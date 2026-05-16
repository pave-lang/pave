#ifndef PAVE_CONTEXT
#define PAVE_CONTEXT

#include <stdint.h>
#include <stdbool.h>

#include <std/str.h>
#include <analyzer/types/Indirect.h>
#include <std/HashMap_str_Type.h>
#include <std/Array_Scope.h>
struct ArenaAllocator;
struct Token;
struct Analysis;
struct Type;
struct Module;
struct Root;
struct Function;

#line 10 "src/analyzer/Context.pv"
struct Context {
    struct ArenaAllocator* allocator;
    struct str base_path;
    struct str path;
    uintptr_t pos;
    struct Token* tokens;
    uintptr_t length;
    uintptr_t offset;
    struct Analysis* analysis;
    struct Type* type_self;
    struct Indirect pointer_const_char;
    struct HashMap_str_Type types;
    struct Array_Scope scopes;
    struct Module* module;
    struct Root* root;
    struct Function* function;
};

#include <std/str.h>
#include <analyzer/Context.h>
#include <analyzer/types/Type.h>
#include <analyzer/TokenType.h>
#include <analyzer/InlayHintKind.h>
#include <std/Array_DeferStatement.h>
#include <std/Array_Type.h>
struct ArenaAllocator;
struct Array_Token;
struct Analysis;
struct Module;
struct Context;
struct Array_Generic;
struct Array_Parameter;
struct Token;
struct Block;
struct Type;
struct Generics;
struct NamespaceCpp;
struct ClassCpp;
struct GenericMap;
struct Array_Type;

#line 29 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module);

#line 93 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type);

#line 124 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message);

#line 145 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value);

#line 166 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message);

#line 178 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type);

#line 184 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type);

#line 195 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value);

#line 201 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value);

#line 212 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 229 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 246 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self);

#line 256 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self);

#line 264 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self);

#line 272 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type);

#line 280 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value);

#line 290 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value);

#line 296 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type);

#line 312 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value);

#line 328 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol);

#line 336 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self);

#line 342 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close);

#line 371 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block);

#line 376 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self);

#line 380 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics);

#line 583 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics);

#line 613 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics);

#line 642 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics);

#line 676 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics);

#line 687 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map);

#line 833 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type);

#line 850 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name);

#line 867 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self);

#line 883 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self);

#line 901 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics);

#line 922 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types);

#endif
