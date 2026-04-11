#include <stdbool.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Type.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <std/str.h>
#include <analyzer/expression/Expression.h>
#include <std/ArenaAllocator.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <std/Array_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <std/trait_Allocator.h>
#include <std/Array_Type.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/c/EnumCValue.h>
#include <std/Array_MatchPattern.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <analyzer/Block.h>

#include <analyzer/statement/MatchStatement.h>

#line 13 "src/analyzer/statement/MatchStatement.pv"
bool MatchStatement__parse_pattern(struct Context* context, struct Generics* generics, struct MatchPattern* pattern) {
    #line 14 "src/analyzer/statement/MatchStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
        #line 15 "src/analyzer/statement/MatchStatement.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 16 "src/analyzer/statement/MatchStatement.pv"
        return true;
    }

    #line 19 "src/analyzer/statement/MatchStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "typeid")) {
        #line 20 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 20 "src/analyzer/statement/MatchStatement.pv"
            return false;
        }

        #line 22 "src/analyzer/statement/MatchStatement.pv"
        struct Type type;
        #line 23 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__parse_type(context, &type, generics)) {
            #line 23 "src/analyzer/statement/MatchStatement.pv"
            return false;
        }

        #line 25 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 25 "src/analyzer/statement/MatchStatement.pv"
            return false;
        }

        #line 27 "src/analyzer/statement/MatchStatement.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__TYPE_ID, .typeid_value = type };
        #line 28 "src/analyzer/statement/MatchStatement.pv"
        return true;
    }

    #line 31 "src/analyzer/statement/MatchStatement.pv"
    struct Token* token = Context__current(context);
    #line 32 "src/analyzer/statement/MatchStatement.pv"
    if (token == 0) {
        #line 32 "src/analyzer/statement/MatchStatement.pv"
        return false;
    }

    #line 34 "src/analyzer/statement/MatchStatement.pv"
    struct Type* type = Context__get_value(context, token->value);

    #line 36 "src/analyzer/statement/MatchStatement.pv"
    if (type != 0) {
        #line 37 "src/analyzer/statement/MatchStatement.pv"
        Context__next_token(context);
        #line 38 "src/analyzer/statement/MatchStatement.pv"
        struct Expression* expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, type);
        #line 39 "src/analyzer/statement/MatchStatement.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = expression };
        #line 40 "src/analyzer/statement/MatchStatement.pv"
        return true;
    }

    #line 43 "src/analyzer/statement/MatchStatement.pv"
    type = Context__parse_type2(context, generics);
    #line 44 "src/analyzer/statement/MatchStatement.pv"
    if (type == 0) {
        #line 45 "src/analyzer/statement/MatchStatement.pv"
        return false;
    } else if (!Type__is_enum(type)) {
        #line 47 "src/analyzer/statement/MatchStatement.pv"
        Context__error_token(context, token, "Type is not an enum");
        #line 48 "src/analyzer/statement/MatchStatement.pv"
        return false;
    }

    #line 51 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 51 "src/analyzer/statement/MatchStatement.pv"
        return false;
    }

    #line 53 "src/analyzer/statement/MatchStatement.pv"
    struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 54 "src/analyzer/statement/MatchStatement.pv"
    if (enum_variant_token == 0) {
        #line 54 "src/analyzer/statement/MatchStatement.pv"
        return false;
    }

    #line 56 "src/analyzer/statement/MatchStatement.pv"
    struct GenericMap* generic_map = 0;

    #line 58 "src/analyzer/statement/MatchStatement.pv"
    switch (type->type) {
        #line 59 "src/analyzer/statement/MatchStatement.pv"
        case TYPE__SELF: {
            #line 60 "src/analyzer/statement/MatchStatement.pv"
            type = context->type_self;
        } break;
        #line 62 "src/analyzer/statement/MatchStatement.pv"
        default: {
        } break;
    }

    #line 65 "src/analyzer/statement/MatchStatement.pv"
    switch (type->type) {
        #line 66 "src/analyzer/statement/MatchStatement.pv"
        case TYPE__ENUM: {
            #line 66 "src/analyzer/statement/MatchStatement.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 66 "src/analyzer/statement/MatchStatement.pv"
            generic_map = generics;
        } break;
        #line 67 "src/analyzer/statement/MatchStatement.pv"
        case TYPE__ENUM_C: {
        } break;
        #line 68 "src/analyzer/statement/MatchStatement.pv"
        default: {
            #line 69 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 70 "src/analyzer/statement/MatchStatement.pv"
            Context__error(context, "Not an enum type");
            #line 71 "src/analyzer/statement/MatchStatement.pv"
            return false;
        } break;
    }

    #line 75 "src/analyzer/statement/MatchStatement.pv"
    struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
    #line 76 "src/analyzer/statement/MatchStatement.pv"
    switch (enum_variant_result.type) {
        #line 77 "src/analyzer/statement/MatchStatement.pv"
        case ENUM_VARIANT_RESULT__NONE: {
            #line 78 "src/analyzer/statement/MatchStatement.pv"
            Context__error(context, "Could not find enum variant");
            #line 79 "src/analyzer/statement/MatchStatement.pv"
            return false;
        } break;
        #line 81 "src/analyzer/statement/MatchStatement.pv"
        case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
            #line 81 "src/analyzer/statement/MatchStatement.pv"
            struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
            #line 82 "src/analyzer/statement/MatchStatement.pv"
            struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 84 "src/analyzer/statement/MatchStatement.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 85 "src/analyzer/statement/MatchStatement.pv"
                uintptr_t variable_i = 0;

                #line 87 "src/analyzer/statement/MatchStatement.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 88 "src/analyzer/statement/MatchStatement.pv"
                    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                    #line 89 "src/analyzer/statement/MatchStatement.pv"
                    struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                    #line 90 "src/analyzer/statement/MatchStatement.pv"
                    if (variable == 0) {
                        #line 90 "src/analyzer/statement/MatchStatement.pv"
                        Context__pop_scope(context);
                        #line 90 "src/analyzer/statement/MatchStatement.pv"
                        return false;
                    }

                    #line 92 "src/analyzer/statement/MatchStatement.pv"
                    Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                    #line 94 "src/analyzer/statement/MatchStatement.pv"
                    struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                    #line 95 "src/analyzer/statement/MatchStatement.pv"
                    if (variable_type == 0) {
                        #line 95 "src/analyzer/statement/MatchStatement.pv"
                        return false;
                    }

                    #line 97 "src/analyzer/statement/MatchStatement.pv"
                    if (ref) {
                        #line 98 "src/analyzer/statement/MatchStatement.pv"
                        struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                        #line 99 "src/analyzer/statement/MatchStatement.pv"
                        variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                    }

                    #line 102 "src/analyzer/statement/MatchStatement.pv"
                    struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                    #line 103 "src/analyzer/statement/MatchStatement.pv"
                    String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 104 "src/analyzer/statement/MatchStatement.pv"
                    Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                    #line 106 "src/analyzer/statement/MatchStatement.pv"
                    if (!Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                        #line 107 "src/analyzer/statement/MatchStatement.pv"
                        if (!Context__set_value(context, variable, variable_type)) {
                            #line 107 "src/analyzer/statement/MatchStatement.pv"
                            Context__pop_scope(context);
                            #line 107 "src/analyzer/statement/MatchStatement.pv"
                            return false;
                        }
                    }

                    #line 110 "src/analyzer/statement/MatchStatement.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 111 "src/analyzer/statement/MatchStatement.pv"
                        Context__pop_scope(context);
                        #line 112 "src/analyzer/statement/MatchStatement.pv"
                        Context__pop_scope(context);
                        #line 113 "src/analyzer/statement/MatchStatement.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 114 "src/analyzer/statement/MatchStatement.pv"
                        return false;
                    }

                    #line 117 "src/analyzer/statement/MatchStatement.pv"
                    variable_i += 1;
                }

                #line 120 "src/analyzer/statement/MatchStatement.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 120 "src/analyzer/statement/MatchStatement.pv"
                    Context__pop_scope(context);
                    #line 120 "src/analyzer/statement/MatchStatement.pv"
                    return false;
                }

                #line 122 "src/analyzer/statement/MatchStatement.pv"
                if (parameters.length != enum_variant->types.length) {
                    #line 123 "src/analyzer/statement/MatchStatement.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 124 "src/analyzer/statement/MatchStatement.pv"
                    String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                    #line 125 "src/analyzer/statement/MatchStatement.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 126 "src/analyzer/statement/MatchStatement.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            } else {
                #line 129 "src/analyzer/statement/MatchStatement.pv"
                if (enum_variant->types.length > 0) {
                    #line 130 "src/analyzer/statement/MatchStatement.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 131 "src/analyzer/statement/MatchStatement.pv"
                    String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                    #line 132 "src/analyzer/statement/MatchStatement.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 133 "src/analyzer/statement/MatchStatement.pv"
                    String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                    #line 134 "src/analyzer/statement/MatchStatement.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            }

            #line 138 "src/analyzer/statement/MatchStatement.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = type, ._1 = enum_variant, ._2 = parameters} };
            #line 139 "src/analyzer/statement/MatchStatement.pv"
            return true;
        } break;
        #line 141 "src/analyzer/statement/MatchStatement.pv"
        case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
            #line 141 "src/analyzer/statement/MatchStatement.pv"
            struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
            #line 142 "src/analyzer/statement/MatchStatement.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = enum_variant };
            #line 143 "src/analyzer/statement/MatchStatement.pv"
            return true;
        } break;
    }
}

