#include <string.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/Module.h>
#include <analyzer/Context.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Analysis.h>
#include <std/trait_Allocator.h>
#include <analyzer/Root.h>
#include <analyzer/types/IndirectType.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Generic.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/HashMap_str_bool.h>
#include <analyzer/Scope.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionType.h>
#include <std/Iter_ref_Generic.h>
#include <analyzer/types/Generics.h>
#include <std/HashMap_str_usize.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/TokenBounds.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>
#include <analyzer/Position.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/InlayHintKind.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>
#include <usize.h>
#include <analyzer/Block.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Tuple.h>
#include <std/Array_Type.h>
#include <std/Iter_ref_Type.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/GenericTypedef.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Enum.h>
#include <analyzer/c/ClassCpp.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/Iter_ref_Scope.h>
#include <std/String.h>
#include <std/HashMap_str_ref_Token.h>
#include <std/HashMap_str_Array_SymbolInfo.h>
#include <std/Array_SymbolInfo.h>
#include <analyzer/SymbolInfo.h>
#include <std/HashMap_str_Array_SignatureInfo.h>
#include <std/Array_SignatureInfo.h>
#include <analyzer/SignatureInfo.h>
#include <std/Array_Position.h>
#include <std/Array_str.h>
#include <std/HashMap_str_Array_CompletionInfo.h>
#include <std/Array_CompletionInfo.h>
#include <analyzer/Naming.h>
#include <analyzer/CompletionInfo.h>
#include <std/HashMap_str_Array_MemberCompletionInfo.h>
#include <std/Array_MemberCompletionInfo.h>
#include <analyzer/MemberCompletionInfo.h>
#include <analyzer/Context.h>

#include <analyzer/Context.h>

#line 31 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module) {
    #line 32 "src/analyzer/Context.pv"
    struct Type type_char = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(module, (struct str){ .ptr = "char", .length = strlen("char") }) };
    #line 33 "src/analyzer/Context.pv"
    struct Context self = (struct Context) {
        .allocator = allocator,
        .base_path = base_path,
        .path = path,
        .analysis = analysis,
        .module = module,
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .scopes = Array_Scope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .root = module->root,
        .pos = 0,
        .tokens = 0,
        .length = 0,
        .offset = 0,
        .type_self = 0,
        .type_char = type_char,
        .pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = type_char },
        .function = 0,
    };

    #line 52 "src/analyzer/Context.pv"
    if (tokens != 0) {
        #line 53 "src/analyzer/Context.pv"
        self.tokens = tokens->data;
        #line 54 "src/analyzer/Context.pv"
        self.length = tokens->length;
    }

    #line 57 "src/analyzer/Context.pv"
    self.type_self = &self.root->type_self;

    #line 59 "src/analyzer/Context.pv"
    struct Token* param_name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "value", .length = strlen("value") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 61 "src/analyzer/Context.pv"
    Context__push_scope(&self, 0);

    #line 63 "src/analyzer/Context.pv"
    struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 64 "src/analyzer/Context.pv"
    t.name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 66 "src/analyzer/Context.pv"
    struct Generic u = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 67 "src/analyzer/Context.pv"
    u.name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "U", .length = strlen("U") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 69 "src/analyzer/Context.pv"
    struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 70 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, t);
    #line 71 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, u);
    #line 72 "src/analyzer/Context.pv"
    struct Generic* generic_t = Array_Generic__get(&generics, 0);
    #line 73 "src/analyzer/Context.pv"
    struct Generic* generic_u = Array_Generic__get(&generics, 1);

    #line 75 "src/analyzer/Context.pv"
    struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 76 "src/analyzer/Context.pv"
    Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_u } });

    #line 78 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "cast", &generics, &params, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t });

    #line 80 "src/analyzer/Context.pv"
    struct Array_Generic generics2 = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 81 "src/analyzer/Context.pv"
    Array_Generic__append(&generics2, t);
    #line 82 "src/analyzer/Context.pv"
    struct Generic* generic2_t = Array_Generic__get(&generics2, 0);

    #line 84 "src/analyzer/Context.pv"
    struct Array_Parameter params2 = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 85 "src/analyzer/Context.pv"
    Array_Parameter__append(&params2, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic2_t } });
    #line 86 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "sizeof", &generics2, &params2, self.root->type_usize);
    #line 87 "src/analyzer/Context.pv"
    struct Indirect* typename_return_indirect = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = type_char }});
    #line 88 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "typename", &generics2, &params2, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = typename_return_indirect });

    #line 90 "src/analyzer/Context.pv"
    HashMap_str_bool__insert(&analysis->files, path, true);

    #line 92 "src/analyzer/Context.pv"
    return self;
}

#line 95 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type) {
    #line 96 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 97 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 97 "src/analyzer/Context.pv"
        return false;
    }
    #line 98 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 100 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 100 "src/analyzer/Context.pv"
        return true;
    }

    #line 102 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 103 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});
    #line 104 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 105 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 107 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 108 "src/analyzer/Context.pv"
        { struct Iter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 108 "src/analyzer/Context.pv"
        while (Iter_ref_Generic__next(&__iter)) {
            #line 108 "src/analyzer/Context.pv"
            struct Generic generic = *Iter_ref_Generic__value(&__iter);

            #line 109 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 110 "src/analyzer/Context.pv"
            struct Token* generic_name = generic.name;
            #line 111 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 111 "src/analyzer/Context.pv"
                return false;
            }
            #line 112 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic_name->value, index);
        } }
    }

    #line 116 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 117 "src/analyzer/Context.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 117 "src/analyzer/Context.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 117 "src/analyzer/Context.pv"
            struct Parameter param = *Iter_ref_Parameter__value(&__iter);

            #line 118 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 122 "src/analyzer/Context.pv"
    struct GenericMap generic_map_val = GenericMap__from_generics(self->allocator, &func_info.generics);
    #line 123 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);

    #line 125 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, &func_info), ._1 = generic_map} };
    #line 126 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 129 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 130 "src/analyzer/Context.pv"
    Context__error_token_bounds(self, TokenBounds__new(token, token), message);
}

