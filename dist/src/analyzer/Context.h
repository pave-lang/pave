#ifndef PAVE_CONTEXT
#define PAVE_CONTEXT

#include <stdint.h>
#include <stdbool.h>

#include <std/str.h>
#include <analyzer/types/Type.h>
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

#line 11 "src/analyzer/Context.pv"
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
    struct Type type_char;
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
#include <analyzer/TokenBounds.h>
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
struct Expression;
struct Statement;
struct Block;
struct Type;
struct Generics;
struct NamespaceCpp;
struct ClassCpp;
struct GenericMap;
struct Array_Type;

#line 31 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module);

#line 96 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type);

#line 130 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message);

#line 134 "src/analyzer/Context.pv"
void Context__error_token_bounds(struct Context* self, struct TokenBounds bounds, char const* message);

#line 156 "src/analyzer/Context.pv"
void Context__error_expression(struct Context* self, struct Expression* expression, char const* message);

#line 160 "src/analyzer/Context.pv"
void Context__error_statement(struct Context* self, struct Statement* statement, char const* message);

#line 164 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value);

#line 168 "src/analyzer/Context.pv"
void Context__error_token_bounds_value(struct Context* self, struct TokenBounds bounds, char const* message, struct str value);

#line 190 "src/analyzer/Context.pv"
void Context__error_expression_value(struct Context* self, struct Expression* expression, char const* message, struct str value);

#line 194 "src/analyzer/Context.pv"
void Context__error_statement_value(struct Context* self, struct Statement* statement, char const* message, struct str value);

#line 198 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message);

#line 210 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type);

#line 216 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type);

#line 227 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value);

#line 233 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value);

#line 244 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 248 "src/analyzer/Context.pv"
void Context__inlay_hint_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 266 "src/analyzer/Context.pv"
void Context__inlay_hint_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 270 "src/analyzer/Context.pv"
void Context__inlay_hint_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 274 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 278 "src/analyzer/Context.pv"
void Context__inlay_hint_before_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 296 "src/analyzer/Context.pv"
void Context__inlay_hint_before_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 300 "src/analyzer/Context.pv"
void Context__inlay_hint_before_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 304 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self);

#line 314 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self);

#line 322 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self);

#line 330 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type);

#line 338 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value);

#line 348 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value);

#line 354 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type);

#line 370 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value);

#line 386 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol);

#line 394 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self);

#line 400 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close);

#line 429 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block);

#line 434 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self);

#line 438 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics);

#line 632 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics);

#line 662 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics);

#line 691 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics);

#line 725 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics);

#line 736 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map);

#line 917 "src/analyzer/Context.pv"
struct Type* Context__get_path_narrowing(struct Context* self, struct str path);

#line 928 "src/analyzer/Context.pv"
void Context__set_narrowed(struct Context* self, struct str name, struct Type* type);

#line 939 "src/analyzer/Context.pv"
struct Type* Context__get_broadened_type(struct Context* self, struct str name);

#line 948 "src/analyzer/Context.pv"
bool Context__broaden_if_narrowed(struct Context* self, struct str name);

#line 965 "src/analyzer/Context.pv"
bool Context__update_value_type(struct Context* self, struct str name, struct Type* type);

#line 981 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type);

#line 998 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name);

#line 1017 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self);

#line 1033 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self);

#line 1051 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics);

#line 1072 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types);

#endif
