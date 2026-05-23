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
    #line 87 "src/analyzer/Context.pv"
    struct Indirect* typename_return_indirect = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__CONST_POINTER, .to = type_char }});
    #line 88 "src/analyzer/Context.pv"
    Context__insert_builtin_function(&self, "typename", &generics2, &params2, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = typename_return_indirect });

    #line 90 "src/analyzer/Context.pv"
    Array_Parameter__release(&params);
    #line 91 "src/analyzer/Context.pv"
    Array_Generic__release(&generics);

    #line 93 "src/analyzer/Context.pv"
    HashMap_str_bool__insert(&analysis->files, path, true);

    #line 95 "src/analyzer/Context.pv"
    return self;
}

#line 98 "src/analyzer/Context.pv"
bool Context__insert_builtin_function(struct Context* self, char const* name, struct Array_Generic* generics, struct Array_Parameter* parameters, struct Type return_type) {
    #line 99 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 100 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 100 "src/analyzer/Context.pv"
        return false;
    }
    #line 101 "src/analyzer/Context.pv"
    struct HashMap_str_Type* values = &scope->values;

    #line 103 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(values, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 103 "src/analyzer/Context.pv"
        return true;
    }

    #line 105 "src/analyzer/Context.pv"
    struct Function func_info = Function__new(self);
    #line 106 "src/analyzer/Context.pv"
    func_info.name = ArenaAllocator__store_Token(self->allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = name, .length = strlen(name) }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});
    #line 107 "src/analyzer/Context.pv"
    func_info.type = FUNCTION_TYPE__BUILTIN;
    #line 108 "src/analyzer/Context.pv"
    func_info.return_type = return_type;

    #line 110 "src/analyzer/Context.pv"
    if (generics != 0) {
        #line 111 "src/analyzer/Context.pv"
        { struct Iter_ref_Generic __iter = Array_Generic__iter(generics);
        #line 111 "src/analyzer/Context.pv"
        while (Iter_ref_Generic__next(&__iter)) {
            #line 111 "src/analyzer/Context.pv"
            struct Generic generic = *Iter_ref_Generic__value(&__iter);

            #line 112 "src/analyzer/Context.pv"
            uintptr_t index = Array_Generic__append(&func_info.generics.array, generic);
            #line 113 "src/analyzer/Context.pv"
            struct Token* generic_name = generic.name;
            #line 114 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 114 "src/analyzer/Context.pv"
                return false;
            }
            #line 115 "src/analyzer/Context.pv"
            HashMap_str_usize__insert(&func_info.generics.map, generic_name->value, index);
        } }
    }

    #line 119 "src/analyzer/Context.pv"
    if (parameters != 0) {
        #line 120 "src/analyzer/Context.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(parameters);
        #line 120 "src/analyzer/Context.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 120 "src/analyzer/Context.pv"
            struct Parameter param = *Iter_ref_Parameter__value(&__iter);

            #line 121 "src/analyzer/Context.pv"
            Array_Parameter__append(&func_info.parameters, param);
        } }
    }

    #line 125 "src/analyzer/Context.pv"
    struct GenericMap generic_map_val = GenericMap__from_generics(self->allocator, &func_info.generics);
    #line 126 "src/analyzer/Context.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);

    #line 128 "src/analyzer/Context.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(self->allocator, &func_info), ._1 = generic_map} };
    #line 129 "src/analyzer/Context.pv"
    return HashMap_str_Type__insert(values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 132 "src/analyzer/Context.pv"
void Context__error_token(struct Context* self, struct Token* token, char const* message) {
    #line 133 "src/analyzer/Context.pv"
    Context__error_token_bounds(self, TokenBounds__new(token, token), message);
}

#line 136 "src/analyzer/Context.pv"
void Context__error_token_bounds(struct Context* self, struct TokenBounds bounds, char const* message) {
    #line 137 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 138 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 139 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 139 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 140 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 140 "src/analyzer/Context.pv"
        return;
    }

    #line 142 "src/analyzer/Context.pv"
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

#line 158 "src/analyzer/Context.pv"
void Context__error_expression(struct Context* self, struct Expression* expression, char const* message) {
    #line 159 "src/analyzer/Context.pv"
    Context__error_token_bounds(self, Expression__get_token_bounds(expression), message);
}

#line 162 "src/analyzer/Context.pv"
void Context__error_statement(struct Context* self, struct Statement* statement, char const* message) {
    #line 163 "src/analyzer/Context.pv"
    Context__error_token_bounds(self, Statement__get_token_bounds(statement), message);
}

#line 166 "src/analyzer/Context.pv"
void Context__error_token_value(struct Context* self, struct Token* token, char const* message, struct str value) {
    #line 167 "src/analyzer/Context.pv"
    Context__error_token_bounds_value(self, TokenBounds__new(token, token), message, value);
}

#line 170 "src/analyzer/Context.pv"
void Context__error_token_bounds_value(struct Context* self, struct TokenBounds bounds, char const* message, struct str value) {
    #line 171 "src/analyzer/Context.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 172 "src/analyzer/Context.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &self->path);
    #line 173 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 173 "src/analyzer/Context.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, self->path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 174 "src/analyzer/Context.pv"
    if (file_diagnostics == 0) {
        #line 174 "src/analyzer/Context.pv"
        return;
    }

    #line 176 "src/analyzer/Context.pv"
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

#line 192 "src/analyzer/Context.pv"
void Context__error_expression_value(struct Context* self, struct Expression* expression, char const* message, struct str value) {
    #line 193 "src/analyzer/Context.pv"
    Context__error_token_bounds_value(self, Expression__get_token_bounds(expression), message, value);
}

#line 196 "src/analyzer/Context.pv"
void Context__error_statement_value(struct Context* self, struct Statement* statement, char const* message, struct str value) {
    #line 197 "src/analyzer/Context.pv"
    Context__error_token_bounds_value(self, Statement__get_token_bounds(statement), message, value);
}

#line 200 "src/analyzer/Context.pv"
void Context__error(struct Context* self, char const* message) {
    #line 201 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 203 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 204 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 207 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;

    #line 209 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 212 "src/analyzer/Context.pv"
void Context__error_token_expected(struct Context* self, struct Token* token, enum TokenType type) {
    #line 213 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 214 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s", TokenType__get_name(&type));
    #line 215 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 218 "src/analyzer/Context.pv"
void Context__error_expected(struct Context* self, enum TokenType type) {
    #line 219 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 221 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 222 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 225 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 226 "src/analyzer/Context.pv"
    Context__error_token_expected(self, token, type);
}

#line 229 "src/analyzer/Context.pv"
void Context__error_token_expected_value(struct Context* self, struct Token* token, enum TokenType type, char const* value) {
    #line 230 "src/analyzer/Context.pv"
    char* message = ArenaAllocator__Allocator__alloc(self->allocator, 512);
    #line 231 "src/analyzer/Context.pv"
    snprintf(message, 512, "Unexpected token, expected %s %s", TokenType__get_name(&type), value);
    #line 232 "src/analyzer/Context.pv"
    Context__error_token(self, token, message);
}

#line 235 "src/analyzer/Context.pv"
void Context__error_expected_value(struct Context* self, enum TokenType type, char const* value) {
    #line 236 "src/analyzer/Context.pv"
    uintptr_t pos = self->pos;

    #line 238 "src/analyzer/Context.pv"
    if (pos >= self->length) {
        #line 239 "src/analyzer/Context.pv"
        pos = self->length - 1;
    }

    #line 242 "src/analyzer/Context.pv"
    struct Token* token = self->tokens + pos;
    #line 243 "src/analyzer/Context.pv"
    Context__error_token_expected_value(self, token, type, value);
}

#line 246 "src/analyzer/Context.pv"
void Context__inlay_hint(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 247 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, TokenBounds__new(token, token), label, kind, padding_left, padding_right);
}

#line 250 "src/analyzer/Context.pv"
void Context__inlay_hint_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 251 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 252 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 253 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 253 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 254 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 254 "src/analyzer/Context.pv"
        return;
    }

    #line 256 "src/analyzer/Context.pv"
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

#line 268 "src/analyzer/Context.pv"
void Context__inlay_hint_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 269 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, Expression__get_token_bounds(expression), label, kind, padding_left, padding_right);
}

