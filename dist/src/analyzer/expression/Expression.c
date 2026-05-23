#include <string.h>
#include <stdint.h>

#include <stdlib.h>

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
#include <analyzer/types/Enum.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/Naming.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <analyzer/ImplConst.h>
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
#include <std/Array_NullNarrowing.h>
#include <analyzer/expression/NullNarrowing.h>
#include <std/Iter_ref_NullNarrowing.h>
#include <analyzer/expression/Expression.h>

#include <analyzer/expression/Expression.h>

#line 15 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type) {
    #line 16 "src/analyzer/expression/Expression.pv"
    return ArenaAllocator__store_Expression(allocator, (struct Expression[]){(struct Expression) {
        .token = token,
        .data = data,
        .return_type = *return_type,
    }});
}

#line 23 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node) {
    #line 24 "src/analyzer/expression/Expression.pv"
    struct Expression* result = ArenaAllocator__store_Expression(context->allocator, &node);

    #line 26 "src/analyzer/expression/Expression.pv"
    Context__next_token(context);

    #line 28 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 31 "src/analyzer/expression/Expression.pv"
struct str Expression__number_primitive(struct str value) {
    #line 32 "src/analyzer/expression/Expression.pv"
    if (str__ends_with(value, "f") || str__ends_with(value, "F")) {
        #line 33 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f32", .length = strlen("f32") };
    } else if (str__ends_with(value, "u") || str__ends_with(value, "U")) {
        #line 35 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "u32", .length = strlen("u32") };
    } else if (str__contains(value, ".")) {
        #line 37 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f64", .length = strlen("f64") };
    }
    #line 39 "src/analyzer/expression/Expression.pv"
    return (struct str){ .ptr = "i32", .length = strlen("i32") };
}

#line 42 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics) {
    #line 43 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 44 "src/analyzer/expression/Expression.pv"
    if (token == 0) {
        #line 45 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Unexpected end of input");
        #line 46 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 49 "src/analyzer/expression/Expression.pv"
    enum TokenType token_type = token->type;
    #line 50 "src/analyzer/expression/Expression.pv"
    struct Expression* result = 0;

    #line 52 "src/analyzer/expression/Expression.pv"
    switch (token_type) {
        #line 53 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 54 "src/analyzer/expression/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 56 "src/analyzer/expression/Expression.pv"
            if (context->module->mode_cpp && (str__Eq_str__eq(&token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 57 "src/analyzer/expression/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 59 "src/analyzer/expression/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 60 "src/analyzer/expression/Expression.pv"
                if (type != 0) {
                    #line 61 "src/analyzer/expression/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 62 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM: {
                            #line 62 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 63 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 63 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 64 "src/analyzer/expression/Expression.pv"
                        case TYPE__SELF: {
                            #line 64 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 65 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 65 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 66 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 66 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 67 "src/analyzer/expression/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 67 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 68 "src/analyzer/expression/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 68 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 69 "src/analyzer/expression/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 69 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 70 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 70 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 73 "src/analyzer/expression/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 74 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                        .data = (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = (struct str) { .ptr = 0, .length = 0 } },
                    });

                    #line 80 "src/analyzer/expression/Expression.pv"
                    if (result == 0) {
                        #line 80 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                    #line 81 "src/analyzer/expression/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 83 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 84 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            } else {
                #line 87 "src/analyzer/expression/Expression.pv"
                switch (return_type->type) {
                    #line 88 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 88 "src/analyzer/expression/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 89 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 90 "src/analyzer/expression/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 91 "src/analyzer/expression/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };

                        #line 93 "src/analyzer/expression/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 94 "src/analyzer/expression/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 97 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 97 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 99 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 101 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 102 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 103 "src/analyzer/expression/Expression.pv"
                            if (argument == 0) {
                                #line 103 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                            #line 104 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                            #line 106 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 107 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 108 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 112 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 112 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 114 "src/analyzer/expression/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 115 "src/analyzer/expression/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 116 "src/analyzer/expression/Expression.pv"
                            func_type = Root__make_type_usage(context->root, func_type, &func_generics->array);
                        }

                        #line 119 "src/analyzer/expression/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 119 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 121 "src/analyzer/expression/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 122 "src/analyzer/expression/Expression.pv"
                        switch (func_type->type) {
                            #line 123 "src/analyzer/expression/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 123 "src/analyzer/expression/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 124 "src/analyzer/expression/Expression.pv"
                                switch (func_info->type) {
                                    #line 125 "src/analyzer/expression/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 126 "src/analyzer/expression/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} }});
                                    } break;
                                    #line 128 "src/analyzer/expression/Expression.pv"
                                    default: {
                                        #line 129 "src/analyzer/expression/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 133 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 136 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 137 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 139 "src/analyzer/expression/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 140 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 141 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 143 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 144 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 145 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 147 "src/analyzer/expression/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 148 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 149 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 151 "src/analyzer/expression/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 152 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 153 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 155 "src/analyzer/expression/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 156 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 157 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 159 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM: {
                        #line 160 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 161 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 163 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 164 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 165 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 167 "src/analyzer/expression/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 168 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 169 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 171 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 172 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 173 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 175 "src/analyzer/expression/Expression.pv"
                    case TYPE__SELF: {
                        #line 176 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 177 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 179 "src/analyzer/expression/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 180 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 181 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 183 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 184 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 185 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 187 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 188 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 189 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 191 "src/analyzer/expression/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 192 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 193 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 195 "src/analyzer/expression/Expression.pv"
                    case TYPE__GLOBAL: {
                        #line 196 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 197 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 199 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 200 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 201 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 203 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 203 "src/analyzer/expression/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 204 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 205 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 205 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 207 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 209 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 210 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 211 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                            #line 213 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 214 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 215 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 219 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 219 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 221 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 223 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, &func_info->return_type);
                    } break;
                    #line 225 "src/analyzer/expression/Expression.pv"
                    default: {
                        #line 226 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 231 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 232 "src/analyzer/expression/Expression.pv"
            struct Type return_type = str__starts_with(token->value, "'") ? context->type_char : (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char };

            #line 234 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = return_type,
            });
        } break;
        #line 240 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 241 "src/analyzer/expression/Expression.pv"
            struct str primitive = Expression__number_primitive(token->value);
            #line 242 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 248 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 249 "src/analyzer/expression/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 250 "src/analyzer/expression/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 251 "src/analyzer/expression/Expression.pv"
                if (operator == 0) {
                    #line 251 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 253 "src/analyzer/expression/Expression.pv"
                if (str__Eq_str__eq(&operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 254 "src/analyzer/expression/Expression.pv"
                    context->pos -= 1;
                    #line 255 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 256 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 258 "src/analyzer/expression/Expression.pv"
                    struct Expression* child = Expression__parse_primary(context, generics);
                    #line 259 "src/analyzer/expression/Expression.pv"
                    if (child == 0) {
                        #line 259 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 261 "src/analyzer/expression/Expression.pv"
                    if (str__Eq_str__eq(&operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 262 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 263 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 263 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 264 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) }});
                                #line 265 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 267 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 268 "src/analyzer/expression/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 269 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__Eq_str__eq(&operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 273 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 274 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 274 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 275 "src/analyzer/expression/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 276 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect }});
                                #line 277 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 279 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 279 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 282 "src/analyzer/expression/Expression.pv"
                        if (str__Eq_str__eq(&operator->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
                            #line 283 "src/analyzer/expression/Expression.pv"
                            struct Expression* trait_result = Expression__find_unary_trait_call(context, operator, child);
                            #line 284 "src/analyzer/expression/Expression.pv"
                            if (trait_result != 0) {
                                #line 285 "src/analyzer/expression/Expression.pv"
                                result = trait_result;
                            } else {
                                #line 287 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                            }
                        } else {
                            #line 290 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                        }
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 295 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 295 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 297 "src/analyzer/expression/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 298 "src/analyzer/expression/Expression.pv"
                if (expr == 0) {
                    #line 298 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 300 "src/analyzer/expression/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 301 "src/analyzer/expression/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 303 "src/analyzer/expression/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, expr->token);
                    #line 304 "src/analyzer/expression/Expression.pv"
                    if (name == 0) {
                        #line 305 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Failed to allocate token for tuple argument name");
                        #line 306 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 309 "src/analyzer/expression/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 311 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 313 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 314 "src/analyzer/expression/Expression.pv"
                        struct String name_string = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 315 "src/analyzer/expression/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 316 "src/analyzer/expression/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 318 "src/analyzer/expression/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, Context__current(context));
                        #line 319 "src/analyzer/expression/Expression.pv"
                        if (name == 0) {
                            #line 320 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Failed to allocate token for tuple argument name");
                            #line 321 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                        #line 323 "src/analyzer/expression/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 325 "src/analyzer/expression/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 326 "src/analyzer/expression/Expression.pv"
                        if (value == 0) {
                            #line 326 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 328 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 330 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 331 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 332 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 336 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple[]){(struct Tuple) { .elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) }});
                    #line 337 "src/analyzer/expression/Expression.pv"
                    if (tuple == 0) {
                        #line 338 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Failed to allocate tuple type");
                        #line 339 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                    #line 341 "src/analyzer/expression/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 342 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 342 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 342 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 342 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 343 "src/analyzer/expression/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 346 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }}), arguments, 0);
                } else {
                    #line 348 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 348 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 350 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 353 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
                    #line 353 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 355 "src/analyzer/expression/Expression.pv"
                struct Type* element_type = 0;
                #line 356 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 358 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 359 "src/analyzer/expression/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 360 "src/analyzer/expression/Expression.pv"
                    if (element == 0) {
                        #line 360 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 362 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .name = 0, .value = element });

                    #line 364 "src/analyzer/expression/Expression.pv"
                    if (element_type == 0) {
                        #line 365 "src/analyzer/expression/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 368 "src/analyzer/expression/Expression.pv"
                    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
                        #line 369 "src/analyzer/expression/Expression.pv"
                        struct Token* count_token = Context__expect(context, TOKEN_TYPE__NUMBER);
                        #line 370 "src/analyzer/expression/Expression.pv"
                        if (count_token == 0) {
                            #line 370 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                        #line 371 "src/analyzer/expression/Expression.pv"
                        uintptr_t count = strtoul(count_token->value.ptr, 0, 10);
                        #line 372 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = 1;
                        #line 373 "src/analyzer/expression/Expression.pv"
                        while (i < count) {
                            #line 374 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .name = 0, .value = element });
                            #line 375 "src/analyzer/expression/Expression.pv"
                            i += 1;
                        }
                        #line 377 "src/analyzer/expression/Expression.pv"
                        break;
                    }

                    #line 380 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 381 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 382 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 386 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 388 "src/analyzer/expression/Expression.pv"
                if (element_type == 0) {
                    #line 388 "src/analyzer/expression/Expression.pv"
                    element_type = &context->root->type_void;
                }
                #line 389 "src/analyzer/expression/Expression.pv"
                struct String length_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 390 "src/analyzer/expression/Expression.pv"
                String__append_usize(&length_str, elements.length);
                #line 391 "src/analyzer/expression/Expression.pv"
                struct Token length_token_val = (struct Token) { .type = TOKEN_TYPE__NUMBER, .value = String__as_str(&length_str), .start_line = token->start_line, .start_column = token->start_column, .end_line = token->end_line, .end_column = token->end_column };
                #line 392 "src/analyzer/expression/Expression.pv"
                struct Token* length_token = ArenaAllocator__store_Token(context->allocator, &length_token_val);
                #line 393 "src/analyzer/expression/Expression.pv"
                struct Type length_primitive = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "usize", .length = strlen("usize") }) };
                #line 394 "src/analyzer/expression/Expression.pv"
                struct Expression* length_expression = Expression__make(context->allocator, length_token, (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = String__as_str(&length_str) }, &length_primitive);
                #line 395 "src/analyzer/expression/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = length_expression }, .element = *element_type, .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
                #line 396 "src/analyzer/expression/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence }});
                #line 397 "src/analyzer/expression/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 399 "src/analyzer/expression/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 401 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 404 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 405 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 406 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "bool", .length = strlen("bool") }) },
                });
            } else if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "null", .length = strlen("null") })) {
                #line 412 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__NULL_LITERAL },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "i32", .length = strlen("i32") }) },
                });
            } else if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "if", .length = strlen("if") })) {
                #line 418 "src/analyzer/expression/Expression.pv"
                result = Expression__parse_if_expression(context, generics);
            } else {
                #line 420 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 423 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 424 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 428 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 428 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 430 "src/analyzer/expression/Expression.pv"
    return Expression__parse_postfix_chain(context, result, generics);
}

#line 433 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 434 "src/analyzer/expression/Expression.pv"
    struct Expression* result = Expression__parse_primary(context, generics);
    #line 435 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 435 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 437 "src/analyzer/expression/Expression.pv"
    result = Expression__parse_binary(context, result, 1, generics);
    #line 438 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 438 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 440 "src/analyzer/expression/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 441 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 443 "src/analyzer/expression/Expression.pv"
        struct Expression* range_start = result;
        #line 444 "src/analyzer/expression/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 445 "src/analyzer/expression/Expression.pv"
        if (range_end == 0) {
            #line 445 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 447 "src/analyzer/expression/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, (struct Array_Type[]){(struct Array_Type) { .data = &range_end->return_type, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .capacity = 0 }});
        #line 448 "src/analyzer/expression/Expression.pv"
        if (enum_type == 0) {
            #line 449 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 450 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 453 "src/analyzer/expression/Expression.pv"
        struct Token variant_name = *token;
        #line 454 "src/analyzer/expression/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 455 "src/analyzer/expression/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 457 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 458 "src/analyzer/expression/Expression.pv"
        struct EnumVariant* variant = 0;
        #line 459 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 460 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 460 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* enum_variant = variant_result.enumvariant_value;
                #line 460 "src/analyzer/expression/Expression.pv"
                variant = enum_variant;
            } break;
            #line 461 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
        #line 463 "src/analyzer/expression/Expression.pv"
        if (variant == 0) {
            #line 464 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range StartEnd enum variant");
            #line 465 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 468 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 469 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = range_start });
        #line 470 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = range_end });

        #line 472 "src/analyzer/expression/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 474 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 477 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 480 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 481 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 482 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 482 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 482 "src/analyzer/expression/Expression.pv"
            return str__Eq_str__eq(&value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 483 "src/analyzer/expression/Expression.pv"
        default: {
            #line 483 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 487 "src/analyzer/expression/Expression.pv"
bool Expression__is_const_expression(struct Expression* self, struct Context* context) {
    #line 488 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 489 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 489 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 490 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 490 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 491 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(inner, context);
        } break;
        #line 493 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 493 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.unaryexpression_value._0;
            #line 493 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 494 "src/analyzer/expression/Expression.pv"
            if (!str__Eq_str__eq(&op, (struct str){ .ptr = "-", .length = strlen("-") }) && !str__Eq_str__eq(&op, (struct str){ .ptr = "+", .length = strlen("+") })) {
                #line 494 "src/analyzer/expression/Expression.pv"
                return false;
            }
            #line 495 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(inner, context);
        } break;
        #line 497 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 497 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 497 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.binaryexpression_value._1;
            #line 497 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 498 "src/analyzer/expression/Expression.pv"
            if (!str__Eq_str__eq(&op, (struct str){ .ptr = "+", .length = strlen("+") }) && !str__Eq_str__eq(&op, (struct str){ .ptr = "-", .length = strlen("-") }) && !str__Eq_str__eq(&op, (struct str){ .ptr = "*", .length = strlen("*") }) && !str__Eq_str__eq(&op, (struct str){ .ptr = "/", .length = strlen("/") }) && !str__Eq_str__eq(&op, (struct str){ .ptr = "%", .length = strlen("%") })) {
                #line 498 "src/analyzer/expression/Expression.pv"
                return false;
            }
            #line 499 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(lhs, context) && Expression__is_const_expression(rhs, context);
        } break;
        #line 501 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 501 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 502 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 502 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 502 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument arguments = self->data.invoke_value._1;
            #line 503 "src/analyzer/expression/Expression.pv"
            if (arguments.length != 0) {
                #line 503 "src/analyzer/expression/Expression.pv"
                return false;
            }
            #line 504 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(target, context);
        } break;
        #line 506 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 507 "src/analyzer/expression/Expression.pv"
            switch (self->return_type.type) {
                #line 508 "src/analyzer/expression/Expression.pv"
                case TYPE__ENUM_C: {
                    #line 508 "src/analyzer/expression/Expression.pv"
                    return true;
                } break;
                #line 509 "src/analyzer/expression/Expression.pv"
                default: {
                    #line 509 "src/analyzer/expression/Expression.pv"
                    return false;
                } break;
            }
        } break;
        #line 512 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 512 "src/analyzer/expression/Expression.pv"
            struct str name = self->data.variable_value;
            #line 513 "src/analyzer/expression/Expression.pv"
            switch (self->return_type.type) {
                #line 514 "src/analyzer/expression/Expression.pv"
                case TYPE__ENUM_C: {
                    #line 514 "src/analyzer/expression/Expression.pv"
                    return true;
                } break;
                #line 515 "src/analyzer/expression/Expression.pv"
                case TYPE__UNKNOWN_C: {
                    #line 516 "src/analyzer/expression/Expression.pv"
                    return Module__find_macro_value(context->module, name) != 0;
                } break;
                #line 518 "src/analyzer/expression/Expression.pv"
                default: {
                    #line 518 "src/analyzer/expression/Expression.pv"
                    return false;
                } break;
            }
        } break;
        #line 521 "src/analyzer/expression/Expression.pv"
        default: {
            #line 521 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 525 "src/analyzer/expression/Expression.pv"
void Expression__append_ident_name(struct Expression* self, struct String* result) {
    #line 526 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 527 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 527 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 528 "src/analyzer/expression/Expression.pv"
            uintptr_t i = 0;
            #line 529 "src/analyzer/expression/Expression.pv"
            while (i < value.length) {
                #line 530 "src/analyzer/expression/Expression.pv"
                char c = value.ptr[i];
                #line 531 "src/analyzer/expression/Expression.pv"
                if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    #line 532 "src/analyzer/expression/Expression.pv"
                    String__append_char(result, c);
                } else {
                    #line 534 "src/analyzer/expression/Expression.pv"
                    String__append_char(result, '_');
                }
                #line 536 "src/analyzer/expression/Expression.pv"
                i += 1;
            }
        } break;
        #line 539 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 539 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 540 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(inner, result);
        } break;
        #line 542 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 542 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.unaryexpression_value._0;
            #line 542 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 543 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(&op, (struct str){ .ptr = "-", .length = strlen("-") })) {
                #line 543 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "neg_", .length = strlen("neg_") });
            }
            #line 544 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(inner, result);
        } break;
        #line 546 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 546 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 546 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.binaryexpression_value._1;
            #line 546 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 547 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(lhs, result);
            #line 548 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(&op, (struct str){ .ptr = "+", .length = strlen("+") })) {
                #line 548 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_add_", .length = strlen("_add_") });
            } else if (str__Eq_str__eq(&op, (struct str){ .ptr = "-", .length = strlen("-") })) {
                #line 549 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_sub_", .length = strlen("_sub_") });
            } else if (str__Eq_str__eq(&op, (struct str){ .ptr = "*", .length = strlen("*") })) {
                #line 550 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_mul_", .length = strlen("_mul_") });
            } else if (str__Eq_str__eq(&op, (struct str){ .ptr = "/", .length = strlen("/") })) {
                #line 551 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_div_", .length = strlen("_div_") });
            } else if (str__Eq_str__eq(&op, (struct str){ .ptr = "%", .length = strlen("%") })) {
                #line 552 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_mod_", .length = strlen("_mod_") });
            } else {
                #line 553 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_op_", .length = strlen("_op_") });
            }
            #line 554 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(rhs, result);
        } break;
        #line 556 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 556 "src/analyzer/expression/Expression.pv"
            struct EnumVariant* variant = self->data.enumvariant_value;
            #line 557 "src/analyzer/expression/Expression.pv"
            struct Token* name = variant->parent->name;
            #line 558 "src/analyzer/expression/Expression.pv"
            if (name != 0) {
                #line 559 "src/analyzer/expression/Expression.pv"
                String__append(result, name->value);
            } else {
                #line 561 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "unknown_enum", .length = strlen("unknown_enum") });
            }

            #line 564 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 565 "src/analyzer/expression/Expression.pv"
            String__append(result, variant->name->value);
        } break;
        #line 567 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 567 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 568 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(target, result);
        } break;
        #line 570 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 570 "src/analyzer/expression/Expression.pv"
            struct str member_name = self->data.memberstaticexpression_value._1;
            #line 571 "src/analyzer/expression/Expression.pv"
            String__append(result, member_name);
        } break;
        #line 573 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 573 "src/analyzer/expression/Expression.pv"
            struct str name = self->data.variable_value;
            #line 574 "src/analyzer/expression/Expression.pv"
            String__append(result, name);
        } break;
        #line 576 "src/analyzer/expression/Expression.pv"
        default: {
            #line 577 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "expr", .length = strlen("expr") });
        } break;
    }
}

