#include <string.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/Module.h>
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
#include <usize.h>
#include <analyzer/InlayHintKind.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>
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
#include <analyzer/expression/ExpressionData.h>
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
    if (usize__Eq_usize__eq(self->length, 0)) {
        #line 198 "src/analyzer/Context.pv"
        return;
    }

    #line 200 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 202 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 203 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 206 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 208 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 211 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 212 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 213 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 214 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 217 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 218 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->length, 0)) {
        #line 218 "src/analyzer/Context.pv"
        return;
    }

    #line 220 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 222 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 223 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 226 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 227 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 230 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 231 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 232 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 233 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 236 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 237 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->length, 0)) {
        #line 237 "src/analyzer/Context.pv"
        return;
    }

    #line 239 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 241 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 242 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 245 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 246 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 249 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 250 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, TokenBounds__new(token, token), label, kind, padding_left, padding_right);
}

#line 253 "src/analyzer/Context.pv"
void Context__inlay_hint_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 254 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 255 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 256 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 256 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 257 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 257 "src/analyzer/Context.pv"
        return;
    }

    #line 259 "src/analyzer/Context.pv"
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

#line 271 "src/analyzer/Context.pv"
void Context__inlay_hint_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 272 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, Expression__get_token_bounds(expression), label, kind, padding_left, padding_right);
}

#line 275 "src/analyzer/Context.pv"
void Context__inlay_hint_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 276 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, Statement__get_token_bounds(statement), label, kind, padding_left, padding_right);
}

#line 279 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 280 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, TokenBounds__new(token, token), label, kind, padding_left, padding_right);
}

#line 283 "src/analyzer/Context.pv"
void Context__inlay_hint_before_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 284 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 285 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 286 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 286 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 287 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 287 "src/analyzer/Context.pv"
        return;
    }

    #line 289 "src/analyzer/Context.pv"
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

#line 301 "src/analyzer/Context.pv"
void Context__inlay_hint_before_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 302 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, Expression__get_token_bounds(expression), label, kind, padding_left, padding_right);
}

#line 305 "src/analyzer/Context.pv"
void Context__inlay_hint_before_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 306 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, Statement__get_token_bounds(statement), label, kind, padding_left, padding_right);
}

#line 309 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 310 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 312 "src/analyzer/Context.pv"
    while (self->pos < self->length && self->tokens[self->pos].type == TOKEN_TYPE__COMMENT) {
        #line 313 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 316 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 319 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 320 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 321 "src/analyzer/Context.pv"
        return 0;
    }

    #line 324 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 327 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 328 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->pos, 0)) {
        #line 329 "src/analyzer/Context.pv"
        return 0;
    }

    #line 332 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 335 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 336 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 337 "src/analyzer/Context.pv"
        return false;
    }

    #line 340 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 343 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 344 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 345 "src/analyzer/Context.pv"
        return false;
    }

    #line 348 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 350 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 353 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 354 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 355 "src/analyzer/Context.pv"
    if (check) {
        #line 355 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 356 "src/analyzer/Context.pv"
    return check;
}

#line 359 "src/analyzer/Context.pv"
bool Context__check_const_generic_argument(struct Context* self) {
    #line 360 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 360 "src/analyzer/Context.pv"
        return false;
    }

    #line 362 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];
    #line 363 "src/analyzer/Context.pv"
    if (token->type == TOKEN_TYPE__NUMBER) {
        #line 363 "src/analyzer/Context.pv"
        return true;
    }

    #line 365 "src/analyzer/Context.pv"
    if (token->type == TOKEN_TYPE__IDENTIFIER && self->pos + 1 < self->length) {
        #line 366 "src/analyzer/Context.pv"
        if (Token__eq(&self->tokens[self->pos + 1], TOKEN_TYPE__SYMBOL, "::")) {
            #line 367 "src/analyzer/Context.pv"
            return true;
        }
    }

    #line 371 "src/analyzer/Context.pv"
    return Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+");
}

#line 374 "src/analyzer/Context.pv"
bool Context__parse_const_generic_argument(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 375 "src/analyzer/Context.pv"
    struct Token* value_token = Context__current(self);
    #line 376 "src/analyzer/Context.pv"
    if (value_token == 0) {
        #line 376 "src/analyzer/Context.pv"
        return false;
    }
    #line 381 "src/analyzer/Context.pv"
    struct Expression* expression = Expression__parse_primary(self, generics);
    #line 382 "src/analyzer/Context.pv"
    if (expression == 0) {
        #line 382 "src/analyzer/Context.pv"
        return false;
    }

    #line 384 "src/analyzer/Context.pv"
    expression = Expression__parse_binary(self, expression, 9, generics);
    #line 385 "src/analyzer/Context.pv"
    if (expression == 0) {
        #line 385 "src/analyzer/Context.pv"
        return false;
    }

    #line 387 "src/analyzer/Context.pv"
    if (!Expression__is_const_expression(expression, self)) {
        #line 388 "src/analyzer/Context.pv"
        Context__error_token(self, value_token, "Const generic argument must be a compile-time constant integer expression");
        #line 389 "src/analyzer/Context.pv"
        return false;
    }

    #line 392 "src/analyzer/Context.pv"
    *type = (struct Type) { .type = TYPE__CONST, .const_value = expression };

    #line 394 "src/analyzer/Context.pv"
    return true;
}

#line 397 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 398 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 399 "src/analyzer/Context.pv"
        Context__error_expected(self, type);
        #line 400 "src/analyzer/Context.pv"
        return 0;
    }

    #line 403 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 405 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 406 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 407 "src/analyzer/Context.pv"
        return token;
    }

    #line 410 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 411 "src/analyzer/Context.pv"
    return 0;
}

