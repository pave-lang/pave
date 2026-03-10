#include <stdlib.h>

#include <analyzer/Naming.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/ExpressionData.h>
#include <analyzer/Type.h>
#include <analyzer/Context.h>
#include <stdbool.h>
#include <analyzer/EnumVariant.h>
#include <analyzer/Indirect.h>
#include <std/str.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/Enum.h>
#include <stdint.h>
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

#line 38 "src/analyzer/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type) {
    #line 39 "src/analyzer/Expression.pv"
    return ArenaAllocator__store_Expression(allocator, (struct Expression) {
        .token = token,
        .data = data,
        .return_type = *return_type,
    });
}

#line 46 "src/analyzer/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node) {
    #line 47 "src/analyzer/Expression.pv"
    struct Expression* result = ArenaAllocator__store_Expression(context->allocator, node);

    #line 49 "src/analyzer/Expression.pv"
    Context__next_token(context);

    #line 51 "src/analyzer/Expression.pv"
    return result;
}

#line 54 "src/analyzer/Expression.pv"
struct EnumVariant* Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token) {
    #line 55 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 56 "src/analyzer/Expression.pv"
        case TYPE__INDIRECT: {
            #line 56 "src/analyzer/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 57 "src/analyzer/Expression.pv"
            return Expression__get_enum_variant(context, &indirect->to, token);
        } break;
        #line 59 "src/analyzer/Expression.pv"
        case TYPE__SELF: {
            #line 60 "src/analyzer/Expression.pv"
            return Expression__get_enum_variant(context, context->type_self, token);
        } break;
        #line 62 "src/analyzer/Expression.pv"
        case TYPE__ENUM: {
            #line 62 "src/analyzer/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 63 "src/analyzer/Expression.pv"
            struct EnumVariant* variant = HashMap_str_EnumVariant__find(&enum_info->variants, &token->value);
            #line 64 "src/analyzer/Expression.pv"
            if (variant == 0) {
                #line 64 "src/analyzer/Expression.pv"
                Context__error_token(context, token, "Variant not found in enum");
            }

            #line 66 "src/analyzer/Expression.pv"
            return variant;
        } break;
        #line 68 "src/analyzer/Expression.pv"
        default: {
            #line 68 "src/analyzer/Expression.pv"
            return 0;
        } break;
    }

    #line 71 "src/analyzer/Expression.pv"
    return 0;
}

#line 74 "src/analyzer/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error) {
    #line 75 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 76 "src/analyzer/Expression.pv"
        case TYPE__INDIRECT: {
            #line 76 "src/analyzer/Expression.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 77 "src/analyzer/Expression.pv"
            return Expression__get_member_type(context, &indirect->to, member, output_error);
        } break;
        #line 79 "src/analyzer/Expression.pv"
        case TYPE__SELF: {
            #line 80 "src/analyzer/Expression.pv"
            return Expression__get_member_type(context, context->type_self, member, output_error);
        } break;
        #line 82 "src/analyzer/Expression.pv"
        case TYPE__PRIMITIVE: {
            #line 82 "src/analyzer/Expression.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 83 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 83 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 83 "src/analyzer/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 84 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 85 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 86 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap) { .self_type = type })} });
                }
            } }

            #line 90 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 90 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Function not implemented on primitive");
            }
            #line 91 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 93 "src/analyzer/Expression.pv"
        case TYPE__STRUCT: {
            #line 93 "src/analyzer/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 93 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->struct_value._1;
            #line 94 "src/analyzer/Expression.pv"
            struct StructField* field = HashMap_str_StructField__find(&struct_info->fields, &member->value);
            #line 95 "src/analyzer/Expression.pv"
            if (field != 0) {
                #line 96 "src/analyzer/Expression.pv"
                return &field->type;
            }

            #line 99 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
            #line 99 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 99 "src/analyzer/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 100 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 101 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 102 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 106 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 107 "src/analyzer/Expression.pv"
                Context__error_token_value(context, member, "Field or function not found in struct", member->value);
            }
            #line 109 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 111 "src/analyzer/Expression.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 111 "src/analyzer/Expression.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 111 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->coroutineinstance_value._1;
            #line 112 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "next", .length = strlen("next") })) {
                #line 113 "src/analyzer/Expression.pv"
                struct Function* func_next = ArenaAllocator__store_Function(context->allocator, context->root->func_next);
                #line 114 "src/analyzer/Expression.pv"
                func_next->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 115 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_next, ._1 = generic_map} });
            }

            #line 118 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "value", .length = strlen("value") })) {
                #line 119 "src/analyzer/Expression.pv"
                struct Function* func_value = ArenaAllocator__store_Function(context->allocator, context->root->func_value);
                #line 120 "src/analyzer/Expression.pv"
                func_value->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = type, ._1 = 0, ._2 = 0} };
                #line 121 "src/analyzer/Expression.pv"
                func_value->return_type = func_info->return_type;
                #line 122 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_value, ._1 = generic_map} });
            }

            #line 125 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 125 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Only next() and value() functions exist on coroutine instances");
            }
            #line 126 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 128 "src/analyzer/Expression.pv"
        case TYPE__ENUM: {
            #line 128 "src/analyzer/Expression.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 128 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->enum_value._1;
            #line 129 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 129 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Impl__next(&__iter)) {
                #line 129 "src/analyzer/Expression.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

                #line 130 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
                #line 131 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 132 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
                }
            } }

            #line 136 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 136 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Function not found in enum");
            }
            #line 137 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 139 "src/analyzer/Expression.pv"
        case TYPE__TRAIT: {
            #line 139 "src/analyzer/Expression.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 139 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map = type->trait_value._1;
            #line 140 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "instance", .length = strlen("instance") })) {
                #line 141 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, context->root->type_void) });
            }

            #line 144 "src/analyzer/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
            #line 145 "src/analyzer/Expression.pv"
            if (function == 0) {
                #line 146 "src/analyzer/Expression.pv"
                if (output_error) {
                    #line 146 "src/analyzer/Expression.pv"
                    Context__error_token(context, member, "Function not found in trait");
                }
                #line 147 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 150 "src/analyzer/Expression.pv"
            return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = generic_map} });
        } break;
        #line 152 "src/analyzer/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 152 "src/analyzer/Expression.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 153 "src/analyzer/Expression.pv"
            return Expression__get_member_type(context, typedef_info->type, member, output_error);
        } break;
        #line 155 "src/analyzer/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 155 "src/analyzer/Expression.pv"
            struct StructC* struct_info = type->structc_value;
            #line 156 "src/analyzer/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&struct_info->fields, &member->value);
            #line 157 "src/analyzer/Expression.pv"
            if (field != 0) {
                #line 157 "src/analyzer/Expression.pv"
                return &field->type;
            }

            #line 159 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 159 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Field not found in C struct");
            }
            #line 160 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 162 "src/analyzer/Expression.pv"
        case TYPE__UNION_C: {
            #line 162 "src/analyzer/Expression.pv"
            struct StructC* union_info = type->unionc_value;
            #line 163 "src/analyzer/Expression.pv"
            struct StructCField* field = HashMap_str_StructCField__find(&union_info->fields, &member->value);
            #line 164 "src/analyzer/Expression.pv"
            if (field != 0) {
                #line 164 "src/analyzer/Expression.pv"
                return &field->type;
            }

            #line 166 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 166 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Field not found in C union");
            }
            #line 167 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 169 "src/analyzer/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 169 "src/analyzer/Expression.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 170 "src/analyzer/Expression.pv"
            struct Type* field_type = HashMap_str_Type__find(&class_info->fields, &member->value);
            #line 171 "src/analyzer/Expression.pv"
            if (field_type != 0) {
                #line 171 "src/analyzer/Expression.pv"
                return field_type;
            }

            #line 173 "src/analyzer/Expression.pv"
            struct Type* value_type = HashMap_str_Type__find(&class_info->values, &member->value);
            #line 174 "src/analyzer/Expression.pv"
            if (value_type != 0) {
                #line 174 "src/analyzer/Expression.pv"
                return value_type;
            }

            #line 176 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&class_info->bases);
            #line 176 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 176 "src/analyzer/Expression.pv"
                struct Type* base = ArrayIter_ref_Type__value(&__iter);

                #line 177 "src/analyzer/Expression.pv"
                struct Type* base_type = Expression__get_member_type(context, base, member, output_error);
                #line 178 "src/analyzer/Expression.pv"
                if (base_type != 0) {
                    #line 178 "src/analyzer/Expression.pv"
                    return base_type;
                }
            } }

            #line 181 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 181 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Field not found in Cpp class/struct");
            }
            #line 182 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 184 "src/analyzer/Expression.pv"
        case TYPE__GENERIC: {
            #line 184 "src/analyzer/Expression.pv"
            struct Generic* generic = type->generic_value;
            #line 185 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_ref_Trait __iter = Array_ref_Trait__iter(&generic->traits);
            #line 185 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_ref_Trait__next(&__iter)) {
                #line 185 "src/analyzer/Expression.pv"
                struct Trait* trait_info = *ArrayIter_ref_ref_Trait__value(&__iter);

                #line 186 "src/analyzer/Expression.pv"
                struct Function* function = HashMap_str_Function__find(&trait_info->functions, &member->value);
                #line 187 "src/analyzer/Expression.pv"
                if (function != 0) {
                    #line 188 "src/analyzer/Expression.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, (struct GenericMap) {})} });
                }
            } }

            #line 192 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 192 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Function not found in Generic traits");
            }
            #line 193 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 195 "src/analyzer/Expression.pv"
        case TYPE__SEQUENCE: {
            #line 195 "src/analyzer/Expression.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 196 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "data", .length = strlen("data") })) {
                #line 197 "src/analyzer/Expression.pv"
                return &sequence->element_pointer;
            }

            #line 200 "src/analyzer/Expression.pv"
            if (str__eq(member->value, (struct str){ .ptr = "length", .length = strlen("length") })) {
                #line 201 "src/analyzer/Expression.pv"
                return &context->root->type_usize;
            }

            #line 204 "src/analyzer/Expression.pv"
            struct Impl* impl_info = context->root->hack_type_impl->impl_info;

            #line 206 "src/analyzer/Expression.pv"
            struct Function* function = HashMap_str_Function__find(&impl_info->functions, &member->value);
            #line 207 "src/analyzer/Expression.pv"
            if (function != 0) {
                #line 208 "src/analyzer/Expression.pv"
                struct GenericMap generic_map = GenericMap__new(context->allocator, &(struct Generics) {}, &(struct Array_Type) {});
                #line 209 "src/analyzer/Expression.pv"
                GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
                #line 210 "src/analyzer/Expression.pv"
                generic_map.self_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence }) });

                #line 212 "src/analyzer/Expression.pv"
                return ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function, ._1 = ArenaAllocator__store_GenericMap(context->allocator, generic_map)} });
            }

            #line 215 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 215 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Sequences do not have this member");
            }
            #line 216 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 218 "src/analyzer/Expression.pv"
        case TYPE__TUPLE: {
            #line 218 "src/analyzer/Expression.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 219 "src/analyzer/Expression.pv"
            if (member->type != TOKEN_TYPE__NUMBER) {
                #line 220 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Tuples do not have this member");
                #line 221 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 224 "src/analyzer/Expression.pv"
            uintptr_t index = strtoul(member->value.ptr, 0, 10);
            #line 225 "src/analyzer/Expression.pv"
            if (index >= tuple->elements.length) {
                #line 226 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Tuple does not have this member");
                #line 227 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 230 "src/analyzer/Expression.pv"
            return &tuple->elements.data[index];
        } break;
        #line 232 "src/analyzer/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 232 "src/analyzer/Expression.pv"
            struct NamespaceCpp* ns_info = type->namespacecpp_value;
            #line 233 "src/analyzer/Expression.pv"
            struct Type* type = HashMap_str_Type__find(&ns_info->types, &member->value);
            #line 234 "src/analyzer/Expression.pv"
            if (type != 0) {
                #line 234 "src/analyzer/Expression.pv"
                return type;
            }

            #line 236 "src/analyzer/Expression.pv"
            struct Type* value = HashMap_str_Type__find(&ns_info->values, &member->value);
            #line 237 "src/analyzer/Expression.pv"
            if (value != 0) {
                #line 237 "src/analyzer/Expression.pv"
                return value;
            }

            #line 239 "src/analyzer/Expression.pv"
            if (output_error) {
                #line 239 "src/analyzer/Expression.pv"
                Context__error_token(context, member, "Namespace does not have this member");
            }

            #line 241 "src/analyzer/Expression.pv"
            return 0;
        } break;
        #line 243 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 243 "src/analyzer/Expression.pv"
            return type;
        } break;
        #line 244 "src/analyzer/Expression.pv"
        default: {
            #line 244 "src/analyzer/Expression.pv"
            Context__error_token(context, member, "Type does not have members");
        } break;
    }

    #line 247 "src/analyzer/Expression.pv"
    return 0;
}

