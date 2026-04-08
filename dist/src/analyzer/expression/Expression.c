#include <stdlib.h>

#include <analyzer/Naming.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/Type.h>
#include <analyzer/Context.h>
#include <stdbool.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/EnumVariant.h>
#include <std/str.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/types/Enum.h>
#include <stdint.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/Impl.h>
#include <std/ArrayIter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/Function.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/types/Struct.h>
#include <analyzer/Root.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Trait.h>
#include <std/Allocator.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/StructCField.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/c/StructC.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/c/ClassCpp.h>
#include <std/ArrayIter_ref_Type.h>
#include <std/Array_Type.h>
#include <std/ArrayIter_ref_ref_Trait.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/types/Generics.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/Array_Parameter.h>
#include <std/ArrayIter_ref_InvokeArgument.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/FunctionType.h>
#include <std/String.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/expression/CppExpression.h>
#include <analyzer/Module.h>
#include <std/Array_Generic.h>
#include <analyzer/types/SequenceType.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>

#include <analyzer/expression/Expression.h>

#line 14 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type) {
    #line 15 "src/analyzer/expression/Expression.pv"
    return ArenaAllocator__store_Expression(allocator, (struct Expression) {
        .token = token,
        .data = data,
        .return_type = *return_type,
    });
}

#line 22 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node) {
    #line 23 "src/analyzer/expression/Expression.pv"
    struct Expression* result = ArenaAllocator__store_Expression(context->allocator, node);

    #line 25 "src/analyzer/expression/Expression.pv"
    Context__next_token(context);

    #line 27 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 30 "src/analyzer/expression/Expression.pv"
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token) {
    #line 31 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 32 "src/analyzer/expression/Expression.pv"
        case TYPE__INDIRECT: {
            #line 32 "src/analyzer/expression/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 33 "src/analyzer/expression/Expression.pv"
            return Expression__get_enum_variant(context, &indirect->to, token);
        } break;
        #line 35 "src/analyzer/expression/Expression.pv"
        case TYPE__SELF: {
            #line 36 "src/analyzer/expression/Expression.pv"
            return Expression__get_enum_variant(context, context->type_self, token);
        } break;
        #line 38 "src/analyzer/expression/Expression.pv"
        case TYPE__ENUM: {
            #line 38 "src/analyzer/expression/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 39 "src/analyzer/expression/Expression.pv"
            struct EnumVariant* variant = HashMap_str_EnumVariant__find(&enum_info->variants, &token->value);
            #line 40 "src/analyzer/expression/Expression.pv"
            if (variant == 0) {
                #line 41 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, "Variant not found in enum");
                #line 42 "src/analyzer/expression/Expression.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
            }

            #line 45 "src/analyzer/expression/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_VARIANT, .enumvariant_value = variant };
        } break;
        #line 47 "src/analyzer/expression/Expression.pv"
        case TYPE__ENUM_C: {
            #line 47 "src/analyzer/expression/Expression.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 48 "src/analyzer/expression/Expression.pv"
            struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &token->value);
            #line 49 "src/analyzer/expression/Expression.pv"
            if (variant == 0) {
                #line 51 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, "Variant not found in enum");
            }

            #line 55 "src/analyzer/expression/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_CVALUE, .enumcvalue_value = variant };
        } break;
        #line 57 "src/analyzer/expression/Expression.pv"
        default: {
            #line 57 "src/analyzer/expression/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
    }

    #line 60 "src/analyzer/expression/Expression.pv"
    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
}

