#include <string.h>
#include <stdint.h>

#include <stdlib.h>
#include <analyzer/expression/Expression.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <std/str.h>
#include <analyzer/TokenType.h>
#include <analyzer/Module.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Type.h>
#include <std/trait_Allocator.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/Root.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/Primitive.h>
#include <std/String.h>
#include <analyzer/types/Tuple.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/Naming.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/types/Enum.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/EnumC.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/types/Struct.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <analyzer/ImplConst.h>
#include <analyzer/types/FunctionParent.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/types/Trait.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/StructCField.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/ClassCpp.h>
#include <std/Iter_ref_Type.h>
#include <std/Array_ref_Trait.h>
#include <std/Iter_ref_ref_Trait.h>
#include <std/HashMapIter_str_usize.h>
#include <tuple_str_usize.h>
#include <analyzer/types/GenericTypedef.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/Iter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/Iter_ref_Generic.h>
#include <std/HashMapBucket_str_StructField.h>
#include <analyzer/InlayHintKind.h>
#include <std/Array_str.h>
#include <analyzer/expression/CppExpression.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/expression/Expression.h>

#include <analyzer/expression/Expression.h>

#line 13 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type) {
    #line 14 "src/analyzer/expression/Expression.pv"
    return ArenaAllocator__store_Expression(allocator, (struct Expression[]){(struct Expression) {
        .token = token,
        .data = data,
        .return_type = *return_type,
    }});
}

#line 21 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node) {
    #line 22 "src/analyzer/expression/Expression.pv"
    struct Expression* result = ArenaAllocator__store_Expression(context->allocator, &node);

    #line 24 "src/analyzer/expression/Expression.pv"
    Context__next_token(context);

    #line 26 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 29 "src/analyzer/expression/Expression.pv"
struct str Expression__number_primitive(struct str value) {
    #line 30 "src/analyzer/expression/Expression.pv"
    if (str__ends_with(value, "f") || str__ends_with(value, "F")) {
        #line 31 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f32", .length = strlen("f32") };
    } else if (str__ends_with(value, "u") || str__ends_with(value, "U")) {
        #line 33 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "u32", .length = strlen("u32") };
    } else if (str__contains(value, ".")) {
        #line 35 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f64", .length = strlen("f64") };
    }
    #line 37 "src/analyzer/expression/Expression.pv"
    return (struct str){ .ptr = "i32", .length = strlen("i32") };
}