#line 250 "src/analyzer/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments) {
    #line 251 "src/analyzer/Expression.pv"
    struct GenericMap generic_map = GenericMap__from_generics(context->allocator, &func_info->generics);

    #line 253 "src/analyzer/Expression.pv"
    uintptr_t i = 0;
    #line 254 "src/analyzer/Expression.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(generics);
    #line 254 "src/analyzer/Expression.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 254 "src/analyzer/Expression.pv"
        struct Type* generic = ArrayIter_ref_Type__value(&__iter);

        #line 255 "src/analyzer/Expression.pv"
        struct Type* target = Array_Type__get(&generic_map.array, i);
        #line 256 "src/analyzer/Expression.pv"
        if (target != 0) {
            #line 256 "src/analyzer/Expression.pv"
            *target = *generic;
        }
        #line 257 "src/analyzer/Expression.pv"
        i += 1;
    } }

    #line 260 "src/analyzer/Expression.pv"
    if (i == generic_map.array.length) {
        #line 261 "src/analyzer/Expression.pv"
        return ArenaAllocator__store_GenericMap(context->allocator, generic_map);
    }

    #line 264 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_Parameter params = Array_Parameter__iter(&func_info->parameters);
    #line 265 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);

    #line 267 "src/analyzer/Expression.pv"
    while (ArrayIter_ref_Parameter__next(&params) && ArrayIter_ref_InvokeArgument__next(&args)) {
        #line 268 "src/analyzer/Expression.pv"
        struct Type* param_type = &ArrayIter_ref_Parameter__value(&params)->type;
        #line 269 "src/analyzer/Expression.pv"
        struct Type* arg_type = &ArrayIter_ref_InvokeArgument__value(&args)->value->return_type;

        #line 271 "src/analyzer/Expression.pv"
        Expression__resolve_generic_type(context, param_type, arg_type, &generic_map);
    }

    #line 274 "src/analyzer/Expression.pv"
    return ArenaAllocator__store_GenericMap(context->allocator, generic_map);
}

#line 277 "src/analyzer/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map) {
    #line 278 "src/analyzer/Expression.pv"
    switch (param_type->type) {
        #line 279 "src/analyzer/Expression.pv"
        case TYPE__GENERIC: {
            #line 279 "src/analyzer/Expression.pv"
            struct Generic* generic = param_type->generic_value;
            #line 280 "src/analyzer/Expression.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 281 "src/analyzer/Expression.pv"
            if (generic_type != 0) {
                #line 281 "src/analyzer/Expression.pv"
                *generic_type = *arg_type;
            }
        } break;
        #line 283 "src/analyzer/Expression.pv"
        case TYPE__INDIRECT: {
            #line 283 "src/analyzer/Expression.pv"
            struct Indirect* indirect_type = param_type->indirect_value;
            #line 284 "src/analyzer/Expression.pv"
            switch (arg_type->type) {
                #line 285 "src/analyzer/Expression.pv"
                case TYPE__INDIRECT: {
                    #line 285 "src/analyzer/Expression.pv"
                    struct Indirect* indirect = arg_type->indirect_value;
                    #line 286 "src/analyzer/Expression.pv"
                    Expression__resolve_generic_type(context, &indirect_type->to, &indirect->to, generic_map);
                } break;
                #line 288 "src/analyzer/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 291 "src/analyzer/Expression.pv"
        default: {
        } break;
    }
}

#line 295 "src/analyzer/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call) {
    #line 296 "src/analyzer/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 298 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 299 "src/analyzer/Expression.pv"
        case TYPE__SELF: {
            #line 299 "src/analyzer/Expression.pv"
            {
                #line 299 "src/analyzer/Expression.pv"
                type = context->type_self;
            }
        } break;
        #line 300 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 303 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 304 "src/analyzer/Expression.pv"
        case TYPE__TYPEDEF_C: {
            #line 304 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 305 "src/analyzer/Expression.pv"
        case TYPE__UNION_C: {
            #line 305 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 306 "src/analyzer/Expression.pv"
        case TYPE__STRUCT_C: {
            #line 306 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 307 "src/analyzer/Expression.pv"
        case TYPE__TUPLE: {
            #line 307 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 308 "src/analyzer/Expression.pv"
        case TYPE__STRUCT: {
            #line 308 "src/analyzer/Expression.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 308 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map2 = type->struct_value._1;
            #line 309 "src/analyzer/Expression.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 309 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 309 "src/analyzer/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 310 "src/analyzer/Expression.pv"
                struct StructField* param = HashMap_str_StructField__find(&struct_info->fields, &arg->name->value);

                #line 312 "src/analyzer/Expression.pv"
                if (param == 0) {
                    #line 313 "src/analyzer/Expression.pv"
                    Context__error_token(context, arg->name, "Unable to find field in struct");
                    #line 314 "src/analyzer/Expression.pv"
                    return false;
                }

                #line 317 "src/analyzer/Expression.pv"
                struct Type* param_type = &param->type;

                #line 319 "src/analyzer/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 320 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 322 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 325 "src/analyzer/Expression.pv"
                if (param_type == 0) {
                    #line 326 "src/analyzer/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve field type");
                    #line 327 "src/analyzer/Expression.pv"
                    return false;
                }

                #line 330 "src/analyzer/Expression.pv"
                Expression__validate_type(arg->value, context, param_type);
            } }

            #line 333 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 335 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION: {
            #line 335 "src/analyzer/Expression.pv"
            struct Function* function = type->function_value._0;
            #line 335 "src/analyzer/Expression.pv"
            struct GenericMap* generic_map2 = type->function_value._1;
            #line 336 "src/analyzer/Expression.pv"
            if (function == 0 || function->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 336 "src/analyzer/Expression.pv"
                return true;
            }

            #line 338 "src/analyzer/Expression.pv"
            if (function->parameters.length != arguments_length) {
                #line 339 "src/analyzer/Expression.pv"
                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 340 "src/analyzer/Expression.pv"
                String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });

                #line 342 "src/analyzer/Expression.pv"
                if (is_member_call) {
                    #line 343 "src/analyzer/Expression.pv"
                    String__append_usize(&message, function->parameters.length - 1);
                } else {
                    #line 345 "src/analyzer/Expression.pv"
                    String__append_usize(&message, function->parameters.length);
                }

                #line 348 "src/analyzer/Expression.pv"
                Context__error_token(context, token, String__c_str(&message));
                #line 349 "src/analyzer/Expression.pv"
                return false;
            }

            #line 352 "src/analyzer/Expression.pv"
            struct ArrayIter_ref_Parameter param_iter = Array_Parameter__iter(&function->parameters);
            #line 353 "src/analyzer/Expression.pv"
            struct ArrayIter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

            #line 355 "src/analyzer/Expression.pv"
            if ((is_member_call)) {
                #line 356 "src/analyzer/Expression.pv"
                ArrayIter_ref_Parameter__next(&param_iter);
                #line 357 "src/analyzer/Expression.pv"
                ArrayIter_ref_InvokeArgument__next(&args_iter);

                #line 359 "src/analyzer/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
                #line 360 "src/analyzer/Expression.pv"
                struct Type* param_type = &ArrayIter_ref_Parameter__value(&param_iter)->type;

                #line 362 "src/analyzer/Expression.pv"
                if (Type__is_indirect(param_type) && !Type__is_indirect(&arg->value->return_type)) {
                    #line 363 "src/analyzer/Expression.pv"
                    struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arg->value->return_type) });
                    #line 364 "src/analyzer/Expression.pv"
                    arg->value = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = (struct str){ .ptr = "&", .length = strlen("&") }, ._1 = arg->value} }, new_type);
                }
            }

            #line 368 "src/analyzer/Expression.pv"
            while (ArrayIter_ref_Parameter__next(&param_iter) && ArrayIter_ref_InvokeArgument__next(&args_iter)) {
                #line 369 "src/analyzer/Expression.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
                #line 370 "src/analyzer/Expression.pv"
                struct Parameter* param = ArrayIter_ref_Parameter__value(&param_iter);
                #line 371 "src/analyzer/Expression.pv"
                struct Type* param_type = &param->type;

                #line 373 "src/analyzer/Expression.pv"
                if (generic_map2->map.length > 0) {
                    #line 374 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map2, generic_map);
                } else if (generic_map != 0) {
                    #line 376 "src/analyzer/Expression.pv"
                    param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
                }

                #line 379 "src/analyzer/Expression.pv"
                if (param_type == 0) {
                    #line 380 "src/analyzer/Expression.pv"
                    Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
                    #line 381 "src/analyzer/Expression.pv"
                    return false;
                }

                #line 384 "src/analyzer/Expression.pv"
                Expression__validate_type(arg->value, context, param_type);
            }

            #line 387 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 389 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 389 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 390 "src/analyzer/Expression.pv"
        case TYPE__CLASS_CPP: {
            #line 390 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 391 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 391 "src/analyzer/Expression.pv"
            return true;
        } break;
        #line 392 "src/analyzer/Expression.pv"
        default: {
            #line 392 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 395 "src/analyzer/Expression.pv"
    return false;
}

