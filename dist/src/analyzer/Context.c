#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <analyzer/Context.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Analysis.h>
#include <analyzer/Module.h>
#include <std/trait_Allocator.h>
#include <analyzer/Root.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Type.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <analyzer/types/Primitive.h>
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

#line 29 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module) {
    #line 30 "src/analyzer/Context.pv"
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
        .pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } },
        .function = 0,
    };

    #line 48 "src/analyzer/Context.pv"
    if (tokens != 0) {
        #line 49 "src/analyzer/Context.pv"
        self.tokens = tokens->data;
        #line 50 "src/analyzer/Context.pv"
        self.length = tokens->length;
    }

    #line 53 "src/analyzer/Context.pv"
    self.type_self = &self.root->type_self;
    #line 54 "src/analyzer/Context.pv"
    self.pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(module, (struct str){ .ptr = "char", .length = strlen("char") }) } };

    #line 56 "src/analyzer/Context.pv"
    struct Token* param_name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "value", .length = strlen("value") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 58 "src/analyzer/Context.pv"
    Context__push_scope(&self, 0);

    #line 60 "src/analyzer/Context.pv"
    struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 61 "src/analyzer/Context.pv"
    t.name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 63 "src/analyzer/Context.pv"
    struct Generic u = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 64 "src/analyzer/Context.pv"
    u.name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "U", .length = strlen("U") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

    #line 66 "src/analyzer/Context.pv"
    struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 67 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, t);
    #line 68 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, u);
    #line 69 "src/analyzer/Context.pv"
    struct Generic* generic_t = Array_Generic__get(&generics, 0);
    #line 70 "src/analyzer/Context.pv"
    struct Generic* generic_u = Array_Generic__get(&generics, 1);

    #line 72 "src/analyzer/Context.pv"
    struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 73 "src/analyzer/Context.pv"
    Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_u } });

    #line 75 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "cast", &generics, &params, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t });

    #line 77 "src/analyzer/Context.pv"
    struct Array_Generic generics2 = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 78 "src/analyzer/Context.pv"
    Array_Generic__append(&generics2, t);
    #line 79 "src/analyzer/Context.pv"
    struct Generic* generic2_t = Array_Generic__get(&generics2, 0);

    #line 81 "src/analyzer/Context.pv"
    struct Array_Parameter params2 = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 82 "src/analyzer/Context.pv"
    Array_Parameter__append(&params2, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic2_t } });
    #line 83 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "sizeof", &generics2, &params2, self.root->type_usize);

    #line 85 "src/analyzer/Context.pv"
    Array_Parameter__release(&params);
    #line 86 "src/analyzer/Context.pv"
    Array_Generic__release(&generics);

    #line 88 "src/analyzer/Context.pv"
    HashMap_str_bool__insert(&analysis->files, path, true);

    #line 90 "src/analyzer/Context.pv"
    return self;
}

#line 93 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type) {
    #line 94 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 95 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 97 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 97 "src/analyzer/Context.pv"
        return true;
    }

    #line 99 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 100 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});
    #line 101 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 102 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 104 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 105 "src/analyzer/Context.pv"
        { struct Iter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 105 "src/analyzer/Context.pv"
        while (Iter_ref_Generic__next(&__iter)) {
            #line 105 "src/analyzer/Context.pv"
            struct Generic generic = *Iter_ref_Generic__value(&__iter);

            #line 106 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 107 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic.name->value, index);
        } }
    }

    #line 111 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 112 "src/analyzer/Context.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 112 "src/analyzer/Context.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 112 "src/analyzer/Context.pv"
            struct Parameter param = *Iter_ref_Parameter__value(&__iter);

            #line 113 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 117 "src/analyzer/Context.pv"
    struct GenericMap generic_map_val = GenericMap__from_generics(self->allocator, &func_info.generics);
    #line 118 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);

    #line 120 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, &func_info), ._1 = generic_map} };
    #line 121 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 124 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 125 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 126 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 127 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 127 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 129 "src/analyzer/Context.pv"
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

#line 145 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 146 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 147 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 148 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 148 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 150 "src/analyzer/Context.pv"
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

#line 166 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 167 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 169 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 170 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 173 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 175 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 178 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 179 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 180 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 181 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 184 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 185 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 187 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 188 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 191 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 192 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 195 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 196 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 197 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 198 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 201 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 202 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 204 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 205 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 208 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 209 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 212 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 213 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 214 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 215 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 215 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 217 "src/analyzer/Context.pv"
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

