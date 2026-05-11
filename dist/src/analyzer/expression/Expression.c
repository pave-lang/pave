#include <stdint.h>
#include <string.h>

#include <stdlib.h>

#include <stdlib.h>
#include <analyzer/expression/Expression.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/EnumVariant.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/types/Enum.h>
#include <std/str.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/types/Function.h>
#include <analyzer/Impl.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/types/Struct.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <analyzer/ImplConst.h>
#include <analyzer/Root.h>
#include <analyzer/types/FunctionParent.h>
#include <std/trait_Allocator.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/types/Trait.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/StructCField.h>
#include <std/HashMap_str_StructCField.h>
#include <analyzer/c/StructC.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/c/ClassCpp.h>
#include <std/Array_Type.h>
#include <std/Iter_ref_Type.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/types/Generic.h>
#include <std/Iter_ref_ref_Trait.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/types/Generics.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/Iter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/FunctionType.h>
#include <std/String.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Array_Generic.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/Module.h>
#include <analyzer/c/UnknownC.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/Naming.h>
#include <analyzer/expression/Expression.h>

#include <analyzer/expression/Expression.h>

#line 15 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type) {
    #line 16 "src/analyzer/expression/Expression.pv"
    return ArenaAllocator__store_Expression(allocator, &(struct Expression) {
        .token = token,
        .data = data,
        .return_type = *return_type,
    });
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
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token) {
    #line 32 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 33 "src/analyzer/expression/Expression.pv"
        case TYPE__INDIRECT: {
            #line 33 "src/analyzer/expression/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 34 "src/analyzer/expression/Expression.pv"
            return Expression__get_enum_variant(context, &indirect->to, token);
        } break;
        #line 36 "src/analyzer/expression/Expression.pv"
        case TYPE__SELF: {
            #line 37 "src/analyzer/expression/Expression.pv"
            return Expression__get_enum_variant(context, context->type_self, token);
        } break;
        #line 39 "src/analyzer/expression/Expression.pv"
        case TYPE__ENUM: {
            #line 39 "src/analyzer/expression/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 39 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 40 "src/analyzer/expression/Expression.pv"
            struct EnumVariant* variant = HashMap_str_EnumVariant__find(&enum_info->variants, &token->value);
            #line 41 "src/analyzer/expression/Expression.pv"
            if (variant != 0) {
                #line 42 "src/analyzer/expression/Expression.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_VARIANT, .enumvariant_value = variant };
            }

            #line 45 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 45 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 45 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 46 "src/analyzer/expression/Expression.pv"
                struct Function* function = Impl__find_function(impl_info, token->value);
                #line 47 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 48 "src/analyzer/expression/Expression.pv"
                    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} };
                }
            } }

            #line 52 "src/analyzer/expression/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
        #line 54 "src/analyzer/expression/Expression.pv"
        case TYPE__ENUM_C: {
            #line 54 "src/analyzer/expression/Expression.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 55 "src/analyzer/expression/Expression.pv"
            struct EnumCValue* variant = HashMap_str_EnumCValue__find(&enum_info->values, &token->value);
            #line 56 "src/analyzer/expression/Expression.pv"
            if (variant == 0) {
                #line 57 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, "Variant not found in enum");
                #line 58 "src/analyzer/expression/Expression.pv"
                return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
            }

            #line 61 "src/analyzer/expression/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__ENUM_CVALUE, .enumcvalue_value = variant };
        } break;
        #line 63 "src/analyzer/expression/Expression.pv"
        default: {
            #line 63 "src/analyzer/expression/Expression.pv"
            return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
        } break;
    }

    #line 66 "src/analyzer/expression/Expression.pv"
    return (struct EnumVariantResult) { .type = ENUM_VARIANT_RESULT__NONE };
}