#line 133 "src/analyzer/Context.pv"
void Context__error_token_bounds(struct Context* self, struct TokenBounds bounds, char const* message) {
    #line 134 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 135 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 136 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 136 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 137 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 137 "src/analyzer/Context.pv"
        return;
    }

    #line 139 "src/analyzer/Context.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
        .code = (struct str) { .ptr = 0, .length = 0 },
        .range = (struct Range) {
            .start = (struct Position) {
                .line = bounds.first->start_line,
                .character = bounds.first->start_column,
            },
            .end = (struct Position) {
                .line = bounds.last->end_line,
                .character = bounds.last->end_column,
            },
        },
    });
}

#line 155 "src/analyzer/Context.pv"
void Context__error_expression(struct Context* self, struct Expression* expression, char const* message) {
    #line 156 "src/analyzer/Context.pv"
    Context__error_token_bounds(self, Expression__get_token_bounds(expression), message);
}

#line 159 "src/analyzer/Context.pv"
void Context__error_statement(struct Context* self, struct Statement* statement, char const* message) {
    #line 160 "src/analyzer/Context.pv"
    Context__error_token_bounds(self, Statement__get_token_bounds(statement), message);
}

#line 163 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 164 "src/analyzer/Context.pv"
    Context__error_token_bounds_value(self, TokenBounds__new(token, token), message, value);
}

#line 167 "src/analyzer/Context.pv"
void Context__error_token_bounds_value(struct Context* self, struct TokenBounds bounds, char const* message, struct str value) {
    #line 168 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 169 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 170 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 170 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 171 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 171 "src/analyzer/Context.pv"
        return;
    }

    #line 173 "src/analyzer/Context.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
        .code = value,
        .range = (struct Range) {
            .start = (struct Position) {
                .line = bounds.first->start_line,
                .character = bounds.first->start_column,
            },
            .end = (struct Position) {
                .line = bounds.last->end_line,
                .character = bounds.last->end_column,
            },
        },
    });
}

#line 189 "src/analyzer/Context.pv"
void Context__error_expression_value(struct Context* self, struct Expression* expression, char const* message, struct str value) {
    #line 190 "src/analyzer/Context.pv"
    Context__error_token_bounds_value(self, Expression__get_token_bounds(expression), message, value);
}

#line 193 "src/analyzer/Context.pv"
void Context__error_statement_value(struct Context* self, struct Statement* statement, char const* message, struct str value) {
    #line 194 "src/analyzer/Context.pv"
    Context__error_token_bounds_value(self, Statement__get_token_bounds(statement), message, value);
}

#line 197 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 198 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 200 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 201 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 204 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 206 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 209 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 210 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 211 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 212 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 215 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 216 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 218 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 219 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 222 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 223 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 226 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 227 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 228 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 229 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 232 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 233 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 235 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 236 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 239 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 240 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 243 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 244 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, TokenBounds__new(token, token), label, kind, padding_left, padding_right);
}

#line 247 "src/analyzer/Context.pv"
void Context__inlay_hint_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 248 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 249 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 250 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 250 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 251 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 251 "src/analyzer/Context.pv"
        return;
    }

    #line 253 "src/analyzer/Context.pv"
    Array_InlayHint__append(file_inlay_hints, (struct InlayHint) {
        .position = (struct Position) {
            .line = bounds.last->end_line,
            .character = bounds.last->end_column,
        },
        .label = (struct str){ .ptr = label, .length = strlen(label) },
        .kind = kind,
        .padding_left = padding_left,
        .padding_right = padding_right,
    });
}

#line 265 "src/analyzer/Context.pv"
void Context__inlay_hint_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 266 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, Expression__get_token_bounds(expression), label, kind, padding_left, padding_right);
}

#line 269 "src/analyzer/Context.pv"
void Context__inlay_hint_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 270 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, Statement__get_token_bounds(statement), label, kind, padding_left, padding_right);
}

#line 273 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 274 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, TokenBounds__new(token, token), label, kind, padding_left, padding_right);
}

#line 277 "src/analyzer/Context.pv"
void Context__inlay_hint_before_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 278 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 279 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 280 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 280 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 281 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 281 "src/analyzer/Context.pv"
        return;
    }

    #line 283 "src/analyzer/Context.pv"
    Array_InlayHint__append(file_inlay_hints, (struct InlayHint) {
        .position = (struct Position) {
            .line = bounds.first->start_line,
            .character = bounds.first->start_column,
        },
        .label = (struct str){ .ptr = label, .length = strlen(label) },
        .kind = kind,
        .padding_left = padding_left,
        .padding_right = padding_right,
    });
}

#line 295 "src/analyzer/Context.pv"
void Context__inlay_hint_before_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 296 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, Expression__get_token_bounds(expression), label, kind, padding_left, padding_right);
}

#line 299 "src/analyzer/Context.pv"
void Context__inlay_hint_before_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 300 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, Statement__get_token_bounds(statement), label, kind, padding_left, padding_right);
}

