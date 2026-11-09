#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

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

#line 45 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file) {
    #line 46 "src/compiler/Generator.pv"
    int16_t i = 0;
    #line 47 "src/compiler/Generator.pv"
    while (i < self->indent) {
        #line 48 "src/compiler/Generator.pv"
        fprintf(file, "    ");
        #line 49 "src/compiler/Generator.pv"
        i += 1;
    }
}

#line 53 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s) {
    #line 54 "src/compiler/Generator.pv"
    int32_t length = s.length;
    #line 55 "src/compiler/Generator.pv"
    fprintf(file, "%.*s", length, s.ptr);
    #line 56 "src/compiler/Generator.pv"
    return true;
}

#line 59 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s) {
    #line 60 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, String__as_str(s));
}

#line 63 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s) {
    #line 64 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 65 "src/compiler/Generator.pv"
    uintptr_t length = s.length;
    #line 66 "src/compiler/Generator.pv"
    bool was_lowercase = false;

    #line 68 "src/compiler/Generator.pv"
    while (i < length) {
        #line 69 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 71 "src/compiler/Generator.pv"
        if (c >= 'a' && c <= 'z') {
            #line 72 "src/compiler/Generator.pv"
            fprintf(file, "%c", c - 32);
            #line 73 "src/compiler/Generator.pv"
            was_lowercase = true;
        } else {
            #line 75 "src/compiler/Generator.pv"
            if (was_lowercase && (c >= 'A') && (c <= 'Z')) {
                #line 76 "src/compiler/Generator.pv"
                fprintf(file, "_");
            }

            #line 79 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
            #line 80 "src/compiler/Generator.pv"
            was_lowercase = false;
        }

        #line 83 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 86 "src/compiler/Generator.pv"
    return true;
}

#line 89 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s) {
    #line 90 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 91 "src/compiler/Generator.pv"
    uintptr_t length = s.length;

    #line 93 "src/compiler/Generator.pv"
    while (i < length) {
        #line 94 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 96 "src/compiler/Generator.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 97 "src/compiler/Generator.pv"
            fprintf(file, "%c", c + 32);
        } else {
            #line 99 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
        }

        #line 102 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 105 "src/compiler/Generator.pv"
    return true;
}

#line 108 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token) {
    #line 109 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, token->value);
}

#line 112 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 113 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 114 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 114 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 114 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, &indirect->to, generics);
        } break;
        #line 115 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 115 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 115 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 116 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 116 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 117 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 120 "src/compiler/Generator.pv"
    return false;
}

#line 123 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union_no_indirect(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 124 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 125 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 125 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 125 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 126 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 126 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 127 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 130 "src/compiler/Generator.pv"
    return false;
}

#line 133 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 134 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_c99, type, generics->self_type, generics);
    #line 135 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 136 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 137 "src/compiler/Generator.pv"
    return true;
}

#line 140 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 141 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_ident, type, generics->self_type, generics);
    #line 142 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 143 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 144 "src/compiler/Generator.pv"
    return true;
}

#line 147 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics) {
    #line 148 "src/compiler/Generator.pv"
    struct Type* self_type = type;
    #line 149 "src/compiler/Generator.pv"
    if (generics != 0) {
        #line 149 "src/compiler/Generator.pv"
        self_type = (*generics).self_type;
    }

    #line 151 "src/compiler/Generator.pv"
    struct String variable_decl = Naming__get_variable_decl(&self->naming_c99, name, type, self_type, generics);
    #line 152 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&variable_decl));
    #line 153 "src/compiler/Generator.pv"
    String__release(&variable_decl);

    #line 155 "src/compiler/Generator.pv"
    Generator__write_array_decl_suffix(self, file, type, generics);

    #line 157 "src/compiler/Generator.pv"
    return true;
}

#line 160 "src/compiler/Generator.pv"
void Generator__write_array_decl_suffix(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 161 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 162 "src/compiler/Generator.pv"
        case TYPE__SEQUENCE: {
            #line 162 "src/compiler/Generator.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 163 "src/compiler/Generator.pv"
            switch (sequence->type.type) {
                #line 164 "src/compiler/Generator.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 164 "src/compiler/Generator.pv"
                    struct Expression* length = sequence->type.fixedarray_value;
                    #line 165 "src/compiler/Generator.pv"
                    fprintf(file, "[");
                    #line 166 "src/compiler/Generator.pv"
                    ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = self }}, file, length, generics);
                    #line 167 "src/compiler/Generator.pv"
                    fprintf(file, "]");
                    #line 168 "src/compiler/Generator.pv"
                    Generator__write_array_decl_suffix(self, file, &sequence->element, generics);
                } break;
                #line 170 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 173 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 177 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 178 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
    #line 179 "src/compiler/Generator.pv"

    #line 181 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&name));

    #line 183 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 186 "src/compiler/Generator.pv"
