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
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>
#include <analyzer/Position.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/Block.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Tuple.h>
#include <std/Array_Type.h>
#include <std/Array_ref_Trait.h>
#include <std/Iter_ref_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/GenericTypedef.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Enum.h>
#include <analyzer/c/ClassCpp.h>
#include <std/Iter_ref_Type.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/String.h>
#include <std/Array_DeferStatement.h>
#include <std/Iter_ref_Scope.h>
#include <std/Iter_ref_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/Context.h>

#include <analyzer/Context.h>

#line 30 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module) {
    #line 31 "src/analyzer/Context.pv"
    struct Type type_char = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(module, (struct str){ .ptr = "char", .length = strlen("char") }) };
    #line 32 "src/analyzer/Context.pv"
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

    #line 51 "src/analyzer/Context.pv"
    if (tokens != 0) {
        #line 52 "src/analyzer/Context.pv"
        self.tokens = tokens->data;
        #line 53 "src/analyzer/Context.pv"
        self.length = tokens->length;
    }

    #line 56 "src/analyzer/Context.pv"
    self.type_self = &self.root->type_self;

    #line 58 "src/analyzer/Context.pv"
    struct Token* param_name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "value", .length = strlen("value") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 60 "src/analyzer/Context.pv"
    Context__push_scope(&self, 0);

    #line 62 "src/analyzer/Context.pv"
    struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 63 "src/analyzer/Context.pv"
    t.name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 65 "src/analyzer/Context.pv"
    struct Generic u = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 66 "src/analyzer/Context.pv"
    u.name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "U", .length = strlen("U") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 68 "src/analyzer/Context.pv"
    struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 69 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, t);
    #line 70 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, u);
    #line 71 "src/analyzer/Context.pv"
    struct Generic* generic_t = Array_Generic__get(&generics, 0);
    #line 72 "src/analyzer/Context.pv"
    struct Generic* generic_u = Array_Generic__get(&generics, 1);

    #line 74 "src/analyzer/Context.pv"
    struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 75 "src/analyzer/Context.pv"
    Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_u } });

    #line 77 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "cast", &generics, &params, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t });

    #line 79 "src/analyzer/Context.pv"
    struct Array_Generic generics2 = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 80 "src/analyzer/Context.pv"
    Array_Generic__append(&generics2, t);
    #line 81 "src/analyzer/Context.pv"
    struct Generic* generic2_t = Array_Generic__get(&generics2, 0);

    #line 83 "src/analyzer/Context.pv"
    struct Array_Parameter params2 = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 84 "src/analyzer/Context.pv"
    Array_Parameter__append(&params2, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic2_t } });
    #line 85 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "sizeof", &generics2, &params2, self.root->type_usize);

    #line 87 "src/analyzer/Context.pv"
    Array_Parameter__release(&params);
    #line 88 "src/analyzer/Context.pv"
    Array_Generic__release(&generics);

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
    struct HashMap_str_Type* values = &scope->values;

    #line 99 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 99 "src/analyzer/Context.pv"
        return true;
    }

    #line 101 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 102 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});
    #line 103 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 104 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 106 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 107 "src/analyzer/Context.pv"
        { struct Iter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 107 "src/analyzer/Context.pv"
        while (Iter_ref_Generic__next(&__iter)) {
            #line 107 "src/analyzer/Context.pv"
            struct Generic generic = *Iter_ref_Generic__value(&__iter);

            #line 108 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 109 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic.name->value, index);
        } }
    }

    #line 113 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 114 "src/analyzer/Context.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 114 "src/analyzer/Context.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 114 "src/analyzer/Context.pv"
            struct Parameter param = *Iter_ref_Parameter__value(&__iter);

            #line 115 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 119 "src/analyzer/Context.pv"
    struct GenericMap generic_map_val = GenericMap__from_generics(self->allocator, &func_info.generics);
    #line 120 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);

    #line 122 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, &func_info), ._1 = generic_map} };
    #line 123 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 126 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 127 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 128 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 129 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 129 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 131 "src/analyzer/Context.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
        .code = (struct str) { .ptr = 0, .length = 0 },
        .range = (struct Range) {
            .start = (struct Position) {
                .line = token->start_line,
                .character = token->start_column,
            },
            .end = (struct Position) {
                .line = token->end_line,
                .character = token->end_column,
            },
        },
    });
}

#line 147 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 148 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 149 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 150 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 150 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 152 "src/analyzer/Context.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
        .code = value,
        .range = (struct Range) {
            .start = (struct Position) {
                .line = token->start_line,
                .character = token->start_column,
            },
            .end = (struct Position) {
                .line = token->end_line,
                .character = token->end_column,
            },
        },
    });
}