#line 229 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 230 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 231 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 232 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 232 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 234 "src/analyzer/Context.pv"
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

#line 246 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 247 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 249 "src/analyzer/Context.pv"
    while (self->pos < self->length && self->tokens[self->pos].type == TOKEN_TYPE__COMMENT) {
        #line 250 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 253 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 256 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 257 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 258 "src/analyzer/Context.pv"
        return 0;
    }

    #line 261 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 264 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 265 "src/analyzer/Context.pv"
    if (self->pos == 0) {
        #line 266 "src/analyzer/Context.pv"
        return 0;
    }

    #line 269 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 272 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 273 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 274 "src/analyzer/Context.pv"
        return false;
    }

    #line 277 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 280 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 281 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 282 "src/analyzer/Context.pv"
        return false;
    }

    #line 285 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 287 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 290 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 291 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 292 "src/analyzer/Context.pv"
    if (check) {
        #line 292 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 293 "src/analyzer/Context.pv"
    return check;
}

#line 296 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 297 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 298 "src/analyzer/Context.pv"
        return 0;
    }

    #line 301 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 303 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 304 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 305 "src/analyzer/Context.pv"
        return token;
    }

    #line 308 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 309 "src/analyzer/Context.pv"
    return 0;
}

#line 312 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 313 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 314 "src/analyzer/Context.pv"
        return false;
    }

    #line 317 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 319 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 320 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 321 "src/analyzer/Context.pv"
        return true;
    }

    #line 324 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 325 "src/analyzer/Context.pv"
    return false;
}

#line 328 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 329 "src/analyzer/Context.pv"
    while (self->pos < self->length && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 330 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 333 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 336 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 337 "src/analyzer/Context.pv"
    while (self->pos < self->length && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 338 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 342 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 343 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 345 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 345 "src/analyzer/Context.pv"
        return false;
    }

    #line 347 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 349 "src/analyzer/Context.pv"
    while (self->pos < self->length && brackets > 0) {
        #line 350 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 351 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 353 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 356 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 357 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 361 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 363 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 364 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 365 "src/analyzer/Context.pv"
        return false;
    }

    #line 368 "src/analyzer/Context.pv"
    return true;
}

