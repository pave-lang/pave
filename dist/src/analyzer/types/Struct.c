#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/types/Struct.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <usize.h>
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

#line 30 "src/analyzer/types/Struct.pv"
struct Struct Struct__new(struct Module* module) {
    #line 31 "src/analyzer/types/Struct.pv"
    struct Context context = module->context;

    #line 33 "src/analyzer/types/Struct.pv"
    return (struct Struct) {
        .module = module,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .fields = HashMap_str_StructField__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .traits = HashMap_str_tuple_ref_Trait_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .name = 0,
        .token_start = 0,
        .token_end = 0,
        .generic_arity = 0,
        .type = STRUCT_TYPE__INCOMPLETE,
    };
}

#line 47 "src/analyzer/types/Struct.pv"
struct Struct Struct__parse(struct Module* module) {
    #line 48 "src/analyzer/types/Struct.pv"
    struct Context* context = &module->context;
    #line 49 "src/analyzer/types/Struct.pv"
    struct Struct node = Struct__new(module);

    #line 51 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "struct")) {
        #line 51 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 53 "src/analyzer/types/Struct.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 54 "src/analyzer/types/Struct.pv"
    if (name == 0) {
        #line 54 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 56 "src/analyzer/types/Struct.pv"
    node.token_start = context->pos;

    #line 58 "src/analyzer/types/Struct.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 59 "src/analyzer/types/Struct.pv"
        uintptr_t depth = 1;
        #line 60 "src/analyzer/types/Struct.pv"
        bool expect_generic = true;
        #line 61 "src/analyzer/types/Struct.pv"
        while (context->pos < context->length && depth > 0) {
            #line 62 "src/analyzer/types/Struct.pv"
            if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                #line 63 "src/analyzer/types/Struct.pv"
                depth += 1;
            } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, ">")) {
                #line 65 "src/analyzer/types/Struct.pv"
                depth -= 1;
                #line 66 "src/analyzer/types/Struct.pv"
                if (usize__Eq_usize__eq(depth, 0)) {
                    #line 66 "src/analyzer/types/Struct.pv"
                    break;
                }
            } else if (usize__Eq_usize__eq(depth, 1) && expect_generic && Context__check(context, TOKEN_TYPE__IDENTIFIER)) {
                #line 68 "src/analyzer/types/Struct.pv"
                node.generic_arity += 1;
                #line 69 "src/analyzer/types/Struct.pv"
                expect_generic = false;
            } else if (usize__Eq_usize__eq(depth, 1) && Context__check_value(context, TOKEN_TYPE__SYMBOL, ",")) {
                #line 71 "src/analyzer/types/Struct.pv"
                expect_generic = true;
            }
            #line 73 "src/analyzer/types/Struct.pv"
            Context__next_token(context);
        }
        #line 75 "src/analyzer/types/Struct.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">")) {
            #line 75 "src/analyzer/types/Struct.pv"
            return node;
        }
    }

    #line 78 "src/analyzer/types/Struct.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 79 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__INCOMPLETE;
    } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 81 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__TUPLE;
        #line 82 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "(", ")") || !Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 82 "src/analyzer/types/Struct.pv"
            return node;
        }
    } else {
        #line 84 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__FIELD;
        #line 85 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "{", "}")) {
            #line 85 "src/analyzer/types/Struct.pv"
            return node;
        }
    }

    #line 88 "src/analyzer/types/Struct.pv"
    node.token_end = context->pos;

    #line 90 "src/analyzer/types/Struct.pv"
    node.name = name;
    #line 91 "src/analyzer/types/Struct.pv"
    return node;
}

#line 94 "src/analyzer/types/Struct.pv"
bool Struct__prefill_types(struct Struct* self) {
    #line 95 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 96 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 98 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 98 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 100 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 101 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 101 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{");
        } break;
        #line 102 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 102 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(");
        } break;
        #line 103 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 103 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 107 "src/analyzer/types/Struct.pv"