#line 398 "src/analyzer/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map) {
    #line 399 "src/analyzer/Expression.pv"
    uintptr_t arguments_length = arguments->length;

    #line 401 "src/analyzer/Expression.pv"
    if (variant->types.length != arguments_length) {
        #line 402 "src/analyzer/Expression.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 403 "src/analyzer/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Number of arguments does not match, expected ", .length = strlen("Number of arguments does not match, expected ") });
        #line 404 "src/analyzer/Expression.pv"
        String__append_usize(&message, variant->types.length);
        #line 405 "src/analyzer/Expression.pv"
        Context__error_token(context, token, String__c_str(&message));
        #line 406 "src/analyzer/Expression.pv"
        return false;
    }

    #line 409 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_Type param_iter = Array_Type__iter(&variant->types);
    #line 410 "src/analyzer/Expression.pv"
    struct ArrayIter_ref_InvokeArgument args_iter = Array_InvokeArgument__iter(arguments);

    #line 412 "src/analyzer/Expression.pv"
    while (ArrayIter_ref_Type__next(&param_iter) && ArrayIter_ref_InvokeArgument__next(&args_iter)) {
        #line 413 "src/analyzer/Expression.pv"
        struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args_iter);
        #line 414 "src/analyzer/Expression.pv"
        struct Type* param_type = ArrayIter_ref_Type__value(&param_iter);

        #line 416 "src/analyzer/Expression.pv"
        if (generic_map != 0) {
            #line 417 "src/analyzer/Expression.pv"
            param_type = Context__resolve_type(context->allocator, param_type, generic_map, 0);
        }

        #line 420 "src/analyzer/Expression.pv"
        if (param_type == 0) {
            #line 421 "src/analyzer/Expression.pv"
            Context__error_token(context, arg->value->token, "Unable to resolve parameter type");
            #line 422 "src/analyzer/Expression.pv"
            return false;
        }

        #line 425 "src/analyzer/Expression.pv"
        Expression__validate_type(arg->value, context, param_type);
    }

    #line 428 "src/analyzer/Expression.pv"
    return true;
}

#line 431 "src/analyzer/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map) {
    #line 432 "src/analyzer/Expression.pv"
    switch (type->type) {
        #line 433 "src/analyzer/Expression.pv"
        case TYPE__TUPLE: {
            #line 433 "src/analyzer/Expression.pv"
            return type;
        } break;
        #line 434 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION: {
            #line 434 "src/analyzer/Expression.pv"
            struct Function* func_info = type->function_value._0;
            #line 434 "src/analyzer/Expression.pv"
            struct GenericMap* func_generic_map = type->function_value._1;
            #line 435 "src/analyzer/Expression.pv"
            return Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, generic_map);
        } break;
        #line 437 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 437 "src/analyzer/Expression.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 437 "src/analyzer/Expression.pv"
            return &func_info->return_type;
        } break;
        #line 438 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 438 "src/analyzer/Expression.pv"
            return type;
        } break;
        #line 439 "src/analyzer/Expression.pv"
        default: {
            #line 439 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Type can't be called");
        } break;
    }

    #line 442 "src/analyzer/Expression.pv"
    return 0;
}

#line 445 "src/analyzer/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 446 "src/analyzer/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 446 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 448 "src/analyzer/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 449 "src/analyzer/Expression.pv"
    if (func_return_type == 0) {
        #line 449 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 451 "src/analyzer/Expression.pv"
    struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
    #line 452 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = arguments} }, func_return_type);
}