#line 272 "src/analyzer/Context.pv"
void Context__inlay_hint_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 273 "src/analyzer/Context.pv"
    Context__inlay_hint_token_bounds(self, Statement__get_token_bounds(statement), label, kind, padding_left, padding_right);
}

#line 276 "src/analyzer/Context.pv"
void Context__inlay_hint_before(struct Context* self, struct Token* token, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 277 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, TokenBounds__new(token, token), label, kind, padding_left, padding_right);
}

#line 280 "src/analyzer/Context.pv"
void Context__inlay_hint_before_token_bounds(struct Context* self, struct TokenBounds bounds, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 281 "src/analyzer/Context.pv"
    struct HashMap_str_Array_InlayHint* inlay_hints = &self->analysis->inlay_hints;
    #line 282 "src/analyzer/Context.pv"
    struct Array_InlayHint* file_inlay_hints = HashMap_str_Array_InlayHint__find(inlay_hints, &self->path);
    #line 283 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 283 "src/analyzer/Context.pv"
        file_inlay_hints = HashMap_str_Array_InlayHint__insert(inlay_hints, self->path, Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }
    #line 284 "src/analyzer/Context.pv"
    if (file_inlay_hints == 0) {
        #line 284 "src/analyzer/Context.pv"
        return;
    }

    #line 286 "src/analyzer/Context.pv"
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

#line 298 "src/analyzer/Context.pv"
void Context__inlay_hint_before_expression(struct Context* self, struct Expression* expression, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 299 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, Expression__get_token_bounds(expression), label, kind, padding_left, padding_right);
}

#line 302 "src/analyzer/Context.pv"
void Context__inlay_hint_before_statement(struct Context* self, struct Statement* statement, char const* label, enum InlayHintKind kind, bool padding_left, bool padding_right) {
    #line 303 "src/analyzer/Context.pv"
    Context__inlay_hint_before_token_bounds(self, Statement__get_token_bounds(statement), label, kind, padding_left, padding_right);
}

#line 306 "src/analyzer/Context.pv"
bool Context__next_token(struct Context* self) {
    #line 307 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 309 "src/analyzer/Context.pv"
    while (self->pos < self->length && self->tokens[self->pos].type == TOKEN_TYPE__COMMENT) {
        #line 310 "src/analyzer/Context.pv"
        self->pos += 1;
    }

    #line 313 "src/analyzer/Context.pv"
    return self->pos < self->length;
}

#line 316 "src/analyzer/Context.pv"
struct Token* Context__current(struct Context* self) {
    #line 317 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 318 "src/analyzer/Context.pv"
        return 0;
    }

    #line 321 "src/analyzer/Context.pv"
    return self->tokens + self->pos;
}

#line 324 "src/analyzer/Context.pv"
struct Token* Context__prev(struct Context* self) {
    #line 325 "src/analyzer/Context.pv"
    if (self->pos == 0) {
        #line 326 "src/analyzer/Context.pv"
        return 0;
    }

    #line 329 "src/analyzer/Context.pv"
    return self->tokens + self->pos - 1;
}

#line 332 "src/analyzer/Context.pv"
bool Context__check(struct Context* self, enum TokenType type) {
    #line 333 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 334 "src/analyzer/Context.pv"
        return false;
    }

    #line 337 "src/analyzer/Context.pv"
    return type == self->tokens[self->pos].type;
}

#line 340 "src/analyzer/Context.pv"
bool Context__check_value(struct Context* self, enum TokenType type, char const* value) {
    #line 341 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 342 "src/analyzer/Context.pv"
        return false;
    }

    #line 345 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 347 "src/analyzer/Context.pv"
    return Token__eq(token, type, value);
}

#line 350 "src/analyzer/Context.pv"
bool Context__check_next(struct Context* self, enum TokenType type, char const* value) {
    #line 351 "src/analyzer/Context.pv"
    bool check = Context__check_value(self, type, value);
    #line 352 "src/analyzer/Context.pv"
    if (check) {
        #line 352 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
    #line 353 "src/analyzer/Context.pv"
    return check;
}

#line 356 "src/analyzer/Context.pv"
struct Token* Context__expect(struct Context* self, enum TokenType type) {
    #line 357 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 358 "src/analyzer/Context.pv"
        return 0;
    }

    #line 361 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 363 "src/analyzer/Context.pv"
    if (token->type == type) {
        #line 364 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 365 "src/analyzer/Context.pv"
        return token;
    }

    #line 368 "src/analyzer/Context.pv"
    Context__error_expected(self, type);
    #line 369 "src/analyzer/Context.pv"
    return 0;
}

#line 372 "src/analyzer/Context.pv"
bool Context__expect_value(struct Context* self, enum TokenType type, char const* value) {
    #line 373 "src/analyzer/Context.pv"
    if (self->pos >= self->length) {
        #line 374 "src/analyzer/Context.pv"
        return false;
    }

    #line 377 "src/analyzer/Context.pv"
    struct Token* token = &self->tokens[self->pos];

    #line 379 "src/analyzer/Context.pv"
    if (Token__eq(token, type, value)) {
        #line 380 "src/analyzer/Context.pv"
        Context__next_token(self);
        #line 381 "src/analyzer/Context.pv"
        return true;
    }

    #line 384 "src/analyzer/Context.pv"
    Context__error_expected_value(self, type, value);
    #line 385 "src/analyzer/Context.pv"
    return false;
}

#line 388 "src/analyzer/Context.pv"
bool Context__skip_to_symbol(struct Context* self, char const* symbol) {
    #line 389 "src/analyzer/Context.pv"
    while (self->pos < self->length && !Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol)) {
        #line 390 "src/analyzer/Context.pv"
        Context__next_token(self);
    }

    #line 393 "src/analyzer/Context.pv"
    return Context__check_value(self, TOKEN_TYPE__SYMBOL, symbol);
}