#line 63 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error) {
    #line 64 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 65 "src/analyzer/expression/Expression.pv"
        case TYPE__INDIRECT: {
            #line 65 "src/analyzer/expression/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 66 "src/analyzer/expression/Expression.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 68 "src/analyzer/expression/Expression.pv"
        case TYPE__SELF: {
            #line 69 "src/analyzer/expression/Expression.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 71 "src/analyzer/expression/Expression.pv"
        case TYPE__PRIMITIVE: {
            #line 71 "src/analyzer/expression/Expression.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 72 "src/analyzer/expression/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 72 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 72 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 73 "src/analyzer/expression/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 74 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 75 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap) { .self_type = type })} });
                }
            } }

            #line 79 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 79 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 80 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 82 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT: {
            #line 82 "src/analyzer/expression/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 82 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 83 "src/analyzer/expression/Expression.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 84 "src/analyzer/expression/Expression.pv"
            if (field != 0) {
                #line 85 "src/analyzer/expression/Expression.pv"
                return &field->type;
            }

            #line 88 "src/analyzer/expression/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 88 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 88 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 89 "src/analyzer/expression/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 90 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 91 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 95 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 96 "src/analyzer/expression/Expression.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 98 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 100 "src/analyzer/expression/Expression.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 100 "src/analyzer/expression/Expression.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 100 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 101 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 102 "src/analyzer/expression/Expression.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, context->root->func_next);
                #line 103 "src/analyzer/expression/Expression.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 104 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} });
            }

            #line 107 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 108 "src/analyzer/expression/Expression.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, context->root->func_value);
                #line 109 "src/analyzer/expression/Expression.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 110 "src/analyzer/expression/Expression.pv"
                func_value->return_type = func_info->return_type;
                #line 111 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} });
            }

            #line 114 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 114 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 115 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 117 "src/analyzer/expression/Expression.pv"
        case TYPE__ENUM: {
            #line 117 "src/analyzer/expression/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 117 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 118 "src/analyzer/expression/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 118 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 118 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 119 "src/analyzer/expression/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 120 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 121 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 125 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 125 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 126 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 128 "src/analyzer/expression/Expression.pv"
        case TYPE__TRAIT: {
            #line 128 "src/analyzer/expression/Expression.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 128 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 129 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 130 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) });
            }

            #line 133 "src/analyzer/expression/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 134 "src/analyzer/expression/Expression.pv"
            if (function == 0) {
                #line 135 "src/analyzer/expression/Expression.pv"
                if (output_error) {
                    #line 135 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 136 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 139 "src/analyzer/expression/Expression.pv"
            return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
        } break;
        #line 141 "src/analyzer/expression/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 141 "src/analyzer/expression/Expression.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 142 "src/analyzer/expression/Expression.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 144 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 144 "src/analyzer/expression/Expression.pv"
            struct StructC* struct_info = type->structc_value;
            #line 145 "src/analyzer/expression/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 146 "src/analyzer/expression/Expression.pv"
            if (field != 0) {
                #line 146 "src/analyzer/expression/Expression.pv"
                return &field->type;
            }

            #line 148 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 148 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 149 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 151 "src/analyzer/expression/Expression.pv"
        case TYPE__UNION_C: {
            #line 151 "src/analyzer/expression/Expression.pv"
            struct StructC* union_info = type->unionc_value;
            #line 152 "src/analyzer/expression/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 153 "src/analyzer/expression/Expression.pv"
            if (field != 0) {
                #line 153 "src/analyzer/expression/Expression.pv"
                return &field->type;
            }

            #line 155 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 155 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 156 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 158 "src/analyzer/expression/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 158 "src/analyzer/expression/Expression.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 159 "src/analyzer/expression/Expression.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 160 "src/analyzer/expression/Expression.pv"
            if (field_type != 0) {
                #line 160 "src/analyzer/expression/Expression.pv"
                return field_type;
            }

            #line 162 "src/analyzer/expression/Expression.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 163 "src/analyzer/expression/Expression.pv"
            if (value_type != 0) {
                #line 163 "src/analyzer/expression/Expression.pv"
                return value_type;
            }

            #line 165 "src/analyzer/expression/Expression.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 165 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 165 "src/analyzer/expression/Expression.pv"
                struct Type* base = ArrayIter_ref_Type__value(&__iter);

                #line 166 "src/analyzer/expression/Expression.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 167 "src/analyzer/expression/Expression.pv"
                if (base_type != 0) {
                    #line 167 "src/analyzer/expression/Expression.pv"
                    return base_type;
                }
            } }

            #line 170 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 170 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 171 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 173 "src/analyzer/expression/Expression.pv"
        case TYPE__GENERIC: {
            #line 173 "src/analyzer/expression/Expression.pv"
            struct Generic* generic = type->generic_value;
            #line 174 "src/analyzer/expression/Expression.pv"
            { struct ArrayIter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
            #line 174 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_ref_Trait__next(&__iter)) {
                #line 174 "src/analyzer/expression/Expression.pv"
                struct Trait* trait_info = *ArrayIter_ref_ref_Trait__value(&__iter);

                #line 175 "src/analyzer/expression/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 176 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 177 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap) {})} });
                }
            } }

            #line 181 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 181 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 182 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 184 "src/analyzer/expression/Expression.pv"
        case TYPE__SEQUENCE: {
            #line 184 "src/analyzer/expression/Expression.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 185 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 186 "src/analyzer/expression/Expression.pv"
                return &sequence->element_pointer;
            }

            #line 189 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 190 "src/analyzer/expression/Expression.pv"
                return &context->root->type_usize;
            }

            #line 193 "src/analyzer/expression/Expression.pv"
            struct Impl* impl_info = context->root->hack_type_impl->impl_info;

            #line 195 "src/analyzer/expression/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
            #line 196 "src/analyzer/expression/Expression.pv"
            if (function != 0) {
                #line 197 "src/analyzer/expression/Expression.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, &(struct Generics) {}, &(struct Array_Type) {});
                #line 198 "src/analyzer/expression/Expression.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 199 "src/analyzer/expression/Expression.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) });

                #line 201 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, generic_map)} });
            }

            #line 204 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 204 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 205 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 207 "src/analyzer/expression/Expression.pv"
        case TYPE__TUPLE: {
            #line 207 "src/analyzer/expression/Expression.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 208 "src/analyzer/expression/Expression.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 209 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 210 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 213 "src/analyzer/expression/Expression.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 214 "src/analyzer/expression/Expression.pv"
            if (index >= tuple->elements.length) {
                #line 215 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 216 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 219 "src/analyzer/expression/Expression.pv"
            return &tuple->elements.data[index];
        } break;
        #line 221 "src/analyzer/expression/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 221 "src/analyzer/expression/Expression.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 222 "src/analyzer/expression/Expression.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 223 "src/analyzer/expression/Expression.pv"
            if (type != 0) {
                #line 223 "src/analyzer/expression/Expression.pv"
                return type;
            }

            #line 225 "src/analyzer/expression/Expression.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 226 "src/analyzer/expression/Expression.pv"
            if (value != 0) {
                #line 226 "src/analyzer/expression/Expression.pv"
                return value;
            }

            #line 228 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 228 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 230 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 232 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 232 "src/analyzer/expression/Expression.pv"
            return type;
        } break;
        #line 233 "src/analyzer/expression/Expression.pv"
        default: {
            #line 233 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 236 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 239 "src/analyzer/expression/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments) {
    #line 240 "src/analyzer/expression/Expression.pv"
    struct GenericMap generic_map = GenericMap__from_generics(context->allocator, &func_info->generics);

    #line 242 "src/analyzer/expression/Expression.pv"
    uintptr_t i = 0;
    #line 243 "src/analyzer/expression/Expression.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(generics);
    #line 243 "src/analyzer/expression/Expression.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 243 "src/analyzer/expression/Expression.pv"
        struct Type* generic = ArrayIter_ref_Type__value(&__iter);

        #line 244 "src/analyzer/expression/Expression.pv"
        struct Type* target = Array_Type__get(&generic_map.array, i);
        #line 245 "src/analyzer/expression/Expression.pv"
        if (target != 0) {
            #line 245 "src/analyzer/expression/Expression.pv"
            *target = *generic;
        }
        #line 246 "src/analyzer/expression/Expression.pv"
        i += 1;
    } }

    #line 249 "src/analyzer/expression/Expression.pv"
    if (i == generic_map.array.length) {
        #line 250 "src/analyzer/expression/Expression.pv"
        return ArenaAllocator__store_GenericMap(context->allocator, generic_map);
    }

    #line 253 "src/analyzer/expression/Expression.pv"
    struct ArrayIter_ref_Parameter params = Array_Parameter__iter(&func_info->parameters);
    #line 254 "src/analyzer/expression/Expression.pv"
    struct ArrayIter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);

    #line 256 "src/analyzer/expression/Expression.pv"
    while (ArrayIter_ref_Parameter__next(&params) && ArrayIter_ref_InvokeArgument__next(&args)) {
        #line 257 "src/analyzer/expression/Expression.pv"
        struct Type* param_type = &ArrayIter_ref_Parameter__value(&params)->type;
        #line 258 "src/analyzer/expression/Expression.pv"
        struct Type* arg_type = &ArrayIter_ref_InvokeArgument__value(&args)->value->return_type;

        #line 260 "src/analyzer/expression/Expression.pv"
        Expression__resolve_generic_type(context, param_type, arg_type, &generic_map);
    }

    #line 263 "src/analyzer/expression/Expression.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, generic_map);
}