bool Generator__write_dynamic_vtable_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 187 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
    #line 188 "src/compiler/Generator.pv"

    #line 190 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, String__as_str(&name));

    #line 192 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 195 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type) {
    #line 196 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 197 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 197 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 198 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 198 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 198 "src/compiler/Generator.pv"
            return Generator__is_reference(info->type);
        } break;
        #line 199 "src/compiler/Generator.pv"
        default: {
            #line 199 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 203 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 204 "src/compiler/Generator.pv"
    struct Type* __pave_tmp_0 = Type__deref(type);
    switch (__pave_tmp_0->type) {
        #line 205 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 205 "src/compiler/Generator.pv"
            struct Struct* struct_info = __pave_tmp_0->struct_value._0;
            #line 205 "src/compiler/Generator.pv"
            return Struct__is_newtype(struct_info);
        } break;
        #line 206 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 206 "src/compiler/Generator.pv"
            return Generator__is_type_single_value_struct(self, generics->self_type, generics);
        } break;
        #line 207 "src/compiler/Generator.pv"
        default: {
            #line 207 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 211 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map) {
    #line 212 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 213 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 214 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 215 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting Self for function, but no generic map input\n");
                #line 216 "src/compiler/Generator.pv"
                return 0;
            }

            #line 219 "src/compiler/Generator.pv"
            return Generator__get_function(self, (*generic_map).self_type, func_name, generic_map);
        } break;
        #line 221 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 221 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 221 "src/compiler/Generator.pv"
            return Generator__get_function(self, &indirect->to, func_name, generic_map);
        } break;
        #line 222 "src/compiler/Generator.pv"
        case TYPE__GENERIC: {
            #line 222 "src/compiler/Generator.pv"
            struct Generic* generic = type->generic_value;
            #line 223 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 224 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, but no generic map input\n");
                #line 225 "src/compiler/Generator.pv"
                return 0;
            }

            #line 228 "src/compiler/Generator.pv"
            struct Token generic_name = *generic->name;
            #line 229 "src/compiler/Generator.pv"
            struct Type* generic_type = GenericMap__get(&(*generic_map), generic_name.value);
            #line 230 "src/compiler/Generator.pv"
            if (generic_type == 0) {
                #line 231 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, no item in generic map found\n");
                #line 232 "src/compiler/Generator.pv"
                return 0;
            }

            #line 235 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_type, func_name, generic_map);
        } break;
        #line 237 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 237 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 238 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 239 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting primitive for function, but no primitive info found\n");
                #line 240 "src/compiler/Generator.pv"
                return 0;
            }

            #line 243 "src/compiler/Generator.pv"
            struct Primitive primitive = *primitive_info;
            #line 244 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 246 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&primitive.impls);
            #line 247 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 248 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 249 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 252 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 253 "src/compiler/Generator.pv"
                int32_t name_length = primitive.name.length;
                #line 254 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 255 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitives %.*s function %.*s for get_function\n", name_length, primitive.name.ptr, func_name_length, func_name.ptr);
            }

            #line 258 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 260 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 260 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 261 "src/compiler/Generator.pv"
            struct Function* func_info = 0;
            #line 262 "src/compiler/Generator.pv"
            struct Token enum_name = *enum_info->name;

            #line 264 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 265 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 266 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 267 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 270 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 271 "src/compiler/Generator.pv"
                int32_t name_length = enum_name.value.length;
                #line 272 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 273 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enums %.*s function %.*s for get_function\n", name_length, enum_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 276 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 278 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 278 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 279 "src/compiler/Generator.pv"
            struct Function* func_info = 0;
            #line 280 "src/compiler/Generator.pv"
            struct Token struct_name = *struct_info->name;

            #line 282 "src/compiler/Generator.pv"
            { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
            #line 282 "src/compiler/Generator.pv"
            while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
                #line 282 "src/compiler/Generator.pv"
                uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
                #line 282 "src/compiler/Generator.pv"
                struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

                #line 283 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);

                #line 285 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 285 "src/compiler/Generator.pv"
                    break;
                }

                #line 287 "src/compiler/Generator.pv"
                if (impl_info->trait_ != 0) {
                    #line 288 "src/compiler/Generator.pv"
                    struct Trait trait_info = *impl_info->trait_;
                    #line 289 "src/compiler/Generator.pv"
                    func_info = HashMap_str_Function__find(&trait_info.functions, &func_name);
                }

                #line 292 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 293 "src/compiler/Generator.pv"
                    struct Function* stored_func_info = ArenaAllocator__store_Function(self->allocator, func_info);
                    #line 294 "src/compiler/Generator.pv"
                    if (stored_func_info != 0) {
                        #line 295 "src/compiler/Generator.pv"
                        stored_func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                    }
                    #line 297 "src/compiler/Generator.pv"
                    func_info = stored_func_info;
                    #line 298 "src/compiler/Generator.pv"
                    break;
                }
            } }

            #line 302 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 303 "src/compiler/Generator.pv"
                int32_t name_length = struct_name.value.length;
                #line 304 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 305 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find structs %.*s function %.*s for get_function\n", name_length, struct_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 308 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 310 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 310 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 311 "src/compiler/Generator.pv"
            struct Token trait_name = *trait_info->name;
            #line 312 "src/compiler/Generator.pv"
            struct Function* func_info = HashMap_str_Function__find(&trait_info->functions, &func_name);

            #line 314 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 315 "src/compiler/Generator.pv"
                int32_t name_length = trait_name.value.length;
                #line 316 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 317 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find traits %.*s function %.*s for get_function\n", name_length, trait_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 320 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 322 "src/compiler/Generator.pv"
        default: {
            #line 323 "src/compiler/Generator.pv"
            fprintf(stderr, "Unhandled type for getting function %s\n", Type__name(type));
        } break;
    }

    #line 327 "src/compiler/Generator.pv"
    return 0;
}

#line 330 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant) {
    #line 331 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;
    #line 332 "src/compiler/Generator.pv"
    struct Token name = *parent->name;
    #line 333 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, name.value);
    #line 334 "src/compiler/Generator.pv"
    fprintf(file, "__");
    #line 335 "src/compiler/Generator.pv"
    struct Token* variant_name = variant->name;
    #line 336 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, variant_name->value);

    #line 338 "src/compiler/Generator.pv"
    return true;
}

#line 341 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 342 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 343 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 343 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 344 "src/compiler/Generator.pv"
            fprintf(file, "*");
            #line 345 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, &indirect->to, generics);
        } break;
        #line 347 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 347 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 348 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, info->type, generics);
        } break;
        #line 350 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 353 "src/compiler/Generator.pv"
    return true;
}

#line 356 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics) {
    #line 357 "src/compiler/Generator.pv"
    fprintf(file, "::");
    #line 358 "src/compiler/Generator.pv"
    return true;
}

