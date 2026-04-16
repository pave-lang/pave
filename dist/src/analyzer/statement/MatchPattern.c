#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <std/str.h>
#include <analyzer/expression/Expression.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <std/trait_Allocator.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <std/Array_Type.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/c/EnumCValue.h>
#include <analyzer/statement/MatchPattern.h>

#include <analyzer/statement/MatchPattern.h>

#line 17 "src/analyzer/statement/MatchPattern.pv"
bool MatchPattern__parse(struct Context* context, struct Generics* generics, struct MatchPattern* pattern) {
    #line 18 "src/analyzer/statement/MatchPattern.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
        #line 19 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 20 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 23 "src/analyzer/statement/MatchPattern.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "typeid")) {
        #line 24 "src/analyzer/statement/MatchPattern.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 24 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 26 "src/analyzer/statement/MatchPattern.pv"
        struct Type type;
        #line 27 "src/analyzer/statement/MatchPattern.pv"
        if (!Context__parse_type(context, &type, generics)) {
            #line 27 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 29 "src/analyzer/statement/MatchPattern.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 29 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 31 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__TYPE_ID, .typeid_value = type };
        #line 32 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 35 "src/analyzer/statement/MatchPattern.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "hash")) {
        #line 36 "src/analyzer/statement/MatchPattern.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 36 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 38 "src/analyzer/statement/MatchPattern.pv"
        struct Token* token = Context__current(context);
        #line 39 "src/analyzer/statement/MatchPattern.pv"
        if (token == 0) {
            #line 39 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 41 "src/analyzer/statement/MatchPattern.pv"
        if (token->type != TOKEN_TYPE__STRING && token->type != TOKEN_TYPE__NUMBER) {
            #line 42 "src/analyzer/statement/MatchPattern.pv"
            Context__error_token(context, token, "Expected a string or number literal");
            #line 43 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 46 "src/analyzer/statement/MatchPattern.pv"
        Context__next_token(context);

        #line 48 "src/analyzer/statement/MatchPattern.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 48 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }

        #line 50 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__HASH, .hash_value = token };
        #line 51 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 54 "src/analyzer/statement/MatchPattern.pv"
    struct Token* token = Context__current(context);
    #line 55 "src/analyzer/statement/MatchPattern.pv"
    if (token == 0) {
        #line 55 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 57 "src/analyzer/statement/MatchPattern.pv"
    struct Type* type = Context__get_value(context, token->value);

    #line 59 "src/analyzer/statement/MatchPattern.pv"
    if (type != 0) {
        #line 60 "src/analyzer/statement/MatchPattern.pv"
        Context__next_token(context);
        #line 61 "src/analyzer/statement/MatchPattern.pv"
        struct Expression* expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, type);
        #line 62 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = expression };
        #line 63 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 66 "src/analyzer/statement/MatchPattern.pv"
    type = Context__parse_type2(context, generics);
    #line 67 "src/analyzer/statement/MatchPattern.pv"
    if (type == 0) {
        #line 68 "src/analyzer/statement/MatchPattern.pv"
        return false;
    } else if (!Type__is_enum(type)) {
        #line 70 "src/analyzer/statement/MatchPattern.pv"
        Context__error_token(context, token, "Type is not an enum");
        #line 71 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 74 "src/analyzer/statement/MatchPattern.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 74 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 76 "src/analyzer/statement/MatchPattern.pv"
    struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 77 "src/analyzer/statement/MatchPattern.pv"
    if (enum_variant_token == 0) {
        #line 77 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 79 "src/analyzer/statement/MatchPattern.pv"
    struct GenericMap* generic_map = 0;

    #line 81 "src/analyzer/statement/MatchPattern.pv"
    switch (type->type) {
        #line 82 "src/analyzer/statement/MatchPattern.pv"
        case TYPE__SELF: {
            #line 83 "src/analyzer/statement/MatchPattern.pv"
            type = context->type_self;
        } break;
        #line 85 "src/analyzer/statement/MatchPattern.pv"
        default: {
        } break;
    }

    #line 88 "src/analyzer/statement/MatchPattern.pv"
    switch (type->type) {
        #line 89 "src/analyzer/statement/MatchPattern.pv"
        case TYPE__ENUM: {
            #line 89 "src/analyzer/statement/MatchPattern.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 89 "src/analyzer/statement/MatchPattern.pv"
            generic_map = generics;
        } break;
        #line 90 "src/analyzer/statement/MatchPattern.pv"
        case TYPE__ENUM_C: {
        } break;
        #line 91 "src/analyzer/statement/MatchPattern.pv"
        default: {
            #line 92 "src/analyzer/statement/MatchPattern.pv"
            Context__pop_scope(context);
            #line 93 "src/analyzer/statement/MatchPattern.pv"
            Context__error(context, "Not an enum type");
            #line 94 "src/analyzer/statement/MatchPattern.pv"
            return false;
        } break;
    }

    #line 98 "src/analyzer/statement/MatchPattern.pv"
    struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
    #line 99 "src/analyzer/statement/MatchPattern.pv"
    switch (enum_variant_result.type) {
        #line 100 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__NONE: {
            #line 101 "src/analyzer/statement/MatchPattern.pv"
            Context__error(context, "Could not find enum variant");
            #line 102 "src/analyzer/statement/MatchPattern.pv"
            return false;
        } break;
        #line 104 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
            #line 104 "src/analyzer/statement/MatchPattern.pv"
            struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
            #line 105 "src/analyzer/statement/MatchPattern.pv"
            struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 107 "src/analyzer/statement/MatchPattern.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 108 "src/analyzer/statement/MatchPattern.pv"
                uintptr_t variable_i = 0;

                #line 110 "src/analyzer/statement/MatchPattern.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 111 "src/analyzer/statement/MatchPattern.pv"
                    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                    #line 112 "src/analyzer/statement/MatchPattern.pv"
                    struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                    #line 113 "src/analyzer/statement/MatchPattern.pv"
                    if (variable == 0) {
                        #line 113 "src/analyzer/statement/MatchPattern.pv"
                        Context__pop_scope(context);
                        #line 113 "src/analyzer/statement/MatchPattern.pv"
                        return false;
                    }

                    #line 115 "src/analyzer/statement/MatchPattern.pv"
                    Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                    #line 117 "src/analyzer/statement/MatchPattern.pv"
                    struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                    #line 118 "src/analyzer/statement/MatchPattern.pv"
                    if (variable_type == 0) {
                        #line 118 "src/analyzer/statement/MatchPattern.pv"
                        return false;
                    }

                    #line 120 "src/analyzer/statement/MatchPattern.pv"
                    if (ref) {
                        #line 121 "src/analyzer/statement/MatchPattern.pv"
                        struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                        #line 122 "src/analyzer/statement/MatchPattern.pv"
                        variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                    }

                    #line 125 "src/analyzer/statement/MatchPattern.pv"
                    struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                    #line 126 "src/analyzer/statement/MatchPattern.pv"
                    String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 127 "src/analyzer/statement/MatchPattern.pv"
                    Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                    #line 129 "src/analyzer/statement/MatchPattern.pv"
                    if (!Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                        #line 130 "src/analyzer/statement/MatchPattern.pv"
                        if (!Context__set_value(context, variable, variable_type)) {
                            #line 130 "src/analyzer/statement/MatchPattern.pv"
                            Context__pop_scope(context);
                            #line 130 "src/analyzer/statement/MatchPattern.pv"
                            return false;
                        }
                    }

                    #line 133 "src/analyzer/statement/MatchPattern.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 134 "src/analyzer/statement/MatchPattern.pv"
                        Context__pop_scope(context);
                        #line 135 "src/analyzer/statement/MatchPattern.pv"
                        Context__pop_scope(context);
                        #line 136 "src/analyzer/statement/MatchPattern.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 137 "src/analyzer/statement/MatchPattern.pv"
                        return false;
                    }

                    #line 140 "src/analyzer/statement/MatchPattern.pv"
                    variable_i += 1;
                }

                #line 143 "src/analyzer/statement/MatchPattern.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 143 "src/analyzer/statement/MatchPattern.pv"
                    Context__pop_scope(context);
                    #line 143 "src/analyzer/statement/MatchPattern.pv"
                    return false;
                }

                #line 145 "src/analyzer/statement/MatchPattern.pv"
                if (parameters.length != enum_variant->types.length) {
                    #line 146 "src/analyzer/statement/MatchPattern.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 147 "src/analyzer/statement/MatchPattern.pv"
                    String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                    #line 148 "src/analyzer/statement/MatchPattern.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 149 "src/analyzer/statement/MatchPattern.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            } else {
                #line 152 "src/analyzer/statement/MatchPattern.pv"
                if (enum_variant->types.length > 0) {
                    #line 153 "src/analyzer/statement/MatchPattern.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 154 "src/analyzer/statement/MatchPattern.pv"
                    String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                    #line 155 "src/analyzer/statement/MatchPattern.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 156 "src/analyzer/statement/MatchPattern.pv"
                    String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                    #line 157 "src/analyzer/statement/MatchPattern.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            }

            #line 161 "src/analyzer/statement/MatchPattern.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = type, ._1 = enum_variant, ._2 = parameters} };
            #line 162 "src/analyzer/statement/MatchPattern.pv"
            return true;
        } break;
        #line 164 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
            #line 164 "src/analyzer/statement/MatchPattern.pv"
            struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
            #line 165 "src/analyzer/statement/MatchPattern.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = enum_variant };
            #line 166 "src/analyzer/statement/MatchPattern.pv"
            return true;
        } break;
        #line 168 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__FUNCTION: {
            #line 169 "src/analyzer/statement/MatchPattern.pv"
            Context__error(context, "Expected an enum variant, not a function");
            #line 170 "src/analyzer/statement/MatchPattern.pv"
            return false;
        } break;
    }
}