#line 69 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error) {
    #line 70 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 71 "src/analyzer/expression/Expression.pv"
        case TYPE__INDIRECT: {
            #line 71 "src/analyzer/expression/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 72 "src/analyzer/expression/Expression.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 74 "src/analyzer/expression/Expression.pv"
        case TYPE__SELF: {
            #line 75 "src/analyzer/expression/Expression.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 77 "src/analyzer/expression/Expression.pv"
        case TYPE__PRIMITIVE: {
            #line 77 "src/analyzer/expression/Expression.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 78 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 78 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 78 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 79 "src/analyzer/expression/Expression.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 80 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 81 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &(struct GenericMap) { .self_type = type })} });
                }
            } }

            #line 85 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 85 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 86 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 88 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT: {
            #line 88 "src/analyzer/expression/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 88 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 89 "src/analyzer/expression/Expression.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 90 "src/analyzer/expression/Expression.pv"
            if (field != 0) {
                #line 91 "src/analyzer/expression/Expression.pv"
                return &field->type;
            }

            #line 94 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 94 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 94 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 95 "src/analyzer/expression/Expression.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 96 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 97 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 101 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 101 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 101 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 102 "src/analyzer/expression/Expression.pv"
                struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member->value);
                #line 103 "src/analyzer/expression/Expression.pv"
                if (impl_const_ptr != 0) {
                    #line 104 "src/analyzer/expression/Expression.pv"
                    struct ImplConst* impl_const = *impl_const_ptr;
                    #line 105 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, &impl_const->type);
                }
            } }

            #line 109 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 110 "src/analyzer/expression/Expression.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 112 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 114 "src/analyzer/expression/Expression.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 114 "src/analyzer/expression/Expression.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 114 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 115 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 116 "src/analyzer/expression/Expression.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, &context->root->func_next);
                #line 117 "src/analyzer/expression/Expression.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 118 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} });
            }

            #line 121 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 122 "src/analyzer/expression/Expression.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, &context->root->func_value);
                #line 123 "src/analyzer/expression/Expression.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 124 "src/analyzer/expression/Expression.pv"
                func_value->return_type = func_info->return_type;
                #line 125 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} });
            }

            #line 128 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 128 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 129 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 131 "src/analyzer/expression/Expression.pv"
        case TYPE__ENUM: {
            #line 131 "src/analyzer/expression/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 131 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 132 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 132 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 132 "src/analyzer/expression/Expression.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 133 "src/analyzer/expression/Expression.pv"
                struct Function* function = Impl__find_function(impl_info, member->value);
                #line 134 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 135 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 139 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 139 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 140 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 142 "src/analyzer/expression/Expression.pv"
        case TYPE__TRAIT: {
            #line 142 "src/analyzer/expression/Expression.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 142 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 143 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 144 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) });
            }

            #line 147 "src/analyzer/expression/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 148 "src/analyzer/expression/Expression.pv"
            if (function == 0) {
                #line 149 "src/analyzer/expression/Expression.pv"
                if (output_error) {
                    #line 149 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 150 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 153 "src/analyzer/expression/Expression.pv"
            return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
        } break;
        #line 155 "src/analyzer/expression/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 155 "src/analyzer/expression/Expression.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 156 "src/analyzer/expression/Expression.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 158 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 158 "src/analyzer/expression/Expression.pv"
            struct StructC* struct_info = type->structc_value;
            #line 159 "src/analyzer/expression/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 160 "src/analyzer/expression/Expression.pv"
            if (field != 0) {
                #line 160 "src/analyzer/expression/Expression.pv"
                return &field->type;
            }

            #line 162 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 162 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 163 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 165 "src/analyzer/expression/Expression.pv"
        case TYPE__UNION_C: {
            #line 165 "src/analyzer/expression/Expression.pv"
            struct StructC* union_info = type->unionc_value;
            #line 166 "src/analyzer/expression/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 167 "src/analyzer/expression/Expression.pv"
            if (field != 0) {
                #line 167 "src/analyzer/expression/Expression.pv"
                return &field->type;
            }

            #line 169 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 169 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 170 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 172 "src/analyzer/expression/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 172 "src/analyzer/expression/Expression.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 173 "src/analyzer/expression/Expression.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 174 "src/analyzer/expression/Expression.pv"
            if (field_type != 0) {
                #line 174 "src/analyzer/expression/Expression.pv"
                return field_type;
            }

            #line 176 "src/analyzer/expression/Expression.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 177 "src/analyzer/expression/Expression.pv"
            if (value_type != 0) {
                #line 177 "src/analyzer/expression/Expression.pv"
                return value_type;
            }

            #line 179 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 179 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 179 "src/analyzer/expression/Expression.pv"
                struct Type* base = Iter_ref_Type__value(&__iter);

                #line 180 "src/analyzer/expression/Expression.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 181 "src/analyzer/expression/Expression.pv"
                if (base_type != 0) {
                    #line 181 "src/analyzer/expression/Expression.pv"
                    return base_type;
                }
            } }

            #line 184 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 184 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 185 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 187 "src/analyzer/expression/Expression.pv"
        case TYPE__GENERIC: {
            #line 187 "src/analyzer/expression/Expression.pv"
            struct Generic* generic = type->generic_value;
            #line 188 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
            #line 188 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_ref_Trait__next(&__iter)) {
                #line 188 "src/analyzer/expression/Expression.pv"
                struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

                #line 189 "src/analyzer/expression/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 190 "src/analyzer/expression/Expression.pv"
                if (function != 0) {
                    #line 191 "src/analyzer/expression/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &(struct GenericMap) {})} });
                }
            } }

            #line 195 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 195 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 196 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 198 "src/analyzer/expression/Expression.pv"
        case TYPE__SEQUENCE: {
            #line 198 "src/analyzer/expression/Expression.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 199 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 200 "src/analyzer/expression/Expression.pv"
                return &sequence->element_pointer;
            }

            #line 203 "src/analyzer/expression/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 204 "src/analyzer/expression/Expression.pv"
                return &context->root->type_usize;
            }

            #line 207 "src/analyzer/expression/Expression.pv"
            struct Impl* impl_info = context->root->hack_type_impl->impl_info;

            #line 209 "src/analyzer/expression/Expression.pv"
            struct Function* function = Impl__find_function(impl_info, member->value);
            #line 210 "src/analyzer/expression/Expression.pv"
            if (function != 0) {
                #line 211 "src/analyzer/expression/Expression.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, &(struct Generics) {}, &(struct Array_Type) {});
                #line 212 "src/analyzer/expression/Expression.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 213 "src/analyzer/expression/Expression.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) });

                #line 215 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &generic_map)} });
            }

            #line 218 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 218 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 219 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 221 "src/analyzer/expression/Expression.pv"
        case TYPE__TUPLE: {
            #line 221 "src/analyzer/expression/Expression.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 222 "src/analyzer/expression/Expression.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 223 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 224 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 227 "src/analyzer/expression/Expression.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 228 "src/analyzer/expression/Expression.pv"
            if (index >= tuple->elements.length) {
                #line 229 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 230 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 233 "src/analyzer/expression/Expression.pv"
            return &tuple->elements.data[index];
        } break;
        #line 235 "src/analyzer/expression/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 235 "src/analyzer/expression/Expression.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 236 "src/analyzer/expression/Expression.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 237 "src/analyzer/expression/Expression.pv"
            if (type != 0) {
                #line 237 "src/analyzer/expression/Expression.pv"
                return type;
            }

            #line 239 "src/analyzer/expression/Expression.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 240 "src/analyzer/expression/Expression.pv"
            if (value != 0) {
                #line 240 "src/analyzer/expression/Expression.pv"
                return value;
            }

            #line 242 "src/analyzer/expression/Expression.pv"
            if (output_error) {
                #line 242 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 244 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
        #line 246 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN_C: {
            #line 246 "src/analyzer/expression/Expression.pv"
            return type;
        } break;
        #line 247 "src/analyzer/expression/Expression.pv"
        default: {
            #line 247 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 250 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 253 "src/analyzer/expression/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments) {
    #line 254 "src/analyzer/expression/Expression.pv"
    struct GenericMap generic_map = GenericMap__from_generics(context->allocator, &func_info->generics);

    #line 256 "src/analyzer/expression/Expression.pv"
    uintptr_t i = 0;
    #line 257 "src/analyzer/expression/Expression.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(generics);
    #line 257 "src/analyzer/expression/Expression.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 257 "src/analyzer/expression/Expression.pv"
        struct Type* generic = Iter_ref_Type__value(&__iter);

        #line 258 "src/analyzer/expression/Expression.pv"
        struct Type* target = Array_Type__get(&generic_map.array, i);
        #line 259 "src/analyzer/expression/Expression.pv"
        if (target != 0) {
            #line 259 "src/analyzer/expression/Expression.pv"
            *target = *generic;
        }
        #line 260 "src/analyzer/expression/Expression.pv"
        i += 1;
    } }

    #line 263 "src/analyzer/expression/Expression.pv"
    if (i == generic_map.array.length) {
        #line 264 "src/analyzer/expression/Expression.pv"
        return ArenaAllocator__store_GenericMap(context->allocator, &generic_map);
    }

    #line 267 "src/analyzer/expression/Expression.pv"
    struct Iter_ref_Parameter params = Array_Parameter__iter(&func_info->parameters);
    #line 268 "src/analyzer/expression/Expression.pv"
    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);

    #line 270 "src/analyzer/expression/Expression.pv"
    while (Iter_ref_Parameter__next(&params) && Iter_ref_InvokeArgument__next(&args)) {
        #line 271 "src/analyzer/expression/Expression.pv"
        struct Type* param_type = &Iter_ref_Parameter__value(&params)->type;
        #line 272 "src/analyzer/expression/Expression.pv"
        struct Type* arg_type = &Iter_ref_InvokeArgument__value(&args)->value->return_type;

        #line 274 "src/analyzer/expression/Expression.pv"
        Expression__resolve_generic_type(context, param_type, arg_type, &generic_map);
    }

    #line 277 "src/analyzer/expression/Expression.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, &generic_map);
}

