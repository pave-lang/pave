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
#include <analyzer/NamespaceCpp.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/types/Trait.h>
#include <std/ArrayIter_ref_Type.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Struct.h>
#include <std/String.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/ArrayIter_ref_Scope.h>

#include <analyzer/Context.h>

#line 28 "src/analyzer/Context.pv"
struct Context Context__new(struct ArenaAllocator* allocator, struct str base_path, struct str path, struct Array_Token* tokens, struct Analysis* analysis, struct Module* module) {
    #line 29 "src/analyzer/Context.pv"
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

    #line 40 "src/analyzer/Context.pv"
    if (tokens != 0) {
        #line 41 "src/analyzer/Context.pv"
        self.tokens = tokens->data;
        #line 42 "src/analyzer/Context.pv"
        self.length = tokens->length;
    }

    #line 45 "src/analyzer/Context.pv"
    self.type_self = &self.root->type_self;
    #line 46 "src/analyzer/Context.pv"
    self.pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(module, "char") } };

    #line 48 "src/analyzer/Context.pv"
    struct Token* param_name = ArenaAllocator__store_Token(allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "value", .length = strlen("value") } });

    #line 50 "src/analyzer/Context.pv"
    Context__push_scope(&self, 0);

    #line 52 "src/analyzer/Context.pv"
    struct Generic t = Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 53 "src/analyzer/Context.pv"
    t.name = ArenaAllocator__store_Token(allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") } });

    #line 55 "src/analyzer/Context.pv"
    struct Generic u = Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 56 "src/analyzer/Context.pv"
    u.name = ArenaAllocator__store_Token(allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "U", .length = strlen("U") } });

    #line 58 "src/analyzer/Context.pv"
    struct Array_Generic generics = Array_Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 59 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, t);
    #line 60 "src/analyzer/Context.pv"
    Array_Generic__append(&generics, u);
    #line 61 "src/analyzer/Context.pv"
    struct Generic* generic_t = Array_Generic__get(&generics, 0);
    #line 62 "src/analyzer/Context.pv"
    struct Generic* generic_u = Array_Generic__get(&generics, 1);

    #line 64 "src/analyzer/Context.pv"
    struct Array_Parameter params = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 65 "src/analyzer/Context.pv"
    Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_u } });

    #line 67 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "cast", &generics, &params, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t });

    #line 69 "src/analyzer/Context.pv"
    struct Array_Generic generics2 = Array_Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 70 "src/analyzer/Context.pv"
    Array_Generic__append(&generics2, t);
    #line 71 "src/analyzer/Context.pv"
    struct Generic* generic2_t = Array_Generic__get(&generics2, 0);

    #line 73 "src/analyzer/Context.pv"
    struct Array_Parameter params2 = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 74 "src/analyzer/Context.pv"
    Array_Parameter__append(&params2, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic2_t } });
    #line 75 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "sizeof", &generics2, &params2, self.root->type_usize);

    #line 77 "src/analyzer/Context.pv"
    Array_Parameter__release(&params);
    #line 78 "src/analyzer/Context.pv"
    Array_Generic__release(&generics);

    #line 80 "src/analyzer/Context.pv"
    HashMap_str_bool__insert(&analysis->files, path, true);

    #line 82 "src/analyzer/Context.pv"
    return self;
}