#line 396 "src/analyzer/Context.pv"
void Context__skip_comments(struct Context* self) {
    #line 397 "src/analyzer/Context.pv"
    while (self->pos < self->length && Context__check(self, TOKEN_TYPE__COMMENT)) {
        #line 398 "src/analyzer/Context.pv"
        Context__next_token(self);
    }
}

#line 402 "src/analyzer/Context.pv"
bool Context__skip_brackets(struct Context* self, char const* open, char const* close) {
    #line 403 "src/analyzer/Context.pv"
    uintptr_t token_start = self->pos;

    #line 405 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, open)) {
        #line 405 "src/analyzer/Context.pv"
        return false;
    }

    #line 407 "src/analyzer/Context.pv"
    uintptr_t brackets = 1;

    #line 409 "src/analyzer/Context.pv"
    while (self->pos < self->length && brackets > 0) {
        #line 410 "src/analyzer/Context.pv"
        if (Context__check_value(self, TOKEN_TYPE__SYMBOL, open)) {
            #line 411 "src/analyzer/Context.pv"
            brackets += 1;
        } else if (Context__check_value(self, TOKEN_TYPE__SYMBOL, close)) {
            #line 413 "src/analyzer/Context.pv"
            brackets -= 1;
        }

        #line 416 "src/analyzer/Context.pv"
        if (brackets > 0) {
            #line 417 "src/analyzer/Context.pv"
            Context__next_token(self);
        }
    }

    #line 421 "src/analyzer/Context.pv"
    self->pos += 1;

    #line 423 "src/analyzer/Context.pv"
    if (brackets != 0) {
        #line 424 "src/analyzer/Context.pv"
        Context__error_token(self, self->tokens + token_start, "Unclosed brackets");
        #line 425 "src/analyzer/Context.pv"
        return false;
    }

    #line 428 "src/analyzer/Context.pv"
    return true;
}

#line 431 "src/analyzer/Context.pv"
void Context__push_scope(struct Context* self, struct Block* block) {
    #line 432 "src/analyzer/Context.pv"
    struct Scope scope = Scope__new(self->allocator, block);
    #line 433 "src/analyzer/Context.pv"
    Array_Scope__append(&self->scopes, scope);
}

#line 436 "src/analyzer/Context.pv"
void Context__pop_scope(struct Context* self) {
    #line 437 "src/analyzer/Context.pv"
    Array_Scope__remove_back(&self->scopes);
}