#line 414 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 415 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 416 "src/analyzer/Context.pv"
        Context__error_expected_value(self, type, value);
        #line 417 "src/analyzer/Context.pv"
        return false;
    }

    #line 420 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 422 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 423 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 424 "src/analyzer/Context.pv"
        return true;
    }

    #line 427 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 428 "src/analyzer/Context.pv"
    return false;
}

#line 431 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 432 "src/analyzer/Context.pv"
    while (self->pos < self->length && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 433 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 436 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 439 "src/analyzer/Context.pv"
bool Context__skip_to_statement_end(struct Context* self) {
    #line 440 "src/analyzer/Context.pv"
    uintptr_t square_depth = 0;
    #line 441 "src/analyzer/Context.pv"
    uintptr_t paren_depth = 0;
    #line 442 "src/analyzer/Context.pv"
    uintptr_t brace_depth = 0;

    #line 444 "src/analyzer/Context.pv"
    while (self->pos < self->length) {
        #line 445 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "[")) {
            #line 446 "src/analyzer/Context.pv"
            square_depth += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 448 "src/analyzer/Context.pv"
            if (square_depth > 0) {
                #line 448 "src/analyzer/Context.pv"
                square_depth -= 1;
            }
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "(")) {
            #line 450 "src/analyzer/Context.pv"
            paren_depth += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 452 "src/analyzer/Context.pv"
            if (paren_depth > 0) {
                #line 452 "src/analyzer/Context.pv"
                paren_depth -= 1;
            }
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "{")) {
            #line 454 "src/analyzer/Context.pv"
            brace_depth += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, "}")) {
            #line 456 "src/analyzer/Context.pv"
            if (brace_depth > 0) {
                #line 456 "src/analyzer/Context.pv"
                brace_depth -= 1;
            }
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, ";") && usize__Eq_usize__eq(square_depth, 0) && usize__Eq_usize__eq(paren_depth, 0) && usize__Eq_usize__eq(brace_depth, 0)) {
            #line 458 "src/analyzer/Context.pv"
            return true;
        }

        #line 461 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 464 "src/analyzer/Context.pv"
    return false;
}

#line 467 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 468 "src/analyzer/Context.pv"
    while (self->pos < self->length && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 469 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 473 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 474 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 476 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 476 "src/analyzer/Context.pv"
        return false;
    }

    #line 478 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 480 "src/analyzer/Context.pv"
    while (self->pos < self->length && brackets > 0) {
        #line 481 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 482 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 484 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 487 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 488 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 492 "src/analyzer/Context.pv"
    Context__next_token(self);

    #line 494 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 495 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 496 "src/analyzer/Context.pv"
        return false;
    }

    #line 499 "src/analyzer/Context.pv"
    return true;
}

#line 502 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 503 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 504 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 507 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 508 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 511 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 512 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 513 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 514 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 514 "src/analyzer/Context.pv"
            return false;
        }

        #line 516 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 517 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 519 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 520 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 522 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 523 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 525 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 526 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 526 "src/analyzer/Context.pv"
                return false;
            }
            #line 527 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 528 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 530 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 530 "src/analyzer/Context.pv"
                return false;
            }
            #line 531 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 532 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 535 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 537 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn")) {
            #line 538 "src/analyzer/Context.pv"
            struct Type target_type;
            #line 539 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 539 "src/analyzer/Context.pv"
                return false;
            }
            #line 540 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 541 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
            #line 542 "src/analyzer/Context.pv"
            return true;
        }

        #line 545 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 546 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 546 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 548 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = indirect_type, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
        #line 549 "src/analyzer/Context.pv"
        if (indirect == 0) {
            #line 549 "src/analyzer/Context.pv"
            return false;
        }

        #line 551 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 552 "src/analyzer/Context.pv"
            return false;
        }

        #line 555 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 556 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 558 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 560 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 560 "src/analyzer/Context.pv"
            return false;
        }
        #line 561 "src/analyzer/Context.pv"
        sequence->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = sequence->element }}) };

        #line 563 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 564 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 565 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 567 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 567 "src/analyzer/Context.pv"
                return false;
            }

            #line 569 "src/analyzer/Context.pv"
            return true;
        }

        #line 572 "src/analyzer/Context.pv"
        struct Token* length_token = Context__current(self);
        #line 573 "src/analyzer/Context.pv"
        struct Expression* length_expr = Expression__parse(self, generics);
        #line 574 "src/analyzer/Context.pv"
        if (length_expr == 0) {
            #line 574 "src/analyzer/Context.pv"
            return false;
        }

        #line 576 "src/analyzer/Context.pv"
        if (!Expression__is_const_expression(length_expr, self)) {
            #line 577 "src/analyzer/Context.pv"
            Context__error_token(self, length_token, "Fixed array length must be a compile-time constant integer expression");
            #line 578 "src/analyzer/Context.pv"
            return false;
        }

        #line 581 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = length_expr };
        #line 582 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 584 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 584 "src/analyzer/Context.pv"
            return false;
        }

        #line 586 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 588 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 589 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 591 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 592 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 594 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 594 "src/analyzer/Context.pv"
                return false;
            }

            #line 596 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 598 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 599 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 600 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 604 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 605 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 607 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 608 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 609 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
        #line 610 "src/analyzer/Context.pv"
        if (func_info == 0) {
            #line 610 "src/analyzer/Context.pv"
            return false;
        }
        #line 611 "src/analyzer/Context.pv"
        if (generic_map == 0) {
            #line 611 "src/analyzer/Context.pv"
            return false;
        }

        #line 613 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 613 "src/analyzer/Context.pv"
            return false;
        }

        #line 615 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 617 "src/analyzer/Context.pv"
        return true;
    }

    #line 620 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 621 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 621 "src/analyzer/Context.pv"
        return false;
    }

    #line 623 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 624 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 625 "src/analyzer/Context.pv"
        return true;
    }

    #line 628 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 630 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 631 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 632 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 634 "src/analyzer/Context.pv"
            if (Context__check_const_generic_argument(self)) {
                #line 635 "src/analyzer/Context.pv"
                if (!Context__parse_const_generic_argument(self, &child_type, generics)) {
                    #line 635 "src/analyzer/Context.pv"
                    return false;
                }
            } else if (!Context__parse_type(self, &child_type, generics)) {
                #line 637 "src/analyzer/Context.pv"
                return false;
            }

            #line 640 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 642 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 643 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 644 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 649 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 650 "src/analyzer/Context.pv"
        struct Generic* generic_ref = Generics__find(generics, name->value);
        #line 651 "src/analyzer/Context.pv"
        if (generic_ref == 0) {
            #line 651 "src/analyzer/Context.pv"
            return false;
        }

        #line 653 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 654 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 655 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 655 "src/analyzer/Context.pv"
                return false;
            }

            #line 657 "src/analyzer/Context.pv"
            bool found = false;
            #line 658 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generic_ref->traits);
            #line 658 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 658 "src/analyzer/Context.pv"
                struct Type* trait_type = Iter_ref_Type__value(&__iter);

                #line 659 "src/analyzer/Context.pv"
                switch (trait_type->type) {
                    #line 660 "src/analyzer/Context.pv"
                    case TYPE__TRAIT: {
                        #line 660 "src/analyzer/Context.pv"
                        struct Trait* trait_info = trait_type->trait_value._0;
                        #line 661 "src/analyzer/Context.pv"
                        if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                            #line 661 "src/analyzer/Context.pv"
                            found = true;
                        }
                    } break;
                    #line 663 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            } }
            #line 666 "src/analyzer/Context.pv"
            if (!found) {
                #line 667 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 668 "src/analyzer/Context.pv"
                return false;
            }

            #line 671 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 672 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 673 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 674 "src/analyzer/Context.pv"
            return true;
        }

        #line 677 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 678 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 679 "src/analyzer/Context.pv"
        return true;
    }

    #line 682 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 683 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 684 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 685 "src/analyzer/Context.pv"
        return true;
    }

    #line 688 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 689 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 690 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 691 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 692 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 693 "src/analyzer/Context.pv"
        return false;
    }

    #line 696 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 697 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 697 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 698 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 700 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 703 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 704 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 704 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 705 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 705 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 707 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 707 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 708 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 708 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 710 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 710 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 711 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 711 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 713 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 716 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 717 "src/analyzer/Context.pv"
    return true;
}

