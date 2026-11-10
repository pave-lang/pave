#include <string.h>
#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <compiler/Generator.h>
#include <std/String.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Function.h>
#include <analyzer/Naming.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/Root.h>
#include <analyzer/Impl.h>
#include <std/Array_Type.h>
#include <std/HashMap_str_usize.h>
#include <std/Array_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <analyzer/c/FunctionC.h>
#include <compiler/FunctionContext.h>
#include <usize.h>
#include <char.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Array_str.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/IndirectType.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/Struct.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <analyzer/types/Generic.h>
#include <analyzer/expression/CppExpression.h>
#include <compiler/ExpressionWriter.h>

#include <compiler/ExpressionWriter.h>

#line 14 "src/compiler/ExpressionWriter.pv"
struct ExpressionWriter ExpressionWriter__new(struct Generator* generator) {
    #line 15 "src/compiler/ExpressionWriter.pv"
    return (struct ExpressionWriter) { .generator = generator };
}

#line 18 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__make_optional_temp_name(struct ExpressionWriter* self, uintptr_t* count) {
    #line 19 "src/compiler/ExpressionWriter.pv"
    struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator });
    #line 20 "src/compiler/ExpressionWriter.pv"
    String__append(&name, (struct str){ .ptr = "__optional_", .length = strlen("__optional_") });
    #line 21 "src/compiler/ExpressionWriter.pv"
    String__append_usize(&name, *count);
    #line 22 "src/compiler/ExpressionWriter.pv"
    *count = *count + 1;
    #line 23 "src/compiler/ExpressionWriter.pv"
    return String__as_str(&name);
}