#line 40 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics) {
    #line 41 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 42 "src/analyzer/expression/Expression.pv"
    enum TokenType token_type = token->type;
    #line 43 "src/analyzer/expression/Expression.pv"
    struct Expression* result = 0;

    #line 45 "src/analyzer/expression/Expression.pv"
    switch (token_type) {
        #line 46 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 47 "src/analyzer/expression/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 49 "src/analyzer/expression/Expression.pv"
            if (context->module->mode_cpp && (str__eq(token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__eq(token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 50 "src/analyzer/expression/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 52 "src/analyzer/expression/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 53 "src/analyzer/expression/Expression.pv"
                if (type != 0) {
                    #line 54 "src/analyzer/expression/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 55 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM: {
                            #line 55 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 56 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 56 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 57 "src/analyzer/expression/Expression.pv"
                        case TYPE__SELF: {
                            #line 57 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 58 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 58 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 59 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 59 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 60 "src/analyzer/expression/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 60 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 61 "src/analyzer/expression/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 61 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 62 "src/analyzer/expression/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 62 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 63 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 63 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 66 "src/analyzer/expression/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 67 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                        .data = (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = (struct str) { .ptr = 0, .length = 0 } },
                    });

                    #line 73 "src/analyzer/expression/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 75 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 76 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            } else {
                #line 79 "src/analyzer/expression/Expression.pv"
                switch (return_type->type) {
                    #line 80 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 80 "src/analyzer/expression/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 81 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 82 "src/analyzer/expression/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 83 "src/analyzer/expression/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };

                        #line 85 "src/analyzer/expression/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 86 "src/analyzer/expression/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 89 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 89 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 91 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 93 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 94 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 95 "src/analyzer/expression/Expression.pv"
                            if (argument == 0) {
                                #line 95 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                            #line 96 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                            #line 98 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 99 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 100 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 104 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 104 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 106 "src/analyzer/expression/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 107 "src/analyzer/expression/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 108 "src/analyzer/expression/Expression.pv"
                            func_type = Root__make_type_usage(context->root, func_type, &func_generics->array);
                        }

                        #line 111 "src/analyzer/expression/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 111 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 113 "src/analyzer/expression/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 114 "src/analyzer/expression/Expression.pv"
                        switch (func_type->type) {
                            #line 115 "src/analyzer/expression/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 115 "src/analyzer/expression/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 116 "src/analyzer/expression/Expression.pv"
                                switch (func_info->type) {
                                    #line 117 "src/analyzer/expression/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 118 "src/analyzer/expression/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} }});
                                    } break;
                                    #line 120 "src/analyzer/expression/Expression.pv"
                                    default: {
                                        #line 121 "src/analyzer/expression/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 125 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 128 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 129 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 131 "src/analyzer/expression/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 132 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 133 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 135 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 136 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 137 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 139 "src/analyzer/expression/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 140 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 141 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 143 "src/analyzer/expression/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 144 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 145 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 147 "src/analyzer/expression/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 148 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 149 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 151 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM: {
                        #line 152 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 153 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 155 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 156 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 157 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 159 "src/analyzer/expression/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 160 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 161 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 163 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 164 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 165 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 167 "src/analyzer/expression/Expression.pv"
                    case TYPE__SELF: {
                        #line 168 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 169 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 171 "src/analyzer/expression/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 172 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 173 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 175 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 176 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 177 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 179 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 180 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 181 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 183 "src/analyzer/expression/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 184 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 185 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 187 "src/analyzer/expression/Expression.pv"
                    case TYPE__GLOBAL: {
                        #line 188 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 189 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 191 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 192 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 193 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 195 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 195 "src/analyzer/expression/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 196 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 197 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 197 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 199 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 201 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 202 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 203 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                            #line 205 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 206 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 207 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 211 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 211 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 213 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 215 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, &func_info->return_type);
                    } break;
                    #line 217 "src/analyzer/expression/Expression.pv"
                    default: {
                        #line 218 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 223 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 224 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char },
            });
        } break;
        #line 230 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 231 "src/analyzer/expression/Expression.pv"
            struct str primitive = Expression__number_primitive(token->value);
            #line 232 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 238 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 239 "src/analyzer/expression/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 240 "src/analyzer/expression/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 241 "src/analyzer/expression/Expression.pv"
                if (operator == 0) {
                    #line 241 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 243 "src/analyzer/expression/Expression.pv"
                if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 244 "src/analyzer/expression/Expression.pv"
                    context->pos -= 1;
                    #line 245 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 246 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 248 "src/analyzer/expression/Expression.pv"
                    struct Expression* child = Expression__parse_primary(context, generics);
                    #line 249 "src/analyzer/expression/Expression.pv"
                    if (child == 0) {
                        #line 249 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 251 "src/analyzer/expression/Expression.pv"
                    if (str__eq(operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 252 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 253 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 253 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 254 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) }});
                                #line 255 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 257 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 258 "src/analyzer/expression/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 259 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 263 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 264 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 264 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 265 "src/analyzer/expression/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 266 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect }});
                                #line 267 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 269 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 269 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 272 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 276 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 276 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 278 "src/analyzer/expression/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 279 "src/analyzer/expression/Expression.pv"
                if (expr == 0) {
                    #line 279 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 281 "src/analyzer/expression/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 282 "src/analyzer/expression/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 284 "src/analyzer/expression/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, expr->token);
                    #line 285 "src/analyzer/expression/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 287 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 289 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 290 "src/analyzer/expression/Expression.pv"
                        struct String name_string = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 291 "src/analyzer/expression/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 292 "src/analyzer/expression/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 294 "src/analyzer/expression/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, Context__current(context));
                        #line 295 "src/analyzer/expression/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 297 "src/analyzer/expression/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 298 "src/analyzer/expression/Expression.pv"
                        if (value == 0) {
                            #line 298 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 300 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 302 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 303 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 304 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 308 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple[]){(struct Tuple) { .elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) }});
                    #line 309 "src/analyzer/expression/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 310 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 310 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 310 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 310 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 311 "src/analyzer/expression/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 314 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }}), arguments, 0);
                } else {
                    #line 316 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 316 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 318 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 321 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
                    #line 321 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 323 "src/analyzer/expression/Expression.pv"
                struct Type* element_type = 0;
                #line 324 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 326 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 327 "src/analyzer/expression/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 328 "src/analyzer/expression/Expression.pv"
                    if (element == 0) {
                        #line 328 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 330 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .name = 0, .value = element });

                    #line 332 "src/analyzer/expression/Expression.pv"
                    if (element_type == 0) {
                        #line 333 "src/analyzer/expression/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 336 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 337 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 338 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 342 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 344 "src/analyzer/expression/Expression.pv"
                if (element_type == 0) {
                    #line 344 "src/analyzer/expression/Expression.pv"
                    element_type = &context->root->type_void;
                }
                #line 345 "src/analyzer/expression/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = elements.length }, .element = *element_type, .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
                #line 346 "src/analyzer/expression/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence }});
                #line 347 "src/analyzer/expression/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 349 "src/analyzer/expression/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 351 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 354 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 355 "src/analyzer/expression/Expression.pv"
            if (str__eq(token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__eq(token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 356 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "bool", .length = strlen("bool") }) },
                });
            } else if (str__eq(token->value, (struct str){ .ptr = "if", .length = strlen("if") })) {
                #line 362 "src/analyzer/expression/Expression.pv"
                result = Expression__parse_if_expression(context, generics);
            } else {
                #line 364 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 367 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 368 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 372 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 372 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 374 "src/analyzer/expression/Expression.pv"
    return Expression__parse_postfix_chain(context, result, generics);
}

#line 377 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 378 "src/analyzer/expression/Expression.pv"
    struct Expression* result = Expression__parse_primary(context, generics);
    #line 379 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 379 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 381 "src/analyzer/expression/Expression.pv"
    result = Expression__parse_binary(context, result, 1, generics);
    #line 382 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 382 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 384 "src/analyzer/expression/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 385 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 387 "src/analyzer/expression/Expression.pv"
        struct Expression* range_start = result;
        #line 388 "src/analyzer/expression/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 389 "src/analyzer/expression/Expression.pv"
        if (range_end == 0) {
            #line 389 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 391 "src/analyzer/expression/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, (struct Array_Type[]){(struct Array_Type) { .data = &range_end->return_type, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .capacity = 0 }});
        #line 392 "src/analyzer/expression/Expression.pv"
        if (enum_type == 0) {
            #line 393 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 394 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 397 "src/analyzer/expression/Expression.pv"
        struct Token variant_name = *token;
        #line 398 "src/analyzer/expression/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 399 "src/analyzer/expression/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 401 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 402 "src/analyzer/expression/Expression.pv"
        struct EnumVariant* variant = 0;
        #line 403 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 404 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 404 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* enum_variant = variant_result.enumvariant_value;
                #line 404 "src/analyzer/expression/Expression.pv"
                variant = enum_variant;
            } break;
            #line 405 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
        #line 407 "src/analyzer/expression/Expression.pv"
        if (variant == 0) {
            #line 408 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range StartEnd enum variant");
            #line 409 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 412 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 413 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = range_start });
        #line 414 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = range_end });

        #line 416 "src/analyzer/expression/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 418 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 421 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 424 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 425 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 426 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 426 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 426 "src/analyzer/expression/Expression.pv"
            return str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 427 "src/analyzer/expression/Expression.pv"
        default: {
            #line 427 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 431 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast) {
    #line 432 "src/analyzer/expression/Expression.pv"
    bool success = true;

    #line 434 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 435 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 435 "src/analyzer/expression/Expression.pv"
            struct str operator = self->data.unaryexpression_value._0;
            #line 435 "src/analyzer/expression/Expression.pv"
            struct Expression* child = self->data.unaryexpression_value._1;
            #line 436 "src/analyzer/expression/Expression.pv"
            if (str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 437 "src/analyzer/expression/Expression.pv"
                switch (type->type) {
                    #line 438 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 438 "src/analyzer/expression/Expression.pv"
                        struct Indirect* indirect = type->indirect_value;
                        #line 439 "src/analyzer/expression/Expression.pv"
                        switch (indirect->to.type) {
                            #line 440 "src/analyzer/expression/Expression.pv"
                            case TYPE__SEQUENCE: {
                                #line 441 "src/analyzer/expression/Expression.pv"
                                switch (child->data.type) {
                                    #line 442 "src/analyzer/expression/Expression.pv"
                                    case EXPRESSION_DATA__INVOKE: {
                                        #line 443 "src/analyzer/expression/Expression.pv"
                                        if (Type__is_sequence_fixed_array(&child->return_type)) {
                                            #line 444 "src/analyzer/expression/Expression.pv"
                                            Expression__validate_type(child, context, &indirect->to, apply_implicit_cast);
                                        }
                                    } break;
                                    #line 447 "src/analyzer/expression/Expression.pv"
                                    default: {
                                    } break;
                                }
                            } break;
                            #line 450 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 453 "src/analyzer/expression/Expression.pv"
                    default: {
                    } break;
                }
            }
        } break;
        #line 457 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 457 "src/analyzer/expression/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 457 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 458 "src/analyzer/expression/Expression.pv"
            switch (type->type) {
                #line 459 "src/analyzer/expression/Expression.pv"
                case TYPE__TUPLE: {
                    #line 459 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = type->tuple_value;
                    #line 460 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 460 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 460 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 460 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 461 "src/analyzer/expression/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i], apply_implicit_cast) && success;
                    } }

                    #line 464 "src/analyzer/expression/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type };
                    #line 465 "src/analyzer/expression/Expression.pv"
                    invoke->return_type = *type;
                    #line 466 "src/analyzer/expression/Expression.pv"
                    self->return_type = *type;

                    #line 468 "src/analyzer/expression/Expression.pv"
                    return success;
                } break;
                #line 470 "src/analyzer/expression/Expression.pv"
                case TYPE__SEQUENCE: {
                    #line 470 "src/analyzer/expression/Expression.pv"
                    struct Sequence* sequence = type->sequence_value;
                    #line 471 "src/analyzer/expression/Expression.pv"
                    if (Type__is_sequence_fixed_array(&self->return_type)) {
                        #line 472 "src/analyzer/expression/Expression.pv"
                        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                        #line 472 "src/analyzer/expression/Expression.pv"
                        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                            #line 472 "src/analyzer/expression/Expression.pv"
                            struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                            #line 473 "src/analyzer/expression/Expression.pv"
                            success = Expression__validate_type(argument->value, context, &sequence->element, apply_implicit_cast) && success;
                        } }

                        #line 476 "src/analyzer/expression/Expression.pv"
                        switch (self->return_type.type) {
                            #line 477 "src/analyzer/expression/Expression.pv"
                            case TYPE__SEQUENCE: {
                                #line 477 "src/analyzer/expression/Expression.pv"
                                struct Sequence* self_seq = self->return_type.sequence_value;
                                #line 478 "src/analyzer/expression/Expression.pv"
                                struct Sequence* new_seq = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) { .type = self_seq->type, .element = sequence->element, .element_pointer = self_seq->element_pointer }});
                                #line 479 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = new_seq }});
                                #line 480 "src/analyzer/expression/Expression.pv"
                                invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type };
                                #line 481 "src/analyzer/expression/Expression.pv"
                                invoke->return_type = *new_type;
                                #line 482 "src/analyzer/expression/Expression.pv"
                                self->return_type = *new_type;
                            } break;
                            #line 484 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 487 "src/analyzer/expression/Expression.pv"
                        return success;
                    }
                } break;
                #line 490 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 493 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 496 "src/analyzer/expression/Expression.pv"
    if (apply_implicit_cast && Type__needs_implicit_cast(type, &self->return_type)) {
        #line 497 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, self);
        #line 498 "src/analyzer/expression/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 499 "src/analyzer/expression/Expression.pv"
        self->return_type = *type;
        #line 500 "src/analyzer/expression/Expression.pv"
        return true;
    }

    #line 503 "src/analyzer/expression/Expression.pv"
    if (!Type__eq(type, &self->return_type)) {
        #line 504 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 505 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
        #line 506 "src/analyzer/expression/Expression.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 507 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&type_name));
        #line 508 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 509 "src/analyzer/expression/Expression.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 510 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 511 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, self->token, String__c_str(&message));
        #line 512 "src/analyzer/expression/Expression.pv"
        return false;
    }
    #line 516 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 519 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics) {
    #line 520 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 521 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 521 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 523 "src/analyzer/expression/Expression.pv"
    struct Expression* condition = Expression__parse(context, generics);
    #line 524 "src/analyzer/expression/Expression.pv"
    if (condition == 0) {
        #line 524 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 526 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 526 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 528 "src/analyzer/expression/Expression.pv"
    struct Expression* a = Expression__parse(context, generics);
    #line 529 "src/analyzer/expression/Expression.pv"
    if (a == 0) {
        #line 529 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 531 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 531 "src/analyzer/expression/Expression.pv"
        return 0;
    }
    #line 532 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 532 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 534 "src/analyzer/expression/Expression.pv"
    bool is_else_if = Context__check_value(context, TOKEN_TYPE__KEYWORD, "if");

    #line 536 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 537 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Expected { or else if");
        #line 538 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 541 "src/analyzer/expression/Expression.pv"
    struct Expression* b = Expression__parse(context, generics);
    #line 542 "src/analyzer/expression/Expression.pv"
    if (b == 0) {
        #line 542 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 544 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 544 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 546 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_type(a, context, &b->return_type, false)) {
        #line 546 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 548 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__IF_EXPRESSION, .ifexpression_value = { ._0 = condition, ._1 = a, ._2 = b} }, &a->return_type);
}

#line 9 "src/analyzer/expression/MemberLookup.pv"
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token) {
    #line 10 "src/analyzer/expression/MemberLookup.pv"
    switch (type->type) {
        #line 11 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__INDIRECT: {
            #line 11 "src/analyzer/expression/MemberLookup.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 12 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_enum_variant(context, &indirect->to, token);
        } break;
        #line 14 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SELF: {
            #line 15 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_enum_variant(context, context->type_self, token);
        } break;
        #line 17 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM: {
            #line 17 "src/analyzer/expression/MemberLookup.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 17 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 18 "src/analyzer/expression/MemberLookup.pv"
            struct EnumVariant* variant = HashMap_str_EnumVariant__find(&enum_info->variants, &token->value);
            #line 19 "src/analyzer/expression/MemberLookup.pv"
            if (variant != 0) {
                #line 20 "src/analyzer/expression/MemberLookup.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_VARIANT, .enumvariant_value = variant };
            }

            #line 23 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 23 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 23 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 24 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, token->value);
                #line 25 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 26 "src/analyzer/expression/MemberLookup.pv"
                    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} };
                }
            } }

            #line 30 "src/analyzer/expression/MemberLookup.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
        #line 32 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM_C: {
            #line 32 "src/analyzer/expression/MemberLookup.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 33 "src/analyzer/expression/MemberLookup.pv"
            struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &token->value);
            #line 34 "src/analyzer/expression/MemberLookup.pv"
            if (variant == 0) {
                #line 35 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, token, "Variant not found in enum");
                #line 36 "src/analyzer/expression/MemberLookup.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
            }

            #line 39 "src/analyzer/expression/MemberLookup.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_CVALUE, .enumcvalue_value = variant };
        } break;
        #line 41 "src/analyzer/expression/MemberLookup.pv"
        default: {
            #line 41 "src/analyzer/expression/MemberLookup.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
    }

    #line 44 "src/analyzer/expression/MemberLookup.pv"
    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
}

