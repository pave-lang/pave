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
#include <analyzer/expression/Expression.h>
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
#include <std/Iter_ref_Scope.h>
#include <std/String.h>
#include <std/Array_DeferStatement.h>
#include <std/Iter_ref_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
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

    #line 88 "src/analyzer/Context.pv"
    Array_Parameter__release(&params);
    #line 89 "src/analyzer/Context.pv"
    Array_Generic__release(&generics);

    #line 91 "src/analyzer/Context.pv"
    HashMap_str_bool__insert(&analysis->files, path, true);

    #line 93 "src/analyzer/Context.pv"
    return self;
}

#line 96 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type) {
    #line 97 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 98 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 98 "src/analyzer/Context.pv"
        return false;
    }
    #line 99 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 101 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 101 "src/analyzer/Context.pv"
        return true;
    }

    #line 103 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 104 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});
    #line 105 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 106 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 108 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 109 "src/analyzer/Context.pv"
        { struct Iter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 109 "src/analyzer/Context.pv"
        while (Iter_ref_Generic__next(&__iter)) {
            #line 109 "src/analyzer/Context.pv"
            struct Generic generic = *Iter_ref_Generic__value(&__iter);

            #line 110 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 111 "src/analyzer/Context.pv"
            struct Token* generic_name = generic.name;
            #line 112 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 112 "src/analyzer/Context.pv"
                return false;
            }
            #line 113 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic_name->value, index);
        } }
    }

    #line 117 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 118 "src/analyzer/Context.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 118 "src/analyzer/Context.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 118 "src/analyzer/Context.pv"
            struct Parameter param = *Iter_ref_Parameter__value(&__iter);

            #line 119 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 123 "src/analyzer/Context.pv"
    struct GenericMap generic_map_val = GenericMap__from_generics(self->allocator, &func_info.generics);
    #line 124 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);

    #line 126 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, &func_info), ._1 = generic_map} };
    #line 127 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 130 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 131 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 132 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 133 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 133 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 134 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 134 "src/analyzer/Context.pv"
        return;
    }

    #line 136 "src/analyzer/Context.pv"
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

#line 152 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 153 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 154 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 155 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 155 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 156 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 156 "src/analyzer/Context.pv"
        return;
    }

    #line 158 "src/analyzer/Context.pv"
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

#line 174 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 175 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 177 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 178 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 181 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 183 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 186 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 187 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 188 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 189 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 192 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 193 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 195 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 196 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 199 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 200 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 203 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 204 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 205 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 206 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 209 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 210 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 212 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 213 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 216 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 217 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 220 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 221 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 222 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 223 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 223 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 224 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 224 "src/analyzer/Context.pv"
        return;
    }

    #line 226 "src/analyzer/Context.pv"
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

#line 238 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 239 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 240 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 241 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 241 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 242 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 242 "src/analyzer/Context.pv"
        return;
    }

    #line 244 "src/analyzer/Context.pv"
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

#line 256 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 257 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 259 "src/analyzer/Context.pv"
    while (self->pos < self->length && self->tokens[self->pos].type == TOKEN_TYPE__COMMENT) {
        #line 260 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 263 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 266 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 267 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 268 "src/analyzer/Context.pv"
        return 0;
    }

    #line 271 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 274 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 275 "src/analyzer/Context.pv"
    if (self->pos == 0) {
        #line 276 "src/analyzer/Context.pv"
        return 0;
    }

    #line 279 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 282 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 283 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 284 "src/analyzer/Context.pv"
        return false;
    }

    #line 287 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 290 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 291 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 292 "src/analyzer/Context.pv"
        return false;
    }

    #line 295 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 297 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 300 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 301 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 302 "src/analyzer/Context.pv"
    if (check) {
        #line 302 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 303 "src/analyzer/Context.pv"
    return check;
}

#line 306 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 307 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 308 "src/analyzer/Context.pv"
        return 0;
    }

    #line 311 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 313 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 314 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 315 "src/analyzer/Context.pv"
        return token;
    }

    #line 318 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 319 "src/analyzer/Context.pv"
    return 0;
}

#line 322 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 323 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 324 "src/analyzer/Context.pv"
        return false;
    }

    #line 327 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 329 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 330 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 331 "src/analyzer/Context.pv"
        return true;
    }

    #line 334 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 335 "src/analyzer/Context.pv"
    return false;
}