#line 582 "src/analyzer/expression/Expression.pv"
void Expression__append_display_name(struct Expression* self, struct String* result) {
    #line 583 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 584 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 584 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 585 "src/analyzer/expression/Expression.pv"
            String__append(result, value);
        } break;
        #line 587 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 587 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 588 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "(", .length = strlen("(") });
            #line 589 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(inner, result);
            #line 590 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = ")", .length = strlen(")") });
        } break;
        #line 592 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 592 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.unaryexpression_value._0;
            #line 592 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 593 "src/analyzer/expression/Expression.pv"
            String__append(result, op);
            #line 594 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(inner, result);
        } break;
        #line 596 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 596 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 596 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.binaryexpression_value._1;
            #line 596 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 597 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(lhs, result);
            #line 598 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = " ", .length = strlen(" ") });
            #line 599 "src/analyzer/expression/Expression.pv"
            String__append(result, op);
            #line 600 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = " ", .length = strlen(" ") });
            #line 601 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(rhs, result);
        } break;
        #line 603 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 603 "src/analyzer/expression/Expression.pv"
            struct EnumVariant* variant = self->data.enumvariant_value;
            #line 604 "src/analyzer/expression/Expression.pv"
            struct Token* name = variant->parent->name;
            #line 605 "src/analyzer/expression/Expression.pv"
            if (name != 0) {
                #line 606 "src/analyzer/expression/Expression.pv"
                String__append(result, name->value);
            } else {
                #line 608 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "unknown_enum", .length = strlen("unknown_enum") });
            }

            #line 611 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "::", .length = strlen("::") });
            #line 612 "src/analyzer/expression/Expression.pv"
            String__append(result, variant->name->value);
        } break;
        #line 614 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 614 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 615 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(target, result);
        } break;
        #line 617 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 617 "src/analyzer/expression/Expression.pv"
            struct str member_name = self->data.memberstaticexpression_value._1;
            #line 618 "src/analyzer/expression/Expression.pv"
            String__append(result, member_name);
        } break;
        #line 620 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 620 "src/analyzer/expression/Expression.pv"
            struct str name = self->data.variable_value;
            #line 621 "src/analyzer/expression/Expression.pv"
            String__append(result, name);
        } break;
        #line 623 "src/analyzer/expression/Expression.pv"
        default: {
            #line 624 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "expr", .length = strlen("expr") });
        } break;
    }
}