#line 720 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 721 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 723 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 723 "src/analyzer/Context.pv"
        return false;
    }

    #line 725 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 726 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 726 "src/analyzer/Context.pv"
        return false;
    }

    #line 728 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 729 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 730 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 731 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 732 "src/analyzer/Context.pv"
        return true;
    }

    #line 735 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 736 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 736 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 737 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 739 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 739 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 740 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 742 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 745 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 747 "src/analyzer/Context.pv"
    return true;
}

#line 750 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 751 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 753 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 754 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 755 "src/analyzer/Context.pv"
        return true;
    }

    #line 758 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 759 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 759 "src/analyzer/Context.pv"
        return false;
    }

    #line 761 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 762 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 763 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 764 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 765 "src/analyzer/Context.pv"
        return true;
    }

    #line 768 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 769 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 769 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 770 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 772 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 775 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 776 "src/analyzer/Context.pv"
    return true;
}

#line 779 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 780 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 781 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 781 "src/analyzer/Context.pv"
        return false;
    }

    #line 783 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 785 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 786 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 787 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 789 "src/analyzer/Context.pv"
            if (Context__check_const_generic_argument(self)) {
                #line 790 "src/analyzer/Context.pv"
                if (!Context__parse_const_generic_argument(self, &child_type, generics)) {
                    #line 790 "src/analyzer/Context.pv"
                    return false;
                }
            } else if (!Context__parse_type(self, &child_type, generics)) {
                #line 792 "src/analyzer/Context.pv"
                return false;
            }

            #line 795 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 797 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 798 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 799 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 804 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value, generics_.length);
    #line 805 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 806 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 807 "src/analyzer/Context.pv"
        return false;
    }

    #line 810 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 812 "src/analyzer/Context.pv"
    return true;
}

#line 815 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 816 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 818 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 819 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 820 "src/analyzer/Context.pv"
        return 0;
    }

    #line 823 "src/analyzer/Context.pv"
    return result;
}