#line 338 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 339 "src/analyzer/Context.pv"
    while (self->pos < self->length && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 340 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 343 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 346 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 347 "src/analyzer/Context.pv"
    while (self->pos < self->length && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 348 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 352 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 353 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 355 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 355 "src/analyzer/Context.pv"
        return false;
    }

    #line 357 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 359 "src/analyzer/Context.pv"
    while (self->pos < self->length && brackets > 0) {
        #line 360 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 361 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 363 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 366 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 367 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 371 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 373 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 374 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 375 "src/analyzer/Context.pv"
        return false;
    }

    #line 378 "src/analyzer/Context.pv"
    return true;
}

#line 381 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 382 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 383 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 386 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 387 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 390 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 391 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 392 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 393 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 393 "src/analyzer/Context.pv"
            return false;
        }

        #line 395 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 396 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 398 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 399 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 401 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 402 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 404 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 405 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 405 "src/analyzer/Context.pv"
                return false;
            }
            #line 406 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 407 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 409 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 409 "src/analyzer/Context.pv"
                return false;
            }
            #line 410 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 411 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 414 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 416 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 417 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 417 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 419 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = indirect_type, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
        #line 420 "src/analyzer/Context.pv"
        if (indirect == 0) {
            #line 420 "src/analyzer/Context.pv"
            return false;
        }

        #line 422 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 423 "src/analyzer/Context.pv"
            return false;
        }

        #line 426 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 427 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 429 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 431 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 431 "src/analyzer/Context.pv"
            return false;
        }
        #line 432 "src/analyzer/Context.pv"
        sequence->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = sequence->element }}) };

        #line 434 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 435 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 436 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 438 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 438 "src/analyzer/Context.pv"
                return false;
            }

            #line 440 "src/analyzer/Context.pv"
            return true;
        }

        #line 443 "src/analyzer/Context.pv"
        struct Token* length_token = Context__current(self);
        #line 444 "src/analyzer/Context.pv"
        struct Expression* length_expr = Expression__parse(self, generics);
        #line 445 "src/analyzer/Context.pv"
        if (length_expr == 0) {
            #line 445 "src/analyzer/Context.pv"
            return false;
        }

        #line 447 "src/analyzer/Context.pv"
        if (!Expression__is_const_expression(length_expr, self)) {
            #line 448 "src/analyzer/Context.pv"
            Context__error_token(self, length_token, "Fixed array length must be a compile-time constant integer expression");
            #line 449 "src/analyzer/Context.pv"
            return false;
        }

        #line 452 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = length_expr };
        #line 453 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 455 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 455 "src/analyzer/Context.pv"
            return false;
        }

        #line 457 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 459 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 460 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 462 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 463 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 465 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 465 "src/analyzer/Context.pv"
                return false;
            }

            #line 467 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 469 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 470 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 471 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 475 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 476 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 478 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 479 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 480 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
        #line 481 "src/analyzer/Context.pv"
        if (func_info == 0) {
            #line 481 "src/analyzer/Context.pv"
            return false;
        }
        #line 482 "src/analyzer/Context.pv"
        if (generic_map == 0) {
            #line 482 "src/analyzer/Context.pv"
            return false;
        }

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
        #line 520 "src/analyzer/Context.pv"
        if (generic_ref == 0) {
            #line 520 "src/analyzer/Context.pv"
            return false;
        }

        #line 522 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 523 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 524 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 524 "src/analyzer/Context.pv"
                return false;
            }

            #line 526 "src/analyzer/Context.pv"
            bool found = false;
            #line 527 "src/analyzer/Context.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_ref->traits);
            #line 527 "src/analyzer/Context.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 527 "src/analyzer/Context.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 528 "src/analyzer/Context.pv"
                if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                    #line 528 "src/analyzer/Context.pv"
                    found = true;
                }
            } }
            #line 530 "src/analyzer/Context.pv"
            if (!found) {
                #line 531 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 532 "src/analyzer/Context.pv"
                return false;
            }

            #line 535 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 536 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 537 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 538 "src/analyzer/Context.pv"
            return true;
        }

        #line 541 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 542 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 543 "src/analyzer/Context.pv"
        return true;
    }

    #line 546 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 547 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 548 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 549 "src/analyzer/Context.pv"
        return true;
    }

    #line 552 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 553 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 554 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 555 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 556 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 557 "src/analyzer/Context.pv"
        return false;
    }

    #line 560 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 561 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 561 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 562 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 564 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 567 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 568 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 568 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 569 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 569 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 571 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 571 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 572 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 572 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 574 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 574 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 575 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 575 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 577 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 580 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 581 "src/analyzer/Context.pv"
    return true;
}

