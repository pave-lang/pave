#include <string.h>
#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <compiler/ExpressionWriter.h>
#include <compiler/Generator.h>
#include <std/String.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Function.h>
#include <std/Array_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/Naming.h>
#include <analyzer/Token.h>
#include <analyzer/types/Trait.h>
#include <analyzer/Context.h>
#include <std/Array_Type.h>
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
#include <analyzer/types/FunctionParent.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/Struct.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <analyzer/Impl.h>
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
            if (Generator__is_type_single_value_struct(generator, &parent->return_type, generics)) {
                #line 64 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(&parent->return_type);
                #line 65 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 65 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 66 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, parent, replace, replacement_name, replacement_type, generics);
                #line 67 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 67 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 68 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 71 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, parent, replace, replacement_name, replacement_type, generics);
            #line 72 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = parent == replace ? replacement_type : &parent->return_type;
            #line 73 "src/compiler/ExpressionWriter.pv"
            Generator__write_instance_member_accessor(generator, file, parent_type, generics);
            #line 74 "src/compiler/ExpressionWriter.pv"
            if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                #line 74 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "_");
            }
            #line 75 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 76 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 78 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 78 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 78 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &expression->data.invoke_value._1;
            #line 79 "src/compiler/ExpressionWriter.pv"
            switch (target->data.type) {
                #line 80 "src/compiler/ExpressionWriter.pv"
                case EXPRESSION_DATA__TYPE: {
                    #line 80 "src/compiler/ExpressionWriter.pv"
                    struct Type* type = target->data.type_value;
                    #line 81 "src/compiler/ExpressionWriter.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 82 "src/compiler/ExpressionWriter.pv"
                        case TYPE__FUNCTION: {
                            #line 82 "src/compiler/ExpressionWriter.pv"
                            struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                            #line 82 "src/compiler/ExpressionWriter.pv"
                            struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
                            #line 83 "src/compiler/ExpressionWriter.pv"
                            struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);
                            #line 84 "src/compiler/ExpressionWriter.pv"
                            bool success = Generator__write_function_name(generator, file, func_info, &resolved_generics);
                            #line 85 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 86 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 87 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 87 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 87 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 88 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 88 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 88 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 89 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression_replacing(self, file, arg->value, replace, replacement_name, replacement_type, generics) && success;
                            } }
                            #line 91 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ")");
                            #line 92 "src/compiler/ExpressionWriter.pv"
                            return success;
                        } break;
                        #line 94 "src/compiler/ExpressionWriter.pv"
                        case TYPE__FUNCTION_C: {
                            #line 94 "src/compiler/ExpressionWriter.pv"
                            struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
                            #line 95 "src/compiler/ExpressionWriter.pv"
                            bool success = Generator__write_str(generator, file, func_info->name);
                            #line 96 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 97 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 98 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 98 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 98 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 99 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 99 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 99 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 100 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression_replacing(self, file, arg->value, replace, replacement_name, replacement_type, generics) && success;
                            } }
                            #line 102 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ")");
                            #line 103 "src/compiler/ExpressionWriter.pv"
                            return success;
                        } break;
                        #line 105 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 108 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 111 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 113 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 113 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 114 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 115 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, inner, replace, replacement_name, replacement_type, generics);
            #line 116 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 117 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 119 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 120 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_expression(self, file, expression, generics);
        } break;
    }

    #line 124 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 127 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_safe_to_duplicate(struct ExpressionWriter* self, struct Expression* expression) {
    #line 128 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 129 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 129 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 130 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 130 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 131 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 131 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 132 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 132 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 132 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__is_safe_to_duplicate(self, inner);
        } break;
        #line 133 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 133 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 135 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 138 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__optional_needs_lowering(struct ExpressionWriter* self, struct Expression* expression) {
    #line 139 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 140 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 140 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 141 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 141 "src/compiler/ExpressionWriter.pv"
                return true;
            }
            #line 142 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__optional_needs_lowering(self, receiver);
        } break;
        #line 144 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 144 "src/compiler/ExpressionWriter.pv"
            return false;
        } break;
    }
    #line 146 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 149 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__lower_optional_to_temp(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics, uintptr_t* count) {
    #line 150 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 152 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 153 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 153 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 153 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 154 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 155 "src/compiler/ExpressionWriter.pv"
                struct str inner_temp = ExpressionWriter__lower_optional_to_temp(self, file, receiver, generics, count);
                #line 156 "src/compiler/ExpressionWriter.pv"
                struct str temp = ExpressionWriter__make_optional_temp_name(self, count);
                #line 157 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 158 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable_decl(generator, file, temp, &expression->return_type, generics);
                #line 159 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = (");
                #line 160 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, inner_temp);
                #line 161 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " == 0 ? 0 : ");
                #line 162 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, inner_temp, &receiver->return_type, generics);
                #line 163 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ");\n");
                #line 164 "src/compiler/ExpressionWriter.pv"
                return temp;
            }
        } break;
        #line 167 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 170 "src/compiler/ExpressionWriter.pv"
    struct str temp = ExpressionWriter__make_optional_temp_name(self, count);
    #line 171 "src/compiler/ExpressionWriter.pv"
    Generator__write_indent(generator, file);
    #line 172 "src/compiler/ExpressionWriter.pv"
    Generator__write_variable_decl(generator, file, temp, &expression->return_type, generics);
    #line 173 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " = ");
    #line 174 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, expression, generics);
    #line 175 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ";\n");
    #line 176 "src/compiler/ExpressionWriter.pv"
    return temp;
}