#line 455 "src/analyzer/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map) {
    #line 456 "src/analyzer/Expression.pv"
    if (!Expression__validate_arguments(context, token, type, &arguments, generic_map, true)) {
        #line 456 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 458 "src/analyzer/Expression.pv"
    struct Type* func_return_type = Expression__get_return_type(context, type, token, generic_map);
    #line 459 "src/analyzer/Expression.pv"
    if (func_return_type == 0) {
        #line 459 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 461 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, func_return_type);
}

#line 464 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics) {
    #line 465 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 466 "src/analyzer/Expression.pv"
        struct Token* variant_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 467 "src/analyzer/Expression.pv"
        if (variant_name == 0) {
            #line 467 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 469 "src/analyzer/Expression.pv"
        struct EnumVariant* variant = Expression__get_enum_variant(context, enum_type, variant_name);
        #line 470 "src/analyzer/Expression.pv"
        if (variant == 0) {
            #line 470 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 472 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 474 "src/analyzer/Expression.pv"
        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 475 "src/analyzer/Expression.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                #line 475 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 477 "src/analyzer/Expression.pv"
            while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 478 "src/analyzer/Expression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 479 "src/analyzer/Expression.pv"
                if (argument == 0) {
                    #line 479 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 481 "src/analyzer/Expression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                #line 483 "src/analyzer/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                    #line 484 "src/analyzer/Expression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 485 "src/analyzer/Expression.pv"
                    return 0;
                }
            }

            #line 489 "src/analyzer/Expression.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 489 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 493 "src/analyzer/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 495 "src/analyzer/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(enum_type, context);
        #line 496 "src/analyzer/Expression.pv"
        if (!Expression__validate_enum_arguments(context, token, variant, &arguments, generic_map)) {
            #line 496 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 498 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 501 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = enum_type }, enum_type);
}

#line 504 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics) {
    #line 505 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 506 "src/analyzer/Expression.pv"
        struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 507 "src/analyzer/Expression.pv"
        if (member == 0) {
            #line 507 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 509 "src/analyzer/Expression.pv"
        struct Type* member_type = Expression__get_member_type(context, struct_type, member, true);
        #line 510 "src/analyzer/Expression.pv"
        if (member_type == 0) {
            #line 510 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 512 "src/analyzer/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);

        #line 514 "src/analyzer/Expression.pv"
        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
            #line 515 "src/analyzer/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
        } else {
            #line 517 "src/analyzer/Expression.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                #line 517 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 519 "src/analyzer/Expression.pv"
            struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 521 "src/analyzer/Expression.pv"
            while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 522 "src/analyzer/Expression.pv"
                struct Expression* argument = Expression__parse(context, generics);
                #line 523 "src/analyzer/Expression.pv"
                if (argument == 0) {
                    #line 523 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 525 "src/analyzer/Expression.pv"
                Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                #line 527 "src/analyzer/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                    #line 528 "src/analyzer/Expression.pv"
                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                    #line 529 "src/analyzer/Expression.pv"
                    return 0;
                }
            }

            #line 533 "src/analyzer/Expression.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 533 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 535 "src/analyzer/Expression.pv"
            if (!Expression__validate_arguments(context, token, member_type, &arguments, generic_map, false)) {
                #line 535 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 537 "src/analyzer/Expression.pv"
            struct Type* func_return_type = Expression__get_return_type(context, member_type, token, generic_map);
            #line 538 "src/analyzer/Expression.pv"
            if (func_return_type == 0) {
                #line 538 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 540 "src/analyzer/Expression.pv"
            struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = member_type }, member_type);
            #line 541 "src/analyzer/Expression.pv"
            return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
        }
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 544 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 546 "src/analyzer/Expression.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 547 "src/analyzer/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 548 "src/analyzer/Expression.pv"
            if (name == 0) {
                #line 548 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 550 "src/analyzer/Expression.pv"
            struct Expression* value = 0;
            #line 551 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 552 "src/analyzer/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 554 "src/analyzer/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 555 "src/analyzer/Expression.pv"
                if (return_type == 0) {
                    #line 556 "src/analyzer/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 557 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 560 "src/analyzer/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 563 "src/analyzer/Expression.pv"
            if (value == 0) {
                #line 563 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 565 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 567 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
                #line 568 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 569 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 573 "src/analyzer/Expression.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 573 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 575 "src/analyzer/Expression.pv"
        struct GenericMap* generic_map = Type__get_generic_map(struct_type, context);
        #line 576 "src/analyzer/Expression.pv"
        if (!Expression__validate_arguments(context, token, struct_type, &fields, generic_map, false)) {
            #line 576 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 578 "src/analyzer/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 579 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 581 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 583 "src/analyzer/Expression.pv"
        uintptr_t field_index = 0;
        #line 584 "src/analyzer/Expression.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 585 "src/analyzer/Expression.pv"
            struct String name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 586 "src/analyzer/Expression.pv"
            String__append(&name, (struct str){ .ptr = "_", .length = strlen("_") });
            #line 587 "src/analyzer/Expression.pv"
            String__append_usize(&name, field_index);
            #line 588 "src/analyzer/Expression.pv"
            struct str name_str = String__as_str(&name);

            #line 590 "src/analyzer/Expression.pv"
            struct Token name_token = *Context__current(context);
            #line 591 "src/analyzer/Expression.pv"
            name_token.value = name_str;

            #line 593 "src/analyzer/Expression.pv"
            struct Expression* value = Expression__parse(context, generics);
            #line 594 "src/analyzer/Expression.pv"
            if (value == 0) {
                #line 594 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 596 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) {
                .name = ArenaAllocator__store_Token(context->allocator, name_token),
                .value = value,
            });

            #line 601 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 602 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 603 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 606 "src/analyzer/Expression.pv"
            field_index += 1;
        }

        #line 609 "src/analyzer/Expression.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 609 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 611 "src/analyzer/Expression.pv"
        struct Expression* struct_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
        #line 612 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = struct_expression, ._1 = fields} }, struct_type);
    }

    #line 615 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = struct_type }, struct_type);
}

#line 618 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics) {
    #line 619 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 620 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument fields = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 622 "src/analyzer/Expression.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 623 "src/analyzer/Expression.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 624 "src/analyzer/Expression.pv"
            if (name == 0) {
                #line 624 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 626 "src/analyzer/Expression.pv"
            struct Expression* value = 0;
            #line 627 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
                #line 628 "src/analyzer/Expression.pv"
                value = Expression__parse(context, generics);
            } else {
                #line 630 "src/analyzer/Expression.pv"
                struct Type* return_type = Context__get_value(context, name->value);
                #line 631 "src/analyzer/Expression.pv"
                if (return_type == 0) {
                    #line 632 "src/analyzer/Expression.pv"
                    Context__error_token(context, name, "Unable to find variable with this name");
                    #line 633 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 636 "src/analyzer/Expression.pv"
                value = Expression__make(context->allocator, name, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = name->value }, return_type);
            }

            #line 639 "src/analyzer/Expression.pv"
            if (value == 0) {
                #line 639 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 641 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&fields, (struct InvokeArgument) { .name = name, .value = value });

            #line 643 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
                #line 644 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
                #line 645 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 649 "src/analyzer/Expression.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 649 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 651 "src/analyzer/Expression.pv"
        if (!Expression__validate_arguments(context, token, &parent->return_type, &fields, 0, false)) {
            #line 651 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 653 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = fields} }, &parent->return_type);
    } else if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 655 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 657 "src/analyzer/Expression.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 658 "src/analyzer/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 659 "src/analyzer/Expression.pv"
            if (argument == 0) {
                #line 659 "src/analyzer/Expression.pv"
                return 0;
            }

            #line 661 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 663 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 664 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 665 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 669 "src/analyzer/Expression.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 669 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 671 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent, ._1 = arguments} }, &parent->return_type);
    }

    #line 674 "src/analyzer/Expression.pv"
    return parent;
}

#line 677 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics) {
    #line 678 "src/analyzer/Expression.pv"
    struct Token* token = &context->tokens[context->pos];

    #line 680 "src/analyzer/Expression.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "new")) {
        #line 681 "src/analyzer/Expression.pv"
        struct Expression* placement = 0;
        #line 682 "src/analyzer/Expression.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 683 "src/analyzer/Expression.pv"
            placement = Expression__parse(context, generics);
            #line 684 "src/analyzer/Expression.pv"
            if (placement == 0) {
                #line 684 "src/analyzer/Expression.pv"
                return 0;
            }
            #line 685 "src/analyzer/Expression.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 685 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 688 "src/analyzer/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 689 "src/analyzer/Expression.pv"
        if (expression == 0) {
            #line 689 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 691 "src/analyzer/Expression.pv"
        struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, expression->return_type);
        #line 692 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__NEW, .new_value = { ._0 = placement, ._1 = expression} } }, &(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
    } else if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "delete")) {
        #line 694 "src/analyzer/Expression.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 695 "src/analyzer/Expression.pv"
        if (expression == 0) {
            #line 695 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 697 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__CPP_EXPRESSION, .cppexpression_value = (struct CppExpression) { .type = CPP_EXPRESSION__DELETE, .delete_value = expression } }, &(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 });
    }

    #line 700 "src/analyzer/Expression.pv"
    Context__error(context, "Expected new or delete in cpp expression");
    #line 701 "src/analyzer/Expression.pv"
    return 0;
}

#line 704 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 705 "src/analyzer/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 705 "src/analyzer/Expression.pv"
        return false;
    }

    #line 707 "src/analyzer/Expression.pv"
    switch (inner->return_type.type) {
        #line 708 "src/analyzer/Expression.pv"
        case TYPE__NAMESPACE_CPP: {
        } break;
        #line 709 "src/analyzer/Expression.pv"
        case TYPE__CLASS_CPP: {
        } break;
        #line 710 "src/analyzer/Expression.pv"
        default: {
            #line 711 "src/analyzer/Expression.pv"
            Context__error(context, "Unhandled type member expression");
            #line 712 "src/analyzer/Expression.pv"
            return 0;
        } break;
    }

    #line 716 "src/analyzer/Expression.pv"
    struct Token* member = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 717 "src/analyzer/Expression.pv"
    if (member == 0) {
        #line 717 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 719 "src/analyzer/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member, true);
    #line 720 "src/analyzer/Expression.pv"
    if (member_type == 0) {
        #line 720 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 722 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, member, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION, .memberstaticexpression_value = { ._0 = inner, ._1 = member->value} }, member_type);
}

#line 725 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 726 "src/analyzer/Expression.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ".")) {
        #line 726 "src/analyzer/Expression.pv"
        return false;
    }

    #line 728 "src/analyzer/Expression.pv"
    struct Token* member_name = Context__current(context);
    #line 729 "src/analyzer/Expression.pv"
    if (member_name == 0) {
        #line 729 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 731 "src/analyzer/Expression.pv"
    if (member_name->type != TOKEN_TYPE__NUMBER && member_name->type != TOKEN_TYPE__IDENTIFIER) {
        #line 732 "src/analyzer/Expression.pv"
        Context__error(context, "Unexpected token, expected Identifier or Number");
    }

    #line 735 "src/analyzer/Expression.pv"
    Context__next_token(context);

    #line 737 "src/analyzer/Expression.pv"
    struct Type* member_type = Expression__get_member_type(context, &inner->return_type, member_name, true);
    #line 738 "src/analyzer/Expression.pv"
    if (member_type == 0) {
        #line 738 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 740 "src/analyzer/Expression.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&inner->return_type, context);
    #line 741 "src/analyzer/Expression.pv"
    struct Array_Type parsed_generics = (struct Array_Type) {};
    #line 742 "src/analyzer/Expression.pv"
    struct Function* func_info = 0;

    #line 744 "src/analyzer/Expression.pv"
    bool is_function = false;
    #line 745 "src/analyzer/Expression.pv"
    switch (member_type->type) {
        #line 746 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION: {
            #line 746 "src/analyzer/Expression.pv"
            struct Function* func_info2 = member_type->function_value._0;
            #line 747 "src/analyzer/Expression.pv"
            is_function = true;
            #line 748 "src/analyzer/Expression.pv"
            func_info = func_info2;
        } break;
        #line 750 "src/analyzer/Expression.pv"
        case TYPE__FUNCTION_C: {
            #line 750 "src/analyzer/Expression.pv"
            is_function = true;
        } break;
        #line 751 "src/analyzer/Expression.pv"
        case TYPE__UNKNOWN: {
            #line 751 "src/analyzer/Expression.pv"
            is_function = true;
        } break;
        #line 752 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 755 "src/analyzer/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 756 "src/analyzer/Expression.pv"
        parsed_generics = Context__parse_generics(context, generics);
    }

    #line 759 "src/analyzer/Expression.pv"
    if (is_function && Context__check_value(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 760 "src/analyzer/Expression.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
            #line 760 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 762 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 764 "src/analyzer/Expression.pv"
        if (func_info != 0 && func_info->parameters.length > 0 && str__eq(func_info->parameters.data[0].name->value, (struct str){ .ptr = "self", .length = strlen("self") })) {
            #line 765 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = inner });
        }

        #line 768 "src/analyzer/Expression.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 769 "src/analyzer/Expression.pv"
            struct Expression* argument = Expression__parse(context, generics);
            #line 770 "src/analyzer/Expression.pv"
            if (argument == 0) {
                #line 770 "src/analyzer/Expression.pv"
                return 0;
            }
            #line 771 "src/analyzer/Expression.pv"
            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

            #line 773 "src/analyzer/Expression.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 774 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 775 "src/analyzer/Expression.pv"
                return 0;
            }
        }

        #line 779 "src/analyzer/Expression.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 779 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 781 "src/analyzer/Expression.pv"
        if (func_info != 0 && func_info->generics.array.length > 0) {
            #line 782 "src/analyzer/Expression.pv"
            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
            #line 783 "src/analyzer/Expression.pv"
            member_type = Module__make_type_usage(context->module, member_type, &func_generics->array);
        }

        #line 786 "src/analyzer/Expression.pv"
        if (func_info != 0 && (func_info->type == FUNCTION_TYPE__BUILTIN || func_info->type == FUNCTION_TYPE__METHOD_CPP)) {
            #line 787 "src/analyzer/Expression.pv"
            struct Expression* member_expression = Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
            #line 788 "src/analyzer/Expression.pv"
            return Expression__make_member_function_call(context, member_expression, member_name, member_type, arguments, generic_map);
        } else {
            #line 790 "src/analyzer/Expression.pv"
            return Expression__make_type_function_call(context, member_name, member_type, arguments, generic_map);
        }
    } else {
        #line 793 "src/analyzer/Expression.pv"
        if (generic_map != 0) {
            #line 794 "src/analyzer/Expression.pv"
            member_type = Context__resolve_type(context->allocator, member_type, generic_map, 0);
        }

        #line 797 "src/analyzer/Expression.pv"
        return Expression__make(context->allocator, member_name, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = inner, ._1 = member_name->value} }, member_type);
    }
}