#line 584 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 585 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 587 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 587 "src/analyzer/Context.pv"
        return false;
    }

    #line 589 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 590 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 590 "src/analyzer/Context.pv"
        return false;
    }

    #line 592 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 593 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 594 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 595 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 596 "src/analyzer/Context.pv"
        return true;
    }

    #line 599 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 600 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 600 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 601 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 603 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 603 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 604 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 606 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 609 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 611 "src/analyzer/Context.pv"
    return true;
}

#line 614 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 615 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 617 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 618 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 619 "src/analyzer/Context.pv"
        return true;
    }

    #line 622 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 623 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 623 "src/analyzer/Context.pv"
        return false;
    }

    #line 625 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 626 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 627 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 628 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 629 "src/analyzer/Context.pv"
        return true;
    }

    #line 632 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 633 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 633 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 634 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 636 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 639 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 640 "src/analyzer/Context.pv"
    return true;
}

#line 643 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 644 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 645 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 645 "src/analyzer/Context.pv"
        return false;
    }

    #line 647 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 649 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 650 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 651 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 653 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 654 "src/analyzer/Context.pv"
                return false;
            }

            #line 657 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 659 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 660 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 661 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 666 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value, generics_.length);
    #line 667 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 668 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 669 "src/analyzer/Context.pv"
        return false;
    }

    #line 672 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 674 "src/analyzer/Context.pv"
    return true;
}

#line 677 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 678 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 680 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 681 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 682 "src/analyzer/Context.pv"
        return 0;
    }

    #line 685 "src/analyzer/Context.pv"
    return result;
}