#line 440 "src/analyzer/Context.pv"
bool Context__parse_type(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 441 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 442 "src/analyzer/Context.pv"
        struct Type target_type;
        #line 443 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &target_type, generics)) {
            #line 443 "src/analyzer/Context.pv"
            return false;
        }

        #line 445 "src/analyzer/Context.pv"
        struct Indirect* indirect_1 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
        #line 446 "src/analyzer/Context.pv"
        struct Indirect* indirect_2 = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_1 });

        #line 448 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect_2 };
        #line 449 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "&")) {
        #line 451 "src/analyzer/Context.pv"
        bool dynamic_dispatch = Context__check_next(self, TOKEN_TYPE__KEYWORD, "dyn");
        #line 452 "src/analyzer/Context.pv"
        struct Type target_type;

        #line 454 "src/analyzer/Context.pv"
        if (dynamic_dispatch) {
            #line 455 "src/analyzer/Context.pv"
            if (!Context__parse_type_trait(self, &target_type, generics)) {
                #line 455 "src/analyzer/Context.pv"
                return false;
            }
            #line 456 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 457 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        } else {
            #line 459 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &target_type, generics)) {
                #line 459 "src/analyzer/Context.pv"
                return false;
            }
            #line 460 "src/analyzer/Context.pv"
            struct Indirect* indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, target_type);
            #line 461 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        }

        #line 464 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "*")) {
        #line 466 "src/analyzer/Context.pv"
        enum IndirectType indirect_type = INDIRECT_TYPE__POINTER;
        #line 467 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "const")) {
            #line 467 "src/analyzer/Context.pv"
            indirect_type = INDIRECT_TYPE__CONST_POINTER;
        }

        #line 469 "src/analyzer/Context.pv"
        struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = indirect_type, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
        #line 470 "src/analyzer/Context.pv"
        if (indirect == 0) {
            #line 470 "src/analyzer/Context.pv"
            return false;
        }

        #line 472 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &indirect->to, generics)) {
            #line 473 "src/analyzer/Context.pv"
            return false;
        }

        #line 476 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 477 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "[")) {
        #line 479 "src/analyzer/Context.pv"
        struct Sequence* sequence = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Sequence));

        #line 481 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &sequence->element, generics)) {
            #line 481 "src/analyzer/Context.pv"
            return false;
        }
        #line 482 "src/analyzer/Context.pv"
        sequence->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = sequence->element }}) };

        #line 484 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ";")) {
            #line 485 "src/analyzer/Context.pv"
            sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE };
            #line 486 "src/analyzer/Context.pv"
            *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

            #line 488 "src/analyzer/Context.pv"
            if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
                #line 488 "src/analyzer/Context.pv"
                return false;
            }

            #line 490 "src/analyzer/Context.pv"
            return true;
        }

        #line 493 "src/analyzer/Context.pv"
        struct Token* length_token = Context__current(self);
        #line 494 "src/analyzer/Context.pv"
        struct Expression* length_expr = Expression__parse(self, generics);
        #line 495 "src/analyzer/Context.pv"
        if (length_expr == 0) {
            #line 495 "src/analyzer/Context.pv"
            return false;
        }

        #line 497 "src/analyzer/Context.pv"
        if (!Expression__is_const_expression(length_expr, self)) {
            #line 498 "src/analyzer/Context.pv"
            Context__error_token(self, length_token, "Fixed array length must be a compile-time constant integer expression");
            #line 499 "src/analyzer/Context.pv"
            return false;
        }

        #line 502 "src/analyzer/Context.pv"
        sequence->type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = length_expr };
        #line 503 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

        #line 505 "src/analyzer/Context.pv"
        if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "]")) {
            #line 505 "src/analyzer/Context.pv"
            return false;
        }

        #line 507 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "(")) {
        #line 509 "src/analyzer/Context.pv"
        struct Tuple* tuple = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Tuple));
        #line 510 "src/analyzer/Context.pv"
        tuple->elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

        #line 512 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ")")) {
            #line 513 "src/analyzer/Context.pv"
            struct Type element_type;

            #line 515 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &element_type, generics)) {
                #line 515 "src/analyzer/Context.pv"
                return false;
            }

            #line 517 "src/analyzer/Context.pv"
            Array_Type__append(&tuple->elements, element_type);

            #line 519 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ")")) {
                #line 520 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or )");
                #line 521 "src/analyzer/Context.pv"
                return false;
            }
        }

        #line 525 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
        #line 526 "src/analyzer/Context.pv"
        return true;
    } else if (Context__check_next(self, TOKEN_TYPE__KEYWORD, "fn")) {
        #line 528 "src/analyzer/Context.pv"
        struct Function func_info_val = Function__new(self);
        #line 529 "src/analyzer/Context.pv"
        struct Function* func_info = ArenaAllocator__store_Function(self->allocator, &func_info_val);
        #line 530 "src/analyzer/Context.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self->type_self, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
        #line 531 "src/analyzer/Context.pv"
        if (func_info == 0) {
            #line 531 "src/analyzer/Context.pv"
            return false;
        }
        #line 532 "src/analyzer/Context.pv"
        if (generic_map == 0) {
            #line 532 "src/analyzer/Context.pv"
            return false;
        }

        #line 534 "src/analyzer/Context.pv"
        if (!Function__parse_parameters(func_info, &func_info->generics) || !Function__parse_return_type(func_info, &func_info->generics)) {
            #line 534 "src/analyzer/Context.pv"
            return false;
        }

        #line 536 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} };

        #line 538 "src/analyzer/Context.pv"
        return true;
    }

    #line 541 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 542 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 542 "src/analyzer/Context.pv"
        return false;
    }

    #line 544 "src/analyzer/Context.pv"
    if (Token__eq(name, TOKEN_TYPE__IDENTIFIER, "Self")) {
        #line 545 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__SELF };
        #line 546 "src/analyzer/Context.pv"
        return true;
    }

    #line 549 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 551 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 552 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 553 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 555 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 556 "src/analyzer/Context.pv"
                return false;
            }

            #line 559 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 561 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 562 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 563 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 568 "src/analyzer/Context.pv"
    if (generics != 0 && Generics__has(generics, name->value)) {
        #line 569 "src/analyzer/Context.pv"
        struct Generic* generic_ref = Generics__find(generics, name->value);
        #line 570 "src/analyzer/Context.pv"
        if (generic_ref == 0) {
            #line 570 "src/analyzer/Context.pv"
            return false;
        }

        #line 572 "src/analyzer/Context.pv"
        if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
            #line 573 "src/analyzer/Context.pv"
            struct Token* typedef_name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
            #line 574 "src/analyzer/Context.pv"
            if (typedef_name == 0) {
                #line 574 "src/analyzer/Context.pv"
                return false;
            }

            #line 576 "src/analyzer/Context.pv"
            bool found = false;
            #line 577 "src/analyzer/Context.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_ref->traits);
            #line 577 "src/analyzer/Context.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 577 "src/analyzer/Context.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 578 "src/analyzer/Context.pv"
                if (HashMap_str_usize__find(&trait_info->typedefs, &typedef_name->value) != 0) {
                    #line 578 "src/analyzer/Context.pv"
                    found = true;
                }
            } }
            #line 580 "src/analyzer/Context.pv"
            if (!found) {
                #line 581 "src/analyzer/Context.pv"
                Context__error_token(self, typedef_name, "Unknown typedef in trait bound");
                #line 582 "src/analyzer/Context.pv"
                return false;
            }

            #line 585 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(self->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic_ref, .typedef_name = typedef_name->value }});
            #line 586 "src/analyzer/Context.pv"
            struct Type new_type = (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt };
            #line 587 "src/analyzer/Context.pv"
            memcpy(type, &new_type, sizeof(struct Type));
            #line 588 "src/analyzer/Context.pv"
            return true;
        }

        #line 591 "src/analyzer/Context.pv"
        struct Type new_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_ref };
        #line 592 "src/analyzer/Context.pv"
        memcpy(type, &new_type, sizeof(struct Type));
        #line 593 "src/analyzer/Context.pv"
        return true;
    }

    #line 596 "src/analyzer/Context.pv"
    struct Type* context_type = HashMap_str_Type__find(&self->types, &name->value);
    #line 597 "src/analyzer/Context.pv"
    if (context_type != 0) {
        #line 598 "src/analyzer/Context.pv"
        memcpy(type, context_type, sizeof(struct Type));
        #line 599 "src/analyzer/Context.pv"
        return true;
    }

    #line 602 "src/analyzer/Context.pv"
    struct Type* new_type = Module__find_make_type(self->module, name->value, &generics_);
    #line 603 "src/analyzer/Context.pv"
    if (new_type == 0) {
        #line 604 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unknown type");
        #line 605 "src/analyzer/Context.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(self->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = name->value, .generics = generics_ }});
        #line 606 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
        #line 607 "src/analyzer/Context.pv"
        return false;
    }

    #line 610 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 611 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 611 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = new_type->namespacecpp_value;
            #line 612 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 614 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 617 "src/analyzer/Context.pv"
    switch (new_type->type) {
        #line 618 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 618 "src/analyzer/Context.pv"
            struct Struct* struct_info = new_type->struct_value._0;
            #line 619 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &struct_info->generics, &generics_)) {
                #line 619 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 621 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 621 "src/analyzer/Context.pv"
            struct Enum* enum_info = new_type->enum_value._0;
            #line 622 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &enum_info->generics, &generics_)) {
                #line 622 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 624 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 624 "src/analyzer/Context.pv"
            struct Trait* trait_info = new_type->trait_value._0;
            #line 625 "src/analyzer/Context.pv"
            if (!Context__validate_generic_constraints(self, &trait_info->generics, &generics_)) {
                #line 625 "src/analyzer/Context.pv"
                return false;
            }
        } break;
        #line 627 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 630 "src/analyzer/Context.pv"
    *type = *new_type;
    #line 631 "src/analyzer/Context.pv"
    return true;
}

#line 634 "src/analyzer/Context.pv"
bool Context__parse_type_namespace_cpp(struct Context* self, struct NamespaceCpp* parent, struct Type* type, struct Generics* generics) {
    #line 635 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 637 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 637 "src/analyzer/Context.pv"
        return false;
    }

    #line 639 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 640 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 640 "src/analyzer/Context.pv"
        return false;
    }

    #line 642 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 643 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 644 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 645 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = parent };
        #line 646 "src/analyzer/Context.pv"
        return true;
    }

    #line 649 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 650 "src/analyzer/Context.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 650 "src/analyzer/Context.pv"
            struct NamespaceCpp* ns_info = find_type->namespacecpp_value;
            #line 651 "src/analyzer/Context.pv"
            return Context__parse_type_namespace_cpp(self, ns_info, type, generics);
        } break;
        #line 653 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 653 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 654 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 656 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 659 "src/analyzer/Context.pv"
    *type = *find_type;

    #line 661 "src/analyzer/Context.pv"
    return true;
}