#line 828 "src/analyzer/Context.pv"
struct Expression* Context__resolve_const_expression(struct ArenaAllocator* allocator, struct Expression* expression, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 829 "src/analyzer/Context.pv"
    switch (expression->data.type) {
        #line 830 "src/analyzer/Context.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 830 "src/analyzer/Context.pv"
            struct Type* type = expression->data.type_value;
            #line 831 "src/analyzer/Context.pv"
            switch (type->type) {
                #line 832 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 832 "src/analyzer/Context.pv"
                    struct Generic* generic = type->generic_value;
                    #line 833 "src/analyzer/Context.pv"
                    if (!Generic__is_const(generic)) {
                        #line 833 "src/analyzer/Context.pv"
                        return expression;
                    }

                    #line 835 "src/analyzer/Context.pv"
                    struct Token* generic_name = generic->name;
                    #line 836 "src/analyzer/Context.pv"
                    if (generic_name == 0) {
                        #line 836 "src/analyzer/Context.pv"
                        return expression;
                    }

                    #line 838 "src/analyzer/Context.pv"
                    struct Type* concrete_type = 0;
                    #line 839 "src/analyzer/Context.pv"
                    if (generics_map != 0) {
                        #line 839 "src/analyzer/Context.pv"
                        concrete_type = GenericMap__get(generics_map, generic_name->value);
                    }
                    #line 840 "src/analyzer/Context.pv"
                    if (concrete_type == 0 && fallback_generics_map != 0) {
                        #line 840 "src/analyzer/Context.pv"
                        concrete_type = GenericMap__get(fallback_generics_map, generic_name->value);
                    }
                    #line 841 "src/analyzer/Context.pv"
                    if (concrete_type == 0) {
                        #line 841 "src/analyzer/Context.pv"
                        return expression;
                    }

                    #line 843 "src/analyzer/Context.pv"
                    switch (concrete_type->type) {
                        #line 844 "src/analyzer/Context.pv"
                        case TYPE__CONST: {
                            #line 844 "src/analyzer/Context.pv"
                            struct Expression* value = concrete_type->const_value;
                            #line 844 "src/analyzer/Context.pv"
                            return value;
                        } break;
                        #line 845 "src/analyzer/Context.pv"
                        default: {
                            #line 845 "src/analyzer/Context.pv"
                            return expression;
                        } break;
                    }
                } break;
                #line 848 "src/analyzer/Context.pv"
                default: {
                    #line 848 "src/analyzer/Context.pv"
                    return expression;
                } break;
            }
        } break;
        #line 851 "src/analyzer/Context.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 851 "src/analyzer/Context.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 852 "src/analyzer/Context.pv"
            struct Expression* resolved_inner = Context__resolve_const_expression(allocator, inner, generics_map, fallback_generics_map);
            #line 853 "src/analyzer/Context.pv"
            if (resolved_inner == inner) {
                #line 853 "src/analyzer/Context.pv"
                return expression;
            }

            #line 855 "src/analyzer/Context.pv"
            return Expression__make(allocator, expression->token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = resolved_inner }, &expression->return_type);
        } break;
        #line 857 "src/analyzer/Context.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 857 "src/analyzer/Context.pv"
            struct str op = expression->data.unaryexpression_value._0;
            #line 857 "src/analyzer/Context.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 858 "src/analyzer/Context.pv"
            struct Expression* resolved_inner = Context__resolve_const_expression(allocator, inner, generics_map, fallback_generics_map);
            #line 859 "src/analyzer/Context.pv"
            if (resolved_inner == inner) {
                #line 859 "src/analyzer/Context.pv"
                return expression;
            }

            #line 861 "src/analyzer/Context.pv"
            return Expression__make(allocator, expression->token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = op, ._1 = resolved_inner} }, &expression->return_type);
        } break;
        #line 863 "src/analyzer/Context.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 863 "src/analyzer/Context.pv"
            struct Expression* lhs = expression->data.binaryexpression_value._0;
            #line 863 "src/analyzer/Context.pv"
            struct str op = expression->data.binaryexpression_value._1;
            #line 863 "src/analyzer/Context.pv"
            struct Expression* rhs = expression->data.binaryexpression_value._2;
            #line 864 "src/analyzer/Context.pv"
            struct Expression* resolved_lhs = Context__resolve_const_expression(allocator, lhs, generics_map, fallback_generics_map);
            #line 865 "src/analyzer/Context.pv"
            struct Expression* resolved_rhs = Context__resolve_const_expression(allocator, rhs, generics_map, fallback_generics_map);
            #line 866 "src/analyzer/Context.pv"
            if (resolved_lhs == lhs && resolved_rhs == rhs) {
                #line 866 "src/analyzer/Context.pv"
                return expression;
            }

            #line 868 "src/analyzer/Context.pv"
            return Expression__make(allocator, expression->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = resolved_lhs, ._1 = op, ._2 = resolved_rhs} }, &expression->return_type);
        } break;
        #line 870 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 873 "src/analyzer/Context.pv"
    return expression;
}