#line 688 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 689 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 690 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 690 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 691 "src/analyzer/Context.pv"
            struct Type* resolved_to = Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map);
            #line 692 "src/analyzer/Context.pv"
            if (resolved_to == 0) {
                #line 692 "src/analyzer/Context.pv"
                return type;
            }

            #line 694 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *resolved_to,
            }});
            #line 698 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 698 "src/analyzer/Context.pv"
                return type;
            }

            #line 700 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 702 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 702 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 703 "src/analyzer/Context.pv"
            struct Type* resolved_element = Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map);
            #line 704 "src/analyzer/Context.pv"
            if (resolved_element == 0) {
                #line 704 "src/analyzer/Context.pv"
                return type;
            }

            #line 706 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = sequence->type,
                .element = *resolved_element,
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 711 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 711 "src/analyzer/Context.pv"
                return type;
            }
            #line 712 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 714 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 716 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 716 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 717 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 719 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 719 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 719 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 720 "src/analyzer/Context.pv"
                struct Type* resolved_element = Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
                #line 721 "src/analyzer/Context.pv"
                if (resolved_element == 0) {
                    #line 721 "src/analyzer/Context.pv"
                    return type;
                }
                #line 722 "src/analyzer/Context.pv"
                *element = *resolved_element;
            } }

            #line 725 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 727 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 728 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 730 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 730 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 730 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 731 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 731 "src/analyzer/Context.pv"
                return type;
            }
            #line 732 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 734 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 734 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 734 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 735 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 736 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 736 "src/analyzer/Context.pv"
                    return type;
                }
                #line 737 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 740 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 741 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 742 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 744 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 746 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 746 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 746 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 747 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 747 "src/analyzer/Context.pv"
                return type;
            }
            #line 748 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 749 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 750 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 750 "src/analyzer/Context.pv"
                return type;
            }

            #line 752 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 752 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 752 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 753 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 754 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 754 "src/analyzer/Context.pv"
                    return type;
                }
                #line 755 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 758 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 759 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 760 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 762 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 764 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 764 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 764 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 765 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 765 "src/analyzer/Context.pv"
                return type;
            }
            #line 766 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 767 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 768 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 768 "src/analyzer/Context.pv"
                return type;
            }

            #line 770 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 770 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 770 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 771 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 772 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 772 "src/analyzer/Context.pv"
                    return type;
                }
                #line 773 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 776 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 777 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 778 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 780 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 782 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 782 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 782 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 783 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 783 "src/analyzer/Context.pv"
                return type;
            }
            #line 784 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 784 "src/analyzer/Context.pv"
                return type;
            }
            #line 785 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 786 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 787 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 787 "src/analyzer/Context.pv"
                return type;
            }

            #line 789 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 789 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 789 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 790 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 791 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 791 "src/analyzer/Context.pv"
                    return type;
                }
                #line 792 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 795 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 796 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 797 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 799 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 801 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 801 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 802 "src/analyzer/Context.pv"
            struct Token* generic_name = gt->generic->name;
            #line 803 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 803 "src/analyzer/Context.pv"
                return type;
            }
            #line 804 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 805 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 807 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 807 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 808 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 808 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 810 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 811 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 812 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 812 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 813 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 813 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 813 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 814 "src/analyzer/Context.pv"
                            struct Trait* trait_info = impl_info->trait_;
                            #line 815 "src/analyzer/Context.pv"
                            if (trait_info == 0) {
                                #line 815 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 816 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&trait_info->typedefs, &gt->typedef_name) == 0) {
                                #line 816 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 817 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 818 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 818 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 821 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 825 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 827 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 827 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 828 "src/analyzer/Context.pv"
            struct Token* generic_name = generic->name;
            #line 829 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 829 "src/analyzer/Context.pv"
                return type;
            }
            #line 830 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 831 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 833 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 834 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 837 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 838 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 841 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 842 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 843 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 844 "src/analyzer/Context.pv"
                return type;
            }

            #line 847 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 849 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 850 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 851 "src/analyzer/Context.pv"
                struct Type* self_type = generics_map->self_type;
                #line 852 "src/analyzer/Context.pv"
                if (self_type != 0) {
                    #line 852 "src/analyzer/Context.pv"
                    return self_type;
                }
            }

            #line 855 "src/analyzer/Context.pv"
            if (fallback_generics_map != 0) {
                #line 856 "src/analyzer/Context.pv"
                struct Type* fallback_self_type = fallback_generics_map->self_type;
                #line 857 "src/analyzer/Context.pv"
                if (fallback_self_type != 0) {
                    #line 857 "src/analyzer/Context.pv"
                    return fallback_self_type;
                }
                #line 858 "src/analyzer/Context.pv"
                return type;
            }

            #line 861 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 863 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 866 "src/analyzer/Context.pv"
    return type;
}

#line 869 "src/analyzer/Context.pv"
struct Type* Context__get_path_narrowing(struct Context* self, struct str path) {
    #line 870 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 870 "src/analyzer/Context.pv"
        return 0;
    }

    #line 872 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 872 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 872 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 873 "src/analyzer/Context.pv"
        struct Type* t = HashMap_str_Type__find(&scope->values, &path);
        #line 874 "src/analyzer/Context.pv"
        if (t != 0) {
            #line 874 "src/analyzer/Context.pv"
            return t;
        }
    } }

    #line 877 "src/analyzer/Context.pv"
    return 0;
}

#line 880 "src/analyzer/Context.pv"
void Context__set_narrowed(struct Context* self, struct str name, struct Type* type) {
    #line 881 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 882 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 882 "src/analyzer/Context.pv"
        return;
    }
    #line 884 "src/analyzer/Context.pv"
    struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
    #line 885 "src/analyzer/Context.pv"
    if (existing != 0 && HashMap_str_Type__find(&scope->narrow_originals, &name) == 0) {
        #line 886 "src/analyzer/Context.pv"
        HashMap_str_Type__insert(&scope->narrow_originals, name, *existing);
    }
    #line 888 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name, *type);
}

#line 891 "src/analyzer/Context.pv"
struct Type* Context__get_broadened_type(struct Context* self, struct str name) {
    #line 892 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 892 "src/analyzer/Context.pv"
        return 0;
    }
    #line 893 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 893 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 893 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 894 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 895 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 895 "src/analyzer/Context.pv"
            return type;
        }
    } }
    #line 897 "src/analyzer/Context.pv"
    return 0;
}

