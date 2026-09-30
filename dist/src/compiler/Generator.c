#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdio.h>
#include <fs.h>
#include <std/str.h>
#include <std/String.h>
#include <analyzer/Token.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Sequence.h>
#include <compiler/ExpressionWriter.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Function.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/Primitive.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <analyzer/types/Trait.h>
#include <std/HashMap_str_Function.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/EnumVariant.h>
#include <char.h>
#include <std/Hash.h>
#include <std/Fnv1a.h>
#include <std/Array_char.h>
#include <analyzer/Context.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <analyzer/c/Include.h>
#include <analyzer/Module.h>
#include <std/HashSetIter_str.h>
#include <analyzer/types/Parameter.h>
#include <compiler/FunctionContext.h>
#include <analyzer/types/FunctionType.h>
#include <usize.h>
#include <std/trait_Allocator.h>
#include <analyzer/Namespace.h>
#include <std/Range_usize.h>
#include <std/Array_Type.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/types/Global.h>
#include <std/Iter_ref_String.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <std/Iter_ref_Generic.h>
#include <std/HashMap_str_usize.h>
#include <std/HashMapIter_str_usize.h>
#include <tuple_str_usize.h>
#include <analyzer/Root.h>
#include <analyzer/NamingType.h>
#include <compiler/FileGenerator.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <compiler/Usages.h>
#include <std/HashMap_usize_TypeUsage_TypeImpl.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <std/HashMapIter_usize_TypeUsage_Primitive.h>
#include <tuple_usize_TypeUsage_Primitive.h>
#include <compiler/TypeUsage_Primitive.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>
#include <tuple_usize_TypeUsage_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <std/HashMapIter_usize_TypeUsage_Enum.h>
#include <tuple_usize_TypeUsage_Enum.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <std/HashMapIter_usize_TypeUsage_Trait.h>
#include <tuple_usize_TypeUsage_Trait.h>
#include <compiler/TypeUsage_Trait.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>
#include <tuple_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>
#include <std/HashMapIter_usize_TypeUsage_Sequence.h>
#include <tuple_usize_TypeUsage_Sequence.h>
#include <compiler/TypeUsage_Sequence.h>
#include <std/HashMap_usize_TypeUsage_Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_Tuple.h>
#include <tuple_usize_TypeUsage_Tuple.h>
#include <compiler/TypeUsage_Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_TypeImpl.h>
#include <tuple_usize_TypeUsage_TypeImpl.h>
#include <compiler/TypeUsage_TypeImpl.h>
#include <compiler/Generator.h>

#include <compiler/Generator.h>

#line 40 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file) {
    #line 41 "src/compiler/Generator.pv"
    int16_t i = 0;
    #line 42 "src/compiler/Generator.pv"
    while (i < self->indent) {
        #line 43 "src/compiler/Generator.pv"
        fprintf(file, "    ");
        #line 44 "src/compiler/Generator.pv"
        i += 1;
    }
}

#line 48 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s) {
    #line 49 "src/compiler/Generator.pv"
    int32_t length = s.length;
    #line 50 "src/compiler/Generator.pv"
    fprintf(file, "%.*s", length, s.ptr);
    #line 51 "src/compiler/Generator.pv"
    return true;
}

#line 54 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s) {
    #line 55 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, String__as_str(s));
}

#line 58 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s) {
    #line 59 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 60 "src/compiler/Generator.pv"
    uintptr_t length = s.length;
    #line 61 "src/compiler/Generator.pv"
    bool was_lowercase = false;

    #line 63 "src/compiler/Generator.pv"
    while (i < length) {
        #line 64 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 66 "src/compiler/Generator.pv"
        if (c >= 'a' && c <= 'z') {
            #line 67 "src/compiler/Generator.pv"
            fprintf(file, "%c", c - 32);
            #line 68 "src/compiler/Generator.pv"
            was_lowercase = true;
        } else {
            #line 70 "src/compiler/Generator.pv"
            if (was_lowercase && (c >= 'A') && (c <= 'Z')) {
                #line 71 "src/compiler/Generator.pv"
                fprintf(file, "_");
            }

            #line 74 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
            #line 75 "src/compiler/Generator.pv"
            was_lowercase = false;
        }

        #line 78 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 81 "src/compiler/Generator.pv"
    return true;
}

#line 84 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s) {
    #line 85 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 86 "src/compiler/Generator.pv"
    uintptr_t length = s.length;

    #line 88 "src/compiler/Generator.pv"
    while (i < length) {
        #line 89 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 91 "src/compiler/Generator.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 92 "src/compiler/Generator.pv"
            fprintf(file, "%c", c + 32);
        } else {
            #line 94 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
        }

        #line 97 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 100 "src/compiler/Generator.pv"
    return true;
}

#line 103 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token) {
    #line 104 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, token->value);
}

#line 107 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 108 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 109 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 109 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 109 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, &indirect->to, generics);
        } break;
        #line 110 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 110 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 110 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 111 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 111 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 112 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 115 "src/compiler/Generator.pv"
    return false;
}

#line 118 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union_no_indirect(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 119 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 120 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 120 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 120 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 121 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 121 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 122 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 125 "src/compiler/Generator.pv"
    return false;
}

#line 128 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 129 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_c99, type, generics->self_type, generics);
    #line 130 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 131 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 132 "src/compiler/Generator.pv"
    return true;
}

#line 135 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 136 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_ident, type, generics->self_type, generics);
    #line 137 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 138 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 139 "src/compiler/Generator.pv"
    return true;
}

#line 142 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics) {
    #line 143 "src/compiler/Generator.pv"
    struct Type* self_type = type;
    #line 144 "src/compiler/Generator.pv"
    if (generics != 0) {
        #line 144 "src/compiler/Generator.pv"
        self_type = (*generics).self_type;
    }

    #line 146 "src/compiler/Generator.pv"
    struct String variable_decl = Naming__get_variable_decl(&self->naming_c99, name, type, self_type, generics);
    #line 147 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&variable_decl));
    #line 148 "src/compiler/Generator.pv"
    String__release(&variable_decl);

    #line 150 "src/compiler/Generator.pv"
    Generator__write_array_decl_suffix(self, file, type, generics);

    #line 152 "src/compiler/Generator.pv"
    return true;
}

