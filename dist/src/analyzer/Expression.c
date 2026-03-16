#include <stdlib.h>

#include <analyzer/Naming.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/ExpressionData.h>
#include <analyzer/Type.h>
#include <analyzer/Context.h>
#include <stdbool.h>
#include <analyzer/EnumVariantResult.h>
#include <analyzer/Indirect.h>
#include <analyzer/EnumVariant.h>
#include <std/str.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/Enum.h>
#include <stdint.h>
#include <analyzer/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/EnumC.h>
#include <analyzer/Impl.h>
#include <std/ArrayIter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Primitive.h>
#include <analyzer/Function.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/GenericMap.h>
#include <analyzer/StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/Struct.h>
#include <analyzer/Root.h>
#include <analyzer/FunctionParent.h>
#include <analyzer/Trait.h>
#include <std/Allocator.h>
#include <analyzer/TypedefC.h>
#include <analyzer/StructCField.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/StructC.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/ClassCpp.h>
#include <std/ArrayIter_ref_Type.h>
#include <std/Array_Type.h>
#include <std/ArrayIter_ref_ref_Trait.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/Generic.h>
#include <analyzer/Sequence.h>
#include <analyzer/TypeImpl.h>
#include <analyzer/Generics.h>
#include <analyzer/TokenType.h>
#include <analyzer/Tuple.h>
#include <analyzer/NamespaceCpp.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/InvokeArgument.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <analyzer/Parameter.h>
#include <std/Array_Parameter.h>
#include <std/ArrayIter_ref_InvokeArgument.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/FunctionType.h>
#include <std/String.h>
#include <analyzer/FunctionC.h>
#include <analyzer/CppExpression.h>
#include <analyzer/Module.h>
#include <std/Array_Generic.h>
#include <analyzer/SequenceType.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>

#include <analyzer/Expression.h>

#line 44 "src/analyzer/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type) {
    #line 45 "src/analyzer/Expression.pv"
    return ArenaAllocator__store_Expression(allocator, (struct Expression) {
        .token = token,
        .data = data,
        .return_type = *return_type,
    });
}

#line 52 "src/analyzer/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node) {
    #line 53 "src/analyzer/Expression.pv"
    struct Expression* result = ArenaAllocator__store_Expression(context->allocator, node);

    #line 55 "src/analyzer/Expression.pv"
    Context__next_token(context);

    #line 57 "src/analyzer/Expression.pv"
    return result;
}

#line 60 "src/analyzer/Expression.pv"
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token) {
    #line 61 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 62 "src/analyzer/Expression.pv"
        case TYPE__INDIRECT: {
            #line 62 "src/analyzer/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 63 "src/analyzer/Expression.pv"
            return Expression__get_enum_variant(context, &indirect->to, token);
        } break;
        #line 65 "src/analyzer/Expression.pv"
        case TYPE__SELF: {
            #line 66 "src/analyzer/Expression.pv"
            return Expression__get_enum_variant(context, context->type_self, token);
        } break;
        #line 68 "src/analyzer/Expression.pv"
        case TYPE__ENUM: {
            #line 68 "src/analyzer/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 69 "src/analyzer/Expression.pv"
            struct EnumVariant* variant = HashMap_str_EnumVariant__find(&enum_info->variants, &token->value);
            #line 70 "src/analyzer/Expression.pv"
            if (variant == 0) {
                #line 71 "src/analyzer/Expression.pv"
                Context__error_token(context, token, "Variant not found in enum");
                #line 72 "src/analyzer/Expression.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
            }

            #line 75 "src/analyzer/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_VARIANT, .enumvariant_value = variant };
        } break;
        #line 77 "src/analyzer/Expression.pv"
        case TYPE__ENUM_C: {
            #line 77 "src/analyzer/Expression.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 78 "src/analyzer/Expression.pv"
            struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &token->value);
            #line 79 "src/analyzer/Expression.pv"
            if (variant == 0) {
                #line 81 "src/analyzer/Expression.pv"
                Context__error_token(context, token, "Variant not found in enum");
            }

            #line 85 "src/analyzer/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_CVALUE, .enumcvalue_value = variant };
        } break;
        #line 87 "src/analyzer/Expression.pv"
        default: {
            #line 87 "src/analyzer/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
    }

    #line 90 "src/analyzer/Expression.pv"
    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
}

