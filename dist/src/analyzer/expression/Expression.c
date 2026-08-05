#include <stdint.h>
#include <string.h>

#include <stdlib.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/TokenBounds.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Array_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <analyzer/Context.h>
#include <std/str.h>
#include <analyzer/TokenType.h>
#include <analyzer/Module.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Trait.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Global.h>
#include <std/Array_Type.h>
#include <std/trait_Allocator.h>
#include <analyzer/expression/ParsedArguments.h>
#include <std/Array_Generic.h>
#include <analyzer/types/GenericMap.h>
#include <std/Array_Position.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/Tuple.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/types/IndirectType.h>
#include <std/Array_NullNarrowing.h>
#include <std/Iter_ref_NullNarrowing.h>
#include <analyzer/expression/NullNarrowing.h>
#include <std/Array_str.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <usize.h>
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
#include <std/HashMap_str_Type.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/types/FunctionParent.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/StructCField.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/ClassCpp.h>
#include <std/Iter_ref_Type.h>
#include <std/HashMapIter_str_usize.h>
#include <tuple_str_usize.h>
#include <analyzer/types/GenericTypedef.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/Iter_ref_Generic.h>
#include <std/HashMap_str_ref_Trait.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/HashMapBucket_str_StructField.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/Position.h>
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
struct TokenBounds Expression__get_token_bounds(struct Expression* self) {
    #line 24 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 25 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 25 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 25 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 26 "src/analyzer/expression/Expression.pv"
            struct TokenBounds lhs_bounds = Expression__get_token_bounds(lhs);
            #line 27 "src/analyzer/expression/Expression.pv"
            struct TokenBounds rhs_bounds = Expression__get_token_bounds(rhs);
            #line 28 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(lhs_bounds.first, rhs_bounds.last);
        } break;
        #line 30 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 30 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 31 "src/analyzer/expression/Expression.pv"
            struct TokenBounds inner_bounds = Expression__get_token_bounds(inner);
            #line 32 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(self->token, inner_bounds.last);
        } break;
        #line 34 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 34 "src/analyzer/expression/Expression.pv"
            struct Expression* otherwise = self->data.ifexpression_value._2;
            #line 35 "src/analyzer/expression/Expression.pv"
            struct TokenBounds otherwise_bounds = Expression__get_token_bounds(otherwise);
            #line 36 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(self->token, otherwise_bounds.last);
        } break;
        #line 38 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 38 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.optionalexpression_value._0;
            #line 38 "src/analyzer/expression/Expression.pv"
            struct Expression* value = self->data.optionalexpression_value._1;
            #line 39 "src/analyzer/expression/Expression.pv"
            struct TokenBounds inner_bounds = Expression__get_token_bounds(inner);
            #line 40 "src/analyzer/expression/Expression.pv"
            struct TokenBounds value_bounds = Expression__get_token_bounds(value);
            #line 41 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(inner_bounds.first, value_bounds.last);
        } break;
        #line 43 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 43 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.memberstaticexpression_value._0;
            #line 44 "src/analyzer/expression/Expression.pv"
            struct TokenBounds inner_bounds = Expression__get_token_bounds(inner);
            #line 45 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(inner_bounds.first, self->token);
        } break;
        #line 47 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 47 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.memberinstanceexpression_value._0;
            #line 48 "src/analyzer/expression/Expression.pv"
            struct TokenBounds inner_bounds = Expression__get_token_bounds(inner);
            #line 49 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(inner_bounds.first, self->token);
        } break;
        #line 51 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 51 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.indexexpression_value._0;
            #line 51 "src/analyzer/expression/Expression.pv"
            struct Expression* index = self->data.indexexpression_value._1;
            #line 52 "src/analyzer/expression/Expression.pv"
            struct TokenBounds inner_bounds = Expression__get_token_bounds(inner);
            #line 53 "src/analyzer/expression/Expression.pv"
            struct TokenBounds index_bounds = Expression__get_token_bounds(index);
            #line 54 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(inner_bounds.first, index_bounds.last);
        } break;
        #line 56 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 56 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 57 "src/analyzer/expression/Expression.pv"
            struct TokenBounds inner_bounds = Expression__get_token_bounds(inner);
            #line 58 "src/analyzer/expression/Expression.pv"
            return TokenBounds__new(self->token, inner_bounds.last);
        } break;
        #line 60 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 60 "src/analyzer/expression/Expression.pv"
            struct CppExpression cpp = self->data.cppexpression_value;
            #line 61 "src/analyzer/expression/Expression.pv"
            switch (cpp.type) {
                #line 62 "src/analyzer/expression/Expression.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 62 "src/analyzer/expression/Expression.pv"
                    struct Expression* placement = cpp.new_value.placement;
                    #line 62 "src/analyzer/expression/Expression.pv"
                    struct Expression* new_expression = cpp.new_value.expression;
                    #line 63 "src/analyzer/expression/Expression.pv"
                    struct TokenBounds expression_bounds = Expression__get_token_bounds(new_expression);
                    #line 64 "src/analyzer/expression/Expression.pv"
                    struct Token* last = expression_bounds.last;
                    #line 65 "src/analyzer/expression/Expression.pv"
                    if (placement != 0) {
                        #line 66 "src/analyzer/expression/Expression.pv"
                        last = expression_bounds.last;
                    }
                    #line 68 "src/analyzer/expression/Expression.pv"
                    return TokenBounds__new(self->token, last);
                } break;
                #line 70 "src/analyzer/expression/Expression.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 70 "src/analyzer/expression/Expression.pv"
                    struct Expression* delete_expression = cpp.delete_value;
                    #line 71 "src/analyzer/expression/Expression.pv"
                    struct TokenBounds expression_bounds = Expression__get_token_bounds(delete_expression);
                    #line 72 "src/analyzer/expression/Expression.pv"
                    return TokenBounds__new(self->token, expression_bounds.last);
                } break;
            }
        } break;
        #line 76 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 76 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.implicitcast_value;
            #line 77 "src/analyzer/expression/Expression.pv"
            return Expression__get_token_bounds(inner);
        } break;
        #line 79 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 79 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 79 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument arguments = self->data.invoke_value._1;
            #line 80 "src/analyzer/expression/Expression.pv"
            struct TokenBounds bounds = Expression__get_token_bounds(target);
            #line 81 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 81 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 81 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* argument = Iter_ref_InvokeArgument__value(&__iter);

                #line 82 "src/analyzer/expression/Expression.pv"
                struct TokenBounds argument_bounds = Expression__get_token_bounds(argument->value);
                #line 83 "src/analyzer/expression/Expression.pv"
                TokenBounds__include(&bounds, argument_bounds);
            } }
            #line 85 "src/analyzer/expression/Expression.pv"
            return bounds;
        } break;
        #line 87 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 90 "src/analyzer/expression/Expression.pv"
    return TokenBounds__new(self->token, self->token);
}

#line 93 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node) {
    #line 94 "src/analyzer/expression/Expression.pv"
    struct Expression* result = ArenaAllocator__store_Expression(context->allocator, &node);

    #line 96 "src/analyzer/expression/Expression.pv"
    Context__next_token(context);

    #line 98 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 101 "src/analyzer/expression/Expression.pv"
struct str Expression__number_primitive(struct str value) {
    #line 102 "src/analyzer/expression/Expression.pv"
    if (str__ends_with(value, "f") || str__ends_with(value, "F")) {
        #line 103 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f32", .length = strlen("f32") };
    } else if (str__ends_with(value, "u") || str__ends_with(value, "U")) {
        #line 105 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "u32", .length = strlen("u32") };
    } else if (str__contains(value, ".")) {
        #line 107 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f64", .length = strlen("f64") };
    }
    #line 109 "src/analyzer/expression/Expression.pv"
    return (struct str){ .ptr = "i32", .length = strlen("i32") };
}