#line 155 "src/compiler/Generator.pv"
void Generator__write_array_decl_suffix(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 156 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 157 "src/compiler/Generator.pv"
        case TYPE__SEQUENCE: {
            #line 157 "src/compiler/Generator.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 158 "src/compiler/Generator.pv"
            switch (sequence->type.type) {
                #line 159 "src/compiler/Generator.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 159 "src/compiler/Generator.pv"
                    struct Expression* length = sequence->type.fixedarray_value;
                    #line 160 "src/compiler/Generator.pv"
                    fprintf(file, "[");
                    #line 161 "src/compiler/Generator.pv"
                    ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = self }}, file, length, generics);
                    #line 162 "src/compiler/Generator.pv"
                    fprintf(file, "]");
                    #line 163 "src/compiler/Generator.pv"
                    Generator__write_array_decl_suffix(self, file, &sequence->element, generics);
                } break;
                #line 165 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 168 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 172 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 173 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
    #line 174 "src/compiler/Generator.pv"

    #line 176 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&name));

    #line 178 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 181 "src/compiler/Generator.pv"
bool Generator__write_dynamic_vtable_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 182 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
    #line 183 "src/compiler/Generator.pv"

    #line 185 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, String__as_str(&name));

    #line 187 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 190 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type) {
    #line 191 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 192 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 192 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 193 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 193 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 193 "src/compiler/Generator.pv"
            return Generator__is_reference(info->type);
        } break;
        #line 194 "src/compiler/Generator.pv"
        default: {
            #line 194 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 198 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 199 "src/compiler/Generator.pv"
    switch (Type__deref(type)->type) {
        #line 200 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 200 "src/compiler/Generator.pv"
            struct Struct* struct_info = Type__deref(type)->struct_value._0;
            #line 200 "src/compiler/Generator.pv"
            return Struct__is_newtype(struct_info);
        } break;
        #line 201 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 201 "src/compiler/Generator.pv"
            return Generator__is_type_single_value_struct(self, generics->self_type, generics);
        } break;
        #line 202 "src/compiler/Generator.pv"
        default: {
            #line 202 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 206 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map) {
    #line 207 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 208 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 209 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 210 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting Self for function, but no generic map input\n");
                #line 211 "src/compiler/Generator.pv"
                return 0;
            }

            #line 214 "src/compiler/Generator.pv"
            return Generator__get_function(self, (*generic_map).self_type, func_name, generic_map);
        } break;
        #line 216 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 216 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 216 "src/compiler/Generator.pv"
            return Generator__get_function(self, &indirect->to, func_name, generic_map);
        } break;
        #line 217 "src/compiler/Generator.pv"
        case TYPE__GENERIC: {
            #line 217 "src/compiler/Generator.pv"
            struct Generic* generic = type->generic_value;
            #line 218 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 219 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, but no generic map input\n");
                #line 220 "src/compiler/Generator.pv"
                return 0;
            }

            #line 223 "src/compiler/Generator.pv"
            struct Token generic_name = *generic->name;
            #line 224 "src/compiler/Generator.pv"
            struct Type* generic_type = GenericMap__get(&(*generic_map), generic_name.value);
            #line 225 "src/compiler/Generator.pv"
            if (generic_type == 0) {
                #line 226 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, no item in generic map found\n");
                #line 227 "src/compiler/Generator.pv"
                return 0;
            }

            #line 230 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_type, func_name, generic_map);
        } break;
        #line 232 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 232 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 233 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 234 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting primitive for function, but no primitive info found\n");
                #line 235 "src/compiler/Generator.pv"
                return 0;
            }

            #line 238 "src/compiler/Generator.pv"
            struct Primitive primitive = *primitive_info;
            #line 239 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 241 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&primitive.impls);
            #line 242 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 243 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 244 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 247 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 248 "src/compiler/Generator.pv"
                int32_t name_length = primitive.name.length;
                #line 249 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 250 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitives %.*s function %.*s for get_function\n", name_length, primitive.name.ptr, func_name_length, func_name.ptr);
            }

            #line 253 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 255 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 255 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 256 "src/compiler/Generator.pv"
            struct Function* func_info = 0;
            #line 257 "src/compiler/Generator.pv"
            struct Token enum_name = *enum_info->name;

            #line 259 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 260 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 261 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 262 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 265 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 266 "src/compiler/Generator.pv"
                int32_t name_length = enum_name.value.length;
                #line 267 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 268 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enums %.*s function %.*s for get_function\n", name_length, enum_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 271 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 273 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 273 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 274 "src/compiler/Generator.pv"
            struct Function* func_info = 0;
            #line 275 "src/compiler/Generator.pv"
            struct Token struct_name = *struct_info->name;

            #line 277 "src/compiler/Generator.pv"
            { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
            #line 277 "src/compiler/Generator.pv"
            while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
                #line 277 "src/compiler/Generator.pv"
                uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
                #line 277 "src/compiler/Generator.pv"
                struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

                #line 278 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);

                #line 280 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 280 "src/compiler/Generator.pv"
                    break;
                }

                #line 282 "src/compiler/Generator.pv"
                if (impl_info->trait_ != 0) {
                    #line 283 "src/compiler/Generator.pv"
                    struct Trait trait_info = *impl_info->trait_;
                    #line 284 "src/compiler/Generator.pv"
                    func_info = HashMap_str_Function__find(&trait_info.functions, &func_name);
                }

                #line 287 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 288 "src/compiler/Generator.pv"
                    struct Function* stored_func_info = ArenaAllocator__store_Function(self->allocator, func_info);
                    #line 289 "src/compiler/Generator.pv"
                    if (stored_func_info != 0) {
                        #line 290 "src/compiler/Generator.pv"
                        stored_func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                    }
                    #line 292 "src/compiler/Generator.pv"
                    func_info = stored_func_info;
                    #line 293 "src/compiler/Generator.pv"
                    break;
                }
            } }

            #line 297 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 298 "src/compiler/Generator.pv"
                int32_t name_length = struct_name.value.length;
                #line 299 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 300 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find structs %.*s function %.*s for get_function\n", name_length, struct_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 303 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 305 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 305 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 306 "src/compiler/Generator.pv"
            struct Token trait_name = *trait_info->name;
            #line 307 "src/compiler/Generator.pv"
            struct Function* func_info = HashMap_str_Function__find(&trait_info->functions, &func_name);

            #line 309 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 310 "src/compiler/Generator.pv"
                int32_t name_length = trait_name.value.length;
                #line 311 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 312 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find traits %.*s function %.*s for get_function\n", name_length, trait_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 315 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 317 "src/compiler/Generator.pv"
        default: {
            #line 318 "src/compiler/Generator.pv"
            fprintf(stderr, "Unhandled type for getting function %s\n", Type__name(type));
        } break;
    }

    #line 322 "src/compiler/Generator.pv"
    return 0;
}

