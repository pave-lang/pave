#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdio.h>
#include <compiler/Generator.h>
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
#include <std/Hash.h>
#include <std/Fnv1a.h>
#include <std/Array_char.h>
#include <analyzer/Context.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <analyzer/c/Include.h>
#include <std/HashSet_str.h>
#include <analyzer/Module.h>
#include <std/HashSetIter_str.h>
#include <analyzer/types/Parameter.h>
#include <compiler/FunctionContext.h>
#include <analyzer/types/FunctionType.h>
#include <std/trait_Allocator.h>
#include <analyzer/Namespace.h>
#include <analyzer/types/Global.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/Generics.h>
#include <std/HashMapIter_str_usize.h>
#include <tuple_str_usize.h>
#include <analyzer/Root.h>
#include <analyzer/NamingType.h>
#include <compiler/FileGenerator.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <compiler/Usages.h>
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
#include <std/Iter_ref_String.h>
#include <compiler/Generator.h>

#include <compiler/Generator.h>

#line 29 "src/compiler/Generator.pv"
bool Generator__overwrite_if_different(struct Generator* self, char const* file_name, FILE* source) {
    #line 30 "src/compiler/Generator.pv"
    FILE* orig = fopen(file_name, "r");
    #line 31 "src/compiler/Generator.pv"
    bool different = true;

    #line 33 "src/compiler/Generator.pv"
    if (orig != 0) {
        #line 34 "src/compiler/Generator.pv"
        rewind(source);
        #line 35 "src/compiler/Generator.pv"
        int32_t c1 = 0;
        #line 36 "src/compiler/Generator.pv"
        int32_t c2 = 0;
        #line 37 "src/compiler/Generator.pv"
        different = false;
        #line 38 "src/compiler/Generator.pv"
        while (!different && (c1 != (int32_t)(EOF)) && (c2 != (int32_t)(EOF))) {
            #line 39 "src/compiler/Generator.pv"
            c1 = fgetc(source);
            #line 40 "src/compiler/Generator.pv"
            c2 = fgetc(orig);
            #line 41 "src/compiler/Generator.pv"
            different = c1 != c2;
        }

        #line 44 "src/compiler/Generator.pv"
        fclose(orig);
    }

    #line 47 "src/compiler/Generator.pv"
    if (!different) {
        #line 47 "src/compiler/Generator.pv"
        return false;
    }

    #line 49 "src/compiler/Generator.pv"
    rewind(source);

    #line 51 "src/compiler/Generator.pv"
    FILE* out = fopen(file_name, "w");
    #line 52 "src/compiler/Generator.pv"
    if (out == 0) {
        #line 52 "src/compiler/Generator.pv"
        perror("fopen");
        #line 52 "src/compiler/Generator.pv"
        return false;
    }

    #line 54 "src/compiler/Generator.pv"
    int32_t c = fgetc(source);
    #line 55 "src/compiler/Generator.pv"
    while (c != (int32_t)(EOF)) {
        #line 56 "src/compiler/Generator.pv"
        fputc(c, out);
        #line 57 "src/compiler/Generator.pv"
        c = fgetc(source);
    }

    #line 60 "src/compiler/Generator.pv"
    fclose(out);
    #line 61 "src/compiler/Generator.pv"
    return true;
}

#line 64 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file) {
    #line 65 "src/compiler/Generator.pv"
    int16_t i = 0;
    #line 66 "src/compiler/Generator.pv"
    while (i < self->indent) {
        #line 67 "src/compiler/Generator.pv"
        fprintf(file, "    ");
        #line 68 "src/compiler/Generator.pv"
        i += 1;
    }
}

#line 72 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s) {
    #line 73 "src/compiler/Generator.pv"
    int32_t length = s.length;
    #line 74 "src/compiler/Generator.pv"
    fprintf(file, "%.*s", length, s.ptr);
    #line 75 "src/compiler/Generator.pv"
    return true;
}

#line 78 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s) {
    #line 79 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, String__as_str(s));
}