#line 664 "src/analyzer/Context.pv"
bool Context__parse_type_class_cpp(struct Context* self, struct ClassCpp* parent, struct Type* type, struct Generics* generics) {
    #line 665 "src/analyzer/Context.pv"
    uintptr_t start_pos = self->pos;

    #line 667 "src/analyzer/Context.pv"
    if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, "::")) {
        #line 668 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 669 "src/analyzer/Context.pv"
        return true;
    }

    #line 672 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 673 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 673 "src/analyzer/Context.pv"
        return false;
    }

    #line 675 "src/analyzer/Context.pv"
    struct Type* find_type = HashMap_str_Type__find(&parent->types, &name->value);
    #line 676 "src/analyzer/Context.pv"
    if (find_type == 0) {
        #line 677 "src/analyzer/Context.pv"
        self->pos = start_pos;
        #line 678 "src/analyzer/Context.pv"
        *type = (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = parent };
        #line 679 "src/analyzer/Context.pv"
        return true;
    }

    #line 682 "src/analyzer/Context.pv"
    switch (find_type->type) {
        #line 683 "src/analyzer/Context.pv"
        case TYPE__CLASS_CPP: {
            #line 683 "src/analyzer/Context.pv"
            struct ClassCpp* class_info = find_type->classcpp_value;
            #line 684 "src/analyzer/Context.pv"
            return Context__parse_type_class_cpp(self, class_info, type, generics);
        } break;
        #line 686 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 689 "src/analyzer/Context.pv"
    *type = *find_type;
    #line 690 "src/analyzer/Context.pv"
    return true;
}

#line 693 "src/analyzer/Context.pv"
bool Context__parse_type_trait(struct Context* self, struct Type* type, struct Generics* generics) {
    #line 694 "src/analyzer/Context.pv"
    struct Token* name = Context__expect(self, TOKEN_TYPE__IDENTIFIER);
    #line 695 "src/analyzer/Context.pv"
    if (name == 0) {
        #line 695 "src/analyzer/Context.pv"
        return false;
    }

    #line 697 "src/analyzer/Context.pv"
    struct Array_Type generics_ = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 699 "src/analyzer/Context.pv"
    if (Context__check_next(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 700 "src/analyzer/Context.pv"
        while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 701 "src/analyzer/Context.pv"
            struct Type child_type;

            #line 703 "src/analyzer/Context.pv"
            if (!Context__parse_type(self, &child_type, generics)) {
                #line 704 "src/analyzer/Context.pv"
                return false;
            }

            #line 707 "src/analyzer/Context.pv"
            Array_Type__append(&generics_, child_type);

            #line 709 "src/analyzer/Context.pv"
            if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
                #line 710 "src/analyzer/Context.pv"
                Context__error(self, "Expected , or >");
                #line 711 "src/analyzer/Context.pv"
                return false;
            }
        }
    }

    #line 716 "src/analyzer/Context.pv"
    struct Trait* trait_info = Module__find_trait(self->module, name->value, generics_.length);
    #line 717 "src/analyzer/Context.pv"
    if (trait_info == 0) {
        #line 718 "src/analyzer/Context.pv"
        Context__error_token(self, name, "Unable to find trait with this name");
        #line 719 "src/analyzer/Context.pv"
        return false;
    }

    #line 722 "src/analyzer/Context.pv"
    *type = *Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = 0} }}, &generics_);

    #line 724 "src/analyzer/Context.pv"
    return true;
}

#line 727 "src/analyzer/Context.pv"
struct Type* Context__parse_type2(struct Context* self, struct Generics* generics) {
    #line 728 "src/analyzer/Context.pv"
    struct Type* result = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Type));

    #line 730 "src/analyzer/Context.pv"
    if (!Context__parse_type(self, result, generics)) {
        #line 731 "src/analyzer/Context.pv"
        ArenaAllocator__Allocator__free(self->allocator, result);
        #line 732 "src/analyzer/Context.pv"
        return 0;
    }

    #line 735 "src/analyzer/Context.pv"
    return result;
}

