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
#include <analyzer/c/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/EnumC.h>
#include <std/Array_Type.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/types/Enum.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/types/Tuple.h>
#include <std/Array_ref_Trait.h>
#include <std/Iter_ref_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/GenericTypedef.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/types/Struct.h>
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
        uintptr_t result = 0;

        #line 436 "src/analyzer/Context.pv"
        if (Context__check(self, TOKEN_TYPE__IDENTIFIER)) {
            #line 437 "src/analyzer/Context.pv"
            struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 438 "src/analyzer/Context.pv"
            if (name == 0) {
                #line 438 "src/analyzer/Context.pv"
                return false;
            }

            #line 440 "src/analyzer/Context.pv"
            if (!Context__check_value(self, TOKEN_TYPE__SYMBOL, "::")) {
                #line 441 "src/analyzer/Context.pv"
                int64_t* macro_value = Module__find_macro_value(self->module, name->value);
                #line 442 "src/analyzer/Context.pv"
                if (macro_value != 0) {
                    #line 443 "src/analyzer/Context.pv"
                    if (*macro_value < 0) {
                        #line 444 "src/analyzer/Context.pv"
                        Context__error_token(self, name, "Array length from C macro must be non-negative");
                        #line 445 "src/analyzer/Context.pv"
                        return false;
                    }
                    #line 447 "src/analyzer/Context.pv"
                    result = *macro_value;
                    #line 448 "src/analyzer/Context.pv"
                    sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
                    #line 449 "src/analyzer/Context.pv"
                    *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
                    #line 450 "src/analyzer/Context.pv"
                    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 450 "src/analyzer/Context.pv"
                        return false;
                    }
                    #line 451 "src/analyzer/Context.pv"
                    return true;
                }

                #line 454 "src/analyzer/Context.pv"
                struct Type* value_type = Module__find_value(self->module, name->value);
                #line 455 "src/analyzer/Context.pv"
                if (value_type == 0) {
                    #line 456 "src/analyzer/Context.pv"
                    Context__error_token(self, name, "Unknown value in array length");
                    #line 457 "src/analyzer/Context.pv"
                    return false;
                }
                #line 459 "src/analyzer/Context.pv"
                switch (value_type->type) {
                    #line 460 "src/analyzer/Context.pv"
                    case TYPE__ENUM_C: {
                        #line 460 "src/analyzer/Context.pv"
                        struct EnumC* enum_info = value_type->enumc_value;
                        #line 461 "src/analyzer/Context.pv"
                        struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &name->value);
                        #line 462 "src/analyzer/Context.pv"
                        if (variant == 0) {
                            #line 463 "src/analyzer/Context.pv"
                            Context__error_token(self, name, "C enum variant not found");
                            #line 464 "src/analyzer/Context.pv"
                            return false;
                        }
                        #line 466 "src/analyzer/Context.pv"
                        if (variant->value < 0) {
                            #line 467 "src/analyzer/Context.pv"
                            Context__error_token(self, name, "Array length from C enum variant must be non-negative");
                            #line 468 "src/analyzer/Context.pv"
                            return false;
                        }
                        #line 470 "src/analyzer/Context.pv"
                        result = variant->value;
                    } break;
                    #line 472 "src/analyzer/Context.pv"
                    default: {
                        #line 473 "src/analyzer/Context.pv"
                        Context__error_token(self, name, "Array length value must be a C enum constant or integer macro");
                        #line 474 "src/analyzer/Context.pv"
                        return false;
                    } break;
                }
                #line 477 "src/analyzer/Context.pv"
                sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
                #line 478 "src/analyzer/Context.pv"
                *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
                #line 479 "src/analyzer/Context.pv"
                if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 479 "src/analyzer/Context.pv"
                    return false;
                }
                #line 480 "src/analyzer/Context.pv"
                return true;
            }

            #line 483 "src/analyzer/Context.pv"
            struct Type* type_lookup = HashMap_str_Type__find(&self->types, &name->value);
            #line 484 "src/analyzer/Context.pv"
            if (type_lookup == 0) {
                #line 485 "src/analyzer/Context.pv"
                struct Array_Type empty_generics = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 486 "src/analyzer/Context.pv"
                type_lookup = Module__find_make_type(self->module, name->value, &empty_generics);
            }
            #line 488 "src/analyzer/Context.pv"
            if (type_lookup == 0) {
                #line 489 "src/analyzer/Context.pv"
                Context__error_token(self, name, "Unknown type in array length");
                #line 490 "src/analyzer/Context.pv"
                return false;
            }

            #line 493 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
                #line 493 "src/analyzer/Context.pv"
                return false;
            }

            #line 495 "src/analyzer/Context.pv"
            struct Token* variant_token = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 496 "src/analyzer/Context.pv"
            if (variant_token == 0) {
                #line 496 "src/analyzer/Context.pv"
                return false;
            }

            #line 498 "src/analyzer/Context.pv"
            switch (type_lookup->type) {
                #line 499 "src/analyzer/Context.pv"
                case TYPE__ENUM: {
                    #line 499 "src/analyzer/Context.pv"
                    struct Enum* enum_info = type_lookup->enum_value._0;
                    #line 500 "src/analyzer/Context.pv"
                    bool found = false;
                    #line 501 "src/analyzer/Context.pv"
                    uintptr_t current = 0;
                    #line 502 "src/analyzer/Context.pv"
                    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
                    #line 502 "src/analyzer/Context.pv"
                    while (HashMapIter_str_EnumVariant__next(&__iter)) {
                        #line 502 "src/analyzer/Context.pv"
                        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                        #line 503 "src/analyzer/Context.pv"
                        if (variant->value != 0) {
                            #line 504 "src/analyzer/Context.pv"
                            Context__error_token(self, variant_token, "Array length from enum with explicit variant values is not supported");
                            #line 505 "src/analyzer/Context.pv"
                            return false;
                        }
                        #line 507 "src/analyzer/Context.pv"
                        if (str__Eq_str__eq(&variant->name->value, variant_token->value)) {
                            #line 508 "src/analyzer/Context.pv"
                            result = current;
                            #line 509 "src/analyzer/Context.pv"
                            found = true;
                            #line 510 "src/analyzer/Context.pv"
                            break;
                        }
                        #line 512 "src/analyzer/Context.pv"
                        current += 1;
                    } }
                    #line 514 "src/analyzer/Context.pv"
                    if (!found) {
                        #line 515 "src/analyzer/Context.pv"
                        Context__error_token(self, variant_token, "Variant not found in enum");
                        #line 516 "src/analyzer/Context.pv"
                        return false;
                    }
                } break;
                #line 519 "src/analyzer/Context.pv"
                case TYPE__ENUM_C: {
                    #line 519 "src/analyzer/Context.pv"
                    struct EnumC* enum_info = type_lookup->enumc_value;
                    #line 520 "src/analyzer/Context.pv"
                    struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &variant_token->value);
                    #line 521 "src/analyzer/Context.pv"
                    if (variant == 0) {
                        #line 522 "src/analyzer/Context.pv"
                        Context__error_token(self, variant_token, "Variant not found in C enum");
                        #line 523 "src/analyzer/Context.pv"
                        return false;
                    }
                    #line 525 "src/analyzer/Context.pv"
                    if (variant->value < 0) {
                        #line 526 "src/analyzer/Context.pv"
                        Context__error_token(self, variant_token, "Array length from C enum variant must be non-negative");
                        #line 527 "src/analyzer/Context.pv"
                        return false;
                    }
                    #line 529 "src/analyzer/Context.pv"
                    result = variant->value;
                } break;
                #line 531 "src/analyzer/Context.pv"
                default: {
                    #line 532 "src/analyzer/Context.pv"
                    Context__error_token(self, name, "Array length identifier must reference an enum");
                    #line 533 "src/analyzer/Context.pv"
                    return false;
                } break;
            }
        } else {
            #line 537 "src/analyzer/Context.pv"
            struct Token* length = Context__expect(self, TOKEN_TYPE__NUMBER);
            #line 538 "src/analyzer/Context.pv"
            if (length == 0) {
                #line 538 "src/analyzer/Context.pv"
                return false;
            }

            #line 540 "src/analyzer/Context.pv"
            int32_t i = 0;
            #line 541 "src/analyzer/Context.pv"
            while (i < length->value.length) {
                #line 542 "src/analyzer/Context.pv"
                char c = length->value.ptr[i];

                #line 544 "src/analyzer/Context.pv"
                if (c >= '0' && c <= '9') {
                    #line 545 "src/analyzer/Context.pv"
                    result = result * 10 + (c - '0');
                } else {
                    #line 547 "src/analyzer/Context.pv"
                    break;
                }

                #line 550 "src/analyzer/Context.pv"
                i += 1;
            }

            #line 553 "src/analyzer/Context.pv"
            if (i != length->value.length) {
                #line 554 "src/analyzer/Context.pv"
                Context__error_token(self, length, "Fixed array length must be a standard positive integer");
            }
        }

        #line 558 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
        #line 559 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 561 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 561 "src/analyzer/Context.pv"
            return false;
        }

        #line 563 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 565 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 566 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 568 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 569 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 571 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 571 "src/analyzer/Context.pv"
                return false;
            }

            #line 573 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 575 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 576 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 577 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 581 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 582 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 584 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 585 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 586 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});

        #line 588 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 588 "src/analyzer/Context.pv"
            return false;
        }

        #line 590 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 592 "src/analyzer/Context.pv"
        return true;
    }

    #line 595 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 596 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 596 "src/analyzer/Context.pv"
        return false;
    }

    #line 598 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 599 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 600 "src/analyzer/Context.pv"
        return true;
    }

    #line 603 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 605 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 606 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 607 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 609 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 610 "src/analyzer/Context.pv"
                return false;
            }

            #line 613 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 615 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 616 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 617 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 622 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 623 "src/analyzer/Context.pv"
        struct Generic* generic_ref = Generics__find(generics, name->value);

        #line 625 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 626 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 627 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 627 "src/analyzer/Context.pv"
                return false;
            }

            #line 629 "src/analyzer/Context.pv"
            bool found = false;
            #line 630 "src/analyzer/Context.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_ref->traits);
            #line 630 "src/analyzer/Context.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 630 "src/analyzer/Context.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 631 "src/analyzer/Context.pv"
                if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                    #line 631 "src/analyzer/Context.pv"
                    found = true;
                }
            } }
            #line 633 "src/analyzer/Context.pv"
            if (!found) {
                #line 634 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 635 "src/analyzer/Context.pv"
                return false;
            }

            #line 638 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 639 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 640 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 641 "src/analyzer/Context.pv"
            return true;
        }

        #line 644 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 645 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 646 "src/analyzer/Context.pv"
        return true;
    }

    #line 649 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 650 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 651 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 652 "src/analyzer/Context.pv"
        return true;
    }

    #line 655 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 656 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 657 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 658 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 659 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 660 "src/analyzer/Context.pv"
        return false;
    }

    #line 663 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 664 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 664 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 665 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 667 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 670 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 671 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 671 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 672 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 672 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 674 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 674 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 675 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 675 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 677 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 677 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 678 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 678 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 680 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 683 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 684 "src/analyzer/Context.pv"
    return true;
}