#line 47 "src/analyzer/expression/MemberLookup.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error) {
    #line 48 "src/analyzer/expression/MemberLookup.pv"
    switch (type->type) {
        #line 49 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__INDIRECT: {
            #line 49 "src/analyzer/expression/MemberLookup.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 50 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 52 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SELF: {
            #line 53 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 55 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__PRIMITIVE: {
            #line 55 "src/analyzer/expression/MemberLookup.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 56 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 56 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 56 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 57 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 58 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 59 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }})} }});
                }
            } }

            #line 63 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 63 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 64 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 66 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__STRUCT: {
            #line 66 "src/analyzer/expression/MemberLookup.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 66 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 67 "src/analyzer/expression/MemberLookup.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 68 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 69 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 72 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 72 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 72 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 73 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 74 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 75 "src/analyzer/expression/MemberLookup.pv"
                    if (impl_info->typedefs.length == 0) {
                        #line 76 "src/analyzer/expression/MemberLookup.pv"
                        return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                    }
                    #line 78 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 79 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 80 "src/analyzer/expression/MemberLookup.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 80 "src/analyzer/expression/MemberLookup.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 80 "src/analyzer/expression/MemberLookup.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 80 "src/analyzer/expression/MemberLookup.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 81 "src/analyzer/expression/MemberLookup.pv"
                        GenericMap__insert(aug_map, name, *typedef_type);
                    } }
                    #line 83 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = aug_map} }});
                }
            } }

            #line 87 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 87 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 87 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 88 "src/analyzer/expression/MemberLookup.pv"
                struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member->value);
                #line 89 "src/analyzer/expression/MemberLookup.pv"
                if (impl_const_ptr != 0) {
                    #line 90 "src/analyzer/expression/MemberLookup.pv"
                    struct ImplConst* impl_const = *impl_const_ptr;
                    #line 91 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, &impl_const->type);
                }
            } }

            #line 95 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 96 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 98 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 100 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 100 "src/analyzer/expression/MemberLookup.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 100 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 101 "src/analyzer/expression/MemberLookup.pv"
            if (str__eq(member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 102 "src/analyzer/expression/MemberLookup.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, &context->root->func_next);
                #line 103 "src/analyzer/expression/MemberLookup.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 104 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} }});
            }

            #line 107 "src/analyzer/expression/MemberLookup.pv"
            if (str__eq(member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 108 "src/analyzer/expression/MemberLookup.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, &context->root->func_value);
                #line 109 "src/analyzer/expression/MemberLookup.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 110 "src/analyzer/expression/MemberLookup.pv"
                func_value->return_type = func_info->return_type;
                #line 111 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} }});
            }

            #line 114 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 114 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 115 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 117 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM: {
            #line 117 "src/analyzer/expression/MemberLookup.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 117 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 118 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 118 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 118 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 119 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 120 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 121 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                }
            } }

            #line 125 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 125 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 126 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 128 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TRAIT: {
            #line 128 "src/analyzer/expression/MemberLookup.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 128 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 129 "src/analyzer/expression/MemberLookup.pv"
            if (str__eq(member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 130 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) }});
            }

            #line 133 "src/analyzer/expression/MemberLookup.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 134 "src/analyzer/expression/MemberLookup.pv"
            if (function == 0) {
                #line 135 "src/analyzer/expression/MemberLookup.pv"
                if (output_error) {
                    #line 135 "src/analyzer/expression/MemberLookup.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 136 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 139 "src/analyzer/expression/MemberLookup.pv"
            return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
        } break;
        #line 141 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TYPEDEF_C: {
            #line 141 "src/analyzer/expression/MemberLookup.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 142 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 144 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__STRUCT_C: {
            #line 144 "src/analyzer/expression/MemberLookup.pv"
            struct StructC* struct_info = type->structc_value;
            #line 145 "src/analyzer/expression/MemberLookup.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 146 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 146 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 148 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 148 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 149 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 151 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__UNION_C: {
            #line 151 "src/analyzer/expression/MemberLookup.pv"
            struct StructC* union_info = type->unionc_value;
            #line 152 "src/analyzer/expression/MemberLookup.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 153 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 153 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 155 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 155 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 156 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 158 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__CLASS_CPP: {
            #line 158 "src/analyzer/expression/MemberLookup.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 159 "src/analyzer/expression/MemberLookup.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 160 "src/analyzer/expression/MemberLookup.pv"
            if (field_type != 0) {
                #line 160 "src/analyzer/expression/MemberLookup.pv"
                return field_type;
            }

            #line 162 "src/analyzer/expression/MemberLookup.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 163 "src/analyzer/expression/MemberLookup.pv"
            if (value_type != 0) {
                #line 163 "src/analyzer/expression/MemberLookup.pv"
                return value_type;
            }

            #line 165 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 165 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 165 "src/analyzer/expression/MemberLookup.pv"
                struct Type* base = Iter_ref_Type__value(&__iter);

                #line 166 "src/analyzer/expression/MemberLookup.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 167 "src/analyzer/expression/MemberLookup.pv"
                if (base_type != 0) {
                    #line 167 "src/analyzer/expression/MemberLookup.pv"
                    return base_type;
                }
            } }

            #line 170 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 170 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 171 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 173 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__GENERIC: {
            #line 173 "src/analyzer/expression/MemberLookup.pv"
            struct Generic* generic = type->generic_value;
            #line 174 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
            #line 174 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 174 "src/analyzer/expression/MemberLookup.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 175 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 176 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 177 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap generic_map_val = (struct GenericMap) { .self_type = 0, .array = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }), .map = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) };
                    #line 178 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(context->allocator, &generic_map_val);
                    #line 179 "src/analyzer/expression/MemberLookup.pv"
                    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
                    #line 179 "src/analyzer/expression/MemberLookup.pv"
                    while (HashMapIter_str_usize__next(&__iter)) {
                        #line 179 "src/analyzer/expression/MemberLookup.pv"
                        struct str typedef_name = HashMapIter_str_usize__value(&__iter)->_0;

                        #line 180 "src/analyzer/expression/MemberLookup.pv"
                        struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(context->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic, .typedef_name = typedef_name }});
                        #line 181 "src/analyzer/expression/MemberLookup.pv"
                        GenericMap__insert(generic_map, typedef_name, (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt });
                    } }
                    #line 183 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                }
            } }

            #line 187 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 187 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 188 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 190 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SEQUENCE: {
            #line 190 "src/analyzer/expression/MemberLookup.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 191 "src/analyzer/expression/MemberLookup.pv"
            if (str__eq(member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 192 "src/analyzer/expression/MemberLookup.pv"
                return &sequence->element_pointer;
            }

            #line 195 "src/analyzer/expression/MemberLookup.pv"
            if (str__eq(member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 196 "src/analyzer/expression/MemberLookup.pv"
                return &context->root->type_usize;
            }

            #line 199 "src/analyzer/expression/MemberLookup.pv"
            struct Impl* impl_info = context->root->hack_type_impl->impl_info;

            #line 201 "src/analyzer/expression/MemberLookup.pv"
            struct Function* function = Impl__find_function(impl_info, member->value);
            #line 202 "src/analyzer/expression/MemberLookup.pv"
            if (function != 0) {
                #line 203 "src/analyzer/expression/MemberLookup.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }});
                #line 204 "src/analyzer/expression/MemberLookup.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 205 "src/analyzer/expression/MemberLookup.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) }});

                #line 207 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &generic_map)} }});
            }

            #line 210 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 210 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 211 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 213 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TUPLE: {
            #line 213 "src/analyzer/expression/MemberLookup.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 214 "src/analyzer/expression/MemberLookup.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 215 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 216 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 219 "src/analyzer/expression/MemberLookup.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 220 "src/analyzer/expression/MemberLookup.pv"
            if (index >= tuple->elements.length) {
                #line 221 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 222 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 225 "src/analyzer/expression/MemberLookup.pv"
            return &tuple->elements.data[index];
        } break;
        #line 227 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 227 "src/analyzer/expression/MemberLookup.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 228 "src/analyzer/expression/MemberLookup.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 229 "src/analyzer/expression/MemberLookup.pv"
            if (type != 0) {
                #line 229 "src/analyzer/expression/MemberLookup.pv"
                return type;
            }

            #line 231 "src/analyzer/expression/MemberLookup.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 232 "src/analyzer/expression/MemberLookup.pv"
            if (value != 0) {
                #line 232 "src/analyzer/expression/MemberLookup.pv"
                return value;
            }

            #line 234 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 234 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 236 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 238 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__UNKNOWN_C: {
            #line 238 "src/analyzer/expression/MemberLookup.pv"
            return type;
        } break;
        #line 239 "src/analyzer/expression/MemberLookup.pv"
        default: {
            #line 239 "src/analyzer/expression/MemberLookup.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 242 "src/analyzer/expression/MemberLookup.pv"
    return 0;
}

#line 6 "src/analyzer/expression/GenericResolve.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments) {
    #line 7 "src/analyzer/expression/GenericResolve.pv"
    struct GenericMap generic_map = GenericMap__from_generics(context->allocator, &func_info->generics);

    #line 9 "src/analyzer/expression/GenericResolve.pv"
    uintptr_t i = 0;
    #line 10 "src/analyzer/expression/GenericResolve.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(generics);
    #line 10 "src/analyzer/expression/GenericResolve.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 10 "src/analyzer/expression/GenericResolve.pv"
        struct Type* generic = Iter_ref_Type__value(&__iter);

        #line 11 "src/analyzer/expression/GenericResolve.pv"
        struct Type* target = Array_Type__get(&generic_map.array, i);
        #line 12 "src/analyzer/expression/GenericResolve.pv"
        if (target != 0) {
            #line 12 "src/analyzer/expression/GenericResolve.pv"
            *target = *generic;
        }
        #line 13 "src/analyzer/expression/GenericResolve.pv"
        i += 1;
    } }

    #line 16 "src/analyzer/expression/GenericResolve.pv"
    if (i == generic_map.array.length) {
        #line 17 "src/analyzer/expression/GenericResolve.pv"
        return ArenaAllocator__store_GenericMap(context->allocator, &generic_map);
    }

    #line 20 "src/analyzer/expression/GenericResolve.pv"
    struct Iter_ref_Parameter params = Array_Parameter__iter(&func_info->parameters);
    #line 21 "src/analyzer/expression/GenericResolve.pv"
    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);

    #line 23 "src/analyzer/expression/GenericResolve.pv"
    while (Iter_ref_Parameter__next(&params) && Iter_ref_InvokeArgument__next(&args)) {
        #line 24 "src/analyzer/expression/GenericResolve.pv"
        struct Type* param_type = &Iter_ref_Parameter__value(&params)->type;
        #line 25 "src/analyzer/expression/GenericResolve.pv"
        struct Type* arg_type = &Iter_ref_InvokeArgument__value(&args)->value->return_type;

        #line 27 "src/analyzer/expression/GenericResolve.pv"
        Expression__resolve_generic_type(context, param_type, arg_type, &generic_map);
    }

    #line 30 "src/analyzer/expression/GenericResolve.pv"
    { struct Iter_ref_Generic __iter = Array_Generic__iter(&func_info->generics.array);
    #line 30 "src/analyzer/expression/GenericResolve.pv"
    while (Iter_ref_Generic__next(&__iter)) {
        #line 30 "src/analyzer/expression/GenericResolve.pv"
        struct Generic* generic = Iter_ref_Generic__value(&__iter);

        #line 31 "src/analyzer/expression/GenericResolve.pv"
        struct Type* concrete_type = GenericMap__get(&generic_map, generic->name->value);
        #line 32 "src/analyzer/expression/GenericResolve.pv"
        if (concrete_type == 0) {
            #line 32 "src/analyzer/expression/GenericResolve.pv"
            continue;
        }

        #line 34 "src/analyzer/expression/GenericResolve.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 34 "src/analyzer/expression/GenericResolve.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 34 "src/analyzer/expression/GenericResolve.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 35 "src/analyzer/expression/GenericResolve.pv"
            { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
            #line 35 "src/analyzer/expression/GenericResolve.pv"
            while (HashMapIter_str_usize__next(&__iter)) {
                #line 35 "src/analyzer/expression/GenericResolve.pv"
                struct str typedef_name = HashMapIter_str_usize__value(&__iter)->_0;

                #line 36 "src/analyzer/expression/GenericResolve.pv"
                switch (concrete_type->type) {
                    #line 37 "src/analyzer/expression/GenericResolve.pv"
                    case TYPE__STRUCT: {
                        #line 37 "src/analyzer/expression/GenericResolve.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 38 "src/analyzer/expression/GenericResolve.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 38 "src/analyzer/expression/GenericResolve.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 38 "src/analyzer/expression/GenericResolve.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 39 "src/analyzer/expression/GenericResolve.pv"
                            if (impl_info->trait_ != trait_info) {
                                #line 39 "src/analyzer/expression/GenericResolve.pv"
                                continue;
                            }
                            #line 40 "src/analyzer/expression/GenericResolve.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &typedef_name);
                            #line 41 "src/analyzer/expression/GenericResolve.pv"
                            if (typedef_type != 0) {
                                #line 42 "src/analyzer/expression/GenericResolve.pv"
                                GenericMap__insert(&generic_map, typedef_name, *typedef_type);
                            }
                        } }
                    } break;
                    #line 46 "src/analyzer/expression/GenericResolve.pv"
                    default: {
                    } break;
                }
            } }
        } }
    } }

    #line 52 "src/analyzer/expression/GenericResolve.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, &generic_map);
}