#line 85 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type) {
    #line 86 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 87 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 89 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 89 "src/analyzer/Context.pv"
        return true;
    }

    #line 91 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 92 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) } });
    #line 93 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 94 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 96 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 97 "src/analyzer/Context.pv"
        { struct ArrayIter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 97 "src/analyzer/Context.pv"
        while (ArrayIter_ref_Generic__next(&__iter)) {
            #line 97 "src/analyzer/Context.pv"
            struct Generic generic = *ArrayIter_ref_Generic__value(&__iter);

            #line 98 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 99 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic.name->value, index);
        } }
    }

    #line 103 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 104 "src/analyzer/Context.pv"
        { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 104 "src/analyzer/Context.pv"
        while (ArrayIter_ref_Parameter__next(&__iter)) {
            #line 104 "src/analyzer/Context.pv"
            struct Parameter param = *ArrayIter_ref_Parameter__value(&__iter);

            #line 105 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 109 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, GenericMap__from_generics(self->allocator, &func_info.generics));

    #line 111 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, func_info), ._1 = generic_map} };
    #line 112 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 115 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 116 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 117 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 118 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 118 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 120 "src/analyzer/Context.pv"
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

#line 135 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 136 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 137 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 138 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 138 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 140 "src/analyzer/Context.pv"
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

#line 156 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 157 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 159 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 160 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 163 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 165 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 168 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 169 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 170 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 171 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 174 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 175 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 177 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 178 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 181 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 182 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 185 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 186 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 187 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 188 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 191 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 192 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 194 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 195 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 198 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 199 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 202 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 203 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 204 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 205 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 205 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 207 "src/analyzer/Context.pv"
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

#line 219 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 220 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 222 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && (self->tokens[self->pos].type == TOKEN_TYPE__COMMENT)) {
        #line 223 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 226 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 229 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 230 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 231 "src/analyzer/Context.pv"
        return 0;
    }

    #line 234 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 237 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 238 "src/analyzer/Context.pv"
    if (self->pos == 0) {
        #line 239 "src/analyzer/Context.pv"
        return 0;
    }

    #line 242 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 245 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 246 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 247 "src/analyzer/Context.pv"
        return false;
    }

    #line 250 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 253 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 254 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 255 "src/analyzer/Context.pv"
        return false;
    }

    #line 258 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 260 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 263 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 264 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 265 "src/analyzer/Context.pv"
    if (check) {
        #line 265 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 266 "src/analyzer/Context.pv"
    return check;
}

#line 269 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 270 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 271 "src/analyzer/Context.pv"
        return 0;
    }

    #line 274 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 276 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 277 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 278 "src/analyzer/Context.pv"
        return token;
    }

    #line 281 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 282 "src/analyzer/Context.pv"
    return 0;
}

#line 285 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 286 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 287 "src/analyzer/Context.pv"
        return false;
    }

    #line 290 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 292 "src/analyzer/Context.pv"
    if ((Token__eq(token, type, value))) {
        #line 293 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 294 "src/analyzer/Context.pv"
        return true;
    }

    #line 297 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 298 "src/analyzer/Context.pv"
    return false;
}

#line 301 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 302 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 303 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 306 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 309 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 310 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 311 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 315 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 316 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 318 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 318 "src/analyzer/Context.pv"
        return false;
    }

    #line 320 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 322 "src/analyzer/Context.pv"
    while ((self->pos < self->length) && (brackets > 0)) {
        #line 323 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 324 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 326 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 329 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 330 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 334 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 336 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 337 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 338 "src/analyzer/Context.pv"
        return false;
    }

    #line 341 "src/analyzer/Context.pv"
    return true;
}