#line 738 "src/analyzer/Context.pv"
struct Type* Context__resolve_type(struct ArenaAllocator* allocator, struct Type* type, struct GenericMap* generics_map, struct GenericMap* fallback_generics_map) {
    #line 739 "src/analyzer/Context.pv"
    switch (type->type) {
        #line 740 "src/analyzer/Context.pv"
        case TYPE__INDIRECT: {
            #line 740 "src/analyzer/Context.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 741 "src/analyzer/Context.pv"
            struct Type* resolved_to = Context__resolve_type(allocator, &indirect->to, generics_map, fallback_generics_map);
            #line 742 "src/analyzer/Context.pv"
            if (resolved_to == 0) {
                #line 742 "src/analyzer/Context.pv"
                return type;
            }

            #line 744 "src/analyzer/Context.pv"
            struct Indirect* resolved = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) {
                .type = indirect->type,
                .to = *resolved_to,
            }});
            #line 748 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 748 "src/analyzer/Context.pv"
                return type;
            }

            #line 750 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = resolved }}, allocator);
        } break;
        #line 752 "src/analyzer/Context.pv"
        case TYPE__SEQUENCE: {
            #line 752 "src/analyzer/Context.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 753 "src/analyzer/Context.pv"
            struct Type* resolved_element = Context__resolve_type(allocator, &sequence->element, generics_map, fallback_generics_map);
            #line 754 "src/analyzer/Context.pv"
            if (resolved_element == 0) {
                #line 754 "src/analyzer/Context.pv"
                return type;
            }

            #line 756 "src/analyzer/Context.pv"
            struct Sequence* resolved = ArenaAllocator__store_Sequence(allocator, (struct Sequence[]){(struct Sequence) {
                .type = sequence->type,
                .element = *resolved_element,
                .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
            }});
            #line 761 "src/analyzer/Context.pv"
            if (resolved == 0) {
                #line 761 "src/analyzer/Context.pv"
                return type;
            }
            #line 762 "src/analyzer/Context.pv"
            resolved->element_pointer = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ArenaAllocator__store_Indirect(allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__POINTER, .to = resolved->element }}) };

            #line 764 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = resolved }}, allocator);
        } break;
        #line 766 "src/analyzer/Context.pv"
        case TYPE__TUPLE: {
            #line 766 "src/analyzer/Context.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 767 "src/analyzer/Context.pv"
            struct Tuple resolved = Tuple__clone(tuple, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

            #line 769 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved.elements);
            #line 769 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 769 "src/analyzer/Context.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 770 "src/analyzer/Context.pv"
                struct Type* resolved_element = Context__resolve_type(allocator, element, generics_map, fallback_generics_map);
                #line 771 "src/analyzer/Context.pv"
                if (resolved_element == 0) {
                    #line 771 "src/analyzer/Context.pv"
                    return type;
                }
                #line 772 "src/analyzer/Context.pv"
                *element = *resolved_element;
            } }

            #line 775 "src/analyzer/Context.pv"
            return Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = ArenaAllocator__store_Tuple(allocator, &resolved) }}, allocator);
        } break;
        #line 777 "src/analyzer/Context.pv"
        case TYPE__PRIMITIVE: {
            #line 778 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 780 "src/analyzer/Context.pv"
        case TYPE__ENUM: {
            #line 780 "src/analyzer/Context.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 780 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 781 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 781 "src/analyzer/Context.pv"
                return type;
            }
            #line 782 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics = GenericMap__clone(generics, allocator);

            #line 784 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics.array);
            #line 784 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 784 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 785 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 786 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 786 "src/analyzer/Context.pv"
                    return type;
                }
                #line 787 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 790 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 791 "src/analyzer/Context.pv"
            resolved_generics.self_type = self_type;
            #line 792 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &resolved_generics)} };

            #line 794 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 796 "src/analyzer/Context.pv"
        case TYPE__STRUCT: {
            #line 796 "src/analyzer/Context.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 796 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 797 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 797 "src/analyzer/Context.pv"
                return type;
            }
            #line 798 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 799 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 800 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 800 "src/analyzer/Context.pv"
                return type;
            }

            #line 802 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 802 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 802 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 803 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 804 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 804 "src/analyzer/Context.pv"
                    return type;
                }
                #line 805 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 808 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 809 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 810 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = resolved_generics} };

            #line 812 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 814 "src/analyzer/Context.pv"
        case TYPE__TRAIT: {
            #line 814 "src/analyzer/Context.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 814 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 815 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 815 "src/analyzer/Context.pv"
                return type;
            }
            #line 816 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 817 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 818 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 818 "src/analyzer/Context.pv"
                return type;
            }

            #line 820 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 820 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 820 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 821 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 822 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 822 "src/analyzer/Context.pv"
                    return type;
                }
                #line 823 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 826 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 827 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 828 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = resolved_generics} };

            #line 830 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 832 "src/analyzer/Context.pv"
        case TYPE__FUNCTION: {
            #line 832 "src/analyzer/Context.pv"
            struct Function* func_info = type->function_value._0;
            #line 832 "src/analyzer/Context.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 833 "src/analyzer/Context.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 833 "src/analyzer/Context.pv"
                return type;
            }
            #line 834 "src/analyzer/Context.pv"
            if (generics == 0) {
                #line 834 "src/analyzer/Context.pv"
                return type;
            }
            #line 835 "src/analyzer/Context.pv"
            struct GenericMap resolved_generics_val = GenericMap__clone(generics, allocator);
            #line 836 "src/analyzer/Context.pv"
            struct GenericMap* resolved_generics = ArenaAllocator__store_GenericMap(allocator, &resolved_generics_val);
            #line 837 "src/analyzer/Context.pv"
            if (resolved_generics == 0) {
                #line 837 "src/analyzer/Context.pv"
                return type;
            }

            #line 839 "src/analyzer/Context.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&resolved_generics->array);
            #line 839 "src/analyzer/Context.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 839 "src/analyzer/Context.pv"
                struct Type* generic = Iter_ref_Type__value(&__iter);

                #line 840 "src/analyzer/Context.pv"
                struct Type* resolved_generic = Context__resolve_type(allocator, generic, generics_map, fallback_generics_map);
                #line 841 "src/analyzer/Context.pv"
                if (resolved_generic == 0) {
                    #line 841 "src/analyzer/Context.pv"
                    return type;
                }
                #line 842 "src/analyzer/Context.pv"
                *generic = *resolved_generic;
            } }

            #line 845 "src/analyzer/Context.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 846 "src/analyzer/Context.pv"
            resolved_generics->self_type = self_type;
            #line 847 "src/analyzer/Context.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = resolved_generics} };

            #line 849 "src/analyzer/Context.pv"
            return self_type;
        } break;
        #line 851 "src/analyzer/Context.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 851 "src/analyzer/Context.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 852 "src/analyzer/Context.pv"
            struct Token* generic_name = gt->generic->name;
            #line 853 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 853 "src/analyzer/Context.pv"
                return type;
            }
            #line 854 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 855 "src/analyzer/Context.pv"
            struct Type* concrete_type = 0;

            #line 857 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 857 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(generics_map, name);
            }
            #line 858 "src/analyzer/Context.pv"
            if (concrete_type == 0 && fallback_generics_map != 0) {
                #line 858 "src/analyzer/Context.pv"
                concrete_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 860 "src/analyzer/Context.pv"
            if (concrete_type != 0) {
                #line 861 "src/analyzer/Context.pv"
                switch (concrete_type->type) {
                    #line 862 "src/analyzer/Context.pv"
                    case TYPE__STRUCT: {
                        #line 862 "src/analyzer/Context.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 863 "src/analyzer/Context.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 863 "src/analyzer/Context.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 863 "src/analyzer/Context.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 864 "src/analyzer/Context.pv"
                            struct Trait* trait_info = impl_info->trait_;
                            #line 865 "src/analyzer/Context.pv"
                            if (trait_info == 0) {
                                #line 865 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 866 "src/analyzer/Context.pv"
                            if (HashMap_str_usize__find(&trait_info->typedefs, &gt->typedef_name) == 0) {
                                #line 866 "src/analyzer/Context.pv"
                                continue;
                            }
                            #line 867 "src/analyzer/Context.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                            #line 868 "src/analyzer/Context.pv"
                            if (typedef_type != 0) {
                                #line 868 "src/analyzer/Context.pv"
                                return typedef_type;
                            }
                        } }
                    } break;
                    #line 871 "src/analyzer/Context.pv"
                    default: {
                    } break;
                }
            }

            #line 875 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 877 "src/analyzer/Context.pv"
        case TYPE__GENERIC: {
            #line 877 "src/analyzer/Context.pv"
            struct Generic* generic = type->generic_value;
            #line 878 "src/analyzer/Context.pv"
            struct Token* generic_name = generic->name;
            #line 879 "src/analyzer/Context.pv"
            if (generic_name == 0) {
                #line 879 "src/analyzer/Context.pv"
                return type;
            }
            #line 880 "src/analyzer/Context.pv"
            struct str name = generic_name->value;
            #line 881 "src/analyzer/Context.pv"
            struct Type* generic_type = 0;

            #line 883 "src/analyzer/Context.pv"
            if (generic_type == 0 && generics_map != 0) {
                #line 884 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(generics_map, name);
            }

            #line 887 "src/analyzer/Context.pv"
            if (generic_type == 0 && fallback_generics_map != 0) {
                #line 888 "src/analyzer/Context.pv"
                generic_type = GenericMap__get(fallback_generics_map, name);
            }

            #line 891 "src/analyzer/Context.pv"
            if (generic_type == 0) {
                #line 892 "src/analyzer/Context.pv"
                uint32_t len = name.length;
                #line 893 "src/analyzer/Context.pv"
                fprintf(stderr, "Could not resolve generic %.*s generics1\n", len, name.ptr);
                #line 894 "src/analyzer/Context.pv"
                return type;
            }

            #line 897 "src/analyzer/Context.pv"
            return generic_type;
        } break;
        #line 899 "src/analyzer/Context.pv"
        case TYPE__SELF: {
            #line 900 "src/analyzer/Context.pv"
            if (generics_map != 0) {
                #line 901 "src/analyzer/Context.pv"
                struct Type* self_type = generics_map->self_type;
                #line 902 "src/analyzer/Context.pv"
                if (self_type != 0) {
                    #line 902 "src/analyzer/Context.pv"
                    return self_type;
                }
            }

            #line 905 "src/analyzer/Context.pv"
            if (fallback_generics_map != 0) {
                #line 906 "src/analyzer/Context.pv"
                struct Type* fallback_self_type = fallback_generics_map->self_type;
                #line 907 "src/analyzer/Context.pv"
                if (fallback_self_type != 0) {
                    #line 907 "src/analyzer/Context.pv"
                    return fallback_self_type;
                }
                #line 908 "src/analyzer/Context.pv"
                return type;
            }

            #line 911 "src/analyzer/Context.pv"
            return type;
        } break;
        #line 913 "src/analyzer/Context.pv"
        default: {
        } break;
    }

    #line 916 "src/analyzer/Context.pv"
    return type;
}

