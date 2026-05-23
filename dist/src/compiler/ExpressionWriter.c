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
#include <compiler/FunctionContext.h>
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
#include <analyzer/Context.h>
#include <analyzer/Naming.h>
#include <std/Array_Type.h>
#include <analyzer/Token.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Indirect.h>
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
struct str ExpressionWriter__make_optional_temp_name(struct ExpressionWriter* self) {
    #line 19 "src/compiler/ExpressionWriter.pv"
    struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator });
    #line 20 "src/compiler/ExpressionWriter.pv"
    String__append(&name, (struct str){ .ptr = "__optional_", .length = strlen("__optional_") });
    #line 21 "src/compiler/ExpressionWriter.pv"
    String__append_usize(&name, self->generator->function_context->optional_temp_count);
    #line 22 "src/compiler/ExpressionWriter.pv"
    self->generator->function_context->optional_temp_count += 1;
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
                            struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, generator->allocator, generics);
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
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics) {
    #line 128 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;

    #line 130 "src/compiler/ExpressionWriter.pv"
    switch (expression->data.type) {
        #line 131 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 131 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = expression->data.optionalexpression_value._0;
            #line 131 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 132 "src/compiler/ExpressionWriter.pv"
            struct str receiver_temp = ExpressionWriter__make_optional_temp_name(self);

            #line 134 "src/compiler/ExpressionWriter.pv"
            Generator__write_indent(generator, file);
            #line 135 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable_decl(generator, file, receiver_temp, &receiver->return_type, generics);
            #line 136 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ";\n");

            #line 138 "src/compiler/ExpressionWriter.pv"
            switch (receiver->data.type) {
                #line 139 "src/compiler/ExpressionWriter.pv"
                case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
                    #line 140 "src/compiler/ExpressionWriter.pv"
                    if (!ExpressionWriter__write_optional_assignment(self, file, receiver_temp, &receiver->return_type, receiver, generics)) {
                        #line 140 "src/compiler/ExpressionWriter.pv"
                        return false;
                    }
                } break;
                #line 142 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 143 "src/compiler/ExpressionWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 144 "src/compiler/ExpressionWriter.pv"
                    Generator__write_variable(generator, file, receiver_temp);
                    #line 145 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " = ");
                    #line 146 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, receiver, generics);
                    #line 147 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ";\n");
                } break;
            }

            #line 151 "src/compiler/ExpressionWriter.pv"
            Generator__write_indent(generator, file);
            #line 152 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, target_name);
            #line 153 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = (");
            #line 154 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, receiver_temp);
            #line 155 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " == 0 ? 0 : ");
            #line 156 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression_replacing(self, file, value, receiver, receiver_temp, &receiver->return_type, generics);
            #line 157 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ");\n");
            #line 158 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 160 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 161 "src/compiler/ExpressionWriter.pv"
            Generator__write_indent(generator, file);
            #line 162 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, target_name);
            #line 163 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 164 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expression, generics);
            #line 165 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ";\n");
            #line 166 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
    }

    #line 170 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 173 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 174 "src/compiler/ExpressionWriter.pv"
    if (reference) {
        #line 174 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "&");
    }
    #line 175 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 176 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 177 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = strlen(");
    #line 178 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 179 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") }");
}

