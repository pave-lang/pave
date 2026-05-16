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
    };
}

#line 47 "src/analyzer/types/Enum.pv"
struct Enum Enum__parse(struct Context* context) {
    #line 48 "src/analyzer/types/Enum.pv"
    struct Enum node = Enum__new(context);

    #line 50 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "enum")) {
        #line 50 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 52 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 53 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 53 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 55 "src/analyzer/types/Enum.pv"
    node.token_start = context->pos;

    #line 57 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 57 "src/analyzer/types/Enum.pv"
        return node;
    }
    #line 58 "src/analyzer/types/Enum.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 58 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 60 "src/analyzer/types/Enum.pv"
    node.token_end = context->pos;

    #line 62 "src/analyzer/types/Enum.pv"
    node.name = name;
    #line 63 "src/analyzer/types/Enum.pv"
    return node;
}

#line 66 "src/analyzer/types/Enum.pv"
bool Enum__prefill_types(struct Enum* self) {
    #line 67 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 68 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 70 "src/analyzer/types/Enum.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 70 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 71 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 71 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 73 "src/analyzer/types/Enum.pv"
    return true;
}

#line 76 "src/analyzer/types/Enum.pv"
bool Enum__fill_variants(struct Enum* self) {
    #line 77 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 78 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 80 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 80 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 81 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 81 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 83 "src/analyzer/types/Enum.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 84 "src/analyzer/types/Enum.pv"
        if (!Enum__parse_variant(self)) {
            #line 84 "src/analyzer/types/Enum.pv"
            return false;
        }

        #line 86 "src/analyzer/types/Enum.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 87 "src/analyzer/types/Enum.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 88 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 92 "src/analyzer/types/Enum.pv"
    return true;
}

#line 95 "src/analyzer/types/Enum.pv"
bool Enum__parse_variant(struct Enum* self) {
    #line 96 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 97 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 98 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 98 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 100 "src/analyzer/types/Enum.pv"
    struct Array_Type types = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
    #line 101 "src/analyzer/types/Enum.pv"
    struct Array_str names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });

    #line 103 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 104 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 105 "src/analyzer/types/Enum.pv"
            struct Type type;

            #line 107 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 107 "src/analyzer/types/Enum.pv"
                return false;
            }
            #line 108 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);

            #line 110 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 111 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 112 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 116 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 117 "src/analyzer/types/Enum.pv"
            struct Token* field_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 118 "src/analyzer/types/Enum.pv"
            if (field_name == 0) {
                #line 118 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 120 "src/analyzer/types/Enum.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 120 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 122 "src/analyzer/types/Enum.pv"
            struct Type type;
            #line 123 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 123 "src/analyzer/types/Enum.pv"
                return false;
            }

            #line 125 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);
            #line 126 "src/analyzer/types/Enum.pv"
            Array_str__append(&names, field_name->value);

            #line 128 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 129 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 130 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    }

    #line 135 "src/analyzer/types/Enum.pv"
    struct Expression* value = 0;

    #line 137 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 138 "src/analyzer/types/Enum.pv"
        value = Expression__parse(context, 0);
        #line 139 "src/analyzer/types/Enum.pv"
        if (value == 0) {
            #line 139 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 142 "src/analyzer/types/Enum.pv"
    if (types.length > 0) {
        #line 143 "src/analyzer/types/Enum.pv"
        self->type = ENUM_TYPE__DISCRIMINATED_UNION;
    }

    #line 146 "src/analyzer/types/Enum.pv"
    struct EnumVariant variant = (struct EnumVariant) {
        .name = name,
        .types = types,
        .names = names,
        .parent = self,
        .value = value,
    };

    #line 154 "src/analyzer/types/Enum.pv"
    if (HashMap_str_EnumVariant__insert(&self->variants, variant.name->value, variant) == 0) {
        #line 154 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 156 "src/analyzer/types/Enum.pv"
    return true;
}

#line 159 "src/analyzer/types/Enum.pv"
bool Enum__is_discriminated_union(struct Enum* self) {
    #line 160 "src/analyzer/types/Enum.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&self->variants);
    #line 160 "src/analyzer/types/Enum.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 160 "src/analyzer/types/Enum.pv"
        struct EnumVariant* variant_info = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 161 "src/analyzer/types/Enum.pv"
        if (variant_info->types.length > 0) {
            #line 162 "src/analyzer/types/Enum.pv"
            return true;
        }
    } }

    #line 166 "src/analyzer/types/Enum.pv"
    return false;
}