#line 344 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 345 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 346 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 349 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 350 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 353 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 354 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 355 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 356 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 356 "src/analyzer/Context.pv"
            return false;
        }

        #line 358 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 359 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 361 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 362 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 364 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 365 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 367 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 368 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 368 "src/analyzer/Context.pv"
                return false;
            }
            #line 369 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 370 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 372 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 372 "src/analyzer/Context.pv"
                return false;
            }
            #line 373 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 374 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 377 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 379 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 380 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 380 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 382 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = indirect_type });

        #line 384 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 385 "src/analyzer/Context.pv"
            return false;
        }

        #line 388 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 389 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 391 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 393 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 393 "src/analyzer/Context.pv"
            return false;
        }

        #line 395 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 396 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 397 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 399 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 399 "src/analyzer/Context.pv"
                return false;
            }

            #line 401 "src/analyzer/Context.pv"
            return true;
        }

        #line 404 "src/analyzer/Context.pv"
        struct Token* length = Context__expect(self, TOKEN_TYPE__NUMBER);
        #line 405 "src/analyzer/Context.pv"
        if (!length) {
            #line 405 "src/analyzer/Context.pv"
            return false;
        }

        #line 407 "src/analyzer/Context.pv"
        uintptr_t result = 0;

        #line 409 "src/analyzer/Context.pv"
        int32_t i = 0;
        #line 410 "src/analyzer/Context.pv"
        while (i < length->value.length) {
            #line 411 "src/analyzer/Context.pv"
            char c = length->value.ptr[i];

            #line 413 "src/analyzer/Context.pv"
            if (((c >= '0') && (c <= '9'))) {
                #line 414 "src/analyzer/Context.pv"
                result = result * 10 + (c - '0');
            } else {
                #line 416 "src/analyzer/Context.pv"
                break;
            }

            #line 419 "src/analyzer/Context.pv"
            i += 1;
        }

        #line 422 "src/analyzer/Context.pv"
        if (i != length->value.length) {
            #line 423 "src/analyzer/Context.pv"
            Context__error_token(self, length, "Fixed array length must be a standard positive integer");
        }

        #line 426 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = result };
        #line 427 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 429 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 429 "src/analyzer/Context.pv"
            return false;
        }

        #line 431 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 433 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 434 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 436 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 437 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 439 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 439 "src/analyzer/Context.pv"
                return false;
            }

            #line 441 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 443 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 444 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 445 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 449 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 450 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 452 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, Function__new(self));
        #line 453 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) { .self_type = self->type_self });

        #line 455 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 455 "src/analyzer/Context.pv"
            return false;
        }

        #line 457 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 459 "src/analyzer/Context.pv"
        return true;
    }

    #line 462 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 463 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 463 "src/analyzer/Context.pv"
        return false;
    }

    #line 465 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 466 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 467 "src/analyzer/Context.pv"
        return true;
    }

    #line 470 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 472 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 473 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 474 "src/analyzer/Context.pv"
            struct Type child_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

            #line 476 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 477 "src/analyzer/Context.pv"
                return false;
            }

            #line 480 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 482 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 483 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 484 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 489 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 490 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = Generics__find(generics, name->value) };
        #line 491 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 492 "src/analyzer/Context.pv"
        return true;
    }

    #line 495 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 496 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 497 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 498 "src/analyzer/Context.pv"
        return true;
    }

    #line 501 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 502 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 503 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 504 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN, .unknown_value = { ._0 = name->value, ._1 = generics_} };
        #line 505 "src/analyzer/Context.pv"
        return false;
    }

    #line 508 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 509 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 509 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 510 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 512 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 515 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 516 "src/analyzer/Context.pv"
    return true;
}

#line 519 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 520 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 522 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 522 "src/analyzer/Context.pv"
        return false;
    }

    #line 524 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 525 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 525 "src/analyzer/Context.pv"
        return false;
    }

    #line 527 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 528 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 529 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 530 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 531 "src/analyzer/Context.pv"
        return true;
    }

    #line 534 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 535 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 535 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 536 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 538 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 538 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 539 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 541 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 544 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 546 "src/analyzer/Context.pv"
    return true;
}

#line 549 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 550 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 552 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 553 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 554 "src/analyzer/Context.pv"
        return true;
    }

    #line 557 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 558 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 558 "src/analyzer/Context.pv"
        return false;
    }

    #line 560 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 561 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 562 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 563 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 564 "src/analyzer/Context.pv"
        return true;
    }

    #line 567 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 568 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 568 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 569 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 571 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 574 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 575 "src/analyzer/Context.pv"
    return true;
}

#line 578 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 579 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 580 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 580 "src/analyzer/Context.pv"
        return false;
    }

    #line 582 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value);
    #line 583 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 584 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 585 "src/analyzer/Context.pv"
        return false;
    }

    #line 588 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 590 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 591 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 592 "src/analyzer/Context.pv"
            struct Type child_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

            #line 594 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 595 "src/analyzer/Context.pv"
                return false;
            }

            #line 598 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 600 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 601 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 602 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 607 "src/analyzer/Context.pv"
    *type = *Module__make_type_usage(self->module, &(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }, &generics_);

    #line 609 "src/analyzer/Context.pv"
    return true;
}

#line 612 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 613 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 615 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 616 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 617 "src/analyzer/Context.pv"
        return 0;
    }

    #line 620 "src/analyzer/Context.pv"
    return result;
}