#line 919 "src/analyzer/Context.pv"
struct Type* Context__get_path_narrowing(struct Context* self, struct str path) {
    #line 920 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 920 "src/analyzer/Context.pv"
        return 0;
    }

    #line 922 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 922 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 922 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 923 "src/analyzer/Context.pv"
        struct Type* t = HashMap_str_Type__find(&scope->values, &path);
        #line 924 "src/analyzer/Context.pv"
        if (t != 0) {
            #line 924 "src/analyzer/Context.pv"
            return t;
        }
    } }

    #line 927 "src/analyzer/Context.pv"
    return 0;
}

#line 930 "src/analyzer/Context.pv"
void Context__set_narrowed(struct Context* self, struct str name, struct Type* type) {
    #line 931 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 932 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 932 "src/analyzer/Context.pv"
        return;
    }
    #line 934 "src/analyzer/Context.pv"
    struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
    #line 935 "src/analyzer/Context.pv"
    if (existing != 0 && HashMap_str_Type__find(&scope->narrow_originals, &name) == 0) {
        #line 936 "src/analyzer/Context.pv"
        HashMap_str_Type__insert(&scope->narrow_originals, name, *existing);
    }
    #line 938 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name, *type);
}

#line 941 "src/analyzer/Context.pv"
struct Type* Context__get_broadened_type(struct Context* self, struct str name) {
    #line 942 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 942 "src/analyzer/Context.pv"
        return 0;
    }
    #line 943 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 943 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 943 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 944 "src/analyzer/Context.pv"
        struct Type* type = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 945 "src/analyzer/Context.pv"
        if (type != 0) {
            #line 945 "src/analyzer/Context.pv"
            return type;
        }
    } }
    #line 947 "src/analyzer/Context.pv"
    return 0;
}

#line 950 "src/analyzer/Context.pv"
bool Context__broaden_if_narrowed(struct Context* self, struct str name) {
    #line 951 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 951 "src/analyzer/Context.pv"
        return false;
    }
    #line 952 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 953 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 954 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 955 "src/analyzer/Context.pv"
        struct Type* original = HashMap_str_Type__find(&scope->narrow_originals, &name);
        #line 956 "src/analyzer/Context.pv"
        if (original != 0) {
            #line 957 "src/analyzer/Context.pv"
            struct Type original_type = *original;
            #line 958 "src/analyzer/Context.pv"
            HashMap_str_Type__remove(&scope->narrow_originals, &name);
            #line 959 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, original_type);
            #line 960 "src/analyzer/Context.pv"
            return true;
        }
        #line 962 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 964 "src/analyzer/Context.pv"
    return false;
}

#line 967 "src/analyzer/Context.pv"
bool Context__update_value_type(struct Context* self, struct str name, struct Type* type) {
    #line 968 "src/analyzer/Context.pv"
    if (self->scopes.length == 0) {
        #line 968 "src/analyzer/Context.pv"
        return false;
    }
    #line 969 "src/analyzer/Context.pv"
    struct Scope* scope_front = self->scopes.data;
    #line 970 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 971 "src/analyzer/Context.pv"
    while (scope != 0 && scope >= scope_front) {
        #line 972 "src/analyzer/Context.pv"
        struct Type* existing = HashMap_str_Type__find(&scope->values, &name);
        #line 973 "src/analyzer/Context.pv"
        if (existing != 0) {
            #line 974 "src/analyzer/Context.pv"
            HashMap_str_Type__insert(&scope->values, name, *type);
            #line 975 "src/analyzer/Context.pv"
            return true;
        }

        #line 978 "src/analyzer/Context.pv"
        scope = scope - 1;
    }
    #line 980 "src/analyzer/Context.pv"
    return false;
}

#line 983 "src/analyzer/Context.pv"
bool Context__set_value(struct Context* self, struct Token* name, struct Type* type) {
    #line 984 "src/analyzer/Context.pv"
    struct Scope* scope = Array_Scope__back(&self->scopes);
    #line 985 "src/analyzer/Context.pv"
    if (scope == 0) {
        #line 985 "src/analyzer/Context.pv"
        return false;
    }

    #line 987 "src/analyzer/Context.pv"
    if (HashMap_str_Type__find(&scope->values, &name->value) != 0) {
        #line 988 "src/analyzer/Context.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 989 "src/analyzer/Context.pv"
        String__append(&message, (struct str){ .ptr = "Variable name already in use: ", .length = strlen("Variable name already in use: ") });
        #line 990 "src/analyzer/Context.pv"
        String__append(&message, name->value);
        #line 991 "src/analyzer/Context.pv"
        Context__error_token(self, name, String__c_str(&message));
        #line 992 "src/analyzer/Context.pv"
        return false;
    }

    #line 995 "src/analyzer/Context.pv"
    HashMap_str_Type__insert(&scope->values, name->value, *type);

    #line 997 "src/analyzer/Context.pv"
    return true;
}

#line 1000 "src/analyzer/Context.pv"
struct Type* Context__get_value(struct Context* self, struct str name) {
    #line 1001 "src/analyzer/Context.pv"
    if (self->scopes.length > 0) {
        #line 1002 "src/analyzer/Context.pv"
        struct Scope* scope_front = self->scopes.data;
        #line 1003 "src/analyzer/Context.pv"
        struct Scope* scope = Array_Scope__back(&self->scopes);

        #line 1005 "src/analyzer/Context.pv"
        while (scope != 0 && scope >= scope_front) {
            #line 1006 "src/analyzer/Context.pv"
            struct Type* type = HashMap_str_Type__find(&scope->values, &name);
            #line 1007 "src/analyzer/Context.pv"
            if (type != 0) {
                #line 1007 "src/analyzer/Context.pv"
                return type;
            }

            #line 1009 "src/analyzer/Context.pv"
            scope = scope - 1;
        }
    }