#line 112 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics) {
    #line 113 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 114 "src/analyzer/expression/Expression.pv"
    if (token == 0) {
        #line 115 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Unexpected end of input");
        #line 116 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 119 "src/analyzer/expression/Expression.pv"
    enum TokenType token_type = token->type;
    #line 120 "src/analyzer/expression/Expression.pv"
    struct Expression* result = 0;

    #line 122 "src/analyzer/expression/Expression.pv"
    switch (token_type) {
        #line 123 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 124 "src/analyzer/expression/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 126 "src/analyzer/expression/Expression.pv"
            if (context->module->mode_cpp && (str__Eq_str__eq(token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 127 "src/analyzer/expression/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 129 "src/analyzer/expression/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 130 "src/analyzer/expression/Expression.pv"
                if (type != 0) {
                    #line 132 "src/analyzer/expression/Expression.pv"
                    if (Context__should_record_symbols(context)) {
                        #line 133 "src/analyzer/expression/Expression.pv"
                        struct Token* type_def_token = 0;
                        #line 134 "src/analyzer/expression/Expression.pv"
                        struct str type_def_path = context->path;
                        #line 135 "src/analyzer/expression/Expression.pv"
                        switch (Type__resolve_typedef(type)->type) {
                            #line 136 "src/analyzer/expression/Expression.pv"
                            case TYPE__STRUCT: {
                                #line 136 "src/analyzer/expression/Expression.pv"
                                struct Struct* struct_info = Type__resolve_typedef(type)->struct_value._0;
                                #line 136 "src/analyzer/expression/Expression.pv"
                                type_def_token = struct_info->name;
                                #line 136 "src/analyzer/expression/Expression.pv"
                                type_def_path = struct_info->module->path;
                            } break;
                            #line 137 "src/analyzer/expression/Expression.pv"
                            case TYPE__ENUM: {
                                #line 137 "src/analyzer/expression/Expression.pv"
                                struct Enum* enum_info = Type__resolve_typedef(type)->enum_value._0;
                                #line 137 "src/analyzer/expression/Expression.pv"
                                type_def_token = enum_info->name;
                                #line 137 "src/analyzer/expression/Expression.pv"
                                type_def_path = enum_info->context->path;
                            } break;
                            #line 138 "src/analyzer/expression/Expression.pv"
                            case TYPE__TRAIT: {
                                #line 138 "src/analyzer/expression/Expression.pv"
                                struct Trait* trait_info = Type__resolve_typedef(type)->trait_value._0;
                                #line 138 "src/analyzer/expression/Expression.pv"
                                type_def_token = trait_info->name;
                                #line 138 "src/analyzer/expression/Expression.pv"
                                type_def_path = trait_info->module->path;
                            } break;
                            #line 139 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                        #line 141 "src/analyzer/expression/Expression.pv"
                        if (type_def_token != 0) {
                            #line 142 "src/analyzer/expression/Expression.pv"
                            struct String type_label_str = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
                            #line 143 "src/analyzer/expression/Expression.pv"
                            Context__record_symbol(context, token, String__as_str(&type_label_str), type_def_path, type_def_token);
                        }
                    }

                    #line 147 "src/analyzer/expression/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 148 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM: {
                            #line 148 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 149 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 149 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 150 "src/analyzer/expression/Expression.pv"
                        case TYPE__SELF: {
                            #line 150 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 151 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 151 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 152 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 152 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 153 "src/analyzer/expression/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 153 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 154 "src/analyzer/expression/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 154 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 155 "src/analyzer/expression/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 155 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 156 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 156 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 159 "src/analyzer/expression/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 160 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                        .data = (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = (struct str) { .ptr = 0, .length = 0 } },
                    });

                    #line 166 "src/analyzer/expression/Expression.pv"
                    if (result == 0) {
                        #line 166 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                    #line 167 "src/analyzer/expression/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 169 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 170 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            } else {
                #line 174 "src/analyzer/expression/Expression.pv"
                if (Context__should_record_symbols(context)) {
                    #line 175 "src/analyzer/expression/Expression.pv"
                    struct String type_label = Naming__get_type_decl(&context->root->naming_decl, return_type, context->type_self, 0);
                    #line 176 "src/analyzer/expression/Expression.pv"
                    struct Token* def_token = Context__get_definition_token(context, token->value);
                    #line 177 "src/analyzer/expression/Expression.pv"
                    struct str def_path = context->path;
                    #line 178 "src/analyzer/expression/Expression.pv"
                    if (def_token == 0) {
                        #line 180 "src/analyzer/expression/Expression.pv"
                        switch (return_type->type) {
                            #line 181 "src/analyzer/expression/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 181 "src/analyzer/expression/Expression.pv"
                                struct Function* func_info = return_type->function_value._0;
                                #line 182 "src/analyzer/expression/Expression.pv"
                                def_token = func_info->name;
                                #line 183 "src/analyzer/expression/Expression.pv"
                                if (func_info->context != 0) {
                                    #line 183 "src/analyzer/expression/Expression.pv"
                                    def_path = func_info->context->path;
                                }
                            } break;
                            #line 185 "src/analyzer/expression/Expression.pv"
                            case TYPE__GLOBAL: {
                                #line 185 "src/analyzer/expression/Expression.pv"
                                struct Global* global_info = return_type->global_value;
                                #line 186 "src/analyzer/expression/Expression.pv"
                                def_token = global_info->name;
                                #line 187 "src/analyzer/expression/Expression.pv"
                                def_path = global_info->module->path;
                            } break;
                            #line 189 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                    }
                    #line 192 "src/analyzer/expression/Expression.pv"
                    Context__record_symbol(context, token, String__as_str(&type_label), def_path, def_token);
                }

                #line 195 "src/analyzer/expression/Expression.pv"
                switch (return_type->type) {
                    #line 196 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 196 "src/analyzer/expression/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 197 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 198 "src/analyzer/expression/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 199 "src/analyzer/expression/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };

                        #line 201 "src/analyzer/expression/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 202 "src/analyzer/expression/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 205 "src/analyzer/expression/Expression.pv"
                        struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                        #line 206 "src/analyzer/expression/Expression.pv"
                        if (parsed == 0) {
                            #line 206 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                        #line 207 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = parsed->arguments;

                        #line 209 "src/analyzer/expression/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 210 "src/analyzer/expression/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 211 "src/analyzer/expression/Expression.pv"
                            func_type = Root__make_type_usage(context->root, func_type, &func_generics->array);
                        }

                        #line 214 "src/analyzer/expression/Expression.pv"
                        if (parsed->open_paren != 0 && parsed->close_paren != 0) {
                            #line 215 "src/analyzer/expression/Expression.pv"
                            Expression__record_function_signature(context, func_type, parsed->open_paren, parsed->close_paren, parsed->comma_positions, false);
                        }

                        #line 218 "src/analyzer/expression/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 218 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 220 "src/analyzer/expression/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 221 "src/analyzer/expression/Expression.pv"
                        switch (func_type->type) {
                            #line 222 "src/analyzer/expression/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 222 "src/analyzer/expression/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 223 "src/analyzer/expression/Expression.pv"
                                switch (func_info->type) {
                                    #line 224 "src/analyzer/expression/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 225 "src/analyzer/expression/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} }});
                                    } break;
                                    #line 227 "src/analyzer/expression/Expression.pv"
                                    default: {
                                        #line 228 "src/analyzer/expression/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 232 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 235 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 236 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 238 "src/analyzer/expression/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 239 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 240 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 242 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 243 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 244 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 246 "src/analyzer/expression/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 247 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 248 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 250 "src/analyzer/expression/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 251 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 252 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 254 "src/analyzer/expression/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 255 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 256 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 258 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM: {
                        #line 259 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 260 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 262 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 263 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 264 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 266 "src/analyzer/expression/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 267 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 268 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 270 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 271 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 272 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 274 "src/analyzer/expression/Expression.pv"
                    case TYPE__SELF: {
                        #line 275 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 276 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 278 "src/analyzer/expression/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 279 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 280 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 282 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 283 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 284 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 286 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 287 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 288 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 290 "src/analyzer/expression/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 291 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 292 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 294 "src/analyzer/expression/Expression.pv"
                    case TYPE__GLOBAL: {
                        #line 295 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 296 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 298 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 299 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 300 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 302 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 302 "src/analyzer/expression/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 303 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 304 "src/analyzer/expression/Expression.pv"
                        struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                        #line 305 "src/analyzer/expression/Expression.pv"
                        if (parsed == 0) {
                            #line 305 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 307 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 309 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = parsed->arguments} }, &func_info->return_type);
                    } break;
                    #line 311 "src/analyzer/expression/Expression.pv"
                    default: {
                        #line 312 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 317 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 318 "src/analyzer/expression/Expression.pv"
            struct Type return_type = str__starts_with(token->value, (struct str){ .ptr = "'", .length = strlen("'") }) ? context->type_char : (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char };

            #line 320 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = return_type,
            });
        } break;
        #line 326 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 327 "src/analyzer/expression/Expression.pv"
            struct str primitive = Expression__number_primitive(token->value);
            #line 328 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 334 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 335 "src/analyzer/expression/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 336 "src/analyzer/expression/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 337 "src/analyzer/expression/Expression.pv"
                if (operator == 0) {
                    #line 337 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 339 "src/analyzer/expression/Expression.pv"
                if (str__Eq_str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 340 "src/analyzer/expression/Expression.pv"
                    context->pos -= 1;
                    #line 341 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 342 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 344 "src/analyzer/expression/Expression.pv"
                    struct Expression* child = Expression__parse_primary(context, generics);
                    #line 345 "src/analyzer/expression/Expression.pv"
                    if (child == 0) {
                        #line 345 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 347 "src/analyzer/expression/Expression.pv"
                    if (str__Eq_str__eq(operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 348 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 349 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 349 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 350 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) }});
                                #line 351 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 353 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 354 "src/analyzer/expression/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 355 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__Eq_str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 359 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 360 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 360 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 361 "src/analyzer/expression/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 362 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect }});
                                #line 363 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 365 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 366 "src/analyzer/expression/Expression.pv"
                                struct Type* deref_target = Type__resolve_typedef(&child->return_type);
                                #line 367 "src/analyzer/expression/Expression.pv"
                                if (!Type__is_indirect(deref_target) && !Type__is_unknown(deref_target)) {
                                    #line 368 "src/analyzer/expression/Expression.pv"
                                    Context__error_token(context, token, "Cannot dereference a non-reference or non-pointer type");
                                    #line 369 "src/analyzer/expression/Expression.pv"
                                    return 0;
                                }
                                #line 371 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 375 "src/analyzer/expression/Expression.pv"
                        if (str__Eq_str__eq(operator->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
                            #line 376 "src/analyzer/expression/Expression.pv"
                            struct Expression* trait_result = Expression__find_unary_trait_call(context, operator, child);
                            #line 377 "src/analyzer/expression/Expression.pv"
                            if (trait_result != 0) {
                                #line 378 "src/analyzer/expression/Expression.pv"
                                result = trait_result;
                            } else {
                                #line 380 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                            }
                        } else {
                            #line 383 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                        }
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 388 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 388 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 390 "src/analyzer/expression/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 391 "src/analyzer/expression/Expression.pv"
                if (expr == 0) {
                    #line 391 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 393 "src/analyzer/expression/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 394 "src/analyzer/expression/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 396 "src/analyzer/expression/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, expr->token);
                    #line 397 "src/analyzer/expression/Expression.pv"
                    if (name == 0) {
                        #line 398 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Failed to allocate token for tuple argument name");
                        #line 399 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 402 "src/analyzer/expression/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 404 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 406 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 407 "src/analyzer/expression/Expression.pv"
                        struct String name_string = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 408 "src/analyzer/expression/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 409 "src/analyzer/expression/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 411 "src/analyzer/expression/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, Context__current(context));
                        #line 412 "src/analyzer/expression/Expression.pv"
                        if (name == 0) {
                            #line 413 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Failed to allocate token for tuple argument name");
                            #line 414 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                        #line 416 "src/analyzer/expression/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 418 "src/analyzer/expression/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 419 "src/analyzer/expression/Expression.pv"
                        if (value == 0) {
                            #line 419 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 421 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 423 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 424 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 425 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 429 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple[]){(struct Tuple) { .elements = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) }});
                    #line 430 "src/analyzer/expression/Expression.pv"
                    if (tuple == 0) {
                        #line 431 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Failed to allocate tuple type");
                        #line 432 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                    #line 434 "src/analyzer/expression/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 435 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 435 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 435 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 435 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 436 "src/analyzer/expression/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 439 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }}), arguments, 0);
                } else {
                    #line 441 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 441 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 443 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 446 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
                    #line 446 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 448 "src/analyzer/expression/Expression.pv"
                struct Type* element_type = 0;
                #line 449 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 451 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 452 "src/analyzer/expression/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 453 "src/analyzer/expression/Expression.pv"
                    if (element == 0) {
                        #line 453 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 455 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .name = 0, .value = element });

                    #line 457 "src/analyzer/expression/Expression.pv"
                    if (element_type == 0) {
                        #line 458 "src/analyzer/expression/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 461 "src/analyzer/expression/Expression.pv"
                    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
                        #line 462 "src/analyzer/expression/Expression.pv"
                        struct Token* count_token = Context__expect(context, TOKEN_TYPE__NUMBER);
                        #line 463 "src/analyzer/expression/Expression.pv"
                        if (count_token == 0) {
                            #line 463 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                        #line 464 "src/analyzer/expression/Expression.pv"
                        uintptr_t count = strtoul(count_token->value.ptr, 0, 10);
                        #line 465 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = 1;
                        #line 466 "src/analyzer/expression/Expression.pv"
                        while (i < count) {
                            #line 467 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .name = 0, .value = element });
                            #line 468 "src/analyzer/expression/Expression.pv"
                            i += 1;
                        }
                        #line 470 "src/analyzer/expression/Expression.pv"
                        break;
                    }

                    #line 473 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 474 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 475 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 479 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 481 "src/analyzer/expression/Expression.pv"
                if (element_type == 0) {
                    #line 481 "src/analyzer/expression/Expression.pv"
                    element_type = &context->root->type_void;
                }
                #line 482 "src/analyzer/expression/Expression.pv"
                struct String length_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 483 "src/analyzer/expression/Expression.pv"
                String__append_usize(&length_str, elements.length);
                #line 484 "src/analyzer/expression/Expression.pv"
                struct Token length_token_val = (struct Token) { .type = TOKEN_TYPE__NUMBER, .value = String__as_str(&length_str), .start_line = token->start_line, .start_column = token->start_column, .end_line = token->end_line, .end_column = token->end_column };
                #line 485 "src/analyzer/expression/Expression.pv"
                struct Token* length_token = ArenaAllocator__store_Token(context->allocator, &length_token_val);
                #line 486 "src/analyzer/expression/Expression.pv"
                struct Type length_primitive = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "usize", .length = strlen("usize") }) };
                #line 487 "src/analyzer/expression/Expression.pv"
                struct Expression* length_expression = Expression__make(context->allocator, length_token, (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = String__as_str(&length_str) }, &length_primitive);
                #line 488 "src/analyzer/expression/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = length_expression }, .element = *element_type, .element_pointer = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }});
                #line 489 "src/analyzer/expression/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence }});
                #line 490 "src/analyzer/expression/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 492 "src/analyzer/expression/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 494 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 497 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 498 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 499 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "bool", .length = strlen("bool") }) },
                });
            } else if (str__Eq_str__eq(token->value, (struct str){ .ptr = "null", .length = strlen("null") })) {
                #line 505 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__NULL_LITERAL },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "i32", .length = strlen("i32") }) },
                });
            } else if (str__Eq_str__eq(token->value, (struct str){ .ptr = "if", .length = strlen("if") })) {
                #line 511 "src/analyzer/expression/Expression.pv"
                result = Expression__parse_if_expression(context, generics);
            } else {
                #line 513 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 516 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 517 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 521 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 521 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 523 "src/analyzer/expression/Expression.pv"
    return Expression__parse_postfix_chain(context, result, generics);
}

#line 526 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 527 "src/analyzer/expression/Expression.pv"
    struct Expression* result = Expression__parse_primary(context, generics);
    #line 528 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 528 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 530 "src/analyzer/expression/Expression.pv"
    result = Expression__parse_binary(context, result, 1, generics);
    #line 531 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 531 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 533 "src/analyzer/expression/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 534 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 536 "src/analyzer/expression/Expression.pv"
        struct Expression* range_start = result;
        #line 537 "src/analyzer/expression/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 538 "src/analyzer/expression/Expression.pv"
        if (range_end == 0) {
            #line 538 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 540 "src/analyzer/expression/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, (struct Array_Type[]){(struct Array_Type) { .data = &range_end->return_type, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .capacity = 0 }});
        #line 541 "src/analyzer/expression/Expression.pv"
        if (enum_type == 0) {
            #line 542 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 543 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 546 "src/analyzer/expression/Expression.pv"
        struct Token variant_name = *token;
        #line 547 "src/analyzer/expression/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 548 "src/analyzer/expression/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 550 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 551 "src/analyzer/expression/Expression.pv"
        struct EnumVariant* variant = 0;
        #line 552 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 553 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 553 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* enum_variant = variant_result.enumvariant_value;
                #line 553 "src/analyzer/expression/Expression.pv"
                variant = enum_variant;
            } break;
            #line 554 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
        #line 556 "src/analyzer/expression/Expression.pv"
        if (variant == 0) {
            #line 557 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range StartEnd enum variant");
            #line 558 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 561 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 562 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = range_start });
        #line 563 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = range_end });

        #line 565 "src/analyzer/expression/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 567 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 570 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 573 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 574 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 575 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 575 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 575 "src/analyzer/expression/Expression.pv"
            return str__Eq_str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 576 "src/analyzer/expression/Expression.pv"
        default: {
            #line 576 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 580 "src/analyzer/expression/Expression.pv"
bool Expression__is_const_expression(struct Expression* self, struct Context* context) {
    #line 581 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 582 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 582 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 583 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 583 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 584 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(inner, context);
        } break;
        #line 586 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 586 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.unaryexpression_value._0;
            #line 586 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 587 "src/analyzer/expression/Expression.pv"
            if (!str__Eq_str__eq(op, (struct str){ .ptr = "-", .length = strlen("-") }) && !str__Eq_str__eq(op, (struct str){ .ptr = "+", .length = strlen("+") })) {
                #line 587 "src/analyzer/expression/Expression.pv"
                return false;
            }
            #line 588 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(inner, context);
        } break;
        #line 590 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 590 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 590 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.binaryexpression_value._1;
            #line 590 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 591 "src/analyzer/expression/Expression.pv"
            if (!str__Eq_str__eq(op, (struct str){ .ptr = "+", .length = strlen("+") }) && !str__Eq_str__eq(op, (struct str){ .ptr = "-", .length = strlen("-") }) && !str__Eq_str__eq(op, (struct str){ .ptr = "*", .length = strlen("*") }) && !str__Eq_str__eq(op, (struct str){ .ptr = "/", .length = strlen("/") }) && !str__Eq_str__eq(op, (struct str){ .ptr = "%", .length = strlen("%") })) {
                #line 591 "src/analyzer/expression/Expression.pv"
                return false;
            }
            #line 592 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(lhs, context) && Expression__is_const_expression(rhs, context);
        } break;
        #line 594 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 594 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 595 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 595 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 595 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument arguments = self->data.invoke_value._1;
            #line 596 "src/analyzer/expression/Expression.pv"
            if (arguments.length != 0) {
                #line 596 "src/analyzer/expression/Expression.pv"
                return false;
            }
            #line 597 "src/analyzer/expression/Expression.pv"
            return Expression__is_const_expression(target, context);
        } break;
        #line 599 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 600 "src/analyzer/expression/Expression.pv"
            switch (self->return_type.type) {
                #line 601 "src/analyzer/expression/Expression.pv"
                case TYPE__ENUM_C: {
                    #line 601 "src/analyzer/expression/Expression.pv"
                    return true;
                } break;
                #line 602 "src/analyzer/expression/Expression.pv"
                default: {
                    #line 602 "src/analyzer/expression/Expression.pv"
                    return false;
                } break;
            }
        } break;
        #line 605 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 605 "src/analyzer/expression/Expression.pv"
            struct str name = self->data.variable_value;
            #line 606 "src/analyzer/expression/Expression.pv"
            switch (self->return_type.type) {
                #line 607 "src/analyzer/expression/Expression.pv"
                case TYPE__ENUM_C: {
                    #line 607 "src/analyzer/expression/Expression.pv"
                    return true;
                } break;
                #line 608 "src/analyzer/expression/Expression.pv"
                case TYPE__UNKNOWN_C: {
                    #line 609 "src/analyzer/expression/Expression.pv"
                    return Module__find_macro_value(context->module, name) != 0;
                } break;
                #line 611 "src/analyzer/expression/Expression.pv"
                default: {
                    #line 611 "src/analyzer/expression/Expression.pv"
                    return false;
                } break;
            }
        } break;
        #line 614 "src/analyzer/expression/Expression.pv"
        default: {
            #line 614 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 618 "src/analyzer/expression/Expression.pv"
void Expression__append_ident_name(struct Expression* self, struct String* result) {
    #line 619 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 620 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 620 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 621 "src/analyzer/expression/Expression.pv"
            uintptr_t i = 0;
            #line 622 "src/analyzer/expression/Expression.pv"
            while (i < value.length) {
                #line 623 "src/analyzer/expression/Expression.pv"
                char c = value.ptr[i];
                #line 624 "src/analyzer/expression/Expression.pv"
                if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    #line 625 "src/analyzer/expression/Expression.pv"
                    String__append_char(result, c);
                } else {
                    #line 627 "src/analyzer/expression/Expression.pv"
                    String__append_char(result, '_');
                }
                #line 629 "src/analyzer/expression/Expression.pv"
                i += 1;
            }
        } break;
        #line 632 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 632 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 633 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(inner, result);
        } break;
        #line 635 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 635 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.unaryexpression_value._0;
            #line 635 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 636 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(op, (struct str){ .ptr = "-", .length = strlen("-") })) {
                #line 636 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "neg_", .length = strlen("neg_") });
            }
            #line 637 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(inner, result);
        } break;
        #line 639 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 639 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 639 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.binaryexpression_value._1;
            #line 639 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 640 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(lhs, result);
            #line 641 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(op, (struct str){ .ptr = "+", .length = strlen("+") })) {
                #line 641 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_add_", .length = strlen("_add_") });
            } else if (str__Eq_str__eq(op, (struct str){ .ptr = "-", .length = strlen("-") })) {
                #line 642 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_sub_", .length = strlen("_sub_") });
            } else if (str__Eq_str__eq(op, (struct str){ .ptr = "*", .length = strlen("*") })) {
                #line 643 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_mul_", .length = strlen("_mul_") });
            } else if (str__Eq_str__eq(op, (struct str){ .ptr = "/", .length = strlen("/") })) {
                #line 644 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_div_", .length = strlen("_div_") });
            } else if (str__Eq_str__eq(op, (struct str){ .ptr = "%", .length = strlen("%") })) {
                #line 645 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_mod_", .length = strlen("_mod_") });
            } else {
                #line 646 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "_op_", .length = strlen("_op_") });
            }
            #line 647 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(rhs, result);
        } break;
        #line 649 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 649 "src/analyzer/expression/Expression.pv"
            struct EnumVariant* variant = self->data.enumvariant_value;
            #line 650 "src/analyzer/expression/Expression.pv"
            struct Token* name = variant->parent->name;
            #line 651 "src/analyzer/expression/Expression.pv"
            if (name != 0) {
                #line 652 "src/analyzer/expression/Expression.pv"
                String__append(result, name->value);
            } else {
                #line 654 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "unknown_enum", .length = strlen("unknown_enum") });
            }

            #line 657 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 658 "src/analyzer/expression/Expression.pv"
            String__append(result, variant->name->value);
        } break;
        #line 660 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 660 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 661 "src/analyzer/expression/Expression.pv"
            Expression__append_ident_name(target, result);
        } break;
        #line 663 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 663 "src/analyzer/expression/Expression.pv"
            struct str member_name = self->data.memberstaticexpression_value._1;
            #line 664 "src/analyzer/expression/Expression.pv"
            String__append(result, member_name);
        } break;
        #line 666 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 666 "src/analyzer/expression/Expression.pv"
            struct str name = self->data.variable_value;
            #line 667 "src/analyzer/expression/Expression.pv"
            String__append(result, name);
        } break;
        #line 669 "src/analyzer/expression/Expression.pv"
        default: {
            #line 670 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "expr", .length = strlen("expr") });
        } break;
    }
}

#line 675 "src/analyzer/expression/Expression.pv"
void Expression__append_display_name(struct Expression* self, struct String* result) {
    #line 676 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 677 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 677 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 678 "src/analyzer/expression/Expression.pv"
            String__append(result, value);
        } break;
        #line 680 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 680 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.parenthesizedexpression_value;
            #line 681 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "(", .length = strlen("(") });
            #line 682 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(inner, result);
            #line 683 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = ")", .length = strlen(")") });
        } break;
        #line 685 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 685 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.unaryexpression_value._0;
            #line 685 "src/analyzer/expression/Expression.pv"
            struct Expression* inner = self->data.unaryexpression_value._1;
            #line 686 "src/analyzer/expression/Expression.pv"
            String__append(result, op);
            #line 687 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(inner, result);
        } break;
        #line 689 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 689 "src/analyzer/expression/Expression.pv"
            struct Expression* lhs = self->data.binaryexpression_value._0;
            #line 689 "src/analyzer/expression/Expression.pv"
            struct str op = self->data.binaryexpression_value._1;
            #line 689 "src/analyzer/expression/Expression.pv"
            struct Expression* rhs = self->data.binaryexpression_value._2;
            #line 690 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(lhs, result);
            #line 691 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = " ", .length = strlen(" ") });
            #line 692 "src/analyzer/expression/Expression.pv"
            String__append(result, op);
            #line 693 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = " ", .length = strlen(" ") });
            #line 694 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(rhs, result);
        } break;
        #line 696 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 696 "src/analyzer/expression/Expression.pv"
            struct EnumVariant* variant = self->data.enumvariant_value;
            #line 697 "src/analyzer/expression/Expression.pv"
            struct Token* name = variant->parent->name;
            #line 698 "src/analyzer/expression/Expression.pv"
            if (name != 0) {
                #line 699 "src/analyzer/expression/Expression.pv"
                String__append(result, name->value);
            } else {
                #line 701 "src/analyzer/expression/Expression.pv"
                String__append(result, (struct str){ .ptr = "unknown_enum", .length = strlen("unknown_enum") });
            }

            #line 704 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "::", .length = strlen("::") });
            #line 705 "src/analyzer/expression/Expression.pv"
            String__append(result, variant->name->value);
        } break;
        #line 707 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 707 "src/analyzer/expression/Expression.pv"
            struct Expression* target = self->data.invoke_value._0;
            #line 708 "src/analyzer/expression/Expression.pv"
            Expression__append_display_name(target, result);
        } break;
        #line 710 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 710 "src/analyzer/expression/Expression.pv"
            struct str member_name = self->data.memberstaticexpression_value._1;
            #line 711 "src/analyzer/expression/Expression.pv"
            String__append(result, member_name);
        } break;
        #line 713 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 713 "src/analyzer/expression/Expression.pv"
            struct str name = self->data.variable_value;
            #line 714 "src/analyzer/expression/Expression.pv"
            String__append(result, name);
        } break;
        #line 716 "src/analyzer/expression/Expression.pv"
        default: {
            #line 717 "src/analyzer/expression/Expression.pv"
            String__append(result, (struct str){ .ptr = "expr", .length = strlen("expr") });
        } break;
    }
}

