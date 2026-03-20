#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/ArrayIter_ref_DeferStatement.h>
#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <analyzer/Analysis.h>
#include <analyzer/Module.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>
#include <std/Array_Scope.h>
#include <analyzer/Scope.h>
#include <analyzer/Root.h>
#include <stdint.h>
#include <stdbool.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/TokenType.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Generic.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/HashMap_str_bool.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionType.h>
#include <std/ArrayIter_ref_Generic.h>
#include <analyzer/types/Generics.h>
#include <std/HashMap_str_usize.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <analyzer/types/GenericMap.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>
#include <analyzer/Position.h>
#include <analyzer/InlayHintKind.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Tuple.h>
#include <std/Array_Type.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/types/Trait.h>
#include <std/ArrayIter_ref_Type.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Struct.h>
#include <std/String.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/ArrayIter_ref_Scope.h>

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
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .scopes = Array_Scope__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .root = module->root,
    };

    #line 41 "src/analyzer/Context.pv"
    if (tokens != 0) {
        #line 42 "src/analyzer/Context.pv"
        self.tokens = tokens->data;
        #line 43 "src/analyzer/Context.pv"
        self.length = tokens->length;
    }

    #line 46 "src/analyzer/Context.pv"
    self.type_self = &self.root->type_self;
    #line 47 "src/analyzer/Context.pv"
    self.pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(module, "char") } };

    #line 49 "src/analyzer/Context.pv"
    struct Token* param_name = ArenaAllocator__store_Token(allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "value", .length = strlen("value") } });

    #line 51 "src/analyzer/Context.pv"
    Context__push_scope(&self, 0);

    #line 53 "src/analyzer/Context.pv"
    struct Generic t = Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 54 "src/analyzer/Context.pv"
    t.name = ArenaAllocator__store_Token(allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") } });

    #line 56 "src/analyzer/Context.pv"
    struct Generic u = Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 57 "src/analyzer/Context.pv"
    u.name = ArenaAllocator__store_Token(allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "U", .length = strlen("U") } });

    #line 59 "src/analyzer/Context.pv"
    struct Array_Generic generics = Array_Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 60 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, t);
    #line 61 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, u);
    #line 62 "src/analyzer/Context.pv"
    struct Generic* generic_t = Array_Generic__get(&generics, 0);
    #line 63 "src/analyzer/Context.pv"
    struct Generic* generic_u = Array_Generic__get(&generics, 1);

    #line 65 "src/analyzer/Context.pv"
    struct Array_Parameter params = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 66 "src/analyzer/Context.pv"
    Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_u } });

    #line 68 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "cast", &generics, &params, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t });

    #line 70 "src/analyzer/Context.pv"
    struct Array_Generic generics2 = Array_Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 71 "src/analyzer/Context.pv"
    Array_Generic__append(&generics2, t);
    #line 72 "src/analyzer/Context.pv"
    struct Generic* generic2_t = Array_Generic__get(&generics2, 0);

    #line 74 "src/analyzer/Context.pv"
    struct Array_Parameter params2 = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 75 "src/analyzer/Context.pv"
    Array_Parameter__append(&params2, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic2_t } });
    #line 76 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "sizeof", &generics2, &params2, self.root->type_usize);

    #line 78 "src/analyzer/Context.pv"
    Array_Parameter__release(&params);
    #line 79 "src/analyzer/Context.pv"
    Array_Generic__release(&generics);

    #line 81 "src/analyzer/Context.pv"
    HashMap_str_bool__insert(&analysis->files, path, true);

    #line 83 "src/analyzer/Context.pv"
    return self;
}

