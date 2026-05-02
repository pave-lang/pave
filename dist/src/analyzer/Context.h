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

#line 86 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type);

#line 116 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message);

#line 136 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value);

#line 157 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message);

#line 169 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type);

#line 175 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type);

#line 186 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value);

#line 192 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value);

#line 203 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 220 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self);

#line 230 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self);

#line 238 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self);

#line 246 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type);

#line 254 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value);

#line 264 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value);

#line 270 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type);

#line 286 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value);

#line 302 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol);

#line 310 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self);

#line 316 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close);

#line 345 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block);

#line 350 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self);

#line 354 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics);

#line 535 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics);

#line 565 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics);

#line 594 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics);

#line 628 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics);

#line 639 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map);

#line 758 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type);

#line 775 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name);

#line 792 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self);

#line 808 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self);

#line 826 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics);

#line 847 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types);

#endif