#line 876 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 877 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 878 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 878 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 879 "src/analyzer/Context.pv"
            struct Type* resolved_to = Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map);
            #line 880 "src/analyzer/Context.pv"
            if (resolved_to == 0) {
                #line 880 "src/analyzer/Context.pv"
                return type;
            }

            #line 882 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *resolved_to,
            }});
            #line 886 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 886 "src/analyzer/Context.pv"
                return type;
            }

            #line 888 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 890 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 890 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 891 "src/analyzer/Context.pv"
            struct Type* resolved_element = Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map);
            #line 892 "src/analyzer/Context.pv"
            if (resolved_element == 0) {
                #line 892 "src/analyzer/Context.pv"
                return type;
            }

            #line 894 "src/analyzer/Context.pv"
            struct SequenceType resolved_sequence_type = sequence->type;
            #line 895 "src/analyzer/Context.pv"
            switch (sequence->type.type) {
                #line 896 "src/analyzer/Context.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 896 "src/analyzer/Context.pv"
                    struct Expression* length = sequence->type.fixedarray_value;
                    #line 897 "src/analyzer/Context.pv"
                    struct Expression* resolved_length = Context__resolve_const_expression(allocator, length, generics_map, fallback_generics_map);
                    #line 898 "src/analyzer/Context.pv"
                    resolved_sequence_type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = resolved_length };
                } break;
                #line 900 "src/analyzer/Context.pv"
                default: {
                } break;
            }

            #line 903 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = resolved_sequence_type,
                .element = *resolved_element,
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 908 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 908 "src/analyzer/Context.pv"
                return type;
            }
            #line 909 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 911 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 913 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 913 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 914 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 916 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 916 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 916 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 917 "src/analyzer/Context.pv"
                struct Type* resolved_element = Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
                #line 918 "src/analyzer/Context.pv"
                if (resolved_element == 0) {
                    #line 918 "src/analyzer/Context.pv"
                    return type;
                }
                #line 919 "src/analyzer/Context.pv"
                *element = *resolved_element;
            } }

            #line 922 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 924 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 925 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 927 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 927 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 927 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 928 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 928 "src/analyzer/Context.pv"
                return type;
            }
            #line 929 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 931 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 931 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 931 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 932 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 933 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 933 "src/analyzer/Context.pv"
                    return type;
                }
                #line 934 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 937 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 938 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 939 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 941 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 943 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 943 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 943 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 944 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 944 "src/analyzer/Context.pv"
                return type;
            }
            #line 945 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 946 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 947 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 947 "src/analyzer/Context.pv"
                return type;
            }

            #line 949 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 949 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 949 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 950 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 951 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 951 "src/analyzer/Context.pv"
                    return type;
                }
                #line 952 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 955 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 956 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 957 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 959 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 961 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 961 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 961 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 962 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 962 "src/analyzer/Context.pv"
                return type;
            }
            #line 963 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 964 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 965 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 965 "src/analyzer/Context.pv"
                return type;
            }

            #line 967 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 967 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 967 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 968 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 969 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 969 "src/analyzer/Context.pv"
                    return type;
                }
                #line 970 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 973 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 974 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 975 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 977 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 979 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 979 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 979 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 980 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 980 "src/analyzer/Context.pv"
                return type;
            }
            #line 981 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 981 "src/analyzer/Context.pv"
                return type;
            }
            #line 982 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 983 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 984 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 984 "src/analyzer/Context.pv"
                return type;
            }

            #line 986 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 986 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 986 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 987 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 988 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 988 "src/analyzer/Context.pv"
                    return type;
                }
                #line 989 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 992 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 993 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 994 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 996 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 998 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 998 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 999 "src/analyzer/Context.pv"
            struct Token* generic_name = gt->generic->name;
            #line 1000 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 1000 "src/analyzer/Context.pv"
                return type;
            }
            #line 1001 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 1002 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 1004 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 1004 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 1005 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 1005 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 1007 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 1008 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 1009 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 1009 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 1010 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 1010 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 1010 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 1011 "src/analyzer/Context.pv"
                            struct Trait* trait_info = impl_info->trait_;
                            #line 1012 "src/analyzer/Context.pv"
                            if (trait_info == 0) {
                                #line 1012 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 1013 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&trait_info->typedefs, &gt->typedef_name) == 0) {
                                #line 1013 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 1014 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 1015 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 1015 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 1018 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 1022 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 1024 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 1024 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 1025 "src/analyzer/Context.pv"
            struct Token* generic_name = generic->name;
            #line 1026 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 1026 "src/analyzer/Context.pv"
                return type;
            }
            #line 1027 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 1028 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 1030 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 1031 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 1034 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 1035 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 1038 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 1039 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 1040 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 1041 "src/analyzer/Context.pv"
                return type;
            }

            #line 1044 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 1046 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 1047 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 1048 "src/analyzer/Context.pv"
                struct Type* self_type = generics_map->self_type;
                #line 1049 "src/analyzer/Context.pv"
                if (self_type != 0) {
                    #line 1049 "src/analyzer/Context.pv"
                    return self_type;
                }
            }

            #line 1052 "src/analyzer/Context.pv"
            if (fallback_generics_map != 0) {
                #line 1053 "src/analyzer/Context.pv"
                struct Type* fallback_self_type = fallback_generics_map->self_type;
                #line 1054 "src/analyzer/Context.pv"
                if (fallback_self_type != 0) {
                    #line 1054 "src/analyzer/Context.pv"
                    return fallback_self_type;
                }
                #line 1055 "src/analyzer/Context.pv"
                return type;
            }

            #line 1058 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 1060 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 1063 "src/analyzer/Context.pv"
    return type;
}

#line 1066 "src/analyzer/Context.pv"
struct Type* Context__get_path_narrowing(struct Context* self, struct str path) {
    #line 1067 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 1067 "src/analyzer/Context.pv"
        return 0;
    }

    #line 1069 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 1069 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 1069 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 1070 "src/analyzer/Context.pv"
        struct Type* t = HashMap_str_Type__find(&scope->values, &path);
        #line 1071 "src/analyzer/Context.pv"
        if (t != 0) {
            #line 1071 "src/analyzer/Context.pv"
            return t;
        }
    } }

    #line 1074 "src/analyzer/Context.pv"
    return 0;
}

#line 1077 "src/analyzer/Context.pv"
void Context__set_narrowed(struct Context* self, struct str name, struct Type* type) {
    #line 1078 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 1079 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 1079 "src/analyzer/Context.pv"
        return;
    }
    #line 1081 "src/analyzer/Context.pv"
    struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
    #line 1082 "src/analyzer/Context.pv"
    if (existing != 0 && HashMap_str_Type__find(&scope->narrow_originals, &name) == 0) {
        #line 1083 "src/analyzer/Context.pv"
        HashMap_str_Type__insert(&scope->narrow_originals, name, *existing);
    }
    #line 1085 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name, *type);
}

#line 1088 "src/analyzer/Context.pv"
struct Type* Context__get_broadened_type(struct Context* self, struct str name) {
    #line 1089 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 1089 "src/analyzer/Context.pv"
        return 0;
    }
    #line 1090 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 1090 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 1090 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 1091 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 1092 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 1092 "src/analyzer/Context.pv"
            return type;
        }
    } }
    #line 1094 "src/analyzer/Context.pv"
    return 0;
}

#line 1097 "src/analyzer/Context.pv"
bool Context__broaden_if_narrowed(struct Context* self, struct str name) {
    #line 1098 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 1098 "src/analyzer/Context.pv"
        return false;
    }
    #line 1099 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 1100 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 1101 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 1102 "src/analyzer/Context.pv"
        struct Type* original = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 1103 "src/analyzer/Context.pv"
        if (original != 0) {
            #line 1104 "src/analyzer/Context.pv"
            struct Type original_type = *original;
            #line 1105 "src/analyzer/Context.pv"
            HashMap_str_Type__remove(&scope->narrow_originals, &name);
            #line 1106 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, original_type);
            #line 1107 "src/analyzer/Context.pv"
            return true;
        }
        #line 1109 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 1111 "src/analyzer/Context.pv"
    return false;
}