#line 371 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 372 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 373 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 376 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 377 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 380 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 381 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 382 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 383 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 383 "src/analyzer/Context.pv"
            return false;
        }

        #line 385 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 386 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 388 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 389 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 391 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 392 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 394 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 395 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 395 "src/analyzer/Context.pv"
                return false;
            }
            #line 396 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 397 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 399 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 399 "src/analyzer/Context.pv"
                return false;
            }
            #line 400 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 401 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 404 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 406 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 407 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 407 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 409 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = indirect_type, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});

        #line 411 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 412 "src/analyzer/Context.pv"
            return false;
        }

        #line 415 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 416 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 418 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 420 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 420 "src/analyzer/Context.pv"
            return false;
        }
        #line 421 "src/analyzer/Context.pv"
        sequence->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = sequence->element }}) };

        #line 423 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 424 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 425 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 427 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 427 "src/analyzer/Context.pv"
                return false;
            }

            #line 429 "src/analyzer/Context.pv"
            return true;
        }

        #line 432 "src/analyzer/Context.pv"
        struct Token* length = Context__expect(self, TOKEN_TYPE__NUMBER);
        #line 433 "src/analyzer/Context.pv"
        if (length == 0) {
            #line 433 "src/analyzer/Context.pv"
            return false;
        }

        #line 435 "src/analyzer/Context.pv"
        uintptr_t result = 0;

        #line 437 "src/analyzer/Context.pv"
        int32_t i = 0;
        #line 438 "src/analyzer/Context.pv"
        while (i < length->value.length) {
            #line 439 "src/analyzer/Context.pv"
            char c = length->value.ptr[i];

            #line 441 "src/analyzer/Context.pv"
            if (c >= '0' && c <= '9') {
                #line 442 "src/analyzer/Context.pv"
                result = result * 10 + (c - '0');
            } else {
                #line 444 "src/analyzer/Context.pv"
                break;
            }

            #line 447 "src/analyzer/Context.pv"
            i += 1;
        }

        #line 450 "src/analyzer/Context.pv"
        if (i != length->value.length) {
            #line 451 "src/analyzer/Context.pv"
            Context__error_token(self, length, "Fixed array length must be a standard positive integer");
        }

        #line 454 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
        #line 455 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 457 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 457 "src/analyzer/Context.pv"
            return false;
        }

        #line 459 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 461 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 462 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 464 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 465 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 467 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 467 "src/analyzer/Context.pv"
                return false;
            }

            #line 469 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 471 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 472 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 473 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 477 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 478 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 480 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 481 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 482 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});

        #line 484 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 484 "src/analyzer/Context.pv"
            return false;
        }

        #line 486 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 488 "src/analyzer/Context.pv"
        return true;
    }

    #line 491 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 492 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 492 "src/analyzer/Context.pv"
        return false;
    }

    #line 494 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 495 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 496 "src/analyzer/Context.pv"
        return true;
    }

    #line 499 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 501 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 502 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 503 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 505 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 506 "src/analyzer/Context.pv"
                return false;
            }

            #line 509 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 511 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 512 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 513 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 518 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 519 "src/analyzer/Context.pv"
        struct Generic* generic_ref = Generics__find(generics, name->value);

        #line 521 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 522 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 523 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 523 "src/analyzer/Context.pv"
                return false;
            }

            #line 525 "src/analyzer/Context.pv"
            bool found = false;
            #line 526 "src/analyzer/Context.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_ref->traits);
            #line 526 "src/analyzer/Context.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 526 "src/analyzer/Context.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 527 "src/analyzer/Context.pv"
                if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                    #line 527 "src/analyzer/Context.pv"
                    found = true;
                }
            } }
            #line 529 "src/analyzer/Context.pv"
            if (!found) {
                #line 530 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 531 "src/analyzer/Context.pv"
                return false;
            }

            #line 534 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 535 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 536 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 537 "src/analyzer/Context.pv"
            return true;
        }

        #line 540 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 541 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 542 "src/analyzer/Context.pv"
        return true;
    }

    #line 545 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 546 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 547 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 548 "src/analyzer/Context.pv"
        return true;
    }

    #line 551 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 552 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 553 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 554 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 555 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 556 "src/analyzer/Context.pv"
        return false;
    }

    #line 559 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 560 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 560 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 561 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 563 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 566 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 567 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 567 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 568 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 568 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 570 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 570 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 571 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 571 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 573 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 573 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 574 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 574 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 576 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 579 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 580 "src/analyzer/Context.pv"
    return true;
}

#line 583 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 584 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 586 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 586 "src/analyzer/Context.pv"
        return false;
    }

    #line 588 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 589 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 589 "src/analyzer/Context.pv"
        return false;
    }

    #line 591 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 592 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 593 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 594 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 595 "src/analyzer/Context.pv"
        return true;
    }

    #line 598 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 599 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 599 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 600 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 602 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 602 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 603 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 605 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 608 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 610 "src/analyzer/Context.pv"
    return true;
}

#line 613 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 614 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 616 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 617 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 618 "src/analyzer/Context.pv"
        return true;
    }

    #line 621 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 622 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 622 "src/analyzer/Context.pv"
        return false;
    }

    #line 624 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 625 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 626 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 627 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 628 "src/analyzer/Context.pv"
        return true;
    }

    #line 631 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 632 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 632 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 633 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 635 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 638 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 639 "src/analyzer/Context.pv"
    return true;
}

#line 642 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 643 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 644 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 644 "src/analyzer/Context.pv"
        return false;
    }

    #line 646 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value);
    #line 647 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 648 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 649 "src/analyzer/Context.pv"
        return false;
    }

    #line 652 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 654 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 655 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 656 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 658 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 659 "src/analyzer/Context.pv"
                return false;
            }

            #line 662 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 664 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 665 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 666 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 671 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 673 "src/analyzer/Context.pv"
    return true;
}

#line 676 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 677 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 679 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 680 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 681 "src/analyzer/Context.pv"
        return 0;
    }

    #line 684 "src/analyzer/Context.pv"
    return result;
}