#line 722 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* expected_type, bool apply_implicit_cast) {
    #line 723 "src/analyzer/expression/Expression.pv"
    bool success = true;

    #line 725 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 726 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 727 "src/analyzer/expression/Expression.pv"
            switch (Type__resolve_typedef(expected_type)->type) {
                #line 728 "src/analyzer/expression/Expression.pv"
                case TYPE__INDIRECT: {
                    #line 728 "src/analyzer/expression/Expression.pv"
                    struct Indirect* indirect = Type__resolve_typedef(expected_type)->indirect_value;
                    #line 729 "src/analyzer/expression/Expression.pv"
                    switch (indirect->type) {
                        #line 730 "src/analyzer/expression/Expression.pv"
                        case INDIRECT_TYPE__REFERENCE: {
                            #line 731 "src/analyzer/expression/Expression.pv"
                            Context__error_token(context, self->token, "null can only be used with * types, not & types");
                            #line 732 "src/analyzer/expression/Expression.pv"
                            return false;
                        } break;
                        #line 734 "src/analyzer/expression/Expression.pv"
                        case INDIRECT_TYPE__DYNAMIC_DISPATCH: {
                            #line 735 "src/analyzer/expression/Expression.pv"
                            Context__error_token(context, self->token, "null can only be used with * types, not & types");
                            #line 736 "src/analyzer/expression/Expression.pv"
                            return false;
                        } break;
                        #line 738 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 738 "src/analyzer/expression/Expression.pv"
                            return true;
                        } break;
                    }
                } break;
                #line 741 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 744 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 744 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 745 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") })) {
                #line 746 "src/analyzer/expression/Expression.pv"
                switch (expected_type->type) {
                    #line 747 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 747 "src/analyzer/expression/Expression.pv"
                        struct Indirect* indirect = expected_type->indirect_value;
                        #line 748 "src/analyzer/expression/Expression.pv"
                        switch (indirect->type) {
                            #line 749 "src/analyzer/expression/Expression.pv"
                            case INDIRECT_TYPE__POINTER: {
                                #line 750 "src/analyzer/expression/Expression.pv"
                                Context__error_token(context, self->token, "use null instead of 0 for pointer types");
                                #line 751 "src/analyzer/expression/Expression.pv"
                                return false;
                            } break;
                            #line 753 "src/analyzer/expression/Expression.pv"
                            case INDIRECT_TYPE__CONST_POINTER: {
                                #line 754 "src/analyzer/expression/Expression.pv"
                                Context__error_token(context, self->token, "use null instead of 0 for pointer types");
                                #line 755 "src/analyzer/expression/Expression.pv"
                                return false;
                            } break;
                            #line 757 "src/analyzer/expression/Expression.pv"
                            case INDIRECT_TYPE__DYNAMIC_DISPATCH_POINTER: {
                                #line 758 "src/analyzer/expression/Expression.pv"
                                Context__error_token(context, self->token, "use null instead of 0 for pointer types");
                                #line 759 "src/analyzer/expression/Expression.pv"
                                return false;
                            } break;
                            #line 761 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 764 "src/analyzer/expression/Expression.pv"
                    default: {
                    } break;
                }
            }
        } break;
        #line 768 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 771 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 772 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 772 "src/analyzer/expression/Expression.pv"
            struct str operator = self->data.unaryexpression_value._0;
            #line 772 "src/analyzer/expression/Expression.pv"
            struct Expression* child = self->data.unaryexpression_value._1;
            #line 773 "src/analyzer/expression/Expression.pv"
            if (str__Eq_str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 774 "src/analyzer/expression/Expression.pv"
                switch (expected_type->type) {
                    #line 775 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 775 "src/analyzer/expression/Expression.pv"
                        struct Indirect* indirect = expected_type->indirect_value;
                        #line 776 "src/analyzer/expression/Expression.pv"
                        switch (indirect->to.type) {
                            #line 777 "src/analyzer/expression/Expression.pv"
                            case TYPE__SEQUENCE: {
                                #line 778 "src/analyzer/expression/Expression.pv"
                                switch (child->data.type) {
                                    #line 779 "src/analyzer/expression/Expression.pv"
                                    case EXPRESSION_DATA__INVOKE: {
                                        #line 780 "src/analyzer/expression/Expression.pv"
                                        if (Type__is_sequence_fixed_array(&child->return_type)) {
                                            #line 781 "src/analyzer/expression/Expression.pv"
                                            Expression__validate_type(child, context, &indirect->to, apply_implicit_cast);
                                        }
                                    } break;
                                    #line 784 "src/analyzer/expression/Expression.pv"
                                    default: {
                                    } break;
                                }
                            } break;
                            #line 787 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 790 "src/analyzer/expression/Expression.pv"
                    default: {
                    } break;
                }
            }
        } break;
        #line 794 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 794 "src/analyzer/expression/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 794 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 795 "src/analyzer/expression/Expression.pv"
            switch (expected_type->type) {
                #line 796 "src/analyzer/expression/Expression.pv"
                case TYPE__TUPLE: {
                    #line 796 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = expected_type->tuple_value;
                    #line 797 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 797 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 797 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 797 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 798 "src/analyzer/expression/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i], apply_implicit_cast) && success;
                    } }

                    #line 801 "src/analyzer/expression/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = expected_type };
                    #line 802 "src/analyzer/expression/Expression.pv"
                    invoke->return_type = *expected_type;
                    #line 803 "src/analyzer/expression/Expression.pv"
                    self->return_type = *expected_type;

                    #line 805 "src/analyzer/expression/Expression.pv"
                    return success;
                } break;
                #line 807 "src/analyzer/expression/Expression.pv"
                case TYPE__SEQUENCE: {
                    #line 807 "src/analyzer/expression/Expression.pv"
                    struct Sequence* sequence = expected_type->sequence_value;
                    #line 808 "src/analyzer/expression/Expression.pv"
                    if (Type__is_sequence_fixed_array(&self->return_type)) {
                        #line 809 "src/analyzer/expression/Expression.pv"
                        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                        #line 809 "src/analyzer/expression/Expression.pv"
                        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                            #line 809 "src/analyzer/expression/Expression.pv"
                            struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                            #line 810 "src/analyzer/expression/Expression.pv"
                            success = Expression__validate_type(argument->value, context, &sequence->element, apply_implicit_cast) && success;
                        } }

                        #line 813 "src/analyzer/expression/Expression.pv"
                        switch (self->return_type.type) {
                            #line 814 "src/analyzer/expression/Expression.pv"
                            case TYPE__SEQUENCE: {
                                #line 814 "src/analyzer/expression/Expression.pv"
                                struct Sequence* self_seq = self->return_type.sequence_value;
                                #line 815 "src/analyzer/expression/Expression.pv"
                                struct Sequence* new_seq = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) { .type = self_seq->type, .element = sequence->element, .element_pointer = self_seq->element_pointer }});
                                #line 816 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = new_seq }});
                                #line 817 "src/analyzer/expression/Expression.pv"
                                invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type };
                                #line 818 "src/analyzer/expression/Expression.pv"
                                invoke->return_type = *new_type;
                                #line 819 "src/analyzer/expression/Expression.pv"
                                self->return_type = *new_type;
                            } break;
                            #line 821 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 824 "src/analyzer/expression/Expression.pv"
                        return success;
                    }
                } break;
                #line 827 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 830 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 833 "src/analyzer/expression/Expression.pv"
    if (apply_implicit_cast && Type__needs_implicit_cast(expected_type, &self->return_type)) {
        #line 834 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, self);
        #line 835 "src/analyzer/expression/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 836 "src/analyzer/expression/Expression.pv"
        self->return_type = *expected_type;
        #line 837 "src/analyzer/expression/Expression.pv"
        return true;
    }

    #line 840 "src/analyzer/expression/Expression.pv"
    if (!Type__eq(expected_type, &self->return_type)) {
        #line 841 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 842 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Expected expression of type ", .length = strlen("Expected expression of type ") });
        #line 843 "src/analyzer/expression/Expression.pv"
        struct String expected_type_name = Naming__get_type_decl(&context->root->naming_decl, expected_type, context->type_self, 0);
        #line 844 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&expected_type_name));
        #line 845 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = ", but found ", .length = strlen(", but found ") });
        #line 846 "src/analyzer/expression/Expression.pv"
        struct String actual_type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 847 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&actual_type_name));
        #line 848 "src/analyzer/expression/Expression.pv"
        Context__error_expression(context, self, String__c_str(&message));
        #line 849 "src/analyzer/expression/Expression.pv"
        return false;
    }
    #line 853 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 856 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics) {
    #line 857 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 858 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 858 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 860 "src/analyzer/expression/Expression.pv"
    struct Expression* condition = Expression__parse(context, generics);
    #line 861 "src/analyzer/expression/Expression.pv"
    if (condition == 0) {
        #line 861 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 863 "src/analyzer/expression/Expression.pv"
    switch (condition->return_type.type) {
        #line 864 "src/analyzer/expression/Expression.pv"
        case TYPE__PRIMITIVE: {
            #line 864 "src/analyzer/expression/Expression.pv"
            struct Primitive* prim = condition->return_type.primitive_value;
            #line 865 "src/analyzer/expression/Expression.pv"
            if (prim == 0) {
                #line 866 "src/analyzer/expression/Expression.pv"
                Context__error_expression(context, condition, "If condition return type is blank");
                #line 867 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 870 "src/analyzer/expression/Expression.pv"
            if (!str__Eq_str__eq(prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                #line 871 "src/analyzer/expression/Expression.pv"
                Context__error_expression(context, condition, "If condition must be a bool expression");
                #line 872 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        } break;
        #line 875 "src/analyzer/expression/Expression.pv"
        default: {
            #line 876 "src/analyzer/expression/Expression.pv"
            Context__error_expression(context, condition, "If condition must be a bool expression");
            #line 877 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
    }

    #line 881 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 881 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 883 "src/analyzer/expression/Expression.pv"
    struct Array_NullNarrowing narrowings_true = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 884 "src/analyzer/expression/Expression.pv"
    Expression__collect_null_narrowings(context, condition, true, &narrowings_true);
    #line 885 "src/analyzer/expression/Expression.pv"
    bool pushed_true_scope = false;
    #line 886 "src/analyzer/expression/Expression.pv"
    if (narrowings_true.length > 0) {
        #line 887 "src/analyzer/expression/Expression.pv"
        Context__push_scope(context, 0);
        #line 888 "src/analyzer/expression/Expression.pv"
        { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_true);
        #line 888 "src/analyzer/expression/Expression.pv"
        while (Iter_ref_NullNarrowing__next(&__iter)) {
            #line 888 "src/analyzer/expression/Expression.pv"
            struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

            #line 888 "src/analyzer/expression/Expression.pv"
            Context__set_narrowed(context, narrow->path, narrow->type);
        } }
        #line 889 "src/analyzer/expression/Expression.pv"
        pushed_true_scope = true;
    }

    #line 892 "src/analyzer/expression/Expression.pv"
    struct Expression* a = Expression__parse(context, generics);
    #line 893 "src/analyzer/expression/Expression.pv"
    if (pushed_true_scope) {
        #line 893 "src/analyzer/expression/Expression.pv"
        Context__pop_scope(context);
    }
    #line 894 "src/analyzer/expression/Expression.pv"
    if (a == 0) {
        #line 894 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 896 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 896 "src/analyzer/expression/Expression.pv"
        return 0;
    }
    #line 897 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 897 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 899 "src/analyzer/expression/Expression.pv"
    bool is_else_if = Context__check_value(context, TOKEN_TYPE__KEYWORD, "if");

    #line 901 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 902 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Expected { or else if");
        #line 903 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 906 "src/analyzer/expression/Expression.pv"
    struct Array_NullNarrowing narrowings_false = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 907 "src/analyzer/expression/Expression.pv"
    Expression__collect_null_narrowings(context, condition, false, &narrowings_false);
    #line 908 "src/analyzer/expression/Expression.pv"
    bool pushed_false_scope = false;
    #line 909 "src/analyzer/expression/Expression.pv"
    if (narrowings_false.length > 0) {
        #line 910 "src/analyzer/expression/Expression.pv"
        Context__push_scope(context, 0);
        #line 911 "src/analyzer/expression/Expression.pv"
        { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_false);
        #line 911 "src/analyzer/expression/Expression.pv"
        while (Iter_ref_NullNarrowing__next(&__iter)) {
            #line 911 "src/analyzer/expression/Expression.pv"
            struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

            #line 911 "src/analyzer/expression/Expression.pv"
            Context__set_narrowed(context, narrow->path, narrow->type);
        } }
        #line 912 "src/analyzer/expression/Expression.pv"
        pushed_false_scope = true;
    }

    #line 915 "src/analyzer/expression/Expression.pv"
    struct Expression* b = Expression__parse(context, generics);
    #line 916 "src/analyzer/expression/Expression.pv"
    if (pushed_false_scope) {
        #line 916 "src/analyzer/expression/Expression.pv"
        Context__pop_scope(context);
    }
    #line 917 "src/analyzer/expression/Expression.pv"
    if (b == 0) {
        #line 917 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 919 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 919 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 921 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_type(a, context, &b->return_type, false)) {
        #line 921 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 923 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__IF_EXPRESSION, .ifexpression_value = { ._0 = condition, ._1 = a, ._2 = b} }, &a->return_type);
}

#line 926 "src/analyzer/expression/Expression.pv"
void Expression__record_function_signature(struct Context* context, struct Type* function_type, struct Token* open_paren, struct Token* close_paren, struct Array_Position comma_positions, bool skip_self) {
    #line 927 "src/analyzer/expression/Expression.pv"
    if (!Context__should_record_symbols(context)) {
        #line 927 "src/analyzer/expression/Expression.pv"
        return;
    }

    #line 929 "src/analyzer/expression/Expression.pv"
    struct Function* func_info = 0;
    #line 930 "src/analyzer/expression/Expression.pv"
    struct Type* function_type_self = context->type_self;
    #line 931 "src/analyzer/expression/Expression.pv"
    struct GenericMap* function_generics = 0;

    #line 933 "src/analyzer/expression/Expression.pv"
    switch (function_type->type) {
        #line 934 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 934 "src/analyzer/expression/Expression.pv"
            struct Function* info = function_type->function_value._0;
            #line 934 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generics = function_type->function_value._1;
            #line 935 "src/analyzer/expression/Expression.pv"
            func_info = info;
            #line 936 "src/analyzer/expression/Expression.pv"
            function_generics = generics;
            #line 937 "src/analyzer/expression/Expression.pv"
            if (generics != 0 && generics->self_type != 0) {
                #line 938 "src/analyzer/expression/Expression.pv"
                function_type_self = generics->self_type;
            }
        } break;
        #line 941 "src/analyzer/expression/Expression.pv"
        default: {
            #line 941 "src/analyzer/expression/Expression.pv"
            return;
        } break;
    }
    #line 943 "src/analyzer/expression/Expression.pv"
    if (func_info == 0) {
        #line 943 "src/analyzer/expression/Expression.pv"
        return;
    }

    #line 945 "src/analyzer/expression/Expression.pv"
    struct String label = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 946 "src/analyzer/expression/Expression.pv"
    String__append(&label, (struct str){ .ptr = "fn ", .length = strlen("fn ") });
    #line 947 "src/analyzer/expression/Expression.pv"
    struct Token* name = func_info->name;
    #line 948 "src/analyzer/expression/Expression.pv"
    if (name != 0) {
        #line 948 "src/analyzer/expression/Expression.pv"
        String__append(&label, name->value);
    }
    #line 949 "src/analyzer/expression/Expression.pv"
    String__append(&label, (struct str){ .ptr = "(", .length = strlen("(") });

    #line 951 "src/analyzer/expression/Expression.pv"
    struct Array_str params = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 952 "src/analyzer/expression/Expression.pv"
    bool first = true;
    #line 953 "src/analyzer/expression/Expression.pv"
    uintptr_t i = 0;
    #line 954 "src/analyzer/expression/Expression.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 954 "src/analyzer/expression/Expression.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 954 "src/analyzer/expression/Expression.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 955 "src/analyzer/expression/Expression.pv"
        if (skip_self && usize__Eq_usize__eq(i, 0)) {
            #line 956 "src/analyzer/expression/Expression.pv"
            i += 1;
            #line 957 "src/analyzer/expression/Expression.pv"
            continue;
        }
        #line 959 "src/analyzer/expression/Expression.pv"
        if (!first) {
            #line 959 "src/analyzer/expression/Expression.pv"
            String__append(&label, (struct str){ .ptr = ", ", .length = strlen(", ") });
        }
        #line 960 "src/analyzer/expression/Expression.pv"
        first = false;

        #line 962 "src/analyzer/expression/Expression.pv"
        struct String param_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 963 "src/analyzer/expression/Expression.pv"
        struct Token* pname = param->name;
        #line 964 "src/analyzer/expression/Expression.pv"
        if (pname != 0) {
            #line 965 "src/analyzer/expression/Expression.pv"
            String__append(&param_str, pname->value);
            #line 966 "src/analyzer/expression/Expression.pv"
            String__append(&param_str, (struct str){ .ptr = ": ", .length = strlen(": ") });
        }
        #line 968 "src/analyzer/expression/Expression.pv"
        struct String type_decl = Naming__get_type_decl(&context->root->naming_decl, &param->type, function_type_self, function_generics);
        #line 969 "src/analyzer/expression/Expression.pv"
        String__append(&param_str, String__as_str(&type_decl));
        #line 970 "src/analyzer/expression/Expression.pv"
        String__append(&label, String__as_str(&param_str));
        #line 971 "src/analyzer/expression/Expression.pv"
        Array_str__append(&params, String__as_str(&param_str));
        #line 972 "src/analyzer/expression/Expression.pv"
        i += 1;
    } }

    #line 975 "src/analyzer/expression/Expression.pv"
    String__append(&label, (struct str){ .ptr = ")", .length = strlen(")") });
    #line 976 "src/analyzer/expression/Expression.pv"
    struct String ret_type_decl = Naming__get_type_decl(&context->root->naming_decl, &func_info->return_type, function_type_self, function_generics);
    #line 977 "src/analyzer/expression/Expression.pv"
    if (!Type__is_void(&func_info->return_type)) {
        #line 978 "src/analyzer/expression/Expression.pv"
        String__append(&label, (struct str){ .ptr = " -> ", .length = strlen(" -> ") });
        #line 979 "src/analyzer/expression/Expression.pv"
        String__append(&label, String__as_str(&ret_type_decl));
    }

    #line 982 "src/analyzer/expression/Expression.pv"
    Context__record_signature(context, open_paren, close_paren, comma_positions, String__as_str(&label), params);
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
            switch (indirect->to.type) {
                #line 59 "src/analyzer/expression/MemberLookup.pv"
                case TYPE__SELF: {
                } break;
                #line 60 "src/analyzer/expression/MemberLookup.pv"
                case TYPE__GENERIC: {
                } break;
                #line 61 "src/analyzer/expression/MemberLookup.pv"
                case TYPE__GENERIC_TYPEDEF: {
                } break;
                #line 62 "src/analyzer/expression/MemberLookup.pv"
                default: {
                    #line 63 "src/analyzer/expression/MemberLookup.pv"
                    struct Function* function = Root__find_type_impl_function(context->root, type, member->value, 0);
                    #line 64 "src/analyzer/expression/MemberLookup.pv"
                    if (function != 0) {
                        #line 65 "src/analyzer/expression/MemberLookup.pv"
                        struct GenericMap generic_map_val = (struct GenericMap) { .self_type = type, .array = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }), .map = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) };
                        #line 66 "src/analyzer/expression/MemberLookup.pv"
                        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(context->allocator, &generic_map_val);
                        #line 67 "src/analyzer/expression/MemberLookup.pv"
                        if (generic_map == 0) {
                            #line 67 "src/analyzer/expression/MemberLookup.pv"
                            return 0;
                        }
                        #line 68 "src/analyzer/expression/MemberLookup.pv"
                        return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                    }
                } break;
            }

            #line 73 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 75 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SELF: {
            #line 76 "src/analyzer/expression/MemberLookup.pv"
            if (context->type_self == 0) {
                #line 76 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }
            #line 77 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 79 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__PRIMITIVE: {
            #line 79 "src/analyzer/expression/MemberLookup.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 80 "src/analyzer/expression/MemberLookup.pv"
            if (primitive_info == 0) {
                #line 80 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }
            #line 81 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 81 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 81 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 82 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 83 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 84 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }})} }});
                }
            } }

            #line 88 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 88 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 89 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 91 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__STRUCT: {
            #line 91 "src/analyzer/expression/MemberLookup.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 91 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 92 "src/analyzer/expression/MemberLookup.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 93 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 94 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 97 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 97 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 97 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 98 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 99 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 100 "src/analyzer/expression/MemberLookup.pv"
                    if (usize__Eq_usize__eq(impl_info->typedefs.length, 0)) {
                        #line 101 "src/analyzer/expression/MemberLookup.pv"
                        return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                    }
                    #line 103 "src/analyzer/expression/MemberLookup.pv"
                    if (generic_map == 0) {
                        #line 103 "src/analyzer/expression/MemberLookup.pv"
                        return 0;
                    }
                    #line 104 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 105 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 106 "src/analyzer/expression/MemberLookup.pv"
                    if (aug_map == 0) {
                        #line 106 "src/analyzer/expression/MemberLookup.pv"
                        return 0;
                    }
                    #line 107 "src/analyzer/expression/MemberLookup.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 107 "src/analyzer/expression/MemberLookup.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 107 "src/analyzer/expression/MemberLookup.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 107 "src/analyzer/expression/MemberLookup.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 108 "src/analyzer/expression/MemberLookup.pv"
                        GenericMap__insert(aug_map, name, *typedef_type);
                    } }
                    #line 110 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = aug_map} }});
                }
            } }

            #line 114 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 114 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 114 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 115 "src/analyzer/expression/MemberLookup.pv"
                struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member->value);
                #line 116 "src/analyzer/expression/MemberLookup.pv"
                if (impl_const_ptr != 0) {
                    #line 117 "src/analyzer/expression/MemberLookup.pv"
                    struct ImplConst* impl_const = *impl_const_ptr;
                    #line 118 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, &impl_const->type);
                }
            } }

            #line 122 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 123 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 125 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 127 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 127 "src/analyzer/expression/MemberLookup.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 127 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 128 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 129 "src/analyzer/expression/MemberLookup.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, &context->root->func_next);
                #line 130 "src/analyzer/expression/MemberLookup.pv"
                if (func_next == 0) {
                    #line 130 "src/analyzer/expression/MemberLookup.pv"
                    return 0;
                }
                #line 131 "src/analyzer/expression/MemberLookup.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 132 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} }});
            }

            #line 135 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 136 "src/analyzer/expression/MemberLookup.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, &context->root->func_value);
                #line 137 "src/analyzer/expression/MemberLookup.pv"
                if (func_value == 0) {
                    #line 137 "src/analyzer/expression/MemberLookup.pv"
                    return 0;
                }
                #line 138 "src/analyzer/expression/MemberLookup.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 139 "src/analyzer/expression/MemberLookup.pv"
                func_value->return_type = func_info->return_type;
                #line 140 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} }});
            }

            #line 143 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 143 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 144 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 146 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__ENUM: {
            #line 146 "src/analyzer/expression/MemberLookup.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 146 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 147 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 147 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 147 "src/analyzer/expression/MemberLookup.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 148 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 149 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 150 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                }
            } }

            #line 154 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 154 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 155 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 157 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TRAIT: {
            #line 157 "src/analyzer/expression/MemberLookup.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 157 "src/analyzer/expression/MemberLookup.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 158 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 159 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) }});
            }

            #line 162 "src/analyzer/expression/MemberLookup.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 163 "src/analyzer/expression/MemberLookup.pv"
            if (function == 0) {
                #line 164 "src/analyzer/expression/MemberLookup.pv"
                if (output_error) {
                    #line 164 "src/analyzer/expression/MemberLookup.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 165 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 168 "src/analyzer/expression/MemberLookup.pv"
            return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
        } break;
        #line 170 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TYPEDEF_C: {
            #line 170 "src/analyzer/expression/MemberLookup.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 171 "src/analyzer/expression/MemberLookup.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 173 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__STRUCT_C: {
            #line 173 "src/analyzer/expression/MemberLookup.pv"
            struct StructC* struct_info = type->structc_value;
            #line 174 "src/analyzer/expression/MemberLookup.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 175 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 175 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 177 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 177 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 178 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 180 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__UNION_C: {
            #line 180 "src/analyzer/expression/MemberLookup.pv"
            struct StructC* union_info = type->unionc_value;
            #line 181 "src/analyzer/expression/MemberLookup.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 182 "src/analyzer/expression/MemberLookup.pv"
            if (field != 0) {
                #line 182 "src/analyzer/expression/MemberLookup.pv"
                return &field->type;
            }

            #line 184 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 184 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 185 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 187 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__CLASS_CPP: {
            #line 187 "src/analyzer/expression/MemberLookup.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 188 "src/analyzer/expression/MemberLookup.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 189 "src/analyzer/expression/MemberLookup.pv"
            if (field_type != 0) {
                #line 189 "src/analyzer/expression/MemberLookup.pv"
                return field_type;
            }

            #line 191 "src/analyzer/expression/MemberLookup.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 192 "src/analyzer/expression/MemberLookup.pv"
            if (value_type != 0) {
                #line 192 "src/analyzer/expression/MemberLookup.pv"
                return value_type;
            }

            #line 194 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 194 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 194 "src/analyzer/expression/MemberLookup.pv"
                struct Type* base = Iter_ref_Type__value(&__iter);

                #line 195 "src/analyzer/expression/MemberLookup.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 196 "src/analyzer/expression/MemberLookup.pv"
                if (base_type != 0) {
                    #line 196 "src/analyzer/expression/MemberLookup.pv"
                    return base_type;
                }
            } }

            #line 199 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 199 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 200 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 202 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__GENERIC: {
            #line 202 "src/analyzer/expression/MemberLookup.pv"
            struct Generic* generic = type->generic_value;
            #line 203 "src/analyzer/expression/MemberLookup.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generic->traits);
            #line 203 "src/analyzer/expression/MemberLookup.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 203 "src/analyzer/expression/MemberLookup.pv"
                struct Type* trait_type = Iter_ref_Type__value(&__iter);

                #line 204 "src/analyzer/expression/MemberLookup.pv"
                struct Trait* trait_info = 0;
                #line 205 "src/analyzer/expression/MemberLookup.pv"
                struct GenericMap* bound_generics = 0;
                #line 206 "src/analyzer/expression/MemberLookup.pv"
                switch (trait_type->type) {
                    #line 207 "src/analyzer/expression/MemberLookup.pv"
                    case TYPE__TRAIT: {
                        #line 207 "src/analyzer/expression/MemberLookup.pv"
                        struct Trait* info = trait_type->trait_value._0;
                        #line 207 "src/analyzer/expression/MemberLookup.pv"
                        struct GenericMap* generic_map = trait_type->trait_value._1;
                        #line 208 "src/analyzer/expression/MemberLookup.pv"
                        trait_info = info;
                        #line 209 "src/analyzer/expression/MemberLookup.pv"
                        bound_generics = generic_map;
                    } break;
                    #line 211 "src/analyzer/expression/MemberLookup.pv"
                    default: {
                    } break;
                }
                #line 213 "src/analyzer/expression/MemberLookup.pv"
                if (trait_info == 0) {
                    #line 213 "src/analyzer/expression/MemberLookup.pv"
                    continue;
                }
                #line 214 "src/analyzer/expression/MemberLookup.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 215 "src/analyzer/expression/MemberLookup.pv"
                if (function != 0) {
                    #line 216 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap generic_map_val;
                    #line 217 "src/analyzer/expression/MemberLookup.pv"
                    if (bound_generics == 0) {
                        #line 218 "src/analyzer/expression/MemberLookup.pv"
                        generic_map_val = (struct GenericMap) { .self_type = 0, .array = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }), .map = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }) };
                    } else {
                        #line 220 "src/analyzer/expression/MemberLookup.pv"
                        generic_map_val = GenericMap__clone(bound_generics, context->allocator);
                    }
                    #line 222 "src/analyzer/expression/MemberLookup.pv"
                    generic_map_val.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__GENERIC, .generic_value = generic }});
                    #line 223 "src/analyzer/expression/MemberLookup.pv"
                    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(context->allocator, &generic_map_val);
                    #line 224 "src/analyzer/expression/MemberLookup.pv"
                    if (generic_map == 0) {
                        #line 224 "src/analyzer/expression/MemberLookup.pv"
                        return 0;
                    }
                    #line 225 "src/analyzer/expression/MemberLookup.pv"
                    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
                    #line 225 "src/analyzer/expression/MemberLookup.pv"
                    while (HashMapIter_str_usize__next(&__iter)) {
                        #line 225 "src/analyzer/expression/MemberLookup.pv"
                        struct str typedef_name = HashMapIter_str_usize__value(&__iter)->_0;

                        #line 226 "src/analyzer/expression/MemberLookup.pv"
                        struct GenericTypedef* gt = ArenaAllocator__store_GenericTypedef(context->allocator, (struct GenericTypedef[]){(struct GenericTypedef) { .generic = generic, .typedef_name = typedef_name }});
                        #line 227 "src/analyzer/expression/MemberLookup.pv"
                        if (gt == 0) {
                            #line 227 "src/analyzer/expression/MemberLookup.pv"
                            return 0;
                        }
                        #line 228 "src/analyzer/expression/MemberLookup.pv"
                        GenericMap__insert(generic_map, typedef_name, (struct Type) { .type = TYPE__GENERIC_TYPEDEF, .generictypedef_value = gt });
                    } }
                    #line 230 "src/analyzer/expression/MemberLookup.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                }
            } }

            #line 234 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 234 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 235 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 237 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__SEQUENCE: {
            #line 237 "src/analyzer/expression/MemberLookup.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 238 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 239 "src/analyzer/expression/MemberLookup.pv"
                return &sequence->element_pointer;
            }

            #line 242 "src/analyzer/expression/MemberLookup.pv"
            if (str__Eq_str__eq(member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 243 "src/analyzer/expression/MemberLookup.pv"
                return &context->root->type_usize;
            }

            #line 246 "src/analyzer/expression/MemberLookup.pv"
            struct TypeImpl* hack_type_impl = context->root->hack_type_impl;
            #line 247 "src/analyzer/expression/MemberLookup.pv"
            if (hack_type_impl == 0) {
                #line 247 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }
            #line 248 "src/analyzer/expression/MemberLookup.pv"
            struct Impl* impl_info = hack_type_impl->impl_info;

            #line 250 "src/analyzer/expression/MemberLookup.pv"
            struct Function* function = Impl__find_function(impl_info, member->value);
            #line 251 "src/analyzer/expression/MemberLookup.pv"
            if (function != 0) {
                #line 252 "src/analyzer/expression/MemberLookup.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 }});
                #line 253 "src/analyzer/expression/MemberLookup.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 254 "src/analyzer/expression/MemberLookup.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) }});

                #line 256 "src/analyzer/expression/MemberLookup.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &generic_map)} }});
            }

            #line 259 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 259 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 260 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 262 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__TUPLE: {
            #line 262 "src/analyzer/expression/MemberLookup.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 263 "src/analyzer/expression/MemberLookup.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 264 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 265 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 268 "src/analyzer/expression/MemberLookup.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 269 "src/analyzer/expression/MemberLookup.pv"
            if (index >= tuple->elements.length) {
                #line 270 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 271 "src/analyzer/expression/MemberLookup.pv"
                return 0;
            }

            #line 274 "src/analyzer/expression/MemberLookup.pv"
            return &tuple->elements.data[index];
        } break;
        #line 276 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 276 "src/analyzer/expression/MemberLookup.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 277 "src/analyzer/expression/MemberLookup.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 278 "src/analyzer/expression/MemberLookup.pv"
            if (type != 0) {
                #line 278 "src/analyzer/expression/MemberLookup.pv"
                return type;
            }

            #line 280 "src/analyzer/expression/MemberLookup.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 281 "src/analyzer/expression/MemberLookup.pv"
            if (value != 0) {
                #line 281 "src/analyzer/expression/MemberLookup.pv"
                return value;
            }

            #line 283 "src/analyzer/expression/MemberLookup.pv"
            if (output_error) {
                #line 283 "src/analyzer/expression/MemberLookup.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 285 "src/analyzer/expression/MemberLookup.pv"
            return 0;
        } break;
        #line 287 "src/analyzer/expression/MemberLookup.pv"
        case TYPE__UNKNOWN_C: {
            #line 287 "src/analyzer/expression/MemberLookup.pv"
            return type;
        } break;
        #line 288 "src/analyzer/expression/MemberLookup.pv"
        default: {
            #line 288 "src/analyzer/expression/MemberLookup.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 291 "src/analyzer/expression/MemberLookup.pv"
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
    if (usize__Eq_usize__eq(i, generic_map.array.length)) {
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
        { struct Iter_ref_Type __iter = Array_Type__iter(&generic->traits);
        #line 37 "src/analyzer/expression/GenericResolve.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 37 "src/analyzer/expression/GenericResolve.pv"
            struct Type* trait_type = Iter_ref_Type__value(&__iter);

            #line 38 "src/analyzer/expression/GenericResolve.pv"
            struct Trait* trait_info = 0;
            #line 39 "src/analyzer/expression/GenericResolve.pv"
            switch (trait_type->type) {
                #line 40 "src/analyzer/expression/GenericResolve.pv"
                case TYPE__TRAIT: {
                    #line 40 "src/analyzer/expression/GenericResolve.pv"
                    struct Trait* info = trait_type->trait_value._0;
                    #line 40 "src/analyzer/expression/GenericResolve.pv"
                    trait_info = info;
                } break;
                #line 41 "src/analyzer/expression/GenericResolve.pv"
                default: {
                } break;
            }
            #line 43 "src/analyzer/expression/GenericResolve.pv"
            if (trait_info == 0) {
                #line 43 "src/analyzer/expression/GenericResolve.pv"
                continue;
            }
            #line 44 "src/analyzer/expression/GenericResolve.pv"
            { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
            #line 44 "src/analyzer/expression/GenericResolve.pv"
            while (HashMapIter_str_usize__next(&__iter)) {
                #line 44 "src/analyzer/expression/GenericResolve.pv"
                struct str typedef_name = HashMapIter_str_usize__value(&__iter)->_0;

                #line 45 "src/analyzer/expression/GenericResolve.pv"
                switch (concrete_type->type) {
                    #line 46 "src/analyzer/expression/GenericResolve.pv"
                    case TYPE__STRUCT: {
                        #line 46 "src/analyzer/expression/GenericResolve.pv"
                        struct Struct* struct_info = concrete_type->struct_value._0;
                        #line 47 "src/analyzer/expression/GenericResolve.pv"
                        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                        #line 47 "src/analyzer/expression/GenericResolve.pv"
                        while (Iter_ref_ref_Impl__next(&__iter)) {
                            #line 47 "src/analyzer/expression/GenericResolve.pv"
                            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                            #line 48 "src/analyzer/expression/GenericResolve.pv"
                            if (impl_info->trait_ != trait_info) {
                                #line 48 "src/analyzer/expression/GenericResolve.pv"
                                continue;
                            }
                            #line 49 "src/analyzer/expression/GenericResolve.pv"
                            struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &typedef_name);
                            #line 50 "src/analyzer/expression/GenericResolve.pv"
                            if (typedef_type != 0) {
                                #line 51 "src/analyzer/expression/GenericResolve.pv"
                                GenericMap__insert(&generic_map, typedef_name, *typedef_type);
                            }
                        } }
                    } break;
                    #line 55 "src/analyzer/expression/GenericResolve.pv"
                    default: {
                    } break;
                }
            } }
        } }
    } }

    #line 61 "src/analyzer/expression/GenericResolve.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, &generic_map);
}

