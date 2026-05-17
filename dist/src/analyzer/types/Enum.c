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

#line 37 "src/analyzer/types/Enum.pv"
struct Enum Enum__new(struct Context* context) {
    #line 38 "src/analyzer/types/Enum.pv"
    return (struct Enum) {
        .context = context,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .variants = HashMap_str_EnumVariant__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .traits = HashMap_str_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .name = 0,
        .token_start = 0,
        .token_end = 0,
        .type = ENUM_TYPE__STANDARD,
    };
}

#line 51 "src/analyzer/types/Enum.pv"
struct Enum Enum__parse(struct Context* context) {
    #line 52 "src/analyzer/types/Enum.pv"
    struct Enum node = Enum__new(context);

    #line 54 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "enum")) {
        #line 54 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 56 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 57 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 57 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 59 "src/analyzer/types/Enum.pv"
    node.token_start = context->pos;

    #line 61 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 61 "src/analyzer/types/Enum.pv"
        return node;
    }
    #line 62 "src/analyzer/types/Enum.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 62 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 64 "src/analyzer/types/Enum.pv"
    node.token_end = context->pos;

    #line 66 "src/analyzer/types/Enum.pv"
    node.name = name;
    #line 67 "src/analyzer/types/Enum.pv"
    return node;
}

#line 70 "src/analyzer/types/Enum.pv"
bool Enum__prefill_types(struct Enum* self) {
    #line 71 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 72 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 74 "src/analyzer/types/Enum.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 74 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 75 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 75 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 77 "src/analyzer/types/Enum.pv"
    return true;
}

#line 80 "src/analyzer/types/Enum.pv"
bool Enum__fill_variants(struct Enum* self) {
    #line 81 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 82 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 84 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 84 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 85 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 85 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 87 "src/analyzer/types/Enum.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 88 "src/analyzer/types/Enum.pv"
        if (!Enum__parse_variant(self)) {
            #line 88 "src/analyzer/types/Enum.pv"
            return false;
        }

        #line 90 "src/analyzer/types/Enum.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 91 "src/analyzer/types/Enum.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 92 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 96 "src/analyzer/types/Enum.pv"
    return true;
}

#line 99 "src/analyzer/types/Enum.pv"
bool Enum__parse_variant(struct Enum* self) {
    #line 100 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 101 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 102 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 102 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 104 "src/analyzer/types/Enum.pv"
    struct Array_Type types = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
    #line 105 "src/analyzer/types/Enum.pv"
    struct Array_str names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });

    #line 107 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 108 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 109 "src/analyzer/types/Enum.pv"
            struct Type type;

            #line 111 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 111 "src/analyzer/types/Enum.pv"
                return false;
            }
            #line 112 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);

            #line 114 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 115 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 116 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 120 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 121 "src/analyzer/types/Enum.pv"
            struct Token* field_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 122 "src/analyzer/types/Enum.pv"
            if (field_name == 0) {
                #line 122 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 124 "src/analyzer/types/Enum.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 124 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 126 "src/analyzer/types/Enum.pv"
            struct Type type;
            #line 127 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 127 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 129 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);
            #line 130 "src/analyzer/types/Enum.pv"
            Array_str__append(&names, field_name->value);

            #line 132 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 133 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 134 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    }

    #line 139 "src/analyzer/types/Enum.pv"
    struct Expression* value = 0;

    #line 141 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 142 "src/analyzer/types/Enum.pv"
        value = Expression__parse(context, 0);
        #line 143 "src/analyzer/types/Enum.pv"
        if (value == 0) {
            #line 143 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 146 "src/analyzer/types/Enum.pv"
    if (types.length > 0) {
        #line 147 "src/analyzer/types/Enum.pv"
        self->type = ENUM_TYPE__DISCRIMINATED_UNION;
    }

    #line 150 "src/analyzer/types/Enum.pv"
    struct EnumVariant variant = (struct EnumVariant) {
        .name = name,
        .types = types,
        .names = names,
        .parent = self,
        .value = value,
    };

    #line 158 "src/analyzer/types/Enum.pv"
    HashMap_str_EnumVariant__insert(&self->variants, variant.name->value, variant);

    #line 160 "src/analyzer/types/Enum.pv"
    return true;
}

#line 163 "src/analyzer/types/Enum.pv"
bool Enum__is_discriminated_union(struct Enum* self) {
    #line 164 "src/analyzer/types/Enum.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&self->variants);
    #line 164 "src/analyzer/types/Enum.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 164 "src/analyzer/types/Enum.pv"
        struct EnumVariant* variant_info = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 165 "src/analyzer/types/Enum.pv"
        if (variant_info->types.length > 0) {
            #line 166 "src/analyzer/types/Enum.pv"
            return true;
        }
    } }

    #line 170 "src/analyzer/types/Enum.pv"
    return false;
}
