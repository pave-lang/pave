#ifndef PAVE_CONTEXT
#define PAVE_CONTEXT

#include <std/str.h>
#include <stdint.h>
#include <analyzer/Indirect.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/Array_Scope.h>
#include <analyzer/Scope.h>
#include <stdbool.h>

struct ArenaAllocator;
struct Token;
struct Analysis;
struct Type;
struct Module;
struct Root;
struct Function;
struct Context;
struct str;
struct Array_Token;
struct Array_Generic;
struct Generic;
struct Array_Parameter;
struct Parameter;
#include <analyzer/TokenType.h>
#include <analyzer/InlayHintKind.h>
struct Block;
struct Generics;
struct NamespaceCpp;
struct GenericMap;
struct Array_DeferStatement;
struct DeferStatement;
struct Array_Type;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#line 21 "src/analyzer/Context.pv"
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

#line 40 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module);

#line 92 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type);

#line 122 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message);

#line 142 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value);

#line 163 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message);

#line 175 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type);

#line 181 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type);

#line 192 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value);

#line 198 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value);

#line 209 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 226 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self);

#line 236 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self);

#line 244 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self);

#line 252 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type);

#line 260 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value);

#line 270 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value);

#line 276 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type);

#line 292 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value);

#line 308 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol);

#line 316 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self);

#line 322 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close);

#line 351 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block);

#line 356 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self);

#line 360 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics);

#line 528 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics);

#line 555 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics);

#line 589 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics);

#line 600 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map);

#line 719 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type);

#line 736 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name);

#line 753 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self);

#line 769 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self);

#line 787 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics);

#endif