#line 64 "src/analyzer/expression/GenericResolve.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 65 "src/analyzer/expression/GenericResolve.pv"
    switch (param_type->type) {
        #line 66 "src/analyzer/expression/GenericResolve.pv"
        case TYPE__GENERIC: {
            #line 66 "src/analyzer/expression/GenericResolve.pv"
            struct Generic* generic = param_type->generic_value;
            #line 67 "src/analyzer/expression/GenericResolve.pv"
            struct Token* generic_name = generic->name;
            #line 68 "src/analyzer/expression/GenericResolve.pv"
            if (generic_name == 0) {
                #line 68 "src/analyzer/expression/GenericResolve.pv"
                return;
            }

            #line 70 "src/analyzer/expression/GenericResolve.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic_name->value);
            #line 71 "src/analyzer/expression/GenericResolve.pv"
            if (generic_type != 0) {
                #line 71 "src/analyzer/expression/GenericResolve.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 73 "src/analyzer/expression/GenericResolve.pv"
        case TYPE__INDIRECT: {
            #line 73 "src/analyzer/expression/GenericResolve.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 74 "src/analyzer/expression/GenericResolve.pv"
            switch (arg_type->type) {
                #line 75 "src/analyzer/expression/GenericResolve.pv"
                case TYPE__INDIRECT: {
                    #line 75 "src/analyzer/expression/GenericResolve.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 76 "src/analyzer/expression/GenericResolve.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 78 "src/analyzer/expression/GenericResolve.pv"
                default: {
                } break;
            }
        } break;
        #line 81 "src/analyzer/expression/GenericResolve.pv"
        default: {
        } break;
    }
}

#line 7 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__type_implements_trait(struct Type* type, struct Trait* trait_info) {
    #line 8 "src/analyzer/expression/ExpressionValidate.pv"
    struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = trait_info->module->context.allocator });

    #line 10 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 11 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__PRIMITIVE: {
            #line 11 "src/analyzer/expression/ExpressionValidate.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 12 "src/analyzer/expression/ExpressionValidate.pv"
            if (primitive_info == 0) {
                #line 12 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }
            #line 13 "src/analyzer/expression/ExpressionValidate.pv"
            return HashMap_str_ref_Trait__find(&primitive_info->traits, &trait_key) != 0;
        } break;
        #line 15 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT: {
            #line 15 "src/analyzer/expression/ExpressionValidate.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 16 "src/analyzer/expression/ExpressionValidate.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&struct_info->traits, &trait_key) != 0;
        } break;
        #line 18 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__ENUM: {
            #line 18 "src/analyzer/expression/ExpressionValidate.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 19 "src/analyzer/expression/ExpressionValidate.pv"
            return HashMap_str_ref_Trait__find(&enum_info->traits, &trait_key) != 0;
        } break;
        #line 21 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TYPEDEF_C: {
            #line 21 "src/analyzer/expression/ExpressionValidate.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 22 "src/analyzer/expression/ExpressionValidate.pv"
            return Expression__type_implements_trait(typedef_info->type, trait_info);
        } break;
        #line 24 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
        } break;
    }

    #line 27 "src/analyzer/expression/ExpressionValidate.pv"
    return false;
}

#line 30 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_typed_variadic_argument(struct Context* context, struct Expression* arg, struct Type* element_type) {
    #line 31 "src/analyzer/expression/ExpressionValidate.pv"
    switch (element_type->type) {
        #line 32 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__INDIRECT: {
            #line 32 "src/analyzer/expression/ExpressionValidate.pv"
            struct Indirect* indirect = element_type->indirect_value;
            #line 33 "src/analyzer/expression/ExpressionValidate.pv"
            switch (indirect->to.type) {
                #line 34 "src/analyzer/expression/ExpressionValidate.pv"
                case TYPE__TRAIT: {
                    #line 34 "src/analyzer/expression/ExpressionValidate.pv"
                    struct Trait* trait_info = indirect->to.trait_value._0;
                    #line 35 "src/analyzer/expression/ExpressionValidate.pv"
                    if (Type__is_indirect(&arg->return_type)) {
                        #line 36 "src/analyzer/expression/ExpressionValidate.pv"
                        return Expression__validate_type(arg, context, element_type, true);
                    }

                    #line 39 "src/analyzer/expression/ExpressionValidate.pv"
                    if (Expression__type_implements_trait(&arg->return_type, trait_info)) {
                        #line 40 "src/analyzer/expression/ExpressionValidate.pv"
                        return true;
                    }
                } break;
                #line 43 "src/analyzer/expression/ExpressionValidate.pv"
                default: {
                } break;
            }
        } break;
        #line 46 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
        } break;
    }

    #line 49 "src/analyzer/expression/ExpressionValidate.pv"
    return Expression__validate_type(arg, context, element_type, true);
}