#line 82 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s) {
    #line 83 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 84 "src/compiler/Generator.pv"
    uintptr_t length = s.length;
    #line 85 "src/compiler/Generator.pv"
    bool was_lowercase = false;

    #line 87 "src/compiler/Generator.pv"
    while (i < length) {
        #line 88 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 90 "src/compiler/Generator.pv"
        if (c >= 'a' && c <= 'z') {
            #line 91 "src/compiler/Generator.pv"
            fprintf(file, "%c", c - 32);
            #line 92 "src/compiler/Generator.pv"
            was_lowercase = true;
        } else {
            #line 94 "src/compiler/Generator.pv"
            if (was_lowercase && (c >= 'A') && (c <= 'Z')) {
                #line 95 "src/compiler/Generator.pv"
                fprintf(file, "_");
            }

            #line 98 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
            #line 99 "src/compiler/Generator.pv"
            was_lowercase = false;
        }

        #line 102 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 105 "src/compiler/Generator.pv"
    return true;
}

#line 108 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s) {
    #line 109 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 110 "src/compiler/Generator.pv"
    uintptr_t length = s.length;

    #line 112 "src/compiler/Generator.pv"
    while (i < length) {
        #line 113 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 115 "src/compiler/Generator.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 116 "src/compiler/Generator.pv"
            fprintf(file, "%c", c + 32);
        } else {
            #line 118 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
        }

        #line 121 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 124 "src/compiler/Generator.pv"
    return true;
}

#line 127 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token) {
    #line 128 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, token->value);
}

#line 131 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 132 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 133 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 133 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 133 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, &indirect->to, generics);
        } break;
        #line 134 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 134 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 134 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 135 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 135 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 136 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 139 "src/compiler/Generator.pv"
    return false;
}

#line 142 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union_no_indirect(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 143 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 144 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 144 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 144 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 145 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 145 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 146 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 149 "src/compiler/Generator.pv"
    return false;
}

#line 152 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 153 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_c99, type, generics->self_type, generics);
    #line 154 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 155 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 156 "src/compiler/Generator.pv"
    return true;
}

#line 159 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 160 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_ident, type, generics->self_type, generics);
    #line 161 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 162 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 163 "src/compiler/Generator.pv"
    return true;
}

#line 166 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics) {
    #line 167 "src/compiler/Generator.pv"
    struct Type* self_type = type;
    #line 168 "src/compiler/Generator.pv"
    if (generics != 0) {
        #line 168 "src/compiler/Generator.pv"
        self_type = (*generics).self_type;
    }

    #line 170 "src/compiler/Generator.pv"
    struct String variable_decl = Naming__get_variable_decl(&self->naming_c99, name, type, self_type, generics);
    #line 171 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&variable_decl));
    #line 172 "src/compiler/Generator.pv"
    String__release(&variable_decl);

    #line 174 "src/compiler/Generator.pv"
    Generator__write_array_decl_suffix(self, file, type, generics);

    #line 176 "src/compiler/Generator.pv"
    return true;
}

#line 179 "src/compiler/Generator.pv"
void Generator__write_array_decl_suffix(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 180 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 181 "src/compiler/Generator.pv"
        case TYPE__SEQUENCE: {
            #line 181 "src/compiler/Generator.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 182 "src/compiler/Generator.pv"
            switch (sequence->type.type) {
                #line 183 "src/compiler/Generator.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 183 "src/compiler/Generator.pv"
                    struct Expression* length = sequence->type.fixedarray_value;
                    #line 184 "src/compiler/Generator.pv"
                    fprintf(file, "[");
                    #line 185 "src/compiler/Generator.pv"
                    ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = self }}, file, length, generics);
                    #line 186 "src/compiler/Generator.pv"
                    fprintf(file, "]");
                    #line 187 "src/compiler/Generator.pv"
                    Generator__write_array_decl_suffix(self, file, &sequence->element, generics);
                } break;
                #line 189 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 192 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 196 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 197 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);

    #line 200 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&name));

    #line 202 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 205 "src/compiler/Generator.pv"