    #line 1013 "src/analyzer/Context.pv"
    struct Type* func = Module__find_function(self->module, name);
    #line 1014 "src/analyzer/Context.pv"
    if (func != 0) {
        #line 1014 "src/analyzer/Context.pv"
        return func;
    }

    #line 1016 "src/analyzer/Context.pv"
    return Module__find_value(self->module, name);
}

#line 1019 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_defer_statements(struct Context* self) {
    #line 1020 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 1022 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 1022 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 1022 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 1023 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 1025 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 1026 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 1026 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 1026 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 1027 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }
        }
    } }

    #line 1032 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 1035 "src/analyzer/Context.pv"
struct Array_DeferStatement Context__get_loop_defer_statements(struct Context* self) {
    #line 1036 "src/analyzer/Context.pv"
    struct Array_DeferStatement defer_statements = Array_DeferStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 1038 "src/analyzer/Context.pv"
    { struct Iter_ref_Scope __iter = Iter_ref_Scope__reverse(Array_Scope__iter(&self->scopes));
    #line 1038 "src/analyzer/Context.pv"
    while (Iter_ref_Scope__next(&__iter)) {
        #line 1038 "src/analyzer/Context.pv"
        struct Scope* scope = Iter_ref_Scope__value(&__iter);

        #line 1039 "src/analyzer/Context.pv"
        struct Block* block = scope->block;

        #line 1041 "src/analyzer/Context.pv"
        if (block != 0) {
            #line 1042 "src/analyzer/Context.pv"
            { struct Iter_ref_DeferStatement __iter = Iter_ref_DeferStatement__reverse(Array_DeferStatement__iter(&block->defer_statements));
            #line 1042 "src/analyzer/Context.pv"
            while (Iter_ref_DeferStatement__next(&__iter)) {
                #line 1042 "src/analyzer/Context.pv"
                struct DeferStatement* defer_statement = Iter_ref_DeferStatement__value(&__iter);

                #line 1043 "src/analyzer/Context.pv"
                Array_DeferStatement__append(&defer_statements, *defer_statement);
            } }

            #line 1046 "src/analyzer/Context.pv"
            if (block->is_loop) {
                #line 1046 "src/analyzer/Context.pv"
                return defer_statements;
            }
        }
    } }

    #line 1050 "src/analyzer/Context.pv"
    return defer_statements;
}

#line 1053 "src/analyzer/Context.pv"
struct Array_Type Context__parse_generics(struct Context* self, struct Generics* generics) {
    #line 1054 "src/analyzer/Context.pv"
    struct Array_Type generic_inputs = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 1056 "src/analyzer/Context.pv"
    if (!Context__expect_value(self, TOKEN_TYPE__SYMBOL, "<")) {
        #line 1056 "src/analyzer/Context.pv"
        return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
    }

    #line 1058 "src/analyzer/Context.pv"
    while (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ">")) {
        #line 1059 "src/analyzer/Context.pv"
        struct Type child_type;

        #line 1061 "src/analyzer/Context.pv"
        if (!Context__parse_type(self, &child_type, generics)) {
            #line 1061 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }

        #line 1063 "src/analyzer/Context.pv"
        Array_Type__append(&generic_inputs, child_type);

        #line 1065 "src/analyzer/Context.pv"
        if (!Context__check_next(self, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(self, TOKEN_TYPE__SYMBOL, ">")) {
            #line 1066 "src/analyzer/Context.pv"
            Context__error(self, "Expected , or >");
            #line 1067 "src/analyzer/Context.pv"
            return (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 };
        }
    }

    #line 1071 "src/analyzer/Context.pv"
    return generic_inputs;
}

#line 1074 "src/analyzer/Context.pv"
bool Context__validate_generic_constraints(struct Context* self, struct Generics* generics, struct Array_Type* usage_types) {
    #line 1075 "src/analyzer/Context.pv"
    uintptr_t i = 0;
    #line 1076 "src/analyzer/Context.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 1077 "src/analyzer/Context.pv"
        struct Generic* generic = &generics->array.data[i];
        #line 1078 "src/analyzer/Context.pv"
        struct Type* usage_type = &usage_types->data[i];

        #line 1080 "src/analyzer/Context.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 1080 "src/analyzer/Context.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 1080 "src/analyzer/Context.pv"
            struct Trait* required_trait = *Iter_ref_ref_Trait__value(&__iter);

            #line 1081 "src/analyzer/Context.pv"
            bool implements = false;
            #line 1082 "src/analyzer/Context.pv"
            switch (usage_type->type) {
                #line 1083 "src/analyzer/Context.pv"
                case TYPE__STRUCT: {
                    #line 1083 "src/analyzer/Context.pv"
                    struct Struct* struct_info = usage_type->struct_value._0;
                    #line 1084 "src/analyzer/Context.pv"
                    struct str trait_key = Trait__get_key(required_trait, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                    #line 1085 "src/analyzer/Context.pv"
                    implements = HashMap_str_tuple_ref_Trait_ref_Type__find(&struct_info->traits, &trait_key) != 0;
                } break;
                #line 1087 "src/analyzer/Context.pv"
                case TYPE__GENERIC: {
                    #line 1087 "src/analyzer/Context.pv"
                    struct Generic* generic_info = usage_type->generic_value;
                    #line 1088 "src/analyzer/Context.pv"
                    { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic_info->traits);
                    #line 1088 "src/analyzer/Context.pv"
                    while (Iter_ref_ref_Trait__next(&__iter)) {
                        #line 1088 "src/analyzer/Context.pv"
                        struct Trait* generic_trait = *Iter_ref_ref_Trait__value(&__iter);

                        #line 1089 "src/analyzer/Context.pv"
                        if (generic_trait == required_trait) {
                            #line 1089 "src/analyzer/Context.pv"
                            implements = true;
                        }
                    } }
                } break;
                #line 1092 "src/analyzer/Context.pv"
                default: {
                    #line 1092 "src/analyzer/Context.pv"
                    implements = true;
                } break;
            }
            #line 1094 "src/analyzer/Context.pv"
            if (!implements) {
                #line 1095 "src/analyzer/Context.pv"
                struct Token* name = required_trait->name;
                #line 1096 "src/analyzer/Context.pv"
                if (name == 0) {
                    #line 1097 "src/analyzer/Context.pv"
                    Context__error(self, "Type does not implement required trait");
                    #line 1098 "src/analyzer/Context.pv"
                    return false;
                }

                #line 1101 "src/analyzer/Context.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
                #line 1102 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "Type does not implement required trait '", .length = strlen("Type does not implement required trait '") });
                #line 1103 "src/analyzer/Context.pv"
                String__append(&message, name->value);
                #line 1104 "src/analyzer/Context.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 1105 "src/analyzer/Context.pv"
                Context__error(self, String__c_str(&message));
                #line 1106 "src/analyzer/Context.pv"
                return false;
            }
        } }

        #line 1110 "src/analyzer/Context.pv"
        i += 1;
    }
    #line 1112 "src/analyzer/Context.pv"
    return true;
}