#line 361 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 362 "src/compiler/Generator.pv"
    if (Type__is_fat_pointer(type)) {
        #line 363 "src/compiler/Generator.pv"
        fprintf(file, ".");
        #line 364 "src/compiler/Generator.pv"
        return true;
    }

    #line 367 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 368 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 369 "src/compiler/Generator.pv"
            fprintf(file, "->");
        } break;
        #line 371 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 372 "src/compiler/Generator.pv"
            return Generator__write_instance_member_accessor(self, file, generics->self_type, generics);
        } break;
        #line 374 "src/compiler/Generator.pv"
        default: {
            #line 375 "src/compiler/Generator.pv"
            fprintf(file, ".");
        } break;
    }

    #line 379 "src/compiler/Generator.pv"
    return true;
}

#line 382 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value) {
    #line 383 "src/compiler/Generator.pv"
    if (value.length > 2 && char__Eq_char__eq(value.ptr[0], '0') && (char__Eq_char__eq(value.ptr[1], 'b') || char__Eq_char__eq(value.ptr[1], 'B'))) {
        #line 385 "src/compiler/Generator.pv"
        uint64_t acc = 0;
        #line 386 "src/compiler/Generator.pv"
        bool unsigned_suffix = false;
        #line 387 "src/compiler/Generator.pv"
        uintptr_t i = 2;
        #line 388 "src/compiler/Generator.pv"
        while (i < value.length) {
            #line 389 "src/compiler/Generator.pv"
            char c = value.ptr[i];
            #line 390 "src/compiler/Generator.pv"
            if (char__Eq_char__eq(c, '0') || char__Eq_char__eq(c, '1')) {
                #line 391 "src/compiler/Generator.pv"
                acc = (acc << 1) | (uint64_t)(c - '0');
            } else if (char__Eq_char__eq(c, 'u') || char__Eq_char__eq(c, 'U')) {
                #line 393 "src/compiler/Generator.pv"
                unsigned_suffix = true;
            }
            #line 395 "src/compiler/Generator.pv"
            i += 1;
        }
        #line 397 "src/compiler/Generator.pv"
        fprintf(file, "0x%llx", acc);
        #line 398 "src/compiler/Generator.pv"
        if (unsigned_suffix) {
            #line 398 "src/compiler/Generator.pv"
            fprintf(file, "u");
        }
    } else if (value.length > 0 && value.ptr[0] >= '0' && value.ptr[0] <= '9') {
        #line 400 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 401 "src/compiler/Generator.pv"
        while (i < value.length) {
            #line 402 "src/compiler/Generator.pv"
            if (value.ptr[i] != '_') {
                #line 403 "src/compiler/Generator.pv"
                fprintf(file, "%c", (int32_t)(value.ptr[i]));
            }
            #line 405 "src/compiler/Generator.pv"
            i += 1;
        }
    } else {
        #line 408 "src/compiler/Generator.pv"
        Generator__write_str(self, file, value);
    }

    #line 411 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 412 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 412 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 413 "src/compiler/Generator.pv"
            if (primitive_info != 0 && str__Eq_str__eq((*primitive_info).name, (struct str){ .ptr = "u64", .length = strlen("u64") })) {
                #line 414 "src/compiler/Generator.pv"
                fprintf(file, "ULL");
            }
        } break;
        #line 417 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 420 "src/compiler/Generator.pv"
    return true;
}

#line 423 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 424 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);
    #line 425 "src/compiler/Generator.pv"

    #line 427 "src/compiler/Generator.pv"
    Hash type_id = Fnv1a__hash(type_name.array.data, String__length(&type_name));

    #line 429 "src/compiler/Generator.pv"
    fprintf(file, "%zuULL", type_id);

    #line 431 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 434 "src/compiler/Generator.pv"
bool Generator__write_typename(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 435 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);
    #line 436 "src/compiler/Generator.pv"

    #line 438 "src/compiler/Generator.pv"
    fprintf(file, "\"");
    #line 439 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &type_name);
    #line 440 "src/compiler/Generator.pv"
    fprintf(file, "\"");

    #line 442 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 445 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token) {
    #line 446 "src/compiler/Generator.pv"
    if (self->output_line_directives) {
        #line 447 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 448 "src/compiler/Generator.pv"
        fprintf(file, "#line %zu \"", token->start_line + 1);
        #line 449 "src/compiler/Generator.pv"
        Generator__write_str(self, file, context->path);
        #line 450 "src/compiler/Generator.pv"
        fprintf(file, "\"\n");
    }
}

#line 454 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes) {
    #line 455 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(includes);
    #line 455 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 455 "src/compiler/Generator.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 456 "src/compiler/Generator.pv"
        struct str path = include->path;
        #line 457 "src/compiler/Generator.pv"
        if (path.length > 0) {
            #line 458 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s>\n", (int32_t)(path.length - 2), path.ptr + 1);
        }
    } }

    #line 462 "src/compiler/Generator.pv"
    if (includes->length > 0) {
        #line 463 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 467 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls) {
    #line 468 "src/compiler/Generator.pv"
    struct HashSet_str written = HashSet_str__new(self->allocator);
    #line 469 "src/compiler/Generator.pv"

    #line 471 "src/compiler/Generator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 471 "src/compiler/Generator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 471 "src/compiler/Generator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 472 "src/compiler/Generator.pv"
        struct Module* module = impl_info->context->module;
        #line 473 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&module->includes);
        #line 473 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Include__next(&__iter)) {
            #line 473 "src/compiler/Generator.pv"
            struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

            #line 474 "src/compiler/Generator.pv"
            if (!HashSet_str__insert(&written, include->path)) {
                #line 474 "src/compiler/Generator.pv"
                continue;
            }
            #line 475 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 476 "src/compiler/Generator.pv"
            Generator__write_str(self, file, include->path);
            #line 477 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } }
    } }
    HashSet_str__release(&written);
}