#line 801 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 802 "src/analyzer/Expression.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[") == 0) {
        #line 802 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 804 "src/analyzer/Expression.pv"
    struct Expression* index_expr = Expression__parse(context, generics);
    #line 805 "src/analyzer/Expression.pv"
    if (index_expr == 0) {
        #line 805 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 807 "src/analyzer/Expression.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]") == 0) {
        #line 807 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 809 "src/analyzer/Expression.pv"
    switch (index_expr->data.type) {
        #line 810 "src/analyzer/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 810 "src/analyzer/Expression.pv"
            struct Expression* target = index_expr->data.invoke_value._0;
            #line 810 "src/analyzer/Expression.pv"
            struct Array_InvokeArgument args = index_expr->data.invoke_value._1;
            #line 811 "src/analyzer/Expression.pv"
            switch (target->return_type.type) {
                #line 812 "src/analyzer/Expression.pv"
                case TYPE__ENUM: {
                    #line 812 "src/analyzer/Expression.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 813 "src/analyzer/Expression.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 814 "src/analyzer/Expression.pv"
                        struct Sequence* sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence) {
                            .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE },
                            .element = *Type__deref(&inner->return_type),
                            .element_pointer = inner->return_type,
                        });

                        #line 820 "src/analyzer/Expression.pv"
                        struct Expression* start = args.data[0].value;
                        #line 821 "src/analyzer/Expression.pv"
                        struct Expression* end = args.data[1].value;

                        #line 823 "src/analyzer/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 825 "src/analyzer/Expression.pv"
                        struct Token* argument_name_data = ArenaAllocator__store_Token(context->allocator, *index_expr->token);
                        #line 826 "src/analyzer/Expression.pv"
                        argument_name_data->type = TOKEN_TYPE__IDENTIFIER;
                        #line 827 "src/analyzer/Expression.pv"
                        argument_name_data->value = (struct str){ .ptr = "data", .length = strlen("data") };

                        #line 829 "src/analyzer/Expression.pv"
                        struct Token* argument_name_length = ArenaAllocator__store_Token(context->allocator, *argument_name_data);
                        #line 830 "src/analyzer/Expression.pv"
                        argument_name_length->value = (struct str){ .ptr = "length", .length = strlen("length") };

                        #line 832 "src/analyzer/Expression.pv"
                        if (Expression__is_zero(start)) {
                            #line 833 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_data, .value = inner });
                            #line 834 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = argument_name_length, .value = end });
                        } else {
                            #line 836 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_data,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = (struct str){ .ptr = "+", .length = strlen("+") }, ._2 = start} }, &sequence->element_pointer),
                            });

                            #line 841 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) {
                                .name = argument_name_length,
                                .value = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = end, ._1 = (struct str){ .ptr = "-", .length = strlen("-") }, ._2 = start} }, &context->root->type_usize),
                            });
                        }

                        #line 847 "src/analyzer/Expression.pv"
                        struct Type* sequence_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence });
                        #line 848 "src/analyzer/Expression.pv"
                        struct Expression* sequence_expr = Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = sequence_type }, sequence_type);
                        #line 849 "src/analyzer/Expression.pv"
                        return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = sequence_expr, ._1 = arguments} }, sequence_type);
                    }
                } break;
                #line 852 "src/analyzer/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 855 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 858 "src/analyzer/Expression.pv"
    struct Type* inner_return_type = &inner->return_type;
    #line 859 "src/analyzer/Expression.pv"
    struct Type* element_type = 0;

    #line 861 "src/analyzer/Expression.pv"
    if (Type__is_reference_sequence_dynamic(inner_return_type)) {
        #line 862 "src/analyzer/Expression.pv"
        switch (Type__deref_1(inner_return_type)->type) {
            #line 863 "src/analyzer/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 863 "src/analyzer/Expression.pv"
                struct Sequence* sequence = Type__deref_1(inner_return_type)->sequence_value;
                #line 864 "src/analyzer/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 866 "src/analyzer/Expression.pv"
            default: {
            } break;
        }
    } else {
        #line 869 "src/analyzer/Expression.pv"
        switch (inner_return_type->type) {
            #line 870 "src/analyzer/Expression.pv"
            case TYPE__INDIRECT: {
                #line 870 "src/analyzer/Expression.pv"
                struct Indirect* indirect = inner_return_type->indirect_value;
                #line 871 "src/analyzer/Expression.pv"
                element_type = &indirect->to;
            } break;
            #line 873 "src/analyzer/Expression.pv"
            case TYPE__SEQUENCE: {
                #line 873 "src/analyzer/Expression.pv"
                struct Sequence* sequence = inner_return_type->sequence_value;
                #line 874 "src/analyzer/Expression.pv"
                element_type = &sequence->element;
            } break;
            #line 876 "src/analyzer/Expression.pv"
            default: {
            } break;
        }
    }

    #line 880 "src/analyzer/Expression.pv"
    if (element_type == 0 && context->module->mode_cpp) {
        #line 881 "src/analyzer/Expression.pv"
        element_type = Type__to_ptr(&(struct Type) { .type = TYPE__UNKNOWN, .unknown_value = { ._0 = (struct str){ .ptr = "", .length = strlen("") }, ._1 = (struct Array_Type) {}} }, context->allocator);
    }

    #line 884 "src/analyzer/Expression.pv"
    if (element_type == 0) {
        #line 885 "src/analyzer/Expression.pv"
        Context__error_token(context, index_expr->token, "Type is not indexable");
        #line 886 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 889 "src/analyzer/Expression.pv"
    return Expression__make(context->allocator, index_expr->token, (struct ExpressionData) { .type = EXPRESSION_DATA__INDEX_EXPRESSION, .indexexpression_value = { ._0 = inner, ._1 = index_expr} }, element_type);
}