#line 325 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant) {
    #line 326 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;
    #line 327 "src/compiler/Generator.pv"
    struct Token name = *parent->name;
    #line 328 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, name.value);
    #line 329 "src/compiler/Generator.pv"
    fprintf(file, "__");
    #line 330 "src/compiler/Generator.pv"
    struct Token* variant_name = variant->name;
    #line 331 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, variant_name->value);

    #line 333 "src/compiler/Generator.pv"
    return true;
}

#line 336 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 337 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 338 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 338 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 339 "src/compiler/Generator.pv"
            fprintf(file, "*");
            #line 340 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, &indirect->to, generics);
        } break;
        #line 342 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 342 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 343 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, info->type, generics);
        } break;
        #line 345 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 348 "src/compiler/Generator.pv"
    return true;
}

#line 351 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics) {
    #line 352 "src/compiler/Generator.pv"
    fprintf(file, "::");
    #line 353 "src/compiler/Generator.pv"
    return true;
}

#line 356 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 357 "src/compiler/Generator.pv"
    if (Type__is_fat_pointer(type)) {
        #line 358 "src/compiler/Generator.pv"
        fprintf(file, ".");
        #line 359 "src/compiler/Generator.pv"
        return true;
    }

    #line 362 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 363 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 364 "src/compiler/Generator.pv"
            fprintf(file, "->");
        } break;
        #line 366 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 367 "src/compiler/Generator.pv"
            return Generator__write_instance_member_accessor(self, file, generics->self_type, generics);
        } break;
        #line 369 "src/compiler/Generator.pv"
        default: {
            #line 370 "src/compiler/Generator.pv"
            fprintf(file, ".");
        } break;
    }

    #line 374 "src/compiler/Generator.pv"
    return true;
}

#line 377 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value) {
    #line 378 "src/compiler/Generator.pv"
    if (value.length > 2 && char__Eq_char__eq(value.ptr[0], '0') && (char__Eq_char__eq(value.ptr[1], 'b') || char__Eq_char__eq(value.ptr[1], 'B'))) {
        #line 379 "src/compiler/Generator.pv"
        uint64_t acc = 0;
        #line 380 "src/compiler/Generator.pv"
        uintptr_t i = 2;
        #line 381 "src/compiler/Generator.pv"
        while (i < value.length) {
            #line 382 "src/compiler/Generator.pv"
            if (value.ptr[i] != '_') {
                #line 383 "src/compiler/Generator.pv"
                acc = (acc << 1) | (uint64_t)(value.ptr[i] - '0');
            }
            #line 385 "src/compiler/Generator.pv"
            i += 1;
        }
        #line 387 "src/compiler/Generator.pv"
        fprintf(file, "0x%llx", acc);
    } else if (value.length > 0 && value.ptr[0] >= '0' && value.ptr[0] <= '9') {
        #line 389 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 390 "src/compiler/Generator.pv"
        while (i < value.length) {
            #line 391 "src/compiler/Generator.pv"
            if (value.ptr[i] != '_') {
                #line 392 "src/compiler/Generator.pv"
                fprintf(file, "%c", (int32_t)(value.ptr[i]));
            }
            #line 394 "src/compiler/Generator.pv"
            i += 1;
        }
    } else {
        #line 397 "src/compiler/Generator.pv"
        Generator__write_str(self, file, value);
    }

    #line 400 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 401 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 401 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 402 "src/compiler/Generator.pv"
            if (primitive_info != 0 && str__Eq_str__eq((*primitive_info).name, (struct str){ .ptr = "u64", .length = strlen("u64") })) {
                #line 403 "src/compiler/Generator.pv"
                fprintf(file, "ULL");
            }
        } break;
        #line 406 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 409 "src/compiler/Generator.pv"
    return true;
}

#line 412 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 413 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);
    #line 414 "src/compiler/Generator.pv"

    #line 416 "src/compiler/Generator.pv"
    Hash type_id = Fnv1a__hash(type_name.array.data, String__length(&type_name));

    #line 418 "src/compiler/Generator.pv"
    fprintf(file, "%zuULL", type_id);

    #line 420 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 423 "src/compiler/Generator.pv"
bool Generator__write_typename(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 424 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);
    #line 425 "src/compiler/Generator.pv"

    #line 427 "src/compiler/Generator.pv"
    fprintf(file, "\"");
    #line 428 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &type_name);
    #line 429 "src/compiler/Generator.pv"
    fprintf(file, "\"");

    #line 431 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 434 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token) {
    #line 435 "src/compiler/Generator.pv"
    if (self->output_line_directives) {
        #line 436 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 437 "src/compiler/Generator.pv"
        fprintf(file, "#line %zu \"", token->start_line + 1);
        #line 438 "src/compiler/Generator.pv"
        Generator__write_str(self, file, context->path);
        #line 439 "src/compiler/Generator.pv"
        fprintf(file, "\"\n");
    }
}

#line 443 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes) {
    #line 444 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(includes);
    #line 444 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 444 "src/compiler/Generator.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 445 "src/compiler/Generator.pv"
        struct str path = include->path;
        #line 446 "src/compiler/Generator.pv"
        if (path.length > 0) {
            #line 447 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s>\n", (int32_t)(path.length - 2), path.ptr + 1);
        }
    } }

    #line 451 "src/compiler/Generator.pv"
    if (includes->length > 0) {
        #line 452 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 456 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls) {
    #line 457 "src/compiler/Generator.pv"
    struct HashSet_str written = HashSet_str__new(self->allocator);
    #line 458 "src/compiler/Generator.pv"

    #line 460 "src/compiler/Generator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 460 "src/compiler/Generator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 460 "src/compiler/Generator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 461 "src/compiler/Generator.pv"
        struct Module* module = impl_info->context->module;
        #line 462 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&module->includes);
        #line 462 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Include__next(&__iter)) {
            #line 462 "src/compiler/Generator.pv"
            struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

            #line 463 "src/compiler/Generator.pv"
            if (!HashSet_str__insert(&written, include->path)) {
                #line 463 "src/compiler/Generator.pv"
                continue;
            }
            #line 464 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 465 "src/compiler/Generator.pv"
            Generator__write_str(self, file, include->path);
            #line 466 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } }
    } }
    HashSet_str__release(&written);
}