#line 55 "src/analyzer/expression/GenericResolve.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 56 "src/analyzer/expression/GenericResolve.pv"
    switch (param_type->type) {
        #line 57 "src/analyzer/expression/GenericResolve.pv"
        case TYPE__GENERIC: {
            #line 57 "src/analyzer/expression/GenericResolve.pv"
            struct Generic* generic = param_type->generic_value;
            #line 58 "src/analyzer/expression/GenericResolve.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 59 "src/analyzer/expression/GenericResolve.pv"
            if (generic_type != 0) {
                #line 59 "src/analyzer/expression/GenericResolve.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 61 "src/analyzer/expression/GenericResolve.pv"
        case TYPE__INDIRECT: {
            #line 61 "src/analyzer/expression/GenericResolve.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 62 "src/analyzer/expression/GenericResolve.pv"
            switch (arg_type->type) {
                #line 63 "src/analyzer/expression/GenericResolve.pv"
                case TYPE__INDIRECT: {
                    #line 63 "src/analyzer/expression/GenericResolve.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 64 "src/analyzer/expression/GenericResolve.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 66 "src/analyzer/expression/GenericResolve.pv"
                default: {
                } break;
            }
        } break;
        #line 69 "src/analyzer/expression/GenericResolve.pv"
        default: {
        } break;
    }
}

#line 7 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call) {
    #line 8 "src/analyzer/expression/ExpressionValidate.pv"
    uintptr_t arguments_length = arguments->length;

    #line 10 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 11 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__SELF: {
            #line 11 "src/analyzer/expression/ExpressionValidate.pv"
            {
                #line 11 "src/analyzer/expression/ExpressionValidate.pv"
                type = context->type_self;
            }
        } break;
        #line 12 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
        } break;
    }

    #line 15 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 16 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TYPEDEF_C: {
            #line 16 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 17 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNION_C: {
            #line 17 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 18 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT_C: {
            #line 18 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 19 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TUPLE: {
            #line 19 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 20 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT: {
            #line 20 "src/analyzer/expression/ExpressionValidate.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 20 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 21 "src/analyzer/expression/ExpressionValidate.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 21 "src/analyzer/expression/ExpressionValidate.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 21 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 22 "src/analyzer/expression/ExpressionValidate.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg->name->value);

                #line 24 "src/analyzer/expression/ExpressionValidate.pv"
                if (param == 0) {
                    #line 25 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg->name, "Unable to find field in struct");
                    #line 26 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 29 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &param->type;

                #line 31 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2->map.length > 0) {
                    #line 32 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 34 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 37 "src/analyzer/expression/ExpressionValidate.pv"
                if (param_type == 0) {
                    #line 38 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve field type");
                    #line 39 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 42 "src/analyzer/expression/ExpressionValidate.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            } }

            #line 45 "src/analyzer/expression/ExpressionValidate.pv"
            bool success = true;
            #line 46 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t field_i = 0;
            #line 47 "src/analyzer/expression/ExpressionValidate.pv"
            while (field_i < struct_info->fields.length) {
                #line 48 "src/analyzer/expression/ExpressionValidate.pv"
                struct HashMapBucket_str_StructField* bucket = struct_info->fields.data + field_i;
                #line 49 "src/analyzer/expression/ExpressionValidate.pv"
                bool provided = false;
                #line 50 "src/analyzer/expression/ExpressionValidate.pv"
                uintptr_t arg_i = 0;
                #line 51 "src/analyzer/expression/ExpressionValidate.pv"
                while (arg_i < arguments->length) {
                    #line 52 "src/analyzer/expression/ExpressionValidate.pv"
                    if (str__eq(arguments->data[arg_i].name->value, bucket->key)) {
                        #line 53 "src/analyzer/expression/ExpressionValidate.pv"
                        provided = true;
                        #line 54 "src/analyzer/expression/ExpressionValidate.pv"
                        break;
                    }
                    #line 56 "src/analyzer/expression/ExpressionValidate.pv"
                    arg_i += 1;
                }
                #line 58 "src/analyzer/expression/ExpressionValidate.pv"
                if (!provided) {
                    #line 59 "src/analyzer/expression/ExpressionValidate.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 60 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, (struct str){ .ptr = "Missing field in struct construction: ", .length = strlen("Missing field in struct construction: ") });
                    #line 61 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, bucket->key);
                    #line 62 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, token, String__c_str(&message));
                    #line 63 "src/analyzer/expression/ExpressionValidate.pv"
                    success = false;
                }
                #line 65 "src/analyzer/expression/ExpressionValidate.pv"
                field_i += 1;
            }

            #line 68 "src/analyzer/expression/ExpressionValidate.pv"
            return success;
        } break;
        #line 70 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION: {
            #line 70 "src/analyzer/expression/ExpressionValidate.pv"
            struct Function* function = type->function_value._0;
            #line 70 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 71 "src/analyzer/expression/ExpressionValidate.pv"
            if (function == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 71 "src/analyzer/expression/ExpressionValidate.pv"
                return true;
            }

            #line 73 "src/analyzer/expression/ExpressionValidate.pv"
            if (function->parameters.length != arguments_length) {
                #line 74 "src/analyzer/expression/ExpressionValidate.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 75 "src/analyzer/expression/ExpressionValidate.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 77 "src/analyzer/expression/ExpressionValidate.pv"
                if (is_member_call) {
                    #line 78 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append_usize(&message, function->parameters.length - 1);
                } else {
                    #line 80 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append_usize(&message, function->parameters.length);
                }

                #line 83 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 84 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 87 "src/analyzer/expression/ExpressionValidate.pv"
            struct Iter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 88 "src/analyzer/expression/ExpressionValidate.pv"
            struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

            #line 90 "src/analyzer/expression/ExpressionValidate.pv"
            if (is_member_call) {
                #line 91 "src/analyzer/expression/ExpressionValidate.pv"
                Iter_ref_Parameter__next(&param_iter);
                #line 92 "src/analyzer/expression/ExpressionValidate.pv"
                Iter_ref_InvokeArgument__next(&args_iter);

                #line 94 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 95 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &Iter_ref_Parameter__value(&param_iter)->type;

                #line 97 "src/analyzer/expression/ExpressionValidate.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 98 "src/analyzer/expression/ExpressionValidate.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) }});
                    #line 99 "src/analyzer/expression/ExpressionValidate.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 103 "src/analyzer/expression/ExpressionValidate.pv"
            while (Iter_ref_Parameter__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
                #line 104 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 105 "src/analyzer/expression/ExpressionValidate.pv"
                struct Parameter* param = Iter_ref_Parameter__value(&param_iter);
                #line 106 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &param->type;

                #line 108 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2->map.length > 0) {
                    #line 109 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 111 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 114 "src/analyzer/expression/ExpressionValidate.pv"
                if (param_type == 0) {
                    #line 115 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
                    #line 116 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 119 "src/analyzer/expression/ExpressionValidate.pv"
                Expression__validate_type(arg->value, context, param_type, true);

                #line 121 "src/analyzer/expression/ExpressionValidate.pv"
                if (arg->name == 0 && param->name != 0 && !str__eq(param->name->value, (struct str){ .ptr = "self", .length = strlen("self") }) && !str__eq(param->name->value, arg->value->token->value)) {
                    #line 122 "src/analyzer/expression/ExpressionValidate.pv"
                    struct String label = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 123 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&label, param->name->value);
                    #line 124 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&label, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 125 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__inlay_hint_before(context, arg->value->token, String__c_str(&label), INLAY_HINT_KIND__PARAMETER, false, true);
                }
            }

            #line 129 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 131 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION_C: {
            #line 131 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 132 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__CLASS_CPP: {
            #line 132 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 133 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNKNOWN_C: {
            #line 133 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 134 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
            #line 134 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 137 "src/analyzer/expression/ExpressionValidate.pv"
    return false;
}

#line 140 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 141 "src/analyzer/expression/ExpressionValidate.pv"
    uintptr_t arguments_length = arguments->length;

    #line 143 "src/analyzer/expression/ExpressionValidate.pv"
    if (variant->types.length != arguments_length) {
        #line 144 "src/analyzer/expression/ExpressionValidate.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 145 "src/analyzer/expression/ExpressionValidate.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 146 "src/analyzer/expression/ExpressionValidate.pv"
        String__append_usize(&message, variant->types.length);
        #line 147 "src/analyzer/expression/ExpressionValidate.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 148 "src/analyzer/expression/ExpressionValidate.pv"
        return false;
    }

    #line 151 "src/analyzer/expression/ExpressionValidate.pv"
    if (variant->names.length > 0) {
        #line 152 "src/analyzer/expression/ExpressionValidate.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 152 "src/analyzer/expression/ExpressionValidate.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 152 "src/analyzer/expression/ExpressionValidate.pv"
            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

            #line 153 "src/analyzer/expression/ExpressionValidate.pv"
            if (arg->name == 0) {
                #line 154 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, token, "Expected named field argument");
                #line 155 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 158 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t field_i = 0;
            #line 159 "src/analyzer/expression/ExpressionValidate.pv"
            bool found = false;
            #line 160 "src/analyzer/expression/ExpressionValidate.pv"
            while (field_i < variant->names.length) {
                #line 161 "src/analyzer/expression/ExpressionValidate.pv"
                if (str__eq(variant->names.data[field_i], arg->name->value)) {
                    #line 162 "src/analyzer/expression/ExpressionValidate.pv"
                    found = true;
                    #line 163 "src/analyzer/expression/ExpressionValidate.pv"
                    break;
                }
                #line 165 "src/analyzer/expression/ExpressionValidate.pv"
                field_i += 1;
            }

            #line 168 "src/analyzer/expression/ExpressionValidate.pv"
            if (!found) {
                #line 169 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, arg->name, "Field not found in enum variant");
                #line 170 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 173 "src/analyzer/expression/ExpressionValidate.pv"
            struct Type* param_type = variant->types.data + field_i;
            #line 174 "src/analyzer/expression/ExpressionValidate.pv"
            if (generic_map != 0) {
                #line 175 "src/analyzer/expression/ExpressionValidate.pv"
                param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
            }

            #line 178 "src/analyzer/expression/ExpressionValidate.pv"
            if (param_type == 0) {
                #line 179 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, arg->value->token, "Unable to resolve field type");
                #line 180 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 183 "src/analyzer/expression/ExpressionValidate.pv"
            Expression__validate_type(arg->value, context, param_type, true);
        } }

        #line 186 "src/analyzer/expression/ExpressionValidate.pv"
        return true;
    }

    #line 189 "src/analyzer/expression/ExpressionValidate.pv"
    struct Iter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 190 "src/analyzer/expression/ExpressionValidate.pv"
    struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 192 "src/analyzer/expression/ExpressionValidate.pv"
    while (Iter_ref_Type__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
        #line 193 "src/analyzer/expression/ExpressionValidate.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
        #line 194 "src/analyzer/expression/ExpressionValidate.pv"
        struct Type* param_type = Iter_ref_Type__value(&param_iter);

        #line 196 "src/analyzer/expression/ExpressionValidate.pv"
        if (generic_map != 0) {
            #line 197 "src/analyzer/expression/ExpressionValidate.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 200 "src/analyzer/expression/ExpressionValidate.pv"
        if (param_type == 0) {
            #line 201 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
            #line 202 "src/analyzer/expression/ExpressionValidate.pv"
            return false;
        }

        #line 205 "src/analyzer/expression/ExpressionValidate.pv"
        Expression__validate_type(arg->value, context, param_type, true);
    }

    #line 208 "src/analyzer/expression/ExpressionValidate.pv"
    return true;
}

#line 211 "src/analyzer/expression/ExpressionValidate.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 212 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 213 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TUPLE: {
            #line 213 "src/analyzer/expression/ExpressionValidate.pv"
            return type;
        } break;
        #line 214 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION: {
            #line 214 "src/analyzer/expression/ExpressionValidate.pv"
            struct Function* func_info = type->function_value._0;
            #line 214 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 215 "src/analyzer/expression/ExpressionValidate.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 216 "src/analyzer/expression/ExpressionValidate.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} }});
            }
            #line 218 "src/analyzer/expression/ExpressionValidate.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 220 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION_C: {
            #line 220 "src/analyzer/expression/ExpressionValidate.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 220 "src/analyzer/expression/ExpressionValidate.pv"
            return &func_info->return_type;
        } break;
        #line 221 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNKNOWN_C: {
            #line 221 "src/analyzer/expression/ExpressionValidate.pv"
            return type;
        } break;
        #line 222 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
            #line 222 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 225 "src/analyzer/expression/ExpressionValidate.pv"
    return 0;
}