#line 52 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call) {
    #line 53 "src/analyzer/expression/ExpressionValidate.pv"
    uintptr_t arguments_length = arguments->length;

    #line 55 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 56 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__SELF: {
            #line 57 "src/analyzer/expression/ExpressionValidate.pv"
            if (context->type_self == 0) {
                #line 57 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }
            #line 58 "src/analyzer/expression/ExpressionValidate.pv"
            type = context->type_self;
        } break;
        #line 60 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
        } break;
    }

    #line 63 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 64 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TYPEDEF_C: {
            #line 64 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 65 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNION_C: {
            #line 65 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 66 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT_C: {
            #line 66 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 67 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TUPLE: {
            #line 67 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 68 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__STRUCT: {
            #line 68 "src/analyzer/expression/ExpressionValidate.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 68 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 69 "src/analyzer/expression/ExpressionValidate.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 69 "src/analyzer/expression/ExpressionValidate.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 69 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 70 "src/analyzer/expression/ExpressionValidate.pv"
                struct Token* arg_name = arg->name;
                #line 71 "src/analyzer/expression/ExpressionValidate.pv"
                if (arg_name == 0) {
                    #line 71 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }
                #line 72 "src/analyzer/expression/ExpressionValidate.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg_name->value);

                #line 74 "src/analyzer/expression/ExpressionValidate.pv"
                if (param == 0) {
                    #line 75 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, arg_name, "Unable to find field in struct");
                    #line 76 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 79 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &param->type;

                #line 81 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2 != 0 && generic_map2->map.length > 0) {
                    #line 82 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 84 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 87 "src/analyzer/expression/ExpressionValidate.pv"
                if (param_type == 0) {
                    #line 88 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_expression(context, arg->value, "Unable to resolve field type");
                    #line 89 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 92 "src/analyzer/expression/ExpressionValidate.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            } }

            #line 95 "src/analyzer/expression/ExpressionValidate.pv"
            bool success = true;
            #line 96 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t field_i = 0;
            #line 97 "src/analyzer/expression/ExpressionValidate.pv"
            while (field_i < struct_info->fields.length) {
                #line 98 "src/analyzer/expression/ExpressionValidate.pv"
                struct HashMapBucket_str_StructField* bucket = struct_info->fields.data + field_i;
                #line 99 "src/analyzer/expression/ExpressionValidate.pv"
                if (bucket == 0) {
                    #line 99 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }
                #line 100 "src/analyzer/expression/ExpressionValidate.pv"
                bool provided = false;
                #line 101 "src/analyzer/expression/ExpressionValidate.pv"
                uintptr_t arg_i = 0;
                #line 102 "src/analyzer/expression/ExpressionValidate.pv"
                while (arg_i < arguments->length) {
                    #line 103 "src/analyzer/expression/ExpressionValidate.pv"
                    struct Token* arg_name = arguments->data[arg_i].name;
                    #line 104 "src/analyzer/expression/ExpressionValidate.pv"
                    if (arg_name != 0 && str__Eq_str__eq(arg_name->value, bucket->key)) {
                        #line 105 "src/analyzer/expression/ExpressionValidate.pv"
                        provided = true;
                        #line 106 "src/analyzer/expression/ExpressionValidate.pv"
                        break;
                    }
                    #line 108 "src/analyzer/expression/ExpressionValidate.pv"
                    arg_i += 1;
                }
                #line 110 "src/analyzer/expression/ExpressionValidate.pv"
                if (!provided) {
                    #line 111 "src/analyzer/expression/ExpressionValidate.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 112 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, (struct str){ .ptr = "Missing field in struct construction: ", .length = strlen("Missing field in struct construction: ") });
                    #line 113 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, bucket->key);
                    #line 114 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, token, String__c_str(&message));
                    #line 115 "src/analyzer/expression/ExpressionValidate.pv"
                    success = false;
                }
                #line 117 "src/analyzer/expression/ExpressionValidate.pv"
                field_i += 1;
            }

            #line 120 "src/analyzer/expression/ExpressionValidate.pv"
            return success;
        } break;
        #line 122 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION: {
            #line 122 "src/analyzer/expression/ExpressionValidate.pv"
            struct Function* function = type->function_value._0;
            #line 122 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 123 "src/analyzer/expression/ExpressionValidate.pv"
            if ((struct Function*)(function) == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 123 "src/analyzer/expression/ExpressionValidate.pv"
                return true;
            }

            #line 125 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t required_parameters_length = function->parameters.length;
            #line 126 "src/analyzer/expression/ExpressionValidate.pv"
            if (function->typed_variadic) {
                #line 127 "src/analyzer/expression/ExpressionValidate.pv"
                required_parameters_length -= 1;
            }

            #line 130 "src/analyzer/expression/ExpressionValidate.pv"
            if ((!function->variadic && function->parameters.length != arguments_length) || (function->variadic && arguments_length < required_parameters_length)) {
                #line 131 "src/analyzer/expression/ExpressionValidate.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 132 "src/analyzer/expression/ExpressionValidate.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 134 "src/analyzer/expression/ExpressionValidate.pv"
                if (is_member_call) {
                    #line 135 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append_usize(&message, required_parameters_length - 1);
                } else {
                    #line 137 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append_usize(&message, required_parameters_length);
                }

                #line 140 "src/analyzer/expression/ExpressionValidate.pv"
                if (function->variadic) {
                    #line 141 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&message, (struct str){ .ptr = " or more", .length = strlen(" or more") });
                }

                #line 144 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 145 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 148 "src/analyzer/expression/ExpressionValidate.pv"
            struct Iter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 149 "src/analyzer/expression/ExpressionValidate.pv"
            struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);
            #line 150 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t param_index = 0;

            #line 152 "src/analyzer/expression/ExpressionValidate.pv"
            if (is_member_call) {
                #line 153 "src/analyzer/expression/ExpressionValidate.pv"
                Iter_ref_Parameter__next(&param_iter);
                #line 154 "src/analyzer/expression/ExpressionValidate.pv"
                Iter_ref_InvokeArgument__next(&args_iter);
                #line 155 "src/analyzer/expression/ExpressionValidate.pv"
                param_index += 1;

                #line 157 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 158 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &Iter_ref_Parameter__value(&param_iter)->type;

                #line 160 "src/analyzer/expression/ExpressionValidate.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 161 "src/analyzer/expression/ExpressionValidate.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) }});
                    #line 162 "src/analyzer/expression/ExpressionValidate.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 166 "src/analyzer/expression/ExpressionValidate.pv"
            while (Iter_ref_Parameter__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
                #line 167 "src/analyzer/expression/ExpressionValidate.pv"
                if (function->typed_variadic && usize__Eq_usize__eq(param_index, function->parameters.length - 1)) {
                    #line 168 "src/analyzer/expression/ExpressionValidate.pv"
                    break;
                }

                #line 171 "src/analyzer/expression/ExpressionValidate.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 172 "src/analyzer/expression/ExpressionValidate.pv"
                struct Parameter* param = Iter_ref_Parameter__value(&param_iter);
                #line 173 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* param_type = &param->type;

                #line 175 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2 != 0 && generic_map2->map.length > 0) {
                    #line 176 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 178 "src/analyzer/expression/ExpressionValidate.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 181 "src/analyzer/expression/ExpressionValidate.pv"
                if (param_type == 0) {
                    #line 182 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_expression(context, arg->value, "Unable to resolve parameter type");
                    #line 183 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 186 "src/analyzer/expression/ExpressionValidate.pv"
                Expression__validate_type(arg->value, context, param_type, true);

                #line 188 "src/analyzer/expression/ExpressionValidate.pv"
                if (arg->name == 0 && param->name != 0 && !str__Eq_str__eq(param->name->value, (struct str){ .ptr = "self", .length = strlen("self") }) && !str__Eq_str__eq(param->name->value, arg->value->token->value)) {
                    #line 189 "src/analyzer/expression/ExpressionValidate.pv"
                    struct String label = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 190 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&label, param->name->value);
                    #line 191 "src/analyzer/expression/ExpressionValidate.pv"
                    String__append(&label, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 192 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__inlay_hint_before_expression(context, arg->value, String__c_str(&label), INLAY_HINT_KIND__PARAMETER, false, true);
                }

                #line 195 "src/analyzer/expression/ExpressionValidate.pv"
                param_index += 1;
            }

            #line 198 "src/analyzer/expression/ExpressionValidate.pv"
            if (function->typed_variadic) {
                #line 199 "src/analyzer/expression/ExpressionValidate.pv"
                struct Parameter* variadic_param = Array_Parameter__get(&function->parameters, function->parameters.length - 1);
                #line 200 "src/analyzer/expression/ExpressionValidate.pv"
                if (variadic_param == 0) {
                    #line 200 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 202 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* variadic_type = &variadic_param->type;

                #line 204 "src/analyzer/expression/ExpressionValidate.pv"
                if (generic_map2 != 0 && generic_map2->map.length > 0) {
                    #line 205 "src/analyzer/expression/ExpressionValidate.pv"
                    variadic_type = Context__resolve_type(context->allocator, variadic_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 207 "src/analyzer/expression/ExpressionValidate.pv"
                    variadic_type = Context__resolve_type(context->allocator, variadic_type, generic_map, 0);
                }

                #line 210 "src/analyzer/expression/ExpressionValidate.pv"
                if (variadic_type == 0) {
                    #line 211 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, token, "Unable to resolve variadic parameter type");
                    #line 212 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 215 "src/analyzer/expression/ExpressionValidate.pv"
                struct Type* element_type = 0;
                #line 216 "src/analyzer/expression/ExpressionValidate.pv"
                switch (variadic_type->type) {
                    #line 217 "src/analyzer/expression/ExpressionValidate.pv"
                    case TYPE__INDIRECT: {
                        #line 217 "src/analyzer/expression/ExpressionValidate.pv"
                        struct Indirect* indirect = variadic_type->indirect_value;
                        #line 218 "src/analyzer/expression/ExpressionValidate.pv"
                        switch (indirect->to.type) {
                            #line 219 "src/analyzer/expression/ExpressionValidate.pv"
                            case TYPE__SEQUENCE: {
                                #line 219 "src/analyzer/expression/ExpressionValidate.pv"
                                struct Sequence* sequence = indirect->to.sequence_value;
                                #line 220 "src/analyzer/expression/ExpressionValidate.pv"
                                element_type = &sequence->element;
                            } break;
                            #line 222 "src/analyzer/expression/ExpressionValidate.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 225 "src/analyzer/expression/ExpressionValidate.pv"
                    default: {
                    } break;
                }

                #line 228 "src/analyzer/expression/ExpressionValidate.pv"
                if (element_type == 0) {
                    #line 229 "src/analyzer/expression/ExpressionValidate.pv"
                    Context__error_token(context, token, "Typed variadic parameter must lower to a slice");
                    #line 230 "src/analyzer/expression/ExpressionValidate.pv"
                    return false;
                }

                #line 233 "src/analyzer/expression/ExpressionValidate.pv"
                uintptr_t arg_i = required_parameters_length;
                #line 234 "src/analyzer/expression/ExpressionValidate.pv"
                while (arg_i < arguments->length) {
                    #line 235 "src/analyzer/expression/ExpressionValidate.pv"
                    Expression__validate_typed_variadic_argument(context, arguments->data[arg_i].value, element_type);
                    #line 236 "src/analyzer/expression/ExpressionValidate.pv"
                    arg_i += 1;
                }
            }

            #line 240 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 242 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION_C: {
            #line 242 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 243 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__CLASS_CPP: {
            #line 243 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 244 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNKNOWN_C: {
            #line 244 "src/analyzer/expression/ExpressionValidate.pv"
            return true;
        } break;
        #line 245 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
            #line 245 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 248 "src/analyzer/expression/ExpressionValidate.pv"
    return false;
}

#line 251 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 252 "src/analyzer/expression/ExpressionValidate.pv"
    uintptr_t arguments_length = arguments->length;

    #line 254 "src/analyzer/expression/ExpressionValidate.pv"
    if (variant->types.length != arguments_length) {
        #line 255 "src/analyzer/expression/ExpressionValidate.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 256 "src/analyzer/expression/ExpressionValidate.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 257 "src/analyzer/expression/ExpressionValidate.pv"
        String__append_usize(&message, variant->types.length);
        #line 258 "src/analyzer/expression/ExpressionValidate.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 259 "src/analyzer/expression/ExpressionValidate.pv"
        return false;
    }

    #line 262 "src/analyzer/expression/ExpressionValidate.pv"
    if (variant->names.length > 0) {
        #line 263 "src/analyzer/expression/ExpressionValidate.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 263 "src/analyzer/expression/ExpressionValidate.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 263 "src/analyzer/expression/ExpressionValidate.pv"
            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

            #line 264 "src/analyzer/expression/ExpressionValidate.pv"
            if (arg->name == 0) {
                #line 265 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, token, "Expected named field argument");
                #line 266 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 269 "src/analyzer/expression/ExpressionValidate.pv"
            uintptr_t field_i = 0;
            #line 270 "src/analyzer/expression/ExpressionValidate.pv"
            bool found = false;
            #line 271 "src/analyzer/expression/ExpressionValidate.pv"
            while (field_i < variant->names.length) {
                #line 272 "src/analyzer/expression/ExpressionValidate.pv"
                if (str__Eq_str__eq(variant->names.data[field_i], arg->name->value)) {
                    #line 273 "src/analyzer/expression/ExpressionValidate.pv"
                    found = true;
                    #line 274 "src/analyzer/expression/ExpressionValidate.pv"
                    break;
                }
                #line 276 "src/analyzer/expression/ExpressionValidate.pv"
                field_i += 1;
            }

            #line 279 "src/analyzer/expression/ExpressionValidate.pv"
            if (!found) {
                #line 280 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_token(context, arg->name, "Field not found in enum variant");
                #line 281 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 284 "src/analyzer/expression/ExpressionValidate.pv"
            struct Type* param_type = variant->types.data + field_i;
            #line 285 "src/analyzer/expression/ExpressionValidate.pv"
            if (generic_map != 0) {
                #line 286 "src/analyzer/expression/ExpressionValidate.pv"
                param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
            }

            #line 289 "src/analyzer/expression/ExpressionValidate.pv"
            if (param_type == 0) {
                #line 290 "src/analyzer/expression/ExpressionValidate.pv"
                Context__error_expression(context, arg->value, "Unable to resolve field type");
                #line 291 "src/analyzer/expression/ExpressionValidate.pv"
                return false;
            }

            #line 294 "src/analyzer/expression/ExpressionValidate.pv"
            Expression__validate_type(arg->value, context, param_type, true);
        } }

        #line 297 "src/analyzer/expression/ExpressionValidate.pv"
        return true;
    }

    #line 300 "src/analyzer/expression/ExpressionValidate.pv"
    struct Iter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 301 "src/analyzer/expression/ExpressionValidate.pv"
    struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 303 "src/analyzer/expression/ExpressionValidate.pv"
    while (Iter_ref_Type__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
        #line 304 "src/analyzer/expression/ExpressionValidate.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
        #line 305 "src/analyzer/expression/ExpressionValidate.pv"
        struct Type* param_type = Iter_ref_Type__value(&param_iter);

        #line 307 "src/analyzer/expression/ExpressionValidate.pv"
        if (generic_map != 0) {
            #line 308 "src/analyzer/expression/ExpressionValidate.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 311 "src/analyzer/expression/ExpressionValidate.pv"
        if (param_type == 0) {
            #line 312 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_expression(context, arg->value, "Unable to resolve parameter type");
            #line 313 "src/analyzer/expression/ExpressionValidate.pv"
            return false;
        }

        #line 316 "src/analyzer/expression/ExpressionValidate.pv"
        Expression__validate_type(arg->value, context, param_type, true);
    }

    #line 319 "src/analyzer/expression/ExpressionValidate.pv"
    return true;
}

#line 322 "src/analyzer/expression/ExpressionValidate.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 323 "src/analyzer/expression/ExpressionValidate.pv"
    switch (type->type) {
        #line 324 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__TUPLE: {
            #line 324 "src/analyzer/expression/ExpressionValidate.pv"
            return type;
        } break;
        #line 325 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION: {
            #line 325 "src/analyzer/expression/ExpressionValidate.pv"
            struct Function* func_info = type->function_value._0;
            #line 325 "src/analyzer/expression/ExpressionValidate.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 326 "src/analyzer/expression/ExpressionValidate.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 327 "src/analyzer/expression/ExpressionValidate.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} }});
            }
            #line 329 "src/analyzer/expression/ExpressionValidate.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 331 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__FUNCTION_C: {
            #line 331 "src/analyzer/expression/ExpressionValidate.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 331 "src/analyzer/expression/ExpressionValidate.pv"
            return &func_info->return_type;
        } break;
        #line 332 "src/analyzer/expression/ExpressionValidate.pv"
        case TYPE__UNKNOWN_C: {
            #line 332 "src/analyzer/expression/ExpressionValidate.pv"
            return type;
        } break;
        #line 333 "src/analyzer/expression/ExpressionValidate.pv"
        default: {
            #line 333 "src/analyzer/expression/ExpressionValidate.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 336 "src/analyzer/expression/ExpressionValidate.pv"
    return 0;
}

#line 339 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 340 "src/analyzer/expression/ExpressionValidate.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 340 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 342 "src/analyzer/expression/ExpressionValidate.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 343 "src/analyzer/expression/ExpressionValidate.pv"
    if (func_return_type == 0) {
        #line 343 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 345 "src/analyzer/expression/ExpressionValidate.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 346 "src/analyzer/expression/ExpressionValidate.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 349 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 350 "src/analyzer/expression/ExpressionValidate.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 350 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 352 "src/analyzer/expression/ExpressionValidate.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 353 "src/analyzer/expression/ExpressionValidate.pv"
    if (func_return_type == 0) {
        #line 353 "src/analyzer/expression/ExpressionValidate.pv"
        return 0;
    }

    #line 355 "src/analyzer/expression/ExpressionValidate.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, func_return_type);
}

#line 7 "src/analyzer/expression/ParseTypeExpression.pv"
void Expression__record_static_member_symbol(struct Context* context, struct Token* member, struct Type* member_type, struct Type* owner_type) {
    #line 8 "src/analyzer/expression/ParseTypeExpression.pv"
    if (!Context__should_record_symbols(context)) {
        #line 8 "src/analyzer/expression/ParseTypeExpression.pv"
        return;
    }

    #line 10 "src/analyzer/expression/ParseTypeExpression.pv"
    struct Token* member_def_token = 0;
    #line 11 "src/analyzer/expression/ParseTypeExpression.pv"
    struct str member_def_path = context->path;

    #line 13 "src/analyzer/expression/ParseTypeExpression.pv"
    switch (member_type->type) {
        #line 14 "src/analyzer/expression/ParseTypeExpression.pv"
        case TYPE__FUNCTION: {
            #line 14 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Function* func_info = member_type->function_value._0;
            #line 15 "src/analyzer/expression/ParseTypeExpression.pv"
            member_def_token = func_info->name;
            #line 16 "src/analyzer/expression/ParseTypeExpression.pv"
            if (func_info->context != 0) {
                #line 16 "src/analyzer/expression/ParseTypeExpression.pv"
                member_def_path = func_info->context->path;
            }
        } break;
        #line 18 "src/analyzer/expression/ParseTypeExpression.pv"
        default: {
            #line 19 "src/analyzer/expression/ParseTypeExpression.pv"
            switch (Type__resolve_typedef(owner_type)->type) {
                #line 20 "src/analyzer/expression/ParseTypeExpression.pv"
                case TYPE__STRUCT: {
                    #line 20 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct Struct* struct_info = Type__resolve_typedef(owner_type)->struct_value._0;
                    #line 21 "src/analyzer/expression/ParseTypeExpression.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 21 "src/analyzer/expression/ParseTypeExpression.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 21 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 22 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member->value);
                        #line 23 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (impl_const_ptr != 0) {
                            #line 24 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct ImplConst* impl_const = *impl_const_ptr;
                            #line 25 "src/analyzer/expression/ParseTypeExpression.pv"
                            member_def_token = impl_const->name;
                            #line 26 "src/analyzer/expression/ParseTypeExpression.pv"
                            member_def_path = impl_const->context->path;
                        }
                    } }
                } break;
                #line 30 "src/analyzer/expression/ParseTypeExpression.pv"
                case TYPE__ENUM: {
                    #line 30 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct Enum* enum_info = Type__resolve_typedef(owner_type)->enum_value._0;
                    #line 31 "src/analyzer/expression/ParseTypeExpression.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 31 "src/analyzer/expression/ParseTypeExpression.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 31 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 32 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member->value);
                        #line 33 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (impl_const_ptr != 0) {
                            #line 34 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct ImplConst* impl_const = *impl_const_ptr;
                            #line 35 "src/analyzer/expression/ParseTypeExpression.pv"
                            member_def_token = impl_const->name;
                            #line 36 "src/analyzer/expression/ParseTypeExpression.pv"
                            member_def_path = impl_const->context->path;
                        }
                    } }
                } break;
                #line 40 "src/analyzer/expression/ParseTypeExpression.pv"
                default: {
                } break;
            }
        } break;
    }

    #line 45 "src/analyzer/expression/ParseTypeExpression.pv"
    struct String member_type_label = Naming__get_type_decl(&context->root->naming_decl, member_type, context->type_self, 0);
    #line 46 "src/analyzer/expression/ParseTypeExpression.pv"
    Context__record_symbol(context, member, String__as_str(&member_type_label), member_def_path, member_def_token);
}