#line 629 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast) {
    #line 630 "src/analyzer/expression/Expression.pv"
    bool success = true;

    #line 632 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 633 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 634 "src/analyzer/expression/Expression.pv"
            switch (Type__resolve_typedef(type)->type) {
                #line 635 "src/analyzer/expression/Expression.pv"
                case TYPE__INDIRECT: {
                    #line 635 "src/analyzer/expression/Expression.pv"
                    struct Indirect* indirect = Type__resolve_typedef(type)->indirect_value;
                    #line 636 "src/analyzer/expression/Expression.pv"
                    switch (indirect->type) {
                        #line 637 "src/analyzer/expression/Expression.pv"
                        case INDIRECT_TYPE__REFERENCE: {
                            #line 638 "src/analyzer/expression/Expression.pv"
                            Context__error_token(context, self->token, "null can only be used with * types, not & types");
                            #line 639 "src/analyzer/expression/Expression.pv"
                            return false;
                        } break;
                        #line 641 "src/analyzer/expression/Expression.pv"
                        case INDIRECT_TYPE__DYNAMIC_DISPATCH: {
                            #line 642 "src/analyzer/expression/Expression.pv"
                            Context__error_token(context, self->token, "null can only be used with * types, not & types");
                            #line 643 "src/analyzer/expression/Expression.pv"
                            return false;
                        } break;
                        #line 645 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 645 "src/analyzer/expression/Expression.pv"
                            return true;
                        } break;
                    }
                } break;
                #line 648 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 651 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 651 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 652 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(&value, (struct str){ .ptr = "0", .length = strlen("0") })) {
                #line 653 "src/analyzer/expression/Expression.pv"
                switch (type->type) {
                    #line 654 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 654 "src/analyzer/expression/Expression.pv"
                        struct Indirect* indirect = type->indirect_value;
                        #line 655 "src/analyzer/expression/Expression.pv"
                        switch (indirect->type) {
                            #line 656 "src/analyzer/expression/Expression.pv"
                            case INDIRECT_TYPE__POINTER: {
                                #line 657 "src/analyzer/expression/Expression.pv"
                                Context__error_token(context, self->token, "use null instead of 0 for pointer types");
                                #line 658 "src/analyzer/expression/Expression.pv"
                                return false;
                            } break;
                            #line 660 "src/analyzer/expression/Expression.pv"
                            case INDIRECT_TYPE__CONST_POINTER: {
                                #line 661 "src/analyzer/expression/Expression.pv"
                                Context__error_token(context, self->token, "use null instead of 0 for pointer types");
                                #line 662 "src/analyzer/expression/Expression.pv"
                                return false;
                            } break;
                            #line 664 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 667 "src/analyzer/expression/Expression.pv"
                    default: {
                    } break;
                }
            }
        } break;
        #line 671 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 674 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 675 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 675 "src/analyzer/expression/Expression.pv"
            struct str operator = self->data.unaryexpression_value._0;
            #line 675 "src/analyzer/expression/Expression.pv"
            struct Expression* child = self->data.unaryexpression_value._1;
            #line 676 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 677 "src/analyzer/expression/Expression.pv"
                switch (type->type) {
                    #line 678 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 678 "src/analyzer/expression/Expression.pv"
                        struct Indirect* indirect = type->indirect_value;
                        #line 679 "src/analyzer/expression/Expression.pv"
                        switch (indirect->to.type) {
                            #line 680 "src/analyzer/expression/Expression.pv"
                            case TYPE__SEQUENCE: {
                                #line 681 "src/analyzer/expression/Expression.pv"
                                switch (child->data.type) {
                                    #line 682 "src/analyzer/expression/Expression.pv"
                                    case EXPRESSION_DATA__INVOKE: {
                                        #line 683 "src/analyzer/expression/Expression.pv"
                                        if (Type__is_sequence_fixed_array(&child->return_type)) {
                                            #line 684 "src/analyzer/expression/Expression.pv"
                                            Expression__validate_type(child, context, &indirect->to, apply_implicit_cast);
                                        }
                                    } break;
                                    #line 687 "src/analyzer/expression/Expression.pv"
                                    default: {
                                    } break;
                                }
                            } break;
                            #line 690 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 693 "src/analyzer/expression/Expression.pv"
                    default: {
                    } break;
                }
            }
        } break;
        #line 697 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 697 "src/analyzer/expression/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 697 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 698 "src/analyzer/expression/Expression.pv"
            switch (type->type) {
                #line 699 "src/analyzer/expression/Expression.pv"
                case TYPE__TUPLE: {
                    #line 699 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = type->tuple_value;
                    #line 700 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 700 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 700 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 700 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 701 "src/analyzer/expression/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i], apply_implicit_cast) && success;
                    } }

                    #line 704 "src/analyzer/expression/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type };
                    #line 705 "src/analyzer/expression/Expression.pv"
                    invoke->return_type = *type;
                    #line 706 "src/analyzer/expression/Expression.pv"
                    self->return_type = *type;

                    #line 708 "src/analyzer/expression/Expression.pv"
                    return success;
                } break;
                #line 710 "src/analyzer/expression/Expression.pv"
                case TYPE__SEQUENCE: {
                    #line 710 "src/analyzer/expression/Expression.pv"
                    struct Sequence* sequence = type->sequence_value;
                    #line 711 "src/analyzer/expression/Expression.pv"
                    if (Type__is_sequence_fixed_array(&self->return_type)) {
                        #line 712 "src/analyzer/expression/Expression.pv"
                        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                        #line 712 "src/analyzer/expression/Expression.pv"
                        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                            #line 712 "src/analyzer/expression/Expression.pv"
                            struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                            #line 713 "src/analyzer/expression/Expression.pv"
                            success = Expression__validate_type(argument->value, context, &sequence->element, apply_implicit_cast) && success;
                        } }

                        #line 716 "src/analyzer/expression/Expression.pv"
                        switch (self->return_type.type) {
                            #line 717 "src/analyzer/expression/Expression.pv"
                            case TYPE__SEQUENCE: {
                                #line 717 "src/analyzer/expression/Expression.pv"
                                struct Sequence* self_seq = self->return_type.sequence_value;
                                #line 718 "src/analyzer/expression/Expression.pv"
                                struct Sequence* new_seq = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) { .type = self_seq->type, .element = sequence->element, .element_pointer = self_seq->element_pointer }});
                                #line 719 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = new_seq }});
                                #line 720 "src/analyzer/expression/Expression.pv"
                                invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type };
                                #line 721 "src/analyzer/expression/Expression.pv"
                                invoke->return_type = *new_type;
                                #line 722 "src/analyzer/expression/Expression.pv"
                                self->return_type = *new_type;
                            } break;
                            #line 724 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 727 "src/analyzer/expression/Expression.pv"
                        return success;
                    }
                } break;
                #line 730 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 733 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 736 "src/analyzer/expression/Expression.pv"
    if (apply_implicit_cast && Type__needs_implicit_cast(type, &self->return_type)) {
        #line 737 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, self);
        #line 738 "src/analyzer/expression/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 739 "src/analyzer/expression/Expression.pv"
        self->return_type = *type;
        #line 740 "src/analyzer/expression/Expression.pv"
        return true;
    }

    #line 743 "src/analyzer/expression/Expression.pv"
    if (!Type__eq(type, &self->return_type)) {
        #line 744 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 745 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
        #line 746 "src/analyzer/expression/Expression.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 747 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&type_name));
        #line 748 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 749 "src/analyzer/expression/Expression.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 750 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 751 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, self->token, String__c_str(&message));
        #line 752 "src/analyzer/expression/Expression.pv"
        return false;
    }
    #line 756 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 759 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics) {
    #line 760 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 761 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 761 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 763 "src/analyzer/expression/Expression.pv"
    struct Expression* condition = Expression__parse(context, generics);
    #line 764 "src/analyzer/expression/Expression.pv"
    if (condition == 0) {
        #line 764 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 766 "src/analyzer/expression/Expression.pv"
    switch (condition->return_type.type) {
        #line 767 "src/analyzer/expression/Expression.pv"
        case TYPE__PRIMITIVE: {
            #line 767 "src/analyzer/expression/Expression.pv"
            struct Primitive* prim = condition->return_type.primitive_value;
            #line 768 "src/analyzer/expression/Expression.pv"
            if (prim == 0) {
                #line 769 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, condition->token, "If condition return type is blank");
                #line 770 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 773 "src/analyzer/expression/Expression.pv"
            if (!str__Eq_str__eq(&prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                #line 774 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, condition->token, "If condition must be a bool expression");
                #line 775 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        } break;
        #line 778 "src/analyzer/expression/Expression.pv"
        default: {
            #line 779 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, condition->token, "If condition must be a bool expression");
            #line 780 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
    }

    #line 784 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 784 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 786 "src/analyzer/expression/Expression.pv"
    struct Expression* a = Expression__parse(context, generics);
    #line 787 "src/analyzer/expression/Expression.pv"
    if (a == 0) {
        #line 787 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 789 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 789 "src/analyzer/expression/Expression.pv"
        return 0;
    }
    #line 790 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 790 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 792 "src/analyzer/expression/Expression.pv"
    bool is_else_if = Context__check_value(context, TOKEN_TYPE__KEYWORD, "if");

    #line 794 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 795 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Expected { or else if");
        #line 796 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 799 "src/analyzer/expression/Expression.pv"
    struct Expression* b = Expression__parse(context, generics);
    #line 800 "src/analyzer/expression/Expression.pv"
    if (b == 0) {
        #line 800 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 802 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 802 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 804 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_type(a, context, &b->return_type, false)) {
        #line 804 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 806 "src/analyzer/expression/Expression.pv"
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
            if (context->type_self == 0) {
                #line 15 "src/analyzer/expression/MemberLookup.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
            }
            #line 16 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_enum_variant(context, context->type_self, token);
        } break;
        #line 18 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM: {
            #line 18 "src/analyzer/expression/MemberLookup.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 18 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 19 "src/analyzer/expression/MemberLookup.pv"
            struct EnumVariant* variant = HashMap_str_EnumVariant__find(&enum_info->variants, &token->value);
            #line 20 "src/analyzer/expression/MemberLookup.pv"
            if (variant != 0) {
                #line 21 "src/analyzer/expression/MemberLookup.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_VARIANT, .enumvariant_value = variant };
            }

            #line 24 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 24 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 24 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 25 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, token->value);
                #line 26 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 27 "src/analyzer/expression/MemberLookup.pv"
                    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} };
                }
            } }

            #line 31 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 31 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 31 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 32 "src/analyzer/expression/MemberLookup.pv"
                struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &token->value);
                #line 33 "src/analyzer/expression/MemberLookup.pv"
                if (impl_const_ptr != 0) {
                    #line 34 "src/analyzer/expression/MemberLookup.pv"
                    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__CONST, .const_value = *impl_const_ptr };
                }
            } }

            #line 38 "src/analyzer/expression/MemberLookup.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
        #line 40 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM_C: {
            #line 40 "src/analyzer/expression/MemberLookup.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 41 "src/analyzer/expression/MemberLookup.pv"
            struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &token->value);
            #line 42 "src/analyzer/expression/MemberLookup.pv"
            if (variant == 0) {
                #line 43 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, token, "Variant not found in enum");
                #line 44 "src/analyzer/expression/MemberLookup.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
            }

            #line 47 "src/analyzer/expression/MemberLookup.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_CVALUE, .enumcvalue_value = variant };
        } break;
        #line 49 "src/analyzer/expression/MemberLookup.pv"
        default: {
            #line 49 "src/analyzer/expression/MemberLookup.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
    }

    #line 52 "src/analyzer/expression/MemberLookup.pv"
    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
}

#line 55 "src/analyzer/expression/MemberLookup.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error) {
    #line 56 "src/analyzer/expression/MemberLookup.pv"
    switch (type->type) {
        #line 57 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__INDIRECT: {
            #line 57 "src/analyzer/expression/MemberLookup.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 58 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 60 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SELF: {
            #line 61 "src/analyzer/expression/MemberLookup.pv"
            if (context->type_self == 0) {
                #line 61 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }
            #line 62 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 64 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__PRIMITIVE: {
            #line 64 "src/analyzer/expression/MemberLookup.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 65 "src/analyzer/expression/MemberLookup.pv"
            if (primitive_info == 0) {
                #line 65 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }
            #line 66 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 66 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 66 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 67 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 68 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 69 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }})} }});
                }
            } }

            #line 73 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 73 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 74 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 76 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__STRUCT: {
            #line 76 "src/analyzer/expression/MemberLookup.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 76 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 77 "src/analyzer/expression/MemberLookup.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 78 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 79 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 82 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 82 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 82 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 83 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 84 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 85 "src/analyzer/expression/MemberLookup.pv"
                    if (impl_info->typedefs.length == 0) {
                        #line 86 "src/analyzer/expression/MemberLookup.pv"
                        return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                    }
                    #line 88 "src/analyzer/expression/MemberLookup.pv"
                    if (generic_map == 0) {
                        #line 88 "src/analyzer/expression/MemberLookup.pv"
                        return 0;
                    }
                    #line 89 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 90 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 91 "src/analyzer/expression/MemberLookup.pv"
                    if (aug_map == 0) {
                        #line 91 "src/analyzer/expression/MemberLookup.pv"
                        return 0;
                    }
                    #line 92 "src/analyzer/expression/MemberLookup.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 92 "src/analyzer/expression/MemberLookup.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 92 "src/analyzer/expression/MemberLookup.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 92 "src/analyzer/expression/MemberLookup.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 93 "src/analyzer/expression/MemberLookup.pv"
                        GenericMap__insert(aug_map, name, *typedef_type);
                    } }
                    #line 95 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = aug_map} }});
                }
            } }

            #line 99 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 99 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 99 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 100 "src/analyzer/expression/MemberLookup.pv"
                struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member->value);
                #line 101 "src/analyzer/expression/MemberLookup.pv"
                if (impl_const_ptr != 0) {
                    #line 102 "src/analyzer/expression/MemberLookup.pv"
                    struct ImplConst* impl_const = *impl_const_ptr;
                    #line 103 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, &impl_const->type);
                }
            } }

            #line 107 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 108 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 110 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 112 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 112 "src/analyzer/expression/MemberLookup.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 112 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 113 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(&member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 114 "src/analyzer/expression/MemberLookup.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, &context->root->func_next);
                #line 115 "src/analyzer/expression/MemberLookup.pv"
                if (func_next == 0) {
                    #line 115 "src/analyzer/expression/MemberLookup.pv"
                    return 0;
                }
                #line 116 "src/analyzer/expression/MemberLookup.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 117 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} }});
            }

            #line 120 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(&member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 121 "src/analyzer/expression/MemberLookup.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, &context->root->func_value);
                #line 122 "src/analyzer/expression/MemberLookup.pv"
                if (func_value == 0) {
                    #line 122 "src/analyzer/expression/MemberLookup.pv"
                    return 0;
                }
                #line 123 "src/analyzer/expression/MemberLookup.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 124 "src/analyzer/expression/MemberLookup.pv"
                func_value->return_type = func_info->return_type;
                #line 125 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} }});
            }

            #line 128 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 128 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 129 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 131 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM: {
            #line 131 "src/analyzer/expression/MemberLookup.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 131 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 132 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 132 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 132 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 133 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 134 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 135 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                }
            } }

            #line 139 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 139 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 140 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 142 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TRAIT: {
            #line 142 "src/analyzer/expression/MemberLookup.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 142 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 143 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(&member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 144 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) }});
            }

            #line 147 "src/analyzer/expression/MemberLookup.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 148 "src/analyzer/expression/MemberLookup.pv"
            if (function == 0) {
                #line 149 "src/analyzer/expression/MemberLookup.pv"
                if (output_error) {
                    #line 149 "src/analyzer/expression/MemberLookup.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 150 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 153 "src/analyzer/expression/MemberLookup.pv"
            return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
        } break;
        #line 155 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TYPEDEF_C: {
            #line 155 "src/analyzer/expression/MemberLookup.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 156 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 158 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__STRUCT_C: {
            #line 158 "src/analyzer/expression/MemberLookup.pv"
            struct StructC* struct_info = type->structc_value;
            #line 159 "src/analyzer/expression/MemberLookup.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 160 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 160 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 162 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 162 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 163 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 165 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__UNION_C: {
            #line 165 "src/analyzer/expression/MemberLookup.pv"
            struct StructC* union_info = type->unionc_value;
            #line 166 "src/analyzer/expression/MemberLookup.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 167 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 167 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 169 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 169 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 170 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 172 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__CLASS_CPP: {
            #line 172 "src/analyzer/expression/MemberLookup.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 173 "src/analyzer/expression/MemberLookup.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 174 "src/analyzer/expression/MemberLookup.pv"
            if (field_type != 0) {
                #line 174 "src/analyzer/expression/MemberLookup.pv"
                return field_type;
            }

            #line 176 "src/analyzer/expression/MemberLookup.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 177 "src/analyzer/expression/MemberLookup.pv"
            if (value_type != 0) {
                #line 177 "src/analyzer/expression/MemberLookup.pv"
                return value_type;
            }

            #line 179 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 179 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 179 "src/analyzer/expression/MemberLookup.pv"
                struct Type* base = Iter_ref_Type__value(&__iter);

                #line 180 "src/analyzer/expression/MemberLookup.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 181 "src/analyzer/expression/MemberLookup.pv"
                if (base_type != 0) {
                    #line 181 "src/analyzer/expression/MemberLookup.pv"
                    return base_type;
                }
            } }

            #line 184 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 184 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 185 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 187 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__GENERIC: {
            #line 187 "src/analyzer/expression/MemberLookup.pv"
            struct Generic* generic = type->generic_value;
            #line 188 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
            #line 188 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 188 "src/analyzer/expression/MemberLookup.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 189 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 190 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 191 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap generic_map_val = (struct GenericMap) { .self_type = 0, .array = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }), .map = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) };
                    #line 192 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(context->allocator, &generic_map_val);
                    #line 193 "src/analyzer/expression/MemberLookup.pv"
                    if (generic_map == 0) {
                        #line 193 "src/analyzer/expression/MemberLookup.pv"
                        return 0;
                    }
                    #line 194 "src/analyzer/expression/MemberLookup.pv"
                    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
                    #line 194 "src/analyzer/expression/MemberLookup.pv"
                    while (HashMapIter_str_usize__next(&__iter)) {
                        #line 194 "src/analyzer/expression/MemberLookup.pv"
                        struct str typedef_name = HashMapIter_str_usize__value(&__iter)->_0;

                        #line 195 "src/analyzer/expression/MemberLookup.pv"
                        struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(context->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic, .typedef_name = typedef_name }});
                        #line 196 "src/analyzer/expression/MemberLookup.pv"
                        if (gt == 0) {
                            #line 196 "src/analyzer/expression/MemberLookup.pv"
                            return 0;
                        }
                        #line 197 "src/analyzer/expression/MemberLookup.pv"
                        GenericMap__insert(generic_map, typedef_name, (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt });
                    } }
                    #line 199 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                }
            } }

            #line 203 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 203 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 204 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 206 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SEQUENCE: {
            #line 206 "src/analyzer/expression/MemberLookup.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 207 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(&member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 208 "src/analyzer/expression/MemberLookup.pv"
                return &sequence->element_pointer;
            }

            #line 211 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(&member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 212 "src/analyzer/expression/MemberLookup.pv"
                return &context->root->type_usize;
            }

            #line 215 "src/analyzer/expression/MemberLookup.pv"
            struct TypeImpl* hack_type_impl = context->root->hack_type_impl;
            #line 216 "src/analyzer/expression/MemberLookup.pv"
            if (hack_type_impl == 0) {
                #line 216 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }
            #line 217 "src/analyzer/expression/MemberLookup.pv"
            struct Impl* impl_info = hack_type_impl->impl_info;

            #line 219 "src/analyzer/expression/MemberLookup.pv"
            struct Function* function = Impl__find_function(impl_info, member->value);
            #line 220 "src/analyzer/expression/MemberLookup.pv"
            if (function != 0) {
                #line 221 "src/analyzer/expression/MemberLookup.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }});
                #line 222 "src/analyzer/expression/MemberLookup.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 223 "src/analyzer/expression/MemberLookup.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) }});

                #line 225 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &generic_map)} }});
            }

            #line 228 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 228 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 229 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 231 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TUPLE: {
            #line 231 "src/analyzer/expression/MemberLookup.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 232 "src/analyzer/expression/MemberLookup.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 233 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 234 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 237 "src/analyzer/expression/MemberLookup.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 238 "src/analyzer/expression/MemberLookup.pv"
            if (index >= tuple->elements.length) {
                #line 239 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 240 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 243 "src/analyzer/expression/MemberLookup.pv"
            return &tuple->elements.data[index];
        } break;
        #line 245 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 245 "src/analyzer/expression/MemberLookup.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 246 "src/analyzer/expression/MemberLookup.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 247 "src/analyzer/expression/MemberLookup.pv"
            if (type != 0) {
                #line 247 "src/analyzer/expression/MemberLookup.pv"
                return type;
            }

            #line 249 "src/analyzer/expression/MemberLookup.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 250 "src/analyzer/expression/MemberLookup.pv"
            if (value != 0) {
                #line 250 "src/analyzer/expression/MemberLookup.pv"
                return value;
            }

            #line 252 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 252 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 254 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 256 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__UNKNOWN_C: {
            #line 256 "src/analyzer/expression/MemberLookup.pv"
            return type;
        } break;
        #line 257 "src/analyzer/expression/MemberLookup.pv"
        default: {
            #line 257 "src/analyzer/expression/MemberLookup.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 260 "src/analyzer/expression/MemberLookup.pv"
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
        struct Token* generic_name = generic->name;
        #line 32 "src/analyzer/expression/GenericResolve.pv"
        if (generic_name == 0) {
            #line 32 "src/analyzer/expression/GenericResolve.pv"
            continue;
        }

        #line 34 "src/analyzer/expression/GenericResolve.pv"
        struct Type* concrete_type = GenericMap__get(&generic_map, generic_name->value);
        #line 35 "src/analyzer/expression/GenericResolve.pv"
        if (concrete_type == 0) {
            #line 35 "src/analyzer/expression/GenericResolve.pv"
            continue;
        }

        #line 37 "src/analyzer/expression/GenericResolve.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
        #line 37 "src/analyzer/expression/GenericResolve.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 37 "src/analyzer/expression/GenericResolve.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 38 "src/analyzer/expression/GenericResolve.pv"
            { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
            #line 38 "src/analyzer/expression/GenericResolve.pv"
            while (HashMapIter_str_usize__next(&__iter)) {
                #line 38 "src/analyzer/expression/GenericResolve.pv"
                struct str typedef_name = HashMapIter_str_usize__value(&__iter)->_0;

                #line 39 "src/analyzer/expression/GenericResolve.pv"
                switch (concrete_type->type) {
                    #line 40 "src/analyzer/expression/GenericResolve.pv"
                    case TYPE__STRUCT: {
                        #line 40 "src/analyzer/expression/GenericResolve.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 41 "src/analyzer/expression/GenericResolve.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 41 "src/analyzer/expression/GenericResolve.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 41 "src/analyzer/expression/GenericResolve.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 42 "src/analyzer/expression/GenericResolve.pv"
                            if (impl_info->trait_ != trait_info) {
                                #line 42 "src/analyzer/expression/GenericResolve.pv"
                                continue;
                            }
                            #line 43 "src/analyzer/expression/GenericResolve.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &typedef_name);
                            #line 44 "src/analyzer/expression/GenericResolve.pv"
                            if (typedef_type != 0) {
                                #line 45 "src/analyzer/expression/GenericResolve.pv"
                                GenericMap__insert(&generic_map, typedef_name, *typedef_type);
                            }
                        } }
                    } break;
                    #line 49 "src/analyzer/expression/GenericResolve.pv"
                    default: {
                    } break;
                }
            } }
        } }
    } }

    #line 55 "src/analyzer/expression/GenericResolve.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, &generic_map);
}