#line 86 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type) {
    #line 87 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 88 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 90 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 90 "src/analyzer/Context.pv"
        return true;
    }

    #line 92 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 93 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) } });
    #line 94 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 95 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 97 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 98 "src/analyzer/Context.pv"
        { struct ArrayIter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 98 "src/analyzer/Context.pv"
        while (ArrayIter_ref_Generic__next(&__iter)) {
            #line 98 "src/analyzer/Context.pv"
            struct Generic generic = *ArrayIter_ref_Generic__value(&__iter);

            #line 99 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 100 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic.name->value, index);
        } }
    }

    #line 104 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 105 "src/analyzer/Context.pv"
        { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 105 "src/analyzer/Context.pv"
        while (ArrayIter_ref_Parameter__next(&__iter)) {
            #line 105 "src/analyzer/Context.pv"
            struct Parameter param = *ArrayIter_ref_Parameter__value(&__iter);

            #line 106 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 110 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, GenericMap__from_generics(self->allocator, &func_info.generics));

    #line 112 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, func_info), ._1 = generic_map} };
    #line 113 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 116 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 117 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 118 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 119 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 119 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 121 "src/analyzer/Context.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
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

#line 136 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 137 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 138 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 139 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 139 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 141 "src/analyzer/Context.pv"
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

#line 157 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 158 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 160 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 161 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 164 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 166 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 169 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 170 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 171 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 172 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 175 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 176 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 178 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 179 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 182 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 183 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 186 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 187 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 188 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 189 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 192 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
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
    Context__error_token_expected_value(self, token, type, value);
}

#line 203 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 204 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 205 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 206 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 206 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 208 "src/analyzer/Context.pv"
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

#line 220 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 221 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 223 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && (self->tokens[self->pos].type == TOKEN_TYPE__COMMENT)) {
        #line 224 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 227 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 230 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 231 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 232 "src/analyzer/Context.pv"
        return 0;
    }

    #line 235 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 238 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 239 "src/analyzer/Context.pv"
    if (self->pos == 0) {
        #line 240 "src/analyzer/Context.pv"
        return 0;
    }

    #line 243 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 246 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 247 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 248 "src/analyzer/Context.pv"
        return false;
    }

    #line 251 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 254 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 255 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 256 "src/analyzer/Context.pv"
        return false;
    }

    #line 259 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 261 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 264 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 265 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 266 "src/analyzer/Context.pv"
    if (check) {
        #line 266 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 267 "src/analyzer/Context.pv"
    return check;
}

#line 270 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 271 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 272 "src/analyzer/Context.pv"
        return 0;
    }

    #line 275 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 277 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 278 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 279 "src/analyzer/Context.pv"
        return token;
    }

    #line 282 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 283 "src/analyzer/Context.pv"
    return 0;
}

#line 286 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 287 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 288 "src/analyzer/Context.pv"
        return false;
    }

    #line 291 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 293 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 294 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 295 "src/analyzer/Context.pv"
        return true;
    }

    #line 298 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 299 "src/analyzer/Context.pv"
    return false;
}

#line 302 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 303 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 304 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 307 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 310 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 311 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 312 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 316 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 317 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 319 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 319 "src/analyzer/Context.pv"
        return false;
    }

    #line 321 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 323 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && (brackets > 0)) {
        #line 324 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 325 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 327 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 330 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 331 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 335 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 337 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 338 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 339 "src/analyzer/Context.pv"
        return false;
    }

    #line 342 "src/analyzer/Context.pv"
    return true;
}