#line 482 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives) {
    #line 483 "src/compiler/Generator.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);

    #line 485 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(primitives);
    #line 485 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 485 "src/compiler/Generator.pv"
        struct str* primitive = HashSetIter_str__value(&__iter);

        #line 486 "src/compiler/Generator.pv"
        if (exclude_primitives && HashSet_str__has(&(*exclude_primitives), primitive)) {
            #line 486 "src/compiler/Generator.pv"
            continue;
        }
        #line 487 "src/compiler/Generator.pv"
        struct str* include = HashMap_str_str__find(&self->primitive_includes, primitive);
        #line 488 "src/compiler/Generator.pv"
        if (include == 0) {
            #line 488 "src/compiler/Generator.pv"
            continue;
        }
        #line 489 "src/compiler/Generator.pv"
        HashSet_str__insert(&includes, *include);
    } }

    #line 492 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 492 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 492 "src/compiler/Generator.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 493 "src/compiler/Generator.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 496 "src/compiler/Generator.pv"
    if (includes.length > 0) {
        #line 497 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 501 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics) {
    #line 502 "src/compiler/Generator.pv"
    if (generics == 0 || (*generics).self_type == 0) {
        #line 502 "src/compiler/Generator.pv"
        return false;
    }

    #line 504 "src/compiler/Generator.pv"
    switch ((*generics).self_type->type) {
        #line 505 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 505 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = (*generics).self_type->primitive_value;
            #line 506 "src/compiler/Generator.pv"
            if (primitive_info == 0 || !str__Eq_str__eq((*primitive_info).name, (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 507 "src/compiler/Generator.pv"
                return false;
            }
        } break;
        #line 510 "src/compiler/Generator.pv"
        default: {
            #line 510 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 513 "src/compiler/Generator.pv"
    struct Type* ref = 0;

    #line 515 "src/compiler/Generator.pv"
    switch (parameter->type.type) {
        #line 516 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 516 "src/compiler/Generator.pv"
            struct Indirect* indirect = parameter->type.indirect_value;
            #line 517 "src/compiler/Generator.pv"
            ref = &indirect->to;
        } break;
        #line 519 "src/compiler/Generator.pv"
        default: {
            #line 519 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 522 "src/compiler/Generator.pv"
    if (ref == 0) {
        #line 522 "src/compiler/Generator.pv"
        return false;
    }

    #line 524 "src/compiler/Generator.pv"
    struct Type ref_type = *ref;
    #line 525 "src/compiler/Generator.pv"
    switch (ref_type.type) {
        #line 526 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 526 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 527 "src/compiler/Generator.pv"
        default: {
            #line 527 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 531 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self) {
    #line 532 "src/compiler/Generator.pv"
    struct FunctionContext function_context = *self->function_context;
    #line 533 "src/compiler/Generator.pv"
    return (*function_context.func_info).type == FUNCTION_TYPE__COROUTINE;
}

#line 537 "src/compiler/Generator.pv"
FILE* Generator__scratch_file(struct Generator* self) {
    #line 538 "src/compiler/Generator.pv"
    if (self->scratch == 0) {
        #line 538 "src/compiler/Generator.pv"
        self->scratch = mem_file_open();
    }
    #line 539 "src/compiler/Generator.pv"
    if (self->scratch != 0) {
        #line 539 "src/compiler/Generator.pv"
        rewind(self->scratch);
    }
    #line 540 "src/compiler/Generator.pv"
    return self->scratch;
}

#line 543 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name) {
    #line 544 "src/compiler/Generator.pv"
    if (self->function_context != 0) {
        #line 545 "src/compiler/Generator.pv"
        name = FunctionContext__get_variable_replacement(&(*self->function_context), name);
    }
    #line 547 "src/compiler/Generator.pv"
    Generator__write_str(self, file, name);
}

#line 550 "src/compiler/Generator.pv"
bool Generator__namespace_is_game(struct Generator* self, struct Module* module) {
    #line 551 "src/compiler/Generator.pv"
    if (module == 0 || usize__Eq_usize__eq(self->game_namespaces.length, 0)) {
        #line 551 "src/compiler/Generator.pv"
        return false;
    }
    #line 552 "src/compiler/Generator.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 553 "src/compiler/Generator.pv"
    struct Namespace* namespace = (*module).namespace;
    #line 554 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 555 "src/compiler/Generator.pv"
        struct Namespace namespace_info = *namespace;
        #line 556 "src/compiler/Generator.pv"
        if (path.array.length > 0) {
            #line 556 "src/compiler/Generator.pv"
            String__prepend(&path, (struct str){ .ptr = "::", .length = strlen("::") });
        }
        #line 557 "src/compiler/Generator.pv"
        String__prepend(&path, namespace_info.name);
        #line 558 "src/compiler/Generator.pv"
        namespace = namespace_info.parent;
    }
    #line 560 "src/compiler/Generator.pv"
    struct str module_path = String__as_str(&path);
    #line 561 "src/compiler/Generator.pv"
    for (uintptr_t i = 0; i != self->game_namespaces.length; i < self->game_namespaces.length ? i++ : i--) {
        #line 562 "src/compiler/Generator.pv"
        struct str game = self->game_namespaces.data[i];
        #line 563 "src/compiler/Generator.pv"
        if (str__Eq_str__eq(module_path, game)) {
            #line 563 "src/compiler/Generator.pv"
            return true;
        }
        #line 564 "src/compiler/Generator.pv"
        if (module_path.length > game.length + 1 && str__starts_with(module_path, game) && char__Eq_char__eq(module_path.ptr[game.length], ':')) {
            #line 564 "src/compiler/Generator.pv"
            return true;
        }
    }
    #line 566 "src/compiler/Generator.pv"
    return false;
}

#line 569 "src/compiler/Generator.pv"
bool Generator__generics_are_game(struct Generator* self, struct GenericMap* generics, uint32_t depth) {
    #line 570 "src/compiler/Generator.pv"
    if (generics == 0) {
        #line 570 "src/compiler/Generator.pv"
        return false;
    }
    #line 571 "src/compiler/Generator.pv"
    struct GenericMap map = *generics;
    #line 572 "src/compiler/Generator.pv"
    for (uintptr_t i = 0; i != map.array.length; i < map.array.length ? i++ : i--) {
        #line 573 "src/compiler/Generator.pv"
        if (Generator__type_is_game(self, &map.array.data[i], depth + 1)) {
            #line 573 "src/compiler/Generator.pv"
            return true;
        }
    }
    #line 575 "src/compiler/Generator.pv"
    return false;
}

#line 580 "src/compiler/Generator.pv"
bool Generator__type_is_game(struct Generator* self, struct Type* type, uint32_t depth) {
    #line 581 "src/compiler/Generator.pv"
    if (depth > 16) {
        #line 581 "src/compiler/Generator.pv"
        return false;
    }
    #line 582 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 583 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 583 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 583 "src/compiler/Generator.pv"
            return Generator__type_is_game(self, &indirect->to, depth + 1);
        } break;
        #line 584 "src/compiler/Generator.pv"
        case TYPE__SEQUENCE: {
            #line 584 "src/compiler/Generator.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 584 "src/compiler/Generator.pv"
            return Generator__type_is_game(self, &sequence->element, depth + 1);
        } break;
        #line 585 "src/compiler/Generator.pv"
        case TYPE__TUPLE: {
            #line 585 "src/compiler/Generator.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 586 "src/compiler/Generator.pv"
            for (uintptr_t i = 0; i != tuple->elements.length; i < tuple->elements.length ? i++ : i--) {
                #line 587 "src/compiler/Generator.pv"
                if (Generator__type_is_game(self, &tuple->elements.data[i], depth + 1)) {
                    #line 587 "src/compiler/Generator.pv"
                    return true;
                }
            }
            #line 589 "src/compiler/Generator.pv"
            return false;
        } break;
        #line 591 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 591 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 591 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->struct_value._1;
            #line 591 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, struct_info->module) || Generator__generics_are_game(self, generics, depth);
        } break;
        #line 592 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 592 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 592 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 592 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, enum_info->context->module) || Generator__generics_are_game(self, generics, depth);
        } break;
        #line 593 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 593 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 593 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->trait_value._1;
            #line 593 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, trait_info->module) || Generator__generics_are_game(self, generics, depth);
        } break;
        #line 594 "src/compiler/Generator.pv"
        case TYPE__FUNCTION: {
            #line 594 "src/compiler/Generator.pv"
            struct Function* func_info = type->function_value._0;
            #line 594 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->function_value._1;
            #line 595 "src/compiler/Generator.pv"
            if (func_info->context != 0) {
                #line 596 "src/compiler/Generator.pv"
                struct Context context = *func_info->context;
                #line 597 "src/compiler/Generator.pv"
                if (Generator__namespace_is_game(self, context.module)) {
                    #line 597 "src/compiler/Generator.pv"
                    return true;
                }
            }
            #line 599 "src/compiler/Generator.pv"
            return Generator__generics_are_game(self, generics, depth);
        } break;
        #line 601 "src/compiler/Generator.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 601 "src/compiler/Generator.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 601 "src/compiler/Generator.pv"
            struct GenericMap* generics = type->coroutineinstance_value._1;
            #line 602 "src/compiler/Generator.pv"
            if (func_info->context != 0) {
                #line 603 "src/compiler/Generator.pv"
                struct Context context = *func_info->context;
                #line 604 "src/compiler/Generator.pv"
                if (Generator__namespace_is_game(self, context.module)) {
                    #line 604 "src/compiler/Generator.pv"
                    return true;
                }
            }
            #line 606 "src/compiler/Generator.pv"
            return Generator__generics_are_game(self, generics, depth);
        } break;
        #line 608 "src/compiler/Generator.pv"
        case TYPE__GLOBAL: {
            #line 608 "src/compiler/Generator.pv"
            struct Global* global = type->global_value;
            #line 608 "src/compiler/Generator.pv"
            return Generator__namespace_is_game(self, global->module);
        } break;
        #line 609 "src/compiler/Generator.pv"
        default: {
            #line 609 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 616 "src/compiler/Generator.pv"
void Generator__begin_file(struct Generator* self, struct Type* type, struct GenericMap* generics, struct Module* module) {
    #line 617 "src/compiler/Generator.pv"
    if (usize__Eq_usize__eq(self->game_namespaces.length, 0)) {
        #line 617 "src/compiler/Generator.pv"
        self->current_host = false;
        #line 617 "src/compiler/Generator.pv"
        return;
    }
    #line 618 "src/compiler/Generator.pv"
    bool game = Generator__namespace_is_game(self, module) || Generator__generics_are_game(self, generics, 0);
    #line 619 "src/compiler/Generator.pv"
    if (!game && type != 0) {
        #line 619 "src/compiler/Generator.pv"
        game = Generator__type_is_game(self, type, 0);
    }
    #line 620 "src/compiler/Generator.pv"
    self->current_host = !game;
}

#line 623 "src/compiler/Generator.pv"
void Generator__add_code_file(struct Generator* self, struct String code) {
    #line 624 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);
    #line 625 "src/compiler/Generator.pv"
    if (usize__Eq_usize__eq(self->game_namespaces.length, 0)) {
        #line 625 "src/compiler/Generator.pv"
        return;
    }
    #line 626 "src/compiler/Generator.pv"
    if (self->current_host) {
        #line 626 "src/compiler/Generator.pv"
        Array_String__append(&self->host_files, code);
    } else {
        #line 626 "src/compiler/Generator.pv"
        Array_String__append(&self->game_files, code);
    }
}

#line 631 "src/compiler/Generator.pv"
void Generator__write_extern(struct Generator* self, FILE* file) {
    #line 632 "src/compiler/Generator.pv"
    fprintf(file, "extern ");
    #line 633 "src/compiler/Generator.pv"
    if (self->current_host) {
        #line 633 "src/compiler/Generator.pv"
        fprintf(file, "PAVE_HOST_API ");
    }
}

#line 636 "src/compiler/Generator.pv"
bool Generator__write_file_list(struct Generator* self, char const* name, struct Array_String* files) {
    #line 637 "src/compiler/Generator.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 638 "src/compiler/Generator.pv"
    String__append(&path, str__new(self->path));
    #line 639 "src/compiler/Generator.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 640 "src/compiler/Generator.pv"
    String__append(&path, str__new(name));
    #line 641 "src/compiler/Generator.pv"
    FILE* file = fopen(String__c_str(&path), "wb");
    #line 642 "src/compiler/Generator.pv"
    if (file == 0) {
        #line 642 "src/compiler/Generator.pv"
        perror(String__c_str(&path));
        #line 642 "src/compiler/Generator.pv"
        return false;
    }
    #line 643 "src/compiler/Generator.pv"
    { struct Iter_ref_String __iter = Array_String__iter(files);
    #line 643 "src/compiler/Generator.pv"
    while (Iter_ref_String__next(&__iter)) {
        #line 643 "src/compiler/Generator.pv"
        struct String* code_file = Iter_ref_String__value(&__iter);

        #line 644 "src/compiler/Generator.pv"
        uint32_t length = code_file->array.length;
        #line 645 "src/compiler/Generator.pv"
        fprintf(file, "%.*s\n", length, code_file->array.data);
    } }
    #line 647 "src/compiler/Generator.pv"
    fclose(file);
    #line 648 "src/compiler/Generator.pv"
    return true;
}

#line 655 "src/compiler/Generator.pv"
struct GenericMap* Generator__trait_default_generics(struct Generator* self, struct Impl* impl_info, struct GenericMap* generics) {
    #line 656 "src/compiler/Generator.pv"
    struct Trait* trait_info = impl_info->trait_;
    #line 657 "src/compiler/Generator.pv"
    if (trait_info == 0 || usize__Eq_usize__eq(trait_info->generics.array.length, 0)) {
        #line 657 "src/compiler/Generator.pv"
        return generics;
    }
    #line 658 "src/compiler/Generator.pv"
    struct GenericMap* trait_map = 0;
    #line 659 "src/compiler/Generator.pv"
    switch (impl_info->trait_type.type) {
        #line 660 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 660 "src/compiler/Generator.pv"
            struct GenericMap* bound_map = impl_info->trait_type.trait_value._1;
            #line 660 "src/compiler/Generator.pv"
            trait_map = bound_map;
        } break;
        #line 661 "src/compiler/Generator.pv"
        default: {
        } break;
    }
    #line 663 "src/compiler/Generator.pv"
    if (trait_map == 0) {
        #line 663 "src/compiler/Generator.pv"
        return generics;
    }
    #line 664 "src/compiler/Generator.pv"
    struct GenericMap result_val = GenericMap__clone(generics, self->allocator);
    #line 665 "src/compiler/Generator.pv"
    struct GenericMap* result = ArenaAllocator__store_GenericMap(self->allocator, &result_val);
    #line 666 "src/compiler/Generator.pv"
    if (result == 0) {
        #line 666 "src/compiler/Generator.pv"
        return generics;
    }
    #line 667 "src/compiler/Generator.pv"
    { struct Iter_ref_Generic __iter = Array_Generic__iter(&trait_info->generics.array);
    #line 667 "src/compiler/Generator.pv"
    while (Iter_ref_Generic__next(&__iter)) {
        #line 667 "src/compiler/Generator.pv"
        struct Generic* generic = Iter_ref_Generic__value(&__iter);

        #line 668 "src/compiler/Generator.pv"
        struct Token* generic_name = generic->name;
        #line 669 "src/compiler/Generator.pv"
        if (generic_name == 0) {
            #line 669 "src/compiler/Generator.pv"
            continue;
        }
        #line 670 "src/compiler/Generator.pv"
        struct Type* bound = GenericMap__get(trait_map, generic_name->value);
        #line 671 "src/compiler/Generator.pv"
        if (bound == 0) {
            #line 671 "src/compiler/Generator.pv"
            continue;
        }
        #line 672 "src/compiler/Generator.pv"
        struct Type* resolved = Context__resolve_type(self->allocator, bound, generics, 0);
        #line 673 "src/compiler/Generator.pv"
        GenericMap__insert(result, generic_name->value, (resolved != 0 ? *resolved : *bound));
    } }
    #line 675 "src/compiler/Generator.pv"
    return result;
}

