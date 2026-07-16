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
#include <std/Array_Position.h>
#include <std/Array_str.h>
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

#line 95 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type);

#line 129 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message);

#line 133 "src/analyzer/Context.pv"
void Context__error_token_bounds(struct Context* self, struct TokenBounds bounds, char const* message);

#line 155 "src/analyzer/Context.pv"
void Context__error_expression(struct Context* self, struct Expression* expression, char const* message);

#line 159 "src/analyzer/Context.pv"
void Context__error_statement(struct Context* self, struct Statement* statement, char const* message);

#line 163 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value);

#line 167 "src/analyzer/Context.pv"
void Context__error_token_bounds_value(struct Context* self, struct TokenBounds bounds, char const* message, struct str value);

#line 189 "src/analyzer/Context.pv"
void Context__error_expression_value(struct Context* self, struct Expression* expression, char const* message, struct str value);

#line 193 "src/analyzer/Context.pv"
void Context__error_statement_value(struct Context* self, struct Statement* statement, char const* message, struct str value);

#line 197 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message);

#line 209 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type);

#line 215 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type);

#line 226 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value);

#line 232 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value);

#line 243 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 247 "src/analyzer/Context.pv"
void Context__inlay_hint_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 265 "src/analyzer/Context.pv"
void Context__inlay_hint_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 269 "src/analyzer/Context.pv"
void Context__inlay_hint_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 273 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 277 "src/analyzer/Context.pv"
void Context__inlay_hint_before_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 295 "src/analyzer/Context.pv"
void Context__inlay_hint_before_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 299 "src/analyzer/Context.pv"
void Context__inlay_hint_before_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 303 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self);

#line 313 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self);

#line 321 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self);

#line 329 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type);

#line 337 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value);

#line 347 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value);

#line 353 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type);

#line 369 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value);

#line 385 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol);

#line 393 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self);

#line 399 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close);

#line 428 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block);

#line 433 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self);

#line 437 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics);

#line 644 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics);

#line 674 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics);

#line 703 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics);

#line 737 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics);

#line 748 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map);

#line 929 "src/analyzer/Context.pv"
struct Type* Context__get_path_narrowing(struct Context* self, struct str path);

#line 940 "src/analyzer/Context.pv"
void Context__set_narrowed(struct Context* self, struct str name, struct Type* type);

#line 951 "src/analyzer/Context.pv"
struct Type* Context__get_broadened_type(struct Context* self, struct str name);

#line 960 "src/analyzer/Context.pv"
bool Context__broaden_if_narrowed(struct Context* self, struct str name);

#line 977 "src/analyzer/Context.pv"
bool Context__update_value_type(struct Context* self, struct str name, struct Type* type);

#line 993 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type);

#line 1012 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name);

#line 1031 "src/analyzer/Context.pv"
struct Token* Context__get_definition_token(struct Context* self, struct str name);

#line 1046 "src/analyzer/Context.pv"
bool Context__should_record_symbols(struct Context* self);

#line 1050 "src/analyzer/Context.pv"
void Context__record_symbol(struct Context* self, struct Token* token, struct str type_label, struct str def_path, struct Token* def_token);

#line 1074 "src/analyzer/Context.pv"
void Context__record_signature(struct Context* self, struct Token* open_paren, struct Token* close_paren, struct Array_Position comma_positions, struct str label, struct Array_str parameters);

#line 1091 "src/analyzer/Context.pv"
void Context__record_completion(struct Context* self, struct Token* name, struct Type* type, uintptr_t kind);

#line 1119 "src/analyzer/Context.pv"
void Context__record_member_completion(struct Context* self, struct Token* dot, struct Type* receiver_type, bool is_static);

#line 1154 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics);

#line 1175 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types);

#endif
