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
#include <analyzer/types/FunctionType.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <usize.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Array_str.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/Struct.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/HashMap_str_ref_ImplConst.h>
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
            Generator__write_str(generator, file, operator);
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
            struct Type* parent_type = parent == replace ? replacement_type : &parent->return_type;
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
                    switch (Type__resolve_typedef(type)->type) {
                        #line 139 "src/compiler/ExpressionWriter.pv"
                        case TYPE__FUNCTION: {
                            #line 139 "src/compiler/ExpressionWriter.pv"
                            struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                            #line 139 "src/compiler/ExpressionWriter.pv"
                            struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
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
                            struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
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

#line 184 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_safe_to_duplicate(struct ExpressionWriter* self, struct Expression* expression) {
    #line 185 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 186 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 186 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 187 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 187 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 188 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 188 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 189 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 189 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 189 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_safe_to_duplicate(self, inner);
        } break;
        #line 190 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 190 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 192 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 195 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__optional_needs_lowering(struct ExpressionWriter* self, struct Expression* expression) {
    #line 196 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 197 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 197 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 198 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 198 "src/compiler/ExpressionWriter.pv"
                return true;
            }
            #line 199 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__optional_needs_lowering(self, receiver);
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

#line 206 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__lower_optional_to_temp(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics, uintptr_t* count) {
    #line 207 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 209 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 210 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 210 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 210 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 211 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 212 "src/compiler/ExpressionWriter.pv"
                struct str inner_temp = ExpressionWriter__lower_optional_to_temp(self, file, receiver, generics, count);
                #line 213 "src/compiler/ExpressionWriter.pv"
                struct str temp = ExpressionWriter__make_optional_temp_name(self, count);
                #line 214 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 215 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable_decl(generator, file, temp, &expression->return_type, generics);
                #line 216 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = (");
                #line 217 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, inner_temp);
                #line 218 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " == 0 ? 0 : ");
                #line 219 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, inner_temp, &receiver->return_type, generics);
                #line 220 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ");\n");
                #line 221 "src/compiler/ExpressionWriter.pv"
                return temp;
            }
        } break;
        #line 224 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 227 "src/compiler/ExpressionWriter.pv"
    struct str temp = ExpressionWriter__make_optional_temp_name(self, count);
    #line 228 "src/compiler/ExpressionWriter.pv"
    Generator__write_indent(generator, file);
    #line 229 "src/compiler/ExpressionWriter.pv"
    Generator__write_variable_decl(generator, file, temp, &expression->return_type, generics);
    #line 230 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " = ");
    #line 231 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, expression, generics);
    #line 232 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ";\n");
    #line 233 "src/compiler/ExpressionWriter.pv"
    return temp;
}

#line 236 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics) {
    #line 237 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 238 "src/compiler/ExpressionWriter.pv"
    uintptr_t count = 0;

    #line 240 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 241 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 241 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 241 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 242 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 243 "src/compiler/ExpressionWriter.pv"
                struct str temp = ExpressionWriter__lower_optional_to_temp(self, file, receiver, generics, &count);
                #line 244 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 245 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, target_name);
                #line 246 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = (");
                #line 247 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, temp);
                #line 248 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " == 0 ? 0 : ");
                #line 249 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, temp, &receiver->return_type, generics);
                #line 250 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ");\n");
                #line 251 "src/compiler/ExpressionWriter.pv"
                return true;
            }
        } break;
        #line 254 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 257 "src/compiler/ExpressionWriter.pv"
    Generator__write_indent(generator, file);
    #line 258 "src/compiler/ExpressionWriter.pv"
    Generator__write_variable(generator, file, target_name);
    #line 259 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " = ");
    #line 260 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, expression, generics);
    #line 261 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ";\n");
    #line 262 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 265 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 266 "src/compiler/ExpressionWriter.pv"
    if (reference) {
        #line 266 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "&");
    }
    #line 267 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 268 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 269 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = strlen(");
    #line 270 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 271 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") }");
}

