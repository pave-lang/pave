#include <stdint.h>
#include <string.h>

#include <std/trait_Allocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Primitive.h>
#include <std/str.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Module.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Generic.h>

#include <analyzer/types/Generic.h>

#line 11 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct trait_Allocator allocator) {
    #line 12 "src/analyzer/types/Generics.pv"
    return (struct Generic) { .name = 0, .traits = Array_Type__new(allocator), .const_type = 0 };
}

#line 15 "src/analyzer/types/Generics.pv"
bool Generic__is_const(struct Generic* self) {
    #line 16 "src/analyzer/types/Generics.pv"
    return self->const_type != 0;
}

#line 19 "src/analyzer/types/Generics.pv"
bool Generic__parse_const_type(struct Generic* self, struct Context* context, struct Generics* generics) {
    #line 20 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 20 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 22 "src/analyzer/types/Generics.pv"
    struct Token* type_token = Context__current(context);
    #line 23 "src/analyzer/types/Generics.pv"
    if (type_token == 0) {
        #line 23 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 25 "src/analyzer/types/Generics.pv"
    struct Type const_type;
    #line 26 "src/analyzer/types/Generics.pv"
    if (!Context__parse_type(context, &const_type, generics)) {
        #line 26 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 28 "src/analyzer/types/Generics.pv"
    bool is_integer = false;
    #line 29 "src/analyzer/types/Generics.pv"
    switch (const_type.type) {
        #line 30 "src/analyzer/types/Generics.pv"
        case TYPE__PRIMITIVE: {
            #line 30 "src/analyzer/types/Generics.pv"
            struct Primitive* primitive_info = const_type.primitive_value;
            #line 31 "src/analyzer/types/Generics.pv"
            if (primitive_info != 0) {
                #line 32 "src/analyzer/types/Generics.pv"
                is_integer = Primitive__is_number(primitive_info) && !str__Eq_str__eq(primitive_info->name, (struct str){ .ptr = "f32", .length = strlen("f32") }) && !str__Eq_str__eq(primitive_info->name, (struct str){ .ptr = "f64", .length = strlen("f64") });
            }
        } break;
        #line 37 "src/analyzer/types/Generics.pv"
        default: {
        } break;
    }

    #line 40 "src/analyzer/types/Generics.pv"
    if (!is_integer) {
        #line 41 "src/analyzer/types/Generics.pv"
        Context__error_token(context, type_token, "Const generic type must be an integer primitive");
        #line 42 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 45 "src/analyzer/types/Generics.pv"
    self->const_type = ArenaAllocator__store_Type(context->allocator, &const_type);

    #line 47 "src/analyzer/types/Generics.pv"
    return self->const_type != 0;
}

#line 50 "src/analyzer/types/Generics.pv"
bool Generic__parse_traits(struct Generic* self, struct Context* context, struct Generics* generics) {
    #line 51 "src/analyzer/types/Generics.pv"
    struct Module* module = context->module;

    #line 53 "src/analyzer/types/Generics.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 54 "src/analyzer/types/Generics.pv"
        bool has_more = true;
        #line 55 "src/analyzer/types/Generics.pv"
        while (has_more) {
            #line 56 "src/analyzer/types/Generics.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 57 "src/analyzer/types/Generics.pv"
            if (name == 0) {
                #line 57 "src/analyzer/types/Generics.pv"
                return false;
            }

            #line 59 "src/analyzer/types/Generics.pv"
            struct Array_Type usage_types = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 60 "src/analyzer/types/Generics.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "<")) {
                #line 61 "src/analyzer/types/Generics.pv"
                while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ">")) {
                    #line 62 "src/analyzer/types/Generics.pv"
                    struct Type usage_type;
                    #line 63 "src/analyzer/types/Generics.pv"
                    if (!Context__parse_type(context, &usage_type, generics)) {
                        #line 63 "src/analyzer/types/Generics.pv"
                        return false;
                    }
                    #line 64 "src/analyzer/types/Generics.pv"
                    Array_Type__append(&usage_types, usage_type);

                    #line 66 "src/analyzer/types/Generics.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ">")) {
                        #line 67 "src/analyzer/types/Generics.pv"
                        Context__error(context, "Expected , or >");
                        #line 68 "src/analyzer/types/Generics.pv"
                        return false;
                    }
                }
            }

            #line 73 "src/analyzer/types/Generics.pv"
            struct Trait* trait_info = Module__find_trait(module, name->value, usage_types.length);
            #line 74 "src/analyzer/types/Generics.pv"
            if (trait_info == 0) {
                #line 74 "src/analyzer/types/Generics.pv"
                Context__error_token(context, name, "Unable to find trait");
                #line 74 "src/analyzer/types/Generics.pv"
                return false;
            }
            #line 75 "src/analyzer/types/Generics.pv"
            struct GenericMap generic_map = GenericMap__new(context->allocator, &trait_info->generics, &usage_types);
            #line 76 "src/analyzer/types/Generics.pv"
            Array_Type__append(&self->traits, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &generic_map)} });

            #line 78 "src/analyzer/types/Generics.pv"
            has_more = Context__check_next(context, TOKEN_TYPE__SYMBOL, "+");
        }
    }

    #line 82 "src/analyzer/types/Generics.pv"
    return true;
}