#line 687 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 688 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 690 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 690 "src/analyzer/Context.pv"
        return false;
    }

    #line 692 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 693 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 693 "src/analyzer/Context.pv"
        return false;
    }

    #line 695 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 696 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 697 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 698 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 699 "src/analyzer/Context.pv"
        return true;
    }

    #line 702 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 703 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 703 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 704 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 706 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 706 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 707 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 709 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 712 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 714 "src/analyzer/Context.pv"
    return true;
}

#line 717 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 718 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 720 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 721 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 722 "src/analyzer/Context.pv"
        return true;
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
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 732 "src/analyzer/Context.pv"
        return true;
    }

    #line 735 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 736 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 736 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 737 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 739 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 742 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 743 "src/analyzer/Context.pv"
    return true;
}

#line 746 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 747 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 748 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 748 "src/analyzer/Context.pv"
        return false;
    }

    #line 750 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value);
    #line 751 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 752 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 753 "src/analyzer/Context.pv"
        return false;
    }

    #line 756 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 758 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 759 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 760 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 762 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 763 "src/analyzer/Context.pv"
                return false;
            }

            #line 766 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 768 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 769 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 770 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 775 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 777 "src/analyzer/Context.pv"
    return true;
}

#line 780 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 781 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 783 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 784 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 785 "src/analyzer/Context.pv"
        return 0;
    }

    #line 788 "src/analyzer/Context.pv"
    return result;
}

