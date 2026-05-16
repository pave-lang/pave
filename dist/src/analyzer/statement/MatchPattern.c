#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <std/str.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/Module.h>
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
    if (token->type == TOKEN_TYPE__NUMBER) {
        #line 58 "src/analyzer/statement/MatchPattern.pv"
        Context__next_token(context);
        #line 59 "src/analyzer/statement/MatchPattern.pv"
        struct str primitive = Expression__number_primitive(token->value);
        #line 60 "src/analyzer/statement/MatchPattern.pv"
        struct Primitive* primitive_info = Module__find_primitive(context->module, primitive);
        #line 61 "src/analyzer/statement/MatchPattern.pv"
        struct Expression* expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value }, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
        #line 62 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = expression };
        #line 63 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 66 "src/analyzer/statement/MatchPattern.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-")) {
        #line 67 "src/analyzer/statement/MatchPattern.pv"
        Context__next_token(context);
        #line 68 "src/analyzer/statement/MatchPattern.pv"
        struct Token* num_token = Context__current(context);
        #line 69 "src/analyzer/statement/MatchPattern.pv"
        if (num_token == 0 || num_token->type != TOKEN_TYPE__NUMBER) {
            #line 70 "src/analyzer/statement/MatchPattern.pv"
            Context__error_token(context, token, "Expected a number after '-'");
            #line 71 "src/analyzer/statement/MatchPattern.pv"
            return false;
        }
        #line 73 "src/analyzer/statement/MatchPattern.pv"
        Context__next_token(context);
        #line 74 "src/analyzer/statement/MatchPattern.pv"
        struct str primitive = Expression__number_primitive(num_token->value);
        #line 75 "src/analyzer/statement/MatchPattern.pv"
        struct Primitive* primitive_info = Module__find_primitive(context->module, primitive);
        #line 76 "src/analyzer/statement/MatchPattern.pv"
        struct Expression* num_expr = Expression__make(context->allocator, num_token, (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = num_token->value }, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
        #line 77 "src/analyzer/statement/MatchPattern.pv"
        struct Expression* neg_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = token->value, ._1 = num_expr} }, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
        #line 78 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = neg_expr };
        #line 79 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 82 "src/analyzer/statement/MatchPattern.pv"
    struct Type* type = Context__get_value(context, token->value);

    #line 84 "src/analyzer/statement/MatchPattern.pv"
    if (type != 0) {
        #line 85 "src/analyzer/statement/MatchPattern.pv"
        Context__next_token(context);
        #line 86 "src/analyzer/statement/MatchPattern.pv"
        struct Expression* expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, type);
        #line 87 "src/analyzer/statement/MatchPattern.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = expression };
        #line 88 "src/analyzer/statement/MatchPattern.pv"
        return true;
    }

    #line 91 "src/analyzer/statement/MatchPattern.pv"
    type = Context__parse_type2(context, generics);
    #line 92 "src/analyzer/statement/MatchPattern.pv"
    if (type == 0) {
        #line 93 "src/analyzer/statement/MatchPattern.pv"
        return false;
    } else if (!Type__is_enum(type)) {
        #line 95 "src/analyzer/statement/MatchPattern.pv"
        Context__error_token(context, token, "Type is not an enum");
        #line 96 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 99 "src/analyzer/statement/MatchPattern.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 99 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 101 "src/analyzer/statement/MatchPattern.pv"
    struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 102 "src/analyzer/statement/MatchPattern.pv"
    if (enum_variant_token == 0) {
        #line 102 "src/analyzer/statement/MatchPattern.pv"
        return false;
    }

    #line 104 "src/analyzer/statement/MatchPattern.pv"
    struct GenericMap* generic_map = 0;

    #line 106 "src/analyzer/statement/MatchPattern.pv"
    switch (type->type) {
        #line 107 "src/analyzer/statement/MatchPattern.pv"
        case TYPE__SELF: {
            #line 108 "src/analyzer/statement/MatchPattern.pv"
            type = context->type_self;
        } break;
        #line 110 "src/analyzer/statement/MatchPattern.pv"
        default: {
        } break;
    }

    #line 113 "src/analyzer/statement/MatchPattern.pv"
    switch (type->type) {
        #line 114 "src/analyzer/statement/MatchPattern.pv"
        case TYPE__ENUM: {
            #line 114 "src/analyzer/statement/MatchPattern.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 114 "src/analyzer/statement/MatchPattern.pv"
            generic_map = generics;
        } break;
        #line 115 "src/analyzer/statement/MatchPattern.pv"
        case TYPE__ENUM_C: {
        } break;
        #line 116 "src/analyzer/statement/MatchPattern.pv"
        default: {
            #line 117 "src/analyzer/statement/MatchPattern.pv"
            Context__pop_scope(context);
            #line 118 "src/analyzer/statement/MatchPattern.pv"
            Context__error(context, "Not an enum type");
            #line 119 "src/analyzer/statement/MatchPattern.pv"
            return false;
        } break;
    }

    #line 123 "src/analyzer/statement/MatchPattern.pv"
    struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
    #line 124 "src/analyzer/statement/MatchPattern.pv"
    switch (enum_variant_result.type) {
        #line 125 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__NONE: {
            #line 126 "src/analyzer/statement/MatchPattern.pv"
            Context__error(context, "Could not find enum variant");
            #line 127 "src/analyzer/statement/MatchPattern.pv"
            return false;
        } break;
        #line 129 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
            #line 129 "src/analyzer/statement/MatchPattern.pv"
            struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
            #line 130 "src/analyzer/statement/MatchPattern.pv"
            struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 132 "src/analyzer/statement/MatchPattern.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 133 "src/analyzer/statement/MatchPattern.pv"
                uintptr_t variable_i = 0;

                #line 135 "src/analyzer/statement/MatchPattern.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 136 "src/analyzer/statement/MatchPattern.pv"
                    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                    #line 137 "src/analyzer/statement/MatchPattern.pv"
                    struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                    #line 138 "src/analyzer/statement/MatchPattern.pv"
                    if (variable == 0) {
                        #line 138 "src/analyzer/statement/MatchPattern.pv"
                        Context__pop_scope(context);
                        #line 138 "src/analyzer/statement/MatchPattern.pv"
                        return false;
                    }

                    #line 140 "src/analyzer/statement/MatchPattern.pv"
                    Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                    #line 142 "src/analyzer/statement/MatchPattern.pv"
                    struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                    #line 143 "src/analyzer/statement/MatchPattern.pv"
                    if (variable_type == 0) {
                        #line 143 "src/analyzer/statement/MatchPattern.pv"
                        return false;
                    }

                    #line 145 "src/analyzer/statement/MatchPattern.pv"
                    if (ref) {
                        #line 146 "src/analyzer/statement/MatchPattern.pv"
                        struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type }});
                        #line 147 "src/analyzer/statement/MatchPattern.pv"
                        variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
                    }

                    #line 150 "src/analyzer/statement/MatchPattern.pv"
                    struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                    #line 151 "src/analyzer/statement/MatchPattern.pv"
                    String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 152 "src/analyzer/statement/MatchPattern.pv"
                    Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                    #line 154 "src/analyzer/statement/MatchPattern.pv"
                    if (!Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                        #line 155 "src/analyzer/statement/MatchPattern.pv"
                        if (!Context__set_value(context, variable, variable_type)) {
                            #line 155 "src/analyzer/statement/MatchPattern.pv"
                            Context__pop_scope(context);
                            #line 155 "src/analyzer/statement/MatchPattern.pv"
                            return false;
                        }
                    }

                    #line 158 "src/analyzer/statement/MatchPattern.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 159 "src/analyzer/statement/MatchPattern.pv"
                        Context__pop_scope(context);
                        #line 160 "src/analyzer/statement/MatchPattern.pv"
                        Context__pop_scope(context);
                        #line 161 "src/analyzer/statement/MatchPattern.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 162 "src/analyzer/statement/MatchPattern.pv"
                        return false;
                    }

                    #line 165 "src/analyzer/statement/MatchPattern.pv"
                    variable_i += 1;
                }

                #line 168 "src/analyzer/statement/MatchPattern.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 168 "src/analyzer/statement/MatchPattern.pv"
                    Context__pop_scope(context);
                    #line 168 "src/analyzer/statement/MatchPattern.pv"
                    return false;
                }

                #line 170 "src/analyzer/statement/MatchPattern.pv"
                if (parameters.length != enum_variant->types.length) {
                    #line 171 "src/analyzer/statement/MatchPattern.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 172 "src/analyzer/statement/MatchPattern.pv"
                    String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                    #line 173 "src/analyzer/statement/MatchPattern.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 174 "src/analyzer/statement/MatchPattern.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            } else {
                #line 177 "src/analyzer/statement/MatchPattern.pv"
                if (enum_variant->types.length > 0) {
                    #line 178 "src/analyzer/statement/MatchPattern.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 179 "src/analyzer/statement/MatchPattern.pv"
                    String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                    #line 180 "src/analyzer/statement/MatchPattern.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 181 "src/analyzer/statement/MatchPattern.pv"
                    String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                    #line 182 "src/analyzer/statement/MatchPattern.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            }

            #line 186 "src/analyzer/statement/MatchPattern.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = type, ._1 = enum_variant, ._2 = parameters} };
            #line 187 "src/analyzer/statement/MatchPattern.pv"
            return true;
        } break;
        #line 189 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
            #line 189 "src/analyzer/statement/MatchPattern.pv"
            struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
            #line 190 "src/analyzer/statement/MatchPattern.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = enum_variant };
            #line 191 "src/analyzer/statement/MatchPattern.pv"
            return true;
        } break;
        #line 193 "src/analyzer/statement/MatchPattern.pv"
        case ENUM_VARIANT_RESULT__FUNCTION: {
            #line 194 "src/analyzer/statement/MatchPattern.pv"
            Context__error(context, "Expected an enum variant, not a function");
            #line 195 "src/analyzer/statement/MatchPattern.pv"
            return false;
        } break;
    }
}