#line 274 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 275 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 276 "src/compiler/ExpressionWriter.pv"
    switch (Type__deref(&inner_expr->return_type)->type) {
        #line 277 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION: {
            #line 277 "src/compiler/ExpressionWriter.pv"
            struct Function* func_info = Type__deref(&inner_expr->return_type)->function_value._0;
            #line 277 "src/compiler/ExpressionWriter.pv"
            struct GenericMap* func_generics = Type__deref(&inner_expr->return_type)->function_value._1;
            #line 278 "src/compiler/ExpressionWriter.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 279 "src/compiler/ExpressionWriter.pv"
                struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
                #line 280 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Co_");
                #line 281 "src/compiler/ExpressionWriter.pv"
                Generator__write_string(generator, file, &co_ret_name);
                #line 282 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ") { .vtable = &");
                #line 283 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 284 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 285 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 286 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Co_");
                #line 287 "src/compiler/ExpressionWriter.pv"
                Generator__write_string(generator, file, &co_ret_name);
                #line 288 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Instance) {}");
                #line 289 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 291 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");
                #line 292 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 293 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 294 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 295 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Fn__Instance) {}");
                #line 296 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            }

            #line 299 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
        #line 301 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 304 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 305 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 305 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 306 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 307 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 308 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 309 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 311 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 312 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 313 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 315 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 316 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 317 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = ");
            #line 318 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 319 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " }");
        } break;
        #line 321 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 321 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 325 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_trait_value_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 326 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 328 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 329 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 329 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 330 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 331 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 332 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 333 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 335 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, &inner_expr->return_type, generics, 0);
            #line 336 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 337 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 339 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 340 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 341 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = (");
            #line 342 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &inner_expr->return_type, generics);
            #line 343 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[]) {");
            #line 344 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 345 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "} }");
            #line 346 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 348 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 351 "src/compiler/ExpressionWriter.pv"
    return ExpressionWriter__write_expression(self, file, inner_expr, generics);
}