#line 900 "src/analyzer/Context.pv"
bool Context__broaden_if_narrowed(struct Context* self, struct str name) {
    #line 901 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 901 "src/analyzer/Context.pv"
        return false;
    }
    #line 902 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 903 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 904 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 905 "src/analyzer/Context.pv"
        struct Type* original = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 906 "src/analyzer/Context.pv"
        if (original != 0) {
            #line 907 "src/analyzer/Context.pv"
            struct Type original_type = *original;
            #line 908 "src/analyzer/Context.pv"
            HashMap_str_Type__remove(&scope->narrow_originals, &name);
            #line 909 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, original_type);
            #line 910 "src/analyzer/Context.pv"
            return true;
        }
        #line 912 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 914 "src/analyzer/Context.pv"
    return false;
}

#line 917 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 918 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 919 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 919 "src/analyzer/Context.pv"
        return false;
    }

    #line 921 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(&scope->values, &name->value) != 0) {
        #line 922 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 923 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 924 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 925 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 926 "src/analyzer/Context.pv"
        return false;
    }

    #line 929 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name->value, *type);

    #line 931 "src/analyzer/Context.pv"
    return true;
}

#line 934 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 935 "src/analyzer/Context.pv"
    if (self->scopes.length > 0) {
        #line 936 "src/analyzer/Context.pv"
        struct Scope* scope_front = self->scopes.data;
        #line 937 "src/analyzer/Context.pv"
        struct Scope* scope = Array_Scope__back(&self->scopes);

        #line 939 "src/analyzer/Context.pv"
        while (scope != 0 && scope >= scope_front) {
            #line 940 "src/analyzer/Context.pv"
            struct Type* type = HashMap_str_Type__find(&scope->values, &name);
            #line 941 "src/analyzer/Context.pv"
            if (type != 0) {
                #line 941 "src/analyzer/Context.pv"
                return type;
            }

            #line 943 "src/analyzer/Context.pv"
            scope = scope - 1;
        }
    }

    #line 947 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 948 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 948 "src/analyzer/Context.pv"
        return func;
    }

    #line 950 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 953 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 954 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 956 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 956 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 956 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 957 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 959 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 960 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 960 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 960 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 961 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 966 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 969 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 970 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 972 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 972 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 972 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 973 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 975 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 976 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 976 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 976 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 977 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 980 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 980 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 984 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 987 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 988 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 990 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 990 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 992 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 993 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 995 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 995 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }

        #line 997 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 999 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 1000 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 1001 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 1005 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 1008 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 1009 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 1010 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 1011 "src/analyzer/Context.pv"
        struct Generic* generic = &generics->array.data[i];
        #line 1012 "src/analyzer/Context.pv"
        struct Type* usage_type = &usage_types->data[i];

        #line 1014 "src/analyzer/Context.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 1014 "src/analyzer/Context.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 1014 "src/analyzer/Context.pv"
            struct Trait* required_trait = *Iter_ref_ref_Trait__value(&__iter);

            #line 1015 "src/analyzer/Context.pv"
            bool implements = false;
            #line 1016 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 1017 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 1017 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 1018 "src/analyzer/Context.pv"
                    struct str trait_key = Trait__get_key(required_trait, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                    #line 1019 "src/analyzer/Context.pv"
                    implements = HashMap_str_tuple_ref_Trait_ref_Type__find(&struct_info->traits, &trait_key) != 0;
                } break;
                #line 1021 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 1021 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 1022 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_info->traits);
                    #line 1022 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Trait__next(&__iter)) {
                        #line 1022 "src/analyzer/Context.pv"
                        struct Trait* generic_trait = *Iter_ref_ref_Trait__value(&__iter);

                        #line 1023 "src/analyzer/Context.pv"
                        if (generic_trait == required_trait) {
                            #line 1023 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1026 "src/analyzer/Context.pv"
                default: {
                    #line 1026 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 1028 "src/analyzer/Context.pv"
            if (!implements) {
                #line 1029 "src/analyzer/Context.pv"
                struct Token* name = required_trait->name;
                #line 1030 "src/analyzer/Context.pv"
                if (name == 0) {
                    #line 1031 "src/analyzer/Context.pv"
                    Context__error(self, "Type does not implement required trait");
                    #line 1032 "src/analyzer/Context.pv"
                    return false;
                }

                #line 1035 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 1036 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 1037 "src/analyzer/Context.pv"
                String__append(&message, name->value);
                #line 1038 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 1039 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 1040 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 1044 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 1046 "src/analyzer/Context.pv"
    return true;
}