#line 49 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics) {
    #line 50 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 51 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* dot_token = Context__current(context);
        #line 52 "src/analyzer/expression/ParseTypeExpression.pv"
        Context__next_token(context);
        #line 53 "src/analyzer/expression/ParseTypeExpression.pv"
        if (dot_token != 0) {
            #line 53 "src/analyzer/expression/ParseTypeExpression.pv"
            Context__record_member_completion(context, dot_token, enum_type, true);
        }
        #line 54 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* variant_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 55 "src/analyzer/expression/ParseTypeExpression.pv"
        if (variant_name == 0) {
            #line 55 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 57 "src/analyzer/expression/ParseTypeExpression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, variant_name);

        #line 59 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (variant_result.type) {
            #line 60 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__NONE: {
                #line 61 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__error_token(context, variant_name, "Unable to find enum variant or function");
                #line 62 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            } break;
            #line 64 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__FUNCTION: {
                #line 64 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Function* function = variant_result.function_value._0;
                #line 64 "src/analyzer/expression/ParseTypeExpression.pv"
                struct GenericMap* generic_map = variant_result.function_value._1;
                #line 65 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* member_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} }});
                #line 66 "src/analyzer/expression/ParseTypeExpression.pv"
                Expression__record_static_member_symbol(context, variant_name, member_type, enum_type);

                #line 68 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 69 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                }

                #line 72 "src/analyzer/expression/ParseTypeExpression.pv"
                struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                #line 73 "src/analyzer/expression/ParseTypeExpression.pv"
                if (parsed == 0) {
                    #line 73 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }
                #line 74 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Array_InvokeArgument arguments = parsed->arguments;

                #line 76 "src/analyzer/expression/ParseTypeExpression.pv"
                if (parsed->open_paren != 0 && parsed->close_paren != 0) {
                    #line 77 "src/analyzer/expression/ParseTypeExpression.pv"
                    Expression__record_function_signature(context, member_type, parsed->open_paren, parsed->close_paren, parsed->comma_positions, false);
                }

                #line 80 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                    #line 80 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 82 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
                #line 83 "src/analyzer/expression/ParseTypeExpression.pv"
                if (func_return_type == 0) {
                    #line 83 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 85 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                #line 86 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
            } break;
            #line 88 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 88 "src/analyzer/expression/ParseTypeExpression.pv"
                struct EnumVariant* variant = variant_result.enumvariant_value;
                #line 89 "src/analyzer/expression/ParseTypeExpression.pv"
                struct String variant_type_label = Naming__get_type_decl(&context->root->naming_decl, enum_type, context->type_self, 0);
                #line 90 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__record_symbol(context, variant_name, String__as_str(&variant_type_label), variant->parent->context->path, variant->name);

                #line 92 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 94 "src/analyzer/expression/ParseTypeExpression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 95 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                    #line 96 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (parsed == 0) {
                        #line 96 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                    #line 97 "src/analyzer/expression/ParseTypeExpression.pv"
                    arguments = parsed->arguments;
                } else if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{") && variant->names.length > 0) {
                    #line 99 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
                        #line 99 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }

                    #line 101 "src/analyzer/expression/ParseTypeExpression.pv"
                    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                        #line 102 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                        #line 103 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (name == 0) {
                            #line 103 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }

                        #line 105 "src/analyzer/expression/ParseTypeExpression.pv"
                        struct Expression* value = 0;
                        #line 106 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                            #line 107 "src/analyzer/expression/ParseTypeExpression.pv"
                            value = Expression__parse(context, generics);
                        } else {
                            #line 109 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Type* return_type = Context__get_value(context, name->value);
                            #line 110 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (return_type == 0) {
                                #line 111 "src/analyzer/expression/ParseTypeExpression.pv"
                                Context__error_token(context, name, "Unable to find variable with this name");
                                #line 112 "src/analyzer/expression/ParseTypeExpression.pv"
                                return 0;
                            }
                            #line 114 "src/analyzer/expression/ParseTypeExpression.pv"
                            value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
                        }

                        #line 117 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (value == 0) {
                            #line 117 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }

                        #line 119 "src/analyzer/expression/ParseTypeExpression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 121 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                            #line 122 "src/analyzer/expression/ParseTypeExpression.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                            #line 123 "src/analyzer/expression/ParseTypeExpression.pv"
                            return 0;
                        }
                    }

                    #line 127 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                        #line 127 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                }

                #line 130 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

                #line 132 "src/analyzer/expression/ParseTypeExpression.pv"
                struct GenericMap* generic_map = Type__get_generic_map(enum_type, context);
                #line 133 "src/analyzer/expression/ParseTypeExpression.pv"
                if (!Expression__validate_enum_arguments(context, token, variant, &arguments, generic_map)) {
                    #line 133 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 135 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
            } break;
            #line 137 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__CONST: {
                #line 137 "src/analyzer/expression/ParseTypeExpression.pv"
                struct ImplConst* impl_const = variant_result.const_value;
                #line 138 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* const_type = ArenaAllocator__store_Type(context->allocator, &impl_const->type);
                #line 139 "src/analyzer/expression/ParseTypeExpression.pv"
                Expression__record_static_member_symbol(context, variant_name, const_type, enum_type);
                #line 140 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 141 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, const_type);
            } break;
            #line 143 "src/analyzer/expression/ParseTypeExpression.pv"
            case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                #line 144 "src/analyzer/expression/ParseTypeExpression.pv"
                struct String variant_type_label = Naming__get_type_decl(&context->root->naming_decl, enum_type, context->type_self, 0);
                #line 145 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__record_symbol(context, variant_name, String__as_str(&variant_type_label), context->path, 0);
                #line 146 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 147 "src/analyzer/expression/ParseTypeExpression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, enum_type);
            } break;
        }
    }

    #line 162 "src/analyzer/expression/ParseTypeExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 165 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 166 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 167 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* dot_token = Context__current(context);
        #line 168 "src/analyzer/expression/ParseTypeExpression.pv"
        Context__next_token(context);
        #line 169 "src/analyzer/expression/ParseTypeExpression.pv"
        if (dot_token != 0) {
            #line 169 "src/analyzer/expression/ParseTypeExpression.pv"
            Context__record_member_completion(context, dot_token, struct_type, true);
        }
        #line 170 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 171 "src/analyzer/expression/ParseTypeExpression.pv"
        if (member == 0) {
            #line 171 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 173 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 174 "src/analyzer/expression/ParseTypeExpression.pv"
        if (member_type == 0) {
            #line 174 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }
        #line 175 "src/analyzer/expression/ParseTypeExpression.pv"
        Expression__record_static_member_symbol(context, member, member_type, struct_type);

        #line 177 "src/analyzer/expression/ParseTypeExpression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 179 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 180 "src/analyzer/expression/ParseTypeExpression.pv"
            switch (member_type->type) {
                #line 181 "src/analyzer/expression/ParseTypeExpression.pv"
                case TYPE__FUNCTION: {
                    #line 182 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                } break;
                #line 184 "src/analyzer/expression/ParseTypeExpression.pv"
                default: {
                    #line 185 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct Expression* struct_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
                    #line 186 "src/analyzer/expression/ParseTypeExpression.pv"
                    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = struct_expr, ._1 = member->value} }, member_type);
                } break;
            }
        } else {
            #line 190 "src/analyzer/expression/ParseTypeExpression.pv"
            struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
            #line 191 "src/analyzer/expression/ParseTypeExpression.pv"
            if (parsed == 0) {
                #line 191 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
            #line 192 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Array_InvokeArgument arguments = parsed->arguments;

            #line 194 "src/analyzer/expression/ParseTypeExpression.pv"
            switch (member_type->type) {
                #line 195 "src/analyzer/expression/ParseTypeExpression.pv"
                case TYPE__FUNCTION: {
                    #line 196 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (parsed->open_paren != 0 && parsed->close_paren != 0) {
                        #line 197 "src/analyzer/expression/ParseTypeExpression.pv"
                        Expression__record_function_signature(context, member_type, parsed->open_paren, parsed->close_paren, parsed->comma_positions, false);
                    }
                } break;
                #line 200 "src/analyzer/expression/ParseTypeExpression.pv"
                default: {
                } break;
            }

            #line 203 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 203 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 205 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 206 "src/analyzer/expression/ParseTypeExpression.pv"
            if (func_return_type == 0) {
                #line 206 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 208 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 209 "src/analyzer/expression/ParseTypeExpression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 212 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 214 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 215 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 216 "src/analyzer/expression/ParseTypeExpression.pv"
            if (name == 0) {
                #line 216 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 218 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = 0;
            #line 219 "src/analyzer/expression/ParseTypeExpression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 220 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 222 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 223 "src/analyzer/expression/ParseTypeExpression.pv"
                if (return_type == 0) {
                    #line 224 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 225 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 228 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 231 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 231 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 233 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 235 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 236 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 237 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 241 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 241 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 243 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Type* resolved_struct_type = struct_type;
        #line 244 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (struct_type->type) {
            #line 245 "src/analyzer/expression/ParseTypeExpression.pv"
            case TYPE__SELF: {
                #line 246 "src/analyzer/expression/ParseTypeExpression.pv"
                if (context->type_self == 0) {
                    #line 246 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }
                #line 247 "src/analyzer/expression/ParseTypeExpression.pv"
                resolved_struct_type = context->type_self;
            } break;
            #line 249 "src/analyzer/expression/ParseTypeExpression.pv"
            default: {
            } break;
        }

        #line 252 "src/analyzer/expression/ParseTypeExpression.pv"
        switch (resolved_struct_type->type) {
            #line 253 "src/analyzer/expression/ParseTypeExpression.pv"
            case TYPE__STRUCT: {
                #line 253 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Struct* struct_info = resolved_struct_type->struct_value._0;
                #line 254 "src/analyzer/expression/ParseTypeExpression.pv"
                uintptr_t field_i = 0;
                #line 255 "src/analyzer/expression/ParseTypeExpression.pv"
                while (field_i < struct_info->fields.length) {
                    #line 256 "src/analyzer/expression/ParseTypeExpression.pv"
                    struct HashMapBucket_str_StructField* bucket = struct_info->fields.data + field_i;
                    #line 257 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (bucket == 0) {
                        #line 257 "src/analyzer/expression/ParseTypeExpression.pv"
                        return 0;
                    }
                    #line 258 "src/analyzer/expression/ParseTypeExpression.pv"
                    if (bucket->value.default_token_start != 0) {
                        #line 259 "src/analyzer/expression/ParseTypeExpression.pv"
                        bool already_provided = false;
                        #line 260 "src/analyzer/expression/ParseTypeExpression.pv"
                        uintptr_t arg_i = 0;
                        #line 261 "src/analyzer/expression/ParseTypeExpression.pv"
                        while (arg_i < fields.length) {
                            #line 262 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Token* arg_name = fields.data[arg_i].name;
                            #line 263 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (arg_name != 0 && str__Eq_str__eq(arg_name->value, bucket->key)) {
                                #line 264 "src/analyzer/expression/ParseTypeExpression.pv"
                                already_provided = true;
                                #line 265 "src/analyzer/expression/ParseTypeExpression.pv"
                                break;
                            }
                            #line 267 "src/analyzer/expression/ParseTypeExpression.pv"
                            arg_i += 1;
                        }

                        #line 270 "src/analyzer/expression/ParseTypeExpression.pv"
                        if (!already_provided) {
                            #line 271 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Module* module = struct_info->module;
                            #line 272 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Context* struct_context = &module->context;
                            #line 273 "src/analyzer/expression/ParseTypeExpression.pv"
                            uintptr_t saved_pos = struct_context->pos;
                            #line 274 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct_context->pos = bucket->value.default_token_start;
                            #line 275 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct Expression* default_expr = Expression__parse(struct_context, &struct_info->generics);
                            #line 276 "src/analyzer/expression/ParseTypeExpression.pv"
                            struct_context->pos = saved_pos;

                            #line 278 "src/analyzer/expression/ParseTypeExpression.pv"
                            if (default_expr != 0) {
                                #line 279 "src/analyzer/expression/ParseTypeExpression.pv"
                                struct Token* field_name = bucket->value.name;
                                #line 280 "src/analyzer/expression/ParseTypeExpression.pv"
                                Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = field_name, .value = default_expr });
                            }
                        }
                    }
                    #line 284 "src/analyzer/expression/ParseTypeExpression.pv"
                    field_i += 1;
                }
            } break;
            #line 287 "src/analyzer/expression/ParseTypeExpression.pv"
            default: {
            } break;
        }

        #line 290 "src/analyzer/expression/ParseTypeExpression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 291 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 291 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 293 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 294 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 296 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 298 "src/analyzer/expression/ParseTypeExpression.pv"
        uintptr_t field_index = 0;
        #line 299 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 300 "src/analyzer/expression/ParseTypeExpression.pv"
            struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 301 "src/analyzer/expression/ParseTypeExpression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 302 "src/analyzer/expression/ParseTypeExpression.pv"
            String__append_usize(&name, field_index);
            #line 303 "src/analyzer/expression/ParseTypeExpression.pv"
            struct str name_str = String__as_str(&name);

            #line 305 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token name_token = *Context__current(context);
            #line 306 "src/analyzer/expression/ParseTypeExpression.pv"
            name_token.value = name_str;

            #line 308 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 309 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 309 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 311 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, &name_token),
                .value = value,
            });

            #line 316 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 317 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 318 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 321 "src/analyzer/expression/ParseTypeExpression.pv"
            field_index += 1;
        }

        #line 324 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 324 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 326 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 327 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 330 "src/analyzer/expression/ParseTypeExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 333 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 334 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 335 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 337 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 338 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 339 "src/analyzer/expression/ParseTypeExpression.pv"
            if (name == 0) {
                #line 339 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 341 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* value = 0;
            #line 342 "src/analyzer/expression/ParseTypeExpression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 343 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 345 "src/analyzer/expression/ParseTypeExpression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 346 "src/analyzer/expression/ParseTypeExpression.pv"
                if (return_type == 0) {
                    #line 347 "src/analyzer/expression/ParseTypeExpression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 348 "src/analyzer/expression/ParseTypeExpression.pv"
                    return 0;
                }

                #line 351 "src/analyzer/expression/ParseTypeExpression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 354 "src/analyzer/expression/ParseTypeExpression.pv"
            if (value == 0) {
                #line 354 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 356 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 358 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 359 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 360 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 364 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 364 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 366 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 366 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 368 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 370 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 372 "src/analyzer/expression/ParseTypeExpression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 373 "src/analyzer/expression/ParseTypeExpression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 374 "src/analyzer/expression/ParseTypeExpression.pv"
            if (argument == 0) {
                #line 374 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }

            #line 376 "src/analyzer/expression/ParseTypeExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

            #line 378 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 379 "src/analyzer/expression/ParseTypeExpression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 380 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 384 "src/analyzer/expression/ParseTypeExpression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 384 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 386 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 389 "src/analyzer/expression/ParseTypeExpression.pv"
    return parent;
}

#line 392 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 393 "src/analyzer/expression/ParseTypeExpression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 395 "src/analyzer/expression/ParseTypeExpression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 396 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* placement = 0;
        #line 397 "src/analyzer/expression/ParseTypeExpression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 398 "src/analyzer/expression/ParseTypeExpression.pv"
            placement = Expression__parse(context, generics);
            #line 399 "src/analyzer/expression/ParseTypeExpression.pv"
            if (placement == 0) {
                #line 399 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
            #line 400 "src/analyzer/expression/ParseTypeExpression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 400 "src/analyzer/expression/ParseTypeExpression.pv"
                return 0;
            }
        }

        #line 403 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 404 "src/analyzer/expression/ParseTypeExpression.pv"
        if (expression == 0) {
            #line 404 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 406 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 407 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { .placement = placement, .expression = expression } } }, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 409 "src/analyzer/expression/ParseTypeExpression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 410 "src/analyzer/expression/ParseTypeExpression.pv"
        if (expression == 0) {
            #line 410 "src/analyzer/expression/ParseTypeExpression.pv"
            return 0;
        }

        #line 412 "src/analyzer/expression/ParseTypeExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &context->root->type_unknown);
    }

    #line 415 "src/analyzer/expression/ParseTypeExpression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 416 "src/analyzer/expression/ParseTypeExpression.pv"
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
struct Type* Expression__make_optional_unwrap_return_type(struct Context* context, struct Token* token, struct Type* type) {
    #line 27 "src/analyzer/expression/PostfixExpression.pv"
    switch (type->type) {
        #line 28 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__INDIRECT: {
            #line 28 "src/analyzer/expression/PostfixExpression.pv"
            struct Indirect* pointer = type->indirect_value;
            #line 29 "src/analyzer/expression/PostfixExpression.pv"
            if (pointer->type == INDIRECT_TYPE__POINTER || pointer->type == INDIRECT_TYPE__CONST_POINTER) {
                #line 30 "src/analyzer/expression/PostfixExpression.pv"
                switch (pointer->to.type) {
                    #line 31 "src/analyzer/expression/PostfixExpression.pv"
                    case TYPE__INDIRECT: {
                        #line 31 "src/analyzer/expression/PostfixExpression.pv"
                        struct Indirect* reference = pointer->to.indirect_value;
                        #line 32 "src/analyzer/expression/PostfixExpression.pv"
                        if (reference->type == INDIRECT_TYPE__REFERENCE) {
                            #line 33 "src/analyzer/expression/PostfixExpression.pv"
                            struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect[]){(struct Indirect) { .type = pointer->type, .to = reference->to }});
                            #line 34 "src/analyzer/expression/PostfixExpression.pv"
                            return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
                        }
                    } break;
                    #line 37 "src/analyzer/expression/PostfixExpression.pv"
                    default: {
                    } break;
                }
            }
        } break;
        #line 41 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 44 "src/analyzer/expression/PostfixExpression.pv"
    Context__error_token(context, token, "? can only be used on *&T values");
    #line 45 "src/analyzer/expression/PostfixExpression.pv"
    return 0;
}

#line 48 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_optional_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 49 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);
    #line 50 "src/analyzer/expression/PostfixExpression.pv"
    if (token == 0) {
        #line 50 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }
    #line 51 "src/analyzer/expression/PostfixExpression.pv"
    bool is_member_access = Context__check_value(context, TOKEN_TYPE__SYMBOL, ".");

    #line 53 "src/analyzer/expression/PostfixExpression.pv"
    if (!Type__is_pointer(&inner->return_type)) {
        #line 54 "src/analyzer/expression/PostfixExpression.pv"
        if (is_member_access) {
            #line 55 "src/analyzer/expression/PostfixExpression.pv"
            Context__error_token(context, token, "?. can only be used on pointer values");
        } else {
            #line 57 "src/analyzer/expression/PostfixExpression.pv"
            Context__error_token(context, token, "? can only be used on pointer values");
        }
        #line 59 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 62 "src/analyzer/expression/PostfixExpression.pv"
    if (!is_member_access) {
        #line 63 "src/analyzer/expression/PostfixExpression.pv"
        struct Type* return_type = Expression__make_optional_unwrap_return_type(context, token, &inner->return_type);
        #line 64 "src/analyzer/expression/PostfixExpression.pv"
        if (return_type == 0) {
            #line 64 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 66 "src/analyzer/expression/PostfixExpression.pv"
        struct Expression* value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "*", .length = strlen("*") }, ._1 = inner} }, return_type);
        #line 67 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__OPTIONAL_EXPRESSION, .optionalexpression_value = { ._0 = inner, ._1 = value} }, return_type);
    }

    #line 70 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* value = Expression__parse_instance_member_expression_inner(context, inner, generics, true);
    #line 71 "src/analyzer/expression/PostfixExpression.pv"
    if (value == 0) {
        #line 71 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 73 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* return_type = Expression__make_optional_return_type(context, value->token, &value->return_type);
    #line 74 "src/analyzer/expression/PostfixExpression.pv"
    if (return_type == 0) {
        #line 74 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 76 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__OPTIONAL_EXPRESSION, .optionalexpression_value = { ._0 = inner, ._1 = value} }, return_type);
}

#line 79 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 80 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* dot_token = Context__current(context);
    #line 81 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 81 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }
    #line 82 "src/analyzer/expression/PostfixExpression.pv"
    if (dot_token != 0) {
        #line 82 "src/analyzer/expression/PostfixExpression.pv"
        Context__record_member_completion(context, dot_token, &inner->return_type, true);
    }

    #line 84 "src/analyzer/expression/PostfixExpression.pv"
    switch (inner->return_type.type) {
        #line 85 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 86 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 87 "src/analyzer/expression/PostfixExpression.pv"
        default: {
            #line 88 "src/analyzer/expression/PostfixExpression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 89 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        } break;
    }

    #line 93 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 94 "src/analyzer/expression/PostfixExpression.pv"
    if (member == 0) {
        #line 94 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 96 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 97 "src/analyzer/expression/PostfixExpression.pv"
    if (member_type == 0) {
        #line 97 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 99 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 102 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 103 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__parse_instance_member_expression_inner(context, inner, generics, false);
}

#line 106 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_instance_member_expression_inner(struct Context* context, struct Expression* inner, struct Generics* generics, bool allow_pointer) {
    #line 107 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* dot_token = Context__current(context);
    #line 108 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 108 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }
    #line 109 "src/analyzer/expression/PostfixExpression.pv"
    if (dot_token != 0) {
        #line 109 "src/analyzer/expression/PostfixExpression.pv"
        Context__record_member_completion(context, dot_token, &inner->return_type, false);
    }

    #line 111 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* member_name = Context__current(context);
    #line 112 "src/analyzer/expression/PostfixExpression.pv"
    if (member_name == 0) {
        #line 113 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_token(context, dot_token, "no token found after .");
        #line 114 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 117 "src/analyzer/expression/PostfixExpression.pv"
    if (member_name->type != TOKEN_TYPE__NUMBER && member_name->type != TOKEN_TYPE__IDENTIFIER) {
        #line 118 "src/analyzer/expression/PostfixExpression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 121 "src/analyzer/expression/PostfixExpression.pv"
    Context__next_token(context);

    #line 123 "src/analyzer/expression/PostfixExpression.pv"
    if (!allow_pointer && Type__is_pointer(&inner->return_type)) {
        #line 124 "src/analyzer/expression/PostfixExpression.pv"
        struct Function* pointer_impl_function = Root__find_type_impl_function(context->root, &inner->return_type, member_name->value, 0);
        #line 125 "src/analyzer/expression/PostfixExpression.pv"
        if (pointer_impl_function == 0) {
            #line 126 "src/analyzer/expression/PostfixExpression.pv"
            Context__error_token(context, dot_token, ". cannot be used on a *T pointer; use ?. or check for null with `if x == null { ... }` first");
        }
    }

    #line 130 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 131 "src/analyzer/expression/PostfixExpression.pv"
    if (member_type == 0) {
        #line 131 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }
    #line 134 "src/analyzer/expression/PostfixExpression.pv"
    if (Context__should_record_symbols(context)) {
        #line 135 "src/analyzer/expression/PostfixExpression.pv"
        struct Token* member_def_token = 0;
        #line 136 "src/analyzer/expression/PostfixExpression.pv"
        struct str member_def_path = context->path;
        #line 137 "src/analyzer/expression/PostfixExpression.pv"
        switch (member_type->type) {
            #line 138 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION: {
                #line 138 "src/analyzer/expression/PostfixExpression.pv"
                struct Function* mfunc = member_type->function_value._0;
                #line 139 "src/analyzer/expression/PostfixExpression.pv"
                member_def_token = mfunc->name;
                #line 140 "src/analyzer/expression/PostfixExpression.pv"
                if (mfunc->context != 0) {
                    #line 140 "src/analyzer/expression/PostfixExpression.pv"
                    member_def_path = mfunc->context->path;
                }
            } break;
            #line 142 "src/analyzer/expression/PostfixExpression.pv"
            default: {
                #line 144 "src/analyzer/expression/PostfixExpression.pv"
                switch (Type__deref_all(&inner->return_type)->type) {
                    #line 145 "src/analyzer/expression/PostfixExpression.pv"
                    case TYPE__STRUCT: {
                        #line 145 "src/analyzer/expression/PostfixExpression.pv"
                        struct Struct* struct_info = Type__deref_all(&inner->return_type)->struct_value._0;
                        #line 146 "src/analyzer/expression/PostfixExpression.pv"
                        struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member_name->value);
                        #line 147 "src/analyzer/expression/PostfixExpression.pv"
                        if (field != 0) {
                            #line 148 "src/analyzer/expression/PostfixExpression.pv"
                            member_def_token = field->name;
                            #line 149 "src/analyzer/expression/PostfixExpression.pv"
                            member_def_path = struct_info->module->path;
                        }
                    } break;
                    #line 152 "src/analyzer/expression/PostfixExpression.pv"
                    default: {
                    } break;
                }
            } break;
        }
        #line 156 "src/analyzer/expression/PostfixExpression.pv"
        struct String member_type_label = Naming__get_type_decl(&context->root->naming_decl, member_type, context->type_self, 0);
        #line 157 "src/analyzer/expression/PostfixExpression.pv"
        Context__record_symbol(context, member_name, String__as_str(&member_type_label), member_def_path, member_def_token);
    }

    #line 160 "src/analyzer/expression/PostfixExpression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 161 "src/analyzer/expression/PostfixExpression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };
    #line 162 "src/analyzer/expression/PostfixExpression.pv"
    struct Function* func_info = 0;

    #line 164 "src/analyzer/expression/PostfixExpression.pv"
    bool is_function = false;
    #line 165 "src/analyzer/expression/PostfixExpression.pv"
    switch (member_type->type) {
        #line 166 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__FUNCTION: {
            #line 166 "src/analyzer/expression/PostfixExpression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 167 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
            #line 168 "src/analyzer/expression/PostfixExpression.pv"
            func_info = func_info2;
        } break;
        #line 170 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__FUNCTION_C: {
            #line 170 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
        } break;
        #line 171 "src/analyzer/expression/PostfixExpression.pv"
        case TYPE__UNKNOWN_C: {
            #line 171 "src/analyzer/expression/PostfixExpression.pv"
            is_function = true;
        } break;
        #line 172 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 175 "src/analyzer/expression/PostfixExpression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 176 "src/analyzer/expression/PostfixExpression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 179 "src/analyzer/expression/PostfixExpression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 180 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info == 0) {
            #line 181 "src/analyzer/expression/PostfixExpression.pv"
            Context__error_token(context, member_name, "Expected function type");
            #line 182 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 185 "src/analyzer/expression/PostfixExpression.pv"
        struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
        #line 186 "src/analyzer/expression/PostfixExpression.pv"
        if (parsed == 0) {
            #line 186 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 188 "src/analyzer/expression/PostfixExpression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 189 "src/analyzer/expression/PostfixExpression.pv"
        struct Token* name = func_info->parameters.length > 0 ? func_info->parameters.data[0].name : 0;
        #line 190 "src/analyzer/expression/PostfixExpression.pv"
        if (name != 0 && str__Eq_str__eq(name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 191 "src/analyzer/expression/PostfixExpression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = inner });
        }
        #line 193 "src/analyzer/expression/PostfixExpression.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&parsed->arguments);
        #line 193 "src/analyzer/expression/PostfixExpression.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 193 "src/analyzer/expression/PostfixExpression.pv"
            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

            #line 193 "src/analyzer/expression/PostfixExpression.pv"
            Array_InvokeArgument__append(&arguments, *arg);
        } }

        #line 195 "src/analyzer/expression/PostfixExpression.pv"
        if (func_info->generics.array.length > 0) {
            #line 196 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 197 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap combined_generics_val = GenericMap__clone(func_generics, context->allocator);
            #line 198 "src/analyzer/expression/PostfixExpression.pv"
            struct GenericMap* combined_generics = ArenaAllocator__store_GenericMap(context->allocator, &combined_generics_val);

            #line 200 "src/analyzer/expression/PostfixExpression.pv"
            if (generic_map != 0) {
                #line 201 "src/analyzer/expression/PostfixExpression.pv"
                { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&generic_map->map);
                #line 201 "src/analyzer/expression/PostfixExpression.pv"
                while (HashMapIter_str_usize__next(&__iter)) {
                    #line 201 "src/analyzer/expression/PostfixExpression.pv"
                    struct str name = HashMapIter_str_usize__value(&__iter)->_0;

                    #line 202 "src/analyzer/expression/PostfixExpression.pv"
                    struct Type* concrete_type = GenericMap__get(generic_map, name);
                    #line 203 "src/analyzer/expression/PostfixExpression.pv"
                    if (concrete_type != 0) {
                        #line 204 "src/analyzer/expression/PostfixExpression.pv"
                        if (combined_generics == 0) {
                            #line 204 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }
                        #line 205 "src/analyzer/expression/PostfixExpression.pv"
                        GenericMap__insert(combined_generics, name, *concrete_type);
                    }
                } }
            }

            #line 210 "src/analyzer/expression/PostfixExpression.pv"
            switch (member_type->type) {
                #line 211 "src/analyzer/expression/PostfixExpression.pv"
                case TYPE__FUNCTION: {
                    #line 211 "src/analyzer/expression/PostfixExpression.pv"
                    struct Function* function_info = member_type->function_value._0;
                    #line 212 "src/analyzer/expression/PostfixExpression.pv"
                    struct Type function_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = combined_generics} };
                    #line 213 "src/analyzer/expression/PostfixExpression.pv"
                    member_type = ArenaAllocator__store_Type(context->allocator, &function_type);
                } break;
                #line 215 "src/analyzer/expression/PostfixExpression.pv"
                default: {
                    #line 216 "src/analyzer/expression/PostfixExpression.pv"
                    member_type = Root__make_type_usage(context->root, member_type, &func_generics->array);
                } break;
            }
        }

        #line 221 "src/analyzer/expression/PostfixExpression.pv"
        if (parsed->open_paren != 0 && parsed->close_paren != 0) {
            #line 222 "src/analyzer/expression/PostfixExpression.pv"
            Expression__record_function_signature(context, member_type, parsed->open_paren, parsed->close_paren, parsed->comma_positions, true);
        }

        #line 225 "src/analyzer/expression/PostfixExpression.pv"
        if ((func_info->type == FUNCTION_TYPE__BUILTIN || func_info->type == FUNCTION_TYPE__METHOD_CPP)) {
            #line 226 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 227 "src/analyzer/expression/PostfixExpression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 229 "src/analyzer/expression/PostfixExpression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 232 "src/analyzer/expression/PostfixExpression.pv"
        if (generic_map != 0) {
            #line 233 "src/analyzer/expression/PostfixExpression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }
        #line 238 "src/analyzer/expression/PostfixExpression.pv"
        struct Expression* result_expr = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
        #line 239 "src/analyzer/expression/PostfixExpression.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 240 "src/analyzer/expression/PostfixExpression.pv"
        if (Expression__build_narrow_path(result_expr, &path)) {
            #line 241 "src/analyzer/expression/PostfixExpression.pv"
            struct Type* narrowed = Context__get_path_narrowing(context, String__as_str(&path));
            #line 242 "src/analyzer/expression/PostfixExpression.pv"
            if (narrowed != 0) {
                #line 243 "src/analyzer/expression/PostfixExpression.pv"
                result_expr->return_type = *narrowed;
            }
        }
        #line 246 "src/analyzer/expression/PostfixExpression.pv"
        return result_expr;
    }
}

#line 250 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 251 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
        #line 251 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 253 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 254 "src/analyzer/expression/PostfixExpression.pv"
    if (index_expr == 0) {
        #line 254 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 256 "src/analyzer/expression/PostfixExpression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]")) {
        #line 256 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 258 "src/analyzer/expression/PostfixExpression.pv"
    switch (index_expr->data.type) {
        #line 259 "src/analyzer/expression/PostfixExpression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 259 "src/analyzer/expression/PostfixExpression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 259 "src/analyzer/expression/PostfixExpression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 260 "src/analyzer/expression/PostfixExpression.pv"
            switch (target->return_type.type) {
                #line 261 "src/analyzer/expression/PostfixExpression.pv"
                case TYPE__ENUM: {
                    #line 261 "src/analyzer/expression/PostfixExpression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 262 "src/analyzer/expression/PostfixExpression.pv"
                    struct Token* enum_name = enum_info->name;
                    #line 263 "src/analyzer/expression/PostfixExpression.pv"
                    if (enum_name != 0 && str__Eq_str__eq(enum_name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 264 "src/analyzer/expression/PostfixExpression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence[]){(struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        }});
                        #line 269 "src/analyzer/expression/PostfixExpression.pv"
                        if (sequence == 0) {
                            #line 269 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }

                        #line 271 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 272 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 274 "src/analyzer/expression/PostfixExpression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 276 "src/analyzer/expression/PostfixExpression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, index_expr->token);
                        #line 277 "src/analyzer/expression/PostfixExpression.pv"
                        if (argument_name_data == 0) {
                            #line 277 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }
                        #line 278 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 279 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 281 "src/analyzer/expression/PostfixExpression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, argument_name_data);
                        #line 282 "src/analyzer/expression/PostfixExpression.pv"
                        if (argument_name_length == 0) {
                            #line 282 "src/analyzer/expression/PostfixExpression.pv"
                            return 0;
                        }
                        #line 283 "src/analyzer/expression/PostfixExpression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 285 "src/analyzer/expression/PostfixExpression.pv"
                        if (Expression__is_zero(start)) {
                            #line 286 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 287 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 289 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 294 "src/analyzer/expression/PostfixExpression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 300 "src/analyzer/expression/PostfixExpression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }});
                        #line 301 "src/analyzer/expression/PostfixExpression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 302 "src/analyzer/expression/PostfixExpression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 305 "src/analyzer/expression/PostfixExpression.pv"
                default: {
                } break;
            }
        } break;
        #line 308 "src/analyzer/expression/PostfixExpression.pv"
        default: {
        } break;
    }

    #line 311 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* index_trait_result = Expression__find_index_trait_call(context, index_expr->token, inner, index_expr);
    #line 312 "src/analyzer/expression/PostfixExpression.pv"
    if (index_trait_result != 0) {
        #line 312 "src/analyzer/expression/PostfixExpression.pv"
        return index_trait_result;
    }

    #line 314 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 315 "src/analyzer/expression/PostfixExpression.pv"
    struct Type* element_type = 0;

    #line 317 "src/analyzer/expression/PostfixExpression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 318 "src/analyzer/expression/PostfixExpression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 319 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__SEQUENCE: {
                #line 319 "src/analyzer/expression/PostfixExpression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 320 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &sequence->element;
            } break;
            #line 322 "src/analyzer/expression/PostfixExpression.pv"
            default: {
            } break;
        }
    } else {
        #line 325 "src/analyzer/expression/PostfixExpression.pv"
        switch (inner_return_type->type) {
            #line 326 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__INDIRECT: {
                #line 326 "src/analyzer/expression/PostfixExpression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 327 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &indirect->to;
            } break;
            #line 329 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__SEQUENCE: {
                #line 329 "src/analyzer/expression/PostfixExpression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 330 "src/analyzer/expression/PostfixExpression.pv"
                element_type = &sequence->element;
            } break;
            #line 332 "src/analyzer/expression/PostfixExpression.pv"
            default: {
            } break;
        }
    }

    #line 336 "src/analyzer/expression/PostfixExpression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 337 "src/analyzer/expression/PostfixExpression.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(context->allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "", .length = strlen("") }, .generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 } }});
        #line 338 "src/analyzer/expression/PostfixExpression.pv"
        element_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c }}, context->allocator);
    }

    #line 341 "src/analyzer/expression/PostfixExpression.pv"
    if (element_type == 0) {
        #line 342 "src/analyzer/expression/PostfixExpression.pv"
        Context__error_expression(context, index_expr, "Type is not indexable");
        #line 343 "src/analyzer/expression/PostfixExpression.pv"
        return 0;
    }

    #line 346 "src/analyzer/expression/PostfixExpression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 349 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 350 "src/analyzer/expression/PostfixExpression.pv"
    struct Token* token = Context__current(context);
    #line 351 "src/analyzer/expression/PostfixExpression.pv"
    if (token == 0) {
        #line 351 "src/analyzer/expression/PostfixExpression.pv"
        return inner;
    }

    #line 353 "src/analyzer/expression/PostfixExpression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 354 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "?")) {
        #line 356 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_optional_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 358 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 360 "src/analyzer/expression/PostfixExpression.pv"
        return Expression__parse_index_expression(context, inner, generics);
    } else if (Type__is_function(Type__resolve_typedef_function(&inner->return_type)) && (Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, "("))) {
        #line 362 "src/analyzer/expression/PostfixExpression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 363 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION: {
                #line 363 "src/analyzer/expression/PostfixExpression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 364 "src/analyzer/expression/PostfixExpression.pv"
                struct Array_Type parsed_generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, .data = 0, .length = 0, .capacity = 0 };

                #line 366 "src/analyzer/expression/PostfixExpression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                    #line 367 "src/analyzer/expression/PostfixExpression.pv"
                    parsed_generics = Context__parse_generics(context, generics);
                }

                #line 370 "src/analyzer/expression/PostfixExpression.pv"
                struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                #line 371 "src/analyzer/expression/PostfixExpression.pv"
                if (parsed == 0) {
                    #line 371 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 373 "src/analyzer/expression/PostfixExpression.pv"
                if (func_info->generics.array.length > 0) {
                    #line 374 "src/analyzer/expression/PostfixExpression.pv"
                    struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &parsed->arguments);
                    #line 375 "src/analyzer/expression/PostfixExpression.pv"
                    struct Type* inner_return_type = Root__make_type_usage(context->root, &inner->return_type, &func_generics->array);
                    #line 376 "src/analyzer/expression/PostfixExpression.pv"
                    if (inner_return_type == 0) {
                        #line 376 "src/analyzer/expression/PostfixExpression.pv"
                        return 0;
                    }
                    #line 377 "src/analyzer/expression/PostfixExpression.pv"
                    inner->return_type = *inner_return_type;

                    #line 379 "src/analyzer/expression/PostfixExpression.pv"
                    switch (inner->data.type) {
                        #line 380 "src/analyzer/expression/PostfixExpression.pv"
                        case EXPRESSION_DATA__TYPE: {
                            #line 380 "src/analyzer/expression/PostfixExpression.pv"
                            struct Type** type = &inner->data.type_value;
                            #line 381 "src/analyzer/expression/PostfixExpression.pv"
                            *type = &inner->return_type;
                        } break;
                        #line 383 "src/analyzer/expression/PostfixExpression.pv"
                        default: {
                        } break;
                    }
                }

                #line 387 "src/analyzer/expression/PostfixExpression.pv"
                if (!Expression__validate_arguments(context, token, &inner->return_type, &parsed->arguments, 0, false)) {
                    #line 387 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 389 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = parsed->arguments} }, &func_info->return_type);
            } break;
            #line 391 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__FUNCTION_C: {
                #line 391 "src/analyzer/expression/PostfixExpression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 392 "src/analyzer/expression/PostfixExpression.pv"
                struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                #line 393 "src/analyzer/expression/PostfixExpression.pv"
                if (parsed == 0) {
                    #line 393 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 395 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = parsed->arguments} }, &func_info->return_type);
            } break;
            #line 397 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__CLASS_CPP: {
                #line 398 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__parse_class(context, token, inner, generics);
            } break;
            #line 400 "src/analyzer/expression/PostfixExpression.pv"
            case TYPE__UNKNOWN_C: {
                #line 401 "src/analyzer/expression/PostfixExpression.pv"
                struct ParsedArguments* parsed = Expression__parse_call_arguments(context, generics);
                #line 402 "src/analyzer/expression/PostfixExpression.pv"
                if (parsed == 0) {
                    #line 402 "src/analyzer/expression/PostfixExpression.pv"
                    return 0;
                }

                #line 404 "src/analyzer/expression/PostfixExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = parsed->arguments} }, &context->root->type_unknown);
            } break;
            #line 406 "src/analyzer/expression/PostfixExpression.pv"
            default: {
                #line 407 "src/analyzer/expression/PostfixExpression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 408 "src/analyzer/expression/PostfixExpression.pv"
                return 0;
            } break;
        }
    }

    #line 413 "src/analyzer/expression/PostfixExpression.pv"
    return inner;
}

