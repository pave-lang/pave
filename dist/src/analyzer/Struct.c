#include <analyzer/Module.h>
#include <analyzer/Context.h>
#include <analyzer/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_StructField.h>
#include <std/str.h>
#include <analyzer/StructField.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Trait.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/String.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <analyzer/StructType.h>
#include <analyzer/Type.h>
#include <analyzer/Root.h>
#include <analyzer/Function.h>
#include <analyzer/FunctionType.h>
#include <analyzer/FunctionParent.h>

#include <analyzer/Struct.h>

#line 27 "src/analyzer/Struct.pv"
struct Struct Struct__new(struct Module* module) {
    #line 28 "src/analyzer/Struct.pv"
    struct Context context = module->context;

    #line 30 "src/analyzer/Struct.pv"
    return (struct Struct) {
        .module = module,
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .fields = HashMap_str_StructField__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .impls = Array_ref_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
    };
}

#line 39 "src/analyzer/Struct.pv"
struct Struct Struct__parse(struct Module* module) {
    #line 40 "src/analyzer/Struct.pv"
    struct Context* context = &module->context;
    #line 41 "src/analyzer/Struct.pv"
    struct Struct node = Struct__new(module);

    #line 43 "src/analyzer/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "struct")) {
        #line 43 "src/analyzer/Struct.pv"
        return node;
    }

    #line 45 "src/analyzer/Struct.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 46 "src/analyzer/Struct.pv"
    if (name == 0) {
        #line 46 "src/analyzer/Struct.pv"
        return node;
    }

    #line 48 "src/analyzer/Struct.pv"
    node.token_start = context->pos;

    #line 50 "src/analyzer/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 50 "src/analyzer/Struct.pv"
        return node;
    }

    #line 52 "src/analyzer/Struct.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 53 "src/analyzer/Struct.pv"
        node.type = STRUCT_TYPE__INCOMPLETE;
    } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 55 "src/analyzer/Struct.pv"
        node.type = STRUCT_TYPE__TUPLE;
        #line 56 "src/analyzer/Struct.pv"
        if (!Context__skip_brackets(context, "(", ")") || !Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 56 "src/analyzer/Struct.pv"
            return node;
        }
    } else {
        #line 58 "src/analyzer/Struct.pv"
        node.type = STRUCT_TYPE__FIELD;
        #line 59 "src/analyzer/Struct.pv"
        if (!Context__skip_brackets(context, "{", "}")) {
            #line 59 "src/analyzer/Struct.pv"
            return node;
        }
    }

    #line 62 "src/analyzer/Struct.pv"
    node.token_end = context->pos;

    #line 64 "src/analyzer/Struct.pv"
    node.name = name;
    #line 65 "src/analyzer/Struct.pv"
    return node;
}

#line 68 "src/analyzer/Struct.pv"
bool Struct__prefill_types(struct Struct* self) {
    #line 69 "src/analyzer/Struct.pv"
    struct Context* context = &self->module->context;
    #line 70 "src/analyzer/Struct.pv"
    context->pos = self->token_start;

    #line 72 "src/analyzer/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 72 "src/analyzer/Struct.pv"
        return false;
    }

    #line 74 "src/analyzer/Struct.pv"
    switch (self->type) {
        #line 75 "src/analyzer/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 75 "src/analyzer/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{");
        } break;
        #line 76 "src/analyzer/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 76 "src/analyzer/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(");
        } break;
        #line 77 "src/analyzer/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 77 "src/analyzer/Struct.pv"
            return true;
        } break;
    }
}

#line 81 "src/analyzer/Struct.pv"
bool Struct__fill_types(struct Struct* self) {
    #line 82 "src/analyzer/Struct.pv"
    struct Context* context = &self->module->context;
    #line 83 "src/analyzer/Struct.pv"
    context->pos = self->token_start;

    #line 85 "src/analyzer/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 85 "src/analyzer/Struct.pv"
        return false;
    }

    #line 87 "src/analyzer/Struct.pv"
    switch (self->type) {
        #line 88 "src/analyzer/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 88 "src/analyzer/Struct.pv"
            return Struct__fill_types_field(self);
        } break;
        #line 89 "src/analyzer/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 89 "src/analyzer/Struct.pv"
            return Struct__fill_types_tuple(self);
        } break;
        #line 90 "src/analyzer/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 90 "src/analyzer/Struct.pv"
            return true;
        } break;
    }
}