#line 687 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 688 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 689 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 689 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 690 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map),
            }});

            #line 695 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 697 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 697 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 698 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = sequence->type,
                .element = *Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map),
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 703 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 705 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 707 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 707 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 708 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 710 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 710 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 710 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 711 "src/analyzer/Context.pv"
                *element = *Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
            } }

            #line 714 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 716 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 717 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 719 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 719 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 719 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 720 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 722 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 722 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 722 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 723 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 726 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 727 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 728 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 730 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 732 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 732 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 732 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 733 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 734 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 736 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 736 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 736 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 737 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 740 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 741 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 742 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 744 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 746 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 746 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 746 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 747 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 748 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 750 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 750 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 750 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 751 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 754 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 755 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 756 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 758 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 760 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 760 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 760 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 761 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 761 "src/analyzer/Context.pv"
                return type;
            }
            #line 762 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 763 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);

            #line 765 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 765 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 765 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 766 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 769 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 770 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 771 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 773 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 775 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 775 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 776 "src/analyzer/Context.pv"
            struct str name = gt->generic->name->value;
            #line 777 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 779 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 779 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 780 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 780 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 782 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 783 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 784 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 784 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 785 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 785 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 785 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 786 "src/analyzer/Context.pv"
                            if (impl_info->trait_ == 0) {
                                #line 786 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 787 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&impl_info->trait_->typedefs, &gt->typedef_name) == 0) {
                                #line 787 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 788 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 789 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 789 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 792 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 796 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 798 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 798 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 799 "src/analyzer/Context.pv"
            struct str name = generic->name->value;
            #line 800 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 802 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 803 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 806 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 807 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 810 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 811 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 812 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 813 "src/analyzer/Context.pv"
                return type;
            }

            #line 816 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 818 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 819 "src/analyzer/Context.pv"
            if (generics_map->self_type != 0) {
                #line 820 "src/analyzer/Context.pv"
                return generics_map->self_type;
            } else if (fallback_generics_map != 0 && fallback_generics_map->self_type != 0) {
                #line 822 "src/analyzer/Context.pv"
                return fallback_generics_map->self_type;
            } else {
                #line 824 "src/analyzer/Context.pv"
                return type;
            }
        } break;
        #line 827 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 830 "src/analyzer/Context.pv"
    return type;
}

#line 833 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 834 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 835 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 837 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &name->value) != 0) {
        #line 838 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 839 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 840 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 841 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 842 "src/analyzer/Context.pv"
        return false;
    }

    #line 845 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(values, name->value, *type);

    #line 847 "src/analyzer/Context.pv"
    return true;
}

#line 850 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 851 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 852 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);

    #line 854 "src/analyzer/Context.pv"
    while (scope >= scope_front) {
        #line 855 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->values, &name);
        #line 856 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 856 "src/analyzer/Context.pv"
            return type;
        }

        #line 858 "src/analyzer/Context.pv"
        scope -= 1;
    }

    #line 861 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 862 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 862 "src/analyzer/Context.pv"
        return func;
    }

    #line 864 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 867 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 868 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 870 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 870 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 870 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 871 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 873 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 874 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 874 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 874 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 875 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 880 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 883 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 884 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 886 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 886 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 886 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 887 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 889 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 890 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 890 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 890 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 891 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 894 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 894 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 898 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 901 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 902 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 904 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 904 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 906 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 907 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 909 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 909 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }

        #line 911 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 913 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 914 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 915 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 919 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 922 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 923 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 924 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 925 "src/analyzer/Context.pv"
        struct Generic* generic = generics->array.data + i;
        #line 926 "src/analyzer/Context.pv"
        struct Type* usage_type = usage_types->data + i;

        #line 928 "src/analyzer/Context.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 928 "src/analyzer/Context.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 928 "src/analyzer/Context.pv"
            struct Trait* required_trait = *Iter_ref_ref_Trait__value(&__iter);

            #line 929 "src/analyzer/Context.pv"
            bool implements = false;
            #line 930 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 931 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 931 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 932 "src/analyzer/Context.pv"
                    implements = HashMap_str_tuple_ref_Trait_ref_Type__find(&struct_info->traits, &required_trait->name->value) != 0;
                } break;
                #line 934 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 934 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 935 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_info->traits);
                    #line 935 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Trait__next(&__iter)) {
                        #line 935 "src/analyzer/Context.pv"
                        struct Trait* generic_trait = *Iter_ref_ref_Trait__value(&__iter);

                        #line 936 "src/analyzer/Context.pv"
                        if (generic_trait == required_trait) {
                            #line 936 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 939 "src/analyzer/Context.pv"
                default: {
                    #line 939 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 941 "src/analyzer/Context.pv"
            if (!implements) {
                #line 942 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 943 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 944 "src/analyzer/Context.pv"
                String__append(&message, required_trait->name->value);
                #line 945 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 946 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 947 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 951 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 953 "src/analyzer/Context.pv"
    return true;
}
