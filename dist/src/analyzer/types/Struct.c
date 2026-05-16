#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/types/Struct.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <analyzer/types/Type.h>
#include <analyzer/Root.h>
#include <analyzer/types/StructField.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/FunctionParent.h>
#include <std/str.h>
#include <std/String.h>
#include <analyzer/types/Struct.h>

#include <analyzer/types/Struct.h>

#line 29 "src/analyzer/types/Struct.pv"
struct Struct Struct__new(struct Module* module) {
    #line 30 "src/analyzer/types/Struct.pv"
    struct Context context = module->context;

    #line 32 "src/analyzer/types/Struct.pv"
    return (struct Struct) {
        .module = module,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .fields = HashMap_str_StructField__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .traits = HashMap_str_tuple_ref_Trait_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
    };
}

#line 41 "src/analyzer/types/Struct.pv"
struct Struct Struct__parse(struct Module* module) {
    #line 42 "src/analyzer/types/Struct.pv"
    struct Context* context = &module->context;
    #line 43 "src/analyzer/types/Struct.pv"
    struct Struct node = Struct__new(module);

    #line 45 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "struct")) {
        #line 45 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 47 "src/analyzer/types/Struct.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 48 "src/analyzer/types/Struct.pv"
    if (name == 0) {
        #line 48 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 50 "src/analyzer/types/Struct.pv"
    node.token_start = context->pos;

    #line 52 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 52 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 54 "src/analyzer/types/Struct.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 55 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__INCOMPLETE;
    } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 57 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__TUPLE;
        #line 58 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "(", ")") || !Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 58 "src/analyzer/types/Struct.pv"
            return node;
        }
    } else {
        #line 60 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__FIELD;
        #line 61 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "{", "}")) {
            #line 61 "src/analyzer/types/Struct.pv"
            return node;
        }
    }

    #line 64 "src/analyzer/types/Struct.pv"
    node.token_end = context->pos;

    #line 66 "src/analyzer/types/Struct.pv"
    node.name = name;
    #line 67 "src/analyzer/types/Struct.pv"
    return node;
}

#line 70 "src/analyzer/types/Struct.pv"
bool Struct__prefill_types(struct Struct* self) {
    #line 71 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 72 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 74 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 74 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 76 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 77 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 77 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{");
        } break;
        #line 78 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 78 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(");
        } break;
        #line 79 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 79 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 83 "src/analyzer/types/Struct.pv"
bool Struct__fill_types(struct Struct* self) {
    #line 84 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 85 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 87 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 87 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 89 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 90 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 90 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_field(self);
        } break;
        #line 91 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 91 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_tuple(self);
        } break;
        #line 92 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 92 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 96 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_field(struct Struct* self) {
    #line 97 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 99 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 99 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 101 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 102 "src/analyzer/types/Struct.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 103 "src/analyzer/types/Struct.pv"
        if (name == 0) {
            #line 103 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 105 "src/analyzer/types/Struct.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
            #line 105 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 107 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 108 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 108 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 110 "src/analyzer/types/Struct.pv"
        uintptr_t default_token_start = 0;
        #line 111 "src/analyzer/types/Struct.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 112 "src/analyzer/types/Struct.pv"
            default_token_start = context->pos;
            #line 113 "src/analyzer/types/Struct.pv"
            uintptr_t depth = 0;
            #line 114 "src/analyzer/types/Struct.pv"
            while (context->pos < self->token_end) {
                #line 115 "src/analyzer/types/Struct.pv"
                bool is_open = Context__check_value(context, TOKEN_TYPE__SYMBOL, "(") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "[");
                #line 116 "src/analyzer/types/Struct.pv"
                bool is_close = Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "]") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 117 "src/analyzer/types/Struct.pv"
                bool is_comma = Context__check_value(context, TOKEN_TYPE__SYMBOL, ",");

                #line 119 "src/analyzer/types/Struct.pv"
                if (is_open) {
                    #line 120 "src/analyzer/types/Struct.pv"
                    depth += 1;
                } else if (is_close) {
                    #line 122 "src/analyzer/types/Struct.pv"
                    if (depth == 0) {
                        #line 122 "src/analyzer/types/Struct.pv"
                        break;
                    }
                    #line 123 "src/analyzer/types/Struct.pv"
                    depth -= 1;
                } else if (is_comma && depth == 0) {
                    #line 125 "src/analyzer/types/Struct.pv"
                    break;
                }
                #line 127 "src/analyzer/types/Struct.pv"
                Context__next_token(context);
            }
        }

        #line 131 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = name,
            .type = type,
            .default_token_start = default_token_start,
        };

        #line 137 "src/analyzer/types/Struct.pv"
        switch (type.type) {
            #line 138 "src/analyzer/types/Struct.pv"
            case TYPE__FUNCTION: {
                #line 138 "src/analyzer/types/Struct.pv"
                struct Function* func_info = type.function_value._0;
                #line 139 "src/analyzer/types/Struct.pv"
                func_info->name = name;
                #line 140 "src/analyzer/types/Struct.pv"
                func_info->type = FUNCTION_TYPE__BUILTIN;
                #line 141 "src/analyzer/types/Struct.pv"
                func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = self, ._1 = 0, ._2 = 0} };
            } break;
            #line 143 "src/analyzer/types/Struct.pv"
            default: {
            } break;
        }

        #line 146 "src/analyzer/types/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name->value, field)) {
            #line 146 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 148 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 149 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 150 "src/analyzer/types/Struct.pv"
            return false;
        }
    }

    #line 154 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 154 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 156 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 157 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at closing bracket for struct definition");
    }

    #line 160 "src/analyzer/types/Struct.pv"
    return true;
}

#line 163 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self) {
    #line 164 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 166 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 166 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 168 "src/analyzer/types/Struct.pv"
    uintptr_t field_index = 0;
    #line 169 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 170 "src/analyzer/types/Struct.pv"
        struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 171 "src/analyzer/types/Struct.pv"
        String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 172 "src/analyzer/types/Struct.pv"
        String__append_usize(&name, field_index);
        #line 173 "src/analyzer/types/Struct.pv"
        struct str name_str = String__as_str(&name);

        #line 175 "src/analyzer/types/Struct.pv"
        struct Token name_token = *Context__current(context);
        #line 176 "src/analyzer/types/Struct.pv"
        name_token.value = name_str;

        #line 178 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 179 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 179 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 181 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = ArenaAllocator__store_Token(context->allocator, &name_token),
            .type = type,
            .default_token_start = 0,
        };

        #line 187 "src/analyzer/types/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name_str, field)) {
            #line 187 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 189 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 190 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
            #line 191 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 194 "src/analyzer/types/Struct.pv"
        field_index += 1;
    }

    #line 197 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 197 "src/analyzer/types/Struct.pv"
        return false;
    }
    #line 198 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 198 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 200 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 201 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at end of struct definition");
    }

    #line 204 "src/analyzer/types/Struct.pv"
    return true;
}

#line 207 "src/analyzer/types/Struct.pv"
bool Struct__is_newtype(struct Struct* self) {
    #line 208 "src/analyzer/types/Struct.pv"
    return (self->type == STRUCT_TYPE__TUPLE) && (self->fields.length == 1);
}