#line 26 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression_replacing(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Expression* replace, struct str replacement_name, struct Type* replacement_type, struct GenericMap* generics) {
    #line 27 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 29 "src/compiler/ExpressionWriter.pv"
    if (expression == replace) {
        #line 30 "src/compiler/ExpressionWriter.pv"
        Generator__write_variable(generator, file, replacement_name);
        #line 31 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 34 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 35 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 35 "src/compiler/ExpressionWriter.pv"
            struct str name = expression->data.variable_value;
            #line 36 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 37 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 39 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 39 "src/compiler/ExpressionWriter.pv"
            struct str value = expression->data.literal_value;
            #line 40 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 41 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 43 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 44 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 45 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 47 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 47 "src/compiler/ExpressionWriter.pv"
            struct Type* type = expression->data.type_value;
            #line 48 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 49 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 51 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 51 "src/compiler/ExpressionWriter.pv"
            struct str operator = expression->data.unaryexpression_value._0;
            #line 51 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 52 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_unary_operator(self, file, operator, inner);
            #line 53 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, inner, replace, replacement_name, replacement_type, generics);
            #line 54 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 56 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 56 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 56 "src/compiler/ExpressionWriter.pv"
            struct str operator = expression->data.binaryexpression_value._1;
            #line 56 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 57 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, left, replace, replacement_name, replacement_type, generics);
            #line 58 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);
            #line 59 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, right, replace, replacement_name, replacement_type, generics);
            #line 60 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 62 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 62 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = expression->data.memberinstanceexpression_value._0;
            #line 62 "src/compiler/ExpressionWriter.pv"
            struct str member = expression->data.memberinstanceexpression_value._1;
            #line 63 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 64 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 64 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = expression->return_type.function_value._0;
                    #line 65 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 66 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TYPE: {
                            #line 66 "src/compiler/ExpressionWriter.pv"
                            struct Type* type = func_info->parent.type_value._0;
                            #line 66 "src/compiler/ExpressionWriter.pv"
                            uintptr_t impl_index = func_info->parent.type_value._1;
                            #line 66 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.type_value._2;
                            #line 67 "src/compiler/ExpressionWriter.pv"
                            struct Type* named_type = type;
                            #line 68 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_fat_pointer(type)) {
                                #line 69 "src/compiler/ExpressionWriter.pv"
                                named_type = Type__deref_1(type);
                                #line 70 "src/compiler/ExpressionWriter.pv"
                                if (named_type == 0) {
                                    #line 70 "src/compiler/ExpressionWriter.pv"
                                    named_type = type;
                                }
                            }
                            #line 72 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, named_type, type, generics);
                            #line 73 "src/compiler/ExpressionWriter.pv"
                            if (trait_info != 0) {
                                #line 74 "src/compiler/ExpressionWriter.pv"
                                struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type, impl_index);
                                #line 75 "src/compiler/ExpressionWriter.pv"
                                struct Type* impl_trait_type = 0;
                                #line 76 "src/compiler/ExpressionWriter.pv"
                                if (type_impl != 0) {
                                    #line 76 "src/compiler/ExpressionWriter.pv"
                                    impl_trait_type = &type_impl->impl_info->trait_type;
                                }
                                #line 77 "src/compiler/ExpressionWriter.pv"
                                struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, impl_trait_type, func_info, generics);
                                #line 78 "src/compiler/ExpressionWriter.pv"
                                return Generator__write_string(generator, file, &function_name);
                            }
                            #line 80 "src/compiler/ExpressionWriter.pv"
                            Generator__write_string(generator, file, &parent_name);
                            #line 81 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "__");
                            #line 82 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                            #line 83 "src/compiler/ExpressionWriter.pv"
                            return true;
                        } break;
                        #line 85 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 88 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 91 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = (parent == replace ? replacement_type : &parent->return_type);
            #line 92 "src/compiler/ExpressionWriter.pv"
            struct Function* type_impl_function = Root__find_type_impl_function(generator->root, parent_type, member, 0);
            #line 93 "src/compiler/ExpressionWriter.pv"
            if (type_impl_function != 0) {
                #line 94 "src/compiler/ExpressionWriter.pv"
                switch (type_impl_function->parent.type) {
                    #line 95 "src/compiler/ExpressionWriter.pv"
                    case FUNCTION_PARENT__TYPE: {
                        #line 95 "src/compiler/ExpressionWriter.pv"
                        struct Type* type = type_impl_function->parent.type_value._0;
                        #line 95 "src/compiler/ExpressionWriter.pv"
                        uintptr_t impl_index = type_impl_function->parent.type_value._1;
                        #line 95 "src/compiler/ExpressionWriter.pv"
                        struct Trait* trait_info = type_impl_function->parent.type_value._2;
                        #line 96 "src/compiler/ExpressionWriter.pv"
                        struct Type* named_type = type;
                        #line 97 "src/compiler/ExpressionWriter.pv"
                        if (Type__is_fat_pointer(type)) {
                            #line 98 "src/compiler/ExpressionWriter.pv"
                            named_type = Type__deref_1(type);
                            #line 99 "src/compiler/ExpressionWriter.pv"
                            if (named_type == 0) {
                                #line 99 "src/compiler/ExpressionWriter.pv"
                                named_type = type;
                            }
                        }
                        #line 101 "src/compiler/ExpressionWriter.pv"
                        struct String parent_name = Naming__get_type_name(&generator->naming_ident, named_type, parent_type, generics);
                        #line 102 "src/compiler/ExpressionWriter.pv"
                        if (trait_info != 0) {
                            #line 103 "src/compiler/ExpressionWriter.pv"
                            struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type, impl_index);
                            #line 104 "src/compiler/ExpressionWriter.pv"
                            struct Type* impl_trait_type = 0;
                            #line 105 "src/compiler/ExpressionWriter.pv"
                            if (type_impl != 0) {
                                #line 105 "src/compiler/ExpressionWriter.pv"
                                impl_trait_type = &type_impl->impl_info->trait_type;
                            }
                            #line 106 "src/compiler/ExpressionWriter.pv"
                            struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, impl_trait_type, type_impl_function, generics);
                            #line 107 "src/compiler/ExpressionWriter.pv"
                            return Generator__write_string(generator, file, &function_name);
                        }
                        #line 109 "src/compiler/ExpressionWriter.pv"
                        Generator__write_string(generator, file, &parent_name);
                        #line 110 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                        #line 111 "src/compiler/ExpressionWriter.pv"
                        Generator__write_str(generator, file, member);
                        #line 112 "src/compiler/ExpressionWriter.pv"
                        return true;
                    } break;
                    #line 114 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 117 "src/compiler/ExpressionWriter.pv"
                struct GenericMap type_impl_generics = (struct GenericMap) { .self_type = parent_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } };
                #line 118 "src/compiler/ExpressionWriter.pv"
                return Generator__write_function_name(generator, file, type_impl_function, &type_impl_generics);
            }

            #line 121 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, &parent->return_type, generics)) {
                #line 122 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(&parent->return_type);
                #line 123 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 123 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 124 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, parent, replace, replacement_name, replacement_type, generics);
                #line 125 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 125 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 126 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 129 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, parent, replace, replacement_name, replacement_type, generics);
            #line 130 "src/compiler/ExpressionWriter.pv"
            Generator__write_instance_member_accessor(generator, file, parent_type, generics);
            #line 131 "src/compiler/ExpressionWriter.pv"
            if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                #line 131 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "_");
            }
            #line 132 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 133 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 135 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 135 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 135 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &expression->data.invoke_value._1;
            #line 136 "src/compiler/ExpressionWriter.pv"
            switch (target->data.type) {
                #line 137 "src/compiler/ExpressionWriter.pv"
                case EXPRESSION_DATA__TYPE: {
                    #line 137 "src/compiler/ExpressionWriter.pv"
                    struct Type* type = target->data.type_value;
                    #line 138 "src/compiler/ExpressionWriter.pv"
                    struct Type* __pave_tmp_0 = Type__resolve_typedef(type);
                    switch (__pave_tmp_0->type) {
                        #line 139 "src/compiler/ExpressionWriter.pv"
                        case TYPE__FUNCTION: {
                            #line 139 "src/compiler/ExpressionWriter.pv"
                            struct Function* func_info = __pave_tmp_0->function_value._0;
                            #line 139 "src/compiler/ExpressionWriter.pv"
                            struct GenericMap* generic_map = __pave_tmp_0->function_value._1;
                            #line 140 "src/compiler/ExpressionWriter.pv"
                            struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);
                            #line 141 "src/compiler/ExpressionWriter.pv"
                            bool success = Generator__write_function_name(generator, file, func_info, &resolved_generics);
                            #line 142 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 143 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 144 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 144 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 144 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 145 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 145 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 145 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 146 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression_replacing(self, file, arg->value, replace, replacement_name, replacement_type, generics) && success;
                            } }
                            #line 148 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ")");
                            #line 149 "src/compiler/ExpressionWriter.pv"
                            return success;
                        } break;
                        #line 151 "src/compiler/ExpressionWriter.pv"
                        case TYPE__FUNCTION_C: {
                            #line 151 "src/compiler/ExpressionWriter.pv"
                            struct FunctionC* func_info = __pave_tmp_0->functionc_value;
                            #line 152 "src/compiler/ExpressionWriter.pv"
                            bool success = Generator__write_str(generator, file, func_info->name);
                            #line 153 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 154 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 155 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 155 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 155 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 156 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 156 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 156 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 157 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression_replacing(self, file, arg->value, replace, replacement_name, replacement_type, generics) && success;
                            } }
                            #line 159 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ")");
                            #line 160 "src/compiler/ExpressionWriter.pv"
                            return success;
                        } break;
                        #line 162 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 165 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 168 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 170 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 170 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 171 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 172 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, inner, replace, replacement_name, replacement_type, generics);
            #line 173 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 174 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 176 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 177 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_expression(self, file, expression, generics);
        } break;
    }

    #line 181 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 186 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_pure(struct ExpressionWriter* self, struct Expression* expression) {
    #line 187 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 188 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 188 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 189 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 189 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 190 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 190 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 191 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 191 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 192 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 192 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 193 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 193 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 193 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, inner);
        } break;
        #line 194 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 194 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 194 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 194 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, left) && ExpressionWriter__is_pure(self, right);
        } break;
        #line 195 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 195 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 195 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 195 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 195 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, cond) && ExpressionWriter__is_pure(self, a) && ExpressionWriter__is_pure(self, b);
        } break;
        #line 196 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 196 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = expression->data.memberstaticexpression_value._0;
            #line 196 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, parent);
        } break;
        #line 197 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 197 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = expression->data.memberinstanceexpression_value._0;
            #line 197 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, parent);
        } break;
        #line 198 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 198 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = expression->data.indexexpression_value._0;
            #line 198 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = expression->data.indexexpression_value._1;
            #line 198 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, array_expr) && ExpressionWriter__is_pure(self, index_expr);
        } break;
        #line 199 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 199 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 199 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, inner);
        } break;
        #line 200 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 200 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 200 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_pure(self, inner);
        } break;
        #line 201 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 201 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 203 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 207 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_place(struct ExpressionWriter* self, struct Expression* expression) {
    #line 208 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 209 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 209 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 210 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 210 "src/compiler/ExpressionWriter.pv"
            struct str operator = expression->data.unaryexpression_value._0;
            #line 210 "src/compiler/ExpressionWriter.pv"
            return str__Eq_str__eq(operator, (struct str){ .ptr = "*", .length = strlen("*") });
        } break;
        #line 211 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 211 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = expression->data.memberinstanceexpression_value._0;
            #line 211 "src/compiler/ExpressionWriter.pv"
            return Type__is_indirect(&parent->return_type) || ExpressionWriter__is_place(self, parent);
        } break;
        #line 212 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 212 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = expression->data.indexexpression_value._0;
            #line 212 "src/compiler/ExpressionWriter.pv"
            return Type__is_indirect(&array_expr->return_type) || ExpressionWriter__is_place(self, array_expr);
        } break;
        #line 213 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 213 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 213 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_place(self, inner);
        } break;
        #line 214 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 214 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 216 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 221 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__make_temp(struct ExpressionWriter* self, struct Type* type) {
    #line 222 "src/compiler/ExpressionWriter.pv"
    struct FunctionContext* function_context = self->generator->function_context;
    #line 223 "src/compiler/ExpressionWriter.pv"
    if (function_context == 0) {
        #line 223 "src/compiler/ExpressionWriter.pv"
        return (struct str){ .ptr = "", .length = strlen("") };
    }
    #line 224 "src/compiler/ExpressionWriter.pv"
    return FunctionContext__add_temp(function_context, type);
}

