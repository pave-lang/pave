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
#include <analyzer/Token.h>
#include <analyzer/types/Trait.h>
#include <analyzer/Context.h>
#include <analyzer/Naming.h>
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
                fprintf(file, "(struct trait_Co_CoroutineStatus) { .vtable = &");
                #line 223 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 224 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 225 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 226 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Co_CoroutineStatus__Instance) {}");
                #line 227 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 229 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");
                #line 230 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 231 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 232 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 233 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Fn__Instance) {}");
                #line 234 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            }

            #line 237 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
        #line 239 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 242 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 243 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 243 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 244 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 245 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 246 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 247 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 249 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 250 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 251 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 253 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 254 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 255 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = ");
            #line 256 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 257 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " }");
        } break;
        #line 259 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 259 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 263 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_trait_value_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 264 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 266 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 267 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 267 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 268 "src/compiler/ExpressionWriter.pv"
            struct Token trait_name = *trait_info->name;
            #line 269 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 270 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 271 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 273 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, &inner_expr->return_type, generics, 0);
            #line 274 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 275 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 277 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 278 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_name.value);
            #line 279 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = (");
            #line 280 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &inner_expr->return_type, generics);
            #line 281 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[]) {");
            #line 282 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 283 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "} }");
            #line 284 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 286 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 289 "src/compiler/ExpressionWriter.pv"
    return ExpressionWriter__write_expression(self, file, inner_expr, generics);
}