#line 168 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 169 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 171 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 172 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 175 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 177 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 180 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 181 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 182 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 183 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 186 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 187 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 189 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 190 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 193 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 194 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 197 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 198 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 199 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 200 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 203 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 204 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 206 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 207 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 210 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 211 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 214 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 215 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 216 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 217 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 217 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 219 "src/analyzer/Context.pv"
    Array_InlayHint__append(file_inlay_hints, (struct InlayHint) {
        .position = (struct Position) {
            .line = token->end_line,
            .character = token->end_column,
        },
        .label = (struct str){ .ptr = label, .length = strlen(label) },
        .kind = kind,
        .padding_left = padding_left,
        .padding_right = padding_right,
    });
}

#line 231 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 232 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 233 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 234 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 234 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 236 "src/analyzer/Context.pv"
    Array_InlayHint__append(file_inlay_hints, (struct InlayHint) {
        .position = (struct Position) {
            .line = token->start_line,
            .character = token->start_column,
        },
        .label = (struct str){ .ptr = label, .length = strlen(label) },
        .kind = kind,
        .padding_left = padding_left,
        .padding_right = padding_right,
    });
}

#line 248 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 249 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 251 "src/analyzer/Context.pv"
    while (self->pos < self->length && self->tokens[self->pos].type == TOKEN_TYPE__COMMENT) {
        #line 252 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 255 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 258 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 259 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 260 "src/analyzer/Context.pv"
        return 0;
    }

    #line 263 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 266 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 267 "src/analyzer/Context.pv"
    if (self->pos == 0) {
        #line 268 "src/analyzer/Context.pv"
        return 0;
    }

    #line 271 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 274 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 275 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 276 "src/analyzer/Context.pv"
        return false;
    }

    #line 279 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 282 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 283 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 284 "src/analyzer/Context.pv"
        return false;
    }

    #line 287 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 289 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 292 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 293 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 294 "src/analyzer/Context.pv"
    if (check) {
        #line 294 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 295 "src/analyzer/Context.pv"
    return check;
}

#line 298 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 299 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 300 "src/analyzer/Context.pv"
        return 0;
    }

    #line 303 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 305 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 306 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 307 "src/analyzer/Context.pv"
        return token;
    }

    #line 310 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 311 "src/analyzer/Context.pv"
    return 0;
}

#line 314 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 315 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 316 "src/analyzer/Context.pv"
        return false;
    }

    #line 319 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 321 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 322 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 323 "src/analyzer/Context.pv"
        return true;
    }

    #line 326 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 327 "src/analyzer/Context.pv"
    return false;
}

#line 330 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 331 "src/analyzer/Context.pv"
    while (self->pos < self->length && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 332 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 335 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 338 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 339 "src/analyzer/Context.pv"
    while (self->pos < self->length && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 340 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 344 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 345 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 347 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 347 "src/analyzer/Context.pv"
        return false;
    }

    #line 349 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 351 "src/analyzer/Context.pv"
    while (self->pos < self->length && brackets > 0) {
        #line 352 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 353 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 355 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 358 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 359 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 363 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 365 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 366 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 367 "src/analyzer/Context.pv"
        return false;
    }

    #line 370 "src/analyzer/Context.pv"
    return true;
}