#line 303 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 304 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 306 "src/analyzer/Context.pv"
    while (self->pos < self->length && self->tokens[self->pos].type == TOKEN_TYPE__COMMENT) {
        #line 307 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 310 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 313 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 314 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 315 "src/analyzer/Context.pv"
        return 0;
    }

    #line 318 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 321 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 322 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->pos, 0)) {
        #line 323 "src/analyzer/Context.pv"
        return 0;
    }

    #line 326 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 329 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 330 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 331 "src/analyzer/Context.pv"
        return false;
    }

    #line 334 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 337 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 338 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 339 "src/analyzer/Context.pv"
        return false;
    }

    #line 342 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 344 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 347 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 348 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 349 "src/analyzer/Context.pv"
    if (check) {
        #line 349 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 350 "src/analyzer/Context.pv"
    return check;
}

#line 353 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 354 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 355 "src/analyzer/Context.pv"
        return 0;
    }

    #line 358 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 360 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 361 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 362 "src/analyzer/Context.pv"
        return token;
    }

    #line 365 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 366 "src/analyzer/Context.pv"
    return 0;
}

#line 369 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 370 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 371 "src/analyzer/Context.pv"
        return false;
    }

    #line 374 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 376 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 377 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 378 "src/analyzer/Context.pv"
        return true;
    }

    #line 381 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 382 "src/analyzer/Context.pv"
    return false;
}

#line 385 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 386 "src/analyzer/Context.pv"
    while (self->pos < self->length && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 387 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 390 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 393 "src/analyzer/Context.pv"
bool Context__skip_to_statement_end(struct Context* self) {
    #line 394 "src/analyzer/Context.pv"
    uintptr_t square_depth = 0;
    #line 395 "src/analyzer/Context.pv"
    uintptr_t paren_depth = 0;
    #line 396 "src/analyzer/Context.pv"
    uintptr_t brace_depth = 0;

    #line 398 "src/analyzer/Context.pv"
    while (self->pos < self->length) {
        #line 399 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "[")) {
            #line 400 "src/analyzer/Context.pv"
            square_depth += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 402 "src/analyzer/Context.pv"
            if (square_depth > 0) {
                #line 402 "src/analyzer/Context.pv"
                square_depth -= 1;
            }
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "(")) {
            #line 404 "src/analyzer/Context.pv"
            paren_depth += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 406 "src/analyzer/Context.pv"
            if (paren_depth > 0) {
                #line 406 "src/analyzer/Context.pv"
                paren_depth -= 1;
            }
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "{")) {
            #line 408 "src/analyzer/Context.pv"
            brace_depth += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "}")) {
            #line 410 "src/analyzer/Context.pv"
            if (brace_depth > 0) {
                #line 410 "src/analyzer/Context.pv"
                brace_depth -= 1;
            }
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, ";") && usize__Eq_usize__eq(square_depth, 0) && usize__Eq_usize__eq(paren_depth, 0) && usize__Eq_usize__eq(brace_depth, 0)) {
            #line 412 "src/analyzer/Context.pv"
            return true;
        }

        #line 415 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 418 "src/analyzer/Context.pv"
    return false;
}

#line 421 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 422 "src/analyzer/Context.pv"
    while (self->pos < self->length && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 423 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 427 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 428 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 430 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 430 "src/analyzer/Context.pv"
        return false;
    }

    #line 432 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 434 "src/analyzer/Context.pv"
    while (self->pos < self->length && brackets > 0) {
        #line 435 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 436 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 438 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 441 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 442 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 446 "src/analyzer/Context.pv"
    Context__next_token(self);

    #line 448 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 449 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 450 "src/analyzer/Context.pv"
        return false;
    }

    #line 453 "src/analyzer/Context.pv"
    return true;
}