bool Struct__fill_types(struct Struct* self) {
    #line 108 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 109 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 111 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 111 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 113 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 114 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 114 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_field(self);
        } break;
        #line 115 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 115 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_tuple(self);
        } break;
        #line 116 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 116 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 120 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_field(struct Struct* self) {
    #line 121 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 123 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 123 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 125 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 126 "src/analyzer/types/Struct.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 127 "src/analyzer/types/Struct.pv"
        if (name == 0) {
            #line 127 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 129 "src/analyzer/types/Struct.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
            #line 129 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 131 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 132 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 132 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 134 "src/analyzer/types/Struct.pv"
        uintptr_t default_token_start = 0;
        #line 135 "src/analyzer/types/Struct.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 136 "src/analyzer/types/Struct.pv"
            default_token_start = context->pos;
            #line 137 "src/analyzer/types/Struct.pv"
            uintptr_t depth = 0;
            #line 138 "src/analyzer/types/Struct.pv"
            while (context->pos < self->token_end) {
                #line 139 "src/analyzer/types/Struct.pv"
                bool is_open = Context__check_value(context, TOKEN_TYPE__SYMBOL, "(") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "[");
                #line 140 "src/analyzer/types/Struct.pv"
                bool is_close = Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "]") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 141 "src/analyzer/types/Struct.pv"
                bool is_comma = Context__check_value(context, TOKEN_TYPE__SYMBOL, ",");

                #line 143 "src/analyzer/types/Struct.pv"
                if (is_open) {
                    #line 144 "src/analyzer/types/Struct.pv"
                    depth += 1;
                } else if (is_close) {
                    #line 146 "src/analyzer/types/Struct.pv"
                    if (usize__Eq_usize__eq(depth, 0)) {
                        #line 146 "src/analyzer/types/Struct.pv"
                        break;
                    }
                    #line 147 "src/analyzer/types/Struct.pv"
                    depth -= 1;
                } else if (is_comma && usize__Eq_usize__eq(depth, 0)) {
                    #line 149 "src/analyzer/types/Struct.pv"
                    break;
                }
                #line 151 "src/analyzer/types/Struct.pv"
                Context__next_token(context);
            }
        }

        #line 155 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = name,
            .type = type,
            .default_token_start = default_token_start,
        };

        #line 161 "src/analyzer/types/Struct.pv"
        switch (type.type) {
            #line 162 "src/analyzer/types/Struct.pv"
            case TYPE__FUNCTION: {
                #line 162 "src/analyzer/types/Struct.pv"
                struct Function* func_info = type.function_value._0;
                #line 163 "src/analyzer/types/Struct.pv"
                func_info->name = name;
                #line 164 "src/analyzer/types/Struct.pv"
                func_info->type = FUNCTION_TYPE__BUILTIN;
                #line 165 "src/analyzer/types/Struct.pv"
                func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = self, ._1 = 0, ._2 = 0} };
            } break;
            #line 167 "src/analyzer/types/Struct.pv"
            default: {
            } break;
        }

        #line 170 "src/analyzer/types/Struct.pv"
        HashMap_str_StructField__insert(&self->fields, name->value, field);

        #line 172 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 173 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 174 "src/analyzer/types/Struct.pv"
            return false;
        }
    }

    #line 178 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 178 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 180 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 181 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at closing bracket for struct definition");
    }

    #line 184 "src/analyzer/types/Struct.pv"
    return true;
}

#line 187 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self) {
    #line 188 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 190 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 190 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 192 "src/analyzer/types/Struct.pv"
    uintptr_t field_index = 0;
    #line 193 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 194 "src/analyzer/types/Struct.pv"
        struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 195 "src/analyzer/types/Struct.pv"
        String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 196 "src/analyzer/types/Struct.pv"
        String__append_usize(&name, field_index);
        #line 197 "src/analyzer/types/Struct.pv"
        struct str name_str = String__as_str(&name);

        #line 199 "src/analyzer/types/Struct.pv"
        struct Token name_token = *Context__current(context);
        #line 200 "src/analyzer/types/Struct.pv"
        name_token.value = name_str;

        #line 202 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 203 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 203 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 205 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = ArenaAllocator__store_Token(context->allocator, &name_token),
            .type = type,
            .default_token_start = 0,
        };

        #line 211 "src/analyzer/types/Struct.pv"
        HashMap_str_StructField__insert(&self->fields, name_str, field);

        #line 213 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 214 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
            #line 215 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 218 "src/analyzer/types/Struct.pv"
        field_index += 1;
    }

    #line 221 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 221 "src/analyzer/types/Struct.pv"
        return false;
    }
    #line 222 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 222 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 224 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 225 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at end of struct definition");
    }

    #line 228 "src/analyzer/types/Struct.pv"
    return true;
}

#line 231 "src/analyzer/types/Struct.pv"
bool Struct__is_newtype(struct Struct* self) {
    #line 232 "src/analyzer/types/Struct.pv"
    return (self->type == STRUCT_TYPE__TUPLE) && (usize__Eq_usize__eq(self->fields.length, 1));
}