#line 678 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 679 "src/compiler/Generator.pv"
    struct String result = Generator__make_rel_path(self, module, name, ext);
    #line 680 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 681 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = self->path, .length = strlen(self->path) });
    #line 682 "src/compiler/Generator.pv"
    return result;
}

#line 685 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 686 "src/compiler/Generator.pv"
    struct String result = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 687 "src/compiler/Generator.pv"
    struct Namespace* namespace = 0;
    #line 688 "src/compiler/Generator.pv"
    if (module != 0) {
        #line 688 "src/compiler/Generator.pv"
        namespace = (*module).namespace;
    }

    #line 690 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 691 "src/compiler/Generator.pv"
        struct Namespace namespace_info = *namespace;
        #line 692 "src/compiler/Generator.pv"
        String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 693 "src/compiler/Generator.pv"
        String__prepend(&result, namespace_info.name);
        #line 694 "src/compiler/Generator.pv"
        namespace = namespace_info.parent;
    }

    #line 697 "src/compiler/Generator.pv"
    String__append(&result, name);
    #line 698 "src/compiler/Generator.pv"
    String__append(&result, ext);

    #line 700 "src/compiler/Generator.pv"
    return result;
}

#line 703 "src/compiler/Generator.pv"
void Generator__collect_primitive_includes(struct Generator* self, struct Type* type, struct GenericMap* generics, struct HashSet_str* out) {
    #line 704 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 705 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 705 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 706 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 706 "src/compiler/Generator.pv"
                return;
            }
            #line 707 "src/compiler/Generator.pv"
            struct Primitive primitive = *primitive_info;
            #line 708 "src/compiler/Generator.pv"
            struct str* inc = HashMap_str_str__find(&self->primitive_includes, &primitive.name);
            #line 709 "src/compiler/Generator.pv"
            if (inc != 0) {
                #line 709 "src/compiler/Generator.pv"
                HashSet_str__insert(out, *inc);
            }
        } break;
        #line 711 "src/compiler/Generator.pv"
        case TYPE__GLOBAL: {
            #line 711 "src/compiler/Generator.pv"
            struct Global* g = type->global_value;
            #line 711 "src/compiler/Generator.pv"
            Generator__collect_primitive_includes(self, &g->type, generics, out);
        } break;
        #line 712 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 716 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics) {
    #line 717 "src/compiler/Generator.pv"
    struct String trait_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 718 "src/compiler/Generator.pv"
    struct Token trait_token = *trait_info->name;

    #line 720 "src/compiler/Generator.pv"
    String__append(&trait_name, struct_name);
    #line 721 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 722 "src/compiler/Generator.pv"
    String__append(&trait_name, trait_token.value);

    #line 724 "src/compiler/Generator.pv"
    if (impl_trait_type != 0) {
        #line 725 "src/compiler/Generator.pv"
        struct Type impl_trait = *impl_trait_type;
        #line 726 "src/compiler/Generator.pv"
        switch (impl_trait.type) {
            #line 727 "src/compiler/Generator.pv"
            case TYPE__TRAIT: {
                #line 727 "src/compiler/Generator.pv"
                struct Trait* ti = impl_trait.trait_value._0;
                #line 727 "src/compiler/Generator.pv"
                struct GenericMap* tmap = impl_trait.trait_value._1;
                #line 728 "src/compiler/Generator.pv"
                if (tmap != 0) {
                    #line 729 "src/compiler/Generator.pv"
                    struct GenericMap trait_generics = *tmap;
                    #line 730 "src/compiler/Generator.pv"
                    struct Trait impl_trait_info = *ti;
                    #line 731 "src/compiler/Generator.pv"
                    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&impl_trait_info.generics.map);
                    #line 731 "src/compiler/Generator.pv"
                    while (HashMapIter_str_usize__next(&__iter)) {
                        #line 731 "src/compiler/Generator.pv"
                        struct str gname = HashMapIter_str_usize__value(&__iter)->_0;

                        #line 732 "src/compiler/Generator.pv"
                        if (HashMap_str_usize__find(&impl_trait_info.typedefs, &gname) == 0) {
                            #line 733 "src/compiler/Generator.pv"
                            struct Type* gtype = GenericMap__get(&trait_generics, gname);
                            #line 734 "src/compiler/Generator.pv"
                            if (gtype != 0) {
                                #line 735 "src/compiler/Generator.pv"
                                String__append(&trait_name, (struct str){ .ptr = "_", .length = strlen("_") });
                                #line 736 "src/compiler/Generator.pv"
                                struct String type_name = Naming__get_type_name(&self->naming_ident, gtype, generics->self_type, generics);
                                #line 737 "src/compiler/Generator.pv"
                                String__append_string(&trait_name, &type_name);
                            }
                        }
                    } }
                }
            } break;
            #line 743 "src/compiler/Generator.pv"
            default: {
            } break;
        }
    }

    #line 747 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 748 "src/compiler/Generator.pv"
    struct Token func_name = *func_info->name;
    #line 749 "src/compiler/Generator.pv"
    String__append(&trait_name, func_name.value);

    #line 751 "src/compiler/Generator.pv"
    return trait_name;
}

