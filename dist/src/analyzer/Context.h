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

#line 30 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module);

#line 95 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type);

#line 126 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message);

#line 147 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value);

#line 168 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message);

#line 180 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type);

#line 186 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type);

#line 197 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value);

#line 203 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value);

#line 214 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 231 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right);

#line 248 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self);

#line 258 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self);

#line 266 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self);

#line 274 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type);

#line 282 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value);

#line 292 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value);

#line 298 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type);

#line 314 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value);

#line 330 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol);

#line 338 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self);

#line 344 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close);

#line 373 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block);

#line 378 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self);

#line 382 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics);

#line 585 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics);

#line 615 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics);

#line 644 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics);

#line 678 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics);

#line 689 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map);

#line 835 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type);

#line 852 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name);

#line 869 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self);

#line 885 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self);

#line 903 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics);

#line 924 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types);

#endif