#line 456 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 457 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 458 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 461 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 462 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 465 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 466 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 467 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 468 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 468 "src/analyzer/Context.pv"
            return false;
        }

        #line 470 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 471 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 473 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 474 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 476 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 477 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 479 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 480 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 480 "src/analyzer/Context.pv"
                return false;
            }
            #line 481 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 482 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 484 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 484 "src/analyzer/Context.pv"
                return false;
            }
            #line 485 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 486 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 489 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 491 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn")) {
            #line 492 "src/analyzer/Context.pv"
            struct Type target_type;
            #line 493 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 493 "src/analyzer/Context.pv"
                return false;
            }
            #line 494 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 495 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
            #line 496 "src/analyzer/Context.pv"
            return true;
        }

        #line 499 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 500 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 500 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 502 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = indirect_type, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
        #line 503 "src/analyzer/Context.pv"
        if (indirect == 0) {
            #line 503 "src/analyzer/Context.pv"
            return false;
        }

        #line 505 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 506 "src/analyzer/Context.pv"
            return false;
        }

        #line 509 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 510 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 512 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 514 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 514 "src/analyzer/Context.pv"
            return false;
        }
        #line 515 "src/analyzer/Context.pv"
        sequence->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = sequence->element }}) };

        #line 517 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 518 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 519 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 521 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 521 "src/analyzer/Context.pv"
                return false;
            }

            #line 523 "src/analyzer/Context.pv"
            return true;
        }

        #line 526 "src/analyzer/Context.pv"
        struct Token* length_token = Context__current(self);
        #line 527 "src/analyzer/Context.pv"
        struct Expression* length_expr = Expression__parse(self, generics);
        #line 528 "src/analyzer/Context.pv"
        if (length_expr == 0) {
            #line 528 "src/analyzer/Context.pv"
            return false;
        }

        #line 530 "src/analyzer/Context.pv"
        if (!Expression__is_const_expression(length_expr, self)) {
            #line 531 "src/analyzer/Context.pv"
            Context__error_token(self, length_token, "Fixed array length must be a compile-time constant integer expression");
            #line 532 "src/analyzer/Context.pv"
            return false;
        }

        #line 535 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = length_expr };
        #line 536 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 538 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 538 "src/analyzer/Context.pv"
            return false;
        }

        #line 540 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 542 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 543 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 545 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 546 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 548 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 548 "src/analyzer/Context.pv"
                return false;
            }

            #line 550 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 552 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 553 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 554 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 558 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 559 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 561 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 562 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 563 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
        #line 564 "src/analyzer/Context.pv"
        if (func_info == 0) {
            #line 564 "src/analyzer/Context.pv"
            return false;
        }
        #line 565 "src/analyzer/Context.pv"
        if (generic_map == 0) {
            #line 565 "src/analyzer/Context.pv"
            return false;
        }

        #line 567 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 567 "src/analyzer/Context.pv"
            return false;
        }

        #line 569 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 571 "src/analyzer/Context.pv"
        return true;
    }

    #line 574 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 575 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 575 "src/analyzer/Context.pv"
        return false;
    }

    #line 577 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 578 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 579 "src/analyzer/Context.pv"
        return true;
    }

    #line 582 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 584 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 585 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 586 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 588 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 589 "src/analyzer/Context.pv"
                return false;
            }

            #line 592 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 594 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 595 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 596 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 601 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 602 "src/analyzer/Context.pv"
        struct Generic* generic_ref = Generics__find(generics, name->value);
        #line 603 "src/analyzer/Context.pv"
        if (generic_ref == 0) {
            #line 603 "src/analyzer/Context.pv"
            return false;
        }

        #line 605 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 606 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 607 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 607 "src/analyzer/Context.pv"
                return false;
            }

            #line 609 "src/analyzer/Context.pv"
            bool found = false;
            #line 610 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generic_ref->traits);
            #line 610 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 610 "src/analyzer/Context.pv"
                struct Type* trait_type = Iter_ref_Type__value(&__iter);

                #line 611 "src/analyzer/Context.pv"
                switch (trait_type->type) {
                    #line 612 "src/analyzer/Context.pv"
                    case TYPE__TRAIT: {
                        #line 612 "src/analyzer/Context.pv"
                        struct Trait* trait_info = trait_type->trait_value._0;
                        #line 613 "src/analyzer/Context.pv"
                        if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                            #line 613 "src/analyzer/Context.pv"
                            found = true;
                        }
                    } break;
                    #line 615 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            } }
            #line 618 "src/analyzer/Context.pv"
            if (!found) {
                #line 619 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 620 "src/analyzer/Context.pv"
                return false;
            }

            #line 623 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 624 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 625 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 626 "src/analyzer/Context.pv"
            return true;
        }

        #line 629 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 630 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 631 "src/analyzer/Context.pv"
        return true;
    }

    #line 634 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 635 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 636 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 637 "src/analyzer/Context.pv"
        return true;
    }

    #line 640 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 641 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 642 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 643 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 644 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 645 "src/analyzer/Context.pv"
        return false;
    }

    #line 648 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 649 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 649 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 650 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 652 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 655 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 656 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 656 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 657 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 657 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 659 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 659 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 660 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 660 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 662 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 662 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 663 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 663 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 665 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 668 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 669 "src/analyzer/Context.pv"
    return true;
}

#line 672 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 673 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 675 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 675 "src/analyzer/Context.pv"
        return false;
    }

    #line 677 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 678 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 678 "src/analyzer/Context.pv"
        return false;
    }

    #line 680 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 681 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 682 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 683 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 684 "src/analyzer/Context.pv"
        return true;
    }

    #line 687 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 688 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 688 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 689 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 691 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 691 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 692 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 694 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 697 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 699 "src/analyzer/Context.pv"
    return true;
}

#line 702 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 703 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 705 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 706 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 707 "src/analyzer/Context.pv"
        return true;
    }

    #line 710 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 711 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 711 "src/analyzer/Context.pv"
        return false;
    }

    #line 713 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 714 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 715 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 716 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 717 "src/analyzer/Context.pv"
        return true;
    }

    #line 720 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 721 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 721 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 722 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 724 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 727 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 728 "src/analyzer/Context.pv"
    return true;
}

#line 731 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 732 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 733 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 733 "src/analyzer/Context.pv"
        return false;
    }

    #line 735 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 737 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 738 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 739 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 741 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 742 "src/analyzer/Context.pv"
                return false;
            }

            #line 745 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 747 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 748 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 749 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 754 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value, generics_.length);
    #line 755 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 756 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 757 "src/analyzer/Context.pv"
        return false;
    }

    #line 760 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 762 "src/analyzer/Context.pv"
    return true;
}

#line 765 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 766 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 768 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 769 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 770 "src/analyzer/Context.pv"
        return 0;
    }

    #line 773 "src/analyzer/Context.pv"
    return result;
}

