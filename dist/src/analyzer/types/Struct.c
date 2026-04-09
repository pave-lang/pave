#include <analyzer/Module.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_StructField.h>
#include <std/str.h>
#include <analyzer/types/StructField.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Type.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/String.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <analyzer/types/StructType.h>
#include <analyzer/Root.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/FunctionParent.h>

#include <analyzer/types/Struct.h>

#line 28 "src/analyzer/types/Struct.pv"
struct Struct Struct__new(struct Module* module) {
    #line 29 "src/analyzer/types/Struct.pv"
    struct Context context = module->context;

    #line 31 "src/analyzer/types/Struct.pv"
    return (struct Struct) {
        .module = module,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .fields = HashMap_str_StructField__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .traits = HashMap_str_tuple_ref_Trait_ref_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
    };
}

#line 40 "src/analyzer/types/Struct.pv"
struct Struct Struct__parse(struct Module* module) {
    #line 41 "src/analyzer/types/Struct.pv"
    struct Context* context = &module->context;
    #line 42 "src/analyzer/types/Struct.pv"
    struct Struct node = Struct__new(module);

    #line 44 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "struct")) {
        #line 44 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 46 "src/analyzer/types/Struct.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 47 "src/analyzer/types/Struct.pv"
    if (name == 0) {
        #line 47 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 49 "src/analyzer/types/Struct.pv"
    node.token_start = context->pos;

    #line 51 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 51 "src/analyzer/types/Struct.pv"
        return node;
    }

    #line 53 "src/analyzer/types/Struct.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 54 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__INCOMPLETE;
    } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 56 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__TUPLE;
        #line 57 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "(", ")") || !Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 57 "src/analyzer/types/Struct.pv"
            return node;
        }
    } else {
        #line 59 "src/analyzer/types/Struct.pv"
        node.type = STRUCT_TYPE__FIELD;
        #line 60 "src/analyzer/types/Struct.pv"
        if (!Context__skip_brackets(context, "{", "}")) {
            #line 60 "src/analyzer/types/Struct.pv"
            return node;
        }
    }

    #line 63 "src/analyzer/types/Struct.pv"
    node.token_end = context->pos;

    #line 65 "src/analyzer/types/Struct.pv"
    node.name = name;
    #line 66 "src/analyzer/types/Struct.pv"
    return node;
}

#line 69 "src/analyzer/types/Struct.pv"
bool Struct__prefill_types(struct Struct* self) {
    #line 70 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 71 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 73 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 73 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 75 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 76 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 76 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{");
        } break;
        #line 77 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 77 "src/analyzer/types/Struct.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(");
        } break;
        #line 78 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 78 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 82 "src/analyzer/types/Struct.pv"
bool Struct__fill_types(struct Struct* self) {
    #line 83 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;
    #line 84 "src/analyzer/types/Struct.pv"
    context->pos = self->token_start;

    #line 86 "src/analyzer/types/Struct.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Context__skip_brackets(context, "<", ">")) {
        #line 86 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 88 "src/analyzer/types/Struct.pv"
    switch (self->type) {
        #line 89 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__FIELD: {
            #line 89 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_field(self);
        } break;
        #line 90 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__TUPLE: {
            #line 90 "src/analyzer/types/Struct.pv"
            return Struct__fill_types_tuple(self);
        } break;
        #line 91 "src/analyzer/types/Struct.pv"
        case STRUCT_TYPE__INCOMPLETE: {
            #line 91 "src/analyzer/types/Struct.pv"
            return true;
        } break;
    }
}

#line 95 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_field(struct Struct* self) {
    #line 96 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 98 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 98 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 100 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 101 "src/analyzer/types/Struct.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 102 "src/analyzer/types/Struct.pv"
        if (name == 0) {
            #line 102 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 104 "src/analyzer/types/Struct.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
            #line 104 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 106 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 107 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 107 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 109 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = name,
            .type = type,
        };

        #line 114 "src/analyzer/types/Struct.pv"
        switch (type.type) {
            #line 115 "src/analyzer/types/Struct.pv"
            case TYPE__FUNCTION: {
                #line 115 "src/analyzer/types/Struct.pv"
                struct Function* func_info = type.function_value._0;
                #line 116 "src/analyzer/types/Struct.pv"
                func_info->name = name;
                #line 117 "src/analyzer/types/Struct.pv"
                func_info->type = FUNCTION_TYPE__BUILTIN;
                #line 118 "src/analyzer/types/Struct.pv"
                func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = self, ._1 = 0, ._2 = 0} };
            } break;
            #line 120 "src/analyzer/types/Struct.pv"
            default: {
            } break;
        }

        #line 123 "src/analyzer/types/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name->value, field)) {
            #line 123 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 125 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 126 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 127 "src/analyzer/types/Struct.pv"
            return false;
        }
    }

    #line 131 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 131 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 133 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 134 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at closing bracket for struct definition");
    }

    #line 137 "src/analyzer/types/Struct.pv"
    return true;
}

#line 140 "src/analyzer/types/Struct.pv"
bool Struct__fill_types_tuple(struct Struct* self) {
    #line 141 "src/analyzer/types/Struct.pv"
    struct Context* context = &self->module->context;

    #line 143 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 143 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 145 "src/analyzer/types/Struct.pv"
    uintptr_t field_index = 0;
    #line 146 "src/analyzer/types/Struct.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 147 "src/analyzer/types/Struct.pv"
        struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 148 "src/analyzer/types/Struct.pv"
        String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 149 "src/analyzer/types/Struct.pv"
        String__append_usize(&name, field_index);
        #line 150 "src/analyzer/types/Struct.pv"
        struct str name_str = String__as_str(&name);

        #line 152 "src/analyzer/types/Struct.pv"
        struct Token name_token = *Context__current(context);
        #line 153 "src/analyzer/types/Struct.pv"
        name_token.value = name_str;

        #line 155 "src/analyzer/types/Struct.pv"
        struct Type type = self->module->root->type_void;
        #line 156 "src/analyzer/types/Struct.pv"
        if (!Context__parse_type(context, &type, &self->generics)) {
            #line 156 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 158 "src/analyzer/types/Struct.pv"
        struct StructField field = (struct StructField) {
            .name = ArenaAllocator__store_Token(context->allocator, name_token),
            .type = type,
        };

        #line 163 "src/analyzer/types/Struct.pv"
        if (!HashMap_str_StructField__insert(&self->fields, name_str, field)) {
            #line 163 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 165 "src/analyzer/types/Struct.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 166 "src/analyzer/types/Struct.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
            #line 167 "src/analyzer/types/Struct.pv"
            return false;
        }

        #line 170 "src/analyzer/types/Struct.pv"
        field_index += 1;
    }

    #line 173 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 173 "src/analyzer/types/Struct.pv"
        return false;
    }
    #line 174 "src/analyzer/types/Struct.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 174 "src/analyzer/types/Struct.pv"
        return false;
    }

    #line 176 "src/analyzer/types/Struct.pv"
    if (context->pos != self->token_end) {
        #line 177 "src/analyzer/types/Struct.pv"
        Context__error(context, "Not at end of struct definition");
    }

    #line 180 "src/analyzer/types/Struct.pv"
    return true;
}

#line 183 "src/analyzer/types/Struct.pv"
bool Struct__is_newtype(struct Struct* self) {
    #line 184 "src/analyzer/types/Struct.pv"
    return (self->type == STRUCT_TYPE__TUPLE) && (self->fields.length == 1);
}