bool Generator__write_dynamic_vtable_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 206 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);

    #line 209 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, String__as_str(&name));

    #line 211 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 214 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type) {
    #line 215 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 216 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 216 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 217 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 217 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 217 "src/compiler/Generator.pv"
            return Generator__is_reference(info->type);
        } break;
        #line 218 "src/compiler/Generator.pv"
        default: {
            #line 218 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 222 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 223 "src/compiler/Generator.pv"
    switch (Type__deref(type)->type) {
        #line 224 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 224 "src/compiler/Generator.pv"
            struct Struct* struct_info = Type__deref(type)->struct_value._0;
            #line 224 "src/compiler/Generator.pv"
            return Struct__is_newtype(struct_info);
        } break;
        #line 225 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 225 "src/compiler/Generator.pv"
            return Generator__is_type_single_value_struct(self, generics->self_type, generics);
        } break;
        #line 226 "src/compiler/Generator.pv"
        default: {
            #line 226 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 230 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map) {
    #line 231 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 232 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 233 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 234 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting Self for function, but no generic map input\n");
                #line 235 "src/compiler/Generator.pv"
                return 0;
            }

            #line 238 "src/compiler/Generator.pv"
            return Generator__get_function(self, (*generic_map).self_type, func_name, generic_map);
        } break;
        #line 240 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 240 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 240 "src/compiler/Generator.pv"
            return Generator__get_function(self, &indirect->to, func_name, generic_map);
        } break;
        #line 241 "src/compiler/Generator.pv"
        case TYPE__GENERIC: {
            #line 241 "src/compiler/Generator.pv"
            struct Generic* generic = type->generic_value;
            #line 242 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 243 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, but no generic map input\n");
                #line 244 "src/compiler/Generator.pv"
                return 0;
            }

            #line 247 "src/compiler/Generator.pv"
            struct Token generic_name = *generic->name;
            #line 248 "src/compiler/Generator.pv"
            struct Type* generic_type = GenericMap__get(&(*generic_map), generic_name.value);
            #line 249 "src/compiler/Generator.pv"
            if (generic_type == 0) {
                #line 250 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, no item in generic map found\n");
                #line 251 "src/compiler/Generator.pv"
                return 0;
            }

            #line 254 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_type, func_name, generic_map);
        } break;
        #line 256 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 256 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 257 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 258 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting primitive for function, but no primitive info found\n");
                #line 259 "src/compiler/Generator.pv"
                return 0;
            }

            #line 262 "src/compiler/Generator.pv"
            struct Primitive primitive = *primitive_info;
            #line 263 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 265 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&primitive.impls);
            #line 266 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 267 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 268 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 271 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 272 "src/compiler/Generator.pv"
                int32_t name_length = primitive.name.length;
                #line 273 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 274 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitives %.*s function %.*s for get_function\n", name_length, primitive.name.ptr, func_name_length, func_name.ptr);
            }

            #line 277 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 279 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 279 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 280 "src/compiler/Generator.pv"
            struct Function* func_info = 0;
            #line 281 "src/compiler/Generator.pv"
            struct Token enum_name = *enum_info->name;

            #line 283 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 284 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 285 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 286 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 289 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 290 "src/compiler/Generator.pv"
                int32_t name_length = enum_name.value.length;
                #line 291 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 292 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enums %.*s function %.*s for get_function\n", name_length, enum_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 295 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 297 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 297 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 298 "src/compiler/Generator.pv"
            struct Function* func_info = 0;
            #line 299 "src/compiler/Generator.pv"
            struct Token struct_name = *struct_info->name;

            #line 301 "src/compiler/Generator.pv"
            { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
            #line 301 "src/compiler/Generator.pv"
            while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
                #line 301 "src/compiler/Generator.pv"
                uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
                #line 301 "src/compiler/Generator.pv"
                struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

                #line 302 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);

                #line 304 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 304 "src/compiler/Generator.pv"
                    break;
                }

                #line 306 "src/compiler/Generator.pv"
                if (impl_info->trait_ != 0) {
                    #line 307 "src/compiler/Generator.pv"
                    struct Trait trait_info = *impl_info->trait_;
                    #line 308 "src/compiler/Generator.pv"
                    func_info = HashMap_str_Function__find(&trait_info.functions, &func_name);
                }

                #line 311 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 312 "src/compiler/Generator.pv"
                    func_info = ArenaAllocator__store_Function(self->allocator, func_info);
                    #line 313 "src/compiler/Generator.pv"
                    func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                    #line 314 "src/compiler/Generator.pv"
                    break;
                }
            } }

            #line 318 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 319 "src/compiler/Generator.pv"
                int32_t name_length = struct_name.value.length;
                #line 320 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 321 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find structs %.*s function %.*s for get_function\n", name_length, struct_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 324 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 326 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 326 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 327 "src/compiler/Generator.pv"
            struct Token trait_name = *trait_info->name;
            #line 328 "src/compiler/Generator.pv"
            struct Function* func_info = HashMap_str_Function__find(&trait_info->functions, &func_name);

            #line 330 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 331 "src/compiler/Generator.pv"
                int32_t name_length = trait_name.value.length;
                #line 332 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 333 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find traits %.*s function %.*s for get_function\n", name_length, trait_name.value.ptr, func_name_length, func_name.ptr);
            }

            #line 336 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 338 "src/compiler/Generator.pv"
        default: {
            #line 339 "src/compiler/Generator.pv"
            fprintf(stderr, "Unhandled type for getting function %s\n", Type__name(type));
        } break;
    }

    #line 343 "src/compiler/Generator.pv"
    return 0;
}