#line 179 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics) {
    #line 180 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 181 "src/compiler/ExpressionWriter.pv"
    uintptr_t count = 0;

    #line 183 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 184 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 184 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 184 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 185 "src/compiler/ExpressionWriter.pv"
            if (!ExpressionWriter__is_safe_to_duplicate(self, receiver)) {
                #line 186 "src/compiler/ExpressionWriter.pv"
                struct str temp = ExpressionWriter__lower_optional_to_temp(self, file, receiver, generics, &count);
                #line 187 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 188 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, target_name);
                #line 189 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " = (");
                #line 190 "src/compiler/ExpressionWriter.pv"
                Generator__write_variable(generator, file, temp);
                #line 191 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " == 0 ? 0 : ");
                #line 192 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression_replacing(self, file, value, receiver, temp, &receiver->return_type, generics);
                #line 193 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ");\n");
                #line 194 "src/compiler/ExpressionWriter.pv"
                return true;
            }
        } break;
        #line 197 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 200 "src/compiler/ExpressionWriter.pv"
    Generator__write_indent(generator, file);
    #line 201 "src/compiler/ExpressionWriter.pv"
    Generator__write_variable(generator, file, target_name);
    #line 202 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " = ");
    #line 203 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, expression, generics);
    #line 204 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ";\n");
    #line 205 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 208 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 209 "src/compiler/ExpressionWriter.pv"
    if (reference) {
        #line 209 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "&");
    }
    #line 210 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 211 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 212 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = strlen(");
    #line 213 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 214 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") }");
}

#line 217 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 218 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 219 "src/compiler/ExpressionWriter.pv"
    switch (Type__deref(&inner_expr->return_type)->type) {
        #line 220 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION: {
            #line 220 "src/compiler/ExpressionWriter.pv"
            struct Function* func_info = Type__deref(&inner_expr->return_type)->function_value._0;
            #line 220 "src/compiler/ExpressionWriter.pv"
            struct GenericMap* func_generics = Type__deref(&inner_expr->return_type)->function_value._1;
            #line 221 "src/compiler/ExpressionWriter.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 222 "src/compiler/ExpressionWriter.pv"
                struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
                #line 223 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Co_");
                #line 224 "src/compiler/ExpressionWriter.pv"
                Generator__write_string(generator, file, &co_ret_name);
                #line 225 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ") { .vtable = &");
                #line 226 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 227 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 228 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 229 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Co_");
                #line 230 "src/compiler/ExpressionWriter.pv"
                Generator__write_string(generator, file, &co_ret_name);
                #line 231 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Instance) {}");
                #line 232 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 234 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");
                #line 235 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 236 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 237 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 238 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Fn__Instance) {}");
                #line 239 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            }

            #line 242 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
        #line 244 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 247 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 248 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 248 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 249 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 250 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 251 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 252 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 254 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 255 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 256 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 258 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 259 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 260 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = ");
            #line 261 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 262 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " }");
        } break;
        #line 264 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 264 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 268 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_trait_value_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 269 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 271 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 272 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 272 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 273 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 274 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 275 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 276 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 278 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, &inner_expr->return_type, generics, 0);
            #line 279 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 280 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 282 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 283 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 284 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = (");
            #line 285 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &inner_expr->return_type, generics);
            #line 286 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[]) {");
            #line 287 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 288 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "} }");
            #line 289 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 291 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 294 "src/compiler/ExpressionWriter.pv"
    return ExpressionWriter__write_expression(self, file, inner_expr, generics);
}