#line 892 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_inner(struct Context* context, struct Expression* inner, struct Generics* generics) {
    #line 893 "src/analyzer/Expression.pv"
    struct Token* token = Context__current(context);
    #line 894 "src/analyzer/Expression.pv"
    struct Expression* result = 0;

    #line 896 "src/analyzer/Expression.pv"
    if (Token__eq(token, TOKEN_TYPE__SYMBOL, ".")) {
        #line 897 "src/analyzer/Expression.pv"
        result = Expression__parse_instance_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "::")) {
        #line 899 "src/analyzer/Expression.pv"
        result = Expression__parse_type_member_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
        #line 901 "src/analyzer/Expression.pv"
        result = Expression__parse_index_expression(context, inner, generics);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "^") || Token__eq(token, TOKEN_TYPE__SYMBOL, "|") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "<<")) {
        #line 903 "src/analyzer/Expression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 904 "src/analyzer/Expression.pv"
        if (operator == 0) {
            #line 904 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 906 "src/analyzer/Expression.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 907 "src/analyzer/Expression.pv"
        if (value == 0) {
            #line 907 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 909 "src/analyzer/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = operator->value, ._2 = value} }, &inner->return_type);
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "==") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!=") || Token__eq(token, TOKEN_TYPE__SYMBOL, "<=") || Token__eq(token, TOKEN_TYPE__SYMBOL, ">=") || Token__eq(token, TOKEN_TYPE__SYMBOL, "<") || Token__eq(token, TOKEN_TYPE__SYMBOL, ">") || Token__eq(token, TOKEN_TYPE__SYMBOL, "||") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&&")) {
        #line 911 "src/analyzer/Expression.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 912 "src/analyzer/Expression.pv"
        if (operator == 0) {
            #line 912 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 914 "src/analyzer/Expression.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 915 "src/analyzer/Expression.pv"
        if (value == 0) {
            #line 915 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 917 "src/analyzer/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__BINARY_EXPRESSION, .binaryexpression_value = { ._0 = inner, ._1 = operator->value, ._2 = value} }, Type__to_ptr(&(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, "bool") }, context->allocator));
    } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
        #line 919 "src/analyzer/Expression.pv"
        switch (Type__resolve_typedef_function(&inner->return_type)->type) {
            #line 920 "src/analyzer/Expression.pv"
            case TYPE__FUNCTION: {
                #line 920 "src/analyzer/Expression.pv"
                struct Function* func_info = Type__resolve_typedef_function(&inner->return_type)->function_value._0;
                #line 921 "src/analyzer/Expression.pv"
                if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                    #line 921 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 923 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 925 "src/analyzer/Expression.pv"
                while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                    #line 926 "src/analyzer/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 927 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 929 "src/analyzer/Expression.pv"
                    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                        #line 930 "src/analyzer/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 931 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 935 "src/analyzer/Expression.pv"
                if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                    #line 935 "src/analyzer/Expression.pv"
                    return 0;
                }
                #line 936 "src/analyzer/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 938 "src/analyzer/Expression.pv"
            case TYPE__FUNCTION_C: {
                #line 938 "src/analyzer/Expression.pv"
                struct FunctionC* func_info = Type__resolve_typedef_function(&inner->return_type)->functionc_value;
                #line 939 "src/analyzer/Expression.pv"
                if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                    #line 939 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 941 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 943 "src/analyzer/Expression.pv"
                while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                    #line 944 "src/analyzer/Expression.pv"
                    struct Expression* argument = Expression__parse(context, generics);
                    #line 945 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                    #line 947 "src/analyzer/Expression.pv"
                    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                        #line 948 "src/analyzer/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 949 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 953 "src/analyzer/Expression.pv"
                if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                    #line 953 "src/analyzer/Expression.pv"
                    return 0;
                }
                #line 954 "src/analyzer/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = inner, ._1 = arguments} }, &func_info->return_type);
            } break;
            #line 956 "src/analyzer/Expression.pv"
            case TYPE__CLASS_CPP: {
                #line 957 "src/analyzer/Expression.pv"
                struct Expression* expr = Expression__parse_class(context, token, inner, generics);
                #line 958 "src/analyzer/Expression.pv"
                if (expr == 0) {
                    #line 958 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 960 "src/analyzer/Expression.pv"
                return expr;
            } break;
            #line 962 "src/analyzer/Expression.pv"
            default: {
                #line 963 "src/analyzer/Expression.pv"
                Context__error_token(context, token, "Unexpected token when parsing open bracket");
                #line 964 "src/analyzer/Expression.pv"
                return 0;
            } break;
        }
    } else {
        #line 968 "src/analyzer/Expression.pv"
        return inner;
    }

    #line 971 "src/analyzer/Expression.pv"
    if (result == 0) {
        #line 971 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 973 "src/analyzer/Expression.pv"
    return Expression__parse_inner(context, result, generics);
}

#line 976 "src/analyzer/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics) {
    #line 977 "src/analyzer/Expression.pv"
    struct Token* token = Context__current(context);
    #line 978 "src/analyzer/Expression.pv"
    enum TokenType token_type = token->type;
    #line 979 "src/analyzer/Expression.pv"
    struct Expression* result = 0;

    #line 981 "src/analyzer/Expression.pv"
    switch (token_type) {
        #line 982 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 983 "src/analyzer/Expression.pv"
            struct Type* return_type = Context__get_value(context, token->value);

            #line 985 "src/analyzer/Expression.pv"
            if (context->module->mode_cpp && (str__eq(token->value, (struct str){ .ptr = "new", .length = strlen("new") }) || str__eq(token->value, (struct str){ .ptr = "delete", .length = strlen("delete") }))) {
                #line 986 "src/analyzer/Expression.pv"
                return Expression__parse_cpp(context, generics);
            } else if (return_type == 0) {
                #line 988 "src/analyzer/Expression.pv"
                struct Type* type = Context__parse_type2(context, generics);
                #line 989 "src/analyzer/Expression.pv"
                if (type != 0) {
                    #line 990 "src/analyzer/Expression.pv"
                    switch (Type__resolve_typedef(type)->type) {
                        #line 991 "src/analyzer/Expression.pv"
                        case TYPE__ENUM: {
                            #line 991 "src/analyzer/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 992 "src/analyzer/Expression.pv"
                        case TYPE__ENUM_C: {
                            #line 992 "src/analyzer/Expression.pv"
                            result = Expression__parse_enum(context, token, type, generics);
                        } break;
                        #line 993 "src/analyzer/Expression.pv"
                        case TYPE__SELF: {
                            #line 993 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 994 "src/analyzer/Expression.pv"
                        case TYPE__STRUCT: {
                            #line 994 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 995 "src/analyzer/Expression.pv"
                        case TYPE__STRUCT_C: {
                            #line 995 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 996 "src/analyzer/Expression.pv"
                        case TYPE__UNION_C: {
                            #line 996 "src/analyzer/Expression.pv"
                            result = Expression__parse_struct(context, token, type, generics);
                        } break;
                        #line 997 "src/analyzer/Expression.pv"
                        case TYPE__CLASS_CPP: {
                            #line 997 "src/analyzer/Expression.pv"
                            result = Expression__parse_class(context, token, Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type), generics);
                        } break;
                        #line 998 "src/analyzer/Expression.pv"
                        case TYPE__NAMESPACE_CPP: {
                            #line 998 "src/analyzer/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                        #line 999 "src/analyzer/Expression.pv"
                        default: {
                            #line 999 "src/analyzer/Expression.pv"
                            result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type }, type);
                        } break;
                    }
                } else if (Generics__has(generics, token->value)) {
                    #line 1002 "src/analyzer/Expression.pv"
                    struct Generic* generic = Generics__find(generics, token->value);
                    #line 1003 "src/analyzer/Expression.pv"
                    result = Expression__make_next(context, (struct Expression) {
                        .token = token,
                        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic },
                    });

                    #line 1008 "src/analyzer/Expression.pv"
                    result->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = &result->return_type };
                } else {
                    #line 1010 "src/analyzer/Expression.pv"
                    Context__error_token(context, token, "Unable to find variable or type with this name");
                    #line 1011 "src/analyzer/Expression.pv"
                    return 0;
                }
            } else {
                #line 1014 "src/analyzer/Expression.pv"
                switch (return_type->type) {
                    #line 1015 "src/analyzer/Expression.pv"
                    case TYPE__FUNCTION: {
                        #line 1015 "src/analyzer/Expression.pv"
                        struct Function* func_info = return_type->function_value._0;
                        #line 1016 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1017 "src/analyzer/Expression.pv"
                        struct Type* func_type = return_type;
                        #line 1018 "src/analyzer/Expression.pv"
                        struct Array_Type parsed_generics = (struct Array_Type) {};

                        #line 1020 "src/analyzer/Expression.pv"
                        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<")) {
                            #line 1021 "src/analyzer/Expression.pv"
                            parsed_generics = Context__parse_generics(context, generics);
                        }

                        #line 1024 "src/analyzer/Expression.pv"
                        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                            #line 1024 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1026 "src/analyzer/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1028 "src/analyzer/Expression.pv"
                        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                            #line 1029 "src/analyzer/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1030 "src/analyzer/Expression.pv"
                            if (argument == 0) {
                                #line 1030 "src/analyzer/Expression.pv"
                                return 0;
                            }
                            #line 1031 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1033 "src/analyzer/Expression.pv"
                            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                                #line 1034 "src/analyzer/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1035 "src/analyzer/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1039 "src/analyzer/Expression.pv"
                        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1039 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1041 "src/analyzer/Expression.pv"
                        if (func_info->generics.array.length > 0) {
                            #line 1042 "src/analyzer/Expression.pv"
                            struct GenericMap* func_generics = Expression__resolve_function_generics(context, func_info, &parsed_generics, &arguments);
                            #line 1043 "src/analyzer/Expression.pv"
                            func_type = Module__make_type_usage(context->module, func_type, &func_generics->array);
                        }

                        #line 1046 "src/analyzer/Expression.pv"
                        if (!Expression__validate_arguments(context, token, func_type, &arguments, 0, false)) {
                            #line 1046 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1048 "src/analyzer/Expression.pv"
                        struct Type* func_return_type = 0;
                        #line 1049 "src/analyzer/Expression.pv"
                        switch (func_type->type) {
                            #line 1050 "src/analyzer/Expression.pv"
                            case TYPE__FUNCTION: {
                                #line 1050 "src/analyzer/Expression.pv"
                                struct GenericMap* func_generic_map = func_type->function_value._1;
                                #line 1051 "src/analyzer/Expression.pv"
                                switch (func_info->type) {
                                    #line 1052 "src/analyzer/Expression.pv"
                                    case FUNCTION_TYPE__COROUTINE: {
                                        #line 1053 "src/analyzer/Expression.pv"
                                        func_return_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__COROUTINE_INSTANCE, .coroutineinstance_value = { ._0 = func_info, ._1 = func_generic_map} });
                                    } break;
                                    #line 1055 "src/analyzer/Expression.pv"
                                    default: {
                                        #line 1056 "src/analyzer/Expression.pv"
                                        func_return_type = Context__resolve_type(context->allocator, &func_info->return_type, func_generic_map, 0);
                                    } break;
                                }
                            } break;
                            #line 1060 "src/analyzer/Expression.pv"
                            default: {
                            } break;
                        }

                        #line 1063 "src/analyzer/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = func_type }, func_type);
                        #line 1064 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, func_return_type);
                    } break;
                    #line 1066 "src/analyzer/Expression.pv"
                    case TYPE__COROUTINE_INSTANCE: {
                        #line 1067 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1068 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1070 "src/analyzer/Expression.pv"
                    case TYPE__INDIRECT: {
                        #line 1071 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1072 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1074 "src/analyzer/Expression.pv"
                    case TYPE__SEQUENCE: {
                        #line 1075 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1076 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1078 "src/analyzer/Expression.pv"
                    case TYPE__TUPLE: {
                        #line 1079 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1080 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1082 "src/analyzer/Expression.pv"
                    case TYPE__PRIMITIVE: {
                        #line 1083 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1084 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1086 "src/analyzer/Expression.pv"
                    case TYPE__ENUM: {
                        #line 1087 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1088 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1090 "src/analyzer/Expression.pv"
                    case TYPE__STRUCT: {
                        #line 1091 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1092 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1094 "src/analyzer/Expression.pv"
                    case TYPE__GENERIC: {
                        #line 1095 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1096 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1098 "src/analyzer/Expression.pv"
                    case TYPE__SELF: {
                        #line 1099 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1100 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1102 "src/analyzer/Expression.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 1103 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1104 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1106 "src/analyzer/Expression.pv"
                    case TYPE__STRUCT_C: {
                        #line 1107 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1108 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1110 "src/analyzer/Expression.pv"
                    case TYPE__UNION_C: {
                        #line 1111 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1112 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1114 "src/analyzer/Expression.pv"
                    case TYPE__CLASS_CPP: {
                        #line 1115 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1116 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1118 "src/analyzer/Expression.pv"
                    case TYPE__ENUM_C: {
                        #line 1119 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1120 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, return_type);
                    } break;
                    #line 1122 "src/analyzer/Expression.pv"
                    case TYPE__FUNCTION_C: {
                        #line 1122 "src/analyzer/Expression.pv"
                        struct FunctionC* func_info = return_type->functionc_value;
                        #line 1123 "src/analyzer/Expression.pv"
                        Context__next_token(context);
                        #line 1124 "src/analyzer/Expression.pv"
                        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                            #line 1124 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1126 "src/analyzer/Expression.pv"
                        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 1128 "src/analyzer/Expression.pv"
                        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                            #line 1129 "src/analyzer/Expression.pv"
                            struct Expression* argument = Expression__parse(context, generics);
                            #line 1130 "src/analyzer/Expression.pv"
                            Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = argument });

                            #line 1132 "src/analyzer/Expression.pv"
                            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                                #line 1133 "src/analyzer/Expression.pv"
                                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                #line 1134 "src/analyzer/Expression.pv"
                                return 0;
                            }
                        }

                        #line 1138 "src/analyzer/Expression.pv"
                        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                            #line 1138 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1140 "src/analyzer/Expression.pv"
                        struct Expression* func_expr = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = return_type }, return_type);

                        #line 1142 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = func_expr, ._1 = arguments} }, &func_info->return_type);
                    } break;
                    #line 1144 "src/analyzer/Expression.pv"
                    default: {
                        #line 1145 "src/analyzer/Expression.pv"
                        Context__error(context, "Expression::parse issue");
                    } break;
                }
            }
        } break;
        #line 1150 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__STRING: {
            #line 1151 "src/analyzer/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &context->pointer_const_char },
            });
        } break;
        #line 1157 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 1158 "src/analyzer/Expression.pv"
            char const* primitive = "i32";

            #line 1160 "src/analyzer/Expression.pv"
            if (str__ends_with(token->value, "f")) {
                #line 1161 "src/analyzer/Expression.pv"
                primitive = "f32";
            } else if (str__contains(token->value, ".")) {
                #line 1163 "src/analyzer/Expression.pv"
                primitive = "f64";
            }

            #line 1166 "src/analyzer/Expression.pv"
            result = Expression__make_next(context, (struct Expression) {
                .token = token,
                .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, primitive) },
            });
        } break;
        #line 1172 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 1173 "src/analyzer/Expression.pv"
            if (Token__eq(token, TOKEN_TYPE__SYMBOL, "-") || Token__eq(token, TOKEN_TYPE__SYMBOL, "+") || Token__eq(token, TOKEN_TYPE__SYMBOL, "!") || Token__eq(token, TOKEN_TYPE__SYMBOL, "&") || Token__eq(token, TOKEN_TYPE__SYMBOL, "*") || Token__eq(token, TOKEN_TYPE__SYMBOL, "/") || Token__eq(token, TOKEN_TYPE__SYMBOL, "%") || Token__eq(token, TOKEN_TYPE__SYMBOL, "~")) {
                #line 1174 "src/analyzer/Expression.pv"
                struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
                #line 1175 "src/analyzer/Expression.pv"
                if (operator == 0) {
                    #line 1175 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1177 "src/analyzer/Expression.pv"
                if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") }) && Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
                    #line 1178 "src/analyzer/Expression.pv"
                    context->pos -= 1;
                    #line 1179 "src/analyzer/Expression.pv"
                    struct Type* new_type = Context__parse_type2(context, generics);
                    #line 1180 "src/analyzer/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                } else {
                    #line 1182 "src/analyzer/Expression.pv"
                    struct Expression* child = Expression__parse(context, generics);
                    #line 1183 "src/analyzer/Expression.pv"
                    if (child == 0) {
                        #line 1183 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 1185 "src/analyzer/Expression.pv"
                    if (str__eq(operator->value, (struct str){ .ptr = "&", .length = strlen("&") })) {
                        #line 1186 "src/analyzer/Expression.pv"
                        switch (child->data.type) {
                            #line 1187 "src/analyzer/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1187 "src/analyzer/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1188 "src/analyzer/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type) });
                                #line 1189 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1191 "src/analyzer/Expression.pv"
                            default: {
                                #line 1192 "src/analyzer/Expression.pv"
                                struct Type return_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, child->return_type) };
                                #line 1193 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &return_type);
                            } break;
                        }
                    } else if (str__eq(operator->value, (struct str){ .ptr = "*", .length = strlen("*") })) {
                        #line 1197 "src/analyzer/Expression.pv"
                        switch (child->data.type) {
                            #line 1198 "src/analyzer/Expression.pv"
                            case EXPRESSION_DATA__TYPE: {
                                #line 1198 "src/analyzer/Expression.pv"
                                struct Type* type = child->data.type_value;
                                #line 1199 "src/analyzer/Expression.pv"
                                struct Indirect* new_indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *type);
                                #line 1200 "src/analyzer/Expression.pv"
                                struct Type* new_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = new_indirect });
                                #line 1201 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = new_type }, new_type);
                            } break;
                            #line 1203 "src/analyzer/Expression.pv"
                            default: {
                                #line 1203 "src/analyzer/Expression.pv"
                                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, Type__deref(&child->return_type));
                            } break;
                        }
                    } else {
                        #line 1206 "src/analyzer/Expression.pv"
                        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__UNARY_EXPRESSION, .unaryexpression_value = { ._0 = operator->value, ._1 = child} }, &child->return_type);
                    }
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "(")) {
                #line 1210 "src/analyzer/Expression.pv"
                if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(") == 0) {
                    #line 1210 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1212 "src/analyzer/Expression.pv"
                struct Expression* expr = Expression__parse(context, generics);
                #line 1213 "src/analyzer/Expression.pv"
                if (expr == 0) {
                    #line 1213 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1215 "src/analyzer/Expression.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
                    #line 1216 "src/analyzer/Expression.pv"
                    struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                    #line 1218 "src/analyzer/Expression.pv"
                    struct Token* name = ArenaAllocator__store_Token(context->allocator, *expr->token);
                    #line 1219 "src/analyzer/Expression.pv"
                    name->value = (struct str){ .ptr = "_0", .length = strlen("_0") };

                    #line 1221 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = expr });

                    #line 1223 "src/analyzer/Expression.pv"
                    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 1224 "src/analyzer/Expression.pv"
                        struct String name_string = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 1225 "src/analyzer/Expression.pv"
                        String__append(&name_string, (struct str){ .ptr = "_", .length = strlen("_") });
                        #line 1226 "src/analyzer/Expression.pv"
                        String__append_usize(&name_string, arguments.length);

                        #line 1228 "src/analyzer/Expression.pv"
                        struct Token* name = ArenaAllocator__store_Token(context->allocator, *Context__current(context));
                        #line 1229 "src/analyzer/Expression.pv"
                        name->value = String__as_str(&name_string);

                        #line 1231 "src/analyzer/Expression.pv"
                        struct Expression* value = Expression__parse(context, generics);
                        #line 1232 "src/analyzer/Expression.pv"
                        if (value == 0) {
                            #line 1232 "src/analyzer/Expression.pv"
                            return 0;
                        }

                        #line 1234 "src/analyzer/Expression.pv"
                        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .name = name, .value = value });

                        #line 1236 "src/analyzer/Expression.pv"
                        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                            #line 1237 "src/analyzer/Expression.pv"
                            Context__error(context, "Expected , or )");
                            #line 1238 "src/analyzer/Expression.pv"
                            return 0;
                        }
                    }

                    #line 1242 "src/analyzer/Expression.pv"
                    struct Tuple* tuple = ArenaAllocator__store_Tuple(context->allocator, (struct Tuple) {});
                    #line 1243 "src/analyzer/Expression.pv"
                    tuple->elements = Array_Type__new_with_length((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, arguments.length);
                    #line 1244 "src/analyzer/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(&arguments));
                    #line 1244 "src/analyzer/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1244 "src/analyzer/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1244 "src/analyzer/Expression.pv"
                        struct InvokeArgument expr = *IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1245 "src/analyzer/Expression.pv"
                        tuple->elements.data[i] = expr.value->return_type;
                    } }

                    #line 1248 "src/analyzer/Expression.pv"
                    result = Expression__make_type_function_call(context, token, ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple }), arguments, 0);
                } else {
                    #line 1250 "src/analyzer/Expression.pv"
                    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                        #line 1250 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 1252 "src/analyzer/Expression.pv"
                    result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__PARENTHESIZED_EXPRESSION, .parenthesizedexpression_value = expr }, &expr->return_type);
                }
            } else if (Token__eq(token, TOKEN_TYPE__SYMBOL, "[")) {
                #line 1255 "src/analyzer/Expression.pv"
                if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "[") == 0) {
                    #line 1255 "src/analyzer/Expression.pv"
                    return 0;
                }

                #line 1257 "src/analyzer/Expression.pv"
                struct Type* element_type = 0;
                #line 1258 "src/analyzer/Expression.pv"
                struct Array_InvokeArgument elements = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 1260 "src/analyzer/Expression.pv"
                while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "]") == 0) {
                    #line 1261 "src/analyzer/Expression.pv"
                    struct Expression* element = Expression__parse(context, generics);
                    #line 1262 "src/analyzer/Expression.pv"
                    if (element == 0) {
                        #line 1262 "src/analyzer/Expression.pv"
                        return 0;
                    }

                    #line 1264 "src/analyzer/Expression.pv"
                    Array_InvokeArgument__append(&elements, (struct InvokeArgument) { .value = element });

                    #line 1266 "src/analyzer/Expression.pv"
                    if (element_type == 0) {
                        #line 1267 "src/analyzer/Expression.pv"
                        element_type = &element->return_type;
                    }

                    #line 1270 "src/analyzer/Expression.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "]")) {
                        #line 1271 "src/analyzer/Expression.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");
                        #line 1272 "src/analyzer/Expression.pv"
                        return 0;
                    }
                }

                #line 1276 "src/analyzer/Expression.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, "]");

                #line 1278 "src/analyzer/Expression.pv"
                struct Sequence* parent_sequence = ArenaAllocator__store_Sequence(context->allocator, (struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__FIXED_ARRAY, .fixedarray_value = elements.length }, .element = *element_type });
                #line 1279 "src/analyzer/Expression.pv"
                struct Type* parent_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = parent_sequence });
                #line 1280 "src/analyzer/Expression.pv"
                struct Expression* parent_expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = parent_type }, parent_type);

                #line 1282 "src/analyzer/Expression.pv"
                result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = parent_expression, ._1 = elements} }, parent_type);
            } else {
                #line 1284 "src/analyzer/Expression.pv"
                Context__error(context, "Unhandled symbol");
            }
        } break;
        #line 1287 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 1288 "src/analyzer/Expression.pv"
            if (str__eq(token->value, (struct str){ .ptr = "true", .length = strlen("true") }) || str__eq(token->value, (struct str){ .ptr = "false", .length = strlen("false") })) {
                #line 1289 "src/analyzer/Expression.pv"
                result = Expression__make_next(context, (struct Expression) {
                    .token = token,
                    .data = (struct ExpressionData) { .type = EXPRESSION_DATA__LITERAL, .literal_value = token->value },
                    .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = Module__find_primitive(context->module, "bool") },
                });
            } else {
                #line 1295 "src/analyzer/Expression.pv"
                Context__error(context, "Only true + false keywords are valid in expressions");
            }
        } break;
        #line 1298 "src/analyzer/Expression.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 1299 "src/analyzer/Expression.pv"
            Context__error(context, "Comment should be skipped");
        } break;
    }

    #line 1303 "src/analyzer/Expression.pv"
    if (result == 0) {
        #line 1303 "src/analyzer/Expression.pv"
        return 0;
    }

    #line 1305 "src/analyzer/Expression.pv"
    result = Expression__parse_inner(context, result, generics);

    #line 1307 "src/analyzer/Expression.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "..")) {
        #line 1308 "src/analyzer/Expression.pv"
        struct Token* token = Context__expect(context, TOKEN_TYPE__SYMBOL);

        #line 1310 "src/analyzer/Expression.pv"
        struct Expression* range_start = result;
        #line 1311 "src/analyzer/Expression.pv"
        struct Expression* range_end = Expression__parse(context, generics);
        #line 1312 "src/analyzer/Expression.pv"
        if (range_end == 0) {
            #line 1312 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1314 "src/analyzer/Expression.pv"
        struct Type* enum_type = Module__find_make_type(context->module, (struct str){ .ptr = "Range", .length = strlen("Range") }, &(struct Array_Type) { .data = &range_end->return_type, .length = 1 });
        #line 1315 "src/analyzer/Expression.pv"
        if (enum_type == 0) {
            #line 1316 "src/analyzer/Expression.pv"
            Context__error_token(context, token, "Could not find Range type, include std library");
            #line 1317 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1320 "src/analyzer/Expression.pv"
        struct Token variant_name = *token;
        #line 1321 "src/analyzer/Expression.pv"
        variant_name.type = TOKEN_TYPE__IDENTIFIER;
        #line 1322 "src/analyzer/Expression.pv"
        variant_name.value = (struct str){ .ptr = "StartEnd", .length = strlen("StartEnd") };

        #line 1324 "src/analyzer/Expression.pv"
        struct EnumVariant* variant = Expression__get_enum_variant(context, enum_type, &variant_name);
        #line 1325 "src/analyzer/Expression.pv"
        if (variant == 0) {
            #line 1325 "src/analyzer/Expression.pv"
            return 0;
        }

        #line 1327 "src/analyzer/Expression.pv"
        struct Array_InvokeArgument arguments = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1328 "src/analyzer/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_start });
        #line 1329 "src/analyzer/Expression.pv"
        Array_InvokeArgument__append(&arguments, (struct InvokeArgument) { .value = range_end });

        #line 1331 "src/analyzer/Expression.pv"
        struct Expression* enum_variant = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__ENUM_VARIANT, .enumvariant_value = variant }, enum_type);

        #line 1333 "src/analyzer/Expression.pv"
        result = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__INVOKE, .invoke_value = { ._0 = enum_variant, ._1 = arguments} }, enum_type);
    }

    #line 1336 "src/analyzer/Expression.pv"
    return result;
}