#line 346 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant) {
    #line 347 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;
    #line 348 "src/compiler/Generator.pv"
    struct Token name = *parent->name;
    #line 349 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, name.value);
    #line 350 "src/compiler/Generator.pv"
    fprintf(file, "__");
    #line 351 "src/compiler/Generator.pv"
    struct Token* variant_name = variant->name;
    #line 352 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, variant_name->value);

    #line 354 "src/compiler/Generator.pv"
    return true;
}

#line 357 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 358 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 359 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 359 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 360 "src/compiler/Generator.pv"
            fprintf(file, "*");
            #line 361 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, &indirect->to, generics);
        } break;
        #line 363 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 363 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 364 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, info->type, generics);
        } break;
        #line 366 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 369 "src/compiler/Generator.pv"
    return true;
}

#line 372 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics) {
    #line 373 "src/compiler/Generator.pv"
    fprintf(file, "::");
    #line 374 "src/compiler/Generator.pv"
    return true;
}

#line 377 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 378 "src/compiler/Generator.pv"
    if (Type__is_fat_pointer(type)) {
        #line 379 "src/compiler/Generator.pv"
        fprintf(file, ".");
        #line 380 "src/compiler/Generator.pv"
        return true;
    }

    #line 383 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 384 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 385 "src/compiler/Generator.pv"
            fprintf(file, "->");
        } break;
        #line 387 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 388 "src/compiler/Generator.pv"
            return Generator__write_instance_member_accessor(self, file, generics->self_type, generics);
        } break;
        #line 390 "src/compiler/Generator.pv"
        default: {
            #line 391 "src/compiler/Generator.pv"
            fprintf(file, ".");
        } break;
    }

    #line 395 "src/compiler/Generator.pv"
    return true;
}

#line 398 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value) {
    #line 399 "src/compiler/Generator.pv"
    if (value.length > 2 && value.ptr[0] == '0' && (value.ptr[1] == 'b' || value.ptr[1] == 'B')) {
        #line 400 "src/compiler/Generator.pv"
        uint64_t acc = 0;
        #line 401 "src/compiler/Generator.pv"
        uintptr_t i = 2;
        #line 402 "src/compiler/Generator.pv"
        while (i < value.length) {
            #line 403 "src/compiler/Generator.pv"
            if (value.ptr[i] != '_') {
                #line 404 "src/compiler/Generator.pv"
                acc = (acc << 1) | (uint64_t)(value.ptr[i] - '0');
            }
            #line 406 "src/compiler/Generator.pv"
            i += 1;
        }
        #line 408 "src/compiler/Generator.pv"
        fprintf(file, "0x%llx", acc);
    } else if (value.length > 0 && value.ptr[0] >= '0' && value.ptr[0] <= '9') {
        #line 410 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 411 "src/compiler/Generator.pv"
        while (i < value.length) {
            #line 412 "src/compiler/Generator.pv"
            if (value.ptr[i] != '_') {
                #line 413 "src/compiler/Generator.pv"
                fprintf(file, "%c", (int32_t)(value.ptr[i]));
            }
            #line 415 "src/compiler/Generator.pv"
            i += 1;
        }
    } else {
        #line 418 "src/compiler/Generator.pv"
        Generator__write_str(self, file, value);
    }

    #line 421 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 422 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 422 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 423 "src/compiler/Generator.pv"
            if (primitive_info != 0 && str__Eq_str__eq(&(*primitive_info).name, (struct str){ .ptr = "u64", .length = strlen("u64") })) {
                #line 424 "src/compiler/Generator.pv"
                fprintf(file, "ULL");
            }
        } break;
        #line 427 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 430 "src/compiler/Generator.pv"
    return true;
}