#line 297 "src/compiler/ExpressionWriter.pv"
struct Type* ExpressionWriter__should_use_trait_value_cast(struct ExpressionWriter* self, struct Type* element_type, struct Expression* arg) {
    #line 298 "src/compiler/ExpressionWriter.pv"
    if (Type__is_indirect(&arg->return_type)) {
        #line 299 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 302 "src/compiler/ExpressionWriter.pv"
    switch (element_type->type) {
        #line 303 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 303 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = element_type->indirect_value;
            #line 304 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 305 "src/compiler/ExpressionWriter.pv"
                case TYPE__TRAIT: {
                    #line 306 "src/compiler/ExpressionWriter.pv"
                    return &indirect->to;
                } break;
                #line 308 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 311 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 314 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 317 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 318 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 319 "src/compiler/ExpressionWriter.pv"
    struct Sequence* inner_sequence = 0;

    #line 321 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->return_type.type) {
        #line 322 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 322 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 323 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 324 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 324 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 324 "src/compiler/ExpressionWriter.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 325 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 328 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 331 "src/compiler/ExpressionWriter.pv"
    if (inner_sequence == 0) {
        #line 332 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 333 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 336 "src/compiler/ExpressionWriter.pv"
    struct Expression* length_expr = 0;
    #line 337 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 338 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 338 "src/compiler/ExpressionWriter.pv"
            struct Expression* seq_length = inner_sequence->type.fixedarray_value;
            #line 338 "src/compiler/ExpressionWriter.pv"
            length_expr = seq_length;
        } break;
        #line 339 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 340 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 341 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
    }

    #line 345 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 346 "src/compiler/ExpressionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 347 "src/compiler/ExpressionWriter.pv"
    struct Expression* unary_inner = 0;

    #line 349 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->data.type) {
        #line 350 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 350 "src/compiler/ExpressionWriter.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 350 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 351 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 352 "src/compiler/ExpressionWriter.pv"
                unary_inner = inner;
            }
        } break;
        #line 355 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 358 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 359 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 360 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 362 "src/compiler/ExpressionWriter.pv"
    if (unary_inner != 0) {
        #line 363 "src/compiler/ExpressionWriter.pv"
        bool is_array_literal = false;
        #line 364 "src/compiler/ExpressionWriter.pv"
        switch (unary_inner->data.type) {
            #line 365 "src/compiler/ExpressionWriter.pv"
            case EXPRESSION_DATA__INVOKE: {
                #line 365 "src/compiler/ExpressionWriter.pv"
                struct Expression* target = unary_inner->data.invoke_value._0;
                #line 366 "src/compiler/ExpressionWriter.pv"
                switch (target->return_type.type) {
                    #line 367 "src/compiler/ExpressionWriter.pv"
                    case TYPE__SEQUENCE: {
                        #line 367 "src/compiler/ExpressionWriter.pv"
                        struct Sequence* seq = target->return_type.sequence_value;
                        #line 368 "src/compiler/ExpressionWriter.pv"
                        switch (seq->type.type) {
                            #line 369 "src/compiler/ExpressionWriter.pv"
                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                #line 369 "src/compiler/ExpressionWriter.pv"
                                is_array_literal = true;
                            } break;
                            #line 370 "src/compiler/ExpressionWriter.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 373 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 376 "src/compiler/ExpressionWriter.pv"
            default: {
            } break;
        }

        #line 379 "src/compiler/ExpressionWriter.pv"
        if (is_array_literal) {
            #line 380 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 381 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &sequence->element, generics);
            #line 382 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[])");
        }
        #line 384 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, unary_inner, generics);
    } else {
        #line 386 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "*");
        #line 387 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }

    #line 390 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = ");
    #line 391 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, length_expr, generics);
    #line 392 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
}

#line 395 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 396 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 397 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(generator, type, generics)) {
        #line 398 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 399 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 401 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 402 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, (*field).value, generics);
        } else {
            #line 404 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 407 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line);

        #line 409 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 410 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);

        #line 412 "src/compiler/ExpressionWriter.pv"
        if (fields->length == 0) {
            #line 413 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 415 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 416 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 416 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 419 "src/compiler/ExpressionWriter.pv"
        generator->indent += 1;
        #line 420 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 420 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 420 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 420 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 421 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 422 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 422 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 423 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 425 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 426 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 429 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, field->name);
            #line 430 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 431 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 432 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 432 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 435 "src/compiler/ExpressionWriter.pv"
        generator->indent -= 1;

        #line 437 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 438 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 439 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 441 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 442 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 447 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 450 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 451 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 452 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 454 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 455 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, variant);
        #line 456 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 459 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 460 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(generator, file, type, generics);
    #line 461 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 462 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(generator, file, type, variant);

    #line 464 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 465 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 466 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 469 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 470 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 471 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 472 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(generator, file, name->value);
        #line 473 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 476 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 477 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 478 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 479 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 479 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 479 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 480 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 480 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 480 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 481 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 482 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, arg.name);
            #line 483 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 484 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 486 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (arguments->length == 1) {
        #line 488 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 490 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 492 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 493 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 493 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 493 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 494 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 494 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 495 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 496 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 497 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 500 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 503 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 504 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 507 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 508 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 509 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 511 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 512 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 512 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 513 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 514 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 514 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 514 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 515 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);

                    #line 517 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 518 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(generator, file, func_info, &resolved_generics);
                    #line 519 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 521 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 522 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 522 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 522 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 523 "src/compiler/ExpressionWriter.pv"
                        if (i == 0) {
                            #line 523 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 524 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 526 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(generator, file, param->name);
                        #line 527 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 529 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 530 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 532 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 535 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 538 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 539 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 541 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 544 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 547 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 548 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 551 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 552 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 553 "src/compiler/ExpressionWriter.pv"
    struct Token func_name = *func_info->name;
    #line 554 "src/compiler/ExpressionWriter.pv"
    struct str name = func_name.value;

    #line 556 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 557 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 558 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 559 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 559 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 560 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(generator, file, type, generics);
    }

    #line 563 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "typename", .length = strlen("typename") })) {
        #line 564 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 565 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 566 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 566 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 567 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typename(generator, file, type, generics);
    }

    #line 570 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 571 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 572 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 573 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 573 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 574 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 575 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 575 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 576 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 577 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 578 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 579 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 580 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 581 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 584 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(generator, file, func_info->name);
    #line 585 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 586 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 587 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 587 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 587 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 588 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 588 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 588 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 589 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 591 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 592 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 595 "src/compiler/ExpressionWriter.pv"
struct Sequence* ExpressionWriter__get_typed_variadic_sequence(struct ExpressionWriter* self, struct Function* func_info) {
    #line 596 "src/compiler/ExpressionWriter.pv"
    if (!func_info->typed_variadic || func_info->parameters.length == 0) {
        #line 596 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 598 "src/compiler/ExpressionWriter.pv"
    struct Parameter* param = Array_Parameter__get(&func_info->parameters, func_info->parameters.length - 1);
    #line 599 "src/compiler/ExpressionWriter.pv"
    if (param == 0) {
        #line 599 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 601 "src/compiler/ExpressionWriter.pv"
    switch (param->type.type) {
        #line 602 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 602 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = param->type.indirect_value;
            #line 603 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 604 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 604 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 605 "src/compiler/ExpressionWriter.pv"
                    return sequence;
                } break;
                #line 607 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 610 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 613 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 616 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_typed_variadic_slice(struct ExpressionWriter* self, FILE* file, struct Sequence* sequence, struct Array_InvokeArgument* arguments, uintptr_t start, struct GenericMap* generics) {
    #line 617 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 618 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 619 "src/compiler/ExpressionWriter.pv"
    struct String sequence_name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 620 "src/compiler/ExpressionWriter.pv"
    bool success = true;
    #line 621 "src/compiler/ExpressionWriter.pv"
    uintptr_t length = arguments->length - start;

    #line 623 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 624 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &sequence_name);
    #line 625 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 627 "src/compiler/ExpressionWriter.pv"
    if (length == 0) {
        #line 628 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "0");
    } else {
        #line 630 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 631 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, &sequence->element, generics);
        #line 632 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "[]) {");

        #line 634 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = start;
        #line 635 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 636 "src/compiler/ExpressionWriter.pv"
        while (i < arguments->length) {
            #line 637 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 637 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 637 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 638 "src/compiler/ExpressionWriter.pv"
            struct Expression* arg = arguments->data[i].value;
            #line 639 "src/compiler/ExpressionWriter.pv"
            struct Type* trait_type = ExpressionWriter__should_use_trait_value_cast(self, &sequence->element, arg);
            #line 640 "src/compiler/ExpressionWriter.pv"
            if (trait_type != 0) {
                #line 641 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_trait_value_cast(self, file, arg, trait_type, generics) && success;
            } else {
                #line 643 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg, generics) && success;
            }
            #line 645 "src/compiler/ExpressionWriter.pv"
            i += 1;
        }

        #line 648 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 651 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = %zu }", length);
    #line 652 "src/compiler/ExpressionWriter.pv"
    String__release(&sequence_name);
    #line 653 "src/compiler/ExpressionWriter.pv"
    return success;
}

#line 656 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 657 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 658 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 659 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 660 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 660 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 661 "src/compiler/ExpressionWriter.pv"
            bool success = Generator__write_str(generator, file, name);
            #line 662 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 663 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 664 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 664 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 664 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 665 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 665 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 665 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 666 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 668 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 669 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 671 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 672 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 673 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 674 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 675 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 675 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 675 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 676 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 676 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 676 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 677 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 679 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 680 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 682 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 683 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 684 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 685 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 686 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 686 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 686 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 687 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 687 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 687 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 688 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 690 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 691 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 693 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 693 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 694 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 696 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 696 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 697 "src/compiler/ExpressionWriter.pv"
            struct Type* invoke_type = type;
            #line 698 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 699 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 700 "src/compiler/ExpressionWriter.pv"
                    invoke_type = generics->self_type;
                } break;
                #line 702 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 704 "src/compiler/ExpressionWriter.pv"
            if (invoke_type == 0) {
                #line 704 "src/compiler/ExpressionWriter.pv"
                return false;
            }

            #line 706 "src/compiler/ExpressionWriter.pv"
            switch (Type__resolve_typedef(invoke_type)->type) {
                #line 707 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 708 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 710 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 711 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 713 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 714 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 716 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 717 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 719 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 719 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = Type__resolve_typedef(invoke_type)->function_value._0;
                    #line 719 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(invoke_type)->function_value._1;
                    #line 720 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 721 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 722 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 724 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 725 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 727 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 730 "src/compiler/ExpressionWriter.pv"
                    struct Token func_name = *func_info->name;
                    #line 731 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_name.value;
                    #line 732 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);
                    #line 733 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 734 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 735 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 736 "src/compiler/ExpressionWriter.pv"
                    uintptr_t arg_index = 0;
                    #line 737 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* variadic_sequence = ExpressionWriter__get_typed_variadic_sequence(self, func_info);
                    #line 738 "src/compiler/ExpressionWriter.pv"
                    uintptr_t variadic_start = arguments->length;
                    #line 739 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 740 "src/compiler/ExpressionWriter.pv"
                        variadic_start = func_info->parameters.length - 1;
                    }

                    #line 743 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 744 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 744 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 745 "src/compiler/ExpressionWriter.pv"
                            struct Token trait_name = *trait_info->name;
                            #line 746 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 747 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 748 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 751 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 753 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 754 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 755 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->fn_");
                                #line 756 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 757 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 758 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 759 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 760 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 761 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            } else {
                                #line 763 "src/compiler/ExpressionWriter.pv"
                                struct String parent_name = Naming__get_type_name(&generator->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 764 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, String__as_str(&parent_name)) && success;
                                #line 765 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 766 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, trait_name.value) && success;
                                #line 767 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 768 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 769 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 770 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 771 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 772 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            }
                        } break;
                        #line 775 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 776 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(generator, file, func_info, &resolved_generics) && success;
                            #line 777 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 781 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 781 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 781 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 782 "src/compiler/ExpressionWriter.pv"
                        if (variadic_sequence != 0 && arg_index >= variadic_start) {
                            #line 783 "src/compiler/ExpressionWriter.pv"
                            break;
                        }
                        #line 785 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 785 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 785 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 786 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        #line 787 "src/compiler/ExpressionWriter.pv"
                        arg_index += 1;
                    } }

                    #line 790 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 791 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 791 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 791 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 792 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_typed_variadic_slice(self, file, variadic_sequence, arguments, variadic_start, generics) && success;
                    }

                    #line 795 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 796 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 798 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 798 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(invoke_type)->functionc_value;
                    #line 799 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 800 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(generator, file, name);
                    #line 801 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 802 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 803 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 803 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 803 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 804 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 804 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 804 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 805 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 807 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 808 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 810 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 810 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = Type__resolve_typedef(invoke_type)->sequence_value;
                    #line 811 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 812 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 813 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 814 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 815 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 816 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 816 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 816 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 817 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 817 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 817 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 818 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 820 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 822 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 823 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 824 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(generator, file, &expression->return_type, generics);
                            #line 825 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 826 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 827 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 827 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 827 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 828 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 828 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 828 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 828 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 829 "src/compiler/ExpressionWriter.pv"
                                struct Token arg_name = *arg->name;
                                #line 830 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, arg_name.value) && success;
                                #line 831 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 832 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 834 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 837 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 839 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 840 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(generator, file, type, generics);
                    #line 841 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 843 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 844 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 845 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 846 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 846 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 846 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 847 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 847 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 847 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 848 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 850 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 852 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 853 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 854 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 854 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 854 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 855 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 855 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 855 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 855 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 856 "src/compiler/ExpressionWriter.pv"
                            struct Token arg_name = *arg->name;
                            #line 857 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(generator, file, arg_name.value) && success;
                            #line 858 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 859 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 861 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 863 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 865 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 866 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 867 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 871 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 874 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 875 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 878 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 879 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 880 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 882 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 883 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 883 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 884 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 885 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 887 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 887 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 888 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 889 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 891 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 892 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 893 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 895 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 895 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 895 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 896 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 898 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 898 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 899 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 901 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 901 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 901 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 902 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 903 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 904 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 905 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 908 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 909 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 910 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 911 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 911 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 912 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 912 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 913 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 913 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 914 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 917 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 920 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 921 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, &inner->return_type, generics);
                    #line 922 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 923 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 924 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 925 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 929 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, operator);
            #line 930 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 931 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 933 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 933 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 933 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 933 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 934 "src/compiler/ExpressionWriter.pv"
            bool is_eq_or_ne = str__Eq_str__eq(&operator, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&operator, (struct str){ .ptr = "!=", .length = strlen("!=") });

            #line 936 "src/compiler/ExpressionWriter.pv"
            bool left_is_null = false;
            #line 937 "src/compiler/ExpressionWriter.pv"
            bool right_is_null = false;
            #line 938 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne) {
                #line 939 "src/compiler/ExpressionWriter.pv"
                switch (left->data.type) {
                    #line 940 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 940 "src/compiler/ExpressionWriter.pv"
                        left_is_null = true;
                    } break;
                    #line 941 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 941 "src/compiler/ExpressionWriter.pv"
                        struct str v = left->data.literal_value;
                        #line 941 "src/compiler/ExpressionWriter.pv"
                        if (str__Eq_str__eq(&v, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 941 "src/compiler/ExpressionWriter.pv"
                            left_is_null = true;
                        }
                    } break;
                    #line 942 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
                #line 944 "src/compiler/ExpressionWriter.pv"
                switch (right->data.type) {
                    #line 945 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 945 "src/compiler/ExpressionWriter.pv"
                        right_is_null = true;
                    } break;
                    #line 946 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 946 "src/compiler/ExpressionWriter.pv"
                        struct str v = right->data.literal_value;
                        #line 946 "src/compiler/ExpressionWriter.pv"
                        if (str__Eq_str__eq(&v, (struct str){ .ptr = "0", .length = strlen("0") })) {
                            #line 946 "src/compiler/ExpressionWriter.pv"
                            right_is_null = true;
                        }
                    } break;
                    #line 947 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            }

            #line 951 "src/compiler/ExpressionWriter.pv"
            bool left_fat_null_cmp = is_eq_or_ne && right_is_null && Type__is_fat_pointer(&left->return_type);
            #line 952 "src/compiler/ExpressionWriter.pv"
            bool right_fat_null_cmp = is_eq_or_ne && left_is_null && Type__is_fat_pointer(&right->return_type);

            #line 954 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &left->return_type, generics)) {
                #line 955 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 956 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 957 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else if (left_fat_null_cmp) {
                #line 959 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 960 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 961 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").instance");
            } else {
                #line 963 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
            }

            #line 966 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);

            #line 968 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &right->return_type, generics)) {
                #line 969 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 970 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 971 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else if (right_fat_null_cmp) {
                #line 973 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 974 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 975 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").instance");
            } else {
                #line 977 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
            }

            #line 980 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 982 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 982 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 982 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 982 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 983 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 984 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 985 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 986 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 987 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 988 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 990 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 990 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = data->optionalexpression_value._0;
            #line 990 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = data->optionalexpression_value._1;
            #line 991 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 992 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, receiver, generics);
            #line 993 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " == 0 ? 0 : ");
            #line 994 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, value, generics);
            #line 995 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 996 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 998 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 998 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 998 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 999 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 1000 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1001 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1001 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 1002 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 1002 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1002 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1003 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 1004 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 1005 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 1006 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 1007 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 1008 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 1009 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 1013 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 1013 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 1014 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 1014 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 1014 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 1015 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 1016 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 1017 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 1018 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 1019 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 1020 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 1021 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 1025 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 1027 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 1028 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(generator, file, generics);
            #line 1029 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 1030 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1032 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1032 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 1032 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 1033 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;

            #line 1035 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, parent_type, generics)) {
                #line 1036 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 1037 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1037 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 1038 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 1039 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1039 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 1040 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 1043 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1044 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 1044 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 1045 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 1046 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1046 "src/compiler/ExpressionWriter.pv"
                            struct Expression* length = sequence->type.fixedarray_value;
                            #line 1047 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 1048 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, length, generics);
                            } else if (str__Eq_str__eq(&member, (struct str){ .ptr = "data", .length = strlen("data") })) {
                                #line 1050 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, parent, generics);
                            } else {
                                #line 1052 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 1053 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(generator, file, member);
                                #line 1054 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 1057 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1058 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, parent, generics);
                            #line 1059 "src/compiler/ExpressionWriter.pv"
                            Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                            #line 1060 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                        } break;
                    }
                } break;
                #line 1064 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1065 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 1066 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                    #line 1067 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 1067 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 1068 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(generator, file, member);
                } break;
            }

            #line 1072 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1074 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1074 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 1075 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 1076 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1078 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1078 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 1078 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 1079 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 1080 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 1081 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 1083 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 1084 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 1085 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 1086 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1088 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1088 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 1089 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1090 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 1091 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1092 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1094 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1094 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 1095 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 1096 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1096 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 1096 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 1097 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 1098 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 1099 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 1100 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 1102 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 1104 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 1106 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1106 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1107 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 1108 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 1111 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1113 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1113 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 1114 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 1115 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1115 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1116 "src/compiler/ExpressionWriter.pv"
                    struct Token struct_name = *struct_info->name;
                    #line 1117 "src/compiler/ExpressionWriter.pv"
                    if (str__Eq_str__eq(&struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1118 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 1121 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 1121 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 1122 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 1123 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 1123 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 1124 "src/compiler/ExpressionWriter.pv"
                            struct Token struct_name = *struct_info->name;
                            #line 1125 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 1126 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 1128 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 1131 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 1131 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 1131 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 1132 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 1132 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 1135 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1135 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 1140 "src/compiler/ExpressionWriter.pv"
    return false;
}
