#include <analyzer/Context.h>
#include <analyzer/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/str.h>
#include <analyzer/EnumVariant.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Trait.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <analyzer/EnumType.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/Token.h>
#include <std/Array_Type.h>
#include <analyzer/Type.h>
#include <analyzer/Primitive.h>
#include <analyzer/Expression.h>

#include <analyzer/Enum.h>

#line 33 "src/analyzer/Enum.pv"
struct Enum Enum__new(struct Context* context) {
    #line 34 "src/analyzer/Enum.pv"
    return (struct Enum) {
        .context = context,
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .variants = HashMap_str_EnumVariant__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .impls = Array_ref_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 43 "src/analyzer/Enum.pv"
struct Enum Enum__parse(struct Context* context) {
    #line 44 "src/analyzer/Enum.pv"
    struct Enum node = Enum__new(context);

    #line 46 "src/analyzer/Enum.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "enum") == 0) {
        #line 46 "src/analyzer/Enum.pv"
        return node;
    }

    #line 48 "src/analyzer/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 49 "src/analyzer/Enum.pv"
    if (name == 0) {
        #line 49 "src/analyzer/Enum.pv"
        return node;
    }

    #line 51 "src/analyzer/Enum.pv"
    node.token_start = context->pos;

    #line 53 "src/analyzer/Enum.pv"
    if (Context__skip_to_symbol(context, "{") == 0) {
        #line 53 "src/analyzer/Enum.pv"
        return node;
    }
    #line 54 "src/analyzer/Enum.pv"
    if (Context__skip_brackets(context, "{", "}") == 0) {
        #line 54 "src/analyzer/Enum.pv"
        return node;
    }

    #line 56 "src/analyzer/Enum.pv"
    node.token_end = context->pos;

    #line 58 "src/analyzer/Enum.pv"
    node.name = name;
    #line 59 "src/analyzer/Enum.pv"
    return node;
}

#line 62 "src/analyzer/Enum.pv"
bool Enum__prefill_types(struct Enum* self) {
    #line 63 "src/analyzer/Enum.pv"
    struct Context* context = self->context;
    #line 64 "src/analyzer/Enum.pv"
    context->pos = self->token_start;

    #line 66 "src/analyzer/Enum.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 66 "src/analyzer/Enum.pv"
        return false;
    }
    #line 67 "src/analyzer/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 67 "src/analyzer/Enum.pv"
        return false;
    }

    #line 69 "src/analyzer/Enum.pv"
    return true;
}

#line 72 "src/analyzer/Enum.pv"
bool Enum__fill_variants(struct Enum* self) {
    #line 73 "src/analyzer/Enum.pv"
    struct Context* context = self->context;
    #line 74 "src/analyzer/Enum.pv"
    context->pos = self->token_start;

    #line 76 "src/analyzer/Enum.pv"
    if (!Context__skip_to_symbol(context, "{")) {
        #line 76 "src/analyzer/Enum.pv"
        return false;
    }
    #line 77 "src/analyzer/Enum.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 77 "src/analyzer/Enum.pv"
        return false;
    }

    #line 79 "src/analyzer/Enum.pv"
    while (Context__check_next(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 80 "src/analyzer/Enum.pv"
        if (!Enum__parse_variant(self)) {
            #line 80 "src/analyzer/Enum.pv"
            return false;
        }

        #line 82 "src/analyzer/Enum.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 83 "src/analyzer/Enum.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 84 "src/analyzer/Enum.pv"
            return false;
        }
    }

    #line 88 "src/analyzer/Enum.pv"
    return true;
}

#line 91 "src/analyzer/Enum.pv"
bool Enum__parse_variant(struct Enum* self) {
    #line 92 "src/analyzer/Enum.pv"
    struct Context* context = self->context;
    #line 93 "src/analyzer/Enum.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 94 "src/analyzer/Enum.pv"
    if (name == 0) {
        #line 94 "src/analyzer/Enum.pv"
        return false;
    }

    #line 96 "src/analyzer/Enum.pv"
    struct Array_Type types = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });

    #line 98 "src/analyzer/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 99 "src/analyzer/Enum.pv"
        while (Context__check_next(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 100 "src/analyzer/Enum.pv"
            struct Type type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };

            #line 102 "src/analyzer/Enum.pv"
            if (!Context__parse_type(context, &type, &self->generics)) {
                #line 102 "src/analyzer/Enum.pv"
                return false;
            }
            #line 103 "src/analyzer/Enum.pv"
            Array_Type__append(&types, type);

            #line 105 "src/analyzer/Enum.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 106 "src/analyzer/Enum.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 107 "src/analyzer/Enum.pv"
                return false;
            }
        }
    }

    #line 112 "src/analyzer/Enum.pv"
    struct Expression* value = 0;

    #line 114 "src/analyzer/Enum.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 115 "src/analyzer/Enum.pv"
        value = Expression__parse(context, 0);
        #line 116 "src/analyzer/Enum.pv"
        if (value == 0) {
            #line 116 "src/analyzer/Enum.pv"
            return false;
        }
    }

    #line 119 "src/analyzer/Enum.pv"
    if (types.length > 0) {
        #line 120 "src/analyzer/Enum.pv"
        self->type = ENUM_TYPE__DISCRIMINATED_UNION;
    }

    #line 123 "src/analyzer/Enum.pv"
    struct EnumVariant variant = (struct EnumVariant) {
        .name = name,
        .types = types,
        .parent = self,
        .value = value,
    };

    #line 130 "src/analyzer/Enum.pv"
    if (HashMap_str_EnumVariant__insert(&self->variants, variant.name->value, variant) == 0) {
        #line 130 "src/analyzer/Enum.pv"
        return false;
    }

    #line 132 "src/analyzer/Enum.pv"
    return true;
}