#line 1114 "src/analyzer/Context.pv"
bool Context__update_value_type(struct Context* self, struct str name, struct Type* type) {
    #line 1115 "src/analyzer/Context.pv"
    if (usize__Eq_usize__eq(self->scopes.length, 0)) {
        #line 1115 "src/analyzer/Context.pv"
        return false;
    }
    #line 1116 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 1117 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 1118 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 1119 "src/analyzer/Context.pv"
        struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
        #line 1120 "src/analyzer/Context.pv"
        if (existing != 0) {
            #line 1121 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, *type);
            #line 1122 "src/analyzer/Context.pv"
            return true;
        }

        #line 1125 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 1127 "src/analyzer/Context.pv"
    return false;
}

#line 1130 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 1131 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 1132 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 1132 "src/analyzer/Context.pv"
        return false;
    }

    #line 1134 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(&scope->values, &name->value) != 0) {
        #line 1135 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 1136 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 1137 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 1138 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 1139 "src/analyzer/Context.pv"
        return false;
    }

    #line 1142 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name->value, *type);
    #line 1143 "src/analyzer/Context.pv"
    HashMap_str_ref_Token__insert(&scope->definition_tokens, name->value, name);
    #line 1144 "src/analyzer/Context.pv"
    Context__record_completion(self, name, type, 6);

    #line 1146 "src/analyzer/Context.pv"
    return true;
}

#line 1149 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 1150 "src/analyzer/Context.pv"
    if (self->scopes.length > 0) {
        #line 1151 "src/analyzer/Context.pv"
        struct Scope* scope_front = self->scopes.data;
        #line 1152 "src/analyzer/Context.pv"
        struct Scope* scope = Array_Scope__back(&self->scopes);

        #line 1154 "src/analyzer/Context.pv"
        while (scope != 0 && scope >= scope_front) {
            #line 1155 "src/analyzer/Context.pv"
            struct Type* type = HashMap_str_Type__find(&scope->values, &name);
            #line 1156 "src/analyzer/Context.pv"
            if (type != 0) {
                #line 1156 "src/analyzer/Context.pv"
                return type;
            }

            #line 1158 "src/analyzer/Context.pv"
            scope = scope - 1;
        }
    }

    #line 1162 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 1163 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 1163 "src/analyzer/Context.pv"
        return func;
    }

    #line 1165 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 1168 "src/analyzer/Context.pv"
struct Token* Context__get_definition_token(struct Context* self, struct str name) {
    #line 1169 "src/analyzer/Context.pv"
    if (self->scopes.length > 0) {
        #line 1170 "src/analyzer/Context.pv"
        struct Scope* scope_front = self->scopes.data;
        #line 1171 "src/analyzer/Context.pv"
        struct Scope* scope = Array_Scope__back(&self->scopes);

        #line 1173 "src/analyzer/Context.pv"
        while (scope != 0 && scope >= scope_front) {
            #line 1174 "src/analyzer/Context.pv"
            struct Token** token = HashMap_str_ref_Token__find(&scope->definition_tokens, &name);
            #line 1175 "src/analyzer/Context.pv"
            if (token != 0) {
                #line 1175 "src/analyzer/Context.pv"
                return *token;
            }
            #line 1176 "src/analyzer/Context.pv"
            scope = scope - 1;
        }
    }

    #line 1180 "src/analyzer/Context.pv"
    return 0;
}

#line 1183 "src/analyzer/Context.pv"
bool Context__should_record_symbols(struct Context* self) {
    #line 1184 "src/analyzer/Context.pv"
    return self->analysis->collect_symbols;
}

