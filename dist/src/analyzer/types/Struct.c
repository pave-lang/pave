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
        .name = 0,
        .token_start = 0,
        .token_end = 0,
        .type = STRUCT_TYPE__INCOMPLETE,
    };
}

#line 45 "src/analyzer/types/Struct.pv"
struct Struct Struct__parse(struct Module* module) {
    #line 46 "src/analyzer/types/Struct.pv"
    struct Context* context = &module->context;
    #line 47 "src/analyzer/types/Struct.pv"
    struct Struct node = Struct__new(module);

    #line 49 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "struct")) {
        #line 49 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 51 "src/analyzer/types/Struct.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 52 "src/analyzer/types/Struct.pv"
    if (name == 0) {
        #line 52 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 54 "src/analyzer/types/Struct.pv"
    node.token_start = context->pos;

    #line 56 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 56 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 58 "src/analyzer/types/Struct.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 59 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__INCOMPLETE;
    } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 61 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__TUPLE;
        #line 62 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "(", ")") || !Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 62 "src/analyzer/types/Struct.pv"
            return node;
        }
    } else {
        #line 64 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__FIELD;
        #line 65 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "{", "}")) {
            #line 65 "src/analyzer/types/Struct.pv"
            return node;
        }
    }

    #line 68 "src/analyzer/types/Struct.pv"
    node.token_end = context->pos;

    #line 70 "src/analyzer/types/Struct.pv"
    node.name = name;
    #line 71 "src/analyzer/types/Struct.pv"
    return node;
}

#line 74 "src/analyzer/types/Struct.pv"
bool Struct__prefill_types(struct Struct* self) {
    #line 75 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 76 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 78 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 78 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 80 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 81 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 81 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{");
        } break;
        #line 82 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 82 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(");
        } break;
        #line 83 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 83 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 87 "src/analyzer/types/Struct.pv"
bool Struct__fill_types(struct Struct* self) {
    #line 88 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 89 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 91 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 91 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 93 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 94 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 94 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_field(self);
        } break;
        #line 95 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 95 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_tuple(self);
        } break;
        #line 96 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 96 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 100 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_field(struct Struct* self) {
    #line 101 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 103 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 103 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 105 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 106 "src/analyzer/types/Struct.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 107 "src/analyzer/types/Struct.pv"
        if (name == 0) {
            #line 107 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 109 "src/analyzer/types/Struct.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
            #line 109 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 111 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 112 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 112 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 114 "src/analyzer/types/Struct.pv"
        uintptr_t default_token_start = 0;
        #line 115 "src/analyzer/types/Struct.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 116 "src/analyzer/types/Struct.pv"
            default_token_start = context->pos;
            #line 117 "src/analyzer/types/Struct.pv"
            uintptr_t depth = 0;
            #line 118 "src/analyzer/types/Struct.pv"
            while (context->pos < self->token_end) {
                #line 119 "src/analyzer/types/Struct.pv"
                bool is_open = Context__check_value(context, TOKEN_TYPE__SYMBOL, "(") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "[");
                #line 120 "src/analyzer/types/Struct.pv"
                bool is_close = Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "]") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 121 "src/analyzer/types/Struct.pv"
                bool is_comma = Context__check_value(context, TOKEN_TYPE__SYMBOL, ",");

                #line 123 "src/analyzer/types/Struct.pv"
                if (is_open) {
                    #line 124 "src/analyzer/types/Struct.pv"
                    depth += 1;
                } else if (is_close) {
                    #line 126 "src/analyzer/types/Struct.pv"
                    if (depth == 0) {
                        #line 126 "src/analyzer/types/Struct.pv"
                        break;
                    }
                    #line 127 "src/analyzer/types/Struct.pv"
                    depth -= 1;
                } else if (is_comma && depth == 0) {
                    #line 129 "src/analyzer/types/Struct.pv"
                    break;
                }
                #line 131 "src/analyzer/types/Struct.pv"
                Context__next_token(context);
            }
        }

        #line 135 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = name,
            .type = type,
            .default_token_start = default_token_start,
        };

        #line 141 "src/analyzer/types/Struct.pv"
        switch (type.type) {
            #line 142 "src/analyzer/types/Struct.pv"
            case TYPE__FUNCTION: {
                #line 142 "src/analyzer/types/Struct.pv"
                struct Function* func_info = type.function_value._0;
                #line 143 "src/analyzer/types/Struct.pv"
                func_info->name = name;
                #line 144 "src/analyzer/types/Struct.pv"
                func_info->type = FUNCTION_TYPE__BUILTIN;
                #line 145 "src/analyzer/types/Struct.pv"
                func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = self, ._1 = 0, ._2 = 0} };
            } break;
            #line 147 "src/analyzer/types/Struct.pv"
            default: {
            } break;
        }

        #line 150 "src/analyzer/types/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name->value, field)) {
            #line 150 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 152 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 153 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 154 "src/analyzer/types/Struct.pv"
            return false;
        }
    }

    #line 158 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 158 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 160 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 161 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at closing bracket for struct definition");
    }

    #line 164 "src/analyzer/types/Struct.pv"
    return true;
}

#line 167 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self) {
    #line 168 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 170 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 170 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 172 "src/analyzer/types/Struct.pv"
    uintptr_t field_index = 0;
    #line 173 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 174 "src/analyzer/types/Struct.pv"
        struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 175 "src/analyzer/types/Struct.pv"
        String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 176 "src/analyzer/types/Struct.pv"
        String__append_usize(&name, field_index);
        #line 177 "src/analyzer/types/Struct.pv"
        struct str name_str = String__as_str(&name);

        #line 179 "src/analyzer/types/Struct.pv"
        struct Token name_token = *Context__current(context);
        #line 180 "src/analyzer/types/Struct.pv"
        name_token.value = name_str;

        #line 182 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 183 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 183 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 185 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = ArenaAllocator__store_Token(context->allocator, &name_token),
            .type = type,
            .default_token_start = 0,
        };

        #line 191 "src/analyzer/types/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name_str, field)) {
            #line 191 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 193 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 194 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
            #line 195 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 198 "src/analyzer/types/Struct.pv"
        field_index += 1;
    }

    #line 201 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 201 "src/analyzer/types/Struct.pv"
        return false;
    }
    #line 202 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 202 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 204 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 205 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at end of struct definition");
    }

    #line 208 "src/analyzer/types/Struct.pv"
    return true;
}

#line 211 "src/analyzer/types/Struct.pv"
bool Struct__is_newtype(struct Struct* self) {
    #line 212 "src/analyzer/types/Struct.pv"
    return (self->type == STRUCT_TYPE__TUPLE) && (self->fields.length == 1);
}