#line 228 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 229 "src/analyzer/expression/ExpressionValidate.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 229 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 231 "src/analyzer/expression/ExpressionValidate.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 232 "src/analyzer/expression/ExpressionValidate.pv"
    if (func_return_type == 0) {
        #line 232 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 234 "src/analyzer/expression/ExpressionValidate.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 235 "src/analyzer/expression/ExpressionValidate.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 238 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 239 "src/analyzer/expression/ExpressionValidate.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 239 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 241 "src/analyzer/expression/ExpressionValidate.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 242 "src/analyzer/expression/ExpressionValidate.pv"
    if (func_return_type == 0) {
        #line 242 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 244 "src/analyzer/expression/ExpressionValidate.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, func_return_type);
}

#line 7 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics) {
    #line 8 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 9 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* variant_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 10 "src/analyzer/expression/ParseTypeExpression.pv"
        if (variant_name == 0) {
            #line 10 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 12 "src/analyzer/expression/ParseTypeExpression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, variant_name);

        #line 14 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (variant_result.type) {
            #line 15 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__NONE: {
                #line 16 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__error_token(context, variant_name, "Unable to find enum variant or function");
                #line 17 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            } break;
            #line 19 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__FUNCTION: {
                #line 19 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Function* function = variant_result.function_value._0;
                #line 19 "src/analyzer/expression/ParseTypeExpression.pv"
                struct GenericMap* generic_map = variant_result.function_value._1;
                #line 20 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* member_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});

                #line 22 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 23 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                }

                #line 26 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 26 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 28 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 30 "src/analyzer/expression/ParseTypeExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 31 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 32 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (argument == 0) {
                        #line 32 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }

                    #line 34 "src/analyzer/expression/ParseTypeExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 36 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 37 "src/analyzer/expression/ParseTypeExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 38 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                }

                #line 42 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 42 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 44 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                    #line 44 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 46 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
                #line 47 "src/analyzer/expression/ParseTypeExpression.pv"
                if (func_return_type == 0) {
                    #line 47 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 49 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                #line 50 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
            } break;
            #line 52 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 52 "src/analyzer/expression/ParseTypeExpression.pv"
                struct EnumVariant* variant = variant_result.enumvariant_value;
                #line 53 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 55 "src/analyzer/expression/ParseTypeExpression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 56 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                        #line 56 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }

                    #line 58 "src/analyzer/expression/ParseTypeExpression.pv"
                    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 59 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Expression* argument = Expression__parse(context, generics);
                        #line 60 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (argument == 0) {
                            #line 60 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }

                        #line 62 "src/analyzer/expression/ParseTypeExpression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                        #line 64 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 65 "src/analyzer/expression/ParseTypeExpression.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                            #line 66 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }
                    }

                    #line 70 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 70 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && variant->names.length > 0) {
                    #line 72 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
                        #line 72 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }

                    #line 74 "src/analyzer/expression/ParseTypeExpression.pv"
                    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                        #line 75 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                        #line 76 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (name == 0) {
                            #line 76 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }

                        #line 78 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Expression* value = 0;
                        #line 79 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                            #line 80 "src/analyzer/expression/ParseTypeExpression.pv"
                            value = Expression__parse(context, generics);
                        } else {
                            #line 82 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Type* return_type = Context__get_value(context, name->value);
                            #line 83 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (return_type == 0) {
                                #line 84 "src/analyzer/expression/ParseTypeExpression.pv"
                                Context__error_token(context, name, "Unable to find variable with this name");
                                #line 85 "src/analyzer/expression/ParseTypeExpression.pv"
                                return 0;
                            }
                            #line 87 "src/analyzer/expression/ParseTypeExpression.pv"
                            value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
                        }

                        #line 90 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (value == 0) {
                            #line 90 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }

                        #line 92 "src/analyzer/expression/ParseTypeExpression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 94 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                            #line 95 "src/analyzer/expression/ParseTypeExpression.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                            #line 96 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }
                    }

                    #line 100 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                        #line 100 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                }

                #line 103 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

                #line 105 "src/analyzer/expression/ParseTypeExpression.pv"
                struct GenericMap* generic_map = Type__get_generic_map(enum_type, context);
                #line 106 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Expression__validate_enum_arguments(context, token, variant, &arguments, generic_map)) {
                    #line 106 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 108 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
            } break;
            #line 110 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                #line 111 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 112 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, enum_type);
            } break;
        }
    }

    #line 127 "src/analyzer/expression/ParseTypeExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 130 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 131 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 132 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 133 "src/analyzer/expression/ParseTypeExpression.pv"
        if (member == 0) {
            #line 133 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 135 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 136 "src/analyzer/expression/ParseTypeExpression.pv"
        if (member_type == 0) {
            #line 136 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 138 "src/analyzer/expression/ParseTypeExpression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 140 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 141 "src/analyzer/expression/ParseTypeExpression.pv"
            switch (member_type->type) {
                #line 142 "src/analyzer/expression/ParseTypeExpression.pv"
                case TYPE__FUNCTION: {
                    #line 143 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                } break;
                #line 145 "src/analyzer/expression/ParseTypeExpression.pv"
                default: {
                    #line 146 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct Expression* struct_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
                    #line 147 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = struct_expr, ._1 = member->value} }, member_type);
                } break;
            }
        } else {
            #line 151 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 151 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 153 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 155 "src/analyzer/expression/ParseTypeExpression.pv"
            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 156 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 157 "src/analyzer/expression/ParseTypeExpression.pv"
                if (argument == 0) {
                    #line 157 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 159 "src/analyzer/expression/ParseTypeExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                #line 161 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 162 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 163 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }
            }

            #line 167 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 167 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 169 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 169 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 171 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 172 "src/analyzer/expression/ParseTypeExpression.pv"
            if (func_return_type == 0) {
                #line 172 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 174 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 175 "src/analyzer/expression/ParseTypeExpression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 178 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 180 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 181 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 182 "src/analyzer/expression/ParseTypeExpression.pv"
            if (name == 0) {
                #line 182 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 184 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = 0;
            #line 185 "src/analyzer/expression/ParseTypeExpression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 186 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 188 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 189 "src/analyzer/expression/ParseTypeExpression.pv"
                if (return_type == 0) {
                    #line 190 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 191 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 194 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 197 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 197 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 199 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 201 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 202 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 203 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 207 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 207 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 209 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (struct_type->type) {
            #line 210 "src/analyzer/expression/ParseTypeExpression.pv"
            case TYPE__STRUCT: {
                #line 210 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Struct* struct_info = struct_type->struct_value._0;
                #line 211 "src/analyzer/expression/ParseTypeExpression.pv"
                uintptr_t field_i = 0;
                #line 212 "src/analyzer/expression/ParseTypeExpression.pv"
                while (field_i < struct_info->fields.length) {
                    #line 213 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct HashMapBucket_str_StructField* bucket = struct_info->fields.data + field_i;
                    #line 214 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (bucket->value.default_token_start != 0) {
                        #line 215 "src/analyzer/expression/ParseTypeExpression.pv"
                        bool already_provided = false;
                        #line 216 "src/analyzer/expression/ParseTypeExpression.pv"
                        uintptr_t arg_i = 0;
                        #line 217 "src/analyzer/expression/ParseTypeExpression.pv"
                        while (arg_i < fields.length) {
                            #line 218 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (str__eq(fields.data[arg_i].name->value, bucket->key)) {
                                #line 219 "src/analyzer/expression/ParseTypeExpression.pv"
                                already_provided = true;
                                #line 220 "src/analyzer/expression/ParseTypeExpression.pv"
                                break;
                            }
                            #line 222 "src/analyzer/expression/ParseTypeExpression.pv"
                            arg_i += 1;
                        }

                        #line 225 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (!already_provided) {
                            #line 226 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Context* struct_context = &struct_info->module->context;
                            #line 227 "src/analyzer/expression/ParseTypeExpression.pv"
                            uintptr_t saved_pos = struct_context->pos;
                            #line 228 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct_context->pos = bucket->value.default_token_start;
                            #line 229 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Expression* default_expr = Expression__parse(struct_context, &struct_info->generics);
                            #line 230 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct_context->pos = saved_pos;

                            #line 232 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (default_expr != 0) {
                                #line 233 "src/analyzer/expression/ParseTypeExpression.pv"
                                Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = bucket->value.name, .value = default_expr });
                            }
                        }
                    }
                    #line 237 "src/analyzer/expression/ParseTypeExpression.pv"
                    field_i += 1;
                }
            } break;
            #line 240 "src/analyzer/expression/ParseTypeExpression.pv"
            default: {
            } break;
        }

        #line 243 "src/analyzer/expression/ParseTypeExpression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 244 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 244 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 246 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 247 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 249 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 251 "src/analyzer/expression/ParseTypeExpression.pv"
        uintptr_t field_index = 0;
        #line 252 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 253 "src/analyzer/expression/ParseTypeExpression.pv"
            struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 254 "src/analyzer/expression/ParseTypeExpression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 255 "src/analyzer/expression/ParseTypeExpression.pv"
            String__append_usize(&name, field_index);
            #line 256 "src/analyzer/expression/ParseTypeExpression.pv"
            struct str name_str = String__as_str(&name);

            #line 258 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token name_token = *Context__current(context);
            #line 259 "src/analyzer/expression/ParseTypeExpression.pv"
            name_token.value = name_str;

            #line 261 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 262 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 262 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 264 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, &name_token),
                .value = value,
            });

            #line 269 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 270 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 271 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 274 "src/analyzer/expression/ParseTypeExpression.pv"
            field_index += 1;
        }

        #line 277 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 277 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 279 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 280 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 283 "src/analyzer/expression/ParseTypeExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 286 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 287 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 288 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 290 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 291 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 292 "src/analyzer/expression/ParseTypeExpression.pv"
            if (name == 0) {
                #line 292 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 294 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = 0;
            #line 295 "src/analyzer/expression/ParseTypeExpression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 296 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 298 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 299 "src/analyzer/expression/ParseTypeExpression.pv"
                if (return_type == 0) {
                    #line 300 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 301 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 304 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 307 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 307 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 309 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 311 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 312 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 313 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 317 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 317 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 319 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 319 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 321 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 323 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 325 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 326 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 327 "src/analyzer/expression/ParseTypeExpression.pv"
            if (argument == 0) {
                #line 327 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 329 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

            #line 331 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 332 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 333 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 337 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 337 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 339 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 342 "src/analyzer/expression/ParseTypeExpression.pv"
    return parent;
}

#line 345 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 346 "src/analyzer/expression/ParseTypeExpression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 348 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 349 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* placement = 0;
        #line 350 "src/analyzer/expression/ParseTypeExpression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 351 "src/analyzer/expression/ParseTypeExpression.pv"
            placement = Expression__parse(context, generics);
            #line 352 "src/analyzer/expression/ParseTypeExpression.pv"
            if (placement == 0) {
                #line 352 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
            #line 353 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 353 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 356 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 357 "src/analyzer/expression/ParseTypeExpression.pv"
        if (expression == 0) {
            #line 357 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 359 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 360 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { ._0 = placement, ._1 = expression} } }, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 362 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 363 "src/analyzer/expression/ParseTypeExpression.pv"
        if (expression == 0) {
            #line 363 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 365 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &context->root->type_unknown);
    }

    #line 368 "src/analyzer/expression/ParseTypeExpression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 369 "src/analyzer/expression/ParseTypeExpression.pv"
    return 0;
}

#line 7 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 8 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 8 "src/analyzer/expression/PostfixExpression.pv"
        return false;
    }

    #line 10 "src/analyzer/expression/PostfixExpression.pv"
    switch (inner->return_type.type) {
        #line 11 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 12 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 13 "src/analyzer/expression/PostfixExpression.pv"
        default: {
            #line 14 "src/analyzer/expression/PostfixExpression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 15 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        } break;
    }

    #line 19 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 20 "src/analyzer/expression/PostfixExpression.pv"
    if (member == 0) {
        #line 20 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 22 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 23 "src/analyzer/expression/PostfixExpression.pv"
    if (member_type == 0) {
        #line 23 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 25 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 28 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 29 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 29 "src/analyzer/expression/PostfixExpression.pv"
        return false;
    }

    #line 31 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* member_name = Context__current(context);
    #line 32 "src/analyzer/expression/PostfixExpression.pv"
    if (member_name == 0) {
        #line 32 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 34 "src/analyzer/expression/PostfixExpression.pv"
    if (member_name->type != TOKEN_TYPE__NUMBER && member_name->type != TOKEN_TYPE__IDENTIFIER) {
        #line 35 "src/analyzer/expression/PostfixExpression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 38 "src/analyzer/expression/PostfixExpression.pv"
    Context__next_token(context);

    #line 40 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 41 "src/analyzer/expression/PostfixExpression.pv"
    if (member_type == 0) {
        #line 41 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 43 "src/analyzer/expression/PostfixExpression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 44 "src/analyzer/expression/PostfixExpression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };
    #line 45 "src/analyzer/expression/PostfixExpression.pv"
    struct Function* func_info = 0;

    #line 47 "src/analyzer/expression/PostfixExpression.pv"
    bool is_function = false;
    #line 48 "src/analyzer/expression/PostfixExpression.pv"
    switch (member_type->type) {
        #line 49 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__FUNCTION: {
            #line 49 "src/analyzer/expression/PostfixExpression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 50 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
            #line 51 "src/analyzer/expression/PostfixExpression.pv"
            func_info = func_info2;
        } break;
        #line 53 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__FUNCTION_C: {
            #line 53 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
        } break;
        #line 54 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__UNKNOWN_C: {
            #line 54 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
        } break;
        #line 55 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 58 "src/analyzer/expression/PostfixExpression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 59 "src/analyzer/expression/PostfixExpression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 62 "src/analyzer/expression/PostfixExpression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 63 "src/analyzer/expression/PostfixExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 63 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 65 "src/analyzer/expression/PostfixExpression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 67 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info != 0 && func_info->parameters.length > 0 && str__eq(func_info->parameters.data[0].name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 68 "src/analyzer/expression/PostfixExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = inner });
        }

        #line 71 "src/analyzer/expression/PostfixExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 72 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 73 "src/analyzer/expression/PostfixExpression.pv"
            if (argument == 0) {
                #line 73 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            }
            #line 74 "src/analyzer/expression/PostfixExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

            #line 76 "src/analyzer/expression/PostfixExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 77 "src/analyzer/expression/PostfixExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 78 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            }
        }

        #line 82 "src/analyzer/expression/PostfixExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 82 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 84 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info != 0 && func_info->generics.array.length > 0) {
            #line 85 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 86 "src/analyzer/expression/PostfixExpression.pv"
            member_type = Root__make_type_usage(context->root, member_type, &func_generics->array);
        }

        #line 89 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info != 0 && (func_info->type == FUNCTION_TYPE__BUILTIN || func_info->type == FUNCTION_TYPE__METHOD_CPP)) {
            #line 90 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 91 "src/analyzer/expression/PostfixExpression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 93 "src/analyzer/expression/PostfixExpression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 96 "src/analyzer/expression/PostfixExpression.pv"
        if (generic_map != 0) {
            #line 97 "src/analyzer/expression/PostfixExpression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }

        #line 100 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
    }
}

#line 104 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 105 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
        #line 105 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 107 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 108 "src/analyzer/expression/PostfixExpression.pv"
    if (index_expr == 0) {
        #line 108 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 110 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]")) {
        #line 110 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 112 "src/analyzer/expression/PostfixExpression.pv"
    switch (index_expr->data.type) {
        #line 113 "src/analyzer/expression/PostfixExpression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 113 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 113 "src/analyzer/expression/PostfixExpression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 114 "src/analyzer/expression/PostfixExpression.pv"
            switch (target->return_type.type) {
                #line 115 "src/analyzer/expression/PostfixExpression.pv"
                case TYPE__ENUM: {
                    #line 115 "src/analyzer/expression/PostfixExpression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 116 "src/analyzer/expression/PostfixExpression.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 117 "src/analyzer/expression/PostfixExpression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        }});

                        #line 123 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 124 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 126 "src/analyzer/expression/PostfixExpression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 128 "src/analyzer/expression/PostfixExpression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, index_expr->token);
                        #line 129 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 130 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 132 "src/analyzer/expression/PostfixExpression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, argument_name_data);
                        #line 133 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 135 "src/analyzer/expression/PostfixExpression.pv"
                        if (Expression__is_zero(start)) {
                            #line 136 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 137 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 139 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 144 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 150 "src/analyzer/expression/PostfixExpression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }});
                        #line 151 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 152 "src/analyzer/expression/PostfixExpression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 155 "src/analyzer/expression/PostfixExpression.pv"
                default: {
                } break;
            }
        } break;
        #line 158 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 161 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 162 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* element_type = 0;

    #line 164 "src/analyzer/expression/PostfixExpression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 165 "src/analyzer/expression/PostfixExpression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 166 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__SEQUENCE: {
                #line 166 "src/analyzer/expression/PostfixExpression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 167 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &sequence->element;
            } break;
            #line 169 "src/analyzer/expression/PostfixExpression.pv"
            default: {
            } break;
        }
    } else {
        #line 172 "src/analyzer/expression/PostfixExpression.pv"
        switch (inner_return_type->type) {
            #line 173 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__INDIRECT: {
                #line 173 "src/analyzer/expression/PostfixExpression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 174 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &indirect->to;
            } break;
            #line 176 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__SEQUENCE: {
                #line 176 "src/analyzer/expression/PostfixExpression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 177 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &sequence->element;
            } break;
            #line 179 "src/analyzer/expression/PostfixExpression.pv"
            default: {
            } break;
        }
    }

    #line 183 "src/analyzer/expression/PostfixExpression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 184 "src/analyzer/expression/PostfixExpression.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(context->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "", .length = strlen("") }, .generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 } }});
        #line 185 "src/analyzer/expression/PostfixExpression.pv"
        element_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c }}, context->allocator);
    }

    #line 188 "src/analyzer/expression/PostfixExpression.pv"
    if (element_type == 0) {
        #line 189 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_token(context, index_expr->token, "Type is not indexable");
        #line 190 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 193 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 196 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 197 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* token = Context__current(context);

    #line 199 "src/analyzer/expression/PostfixExpression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 200 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 202 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 204 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_index_expression(context, inner, generics);
    } else if (Type__is_function(Type__resolve_typedef_function(&inner->return_type)) && (Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, "("))) {
        #line 206 "src/analyzer/expression/PostfixExpression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 207 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION: {
                #line 207 "src/analyzer/expression/PostfixExpression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 208 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };

                #line 210 "src/analyzer/expression/PostfixExpression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                    #line 211 "src/analyzer/expression/PostfixExpression.pv"
                    parsed_generics = Context__parse_generics(context, generics);
                }

                #line 214 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 214 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 216 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 218 "src/analyzer/expression/PostfixExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 219 "src/analyzer/expression/PostfixExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 220 "src/analyzer/expression/PostfixExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 222 "src/analyzer/expression/PostfixExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 223 "src/analyzer/expression/PostfixExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 224 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                }

                #line 228 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 228 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 230 "src/analyzer/expression/PostfixExpression.pv"
                if (func_info->generics.array.length > 0) {
                    #line 231 "src/analyzer/expression/PostfixExpression.pv"
                    struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                    #line 232 "src/analyzer/expression/PostfixExpression.pv"
                    inner->return_type = *Root__make_type_usage(context->root, &inner->return_type, &func_generics->array);

                    #line 234 "src/analyzer/expression/PostfixExpression.pv"
                    switch (inner->data.type) {
                        #line 235 "src/analyzer/expression/PostfixExpression.pv"
                        case EXPRESSION_DATA__TYPE: {
                            #line 235 "src/analyzer/expression/PostfixExpression.pv"
                            struct Type** type = &inner->data.type_value;
                            #line 236 "src/analyzer/expression/PostfixExpression.pv"
                            *type = &inner->return_type;
                        } break;
                        #line 238 "src/analyzer/expression/PostfixExpression.pv"
                        default: {
                        } break;
                    }
                }

                #line 242 "src/analyzer/expression/PostfixExpression.pv"
                if (!Expression__validate_arguments(context, token, &inner->return_type, &arguments, 0, false)) {
                    #line 242 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 244 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 246 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION_C: {
                #line 246 "src/analyzer/expression/PostfixExpression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 247 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 247 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 249 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 251 "src/analyzer/expression/PostfixExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 252 "src/analyzer/expression/PostfixExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 253 "src/analyzer/expression/PostfixExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 255 "src/analyzer/expression/PostfixExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 256 "src/analyzer/expression/PostfixExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 257 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                }

                #line 261 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 261 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 263 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 265 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__CLASS_CPP: {
                #line 266 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__parse_class(context, token, inner, generics);
            } break;
            #line 268 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__UNKNOWN_C: {
                #line 269 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 269 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 271 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 273 "src/analyzer/expression/PostfixExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 274 "src/analyzer/expression/PostfixExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 275 "src/analyzer/expression/PostfixExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 277 "src/analyzer/expression/PostfixExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 278 "src/analyzer/expression/PostfixExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 279 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                }

                #line 283 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 283 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 285 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &context->root->type_unknown);
            } break;
            #line 287 "src/analyzer/expression/PostfixExpression.pv"
            default: {
                #line 288 "src/analyzer/expression/PostfixExpression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 289 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            } break;
        }
    }

    #line 294 "src/analyzer/expression/PostfixExpression.pv"
    return inner;
}