#line 266 "src/analyzer/expression/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 267 "src/analyzer/expression/Expression.pv"
    switch (param_type->type) {
        #line 268 "src/analyzer/expression/Expression.pv"
        case TYPE__GENERIC: {
            #line 268 "src/analyzer/expression/Expression.pv"
            struct Generic* generic = param_type->generic_value;
            #line 269 "src/analyzer/expression/Expression.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 270 "src/analyzer/expression/Expression.pv"
            if (generic_type != 0) {
                #line 270 "src/analyzer/expression/Expression.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 272 "src/analyzer/expression/Expression.pv"
        case TYPE__INDIRECT: {
            #line 272 "src/analyzer/expression/Expression.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 273 "src/analyzer/expression/Expression.pv"
            switch (arg_type->type) {
                #line 274 "src/analyzer/expression/Expression.pv"
                case TYPE__INDIRECT: {
                    #line 274 "src/analyzer/expression/Expression.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 275 "src/analyzer/expression/Expression.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 277 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 280 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }
}

#line 284 "src/analyzer/expression/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call) {
    #line 285 "src/analyzer/expression/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 287 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 288 "src/analyzer/expression/Expression.pv"
        case TYPE__SELF: {
            #line 288 "src/analyzer/expression/Expression.pv"
            {
                #line 288 "src/analyzer/expression/Expression.pv"
                type = context->type_self;
            }
        } break;
        #line 289 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 292 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 293 "src/analyzer/expression/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 293 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 294 "src/analyzer/expression/Expression.pv"
        case TYPE__UNION_C: {
            #line 294 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 295 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 295 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 296 "src/analyzer/expression/Expression.pv"
        case TYPE__TUPLE: {
            #line 296 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 297 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT: {
            #line 297 "src/analyzer/expression/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 297 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 298 "src/analyzer/expression/Expression.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 298 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 298 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 299 "src/analyzer/expression/Expression.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg->name->value);

                #line 301 "src/analyzer/expression/Expression.pv"
                if (param == 0) {
                    #line 302 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, arg->name, "Unable to find field in struct");
                    #line 303 "src/analyzer/expression/Expression.pv"
                    return false;
                }

                #line 306 "src/analyzer/expression/Expression.pv"
                struct Type* param_type = &param->type;

                #line 308 "src/analyzer/expression/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 309 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 311 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 314 "src/analyzer/expression/Expression.pv"
                if (param_type == 0) {
                    #line 315 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve field type");
                    #line 316 "src/analyzer/expression/Expression.pv"
                    return false;
                }

                #line 319 "src/analyzer/expression/Expression.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            } }

            #line 322 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 324 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 324 "src/analyzer/expression/Expression.pv"
            struct Function* function = type->function_value._0;
            #line 324 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 325 "src/analyzer/expression/Expression.pv"
            if (function == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 325 "src/analyzer/expression/Expression.pv"
                return true;
            }

            #line 327 "src/analyzer/expression/Expression.pv"
            if (function->parameters.length != arguments_length) {
                #line 328 "src/analyzer/expression/Expression.pv"
                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 329 "src/analyzer/expression/Expression.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 331 "src/analyzer/expression/Expression.pv"
                if (is_member_call) {
                    #line 332 "src/analyzer/expression/Expression.pv"
                    String__append_usize(&message, function->parameters.length - 1);
                } else {
                    #line 334 "src/analyzer/expression/Expression.pv"
                    String__append_usize(&message, function->parameters.length);
                }

                #line 337 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 338 "src/analyzer/expression/Expression.pv"
                return false;
            }

            #line 341 "src/analyzer/expression/Expression.pv"
            struct ArrayIter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 342 "src/analyzer/expression/Expression.pv"
            struct ArrayIter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

            #line 344 "src/analyzer/expression/Expression.pv"
            if (is_member_call) {
                #line 345 "src/analyzer/expression/Expression.pv"
                ArrayIter_ref_Parameter__next(&param_iter);
                #line 346 "src/analyzer/expression/Expression.pv"
                ArrayIter_ref_InvokeArgument__next(&args_iter);

                #line 348 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
                #line 349 "src/analyzer/expression/Expression.pv"
                struct Type* param_type = &ArrayIter_ref_Parameter__value(&param_iter)->type;

                #line 351 "src/analyzer/expression/Expression.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 352 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) });
                    #line 353 "src/analyzer/expression/Expression.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 357 "src/analyzer/expression/Expression.pv"
            while (ArrayIter_ref_Parameter__next(&param_iter) && ArrayIter_ref_InvokeArgument__next(&args_iter)) {
                #line 358 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
                #line 359 "src/analyzer/expression/Expression.pv"
                struct Parameter* param = ArrayIter_ref_Parameter__value(&param_iter);
                #line 360 "src/analyzer/expression/Expression.pv"
                struct Type* param_type = &param->type;

                #line 362 "src/analyzer/expression/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 363 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 365 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 368 "src/analyzer/expression/Expression.pv"
                if (param_type == 0) {
                    #line 369 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
                    #line 370 "src/analyzer/expression/Expression.pv"
                    return false;
                }

                #line 373 "src/analyzer/expression/Expression.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            }

            #line 376 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 378 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 378 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 379 "src/analyzer/expression/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 379 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 380 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 380 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 381 "src/analyzer/expression/Expression.pv"
        default: {
            #line 381 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 384 "src/analyzer/expression/Expression.pv"
    return false;
}

#line 387 "src/analyzer/expression/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 388 "src/analyzer/expression/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 390 "src/analyzer/expression/Expression.pv"
    if (variant->types.length != arguments_length) {
        #line 391 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 392 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 393 "src/analyzer/expression/Expression.pv"
        String__append_usize(&message, variant->types.length);
        #line 394 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 395 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 398 "src/analyzer/expression/Expression.pv"
    struct ArrayIter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 399 "src/analyzer/expression/Expression.pv"
    struct ArrayIter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 401 "src/analyzer/expression/Expression.pv"
    while (ArrayIter_ref_Type__next(&param_iter) && ArrayIter_ref_InvokeArgument__next(&args_iter)) {
        #line 402 "src/analyzer/expression/Expression.pv"
        struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
        #line 403 "src/analyzer/expression/Expression.pv"
        struct Type* param_type = ArrayIter_ref_Type__value(&param_iter);

        #line 405 "src/analyzer/expression/Expression.pv"
        if (generic_map != 0) {
            #line 406 "src/analyzer/expression/Expression.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 409 "src/analyzer/expression/Expression.pv"
        if (param_type == 0) {
            #line 410 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
            #line 411 "src/analyzer/expression/Expression.pv"
            return false;
        }

        #line 414 "src/analyzer/expression/Expression.pv"
        Expression__validate_type(arg->value, context, param_type, true);
    }

    #line 417 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 420 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 421 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 422 "src/analyzer/expression/Expression.pv"
        case TYPE__TUPLE: {
            #line 422 "src/analyzer/expression/Expression.pv"
            return type;
        } break;
        #line 423 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 423 "src/analyzer/expression/Expression.pv"
            struct Function* func_info = type->function_value._0;
            #line 423 "src/analyzer/expression/Expression.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 424 "src/analyzer/expression/Expression.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 426 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 426 "src/analyzer/expression/Expression.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 426 "src/analyzer/expression/Expression.pv"
            return &func_info->return_type;
        } break;
        #line 427 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 427 "src/analyzer/expression/Expression.pv"
            return type;
        } break;
        #line 428 "src/analyzer/expression/Expression.pv"
        default: {
            #line 428 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 431 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 434 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 435 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 435 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 437 "src/analyzer/expression/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 438 "src/analyzer/expression/Expression.pv"
    if (func_return_type == 0) {
        #line 438 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 440 "src/analyzer/expression/Expression.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 441 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 444 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 445 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 445 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 447 "src/analyzer/expression/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 448 "src/analyzer/expression/Expression.pv"
    if (func_return_type == 0) {
        #line 448 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 450 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, func_return_type);
}

#line 453 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics) {
    #line 454 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 455 "src/analyzer/expression/Expression.pv"
        struct Token* variant_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 456 "src/analyzer/expression/Expression.pv"
        if (variant_name == 0) {
            #line 456 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 458 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, variant_name);

        #line 460 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 461 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__NONE: {
                #line 462 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, variant_name, "Unable to find enum variant");
                #line 463 "src/analyzer/expression/Expression.pv"
                return false;
            } break;
            #line 465 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 465 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* variant = variant_result.enumvariant_value;
                #line 466 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 468 "src/analyzer/expression/Expression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 469 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                        #line 469 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 471 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 472 "src/analyzer/expression/Expression.pv"
                        struct Expression* argument = Expression__parse(context, generics);
                        #line 473 "src/analyzer/expression/Expression.pv"
                        if (argument == 0) {
                            #line 473 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 475 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                        #line 477 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 478 "src/analyzer/expression/Expression.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                            #line 479 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 483 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 483 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 487 "src/analyzer/expression/Expression.pv"
                struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

                #line 489 "src/analyzer/expression/Expression.pv"
                struct GenericMap* generic_map = Type__get_generic_map(enum_type, context);
                #line 490 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_enum_arguments(context, token, variant, &arguments, generic_map)) {
                    #line 490 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 492 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
            } break;
            #line 494 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                #line 495 "src/analyzer/expression/Expression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 496 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, enum_type);
            } break;
        }
    }

    #line 511 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 514 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 515 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 516 "src/analyzer/expression/Expression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 517 "src/analyzer/expression/Expression.pv"
        if (member == 0) {
            #line 517 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 519 "src/analyzer/expression/Expression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 520 "src/analyzer/expression/Expression.pv"
        if (member_type == 0) {
            #line 520 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 522 "src/analyzer/expression/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 524 "src/analyzer/expression/Expression.pv"
        if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 525 "src/analyzer/expression/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
        } else {
            #line 527 "src/analyzer/expression/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 527 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 529 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 531 "src/analyzer/expression/Expression.pv"
            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 532 "src/analyzer/expression/Expression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 533 "src/analyzer/expression/Expression.pv"
                if (argument == 0) {
                    #line 533 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 535 "src/analyzer/expression/Expression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                #line 537 "src/analyzer/expression/Expression.pv"
                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 538 "src/analyzer/expression/Expression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 539 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            }

            #line 543 "src/analyzer/expression/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 543 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 545 "src/analyzer/expression/Expression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 545 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 547 "src/analyzer/expression/Expression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 548 "src/analyzer/expression/Expression.pv"
            if (func_return_type == 0) {
                #line 548 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 550 "src/analyzer/expression/Expression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 551 "src/analyzer/expression/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 554 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 556 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 557 "src/analyzer/expression/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 558 "src/analyzer/expression/Expression.pv"
            if (name == 0) {
                #line 558 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 560 "src/analyzer/expression/Expression.pv"
            struct Expression* value = 0;
            #line 561 "src/analyzer/expression/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 562 "src/analyzer/expression/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 564 "src/analyzer/expression/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 565 "src/analyzer/expression/Expression.pv"
                if (return_type == 0) {
                    #line 566 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 567 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 570 "src/analyzer/expression/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 573 "src/analyzer/expression/Expression.pv"
            if (value == 0) {
                #line 573 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 575 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 577 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 578 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 579 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 583 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 583 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 585 "src/analyzer/expression/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 586 "src/analyzer/expression/Expression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 586 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 588 "src/analyzer/expression/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 589 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 591 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 593 "src/analyzer/expression/Expression.pv"
        uintptr_t field_index = 0;
        #line 594 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 595 "src/analyzer/expression/Expression.pv"
            struct String name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 596 "src/analyzer/expression/Expression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 597 "src/analyzer/expression/Expression.pv"
            String__append_usize(&name, field_index);
            #line 598 "src/analyzer/expression/Expression.pv"
            struct str name_str = String__as_str(&name);

            #line 600 "src/analyzer/expression/Expression.pv"
            struct Token name_token = *Context__current(context);
            #line 601 "src/analyzer/expression/Expression.pv"
            name_token.value = name_str;

            #line 603 "src/analyzer/expression/Expression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 604 "src/analyzer/expression/Expression.pv"
            if (value == 0) {
                #line 604 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 606 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, name_token),
                .value = value,
            });

            #line 611 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 612 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 613 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 616 "src/analyzer/expression/Expression.pv"
            field_index += 1;
        }

        #line 619 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 619 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 621 "src/analyzer/expression/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 622 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 625 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 628 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 629 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 630 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 632 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 633 "src/analyzer/expression/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 634 "src/analyzer/expression/Expression.pv"
            if (name == 0) {
                #line 634 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 636 "src/analyzer/expression/Expression.pv"
            struct Expression* value = 0;
            #line 637 "src/analyzer/expression/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 638 "src/analyzer/expression/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 640 "src/analyzer/expression/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 641 "src/analyzer/expression/Expression.pv"
                if (return_type == 0) {
                    #line 642 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 643 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 646 "src/analyzer/expression/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 649 "src/analyzer/expression/Expression.pv"
            if (value == 0) {
                #line 649 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 651 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 653 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 654 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 655 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 659 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 659 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 661 "src/analyzer/expression/Expression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 661 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 663 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 665 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 667 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 668 "src/analyzer/expression/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 669 "src/analyzer/expression/Expression.pv"
            if (argument == 0) {
                #line 669 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 671 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 673 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 674 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 675 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 679 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 679 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 681 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 684 "src/analyzer/expression/Expression.pv"
    return parent;
}

#line 687 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 688 "src/analyzer/expression/Expression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 690 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 691 "src/analyzer/expression/Expression.pv"
        struct Expression* placement = 0;
        #line 692 "src/analyzer/expression/Expression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 693 "src/analyzer/expression/Expression.pv"
            placement = Expression__parse(context, generics);
            #line 694 "src/analyzer/expression/Expression.pv"
            if (placement == 0) {
                #line 694 "src/analyzer/expression/Expression.pv"
                return 0;
            }
            #line 695 "src/analyzer/expression/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 695 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 698 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 699 "src/analyzer/expression/Expression.pv"
        if (expression == 0) {
            #line 699 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 701 "src/analyzer/expression/Expression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 702 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { ._0 = placement, ._1 = expression} } }, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 704 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 705 "src/analyzer/expression/Expression.pv"
        if (expression == 0) {
            #line 705 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 707 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 });
    }

    #line 710 "src/analyzer/expression/Expression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 711 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 714 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 715 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 715 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 717 "src/analyzer/expression/Expression.pv"
    switch (inner->return_type.type) {
        #line 718 "src/analyzer/expression/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 719 "src/analyzer/expression/Expression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 720 "src/analyzer/expression/Expression.pv"
        default: {
            #line 721 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 722 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
    }

    #line 726 "src/analyzer/expression/Expression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 727 "src/analyzer/expression/Expression.pv"
    if (member == 0) {
        #line 727 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 729 "src/analyzer/expression/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 730 "src/analyzer/expression/Expression.pv"
    if (member_type == 0) {
        #line 730 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 732 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 735 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 736 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 736 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 738 "src/analyzer/expression/Expression.pv"
    struct Token* member_name = Context__current(context);
    #line 739 "src/analyzer/expression/Expression.pv"
    if (member_name == 0) {
        #line 739 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 741 "src/analyzer/expression/Expression.pv"
    if (member_name->type != TOKEN_TYPE__NUMBER && member_name->type != TOKEN_TYPE__IDENTIFIER) {
        #line 742 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 745 "src/analyzer/expression/Expression.pv"
    Context__next_token(context);

    #line 747 "src/analyzer/expression/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 748 "src/analyzer/expression/Expression.pv"
    if (member_type == 0) {
        #line 748 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 750 "src/analyzer/expression/Expression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 751 "src/analyzer/expression/Expression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) {};
    #line 752 "src/analyzer/expression/Expression.pv"
    struct Function* func_info = 0;

    #line 754 "src/analyzer/expression/Expression.pv"
    bool is_function = false;
    #line 755 "src/analyzer/expression/Expression.pv"
    switch (member_type->type) {
        #line 756 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 756 "src/analyzer/expression/Expression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 757 "src/analyzer/expression/Expression.pv"
            is_function = true;
            #line 758 "src/analyzer/expression/Expression.pv"
            func_info = func_info2;
        } break;
        #line 760 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 760 "src/analyzer/expression/Expression.pv"
            is_function = true;
        } break;
        #line 761 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 761 "src/analyzer/expression/Expression.pv"
            is_function = true;
        } break;
        #line 762 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 765 "src/analyzer/expression/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 766 "src/analyzer/expression/Expression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 769 "src/analyzer/expression/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 770 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 770 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 772 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 774 "src/analyzer/expression/Expression.pv"
        if (func_info != 0 && func_info->parameters.length > 0 && str__eq(func_info->parameters.data[0].name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 775 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = inner });
        }

        #line 778 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 779 "src/analyzer/expression/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 780 "src/analyzer/expression/Expression.pv"
            if (argument == 0) {
                #line 780 "src/analyzer/expression/Expression.pv"
                return 0;
            }
            #line 781 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 783 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 784 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 785 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 789 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 789 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 791 "src/analyzer/expression/Expression.pv"
        if (func_info != 0 && func_info->generics.array.length > 0) {
            #line 792 "src/analyzer/expression/Expression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 793 "src/analyzer/expression/Expression.pv"
            member_type = Module__make_type_usage(context->module, member_type, &func_generics->array);
        }

        #line 796 "src/analyzer/expression/Expression.pv"
        if (func_info != 0 && (func_info->type == FUNCTION_TYPE__BUILTIN || func_info->type == FUNCTION_TYPE__METHOD_CPP)) {
            #line 797 "src/analyzer/expression/Expression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 798 "src/analyzer/expression/Expression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 800 "src/analyzer/expression/Expression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 803 "src/analyzer/expression/Expression.pv"
        if (generic_map != 0) {
            #line 804 "src/analyzer/expression/Expression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }

        #line 807 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
    }
}

#line 811 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 812 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
        #line 812 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 814 "src/analyzer/expression/Expression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 815 "src/analyzer/expression/Expression.pv"
    if (index_expr == 0) {
        #line 815 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 817 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]")) {
        #line 817 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 819 "src/analyzer/expression/Expression.pv"
    switch (index_expr->data.type) {
        #line 820 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 820 "src/analyzer/expression/Expression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 820 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 821 "src/analyzer/expression/Expression.pv"
            switch (target->return_type.type) {
                #line 822 "src/analyzer/expression/Expression.pv"
                case TYPE__ENUM: {
                    #line 822 "src/analyzer/expression/Expression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 823 "src/analyzer/expression/Expression.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 824 "src/analyzer/expression/Expression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        });

                        #line 830 "src/analyzer/expression/Expression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 831 "src/analyzer/expression/Expression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 833 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 835 "src/analyzer/expression/Expression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, *index_expr->token);
                        #line 836 "src/analyzer/expression/Expression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 837 "src/analyzer/expression/Expression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 839 "src/analyzer/expression/Expression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, *argument_name_data);
                        #line 840 "src/analyzer/expression/Expression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 842 "src/analyzer/expression/Expression.pv"
                        if (Expression__is_zero(start)) {
                            #line 843 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 844 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 846 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 851 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 857 "src/analyzer/expression/Expression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence });
                        #line 858 "src/analyzer/expression/Expression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 859 "src/analyzer/expression/Expression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 862 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 865 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 868 "src/analyzer/expression/Expression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 869 "src/analyzer/expression/Expression.pv"
    struct Type* element_type = 0;

    #line 871 "src/analyzer/expression/Expression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 872 "src/analyzer/expression/Expression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 873 "src/analyzer/expression/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 873 "src/analyzer/expression/Expression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 874 "src/analyzer/expression/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 876 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
    } else {
        #line 879 "src/analyzer/expression/Expression.pv"
        switch (inner_return_type->type) {
            #line 880 "src/analyzer/expression/Expression.pv"
            case TYPE__INDIRECT: {
                #line 880 "src/analyzer/expression/Expression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 881 "src/analyzer/expression/Expression.pv"
                element_type = &indirect->to;
            } break;
            #line 883 "src/analyzer/expression/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 883 "src/analyzer/expression/Expression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 884 "src/analyzer/expression/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 886 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
    }

    #line 890 "src/analyzer/expression/Expression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 891 "src/analyzer/expression/Expression.pv"
        element_type = Type__to_ptr(&(struct Type) { .type = TYPE__UNKNOWN, .unknown_value = { ._0 = (struct str){ .ptr = "", .length = strlen("") }, ._1 = (struct Array_Type) {}} }, context->allocator);
    }

    #line 894 "src/analyzer/expression/Expression.pv"
    if (element_type == 0) {
        #line 895 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, index_expr->token, "Type is not indexable");
        #line 896 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 899 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 902 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 903 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);

    #line 905 "src/analyzer/expression/Expression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 906 "src/analyzer/expression/Expression.pv"
        return Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 908 "src/analyzer/expression/Expression.pv"
        return Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 910 "src/analyzer/expression/Expression.pv"
        return Expression__parse_index_expression(context, inner, generics);
    } else if (Type__is_function(Type__resolve_typedef_function(&inner->return_type)) && (Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, "("))) {
        #line 912 "src/analyzer/expression/Expression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 913 "src/analyzer/expression/Expression.pv"
            case TYPE__FUNCTION: {
                #line 913 "src/analyzer/expression/Expression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 914 "src/analyzer/expression/Expression.pv"
                struct Array_Type parsed_generics = (struct Array_Type) {};

                #line 916 "src/analyzer/expression/Expression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                    #line 917 "src/analyzer/expression/Expression.pv"
                    parsed_generics = Context__parse_generics(context, generics);
                }

                #line 920 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 920 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 922 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 924 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 925 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 926 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 928 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 929 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 930 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 934 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 934 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 936 "src/analyzer/expression/Expression.pv"
                if (func_info->generics.array.length > 0) {
                    #line 937 "src/analyzer/expression/Expression.pv"
                    struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                    #line 938 "src/analyzer/expression/Expression.pv"
                    inner->return_type = *Module__make_type_usage(context->module, &inner->return_type, &func_generics->array);

                    #line 940 "src/analyzer/expression/Expression.pv"
                    switch (inner->data.type) {
                        #line 941 "src/analyzer/expression/Expression.pv"
                        case EXPRESSION_DATA__TYPE: {
                            #line 941 "src/analyzer/expression/Expression.pv"
                            struct Type** type = &inner->data.type_value;
                            #line 942 "src/analyzer/expression/Expression.pv"
                            *type = &inner->return_type;
                        } break;
                        #line 944 "src/analyzer/expression/Expression.pv"
                        default: {
                        } break;
                    }
                }

                #line 948 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_arguments(context, token, &inner->return_type, &arguments, 0, false)) {
                    #line 948 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 950 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 952 "src/analyzer/expression/Expression.pv"
            case TYPE__FUNCTION_C: {
                #line 952 "src/analyzer/expression/Expression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 953 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 953 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 955 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 957 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 958 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 959 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 961 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 962 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 963 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 967 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 967 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 969 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 971 "src/analyzer/expression/Expression.pv"
            case TYPE__CLASS_CPP: {
                #line 972 "src/analyzer/expression/Expression.pv"
                return Expression__parse_class(context, token, inner, generics);
            } break;
            #line 974 "src/analyzer/expression/Expression.pv"
            case TYPE__UNKNOWN: {
                #line 975 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 975 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 977 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 979 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 980 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 981 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 983 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 984 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 985 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 989 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 989 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 991 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &context->root->type_unknown);
            } break;
            #line 993 "src/analyzer/expression/Expression.pv"
            default: {
                #line 994 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 995 "src/analyzer/expression/Expression.pv"
                return 0;
            } break;
        }
    }

    #line 1000 "src/analyzer/expression/Expression.pv"
    return inner;
}

#line 1003 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics) {
    #line 1004 "src/analyzer/expression/Expression.pv"
    struct Expression* result = lhs;

    #line 1006 "src/analyzer/expression/Expression.pv"
    while (true) {
        #line 1007 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__current(context);
        #line 1008 "src/analyzer/expression/Expression.pv"
        uintptr_t prec = Expression__get_precedence(token);
        #line 1009 "src/analyzer/expression/Expression.pv"
        if (prec < min_prec) {
            #line 1009 "src/analyzer/expression/Expression.pv"
            break;
        }

        #line 1011 "src/analyzer/expression/Expression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 1012 "src/analyzer/expression/Expression.pv"
        if (operator == 0) {
            #line 1012 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1014 "src/analyzer/expression/Expression.pv"
        struct Expression* rhs = Expression__parse_primary(context, generics);
        #line 1015 "src/analyzer/expression/Expression.pv"
        if (rhs == 0) {
            #line 1015 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1017 "src/analyzer/expression/Expression.pv"
        struct Expression* rhs_final = Expression__parse_binary(context, rhs, prec + 1, generics);
        #line 1018 "src/analyzer/expression/Expression.pv"
        if (rhs_final == 0) {
            #line 1018 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1020 "src/analyzer/expression/Expression.pv"
        bool is_comparison = str__eq(operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__eq(operator->value, (struct str){ .ptr = "!=", .length = strlen("!=") }) || str__eq(operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__eq(operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") }) || str__eq(operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__eq(operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });

        #line 1026 "src/analyzer/expression/Expression.pv"
        struct Type* return_type = 0;
        #line 1027 "src/analyzer/expression/Expression.pv"
        if (is_comparison) {
            #line 1028 "src/analyzer/expression/Expression.pv"
            if (!str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) && !str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
                #line 1029 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_type(result, context, &rhs_final->return_type, false)) {
                    #line 1029 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            }

            #line 1032 "src/analyzer/expression/Expression.pv"
            return_type = &context->root->type_bool;
        } else {
            #line 1034 "src/analyzer/expression/Expression.pv"
            return_type = &result->return_type;
        }

        #line 1037 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = result, ._1 = operator->value, ._2 = rhs_final} }, return_type);
    }

    #line 1040 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 1043 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics) {
    #line 1044 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 1045 "src/analyzer/expression/Expression.pv"
    enum TokenType token_type = token->type;
    #line 1046 "src/analyzer/expression/Expression.pv"
    struct Expression* result = 0;

    #line 1048 "src/analyzer/expression/Expression.pv"
    switch (token_type) {
        #line 1049 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 1050 "src/analyzer/expression/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 1052 "src/analyzer/expression/Expression.pv"
            if (context->module->mode_cpp && (str__eq(token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__eq(token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 1053 "src/analyzer/expression/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 1055 "src/analyzer/expression/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 1056 "src/analyzer/expression/Expression.pv"
                if (type != 0) {
                    #line 1057 "src/analyzer/expression/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 1058 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM: {
                            #line 1058 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 1059 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 1059 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 1060 "src/analyzer/expression/Expression.pv"
                        case TYPE__SELF: {
                            #line 1060 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1061 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 1061 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1062 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 1062 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1063 "src/analyzer/expression/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 1063 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1064 "src/analyzer/expression/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 1064 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 1065 "src/analyzer/expression/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 1065 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 1066 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 1066 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 1069 "src/analyzer/expression/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 1070 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                    });

                    #line 1075 "src/analyzer/expression/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 1077 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 1078 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            } else {
                #line 1081 "src/analyzer/expression/Expression.pv"
                switch (return_type->type) {
                    #line 1082 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 1082 "src/analyzer/expression/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 1083 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1084 "src/analyzer/expression/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 1085 "src/analyzer/expression/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) {};

                        #line 1087 "src/analyzer/expression/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 1088 "src/analyzer/expression/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 1091 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 1091 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1093 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1095 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1096 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1097 "src/analyzer/expression/Expression.pv"
                            if (argument == 0) {
                                #line 1097 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                            #line 1098 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1100 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 1101 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1102 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1106 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1106 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1108 "src/analyzer/expression/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 1109 "src/analyzer/expression/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 1110 "src/analyzer/expression/Expression.pv"
                            func_type = Module__make_type_usage(context->module, func_type, &func_generics->array);
                        }

                        #line 1113 "src/analyzer/expression/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 1113 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1115 "src/analyzer/expression/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 1116 "src/analyzer/expression/Expression.pv"
                        switch (func_type->type) {
                            #line 1117 "src/analyzer/expression/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 1117 "src/analyzer/expression/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 1118 "src/analyzer/expression/Expression.pv"
                                switch (func_info->type) {
                                    #line 1119 "src/analyzer/expression/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 1120 "src/analyzer/expression/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} });
                                    } break;
                                    #line 1122 "src/analyzer/expression/Expression.pv"
                                    default: {
                                        #line 1123 "src/analyzer/expression/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 1127 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 1130 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 1131 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 1133 "src/analyzer/expression/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 1134 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1135 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1137 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 1138 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1139 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1141 "src/analyzer/expression/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 1142 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1143 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1145 "src/analyzer/expression/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 1146 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1147 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1149 "src/analyzer/expression/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 1150 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1151 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1153 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM: {
                        #line 1154 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1155 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1157 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 1158 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1159 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1161 "src/analyzer/expression/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 1162 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1163 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1165 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNKNOWN: {
                        #line 1166 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1167 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1169 "src/analyzer/expression/Expression.pv"
                    case TYPE__SELF: {
                        #line 1170 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1171 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1173 "src/analyzer/expression/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 1174 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1175 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1177 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 1178 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1179 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1181 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 1182 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1183 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1185 "src/analyzer/expression/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 1186 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1187 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1189 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 1190 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1191 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1193 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 1193 "src/analyzer/expression/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 1194 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1195 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 1195 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1197 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1199 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1200 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1201 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1203 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 1204 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1205 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1209 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1209 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1211 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 1213 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, &func_info->return_type);
                    } break;
                    #line 1215 "src/analyzer/expression/Expression.pv"
                    default: {
                        #line 1216 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 1221 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 1222 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char },
            });
        } break;
        #line 1228 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 1229 "src/analyzer/expression/Expression.pv"
            char const* primitive = "i32";

            #line 1231 "src/analyzer/expression/Expression.pv"
            if (str__ends_with(token->value, "f") || str__ends_with(token->value, "F")) {
                #line 1232 "src/analyzer/expression/Expression.pv"
                primitive = "f32";
            } else if (str__ends_with(token->value, "u") || str__ends_with(token->value, "U")) {
                #line 1234 "src/analyzer/expression/Expression.pv"
                primitive = "u32";
            } else if (str__contains(token->value, ".")) {
                #line 1236 "src/analyzer/expression/Expression.pv"
                primitive = "f64";
            }

            #line 1239 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 1245 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 1246 "src/analyzer/expression/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 1247 "src/analyzer/expression/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 1248 "src/analyzer/expression/Expression.pv"
                if (operator == 0) {
                    #line 1248 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1250 "src/analyzer/expression/Expression.pv"
                if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 1251 "src/analyzer/expression/Expression.pv"
                    context->pos -= 1;
                    #line 1252 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 1253 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 1255 "src/analyzer/expression/Expression.pv"
                    struct Expression* child = Expression__parse_primary(context, generics);
                    #line 1256 "src/analyzer/expression/Expression.pv"
                    if (child == 0) {
                        #line 1256 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 1258 "src/analyzer/expression/Expression.pv"
                    if (str__eq(operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 1259 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 1260 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1260 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1261 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) });
                                #line 1262 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1264 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 1265 "src/analyzer/expression/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 1266 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 1270 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 1271 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1271 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1272 "src/analyzer/expression/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 1273 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect });
                                #line 1274 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1276 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 1276 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 1279 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 1283 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 1283 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1285 "src/analyzer/expression/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 1286 "src/analyzer/expression/Expression.pv"
                if (expr == 0) {
                    #line 1286 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1288 "src/analyzer/expression/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 1289 "src/analyzer/expression/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 1291 "src/analyzer/expression/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, *expr->token);
                    #line 1292 "src/analyzer/expression/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 1294 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 1296 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1297 "src/analyzer/expression/Expression.pv"
                        struct String name_string = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 1298 "src/analyzer/expression/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 1299 "src/analyzer/expression/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 1301 "src/analyzer/expression/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, *Context__current(context));
                        #line 1302 "src/analyzer/expression/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 1304 "src/analyzer/expression/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 1305 "src/analyzer/expression/Expression.pv"
                        if (value == 0) {
                            #line 1305 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1307 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 1309 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1310 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 1311 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 1315 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple) {});
                    #line 1316 "src/analyzer/expression/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 1317 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 1317 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1317 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1317 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1318 "src/analyzer/expression/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 1321 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }), arguments, 0);
                } else {
                    #line 1323 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1323 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 1325 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 1328 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
                    #line 1328 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1330 "src/analyzer/expression/Expression.pv"
                struct Type* element_type = 0;
                #line 1331 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 1333 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 1334 "src/analyzer/expression/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 1335 "src/analyzer/expression/Expression.pv"
                    if (element == 0) {
                        #line 1335 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 1337 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .value = element });

                    #line 1339 "src/analyzer/expression/Expression.pv"
                    if (element_type == 0) {
                        #line 1340 "src/analyzer/expression/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 1343 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 1344 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 1345 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 1349 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 1351 "src/analyzer/expression/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = elements.length }, .element = *element_type });
                #line 1352 "src/analyzer/expression/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence });
                #line 1353 "src/analyzer/expression/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 1355 "src/analyzer/expression/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 1357 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 1360 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 1361 "src/analyzer/expression/Expression.pv"
            if (str__eq(token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__eq(token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 1362 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, "bool") },
                });
            } else if (str__eq(token->value, (struct str){ .ptr = "if", .length = strlen("if") })) {
                #line 1368 "src/analyzer/expression/Expression.pv"
                result = Expression__parse_if_expression(context, generics);
            } else {
                #line 1370 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 1373 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 1374 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 1378 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 1378 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1380 "src/analyzer/expression/Expression.pv"
    return Expression__parse_postfix_chain(context, result, generics);
}

#line 1384 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 1385 "src/analyzer/expression/Expression.pv"
    struct Expression* result = Expression__parse_primary(context, generics);
    #line 1386 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 1386 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1388 "src/analyzer/expression/Expression.pv"
    result = Expression__parse_binary(context, result, 1, generics);
    #line 1389 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 1389 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1391 "src/analyzer/expression/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 1392 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 1394 "src/analyzer/expression/Expression.pv"
        struct Expression* range_start = result;
        #line 1395 "src/analyzer/expression/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 1396 "src/analyzer/expression/Expression.pv"
        if (range_end == 0) {
            #line 1396 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1398 "src/analyzer/expression/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, &(struct Array_Type) { .data = &range_end->return_type, .length = 1 });
        #line 1399 "src/analyzer/expression/Expression.pv"
        if (enum_type == 0) {
            #line 1400 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 1401 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1404 "src/analyzer/expression/Expression.pv"
        struct Token variant_name = *token;
        #line 1405 "src/analyzer/expression/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 1406 "src/analyzer/expression/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 1408 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 1409 "src/analyzer/expression/Expression.pv"
        struct EnumVariant* variant = 0;
        #line 1410 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 1411 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 1411 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* enum_variant = variant_result.enumvariant_value;
                #line 1411 "src/analyzer/expression/Expression.pv"
                variant = enum_variant;
            } break;
            #line 1412 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
        #line 1414 "src/analyzer/expression/Expression.pv"
        if (variant == 0) {
            #line 1415 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range StartEnd enum variant");
            #line 1416 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1419 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1420 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_start });
        #line 1421 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_end });

        #line 1423 "src/analyzer/expression/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 1425 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 1428 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 1431 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 1432 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 1433 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1433 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 1433 "src/analyzer/expression/Expression.pv"
            return str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 1434 "src/analyzer/expression/Expression.pv"
        default: {
            #line 1434 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 1438 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast) {
    #line 1439 "src/analyzer/expression/Expression.pv"
    bool success = true;

    #line 1441 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 1442 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1442 "src/analyzer/expression/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 1442 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 1443 "src/analyzer/expression/Expression.pv"
            switch (type->type) {
                #line 1444 "src/analyzer/expression/Expression.pv"
                case TYPE__TUPLE: {
                    #line 1444 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = type->tuple_value;
                    #line 1445 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 1445 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1445 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1445 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1446 "src/analyzer/expression/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i], apply_implicit_cast) && success;
                    } }

                    #line 1449 "src/analyzer/expression/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type };
                    #line 1450 "src/analyzer/expression/Expression.pv"
                    invoke->return_type = *type;
                    #line 1451 "src/analyzer/expression/Expression.pv"
                    self->return_type = *type;

                    #line 1453 "src/analyzer/expression/Expression.pv"
                    return success;
                } break;
                #line 1455 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 1458 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 1461 "src/analyzer/expression/Expression.pv"
    if (apply_implicit_cast && Type__needs_implicit_cast(type, &self->return_type)) {
        #line 1462 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, *self);
        #line 1463 "src/analyzer/expression/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 1464 "src/analyzer/expression/Expression.pv"
        self->return_type = *type;
        #line 1465 "src/analyzer/expression/Expression.pv"
        return true;
    }

    #line 1468 "src/analyzer/expression/Expression.pv"
    if (!Type__eq(type, &self->return_type)) {
        #line 1469 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1470 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
        #line 1471 "src/analyzer/expression/Expression.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 1472 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&type_name));
        #line 1473 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 1474 "src/analyzer/expression/Expression.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 1475 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 1476 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, self->token, String__c_str(&message));
        #line 1477 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 1480 "src/analyzer/expression/Expression.pv"
    self->return_type = *type;
    #line 1481 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 1484 "src/analyzer/expression/Expression.pv"
uintptr_t Expression__get_precedence(struct Token* token) {
    #line 1485 "src/analyzer/expression/Expression.pv"
    if (token->type != TOKEN_TYPE__SYMBOL) {
        #line 1485 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1487 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "||", .length = strlen("||") })) {
        #line 1487 "src/analyzer/expression/Expression.pv"
        return 1;
    }
    #line 1488 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
        #line 1488 "src/analyzer/expression/Expression.pv"
        return 2;
    }
    #line 1489 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "|", .length = strlen("|") })) {
        #line 1489 "src/analyzer/expression/Expression.pv"
        return 3;
    }
    #line 1490 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "^", .length = strlen("^") })) {
        #line 1490 "src/analyzer/expression/Expression.pv"
        return 4;
    }
    #line 1491 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
        #line 1491 "src/analyzer/expression/Expression.pv"
        return 5;
    }
    #line 1492 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__eq(token->value, (struct str){ .ptr = "!=", .length = strlen("!=") })) {
        #line 1492 "src/analyzer/expression/Expression.pv"
        return 6;
    }
    #line 1493 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__eq(token->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__eq(token->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__eq(token->value, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 1493 "src/analyzer/expression/Expression.pv"
        return 7;
    }
    #line 1494 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "<<", .length = strlen("<<") }) || str__eq(token->value, (struct str){ .ptr = ">>", .length = strlen(">>") })) {
        #line 1494 "src/analyzer/expression/Expression.pv"
        return 8;
    }
    #line 1495 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__eq(token->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 1495 "src/analyzer/expression/Expression.pv"
        return 9;
    }
    #line 1496 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__eq(token->value, (struct str){ .ptr = "/", .length = strlen("/") }) || str__eq(token->value, (struct str){ .ptr = "%", .length = strlen("%") })) {
        #line 1496 "src/analyzer/expression/Expression.pv"
        return 10;
    }

    #line 1498 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 1501 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 1502 "src/analyzer/expression/Expression.pv"
    struct Expression* result = inner;
    #line 1503 "src/analyzer/expression/Expression.pv"
    while (true) {
        #line 1504 "src/analyzer/expression/Expression.pv"
        struct Expression* next = Expression__parse_postfix(context, result, generics);
        #line 1505 "src/analyzer/expression/Expression.pv"
        if (next == result) {
            #line 1505 "src/analyzer/expression/Expression.pv"
            break;
        }
        #line 1506 "src/analyzer/expression/Expression.pv"
        if (next == 0) {
            #line 1506 "src/analyzer/expression/Expression.pv"
            return 0;
        }
        #line 1507 "src/analyzer/expression/Expression.pv"
        result = next;
    }
    #line 1509 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 1512 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics) {
    #line 1513 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 1514 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 1514 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1516 "src/analyzer/expression/Expression.pv"
    struct Expression* condition = Expression__parse(context, generics);
    #line 1517 "src/analyzer/expression/Expression.pv"
    if (condition == 0) {
        #line 1517 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1519 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 1519 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1521 "src/analyzer/expression/Expression.pv"
    struct Expression* a = Expression__parse(context, generics);
    #line 1522 "src/analyzer/expression/Expression.pv"
    if (a == 0) {
        #line 1522 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1524 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 1524 "src/analyzer/expression/Expression.pv"
        return 0;
    }
    #line 1525 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 1525 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1527 "src/analyzer/expression/Expression.pv"
    bool is_else_if = Context__check_value(context, TOKEN_TYPE__KEYWORD, "if");

    #line 1529 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 1530 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Expected { or else if");
        #line 1531 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1534 "src/analyzer/expression/Expression.pv"
    struct Expression* b = Expression__parse(context, generics);
    #line 1535 "src/analyzer/expression/Expression.pv"
    if (b == 0) {
        #line 1535 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1537 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 1537 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1539 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_type(a, context, &b->return_type, false)) {
        #line 1539 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1541 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__IF_EXPRESSION, .ifexpression_value = { ._0 = condition, ._1 = a, ._2 = b} }, &a->return_type);
}