#line 416 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 417 "src/analyzer/expression/PostfixExpression.pv"
    struct Expression* result = inner;
    #line 418 "src/analyzer/expression/PostfixExpression.pv"
    while (true) {
        #line 419 "src/analyzer/expression/PostfixExpression.pv"
        struct Expression* next = Expression__parse_postfix(context, result, generics);
        #line 420 "src/analyzer/expression/PostfixExpression.pv"
        if (next == result) {
            #line 420 "src/analyzer/expression/PostfixExpression.pv"
            break;
        }
        #line 421 "src/analyzer/expression/PostfixExpression.pv"
        if (next == 0) {
            #line 421 "src/analyzer/expression/PostfixExpression.pv"
            return 0;
        }

        #line 423 "src/analyzer/expression/PostfixExpression.pv"
        result = next;
    }
    #line 425 "src/analyzer/expression/PostfixExpression.pv"
    return result;
}

#line 11 "src/analyzer/expression/BinaryExpression.pv"
bool Expression__is_null_literal_expression(struct Expression* expr) {
    #line 12 "src/analyzer/expression/BinaryExpression.pv"
    switch (expr->data.type) {
        #line 13 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 13 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* child = expr->data.parenthesizedexpression_value;
            #line 13 "src/analyzer/expression/BinaryExpression.pv"
            return Expression__is_null_literal_expression(child);
        } break;
        #line 14 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 14 "src/analyzer/expression/BinaryExpression.pv"
            return true;
        } break;
        #line 15 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 18 "src/analyzer/expression/BinaryExpression.pv"
    return false;
}

#line 21 "src/analyzer/expression/BinaryExpression.pv"
void Expression__append_null_narrowing(struct Context* context, struct Expression* expr, struct str path, struct Array_NullNarrowing* out) {
    #line 22 "src/analyzer/expression/BinaryExpression.pv"
    switch (expr->return_type.type) {
        #line 23 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__INDIRECT: {
            #line 23 "src/analyzer/expression/BinaryExpression.pv"
            struct Indirect* indirect = expr->return_type.indirect_value;
            #line 24 "src/analyzer/expression/BinaryExpression.pv"
            struct Indirect* narrowed_indirect;
            #line 25 "src/analyzer/expression/BinaryExpression.pv"
            if (indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER) {
                #line 26 "src/analyzer/expression/BinaryExpression.pv"
                narrowed_indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, indirect->to);
            } else if (indirect->type == INDIRECT_TYPE__DYNAMIC_DISPATCH_POINTER) {
                #line 28 "src/analyzer/expression/BinaryExpression.pv"
                narrowed_indirect = Indirect__new_dynamic_dispatch((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, indirect->to);
            } else {
                #line 30 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 32 "src/analyzer/expression/BinaryExpression.pv"
            struct Type type_val = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = narrowed_indirect };
            #line 33 "src/analyzer/expression/BinaryExpression.pv"
            struct Type* stored = ArenaAllocator__store_Type(context->allocator, &type_val);
            #line 34 "src/analyzer/expression/BinaryExpression.pv"
            if (stored == 0) {
                #line 34 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 35 "src/analyzer/expression/BinaryExpression.pv"
            Array_NullNarrowing__append(out, (struct NullNarrowing) { .path = path, .type = stored });
        } break;
        #line 37 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }
}

#line 44 "src/analyzer/expression/BinaryExpression.pv"
bool Expression__build_narrow_path(struct Expression* self, struct String* out) {
    #line 45 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* inner = self;
    #line 46 "src/analyzer/expression/BinaryExpression.pv"
    switch (inner->data.type) {
        #line 47 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 47 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* child = inner->data.parenthesizedexpression_value;
            #line 47 "src/analyzer/expression/BinaryExpression.pv"
            return Expression__build_narrow_path(child, out);
        } break;
        #line 48 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 48 "src/analyzer/expression/BinaryExpression.pv"
            struct str name = inner->data.variable_value;
            #line 49 "src/analyzer/expression/BinaryExpression.pv"
            String__append(out, name);
            #line 50 "src/analyzer/expression/BinaryExpression.pv"
            return true;
        } break;
        #line 52 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 52 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* parent = inner->data.memberinstanceexpression_value._0;
            #line 52 "src/analyzer/expression/BinaryExpression.pv"
            struct str member = inner->data.memberinstanceexpression_value._1;
            #line 53 "src/analyzer/expression/BinaryExpression.pv"
            if (!Expression__build_narrow_path(parent, out)) {
                #line 53 "src/analyzer/expression/BinaryExpression.pv"
                return false;
            }
            #line 54 "src/analyzer/expression/BinaryExpression.pv"
            String__append(out, (struct str){ .ptr = ".", .length = strlen(".") });
            #line 55 "src/analyzer/expression/BinaryExpression.pv"
            String__append(out, member);
            #line 56 "src/analyzer/expression/BinaryExpression.pv"
            return true;
        } break;
        #line 58 "src/analyzer/expression/BinaryExpression.pv"
        default: {
            #line 58 "src/analyzer/expression/BinaryExpression.pv"
            return false;
        } break;
    }
}

#line 66 "src/analyzer/expression/BinaryExpression.pv"
void Expression__collect_null_narrowings(struct Context* context, struct Expression* expr, bool narrow_on_true, struct Array_NullNarrowing* out) {
    #line 67 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* inner = expr;
    #line 68 "src/analyzer/expression/BinaryExpression.pv"
    switch (inner->data.type) {
        #line 69 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 69 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* child = inner->data.parenthesizedexpression_value;
            #line 69 "src/analyzer/expression/BinaryExpression.pv"
            inner = child;
        } break;
        #line 70 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 73 "src/analyzer/expression/BinaryExpression.pv"
    switch (inner->data.type) {
        #line 74 "src/analyzer/expression/BinaryExpression.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 74 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* lhs = inner->data.binaryexpression_value._0;
            #line 74 "src/analyzer/expression/BinaryExpression.pv"
            struct str op = inner->data.binaryexpression_value._1;
            #line 74 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* rhs = inner->data.binaryexpression_value._2;
            #line 75 "src/analyzer/expression/BinaryExpression.pv"
            if (str__Eq_str__eq(op, (struct str){ .ptr = "||", .length = strlen("||") }) && !narrow_on_true) {
                #line 76 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, lhs, false, out);
                #line 77 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, rhs, false, out);
                #line 78 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 80 "src/analyzer/expression/BinaryExpression.pv"
            if (str__Eq_str__eq(op, (struct str){ .ptr = "&&", .length = strlen("&&") }) && narrow_on_true) {
                #line 81 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, lhs, true, out);
                #line 82 "src/analyzer/expression/BinaryExpression.pv"
                Expression__collect_null_narrowings(context, rhs, true, out);
                #line 83 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }

            #line 86 "src/analyzer/expression/BinaryExpression.pv"
            struct str want_op = (struct str){ .ptr = narrow_on_true ? "!=" : "==", .length = strlen(narrow_on_true ? "!=" : "==") };
            #line 87 "src/analyzer/expression/BinaryExpression.pv"
            if (!str__Eq_str__eq(op, want_op)) {
                #line 87 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }

            #line 89 "src/analyzer/expression/BinaryExpression.pv"
            struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 90 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* var_expr = 0;
            #line 91 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* other = 0;

            #line 93 "src/analyzer/expression/BinaryExpression.pv"
            if (Expression__build_narrow_path(lhs, &path)) {
                #line 93 "src/analyzer/expression/BinaryExpression.pv"
                var_expr = lhs;
                #line 93 "src/analyzer/expression/BinaryExpression.pv"
                other = rhs;
            } else {
                #line 95 "src/analyzer/expression/BinaryExpression.pv"
                struct String path2 = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 96 "src/analyzer/expression/BinaryExpression.pv"
                if (Expression__build_narrow_path(rhs, &path2)) {
                    #line 96 "src/analyzer/expression/BinaryExpression.pv"
                    var_expr = rhs;
                    #line 96 "src/analyzer/expression/BinaryExpression.pv"
                    other = lhs;
                    #line 96 "src/analyzer/expression/BinaryExpression.pv"
                    path = path2;
                } else {
                    #line 97 "src/analyzer/expression/BinaryExpression.pv"
                    return;
                }
            }

            #line 100 "src/analyzer/expression/BinaryExpression.pv"
            if (other == 0) {
                #line 100 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 101 "src/analyzer/expression/BinaryExpression.pv"
            if (!Expression__is_null_literal_expression(other)) {
                #line 101 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }

            #line 103 "src/analyzer/expression/BinaryExpression.pv"
            if (var_expr == 0) {
                #line 103 "src/analyzer/expression/BinaryExpression.pv"
                return;
            }
            #line 104 "src/analyzer/expression/BinaryExpression.pv"
            Expression__append_null_narrowing(context, var_expr, String__as_str(&path), out);
        } break;
        #line 106 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }
}

#line 110 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics) {
    #line 111 "src/analyzer/expression/BinaryExpression.pv"
    struct Expression* result = lhs;

    #line 113 "src/analyzer/expression/BinaryExpression.pv"
    while (true) {
        #line 114 "src/analyzer/expression/BinaryExpression.pv"
        struct Token* token = Context__current(context);
        #line 115 "src/analyzer/expression/BinaryExpression.pv"
        uintptr_t prec = Expression__get_precedence(token);
        #line 116 "src/analyzer/expression/BinaryExpression.pv"
        if (prec < min_prec) {
            #line 116 "src/analyzer/expression/BinaryExpression.pv"
            break;
        }

        #line 118 "src/analyzer/expression/BinaryExpression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 119 "src/analyzer/expression/BinaryExpression.pv"
        if (operator == 0) {
            #line 119 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }
        #line 124 "src/analyzer/expression/BinaryExpression.pv"
        bool pushed_narrow_scope = false;
        #line 125 "src/analyzer/expression/BinaryExpression.pv"
        if (str__Eq_str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
            #line 126 "src/analyzer/expression/BinaryExpression.pv"
            bool narrow_on_true_for_rhs = str__Eq_str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });
            #line 127 "src/analyzer/expression/BinaryExpression.pv"
            struct Array_NullNarrowing narrowings = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 128 "src/analyzer/expression/BinaryExpression.pv"
            Expression__collect_null_narrowings(context, result, narrow_on_true_for_rhs, &narrowings);
            #line 129 "src/analyzer/expression/BinaryExpression.pv"
            if (narrowings.length > 0) {
                #line 130 "src/analyzer/expression/BinaryExpression.pv"
                Context__push_scope(context, 0);
                #line 131 "src/analyzer/expression/BinaryExpression.pv"
                { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings);
                #line 131 "src/analyzer/expression/BinaryExpression.pv"
                while (Iter_ref_NullNarrowing__next(&__iter)) {
                    #line 131 "src/analyzer/expression/BinaryExpression.pv"
                    struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

                    #line 132 "src/analyzer/expression/BinaryExpression.pv"
                    Context__set_narrowed(context, narrow->path, narrow->type);
                } }
                #line 134 "src/analyzer/expression/BinaryExpression.pv"
                pushed_narrow_scope = true;
            }
        }

        #line 138 "src/analyzer/expression/BinaryExpression.pv"
        struct Expression* rhs = Expression__parse_primary(context, generics);
        #line 139 "src/analyzer/expression/BinaryExpression.pv"
        if (rhs == 0) {
            #line 139 "src/analyzer/expression/BinaryExpression.pv"
            if (pushed_narrow_scope) {
                #line 139 "src/analyzer/expression/BinaryExpression.pv"
                Context__pop_scope(context);
            }
            #line 139 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 141 "src/analyzer/expression/BinaryExpression.pv"
        struct Expression* rhs_final = Expression__parse_binary(context, rhs, prec + 1, generics);
        #line 142 "src/analyzer/expression/BinaryExpression.pv"
        if (rhs_final == 0) {
            #line 142 "src/analyzer/expression/BinaryExpression.pv"
            if (pushed_narrow_scope) {
                #line 142 "src/analyzer/expression/BinaryExpression.pv"
                Context__pop_scope(context);
            }
            #line 142 "src/analyzer/expression/BinaryExpression.pv"
            return 0;
        }

        #line 144 "src/analyzer/expression/BinaryExpression.pv"
        if (pushed_narrow_scope) {
            #line 144 "src/analyzer/expression/BinaryExpression.pv"
            Context__pop_scope(context);
        }

        #line 146 "src/analyzer/expression/BinaryExpression.pv"
        bool is_arithmetic = str__Eq_str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "-", .length = strlen("-") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "/", .length = strlen("/") });

        #line 150 "src/analyzer/expression/BinaryExpression.pv"
        bool is_trait_op = is_arithmetic || str__Eq_str__eq(operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") });

        #line 154 "src/analyzer/expression/BinaryExpression.pv"
        if (is_trait_op) {
            #line 155 "src/analyzer/expression/BinaryExpression.pv"
            struct Expression* trait_result = Expression__find_operator_trait_call(context, token, result, &result->return_type, operator->value, rhs_final);
            #line 156 "src/analyzer/expression/BinaryExpression.pv"
            if (trait_result != 0) {
                #line 157 "src/analyzer/expression/BinaryExpression.pv"
                result = trait_result;
                #line 158 "src/analyzer/expression/BinaryExpression.pv"
                continue;
            }
        }

        #line 162 "src/analyzer/expression/BinaryExpression.pv"
        bool is_comparison = str__Eq_str__eq(operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "!=", .length = strlen("!=") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__Eq_str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });

        #line 168 "src/analyzer/expression/BinaryExpression.pv"
        struct Type* return_type = 0;
        #line 169 "src/analyzer/expression/BinaryExpression.pv"
        if (is_comparison) {
            #line 170 "src/analyzer/expression/BinaryExpression.pv"
            if (!str__Eq_str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) && !str__Eq_str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
                #line 171 "src/analyzer/expression/BinaryExpression.pv"
                if (!Expression__validate_type(result, context, &rhs_final->return_type, false)) {
                    #line 171 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }
                #line 174 "src/analyzer/expression/BinaryExpression.pv"
                switch (rhs_final->data.type) {
                    #line 175 "src/analyzer/expression/BinaryExpression.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 176 "src/analyzer/expression/BinaryExpression.pv"
                        Expression__validate_type(rhs_final, context, &result->return_type, false);
                    } break;
                    #line 178 "src/analyzer/expression/BinaryExpression.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 178 "src/analyzer/expression/BinaryExpression.pv"
                        struct str value = rhs_final->data.literal_value;
                        #line 179 "src/analyzer/expression/BinaryExpression.pv"
                        if (str__Eq_str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 180 "src/analyzer/expression/BinaryExpression.pv"
                            Expression__validate_type(rhs_final, context, &result->return_type, false);
                        }
                    } break;
                    #line 183 "src/analyzer/expression/BinaryExpression.pv"
                    default: {
                    } break;
                }
            }

            #line 187 "src/analyzer/expression/BinaryExpression.pv"
            return_type = &context->root->type_bool;
        } else {
            #line 189 "src/analyzer/expression/BinaryExpression.pv"
            return_type = &result->return_type;
        }

        #line 192 "src/analyzer/expression/BinaryExpression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = result, ._1 = operator->value, ._2 = rhs_final} }, return_type);
    }

    #line 195 "src/analyzer/expression/BinaryExpression.pv"
    return result;
}