#line 228 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_unary_operator(struct ExpressionWriter* self, FILE* file, struct str operator, struct Expression* inner) {
    #line 229 "src/compiler/ExpressionWriter.pv"
    Generator__write_str(self->generator, file, operator);
    #line 230 "src/compiler/ExpressionWriter.pv"
    if (usize__Eq_usize__eq(operator.length, 0)) {
        #line 230 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 232 "src/compiler/ExpressionWriter.pv"
    switch (inner->data.type) {
        #line 233 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 233 "src/compiler/ExpressionWriter.pv"
            struct str inner_operator = inner->data.unaryexpression_value._0;
            #line 234 "src/compiler/ExpressionWriter.pv"
            char last = operator.ptr[operator.length - 1];
            #line 235 "src/compiler/ExpressionWriter.pv"
            if (inner_operator.length > 0 && char__Eq_char__eq(inner_operator.ptr[0], last) && (char__Eq_char__eq(last, '-') || char__Eq_char__eq(last, '+') || char__Eq_char__eq(last, '&'))) {
                #line 236 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " ");
            }
        } break;
        #line 239 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 239 "src/compiler/ExpressionWriter.pv"
            struct str value = inner->data.literal_value;
            #line 240 "src/compiler/ExpressionWriter.pv"
            if (value.length > 0 && char__Eq_char__eq(value.ptr[0], '-') && char__Eq_char__eq(operator.ptr[operator.length - 1], '-')) {
                #line 241 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " ");
            }
        } break;
        #line 244 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }
}

#line 248 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_safe_to_duplicate(struct ExpressionWriter* self, struct Expression* expression) {
    #line 249 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 250 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 250 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 251 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 251 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 252 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 252 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 253 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 253 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 253 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_safe_to_duplicate(self, inner);
        } break;
        #line 254 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 254 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 256 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 259 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__optional_needs_lowering(struct ExpressionWriter* self, struct Expression* expression) {
    #line 260 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 261 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 261 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 262 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 262 "src/compiler/ExpressionWriter.pv"
                return true;
            }
            #line 263 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__optional_needs_lowering(self, receiver);
        } break;
        #line 265 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 265 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 267 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 270 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__lower_optional_to_temp(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics, uintptr_t* count) {
    #line 271 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 273 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 274 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 274 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 274 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 275 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 276 "src/compiler/ExpressionWriter.pv"
                struct str inner_temp = ExpressionWriter__lower_optional_to_temp(self, file, receiver, generics, count);
                #line 277 "src/compiler/ExpressionWriter.pv"
                struct str temp = ExpressionWriter__make_optional_temp_name(self, count);
                #line 278 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 279 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable_decl(generator, file, temp, &expression->return_type, generics);
                #line 280 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = (");
                #line 281 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, inner_temp);
                #line 282 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " == 0 ? 0 : ");
                #line 283 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, inner_temp, &receiver->return_type, generics);
                #line 284 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ");\n");
                #line 285 "src/compiler/ExpressionWriter.pv"
                return temp;
            }
        } break;
        #line 288 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 291 "src/compiler/ExpressionWriter.pv"
    struct str temp = ExpressionWriter__make_optional_temp_name(self, count);
    #line 292 "src/compiler/ExpressionWriter.pv"
    Generator__write_indent(generator, file);
    #line 293 "src/compiler/ExpressionWriter.pv"
    Generator__write_variable_decl(generator, file, temp, &expression->return_type, generics);
    #line 294 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " = ");
    #line 295 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, expression, generics);
    #line 296 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ";\n");
    #line 297 "src/compiler/ExpressionWriter.pv"
    return temp;
}

#line 300 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics) {
    #line 301 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 302 "src/compiler/ExpressionWriter.pv"
    uintptr_t count = 0;

    #line 304 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 305 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 305 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 305 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 306 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 307 "src/compiler/ExpressionWriter.pv"
                struct str temp = ExpressionWriter__lower_optional_to_temp(self, file, receiver, generics, &count);
                #line 308 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 309 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, target_name);
                #line 310 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = (");
                #line 311 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, temp);
                #line 312 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " == 0 ? 0 : ");
                #line 313 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, temp, &receiver->return_type, generics);
                #line 314 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ");\n");
                #line 315 "src/compiler/ExpressionWriter.pv"
                return true;
            }
        } break;
        #line 318 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 321 "src/compiler/ExpressionWriter.pv"
    Generator__write_indent(generator, file);
    #line 322 "src/compiler/ExpressionWriter.pv"
    Generator__write_variable(generator, file, target_name);
    #line 323 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " = ");
    #line 324 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, expression, generics);
    #line 325 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ";\n");
    #line 326 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 329 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 331 "src/compiler/ExpressionWriter.pv"
    struct str temp = (struct str){ .ptr = "", .length = strlen("") };
    #line 332 "src/compiler/ExpressionWriter.pv"
    if (!ExpressionWriter__is_pure(self, inner_expr)) {
        #line 332 "src/compiler/ExpressionWriter.pv"
        temp = ExpressionWriter__make_temp(self, &inner_expr->return_type);
    }

    #line 334 "src/compiler/ExpressionWriter.pv"
    if (temp.length > 0) {
        #line 335 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 336 "src/compiler/ExpressionWriter.pv"
        Generator__write_variable(self->generator, file, temp);
        #line 337 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " = ");
        #line 338 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
        #line 339 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", ");
    }

    #line 342 "src/compiler/ExpressionWriter.pv"
    if (reference) {
        #line 342 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "&");
    }
    #line 343 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 344 "src/compiler/ExpressionWriter.pv"
    if (temp.length > 0) {
        #line 344 "src/compiler/ExpressionWriter.pv"
        Generator__write_variable(self->generator, file, temp);
    } else {
        #line 344 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }
    #line 345 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = strlen(");
    #line 346 "src/compiler/ExpressionWriter.pv"
    if (temp.length > 0) {
        #line 346 "src/compiler/ExpressionWriter.pv"
        Generator__write_variable(self->generator, file, temp);
    } else {
        #line 346 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }
    #line 347 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") }");

    #line 349 "src/compiler/ExpressionWriter.pv"
    if (temp.length > 0) {
        #line 349 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
    }
}

#line 352 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 353 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 354 "src/compiler/ExpressionWriter.pv"
    struct Type* __pave_tmp_0 = Type__deref(&inner_expr->return_type);
    switch (__pave_tmp_0->type) {
        #line 355 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION: {
            #line 355 "src/compiler/ExpressionWriter.pv"
            struct Function* func_info = __pave_tmp_0->function_value._0;
            #line 355 "src/compiler/ExpressionWriter.pv"
            struct GenericMap* func_generics = __pave_tmp_0->function_value._1;
            #line 356 "src/compiler/ExpressionWriter.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 357 "src/compiler/ExpressionWriter.pv"
                struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
                #line 358 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Co_");
                #line 359 "src/compiler/ExpressionWriter.pv"
                Generator__write_string(generator, file, &co_ret_name);
                #line 360 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ") { .vtable = &");
                #line 361 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 362 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 363 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 364 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Co_");
                #line 365 "src/compiler/ExpressionWriter.pv"
                Generator__write_string(generator, file, &co_ret_name);
                #line 366 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Instance) {}");
                #line 367 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 369 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");
                #line 370 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 371 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 372 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 373 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Fn__Instance) {}");
                #line 374 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            }

            #line 377 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
        #line 379 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 382 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 383 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 383 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 384 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 385 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 386 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 387 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 389 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 390 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 391 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 393 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 394 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 395 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = ");
            #line 396 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 397 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " }");
        } break;
        #line 399 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 399 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 403 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_trait_value_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 404 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 406 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 407 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 407 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 408 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 409 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 410 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 411 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 413 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, &inner_expr->return_type, generics, 0);
            #line 414 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 415 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 417 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 418 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 419 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = (");
            #line 420 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &inner_expr->return_type, generics);
            #line 421 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[]) {");
            #line 422 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 423 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "} }");
            #line 424 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 426 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 429 "src/compiler/ExpressionWriter.pv"
    return ExpressionWriter__write_expression(self, file, inner_expr, generics);
}