#line 776 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 777 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 778 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 778 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 779 "src/analyzer/Context.pv"
            struct Type* resolved_to = Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map);
            #line 780 "src/analyzer/Context.pv"
            if (resolved_to == 0) {
                #line 780 "src/analyzer/Context.pv"
                return type;
            }

            #line 782 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *resolved_to,
            }});
            #line 786 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 786 "src/analyzer/Context.pv"
                return type;
            }

            #line 788 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 790 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 790 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 791 "src/analyzer/Context.pv"
            struct Type* resolved_element = Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map);
            #line 792 "src/analyzer/Context.pv"
            if (resolved_element == 0) {
                #line 792 "src/analyzer/Context.pv"
                return type;
            }

            #line 794 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = sequence->type,
                .element = *resolved_element,
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 799 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 799 "src/analyzer/Context.pv"
                return type;
            }
            #line 800 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 802 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 804 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 804 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 805 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 807 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 807 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 807 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 808 "src/analyzer/Context.pv"
                struct Type* resolved_element = Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
                #line 809 "src/analyzer/Context.pv"
                if (resolved_element == 0) {
                    #line 809 "src/analyzer/Context.pv"
                    return type;
                }
                #line 810 "src/analyzer/Context.pv"
                *element = *resolved_element;
            } }

            #line 813 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 815 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 816 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 818 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 818 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 818 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 819 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 819 "src/analyzer/Context.pv"
                return type;
            }
            #line 820 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 822 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 822 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 822 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 823 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 824 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 824 "src/analyzer/Context.pv"
                    return type;
                }
                #line 825 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 828 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 829 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 830 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 832 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 834 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 834 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 834 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 835 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 835 "src/analyzer/Context.pv"
                return type;
            }
            #line 836 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 837 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 838 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 838 "src/analyzer/Context.pv"
                return type;
            }

            #line 840 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 840 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 840 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 841 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 842 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 842 "src/analyzer/Context.pv"
                    return type;
                }
                #line 843 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 846 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 847 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 848 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 850 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 852 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 852 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 852 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 853 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 853 "src/analyzer/Context.pv"
                return type;
            }
            #line 854 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 855 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 856 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 856 "src/analyzer/Context.pv"
                return type;
            }

            #line 858 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 858 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 858 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 859 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 860 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 860 "src/analyzer/Context.pv"
                    return type;
                }
                #line 861 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 864 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 865 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 866 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 868 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 870 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 870 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 870 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 871 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 871 "src/analyzer/Context.pv"
                return type;
            }
            #line 872 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 872 "src/analyzer/Context.pv"
                return type;
            }
            #line 873 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 874 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 875 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 875 "src/analyzer/Context.pv"
                return type;
            }

            #line 877 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 877 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 877 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 878 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 879 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 879 "src/analyzer/Context.pv"
                    return type;
                }
                #line 880 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 883 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 884 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 885 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 887 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 889 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 889 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 890 "src/analyzer/Context.pv"
            struct Token* generic_name = gt->generic->name;
            #line 891 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 891 "src/analyzer/Context.pv"
                return type;
            }
            #line 892 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 893 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 895 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 895 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 896 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 896 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 898 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 899 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 900 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 900 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 901 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 901 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 901 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 902 "src/analyzer/Context.pv"
                            struct Trait* trait_info = impl_info->trait_;
                            #line 903 "src/analyzer/Context.pv"
                            if (trait_info == 0) {
                                #line 903 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 904 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&trait_info->typedefs, &gt->typedef_name) == 0) {
                                #line 904 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 905 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 906 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 906 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 909 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 913 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 915 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 915 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 916 "src/analyzer/Context.pv"
            struct Token* generic_name = generic->name;
            #line 917 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 917 "src/analyzer/Context.pv"
                return type;
            }
            #line 918 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 919 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 921 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 922 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 925 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 926 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 929 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 930 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 931 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 932 "src/analyzer/Context.pv"
                return type;
            }

            #line 935 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 937 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 938 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 939 "src/analyzer/Context.pv"
                struct Type* self_type = generics_map->self_type;
                #line 940 "src/analyzer/Context.pv"
                if (self_type != 0) {
                    #line 940 "src/analyzer/Context.pv"
                    return self_type;
                }
            }

            #line 943 "src/analyzer/Context.pv"
            if (fallback_generics_map != 0) {
                #line 944 "src/analyzer/Context.pv"
                struct Type* fallback_self_type = fallback_generics_map->self_type;
                #line 945 "src/analyzer/Context.pv"
                if (fallback_self_type != 0) {
                    #line 945 "src/analyzer/Context.pv"
                    return fallback_self_type;
                }
                #line 946 "src/analyzer/Context.pv"
                return type;
            }

            #line 949 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 951 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 954 "src/analyzer/Context.pv"
    return type;
}

#line 957 "src/analyzer/Context.pv"
struct Type* Context__get_path_narrowing(struct Context* self, struct str path) {
    #line 958 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 958 "src/analyzer/Context.pv"
        return 0;
    }

    #line 960 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 960 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 960 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 961 "src/analyzer/Context.pv"
        struct Type* t = HashMap_str_Type__find(&scope->values, &path);
        #line 962 "src/analyzer/Context.pv"
        if (t != 0) {
            #line 962 "src/analyzer/Context.pv"
            return t;
        }
    } }

    #line 965 "src/analyzer/Context.pv"
    return 0;
}

#line 968 "src/analyzer/Context.pv"
void Context__set_narrowed(struct Context* self, struct str name, struct Type* type) {
    #line 969 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 970 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 970 "src/analyzer/Context.pv"
        return;
    }
    #line 972 "src/analyzer/Context.pv"
    struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
    #line 973 "src/analyzer/Context.pv"
    if (existing != 0 && HashMap_str_Type__find(&scope->narrow_originals, &name) == 0) {
        #line 974 "src/analyzer/Context.pv"
        HashMap_str_Type__insert(&scope->narrow_originals, name, *existing);
    }
    #line 976 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name, *type);
}

#line 979 "src/analyzer/Context.pv"
struct Type* Context__get_broadened_type(struct Context* self, struct str name) {
    #line 980 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 980 "src/analyzer/Context.pv"
        return 0;
    }
    #line 981 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 981 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 981 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 982 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 983 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 983 "src/analyzer/Context.pv"
            return type;
        }
    } }
    #line 985 "src/analyzer/Context.pv"
    return 0;
}