#line 280 "src/analyzer/expression/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 281 "src/analyzer/expression/Expression.pv"
    switch (param_type->type) {
        #line 282 "src/analyzer/expression/Expression.pv"
        case TYPE__GENERIC: {
            #line 282 "src/analyzer/expression/Expression.pv"
            struct Generic* generic = param_type->generic_value;
            #line 283 "src/analyzer/expression/Expression.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 284 "src/analyzer/expression/Expression.pv"
            if (generic_type != 0) {
                #line 284 "src/analyzer/expression/Expression.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 286 "src/analyzer/expression/Expression.pv"
        case TYPE__INDIRECT: {
            #line 286 "src/analyzer/expression/Expression.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 287 "src/analyzer/expression/Expression.pv"
            switch (arg_type->type) {
                #line 288 "src/analyzer/expression/Expression.pv"
                case TYPE__INDIRECT: {
                    #line 288 "src/analyzer/expression/Expression.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 289 "src/analyzer/expression/Expression.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 291 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 294 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }
}

#line 298 "src/analyzer/expression/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call) {
    #line 299 "src/analyzer/expression/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 301 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 302 "src/analyzer/expression/Expression.pv"
        case TYPE__SELF: {
            #line 302 "src/analyzer/expression/Expression.pv"
            {
                #line 302 "src/analyzer/expression/Expression.pv"
                type = context->type_self;
            }
        } break;
        #line 303 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 306 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 307 "src/analyzer/expression/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 307 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 308 "src/analyzer/expression/Expression.pv"
        case TYPE__UNION_C: {
            #line 308 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 309 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 309 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 310 "src/analyzer/expression/Expression.pv"
        case TYPE__TUPLE: {
            #line 310 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 311 "src/analyzer/expression/Expression.pv"
        case TYPE__STRUCT: {
            #line 311 "src/analyzer/expression/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 311 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 312 "src/analyzer/expression/Expression.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 312 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 312 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 313 "src/analyzer/expression/Expression.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg->name->value);

                #line 315 "src/analyzer/expression/Expression.pv"
                if (param == 0) {
                    #line 316 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, arg->name, "Unable to find field in struct");
                    #line 317 "src/analyzer/expression/Expression.pv"
                    return false;
                }

                #line 320 "src/analyzer/expression/Expression.pv"
                struct Type* param_type = &param->type;

                #line 322 "src/analyzer/expression/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 323 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 325 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 328 "src/analyzer/expression/Expression.pv"
                if (param_type == 0) {
                    #line 329 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve field type");
                    #line 330 "src/analyzer/expression/Expression.pv"
                    return false;
                }

                #line 333 "src/analyzer/expression/Expression.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            } }

            #line 336 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 338 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 338 "src/analyzer/expression/Expression.pv"
            struct Function* function = type->function_value._0;
            #line 338 "src/analyzer/expression/Expression.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 339 "src/analyzer/expression/Expression.pv"
            if (function == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 339 "src/analyzer/expression/Expression.pv"
                return true;
            }

            #line 341 "src/analyzer/expression/Expression.pv"
            if (function->parameters.length != arguments_length) {
                #line 342 "src/analyzer/expression/Expression.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 343 "src/analyzer/expression/Expression.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 345 "src/analyzer/expression/Expression.pv"
                if (is_member_call) {
                    #line 346 "src/analyzer/expression/Expression.pv"
                    String__append_usize(&message, function->parameters.length - 1);
                } else {
                    #line 348 "src/analyzer/expression/Expression.pv"
                    String__append_usize(&message, function->parameters.length);
                }

                #line 351 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 352 "src/analyzer/expression/Expression.pv"
                return false;
            }

            #line 355 "src/analyzer/expression/Expression.pv"
            struct Iter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 356 "src/analyzer/expression/Expression.pv"
            struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

            #line 358 "src/analyzer/expression/Expression.pv"
            if (is_member_call) {
                #line 359 "src/analyzer/expression/Expression.pv"
                Iter_ref_Parameter__next(&param_iter);
                #line 360 "src/analyzer/expression/Expression.pv"
                Iter_ref_InvokeArgument__next(&args_iter);

                #line 362 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 363 "src/analyzer/expression/Expression.pv"
                struct Type* param_type = &Iter_ref_Parameter__value(&param_iter)->type;

                #line 365 "src/analyzer/expression/Expression.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 366 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) });
                    #line 367 "src/analyzer/expression/Expression.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 371 "src/analyzer/expression/Expression.pv"
            while (Iter_ref_Parameter__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
                #line 372 "src/analyzer/expression/Expression.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
                #line 373 "src/analyzer/expression/Expression.pv"
                struct Parameter* param = Iter_ref_Parameter__value(&param_iter);
                #line 374 "src/analyzer/expression/Expression.pv"
                struct Type* param_type = &param->type;

                #line 376 "src/analyzer/expression/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 377 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 379 "src/analyzer/expression/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 382 "src/analyzer/expression/Expression.pv"
                if (param_type == 0) {
                    #line 383 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
                    #line 384 "src/analyzer/expression/Expression.pv"
                    return false;
                }

                #line 387 "src/analyzer/expression/Expression.pv"
                Expression__validate_type(arg->value, context, param_type, true);
            }

            #line 390 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 392 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 392 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 393 "src/analyzer/expression/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 393 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 394 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN_C: {
            #line 394 "src/analyzer/expression/Expression.pv"
            return true;
        } break;
        #line 395 "src/analyzer/expression/Expression.pv"
        default: {
            #line 395 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 398 "src/analyzer/expression/Expression.pv"
    return false;
}

#line 401 "src/analyzer/expression/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 402 "src/analyzer/expression/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 404 "src/analyzer/expression/Expression.pv"
    if (variant->types.length != arguments_length) {
        #line 405 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 406 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 407 "src/analyzer/expression/Expression.pv"
        String__append_usize(&message, variant->types.length);
        #line 408 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 409 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 412 "src/analyzer/expression/Expression.pv"
    struct Iter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 413 "src/analyzer/expression/Expression.pv"
    struct Iter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 415 "src/analyzer/expression/Expression.pv"
    while (Iter_ref_Type__next(&param_iter) && Iter_ref_InvokeArgument__next(&args_iter)) {
        #line 416 "src/analyzer/expression/Expression.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args_iter);
        #line 417 "src/analyzer/expression/Expression.pv"
        struct Type* param_type = Iter_ref_Type__value(&param_iter);

        #line 419 "src/analyzer/expression/Expression.pv"
        if (generic_map != 0) {
            #line 420 "src/analyzer/expression/Expression.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 423 "src/analyzer/expression/Expression.pv"
        if (param_type == 0) {
            #line 424 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
            #line 425 "src/analyzer/expression/Expression.pv"
            return false;
        }

        #line 428 "src/analyzer/expression/Expression.pv"
        Expression__validate_type(arg->value, context, param_type, true);
    }

    #line 431 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 434 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 435 "src/analyzer/expression/Expression.pv"
    switch (type->type) {
        #line 436 "src/analyzer/expression/Expression.pv"
        case TYPE__TUPLE: {
            #line 436 "src/analyzer/expression/Expression.pv"
            return type;
        } break;
        #line 437 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 437 "src/analyzer/expression/Expression.pv"
            struct Function* func_info = type->function_value._0;
            #line 437 "src/analyzer/expression/Expression.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 438 "src/analyzer/expression/Expression.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 439 "src/analyzer/expression/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} });
            }
            #line 441 "src/analyzer/expression/Expression.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 443 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 443 "src/analyzer/expression/Expression.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 443 "src/analyzer/expression/Expression.pv"
            return &func_info->return_type;
        } break;
        #line 444 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN_C: {
            #line 444 "src/analyzer/expression/Expression.pv"
            return type;
        } break;
        #line 445 "src/analyzer/expression/Expression.pv"
        default: {
            #line 445 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 448 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 451 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 452 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 452 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 454 "src/analyzer/expression/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 455 "src/analyzer/expression/Expression.pv"
    if (func_return_type == 0) {
        #line 455 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 457 "src/analyzer/expression/Expression.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 458 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 461 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 462 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 462 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 464 "src/analyzer/expression/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 465 "src/analyzer/expression/Expression.pv"
    if (func_return_type == 0) {
        #line 465 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 467 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, func_return_type);
}

#line 470 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics) {
    #line 471 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 472 "src/analyzer/expression/Expression.pv"
        struct Token* variant_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 473 "src/analyzer/expression/Expression.pv"
        if (variant_name == 0) {
            #line 473 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 475 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, variant_name);

        #line 477 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 478 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__NONE: {
                #line 479 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, variant_name, "Unable to find enum variant or function");
                #line 480 "src/analyzer/expression/Expression.pv"
                return 0;
            } break;
            #line 482 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__FUNCTION: {
                #line 482 "src/analyzer/expression/Expression.pv"
                struct Function* function = variant_result.function_value._0;
                #line 482 "src/analyzer/expression/Expression.pv"
                struct GenericMap* generic_map = variant_result.function_value._1;
                #line 483 "src/analyzer/expression/Expression.pv"
                struct Type* member_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });

                #line 485 "src/analyzer/expression/Expression.pv"
                if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 486 "src/analyzer/expression/Expression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                }

                #line 489 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 489 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 491 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 493 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 494 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 495 "src/analyzer/expression/Expression.pv"
                    if (argument == 0) {
                        #line 495 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 497 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 499 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 500 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 501 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 505 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 505 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 507 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                    #line 507 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 509 "src/analyzer/expression/Expression.pv"
                struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
                #line 510 "src/analyzer/expression/Expression.pv"
                if (func_return_type == 0) {
                    #line 510 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 512 "src/analyzer/expression/Expression.pv"
                struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                #line 513 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
            } break;
            #line 515 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 515 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* variant = variant_result.enumvariant_value;
                #line 516 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 518 "src/analyzer/expression/Expression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 519 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                        #line 519 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 521 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 522 "src/analyzer/expression/Expression.pv"
                        struct Expression* argument = Expression__parse(context, generics);
                        #line 523 "src/analyzer/expression/Expression.pv"
                        if (argument == 0) {
                            #line 523 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 525 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                        #line 527 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 528 "src/analyzer/expression/Expression.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                            #line 529 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 533 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 533 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 537 "src/analyzer/expression/Expression.pv"
                struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

                #line 539 "src/analyzer/expression/Expression.pv"
                struct GenericMap* generic_map = Type__get_generic_map(enum_type, context);
                #line 540 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_enum_arguments(context, token, variant, &arguments, generic_map)) {
                    #line 540 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 542 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
            } break;
            #line 544 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                #line 545 "src/analyzer/expression/Expression.pv"
                struct Expression* enum_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
                #line 546 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, variant_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = enum_expr, ._1 = variant_name->value} }, enum_type);
            } break;
        }
    }

    #line 561 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 564 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 565 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 566 "src/analyzer/expression/Expression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 567 "src/analyzer/expression/Expression.pv"
        if (member == 0) {
            #line 567 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 569 "src/analyzer/expression/Expression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 570 "src/analyzer/expression/Expression.pv"
        if (member_type == 0) {
            #line 570 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 572 "src/analyzer/expression/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 574 "src/analyzer/expression/Expression.pv"
        if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 575 "src/analyzer/expression/Expression.pv"
            switch (member_type->type) {
                #line 576 "src/analyzer/expression/Expression.pv"
                case TYPE__FUNCTION: {
                    #line 577 "src/analyzer/expression/Expression.pv"
                    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
                } break;
                #line 579 "src/analyzer/expression/Expression.pv"
                default: {
                    #line 580 "src/analyzer/expression/Expression.pv"
                    struct Expression* struct_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
                    #line 581 "src/analyzer/expression/Expression.pv"
                    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = struct_expr, ._1 = member->value} }, member_type);
                } break;
            }
        } else {
            #line 585 "src/analyzer/expression/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 585 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 587 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 589 "src/analyzer/expression/Expression.pv"
            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 590 "src/analyzer/expression/Expression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 591 "src/analyzer/expression/Expression.pv"
                if (argument == 0) {
                    #line 591 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 593 "src/analyzer/expression/Expression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                #line 595 "src/analyzer/expression/Expression.pv"
                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 596 "src/analyzer/expression/Expression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 597 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            }

            #line 601 "src/analyzer/expression/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 601 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 603 "src/analyzer/expression/Expression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 603 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 605 "src/analyzer/expression/Expression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 606 "src/analyzer/expression/Expression.pv"
            if (func_return_type == 0) {
                #line 606 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 608 "src/analyzer/expression/Expression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 609 "src/analyzer/expression/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 612 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 614 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 615 "src/analyzer/expression/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 616 "src/analyzer/expression/Expression.pv"
            if (name == 0) {
                #line 616 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 618 "src/analyzer/expression/Expression.pv"
            struct Expression* value = 0;
            #line 619 "src/analyzer/expression/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 620 "src/analyzer/expression/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 622 "src/analyzer/expression/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 623 "src/analyzer/expression/Expression.pv"
                if (return_type == 0) {
                    #line 624 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 625 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 628 "src/analyzer/expression/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 631 "src/analyzer/expression/Expression.pv"
            if (value == 0) {
                #line 631 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 633 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 635 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 636 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 637 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 641 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 641 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 643 "src/analyzer/expression/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 644 "src/analyzer/expression/Expression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 644 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 646 "src/analyzer/expression/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 647 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 649 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 651 "src/analyzer/expression/Expression.pv"
        uintptr_t field_index = 0;
        #line 652 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 653 "src/analyzer/expression/Expression.pv"
            struct String name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 654 "src/analyzer/expression/Expression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 655 "src/analyzer/expression/Expression.pv"
            String__append_usize(&name, field_index);
            #line 656 "src/analyzer/expression/Expression.pv"
            struct str name_str = String__as_str(&name);

            #line 658 "src/analyzer/expression/Expression.pv"
            struct Token name_token = *Context__current(context);
            #line 659 "src/analyzer/expression/Expression.pv"
            name_token.value = name_str;

            #line 661 "src/analyzer/expression/Expression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 662 "src/analyzer/expression/Expression.pv"
            if (value == 0) {
                #line 662 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 664 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, &name_token),
                .value = value,
            });

            #line 669 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 670 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 671 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 674 "src/analyzer/expression/Expression.pv"
            field_index += 1;
        }

        #line 677 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 677 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 679 "src/analyzer/expression/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 680 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 683 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 686 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 687 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 688 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 690 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 691 "src/analyzer/expression/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 692 "src/analyzer/expression/Expression.pv"
            if (name == 0) {
                #line 692 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 694 "src/analyzer/expression/Expression.pv"
            struct Expression* value = 0;
            #line 695 "src/analyzer/expression/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 696 "src/analyzer/expression/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 698 "src/analyzer/expression/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 699 "src/analyzer/expression/Expression.pv"
                if (return_type == 0) {
                    #line 700 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 701 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 704 "src/analyzer/expression/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 707 "src/analyzer/expression/Expression.pv"
            if (value == 0) {
                #line 707 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 709 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 711 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
                #line 712 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 713 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 717 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 717 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 719 "src/analyzer/expression/Expression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 719 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 721 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 723 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 725 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 726 "src/analyzer/expression/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 727 "src/analyzer/expression/Expression.pv"
            if (argument == 0) {
                #line 727 "src/analyzer/expression/Expression.pv"
                return 0;
            }

            #line 729 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 731 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 732 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 733 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 737 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 737 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 739 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 742 "src/analyzer/expression/Expression.pv"
    return parent;
}

#line 745 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 746 "src/analyzer/expression/Expression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 748 "src/analyzer/expression/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 749 "src/analyzer/expression/Expression.pv"
        struct Expression* placement = 0;
        #line 750 "src/analyzer/expression/Expression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 751 "src/analyzer/expression/Expression.pv"
            placement = Expression__parse(context, generics);
            #line 752 "src/analyzer/expression/Expression.pv"
            if (placement == 0) {
                #line 752 "src/analyzer/expression/Expression.pv"
                return 0;
            }
            #line 753 "src/analyzer/expression/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 753 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 756 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 757 "src/analyzer/expression/Expression.pv"
        if (expression == 0) {
            #line 757 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 759 "src/analyzer/expression/Expression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 760 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { ._0 = placement, ._1 = expression} } }, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 762 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 763 "src/analyzer/expression/Expression.pv"
        if (expression == 0) {
            #line 763 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 765 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &context->root->type_unknown);
    }

    #line 768 "src/analyzer/expression/Expression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 769 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 772 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 773 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 773 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 775 "src/analyzer/expression/Expression.pv"
    switch (inner->return_type.type) {
        #line 776 "src/analyzer/expression/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 777 "src/analyzer/expression/Expression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 778 "src/analyzer/expression/Expression.pv"
        default: {
            #line 779 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 780 "src/analyzer/expression/Expression.pv"
            return 0;
        } break;
    }

    #line 784 "src/analyzer/expression/Expression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 785 "src/analyzer/expression/Expression.pv"
    if (member == 0) {
        #line 785 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 787 "src/analyzer/expression/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 788 "src/analyzer/expression/Expression.pv"
    if (member_type == 0) {
        #line 788 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 790 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 793 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 794 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 794 "src/analyzer/expression/Expression.pv"
        return false;
    }

    #line 796 "src/analyzer/expression/Expression.pv"
    struct Token* member_name = Context__current(context);
    #line 797 "src/analyzer/expression/Expression.pv"
    if (member_name == 0) {
        #line 797 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 799 "src/analyzer/expression/Expression.pv"
    if (member_name->type != TOKEN_TYPE__NUMBER && member_name->type != TOKEN_TYPE__IDENTIFIER) {
        #line 800 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 803 "src/analyzer/expression/Expression.pv"
    Context__next_token(context);

    #line 805 "src/analyzer/expression/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 806 "src/analyzer/expression/Expression.pv"
    if (member_type == 0) {
        #line 806 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 808 "src/analyzer/expression/Expression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 809 "src/analyzer/expression/Expression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) {};
    #line 810 "src/analyzer/expression/Expression.pv"
    struct Function* func_info = 0;

    #line 812 "src/analyzer/expression/Expression.pv"
    bool is_function = false;
    #line 813 "src/analyzer/expression/Expression.pv"
    switch (member_type->type) {
        #line 814 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION: {
            #line 814 "src/analyzer/expression/Expression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 815 "src/analyzer/expression/Expression.pv"
            is_function = true;
            #line 816 "src/analyzer/expression/Expression.pv"
            func_info = func_info2;
        } break;
        #line 818 "src/analyzer/expression/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 818 "src/analyzer/expression/Expression.pv"
            is_function = true;
        } break;
        #line 819 "src/analyzer/expression/Expression.pv"
        case TYPE__UNKNOWN_C: {
            #line 819 "src/analyzer/expression/Expression.pv"
            is_function = true;
        } break;
        #line 820 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 823 "src/analyzer/expression/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 824 "src/analyzer/expression/Expression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 827 "src/analyzer/expression/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 828 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 828 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 830 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 832 "src/analyzer/expression/Expression.pv"
        if (func_info != 0 && func_info->parameters.length > 0 && str__eq(func_info->parameters.data[0].name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 833 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = inner });
        }

        #line 836 "src/analyzer/expression/Expression.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 837 "src/analyzer/expression/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 838 "src/analyzer/expression/Expression.pv"
            if (argument == 0) {
                #line 838 "src/analyzer/expression/Expression.pv"
                return 0;
            }
            #line 839 "src/analyzer/expression/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 841 "src/analyzer/expression/Expression.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 842 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 843 "src/analyzer/expression/Expression.pv"
                return 0;
            }
        }

        #line 847 "src/analyzer/expression/Expression.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 847 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 849 "src/analyzer/expression/Expression.pv"
        if (func_info != 0 && func_info->generics.array.length > 0) {
            #line 850 "src/analyzer/expression/Expression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 851 "src/analyzer/expression/Expression.pv"
            member_type = Root__make_type_usage(context->root, member_type, &func_generics->array);
        }

        #line 854 "src/analyzer/expression/Expression.pv"
        if (func_info != 0 && (func_info->type == FUNCTION_TYPE__BUILTIN || func_info->type == FUNCTION_TYPE__METHOD_CPP)) {
            #line 855 "src/analyzer/expression/Expression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 856 "src/analyzer/expression/Expression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 858 "src/analyzer/expression/Expression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 861 "src/analyzer/expression/Expression.pv"
        if (generic_map != 0) {
            #line 862 "src/analyzer/expression/Expression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }

        #line 865 "src/analyzer/expression/Expression.pv"
        return Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
    }
}

#line 869 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 870 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
        #line 870 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 872 "src/analyzer/expression/Expression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 873 "src/analyzer/expression/Expression.pv"
    if (index_expr == 0) {
        #line 873 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 875 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]")) {
        #line 875 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 877 "src/analyzer/expression/Expression.pv"
    switch (index_expr->data.type) {
        #line 878 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 878 "src/analyzer/expression/Expression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 878 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 879 "src/analyzer/expression/Expression.pv"
            switch (target->return_type.type) {
                #line 880 "src/analyzer/expression/Expression.pv"
                case TYPE__ENUM: {
                    #line 880 "src/analyzer/expression/Expression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 881 "src/analyzer/expression/Expression.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 882 "src/analyzer/expression/Expression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, &(struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        });

                        #line 888 "src/analyzer/expression/Expression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 889 "src/analyzer/expression/Expression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 891 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 893 "src/analyzer/expression/Expression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, index_expr->token);
                        #line 894 "src/analyzer/expression/Expression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 895 "src/analyzer/expression/Expression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 897 "src/analyzer/expression/Expression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, argument_name_data);
                        #line 898 "src/analyzer/expression/Expression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 900 "src/analyzer/expression/Expression.pv"
                        if (Expression__is_zero(start)) {
                            #line 901 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 902 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 904 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 909 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 915 "src/analyzer/expression/Expression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence });
                        #line 916 "src/analyzer/expression/Expression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 917 "src/analyzer/expression/Expression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 920 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 923 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 926 "src/analyzer/expression/Expression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 927 "src/analyzer/expression/Expression.pv"
    struct Type* element_type = 0;

    #line 929 "src/analyzer/expression/Expression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 930 "src/analyzer/expression/Expression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 931 "src/analyzer/expression/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 931 "src/analyzer/expression/Expression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 932 "src/analyzer/expression/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 934 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
    } else {
        #line 937 "src/analyzer/expression/Expression.pv"
        switch (inner_return_type->type) {
            #line 938 "src/analyzer/expression/Expression.pv"
            case TYPE__INDIRECT: {
                #line 938 "src/analyzer/expression/Expression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 939 "src/analyzer/expression/Expression.pv"
                element_type = &indirect->to;
            } break;
            #line 941 "src/analyzer/expression/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 941 "src/analyzer/expression/Expression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 942 "src/analyzer/expression/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 944 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
    }

    #line 948 "src/analyzer/expression/Expression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 949 "src/analyzer/expression/Expression.pv"
        struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(context->allocator, &(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "", .length = strlen("") }, .generics = (struct Array_Type) {} });
        #line 950 "src/analyzer/expression/Expression.pv"
        element_type = Type__to_ptr(&(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c }, context->allocator);
    }

    #line 953 "src/analyzer/expression/Expression.pv"
    if (element_type == 0) {
        #line 954 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, index_expr->token, "Type is not indexable");
        #line 955 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 958 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 961 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 962 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);

    #line 964 "src/analyzer/expression/Expression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 965 "src/analyzer/expression/Expression.pv"
        return Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 967 "src/analyzer/expression/Expression.pv"
        return Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 969 "src/analyzer/expression/Expression.pv"
        return Expression__parse_index_expression(context, inner, generics);
    } else if (Type__is_function(Type__resolve_typedef_function(&inner->return_type)) && (Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, "("))) {
        #line 971 "src/analyzer/expression/Expression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 972 "src/analyzer/expression/Expression.pv"
            case TYPE__FUNCTION: {
                #line 972 "src/analyzer/expression/Expression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 973 "src/analyzer/expression/Expression.pv"
                struct Array_Type parsed_generics = (struct Array_Type) {};

                #line 975 "src/analyzer/expression/Expression.pv"
                if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                    #line 976 "src/analyzer/expression/Expression.pv"
                    parsed_generics = Context__parse_generics(context, generics);
                }

                #line 979 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 979 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 981 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 983 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 984 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 985 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 987 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 988 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 989 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 993 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 993 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 995 "src/analyzer/expression/Expression.pv"
                if (func_info->generics.array.length > 0) {
                    #line 996 "src/analyzer/expression/Expression.pv"
                    struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                    #line 997 "src/analyzer/expression/Expression.pv"
                    inner->return_type = *Root__make_type_usage(context->root, &inner->return_type, &func_generics->array);

                    #line 999 "src/analyzer/expression/Expression.pv"
                    switch (inner->data.type) {
                        #line 1000 "src/analyzer/expression/Expression.pv"
                        case EXPRESSION_DATA__TYPE: {
                            #line 1000 "src/analyzer/expression/Expression.pv"
                            struct Type** type = &inner->data.type_value;
                            #line 1001 "src/analyzer/expression/Expression.pv"
                            *type = &inner->return_type;
                        } break;
                        #line 1003 "src/analyzer/expression/Expression.pv"
                        default: {
                        } break;
                    }
                }

                #line 1007 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_arguments(context, token, &inner->return_type, &arguments, 0, false)) {
                    #line 1007 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1009 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 1011 "src/analyzer/expression/Expression.pv"
            case TYPE__FUNCTION_C: {
                #line 1011 "src/analyzer/expression/Expression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 1012 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 1012 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1014 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 1016 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 1017 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 1018 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 1020 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1021 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 1022 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 1026 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 1026 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1028 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 1030 "src/analyzer/expression/Expression.pv"
            case TYPE__CLASS_CPP: {
                #line 1031 "src/analyzer/expression/Expression.pv"
                return Expression__parse_class(context, token, inner, generics);
            } break;
            #line 1033 "src/analyzer/expression/Expression.pv"
            case TYPE__UNKNOWN_C: {
                #line 1034 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 1034 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1036 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 1038 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 1039 "src/analyzer/expression/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 1040 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 1042 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1043 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 1044 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 1048 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 1048 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1050 "src/analyzer/expression/Expression.pv"
                return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &context->root->type_unknown);
            } break;
            #line 1052 "src/analyzer/expression/Expression.pv"
            default: {
                #line 1053 "src/analyzer/expression/Expression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 1054 "src/analyzer/expression/Expression.pv"
                return 0;
            } break;
        }
    }

    #line 1059 "src/analyzer/expression/Expression.pv"
    return inner;
}

#line 1062 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics) {
    #line 1063 "src/analyzer/expression/Expression.pv"
    struct Expression* result = lhs;

    #line 1065 "src/analyzer/expression/Expression.pv"
    while (true) {
        #line 1066 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__current(context);
        #line 1067 "src/analyzer/expression/Expression.pv"
        uintptr_t prec = Expression__get_precedence(token);
        #line 1068 "src/analyzer/expression/Expression.pv"
        if (prec < min_prec) {
            #line 1068 "src/analyzer/expression/Expression.pv"
            break;
        }

        #line 1070 "src/analyzer/expression/Expression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 1071 "src/analyzer/expression/Expression.pv"
        if (operator == 0) {
            #line 1071 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1073 "src/analyzer/expression/Expression.pv"
        struct Expression* rhs = Expression__parse_primary(context, generics);
        #line 1074 "src/analyzer/expression/Expression.pv"
        if (rhs == 0) {
            #line 1074 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1076 "src/analyzer/expression/Expression.pv"
        struct Expression* rhs_final = Expression__parse_binary(context, rhs, prec + 1, generics);
        #line 1077 "src/analyzer/expression/Expression.pv"
        if (rhs_final == 0) {
            #line 1077 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1079 "src/analyzer/expression/Expression.pv"
        bool is_comparison = str__eq(operator->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__eq(operator->value, (struct str){ .ptr = "!=", .length = strlen("!=") }) || str__eq(operator->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__eq(operator->value, (struct str){ .ptr = ">=", .length = strlen(">=") }) || str__eq(operator->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__eq(operator->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) || str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") });

        #line 1085 "src/analyzer/expression/Expression.pv"
        struct Type* return_type = 0;
        #line 1086 "src/analyzer/expression/Expression.pv"
        if (is_comparison) {
            #line 1087 "src/analyzer/expression/Expression.pv"
            if (!str__eq(operator->value, (struct str){ .ptr = "||", .length = strlen("||") }) && !str__eq(operator->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
                #line 1088 "src/analyzer/expression/Expression.pv"
                if (!Expression__validate_type(result, context, &rhs_final->return_type, false)) {
                    #line 1088 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            }

            #line 1091 "src/analyzer/expression/Expression.pv"
            return_type = &context->root->type_bool;
        } else {
            #line 1093 "src/analyzer/expression/Expression.pv"
            return_type = &result->return_type;
        }

        #line 1096 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = result, ._1 = operator->value, ._2 = rhs_final} }, return_type);
    }

    #line 1099 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 1102 "src/analyzer/expression/Expression.pv"
struct str Expression__number_primitive(struct str value) {
    #line 1103 "src/analyzer/expression/Expression.pv"
    if (str__ends_with(value, "f") || str__ends_with(value, "F")) {
        #line 1104 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f32", .length = strlen("f32") };
    } else if (str__ends_with(value, "u") || str__ends_with(value, "U")) {
        #line 1106 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "u32", .length = strlen("u32") };
    } else if (str__contains(value, ".")) {
        #line 1108 "src/analyzer/expression/Expression.pv"
        return (struct str){ .ptr = "f64", .length = strlen("f64") };
    }
    #line 1110 "src/analyzer/expression/Expression.pv"
    return (struct str){ .ptr = "i32", .length = strlen("i32") };
}

#line 1113 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics) {
    #line 1114 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 1115 "src/analyzer/expression/Expression.pv"
    enum TokenType token_type = token->type;
    #line 1116 "src/analyzer/expression/Expression.pv"
    struct Expression* result = 0;

    #line 1118 "src/analyzer/expression/Expression.pv"
    switch (token_type) {
        #line 1119 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 1120 "src/analyzer/expression/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 1122 "src/analyzer/expression/Expression.pv"
            if (context->module->mode_cpp && (str__eq(token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__eq(token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 1123 "src/analyzer/expression/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 1125 "src/analyzer/expression/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 1126 "src/analyzer/expression/Expression.pv"
                if (type != 0) {
                    #line 1127 "src/analyzer/expression/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 1128 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM: {
                            #line 1128 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 1129 "src/analyzer/expression/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 1129 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 1130 "src/analyzer/expression/Expression.pv"
                        case TYPE__SELF: {
                            #line 1130 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1131 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 1131 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1132 "src/analyzer/expression/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 1132 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1133 "src/analyzer/expression/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 1133 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 1134 "src/analyzer/expression/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 1134 "src/analyzer/expression/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 1135 "src/analyzer/expression/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 1135 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 1136 "src/analyzer/expression/Expression.pv"
                        default: {
                            #line 1136 "src/analyzer/expression/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 1139 "src/analyzer/expression/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 1140 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                    });

                    #line 1145 "src/analyzer/expression/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 1147 "src/analyzer/expression/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 1148 "src/analyzer/expression/Expression.pv"
                    return 0;
                }
            } else {
                #line 1151 "src/analyzer/expression/Expression.pv"
                switch (return_type->type) {
                    #line 1152 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 1152 "src/analyzer/expression/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 1153 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1154 "src/analyzer/expression/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 1155 "src/analyzer/expression/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) {};

                        #line 1157 "src/analyzer/expression/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 1158 "src/analyzer/expression/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 1161 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 1161 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1163 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1165 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1166 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1167 "src/analyzer/expression/Expression.pv"
                            if (argument == 0) {
                                #line 1167 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                            #line 1168 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1170 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 1171 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1172 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1176 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1176 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1178 "src/analyzer/expression/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 1179 "src/analyzer/expression/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 1180 "src/analyzer/expression/Expression.pv"
                            func_type = Root__make_type_usage(context->root, func_type, &func_generics->array);
                        }

                        #line 1183 "src/analyzer/expression/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 1183 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1185 "src/analyzer/expression/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 1186 "src/analyzer/expression/Expression.pv"
                        switch (func_type->type) {
                            #line 1187 "src/analyzer/expression/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 1187 "src/analyzer/expression/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 1188 "src/analyzer/expression/Expression.pv"
                                switch (func_info->type) {
                                    #line 1189 "src/analyzer/expression/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 1190 "src/analyzer/expression/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} });
                                    } break;
                                    #line 1192 "src/analyzer/expression/Expression.pv"
                                    default: {
                                        #line 1193 "src/analyzer/expression/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 1197 "src/analyzer/expression/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 1200 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 1201 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 1203 "src/analyzer/expression/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 1204 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1205 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1207 "src/analyzer/expression/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 1208 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1209 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1211 "src/analyzer/expression/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 1212 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1213 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1215 "src/analyzer/expression/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 1216 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1217 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1219 "src/analyzer/expression/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 1220 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1221 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1223 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM: {
                        #line 1224 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1225 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1227 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 1228 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1229 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1231 "src/analyzer/expression/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 1232 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1233 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1235 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 1236 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1237 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1239 "src/analyzer/expression/Expression.pv"
                    case TYPE__SELF: {
                        #line 1240 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1241 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1243 "src/analyzer/expression/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 1244 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1245 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1247 "src/analyzer/expression/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 1248 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1249 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1251 "src/analyzer/expression/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 1252 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1253 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1255 "src/analyzer/expression/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 1256 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1257 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1259 "src/analyzer/expression/Expression.pv"
                    case TYPE__GLOBAL: {
                        #line 1260 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1261 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1263 "src/analyzer/expression/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 1264 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1265 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1267 "src/analyzer/expression/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 1267 "src/analyzer/expression/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 1268 "src/analyzer/expression/Expression.pv"
                        Context__next_token(context);
                        #line 1269 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 1269 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1271 "src/analyzer/expression/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1273 "src/analyzer/expression/Expression.pv"
                        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1274 "src/analyzer/expression/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1275 "src/analyzer/expression/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1277 "src/analyzer/expression/Expression.pv"
                            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 1278 "src/analyzer/expression/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1279 "src/analyzer/expression/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1283 "src/analyzer/expression/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1283 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1285 "src/analyzer/expression/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 1287 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, &func_info->return_type);
                    } break;
                    #line 1289 "src/analyzer/expression/Expression.pv"
                    default: {
                        #line 1290 "src/analyzer/expression/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 1295 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 1296 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char },
            });
        } break;
        #line 1302 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 1303 "src/analyzer/expression/Expression.pv"
            struct str primitive = Expression__number_primitive(token->value);
            #line 1304 "src/analyzer/expression/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 1310 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 1311 "src/analyzer/expression/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 1312 "src/analyzer/expression/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 1313 "src/analyzer/expression/Expression.pv"
                if (operator == 0) {
                    #line 1313 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1315 "src/analyzer/expression/Expression.pv"
                if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 1316 "src/analyzer/expression/Expression.pv"
                    context->pos -= 1;
                    #line 1317 "src/analyzer/expression/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 1318 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 1320 "src/analyzer/expression/Expression.pv"
                    struct Expression* child = Expression__parse_primary(context, generics);
                    #line 1321 "src/analyzer/expression/Expression.pv"
                    if (child == 0) {
                        #line 1321 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 1323 "src/analyzer/expression/Expression.pv"
                    if (str__eq(operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 1324 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 1325 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1325 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1326 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) });
                                #line 1327 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1329 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 1330 "src/analyzer/expression/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 1331 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 1335 "src/analyzer/expression/Expression.pv"
                        switch (child->data.type) {
                            #line 1336 "src/analyzer/expression/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1336 "src/analyzer/expression/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1337 "src/analyzer/expression/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 1338 "src/analyzer/expression/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect });
                                #line 1339 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1341 "src/analyzer/expression/Expression.pv"
                            default: {
                                #line 1341 "src/analyzer/expression/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 1344 "src/analyzer/expression/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 1348 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 1348 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1350 "src/analyzer/expression/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 1351 "src/analyzer/expression/Expression.pv"
                if (expr == 0) {
                    #line 1351 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1353 "src/analyzer/expression/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 1354 "src/analyzer/expression/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 1356 "src/analyzer/expression/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, expr->token);
                    #line 1357 "src/analyzer/expression/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 1359 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 1361 "src/analyzer/expression/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1362 "src/analyzer/expression/Expression.pv"
                        struct String name_string = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 1363 "src/analyzer/expression/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 1364 "src/analyzer/expression/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 1366 "src/analyzer/expression/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, Context__current(context));
                        #line 1367 "src/analyzer/expression/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 1369 "src/analyzer/expression/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 1370 "src/analyzer/expression/Expression.pv"
                        if (value == 0) {
                            #line 1370 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }

                        #line 1372 "src/analyzer/expression/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 1374 "src/analyzer/expression/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1375 "src/analyzer/expression/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 1376 "src/analyzer/expression/Expression.pv"
                            return 0;
                        }
                    }

                    #line 1380 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, &(struct Tuple) {});
                    #line 1381 "src/analyzer/expression/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 1382 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 1382 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1382 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1382 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1383 "src/analyzer/expression/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 1386 "src/analyzer/expression/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }), arguments, 0);
                } else {
                    #line 1388 "src/analyzer/expression/Expression.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1388 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 1390 "src/analyzer/expression/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 1393 "src/analyzer/expression/Expression.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[")) {
                    #line 1393 "src/analyzer/expression/Expression.pv"
                    return 0;
                }

                #line 1395 "src/analyzer/expression/Expression.pv"
                struct Type* element_type = 0;
                #line 1396 "src/analyzer/expression/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 1398 "src/analyzer/expression/Expression.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                    #line 1399 "src/analyzer/expression/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 1400 "src/analyzer/expression/Expression.pv"
                    if (element == 0) {
                        #line 1400 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }

                    #line 1402 "src/analyzer/expression/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .value = element });

                    #line 1404 "src/analyzer/expression/Expression.pv"
                    if (element_type == 0) {
                        #line 1405 "src/analyzer/expression/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 1408 "src/analyzer/expression/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 1409 "src/analyzer/expression/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 1410 "src/analyzer/expression/Expression.pv"
                        return 0;
                    }
                }

                #line 1414 "src/analyzer/expression/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 1416 "src/analyzer/expression/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, &(struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = elements.length }, .element = *element_type });
                #line 1417 "src/analyzer/expression/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, &(struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence });
                #line 1418 "src/analyzer/expression/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 1420 "src/analyzer/expression/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 1422 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 1425 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 1426 "src/analyzer/expression/Expression.pv"
            if (str__eq(token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__eq(token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 1427 "src/analyzer/expression/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, (struct str){ .ptr = "bool", .length = strlen("bool") }) },
                });
            } else if (str__eq(token->value, (struct str){ .ptr = "if", .length = strlen("if") })) {
                #line 1433 "src/analyzer/expression/Expression.pv"
                result = Expression__parse_if_expression(context, generics);
            } else {
                #line 1435 "src/analyzer/expression/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 1438 "src/analyzer/expression/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 1439 "src/analyzer/expression/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 1443 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 1443 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1445 "src/analyzer/expression/Expression.pv"
    return Expression__parse_postfix_chain(context, result, generics);
}

#line 1449 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 1450 "src/analyzer/expression/Expression.pv"
    struct Expression* result = Expression__parse_primary(context, generics);
    #line 1451 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 1451 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1453 "src/analyzer/expression/Expression.pv"
    result = Expression__parse_binary(context, result, 1, generics);
    #line 1454 "src/analyzer/expression/Expression.pv"
    if (result == 0) {
        #line 1454 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1456 "src/analyzer/expression/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 1457 "src/analyzer/expression/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 1459 "src/analyzer/expression/Expression.pv"
        struct Expression* range_start = result;
        #line 1460 "src/analyzer/expression/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 1461 "src/analyzer/expression/Expression.pv"
        if (range_end == 0) {
            #line 1461 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1463 "src/analyzer/expression/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, &(struct Array_Type) { .data = &range_end->return_type, .length = 1 });
        #line 1464 "src/analyzer/expression/Expression.pv"
        if (enum_type == 0) {
            #line 1465 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 1466 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1469 "src/analyzer/expression/Expression.pv"
        struct Token variant_name = *token;
        #line 1470 "src/analyzer/expression/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 1471 "src/analyzer/expression/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 1473 "src/analyzer/expression/Expression.pv"
        struct EnumVariantResult variant_result = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 1474 "src/analyzer/expression/Expression.pv"
        struct EnumVariant* variant = 0;
        #line 1475 "src/analyzer/expression/Expression.pv"
        switch (variant_result.type) {
            #line 1476 "src/analyzer/expression/Expression.pv"
            case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                #line 1476 "src/analyzer/expression/Expression.pv"
                struct EnumVariant* enum_variant = variant_result.enumvariant_value;
                #line 1476 "src/analyzer/expression/Expression.pv"
                variant = enum_variant;
            } break;
            #line 1477 "src/analyzer/expression/Expression.pv"
            default: {
            } break;
        }
        #line 1479 "src/analyzer/expression/Expression.pv"
        if (variant == 0) {
            #line 1480 "src/analyzer/expression/Expression.pv"
            Context__error_token(context, token, "Could not find Range StartEnd enum variant");
            #line 1481 "src/analyzer/expression/Expression.pv"
            return 0;
        }

        #line 1484 "src/analyzer/expression/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1485 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_start });
        #line 1486 "src/analyzer/expression/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_end });

        #line 1488 "src/analyzer/expression/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 1490 "src/analyzer/expression/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 1493 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 1496 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 1497 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 1498 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1498 "src/analyzer/expression/Expression.pv"
            struct str value = self->data.literal_value;
            #line 1498 "src/analyzer/expression/Expression.pv"
            return str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 1499 "src/analyzer/expression/Expression.pv"
        default: {
            #line 1499 "src/analyzer/expression/Expression.pv"
            return false;
        } break;
    }
}

#line 1503 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast) {
    #line 1504 "src/analyzer/expression/Expression.pv"
    bool success = true;

    #line 1506 "src/analyzer/expression/Expression.pv"
    switch (self->data.type) {
        #line 1507 "src/analyzer/expression/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1507 "src/analyzer/expression/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 1507 "src/analyzer/expression/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 1508 "src/analyzer/expression/Expression.pv"
            switch (type->type) {
                #line 1509 "src/analyzer/expression/Expression.pv"
                case TYPE__TUPLE: {
                    #line 1509 "src/analyzer/expression/Expression.pv"
                    struct Tuple* tuple = type->tuple_value;
                    #line 1510 "src/analyzer/expression/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 1510 "src/analyzer/expression/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1510 "src/analyzer/expression/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1510 "src/analyzer/expression/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1511 "src/analyzer/expression/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i], apply_implicit_cast) && success;
                    } }

                    #line 1514 "src/analyzer/expression/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type };
                    #line 1515 "src/analyzer/expression/Expression.pv"
                    invoke->return_type = *type;
                    #line 1516 "src/analyzer/expression/Expression.pv"
                    self->return_type = *type;

                    #line 1518 "src/analyzer/expression/Expression.pv"
                    return success;
                } break;
                #line 1520 "src/analyzer/expression/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 1523 "src/analyzer/expression/Expression.pv"
        default: {
        } break;
    }

    #line 1526 "src/analyzer/expression/Expression.pv"
    if (apply_implicit_cast && Type__needs_implicit_cast(type, &self->return_type)) {
        #line 1527 "src/analyzer/expression/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, self);
        #line 1528 "src/analyzer/expression/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 1529 "src/analyzer/expression/Expression.pv"
        self->return_type = *type;
        #line 1530 "src/analyzer/expression/Expression.pv"
        return true;
    }

    #line 1533 "src/analyzer/expression/Expression.pv"
    if (!Type__eq(type, &self->return_type)) {
        #line 1534 "src/analyzer/expression/Expression.pv"
        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1535 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
        #line 1536 "src/analyzer/expression/Expression.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 1537 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&type_name));
        #line 1538 "src/analyzer/expression/Expression.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 1539 "src/analyzer/expression/Expression.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 1540 "src/analyzer/expression/Expression.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 1541 "src/analyzer/expression/Expression.pv"
        Context__error_token(context, self->token, String__c_str(&message));
        #line 1542 "src/analyzer/expression/Expression.pv"
        return false;
    }
    #line 1546 "src/analyzer/expression/Expression.pv"
    return true;
}

#line 1549 "src/analyzer/expression/Expression.pv"
uintptr_t Expression__get_precedence(struct Token* token) {
    #line 1550 "src/analyzer/expression/Expression.pv"
    if (token->type != TOKEN_TYPE__SYMBOL) {
        #line 1550 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1552 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "||", .length = strlen("||") })) {
        #line 1552 "src/analyzer/expression/Expression.pv"
        return 1;
    }
    #line 1553 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "&&", .length = strlen("&&") })) {
        #line 1553 "src/analyzer/expression/Expression.pv"
        return 2;
    }
    #line 1554 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "|", .length = strlen("|") })) {
        #line 1554 "src/analyzer/expression/Expression.pv"
        return 3;
    }
    #line 1555 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "^", .length = strlen("^") })) {
        #line 1555 "src/analyzer/expression/Expression.pv"
        return 4;
    }
    #line 1556 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
        #line 1556 "src/analyzer/expression/Expression.pv"
        return 5;
    }
    #line 1557 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "==", .length = strlen("==") }) || str__eq(token->value, (struct str){ .ptr = "!=", .length = strlen("!=") })) {
        #line 1557 "src/analyzer/expression/Expression.pv"
        return 6;
    }
    #line 1558 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "<", .length = strlen("<") }) || str__eq(token->value, (struct str){ .ptr = ">", .length = strlen(">") }) || str__eq(token->value, (struct str){ .ptr = "<=", .length = strlen("<=") }) || str__eq(token->value, (struct str){ .ptr = ">=", .length = strlen(">=") })) {
        #line 1558 "src/analyzer/expression/Expression.pv"
        return 7;
    }
    #line 1559 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "<<", .length = strlen("<<") }) || str__eq(token->value, (struct str){ .ptr = ">>", .length = strlen(">>") })) {
        #line 1559 "src/analyzer/expression/Expression.pv"
        return 8;
    }
    #line 1560 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "+", .length = strlen("+") }) || str__eq(token->value, (struct str){ .ptr = "-", .length = strlen("-") })) {
        #line 1560 "src/analyzer/expression/Expression.pv"
        return 9;
    }
    #line 1561 "src/analyzer/expression/Expression.pv"
    if (str__eq(token->value, (struct str){ .ptr = "*", .length = strlen("*") }) || str__eq(token->value, (struct str){ .ptr = "/", .length = strlen("/") }) || str__eq(token->value, (struct str){ .ptr = "%", .length = strlen("%") })) {
        #line 1561 "src/analyzer/expression/Expression.pv"
        return 10;
    }

    #line 1563 "src/analyzer/expression/Expression.pv"
    return 0;
}

#line 1566 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 1567 "src/analyzer/expression/Expression.pv"
    struct Expression* result = inner;
    #line 1568 "src/analyzer/expression/Expression.pv"
    while (true) {
        #line 1569 "src/analyzer/expression/Expression.pv"
        struct Expression* next = Expression__parse_postfix(context, result, generics);
        #line 1570 "src/analyzer/expression/Expression.pv"
        if (next == result) {
            #line 1570 "src/analyzer/expression/Expression.pv"
            break;
        }
        #line 1571 "src/analyzer/expression/Expression.pv"
        if (next == 0) {
            #line 1571 "src/analyzer/expression/Expression.pv"
            return 0;
        }
        #line 1572 "src/analyzer/expression/Expression.pv"
        result = next;
    }
    #line 1574 "src/analyzer/expression/Expression.pv"
    return result;
}

#line 1577 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics) {
    #line 1578 "src/analyzer/expression/Expression.pv"
    struct Token* token = Context__current(context);
    #line 1579 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 1579 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1581 "src/analyzer/expression/Expression.pv"
    struct Expression* condition = Expression__parse(context, generics);
    #line 1582 "src/analyzer/expression/Expression.pv"
    if (condition == 0) {
        #line 1582 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1584 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 1584 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1586 "src/analyzer/expression/Expression.pv"
    struct Expression* a = Expression__parse(context, generics);
    #line 1587 "src/analyzer/expression/Expression.pv"
    if (a == 0) {
        #line 1587 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1589 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 1589 "src/analyzer/expression/Expression.pv"
        return 0;
    }
    #line 1590 "src/analyzer/expression/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 1590 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1592 "src/analyzer/expression/Expression.pv"
    bool is_else_if = Context__check_value(context, TOKEN_TYPE__KEYWORD, "if");

    #line 1594 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 1595 "src/analyzer/expression/Expression.pv"
        Context__error(context, "Expected { or else if");
        #line 1596 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1599 "src/analyzer/expression/Expression.pv"
    struct Expression* b = Expression__parse(context, generics);
    #line 1600 "src/analyzer/expression/Expression.pv"
    if (b == 0) {
        #line 1600 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1602 "src/analyzer/expression/Expression.pv"
    if (!is_else_if && !Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 1602 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1604 "src/analyzer/expression/Expression.pv"
    if (!Expression__validate_type(a, context, &b->return_type, false)) {
        #line 1604 "src/analyzer/expression/Expression.pv"
        return 0;
    }

    #line 1606 "src/analyzer/expression/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__IF_EXPRESSION, .ifexpression_value = { ._0 = condition, ._1 = a, ._2 = b} }, &a->return_type);
}