#line 471 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives) {
    #line 472 "src/compiler/Generator.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);

    #line 474 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(primitives);
    #line 474 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 474 "src/compiler/Generator.pv"
        struct str* primitive = HashSetIter_str__value(&__iter);

        #line 475 "src/compiler/Generator.pv"
        if (exclude_primitives && HashSet_str__has(&(*exclude_primitives), primitive)) {
            #line 475 "src/compiler/Generator.pv"
            continue;
        }
        #line 476 "src/compiler/Generator.pv"
        struct str* include = HashMap_str_str__find(&self->primitive_includes, primitive);
        #line 477 "src/compiler/Generator.pv"
        if (include == 0) {
            #line 477 "src/compiler/Generator.pv"
            continue;
        }
        #line 478 "src/compiler/Generator.pv"
        HashSet_str__insert(&includes, *include);
    } }

    #line 481 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 481 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 481 "src/compiler/Generator.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 482 "src/compiler/Generator.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 485 "src/compiler/Generator.pv"
    if (includes.length > 0) {
        #line 486 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 490 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics) {
    #line 491 "src/compiler/Generator.pv"
    if (generics == 0 || (*generics).self_type == 0) {
        #line 491 "src/compiler/Generator.pv"
        return false;
    }

    #line 493 "src/compiler/Generator.pv"
    switch ((*generics).self_type->type) {
        #line 494 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 494 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = (*generics).self_type->primitive_value;
            #line 495 "src/compiler/Generator.pv"
            if (primitive_info == 0 || !str__Eq_str__eq((*primitive_info).name, (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 496 "src/compiler/Generator.pv"
                return false;
            }
        } break;
        #line 499 "src/compiler/Generator.pv"
        default: {
            #line 499 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 502 "src/compiler/Generator.pv"
    struct Type* ref = 0;

    #line 504 "src/compiler/Generator.pv"
    switch (parameter->type.type) {
        #line 505 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 505 "src/compiler/Generator.pv"
            struct Indirect* indirect = parameter->type.indirect_value;
            #line 506 "src/compiler/Generator.pv"
            ref = &indirect->to;
        } break;
        #line 508 "src/compiler/Generator.pv"
        default: {
            #line 508 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 511 "src/compiler/Generator.pv"
    if (ref == 0) {
        #line 511 "src/compiler/Generator.pv"
        return false;
    }

    #line 513 "src/compiler/Generator.pv"
    struct Type ref_type = *ref;
    #line 514 "src/compiler/Generator.pv"
    switch (ref_type.type) {
        #line 515 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 515 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 516 "src/compiler/Generator.pv"
        default: {
            #line 516 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 520 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self) {
    #line 521 "src/compiler/Generator.pv"
    struct FunctionContext function_context = *self->function_context;
    #line 522 "src/compiler/Generator.pv"
    return (*function_context.func_info).type == FUNCTION_TYPE__COROUTINE;
}

#line 525 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name) {
    #line 526 "src/compiler/Generator.pv"
    if (self->function_context != 0) {
        #line 527 "src/compiler/Generator.pv"
        name = FunctionContext__get_variable_replacement(&(*self->function_context), name);
    }
    #line 529 "src/compiler/Generator.pv"
    Generator__write_str(self, file, name);
}

#line 532 "src/compiler/Generator.pv"
bool Generator__namespace_is_game(struct Generator* self, struct Module* module) {
    #line 533 "src/compiler/Generator.pv"
    if (module == 0 || usize__Eq_usize__eq(self->game_namespaces.length, 0)) {
        #line 533 "src/compiler/Generator.pv"
        return false;
    }
    #line 534 "src/compiler/Generator.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 535 "src/compiler/Generator.pv"
    struct Namespace* namespace = (*module).namespace;
    #line 536 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 537 "src/compiler/Generator.pv"
        struct Namespace namespace_info = *namespace;
        #line 538 "src/compiler/Generator.pv"
        if (path.array.length > 0) {
            #line 538 "src/compiler/Generator.pv"
            String__prepend(&path, (struct str){ .ptr = "::", .length = strlen("::") });
        }
        #line 539 "src/compiler/Generator.pv"
        String__prepend(&path, namespace_info.name);
        #line 540 "src/compiler/Generator.pv"
        namespace = namespace_info.parent;
    }
    #line 542 "src/compiler/Generator.pv"
    struct str module_path = String__as_str(&path);
    #line 543 "src/compiler/Generator.pv"
    for (uintptr_t i = 0; i != self->game_namespaces.length; i < self->game_namespaces.length ? i++ : i--) {
        #line 544 "src/compiler/Generator.pv"
        struct str game = self->game_namespaces.data[i];
        #line 545 "src/compiler/Generator.pv"
        if (str__Eq_str__eq(module_path, game)) {
            #line 545 "src/compiler/Generator.pv"
            return true;
        }
        #line 546 "src/compiler/Generator.pv"
        if (module_path.length > game.length + 1 && str__starts_with(module_path, game) && char__Eq_char__eq(module_path.ptr[game.length], ':')) {
            #line 546 "src/compiler/Generator.pv"
            return true;
        }
    }
    #line 548 "src/compiler/Generator.pv"
    return false;
}

#line 551 "src/compiler/Generator.pv"
bool Generator__generics_are_game(struct Generator* self, struct GenericMap* generics, uint32_t depth) {
    #line 552 "src/compiler/Generator.pv"
    if (generics == 0) {
        #line 552 "src/compiler/Generator.pv"
        return false;
    }
    #line 553 "src/compiler/Generator.pv"
    struct GenericMap map = *generics;
    #line 554 "src/compiler/Generator.pv"
    for (uintptr_t i = 0; i != map.array.length; i < map.array.length ? i++ : i--) {
        #line 555 "src/compiler/Generator.pv"
        if (Generator__type_is_game(self, &map.array.data[i], depth + 1)) {
            #line 555 "src/compiler/Generator.pv"
            return true;
        }
    }
    #line 557 "src/compiler/Generator.pv"
    return false;
}

#line 562 "src/compiler/Generator.pv"
bool Generator__type_is_game(struct Generator* self, struct Type* type, uint32_t depth) {
    #line 563 "src/compiler/Generator.pv"
    if (depth > 16) {
        #line 563 "src/compiler/Generator.pv"
        return false;
    }
    #line 564 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 565 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 565 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 565 "src/compiler/Generator.pv"
            return Generator__type_is_game(self, &indirect->to, depth + 1);
        } break;
        #line 566 "src/compiler/Generator.pv"
        case TYPE__SEQUENCE: {
            #line 566 "src/compiler/Generator.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 566 "src/compiler/Generator.pv"
            return Generator__type_is_game(self, &sequence->element, depth + 1);
        } break;
        #line 567 "src/compiler/Generator.pv"
        case TYPE__TUPLE: {
            #line 567 "src/compiler/Generator.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 568 "src/compiler/Generator.pv"
            for (uintptr_t i = 0; i != tuple->elements.length; i < tuple->elements.length ? i++ : i--) {
                #line 569 "src/compiler/Generator.pv"
                if (Generator__type_is_game(self, &tuple->elements.data[i], depth + 1)) {
                    #line 569 "src/compiler/Generator.pv"
                    return true;
                }
            }
            #line 571 "src/compiler/Generator.pv"
            return false;
        } break;
        #line 573 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 573 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 573 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 573 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, struct_info->module) || Generator__generics_are_game(self, generics, depth);
        } break;
        #line 574 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 574 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 574 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 574 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, enum_info->context->module) || Generator__generics_are_game(self, generics, depth);
        } break;
        #line 575 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 575 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 575 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 575 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, trait_info->module) || Generator__generics_are_game(self, generics, depth);
        } break;
        #line 576 "src/compiler/Generator.pv"
        case TYPE__FUNCTION: {
            #line 576 "src/compiler/Generator.pv"
            struct Function* func_info = type->function_value._0;
            #line 576 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 577 "src/compiler/Generator.pv"
            if (func_info->context != 0) {
                #line 578 "src/compiler/Generator.pv"
                struct Context context = *func_info->context;
                #line 579 "src/compiler/Generator.pv"
                if (Generator__namespace_is_game(self, context.module)) {
                    #line 579 "src/compiler/Generator.pv"
                    return true;
                }
            }
            #line 581 "src/compiler/Generator.pv"
            return Generator__generics_are_game(self, generics, depth);
        } break;
        #line 583 "src/compiler/Generator.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 583 "src/compiler/Generator.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 583 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->coroutineinstance_value._1;
            #line 584 "src/compiler/Generator.pv"
            if (func_info->context != 0) {
                #line 585 "src/compiler/Generator.pv"
                struct Context context = *func_info->context;
                #line 586 "src/compiler/Generator.pv"
                if (Generator__namespace_is_game(self, context.module)) {
                    #line 586 "src/compiler/Generator.pv"
                    return true;
                }
            }
            #line 588 "src/compiler/Generator.pv"
            return Generator__generics_are_game(self, generics, depth);
        } break;
        #line 590 "src/compiler/Generator.pv"
        case TYPE__GLOBAL: {
            #line 590 "src/compiler/Generator.pv"
            struct Global* global = type->global_value;
            #line 590 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, global->module);
        } break;
        #line 591 "src/compiler/Generator.pv"
        default: {
            #line 591 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 598 "src/compiler/Generator.pv"
void Generator__begin_file(struct Generator* self, struct Type* type, struct GenericMap* generics, struct Module* module) {
    #line 599 "src/compiler/Generator.pv"
    if (usize__Eq_usize__eq(self->game_namespaces.length, 0)) {
        #line 599 "src/compiler/Generator.pv"
        self->current_host = false;
        #line 599 "src/compiler/Generator.pv"
        return;
    }
    #line 600 "src/compiler/Generator.pv"
    bool game = Generator__namespace_is_game(self, module) || Generator__generics_are_game(self, generics, 0);
    #line 601 "src/compiler/Generator.pv"
    if (!game && type != 0) {
        #line 601 "src/compiler/Generator.pv"
        game = Generator__type_is_game(self, type, 0);
    }
    #line 602 "src/compiler/Generator.pv"
    self->current_host = !game;
}

#line 605 "src/compiler/Generator.pv"
void Generator__add_code_file(struct Generator* self, struct String code) {
    #line 606 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);
    #line 607 "src/compiler/Generator.pv"
    if (usize__Eq_usize__eq(self->game_namespaces.length, 0)) {
        #line 607 "src/compiler/Generator.pv"
        return;
    }
    #line 608 "src/compiler/Generator.pv"
    if (self->current_host) {
        #line 608 "src/compiler/Generator.pv"
        Array_String__append(&self->host_files, code);
    } else {
        #line 608 "src/compiler/Generator.pv"
        Array_String__append(&self->game_files, code);
    }
}

#line 613 "src/compiler/Generator.pv"
void Generator__write_extern(struct Generator* self, FILE* file) {
    #line 614 "src/compiler/Generator.pv"
    fprintf(file, "extern ");
    #line 615 "src/compiler/Generator.pv"
    if (self->current_host) {
        #line 615 "src/compiler/Generator.pv"
        fprintf(file, "PAVE_HOST_API ");
    }
}

#line 618 "src/compiler/Generator.pv"
bool Generator__write_file_list(struct Generator* self, char const* name, struct Array_String* files) {
    #line 619 "src/compiler/Generator.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 620 "src/compiler/Generator.pv"
    String__append(&path, str__new(self->path));
    #line 621 "src/compiler/Generator.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 622 "src/compiler/Generator.pv"
    String__append(&path, str__new(name));
    #line 623 "src/compiler/Generator.pv"
    FILE* file = fopen(String__c_str(&path), "wb");
    #line 624 "src/compiler/Generator.pv"
    if (file == 0) {
        #line 624 "src/compiler/Generator.pv"
        perror(String__c_str(&path));
        #line 624 "src/compiler/Generator.pv"
        return false;
    }
    #line 625 "src/compiler/Generator.pv"
    { struct Iter_ref_String __iter = Array_String__iter(files);
    #line 625 "src/compiler/Generator.pv"
    while (Iter_ref_String__next(&__iter)) {
        #line 625 "src/compiler/Generator.pv"
        struct String* code_file = Iter_ref_String__value(&__iter);

        #line 626 "src/compiler/Generator.pv"
        uint32_t length = code_file->array.length;
        #line 627 "src/compiler/Generator.pv"
        fprintf(file, "%.*s\n", length, code_file->array.data);
    } }
    #line 629 "src/compiler/Generator.pv"
    fclose(file);
    #line 630 "src/compiler/Generator.pv"
    return true;
}

#line 637 "src/compiler/Generator.pv"
struct GenericMap* Generator__trait_default_generics(struct Generator* self, struct Impl* impl_info, struct GenericMap* generics) {
    #line 638 "src/compiler/Generator.pv"
    struct Trait* trait_info = impl_info->trait_;
    #line 639 "src/compiler/Generator.pv"
    if (trait_info == 0 || usize__Eq_usize__eq(trait_info->generics.array.length, 0)) {
        #line 639 "src/compiler/Generator.pv"
        return generics;
    }
    #line 640 "src/compiler/Generator.pv"
    struct GenericMap* trait_map = 0;
    #line 641 "src/compiler/Generator.pv"
    switch (impl_info->trait_type.type) {
        #line 642 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 642 "src/compiler/Generator.pv"
            struct GenericMap* bound_map = impl_info->trait_type.trait_value._1;
            #line 642 "src/compiler/Generator.pv"
            trait_map = bound_map;
        } break;
        #line 643 "src/compiler/Generator.pv"
        default: {
        } break;
    }
    #line 645 "src/compiler/Generator.pv"
    if (trait_map == 0) {
        #line 645 "src/compiler/Generator.pv"
        return generics;
    }
    #line 646 "src/compiler/Generator.pv"
    struct GenericMap result_val = GenericMap__clone(generics, self->allocator);
    #line 647 "src/compiler/Generator.pv"
    struct GenericMap* result = ArenaAllocator__store_GenericMap(self->allocator, &result_val);
    #line 648 "src/compiler/Generator.pv"
    if (result == 0) {
        #line 648 "src/compiler/Generator.pv"
        return generics;
    }
    #line 649 "src/compiler/Generator.pv"
    { struct Iter_ref_Generic __iter = Array_Generic__iter(&trait_info->generics.array);
    #line 649 "src/compiler/Generator.pv"
    while (Iter_ref_Generic__next(&__iter)) {
        #line 649 "src/compiler/Generator.pv"
        struct Generic* generic = Iter_ref_Generic__value(&__iter);

        #line 650 "src/compiler/Generator.pv"
        struct Token* generic_name = generic->name;
        #line 651 "src/compiler/Generator.pv"
        if (generic_name == 0) {
            #line 651 "src/compiler/Generator.pv"
            continue;
        }
        #line 652 "src/compiler/Generator.pv"
        struct Type* bound = GenericMap__get(trait_map, generic_name->value);
        #line 653 "src/compiler/Generator.pv"
        if (bound == 0) {
            #line 653 "src/compiler/Generator.pv"
            continue;
        }
        #line 654 "src/compiler/Generator.pv"
        struct Type* resolved = Context__resolve_type(self->allocator, bound, generics, 0);
        #line 655 "src/compiler/Generator.pv"
        GenericMap__insert(result, generic_name->value, resolved != 0 ? *resolved : *bound);
    } }
    #line 657 "src/compiler/Generator.pv"
    return result;
}