#line 754 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Array_str game_namespaces, bool test_mode, struct Root* root) {
    #line 755 "src/compiler/Generator.pv"
    bool result = true;

    #line 757 "src/compiler/Generator.pv"
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
        .scratch = 0,
        .game_namespaces = game_namespaces,
        .current_host = false,
        .host_files = Array_String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .game_files = Array_String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .type_impl_usages = 0,
        .type_impl_paths = HashSet_str__new(allocator),
        .test_mode = test_mode,
    };

    #line 781 "src/compiler/Generator.pv"
    self.naming_c99 = Naming__new_c99(allocator, &self.naming_ident);

    #line 783 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitives = &self.primitives;
    #line 784 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 785 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 786 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 787 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 788 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 789 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 790 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 791 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 792 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 793 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 794 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 795 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 796 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 797 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 798 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 800 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitive_includes = &self.primitive_includes;
    #line 801 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 802 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 803 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 804 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 805 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 806 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 807 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 808 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 809 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 810 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 811 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "stdbool", .length = strlen("stdbool") });
    #line 812 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "str", .length = strlen("str") }, (struct str){ .ptr = "string", .length = strlen("string") });

    #line 814 "src/compiler/Generator.pv"
    struct FileGenerator file_gen = (struct FileGenerator) { .generator = &self };

    #line 816 "src/compiler/Generator.pv"
    FileGenerator__create_directories(&file_gen, (struct str){ .ptr = path, .length = strlen(path) }, &root->children);

    #line 818 "src/compiler/Generator.pv"
    bool success = true;

    #line 820 "src/compiler/Generator.pv"
    struct Usages usages = Usages__new(&self);
    #line 821 "src/compiler/Generator.pv"
    self.type_impl_usages = &usages.type_impls;
    #line 822 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Primitive __iter = HashMap_usize_TypeUsage_Primitive__iter(&usages.primitives);
    #line 822 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Primitive__next(&__iter)) {
        #line 822 "src/compiler/Generator.pv"
        struct TypeUsage_Primitive* usage = &HashMapIter_usize_TypeUsage_Primitive__value(&__iter)->_1;

        #line 822 "src/compiler/Generator.pv"
        success = FileGenerator__generate_primitive_loop(&file_gen, usage) && success;
    } }
    #line 823 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Struct __iter = HashMap_usize_TypeUsage_Struct__iter(&usages.structs);
    #line 823 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Struct__next(&__iter)) {
        #line 823 "src/compiler/Generator.pv"
        struct TypeUsage_Struct* usage = &HashMapIter_usize_TypeUsage_Struct__value(&__iter)->_1;

        #line 823 "src/compiler/Generator.pv"
        success = FileGenerator__generate_struct_loop(&file_gen, usage) && success;
    } }
    #line 824 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Enum __iter = HashMap_usize_TypeUsage_Enum__iter(&usages.enums);
    #line 824 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Enum__next(&__iter)) {
        #line 824 "src/compiler/Generator.pv"
        struct TypeUsage_Enum* usage = &HashMapIter_usize_TypeUsage_Enum__value(&__iter)->_1;

        #line 824 "src/compiler/Generator.pv"
        success = FileGenerator__generate_enum_loop(&file_gen, usage) && success;
    } }
    #line 825 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Trait __iter = HashMap_usize_TypeUsage_Trait__iter(&usages.traits);
    #line 825 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Trait__next(&__iter)) {
        #line 825 "src/compiler/Generator.pv"
        struct TypeUsage_Trait* usage = &HashMapIter_usize_TypeUsage_Trait__value(&__iter)->_1;

        #line 825 "src/compiler/Generator.pv"
        success = FileGenerator__generate_trait_loop(&file_gen, usage) && success;
    } }
    #line 826 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeFunctionUsage __iter = HashMap_usize_TypeFunctionUsage__iter(&usages.functions);
    #line 826 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeFunctionUsage__next(&__iter)) {
        #line 826 "src/compiler/Generator.pv"
        struct TypeFunctionUsage* usage = &HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_1;

        #line 826 "src/compiler/Generator.pv"
        success = FileGenerator__generate_function_loop(&file_gen, usage) && success;
    } }
    #line 827 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Sequence __iter = HashMap_usize_TypeUsage_Sequence__iter(&usages.sequences);
    #line 827 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Sequence__next(&__iter)) {
        #line 827 "src/compiler/Generator.pv"
        struct TypeUsage_Sequence* usage = &HashMapIter_usize_TypeUsage_Sequence__value(&__iter)->_1;

        #line 827 "src/compiler/Generator.pv"
        success = FileGenerator__generate_sequence(&file_gen, usage) && success;
    } }
    #line 828 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Tuple __iter = HashMap_usize_TypeUsage_Tuple__iter(&usages.tuples);
    #line 828 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Tuple__next(&__iter)) {
        #line 828 "src/compiler/Generator.pv"
        struct TypeUsage_Tuple* usage = &HashMapIter_usize_TypeUsage_Tuple__value(&__iter)->_1;

        #line 828 "src/compiler/Generator.pv"
        success = FileGenerator__generate_tuple_loop(&file_gen, usage) && success;
    } }
    #line 829 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_TypeImpl __iter = HashMap_usize_TypeUsage_TypeImpl__iter(&usages.type_impls);
    #line 829 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_TypeImpl__next(&__iter)) {
        #line 829 "src/compiler/Generator.pv"
        struct TypeUsage_TypeImpl* usage = &HashMapIter_usize_TypeUsage_TypeImpl__value(&__iter)->_1;

        #line 829 "src/compiler/Generator.pv"
        success = FileGenerator__generate_type_impl_loop(&file_gen, usage) && success;
    } }
    #line 830 "src/compiler/Generator.pv"
    FileGenerator__generate_globals_namespace(&file_gen, &root->children);
    #line 831 "src/compiler/Generator.pv"
    if (test_mode) {
        #line 831 "src/compiler/Generator.pv"
        success = FileGenerator__generate_test_runner(&file_gen, &root->children) && success;
    }
    #line 832 "src/compiler/Generator.pv"
    if (mem_file_flush() != 0) {
        #line 832 "src/compiler/Generator.pv"
        success = false;
    }

    #line 834 "src/compiler/Generator.pv"
    if (!success) {
        #line 835 "src/compiler/Generator.pv"
        fprintf(stderr, "Generation failed\n");
        #line 836 "src/compiler/Generator.pv"
        return false;
    }

    #line 839 "src/compiler/Generator.pv"
    if (game_namespaces.length > 0) {
        #line 840 "src/compiler/Generator.pv"
        if (!Generator__write_file_list(&self, "pave_host_sources.txt", &self.host_files) || !Generator__write_file_list(&self, "pave_game_sources.txt", &self.game_files)) {
            #line 840 "src/compiler/Generator.pv"
            return false;
        }
    }

    #line 843 "src/compiler/Generator.pv"
    if (self.code_files.length > 0) {
        #line 844 "src/compiler/Generator.pv"
        struct String command = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

        #line 846 "src/compiler/Generator.pv"
        { struct Iter_ref_String __iter = Array_String__iter(&self.code_files);
        #line 846 "src/compiler/Generator.pv"
        while (Iter_ref_String__next(&__iter)) {
            #line 846 "src/compiler/Generator.pv"
            struct String* code_file = Iter_ref_String__value(&__iter);

            #line 847 "src/compiler/Generator.pv"
            if (command.array.length > 0) {
                #line 848 "src/compiler/Generator.pv"
                String__append(&command, (struct str){ .ptr = output_seperator, .length = strlen(output_seperator) });
            }

            #line 851 "src/compiler/Generator.pv"
            String__append(&command, String__as_str(code_file));
        } }

        #line 854 "src/compiler/Generator.pv"
        uint32_t length = command.array.length;
        #line 855 "src/compiler/Generator.pv"
        printf("%.*s\n", length, command.array.data);
    }

    #line 858 "src/compiler/Generator.pv"
    return result;
}
