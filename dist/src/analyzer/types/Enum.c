#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/str.h>
#include <analyzer/types/EnumVariant.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <analyzer/types/EnumType.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/expression/Expression.h>

#include <analyzer/types/Enum.h>

#line 35 "src/analyzer/types/Enum.pv"
struct Enum Enum__new(struct Context* context) {
    #line 36 "src/analyzer/types/Enum.pv"
    return (struct Enum) {
        .context = context,
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .variants = HashMap_str_EnumVariant__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .impls = Array_ref_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 45 "src/analyzer/types/Enum.pv"
struct Enum Enum__parse(struct Context* context) {
    #line 46 "src/analyzer/types/Enum.pv"
    struct Enum node = Enum__new(context);

    #line 48 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "enum")) {
        #line 48 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 50 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 51 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 51 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 53 "src/analyzer/types/Enum.pv"
    node.token_start = context->pos;

    #line 55 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 55 "src/analyzer/types/Enum.pv"
        return node;
    }
    #line 56 "src/analyzer/types/Enum.pv"
    if (!Context__skip_brackets(context, "{", "}")) {
        #line 56 "src/analyzer/types/Enum.pv"
        return node;
    }

    #line 58 "src/analyzer/types/Enum.pv"
    node.token_end = context->pos;

    #line 60 "src/analyzer/types/Enum.pv"
    node.name = name;
    #line 61 "src/analyzer/types/Enum.pv"
    return node;
}

#line 64 "src/analyzer/types/Enum.pv"
bool Enum__prefill_types(struct Enum* self) {
    #line 65 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 66 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 68 "src/analyzer/types/Enum.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 68 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 69 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 69 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 71 "src/analyzer/types/Enum.pv"
    return true;
}

#line 74 "src/analyzer/types/Enum.pv"
bool Enum__fill_variants(struct Enum* self) {
    #line 75 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 76 "src/analyzer/types/Enum.pv"
    context->pos = self->token_start;

    #line 78 "src/analyzer/types/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 78 "src/analyzer/types/Enum.pv"
        return false;
    }
    #line 79 "src/analyzer/types/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 79 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 81 "src/analyzer/types/Enum.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 82 "src/analyzer/types/Enum.pv"
        if (!Enum__parse_variant(self)) {
            #line 82 "src/analyzer/types/Enum.pv"
            return false;
        }

        #line 84 "src/analyzer/types/Enum.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 85 "src/analyzer/types/Enum.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 86 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 90 "src/analyzer/types/Enum.pv"
    return true;
}

#line 93 "src/analyzer/types/Enum.pv"
bool Enum__parse_variant(struct Enum* self) {
    #line 94 "src/analyzer/types/Enum.pv"
    struct Context* context = self->context;
    #line 95 "src/analyzer/types/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 96 "src/analyzer/types/Enum.pv"
    if (name == 0) {
        #line 96 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 98 "src/analyzer/types/Enum.pv"
    struct Array_Type types = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });

    #line 100 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 101 "src/analyzer/types/Enum.pv"
        while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 102 "src/analyzer/types/Enum.pv"
            struct Type type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

            #line 104 "src/analyzer/types/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 104 "src/analyzer/types/Enum.pv"
                return false;
            }
            #line 105 "src/analyzer/types/Enum.pv"
            Array_Type__append(&types, type);

            #line 107 "src/analyzer/types/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 108 "src/analyzer/types/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 109 "src/analyzer/types/Enum.pv"
                return false;
            }
        }
    }

    #line 114 "src/analyzer/types/Enum.pv"
    struct Expression* value = 0;

    #line 116 "src/analyzer/types/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 117 "src/analyzer/types/Enum.pv"
        value = Expression__parse(context, 0);
        #line 118 "src/analyzer/types/Enum.pv"
        if (value == 0) {
            #line 118 "src/analyzer/types/Enum.pv"
            return false;
        }
    }

    #line 121 "src/analyzer/types/Enum.pv"
    if (types.length > 0) {
        #line 122 "src/analyzer/types/Enum.pv"
        self->type = ENUM_TYPE__DISCRIMINATED_UNION;
    }

    #line 125 "src/analyzer/types/Enum.pv"
    struct EnumVariant variant = (struct EnumVariant) {
        .name = name,
        .types = types,
        .parent = self,
        .value = value,
    };

    #line 132 "src/analyzer/types/Enum.pv"
    if (HashMap_str_EnumVariant__insert(&self->variants, variant.name->value, variant) == 0) {
        #line 132 "src/analyzer/types/Enum.pv"
        return false;
    }

    #line 134 "src/analyzer/types/Enum.pv"
    return true;
}