#line 354 "src/compiler/ExpressionWriter.pv"
struct Type* ExpressionWriter__should_use_trait_value_cast(struct ExpressionWriter* self, struct Type* element_type, struct Expression* arg) {
    #line 355 "src/compiler/ExpressionWriter.pv"
    if (Type__is_indirect(&arg->return_type)) {
        #line 356 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 359 "src/compiler/ExpressionWriter.pv"
    switch (element_type->type) {
        #line 360 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 360 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = element_type->indirect_value;
            #line 361 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 362 "src/compiler/ExpressionWriter.pv"
                case TYPE__TRAIT: {
                    #line 363 "src/compiler/ExpressionWriter.pv"
                    return &indirect->to;
                } break;
                #line 365 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 368 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 371 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 374 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 375 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 376 "src/compiler/ExpressionWriter.pv"
    struct Sequence* inner_sequence = 0;

    #line 378 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->return_type.type) {
        #line 379 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 379 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 380 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 381 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 381 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 381 "src/compiler/ExpressionWriter.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 382 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 385 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 388 "src/compiler/ExpressionWriter.pv"
    if (inner_sequence == 0) {
        #line 389 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 390 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 393 "src/compiler/ExpressionWriter.pv"
    struct Expression* length_expr = 0;
    #line 394 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 395 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 395 "src/compiler/ExpressionWriter.pv"
            struct Expression* seq_length = inner_sequence->type.fixedarray_value;
            #line 395 "src/compiler/ExpressionWriter.pv"
            length_expr = seq_length;
        } break;
        #line 396 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 397 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 398 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
    }

    #line 402 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 403 "src/compiler/ExpressionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 404 "src/compiler/ExpressionWriter.pv"
    struct Expression* unary_inner = 0;

    #line 406 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->data.type) {
        #line 407 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 407 "src/compiler/ExpressionWriter.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 407 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 408 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 409 "src/compiler/ExpressionWriter.pv"
                unary_inner = inner;
            }
        } break;
        #line 412 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 415 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 416 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 417 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 419 "src/compiler/ExpressionWriter.pv"
    if (unary_inner != 0) {
        #line 420 "src/compiler/ExpressionWriter.pv"
        bool is_array_literal = false;
        #line 421 "src/compiler/ExpressionWriter.pv"
        switch (unary_inner->data.type) {
            #line 422 "src/compiler/ExpressionWriter.pv"
            case EXPRESSION_DATA__INVOKE: {
                #line 422 "src/compiler/ExpressionWriter.pv"
                struct Expression* target = unary_inner->data.invoke_value._0;
                #line 423 "src/compiler/ExpressionWriter.pv"
                switch (target->return_type.type) {
                    #line 424 "src/compiler/ExpressionWriter.pv"
                    case TYPE__SEQUENCE: {
                        #line 424 "src/compiler/ExpressionWriter.pv"
                        struct Sequence* seq = target->return_type.sequence_value;
                        #line 425 "src/compiler/ExpressionWriter.pv"
                        switch (seq->type.type) {
                            #line 426 "src/compiler/ExpressionWriter.pv"
                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                #line 426 "src/compiler/ExpressionWriter.pv"
                                is_array_literal = true;
                            } break;
                            #line 427 "src/compiler/ExpressionWriter.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 430 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 433 "src/compiler/ExpressionWriter.pv"
            default: {
            } break;
        }

        #line 436 "src/compiler/ExpressionWriter.pv"
        if (is_array_literal) {
            #line 437 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 438 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &sequence->element, generics);
            #line 439 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[])");
        }
        #line 441 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, unary_inner, generics);
    } else {
        #line 443 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "*");
        #line 444 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }

    #line 447 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = ");
    #line 448 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, length_expr, generics);
    #line 449 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
}

#line 452 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 453 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 454 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(generator, type, generics)) {
        #line 455 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 456 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (usize__Eq_usize__eq(fields->length, 1)) {
            #line 458 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 459 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, (*field).value, generics);
        } else {
            #line 461 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 464 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (usize__Eq_usize__eq(fields->data[0].value->token->start_line, fields->data[fields->length - 1].value->token->start_line));

        #line 466 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 467 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);

        #line 469 "src/compiler/ExpressionWriter.pv"
        if (usize__Eq_usize__eq(fields->length, 0)) {
            #line 470 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 472 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 473 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 473 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 476 "src/compiler/ExpressionWriter.pv"
        generator->indent += 1;
        #line 477 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 477 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 477 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 477 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 478 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 479 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 479 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 480 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 482 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 483 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 486 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, field->name);
            #line 487 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 488 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 489 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 489 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 492 "src/compiler/ExpressionWriter.pv"
        generator->indent -= 1;

        #line 494 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 495 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 496 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 498 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 499 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 504 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 507 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 508 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 509 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 511 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 512 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, variant);
        #line 513 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 516 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 517 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(generator, file, type, generics);
    #line 518 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 519 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(generator, file, type, variant);

    #line 521 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 522 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 523 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 526 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 527 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 528 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 529 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(generator, file, name->value);
        #line 530 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 533 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 534 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 535 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 536 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 536 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 536 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 537 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 537 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 537 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 538 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 539 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, arg.name);
            #line 540 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 541 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 543 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (usize__Eq_usize__eq(arguments->length, 1)) {
        #line 545 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 547 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 549 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 550 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 550 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 550 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 551 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 551 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 552 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 553 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 554 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 557 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 560 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 561 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 564 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 565 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 566 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 568 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 569 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 569 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 570 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 571 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 571 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 571 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 572 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);

                    #line 574 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 575 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(generator, file, func_info, &resolved_generics);
                    #line 576 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 578 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 579 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 579 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 579 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 580 "src/compiler/ExpressionWriter.pv"
                        if (usize__Eq_usize__eq(i, 0)) {
                            #line 580 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 581 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 583 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(generator, file, param->name);
                        #line 584 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 586 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 587 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 589 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 592 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 595 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 596 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 598 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 601 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 604 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 605 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 608 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 609 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 610 "src/compiler/ExpressionWriter.pv"
    struct Token func_name = *func_info->name;
    #line 611 "src/compiler/ExpressionWriter.pv"
    struct str name = func_name.value;

    #line 613 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 614 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 615 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 616 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 616 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 617 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(generator, file, type, generics);
    }

    #line 620 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(name, (struct str){ .ptr = "typename", .length = strlen("typename") })) {
        #line 621 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 622 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 623 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 623 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 624 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typename(generator, file, type, generics);
    }

    #line 627 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 628 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 629 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 630 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 630 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 631 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 632 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 632 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 633 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 634 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 635 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 636 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 637 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 638 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 641 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(generator, file, func_info->name);
    #line 642 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 643 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 644 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 644 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 644 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 645 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 645 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 645 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 646 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 648 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 649 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 652 "src/compiler/ExpressionWriter.pv"
struct Sequence* ExpressionWriter__get_typed_variadic_sequence(struct ExpressionWriter* self, struct Function* func_info) {
    #line 653 "src/compiler/ExpressionWriter.pv"
    if (!func_info->typed_variadic || usize__Eq_usize__eq(func_info->parameters.length, 0)) {
        #line 653 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 655 "src/compiler/ExpressionWriter.pv"
    struct Parameter* param = Array_Parameter__get(&func_info->parameters, func_info->parameters.length - 1);
    #line 656 "src/compiler/ExpressionWriter.pv"
    if (param == 0) {
        #line 656 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 658 "src/compiler/ExpressionWriter.pv"
    switch (param->type.type) {
        #line 659 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 659 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = param->type.indirect_value;
            #line 660 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 661 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 661 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 662 "src/compiler/ExpressionWriter.pv"
                    return sequence;
                } break;
                #line 664 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 667 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 670 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 673 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_typed_variadic_slice(struct ExpressionWriter* self, FILE* file, struct Sequence* sequence, struct Array_InvokeArgument* arguments, uintptr_t start, struct GenericMap* generics) {
    #line 674 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 675 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 676 "src/compiler/ExpressionWriter.pv"
    struct String sequence_name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 677 "src/compiler/ExpressionWriter.pv"
    bool success = true;
    #line 678 "src/compiler/ExpressionWriter.pv"
    uintptr_t length = arguments->length - start;

    #line 680 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 681 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &sequence_name);
    #line 682 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 684 "src/compiler/ExpressionWriter.pv"
    if (usize__Eq_usize__eq(length, 0)) {
        #line 685 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "0");
    } else {
        #line 687 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 688 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, &sequence->element, generics);
        #line 689 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "[]) {");

        #line 691 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = start;
        #line 692 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 693 "src/compiler/ExpressionWriter.pv"
        while (i < arguments->length) {
            #line 694 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 694 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 694 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 695 "src/compiler/ExpressionWriter.pv"
            struct Expression* arg = arguments->data[i].value;
            #line 696 "src/compiler/ExpressionWriter.pv"
            struct Type* trait_type = ExpressionWriter__should_use_trait_value_cast(self, &sequence->element, arg);
            #line 697 "src/compiler/ExpressionWriter.pv"
            if (trait_type != 0) {
                #line 698 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_trait_value_cast(self, file, arg, trait_type, generics) && success;
            } else {
                #line 700 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg, generics) && success;
            }
            #line 702 "src/compiler/ExpressionWriter.pv"
            i += 1;
        }

        #line 705 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 708 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = %zu }", length);
    #line 709 "src/compiler/ExpressionWriter.pv"
    String__release(&sequence_name);
    #line 710 "src/compiler/ExpressionWriter.pv"
    return success;
}

#line 713 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 714 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 715 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 716 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 717 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 717 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 718 "src/compiler/ExpressionWriter.pv"
            bool success = Generator__write_str(generator, file, name);
            #line 719 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 720 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 721 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 721 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 721 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 722 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 722 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 722 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 723 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 725 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 726 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 728 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 729 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 730 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 731 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 732 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 732 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 732 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 733 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 733 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 733 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 734 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 736 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 737 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 739 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 740 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 741 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 742 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 743 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 743 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 743 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 744 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 744 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 744 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 745 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 747 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 748 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 750 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 750 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 751 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 753 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 753 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 754 "src/compiler/ExpressionWriter.pv"
            struct Type* invoke_type = type;
            #line 755 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 756 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 757 "src/compiler/ExpressionWriter.pv"
                    invoke_type = generics->self_type;
                } break;
                #line 759 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 761 "src/compiler/ExpressionWriter.pv"
            if (invoke_type == 0) {
                #line 761 "src/compiler/ExpressionWriter.pv"
                return false;
            }

            #line 763 "src/compiler/ExpressionWriter.pv"
            switch (Type__resolve_typedef(invoke_type)->type) {
                #line 764 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 765 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 767 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 768 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 770 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 771 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 773 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 774 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 776 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 776 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = Type__resolve_typedef(invoke_type)->function_value._0;
                    #line 776 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(invoke_type)->function_value._1;
                    #line 777 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 778 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 779 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 781 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 782 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 784 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 787 "src/compiler/ExpressionWriter.pv"
                    struct Token func_name = *func_info->name;
                    #line 788 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_name.value;
                    #line 789 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);
                    #line 790 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 791 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 792 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 793 "src/compiler/ExpressionWriter.pv"
                    uintptr_t arg_index = 0;
                    #line 794 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* variadic_sequence = ExpressionWriter__get_typed_variadic_sequence(self, func_info);
                    #line 795 "src/compiler/ExpressionWriter.pv"
                    uintptr_t variadic_start = arguments->length;
                    #line 796 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 797 "src/compiler/ExpressionWriter.pv"
                        variadic_start = func_info->parameters.length - 1;
                    }

                    #line 800 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 801 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 801 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 802 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 803 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 804 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 807 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 809 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 810 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 811 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->fn_");
                                #line 812 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 813 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 814 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 815 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 816 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 817 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            } else {
                                #line 819 "src/compiler/ExpressionWriter.pv"
                                struct Function* type_impl_function = Root__find_type_impl_function(generator->root, &arg->value->return_type, name, 0);
                                #line 820 "src/compiler/ExpressionWriter.pv"
                                if (type_impl_function != 0) {
                                    #line 821 "src/compiler/ExpressionWriter.pv"
                                    success = Generator__write_function_name(generator, file, type_impl_function, &resolved_generics) && success;
                                } else {
                                    #line 823 "src/compiler/ExpressionWriter.pv"
                                    struct String parent_name = Naming__get_type_name(&generator->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                    #line 824 "src/compiler/ExpressionWriter.pv"
                                    struct Type resolved_trait_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(generator->allocator, &resolved_generics)} };
                                    #line 825 "src/compiler/ExpressionWriter.pv"
                                    struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, &resolved_trait_type, func_info, generics);
                                    #line 826 "src/compiler/ExpressionWriter.pv"
                                    success = Generator__write_string(generator, file, &function_name) && success;
                                }
                                #line 828 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 829 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 830 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 831 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            }
                        } break;
                        #line 834 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 835 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(generator, file, func_info, &resolved_generics) && success;
                            #line 836 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 840 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 840 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 840 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 841 "src/compiler/ExpressionWriter.pv"
                        if (variadic_sequence != 0 && arg_index >= variadic_start) {
                            #line 842 "src/compiler/ExpressionWriter.pv"
                            break;
                        }
                        #line 844 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 844 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 844 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 845 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        #line 846 "src/compiler/ExpressionWriter.pv"
                        arg_index += 1;
                    } }

                    #line 849 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 850 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 850 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 850 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 851 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_typed_variadic_slice(self, file, variadic_sequence, arguments, variadic_start, generics) && success;
                    }

                    #line 854 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 855 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 857 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 857 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(invoke_type)->functionc_value;
                    #line 858 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 859 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(generator, file, name);
                    #line 860 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 861 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 862 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 862 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 862 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 863 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 863 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 863 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 864 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 866 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 867 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 869 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 869 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = Type__resolve_typedef(invoke_type)->sequence_value;
                    #line 870 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 871 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 872 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 873 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 874 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 875 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 875 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 875 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 876 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 876 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 876 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 877 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 879 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 881 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 882 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 883 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(generator, file, &expression->return_type, generics);
                            #line 884 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 885 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 886 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 886 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 886 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 887 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 887 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 887 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 887 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 888 "src/compiler/ExpressionWriter.pv"
                                struct Token arg_name = *arg->name;
                                #line 889 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, arg_name.value) && success;
                                #line 890 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 891 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 893 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 896 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 898 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 899 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(generator, file, type, generics);
                    #line 900 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 902 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 903 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 904 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 905 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 905 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 905 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 906 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 906 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 906 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 907 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 909 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 911 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 912 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 913 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 913 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 913 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 914 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 914 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 914 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 914 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 915 "src/compiler/ExpressionWriter.pv"
                            struct Token arg_name = *arg->name;
                            #line 916 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(generator, file, arg_name.value) && success;
                            #line 917 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 918 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 920 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 922 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 924 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 925 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 926 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 930 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 933 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 934 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 937 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 938 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 939 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 941 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 942 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 942 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 943 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 944 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 946 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 946 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 947 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 948 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 950 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 951 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 952 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 954 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 954 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 954 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 955 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 957 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 957 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 958 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 960 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 960 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 960 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 961 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__Eq_str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 962 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 963 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 964 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 967 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 968 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 969 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 970 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 970 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 971 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 971 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 972 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 972 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 973 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 976 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 979 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 980 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, &inner->return_type, generics);
                    #line 981 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 982 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 983 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 984 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 988 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, operator);
            #line 989 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 990 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 992 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 992 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 992 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 992 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 993 "src/compiler/ExpressionWriter.pv"
            bool is_eq_or_ne = str__Eq_str__eq(operator, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(operator, (struct str){ .ptr = "!=", .length = strlen("!=") });

            #line 995 "src/compiler/ExpressionWriter.pv"
            bool left_is_null = false;
            #line 996 "src/compiler/ExpressionWriter.pv"
            bool right_is_null = false;
            #line 997 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne) {
                #line 998 "src/compiler/ExpressionWriter.pv"
                switch (left->data.type) {
                    #line 999 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 999 "src/compiler/ExpressionWriter.pv"
                        left_is_null = true;
                    } break;
                    #line 1000 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 1000 "src/compiler/ExpressionWriter.pv"
                        struct str v = left->data.literal_value;
                        #line 1000 "src/compiler/ExpressionWriter.pv"
                        if (str__Eq_str__eq(v, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 1000 "src/compiler/ExpressionWriter.pv"
                            left_is_null = true;
                        }
                    } break;
                    #line 1001 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
                #line 1003 "src/compiler/ExpressionWriter.pv"
                switch (right->data.type) {
                    #line 1004 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 1004 "src/compiler/ExpressionWriter.pv"
                        right_is_null = true;
                    } break;
                    #line 1005 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 1005 "src/compiler/ExpressionWriter.pv"
                        struct str v = right->data.literal_value;
                        #line 1005 "src/compiler/ExpressionWriter.pv"
                        if (str__Eq_str__eq(v, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 1005 "src/compiler/ExpressionWriter.pv"
                            right_is_null = true;
                        }
                    } break;
                    #line 1006 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            }

            #line 1010 "src/compiler/ExpressionWriter.pv"
            bool left_fat_null_cmp = is_eq_or_ne && right_is_null && Type__is_fat_pointer(&left->return_type);
            #line 1011 "src/compiler/ExpressionWriter.pv"
            bool right_fat_null_cmp = is_eq_or_ne && left_is_null && Type__is_fat_pointer(&right->return_type);

            #line 1013 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &left->return_type, generics)) {
                #line 1014 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1015 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 1016 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else if (left_fat_null_cmp) {
                #line 1018 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1019 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 1020 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").instance");
            } else {
                #line 1022 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
            }

            #line 1025 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);

            #line 1027 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &right->return_type, generics)) {
                #line 1028 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1029 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 1030 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else if (right_fat_null_cmp) {
                #line 1032 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 1033 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 1034 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").instance");
            } else {
                #line 1036 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
            }

            #line 1039 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1041 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 1041 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 1041 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 1041 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 1042 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 1043 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 1044 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 1045 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 1046 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 1047 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1049 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 1049 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = data->optionalexpression_value._0;
            #line 1049 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = data->optionalexpression_value._1;
            #line 1050 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1051 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, receiver, generics);
            #line 1052 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " == 0 ? 0 : ");
            #line 1053 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, value, generics);
            #line 1054 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1055 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1057 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 1057 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 1057 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 1058 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 1059 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1060 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 1061 "src/compiler/ExpressionWriter.pv"
                    if (generics->self_type != 0) {
                        #line 1061 "src/compiler/ExpressionWriter.pv"
                        parent_type = generics->self_type;
                    }
                } break;
                #line 1063 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 1065 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1066 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1066 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 1067 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 1067 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1067 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1068 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 1069 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 1070 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 1071 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 1072 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 1073 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 1074 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 1078 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 1078 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 1079 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 1079 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1079 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1080 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 1081 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 1082 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 1083 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 1084 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 1085 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 1086 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 1090 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 1092 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 1093 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(generator, file, generics);
            #line 1094 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 1095 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1097 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1097 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 1097 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 1098 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 1099 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 1099 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = expression->return_type.function_value._0;
                    #line 1100 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 1101 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TYPE: {
                            #line 1101 "src/compiler/ExpressionWriter.pv"
                            struct Type* type = func_info->parent.type_value._0;
                            #line 1101 "src/compiler/ExpressionWriter.pv"
                            uintptr_t impl_index = func_info->parent.type_value._1;
                            #line 1101 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.type_value._2;
                            #line 1102 "src/compiler/ExpressionWriter.pv"
                            struct Type* named_type = type;
                            #line 1103 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_fat_pointer(type)) {
                                #line 1104 "src/compiler/ExpressionWriter.pv"
                                named_type = Type__deref_1(type);
                                #line 1105 "src/compiler/ExpressionWriter.pv"
                                if (named_type == 0) {
                                    #line 1105 "src/compiler/ExpressionWriter.pv"
                                    named_type = type;
                                }
                            }
                            #line 1107 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, named_type, type, generics);
                            #line 1108 "src/compiler/ExpressionWriter.pv"
                            if (trait_info != 0) {
                                #line 1109 "src/compiler/ExpressionWriter.pv"
                                struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type, impl_index);
                                #line 1110 "src/compiler/ExpressionWriter.pv"
                                struct Type* impl_trait_type = 0;
                                #line 1111 "src/compiler/ExpressionWriter.pv"
                                if (type_impl != 0) {
                                    #line 1111 "src/compiler/ExpressionWriter.pv"
                                    impl_trait_type = &type_impl->impl_info->trait_type;
                                }
                                #line 1112 "src/compiler/ExpressionWriter.pv"
                                struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, impl_trait_type, func_info, generics);
                                #line 1113 "src/compiler/ExpressionWriter.pv"
                                return Generator__write_string(generator, file, &function_name);
                            }
                            #line 1115 "src/compiler/ExpressionWriter.pv"
                            Generator__write_string(generator, file, &parent_name);
                            #line 1116 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "__");
                            #line 1117 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                            #line 1118 "src/compiler/ExpressionWriter.pv"
                            return true;
                        } break;
                        #line 1120 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1123 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 1126 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 1127 "src/compiler/ExpressionWriter.pv"
            struct Function* type_impl_function = Root__find_type_impl_function(generator->root, parent_type, member, 0);
            #line 1128 "src/compiler/ExpressionWriter.pv"
            if (type_impl_function != 0) {
                #line 1129 "src/compiler/ExpressionWriter.pv"
                switch (type_impl_function->parent.type) {
                    #line 1130 "src/compiler/ExpressionWriter.pv"
                    case FUNCTION_PARENT__TYPE: {
                        #line 1130 "src/compiler/ExpressionWriter.pv"
                        struct Type* type = type_impl_function->parent.type_value._0;
                        #line 1130 "src/compiler/ExpressionWriter.pv"
                        uintptr_t impl_index = type_impl_function->parent.type_value._1;
                        #line 1130 "src/compiler/ExpressionWriter.pv"
                        struct Trait* trait_info = type_impl_function->parent.type_value._2;
                        #line 1131 "src/compiler/ExpressionWriter.pv"
                        struct Type* named_type = type;
                        #line 1132 "src/compiler/ExpressionWriter.pv"
                        if (Type__is_fat_pointer(type)) {
                            #line 1133 "src/compiler/ExpressionWriter.pv"
                            named_type = Type__deref_1(type);
                            #line 1134 "src/compiler/ExpressionWriter.pv"
                            if (named_type == 0) {
                                #line 1134 "src/compiler/ExpressionWriter.pv"
                                named_type = type;
                            }
                        }
                        #line 1136 "src/compiler/ExpressionWriter.pv"
                        struct String parent_name = Naming__get_type_name(&generator->naming_ident, named_type, parent_type, generics);
                        #line 1137 "src/compiler/ExpressionWriter.pv"
                        if (trait_info != 0) {
                            #line 1138 "src/compiler/ExpressionWriter.pv"
                            struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type, impl_index);
                            #line 1139 "src/compiler/ExpressionWriter.pv"
                            struct Type* impl_trait_type = 0;
                            #line 1140 "src/compiler/ExpressionWriter.pv"
                            if (type_impl != 0) {
                                #line 1140 "src/compiler/ExpressionWriter.pv"
                                impl_trait_type = &type_impl->impl_info->trait_type;
                            }
                            #line 1141 "src/compiler/ExpressionWriter.pv"
                            struct String function_name = Generator__get_trait_function_name(generator, String__as_str(&parent_name), trait_info, impl_trait_type, type_impl_function, generics);
                            #line 1142 "src/compiler/ExpressionWriter.pv"
                            return Generator__write_string(generator, file, &function_name);
                        }
                        #line 1144 "src/compiler/ExpressionWriter.pv"
                        Generator__write_string(generator, file, &parent_name);
                        #line 1145 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                        #line 1146 "src/compiler/ExpressionWriter.pv"
                        Generator__write_str(generator, file, member);
                        #line 1147 "src/compiler/ExpressionWriter.pv"
                        return true;
                    } break;
                    #line 1149 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 1152 "src/compiler/ExpressionWriter.pv"
                struct GenericMap type_impl_generics = (struct GenericMap) { .self_type = parent_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } };
                #line 1153 "src/compiler/ExpressionWriter.pv"
                return Generator__write_function_name(generator, file, type_impl_function, &type_impl_generics);
            }

            #line 1156 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, parent_type, generics)) {
                #line 1157 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 1158 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1158 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 1159 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 1160 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1160 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 1161 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 1164 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1165 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 1165 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 1166 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 1167 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1167 "src/compiler/ExpressionWriter.pv"
                            struct Expression* length = sequence->type.fixedarray_value;
                            #line 1168 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 1169 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, length, generics);
                            } else if (str__Eq_str__eq(member, (struct str){ .ptr = "data", .length = strlen("data") })) {
                                #line 1171 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, parent, generics);
                            } else {
                                #line 1173 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 1174 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(generator, file, member);
                                #line 1175 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 1178 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1179 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, parent, generics);
                            #line 1180 "src/compiler/ExpressionWriter.pv"
                            Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                            #line 1181 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                        } break;
                    }
                } break;
                #line 1185 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1186 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 1187 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                    #line 1188 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 1188 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 1189 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(generator, file, member);
                } break;
            }

            #line 1193 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1195 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1195 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 1196 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 1197 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1199 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1199 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 1199 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 1200 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 1201 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 1202 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 1204 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 1205 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 1206 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 1207 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1209 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1209 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 1210 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1211 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 1212 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1213 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1215 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1215 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 1216 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 1217 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1217 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 1217 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 1218 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 1219 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 1220 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 1221 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 1223 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 1225 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 1227 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1227 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1228 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 1229 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 1232 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1234 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1234 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 1235 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 1236 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1236 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1237 "src/compiler/ExpressionWriter.pv"
                    struct Token struct_name = *struct_info->name;
                    #line 1238 "src/compiler/ExpressionWriter.pv"
                    if (str__Eq_str__eq(struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1239 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 1242 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 1242 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 1243 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 1244 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 1244 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 1245 "src/compiler/ExpressionWriter.pv"
                            struct Token struct_name = *struct_info->name;
                            #line 1246 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 1247 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 1249 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 1252 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 1252 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 1252 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 1253 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 1253 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 1256 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1256 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 1261 "src/compiler/ExpressionWriter.pv"
    return false;
}