#line 292 "src/compiler/ExpressionWriter.pv"
struct Type* ExpressionWriter__should_use_trait_value_cast(struct ExpressionWriter* self, struct Type* element_type, struct Expression* arg) {
    #line 293 "src/compiler/ExpressionWriter.pv"
    if (Type__is_indirect(&arg->return_type)) {
        #line 294 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 297 "src/compiler/ExpressionWriter.pv"
    switch (element_type->type) {
        #line 298 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 298 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = element_type->indirect_value;
            #line 299 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 300 "src/compiler/ExpressionWriter.pv"
                case TYPE__TRAIT: {
                    #line 301 "src/compiler/ExpressionWriter.pv"
                    return &indirect->to;
                } break;
                #line 303 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 306 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 309 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 312 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 313 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 314 "src/compiler/ExpressionWriter.pv"
    struct Sequence* inner_sequence = 0;

    #line 316 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->return_type.type) {
        #line 317 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 317 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 318 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 319 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 319 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 319 "src/compiler/ExpressionWriter.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 320 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 323 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 326 "src/compiler/ExpressionWriter.pv"
    if (inner_sequence == 0) {
        #line 327 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 328 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 331 "src/compiler/ExpressionWriter.pv"
    struct Expression* length_expr = 0;
    #line 332 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 333 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 333 "src/compiler/ExpressionWriter.pv"
            struct Expression* seq_length = inner_sequence->type.fixedarray_value;
            #line 333 "src/compiler/ExpressionWriter.pv"
            length_expr = seq_length;
        } break;
        #line 334 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 335 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 336 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
    }

    #line 340 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 341 "src/compiler/ExpressionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 342 "src/compiler/ExpressionWriter.pv"
    struct Expression* unary_inner = 0;

    #line 344 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->data.type) {
        #line 345 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 345 "src/compiler/ExpressionWriter.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 345 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 346 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 347 "src/compiler/ExpressionWriter.pv"
                unary_inner = inner;
            }
        } break;
        #line 350 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 353 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 354 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 355 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 357 "src/compiler/ExpressionWriter.pv"
    if (unary_inner != 0) {
        #line 358 "src/compiler/ExpressionWriter.pv"
        bool is_array_literal = false;
        #line 359 "src/compiler/ExpressionWriter.pv"
        switch (unary_inner->data.type) {
            #line 360 "src/compiler/ExpressionWriter.pv"
            case EXPRESSION_DATA__INVOKE: {
                #line 360 "src/compiler/ExpressionWriter.pv"
                struct Expression* target = unary_inner->data.invoke_value._0;
                #line 361 "src/compiler/ExpressionWriter.pv"
                switch (target->return_type.type) {
                    #line 362 "src/compiler/ExpressionWriter.pv"
                    case TYPE__SEQUENCE: {
                        #line 362 "src/compiler/ExpressionWriter.pv"
                        struct Sequence* seq = target->return_type.sequence_value;
                        #line 363 "src/compiler/ExpressionWriter.pv"
                        switch (seq->type.type) {
                            #line 364 "src/compiler/ExpressionWriter.pv"
                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                #line 364 "src/compiler/ExpressionWriter.pv"
                                is_array_literal = true;
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
            } break;
            #line 371 "src/compiler/ExpressionWriter.pv"
            default: {
            } break;
        }

        #line 374 "src/compiler/ExpressionWriter.pv"
        if (is_array_literal) {
            #line 375 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 376 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &sequence->element, generics);
            #line 377 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[])");
        }
        #line 379 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, unary_inner, generics);
    } else {
        #line 381 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "*");
        #line 382 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }

    #line 385 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = ");
    #line 386 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, length_expr, generics);
    #line 387 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
}

#line 390 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 391 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 392 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(generator, type, generics)) {
        #line 393 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 394 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 396 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 397 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, (*field).value, generics);
        } else {
            #line 399 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 402 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line);

        #line 404 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 405 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);

        #line 407 "src/compiler/ExpressionWriter.pv"
        if (fields->length == 0) {
            #line 408 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 410 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 411 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 411 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 414 "src/compiler/ExpressionWriter.pv"
        generator->indent += 1;
        #line 415 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 415 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 415 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 415 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 416 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 417 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 417 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 418 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 420 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 421 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 424 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, field->name);
            #line 425 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 426 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 427 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 427 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 430 "src/compiler/ExpressionWriter.pv"
        generator->indent -= 1;

        #line 432 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 433 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 434 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 436 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 437 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 442 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 445 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 446 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 447 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 449 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 450 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, variant);
        #line 451 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 454 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 455 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(generator, file, type, generics);
    #line 456 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 457 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(generator, file, type, variant);

    #line 459 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 460 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 461 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 464 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 465 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 466 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 467 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(generator, file, name->value);
        #line 468 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 471 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 472 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 473 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 474 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 474 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 474 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 475 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 475 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 475 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 476 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 477 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, arg.name);
            #line 478 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 479 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 481 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (arguments->length == 1) {
        #line 483 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 485 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 487 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 488 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 488 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 488 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 489 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 489 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 490 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 491 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 492 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 495 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 498 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 499 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 502 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 503 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 504 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 506 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 507 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 507 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 508 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 509 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 509 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 509 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 510 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);

                    #line 512 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 513 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(generator, file, func_info, &resolved_generics);
                    #line 514 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 516 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 517 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 517 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 517 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 518 "src/compiler/ExpressionWriter.pv"
                        if (i == 0) {
                            #line 518 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 519 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 521 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(generator, file, param->name);
                        #line 522 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 524 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 525 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 527 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 530 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 533 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 534 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 536 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 539 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 542 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 543 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 546 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 547 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 548 "src/compiler/ExpressionWriter.pv"
    struct Token func_name = *func_info->name;
    #line 549 "src/compiler/ExpressionWriter.pv"
    struct str name = func_name.value;

    #line 551 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 552 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 553 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 554 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 554 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 555 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(generator, file, type, generics);
    }

    #line 558 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "typename", .length = strlen("typename") })) {
        #line 559 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 560 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 561 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 561 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 562 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typename(generator, file, type, generics);
    }

    #line 565 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 566 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 567 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 568 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 568 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 569 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 570 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 570 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 571 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 572 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 573 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 574 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 575 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 576 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 579 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(generator, file, func_info->name);
    #line 580 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 581 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 582 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 582 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 582 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 583 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 583 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 583 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 584 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 586 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 587 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 590 "src/compiler/ExpressionWriter.pv"
struct Sequence* ExpressionWriter__get_typed_variadic_sequence(struct ExpressionWriter* self, struct Function* func_info) {
    #line 591 "src/compiler/ExpressionWriter.pv"
    if (!func_info->typed_variadic || func_info->parameters.length == 0) {
        #line 591 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 593 "src/compiler/ExpressionWriter.pv"
    struct Parameter* param = Array_Parameter__get(&func_info->parameters, func_info->parameters.length - 1);
    #line 594 "src/compiler/ExpressionWriter.pv"
    if (param == 0) {
        #line 594 "src/compiler/ExpressionWriter.pv"
        return 0;
    }

    #line 596 "src/compiler/ExpressionWriter.pv"
    switch (param->type.type) {
        #line 597 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 597 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = param->type.indirect_value;
            #line 598 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 599 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 599 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 600 "src/compiler/ExpressionWriter.pv"
                    return sequence;
                } break;
                #line 602 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 605 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 608 "src/compiler/ExpressionWriter.pv"
    return 0;
}

#line 611 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_typed_variadic_slice(struct ExpressionWriter* self, FILE* file, struct Sequence* sequence, struct Array_InvokeArgument* arguments, uintptr_t start, struct GenericMap* generics) {
    #line 612 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 613 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 614 "src/compiler/ExpressionWriter.pv"
    struct String sequence_name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 615 "src/compiler/ExpressionWriter.pv"
    bool success = true;
    #line 616 "src/compiler/ExpressionWriter.pv"
    uintptr_t length = arguments->length - start;

    #line 618 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 619 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &sequence_name);
    #line 620 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 622 "src/compiler/ExpressionWriter.pv"
    if (length == 0) {
        #line 623 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "0");
    } else {
        #line 625 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 626 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, &sequence->element, generics);
        #line 627 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "[]) {");

        #line 629 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = start;
        #line 630 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 631 "src/compiler/ExpressionWriter.pv"
        while (i < arguments->length) {
            #line 632 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 632 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 632 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 633 "src/compiler/ExpressionWriter.pv"
            struct Expression* arg = arguments->data[i].value;
            #line 634 "src/compiler/ExpressionWriter.pv"
            struct Type* trait_type = ExpressionWriter__should_use_trait_value_cast(self, &sequence->element, arg);
            #line 635 "src/compiler/ExpressionWriter.pv"
            if (trait_type != 0) {
                #line 636 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_trait_value_cast(self, file, arg, trait_type, generics) && success;
            } else {
                #line 638 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg, generics) && success;
            }
            #line 640 "src/compiler/ExpressionWriter.pv"
            i += 1;
        }

        #line 643 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 646 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = %zu }", length);
    #line 647 "src/compiler/ExpressionWriter.pv"
    String__release(&sequence_name);
    #line 648 "src/compiler/ExpressionWriter.pv"
    return success;
}

#line 651 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 652 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 653 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 654 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 655 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 655 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 656 "src/compiler/ExpressionWriter.pv"
            bool success = Generator__write_str(generator, file, name);
            #line 657 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 658 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 659 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 659 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 659 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 660 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 660 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 660 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 661 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 663 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 664 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 666 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 667 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 668 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 669 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 670 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 670 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 670 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 671 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 671 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 671 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 672 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 674 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 675 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 677 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 678 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 679 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 680 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 681 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 681 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 681 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 682 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 682 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 682 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 683 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 685 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 686 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 688 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 688 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 689 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 691 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 691 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 692 "src/compiler/ExpressionWriter.pv"
            struct Type* invoke_type = type;
            #line 693 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 694 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 695 "src/compiler/ExpressionWriter.pv"
                    invoke_type = generics->self_type;
                } break;
                #line 697 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 699 "src/compiler/ExpressionWriter.pv"
            if (invoke_type == 0) {
                #line 699 "src/compiler/ExpressionWriter.pv"
                return false;
            }

            #line 701 "src/compiler/ExpressionWriter.pv"
            switch (Type__resolve_typedef(invoke_type)->type) {
                #line 702 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 703 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 705 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 706 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 708 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 709 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 711 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 712 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, invoke_type, arguments, generics);
                } break;
                #line 714 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 714 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = Type__resolve_typedef(invoke_type)->function_value._0;
                    #line 714 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(invoke_type)->function_value._1;
                    #line 715 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 716 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 717 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 719 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 720 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 722 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 725 "src/compiler/ExpressionWriter.pv"
                    struct Token func_name = *func_info->name;
                    #line 726 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_name.value;
                    #line 727 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(&(*generic_map), generator->allocator, generics);
                    #line 728 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 729 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 730 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 731 "src/compiler/ExpressionWriter.pv"
                    uintptr_t arg_index = 0;
                    #line 732 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* variadic_sequence = ExpressionWriter__get_typed_variadic_sequence(self, func_info);
                    #line 733 "src/compiler/ExpressionWriter.pv"
                    uintptr_t variadic_start = arguments->length;
                    #line 734 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 735 "src/compiler/ExpressionWriter.pv"
                        variadic_start = func_info->parameters.length - 1;
                    }

                    #line 738 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 739 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 739 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 740 "src/compiler/ExpressionWriter.pv"
                            struct Token trait_name = *trait_info->name;
                            #line 741 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 742 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 743 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 746 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 748 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 749 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 750 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->fn_");
                                #line 751 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 752 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 753 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 754 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 755 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 756 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            } else {
                                #line 758 "src/compiler/ExpressionWriter.pv"
                                struct String parent_name = Naming__get_type_name(&generator->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 759 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, String__as_str(&parent_name)) && success;
                                #line 760 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 761 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, trait_name.value) && success;
                                #line 762 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 763 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 764 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 765 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 766 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 767 "src/compiler/ExpressionWriter.pv"
                                arg_index = 1;
                            }
                        } break;
                        #line 770 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 771 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(generator, file, func_info, &resolved_generics) && success;
                            #line 772 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 776 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 776 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 776 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 777 "src/compiler/ExpressionWriter.pv"
                        if (variadic_sequence != 0 && arg_index >= variadic_start) {
                            #line 778 "src/compiler/ExpressionWriter.pv"
                            break;
                        }
                        #line 780 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 780 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 780 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 781 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        #line 782 "src/compiler/ExpressionWriter.pv"
                        arg_index += 1;
                    } }

                    #line 785 "src/compiler/ExpressionWriter.pv"
                    if (variadic_sequence != 0) {
                        #line 786 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 786 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 786 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 787 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_typed_variadic_slice(self, file, variadic_sequence, arguments, variadic_start, generics) && success;
                    }

                    #line 790 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 791 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 793 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 793 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(invoke_type)->functionc_value;
                    #line 794 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 795 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(generator, file, name);
                    #line 796 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 797 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 798 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 798 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 798 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 799 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 799 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 799 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 800 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 802 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 803 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 805 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 805 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = Type__resolve_typedef(invoke_type)->sequence_value;
                    #line 806 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 807 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 808 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 809 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 810 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 811 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 811 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 811 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 812 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 812 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 812 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 813 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 815 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 817 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 818 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 819 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(generator, file, &expression->return_type, generics);
                            #line 820 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 821 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 822 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 822 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 822 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 823 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 823 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 823 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 823 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 824 "src/compiler/ExpressionWriter.pv"
                                struct Token arg_name = *arg->name;
                                #line 825 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, arg_name.value) && success;
                                #line 826 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 827 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 829 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 832 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 834 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 835 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(generator, file, type, generics);
                    #line 836 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 838 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 839 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 840 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 841 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 841 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 841 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 842 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 842 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 842 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 843 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 845 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 847 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 848 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 849 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 849 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 849 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 850 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 850 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 850 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 850 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 851 "src/compiler/ExpressionWriter.pv"
                            struct Token arg_name = *arg->name;
                            #line 852 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(generator, file, arg_name.value) && success;
                            #line 853 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 854 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 856 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 858 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 860 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 861 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 862 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 866 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 869 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 870 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 873 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 874 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 875 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 877 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 878 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 878 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 879 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 880 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 882 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 882 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 883 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 884 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 886 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 887 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 888 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 890 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 890 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 890 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 891 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 893 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 893 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 894 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 896 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 896 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 896 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 897 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 898 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 899 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 900 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 903 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 904 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 905 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 906 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 906 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 907 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 907 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 908 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 908 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 909 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 912 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 915 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 916 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, &inner->return_type, generics);
                    #line 917 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 918 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 919 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 920 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 924 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, operator);
            #line 925 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 926 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 928 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 928 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 928 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 928 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 929 "src/compiler/ExpressionWriter.pv"
            bool is_eq_or_ne = str__Eq_str__eq(&operator, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&operator, (struct str){ .ptr = "!=", .length = strlen("!=") });
            #line 930 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &left->return_type, generics)) {
                #line 931 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 932 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 933 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else {
                #line 935 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
            }

            #line 938 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);

            #line 940 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &right->return_type, generics)) {
                #line 941 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 942 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 943 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else {
                #line 945 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
            }

            #line 948 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 950 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 950 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 950 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 950 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 951 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 952 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 953 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 954 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 955 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 956 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 958 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 958 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = data->optionalexpression_value._0;
            #line 958 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = data->optionalexpression_value._1;
            #line 959 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 960 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, receiver, generics);
            #line 961 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " == 0 ? 0 : ");
            #line 962 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, value, generics);
            #line 963 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 964 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 966 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 966 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 966 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 967 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 968 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 969 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 969 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 970 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 970 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 970 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 971 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 972 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 973 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 974 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 975 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 976 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 977 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 981 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 981 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 982 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 982 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 982 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 983 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 984 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 985 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 986 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 987 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 988 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 989 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 993 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 995 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 996 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(generator, file, generics);
            #line 997 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 998 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1000 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1000 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 1000 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 1001 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;

            #line 1003 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, parent_type, generics)) {
                #line 1004 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 1005 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1005 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 1006 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 1007 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 1007 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 1008 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 1011 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 1012 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 1012 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 1013 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 1014 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1014 "src/compiler/ExpressionWriter.pv"
                            struct Expression* length = sequence->type.fixedarray_value;
                            #line 1015 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 1016 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, length, generics);
                            } else if (str__Eq_str__eq(&member, (struct str){ .ptr = "data", .length = strlen("data") })) {
                                #line 1018 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, parent, generics);
                            } else {
                                #line 1020 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 1021 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(generator, file, member);
                                #line 1022 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 1025 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1026 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, parent, generics);
                            #line 1027 "src/compiler/ExpressionWriter.pv"
                            Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                            #line 1028 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str(generator, file, member);
                        } break;
                    }
                } break;
                #line 1032 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1033 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 1034 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                    #line 1035 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 1035 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 1036 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(generator, file, member);
                } break;
            }

            #line 1040 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1042 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1042 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 1043 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 1044 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1046 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1046 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 1046 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 1047 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 1048 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 1049 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 1051 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 1052 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 1053 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 1054 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1056 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1056 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 1057 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 1058 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 1059 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 1060 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1062 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1062 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 1063 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 1064 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1064 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 1064 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 1065 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 1066 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 1067 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 1068 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 1070 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 1072 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 1074 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1074 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1075 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 1076 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 1079 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 1081 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1081 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 1082 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 1083 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 1083 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1084 "src/compiler/ExpressionWriter.pv"
                    struct Token struct_name = *struct_info->name;
                    #line 1085 "src/compiler/ExpressionWriter.pv"
                    if (str__Eq_str__eq(&struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1086 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 1089 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 1089 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 1090 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 1091 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 1091 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 1092 "src/compiler/ExpressionWriter.pv"
                            struct Token struct_name = *struct_info->name;
                            #line 1093 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&struct_name.value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 1094 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 1096 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 1099 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 1099 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 1099 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 1100 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 1100 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 1103 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 1103 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 1108 "src/compiler/ExpressionWriter.pv"
    return false;
}