#line 94 "src/analyzer/Struct.pv"
bool Struct__fill_types_field(struct Struct* self) {
    #line 95 "src/analyzer/Struct.pv"
    struct Context* context = &self->module->context;

    #line 97 "src/analyzer/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 97 "src/analyzer/Struct.pv"
        return false;
    }

    #line 99 "src/analyzer/Struct.pv"
    while (context->pos < self->token_end && Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 100 "src/analyzer/Struct.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 101 "src/analyzer/Struct.pv"
        if (name == 0) {
            #line 101 "src/analyzer/Struct.pv"
            return false;
        }

        #line 103 "src/analyzer/Struct.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
            #line 103 "src/analyzer/Struct.pv"
            return false;
        }

        #line 105 "src/analyzer/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 106 "src/analyzer/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 106 "src/analyzer/Struct.pv"
            return false;
        }

        #line 108 "src/analyzer/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = name,
            .type = type,
        };

        #line 113 "src/analyzer/Struct.pv"
        switch (type.type) {
            #line 114 "src/analyzer/Struct.pv"
            case TYPE__FUNCTION: {
                #line 114 "src/analyzer/Struct.pv"
                struct Function* func_info = type.function_value._0;
                #line 115 "src/analyzer/Struct.pv"
                func_info->name = name;
                #line 116 "src/analyzer/Struct.pv"
                func_info->type = FUNCTION_TYPE__BUILTIN;
                #line 117 "src/analyzer/Struct.pv"
                func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = self, ._1 = 0, ._2 = 0} };
            } break;
            #line 119 "src/analyzer/Struct.pv"
            default: {
            } break;
        }

        #line 122 "src/analyzer/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name->value, field)) {
            #line 122 "src/analyzer/Struct.pv"
            return false;
        }

        #line 124 "src/analyzer/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 125 "src/analyzer/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 126 "src/analyzer/Struct.pv"
            return false;
        }
    }

    #line 130 "src/analyzer/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 130 "src/analyzer/Struct.pv"
        return false;
    }

    #line 132 "src/analyzer/Struct.pv"
    if (context->pos != self->token_end) {
        #line 133 "src/analyzer/Struct.pv"
        Context__error(context, "Not at closing bracket for struct definition");
    }

    #line 136 "src/analyzer/Struct.pv"
    return true;
}

#line 139 "src/analyzer/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self) {
    #line 140 "src/analyzer/Struct.pv"
    struct Context* context = &self->module->context;

    #line 142 "src/analyzer/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 142 "src/analyzer/Struct.pv"
        return false;
    }

    #line 144 "src/analyzer/Struct.pv"
    uintptr_t field_index = 0;
    #line 145 "src/analyzer/Struct.pv"
    while (context->pos < self->token_end && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
        #line 146 "src/analyzer/Struct.pv"
        struct String name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 147 "src/analyzer/Struct.pv"
        String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 148 "src/analyzer/Struct.pv"
        String__append_usize(&name, field_index);
        #line 149 "src/analyzer/Struct.pv"
        struct str name_str = String__as_str(&name);

        #line 151 "src/analyzer/Struct.pv"
        struct Token name_token = *Context__current(context);
        #line 152 "src/analyzer/Struct.pv"
        name_token.value = name_str;

        #line 154 "src/analyzer/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 155 "src/analyzer/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 155 "src/analyzer/Struct.pv"
            return false;
        }

        #line 157 "src/analyzer/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = ArenaAllocator__store_Token(context->allocator, name_token),
            .type = type,
        };

        #line 162 "src/analyzer/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name_str, field)) {
            #line 162 "src/analyzer/Struct.pv"
            return false;
        }

        #line 164 "src/analyzer/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 165 "src/analyzer/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
            #line 166 "src/analyzer/Struct.pv"
            return false;
        }

        #line 169 "src/analyzer/Struct.pv"
        field_index += 1;
    }

    #line 172 "src/analyzer/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 172 "src/analyzer/Struct.pv"
        return false;
    }
    #line 173 "src/analyzer/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 173 "src/analyzer/Struct.pv"
        return false;
    }

    #line 175 "src/analyzer/Struct.pv"
    if (context->pos != self->token_end) {
        #line 176 "src/analyzer/Struct.pv"
        Context__error(context, "Not at end of struct definition");
    }

    #line 179 "src/analyzer/Struct.pv"
    return true;
}

#line 182 "src/analyzer/Struct.pv"
bool Struct__is_newtype(struct Struct* self) {
    #line 183 "src/analyzer/Struct.pv"
    return self->type == STRUCT_TYPE__TUPLE && self->fields.length == 1;
}