#line 660 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 661 "src/compiler/Generator.pv"
    struct String result = Generator__make_rel_path(self, module, name, ext);
    #line 662 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 663 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = self->path, .length = strlen(self->path) });
    #line 664 "src/compiler/Generator.pv"
    return result;
}

#line 667 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 668 "src/compiler/Generator.pv"
    struct String result = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 669 "src/compiler/Generator.pv"
    struct Namespace* namespace = 0;
    #line 670 "src/compiler/Generator.pv"
    if (module != 0) {
        #line 670 "src/compiler/Generator.pv"
        namespace = (*module).namespace;
    }

    #line 672 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 673 "src/compiler/Generator.pv"
        struct Namespace namespace_info = *namespace;
        #line 674 "src/compiler/Generator.pv"
        String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 675 "src/compiler/Generator.pv"
        String__prepend(&result, namespace_info.name);
        #line 676 "src/compiler/Generator.pv"
        namespace = namespace_info.parent;
    }

    #line 679 "src/compiler/Generator.pv"
    String__append(&result, name);
    #line 680 "src/compiler/Generator.pv"
    String__append(&result, ext);

    #line 682 "src/compiler/Generator.pv"
    return result;
}

#line 685 "src/compiler/Generator.pv"
void Generator__collect_primitive_includes(struct Generator* self, struct Type* type, struct GenericMap* generics, struct HashSet_str* out) {
    #line 686 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 687 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 687 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 688 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 688 "src/compiler/Generator.pv"
                return;
            }
            #line 689 "src/compiler/Generator.pv"
            struct Primitive primitive = *primitive_info;
            #line 690 "src/compiler/Generator.pv"
            struct str* inc = HashMap_str_str__find(&self->primitive_includes, &primitive.name);
            #line 691 "src/compiler/Generator.pv"
            if (inc != 0) {
                #line 691 "src/compiler/Generator.pv"
                HashSet_str__insert(out, *inc);
            }
        } break;
        #line 693 "src/compiler/Generator.pv"
        case TYPE__GLOBAL: {
            #line 693 "src/compiler/Generator.pv"
            struct Global* g = type->global_value;
            #line 693 "src/compiler/Generator.pv"
            Generator__collect_primitive_includes(self, &g->type, generics, out);
        } break;
        #line 694 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 698 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics) {
    #line 699 "src/compiler/Generator.pv"
    struct String trait_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 700 "src/compiler/Generator.pv"
    struct Token trait_token = *trait_info->name;

    #line 702 "src/compiler/Generator.pv"
    String__append(&trait_name, struct_name);
    #line 703 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 704 "src/compiler/Generator.pv"
    String__append(&trait_name, trait_token.value);

    #line 706 "src/compiler/Generator.pv"
    if (impl_trait_type != 0) {
        #line 707 "src/compiler/Generator.pv"
        struct Type impl_trait = *impl_trait_type;
        #line 708 "src/compiler/Generator.pv"
        switch (impl_trait.type) {
            #line 709 "src/compiler/Generator.pv"
            case TYPE__TRAIT: {
                #line 709 "src/compiler/Generator.pv"
                struct Trait* ti = impl_trait.trait_value._0;
                #line 709 "src/compiler/Generator.pv"
                struct GenericMap* tmap = impl_trait.trait_value._1;
                #line 710 "src/compiler/Generator.pv"
                if (tmap != 0) {
                    #line 711 "src/compiler/Generator.pv"
                    struct GenericMap trait_generics = *tmap;
                    #line 712 "src/compiler/Generator.pv"
                    struct Trait impl_trait_info = *ti;
                    #line 713 "src/compiler/Generator.pv"
                    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&impl_trait_info.generics.map);
                    #line 713 "src/compiler/Generator.pv"
                    while (HashMapIter_str_usize__next(&__iter)) {
                        #line 713 "src/compiler/Generator.pv"
                        struct str gname = HashMapIter_str_usize__value(&__iter)->_0;

                        #line 714 "src/compiler/Generator.pv"
                        if (HashMap_str_usize__find(&impl_trait_info.typedefs, &gname) == 0) {
                            #line 715 "src/compiler/Generator.pv"
                            struct Type* gtype = GenericMap__get(&trait_generics, gname);
                            #line 716 "src/compiler/Generator.pv"
                            if (gtype != 0) {
                                #line 717 "src/compiler/Generator.pv"
                                String__append(&trait_name, (struct str){ .ptr = "_", .length = strlen("_") });
                                #line 718 "src/compiler/Generator.pv"
                                struct String type_name = Naming__get_type_name(&self->naming_ident, gtype, generics->self_type, generics);
                                #line 719 "src/compiler/Generator.pv"
                                String__append_string(&trait_name, &type_name);
                            }
                        }
                    } }
                }
            } break;
            #line 725 "src/compiler/Generator.pv"
            default: {
            } break;
        }
    }

    #line 729 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 730 "src/compiler/Generator.pv"
    struct Token func_name = *func_info->name;
    #line 731 "src/compiler/Generator.pv"
    String__append(&trait_name, func_name.value);

    #line 733 "src/compiler/Generator.pv"
    return trait_name;
}