#line 433 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 434 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);

    #line 437 "src/compiler/Generator.pv"
    Hash type_id = Fnv1a__hash(type_name.array.data, String__length(&type_name));

    #line 439 "src/compiler/Generator.pv"
    fprintf(file, "%zuULL", type_id);

    #line 441 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 444 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token) {
    #line 445 "src/compiler/Generator.pv"
    if (self->output_line_directives) {
        #line 446 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 447 "src/compiler/Generator.pv"
        fprintf(file, "#line %zu \"", token->start_line + 1);
        #line 448 "src/compiler/Generator.pv"
        Generator__write_str(self, file, context->path);
        #line 449 "src/compiler/Generator.pv"
        fprintf(file, "\"\n");
    }
}

#line 453 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes) {
    #line 454 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(includes);
    #line 454 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 454 "src/compiler/Generator.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 455 "src/compiler/Generator.pv"
        struct str path = include->path;
        #line 456 "src/compiler/Generator.pv"
        if (path.length > 0) {
            #line 457 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s>\n", (int32_t)(path.length - 2), path.ptr + 1);
        }
    } }

    #line 461 "src/compiler/Generator.pv"
    if (includes->length > 0) {
        #line 462 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 466 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls) {
    #line 467 "src/compiler/Generator.pv"
    struct HashSet_str written = HashSet_str__new(self->allocator);

    #line 470 "src/compiler/Generator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 470 "src/compiler/Generator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 470 "src/compiler/Generator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 471 "src/compiler/Generator.pv"
        struct Module* module = impl_info->context->module;
        #line 472 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&module->includes);
        #line 472 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Include__next(&__iter)) {
            #line 472 "src/compiler/Generator.pv"
            struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

            #line 473 "src/compiler/Generator.pv"
            if (!HashSet_str__insert(&written, include->path)) {
                #line 473 "src/compiler/Generator.pv"
                continue;
            }
            #line 474 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 475 "src/compiler/Generator.pv"
            Generator__write_str(self, file, include->path);
            #line 476 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } }
    } }
    HashSet_str__release(&written);
}

