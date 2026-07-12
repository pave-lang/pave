#include <stdint.h>

#include <analyzer/types/Enum.h>
#include <analyzer/Context.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <std/Array_Type.h>
#include <std/Array_str.h>
#include <analyzer/types/Type.h>
#include <std/str.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <analyzer/types/Enum.h>

#include <analyzer/types/Enum.h>

#line 39 "src/analyzer/types/Enum.pv"
struct Enum Enum__new(struct Context* context) {
    #line 40 "src/analyzer/types/Enum.pv"
    return (struct Enum) {
        .context = context,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .variants = HashMap_str_EnumVariant__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .traits = HashMap_str_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .name = 0,
        .token_start = 0,
        .token_end = 0,
        .generic_arity = 0,
        .type = ENUM_TYPE__STANDARD,
    };
}

#line 54 "src/analyzer/types/Enum.pv"
struct Enum Enum__parse(struct Context* context) {
    #line 55 "src/analyzer/types/Enum.pv"
    struct Enum node = Enum__new(context);

    #line 57 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "enum")) {
        #line 57 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 59 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 60 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 60 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 62 "src/analyzer/types/Enum.pv"
    node.token_start = context->pos;

    #line 64 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 65 "src/analyzer/types/Enum.pv"
        uintptr_t depth = 1;
        #line 66 "src/analyzer/types/Enum.pv"
        bool expect_generic = true;
        #line 67 "src/analyzer/types/Enum.pv"
        while (context->pos < context->length && depth > 0) {
            #line 68 "src/analyzer/types/Enum.pv"
            if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                #line 69 "src/analyzer/types/Enum.pv"
                depth += 1;
            } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, ">")) {
                #line 71 "src/analyzer/types/Enum.pv"
                depth -= 1;
                #line 72 "src/analyzer/types/Enum.pv"
                if (depth == 0) {
                    #line 72 "src/analyzer/types/Enum.pv"
                    break;
                }
            } else if (depth == 1 && expect_generic && Context__check(context, TOKEN_TYPE__IDENTIFIER)) {
                #line 74 "src/analyzer/types/Enum.pv"
                node.generic_arity += 1;
                #line 75 "src/analyzer/types/Enum.pv"
                expect_generic = false;
            } else if (depth == 1 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ",")) {
                #line 77 "src/analyzer/types/Enum.pv"
                expect_generic = true;
            }
            #line 79 "src/analyzer/types/Enum.pv"
            Context__next_token(context);
        }
        #line 81 "src/analyzer/types/Enum.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">")) {
            #line 81 "src/analyzer/types/Enum.pv"
            return node;
        }
    }

    #line 84 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 84 "src/analyzer/types/Enum.pv"
        return node;
    }
    #line 85 "src/analyzer/types/Enum.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 85 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 87 "src/analyzer/types/Enum.pv"
    node.token_end = context->pos;

    #line 89 "src/analyzer/types/Enum.pv"
    node.name = name;
    #line 90 "src/analyzer/types/Enum.pv"
    return node;
}

#line 93 "src/analyzer/types/Enum.pv"
bool Enum__prefill_types(struct Enum* self) {
    #line 94 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 95 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 97 "src/analyzer/types/Enum.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 97 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 98 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 98 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 100 "src/analyzer/types/Enum.pv"
    return true;
}

#line 103 "src/analyzer/types/Enum.pv"
bool Enum__fill_variants(struct Enum* self) {
    #line 104 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 105 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 107 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 107 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 108 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 108 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 110 "src/analyzer/types/Enum.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 111 "src/analyzer/types/Enum.pv"
        if (!Enum__parse_variant(self)) {
            #line 111 "src/analyzer/types/Enum.pv"
            return false;
        }

        #line 113 "src/analyzer/types/Enum.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 114 "src/analyzer/types/Enum.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 115 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 119 "src/analyzer/types/Enum.pv"
    return true;
}

#line 122 "src/analyzer/types/Enum.pv"
bool Enum__parse_variant(struct Enum* self) {
    #line 123 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 124 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 125 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 125 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 127 "src/analyzer/types/Enum.pv"
    struct Array_Type types = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
    #line 128 "src/analyzer/types/Enum.pv"
    struct Array_str names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });

    #line 130 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 131 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 132 "src/analyzer/types/Enum.pv"
            struct Type type;

            #line 134 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 134 "src/analyzer/types/Enum.pv"
                return false;
            }
            #line 135 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);

            #line 137 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 138 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 139 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 143 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 144 "src/analyzer/types/Enum.pv"
            struct Token* field_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 145 "src/analyzer/types/Enum.pv"
            if (field_name == 0) {
                #line 145 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 147 "src/analyzer/types/Enum.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 147 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 149 "src/analyzer/types/Enum.pv"
            struct Type type;
            #line 150 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 150 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 152 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);
            #line 153 "src/analyzer/types/Enum.pv"
            Array_str__append(&names, field_name->value);

            #line 155 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 156 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 157 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    }

    #line 162 "src/analyzer/types/Enum.pv"
    struct Expression* value = 0;

    #line 164 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 165 "src/analyzer/types/Enum.pv"
        value = Expression__parse(context, 0);
        #line 166 "src/analyzer/types/Enum.pv"
        if (value == 0) {
            #line 166 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 169 "src/analyzer/types/Enum.pv"
    struct Token* label = 0;
    #line 170 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "@")) {
        #line 171 "src/analyzer/types/Enum.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__IDENTIFIER, "label")) {
            #line 171 "src/analyzer/types/Enum.pv"
            return false;
        }
        #line 172 "src/analyzer/types/Enum.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 172 "src/analyzer/types/Enum.pv"
            return false;
        }
        #line 173 "src/analyzer/types/Enum.pv"
        label = Context__expect(context, TOKEN_TYPE__STRING);
        #line 174 "src/analyzer/types/Enum.pv"
        if (label == 0) {
            #line 174 "src/analyzer/types/Enum.pv"
            return false;
        }
        #line 175 "src/analyzer/types/Enum.pv"
        if (label->value.length < 2 || label->value.ptr[0] != '"') {
            #line 176 "src/analyzer/types/Enum.pv"
            Context__error_token(context, label, "Enum variant label must use a double-quoted string");
            #line 177 "src/analyzer/types/Enum.pv"
            return false;
        }
        #line 179 "src/analyzer/types/Enum.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 179 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 182 "src/analyzer/types/Enum.pv"
    if (types.length > 0) {
        #line 183 "src/analyzer/types/Enum.pv"
        self->type = ENUM_TYPE__DISCRIMINATED_UNION;
    }

    #line 186 "src/analyzer/types/Enum.pv"
    struct EnumVariant variant = (struct EnumVariant) {
        .name = name,
        .label = label,
        .types = types,
        .names = names,
        .parent = self,
        .value = value,
    };

    #line 195 "src/analyzer/types/Enum.pv"
    HashMap_str_EnumVariant__insert(&self->variants, variant.name->value, variant);

    #line 197 "src/analyzer/types/Enum.pv"
    return true;
}

#line 200 "src/analyzer/types/Enum.pv"
bool Enum__is_discriminated_union(struct Enum* self) {
    #line 201 "src/analyzer/types/Enum.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&self->variants);
    #line 201 "src/analyzer/types/Enum.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 201 "src/analyzer/types/Enum.pv"
        struct EnumVariant* variant_info = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 202 "src/analyzer/types/Enum.pv"
        if (variant_info->types.length > 0) {
            #line 203 "src/analyzer/types/Enum.pv"
            return true;
        }
    } }

    #line 207 "src/analyzer/types/Enum.pv"
    return false;
}