#line 373 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 374 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 375 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 378 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 379 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 382 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 383 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 384 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 385 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 385 "src/analyzer/Context.pv"
            return false;
        }

        #line 387 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 388 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 390 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 391 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 393 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 394 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 396 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 397 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 397 "src/analyzer/Context.pv"
                return false;
            }
            #line 398 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 399 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 401 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 401 "src/analyzer/Context.pv"
                return false;
            }
            #line 402 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 403 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 406 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 408 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 409 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 409 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 411 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = indirect_type, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});

        #line 413 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 414 "src/analyzer/Context.pv"
            return false;
        }

        #line 417 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 418 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 420 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 422 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 422 "src/analyzer/Context.pv"
            return false;
        }
        #line 423 "src/analyzer/Context.pv"
        sequence->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = sequence->element }}) };

        #line 425 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 426 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 427 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 429 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 429 "src/analyzer/Context.pv"
                return false;
            }

            #line 431 "src/analyzer/Context.pv"
            return true;
        }

        #line 434 "src/analyzer/Context.pv"
        struct Token* length = Context__expect(self, TOKEN_TYPE__NUMBER);
        #line 435 "src/analyzer/Context.pv"
        if (length == 0) {
            #line 435 "src/analyzer/Context.pv"
            return false;
        }

        #line 437 "src/analyzer/Context.pv"
        uintptr_t result = 0;

        #line 439 "src/analyzer/Context.pv"
        int32_t i = 0;
        #line 440 "src/analyzer/Context.pv"
        while (i < length->value.length) {
            #line 441 "src/analyzer/Context.pv"
            char c = length->value.ptr[i];

            #line 443 "src/analyzer/Context.pv"
            if (c >= '0' && c <= '9') {
                #line 444 "src/analyzer/Context.pv"
                result = result * 10 + (c - '0');
            } else {
                #line 446 "src/analyzer/Context.pv"
                break;
            }

            #line 449 "src/analyzer/Context.pv"
            i += 1;
        }

        #line 452 "src/analyzer/Context.pv"
        if (i != length->value.length) {
            #line 453 "src/analyzer/Context.pv"
            Context__error_token(self, length, "Fixed array length must be a standard positive integer");
        }

        #line 456 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
        #line 457 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 459 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 459 "src/analyzer/Context.pv"
            return false;
        }

        #line 461 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 463 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 464 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 466 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 467 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 469 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 469 "src/analyzer/Context.pv"
                return false;
            }

            #line 471 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 473 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 474 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 475 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 479 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 480 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 482 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 483 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 484 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});

        #line 486 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 486 "src/analyzer/Context.pv"
            return false;
        }

        #line 488 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 490 "src/analyzer/Context.pv"
        return true;
    }

    #line 493 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 494 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 494 "src/analyzer/Context.pv"
        return false;
    }

    #line 496 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 497 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 498 "src/analyzer/Context.pv"
        return true;
    }

    #line 501 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 503 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 504 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 505 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 507 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 508 "src/analyzer/Context.pv"
                return false;
            }

            #line 511 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 513 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 514 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 515 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 520 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 521 "src/analyzer/Context.pv"
        struct Generic* generic_ref = Generics__find(generics, name->value);

        #line 523 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 524 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 525 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 525 "src/analyzer/Context.pv"
                return false;
            }

            #line 527 "src/analyzer/Context.pv"
            bool found = false;
            #line 528 "src/analyzer/Context.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_ref->traits);
            #line 528 "src/analyzer/Context.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 528 "src/analyzer/Context.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 529 "src/analyzer/Context.pv"
                if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                    #line 529 "src/analyzer/Context.pv"
                    found = true;
                }
            } }
            #line 531 "src/analyzer/Context.pv"
            if (!found) {
                #line 532 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 533 "src/analyzer/Context.pv"
                return false;
            }

            #line 536 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 537 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 538 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 539 "src/analyzer/Context.pv"
            return true;
        }

        #line 542 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 543 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 544 "src/analyzer/Context.pv"
        return true;
    }

    #line 547 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 548 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 549 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 550 "src/analyzer/Context.pv"
        return true;
    }

    #line 553 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 554 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 555 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 556 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 557 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 558 "src/analyzer/Context.pv"
        return false;
    }

    #line 561 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 562 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 562 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 563 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 565 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 568 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 569 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 569 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 570 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 570 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 572 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 572 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 573 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 573 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 575 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 575 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 576 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 576 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 578 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 581 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 582 "src/analyzer/Context.pv"
    return true;
}

#line 585 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 586 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 588 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 588 "src/analyzer/Context.pv"
        return false;
    }

    #line 590 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 591 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 591 "src/analyzer/Context.pv"
        return false;
    }

    #line 593 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 594 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 595 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 596 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 597 "src/analyzer/Context.pv"
        return true;
    }

    #line 600 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 601 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 601 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 602 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 604 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 604 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 605 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 607 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 610 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 612 "src/analyzer/Context.pv"
    return true;
}

#line 615 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 616 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 618 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 619 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 620 "src/analyzer/Context.pv"
        return true;
    }

    #line 623 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 624 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 624 "src/analyzer/Context.pv"
        return false;
    }

    #line 626 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 627 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 628 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 629 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 630 "src/analyzer/Context.pv"
        return true;
    }

    #line 633 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 634 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 634 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 635 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 637 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 640 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 641 "src/analyzer/Context.pv"
    return true;
}

#line 644 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 645 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 646 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 646 "src/analyzer/Context.pv"
        return false;
    }

    #line 648 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value);
    #line 649 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 650 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 651 "src/analyzer/Context.pv"
        return false;
    }

    #line 654 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 656 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 657 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 658 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 660 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 661 "src/analyzer/Context.pv"
                return false;
            }

            #line 664 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 666 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 667 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 668 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 673 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 675 "src/analyzer/Context.pv"
    return true;
}

#line 678 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 679 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 681 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 682 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 683 "src/analyzer/Context.pv"
        return 0;
    }

    #line 686 "src/analyzer/Context.pv"
    return result;
}