#line 93 "src/analyzer/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error) {
    #line 94 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 95 "src/analyzer/Expression.pv"
        case TYPE__INDIRECT: {
            #line 95 "src/analyzer/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 96 "src/analyzer/Expression.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 98 "src/analyzer/Expression.pv"
        case TYPE__SELF: {
            #line 99 "src/analyzer/Expression.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 101 "src/analyzer/Expression.pv"
        case TYPE__PRIMITIVE: {
            #line 101 "src/analyzer/Expression.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 102 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 102 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 102 "src/analyzer/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 103 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 104 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 105 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap) { .self_type = type })} });
                }
            } }

            #line 109 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 109 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 110 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 112 "src/analyzer/Expression.pv"
        case TYPE__STRUCT: {
            #line 112 "src/analyzer/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 112 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 113 "src/analyzer/Expression.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 114 "src/analyzer/Expression.pv"
            if (field != 0) {
                #line 115 "src/analyzer/Expression.pv"
                return &field->type;
            }

            #line 118 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 118 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 118 "src/analyzer/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 119 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 120 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 121 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 125 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 126 "src/analyzer/Expression.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 128 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 130 "src/analyzer/Expression.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 130 "src/analyzer/Expression.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 130 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 131 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 132 "src/analyzer/Expression.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, context->root->func_next);
                #line 133 "src/analyzer/Expression.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 134 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} });
            }

            #line 137 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 138 "src/analyzer/Expression.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, context->root->func_value);
                #line 139 "src/analyzer/Expression.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 140 "src/analyzer/Expression.pv"
                func_value->return_type = func_info->return_type;
                #line 141 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} });
            }

            #line 144 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 144 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 145 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 147 "src/analyzer/Expression.pv"
        case TYPE__ENUM: {
            #line 147 "src/analyzer/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 147 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 148 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 148 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 148 "src/analyzer/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 149 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 150 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 151 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 155 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 155 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 156 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 158 "src/analyzer/Expression.pv"
        case TYPE__TRAIT: {
            #line 158 "src/analyzer/Expression.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 158 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 159 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 160 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) });
            }

            #line 163 "src/analyzer/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 164 "src/analyzer/Expression.pv"
            if (function == 0) {
                #line 165 "src/analyzer/Expression.pv"
                if (output_error) {
                    #line 165 "src/analyzer/Expression.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 166 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 169 "src/analyzer/Expression.pv"
            return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
        } break;
        #line 171 "src/analyzer/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 171 "src/analyzer/Expression.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 172 "src/analyzer/Expression.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 174 "src/analyzer/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 174 "src/analyzer/Expression.pv"
            struct StructC* struct_info = type->structc_value;
            #line 175 "src/analyzer/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 176 "src/analyzer/Expression.pv"
            if (field != 0) {
                #line 176 "src/analyzer/Expression.pv"
                return &field->type;
            }

            #line 178 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 178 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 179 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 181 "src/analyzer/Expression.pv"
        case TYPE__UNION_C: {
            #line 181 "src/analyzer/Expression.pv"
            struct StructC* union_info = type->unionc_value;
            #line 182 "src/analyzer/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 183 "src/analyzer/Expression.pv"
            if (field != 0) {
                #line 183 "src/analyzer/Expression.pv"
                return &field->type;
            }

            #line 185 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 185 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 186 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 188 "src/analyzer/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 188 "src/analyzer/Expression.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 189 "src/analyzer/Expression.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 190 "src/analyzer/Expression.pv"
            if (field_type != 0) {
                #line 190 "src/analyzer/Expression.pv"
                return field_type;
            }

            #line 192 "src/analyzer/Expression.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 193 "src/analyzer/Expression.pv"
            if (value_type != 0) {
                #line 193 "src/analyzer/Expression.pv"
                return value_type;
            }

            #line 195 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 195 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 195 "src/analyzer/Expression.pv"
                struct Type* base = ArrayIter_ref_Type__value(&__iter);

                #line 196 "src/analyzer/Expression.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 197 "src/analyzer/Expression.pv"
                if (base_type != 0) {
                    #line 197 "src/analyzer/Expression.pv"
                    return base_type;
                }
            } }

            #line 200 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 200 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 201 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 203 "src/analyzer/Expression.pv"
        case TYPE__GENERIC: {
            #line 203 "src/analyzer/Expression.pv"
            struct Generic* generic = type->generic_value;
            #line 204 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
            #line 204 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Trait__next(&__iter)) {
                #line 204 "src/analyzer/Expression.pv"
                struct Trait* trait_info = *ArrayIter_ref_ref_Trait__value(&__iter);

                #line 205 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 206 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 207 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap) {})} });
                }
            } }

            #line 211 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 211 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 212 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 214 "src/analyzer/Expression.pv"
        case TYPE__SEQUENCE: {
            #line 214 "src/analyzer/Expression.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 215 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 216 "src/analyzer/Expression.pv"
                return &sequence->element_pointer;
            }

            #line 219 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 220 "src/analyzer/Expression.pv"
                return &context->root->type_usize;
            }

            #line 223 "src/analyzer/Expression.pv"
            struct Impl* impl_info = context->root->hack_type_impl->impl_info;

            #line 225 "src/analyzer/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
            #line 226 "src/analyzer/Expression.pv"
            if (function != 0) {
                #line 227 "src/analyzer/Expression.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, &(struct Generics) {}, &(struct Array_Type) {});
                #line 228 "src/analyzer/Expression.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 229 "src/analyzer/Expression.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) });

                #line 231 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, generic_map)} });
            }

            #line 234 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 234 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 235 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 237 "src/analyzer/Expression.pv"
        case TYPE__TUPLE: {
            #line 237 "src/analyzer/Expression.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 238 "src/analyzer/Expression.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 239 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 240 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 243 "src/analyzer/Expression.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 244 "src/analyzer/Expression.pv"
            if (index >= tuple->elements.length) {
                #line 245 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 246 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 249 "src/analyzer/Expression.pv"
            return &tuple->elements.data[index];
        } break;
        #line 251 "src/analyzer/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 251 "src/analyzer/Expression.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 252 "src/analyzer/Expression.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 253 "src/analyzer/Expression.pv"
            if (type != 0) {
                #line 253 "src/analyzer/Expression.pv"
                return type;
            }

            #line 255 "src/analyzer/Expression.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 256 "src/analyzer/Expression.pv"
            if (value != 0) {
                #line 256 "src/analyzer/Expression.pv"
                return value;
            }

            #line 258 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 258 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 260 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 262 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 262 "src/analyzer/Expression.pv"
            return type;
        } break;
        #line 263 "src/analyzer/Expression.pv"
        default: {
            #line 263 "src/analyzer/Expression.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 266 "src/analyzer/Expression.pv"
    return 0;
}

#line 269 "src/analyzer/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments) {
    #line 270 "src/analyzer/Expression.pv"
    struct GenericMap generic_map = GenericMap__from_generics(context->allocator, &func_info->generics);

    #line 272 "src/analyzer/Expression.pv"
    uintptr_t i = 0;
    #line 273 "src/analyzer/Expression.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(generics);
    #line 273 "src/analyzer/Expression.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 273 "src/analyzer/Expression.pv"
        struct Type* generic = ArrayIter_ref_Type__value(&__iter);

        #line 274 "src/analyzer/Expression.pv"
        struct Type* target = Array_Type__get(&generic_map.array, i);
        #line 275 "src/analyzer/Expression.pv"
        if (target != 0) {
            #line 275 "src/analyzer/Expression.pv"
            *target = *generic;
        }
        #line 276 "src/analyzer/Expression.pv"
        i += 1;
    } }

    #line 279 "src/analyzer/Expression.pv"
    if (i == generic_map.array.length) {
        #line 280 "src/analyzer/Expression.pv"
        return ArenaAllocator__store_GenericMap(context->allocator, generic_map);
    }

    #line 283 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_Parameter params = Array_Parameter__iter(&func_info->parameters);
    #line 284 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);

    #line 286 "src/analyzer/Expression.pv"
    while (ArrayIter_ref_Parameter__next(&params) && ArrayIter_ref_InvokeArgument__next(&args)) {
        #line 287 "src/analyzer/Expression.pv"
        struct Type* param_type = &ArrayIter_ref_Parameter__value(&params)->type;
        #line 288 "src/analyzer/Expression.pv"
        struct Type* arg_type = &ArrayIter_ref_InvokeArgument__value(&args)->value->return_type;

        #line 290 "src/analyzer/Expression.pv"
        Expression__resolve_generic_type(context, param_type, arg_type, &generic_map);
    }

    #line 293 "src/analyzer/Expression.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, generic_map);
}