#line 791 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 792 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 793 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 793 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 794 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map),
            }});

            #line 799 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 801 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 801 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 802 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = sequence->type,
                .element = *Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map),
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 807 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 809 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 811 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 811 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 812 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 814 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 814 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 814 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 815 "src/analyzer/Context.pv"
                *element = *Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
            } }

            #line 818 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 820 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 821 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 823 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 823 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 823 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 824 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 826 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 826 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 826 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 827 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 830 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 831 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 832 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 834 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 836 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 836 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 836 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 837 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 838 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 840 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 840 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 840 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 841 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 844 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 845 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 846 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 848 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 850 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 850 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 850 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 851 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 852 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 854 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 854 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 854 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 855 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 858 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 859 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 860 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 862 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 864 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 864 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 864 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 865 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 865 "src/analyzer/Context.pv"
                return type;
            }
            #line 866 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 867 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 869 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 869 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 869 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 870 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 873 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 874 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 875 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 877 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 879 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 879 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 880 "src/analyzer/Context.pv"
            struct str name = gt->generic->name->value;
            #line 881 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 883 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 883 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 884 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 884 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 886 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 887 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 888 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 888 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 889 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 889 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 889 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 890 "src/analyzer/Context.pv"
                            if (impl_info->trait_ == 0) {
                                #line 890 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 891 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&impl_info->trait_->typedefs, &gt->typedef_name) == 0) {
                                #line 891 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 892 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 893 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 893 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 896 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 900 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 902 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 902 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 903 "src/analyzer/Context.pv"
            struct str name = generic->name->value;
            #line 904 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 906 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 907 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 910 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 911 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 914 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 915 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 916 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 917 "src/analyzer/Context.pv"
                return type;
            }

            #line 920 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 922 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 923 "src/analyzer/Context.pv"
            if (generics_map->self_type != 0) {
                #line 924 "src/analyzer/Context.pv"
                return generics_map->self_type;
            } else if (fallback_generics_map != 0 && fallback_generics_map->self_type != 0) {
                #line 926 "src/analyzer/Context.pv"
                return fallback_generics_map->self_type;
            } else {
                #line 928 "src/analyzer/Context.pv"
                return type;
            }
        } break;
        #line 931 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 934 "src/analyzer/Context.pv"
    return type;
}