#line 432 "src/compiler/ExpressionWriter.pv"
struct Type* ExpressionWriter__should_use_trait_value_cast(struct ExpressionWriter* self, struct Type* element_type, struct Expression* arg) {
    #line 433 "src/compiler/ExpressionWriter.pv"
    if (Type__is_indirect(&arg->return_type)) {
        #line 434 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 437 "src/compiler/ExpressionWriter.pv"
    switch (element_type->type) {
        #line 438 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 438 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = element_type->indirect_value;
            #line 439 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 440 "src/compiler/ExpressionWriter.pv"
                case TYPE__TRAIT: {
                    #line 441 "src/compiler/ExpressionWriter.pv"
                    return &indirect->to;
                } break;
                #line 443 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 446 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 449 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 452 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 453 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 454 "src/compiler/ExpressionWriter.pv"
    struct Sequence* inner_sequence = 0;

    #line 456 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->return_type.type) {
        #line 457 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 457 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 458 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 459 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 459 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 459 "src/compiler/ExpressionWriter.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 460 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 463 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 466 "src/compiler/ExpressionWriter.pv"
    if (inner_sequence == 0) {
        #line 467 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 468 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 471 "src/compiler/ExpressionWriter.pv"
    struct Expression* length_expr = 0;
    #line 472 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 473 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 473 "src/compiler/ExpressionWriter.pv"
            struct Expression* seq_length = inner_sequence->type.fixedarray_value;
            #line 473 "src/compiler/ExpressionWriter.pv"
            length_expr = seq_length;
        } break;
        #line 474 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 475 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 476 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
    }

    #line 480 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 481 "src/compiler/ExpressionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 482 "src/compiler/ExpressionWriter.pv"
    struct Expression* unary_inner = 0;

    #line 484 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->data.type) {
        #line 485 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 485 "src/compiler/ExpressionWriter.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 485 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 486 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 487 "src/compiler/ExpressionWriter.pv"
                unary_inner = inner;
            }
        } break;
        #line 490 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 493 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 494 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 495 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 497 "src/compiler/ExpressionWriter.pv"
    if (unary_inner != 0) {
        #line 498 "src/compiler/ExpressionWriter.pv"
        bool is_array_literal = false;
        #line 499 "src/compiler/ExpressionWriter.pv"
        switch (unary_inner->data.type) {
            #line 500 "src/compiler/ExpressionWriter.pv"
            case EXPRESSION_DATA__INVOKE: {
                #line 500 "src/compiler/ExpressionWriter.pv"
                struct Expression* target = unary_inner->data.invoke_value._0;
                #line 501 "src/compiler/ExpressionWriter.pv"
                switch (target->return_type.type) {
                    #line 502 "src/compiler/ExpressionWriter.pv"
                    case TYPE__SEQUENCE: {
                        #line 502 "src/compiler/ExpressionWriter.pv"
                        struct Sequence* seq = target->return_type.sequence_value;
                        #line 503 "src/compiler/ExpressionWriter.pv"
                        switch (seq->type.type) {
                            #line 504 "src/compiler/ExpressionWriter.pv"
                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                #line 504 "src/compiler/ExpressionWriter.pv"
                                is_array_literal = true;
                            } break;
                            #line 505 "src/compiler/ExpressionWriter.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 508 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 511 "src/compiler/ExpressionWriter.pv"
            default: {
            } break;
        }

        #line 514 "src/compiler/ExpressionWriter.pv"
        if (is_array_literal) {
            #line 515 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 516 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &sequence->element, generics);
            #line 517 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[])");
        }
        #line 519 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, unary_inner, generics);
    } else {
        #line 521 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "*");
        #line 522 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }

    #line 525 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = ");
    #line 526 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, length_expr, generics);
    #line 527 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
}

#line 530 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 531 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 532 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(generator, type, generics)) {
        #line 533 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 534 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (usize__Eq_usize__eq(fields->length, 1)) {
            #line 536 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 537 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, (*field).value, generics);
        } else {
            #line 539 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 542 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (usize__Eq_usize__eq(fields->data[0].value->token->start_line, fields->data[fields->length - 1].value->token->start_line));

        #line 544 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 545 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);

        #line 547 "src/compiler/ExpressionWriter.pv"
        if (usize__Eq_usize__eq(fields->length, 0)) {
            #line 548 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 550 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 551 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 551 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 554 "src/compiler/ExpressionWriter.pv"
        generator->indent += 1;
        #line 555 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 555 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 555 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 555 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 556 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 557 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 557 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 558 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 560 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 561 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 564 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, field->name);
            #line 565 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 566 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 567 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 567 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 570 "src/compiler/ExpressionWriter.pv"
        generator->indent -= 1;

        #line 572 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 573 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 574 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 576 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 577 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 582 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 585 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 586 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 587 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 589 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 590 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, variant);
        #line 591 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 594 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 595 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(generator, file, type, generics);
    #line 596 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 597 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(generator, file, type, variant);

    #line 599 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 600 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 601 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 604 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 605 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 606 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 607 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(generator, file, name->value);
        #line 608 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 611 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 612 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 613 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 614 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 614 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 614 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 615 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 615 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 615 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 616 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 617 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, arg.name);
            #line 618 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 619 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 621 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (usize__Eq_usize__eq(arguments->length, 1)) {
        #line 623 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 625 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 627 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 628 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 628 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 628 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 629 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 629 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 630 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 631 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 632 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 635 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 638 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 639 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 642 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 643 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 644 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 646 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 647 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 647 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 648 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 649 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 649 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 649 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 650 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);

                    #line 652 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 653 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(generator, file, func_info, &resolved_generics);
                    #line 654 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 656 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 657 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 657 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 657 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 658 "src/compiler/ExpressionWriter.pv"
                        if (usize__Eq_usize__eq(i, 0)) {
                            #line 658 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 659 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 661 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(generator, file, param->name);
                        #line 662 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 664 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 665 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 667 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 670 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 673 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 674 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 676 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 679 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 682 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 683 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 686 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 687 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 688 "src/compiler/ExpressionWriter.pv"
    struct Token func_name = *func_info->name;
    #line 689 "src/compiler/ExpressionWriter.pv"
    struct str name = func_name.value;

    #line 691 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 692 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 693 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 694 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 694 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 695 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(generator, file, type, generics);
    }

    #line 698 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(name, (struct str){ .ptr = "typename", .length = strlen("typename") })) {
        #line 699 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 700 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 701 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 701 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 702 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typename(generator, file, type, generics);
    }

    #line 705 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 706 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 707 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 708 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 708 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 709 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 710 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 710 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 711 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 712 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 713 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 714 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 715 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 716 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 719 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(generator, file, func_info->name);
    #line 720 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 721 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 722 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 722 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 722 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 723 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 723 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 723 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 724 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 726 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 727 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 730 "src/compiler/ExpressionWriter.pv"
struct Sequence* ExpressionWriter__get_typed_variadic_sequence(struct ExpressionWriter* self, struct Function* func_info) {
    #line 731 "src/compiler/ExpressionWriter.pv"
    if (!func_info->typed_variadic || usize__Eq_usize__eq(func_info->parameters.length, 0)) {
        #line 731 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 733 "src/compiler/ExpressionWriter.pv"
    struct Parameter* param = Array_Parameter__get(&func_info->parameters, func_info->parameters.length - 1);
    #line 734 "src/compiler/ExpressionWriter.pv"
    if (param == 0) {
        #line 734 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 736 "src/compiler/ExpressionWriter.pv"
    switch (param->type.type) {
        #line 737 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 737 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = param->type.indirect_value;
            #line 738 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 739 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 739 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 740 "src/compiler/ExpressionWriter.pv"
                    return sequence;
                } break;
                #line 742 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 745 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 748 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 751 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_typed_variadic_slice(struct ExpressionWriter* self, FILE* file, struct Sequence* sequence, struct Array_InvokeArgument* arguments, uintptr_t start, struct GenericMap* generics) {
    #line 752 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 753 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 754 "src/compiler/ExpressionWriter.pv"
    struct String sequence_name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 755 "src/compiler/ExpressionWriter.pv"
    bool success = true;
    #line 756 "src/compiler/ExpressionWriter.pv"
    uintptr_t length = arguments->length - start;

    #line 758 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 759 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &sequence_name);
    #line 760 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 762 "src/compiler/ExpressionWriter.pv"
    if (usize__Eq_usize__eq(length, 0)) {
        #line 763 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "0");
    } else {
        #line 765 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 766 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, &sequence->element, generics);
        #line 767 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "[]) {");

        #line 769 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = start;
        #line 770 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 771 "src/compiler/ExpressionWriter.pv"
        while (i < arguments->length) {
            #line 772 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 772 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 772 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 773 "src/compiler/ExpressionWriter.pv"
            struct Expression* arg = arguments->data[i].value;
            #line 774 "src/compiler/ExpressionWriter.pv"
            struct Type* trait_type = ExpressionWriter__should_use_trait_value_cast(self, &sequence->element, arg);
            #line 775 "src/compiler/ExpressionWriter.pv"
            if (trait_type != 0) {
                #line 776 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_trait_value_cast(self, file, arg, trait_type, generics) && success;
            } else {
                #line 778 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg, generics) && success;
            }
            #line 780 "src/compiler/ExpressionWriter.pv"
            i += 1;
        }

        #line 783 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 786 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = %zu }", length);
    #line 787 "src/compiler/ExpressionWriter.pv"
    String__release(&sequence_name);
    #line 788 "src/compiler/ExpressionWriter.pv"
    return success;
}

#line 794 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__returns_cpp_reference(struct Type* function) {
    #line 795 "src/compiler/ExpressionWriter.pv"
    struct Type* return_type = 0;
    #line 796 "src/compiler/ExpressionWriter.pv"
    switch (function->type) {
        #line 797 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION: {
            #line 797 "src/compiler/ExpressionWriter.pv"
            struct Function* func_info = function->function_value._0;
            #line 798 "src/compiler/ExpressionWriter.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 798 "src/compiler/ExpressionWriter.pv"
                return_type = &func_info->return_type;
            }
        } break;
        #line 800 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION_C: {
            #line 800 "src/compiler/ExpressionWriter.pv"
            struct FunctionC* func_info = function->functionc_value;
            #line 800 "src/compiler/ExpressionWriter.pv"
            return_type = &func_info->return_type;
        } break;
        #line 801 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }
    #line 803 "src/compiler/ExpressionWriter.pv"
    if (return_type == 0) {
        #line 803 "src/compiler/ExpressionWriter.pv"
        return false;
    }
    #line 804 "src/compiler/ExpressionWriter.pv"
    switch (return_type->type) {
        #line 805 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 805 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = return_type->indirect_value;
            #line 805 "src/compiler/ExpressionWriter.pv"
            return indirect->type == INDIRECT_TYPE__REFERENCE;
        } break;
        #line 806 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }
    #line 808 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 811 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 812 "src/compiler/ExpressionWriter.pv"
    if (ExpressionWriter__returns_cpp_reference(&expression->return_type)) {
        #line 814 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(&(");
        #line 815 "src/compiler/ExpressionWriter.pv"
        bool success = ExpressionWriter__write_invoke_call(self, file, expression, arguments, generics);
        #line 816 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "))");
        #line 817 "src/compiler/ExpressionWriter.pv"
        return success;
    }
    #line 819 "src/compiler/ExpressionWriter.pv"
    return ExpressionWriter__write_invoke_call(self, file, expression, arguments, generics);
}

#line 822 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke_call(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 823 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 824 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 825 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 826 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 826 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 827 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 828 "src/compiler/ExpressionWriter.pv"
            bool success = true;
            #line 829 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 830 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 831 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 831 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 831 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 832 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 832 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 832 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 833 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 835 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 836 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 838 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 839 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 840 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 841 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 842 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 842 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 842 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 843 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 843 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 843 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 844 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 846 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 847 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 849 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 850 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 851 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 852 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 853 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 853 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 853 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 854 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 854 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 854 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 855 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 857 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 858 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 860 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 860 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 861 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 863 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 863 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 864 "src/compiler/ExpressionWriter.pv"
            struct Type* invoke_type = type;
            #line 865 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 866 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 867 "src/compiler/ExpressionWriter.pv"
                    invoke_type = generics->self_type;
                } break;
                #line 869 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 871 "src/compiler/ExpressionWriter.pv"
            if (invoke_type == 0) {
                #line 871 "src/compiler/ExpressionWriter.pv"
                return false;
            }

            #line 873 "src/compiler/ExpressionWriter.pv"
            struct Type* __pave_tmp_0 = Type__resolve_typedef(invoke_type);
            switch (__pave_tmp_0->type) {
                #line 874 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 875 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 877 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 878 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 880 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 881 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 883 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 884 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 886 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 886 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = __pave_tmp_0->function_value._0;
                    #line 886 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = __pave_tmp_0->function_value._1;
                    #line 887 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 888 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 889 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 891 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 892 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 894 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 897 "src/compiler/ExpressionWriter.pv"
                    struct Token func_name = *func_info->name;
                    #line 898 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_name.value;
                    #line 899 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);
                    #line 900 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 901 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 902 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 903 "src/compiler/ExpressionWriter.pv"
                    uintptr_t arg_index = 0;
                    #line 904 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* variadic_sequence = ExpressionWriter__get_typed_variadic_sequence(self, func_info);
                    #line 905 "src/compiler/ExpressionWriter.pv"
                    uintptr_t variadic_start = arguments->length;
                    #line 906 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 907 "src/compiler/ExpressionWriter.pv"
                        variadic_start = func_info->parameters.length - 1;
                    }
                    #line 909 "src/compiler/ExpressionWriter.pv"
                    struct str receiver_temp = (struct str){ .ptr = "", .length = strlen("") };

                    #line 911 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 912 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 912 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 913 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 914 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 915 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 918 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 920 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 923 "src/compiler/ExpressionWriter.pv"
                                if (!ExpressionWriter__is_pure(self, arg->value)) {
                                    #line 923 "src/compiler/ExpressionWriter.pv"
                                    receiver_temp = ExpressionWriter__make_temp(self, &arg->value->return_type);
                                }

                                #line 925 "src/compiler/ExpressionWriter.pv"
                                if (receiver_temp.length > 0) {
                                    #line 926 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, "(");
                                    #line 927 "src/compiler/ExpressionWriter.pv"
                                    Generator__write_variable(generator, file, receiver_temp);
                                    #line 928 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " = ");
                                    #line 929 "src/compiler/ExpressionWriter.pv"
                                    success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                    #line 930 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                    #line 931 "src/compiler/ExpressionWriter.pv"
                                    Generator__write_variable(generator, file, receiver_temp);
                                } else {
                                    #line 933 "src/compiler/ExpressionWriter.pv"
                                    success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                }
                                #line 935 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->fn_");
                                #line 936 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 937 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 938 "src/compiler/ExpressionWriter.pv"
                                if (receiver_temp.length > 0) {
                                    #line 939 "src/compiler/ExpressionWriter.pv"
                                    Generator__write_variable(generator, file, receiver_temp);
                                } else {
                                    #line 941 "src/compiler/ExpressionWriter.pv"
                                    success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                }
                                #line 943 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 944 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 945 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            } else {
                                #line 947 "src/compiler/ExpressionWriter.pv"
                                struct Function* type_impl_function = Root__find_type_impl_function(generator->root, &arg->value->return_type, name, 0);
                                #line 948 "src/compiler/ExpressionWriter.pv"
                                if (type_impl_function != 0) {
                                    #line 949 "src/compiler/ExpressionWriter.pv"
                                    success = Generator__write_function_name(generator, file, type_impl_function, &resolved_generics) && success;
                                } else {
                                    #line 951 "src/compiler/ExpressionWriter.pv"
                                    struct String parent_name = Naming__get_type_name(&generator->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                    #line 952 "src/compiler/ExpressionWriter.pv"
                                    struct Type resolved_trait_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(generator->allocator, &resolved_generics)} };
                                    #line 953 "src/compiler/ExpressionWriter.pv"
                                    struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, &resolved_trait_type, func_info, generics);
                                    #line 954 "src/compiler/ExpressionWriter.pv"
                                    success = Generator__write_string(generator, file, &function_name) && success;
                                }
                                #line 956 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 957 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 958 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 959 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            }
                        } break;
                        #line 962 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 963 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(generator, file, func_info, &resolved_generics) && success;
                            #line 964 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 968 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 968 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 968 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 969 "src/compiler/ExpressionWriter.pv"
                        if (variadic_sequence != 0 && arg_index >= variadic_start) {
                            #line 970 "src/compiler/ExpressionWriter.pv"
                            break;
                        }
                        #line 972 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 972 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 972 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 973 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        #line 974 "src/compiler/ExpressionWriter.pv"
                        arg_index += 1;
                    } }

                    #line 977 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 978 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 978 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 978 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 979 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_typed_variadic_slice(self, file, variadic_sequence, arguments, variadic_start, generics) && success;
                    }

                    #line 982 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 983 "src/compiler/ExpressionWriter.pv"
                    if (receiver_temp.length > 0) {
                        #line 983 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    }
                    #line 984 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 986 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 986 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = __pave_tmp_0->functionc_value;
                    #line 987 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 988 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(generator, file, name);
                    #line 989 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 990 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 991 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 991 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 991 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 992 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 992 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 992 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 993 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 995 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 996 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 998 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 998 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = __pave_tmp_0->sequence_value;
                    #line 999 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 1000 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 1001 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1002 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 1003 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 1004 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 1004 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 1004 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 1005 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 1005 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 1005 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 1006 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 1008 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 1010 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1011 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 1012 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(generator, file, &expression->return_type, generics);
                            #line 1013 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 1014 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 1015 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 1015 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 1015 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 1016 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 1016 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 1016 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 1016 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 1017 "src/compiler/ExpressionWriter.pv"
                                struct Token arg_name = *arg->name;
                                #line 1018 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, arg_name.value) && success;
                                #line 1019 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 1020 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 1022 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 1025 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 1027 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 1028 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(generator, file, type, generics);
                    #line 1029 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 1031 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 1032 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 1033 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 1034 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 1034 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 1034 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 1035 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 1035 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 1035 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 1036 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 1038 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 1040 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 1041 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 1042 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 1042 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 1042 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 1043 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 1043 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 1043 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 1043 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 1044 "src/compiler/ExpressionWriter.pv"
                            struct Token arg_name = *arg->name;
                            #line 1045 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(generator, file, arg_name.value) && success;
                            #line 1046 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 1047 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 1049 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 1051 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 1053 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1054 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 1055 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 1059 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 1062 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 1063 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 1066 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 1067 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1068 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 1070 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 1071 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 1071 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 1072 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 1073 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1075 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1075 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 1076 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 1077 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1079 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 1080 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 1081 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1083 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1083 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 1083 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 1084 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 1086 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 1086 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 1087 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 1089 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 1089 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 1089 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 1090 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__Eq_str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 1091 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 1092 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 1093 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 1096 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 1097 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 1098 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 1099 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 1099 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 1100 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 1100 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 1101 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 1101 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 1102 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 1105 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 1108 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 1109 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, &inner->return_type, generics);
                    #line 1110 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 1111 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 1112 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 1113 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 1117 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_unary_operator(self, file, operator, inner);
            #line 1118 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 1119 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1121 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 1121 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 1121 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 1121 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 1122 "src/compiler/ExpressionWriter.pv"
            bool is_eq_or_ne = str__Eq_str__eq(operator, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(operator, (struct str){ .ptr = "!=", .length = strlen("!=") });

            #line 1124 "src/compiler/ExpressionWriter.pv"
            bool left_is_null = false;
            #line 1125 "src/compiler/ExpressionWriter.pv"
            bool right_is_null = false;
            #line 1126 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne) {
                #line 1127 "src/compiler/ExpressionWriter.pv"
                switch (left->data.type) {
                    #line 1128 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 1128 "src/compiler/ExpressionWriter.pv"
                        left_is_null = true;
                    } break;
                    #line 1129 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 1129 "src/compiler/ExpressionWriter.pv"
                        struct str v = left->data.literal_value;
                        #line 1129 "src/compiler/ExpressionWriter.pv"
                        if (str__Eq_str__eq(v, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 1129 "src/compiler/ExpressionWriter.pv"
                            left_is_null = true;
                        }
                    } break;
                    #line 1130 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
                #line 1132 "src/compiler/ExpressionWriter.pv"
                switch (right->data.type) {
                    #line 1133 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 1133 "src/compiler/ExpressionWriter.pv"
                        right_is_null = true;
                    } break;
                    #line 1134 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 1134 "src/compiler/ExpressionWriter.pv"
                        struct str v = right->data.literal_value;
                        #line 1134 "src/compiler/ExpressionWriter.pv"
                        if (str__Eq_str__eq(v, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 1134 "src/compiler/ExpressionWriter.pv"
                            right_is_null = true;
                        }
                    } break;
                    #line 1135 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            }

            #line 1139 "src/compiler/ExpressionWriter.pv"
            bool left_fat_null_cmp = is_eq_or_ne && right_is_null && Type__is_fat_pointer(&left->return_type);
            #line 1140 "src/compiler/ExpressionWriter.pv"
            bool right_fat_null_cmp = is_eq_or_ne && left_is_null && Type__is_fat_pointer(&right->return_type);

            #line 1142 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &left->return_type, generics)) {
                #line 1143 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1144 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 1145 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else if (left_fat_null_cmp) {
                #line 1147 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1148 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 1149 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").instance");
            } else {
                #line 1151 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
            }

            #line 1154 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);

            #line 1156 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &right->return_type, generics)) {
                #line 1157 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1158 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 1159 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else if (right_fat_null_cmp) {
                #line 1161 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1162 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 1163 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").instance");
            } else {
                #line 1165 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
            }

            #line 1168 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1170 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 1170 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 1170 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 1170 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 1172 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1173 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 1174 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 1175 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 1176 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 1177 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 1178 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1179 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1181 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 1181 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = data->optionalexpression_value._0;
            #line 1181 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = data->optionalexpression_value._1;
            #line 1184 "src/compiler/ExpressionWriter.pv"
            struct str temp = (struct str){ .ptr = "", .length = strlen("") };
            #line 1185 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 1185 "src/compiler/ExpressionWriter.pv"
                temp = ExpressionWriter__make_temp(self, &receiver->return_type);
            }

            #line 1187 "src/compiler/ExpressionWriter.pv"
            if (temp.length > 0) {
                #line 1188 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "((");
                #line 1189 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, temp);
                #line 1190 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = ");
                #line 1191 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, receiver, generics);
                #line 1192 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ") == 0 ? 0 : ");
                #line 1193 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, temp, &receiver->return_type, generics);
                #line 1194 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ")");
                #line 1195 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 1198 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1199 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, receiver, generics);
            #line 1200 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " == 0 ? 0 : ");
            #line 1201 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, value, generics);
            #line 1202 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1203 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1205 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 1205 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 1205 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 1206 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 1207 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1208 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 1209 "src/compiler/ExpressionWriter.pv"
                    if (generics->self_type != 0) {
                        #line 1209 "src/compiler/ExpressionWriter.pv"
                        parent_type = generics->self_type;
                    }
                } break;
                #line 1211 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 1213 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1214 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1214 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 1215 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 1215 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1215 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1216 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 1217 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 1218 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 1219 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 1220 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 1221 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 1222 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 1226 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 1226 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 1227 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 1227 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1227 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1228 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 1229 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 1230 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 1231 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 1232 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 1233 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 1234 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 1238 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 1240 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 1241 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(generator, file, generics);
            #line 1242 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 1243 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1245 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1245 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 1245 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 1246 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 1247 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 1247 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = expression->return_type.function_value._0;
                    #line 1248 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 1249 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TYPE: {
                            #line 1249 "src/compiler/ExpressionWriter.pv"
                            struct Type* type = func_info->parent.type_value._0;
                            #line 1249 "src/compiler/ExpressionWriter.pv"
                            uintptr_t impl_index = func_info->parent.type_value._1;
                            #line 1249 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.type_value._2;
                            #line 1250 "src/compiler/ExpressionWriter.pv"
                            struct Type* named_type = type;
                            #line 1251 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_fat_pointer(type)) {
                                #line 1252 "src/compiler/ExpressionWriter.pv"
                                named_type = Type__deref_1(type);
                                #line 1253 "src/compiler/ExpressionWriter.pv"
                                if (named_type == 0) {
                                    #line 1253 "src/compiler/ExpressionWriter.pv"
                                    named_type = type;
                                }
                            }
                            #line 1255 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, named_type, type, generics);
                            #line 1256 "src/compiler/ExpressionWriter.pv"
                            if (trait_info != 0) {
                                #line 1257 "src/compiler/ExpressionWriter.pv"
                                struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type, impl_index);
                                #line 1258 "src/compiler/ExpressionWriter.pv"
                                struct Type* impl_trait_type = 0;
                                #line 1259 "src/compiler/ExpressionWriter.pv"
                                if (type_impl != 0) {
                                    #line 1259 "src/compiler/ExpressionWriter.pv"
                                    impl_trait_type = &type_impl->impl_info->trait_type;
                                }
                                #line 1260 "src/compiler/ExpressionWriter.pv"
                                struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, impl_trait_type, func_info, generics);
                                #line 1261 "src/compiler/ExpressionWriter.pv"
                                return Generator__write_string(generator, file, &function_name);
                            }
                            #line 1263 "src/compiler/ExpressionWriter.pv"
                            Generator__write_string(generator, file, &parent_name);
                            #line 1264 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "__");
                            #line 1265 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                            #line 1266 "src/compiler/ExpressionWriter.pv"
                            return true;
                        } break;
                        #line 1268 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1271 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 1274 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 1275 "src/compiler/ExpressionWriter.pv"
            struct Function* type_impl_function = Root__find_type_impl_function(generator->root, parent_type, member, 0);
            #line 1276 "src/compiler/ExpressionWriter.pv"
            if (type_impl_function != 0) {
                #line 1277 "src/compiler/ExpressionWriter.pv"
                switch (type_impl_function->parent.type) {
                    #line 1278 "src/compiler/ExpressionWriter.pv"
                    case FUNCTION_PARENT__TYPE: {
                        #line 1278 "src/compiler/ExpressionWriter.pv"
                        struct Type* type = type_impl_function->parent.type_value._0;
                        #line 1278 "src/compiler/ExpressionWriter.pv"
                        uintptr_t impl_index = type_impl_function->parent.type_value._1;
                        #line 1278 "src/compiler/ExpressionWriter.pv"
                        struct Trait* trait_info = type_impl_function->parent.type_value._2;
                        #line 1279 "src/compiler/ExpressionWriter.pv"
                        struct Type* named_type = type;
                        #line 1280 "src/compiler/ExpressionWriter.pv"
                        if (Type__is_fat_pointer(type)) {
                            #line 1281 "src/compiler/ExpressionWriter.pv"
                            named_type = Type__deref_1(type);
                            #line 1282 "src/compiler/ExpressionWriter.pv"
                            if (named_type == 0) {
                                #line 1282 "src/compiler/ExpressionWriter.pv"
                                named_type = type;
                            }
                        }
                        #line 1284 "src/compiler/ExpressionWriter.pv"
                        struct String parent_name = Naming__get_type_name(&generator->naming_ident, named_type, parent_type, generics);
                        #line 1285 "src/compiler/ExpressionWriter.pv"
                        if (trait_info != 0) {
                            #line 1286 "src/compiler/ExpressionWriter.pv"
                            struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type, impl_index);
                            #line 1287 "src/compiler/ExpressionWriter.pv"
                            struct Type* impl_trait_type = 0;
                            #line 1288 "src/compiler/ExpressionWriter.pv"
                            if (type_impl != 0) {
                                #line 1288 "src/compiler/ExpressionWriter.pv"
                                impl_trait_type = &type_impl->impl_info->trait_type;
                            }
                            #line 1289 "src/compiler/ExpressionWriter.pv"
                            struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, impl_trait_type, type_impl_function, generics);
                            #line 1290 "src/compiler/ExpressionWriter.pv"
                            return Generator__write_string(generator, file, &function_name);
                        }
                        #line 1292 "src/compiler/ExpressionWriter.pv"
                        Generator__write_string(generator, file, &parent_name);
                        #line 1293 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                        #line 1294 "src/compiler/ExpressionWriter.pv"
                        Generator__write_str(generator, file, member);
                        #line 1295 "src/compiler/ExpressionWriter.pv"
                        return true;
                    } break;
                    #line 1297 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 1300 "src/compiler/ExpressionWriter.pv"
                struct GenericMap type_impl_generics = (struct GenericMap) { .self_type = parent_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } };
                #line 1301 "src/compiler/ExpressionWriter.pv"
                return Generator__write_function_name(generator, file, type_impl_function, &type_impl_generics);
            }

            #line 1304 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, parent_type, generics)) {
                #line 1305 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 1306 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1306 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 1307 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 1308 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1308 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 1309 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 1312 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1313 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 1313 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 1314 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 1315 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1315 "src/compiler/ExpressionWriter.pv"
                            struct Expression* length = sequence->type.fixedarray_value;
                            #line 1316 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 1317 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, length, generics);
                            } else if (str__Eq_str__eq(member, (struct str){ .ptr = "data", .length = strlen("data") })) {
                                #line 1319 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, parent, generics);
                            } else {
                                #line 1321 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 1322 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(generator, file, member);
                                #line 1323 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 1326 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1327 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, parent, generics);
                            #line 1328 "src/compiler/ExpressionWriter.pv"
                            Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                            #line 1329 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                        } break;
                    }
                } break;
                #line 1333 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1334 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 1335 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                    #line 1336 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 1336 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 1337 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(generator, file, member);
                } break;
            }

            #line 1341 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1343 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1343 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 1344 "src/compiler/ExpressionWriter.pv"
            struct Type* resolved_type = type;
            #line 1345 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 1346 "src/compiler/ExpressionWriter.pv"
                case TYPE__GENERIC: {
                    #line 1346 "src/compiler/ExpressionWriter.pv"
                    struct Generic* generic = type->generic_value;
                    #line 1347 "src/compiler/ExpressionWriter.pv"
                    if (Generic__is_const(generic)) {
                        #line 1348 "src/compiler/ExpressionWriter.pv"
                        struct Token* generic_name = generic->name;
                        #line 1349 "src/compiler/ExpressionWriter.pv"
                        if (generic_name != 0) {
                            #line 1350 "src/compiler/ExpressionWriter.pv"
                            struct Type* concrete_type = GenericMap__get(generics, generic_name->value);
                            #line 1351 "src/compiler/ExpressionWriter.pv"
                            if (concrete_type != 0) {
                                #line 1352 "src/compiler/ExpressionWriter.pv"
                                resolved_type = concrete_type;
                            }
                        }
                    }
                } break;
                #line 1357 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 1359 "src/compiler/ExpressionWriter.pv"
            switch (resolved_type->type) {
                #line 1360 "src/compiler/ExpressionWriter.pv"
                case TYPE__CONST: {
                    #line 1360 "src/compiler/ExpressionWriter.pv"
                    struct Expression* const_expr = resolved_type->const_value;
                    #line 1361 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_expression(self, file, const_expr, generics);
                } break;
                #line 1363 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1364 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 1365 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
            }
        } break;
        #line 1369 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1369 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 1369 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 1370 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 1371 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 1372 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 1374 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 1375 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 1376 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 1377 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1379 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1379 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 1380 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1381 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 1382 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1383 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1385 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1385 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 1386 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 1387 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1387 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 1387 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 1388 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 1389 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 1390 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 1391 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 1393 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 1395 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 1397 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1397 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1398 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 1399 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 1402 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1404 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1404 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 1405 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 1406 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1406 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1407 "src/compiler/ExpressionWriter.pv"
                    struct Token struct_name = *struct_info->name;
                    #line 1408 "src/compiler/ExpressionWriter.pv"
                    if (str__Eq_str__eq(struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1409 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 1412 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 1412 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 1413 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 1414 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 1414 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 1415 "src/compiler/ExpressionWriter.pv"
                            struct Token struct_name = *struct_info->name;
                            #line 1416 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 1417 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 1419 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 1422 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 1422 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 1422 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 1423 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 1423 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 1426 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1426 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 1431 "src/compiler/ExpressionWriter.pv"
    return false;
}