#line 182 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 183 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 184 "src/compiler/ExpressionWriter.pv"
    switch (Type__deref(&inner_expr->return_type)->type) {
        #line 185 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION: {
            #line 185 "src/compiler/ExpressionWriter.pv"
            struct Function* func_info = Type__deref(&inner_expr->return_type)->function_value._0;
            #line 185 "src/compiler/ExpressionWriter.pv"
            struct GenericMap* func_generics = Type__deref(&inner_expr->return_type)->function_value._1;
            #line 186 "src/compiler/ExpressionWriter.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 187 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Co_CoroutineStatus) { .vtable = &");
                #line 188 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 189 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 190 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 191 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Co_CoroutineStatus__Instance) {}");
                #line 192 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 194 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");
                #line 195 "src/compiler/ExpressionWriter.pv"
                Generator__write_dynamic_vtable_name(generator, file, func_info, func_generics);
                #line 196 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 197 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
                #line 198 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Fn__Instance) {}");
                #line 199 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            }

            #line 202 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
        #line 204 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 207 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 208 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 208 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 209 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 210 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 211 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 213 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 214 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 215 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 217 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 218 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_info->name->value);
            #line 219 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = ");
            #line 220 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 221 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " }");
        } break;
        #line 223 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 223 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 227 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 228 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 229 "src/compiler/ExpressionWriter.pv"
    struct Sequence* inner_sequence = 0;

    #line 231 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->return_type.type) {
        #line 232 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 232 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 233 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 234 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 234 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 234 "src/compiler/ExpressionWriter.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 235 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 238 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 241 "src/compiler/ExpressionWriter.pv"
    if (inner_sequence == 0) {
        #line 242 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 243 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 246 "src/compiler/ExpressionWriter.pv"
    struct Expression* length_expr = 0;
    #line 247 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 248 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 248 "src/compiler/ExpressionWriter.pv"
            struct Expression* seq_length = inner_sequence->type.fixedarray_value;
            #line 248 "src/compiler/ExpressionWriter.pv"
            length_expr = seq_length;
        } break;
        #line 249 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 250 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 251 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
    }

    #line 255 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 256 "src/compiler/ExpressionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
    #line 257 "src/compiler/ExpressionWriter.pv"
    struct Expression* unary_inner = 0;

    #line 259 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->data.type) {
        #line 260 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 260 "src/compiler/ExpressionWriter.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 260 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 261 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 262 "src/compiler/ExpressionWriter.pv"
                unary_inner = inner;
            }
        } break;
        #line 265 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 268 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 269 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 270 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 272 "src/compiler/ExpressionWriter.pv"
    if (unary_inner != 0) {
        #line 273 "src/compiler/ExpressionWriter.pv"
        bool is_array_literal = false;
        #line 274 "src/compiler/ExpressionWriter.pv"
        switch (unary_inner->data.type) {
            #line 275 "src/compiler/ExpressionWriter.pv"
            case EXPRESSION_DATA__INVOKE: {
                #line 275 "src/compiler/ExpressionWriter.pv"
                struct Expression* target = unary_inner->data.invoke_value._0;
                #line 276 "src/compiler/ExpressionWriter.pv"
                switch (target->return_type.type) {
                    #line 277 "src/compiler/ExpressionWriter.pv"
                    case TYPE__SEQUENCE: {
                        #line 277 "src/compiler/ExpressionWriter.pv"
                        struct Sequence* seq = target->return_type.sequence_value;
                        #line 278 "src/compiler/ExpressionWriter.pv"
                        switch (seq->type.type) {
                            #line 279 "src/compiler/ExpressionWriter.pv"
                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                #line 279 "src/compiler/ExpressionWriter.pv"
                                is_array_literal = true;
                            } break;
                            #line 280 "src/compiler/ExpressionWriter.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 283 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 286 "src/compiler/ExpressionWriter.pv"
            default: {
            } break;
        }

        #line 289 "src/compiler/ExpressionWriter.pv"
        if (is_array_literal) {
            #line 290 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 291 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, &sequence->element, generics);
            #line 292 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[])");
        }
        #line 294 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, unary_inner, generics);
    } else {
        #line 296 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "*");
        #line 297 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }

    #line 300 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = ");
    #line 301 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, length_expr, generics);
    #line 302 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
}

#line 305 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 306 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 307 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(generator, type, generics)) {
        #line 308 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 309 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 311 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 312 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
        } else {
            #line 314 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 317 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line);

        #line 319 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 320 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);

        #line 322 "src/compiler/ExpressionWriter.pv"
        if (fields->length == 0) {
            #line 323 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 325 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 326 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 326 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 329 "src/compiler/ExpressionWriter.pv"
        generator->indent += 1;
        #line 330 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 330 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 330 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 330 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 331 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 332 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 332 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 333 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 335 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 336 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 339 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, field->name);
            #line 340 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 341 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 342 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 342 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 345 "src/compiler/ExpressionWriter.pv"
        generator->indent -= 1;

        #line 347 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 348 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 349 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 351 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 352 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 357 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 360 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 361 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 362 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 364 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 365 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, variant);
        #line 366 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 369 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 370 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(generator, file, type, generics);
    #line 371 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 372 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(generator, file, type, variant);

    #line 374 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 375 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 376 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 379 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 380 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 381 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 382 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(generator, file, name->value);
        #line 383 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 386 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 387 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 388 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 389 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 389 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 389 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 390 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 390 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 390 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 391 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 392 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, arg.name);
            #line 393 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 394 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 396 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (arguments->length == 1) {
        #line 398 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 400 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 402 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 403 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 403 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 403 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 404 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 404 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 405 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 406 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 407 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 410 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 413 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 414 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 417 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 418 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 419 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 421 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 422 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 422 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 423 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 424 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 424 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 424 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 425 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, generator->allocator, generics);

                    #line 427 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 428 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(generator, file, func_info, &resolved_generics);
                    #line 429 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 431 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 432 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 432 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 432 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 433 "src/compiler/ExpressionWriter.pv"
                        if (i == 0) {
                            #line 433 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 434 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 436 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(generator, file, param->name);
                        #line 437 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 439 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 440 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 442 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 445 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 448 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 449 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 451 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 454 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 457 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 458 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 461 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 462 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 463 "src/compiler/ExpressionWriter.pv"
    struct str name = func_info->name->value;

    #line 465 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 466 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 467 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 468 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 468 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 469 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(generator, file, type, generics);
    }

    #line 472 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 473 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 474 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 475 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 475 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 476 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 477 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 477 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 478 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 479 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 480 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 481 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 482 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 483 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 486 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(generator, file, func_info->name);
    #line 487 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 488 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 489 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 489 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 489 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 490 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 490 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 490 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 491 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 493 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 494 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 497 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 498 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 499 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 500 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 501 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 501 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 502 "src/compiler/ExpressionWriter.pv"
            bool success = Generator__write_str(generator, file, name);
            #line 503 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 504 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 505 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 505 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 505 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 506 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 506 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 506 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 507 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 509 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 510 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 512 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 513 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 514 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 515 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 516 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 516 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 516 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 517 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 517 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 517 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 518 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 520 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 521 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 523 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 524 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 525 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 526 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 527 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 527 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 527 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 528 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 528 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 528 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 529 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 531 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 532 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 534 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 534 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 535 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 537 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 537 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 538 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 539 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 539 "src/compiler/ExpressionWriter.pv"
                    type = generics->self_type;
                } break;
                #line 540 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 543 "src/compiler/ExpressionWriter.pv"
            switch (Type__resolve_typedef(type)->type) {
                #line 544 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 545 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 547 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 548 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 550 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 551 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 553 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 554 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 556 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 556 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                    #line 556 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
                    #line 557 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 558 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 559 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 561 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 562 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 564 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 567 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name->value;
                    #line 568 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, generator->allocator, generics);
                    #line 569 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 570 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 571 "src/compiler/ExpressionWriter.pv"
                    bool first = true;

                    #line 573 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 574 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 574 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 575 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 576 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 577 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 580 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 582 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 583 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 584 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->fn_");
                                #line 585 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 586 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 587 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 588 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 589 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 591 "src/compiler/ExpressionWriter.pv"
                                struct String parent_name = Naming__get_type_name(&generator->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 592 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, String__as_str(&parent_name)) && success;
                                #line 593 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 594 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, trait_info->name->value) && success;
                                #line 595 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 596 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, func_info->name->value) && success;
                                #line 597 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 598 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 599 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            }
                        } break;
                        #line 602 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 603 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(generator, file, func_info, &resolved_generics) && success;
                            #line 604 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 608 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 608 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 608 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 609 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 609 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 609 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 610 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 613 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 614 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 616 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 616 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
                    #line 617 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 618 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(generator, file, name);
                    #line 619 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 620 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 621 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 621 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 621 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 622 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 622 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 622 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 623 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 625 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 626 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 628 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 628 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = Type__resolve_typedef(type)->sequence_value;
                    #line 629 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 630 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 631 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 632 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 633 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 634 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 634 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 634 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 635 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 635 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 635 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 636 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 638 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 640 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 641 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 642 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(generator, file, &expression->return_type, generics);
                            #line 643 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 644 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 645 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 645 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 645 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 646 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 646 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 646 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 646 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 647 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, arg->name->value) && success;
                                #line 648 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 649 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 651 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 654 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 656 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 657 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(generator, file, type, generics);
                    #line 658 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 660 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 661 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 662 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 663 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 663 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 663 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 664 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 664 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 664 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 665 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 667 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 669 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 670 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 671 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 671 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 671 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 672 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 672 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 672 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 672 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 673 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(generator, file, arg->name->value) && success;
                            #line 674 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 675 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 677 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 679 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 681 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 682 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 683 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 687 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 690 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 691 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 694 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 695 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 696 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 698 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 699 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 699 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 700 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 701 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 703 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 703 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 704 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 705 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 707 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 708 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 709 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 711 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 711 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 711 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 712 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 714 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 714 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 715 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 717 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 717 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 717 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 718 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 719 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 720 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 721 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 724 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 725 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 726 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 727 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 727 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 728 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 728 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 729 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 729 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 730 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 733 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 736 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 737 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, &inner->return_type, generics);
                    #line 738 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 739 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 740 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 741 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 745 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, operator);
            #line 746 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 747 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 749 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 749 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 749 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 749 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 750 "src/compiler/ExpressionWriter.pv"
            bool is_eq_or_ne = str__Eq_str__eq(&operator, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&operator, (struct str){ .ptr = "!=", .length = strlen("!=") });
            #line 751 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &left->return_type, generics)) {
                #line 752 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 753 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 754 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else {
                #line 756 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
            }

            #line 759 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);

            #line 761 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &right->return_type, generics)) {
                #line 762 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 763 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 764 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else {
                #line 766 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
            }

            #line 769 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 771 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 771 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 771 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 771 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 772 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 773 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 774 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 775 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 776 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 777 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 779 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 779 "src/compiler/ExpressionWriter.pv"
            struct Expression* receiver = data->optionalexpression_value._0;
            #line 779 "src/compiler/ExpressionWriter.pv"
            struct Expression* value = data->optionalexpression_value._1;
            #line 780 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 781 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, receiver, generics);
            #line 782 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " == 0 ? 0 : ");
            #line 783 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, value, generics);
            #line 784 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 785 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 787 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 787 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 787 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 788 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 789 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 790 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 790 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 791 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 791 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 791 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 792 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 793 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 794 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 795 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 796 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 797 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 798 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 802 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 802 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 803 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 803 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 803 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 804 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 805 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 806 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 807 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 808 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 809 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 810 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 814 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 816 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 817 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(generator, file, generics);
            #line 818 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 819 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 821 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 821 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 821 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 822 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;

            #line 824 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, parent_type, generics)) {
                #line 825 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 826 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 826 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 827 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 828 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 828 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 829 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 832 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 833 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 833 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 834 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 835 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 835 "src/compiler/ExpressionWriter.pv"
                            struct Expression* length = sequence->type.fixedarray_value;
                            #line 836 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 837 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, length, generics);
                            } else {
                                #line 839 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 840 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(generator, file, member);
                                #line 841 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 844 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 845 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "!!ERROR TODO MEMBERS FOR DYNAMIC SEQUENCES!!");
                        } break;
                    }
                } break;
                #line 849 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 850 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 851 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                    #line 852 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 852 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 853 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(generator, file, member);
                } break;
            }

            #line 857 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 859 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 859 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 860 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 861 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 863 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 863 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 863 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 864 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 865 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 866 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 868 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 869 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 870 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 871 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 873 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 873 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 874 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 875 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 876 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 877 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 879 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 879 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 880 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 881 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 881 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 881 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 882 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 883 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 884 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 885 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 887 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 889 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 891 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 891 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 892 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 893 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 896 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 898 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 898 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 899 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 900 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 900 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 901 "src/compiler/ExpressionWriter.pv"
                    if (str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 902 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 905 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 905 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 906 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 907 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 907 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 908 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 909 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 911 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 914 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 914 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 914 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 915 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 915 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 918 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 918 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 923 "src/compiler/ExpressionWriter.pv"
    return false;
}