#line 988 "src/analyzer/Context.pv"
bool Context__broaden_if_narrowed(struct Context* self, struct str name) {
    #line 989 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 989 "src/analyzer/Context.pv"
        return false;
    }
    #line 990 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 991 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 992 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 993 "src/analyzer/Context.pv"
        struct Type* original = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 994 "src/analyzer/Context.pv"
        if (original != 0) {
            #line 995 "src/analyzer/Context.pv"
            struct Type original_type = *original;
            #line 996 "src/analyzer/Context.pv"
            HashMap_str_Type__remove(&scope->narrow_originals, &name);
            #line 997 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, original_type);
            #line 998 "src/analyzer/Context.pv"
            return true;
        }
        #line 1000 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 1002 "src/analyzer/Context.pv"
    return false;
}

#line 1005 "src/analyzer/Context.pv"
bool Context__update_value_type(struct Context* self, struct str name, struct Type* type) {
    #line 1006 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 1006 "src/analyzer/Context.pv"
        return false;
    }
    #line 1007 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 1008 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 1009 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 1010 "src/analyzer/Context.pv"
        struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
        #line 1011 "src/analyzer/Context.pv"
        if (existing != 0) {
            #line 1012 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, *type);
            #line 1013 "src/analyzer/Context.pv"
            return true;
        }

        #line 1016 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 1018 "src/analyzer/Context.pv"
    return false;
}

#line 1021 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 1022 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 1023 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 1023 "src/analyzer/Context.pv"
        return false;
    }

    #line 1025 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(&scope->values, &name->value) != 0) {
        #line 1026 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 1027 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 1028 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 1029 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 1030 "src/analyzer/Context.pv"
        return false;
    }

    #line 1033 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name->value, *type);
    #line 1034 "src/analyzer/Context.pv"
    HashMap_str_ref_Token__insert(&scope->definition_tokens, name->value, name);
    #line 1035 "src/analyzer/Context.pv"
    Context__record_completion(self, name, type, 6);

    #line 1037 "src/analyzer/Context.pv"
    return true;
}

#line 1040 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 1041 "src/analyzer/Context.pv"
    if (self->scopes.length > 0) {
        #line 1042 "src/analyzer/Context.pv"
        struct Scope* scope_front = self->scopes.data;
        #line 1043 "src/analyzer/Context.pv"
        struct Scope* scope = Array_Scope__back(&self->scopes);

        #line 1045 "src/analyzer/Context.pv"
        while (scope != 0 && scope >= scope_front) {
            #line 1046 "src/analyzer/Context.pv"
            struct Type* type = HashMap_str_Type__find(&scope->values, &name);
            #line 1047 "src/analyzer/Context.pv"
            if (type != 0) {
                #line 1047 "src/analyzer/Context.pv"
                return type;
            }

            #line 1049 "src/analyzer/Context.pv"
            scope = scope - 1;
        }
    }

    #line 1053 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 1054 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 1054 "src/analyzer/Context.pv"
        return func;
    }

    #line 1056 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 1059 "src/analyzer/Context.pv"
struct Token* Context__get_definition_token(struct Context* self, struct str name) {
    #line 1060 "src/analyzer/Context.pv"
    if (self->scopes.length > 0) {
        #line 1061 "src/analyzer/Context.pv"
        struct Scope* scope_front = self->scopes.data;
        #line 1062 "src/analyzer/Context.pv"
        struct Scope* scope = Array_Scope__back(&self->scopes);

        #line 1064 "src/analyzer/Context.pv"
        while (scope != 0 && scope >= scope_front) {
            #line 1065 "src/analyzer/Context.pv"
            struct Token** token = HashMap_str_ref_Token__find(&scope->definition_tokens, &name);
            #line 1066 "src/analyzer/Context.pv"
            if (token != 0) {
                #line 1066 "src/analyzer/Context.pv"
                return *token;
            }
            #line 1067 "src/analyzer/Context.pv"
            scope = scope - 1;
        }
    }

    #line 1071 "src/analyzer/Context.pv"
    return 0;
}

#line 1074 "src/analyzer/Context.pv"
bool Context__should_record_symbols(struct Context* self) {
    #line 1075 "src/analyzer/Context.pv"
    return self->analysis->collect_symbols;
}