#line 481 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives) {
    #line 482 "src/compiler/Generator.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);

    #line 484 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(primitives);
    #line 484 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 484 "src/compiler/Generator.pv"
        struct str* primitive = HashSetIter_str__value(&__iter);

        #line 485 "src/compiler/Generator.pv"
        if (exclude_primitives && HashSet_str__has(&(*exclude_primitives), primitive)) {
            #line 485 "src/compiler/Generator.pv"
            continue;
        }
        #line 486 "src/compiler/Generator.pv"
        struct str* include = HashMap_str_str__find(&self->primitive_includes, primitive);
        #line 487 "src/compiler/Generator.pv"
        if (include == 0) {
            #line 487 "src/compiler/Generator.pv"
            continue;
        }
        #line 488 "src/compiler/Generator.pv"
        HashSet_str__insert(&includes, *include);
    } }

    #line 491 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 491 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 491 "src/compiler/Generator.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 492 "src/compiler/Generator.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 495 "src/compiler/Generator.pv"
    if (includes.length > 0) {
        #line 496 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 500 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics) {
    #line 501 "src/compiler/Generator.pv"
    if (generics == 0 || (*generics).self_type == 0) {
        #line 501 "src/compiler/Generator.pv"
        return false;
    }

    #line 503 "src/compiler/Generator.pv"
    switch ((*generics).self_type->type) {
        #line 504 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 504 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = (*generics).self_type->primitive_value;
            #line 505 "src/compiler/Generator.pv"
            if (primitive_info == 0 || !str__Eq_str__eq(&(*primitive_info).name, (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 506 "src/compiler/Generator.pv"
                return false;
            }
        } break;
        #line 509 "src/compiler/Generator.pv"
        default: {
            #line 509 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 512 "src/compiler/Generator.pv"
    struct Type* ref = 0;

    #line 514 "src/compiler/Generator.pv"
    switch (parameter->type.type) {
        #line 515 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 515 "src/compiler/Generator.pv"
            struct Indirect* indirect = parameter->type.indirect_value;
            #line 516 "src/compiler/Generator.pv"
            ref = &indirect->to;
        } break;
        #line 518 "src/compiler/Generator.pv"
        default: {
            #line 518 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 521 "src/compiler/Generator.pv"
    if (ref == 0) {
        #line 521 "src/compiler/Generator.pv"
        return false;
    }

    #line 523 "src/compiler/Generator.pv"
    struct Type ref_type = *ref;
    #line 524 "src/compiler/Generator.pv"
    switch (ref_type.type) {
        #line 525 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 525 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 526 "src/compiler/Generator.pv"
        default: {
            #line 526 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 530 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self) {
    #line 531 "src/compiler/Generator.pv"
    struct FunctionContext function_context = *self->function_context;
    #line 532 "src/compiler/Generator.pv"
    return (*function_context.func_info).type == FUNCTION_TYPE__COROUTINE;
}

#line 535 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name) {
    #line 536 "src/compiler/Generator.pv"
    if (self->function_context != 0) {
        #line 537 "src/compiler/Generator.pv"
        name = FunctionContext__get_variable_replacement(&(*self->function_context), name);
    }
    #line 539 "src/compiler/Generator.pv"
    Generator__write_str(self, file, name);
}

#line 542 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 543 "src/compiler/Generator.pv"
    struct String result = Generator__make_rel_path(self, module, name, ext);
    #line 544 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 545 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = self->path, .length = strlen(self->path) });
    #line 546 "src/compiler/Generator.pv"
    return result;
}

#line 549 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 550 "src/compiler/Generator.pv"
    struct String result = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 551 "src/compiler/Generator.pv"
    struct Namespace* namespace = 0;
    #line 552 "src/compiler/Generator.pv"
    if (module != 0) {
        #line 552 "src/compiler/Generator.pv"
        namespace = (*module).namespace;
    }

    #line 554 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 555 "src/compiler/Generator.pv"
        struct Namespace namespace_info = *namespace;
        #line 556 "src/compiler/Generator.pv"
        String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 557 "src/compiler/Generator.pv"
        String__prepend(&result, namespace_info.name);
        #line 558 "src/compiler/Generator.pv"
        namespace = namespace_info.parent;
    }

    #line 561 "src/compiler/Generator.pv"
    String__append(&result, name);
    #line 562 "src/compiler/Generator.pv"
    String__append(&result, ext);

    #line 564 "src/compiler/Generator.pv"
    return result;
}

#line 567 "src/compiler/Generator.pv"
void Generator__collect_primitive_includes(struct Generator* self, struct Type* type, struct GenericMap* generics, struct HashSet_str* out) {
    #line 568 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 569 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 569 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 570 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 570 "src/compiler/Generator.pv"
                return;
            }
            #line 571 "src/compiler/Generator.pv"
            struct Primitive primitive = *primitive_info;
            #line 572 "src/compiler/Generator.pv"
            struct str* inc = HashMap_str_str__find(&self->primitive_includes, &primitive.name);
            #line 573 "src/compiler/Generator.pv"
            if (inc != 0) {
                #line 573 "src/compiler/Generator.pv"
                HashSet_str__insert(out, *inc);
            }
        } break;
        #line 575 "src/compiler/Generator.pv"
        case TYPE__GLOBAL: {
            #line 575 "src/compiler/Generator.pv"
            struct Global* g = type->global_value;
            #line 575 "src/compiler/Generator.pv"
            Generator__collect_primitive_includes(self, &g->type, generics, out);
        } break;
        #line 576 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 580 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics) {
    #line 581 "src/compiler/Generator.pv"
    struct String trait_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 582 "src/compiler/Generator.pv"
    struct Token trait_token = *trait_info->name;

    #line 584 "src/compiler/Generator.pv"
    String__append(&trait_name, struct_name);
    #line 585 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 586 "src/compiler/Generator.pv"
    String__append(&trait_name, trait_token.value);

    #line 588 "src/compiler/Generator.pv"
    if (impl_trait_type != 0) {
        #line 589 "src/compiler/Generator.pv"
        struct Type impl_trait = *impl_trait_type;
        #line 590 "src/compiler/Generator.pv"
        switch (impl_trait.type) {
            #line 591 "src/compiler/Generator.pv"
            case TYPE__TRAIT: {
                #line 591 "src/compiler/Generator.pv"
                struct Trait* ti = impl_trait.trait_value._0;
                #line 591 "src/compiler/Generator.pv"
                struct GenericMap* tmap = impl_trait.trait_value._1;
                #line 592 "src/compiler/Generator.pv"
                if (tmap != 0) {
                    #line 593 "src/compiler/Generator.pv"
                    struct GenericMap trait_generics = *tmap;
                    #line 594 "src/compiler/Generator.pv"
                    struct Trait impl_trait_info = *ti;
                    #line 595 "src/compiler/Generator.pv"
                    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&impl_trait_info.generics.map);
                    #line 595 "src/compiler/Generator.pv"
                    while (HashMapIter_str_usize__next(&__iter)) {
                        #line 595 "src/compiler/Generator.pv"
                        struct str gname = HashMapIter_str_usize__value(&__iter)->_0;

                        #line 596 "src/compiler/Generator.pv"
                        if (HashMap_str_usize__find(&impl_trait_info.typedefs, &gname) == 0) {
                            #line 597 "src/compiler/Generator.pv"
                            struct Type* gtype = GenericMap__get(&trait_generics, gname);
                            #line 598 "src/compiler/Generator.pv"
                            if (gtype != 0) {
                                #line 599 "src/compiler/Generator.pv"
                                String__append(&trait_name, (struct str){ .ptr = "_", .length = strlen("_") });
                                #line 600 "src/compiler/Generator.pv"
                                struct String type_name = Naming__get_type_name(&self->naming_ident, gtype, generics->self_type, generics);
                                #line 601 "src/compiler/Generator.pv"
                                String__append_string(&trait_name, &type_name);
                            }
                        }
                    } }
                }
            } break;
            #line 607 "src/compiler/Generator.pv"
            default: {
            } break;
        }
    }

    #line 611 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 612 "src/compiler/Generator.pv"
    struct Token func_name = *func_info->name;
    #line 613 "src/compiler/Generator.pv"
    String__append(&trait_name, func_name.value);

    #line 615 "src/compiler/Generator.pv"
    return trait_name;
}