#line 736 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Array_str game_namespaces, struct Root* root) {
    #line 737 "src/compiler/Generator.pv"
    bool result = true;

    #line 739 "src/compiler/Generator.pv"
    struct Generator self = (struct Generator) {
        .allocator = allocator,
        .path = path,
        .root = root,
        .primitives = HashMap_str_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitive_includes = HashMap_str_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .code_files = Array_String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .error = FileWriter__new(stderr),
        .output_line_directives = output_line_directives,
        .naming_decl = &root->naming_decl,
        .naming_ident = Naming__new_ident(allocator),
        .indent = 0,
        .naming_c99 = (struct Naming) { .allocator = allocator, .type = NAMING_TYPE__IDENT, .generic_start = (struct str){ .ptr = "", .length = strlen("") }, .generic_seperator = (struct str){ .ptr = "", .length = strlen("") }, .generic_end = (struct str){ .ptr = "", .length = strlen("") }, .pointer_prefix = (struct str){ .ptr = "", .length = strlen("") }, .pointer_suffix = (struct str){ .ptr = "", .length = strlen("") }, .pointer_const_prefix = (struct str){ .ptr = "", .length = strlen("") }, .pointer_const_suffix = (struct str){ .ptr = "", .length = strlen("") }, .reference_prefix = (struct str){ .ptr = "", .length = strlen("") }, .reference_suffix = (struct str){ .ptr = "", .length = strlen("") }, .sequence_slice_prefix = (struct str){ .ptr = "", .length = strlen("") }, .sequence_open = (struct str){ .ptr = "", .length = strlen("") }, .sequence_fixed_delimiter = (struct str){ .ptr = "", .length = strlen("") }, .sequence_close = (struct str){ .ptr = "", .length = strlen("") }, .tuple_prefix = (struct str){ .ptr = "", .length = strlen("") }, .tuple_open = (struct str){ .ptr = "", .length = strlen("") }, .tuple_close = (struct str){ .ptr = "", .length = strlen("") }, .enum_generic_type_suffix = (struct str){ .ptr = "", .length = strlen("") }, .enum_prefix = (struct str){ .ptr = "", .length = strlen("") }, .struct_prefix = (struct str){ .ptr = "", .length = strlen("") }, .trait_prefix = (struct str){ .ptr = "", .length = strlen("") }, .union_prefix = (struct str){ .ptr = "", .length = strlen("") }, .coroutine_instance_prefix = (struct str){ .ptr = "", .length = strlen("") }, .primitives = (struct HashMap_str_str) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 }, .naming_ident = 0 },
        .function_context = 0,
        .game_namespaces = game_namespaces,
        .current_host = false,
        .host_files = Array_String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .game_files = Array_String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .type_impl_usages = 0,
        .type_impl_paths = HashSet_str__new(allocator),
    };

    #line 761 "src/compiler/Generator.pv"
    self.naming_c99 = Naming__new_c99(allocator, &self.naming_ident);

    #line 763 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitives = &self.primitives;
    #line 764 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 765 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 766 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 767 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 768 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 769 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 770 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 771 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 772 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 773 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 774 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 775 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 776 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 777 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 778 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 780 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitive_includes = &self.primitive_includes;
    #line 781 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 782 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 783 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 784 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 785 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 786 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 787 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 788 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 789 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 790 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 791 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "stdbool", .length = strlen("stdbool") });
    #line 792 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "str", .length = strlen("str") }, (struct str){ .ptr = "string", .length = strlen("string") });

    #line 794 "src/compiler/Generator.pv"
    struct FileGenerator file_gen = (struct FileGenerator) { .generator = &self };

    #line 796 "src/compiler/Generator.pv"
    FileGenerator__create_directories(&file_gen, (struct str){ .ptr = path, .length = strlen(path) }, &root->children);

    #line 798 "src/compiler/Generator.pv"
    bool success = true;

    #line 800 "src/compiler/Generator.pv"
    struct Usages usages = Usages__new(&self);
    #line 801 "src/compiler/Generator.pv"
    self.type_impl_usages = &usages.type_impls;
    #line 802 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Primitive __iter = HashMap_usize_TypeUsage_Primitive__iter(&usages.primitives);
    #line 802 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Primitive__next(&__iter)) {
        #line 802 "src/compiler/Generator.pv"
        struct TypeUsage_Primitive* usage = &HashMapIter_usize_TypeUsage_Primitive__value(&__iter)->_1;

        #line 802 "src/compiler/Generator.pv"
        success = FileGenerator__generate_primitive_loop(&file_gen, usage) && success;
    } }
    #line 803 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Struct __iter = HashMap_usize_TypeUsage_Struct__iter(&usages.structs);
    #line 803 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Struct__next(&__iter)) {
        #line 803 "src/compiler/Generator.pv"
        struct TypeUsage_Struct* usage = &HashMapIter_usize_TypeUsage_Struct__value(&__iter)->_1;

        #line 803 "src/compiler/Generator.pv"
        success = FileGenerator__generate_struct_loop(&file_gen, usage) && success;
    } }
    #line 804 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Enum __iter = HashMap_usize_TypeUsage_Enum__iter(&usages.enums);
    #line 804 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Enum__next(&__iter)) {
        #line 804 "src/compiler/Generator.pv"
        struct TypeUsage_Enum* usage = &HashMapIter_usize_TypeUsage_Enum__value(&__iter)->_1;

        #line 804 "src/compiler/Generator.pv"
        success = FileGenerator__generate_enum_loop(&file_gen, usage) && success;
    } }
    #line 805 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Trait __iter = HashMap_usize_TypeUsage_Trait__iter(&usages.traits);
    #line 805 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Trait__next(&__iter)) {
        #line 805 "src/compiler/Generator.pv"
        struct TypeUsage_Trait* usage = &HashMapIter_usize_TypeUsage_Trait__value(&__iter)->_1;

        #line 805 "src/compiler/Generator.pv"
        success = FileGenerator__generate_trait_loop(&file_gen, usage) && success;
    } }
    #line 806 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeFunctionUsage __iter = HashMap_usize_TypeFunctionUsage__iter(&usages.functions);
    #line 806 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeFunctionUsage__next(&__iter)) {
        #line 806 "src/compiler/Generator.pv"
        struct TypeFunctionUsage* usage = &HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_1;

        #line 806 "src/compiler/Generator.pv"
        success = FileGenerator__generate_function_loop(&file_gen, usage) && success;
    } }
    #line 807 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Sequence __iter = HashMap_usize_TypeUsage_Sequence__iter(&usages.sequences);
    #line 807 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Sequence__next(&__iter)) {
        #line 807 "src/compiler/Generator.pv"
        struct TypeUsage_Sequence* usage = &HashMapIter_usize_TypeUsage_Sequence__value(&__iter)->_1;

        #line 807 "src/compiler/Generator.pv"
        success = FileGenerator__generate_sequence(&file_gen, usage) && success;
    } }
    #line 808 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Tuple __iter = HashMap_usize_TypeUsage_Tuple__iter(&usages.tuples);
    #line 808 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Tuple__next(&__iter)) {
        #line 808 "src/compiler/Generator.pv"
        struct TypeUsage_Tuple* usage = &HashMapIter_usize_TypeUsage_Tuple__value(&__iter)->_1;

        #line 808 "src/compiler/Generator.pv"
        success = FileGenerator__generate_tuple_loop(&file_gen, usage) && success;
    } }
    #line 809 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_TypeImpl __iter = HashMap_usize_TypeUsage_TypeImpl__iter(&usages.type_impls);
    #line 809 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_TypeImpl__next(&__iter)) {
        #line 809 "src/compiler/Generator.pv"
        struct TypeUsage_TypeImpl* usage = &HashMapIter_usize_TypeUsage_TypeImpl__value(&__iter)->_1;

        #line 809 "src/compiler/Generator.pv"
        success = FileGenerator__generate_type_impl_loop(&file_gen, usage) && success;
    } }
    #line 810 "src/compiler/Generator.pv"
    FileGenerator__generate_globals_namespace(&file_gen, &root->children);
    #line 811 "src/compiler/Generator.pv"
    FileGenerator__generate_test_runner(&file_gen, &root->children);
    #line 812 "src/compiler/Generator.pv"
    if (mem_file_flush() != 0) {
        #line 812 "src/compiler/Generator.pv"
        success = false;
    }

    #line 814 "src/compiler/Generator.pv"
    if (!success) {
        #line 815 "src/compiler/Generator.pv"
        fprintf(stderr, "Generation failed\n");
        #line 816 "src/compiler/Generator.pv"
        return false;
    }

    #line 819 "src/compiler/Generator.pv"
    if (game_namespaces.length > 0) {
        #line 820 "src/compiler/Generator.pv"
        if (!Generator__write_file_list(&self, "pave_host_sources.txt", &self.host_files) || !Generator__write_file_list(&self, "pave_game_sources.txt", &self.game_files)) {
            #line 820 "src/compiler/Generator.pv"
            return false;
        }
    }

    #line 823 "src/compiler/Generator.pv"
    if (self.code_files.length > 0) {
        #line 824 "src/compiler/Generator.pv"
        struct String command = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

        #line 826 "src/compiler/Generator.pv"
        { struct Iter_ref_String __iter = Array_String__iter(&self.code_files);
        #line 826 "src/compiler/Generator.pv"
        while (Iter_ref_String__next(&__iter)) {
            #line 826 "src/compiler/Generator.pv"
            struct String* code_file = Iter_ref_String__value(&__iter);

            #line 827 "src/compiler/Generator.pv"
            if (command.array.length > 0) {
                #line 828 "src/compiler/Generator.pv"
                String__append(&command, (struct str){ .ptr = output_seperator, .length = strlen(output_seperator) });
            }

            #line 831 "src/compiler/Generator.pv"
            String__append(&command, String__as_str(code_file));
        } }

        #line 834 "src/compiler/Generator.pv"
        uint32_t length = command.array.length;
        #line 835 "src/compiler/Generator.pv"
        printf("%.*s\n", length, command.array.data);
    }

    #line 838 "src/compiler/Generator.pv"
    return result;
}