#line 296 "src/analyzer/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 297 "src/analyzer/Expression.pv"
    switch (param_type->type) {
        #line 298 "src/analyzer/Expression.pv"
        case TYPE__GENERIC: {
            #line 298 "src/analyzer/Expression.pv"
            struct Generic* generic = param_type->generic_value;
            #line 299 "src/analyzer/Expression.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 300 "src/analyzer/Expression.pv"
            if (generic_type != 0) {
                #line 300 "src/analyzer/Expression.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 302 "src/analyzer/Expression.pv"
        case TYPE__INDIRECT: {
            #line 302 "src/analyzer/Expression.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 303 "src/analyzer/Expression.pv"
            switch (arg_type->type) {
                #line 304 "src/analyzer/Expression.pv"
                case TYPE__INDIRECT: {
                    #line 304 "src/analyzer/Expression.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 305 "src/analyzer/Expression.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 307 "src/analyzer/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 310 "src/analyzer/Expression.pv"
        default: {
        } break;
    }
}

#line 314 "src/analyzer/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call) {
    #line 315 "src/analyzer/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 317 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 318 "src/analyzer/Expression.pv"
        case TYPE__SELF: {
            #line 318 "src/analyzer/Expression.pv"
            {
                #line 318 "src/analyzer/Expression.pv"
                type = context->type_self;
            }
        } break;
        #line 319 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 322 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 323 "src/analyzer/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 323 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 324 "src/analyzer/Expression.pv"
        case TYPE__UNION_C: {
            #line 324 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 325 "src/analyzer/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 325 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 326 "src/analyzer/Expression.pv"
        case TYPE__TUPLE: {
            #line 326 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 327 "src/analyzer/Expression.pv"
        case TYPE__STRUCT: {
            #line 327 "src/analyzer/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 327 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 328 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 328 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 328 "src/analyzer/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 329 "src/analyzer/Expression.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg->name->value);

                #line 331 "src/analyzer/Expression.pv"
                if (param == 0) {
                    #line 332 "src/analyzer/Expression.pv"
                    Context__error_token(context, arg->name, "Unable to find field in struct");
                    #line 333 "src/analyzer/Expression.pv"
                    return false;
                }

                #line 336 "src/analyzer/Expression.pv"
                struct Type* param_type = &param->type;

                #line 338 "src/analyzer/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 339 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 341 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 344 "src/analyzer/Expression.pv"
                if (param_type == 0) {
                    #line 345 "src/analyzer/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve field type");
                    #line 346 "src/analyzer/Expression.pv"
                    return false;
                }

                #line 349 "src/analyzer/Expression.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            } }

            #line 352 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 354 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION: {
            #line 354 "src/analyzer/Expression.pv"
            struct Function* function = type->function_value._0;
            #line 354 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 355 "src/analyzer/Expression.pv"
            if (function == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 355 "src/analyzer/Expression.pv"
                return true;
            }

            #line 357 "src/analyzer/Expression.pv"
            if (function->parameters.length != arguments_length) {
                #line 358 "src/analyzer/Expression.pv"
                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 359 "src/analyzer/Expression.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 361 "src/analyzer/Expression.pv"
                if (is_member_call) {
                    #line 362 "src/analyzer/Expression.pv"
                    String__append_usize(&message, function->parameters.length - 1);
                } else {
                    #line 364 "src/analyzer/Expression.pv"
                    String__append_usize(&message, function->parameters.length);
                }

                #line 367 "src/analyzer/Expression.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 368 "src/analyzer/Expression.pv"
                return false;
            }

            #line 371 "src/analyzer/Expression.pv"
            struct ArrayIter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 372 "src/analyzer/Expression.pv"
            struct ArrayIter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

            #line 374 "src/analyzer/Expression.pv"
            if ((is_member_call)) {
                #line 375 "src/analyzer/Expression.pv"
                ArrayIter_ref_Parameter__next(&param_iter);
                #line 376 "src/analyzer/Expression.pv"
                ArrayIter_ref_InvokeArgument__next(&args_iter);

                #line 378 "src/analyzer/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
                #line 379 "src/analyzer/Expression.pv"
                struct Type* param_type = &ArrayIter_ref_Parameter__value(&param_iter)->type;

                #line 381 "src/analyzer/Expression.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 382 "src/analyzer/Expression.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) });
                    #line 383 "src/analyzer/Expression.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 387 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_Parameter__next(&param_iter) && ArrayIter_ref_InvokeArgument__next(&args_iter)) {
                #line 388 "src/analyzer/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
                #line 389 "src/analyzer/Expression.pv"
                struct Parameter* param = ArrayIter_ref_Parameter__value(&param_iter);
                #line 390 "src/analyzer/Expression.pv"
                struct Type* param_type = &param->type;

                #line 392 "src/analyzer/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 393 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 395 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 398 "src/analyzer/Expression.pv"
                if (param_type == 0) {
                    #line 399 "src/analyzer/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
                    #line 400 "src/analyzer/Expression.pv"
                    return false;
                }

                #line 403 "src/analyzer/Expression.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            }

            #line 406 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 408 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 408 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 409 "src/analyzer/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 409 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 410 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 410 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 411 "src/analyzer/Expression.pv"
        default: {
            #line 411 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 414 "src/analyzer/Expression.pv"
    return false;
}

#line 417 "src/analyzer/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 418 "src/analyzer/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 420 "src/analyzer/Expression.pv"
    if (variant->types.length != arguments_length) {
        #line 421 "src/analyzer/Expression.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 422 "src/analyzer/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 423 "src/analyzer/Expression.pv"
        String__append_usize(&message, variant->types.length);
        #line 424 "src/analyzer/Expression.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 425 "src/analyzer/Expression.pv"
        return false;
    }

    #line 428 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 429 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 431 "src/analyzer/Expression.pv"
    while (ArrayIter_ref_Type__next(&param_iter) && ArrayIter_ref_InvokeArgument__next(&args_iter)) {
        #line 432 "src/analyzer/Expression.pv"
        struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
        #line 433 "src/analyzer/Expression.pv"
        struct Type* param_type = ArrayIter_ref_Type__value(&param_iter);

        #line 435 "src/analyzer/Expression.pv"
        if (generic_map != 0) {
            #line 436 "src/analyzer/Expression.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 439 "src/analyzer/Expression.pv"
        if (param_type == 0) {
            #line 440 "src/analyzer/Expression.pv"
            Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
            #line 441 "src/analyzer/Expression.pv"
            return false;
        }

        #line 444 "src/analyzer/Expression.pv"
        Expression__validate_type(arg->value, context, param_type, true);
    }

    #line 447 "src/analyzer/Expression.pv"
    return true;
}

#line 450 "src/analyzer/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 451 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 452 "src/analyzer/Expression.pv"
        case TYPE__TUPLE: {
            #line 452 "src/analyzer/Expression.pv"
            return type;
        } break;
        #line 453 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION: {
            #line 453 "src/analyzer/Expression.pv"
            struct Function* func_info = type->function_value._0;
            #line 453 "src/analyzer/Expression.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 454 "src/analyzer/Expression.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 456 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 456 "src/analyzer/Expression.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 456 "src/analyzer/Expression.pv"
            return &func_info->return_type;
        } break;
        #line 457 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 457 "src/analyzer/Expression.pv"
            return type;
        } break;
        #line 458 "src/analyzer/Expression.pv"
        default: {
            #line 458 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 461 "src/analyzer/Expression.pv"
    return 0;
}

#line 464 "src/analyzer/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 465 "src/analyzer/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 465 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 467 "src/analyzer/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 468 "src/analyzer/Expression.pv"
    if (func_return_type == 0) {
        #line 468 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 470 "src/analyzer/Expression.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 471 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 474 "src/analyzer/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 475 "src/analyzer/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 475 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 477 "src/analyzer/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 478 "src/analyzer/Expression.pv"
    if (func_return_type == 0) {
        #line 478 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 480 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, func_return_type);
}

#line 483 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics) {
    #line 484 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 485 "src/analyzer/Expression.pv"
        struct Token* variant_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 486 "src/analyzer/Expression.pv"
        if (variant_name == 0) {
            #line 486 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 488 "src/analyzer/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, variant_name);

        #line 490 "src/analyzer/Expression.pv"
        switch (variant_result.type) {
            #line 491 "src/analyzer/Expression.pv"
            case ENUM_VARIANT_RESULT__NONE: {
                #line 492 "src/analyzer/Expression.pv"
                Context__error_token(context, variant_name, "Unable to find enum variant");
                #line 493 "src/analyzer/Expression.pv"
                return false;
            } break;
            #line 495 "src/analyzer/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 495 "src/analyzer/Expression.pv"
                struct EnumVariant* variant = variant_result.enumvariant_value;
                #line 496 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 498 "src/analyzer/Expression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 499 "src/analyzer/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                        #line 499 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 501 "src/analyzer/Expression.pv"
                    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 502 "src/analyzer/Expression.pv"
                        struct Expression* argument = Expression__parse(context, generics);
                        #line 503 "src/analyzer/Expression.pv"
                        if (argument == 0) {
                            #line 503 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 505 "src/analyzer/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                        #line 507 "src/analyzer/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 508 "src/analyzer/Expression.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                            #line 509 "src/analyzer/Expression.pv"
                            return 0;
                        }
                    }

                    #line 513 "src/analyzer/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 513 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 517 "src/analyzer/Expression.pv"
                struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

                #line 519 "src/analyzer/Expression.pv"
                struct GenericMap* generic_map = Type__get_generic_map(enum_type, context);
                #line 520 "src/analyzer/Expression.pv"
                if (!Expression__validate_enum_arguments(context, token, variant, &arguments, generic_map)) {
                    #line 520 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 522 "src/analyzer/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
            } break;
            #line 524 "src/analyzer/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                #line 525 "src/analyzer/Expression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 526 "src/analyzer/Expression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, enum_type);
            } break;
        }
    }

    #line 541 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 544 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 545 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 546 "src/analyzer/Expression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 547 "src/analyzer/Expression.pv"
        if (member == 0) {
            #line 547 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 549 "src/analyzer/Expression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 550 "src/analyzer/Expression.pv"
        if (member_type == 0) {
            #line 550 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 552 "src/analyzer/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 554 "src/analyzer/Expression.pv"
        if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 555 "src/analyzer/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
        } else {
            #line 557 "src/analyzer/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 557 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 559 "src/analyzer/Expression.pv"
            struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 561 "src/analyzer/Expression.pv"
            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 562 "src/analyzer/Expression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 563 "src/analyzer/Expression.pv"
                if (argument == 0) {
                    #line 563 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 565 "src/analyzer/Expression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                #line 567 "src/analyzer/Expression.pv"
                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 568 "src/analyzer/Expression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 569 "src/analyzer/Expression.pv"
                    return 0;
                }
            }

            #line 573 "src/analyzer/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 573 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 575 "src/analyzer/Expression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 575 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 577 "src/analyzer/Expression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 578 "src/analyzer/Expression.pv"
            if (func_return_type == 0) {
                #line 578 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 580 "src/analyzer/Expression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 581 "src/analyzer/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 584 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 586 "src/analyzer/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 587 "src/analyzer/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 588 "src/analyzer/Expression.pv"
            if (name == 0) {
                #line 588 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 590 "src/analyzer/Expression.pv"
            struct Expression* value = 0;
            #line 591 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 592 "src/analyzer/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 594 "src/analyzer/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 595 "src/analyzer/Expression.pv"
                if (return_type == 0) {
                    #line 596 "src/analyzer/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 597 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 600 "src/analyzer/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 603 "src/analyzer/Expression.pv"
            if (value == 0) {
                #line 603 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 605 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 607 "src/analyzer/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 608 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 609 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 613 "src/analyzer/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 613 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 615 "src/analyzer/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 616 "src/analyzer/Expression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 616 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 618 "src/analyzer/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 619 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 621 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 623 "src/analyzer/Expression.pv"
        uintptr_t field_index = 0;
        #line 624 "src/analyzer/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 625 "src/analyzer/Expression.pv"
            struct String name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 626 "src/analyzer/Expression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 627 "src/analyzer/Expression.pv"
            String__append_usize(&name, field_index);
            #line 628 "src/analyzer/Expression.pv"
            struct str name_str = String__as_str(&name);

            #line 630 "src/analyzer/Expression.pv"
            struct Token name_token = *Context__current(context);
            #line 631 "src/analyzer/Expression.pv"
            name_token.value = name_str;

            #line 633 "src/analyzer/Expression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 634 "src/analyzer/Expression.pv"
            if (value == 0) {
                #line 634 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 636 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, name_token),
                .value = value,
            });

            #line 641 "src/analyzer/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 642 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 643 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 646 "src/analyzer/Expression.pv"
            field_index += 1;
        }

        #line 649 "src/analyzer/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 649 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 651 "src/analyzer/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 652 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 655 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 658 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 659 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 660 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 662 "src/analyzer/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 663 "src/analyzer/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 664 "src/analyzer/Expression.pv"
            if (name == 0) {
                #line 664 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 666 "src/analyzer/Expression.pv"
            struct Expression* value = 0;
            #line 667 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 668 "src/analyzer/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 670 "src/analyzer/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 671 "src/analyzer/Expression.pv"
                if (return_type == 0) {
                    #line 672 "src/analyzer/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 673 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 676 "src/analyzer/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 679 "src/analyzer/Expression.pv"
            if (value == 0) {
                #line 679 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 681 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 683 "src/analyzer/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 684 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 685 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 689 "src/analyzer/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 689 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 691 "src/analyzer/Expression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 691 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 693 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 695 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 697 "src/analyzer/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 698 "src/analyzer/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 699 "src/analyzer/Expression.pv"
            if (argument == 0) {
                #line 699 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 701 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 703 "src/analyzer/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 704 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 705 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 709 "src/analyzer/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 709 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 711 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 714 "src/analyzer/Expression.pv"
    return parent;
}

#line 717 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 718 "src/analyzer/Expression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 720 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 721 "src/analyzer/Expression.pv"
        struct Expression* placement = 0;
        #line 722 "src/analyzer/Expression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 723 "src/analyzer/Expression.pv"
            placement = Expression__parse(context, generics);
            #line 724 "src/analyzer/Expression.pv"
            if (placement == 0) {
                #line 724 "src/analyzer/Expression.pv"
                return 0;
            }
            #line 725 "src/analyzer/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 725 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 728 "src/analyzer/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 729 "src/analyzer/Expression.pv"
        if (expression == 0) {
            #line 729 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 731 "src/analyzer/Expression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 732 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { ._0 = placement, ._1 = expression} } }, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 734 "src/analyzer/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 735 "src/analyzer/Expression.pv"
        if (expression == 0) {
            #line 735 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 737 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 });
    }

    #line 740 "src/analyzer/Expression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 741 "src/analyzer/Expression.pv"
    return 0;
}

#line 744 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 745 "src/analyzer/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 745 "src/analyzer/Expression.pv"
        return false;
    }

    #line 747 "src/analyzer/Expression.pv"
    switch (inner->return_type.type) {
        #line 748 "src/analyzer/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 749 "src/analyzer/Expression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 750 "src/analyzer/Expression.pv"
        default: {
            #line 751 "src/analyzer/Expression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 752 "src/analyzer/Expression.pv"
            return 0;
        } break;
    }

    #line 756 "src/analyzer/Expression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 757 "src/analyzer/Expression.pv"
    if (member == 0) {
        #line 757 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 759 "src/analyzer/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 760 "src/analyzer/Expression.pv"
    if (member_type == 0) {
        #line 760 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 762 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 765 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 766 "src/analyzer/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 766 "src/analyzer/Expression.pv"
        return false;
    }

    #line 768 "src/analyzer/Expression.pv"
    struct Token* member_name = Context__current(context);
    #line 769 "src/analyzer/Expression.pv"
    if (member_name == 0) {
        #line 769 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 771 "src/analyzer/Expression.pv"
    if ((member_name->type != TOKEN_TYPE__NUMBER) && (member_name->type != TOKEN_TYPE__IDENTIFIER)) {
        #line 772 "src/analyzer/Expression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 775 "src/analyzer/Expression.pv"
    Context__next_token(context);

    #line 777 "src/analyzer/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 778 "src/analyzer/Expression.pv"
    if (member_type == 0) {
        #line 778 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 780 "src/analyzer/Expression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 781 "src/analyzer/Expression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) {};
    #line 782 "src/analyzer/Expression.pv"
    struct Function* func_info = 0;

    #line 784 "src/analyzer/Expression.pv"
    bool is_function = false;
    #line 785 "src/analyzer/Expression.pv"
    switch (member_type->type) {
        #line 786 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION: {
            #line 786 "src/analyzer/Expression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 787 "src/analyzer/Expression.pv"
            is_function = true;
            #line 788 "src/analyzer/Expression.pv"
            func_info = func_info2;
        } break;
        #line 790 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 790 "src/analyzer/Expression.pv"
            is_function = true;
        } break;
        #line 791 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 791 "src/analyzer/Expression.pv"
            is_function = true;
        } break;
        #line 792 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 795 "src/analyzer/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 796 "src/analyzer/Expression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 799 "src/analyzer/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 800 "src/analyzer/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 800 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 802 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 804 "src/analyzer/Expression.pv"
        if ((func_info != 0) && (func_info->parameters.length > 0) && str__eq(func_info->parameters.data[0].name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 805 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = inner });
        }

        #line 808 "src/analyzer/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 809 "src/analyzer/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 810 "src/analyzer/Expression.pv"
            if (argument == 0) {
                #line 810 "src/analyzer/Expression.pv"
                return 0;
            }
            #line 811 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 813 "src/analyzer/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 814 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 815 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 819 "src/analyzer/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 819 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 821 "src/analyzer/Expression.pv"
        if (func_info != 0 && func_info->generics.array.length > 0) {
            #line 822 "src/analyzer/Expression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 823 "src/analyzer/Expression.pv"
            member_type = Module__make_type_usage(context->module, member_type, &func_generics->array);
        }

        #line 826 "src/analyzer/Expression.pv"
        if ((func_info != 0) && ((func_info->type == FUNCTION_TYPE__BUILTIN) || (func_info->type == FUNCTION_TYPE__METHOD_CPP))) {
            #line 827 "src/analyzer/Expression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 828 "src/analyzer/Expression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 830 "src/analyzer/Expression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 833 "src/analyzer/Expression.pv"
        if (generic_map != 0) {
            #line 834 "src/analyzer/Expression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }

        #line 837 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
    }
}

#line 841 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 842 "src/analyzer/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
        #line 842 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 844 "src/analyzer/Expression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 845 "src/analyzer/Expression.pv"
    if (index_expr == 0) {
        #line 845 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 847 "src/analyzer/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]")) {
        #line 847 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 849 "src/analyzer/Expression.pv"
    switch (index_expr->data.type) {
        #line 850 "src/analyzer/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 850 "src/analyzer/Expression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 850 "src/analyzer/Expression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 851 "src/analyzer/Expression.pv"
            switch (target->return_type.type) {
                #line 852 "src/analyzer/Expression.pv"
                case TYPE__ENUM: {
                    #line 852 "src/analyzer/Expression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 853 "src/analyzer/Expression.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 854 "src/analyzer/Expression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        });

                        #line 860 "src/analyzer/Expression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 861 "src/analyzer/Expression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 863 "src/analyzer/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 865 "src/analyzer/Expression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, *index_expr->token);
                        #line 866 "src/analyzer/Expression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 867 "src/analyzer/Expression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 869 "src/analyzer/Expression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, *argument_name_data);
                        #line 870 "src/analyzer/Expression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 872 "src/analyzer/Expression.pv"
                        if (Expression__is_zero(start)) {
                            #line 873 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 874 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 876 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 881 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 887 "src/analyzer/Expression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence });
                        #line 888 "src/analyzer/Expression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 889 "src/analyzer/Expression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 892 "src/analyzer/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 895 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 898 "src/analyzer/Expression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 899 "src/analyzer/Expression.pv"
    struct Type* element_type = 0;

    #line 901 "src/analyzer/Expression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 902 "src/analyzer/Expression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 903 "src/analyzer/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 903 "src/analyzer/Expression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 904 "src/analyzer/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 906 "src/analyzer/Expression.pv"
            default: {
            } break;
        }
    } else {
        #line 909 "src/analyzer/Expression.pv"
        switch (inner_return_type->type) {
            #line 910 "src/analyzer/Expression.pv"
            case TYPE__INDIRECT: {
                #line 910 "src/analyzer/Expression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 911 "src/analyzer/Expression.pv"
                element_type = &indirect->to;
            } break;
            #line 913 "src/analyzer/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 913 "src/analyzer/Expression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 914 "src/analyzer/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 916 "src/analyzer/Expression.pv"
            default: {
            } break;
        }
    }

    #line 920 "src/analyzer/Expression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 921 "src/analyzer/Expression.pv"
        element_type = Type__to_ptr(&(struct Type) { .type = TYPE__UNKNOWN, .unknown_value = { ._0 = (struct str){ .ptr = "", .length = strlen("") }, ._1 = (struct Array_Type) {}} }, context->allocator);
    }

    #line 924 "src/analyzer/Expression.pv"
    if (element_type == 0) {
        #line 925 "src/analyzer/Expression.pv"
        Context__error_token(context, index_expr->token, "Type is not indexable");
        #line 926 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 929 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 932 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_inner(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 933 "src/analyzer/Expression.pv"
    struct Token* token = Context__current(context);
    #line 934 "src/analyzer/Expression.pv"
    struct Expression* result = 0;

    #line 936 "src/analyzer/Expression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 937 "src/analyzer/Expression.pv"
        result = Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 939 "src/analyzer/Expression.pv"
        result = Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 941 "src/analyzer/Expression.pv"
        result = Expression__parse_index_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "^") || Token__eq(token, TOKEN_TYPE__SYMBOL, "|") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "<<")) {
        #line 943 "src/analyzer/Expression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 944 "src/analyzer/Expression.pv"
        if (operator == 0) {
            #line 944 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 946 "src/analyzer/Expression.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 947 "src/analyzer/Expression.pv"
        if (value == 0) {
            #line 947 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 949 "src/analyzer/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = operator->value, ._2 = value} }, &inner->return_type);
    } else if (Type__is_function(Type__resolve_typedef_function(&inner->return_type)) && (Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, "("))) {
        #line 951 "src/analyzer/Expression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 952 "src/analyzer/Expression.pv"
            case TYPE__FUNCTION: {
                #line 952 "src/analyzer/Expression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 953 "src/analyzer/Expression.pv"
                struct Array_Type parsed_generics = (struct Array_Type) {};

                #line 955 "src/analyzer/Expression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                    #line 956 "src/analyzer/Expression.pv"
                    parsed_generics = Context__parse_generics(context, generics);
                }

                #line 959 "src/analyzer/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 959 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 961 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 963 "src/analyzer/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 964 "src/analyzer/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 965 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 967 "src/analyzer/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 968 "src/analyzer/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 969 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 973 "src/analyzer/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 973 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 975 "src/analyzer/Expression.pv"
                if (func_info->generics.array.length > 0) {
                    #line 976 "src/analyzer/Expression.pv"
                    struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                    #line 977 "src/analyzer/Expression.pv"
                    inner->return_type = *Module__make_type_usage(context->module, &inner->return_type, &func_generics->array);

                    #line 979 "src/analyzer/Expression.pv"
                    switch (inner->data.type) {
                        #line 980 "src/analyzer/Expression.pv"
                        case EXPRESSION_DATA__TYPE: {
                            #line 980 "src/analyzer/Expression.pv"
                            struct Type** type = &inner->data.type_value;
                            #line 981 "src/analyzer/Expression.pv"
                            *type = &inner->return_type;
                        } break;
                        #line 983 "src/analyzer/Expression.pv"
                        default: {
                        } break;
                    }
                }

                #line 987 "src/analyzer/Expression.pv"
                if (!Expression__validate_arguments(context, token, &inner->return_type, &arguments, 0, false)) {
                    #line 987 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 989 "src/analyzer/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 991 "src/analyzer/Expression.pv"
            case TYPE__FUNCTION_C: {
                #line 991 "src/analyzer/Expression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 992 "src/analyzer/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 992 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 994 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 996 "src/analyzer/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 997 "src/analyzer/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 998 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 1000 "src/analyzer/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1001 "src/analyzer/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 1002 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 1006 "src/analyzer/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 1006 "src/analyzer/Expression.pv"
                    return 0;
                }
                #line 1007 "src/analyzer/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 1009 "src/analyzer/Expression.pv"
            case TYPE__CLASS_CPP: {
                #line 1010 "src/analyzer/Expression.pv"
                struct Expression* expr = Expression__parse_class(context, token, inner, generics);
                #line 1011 "src/analyzer/Expression.pv"
                if (expr == 0) {
                    #line 1011 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1013 "src/analyzer/Expression.pv"
                return expr;
            } break;
            #line 1015 "src/analyzer/Expression.pv"
            default: {
                #line 1016 "src/analyzer/Expression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 1017 "src/analyzer/Expression.pv"
                return 0;
            } break;
        }
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "==") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!=") || Token__eq(token, TOKEN_TYPE__SYMBOL, "<=") || Token__eq(token, TOKEN_TYPE__SYMBOL, ">=") || Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, ">") || Token__eq(token, TOKEN_TYPE__SYMBOL, "||") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 1021 "src/analyzer/Expression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 1022 "src/analyzer/Expression.pv"
        if (operator == 0) {
            #line 1022 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1024 "src/analyzer/Expression.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 1025 "src/analyzer/Expression.pv"
        if (value == 0) {
            #line 1025 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1027 "src/analyzer/Expression.pv"
        if (!Token__eq(token, TOKEN_TYPE__SYMBOL, "||") && !Token__eq(token, TOKEN_TYPE__SYMBOL, "&&") && !Expression__validate_type(inner, context, &value->return_type, false)) {
            #line 1027 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1029 "src/analyzer/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = operator->value, ._2 = value} }, Type__to_ptr(&(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, "bool") }, context->allocator));
    } else {
        #line 1031 "src/analyzer/Expression.pv"
        return inner;
    }

    #line 1034 "src/analyzer/Expression.pv"
    if (result == 0) {
        #line 1034 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 1036 "src/analyzer/Expression.pv"
    return Expression__parse_inner(context, result, generics);
}

#line 1039 "src/analyzer/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 1040 "src/analyzer/Expression.pv"
    struct Token* token = Context__current(context);
    #line 1041 "src/analyzer/Expression.pv"
    enum TokenType token_type = token->type;
    #line 1042 "src/analyzer/Expression.pv"
    struct Expression* result = 0;

    #line 1044 "src/analyzer/Expression.pv"
    switch (token_type) {
        #line 1045 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 1046 "src/analyzer/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 1048 "src/analyzer/Expression.pv"
            if (context->module->mode_cpp && (str__eq(token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__eq(token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 1049 "src/analyzer/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 1051 "src/analyzer/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 1052 "src/analyzer/Expression.pv"
                if (type != 0) {
                    #line 1053 "src/analyzer/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 1054 "src/analyzer/Expression.pv"
                        case TYPE__ENUM: {
                            #line 1054 "src/analyzer/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 1055 "src/analyzer/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 1055 "src/analyzer/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 1056 "src/analyzer/Expression.pv"
                        case TYPE__SELF: {
                            #line 1056 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1057 "src/analyzer/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 1057 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1058 "src/analyzer/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 1058 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1059 "src/analyzer/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 1059 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1060 "src/analyzer/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 1060 "src/analyzer/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 1061 "src/analyzer/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 1061 "src/analyzer/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 1062 "src/analyzer/Expression.pv"
                        default: {
                            #line 1062 "src/analyzer/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 1065 "src/analyzer/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 1066 "src/analyzer/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                    });

                    #line 1071 "src/analyzer/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 1073 "src/analyzer/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 1074 "src/analyzer/Expression.pv"
                    return 0;
                }
            } else {
                #line 1077 "src/analyzer/Expression.pv"
                switch (return_type->type) {
                    #line 1078 "src/analyzer/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 1078 "src/analyzer/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 1079 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1080 "src/analyzer/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 1081 "src/analyzer/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) {};

                        #line 1083 "src/analyzer/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 1084 "src/analyzer/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 1087 "src/analyzer/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 1087 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1089 "src/analyzer/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1091 "src/analyzer/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1092 "src/analyzer/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1093 "src/analyzer/Expression.pv"
                            if (argument == 0) {
                                #line 1093 "src/analyzer/Expression.pv"
                                return 0;
                            }
                            #line 1094 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1096 "src/analyzer/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 1097 "src/analyzer/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1098 "src/analyzer/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1102 "src/analyzer/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1102 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1104 "src/analyzer/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 1105 "src/analyzer/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 1106 "src/analyzer/Expression.pv"
                            func_type = Module__make_type_usage(context->module, func_type, &func_generics->array);
                        }

                        #line 1109 "src/analyzer/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 1109 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1111 "src/analyzer/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 1112 "src/analyzer/Expression.pv"
                        switch (func_type->type) {
                            #line 1113 "src/analyzer/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 1113 "src/analyzer/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 1114 "src/analyzer/Expression.pv"
                                switch (func_info->type) {
                                    #line 1115 "src/analyzer/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 1116 "src/analyzer/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} });
                                    } break;
                                    #line 1118 "src/analyzer/Expression.pv"
                                    default: {
                                        #line 1119 "src/analyzer/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 1123 "src/analyzer/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 1126 "src/analyzer/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 1127 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 1129 "src/analyzer/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 1130 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1131 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1133 "src/analyzer/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 1134 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1135 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1137 "src/analyzer/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 1138 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1139 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1141 "src/analyzer/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 1142 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1143 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1145 "src/analyzer/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 1146 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1147 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1149 "src/analyzer/Expression.pv"
                    case TYPE__ENUM: {
                        #line 1150 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1151 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1153 "src/analyzer/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 1154 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1155 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1157 "src/analyzer/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 1158 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1159 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1161 "src/analyzer/Expression.pv"
                    case TYPE__SELF: {
                        #line 1162 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1163 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1165 "src/analyzer/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 1166 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1167 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1169 "src/analyzer/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 1170 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1171 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1173 "src/analyzer/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 1174 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1175 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1177 "src/analyzer/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 1178 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1179 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1181 "src/analyzer/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 1182 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1183 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1185 "src/analyzer/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 1185 "src/analyzer/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 1186 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1187 "src/analyzer/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 1187 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1189 "src/analyzer/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1191 "src/analyzer/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1192 "src/analyzer/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1193 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1195 "src/analyzer/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 1196 "src/analyzer/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1197 "src/analyzer/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1201 "src/analyzer/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1201 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1203 "src/analyzer/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 1205 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, &func_info->return_type);
                    } break;
                    #line 1207 "src/analyzer/Expression.pv"
                    default: {
                        #line 1208 "src/analyzer/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 1213 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 1214 "src/analyzer/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char },
            });
        } break;
        #line 1220 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 1221 "src/analyzer/Expression.pv"
            char const* primitive = "i32";

            #line 1223 "src/analyzer/Expression.pv"
            if (str__ends_with(token->value, "f")) {
                #line 1224 "src/analyzer/Expression.pv"
                primitive = "f32";
            } else if (str__contains(token->value, ".")) {
                #line 1226 "src/analyzer/Expression.pv"
                primitive = "f64";
            }

            #line 1229 "src/analyzer/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 1235 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 1236 "src/analyzer/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 1237 "src/analyzer/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 1238 "src/analyzer/Expression.pv"
                if (operator == 0) {
                    #line 1238 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1240 "src/analyzer/Expression.pv"
                if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 1241 "src/analyzer/Expression.pv"
                    context->pos -= 1;
                    #line 1242 "src/analyzer/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 1243 "src/analyzer/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 1245 "src/analyzer/Expression.pv"
                    struct Expression* child = Expression__parse(context, generics);
                    #line 1246 "src/analyzer/Expression.pv"
                    if (child == 0) {
                        #line 1246 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 1248 "src/analyzer/Expression.pv"
                    if (str__eq(operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 1249 "src/analyzer/Expression.pv"
                        switch (child->data.type) {
                            #line 1250 "src/analyzer/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1250 "src/analyzer/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1251 "src/analyzer/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) });
                                #line 1252 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1254 "src/analyzer/Expression.pv"
                            default: {
                                #line 1255 "src/analyzer/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 1256 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 1260 "src/analyzer/Expression.pv"
                        switch (child->data.type) {
                            #line 1261 "src/analyzer/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1261 "src/analyzer/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1262 "src/analyzer/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 1263 "src/analyzer/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect });
                                #line 1264 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1266 "src/analyzer/Expression.pv"
                            default: {
                                #line 1266 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 1269 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 1273 "src/analyzer/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 1273 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1275 "src/analyzer/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 1276 "src/analyzer/Expression.pv"
                if (expr == 0) {
                    #line 1276 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1278 "src/analyzer/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 1279 "src/analyzer/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 1281 "src/analyzer/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, *expr->token);
                    #line 1282 "src/analyzer/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 1284 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 1286 "src/analyzer/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1287 "src/analyzer/Expression.pv"
                        struct String name_string = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 1288 "src/analyzer/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 1289 "src/analyzer/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 1291 "src/analyzer/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, *Context__current(context));
                        #line 1292 "src/analyzer/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 1294 "src/analyzer/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 1295 "src/analyzer/Expression.pv"
                        if (value == 0) {
                            #line 1295 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1297 "src/analyzer/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 1299 "src/analyzer/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1300 "src/analyzer/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 1301 "src/analyzer/Expression.pv"
                            return 0;
                        }
                    }

                    #line 1305 "src/analyzer/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple) {});
                    #line 1306 "src/analyzer/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 1307 "src/analyzer/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 1307 "src/analyzer/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1307 "src/analyzer/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1307 "src/analyzer/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1308 "src/analyzer/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 1311 "src/analyzer/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }), arguments, 0);
                } else {
                    #line 1313 "src/analyzer/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1313 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 1315 "src/analyzer/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 1318 "src/analyzer/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
                    #line 1318 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1320 "src/analyzer/Expression.pv"
                struct Type* element_type = 0;
                #line 1321 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 1323 "src/analyzer/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 1324 "src/analyzer/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 1325 "src/analyzer/Expression.pv"
                    if (element == 0) {
                        #line 1325 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 1327 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .value = element });

                    #line 1329 "src/analyzer/Expression.pv"
                    if (element_type == 0) {
                        #line 1330 "src/analyzer/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 1333 "src/analyzer/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 1334 "src/analyzer/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 1335 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 1339 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 1341 "src/analyzer/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = elements.length }, .element = *element_type });
                #line 1342 "src/analyzer/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence });
                #line 1343 "src/analyzer/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 1345 "src/analyzer/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 1347 "src/analyzer/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 1350 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 1351 "src/analyzer/Expression.pv"
            if (str__eq(token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__eq(token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 1352 "src/analyzer/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, "bool") },
                });
            } else {
                #line 1358 "src/analyzer/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 1361 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 1362 "src/analyzer/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 1366 "src/analyzer/Expression.pv"
    if (result == 0) {
        #line 1366 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 1368 "src/analyzer/Expression.pv"
    result = Expression__parse_inner(context, result, generics);

    #line 1370 "src/analyzer/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 1371 "src/analyzer/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 1373 "src/analyzer/Expression.pv"
        struct Expression* range_start = result;
        #line 1374 "src/analyzer/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 1375 "src/analyzer/Expression.pv"
        if (range_end == 0) {
            #line 1375 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1377 "src/analyzer/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, &(struct Array_Type) { .data = &range_end->return_type, .length = 1 });
        #line 1378 "src/analyzer/Expression.pv"
        if (enum_type == 0) {
            #line 1379 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 1380 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1383 "src/analyzer/Expression.pv"
        struct Token variant_name = *token;
        #line 1384 "src/analyzer/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 1385 "src/analyzer/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 1387 "src/analyzer/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 1388 "src/analyzer/Expression.pv"
        struct EnumVariant* variant = 0;
        #line 1389 "src/analyzer/Expression.pv"
        switch (variant_result.type) {
            #line 1390 "src/analyzer/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 1390 "src/analyzer/Expression.pv"
                struct EnumVariant* enum_variant = variant_result.enumvariant_value;
                #line 1390 "src/analyzer/Expression.pv"
                variant = enum_variant;
            } break;
            #line 1391 "src/analyzer/Expression.pv"
            default: {
            } break;
        }
        #line 1393 "src/analyzer/Expression.pv"
        if (variant == 0) {
            #line 1394 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Could not find Range StartEnd enum variant");
            #line 1395 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1398 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1399 "src/analyzer/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_start });
        #line 1400 "src/analyzer/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_end });

        #line 1402 "src/analyzer/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 1404 "src/analyzer/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 1407 "src/analyzer/Expression.pv"
    return result;
}

#line 1410 "src/analyzer/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 1411 "src/analyzer/Expression.pv"
    switch (self->data.type) {
        #line 1412 "src/analyzer/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1412 "src/analyzer/Expression.pv"
            struct str value = self->data.literal_value;
            #line 1412 "src/analyzer/Expression.pv"
            return str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 1413 "src/analyzer/Expression.pv"
        default: {
            #line 1413 "src/analyzer/Expression.pv"
            return false;
        } break;
    }
}

#line 1417 "src/analyzer/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast) {
    #line 1418 "src/analyzer/Expression.pv"
    bool success = true;

    #line 1420 "src/analyzer/Expression.pv"
    switch (self->data.type) {
        #line 1421 "src/analyzer/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1421 "src/analyzer/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 1421 "src/analyzer/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 1422 "src/analyzer/Expression.pv"
            switch (type->type) {
                #line 1423 "src/analyzer/Expression.pv"
                case TYPE__TUPLE: {
                    #line 1423 "src/analyzer/Expression.pv"
                    struct Tuple* tuple = type->tuple_value;
                    #line 1424 "src/analyzer/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 1424 "src/analyzer/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1424 "src/analyzer/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1424 "src/analyzer/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1425 "src/analyzer/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i], apply_implicit_cast) && success;
                    } }

                    #line 1428 "src/analyzer/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type };
                    #line 1429 "src/analyzer/Expression.pv"
                    invoke->return_type = *type;
                    #line 1430 "src/analyzer/Expression.pv"
                    self->return_type = *type;

                    #line 1432 "src/analyzer/Expression.pv"
                    return success;
                } break;
                #line 1434 "src/analyzer/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 1437 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 1440 "src/analyzer/Expression.pv"
    if (apply_implicit_cast && Type__needs_implicit_cast(type, &self->return_type)) {
        #line 1441 "src/analyzer/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, *self);
        #line 1442 "src/analyzer/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 1443 "src/analyzer/Expression.pv"
        self->return_type = *type;
        #line 1444 "src/analyzer/Expression.pv"
        return true;
    }

    #line 1447 "src/analyzer/Expression.pv"
    if (!Type__eq(type, &self->return_type)) {
        #line 1448 "src/analyzer/Expression.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1449 "src/analyzer/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
        #line 1450 "src/analyzer/Expression.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 1451 "src/analyzer/Expression.pv"
        String__append(&message, String__as_str(&type_name));
        #line 1452 "src/analyzer/Expression.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 1453 "src/analyzer/Expression.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 1454 "src/analyzer/Expression.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 1455 "src/analyzer/Expression.pv"
        Context__error_token(context, self->token, String__c_str(&message));
        #line 1456 "src/analyzer/Expression.pv"
        return false;
    }

    #line 1459 "src/analyzer/Expression.pv"
    self->return_type = *type;
    #line 1460 "src/analyzer/Expression.pv"
    return true;
}