#line 1339 "src/analyzer/Expression.pv"
bool Expression__is_zero(struct Expression* self) {
    #line 1340 "src/analyzer/Expression.pv"
    switch (self->data.type) {
        #line 1341 "src/analyzer/Expression.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1341 "src/analyzer/Expression.pv"
            struct str value = self->data.literal_value;
            #line 1341 "src/analyzer/Expression.pv"
            return str__eq(value, (struct str){ .ptr = "0", .length = strlen("0") });
        } break;
        #line 1342 "src/analyzer/Expression.pv"
        default: {
            #line 1342 "src/analyzer/Expression.pv"
            return false;
        } break;
    }
}

#line 1346 "src/analyzer/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type) {
    #line 1347 "src/analyzer/Expression.pv"
    bool success = true;

    #line 1349 "src/analyzer/Expression.pv"
    switch (self->data.type) {
        #line 1350 "src/analyzer/Expression.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1350 "src/analyzer/Expression.pv"
            struct Expression* invoke = self->data.invoke_value._0;
            #line 1350 "src/analyzer/Expression.pv"
            struct Array_InvokeArgument* arguments = &self->data.invoke_value._1;
            #line 1351 "src/analyzer/Expression.pv"
            switch (type->type) {
                #line 1352 "src/analyzer/Expression.pv"
                case TYPE__TUPLE: {
                    #line 1352 "src/analyzer/Expression.pv"
                    struct Tuple* tuple = type->tuple_value;
                    #line 1353 "src/analyzer/Expression.pv"
                    { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(arguments));
                    #line 1353 "src/analyzer/Expression.pv"
                    while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
                        #line 1353 "src/analyzer/Expression.pv"
                        uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
                        #line 1353 "src/analyzer/Expression.pv"
                        struct InvokeArgument* argument = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

                        #line 1354 "src/analyzer/Expression.pv"
                        success = Expression__validate_type(argument->value, context, &tuple->elements.data[i]) && success;
                    } }

                    #line 1357 "src/analyzer/Expression.pv"
                    invoke->data = (struct ExpressionData) { .type = EXPRESSION_DATA__TYPE, .type_value = type };
                    #line 1358 "src/analyzer/Expression.pv"
                    invoke->return_type = *type;
                    #line 1359 "src/analyzer/Expression.pv"
                    self->return_type = *type;

                    #line 1361 "src/analyzer/Expression.pv"
                    return success;
                } break;
                #line 1363 "src/analyzer/Expression.pv"
                default: {
                } break;
            }
        } break;
        #line 1366 "src/analyzer/Expression.pv"
        default: {
        } break;
    }

    #line 1369 "src/analyzer/Expression.pv"
    if (Type__needs_implicit_cast(type, &self->return_type)) {
        #line 1370 "src/analyzer/Expression.pv"
        struct Expression* expression = ArenaAllocator__store_Expression(context->allocator, *self);
        #line 1371 "src/analyzer/Expression.pv"
        self->data = (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression };
        #line 1372 "src/analyzer/Expression.pv"
        self->return_type = *type;
        #line 1373 "src/analyzer/Expression.pv"
        return true;
    }

    #line 1376 "src/analyzer/Expression.pv"
    if (!Type__eq(type, &self->return_type)) {
        #line 1377 "src/analyzer/Expression.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 1378 "src/analyzer/Expression.pv"
        String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
        #line 1379 "src/analyzer/Expression.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, &self->return_type, context->type_self, 0);
        #line 1380 "src/analyzer/Expression.pv"
        String__append(&message, String__as_str(&type_name));
        #line 1381 "src/analyzer/Expression.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 1382 "src/analyzer/Expression.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 1383 "src/analyzer/Expression.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 1384 "src/analyzer/Expression.pv"
        Context__error_token(context, self->token, String__c_str(&message));
        #line 1385 "src/analyzer/Expression.pv"
        return false;
    }

    #line 1388 "src/analyzer/Expression.pv"
    self->return_type = *type;
    #line 1389 "src/analyzer/Expression.pv"
    return true;
}