#line 618 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Root* root) {
    #line 619 "src/compiler/Generator.pv"
    bool result = true;

    #line 621 "src/compiler/Generator.pv"
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
    };

    #line 637 "src/compiler/Generator.pv"
    self.naming_c99 = Naming__new_c99(allocator, &self.naming_ident);

    #line 639 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitives = &self.primitives;
    #line 640 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 641 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 642 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 643 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 644 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 645 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 646 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 647 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 648 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 649 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 650 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 651 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 652 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 653 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 654 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 656 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitive_includes = &self.primitive_includes;
    #line 657 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 658 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 659 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 660 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 661 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 662 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 663 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 664 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 665 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 666 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 667 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "stdbool", .length = strlen("stdbool") });
    #line 668 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "str", .length = strlen("str") }, (struct str){ .ptr = "string", .length = strlen("string") });

    #line 670 "src/compiler/Generator.pv"
    struct FileGenerator file_gen = (struct FileGenerator) { .generator = &self };

    #line 672 "src/compiler/Generator.pv"
    FileGenerator__create_directories(&file_gen, (struct str){ .ptr = path, .length = strlen(path) }, &root->children);

    #line 674 "src/compiler/Generator.pv"
    struct Usages usages = Usages__new(&self);
    #line 675 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Primitive __iter = HashMap_usize_TypeUsage_Primitive__iter(&usages.primitives);
    #line 675 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Primitive__next(&__iter)) {
        #line 675 "src/compiler/Generator.pv"
        struct TypeUsage_Primitive* usage = &HashMapIter_usize_TypeUsage_Primitive__value(&__iter)->_1;

        #line 675 "src/compiler/Generator.pv"
        FileGenerator__generate_primitive_loop(&file_gen, usage);
    } }
    #line 676 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Struct __iter = HashMap_usize_TypeUsage_Struct__iter(&usages.structs);
    #line 676 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Struct__next(&__iter)) {
        #line 676 "src/compiler/Generator.pv"
        struct TypeUsage_Struct* usage = &HashMapIter_usize_TypeUsage_Struct__value(&__iter)->_1;

        #line 676 "src/compiler/Generator.pv"
        FileGenerator__generate_struct_loop(&file_gen, usage);
    } }
    #line 677 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Enum __iter = HashMap_usize_TypeUsage_Enum__iter(&usages.enums);
    #line 677 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Enum__next(&__iter)) {
        #line 677 "src/compiler/Generator.pv"
        struct TypeUsage_Enum* usage = &HashMapIter_usize_TypeUsage_Enum__value(&__iter)->_1;

        #line 677 "src/compiler/Generator.pv"
        FileGenerator__generate_enum_loop(&file_gen, usage);
    } }
    #line 678 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Trait __iter = HashMap_usize_TypeUsage_Trait__iter(&usages.traits);
    #line 678 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Trait__next(&__iter)) {
        #line 678 "src/compiler/Generator.pv"
        struct TypeUsage_Trait* usage = &HashMapIter_usize_TypeUsage_Trait__value(&__iter)->_1;

        #line 678 "src/compiler/Generator.pv"
        FileGenerator__generate_trait_loop(&file_gen, usage);
    } }
    #line 679 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeFunctionUsage __iter = HashMap_usize_TypeFunctionUsage__iter(&usages.functions);
    #line 679 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeFunctionUsage__next(&__iter)) {
        #line 679 "src/compiler/Generator.pv"
        struct TypeFunctionUsage* usage = &HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_1;

        #line 679 "src/compiler/Generator.pv"
        FileGenerator__generate_function_loop(&file_gen, usage);
    } }
    #line 680 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Sequence __iter = HashMap_usize_TypeUsage_Sequence__iter(&usages.sequences);
    #line 680 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Sequence__next(&__iter)) {
        #line 680 "src/compiler/Generator.pv"
        struct TypeUsage_Sequence* usage = &HashMapIter_usize_TypeUsage_Sequence__value(&__iter)->_1;

        #line 680 "src/compiler/Generator.pv"
        FileGenerator__generate_sequence(&file_gen, usage);
    } }
    #line 681 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Tuple __iter = HashMap_usize_TypeUsage_Tuple__iter(&usages.tuples);
    #line 681 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Tuple__next(&__iter)) {
        #line 681 "src/compiler/Generator.pv"
        struct TypeUsage_Tuple* usage = &HashMapIter_usize_TypeUsage_Tuple__value(&__iter)->_1;

        #line 681 "src/compiler/Generator.pv"
        FileGenerator__generate_tuple_loop(&file_gen, usage);
    } }
    #line 682 "src/compiler/Generator.pv"
    FileGenerator__generate_globals_namespace(&file_gen, &root->children);
    #line 683 "src/compiler/Generator.pv"
    FileGenerator__generate_test_runner(&file_gen, &root->children);

    #line 685 "src/compiler/Generator.pv"
    if (self.code_files.length > 0) {
        #line 686 "src/compiler/Generator.pv"
        struct String command = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

        #line 688 "src/compiler/Generator.pv"
        { struct Iter_ref_String __iter = Array_String__iter(&self.code_files);
        #line 688 "src/compiler/Generator.pv"
        while (Iter_ref_String__next(&__iter)) {
            #line 688 "src/compiler/Generator.pv"
            struct String* code_file = Iter_ref_String__value(&__iter);

            #line 689 "src/compiler/Generator.pv"
            if (command.array.length > 0) {
                #line 690 "src/compiler/Generator.pv"
                String__append(&command, (struct str){ .ptr = output_seperator, .length = strlen(output_seperator) });
            }

            #line 693 "src/compiler/Generator.pv"
            String__append(&command, String__as_str(code_file));
        } }

        #line 696 "src/compiler/Generator.pv"
        uint32_t length = command.array.length;
        #line 697 "src/compiler/Generator.pv"
        printf("%.*s\n", length, command.array.data);
    }

    #line 700 "src/compiler/Generator.pv"
    return result;
}