#line 345 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 346 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 347 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 350 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 351 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 354 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 355 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 356 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 357 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 357 "src/analyzer/Context.pv"
            return false;
        }

        #line 359 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 360 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 362 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 363 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 365 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 366 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 368 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 369 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 369 "src/analyzer/Context.pv"
                return false;
            }
            #line 370 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 371 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 373 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 373 "src/analyzer/Context.pv"
                return false;
            }
            #line 374 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 375 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 378 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 380 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 381 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 381 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 383 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = indirect_type });

        #line 385 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 386 "src/analyzer/Context.pv"
            return false;
        }

        #line 389 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 390 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 392 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 394 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 394 "src/analyzer/Context.pv"
            return false;
        }

        #line 396 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 397 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 398 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 400 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 400 "src/analyzer/Context.pv"
                return false;
            }

            #line 402 "src/analyzer/Context.pv"
            return true;
        }

        #line 405 "src/analyzer/Context.pv"
        struct Token* length = Context__expect(self, TOKEN_TYPE__NUMBER);
        #line 406 "src/analyzer/Context.pv"
        if (!length) {
            #line 406 "src/analyzer/Context.pv"
            return false;
        }

        #line 408 "src/analyzer/Context.pv"
        uintptr_t result = 0;

        #line 410 "src/analyzer/Context.pv"
        int32_t i = 0;
        #line 411 "src/analyzer/Context.pv"
        while (i < length->value.length) {
            #line 412 "src/analyzer/Context.pv"
            char c = length->value.ptr[i];

            #line 414 "src/analyzer/Context.pv"
            if (c >= '0' && c <= '9') {
                #line 415 "src/analyzer/Context.pv"
                result = result * 10 + (c - '0');
            } else {
                #line 417 "src/analyzer/Context.pv"
                break;
            }

            #line 420 "src/analyzer/Context.pv"
            i += 1;
        }

        #line 423 "src/analyzer/Context.pv"
        if (i != length->value.length) {
            #line 424 "src/analyzer/Context.pv"
            Context__error_token(self, length, "Fixed array length must be a standard positive integer");
        }

        #line 427 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
        #line 428 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 430 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 430 "src/analyzer/Context.pv"
            return false;
        }

        #line 432 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 434 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 435 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 437 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 438 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 440 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 440 "src/analyzer/Context.pv"
                return false;
            }

            #line 442 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 444 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 445 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 446 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 450 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 451 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 453 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, Function__new(self));
        #line 454 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) { .self_type = self->type_self });

        #line 456 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 456 "src/analyzer/Context.pv"
            return false;
        }

        #line 458 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 460 "src/analyzer/Context.pv"
        return true;
    }

    #line 463 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 464 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 464 "src/analyzer/Context.pv"
        return false;
    }

    #line 466 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 467 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 468 "src/analyzer/Context.pv"
        return true;
    }

    #line 471 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 473 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 474 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 475 "src/analyzer/Context.pv"
            struct Type child_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

            #line 477 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 478 "src/analyzer/Context.pv"
                return false;
            }

            #line 481 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 483 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 484 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 485 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 490 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 491 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = Generics__find(generics, name->value) };
        #line 492 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 493 "src/analyzer/Context.pv"
        return true;
    }

    #line 496 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 497 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 498 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 499 "src/analyzer/Context.pv"
        return true;
    }

    #line 502 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 503 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 504 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 505 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN, .unknown_value = { ._0 = name->value, ._1 = generics_} };
        #line 506 "src/analyzer/Context.pv"
        return false;
    }

    #line 509 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 510 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 510 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 511 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 513 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 516 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 517 "src/analyzer/Context.pv"
    return true;
}

#line 520 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 521 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 523 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 523 "src/analyzer/Context.pv"
        return false;
    }

    #line 525 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 526 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 526 "src/analyzer/Context.pv"
        return false;
    }

    #line 528 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 529 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 530 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 531 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 532 "src/analyzer/Context.pv"
        return true;
    }

    #line 535 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 536 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 536 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 537 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 539 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 539 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 540 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 542 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 545 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 547 "src/analyzer/Context.pv"
    return true;
}

#line 550 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 551 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 553 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 554 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 555 "src/analyzer/Context.pv"
        return true;
    }

    #line 558 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 559 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 559 "src/analyzer/Context.pv"
        return false;
    }

    #line 561 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 562 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 563 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 564 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 565 "src/analyzer/Context.pv"
        return true;
    }

    #line 568 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 569 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 569 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 570 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 572 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 575 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 576 "src/analyzer/Context.pv"
    return true;
}

#line 579 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 580 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 581 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 581 "src/analyzer/Context.pv"
        return false;
    }

    #line 583 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value);
    #line 584 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 585 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 586 "src/analyzer/Context.pv"
        return false;
    }

    #line 589 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 591 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 592 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 593 "src/analyzer/Context.pv"
            struct Type child_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

            #line 595 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 596 "src/analyzer/Context.pv"
                return false;
            }

            #line 599 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 601 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 602 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 603 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 608 "src/analyzer/Context.pv"
    *type = *Module__make_type_usage(self->module, &(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }, &generics_);

    #line 610 "src/analyzer/Context.pv"
    return true;
}

#line 613 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 614 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 616 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 617 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 618 "src/analyzer/Context.pv"
        return 0;
    }

    #line 621 "src/analyzer/Context.pv"
    return result;
}