#line 297 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 298 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* result = inner;
    #line 299 "src/analyzer/expression/PostfixExpression.pv"
    while (true) {
        #line 300 "src/analyzer/expression/PostfixExpression.pv"
        struct Expression* next = Expression__parse_postfix(context, result, generics);
        #line 301 "src/analyzer/expression/PostfixExpression.pv"
        if (next == result) {
            #line 301 "src/analyzer/expression/PostfixExpression.pv"
            break;
        }
        #line 302 "src/analyzer/expression/PostfixExpression.pv"
        if (next == 0) {
            #line 302 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 304 "src/analyzer/expression/PostfixExpression.pv"
        struct Token* expanded_token = ArenaAllocator__store_Token(context->allocator, next->token);
        #line 305 "src/analyzer/expression/PostfixExpression.pv"
        expanded_token->start_line = result->token->start_line;
        #line 306 "src/analyzer/expression/PostfixExpression.pv"
        expanded_token->start_column = result->token->start_column;
        #line 307 "src/analyzer/expression/PostfixExpression.pv"
        next->token = expanded_token;

        #line 309 "src/analyzer/expression/PostfixExpression.pv"
        result = next;
    }
    #line 311 "src/analyzer/expression/PostfixExpression.pv"
    return result;
}

#line 6 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics) {
    #line 7 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* result = lhs;

    #line 9 "src/analyzer/expression/BinaryExpression.pv"
    while (true) {
        #line 10 "src/analyzer/expression/BinaryExpression.pv"
        struct Token* token = Context__current(context);
        #line 11 "src/analyzer/expression/BinaryExpression.pv"
        uintptr_t prec = Expression__get_precedence(token);
        #line 12 "src/analyzer/expression/BinaryExpression.pv"
        if (prec < min_prec) {
            #line 12 "src/analyzer/expression/BinaryExpression.pv"
            break;
        }

        #line 14 "src/analyzer/expression/BinaryExpression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 15 "src/analyzer/expression/BinaryExpression.pv"
        if (operator == 0) {
            #line 15 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 17 "src/analyzer/expression/BinaryExpression.pv"
        struct Expression* rhs = Expression__parse_primary(context, generics);
        #line 18 "src/analyzer/expression/BinaryExpression.pv"
        if (rhs == 0) {
            #line 18 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 20 "src/analyzer/expression/BinaryExpression.pv"
        struct Expression* rhs_final = Expression__parse_binary(context, rhs, prec + 1, generics);
        #line 21 "src/analyzer/expression/BinaryExpression.pv"
        if (rhs_final == 0) {
            #line 21 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 23 "src/analyzer/expression/BinaryExpression.pv"
        bool is_arithmetic = str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__eq(operator->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__eq(operator->value, (struct str){ .ptr = "-", .length = strlen("-") }) || str__eq(operator->value, (struct str){ .ptr = "/", .length = strlen("/") });

        #line 27 "src/analyzer/expression/BinaryExpression.pv"
        if (is_arithmetic) {
            #line 28 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* trait_result = Expression__find_operator_trait_call(context, token, result, &result->return_type, operator->value, rhs_final);
            #line 29 "src/analyzer/expression/BinaryExpression.pv"
            if (trait_result != 0) {
                #line 30 "src/analyzer/expression/BinaryExpression.pv"
                result = trait_result;
                #line 31 "src/analyzer/expression/BinaryExpression.pv"
                continue;
            }
        }

        #line 35 "src/analyzer/expression/BinaryExpression.pv"
        bool is_comparison = str__eq(operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__eq(operator->value, (struct str){ .ptr = "!=", .length = strlen("!=") }) || str__eq(operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__eq(operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") }) || str__eq(operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__eq(operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });

        #line 41 "src/analyzer/expression/BinaryExpression.pv"
        struct Type* return_type = 0;
        #line 42 "src/analyzer/expression/BinaryExpression.pv"
        if (is_comparison) {
            #line 43 "src/analyzer/expression/BinaryExpression.pv"
            if (!str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) && !str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
                #line 44 "src/analyzer/expression/BinaryExpression.pv"
                if (!Expression__validate_type(result, context, &rhs_final->return_type, false)) {
                    #line 44 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }
            }

            #line 47 "src/analyzer/expression/BinaryExpression.pv"
            return_type = &context->root->type_bool;
        } else {
            #line 49 "src/analyzer/expression/BinaryExpression.pv"
            return_type = &result->return_type;
        }

        #line 52 "src/analyzer/expression/BinaryExpression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = result, ._1 = operator->value, ._2 = rhs_final} }, return_type);
    }

    #line 55 "src/analyzer/expression/BinaryExpression.pv"
    return result;
}

#line 58 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_operator_trait_call(struct Context* context, struct Token* token, struct Expression* lhs, struct Type* lhs_type, struct str operator, struct Expression* rhs) {
    #line 59 "src/analyzer/expression/BinaryExpression.pv"
    struct str trait_name = (struct str){ .ptr = "", .length = strlen("") };
    #line 60 "src/analyzer/expression/BinaryExpression.pv"
    struct str func_name = (struct str){ .ptr = "", .length = strlen("") };

    #line 62 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(operator, (struct str){ .ptr = "*", .length = strlen("*") })) {
        #line 62 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Mul", .length = strlen("Mul") };
        #line 62 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "mul", .length = strlen("mul") };
    } else if (str__eq(operator, (struct str){ .ptr = "+", .length = strlen("+") })) {
        #line 63 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Add", .length = strlen("Add") };
        #line 63 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "add", .length = strlen("add") };
    } else if (str__eq(operator, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 64 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Sub", .length = strlen("Sub") };
        #line 64 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "sub", .length = strlen("sub") };
    } else if (str__eq(operator, (struct str){ .ptr = "/", .length = strlen("/") })) {
        #line 65 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Div", .length = strlen("Div") };
        #line 65 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "div", .length = strlen("div") };
    } else {
        #line 66 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 68 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(lhs_type) || Type__is_unknown(&rhs->return_type)) {
        #line 68 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 70 "src/analyzer/expression/BinaryExpression.pv"
    switch (lhs_type->type) {
        #line 71 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__SELF: {
            #line 72 "src/analyzer/expression/BinaryExpression.pv"
            if (context->type_self != 0) {
                #line 73 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__find_operator_trait_call(context, token, lhs, context->type_self, operator, rhs);
            }
        } break;
        #line 76 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__INDIRECT: {
            #line 76 "src/analyzer/expression/BinaryExpression.pv"
            struct Indirect* indirect = lhs_type->indirect_value;
            #line 77 "src/analyzer/expression/BinaryExpression.pv"
            return Expression__find_operator_trait_call(context, token, lhs, &indirect->to, operator, rhs);
        } break;
        #line 79 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 79 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = lhs_type->struct_value._0;
            #line 79 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = lhs_type->struct_value._1;
            #line 80 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 80 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 80 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 81 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_info->trait_ == 0) {
                    #line 81 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 82 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__eq(impl_info->trait_->name->value, trait_name)) {
                    #line 82 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 84 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &func_name);
                #line 85 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 85 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 86 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 2) {
                    #line 86 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 88 "src/analyzer/expression/BinaryExpression.pv"
                struct Parameter* other_param = Array_Parameter__get(&func->parameters, 1);
                #line 89 "src/analyzer/expression/BinaryExpression.pv"
                if (!Type__eq(&other_param->type, &rhs->return_type)) {
                    #line 89 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 91 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 92 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 93 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 94 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 95 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 95 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 95 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 95 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 96 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *typedef_type);
                    } }
                    #line 98 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 101 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});

                #line 103 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 104 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = lhs });
                #line 105 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = rhs });

                #line 107 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 110 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__PRIMITIVE: {
            #line 110 "src/analyzer/expression/BinaryExpression.pv"
            struct Primitive* primitive_info = lhs_type->primitive_value;
            #line 111 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 111 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 111 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 112 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_info->trait_ == 0) {
                    #line 112 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 113 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__eq(impl_info->trait_->name->value, trait_name)) {
                    #line 113 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 115 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &func_name);
                #line 116 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 116 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 117 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 2) {
                    #line 117 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 119 "src/analyzer/expression/BinaryExpression.pv"
                struct Parameter* other_param = Array_Parameter__get(&func->parameters, 1);
                #line 120 "src/analyzer/expression/BinaryExpression.pv"
                if (Type__is_self(&rhs->return_type)) {
                    #line 120 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 121 "src/analyzer/expression/BinaryExpression.pv"
                if (!Type__eq(&other_param->type, &rhs->return_type)) {
                    #line 121 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 123 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = Type__get_generic_map(&impl_info->trait_type, context);

                #line 125 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});

                #line 127 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 128 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = lhs });
                #line 129 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = rhs });

                #line 131 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 134 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 137 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 140 "src/analyzer/expression/BinaryExpression.pv"
uintptr_t Expression__get_precedence(struct Token* token) {
    #line 141 "src/analyzer/expression/BinaryExpression.pv"
    if (token->type != TOKEN_TYPE__SYMBOL) {
        #line 141 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 143 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "||", .length = strlen("||") })) {
        #line 143 "src/analyzer/expression/BinaryExpression.pv"
        return 1;
    }
    #line 144 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
        #line 144 "src/analyzer/expression/BinaryExpression.pv"
        return 2;
    }
    #line 145 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "|", .length = strlen("|") })) {
        #line 145 "src/analyzer/expression/BinaryExpression.pv"
        return 3;
    }
    #line 146 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "^", .length = strlen("^") })) {
        #line 146 "src/analyzer/expression/BinaryExpression.pv"
        return 4;
    }
    #line 147 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
        #line 147 "src/analyzer/expression/BinaryExpression.pv"
        return 5;
    }
    #line 148 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__eq(token->value, (struct str){ .ptr = "!=", .length = strlen("!=") })) {
        #line 148 "src/analyzer/expression/BinaryExpression.pv"
        return 6;
    }
    #line 149 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__eq(token->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__eq(token->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__eq(token->value, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 149 "src/analyzer/expression/BinaryExpression.pv"
        return 7;
    }
    #line 150 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "<<", .length = strlen("<<") }) || str__eq(token->value, (struct str){ .ptr = ">>", .length = strlen(">>") })) {
        #line 150 "src/analyzer/expression/BinaryExpression.pv"
        return 8;
    }
    #line 151 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__eq(token->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 151 "src/analyzer/expression/BinaryExpression.pv"
        return 9;
    }
    #line 152 "src/analyzer/expression/BinaryExpression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__eq(token->value, (struct str){ .ptr = "/", .length = strlen("/") }) || str__eq(token->value, (struct str){ .ptr = "%", .length = strlen("%") })) {
        #line 152 "src/analyzer/expression/BinaryExpression.pv"
        return 10;
    }

    #line 154 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}