#line 689 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 690 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 691 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 691 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 692 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map),
            }});

            #line 697 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 699 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 699 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 700 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = sequence->type,
                .element = *Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map),
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 705 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 707 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 709 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 709 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 710 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 712 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 712 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 712 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 713 "src/analyzer/Context.pv"
                *element = *Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
            } }

            #line 716 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 718 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 719 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 721 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 721 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 721 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 722 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 724 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 724 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 724 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 725 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 728 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 729 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 730 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 732 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 734 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 734 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 734 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 735 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 736 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 738 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 738 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 738 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 739 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 742 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 743 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 744 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 746 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 748 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 748 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 748 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 749 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 750 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 752 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 752 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 752 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 753 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 756 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 757 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 758 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 760 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 762 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 762 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 762 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 763 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 763 "src/analyzer/Context.pv"
                return type;
            }
            #line 764 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 765 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 767 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 767 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 767 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 768 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 771 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 772 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 773 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 775 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 777 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 777 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 778 "src/analyzer/Context.pv"
            struct str name = gt->generic->name->value;
            #line 779 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 781 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 781 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 782 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 782 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 784 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 785 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 786 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 786 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 787 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 787 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 787 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 788 "src/analyzer/Context.pv"
                            if (impl_info->trait_ == 0) {
                                #line 788 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 789 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&impl_info->trait_->typedefs, &gt->typedef_name) == 0) {
                                #line 789 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 790 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 791 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 791 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 794 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 798 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 800 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 800 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 801 "src/analyzer/Context.pv"
            struct str name = generic->name->value;
            #line 802 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 804 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 805 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 808 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 809 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 812 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 813 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 814 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 815 "src/analyzer/Context.pv"
                return type;
            }

            #line 818 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 820 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 821 "src/analyzer/Context.pv"
            if (generics_map->self_type != 0) {
                #line 822 "src/analyzer/Context.pv"
                return generics_map->self_type;
            } else if (fallback_generics_map != 0 && fallback_generics_map->self_type != 0) {
                #line 824 "src/analyzer/Context.pv"
                return fallback_generics_map->self_type;
            } else {
                #line 826 "src/analyzer/Context.pv"
                return type;
            }
        } break;
        #line 829 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 832 "src/analyzer/Context.pv"
    return type;
}

#line 835 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 836 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 837 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 839 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &name->value) != 0) {
        #line 840 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 841 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 842 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 843 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 844 "src/analyzer/Context.pv"
        return false;
    }

    #line 847 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(values, name->value, *type);

    #line 849 "src/analyzer/Context.pv"
    return true;
}

#line 852 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 853 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 854 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);

    #line 856 "src/analyzer/Context.pv"
    while (scope >= scope_front) {
        #line 857 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->values, &name);
        #line 858 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 858 "src/analyzer/Context.pv"
            return type;
        }

        #line 860 "src/analyzer/Context.pv"
        scope -= 1;
    }

    #line 863 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 864 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 864 "src/analyzer/Context.pv"
        return func;
    }

    #line 866 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 869 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 870 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 872 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 872 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 872 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 873 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 875 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 876 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 876 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 876 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 877 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 882 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 885 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 886 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 888 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 888 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 888 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 889 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 891 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 892 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 892 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 892 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 893 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 896 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 896 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 900 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 903 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 904 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 906 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 906 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 908 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 909 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 911 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 911 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }

        #line 913 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 915 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 916 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 917 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 921 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 924 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 925 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 926 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 927 "src/analyzer/Context.pv"
        struct Generic* generic = generics->array.data + i;
        #line 928 "src/analyzer/Context.pv"
        struct Type* usage_type = usage_types->data + i;

        #line 930 "src/analyzer/Context.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 930 "src/analyzer/Context.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 930 "src/analyzer/Context.pv"
            struct Trait* required_trait = *Iter_ref_ref_Trait__value(&__iter);

            #line 931 "src/analyzer/Context.pv"
            bool implements = false;
            #line 932 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 933 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 933 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 934 "src/analyzer/Context.pv"
                    implements = HashMap_str_tuple_ref_Trait_ref_Type__find(&struct_info->traits, &required_trait->name->value) != 0;
                } break;
                #line 936 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 936 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 937 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_info->traits);
                    #line 937 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Trait__next(&__iter)) {
                        #line 937 "src/analyzer/Context.pv"
                        struct Trait* generic_trait = *Iter_ref_ref_Trait__value(&__iter);

                        #line 938 "src/analyzer/Context.pv"
                        if (generic_trait == required_trait) {
                            #line 938 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 941 "src/analyzer/Context.pv"
                default: {
                    #line 941 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 943 "src/analyzer/Context.pv"
            if (!implements) {
                #line 944 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 945 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 946 "src/analyzer/Context.pv"
                String__append(&message, required_trait->name->value);
                #line 947 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 948 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 949 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 953 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 955 "src/analyzer/Context.pv"
    return true;
}