#line 624 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 625 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 626 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 626 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 627 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect) {
                .type = indirect->type,
                .to = *Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map),
            });

            #line 632 "src/analyzer/Context.pv"
            return Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }, allocator);
        } break;
        #line 634 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 634 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 635 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence) {
                .type = sequence->type,
                .element = *Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map),
            });
            #line 639 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }) };

            #line 641 "src/analyzer/Context.pv"
            return Type__to_ptr(&(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }, allocator);
        } break;
        #line 643 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 643 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 644 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 646 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 646 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 646 "src/analyzer/Context.pv"
                struct Type* element = ArrayIter_ref_Type__value(&__iter);

                #line 647 "src/analyzer/Context.pv"
                *element = *Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
            } }

            #line 650 "src/analyzer/Context.pv"
            return Type__to_ptr(&(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, resolved) }, allocator);
        } break;
        #line 652 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 653 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 655 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 655 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 655 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 656 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 658 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 658 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 658 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 659 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 662 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 663 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 664 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, resolved_generics)} };

            #line 666 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 668 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 668 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 668 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 669 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__clone(generics, allocator));

            #line 671 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 671 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 671 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 672 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 675 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 676 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 677 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 679 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 681 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 681 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 681 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 682 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__clone(generics, allocator));

            #line 684 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 684 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 684 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 685 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 688 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 689 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 690 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 692 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 694 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 694 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 694 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 695 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 695 "src/analyzer/Context.pv"
                return type;
            }
            #line 696 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__clone(generics, allocator));

            #line 698 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 698 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 698 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 699 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 702 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 703 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 704 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 706 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 708 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 708 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 709 "src/analyzer/Context.pv"
            struct str name = generic->name->value;
            #line 710 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 712 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 713 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 716 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 717 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 720 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 721 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 722 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 723 "src/analyzer/Context.pv"
                return type;
            }

            #line 726 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 728 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 729 "src/analyzer/Context.pv"
            if (generics_map->self_type != 0) {
                #line 730 "src/analyzer/Context.pv"
                return generics_map->self_type;
            } else if (fallback_generics_map != 0 && fallback_generics_map->self_type != 0) {
                #line 732 "src/analyzer/Context.pv"
                return fallback_generics_map->self_type;
            } else {
                #line 734 "src/analyzer/Context.pv"
                return type;
            }
        } break;
        #line 737 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 740 "src/analyzer/Context.pv"
    return type;
}

#line 743 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 744 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 745 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 747 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &name->value) != 0) {
        #line 748 "src/analyzer/Context.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 749 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 750 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 751 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 752 "src/analyzer/Context.pv"
        return false;
    }

    #line 755 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(values, name->value, *type);

    #line 757 "src/analyzer/Context.pv"
    return true;
}

#line 760 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 761 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 762 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);

    #line 764 "src/analyzer/Context.pv"
    while (scope >= scope_front) {
        #line 765 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->values, &name);
        #line 766 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 766 "src/analyzer/Context.pv"
            return type;
        }

        #line 768 "src/analyzer/Context.pv"
        scope -= 1;
    }

    #line 771 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 772 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 772 "src/analyzer/Context.pv"
        return func;
    }

    #line 774 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 777 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 778 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 780 "src/analyzer/Context.pv"
    { struct ArrayIter_ref_Scope __iter = ArrayIter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 780 "src/analyzer/Context.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 780 "src/analyzer/Context.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 781 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 783 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 784 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_DeferStatement __iter = ArrayIter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 784 "src/analyzer/Context.pv"
            while (ArrayIter_ref_DeferStatement__next(&__iter)) {
                #line 784 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = ArrayIter_ref_DeferStatement__value(&__iter);

                #line 785 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 790 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 793 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 794 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 796 "src/analyzer/Context.pv"
    { struct ArrayIter_ref_Scope __iter = ArrayIter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 796 "src/analyzer/Context.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 796 "src/analyzer/Context.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 797 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 799 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 800 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_DeferStatement __iter = ArrayIter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 800 "src/analyzer/Context.pv"
            while (ArrayIter_ref_DeferStatement__next(&__iter)) {
                #line 800 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = ArrayIter_ref_DeferStatement__value(&__iter);

                #line 801 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 804 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 804 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 808 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 811 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 812 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 814 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 814 "src/analyzer/Context.pv"
        return (struct Array_Type) {};
    }

    #line 816 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 817 "src/analyzer/Context.pv"
        struct Type child_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

        #line 819 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 819 "src/analyzer/Context.pv"
            return (struct Array_Type) {};
        }

        #line 821 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 823 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 824 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 825 "src/analyzer/Context.pv"
            return (struct Array_Type) {};
        }
    }

    #line 829 "src/analyzer/Context.pv"
    return generic_inputs;
}