#line 148 "src/analyzer/statement/MatchStatement.pv"
struct MatchStatement* MatchStatement__parse(struct Context* context, struct Generics* generics) {
    #line 149 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match")) {
        #line 149 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 151 "src/analyzer/statement/MatchStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 152 "src/analyzer/statement/MatchStatement.pv"
    if (expression == 0) {
        #line 152 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 154 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 154 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 156 "src/analyzer/statement/MatchStatement.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 158 "src/analyzer/statement/MatchStatement.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 159 "src/analyzer/statement/MatchStatement.pv"
        struct Token* first_match_token = Context__current(context);

        #line 161 "src/analyzer/statement/MatchStatement.pv"
        struct Block* block = Block__new_ptr(context);
        #line 162 "src/analyzer/statement/MatchStatement.pv"
        Context__push_scope(context, block);

        #line 164 "src/analyzer/statement/MatchStatement.pv"
        struct Array_MatchPattern patterns = Array_MatchPattern__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 166 "src/analyzer/statement/MatchStatement.pv"
        while (patterns.length == 0 || Context__check_next(context, TOKEN_TYPE__SYMBOL, "|")) {
            #line 167 "src/analyzer/statement/MatchStatement.pv"
            struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
            #line 168 "src/analyzer/statement/MatchStatement.pv"
            if (!MatchStatement__parse_pattern(context, generics, &pattern)) {
                #line 168 "src/analyzer/statement/MatchStatement.pv"
                return 0;
            }

            #line 170 "src/analyzer/statement/MatchStatement.pv"
            Array_MatchPattern__append(&patterns, pattern);
        }

        #line 173 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>")) {
            #line 173 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 173 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }

        #line 175 "src/analyzer/statement/MatchStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 175 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 175 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }

        #line 177 "src/analyzer/statement/MatchStatement.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .patterns = patterns,
            .body = block,
        };

        #line 183 "src/analyzer/statement/MatchStatement.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 185 "src/analyzer/statement/MatchStatement.pv"
        Context__pop_scope(context);

        #line 187 "src/analyzer/statement/MatchStatement.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 188 "src/analyzer/statement/MatchStatement.pv"
            Context__pop_scope(context);
            #line 189 "src/analyzer/statement/MatchStatement.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 190 "src/analyzer/statement/MatchStatement.pv"
            return 0;
        }
    }

    #line 194 "src/analyzer/statement/MatchStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 194 "src/analyzer/statement/MatchStatement.pv"
        return 0;
    }

    #line 196 "src/analyzer/statement/MatchStatement.pv"
    return ArenaAllocator__store_MatchStatement(context->allocator, (struct MatchStatement) {
        .expression = expression,
        .cases = cases,
    });
}