#line 198 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_operator_trait_call(struct Context* context, struct Token* token, struct Expression* lhs, struct Type* lhs_type, struct str operator, struct Expression* rhs) {
    #line 199 "src/analyzer/expression/BinaryExpression.pv"
    struct str trait_name = (struct str){ .ptr = "", .length = strlen("") };
    #line 200 "src/analyzer/expression/BinaryExpression.pv"
    struct str func_name = (struct str){ .ptr = "", .length = strlen("") };

    #line 202 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(operator, (struct str){ .ptr = "*", .length = strlen("*") })) {
        #line 202 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Mul", .length = strlen("Mul") };
        #line 202 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "mul", .length = strlen("mul") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = "+", .length = strlen("+") })) {
        #line 203 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Add", .length = strlen("Add") };
        #line 203 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "add", .length = strlen("add") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 204 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Sub", .length = strlen("Sub") };
        #line 204 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "sub", .length = strlen("sub") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = "/", .length = strlen("/") })) {
        #line 205 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Div", .length = strlen("Div") };
        #line 205 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "div", .length = strlen("div") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = "==", .length = strlen("==") })) {
        #line 206 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Eq", .length = strlen("Eq") };
        #line 206 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "eq", .length = strlen("eq") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = "<", .length = strlen("<") })) {
        #line 207 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 207 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "lt", .length = strlen("lt") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = ">", .length = strlen(">") })) {
        #line 208 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 208 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "gt", .length = strlen("gt") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = "<=", .length = strlen("<=") })) {
        #line 209 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 209 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "le", .length = strlen("le") };
    } else if (str__Eq_str__eq(operator, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 210 "src/analyzer/expression/BinaryExpression.pv"
        trait_name = (struct str){ .ptr = "Ord", .length = strlen("Ord") };
        #line 210 "src/analyzer/expression/BinaryExpression.pv"
        func_name = (struct str){ .ptr = "ge", .length = strlen("ge") };
    } else {
        #line 211 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 213 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(lhs_type) || Type__is_unknown(&rhs->return_type)) {
        #line 213 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 215 "src/analyzer/expression/BinaryExpression.pv"
    switch (lhs_type->type) {
        #line 216 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__SELF: {
            #line 217 "src/analyzer/expression/BinaryExpression.pv"
            if (context->type_self != 0) {
                #line 218 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__find_operator_trait_call(context, token, lhs, context->type_self, operator, rhs);
            }
        } break;
        #line 224 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 224 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = lhs_type->struct_value._0;
            #line 224 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = lhs_type->struct_value._1;
            #line 225 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 225 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 225 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 226 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 227 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 227 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 228 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 229 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 229 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 230 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(impl_trait_name->value, trait_name)) {
                    #line 230 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 232 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &func_name);
                #line 233 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 233 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 234 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 2) {
                    #line 234 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 236 "src/analyzer/expression/BinaryExpression.pv"
                struct Parameter* other_param = Array_Parameter__get(&func->parameters, 1);
                #line 237 "src/analyzer/expression/BinaryExpression.pv"
                if (other_param == 0) {
                    #line 237 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 238 "src/analyzer/expression/BinaryExpression.pv"
                if (!Type__eq(&other_param->type, &rhs->return_type)) {
                    #line 238 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 240 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 241 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 242 "src/analyzer/expression/BinaryExpression.pv"
                    if (generic_map == 0) {
                        #line 242 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 243 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 244 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 245 "src/analyzer/expression/BinaryExpression.pv"
                    if (aug_map == 0) {
                        #line 245 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 246 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 246 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 246 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 246 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 247 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *typedef_type);
                    } }
                    #line 249 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 252 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});
                #line 253 "src/analyzer/expression/BinaryExpression.pv"
                if (func_type == 0) {
                    #line 253 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }

                #line 255 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 256 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = lhs });
                #line 257 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = rhs });

                #line 259 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 262 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__PRIMITIVE: {
            #line 262 "src/analyzer/expression/BinaryExpression.pv"
            struct Primitive* primitive_info = lhs_type->primitive_value;
            #line 263 "src/analyzer/expression/BinaryExpression.pv"
            if (primitive_info == 0) {
                #line 263 "src/analyzer/expression/BinaryExpression.pv"
                return 0;
            }
            #line 264 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 264 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 264 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 265 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 266 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 266 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 267 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 268 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 268 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 269 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(impl_trait_name->value, trait_name)) {
                    #line 269 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 271 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &func_name);
                #line 272 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 272 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 273 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 2) {
                    #line 273 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 275 "src/analyzer/expression/BinaryExpression.pv"
                struct Parameter* other_param = Array_Parameter__get(&func->parameters, 1);
                #line 276 "src/analyzer/expression/BinaryExpression.pv"
                if (other_param == 0) {
                    #line 276 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 277 "src/analyzer/expression/BinaryExpression.pv"
                if (Type__is_self(&rhs->return_type)) {
                    #line 277 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 278 "src/analyzer/expression/BinaryExpression.pv"
                if (!Type__eq(&other_param->type, &rhs->return_type)) {
                    #line 278 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 280 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = Type__get_generic_map(&impl_info->trait_type, context);

                #line 282 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});

                #line 284 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 285 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = lhs });
                #line 286 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = rhs });

                #line 288 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 291 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 294 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 297 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_unary_trait_call(struct Context* context, struct Token* token, struct Expression* operand) {
    #line 298 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(&operand->return_type)) {
        #line 298 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 300 "src/analyzer/expression/BinaryExpression.pv"
    switch (operand->return_type.type) {
        #line 301 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__SELF: {
            #line 302 "src/analyzer/expression/BinaryExpression.pv"
            if (context->type_self != 0) {
                #line 303 "src/analyzer/expression/BinaryExpression.pv"
                struct Expression concrete_operand = (struct Expression) { .data = operand->data, .return_type = *context->type_self, .token = operand->token };
                #line 304 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__find_unary_trait_call(context, token, &concrete_operand);
            }
        } break;
        #line 307 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 307 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = operand->return_type.struct_value._0;
            #line 307 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = operand->return_type.struct_value._1;
            #line 308 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 308 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 308 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 309 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 310 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 310 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 311 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 312 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 312 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 313 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(impl_trait_name->value, (struct str){ .ptr = "Neg", .length = strlen("Neg") })) {
                    #line 313 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 315 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &(struct str){ .ptr = "neg", .length = strlen("neg") });
                #line 316 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 316 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 317 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 1) {
                    #line 317 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 319 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 320 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 321 "src/analyzer/expression/BinaryExpression.pv"
                    if (generic_map == 0) {
                        #line 321 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 322 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 323 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 324 "src/analyzer/expression/BinaryExpression.pv"
                    if (aug_map == 0) {
                        #line 324 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 325 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 325 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 325 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 325 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 326 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* resolved = Context__resolve_type(context->allocator, typedef_type, generic_map, 0);
                        #line 327 "src/analyzer/expression/BinaryExpression.pv"
                        if (resolved == 0) {
                            #line 327 "src/analyzer/expression/BinaryExpression.pv"
                            return 0;
                        }
                        #line 328 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *resolved);
                    } }
                    #line 330 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 333 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});
                #line 334 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 335 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = operand });

                #line 337 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make_type_function_call(context, token, func_type, arguments, 0);
            } }
        } break;
        #line 340 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 343 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 346 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_index_trait_call(struct Context* context, struct Token* token, struct Expression* inner, struct Expression* index_expr) {
    #line 347 "src/analyzer/expression/BinaryExpression.pv"
    if (Type__is_unknown(&inner->return_type)) {
        #line 347 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 349 "src/analyzer/expression/BinaryExpression.pv"
    switch (Type__deref_reference(&inner->return_type)->type) {
        #line 350 "src/analyzer/expression/BinaryExpression.pv"
        case TYPE__STRUCT: {
            #line 350 "src/analyzer/expression/BinaryExpression.pv"
            struct Struct* struct_info = Type__deref_reference(&inner->return_type)->struct_value._0;
            #line 350 "src/analyzer/expression/BinaryExpression.pv"
            struct GenericMap* generic_map = Type__deref_reference(&inner->return_type)->struct_value._1;
            #line 351 "src/analyzer/expression/BinaryExpression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 351 "src/analyzer/expression/BinaryExpression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 351 "src/analyzer/expression/BinaryExpression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 352 "src/analyzer/expression/BinaryExpression.pv"
                struct Trait* impl_trait = impl_info->trait_;
                #line 353 "src/analyzer/expression/BinaryExpression.pv"
                if (!impl_info->has_trait || impl_trait == 0) {
                    #line 353 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 354 "src/analyzer/expression/BinaryExpression.pv"
                struct Token* impl_trait_name = impl_trait->name;
                #line 355 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_trait_name == 0) {
                    #line 355 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 356 "src/analyzer/expression/BinaryExpression.pv"
                if (!str__Eq_str__eq(impl_trait_name->value, (struct str){ .ptr = "Index", .length = strlen("Index") })) {
                    #line 356 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 358 "src/analyzer/expression/BinaryExpression.pv"
                struct Function* func = HashMap_str_Function__find(&impl_info->functions, &(struct str){ .ptr = "index", .length = strlen("index") });
                #line 359 "src/analyzer/expression/BinaryExpression.pv"
                if (func == 0) {
                    #line 359 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }
                #line 360 "src/analyzer/expression/BinaryExpression.pv"
                if (func->parameters.length < 1) {
                    #line 360 "src/analyzer/expression/BinaryExpression.pv"
                    continue;
                }

                #line 362 "src/analyzer/expression/BinaryExpression.pv"
                struct GenericMap* func_map = generic_map;
                #line 363 "src/analyzer/expression/BinaryExpression.pv"
                if (impl_info->typedefs.length > 0) {
                    #line 364 "src/analyzer/expression/BinaryExpression.pv"
                    if (generic_map == 0) {
                        #line 364 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 365 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                    #line 366 "src/analyzer/expression/BinaryExpression.pv"
                    struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                    #line 367 "src/analyzer/expression/BinaryExpression.pv"
                    if (aug_map == 0) {
                        #line 367 "src/analyzer/expression/BinaryExpression.pv"
                        return 0;
                    }
                    #line 368 "src/analyzer/expression/BinaryExpression.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&impl_info->typedefs);
                    #line 368 "src/analyzer/expression/BinaryExpression.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 368 "src/analyzer/expression/BinaryExpression.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 368 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 369 "src/analyzer/expression/BinaryExpression.pv"
                        struct Type* resolved = Context__resolve_type(context->allocator, typedef_type, generic_map, 0);
                        #line 370 "src/analyzer/expression/BinaryExpression.pv"
                        if (resolved == 0) {
                            #line 370 "src/analyzer/expression/BinaryExpression.pv"
                            return 0;
                        }
                        #line 371 "src/analyzer/expression/BinaryExpression.pv"
                        GenericMap__insert(aug_map, name, *resolved);
                    } }
                    #line 373 "src/analyzer/expression/BinaryExpression.pv"
                    func_map = aug_map;
                }

                #line 376 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* func_type = ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func, ._1 = func_map} }});
                #line 377 "src/analyzer/expression/BinaryExpression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 378 "src/analyzer/expression/BinaryExpression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = inner });

                #line 380 "src/analyzer/expression/BinaryExpression.pv"
                struct Expression* ptr_expr = Expression__make_type_function_call(context, token, func_type, arguments, 0);
                #line 381 "src/analyzer/expression/BinaryExpression.pv"
                if (ptr_expr == 0) {
                    #line 381 "src/analyzer/expression/BinaryExpression.pv"
                    return 0;
                }

                #line 383 "src/analyzer/expression/BinaryExpression.pv"
                struct Type* element_type = Type__deref(&ptr_expr->return_type);
                #line 384 "src/analyzer/expression/BinaryExpression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = ptr_expr, ._1 = index_expr} }, element_type);
            } }
        } break;
        #line 387 "src/analyzer/expression/BinaryExpression.pv"
        default: {
        } break;
    }

    #line 390 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 393 "src/analyzer/expression/BinaryExpression.pv"
uintptr_t Expression__get_precedence(struct Token* token) {
    #line 394 "src/analyzer/expression/BinaryExpression.pv"
    if (token->type != TOKEN_TYPE__SYMBOL) {
        #line 394 "src/analyzer/expression/BinaryExpression.pv"
        return 0;
    }

    #line 396 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "||", .length = strlen("||") })) {
        #line 396 "src/analyzer/expression/BinaryExpression.pv"
        return 1;
    }
    #line 397 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
        #line 397 "src/analyzer/expression/BinaryExpression.pv"
        return 2;
    }
    #line 398 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "|", .length = strlen("|") })) {
        #line 398 "src/analyzer/expression/BinaryExpression.pv"
        return 3;
    }
    #line 399 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "^", .length = strlen("^") })) {
        #line 399 "src/analyzer/expression/BinaryExpression.pv"
        return 4;
    }
    #line 400 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
        #line 400 "src/analyzer/expression/BinaryExpression.pv"
        return 5;
    }
    #line 401 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "!=", .length = strlen("!=") })) {
        #line 401 "src/analyzer/expression/BinaryExpression.pv"
        return 6;
    }
    #line 402 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 402 "src/analyzer/expression/BinaryExpression.pv"
        return 7;
    }
    #line 403 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "<<", .length = strlen("<<") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = ">>", .length = strlen(">>") })) {
        #line 403 "src/analyzer/expression/BinaryExpression.pv"
        return 8;
    }
    #line 404 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 404 "src/analyzer/expression/BinaryExpression.pv"
        return 9;
    }
    #line 405 "src/analyzer/expression/BinaryExpression.pv"
    if (str__Eq_str__eq(token->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "/", .length = strlen("/") }) || str__Eq_str__eq(token->value, (struct str){ .ptr = "%", .length = strlen("%") })) {
        #line 405 "src/analyzer/expression/BinaryExpression.pv"
        return 10;
    }

    #line 407 "src/analyzer/expression/BinaryExpression.pv"
    return 0;
}

#line 13 "src/analyzer/expression/ParseCallArguments.pv"
struct ParsedArguments* Expression__parse_call_arguments(struct Context* context, struct Generics* generics) {
    #line 14 "src/analyzer/expression/ParseCallArguments.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 14 "src/analyzer/expression/ParseCallArguments.pv"
        return 0;
    }
    #line 15 "src/analyzer/expression/ParseCallArguments.pv"
    struct Token* open_paren = Context__prev(context);

    #line 17 "src/analyzer/expression/ParseCallArguments.pv"
    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 18 "src/analyzer/expression/ParseCallArguments.pv"
    struct Array_Position comma_positions = Array_Position__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 20 "src/analyzer/expression/ParseCallArguments.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 21 "src/analyzer/expression/ParseCallArguments.pv"
        struct Expression* argument = Expression__parse(context, generics);
        #line 22 "src/analyzer/expression/ParseCallArguments.pv"
        if (argument == 0) {
            #line 22 "src/analyzer/expression/ParseCallArguments.pv"
            return 0;
        }
        #line 23 "src/analyzer/expression/ParseCallArguments.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = 0, .value = argument });

        #line 25 "src/analyzer/expression/ParseCallArguments.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 26 "src/analyzer/expression/ParseCallArguments.pv"
            struct Token* comma_tok = Context__prev(context);
            #line 27 "src/analyzer/expression/ParseCallArguments.pv"
            if (comma_tok != 0) {
                #line 28 "src/analyzer/expression/ParseCallArguments.pv"
                Array_Position__append(&comma_positions, (struct Position) { .line = comma_tok->start_line, .character = comma_tok->start_column });
            }
        } else if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 31 "src/analyzer/expression/ParseCallArguments.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
            #line 32 "src/analyzer/expression/ParseCallArguments.pv"
            return 0;
        }
    }

    #line 36 "src/analyzer/expression/ParseCallArguments.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
        #line 36 "src/analyzer/expression/ParseCallArguments.pv"
        return 0;
    }
    #line 37 "src/analyzer/expression/ParseCallArguments.pv"
    struct Token* close_paren = Context__prev(context);

    #line 39 "src/analyzer/expression/ParseCallArguments.pv"
    return ArenaAllocator__store_ParsedArguments(context->allocator, (struct ParsedArguments[]){(struct ParsedArguments) {
        .arguments = arguments,
        .open_paren = open_paren,
        .close_paren = close_paren,
        .comma_positions = comma_positions,
    }});
}