#line 1187 "src/analyzer/Context.pv"
void Context__record_symbol(struct Context* self, struct Token* token, struct str type_label, struct str def_path, struct Token* def_token) {
    #line 1188 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1188 "src/analyzer/Context.pv"
        return;
    }

    #line 1190 "src/analyzer/Context.pv"
    struct HashMap_str_Array_SymbolInfo* symbols = &self->analysis->symbol_info;
    #line 1191 "src/analyzer/Context.pv"
    struct Array_SymbolInfo* file_symbols = HashMap_str_Array_SymbolInfo__find(symbols, &self->path);
    #line 1192 "src/analyzer/Context.pv"
    if (file_symbols == 0) {
        #line 1192 "src/analyzer/Context.pv"
        file_symbols = HashMap_str_Array_SymbolInfo__insert(symbols, self->path, Array_SymbolInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1193 "src/analyzer/Context.pv"
    if (file_symbols == 0) {
        #line 1193 "src/analyzer/Context.pv"
        return;
    }

    #line 1195 "src/analyzer/Context.pv"
    struct Position def_position = (struct Position) { .line = 0, .character = 0 };
    #line 1196 "src/analyzer/Context.pv"
    if (def_token != 0) {
        #line 1197 "src/analyzer/Context.pv"
        def_position = (struct Position) { .line = def_token->start_line, .character = def_token->start_column };
    }

    #line 1200 "src/analyzer/Context.pv"
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

#line 1211 "src/analyzer/Context.pv"
void Context__record_signature(struct Context* self, struct Token* open_paren, struct Token* close_paren, struct Array_Position comma_positions, struct str label, struct Array_str parameters) {
    #line 1212 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1212 "src/analyzer/Context.pv"
        return;
    }

    #line 1214 "src/analyzer/Context.pv"
    struct HashMap_str_Array_SignatureInfo* sigs = &self->analysis->signature_info;
    #line 1215 "src/analyzer/Context.pv"
    struct Array_SignatureInfo* file_sigs = HashMap_str_Array_SignatureInfo__find(sigs, &self->path);
    #line 1216 "src/analyzer/Context.pv"
    if (file_sigs == 0) {
        #line 1216 "src/analyzer/Context.pv"
        file_sigs = HashMap_str_Array_SignatureInfo__insert(sigs, self->path, Array_SignatureInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1217 "src/analyzer/Context.pv"
    if (file_sigs == 0) {
        #line 1217 "src/analyzer/Context.pv"
        return;
    }

    #line 1219 "src/analyzer/Context.pv"
    Array_SignatureInfo__append(file_sigs, (struct SignatureInfo) {
        .open_paren = (struct Position) { .line = open_paren->start_line, .character = open_paren->start_column },
        .close_paren = (struct Position) { .line = close_paren->end_line, .character = close_paren->end_column },
        .comma_positions = comma_positions,
        .label = label,
        .parameters = parameters,
    });
}

#line 1228 "src/analyzer/Context.pv"
void Context__record_completion(struct Context* self, struct Token* name, struct Type* type, uintptr_t kind) {
    #line 1229 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1229 "src/analyzer/Context.pv"
        return;
    }

    #line 1231 "src/analyzer/Context.pv"
    struct Function* function = self->function;
    #line 1232 "src/analyzer/Context.pv"
    if (function == 0) {
        #line 1232 "src/analyzer/Context.pv"
        return;
    }
    #line 1233 "src/analyzer/Context.pv"
    if (function->token_start >= self->length || usize__Eq_usize__eq(function->token_end, 0) || function->token_end > self->length) {
        #line 1233 "src/analyzer/Context.pv"
        return;
    }

    #line 1235 "src/analyzer/Context.pv"
    struct HashMap_str_Array_CompletionInfo* items = &self->analysis->completion_info;
    #line 1236 "src/analyzer/Context.pv"
    struct Array_CompletionInfo* file_items = HashMap_str_Array_CompletionInfo__find(items, &self->path);
    #line 1237 "src/analyzer/Context.pv"
    if (file_items == 0) {
        #line 1237 "src/analyzer/Context.pv"
        file_items = HashMap_str_Array_CompletionInfo__insert(items, self->path, Array_CompletionInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1238 "src/analyzer/Context.pv"
    if (file_items == 0) {
        #line 1238 "src/analyzer/Context.pv"
        return;
    }

    #line 1240 "src/analyzer/Context.pv"
    struct String type_label = Naming__get_type_decl(&self->root->naming_decl, type, self->type_self, 0);
    #line 1241 "src/analyzer/Context.pv"
    struct Token* first = &self->tokens[function->token_start];
    #line 1242 "src/analyzer/Context.pv"
    struct Token* last = &self->tokens[function->token_end - 1];

    #line 1244 "src/analyzer/Context.pv"
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

#line 1256 "src/analyzer/Context.pv"
void Context__record_member_completion(struct Context* self, struct Token* dot, struct Type* receiver_type, bool is_static) {
    #line 1257 "src/analyzer/Context.pv"
    if (!self->analysis->collect_symbols) {
        #line 1257 "src/analyzer/Context.pv"
        return;
    }

    #line 1259 "src/analyzer/Context.pv"
    struct HashMap_str_Array_MemberCompletionInfo* infos = &self->analysis->member_completion_info;
    #line 1260 "src/analyzer/Context.pv"
    struct Array_MemberCompletionInfo* file_infos = HashMap_str_Array_MemberCompletionInfo__find(infos, &self->path);
    #line 1261 "src/analyzer/Context.pv"
    if (file_infos == 0) {
        #line 1261 "src/analyzer/Context.pv"
        file_infos = HashMap_str_Array_MemberCompletionInfo__insert(infos, self->path, Array_MemberCompletionInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 1262 "src/analyzer/Context.pv"
    if (file_infos == 0) {
        #line 1262 "src/analyzer/Context.pv"
        return;
    }

    #line 1264 "src/analyzer/Context.pv"
    struct Type* resolved_type = receiver_type;
    #line 1265 "src/analyzer/Context.pv"
    switch (receiver_type->type) {
        #line 1266 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 1267 "src/analyzer/Context.pv"
            if (self->type_self != 0 && !Type__is_self(self->type_self)) {
                #line 1268 "src/analyzer/Context.pv"
                resolved_type = self->type_self;
            }
        } break;
        #line 1271 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 1271 "src/analyzer/Context.pv"
            struct Indirect* indirect = receiver_type->indirect_value;
            #line 1272 "src/analyzer/Context.pv"
            switch (indirect->to.type) {
                #line 1273 "src/analyzer/Context.pv"
                case TYPE__SELF: {
                    #line 1274 "src/analyzer/Context.pv"
                    if (self->type_self != 0 && !Type__is_self(self->type_self)) {
                        #line 1275 "src/analyzer/Context.pv"
                        resolved_type = self->type_self;
                    }
                } break;
                #line 1278 "src/analyzer/Context.pv"
                default: {
                } break;
            }
        } break;
        #line 1281 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 1284 "src/analyzer/Context.pv"
    Array_MemberCompletionInfo__append(file_infos, (struct MemberCompletionInfo) {
        .dot_position = (struct Position) { .line = dot->start_line, .character = dot->start_column },
        .receiver_type = *resolved_type,
        .is_static = is_static,
    });
}

#line 1291 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 1292 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 1294 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 1294 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 1296 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 1297 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 1299 "src/analyzer/Context.pv"
        if (Context__check_const_generic_argument(self)) {
            #line 1300 "src/analyzer/Context.pv"
            if (!Context__parse_const_generic_argument(self, &child_type, generics)) {
                #line 1300 "src/analyzer/Context.pv"
                return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
            }
        } else {
            #line 1302 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 1302 "src/analyzer/Context.pv"
                return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
            }
        }

        #line 1305 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 1307 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 1308 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 1309 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 1313 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 1316 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 1317 "src/analyzer/Context.pv"
    struct GenericMap usage_map = GenericMap__new(self->allocator, generics, usage_types);
    #line 1318 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 1319 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 1320 "src/analyzer/Context.pv"
        struct Generic* generic = &generics->array.data[i];
        #line 1321 "src/analyzer/Context.pv"
        struct Type* usage_type = &usage_types->data[i];

        #line 1323 "src/analyzer/Context.pv"
        bool is_const_argument = false;
        #line 1324 "src/analyzer/Context.pv"
        switch (usage_type->type) {
            #line 1325 "src/analyzer/Context.pv"
            case TYPE__CONST: {
                #line 1325 "src/analyzer/Context.pv"
                is_const_argument = true;
            } break;
            #line 1326 "src/analyzer/Context.pv"
            case TYPE__GENERIC: {
                #line 1326 "src/analyzer/Context.pv"
                struct Generic* argument_generic = usage_type->generic_value;
                #line 1326 "src/analyzer/Context.pv"
                is_const_argument = Generic__is_const(argument_generic);
            } break;
            #line 1327 "src/analyzer/Context.pv"
            default: {
            } break;
        }

        #line 1330 "src/analyzer/Context.pv"
        if (Generic__is_const(generic) && !is_const_argument) {
            #line 1331 "src/analyzer/Context.pv"
            Context__error(self, "Expected a constant value for this const generic parameter");
            #line 1332 "src/analyzer/Context.pv"
            return false;
        }

        #line 1335 "src/analyzer/Context.pv"
        if (!Generic__is_const(generic) && is_const_argument) {
            #line 1336 "src/analyzer/Context.pv"
            Context__error(self, "Expected a type for this generic parameter, not a constant value");
            #line 1337 "src/analyzer/Context.pv"
            return false;
        }

        #line 1340 "src/analyzer/Context.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&generic->traits);
        #line 1340 "src/analyzer/Context.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 1340 "src/analyzer/Context.pv"
            struct Type* required_trait = Iter_ref_Type__value(&__iter);

            #line 1341 "src/analyzer/Context.pv"
            struct Type* resolved_required_trait = Context__resolve_type(self->allocator, required_trait, &usage_map, 0);
            #line 1342 "src/analyzer/Context.pv"
            if (resolved_required_trait == 0) {
                #line 1342 "src/analyzer/Context.pv"
                return false;
            }
            #line 1343 "src/analyzer/Context.pv"
            bool implements = false;
            #line 1344 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 1345 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 1345 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 1346 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 1346 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1346 "src/analyzer/Context.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1347 "src/analyzer/Context.pv"
                        if (Type__eq(&impl_info->trait_type, resolved_required_trait)) {
                            #line 1347 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1350 "src/analyzer/Context.pv"
                case TYPE__ENUM: {
                    #line 1350 "src/analyzer/Context.pv"
                    struct Enum* enum_info = usage_type->enum_value._0;
                    #line 1351 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 1351 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1351 "src/analyzer/Context.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1352 "src/analyzer/Context.pv"
                        if (Type__eq(&impl_info->trait_type, resolved_required_trait)) {
                            #line 1352 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1355 "src/analyzer/Context.pv"
                case TYPE__PRIMITIVE: {
                    #line 1355 "src/analyzer/Context.pv"
                    struct Primitive* primitive_info = usage_type->primitive_value;
                    #line 1356 "src/analyzer/Context.pv"
                    if (primitive_info != 0) {
                        #line 1357 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
                        #line 1357 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 1357 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 1358 "src/analyzer/Context.pv"
                            if (Type__eq(&impl_info->trait_type, resolved_required_trait)) {
                                #line 1358 "src/analyzer/Context.pv"
                                implements = true;
                            }
                        } }
                    }
                } break;
                #line 1362 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 1362 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 1363 "src/analyzer/Context.pv"
                    { struct Iter_ref_Type __iter = Array_Type__iter(&generic_info->traits);
                    #line 1363 "src/analyzer/Context.pv"
                    while (Iter_ref_Type__next(&__iter)) {
                        #line 1363 "src/analyzer/Context.pv"
                        struct Type* generic_trait = Iter_ref_Type__value(&__iter);

                        #line 1364 "src/analyzer/Context.pv"
                        if (Type__eq(generic_trait, resolved_required_trait)) {
                            #line 1364 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1367 "src/analyzer/Context.pv"
                default: {
                    #line 1367 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 1369 "src/analyzer/Context.pv"
            if (!implements) {
                #line 1370 "src/analyzer/Context.pv"
                struct Token* name = 0;
                #line 1371 "src/analyzer/Context.pv"
                switch (resolved_required_trait->type) {
                    #line 1372 "src/analyzer/Context.pv"
                    case TYPE__TRAIT: {
                        #line 1372 "src/analyzer/Context.pv"
                        struct Trait* trait_info = resolved_required_trait->trait_value._0;
                        #line 1372 "src/analyzer/Context.pv"
                        name = trait_info->name;
                    } break;
                    #line 1373 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
                #line 1375 "src/analyzer/Context.pv"
                if (name == 0) {
                    #line 1376 "src/analyzer/Context.pv"
                    Context__error(self, "Type does not implement required trait");
                    #line 1377 "src/analyzer/Context.pv"
                    return false;
                }

                #line 1380 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 1381 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 1382 "src/analyzer/Context.pv"
                String__append(&message, name->value);
                #line 1383 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 1384 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 1385 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 1389 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 1391 "src/analyzer/Context.pv"
    return true;
}