#line 623 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 624 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 625 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 625 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 626 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect) {
                .type = indirect->type,
                .to = *Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map),
            });

            #line 631 "src/analyzer/Context.pv"
            return Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }, allocator);
        } break;
        #line 633 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 633 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 634 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence) {
                .type = sequence->type,
                .element = *Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map),
            });
            #line 638 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }) };

            #line 640 "src/analyzer/Context.pv"
            return Type__to_ptr(&(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }, allocator);
        } break;
        #line 642 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 642 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 643 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 645 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 645 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 645 "src/analyzer/Context.pv"
                struct Type* element = ArrayIter_ref_Type__value(&__iter);

                #line 646 "src/analyzer/Context.pv"
                *element = *Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
            } }

            #line 649 "src/analyzer/Context.pv"
            return Type__to_ptr(&(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, resolved) }, allocator);
        } break;
        #line 651 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 652 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 654 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 654 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 654 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 655 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 657 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 657 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 657 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 658 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 661 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 662 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 663 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, resolved_generics)} };

            #line 665 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 667 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 667 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 667 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 668 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__clone(generics, allocator));

            #line 670 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 670 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 670 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 671 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 674 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 675 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 676 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 678 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 680 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 680 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 680 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 681 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__clone(generics, allocator));

            #line 683 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 683 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 683 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 684 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 687 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 688 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 689 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 691 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 693 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 693 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 693 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 694 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 694 "src/analyzer/Context.pv"
                return type;
            }
            #line 695 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__clone(generics, allocator));

            #line 697 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 697 "src/analyzer/Context.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 697 "src/analyzer/Context.pv"
                struct Type* generic = ArrayIter_ref_Type__value(&__iter);

                #line 698 "src/analyzer/Context.pv"
                *generic = *Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
            } }

            #line 701 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 702 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 703 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 705 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 707 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 707 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 708 "src/analyzer/Context.pv"
            struct str name = generic->name->value;
            #line 709 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 711 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 712 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 715 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 716 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 719 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 720 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 721 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 722 "src/analyzer/Context.pv"
                return type;
            }

            #line 725 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 727 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 728 "src/analyzer/Context.pv"
            if (generics_map->self_type != 0) {
                #line 729 "src/analyzer/Context.pv"
                return generics_map->self_type;
            } else if (fallback_generics_map != 0 && fallback_generics_map->self_type != 0) {
                #line 731 "src/analyzer/Context.pv"
                return fallback_generics_map->self_type;
            } else {
                #line 733 "src/analyzer/Context.pv"
                return type;
            }
        } break;
        #line 736 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 739 "src/analyzer/Context.pv"
    return type;
}

#line 742 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 743 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 744 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 746 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &name->value) != 0) {
        #line 747 "src/analyzer/Context.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 748 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 749 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 750 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 751 "src/analyzer/Context.pv"
        return false;
    }

    #line 754 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(values, name->value, *type);

    #line 756 "src/analyzer/Context.pv"
    return true;
}

#line 759 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 760 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 761 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);

    #line 763 "src/analyzer/Context.pv"
    while (scope >= scope_front) {
        #line 764 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->values, &name);
        #line 765 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 765 "src/analyzer/Context.pv"
            return type;
        }

        #line 767 "src/analyzer/Context.pv"
        scope -= 1;
    }

    #line 770 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 771 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 771 "src/analyzer/Context.pv"
        return func;
    }

    #line 773 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 776 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 777 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 779 "src/analyzer/Context.pv"
    { struct ArrayIter_ref_Scope __iter = ArrayIter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 779 "src/analyzer/Context.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 779 "src/analyzer/Context.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 780 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 782 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 783 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_DeferStatement __iter = ArrayIter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 783 "src/analyzer/Context.pv"
            while (ArrayIter_ref_DeferStatement__next(&__iter)) {
                #line 783 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = ArrayIter_ref_DeferStatement__value(&__iter);

                #line 784 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 789 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 792 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 793 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 795 "src/analyzer/Context.pv"
    { struct ArrayIter_ref_Scope __iter = ArrayIter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 795 "src/analyzer/Context.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 795 "src/analyzer/Context.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 796 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 798 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 799 "src/analyzer/Context.pv"
            { struct ArrayIter_ref_DeferStatement __iter = ArrayIter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 799 "src/analyzer/Context.pv"
            while (ArrayIter_ref_DeferStatement__next(&__iter)) {
                #line 799 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = ArrayIter_ref_DeferStatement__value(&__iter);

                #line 800 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 803 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 803 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 807 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 810 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 811 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 813 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 813 "src/analyzer/Context.pv"
        return (struct Array_Type) {};
    }

    #line 815 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 816 "src/analyzer/Context.pv"
        struct Type child_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

        #line 818 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 818 "src/analyzer/Context.pv"
            return (struct Array_Type) {};
        }

        #line 820 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 822 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 823 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 824 "src/analyzer/Context.pv"
            return (struct Array_Type) {};
        }
    }

    #line 828 "src/analyzer/Context.pv"
    return generic_inputs;
}