#line 58 "src/analyzer/expression/GenericResolve.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 59 "src/analyzer/expression/GenericResolve.pv"
    switch (param_type->type) {
        #line 60 "src/analyzer/expression/GenericResolve.pv"
        case TYPE__GENERIC: {
            #line 60 "src/analyzer/expression/GenericResolve.pv"
            struct Generic* generic = param_type->generic_value;
            #line 61 "src/analyzer/expression/GenericResolve.pv"
            struct Token* generic_name = generic->name;
            #line 62 "src/analyzer/expression/GenericResolve.pv"
            if (generic_name == 0) {
                #line 62 "src/analyzer/expression/GenericResolve.pv"
                return;
            }

            #line 64 "src/analyzer/expression/GenericResolve.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic_name->value);
            #line 65 "src/analyzer/expression/GenericResolve.pv"
            if (generic_type != 0) {
                #line 65 "src/analyzer/expression/GenericResolve.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 67 "src/analyzer/expression/GenericResolve.pv"
        case TYPE__INDIRECT: {
            #line 67 "src/analyzer/expression/GenericResolve.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 68 "src/analyzer/expression/GenericResolve.pv"
            switch (arg_type->type) {
                #line 69 "src/analyzer/expression/GenericResolve.pv"
                case TYPE__INDIRECT: {
                    #line 69 "src/analyzer/expression/GenericResolve.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 70 "src/analyzer/expression/GenericResolve.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 72 "src/analyzer/expression/GenericResolve.pv"
                default: {
                } break;
            }
        } break;
        #line 75 "src/analyzer/expression/GenericResolve.pv"
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
            #line 12 "src/analyzer/expression/ExpressionValidate.pv"
            if (context->type_self == 0) {
                #line 12 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }
            #line 13 "src/analyzer/expression/ExpressionValidate.pv"
            type = context->type_self;
        } break;
        #line 15 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
        } break;
    }

    #line 18 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 19 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TYPEDEF_C: {
            #line 19 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 20 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNION_C: {
            #line 20 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 21 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT_C: {
            #line 21 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 22 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TUPLE: {
            #line 22 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 23 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT: {
            #line 23 "src/analyzer/expression/ExpressionValidate.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 23 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 24 "src/analyzer/expression/ExpressionValidate.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 24 "src/analyzer/expression/ExpressionValidate.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 24 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 25 "src/analyzer/expression/ExpressionValidate.pv"
                struct Token* arg_name = arg->name;
                #line 26 "src/analyzer/expression/ExpressionValidate.pv"
                if (arg_name == 0) {
                    #line 26 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }
                #line 27 "src/analyzer/expression/ExpressionValidate.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg_name->value);

                #line 29 "src/analyzer/expression/ExpressionValidate.pv"
                if (param == 0) {
                    #line 30 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg_name, "Unable to find field in struct");
                    #line 31 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 34 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &param->type;

                #line 36 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2 != 0 && generic_map2->map.length > 0) {
                    #line 37 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 39 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 42 "src/analyzer/expression/ExpressionValidate.pv"
                if (param_type == 0) {
                    #line 43 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve field type");
                    #line 44 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 47 "src/analyzer/expression/ExpressionValidate.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            } }

            #line 50 "src/analyzer/expression/ExpressionValidate.pv"
            bool success = true;
            #line 51 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t field_i = 0;
            #line 52 "src/analyzer/expression/ExpressionValidate.pv"
            while (field_i < struct_info->fields.length) {
                #line 53 "src/analyzer/expression/ExpressionValidate.pv"
                struct HashMapBucket_str_StructField* bucket = struct_info->fields.data + field_i;
                #line 54 "src/analyzer/expression/ExpressionValidate.pv"
                if (bucket == 0) {
                    #line 54 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }
                #line 55 "src/analyzer/expression/ExpressionValidate.pv"
                bool provided = false;
                #line 56 "src/analyzer/expression/ExpressionValidate.pv"
                uintptr_t arg_i = 0;
                #line 57 "src/analyzer/expression/ExpressionValidate.pv"
                while (arg_i < arguments->length) {
                    #line 58 "src/analyzer/expression/ExpressionValidate.pv"
                    struct Token* arg_name = arguments->data[arg_i].name;
                    #line 59 "src/analyzer/expression/ExpressionValidate.pv"
                    if (arg_name != 0 && str__Eq_str__eq(&arg_name->value, bucket->key)) {
                        #line 60 "src/analyzer/expression/ExpressionValidate.pv"
                        provided = true;
                        #line 61 "src/analyzer/expression/ExpressionValidate.pv"
                        break;
                    }
                    #line 63 "src/analyzer/expression/ExpressionValidate.pv"
                    arg_i += 1;
                }
                #line 65 "src/analyzer/expression/ExpressionValidate.pv"
                if (!provided) {
                    #line 66 "src/analyzer/expression/ExpressionValidate.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 67 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, (struct str){ .ptr = "Missing field in struct construction: ", .length = strlen("Missing field in struct construction: ") });
                    #line 68 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, bucket->key);
                    #line 69 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, token, String__c_str(&message));
                    #line 70 "src/analyzer/expression/ExpressionValidate.pv"
                    success = false;
                }
                #line 72 "src/analyzer/expression/ExpressionValidate.pv"
                field_i += 1;
            }

            #line 75 "src/analyzer/expression/ExpressionValidate.pv"
            return success;
        } break;
        #line 77 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION: {
            #line 77 "src/analyzer/expression/ExpressionValidate.pv"
            struct Function* function = type->function_value._0;
            #line 77 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 78 "src/analyzer/expression/ExpressionValidate.pv"
            if ((struct Function*)(function) == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 78 "src/analyzer/expression/ExpressionValidate.pv"
                return true;
            }

            #line 80 "src/analyzer/expression/ExpressionValidate.pv"
            if (function->parameters.length != arguments_length) {
                #line 81 "src/analyzer/expression/ExpressionValidate.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 82 "src/analyzer/expression/ExpressionValidate.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 84 "src/analyzer/expression/ExpressionValidate.pv"
                if (is_member_call) {
                    #line 85 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append_usize(&message, function->parameters.length - 1);
                } else {
                    #line 87 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append_usize(&message, function->parameters.length);
                }

                #line 90 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 91 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 94 "src/analyzer/expression/ExpressionValidate.pv"
            struct Iter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 95 "src/analyzer/expression/ExpressionValidate.pv"
            struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

            #line 97 "src/analyzer/expression/ExpressionValidate.pv"
            if (is_member_call) {
                #line 98 "src/analyzer/expression/ExpressionValidate.pv"
                Iter_ref_Parameter__next(&param_iter);
                #line 99 "src/analyzer/expression/ExpressionValidate.pv"
                Iter_ref_InvokeArgument__next(&args_iter);

                #line 101 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 102 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &Iter_ref_Parameter__value(&param_iter)->type;

                #line 104 "src/analyzer/expression/ExpressionValidate.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 105 "src/analyzer/expression/ExpressionValidate.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) }});
                    #line 106 "src/analyzer/expression/ExpressionValidate.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 110 "src/analyzer/expression/ExpressionValidate.pv"
            while (Iter_ref_Parameter__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
                #line 111 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 112 "src/analyzer/expression/ExpressionValidate.pv"
                struct Parameter* param = Iter_ref_Parameter__value(&param_iter);
                #line 113 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &param->type;

                #line 115 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2 != 0 && generic_map2->map.length > 0) {
                    #line 116 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 118 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 121 "src/analyzer/expression/ExpressionValidate.pv"
                if (param_type == 0) {
                    #line 122 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
                    #line 123 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 126 "src/analyzer/expression/ExpressionValidate.pv"
                Expression__validate_type(arg->value, context, param_type, true);

                #line 128 "src/analyzer/expression/ExpressionValidate.pv"
                if (arg->name == 0 && param->name != 0 && !str__Eq_str__eq(&param->name->value, (struct str){ .ptr = "self", .length = strlen("self") }) && !str__Eq_str__eq(&param->name->value, arg->value->token->value)) {
                    #line 129 "src/analyzer/expression/ExpressionValidate.pv"
                    struct String label = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 130 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&label, param->name->value);
                    #line 131 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&label, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 132 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__inlay_hint_before(context, arg->value->token, String__c_str(&label), INLAY_HINT_KIND__PARAMETER, false, true);
                }
            }

            #line 136 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 138 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION_C: {
            #line 138 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 139 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__CLASS_CPP: {
            #line 139 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 140 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNKNOWN_C: {
            #line 140 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 141 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
            #line 141 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 144 "src/analyzer/expression/ExpressionValidate.pv"
    return false;
}

#line 147 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 148 "src/analyzer/expression/ExpressionValidate.pv"
    uintptr_t arguments_length = arguments->length;

    #line 150 "src/analyzer/expression/ExpressionValidate.pv"
    if (variant->types.length != arguments_length) {
        #line 151 "src/analyzer/expression/ExpressionValidate.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 152 "src/analyzer/expression/ExpressionValidate.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 153 "src/analyzer/expression/ExpressionValidate.pv"
        String__append_usize(&message, variant->types.length);
        #line 154 "src/analyzer/expression/ExpressionValidate.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 155 "src/analyzer/expression/ExpressionValidate.pv"
        return false;
    }

    #line 158 "src/analyzer/expression/ExpressionValidate.pv"
    if (variant->names.length > 0) {
        #line 159 "src/analyzer/expression/ExpressionValidate.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 159 "src/analyzer/expression/ExpressionValidate.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 159 "src/analyzer/expression/ExpressionValidate.pv"
            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

            #line 160 "src/analyzer/expression/ExpressionValidate.pv"
            if (arg->name == 0) {
                #line 161 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, token, "Expected named field argument");
                #line 162 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 165 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t field_i = 0;
            #line 166 "src/analyzer/expression/ExpressionValidate.pv"
            bool found = false;
            #line 167 "src/analyzer/expression/ExpressionValidate.pv"
            while (field_i < variant->names.length) {
                #line 168 "src/analyzer/expression/ExpressionValidate.pv"
                if (str__Eq_str__eq(&variant->names.data[field_i], arg->name->value)) {
                    #line 169 "src/analyzer/expression/ExpressionValidate.pv"
                    found = true;
                    #line 170 "src/analyzer/expression/ExpressionValidate.pv"
                    break;
                }
                #line 172 "src/analyzer/expression/ExpressionValidate.pv"
                field_i += 1;
            }

            #line 175 "src/analyzer/expression/ExpressionValidate.pv"
            if (!found) {
                #line 176 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, arg->name, "Field not found in enum variant");
                #line 177 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 180 "src/analyzer/expression/ExpressionValidate.pv"
            struct Type* param_type = variant->types.data + field_i;
            #line 181 "src/analyzer/expression/ExpressionValidate.pv"
            if (generic_map != 0) {
                #line 182 "src/analyzer/expression/ExpressionValidate.pv"
                param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
            }

            #line 185 "src/analyzer/expression/ExpressionValidate.pv"
            if (param_type == 0) {
                #line 186 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, arg->value->token, "Unable to resolve field type");
                #line 187 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 190 "src/analyzer/expression/ExpressionValidate.pv"
            Expression__validate_type(arg->value, context, param_type, true);
        } }

        #line 193 "src/analyzer/expression/ExpressionValidate.pv"
        return true;
    }

    #line 196 "src/analyzer/expression/ExpressionValidate.pv"
    struct Iter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 197 "src/analyzer/expression/ExpressionValidate.pv"
    struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 199 "src/analyzer/expression/ExpressionValidate.pv"
    while (Iter_ref_Type__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
        #line 200 "src/analyzer/expression/ExpressionValidate.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
        #line 201 "src/analyzer/expression/ExpressionValidate.pv"
        struct Type* param_type = Iter_ref_Type__value(&param_iter);

        #line 203 "src/analyzer/expression/ExpressionValidate.pv"
        if (generic_map != 0) {
            #line 204 "src/analyzer/expression/ExpressionValidate.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 207 "src/analyzer/expression/ExpressionValidate.pv"
        if (param_type == 0) {
            #line 208 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
            #line 209 "src/analyzer/expression/ExpressionValidate.pv"
            return false;
        }

        #line 212 "src/analyzer/expression/ExpressionValidate.pv"
        Expression__validate_type(arg->value, context, param_type, true);
    }

    #line 215 "src/analyzer/expression/ExpressionValidate.pv"
    return true;
}

#line 218 "src/analyzer/expression/ExpressionValidate.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 219 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 220 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TUPLE: {
            #line 220 "src/analyzer/expression/ExpressionValidate.pv"
            return type;
        } break;
        #line 221 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION: {
            #line 221 "src/analyzer/expression/ExpressionValidate.pv"
            struct Function* func_info = type->function_value._0;
            #line 221 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 222 "src/analyzer/expression/ExpressionValidate.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 223 "src/analyzer/expression/ExpressionValidate.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} }});
            }
            #line 225 "src/analyzer/expression/ExpressionValidate.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 227 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION_C: {
            #line 227 "src/analyzer/expression/ExpressionValidate.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 227 "src/analyzer/expression/ExpressionValidate.pv"
            return &func_info->return_type;
        } break;
        #line 228 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNKNOWN_C: {
            #line 228 "src/analyzer/expression/ExpressionValidate.pv"
            return type;
        } break;
        #line 229 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
            #line 229 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 232 "src/analyzer/expression/ExpressionValidate.pv"
    return 0;
}

#line 235 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 236 "src/analyzer/expression/ExpressionValidate.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 236 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 238 "src/analyzer/expression/ExpressionValidate.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 239 "src/analyzer/expression/ExpressionValidate.pv"
    if (func_return_type == 0) {
        #line 239 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 241 "src/analyzer/expression/ExpressionValidate.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 242 "src/analyzer/expression/ExpressionValidate.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 245 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 246 "src/analyzer/expression/ExpressionValidate.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 246 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 248 "src/analyzer/expression/ExpressionValidate.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 249 "src/analyzer/expression/ExpressionValidate.pv"
    if (func_return_type == 0) {
        #line 249 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 251 "src/analyzer/expression/ExpressionValidate.pv"
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
            case ENUM_VARIANT_RESULT__CONST: {
                #line 110 "src/analyzer/expression/ParseTypeExpression.pv"
                struct ImplConst* impl_const = variant_result.const_value;
                #line 111 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 112 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, ArenaAllocator__store_Type(context->allocator, &impl_const->type));
            } break;
            #line 114 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                #line 115 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 116 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, enum_type);
            } break;
        }
    }

    #line 131 "src/analyzer/expression/ParseTypeExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 134 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 135 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 136 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 137 "src/analyzer/expression/ParseTypeExpression.pv"
        if (member == 0) {
            #line 137 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 139 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 140 "src/analyzer/expression/ParseTypeExpression.pv"
        if (member_type == 0) {
            #line 140 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 142 "src/analyzer/expression/ParseTypeExpression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 144 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 145 "src/analyzer/expression/ParseTypeExpression.pv"
            switch (member_type->type) {
                #line 146 "src/analyzer/expression/ParseTypeExpression.pv"
                case TYPE__FUNCTION: {
                    #line 147 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                } break;
                #line 149 "src/analyzer/expression/ParseTypeExpression.pv"
                default: {
                    #line 150 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct Expression* struct_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
                    #line 151 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = struct_expr, ._1 = member->value} }, member_type);
                } break;
            }
        } else {
            #line 155 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 155 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 157 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 159 "src/analyzer/expression/ParseTypeExpression.pv"
            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 160 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 161 "src/analyzer/expression/ParseTypeExpression.pv"
                if (argument == 0) {
                    #line 161 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 163 "src/analyzer/expression/ParseTypeExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                #line 165 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 166 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 167 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }
            }

            #line 171 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 171 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 173 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 173 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 175 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 176 "src/analyzer/expression/ParseTypeExpression.pv"
            if (func_return_type == 0) {
                #line 176 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 178 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 179 "src/analyzer/expression/ParseTypeExpression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 182 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 184 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 185 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 186 "src/analyzer/expression/ParseTypeExpression.pv"
            if (name == 0) {
                #line 186 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 188 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = 0;
            #line 189 "src/analyzer/expression/ParseTypeExpression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 190 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 192 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 193 "src/analyzer/expression/ParseTypeExpression.pv"
                if (return_type == 0) {
                    #line 194 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 195 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 198 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 201 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 201 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 203 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 205 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 206 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 207 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 211 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 211 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 213 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Type* resolved_struct_type = struct_type;
        #line 214 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (struct_type->type) {
            #line 215 "src/analyzer/expression/ParseTypeExpression.pv"
            case TYPE__SELF: {
                #line 216 "src/analyzer/expression/ParseTypeExpression.pv"
                if (context->type_self == 0) {
                    #line 216 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }
                #line 217 "src/analyzer/expression/ParseTypeExpression.pv"
                resolved_struct_type = context->type_self;
            } break;
            #line 219 "src/analyzer/expression/ParseTypeExpression.pv"
            default: {
            } break;
        }

        #line 222 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (resolved_struct_type->type) {
            #line 223 "src/analyzer/expression/ParseTypeExpression.pv"
            case TYPE__STRUCT: {
                #line 223 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Struct* struct_info = resolved_struct_type->struct_value._0;
                #line 224 "src/analyzer/expression/ParseTypeExpression.pv"
                uintptr_t field_i = 0;
                #line 225 "src/analyzer/expression/ParseTypeExpression.pv"
                while (field_i < struct_info->fields.length) {
                    #line 226 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct HashMapBucket_str_StructField* bucket = struct_info->fields.data + field_i;
                    #line 227 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (bucket == 0) {
                        #line 227 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                    #line 228 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (bucket->value.default_token_start != 0) {
                        #line 229 "src/analyzer/expression/ParseTypeExpression.pv"
                        bool already_provided = false;
                        #line 230 "src/analyzer/expression/ParseTypeExpression.pv"
                        uintptr_t arg_i = 0;
                        #line 231 "src/analyzer/expression/ParseTypeExpression.pv"
                        while (arg_i < fields.length) {
                            #line 232 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Token* arg_name = fields.data[arg_i].name;
                            #line 233 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (arg_name != 0 && str__Eq_str__eq(&arg_name->value, bucket->key)) {
                                #line 234 "src/analyzer/expression/ParseTypeExpression.pv"
                                already_provided = true;
                                #line 235 "src/analyzer/expression/ParseTypeExpression.pv"
                                break;
                            }
                            #line 237 "src/analyzer/expression/ParseTypeExpression.pv"
                            arg_i += 1;
                        }

                        #line 240 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (!already_provided) {
                            #line 241 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Module* module = struct_info->module;
                            #line 242 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Context* struct_context = &module->context;
                            #line 243 "src/analyzer/expression/ParseTypeExpression.pv"
                            uintptr_t saved_pos = struct_context->pos;
                            #line 244 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct_context->pos = bucket->value.default_token_start;
                            #line 245 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Expression* default_expr = Expression__parse(struct_context, &struct_info->generics);
                            #line 246 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct_context->pos = saved_pos;

                            #line 248 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (default_expr != 0) {
                                #line 249 "src/analyzer/expression/ParseTypeExpression.pv"
                                struct Token* field_name = bucket->value.name;
                                #line 250 "src/analyzer/expression/ParseTypeExpression.pv"
                                Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = field_name, .value = default_expr });
                            }
                        }
                    }
                    #line 254 "src/analyzer/expression/ParseTypeExpression.pv"
                    field_i += 1;
                }
            } break;
            #line 257 "src/analyzer/expression/ParseTypeExpression.pv"
            default: {
            } break;
        }

        #line 260 "src/analyzer/expression/ParseTypeExpression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 261 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 261 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 263 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 264 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 266 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 268 "src/analyzer/expression/ParseTypeExpression.pv"
        uintptr_t field_index = 0;
        #line 269 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 270 "src/analyzer/expression/ParseTypeExpression.pv"
            struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 271 "src/analyzer/expression/ParseTypeExpression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 272 "src/analyzer/expression/ParseTypeExpression.pv"
            String__append_usize(&name, field_index);
            #line 273 "src/analyzer/expression/ParseTypeExpression.pv"
            struct str name_str = String__as_str(&name);

            #line 275 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token name_token = *Context__current(context);
            #line 276 "src/analyzer/expression/ParseTypeExpression.pv"
            name_token.value = name_str;

            #line 278 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 279 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 279 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 281 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, &name_token),
                .value = value,
            });

            #line 286 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 287 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 288 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 291 "src/analyzer/expression/ParseTypeExpression.pv"
            field_index += 1;
        }

        #line 294 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 294 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 296 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 297 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 300 "src/analyzer/expression/ParseTypeExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 303 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 304 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 305 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 307 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 308 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 309 "src/analyzer/expression/ParseTypeExpression.pv"
            if (name == 0) {
                #line 309 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 311 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = 0;
            #line 312 "src/analyzer/expression/ParseTypeExpression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 313 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 315 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 316 "src/analyzer/expression/ParseTypeExpression.pv"
                if (return_type == 0) {
                    #line 317 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 318 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 321 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 324 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 324 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 326 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 328 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 329 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 330 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 334 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 334 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 336 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 336 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 338 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 340 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 342 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 343 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 344 "src/analyzer/expression/ParseTypeExpression.pv"
            if (argument == 0) {
                #line 344 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 346 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

            #line 348 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 349 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 350 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 354 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 354 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 356 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 359 "src/analyzer/expression/ParseTypeExpression.pv"
    return parent;
}

#line 362 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 363 "src/analyzer/expression/ParseTypeExpression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 365 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 366 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* placement = 0;
        #line 367 "src/analyzer/expression/ParseTypeExpression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 368 "src/analyzer/expression/ParseTypeExpression.pv"
            placement = Expression__parse(context, generics);
            #line 369 "src/analyzer/expression/ParseTypeExpression.pv"
            if (placement == 0) {
                #line 369 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
            #line 370 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 370 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 373 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 374 "src/analyzer/expression/ParseTypeExpression.pv"
        if (expression == 0) {
            #line 374 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 376 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 377 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { .placement = placement, .expression = expression } } }, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 379 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 380 "src/analyzer/expression/ParseTypeExpression.pv"
        if (expression == 0) {
            #line 380 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 382 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &context->root->type_unknown);
    }

    #line 385 "src/analyzer/expression/ParseTypeExpression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 386 "src/analyzer/expression/ParseTypeExpression.pv"
    return 0;
}

#line 7 "src/analyzer/expression/PostfixExpression.pv"
struct Type* Expression__make_optional_return_type(struct Context* context, struct Token* token, struct Type* type) {
    #line 8 "src/analyzer/expression/PostfixExpression.pv"
    switch (type->type) {
        #line 9 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__INDIRECT: {
            #line 9 "src/analyzer/expression/PostfixExpression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 10 "src/analyzer/expression/PostfixExpression.pv"
            switch (indirect->type) {
                #line 11 "src/analyzer/expression/PostfixExpression.pv"
                case INDIRECT_TYPE__REFERENCE: {
                    #line 12 "src/analyzer/expression/PostfixExpression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, indirect->to) }});
                } break;
                #line 14 "src/analyzer/expression/PostfixExpression.pv"
                case INDIRECT_TYPE__POINTER: {
                    #line 14 "src/analyzer/expression/PostfixExpression.pv"
                    return type;
                } break;
                #line 15 "src/analyzer/expression/PostfixExpression.pv"
                case INDIRECT_TYPE__CONST_POINTER: {
                    #line 15 "src/analyzer/expression/PostfixExpression.pv"
                    return type;
                } break;
                #line 16 "src/analyzer/expression/PostfixExpression.pv"
                default: {
                } break;
            }
        } break;
        #line 19 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 22 "src/analyzer/expression/PostfixExpression.pv"
    Context__error_token(context, token, "?. must return a pointer or reference");
    #line 23 "src/analyzer/expression/PostfixExpression.pv"
    return 0;
}

#line 26 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_optional_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 27 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);
    #line 28 "src/analyzer/expression/PostfixExpression.pv"
    if (token == 0) {
        #line 28 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 30 "src/analyzer/expression/PostfixExpression.pv"
    if (!Type__is_pointer(&inner->return_type)) {
        #line 31 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_token(context, token, "?. can only be used on pointer values");
        #line 32 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 35 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* value = Expression__parse_instance_member_expression_inner(context, inner, generics, true);
    #line 36 "src/analyzer/expression/PostfixExpression.pv"
    if (value == 0) {
        #line 36 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 38 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* return_type = Expression__make_optional_return_type(context, value->token, &value->return_type);
    #line 39 "src/analyzer/expression/PostfixExpression.pv"
    if (return_type == 0) {
        #line 39 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 41 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__OPTIONAL_EXPRESSION, .optionalexpression_value = { ._0 = inner, ._1 = value} }, return_type);
}

#line 44 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 45 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 45 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 47 "src/analyzer/expression/PostfixExpression.pv"
    switch (inner->return_type.type) {
        #line 48 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 49 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 50 "src/analyzer/expression/PostfixExpression.pv"
        default: {
            #line 51 "src/analyzer/expression/PostfixExpression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 52 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        } break;
    }

    #line 56 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 57 "src/analyzer/expression/PostfixExpression.pv"
    if (member == 0) {
        #line 57 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 59 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 60 "src/analyzer/expression/PostfixExpression.pv"
    if (member_type == 0) {
        #line 60 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 62 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 65 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 66 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__parse_instance_member_expression_inner(context, inner, generics, false);
}

#line 69 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_instance_member_expression_inner(struct Context* context, struct Expression* inner, struct Generics* generics, bool allow_pointer) {
    #line 70 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* dot_token = Context__current(context);
    #line 71 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 71 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 73 "src/analyzer/expression/PostfixExpression.pv"
    if (!allow_pointer && Type__is_pointer(&inner->return_type)) {
        #line 74 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_token(context, dot_token, ". cannot be used on a *T pointer; use ?. or check for null with `if x == null { ... }` first");
    }

    #line 77 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* member_name = Context__current(context);
    #line 78 "src/analyzer/expression/PostfixExpression.pv"
    if (member_name == 0) {
        #line 79 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_token(context, dot_token, "no token found after .");
        #line 80 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 83 "src/analyzer/expression/PostfixExpression.pv"
    if (member_name->type != TOKEN_TYPE__NUMBER && member_name->type != TOKEN_TYPE__IDENTIFIER) {
        #line 84 "src/analyzer/expression/PostfixExpression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 87 "src/analyzer/expression/PostfixExpression.pv"
    Context__next_token(context);

    #line 89 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 90 "src/analyzer/expression/PostfixExpression.pv"
    if (member_type == 0) {
        #line 90 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 92 "src/analyzer/expression/PostfixExpression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 93 "src/analyzer/expression/PostfixExpression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };
    #line 94 "src/analyzer/expression/PostfixExpression.pv"
    struct Function* func_info = 0;

    #line 96 "src/analyzer/expression/PostfixExpression.pv"
    bool is_function = false;
    #line 97 "src/analyzer/expression/PostfixExpression.pv"
    switch (member_type->type) {
        #line 98 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__FUNCTION: {
            #line 98 "src/analyzer/expression/PostfixExpression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 99 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
            #line 100 "src/analyzer/expression/PostfixExpression.pv"
            func_info = func_info2;
        } break;
        #line 102 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__FUNCTION_C: {
            #line 102 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
        } break;
        #line 103 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__UNKNOWN_C: {
            #line 103 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
        } break;
        #line 104 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 107 "src/analyzer/expression/PostfixExpression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 108 "src/analyzer/expression/PostfixExpression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 111 "src/analyzer/expression/PostfixExpression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 112 "src/analyzer/expression/PostfixExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 112 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 114 "src/analyzer/expression/PostfixExpression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 116 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info == 0) {
            #line 117 "src/analyzer/expression/PostfixExpression.pv"
            Context__error_token(context, member_name, "Expected function type");
            #line 118 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 121 "src/analyzer/expression/PostfixExpression.pv"
        struct Token* name = func_info->parameters.length > 0 ? func_info->parameters.data[0].name : 0;
        #line 122 "src/analyzer/expression/PostfixExpression.pv"
        if (name == 0) {
            #line 122 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 124 "src/analyzer/expression/PostfixExpression.pv"
        if (str__Eq_str__eq(&name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 125 "src/analyzer/expression/PostfixExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = inner });
        }

        #line 128 "src/analyzer/expression/PostfixExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 129 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 130 "src/analyzer/expression/PostfixExpression.pv"
            if (argument == 0) {
                #line 130 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            }
            #line 131 "src/analyzer/expression/PostfixExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

            #line 133 "src/analyzer/expression/PostfixExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 134 "src/analyzer/expression/PostfixExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 135 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            }
        }

        #line 139 "src/analyzer/expression/PostfixExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 139 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 141 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info->generics.array.length > 0) {
            #line 142 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 143 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap combined_generics_val = GenericMap__clone(func_generics, context->allocator);
            #line 144 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap* combined_generics = ArenaAllocator__store_GenericMap(context->allocator, &combined_generics_val);

            #line 146 "src/analyzer/expression/PostfixExpression.pv"
            if (generic_map != 0) {
                #line 147 "src/analyzer/expression/PostfixExpression.pv"
                { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&generic_map->map);
                #line 147 "src/analyzer/expression/PostfixExpression.pv"
                while (HashMapIter_str_usize__next(&__iter)) {
                    #line 147 "src/analyzer/expression/PostfixExpression.pv"
                    struct str name = HashMapIter_str_usize__value(&__iter)->_0;

                    #line 148 "src/analyzer/expression/PostfixExpression.pv"
                    struct Type* concrete_type = GenericMap__get(generic_map, name);
                    #line 149 "src/analyzer/expression/PostfixExpression.pv"
                    if (concrete_type != 0) {
                        #line 150 "src/analyzer/expression/PostfixExpression.pv"
                        if (combined_generics == 0) {
                            #line 150 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }
                        #line 151 "src/analyzer/expression/PostfixExpression.pv"
                        GenericMap__insert(combined_generics, name, *concrete_type);
                    }
                } }
            }

            #line 156 "src/analyzer/expression/PostfixExpression.pv"
            switch (member_type->type) {
                #line 157 "src/analyzer/expression/PostfixExpression.pv"
                case TYPE__FUNCTION: {
                    #line 157 "src/analyzer/expression/PostfixExpression.pv"
                    struct Function* function_info = member_type->function_value._0;
                    #line 158 "src/analyzer/expression/PostfixExpression.pv"
                    struct Type function_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = combined_generics} };
                    #line 159 "src/analyzer/expression/PostfixExpression.pv"
                    member_type = ArenaAllocator__store_Type(context->allocator, &function_type);
                } break;
                #line 161 "src/analyzer/expression/PostfixExpression.pv"
                default: {
                    #line 162 "src/analyzer/expression/PostfixExpression.pv"
                    member_type = Root__make_type_usage(context->root, member_type, &func_generics->array);
                } break;
            }
        }

        #line 167 "src/analyzer/expression/PostfixExpression.pv"
        if ((func_info->type == FUNCTION_TYPE__BUILTIN || func_info->type == FUNCTION_TYPE__METHOD_CPP)) {
            #line 168 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 169 "src/analyzer/expression/PostfixExpression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 171 "src/analyzer/expression/PostfixExpression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 174 "src/analyzer/expression/PostfixExpression.pv"
        if (generic_map != 0) {
            #line 175 "src/analyzer/expression/PostfixExpression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }
        #line 180 "src/analyzer/expression/PostfixExpression.pv"
        struct Expression* result_expr = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
        #line 181 "src/analyzer/expression/PostfixExpression.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 182 "src/analyzer/expression/PostfixExpression.pv"
        if (Expression__build_narrow_path(result_expr, &path)) {
            #line 183 "src/analyzer/expression/PostfixExpression.pv"
            struct Type* narrowed = Context__get_path_narrowing(context, String__as_str(&path));
            #line 184 "src/analyzer/expression/PostfixExpression.pv"
            if (narrowed != 0) {
                #line 185 "src/analyzer/expression/PostfixExpression.pv"
                result_expr->return_type = *narrowed;
            }
        }
        #line 188 "src/analyzer/expression/PostfixExpression.pv"
        return result_expr;
    }
}

#line 192 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 193 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
        #line 193 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 195 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 196 "src/analyzer/expression/PostfixExpression.pv"
    if (index_expr == 0) {
        #line 196 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 198 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]")) {
        #line 198 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 200 "src/analyzer/expression/PostfixExpression.pv"
    switch (index_expr->data.type) {
        #line 201 "src/analyzer/expression/PostfixExpression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 201 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 201 "src/analyzer/expression/PostfixExpression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 202 "src/analyzer/expression/PostfixExpression.pv"
            switch (target->return_type.type) {
                #line 203 "src/analyzer/expression/PostfixExpression.pv"
                case TYPE__ENUM: {
                    #line 203 "src/analyzer/expression/PostfixExpression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 204 "src/analyzer/expression/PostfixExpression.pv"
                    struct Token* enum_name = enum_info->name;
                    #line 205 "src/analyzer/expression/PostfixExpression.pv"
                    if (enum_name != 0 && str__Eq_str__eq(&enum_name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 206 "src/analyzer/expression/PostfixExpression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        }});
                        #line 211 "src/analyzer/expression/PostfixExpression.pv"
                        if (sequence == 0) {
                            #line 211 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }

                        #line 213 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 214 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 216 "src/analyzer/expression/PostfixExpression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 218 "src/analyzer/expression/PostfixExpression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, index_expr->token);
                        #line 219 "src/analyzer/expression/PostfixExpression.pv"
                        if (argument_name_data == 0) {
                            #line 219 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }
                        #line 220 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 221 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 223 "src/analyzer/expression/PostfixExpression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, argument_name_data);
                        #line 224 "src/analyzer/expression/PostfixExpression.pv"
                        if (argument_name_length == 0) {
                            #line 224 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }
                        #line 225 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 227 "src/analyzer/expression/PostfixExpression.pv"
                        if (Expression__is_zero(start)) {
                            #line 228 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 229 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 231 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 236 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 242 "src/analyzer/expression/PostfixExpression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }});
                        #line 243 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 244 "src/analyzer/expression/PostfixExpression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 247 "src/analyzer/expression/PostfixExpression.pv"
                default: {
                } break;
            }
        } break;
        #line 250 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 253 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* index_trait_result = Expression__find_index_trait_call(context, index_expr->token, inner, index_expr);
    #line 254 "src/analyzer/expression/PostfixExpression.pv"
    if (index_trait_result != 0) {
        #line 254 "src/analyzer/expression/PostfixExpression.pv"
        return index_trait_result;
    }

    #line 256 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 257 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* element_type = 0;

    #line 259 "src/analyzer/expression/PostfixExpression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 260 "src/analyzer/expression/PostfixExpression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 261 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__SEQUENCE: {
                #line 261 "src/analyzer/expression/PostfixExpression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 262 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &sequence->element;
            } break;
            #line 264 "src/analyzer/expression/PostfixExpression.pv"
            default: {
            } break;
        }
    } else {
        #line 267 "src/analyzer/expression/PostfixExpression.pv"
        switch (inner_return_type->type) {
            #line 268 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__INDIRECT: {
                #line 268 "src/analyzer/expression/PostfixExpression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 269 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &indirect->to;
            } break;
            #line 271 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__SEQUENCE: {
                #line 271 "src/analyzer/expression/PostfixExpression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 272 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &sequence->element;
            } break;
            #line 274 "src/analyzer/expression/PostfixExpression.pv"
            default: {
            } break;
        }
    }

    #line 278 "src/analyzer/expression/PostfixExpression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 279 "src/analyzer/expression/PostfixExpression.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(context->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "", .length = strlen("") }, .generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 } }});
        #line 280 "src/analyzer/expression/PostfixExpression.pv"
        element_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c }}, context->allocator);
    }

    #line 283 "src/analyzer/expression/PostfixExpression.pv"
    if (element_type == 0) {
        #line 284 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_token(context, index_expr->token, "Type is not indexable");
        #line 285 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 288 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 291 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 292 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* token = Context__current(context);
    #line 293 "src/analyzer/expression/PostfixExpression.pv"
    if (token == 0) {
        #line 293 "src/analyzer/expression/PostfixExpression.pv"
        return inner;
    }

    #line 295 "src/analyzer/expression/PostfixExpression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 296 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "?")) {
        #line 298 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_optional_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 300 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 302 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_index_expression(context, inner, generics);
    } else if (Type__is_function(Type__resolve_typedef_function(&inner->return_type)) && (Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, "("))) {
        #line 304 "src/analyzer/expression/PostfixExpression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 305 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION: {
                #line 305 "src/analyzer/expression/PostfixExpression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 306 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };

                #line 308 "src/analyzer/expression/PostfixExpression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                    #line 309 "src/analyzer/expression/PostfixExpression.pv"
                    parsed_generics = Context__parse_generics(context, generics);
                }

                #line 312 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 312 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 314 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 316 "src/analyzer/expression/PostfixExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 317 "src/analyzer/expression/PostfixExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 318 "src/analyzer/expression/PostfixExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 320 "src/analyzer/expression/PostfixExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 321 "src/analyzer/expression/PostfixExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 322 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                }

                #line 326 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 326 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 328 "src/analyzer/expression/PostfixExpression.pv"
                if (func_info->generics.array.length > 0) {
                    #line 329 "src/analyzer/expression/PostfixExpression.pv"
                    struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                    #line 330 "src/analyzer/expression/PostfixExpression.pv"
                    inner->return_type = *Root__make_type_usage(context->root, &inner->return_type, &func_generics->array);

                    #line 332 "src/analyzer/expression/PostfixExpression.pv"
                    switch (inner->data.type) {
                        #line 333 "src/analyzer/expression/PostfixExpression.pv"
                        case EXPRESSION_DATA__TYPE: {
                            #line 333 "src/analyzer/expression/PostfixExpression.pv"
                            struct Type** type = &inner->data.type_value;
                            #line 334 "src/analyzer/expression/PostfixExpression.pv"
                            *type = &inner->return_type;
                        } break;
                        #line 336 "src/analyzer/expression/PostfixExpression.pv"
                        default: {
                        } break;
                    }
                }

                #line 340 "src/analyzer/expression/PostfixExpression.pv"
                if (!Expression__validate_arguments(context, token, &inner->return_type, &arguments, 0, false)) {
                    #line 340 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 342 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 344 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION_C: {
                #line 344 "src/analyzer/expression/PostfixExpression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 345 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 345 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 347 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 349 "src/analyzer/expression/PostfixExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 350 "src/analyzer/expression/PostfixExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 351 "src/analyzer/expression/PostfixExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 353 "src/analyzer/expression/PostfixExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 354 "src/analyzer/expression/PostfixExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 355 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                }

                #line 359 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 359 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 361 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 363 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__CLASS_CPP: {
                #line 364 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__parse_class(context, token, inner, generics);
            } break;
            #line 366 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__UNKNOWN_C: {
                #line 367 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 367 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 369 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 371 "src/analyzer/expression/PostfixExpression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 372 "src/analyzer/expression/PostfixExpression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 373 "src/analyzer/expression/PostfixExpression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

                    #line 375 "src/analyzer/expression/PostfixExpression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 376 "src/analyzer/expression/PostfixExpression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 377 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                }

                #line 381 "src/analyzer/expression/PostfixExpression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 381 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 383 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &context->root->type_unknown);
            } break;
            #line 385 "src/analyzer/expression/PostfixExpression.pv"
            default: {
                #line 386 "src/analyzer/expression/PostfixExpression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 387 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            } break;
        }
    }

    #line 392 "src/analyzer/expression/PostfixExpression.pv"
    return inner;
}

#line 395 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 396 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* result = inner;
    #line 397 "src/analyzer/expression/PostfixExpression.pv"
    while (true) {
        #line 398 "src/analyzer/expression/PostfixExpression.pv"
        struct Expression* next = Expression__parse_postfix(context, result, generics);
        #line 399 "src/analyzer/expression/PostfixExpression.pv"
        if (next == result) {
            #line 399 "src/analyzer/expression/PostfixExpression.pv"
            break;
        }
        #line 400 "src/analyzer/expression/PostfixExpression.pv"
        if (next == 0) {
            #line 400 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 402 "src/analyzer/expression/PostfixExpression.pv"
        struct Token* expanded_token = ArenaAllocator__store_Token(context->allocator, next->token);
        #line 403 "src/analyzer/expression/PostfixExpression.pv"
        if (expanded_token == 0) {
            #line 403 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }
        #line 404 "src/analyzer/expression/PostfixExpression.pv"
        expanded_token->start_line = result->token->start_line;
        #line 405 "src/analyzer/expression/PostfixExpression.pv"
        expanded_token->start_column = result->token->start_column;
        #line 406 "src/analyzer/expression/PostfixExpression.pv"
        next->token = expanded_token;

        #line 408 "src/analyzer/expression/PostfixExpression.pv"
        result = next;
    }
    #line 410 "src/analyzer/expression/PostfixExpression.pv"
    return result;
}

#line 14 "src/analyzer/expression/BinaryExpression.pv"
bool Expression__build_narrow_path(struct Expression* self, struct String* out) {
    #line 15 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* inner = self;
    #line 16 "src/analyzer/expression/BinaryExpression.pv"
    switch (inner->data.type) {
        #line 17 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 17 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* child = inner->data.parenthesizedexpression_value;
            #line 17 "src/analyzer/expression/BinaryExpression.pv"
            return Expression__build_narrow_path(child, out);
        } break;
        #line 18 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 18 "src/analyzer/expression/BinaryExpression.pv"
            struct str name = inner->data.variable_value;
            #line 19 "src/analyzer/expression/BinaryExpression.pv"
            String__append(out, name);
            #line 20 "src/analyzer/expression/BinaryExpression.pv"
            return true;
        } break;
        #line 22 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 22 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* parent = inner->data.memberinstanceexpression_value._0;
            #line 22 "src/analyzer/expression/BinaryExpression.pv"
            struct str member = inner->data.memberinstanceexpression_value._1;
            #line 23 "src/analyzer/expression/BinaryExpression.pv"
            if (!Expression__build_narrow_path(parent, out)) {
                #line 23 "src/analyzer/expression/BinaryExpression.pv"
                return false;
            }
            #line 24 "src/analyzer/expression/BinaryExpression.pv"
            String__append(out, (struct str){ .ptr = ".", .length = strlen(".") });
            #line 25 "src/analyzer/expression/BinaryExpression.pv"
            String__append(out, member);
            #line 26 "src/analyzer/expression/BinaryExpression.pv"
            return true;
        } break;
        #line 28 "src/analyzer/expression/BinaryExpression.pv"
        default: {
            #line 28 "src/analyzer/expression/BinaryExpression.pv"
            return false;
        } break;
    }
}

#line 36 "src/analyzer/expression/BinaryExpression.pv"
void Expression__collect_null_narrowings(struct Context* context, struct Expression* expr, bool narrow_on_true, struct Array_NullNarrowing* out) {
    #line 37 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* inner = expr;
    #line 38 "src/analyzer/expression/BinaryExpression.pv"
    switch (inner->data.type) {
        #line 39 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 39 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* child = inner->data.parenthesizedexpression_value;
            #line 39 "src/analyzer/expression/BinaryExpression.pv"
            inner = child;
        } break;
        #line 40 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 43 "src/analyzer/expression/BinaryExpression.pv"
    switch (inner->data.type) {
        #line 44 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 44 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* lhs = inner->data.binaryexpression_value._0;
            #line 44 "src/analyzer/expression/BinaryExpression.pv"
            struct str op = inner->data.binaryexpression_value._1;
            #line 44 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* rhs = inner->data.binaryexpression_value._2;
            #line 45 "src/analyzer/expression/BinaryExpression.pv"
            if (str__Eq_str__eq(&op, (struct str){ .ptr = "||", .length = strlen("||") }) && !narrow_on_true) {
                #line 46 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, lhs, false, out);
                #line 47 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, rhs, false, out);
                #line 48 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 50 "src/analyzer/expression/BinaryExpression.pv"
            if (str__Eq_str__eq(&op, (struct str){ .ptr = "&&", .length = strlen("&&") }) && narrow_on_true) {
                #line 51 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, lhs, true, out);
                #line 52 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, rhs, true, out);
                #line 53 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }

            #line 56 "src/analyzer/expression/BinaryExpression.pv"
            struct str want_op = (struct str){ .ptr = narrow_on_true ? "!=" : "==", .length = strlen(narrow_on_true ? "!=" : "==") };
            #line 57 "src/analyzer/expression/BinaryExpression.pv"
            if (!str__Eq_str__eq(&op, want_op)) {
                #line 57 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }

            #line 59 "src/analyzer/expression/BinaryExpression.pv"
            struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 60 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* var_expr = 0;
            #line 61 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* other = 0;

            #line 63 "src/analyzer/expression/BinaryExpression.pv"
            if (Expression__build_narrow_path(lhs, &path)) {
                #line 63 "src/analyzer/expression/BinaryExpression.pv"
                var_expr = lhs;
                #line 63 "src/analyzer/expression/BinaryExpression.pv"
                other = rhs;
            } else {
                #line 65 "src/analyzer/expression/BinaryExpression.pv"
                struct String path2 = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 66 "src/analyzer/expression/BinaryExpression.pv"
                if (Expression__build_narrow_path(rhs, &path2)) {
                    #line 66 "src/analyzer/expression/BinaryExpression.pv"
                    var_expr = rhs;
                    #line 66 "src/analyzer/expression/BinaryExpression.pv"
                    other = lhs;
                    #line 66 "src/analyzer/expression/BinaryExpression.pv"
                    path = path2;
                } else {
                    #line 67 "src/analyzer/expression/BinaryExpression.pv"
                    return;
                }
            }

            #line 70 "src/analyzer/expression/BinaryExpression.pv"
            if (other == 0) {
                #line 70 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 71 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* other_inner = other;
            #line 72 "src/analyzer/expression/BinaryExpression.pv"
            switch (other_inner->data.type) {
                #line 73 "src/analyzer/expression/BinaryExpression.pv"
                case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
                    #line 73 "src/analyzer/expression/BinaryExpression.pv"
                    struct Expression* c = other_inner->data.parenthesizedexpression_value;
                    #line 73 "src/analyzer/expression/BinaryExpression.pv"
                    other_inner = c;
                } break;
                #line 74 "src/analyzer/expression/BinaryExpression.pv"
                default: {
                } break;
            }
            #line 76 "src/analyzer/expression/BinaryExpression.pv"
            if (other_inner == 0) {
                #line 76 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 77 "src/analyzer/expression/BinaryExpression.pv"
            switch (other_inner->data.type) {
                #line 78 "src/analyzer/expression/BinaryExpression.pv"
                case EXPRESSION_DATA__NULL_LITERAL: {
                } break;
                #line 79 "src/analyzer/expression/BinaryExpression.pv"
                default: {
                    #line 79 "src/analyzer/expression/BinaryExpression.pv"
                    return;
                } break;
            }

            #line 82 "src/analyzer/expression/BinaryExpression.pv"
            if (var_expr == 0) {
                #line 82 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 83 "src/analyzer/expression/BinaryExpression.pv"
            switch (var_expr->return_type.type) {
                #line 84 "src/analyzer/expression/BinaryExpression.pv"
                case TYPE__INDIRECT: {
                    #line 84 "src/analyzer/expression/BinaryExpression.pv"
                    struct Indirect* indirect = var_expr->return_type.indirect_value;
                    #line 85 "src/analyzer/expression/BinaryExpression.pv"
                    if (indirect->type != INDIRECT_TYPE__POINTER && indirect->type != INDIRECT_TYPE__CONST_POINTER) {
                        #line 86 "src/analyzer/expression/BinaryExpression.pv"
                        return;
                    }
                    #line 88 "src/analyzer/expression/BinaryExpression.pv"
                    struct Indirect* ref_indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, indirect->to);
                    #line 89 "src/analyzer/expression/BinaryExpression.pv"
                    struct Type type_val = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = ref_indirect };
                    #line 90 "src/analyzer/expression/BinaryExpression.pv"
                    struct Type* stored = ArenaAllocator__store_Type(context->allocator, &type_val);
                    #line 91 "src/analyzer/expression/BinaryExpression.pv"
                    if (stored == 0) {
                        #line 91 "src/analyzer/expression/BinaryExpression.pv"
                        return;
                    }
                    #line 92 "src/analyzer/expression/BinaryExpression.pv"
                    Array_NullNarrowing__append(out, (struct NullNarrowing) { .path = String__as_str(&path), .type = stored });
                } break;
                #line 94 "src/analyzer/expression/BinaryExpression.pv"
                default: {
                } break;
            }
        } break;
        #line 97 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }
}

#line 101 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics) {
    #line 102 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* result = lhs;

    #line 104 "src/analyzer/expression/BinaryExpression.pv"
    while (true) {
        #line 105 "src/analyzer/expression/BinaryExpression.pv"
        struct Token* token = Context__current(context);
        #line 106 "src/analyzer/expression/BinaryExpression.pv"
        uintptr_t prec = Expression__get_precedence(token);
        #line 107 "src/analyzer/expression/BinaryExpression.pv"
        if (prec < min_prec) {
            #line 107 "src/analyzer/expression/BinaryExpression.pv"
            break;
        }

        #line 109 "src/analyzer/expression/BinaryExpression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 110 "src/analyzer/expression/BinaryExpression.pv"
        if (operator == 0) {
            #line 110 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }
        #line 115 "src/analyzer/expression/BinaryExpression.pv"
        bool pushed_narrow_scope = false;
        #line 116 "src/analyzer/expression/BinaryExpression.pv"
        if (str__Eq_str__eq(&operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
            #line 117 "src/analyzer/expression/BinaryExpression.pv"
            bool narrow_on_true_for_rhs = str__Eq_str__eq(&operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });
            #line 118 "src/analyzer/expression/BinaryExpression.pv"
            struct Array_NullNarrowing narrowings = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 119 "src/analyzer/expression/BinaryExpression.pv"
            Expression__collect_null_narrowings(context, result, narrow_on_true_for_rhs, &narrowings);
            #line 120 "src/analyzer/expression/BinaryExpression.pv"
            if (narrowings.length > 0) {
                #line 121 "src/analyzer/expression/BinaryExpression.pv"
                Context__push_scope(context, 0);
                #line 122 "src/analyzer/expression/BinaryExpression.pv"
                { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings);
                #line 122 "src/analyzer/expression/BinaryExpression.pv"
                while (Iter_ref_NullNarrowing__next(&__iter)) {
                    #line 122 "src/analyzer/expression/BinaryExpression.pv"
                    struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

                    #line 123 "src/analyzer/expression/BinaryExpression.pv"
                    Context__set_narrowed(context, narrow->path, narrow->type);
                } }
                #line 125 "src/analyzer/expression/BinaryExpression.pv"
                pushed_narrow_scope = true;
            }
        }

        #line 129 "src/analyzer/expression/BinaryExpression.pv"
        struct Expression* rhs = Expression__parse_primary(context, generics);
        #line 130 "src/analyzer/expression/BinaryExpression.pv"
        if (rhs == 0) {
            #line 130 "src/analyzer/expression/BinaryExpression.pv"
            if (pushed_narrow_scope) {
                #line 130 "src/analyzer/expression/BinaryExpression.pv"
                Context__pop_scope(context);
            }
            #line 130 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 132 "src/analyzer/expression/BinaryExpression.pv"
        struct Expression* rhs_final = Expression__parse_binary(context, rhs, prec + 1, generics);
        #line 133 "src/analyzer/expression/BinaryExpression.pv"
        if (rhs_final == 0) {
            #line 133 "src/analyzer/expression/BinaryExpression.pv"
            if (pushed_narrow_scope) {
                #line 133 "src/analyzer/expression/BinaryExpression.pv"
                Context__pop_scope(context);
            }
            #line 133 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 135 "src/analyzer/expression/BinaryExpression.pv"
        if (pushed_narrow_scope) {
            #line 135 "src/analyzer/expression/BinaryExpression.pv"
            Context__pop_scope(context);
        }

        #line 137 "src/analyzer/expression/BinaryExpression.pv"
        bool is_arithmetic = str__Eq_str__eq(&operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "-", .length = strlen("-") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "/", .length = strlen("/") });

        #line 141 "src/analyzer/expression/BinaryExpression.pv"
        bool is_trait_op = is_arithmetic || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") });

        #line 145 "src/analyzer/expression/BinaryExpression.pv"
        if (is_trait_op) {
            #line 146 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* trait_result = Expression__find_operator_trait_call(context, token, result, &result->return_type, operator->value, rhs_final);
            #line 147 "src/analyzer/expression/BinaryExpression.pv"
            if (trait_result != 0) {
                #line 148 "src/analyzer/expression/BinaryExpression.pv"
                result = trait_result;
                #line 149 "src/analyzer/expression/BinaryExpression.pv"
                continue;
            }
        }

        #line 153 "src/analyzer/expression/BinaryExpression.pv"
        bool is_comparison = str__Eq_str__eq(&operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "!=", .length = strlen("!=") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__Eq_str__eq(&operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });

        #line 159 "src/analyzer/expression/BinaryExpression.pv"
        struct Type* return_type = 0;
        #line 160 "src/analyzer/expression/BinaryExpression.pv"
        if (is_comparison) {
            #line 161 "src/analyzer/expression/BinaryExpression.pv"
            if (!str__Eq_str__eq(&operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) && !str__Eq_str__eq(&operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
                #line 162 "src/analyzer/expression/BinaryExpression.pv"
                if (!Expression__validate_type(result, context, &rhs_final->return_type, false)) {
                    #line 162 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }
                #line 165 "src/analyzer/expression/BinaryExpression.pv"
                switch (rhs_final->data.type) {
                    #line 166 "src/analyzer/expression/BinaryExpression.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 167 "src/analyzer/expression/BinaryExpression.pv"
                        Expression__validate_type(rhs_final, context, &result->return_type, false);
                    } break;
                    #line 169 "src/analyzer/expression/BinaryExpression.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 169 "src/analyzer/expression/BinaryExpression.pv"
                        struct str value = rhs_final->data.literal_value;
                        #line 170 "src/analyzer/expression/BinaryExpression.pv"
                        if (str__Eq_str__eq(&value, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 171 "src/analyzer/expression/BinaryExpression.pv"
                            Expression__validate_type(rhs_final, context, &result->return_type, false);
                        }
                    } break;
                    #line 174 "src/analyzer/expression/BinaryExpression.pv"
                    default: {
                    } break;
                }
            }

            #line 178 "src/analyzer/expression/BinaryExpression.pv"
            return_type = &context->root->type_bool;
        } else {
            #line 180 "src/analyzer/expression/BinaryExpression.pv"
            return_type = &result->return_type;
        }

        #line 183 "src/analyzer/expression/BinaryExpression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = result, ._1 = operator->value, ._2 = rhs_final} }, return_type);
    }

    #line 186 "src/analyzer/expression/BinaryExpression.pv"
    return result;
}

#line 189 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_operator_trait_call(struct Context* context, struct Token* token, struct Expression* lhs, struct Type* lhs_type, struct str operator, struct Expression* rhs) {
    #line 190 "src/analyzer/expression/BinaryExpression.pv"
    struct str trait_name = (struct str){ .ptr = "", .length = strlen("") };
    #line 191 "src/analyzer/expression/BinaryExpression.pv"
    struct str func_name = (struct str){ .ptr = "", .length = strlen("") };

    #line 193 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&operator, (struct str){ .ptr = "*", .length = strlen("*") })) {
        #line 193 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Mul", .length = strlen("Mul") };
        #line 193 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "mul", .length = strlen("mul") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = "+", .length = strlen("+") })) {
        #line 194 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Add", .length = strlen("Add") };
        #line 194 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "add", .length = strlen("add") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 195 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Sub", .length = strlen("Sub") };
        #line 195 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "sub", .length = strlen("sub") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = "/", .length = strlen("/") })) {
        #line 196 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Div", .length = strlen("Div") };
        #line 196 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "div", .length = strlen("div") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = "==", .length = strlen("==") })) {
        #line 197 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Eq", .length = strlen("Eq") };
        #line 197 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "eq", .length = strlen("eq") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = "<", .length = strlen("<") })) {
        #line 198 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 198 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "lt", .length = strlen("lt") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = ">", .length = strlen(">") })) {
        #line 199 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 199 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "gt", .length = strlen("gt") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = "<=", .length = strlen("<=") })) {
        #line 200 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 200 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "le", .length = strlen("le") };
    } else if (str__Eq_str__eq(&operator, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 201 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 201 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "ge", .length = strlen("ge") };
    } else {
        #line 202 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 204 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(lhs_type) || Type__is_unknown(&rhs->return_type)) {
        #line 204 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 206 "src/analyzer/expression/BinaryExpression.pv"
    switch (lhs_type->type) {
        #line 207 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__SELF: {
            #line 208 "src/analyzer/expression/BinaryExpression.pv"
            if (context->type_self != 0) {
                #line 209 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__find_operator_trait_call(context, token, lhs, context->type_self, operator, rhs);
            }
        } break;
        #line 215 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 215 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = lhs_type->struct_value._0;
            #line 215 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = lhs_type->struct_value._1;
            #line 216 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 216 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 216 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 217 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 218 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 218 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 219 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 220 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 220 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 221 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(&impl_trait_name->value, trait_name)) {
                    #line 221 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 223 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &func_name);
                #line 224 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 224 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 225 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 2) {
                    #line 225 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 227 "src/analyzer/expression/BinaryExpression.pv"
                struct Parameter* other_param = Array_Parameter__get(&func->parameters, 1);
                #line 228 "src/analyzer/expression/BinaryExpression.pv"
                if (other_param == 0) {
                    #line 228 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 229 "src/analyzer/expression/BinaryExpression.pv"
                if (!Type__eq(&other_param->type, &rhs->return_type)) {
                    #line 229 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 231 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 232 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 233 "src/analyzer/expression/BinaryExpression.pv"
                    if (generic_map == 0) {
                        #line 233 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 234 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 235 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 236 "src/analyzer/expression/BinaryExpression.pv"
                    if (aug_map == 0) {
                        #line 236 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 237 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 237 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 237 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 237 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 238 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *typedef_type);
                    } }
                    #line 240 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 243 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});
                #line 244 "src/analyzer/expression/BinaryExpression.pv"
                if (func_type == 0) {
                    #line 244 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }

                #line 246 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 247 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = lhs });
                #line 248 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = rhs });

                #line 250 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 253 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__PRIMITIVE: {
            #line 253 "src/analyzer/expression/BinaryExpression.pv"
            struct Primitive* primitive_info = lhs_type->primitive_value;
            #line 254 "src/analyzer/expression/BinaryExpression.pv"
            if (primitive_info == 0) {
                #line 254 "src/analyzer/expression/BinaryExpression.pv"
                return 0;
            }
            #line 255 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 255 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 255 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 256 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 257 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 257 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 258 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 259 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 259 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 260 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(&impl_trait_name->value, trait_name)) {
                    #line 260 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 262 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &func_name);
                #line 263 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 263 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 264 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 2) {
                    #line 264 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 266 "src/analyzer/expression/BinaryExpression.pv"
                struct Parameter* other_param = Array_Parameter__get(&func->parameters, 1);
                #line 267 "src/analyzer/expression/BinaryExpression.pv"
                if (other_param == 0) {
                    #line 267 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 268 "src/analyzer/expression/BinaryExpression.pv"
                if (Type__is_self(&rhs->return_type)) {
                    #line 268 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 269 "src/analyzer/expression/BinaryExpression.pv"
                if (!Type__eq(&other_param->type, &rhs->return_type)) {
                    #line 269 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 271 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = Type__get_generic_map(&impl_info->trait_type, context);

                #line 273 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});

                #line 275 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 276 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = lhs });
                #line 277 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = rhs });

                #line 279 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 282 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 285 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 288 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_unary_trait_call(struct Context* context, struct Token* token, struct Expression* operand) {
    #line 289 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(&operand->return_type)) {
        #line 289 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 291 "src/analyzer/expression/BinaryExpression.pv"
    switch (operand->return_type.type) {
        #line 292 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__SELF: {
            #line 293 "src/analyzer/expression/BinaryExpression.pv"
            if (context->type_self != 0) {
                #line 294 "src/analyzer/expression/BinaryExpression.pv"
                struct Expression concrete_operand = (struct Expression) { .data = operand->data, .return_type = *context->type_self, .token = operand->token };
                #line 295 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__find_unary_trait_call(context, token, &concrete_operand);
            }
        } break;
        #line 298 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 298 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = operand->return_type.struct_value._0;
            #line 298 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = operand->return_type.struct_value._1;
            #line 299 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 299 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 299 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 300 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 301 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 301 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 302 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 303 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 303 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 304 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(&impl_trait_name->value, (struct str){ .ptr = "Neg", .length = strlen("Neg") })) {
                    #line 304 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 306 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &(struct str){ .ptr = "neg", .length = strlen("neg") });
                #line 307 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 307 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 308 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 1) {
                    #line 308 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 310 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 311 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 312 "src/analyzer/expression/BinaryExpression.pv"
                    if (generic_map == 0) {
                        #line 312 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 313 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 314 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 315 "src/analyzer/expression/BinaryExpression.pv"
                    if (aug_map == 0) {
                        #line 315 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 316 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 316 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 316 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 316 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 317 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* resolved = Context__resolve_type(context->allocator, typedef_type, generic_map, 0);
                        #line 318 "src/analyzer/expression/BinaryExpression.pv"
                        if (resolved == 0) {
                            #line 318 "src/analyzer/expression/BinaryExpression.pv"
                            return 0;
                        }
                        #line 319 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *resolved);
                    } }
                    #line 321 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 324 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});
                #line 325 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 326 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = operand });

                #line 328 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 331 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 334 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 337 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_index_trait_call(struct Context* context, struct Token* token, struct Expression* inner, struct Expression* index_expr) {
    #line 338 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(&inner->return_type)) {
        #line 338 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 340 "src/analyzer/expression/BinaryExpression.pv"
    switch (Type__deref_reference(&inner->return_type)->type) {
        #line 341 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 341 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = Type__deref_reference(&inner->return_type)->struct_value._0;
            #line 341 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = Type__deref_reference(&inner->return_type)->struct_value._1;
            #line 342 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 342 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 342 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 343 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 344 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 344 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 345 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 346 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 346 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 347 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(&impl_trait_name->value, (struct str){ .ptr = "Index", .length = strlen("Index") })) {
                    #line 347 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 349 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &(struct str){ .ptr = "index", .length = strlen("index") });
                #line 350 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 350 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 351 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 1) {
                    #line 351 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 353 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 354 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 355 "src/analyzer/expression/BinaryExpression.pv"
                    if (generic_map == 0) {
                        #line 355 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 356 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 357 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 358 "src/analyzer/expression/BinaryExpression.pv"
                    if (aug_map == 0) {
                        #line 358 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 359 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 359 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 359 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 359 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 360 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* resolved = Context__resolve_type(context->allocator, typedef_type, generic_map, 0);
                        #line 361 "src/analyzer/expression/BinaryExpression.pv"
                        if (resolved == 0) {
                            #line 361 "src/analyzer/expression/BinaryExpression.pv"
                            return 0;
                        }
                        #line 362 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *resolved);
                    } }
                    #line 364 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 367 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});
                #line 368 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 369 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = inner });

                #line 371 "src/analyzer/expression/BinaryExpression.pv"
                struct Expression* ptr_expr = Expression__make_type_function_call(context, token, func_type, arguments, 0);
                #line 372 "src/analyzer/expression/BinaryExpression.pv"
                if (ptr_expr == 0) {
                    #line 372 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }

                #line 374 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* element_type = Type__deref(&ptr_expr->return_type);
                #line 375 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = ptr_expr, ._1 = index_expr} }, element_type);
            } }
        } break;
        #line 378 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 381 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 384 "src/analyzer/expression/BinaryExpression.pv"
uintptr_t Expression__get_precedence(struct Token* token) {
    #line 385 "src/analyzer/expression/BinaryExpression.pv"
    if (token->type != TOKEN_TYPE__SYMBOL) {
        #line 385 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 387 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "||", .length = strlen("||") })) {
        #line 387 "src/analyzer/expression/BinaryExpression.pv"
        return 1;
    }
    #line 388 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
        #line 388 "src/analyzer/expression/BinaryExpression.pv"
        return 2;
    }
    #line 389 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "|", .length = strlen("|") })) {
        #line 389 "src/analyzer/expression/BinaryExpression.pv"
        return 3;
    }
    #line 390 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "^", .length = strlen("^") })) {
        #line 390 "src/analyzer/expression/BinaryExpression.pv"
        return 4;
    }
    #line 391 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
        #line 391 "src/analyzer/expression/BinaryExpression.pv"
        return 5;
    }
    #line 392 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "!=", .length = strlen("!=") })) {
        #line 392 "src/analyzer/expression/BinaryExpression.pv"
        return 6;
    }
    #line 393 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 393 "src/analyzer/expression/BinaryExpression.pv"
        return 7;
    }
    #line 394 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "<<", .length = strlen("<<") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = ">>", .length = strlen(">>") })) {
        #line 394 "src/analyzer/expression/BinaryExpression.pv"
        return 8;
    }
    #line 395 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 395 "src/analyzer/expression/BinaryExpression.pv"
        return 9;
    }
    #line 396 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(&token->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "/", .length = strlen("/") }) || str__Eq_str__eq(&token->value, (struct str){ .ptr = "%", .length = strlen("%") })) {
        #line 396 "src/analyzer/expression/BinaryExpression.pv"
        return 10;
    }

    #line 398 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}