#line 1078 "src/analyzer/Context.pv"
void Context__record_symbol(struct Context* self, struct Token* token, struct str type_label, struct str def_path, struct Token* def_token) {
    #line 1079 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1079 "src/analyzer/Context.pv"
        return;
    }

    #line 1081 "src/analyzer/Context.pv"
    struct HashMap_str_Array_SymbolInfo* symbols = &self->analysis->symbol_info;
    #line 1082 "src/analyzer/Context.pv"
    struct Array_SymbolInfo* file_symbols = HashMap_str_Array_SymbolInfo__find(symbols, &self->path);
    #line 1083 "src/analyzer/Context.pv"
    if (file_symbols == 0) {
        #line 1083 "src/analyzer/Context.pv"
        file_symbols = HashMap_str_Array_SymbolInfo__insert(symbols, self->path, Array_SymbolInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1084 "src/analyzer/Context.pv"
    if (file_symbols == 0) {
        #line 1084 "src/analyzer/Context.pv"
        return;
    }

    #line 1086 "src/analyzer/Context.pv"
    struct Position def_position = (struct Position) { .line = 0, .character = 0 };
    #line 1087 "src/analyzer/Context.pv"
    if (def_token != 0) {
        #line 1088 "src/analyzer/Context.pv"
        def_position = (struct Position) { .line = def_token->start_line, .character = def_token->start_column };
    }

    #line 1091 "src/analyzer/Context.pv"
    Array_SymbolInfo__append(file_symbols, (struct SymbolInfo) {
        .range = (struct Range) {
            .start = (struct Position) { .line = token->start_line, .character = token->start_column },
            .end = (struct Position) { .line = token->end_line, .character = token->end_column },
        },
        .type_label = type_label,
        .definition_path = def_path,
        .definition_position = def_position,
    });
}

#line 1102 "src/analyzer/Context.pv"
void Context__record_signature(struct Context* self, struct Token* open_paren, struct Token* close_paren, struct Array_Position comma_positions, struct str label, struct Array_str parameters) {
    #line 1103 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1103 "src/analyzer/Context.pv"
        return;
    }

    #line 1105 "src/analyzer/Context.pv"
    struct HashMap_str_Array_SignatureInfo* sigs = &self->analysis->signature_info;
    #line 1106 "src/analyzer/Context.pv"
    struct Array_SignatureInfo* file_sigs = HashMap_str_Array_SignatureInfo__find(sigs, &self->path);
    #line 1107 "src/analyzer/Context.pv"
    if (file_sigs == 0) {
        #line 1107 "src/analyzer/Context.pv"
        file_sigs = HashMap_str_Array_SignatureInfo__insert(sigs, self->path, Array_SignatureInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1108 "src/analyzer/Context.pv"
    if (file_sigs == 0) {
        #line 1108 "src/analyzer/Context.pv"
        return;
    }

    #line 1110 "src/analyzer/Context.pv"
    Array_SignatureInfo__append(file_sigs, (struct SignatureInfo) {
        .open_paren = (struct Position) { .line = open_paren->start_line, .character = open_paren->start_column },
        .close_paren = (struct Position) { .line = close_paren->end_line, .character = close_paren->end_column },
        .comma_positions = comma_positions,
        .label = label,
        .parameters = parameters,
    });
}

#line 1119 "src/analyzer/Context.pv"
void Context__record_completion(struct Context* self, struct Token* name, struct Type* type, uintptr_t kind) {
    #line 1120 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1120 "src/analyzer/Context.pv"
        return;
    }

    #line 1122 "src/analyzer/Context.pv"
    struct Function* function = self->function;
    #line 1123 "src/analyzer/Context.pv"
    if (function == 0) {
        #line 1123 "src/analyzer/Context.pv"
        return;
    }
    #line 1124 "src/analyzer/Context.pv"
    if (function->token_start >= self->length || usize__Eq_usize__eq(function->token_end, 0) || function->token_end > self->length) {
        #line 1124 "src/analyzer/Context.pv"
        return;
    }

    #line 1126 "src/analyzer/Context.pv"
    struct HashMap_str_Array_CompletionInfo* items = &self->analysis->completion_info;
    #line 1127 "src/analyzer/Context.pv"
    struct Array_CompletionInfo* file_items = HashMap_str_Array_CompletionInfo__find(items, &self->path);
    #line 1128 "src/analyzer/Context.pv"
    if (file_items == 0) {
        #line 1128 "src/analyzer/Context.pv"
        file_items = HashMap_str_Array_CompletionInfo__insert(items, self->path, Array_CompletionInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1129 "src/analyzer/Context.pv"
    if (file_items == 0) {
        #line 1129 "src/analyzer/Context.pv"
        return;
    }

    #line 1131 "src/analyzer/Context.pv"
    struct String type_label = Naming__get_type_decl(&self->root->naming_decl, type, self->type_self, 0);
    #line 1132 "src/analyzer/Context.pv"
    struct Token* first = &self->tokens[function->token_start];
    #line 1133 "src/analyzer/Context.pv"
    struct Token* last = &self->tokens[function->token_end - 1];

    #line 1135 "src/analyzer/Context.pv"
    Array_CompletionInfo__append(file_items, (struct CompletionInfo) {
        .range = (struct Range) {
            .start = (struct Position) { .line = first->start_line, .character = first->start_column },
            .end = (struct Position) { .line = last->end_line, .character = last->end_column },
        },
        .name = name->value,
        .type_label = String__as_str(&type_label),
        .kind = kind,
        .definition_position = (struct Position) { .line = name->start_line, .character = name->start_column },
    });
}

#line 1147 "src/analyzer/Context.pv"
void Context__record_member_completion(struct Context* self, struct Token* dot, struct Type* receiver_type, bool is_static) {
    #line 1148 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1148 "src/analyzer/Context.pv"
        return;
    }

    #line 1150 "src/analyzer/Context.pv"
    struct HashMap_str_Array_MemberCompletionInfo* infos = &self->analysis->member_completion_info;
    #line 1151 "src/analyzer/Context.pv"
    struct Array_MemberCompletionInfo* file_infos = HashMap_str_Array_MemberCompletionInfo__find(infos, &self->path);
    #line 1152 "src/analyzer/Context.pv"
    if (file_infos == 0) {
        #line 1152 "src/analyzer/Context.pv"
        file_infos = HashMap_str_Array_MemberCompletionInfo__insert(infos, self->path, Array_MemberCompletionInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1153 "src/analyzer/Context.pv"
    if (file_infos == 0) {
        #line 1153 "src/analyzer/Context.pv"
        return;
    }

    #line 1155 "src/analyzer/Context.pv"
    struct Type* resolved_type = receiver_type;
    #line 1156 "src/analyzer/Context.pv"
    switch (receiver_type->type) {
        #line 1157 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 1158 "src/analyzer/Context.pv"
            if (self->type_self != 0 && !Type__is_self(self->type_self)) {
                #line 1159 "src/analyzer/Context.pv"
                resolved_type = self->type_self;
            }
        } break;
        #line 1162 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 1162 "src/analyzer/Context.pv"
            struct Indirect* indirect = receiver_type->indirect_value;
            #line 1163 "src/analyzer/Context.pv"
            switch (indirect->to.type) {
                #line 1164 "src/analyzer/Context.pv"
                case TYPE__SELF: {
                    #line 1165 "src/analyzer/Context.pv"
                    if (self->type_self != 0 && !Type__is_self(self->type_self)) {
                        #line 1166 "src/analyzer/Context.pv"
                        resolved_type = self->type_self;
                    }
                } break;
                #line 1169 "src/analyzer/Context.pv"
                default: {
                } break;
            }
        } break;
        #line 1172 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 1175 "src/analyzer/Context.pv"
    Array_MemberCompletionInfo__append(file_infos, (struct MemberCompletionInfo) {
        .dot_position = (struct Position) { .line = dot->start_line, .character = dot->start_column },
        .receiver_type = *resolved_type,
        .is_static = is_static,
    });
}

#line 1182 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 1183 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 1185 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 1185 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 1187 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 1188 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 1190 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 1190 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }

        #line 1192 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 1194 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 1195 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 1196 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 1200 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 1203 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 1204 "src/analyzer/Context.pv"
    struct GenericMap usage_map = GenericMap__new(self->allocator, generics, usage_types);
    #line 1205 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 1206 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 1207 "src/analyzer/Context.pv"
        struct Generic* generic = &generics->array.data[i];
        #line 1208 "src/analyzer/Context.pv"
        struct Type* usage_type = &usage_types->data[i];

        #line 1210 "src/analyzer/Context.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&generic->traits);
        #line 1210 "src/analyzer/Context.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 1210 "src/analyzer/Context.pv"
            struct Type* required_trait = Iter_ref_Type__value(&__iter);

            #line 1211 "src/analyzer/Context.pv"
            struct Type* resolved_required_trait = Context__resolve_type(self->allocator, required_trait, &usage_map, 0);
            #line 1212 "src/analyzer/Context.pv"
            if (resolved_required_trait == 0) {
                #line 1212 "src/analyzer/Context.pv"
                return false;
            }
            #line 1213 "src/analyzer/Context.pv"
            bool implements = false;
            #line 1214 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 1215 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 1215 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 1216 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 1216 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1216 "src/analyzer/Context.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1217 "src/analyzer/Context.pv"
                        if (Type__eq(&impl_info->trait_type, resolved_required_trait)) {
                            #line 1217 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1220 "src/analyzer/Context.pv"
                case TYPE__ENUM: {
                    #line 1220 "src/analyzer/Context.pv"
                    struct Enum* enum_info = usage_type->enum_value._0;
                    #line 1221 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 1221 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1221 "src/analyzer/Context.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1222 "src/analyzer/Context.pv"
                        if (Type__eq(&impl_info->trait_type, resolved_required_trait)) {
                            #line 1222 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1225 "src/analyzer/Context.pv"
                case TYPE__PRIMITIVE: {
                    #line 1225 "src/analyzer/Context.pv"
                    struct Primitive* primitive_info = usage_type->primitive_value;
                    #line 1226 "src/analyzer/Context.pv"
                    if (primitive_info != 0) {
                        #line 1227 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
                        #line 1227 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 1227 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 1228 "src/analyzer/Context.pv"
                            if (Type__eq(&impl_info->trait_type, resolved_required_trait)) {
                                #line 1228 "src/analyzer/Context.pv"
                                implements = true;
                            }
                        } }
                    }
                } break;
                #line 1232 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 1232 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 1233 "src/analyzer/Context.pv"
                    { struct Iter_ref_Type __iter = Array_Type__iter(&generic_info->traits);
                    #line 1233 "src/analyzer/Context.pv"
                    while (Iter_ref_Type__next(&__iter)) {
                        #line 1233 "src/analyzer/Context.pv"
                        struct Type* generic_trait = Iter_ref_Type__value(&__iter);

                        #line 1234 "src/analyzer/Context.pv"
                        if (Type__eq(generic_trait, resolved_required_trait)) {
                            #line 1234 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1237 "src/analyzer/Context.pv"
                default: {
                    #line 1237 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 1239 "src/analyzer/Context.pv"
            if (!implements) {
                #line 1240 "src/analyzer/Context.pv"
                struct Token* name = 0;
                #line 1241 "src/analyzer/Context.pv"
                switch (resolved_required_trait->type) {
                    #line 1242 "src/analyzer/Context.pv"
                    case TYPE__TRAIT: {
                        #line 1242 "src/analyzer/Context.pv"
                        struct Trait* trait_info = resolved_required_trait->trait_value._0;
                        #line 1242 "src/analyzer/Context.pv"
                        name = trait_info->name;
                    } break;
                    #line 1243 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
                #line 1245 "src/analyzer/Context.pv"
                if (name == 0) {
                    #line 1246 "src/analyzer/Context.pv"
                    Context__error(self, "Type does not implement required trait");
                    #line 1247 "src/analyzer/Context.pv"
                    return false;
                }

                #line 1250 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 1251 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 1252 "src/analyzer/Context.pv"
                String__append(&message, name->value);
                #line 1253 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 1254 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 1255 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 1259 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 1261 "src/analyzer/Context.pv"
    return true;
}