#line 937 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 938 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 939 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 941 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &name->value) != 0) {
        #line 942 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 943 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 944 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 945 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 946 "src/analyzer/Context.pv"
        return false;
    }

    #line 949 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(values, name->value, *type);

    #line 951 "src/analyzer/Context.pv"
    return true;
}

#line 954 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 955 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 956 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);

    #line 958 "src/analyzer/Context.pv"
    while (scope >= scope_front) {
        #line 959 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->values, &name);
        #line 960 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 960 "src/analyzer/Context.pv"
            return type;
        }

        #line 962 "src/analyzer/Context.pv"
        scope -= 1;
    }

    #line 965 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 966 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 966 "src/analyzer/Context.pv"
        return func;
    }

    #line 968 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 971 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 972 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 974 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 974 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 974 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 975 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 977 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 978 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 978 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 978 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 979 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 984 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 987 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 988 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 990 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 990 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 990 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 991 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 993 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 994 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 994 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 994 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 995 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 998 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 998 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 1002 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 1005 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 1006 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 1008 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 1008 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 1010 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 1011 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 1013 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 1013 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }

        #line 1015 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 1017 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 1018 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 1019 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 1023 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 1026 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 1027 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 1028 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 1029 "src/analyzer/Context.pv"
        struct Generic* generic = &generics->array.data[i];
        #line 1030 "src/analyzer/Context.pv"
        struct Type* usage_type = &usage_types->data[i];

        #line 1032 "src/analyzer/Context.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 1032 "src/analyzer/Context.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 1032 "src/analyzer/Context.pv"
            struct Trait* required_trait = *Iter_ref_ref_Trait__value(&__iter);

            #line 1033 "src/analyzer/Context.pv"
            bool implements = false;
            #line 1034 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 1035 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 1035 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 1036 "src/analyzer/Context.pv"
                    implements = HashMap_str_tuple_ref_Trait_ref_Type__find(&struct_info->traits, &required_trait->name->value) != 0;
                } break;
                #line 1038 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 1038 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 1039 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_info->traits);
                    #line 1039 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Trait__next(&__iter)) {
                        #line 1039 "src/analyzer/Context.pv"
                        struct Trait* generic_trait = *Iter_ref_ref_Trait__value(&__iter);

                        #line 1040 "src/analyzer/Context.pv"
                        if (generic_trait == required_trait) {
                            #line 1040 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1043 "src/analyzer/Context.pv"
                default: {
                    #line 1043 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 1045 "src/analyzer/Context.pv"
            if (!implements) {
                #line 1046 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 1047 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 1048 "src/analyzer/Context.pv"
                String__append(&message, required_trait->name->value);
                #line 1049 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 1050 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 1051 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 1055 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 1057 "src/analyzer/Context.pv"
    return true;
}
