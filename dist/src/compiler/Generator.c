#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdbool.h>
#include <stdint.h>
#include <std/str.h>
#include <std/String.h>
#include <std/ArrayIter_ref_String.h>
#include <analyzer/Token.h>
#include <analyzer/Enum.h>
#include <analyzer/EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/Array_Type.h>
#include <analyzer/Type.h>
#include <analyzer/GenericMap.h>
#include <analyzer/Indirect.h>
#include <analyzer/Naming.h>
#include <analyzer/Function.h>
#include <analyzer/TypedefC.h>
#include <analyzer/Struct.h>
#include <analyzer/Generic.h>
#include <analyzer/Primitive.h>
#include <std/ArrayIter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/Array_ref_Impl.h>
#include <std/HashMap_str_Function.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <analyzer/Trait.h>
#include <std/ArenaAllocator.h>
#include <analyzer/FunctionParent.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>
#include <std/Array_char.h>
#include <analyzer/Context.h>
#include <analyzer/Expression.h>
#include <analyzer/FunctionType.h>
#include <analyzer/Sequence.h>
#include <analyzer/SequenceType.h>
#include <analyzer/ExpressionData.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <std/ArrayIter_ref_InvokeArgument.h>
#include <analyzer/Parameter.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <analyzer/FunctionC.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/CppExpression.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/DeferStatement.h>
#include <std/ArrayIter_ref_DeferStatement.h>
#include <compiler/FunctionContext.h>
#include <analyzer/Block.h>
#include <analyzer/Statement.h>
#include <std/ArrayIter_ref_Statement.h>
#include <std/Array_Statement.h>
#include <analyzer/StatementData.h>
#include <analyzer/LetStatement.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/ElseStatement.h>
#include <std/ArrayIter_ref_ElseStatement.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/MatchCase.h>
#include <std/ArrayIter_ref_MatchCase.h>
#include <std/Array_MatchCase.h>
#include <analyzer/MatchPattern.h>
#include <analyzer/EnumVariantParameter.h>
#include <std/ArrayIter_ref_EnumVariantParameter.h>
#include <std/Array_EnumVariantParameter.h>
#include <analyzer/TokenType.h>
#include <std/Allocator.h>
#include <analyzer/ForStatementType.h>
#include <analyzer/ForStatement.h>
#include <analyzer/ForVariable.h>
#include <std/Array_ForVariable.h>
#include <std/ArrayIter_ref_ForVariable.h>
#include <std/HashMap_str_GeneratorInclude.h>
#include <compiler/GeneratorInclude.h>
#include <std/HashMap_str_str.h>
#include <std/ArrayIter_ref_Type.h>
#include <analyzer/Tuple.h>
#include <analyzer/StructField.h>
#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/Include.h>
#include <analyzer/EnumC.h>
#include <analyzer/StructC.h>
#include <std/HashMap_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <std/HashSet_str.h>
#include <analyzer/Module.h>
#include <tuple_str_GeneratorInclude.h>
#include <std/HashMapIter_str_GeneratorInclude.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/Generics.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/ArrayIter_ref_ref_GenericMap.h>
#include <std/Array_ref_GenericMap.h>
#include <tuple_str_ref_Type.h>
#include <std/HashMapIter_str_ref_Type.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/Array_String.h>
#include <std/Array_Generic.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <tuple_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Trait.h>
#include <std/HashMap_str_ref_Trait.h>
#include <compiler/TypeUsage_Struct.h>
#include <analyzer/StructType.h>
#include <analyzer/Root.h>
#include <analyzer/Namespace.h>
#include <compiler/UsageContext.h>
#include <compiler/TypeUsage_Primitive.h>
#include <analyzer/IndirectType.h>
#include <analyzer/TypeImpl.h>
#include <tuple_usize_ref_Type.h>
#include <std/IterEnumerate_ref_Type.h>
#include <compiler/TypeUsage_Trait.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <compiler/FileWriter.h>
#include <compiler/Usages.h>
#include <tuple_usize_TypeUsage_Primitive.h>
#include <std/HashMapIter_usize_TypeUsage_Primitive.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <tuple_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <tuple_usize_TypeUsage_Enum.h>
#include <std/HashMapIter_usize_TypeUsage_Enum.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <tuple_usize_TypeUsage_Trait.h>
#include <std/HashMapIter_usize_TypeUsage_Trait.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <tuple_usize_TypeFunctionUsage.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>
#include <std/ArrayIter_ref_ref_Tuple.h>
#include <std/Array_ref_Tuple.h>

#include <compiler/Generator.h>

#line 160 "src/compiler/Generator.pv"
bool Generator__overwrite_if_different(struct Generator* self, char const* file_name, FILE* source) {
    #line 161 "src/compiler/Generator.pv"
    FILE* orig = fopen(file_name, "r");
    #line 162 "src/compiler/Generator.pv"
    bool different = true;

    #line 164 "src/compiler/Generator.pv"
    if (orig != 0) {
        #line 165 "src/compiler/Generator.pv"
        rewind(source);
        #line 166 "src/compiler/Generator.pv"
        int32_t c1 = 0;
        #line 167 "src/compiler/Generator.pv"
        int32_t c2 = 0;
        #line 168 "src/compiler/Generator.pv"
        different = false;
        #line 169 "src/compiler/Generator.pv"
        while (!different && c1 != EOF && c2 != EOF) {
            #line 170 "src/compiler/Generator.pv"
            c1 = fgetc(source);
            #line 171 "src/compiler/Generator.pv"
            c2 = fgetc(orig);
            #line 172 "src/compiler/Generator.pv"
            different = c1 != c2;
        }

        #line 175 "src/compiler/Generator.pv"
        fclose(orig);
    }

    #line 178 "src/compiler/Generator.pv"
    if (!different) {
        #line 178 "src/compiler/Generator.pv"
        return false;
    }

    #line 180 "src/compiler/Generator.pv"
    rewind(source);

    #line 182 "src/compiler/Generator.pv"
    FILE* out = fopen(file_name, "w");
    #line 183 "src/compiler/Generator.pv"
    if ((!out)) {
        #line 183 "src/compiler/Generator.pv"
        perror("fopen");
        #line 183 "src/compiler/Generator.pv"
        return false;
    }

    #line 185 "src/compiler/Generator.pv"
    int32_t c = fgetc(source);
    #line 186 "src/compiler/Generator.pv"
    while (c != EOF) {
        #line 187 "src/compiler/Generator.pv"
        fputc(c, out);
        #line 188 "src/compiler/Generator.pv"
        c = fgetc(source);
    }

    #line 191 "src/compiler/Generator.pv"
    fclose(out);
    #line 192 "src/compiler/Generator.pv"
    return true;
}

#line 195 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file) {
    #line 196 "src/compiler/Generator.pv"
    int16_t i = 0;

    #line 198 "src/compiler/Generator.pv"
    while (i < self->indent) {
        #line 199 "src/compiler/Generator.pv"
        fprintf(file, "    ");
        #line 200 "src/compiler/Generator.pv"
        i += 1;
    }
}

#line 204 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s) {
    #line 205 "src/compiler/Generator.pv"
    int32_t length = s.length;
    #line 206 "src/compiler/Generator.pv"
    fprintf(file, "%.*s", length, s.ptr);
    #line 207 "src/compiler/Generator.pv"
    return 1;
}

#line 210 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s) {
    #line 211 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, String__as_str(s));
}

#line 214 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s) {
    #line 215 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 216 "src/compiler/Generator.pv"
    uintptr_t length = s.length;
    #line 217 "src/compiler/Generator.pv"
    bool was_lowercase = false;

    #line 219 "src/compiler/Generator.pv"
    while (i < length) {
        #line 220 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 222 "src/compiler/Generator.pv"
        if (c >= 'a' && c <= 'z') {
            #line 223 "src/compiler/Generator.pv"
            fprintf(file, "%c", c - 32);
            #line 224 "src/compiler/Generator.pv"
            was_lowercase = 1;
        } else {
            #line 226 "src/compiler/Generator.pv"
            if (was_lowercase && c >= 'A' && c <= 'Z') {
                #line 227 "src/compiler/Generator.pv"
                fprintf(file, "_");
            }

            #line 230 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
            #line 231 "src/compiler/Generator.pv"
            was_lowercase = 0;
        }

        #line 234 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 237 "src/compiler/Generator.pv"
    return 1;
}

#line 240 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s) {
    #line 241 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 242 "src/compiler/Generator.pv"
    uintptr_t length = s.length;

    #line 244 "src/compiler/Generator.pv"
    while (i < length) {
        #line 245 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 247 "src/compiler/Generator.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 248 "src/compiler/Generator.pv"
            fprintf(file, "%c", c + 32);
        } else {
            #line 250 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
        }

        #line 253 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 256 "src/compiler/Generator.pv"
    return 1;
}

#line 259 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token) {
    #line 260 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, token->value);
}

#line 263 "src/compiler/Generator.pv"
bool Generator__is_discriminated_union(struct Enum* enum_info) {
    #line 264 "src/compiler/Generator.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 264 "src/compiler/Generator.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 264 "src/compiler/Generator.pv"
        struct EnumVariant* variant_info = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 265 "src/compiler/Generator.pv"
        if (variant_info->types.length > 0) {
            #line 266 "src/compiler/Generator.pv"
            return true;
        }
    } }

    #line 270 "src/compiler/Generator.pv"
    return false;
}

#line 273 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 274 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 275 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 275 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 275 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, &indirect->to, generics);
        } break;
        #line 276 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 276 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 276 "src/compiler/Generator.pv"
            return Generator__is_discriminated_union(enum_info);
        } break;
        #line 277 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 277 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 278 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 281 "src/compiler/Generator.pv"
    return 0;
}

#line 284 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 285 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_c99, type, generics->self_type, generics);
    #line 286 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 287 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 288 "src/compiler/Generator.pv"
    return true;
}

#line 291 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics) {
    #line 292 "src/compiler/Generator.pv"
    struct Type* self_type = type;
    #line 293 "src/compiler/Generator.pv"
    if (generics != 0) {
        #line 293 "src/compiler/Generator.pv"
        self_type = generics->self_type;
    }

    #line 295 "src/compiler/Generator.pv"
    struct String variable_decl = Naming__get_variable_decl(&self->naming_c99, name, type, self_type, generics);
    #line 296 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&variable_decl));
    #line 297 "src/compiler/Generator.pv"
    String__release(&variable_decl);
    #line 298 "src/compiler/Generator.pv"
    return true;
}

#line 301 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 302 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);

    #line 305 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&name));

    #line 307 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 310 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type) {
    #line 311 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 312 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 312 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 313 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 313 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 313 "src/compiler/Generator.pv"
            return Generator__is_reference(info->type);
        } break;
        #line 314 "src/compiler/Generator.pv"
        default: {
            #line 314 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 318 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 319 "src/compiler/Generator.pv"
    switch (Type__deref(type)->type) {
        #line 320 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 320 "src/compiler/Generator.pv"
            struct Struct* struct_info = Type__deref(type)->struct_value._0;
            #line 320 "src/compiler/Generator.pv"
            return Struct__is_newtype(struct_info);
        } break;
        #line 321 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 321 "src/compiler/Generator.pv"
            return Generator__is_type_single_value_struct(self, generics->self_type, generics);
        } break;
        #line 322 "src/compiler/Generator.pv"
        default: {
            #line 322 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 326 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map) {
    #line 327 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 328 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 328 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_map->self_type, func_name, generic_map);
        } break;
        #line 329 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 329 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 329 "src/compiler/Generator.pv"
            return Generator__get_function(self, &indirect->to, func_name, generic_map);
        } break;
        #line 330 "src/compiler/Generator.pv"
        case TYPE__GENERIC: {
            #line 330 "src/compiler/Generator.pv"
            struct Generic* generic = type->generic_value;
            #line 331 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 332 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, but no generic map input\n");
                #line 333 "src/compiler/Generator.pv"
                return 0;
            }

            #line 336 "src/compiler/Generator.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 337 "src/compiler/Generator.pv"
            if (generic_type == 0) {
                #line 338 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, no item in generic map found\n");
                #line 339 "src/compiler/Generator.pv"
                return 0;
            }

            #line 342 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_type, func_name, generic_map);
        } break;
        #line 344 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 344 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 345 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 346 "src/compiler/Generator.pv"
                int32_t name_length = primitive_info->name.length;
                #line 347 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitive_info %.*s for get_function\n", name_length, primitive_info->name.ptr);
                #line 348 "src/compiler/Generator.pv"
                return 0;
            }

            #line 351 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 353 "src/compiler/Generator.pv"
            struct ArrayIter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 354 "src/compiler/Generator.pv"
            while (func_info == 0 && ArrayIter_ref_ref_Impl__next(&impl_iter)) {
                #line 355 "src/compiler/Generator.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&impl_iter);
                #line 356 "src/compiler/Generator.pv"
                func_info = HashMap_str_Function__find(&impl_info->functions, &func_name);
            }

            #line 359 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 360 "src/compiler/Generator.pv"
                int32_t name_length = primitive_info->name.length;
                #line 361 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 362 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitives %.*s function %.*s for get_function\n", name_length, primitive_info->name.ptr, func_name_length, func_name.ptr);
            }

            #line 365 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 367 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 367 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 368 "src/compiler/Generator.pv"
            if (enum_info == 0) {
                #line 369 "src/compiler/Generator.pv"
                int32_t name_length = enum_info->name->value.length;
                #line 370 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enum %.*s for get_function\n", name_length, enum_info->name->value.ptr);
                #line 371 "src/compiler/Generator.pv"
                return 0;
            }

            #line 374 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 376 "src/compiler/Generator.pv"
            struct ArrayIter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 377 "src/compiler/Generator.pv"
            while (func_info == 0 && ArrayIter_ref_ref_Impl__next(&impl_iter)) {
                #line 378 "src/compiler/Generator.pv"
                struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&impl_iter);
                #line 379 "src/compiler/Generator.pv"
                func_info = HashMap_str_Function__find(&impl_info->functions, &func_name);
            }

            #line 382 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 383 "src/compiler/Generator.pv"
                int32_t name_length = enum_info->name->value.length;
                #line 384 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 385 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enums %.*s function %.*s for get_function\n", name_length, enum_info->name->value.ptr, func_name_length, func_name.ptr);
            }

            #line 388 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 390 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 390 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 391 "src/compiler/Generator.pv"
            if (struct_info == 0) {
                #line 392 "src/compiler/Generator.pv"
                int32_t name_length = struct_info->name->value.length;
                #line 393 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find struct %.*s for get_function\n", name_length, struct_info->name->value.ptr);
                #line 394 "src/compiler/Generator.pv"
                return 0;
            }

            #line 397 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 399 "src/compiler/Generator.pv"
            { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
            #line 399 "src/compiler/Generator.pv"
            while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
                #line 399 "src/compiler/Generator.pv"
                uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
                #line 399 "src/compiler/Generator.pv"
                struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

                #line 400 "src/compiler/Generator.pv"
                func_info = HashMap_str_Function__find(&impl_info->functions, &func_name);

                #line 402 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 402 "src/compiler/Generator.pv"
                    break;
                }

                #line 404 "src/compiler/Generator.pv"
                func_info = HashMap_str_Function__find(&impl_info->trait_->functions, &func_name);

                #line 406 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 407 "src/compiler/Generator.pv"
                    func_info = ArenaAllocator__store_Function(self->allocator, *func_info);
                    #line 408 "src/compiler/Generator.pv"
                    func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                    #line 409 "src/compiler/Generator.pv"
                    break;
                }
            } }

            #line 413 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 414 "src/compiler/Generator.pv"
                int32_t name_length = struct_info->name->value.length;
                #line 415 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 416 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find structs %.*s function %.*s for get_function\n", name_length, struct_info->name->value.ptr, func_name_length, func_name.ptr);
            }

            #line 419 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 421 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 421 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 422 "src/compiler/Generator.pv"
            if (trait_info == 0) {
                #line 423 "src/compiler/Generator.pv"
                int32_t name_length = trait_info->name->value.length;
                #line 424 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find trait %.*s for get_function\n", name_length, trait_info->name->value.ptr);
                #line 425 "src/compiler/Generator.pv"
                return 0;
            }

            #line 428 "src/compiler/Generator.pv"
            struct Function* func_info = HashMap_str_Function__find(&trait_info->functions, &func_name);

            #line 430 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 431 "src/compiler/Generator.pv"
                int32_t name_length = trait_info->name->value.length;
                #line 432 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 433 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find traits %.*s function %.*s for get_function\n", name_length, trait_info->name->value.ptr, func_name_length, func_name.ptr);
            }

            #line 436 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 438 "src/compiler/Generator.pv"
        default: {
            #line 439 "src/compiler/Generator.pv"
            fprintf(stderr, "Unhandled type for getting function %s\n", Type__name(type));
        } break;
    }

    #line 443 "src/compiler/Generator.pv"
    return 0;
}

#line 446 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant) {
    #line 447 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;
    #line 448 "src/compiler/Generator.pv"
    struct Token* name = parent->name;
    #line 449 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, name->value);
    #line 450 "src/compiler/Generator.pv"
    fprintf(file, "__");
    #line 451 "src/compiler/Generator.pv"
    struct Token* variant_name = variant->name;
    #line 452 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, variant_name->value);

    #line 454 "src/compiler/Generator.pv"
    return 1;
}

#line 457 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 458 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 459 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 459 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 460 "src/compiler/Generator.pv"
            fprintf(file, "*");
            #line 461 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, &indirect->to, generics);
        } break;
        #line 463 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 463 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 464 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, info->type, generics);
        } break;
        #line 466 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 469 "src/compiler/Generator.pv"
    return 1;
}

#line 472 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics) {
    #line 473 "src/compiler/Generator.pv"
    fprintf(file, "::");

    #line 475 "src/compiler/Generator.pv"
    return true;
}

#line 478 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 479 "src/compiler/Generator.pv"
    if (Type__is_fat_pointer(type)) {
        #line 480 "src/compiler/Generator.pv"
        fprintf(file, ".");
        #line 481 "src/compiler/Generator.pv"
        return true;
    }

    #line 484 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 485 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 486 "src/compiler/Generator.pv"
            fprintf(file, "->");
        } break;
        #line 488 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 489 "src/compiler/Generator.pv"
            return Generator__write_instance_member_accessor(self, file, generics->self_type, generics);
        } break;
        #line 491 "src/compiler/Generator.pv"
        default: {
            #line 492 "src/compiler/Generator.pv"
            fprintf(file, ".");
        } break;
    }

    #line 496 "src/compiler/Generator.pv"
    return true;
}

#line 499 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value) {
    #line 500 "src/compiler/Generator.pv"
    Generator__write_str(self, file, value);

    #line 502 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 503 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 503 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 504 "src/compiler/Generator.pv"
            if (str__eq(primitive_info->name, (struct str){ .ptr = "u64", .length = strlen("u64") })) {
                #line 505 "src/compiler/Generator.pv"
                fprintf(file, "ULL");
            }
        } break;
        #line 508 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 511 "src/compiler/Generator.pv"
    return true;
}

#line 514 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 515 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);

    #line 518 "src/compiler/Generator.pv"
    Hashed type_id = Fnv1a__hash(type_name.array.data, String__length(&type_name));

    #line 520 "src/compiler/Generator.pv"
    fprintf(file, "%zuULL", type_id);

    #line 522 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 525 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token) {
    #line 526 "src/compiler/Generator.pv"
    if (self->output_line_directives) {
        #line 527 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 528 "src/compiler/Generator.pv"
        fprintf(file, "#line %zu \"", token->start_line + 1);
        #line 529 "src/compiler/Generator.pv"
        Generator__write_str(self, file, context->path);
        #line 530 "src/compiler/Generator.pv"
        fprintf(file, "\"\n");
    }
}

#line 534 "src/compiler/Generator.pv"
void Generator__write_str_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 535 "src/compiler/Generator.pv"
    if (reference) {
        #line 535 "src/compiler/Generator.pv"
        fprintf(file, "&");
    }
    #line 536 "src/compiler/Generator.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 537 "src/compiler/Generator.pv"
    Generator__write_expression(self, file, inner_expr, generics);
    #line 538 "src/compiler/Generator.pv"
    fprintf(file, ", .length = strlen(");
    #line 539 "src/compiler/Generator.pv"
    Generator__write_expression(self, file, inner_expr, generics);
    #line 540 "src/compiler/Generator.pv"
    fprintf(file, ") }");
}

#line 543 "src/compiler/Generator.pv"
void Generator__write_trait_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 544 "src/compiler/Generator.pv"
    switch (Type__deref(&inner_expr->return_type)->type) {
        #line 545 "src/compiler/Generator.pv"
        case TYPE__FUNCTION: {
            #line 545 "src/compiler/Generator.pv"
            struct Function* func_info = Type__deref(&inner_expr->return_type)->function_value._0;
            #line 545 "src/compiler/Generator.pv"
            struct GenericMap* func_generics = Type__deref(&inner_expr->return_type)->function_value._1;
            #line 546 "src/compiler/Generator.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 547 "src/compiler/Generator.pv"
                fprintf(file, "(struct Co_CoroutineStatus) { .vtable = &");

                #line 549 "src/compiler/Generator.pv"
                switch (func_info->parent.type) {
                    #line 550 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 550 "src/compiler/Generator.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 551 "src/compiler/Generator.pv"
                        Generator__write_str_title(self, file, struct_info->name->value);
                        #line 552 "src/compiler/Generator.pv"
                        fprintf(file, "__");
                    } break;
                    #line 554 "src/compiler/Generator.pv"
                    default: {
                    } break;
                }

                #line 557 "src/compiler/Generator.pv"
                Generator__write_str_title(self, file, func_info->name->value);
                #line 558 "src/compiler/Generator.pv"
                fprintf(file, "__VTABLE__DYN_CO, .instance = &(struct ");
                #line 559 "src/compiler/Generator.pv"
                Generator__write_function_name(self, file, func_info, func_generics);
                #line 560 "src/compiler/Generator.pv"
                fprintf(file, "__Co_CoroutineStatus__Instance) {}");

                #line 562 "src/compiler/Generator.pv"
                fprintf(file, " }");
            } else {
                #line 564 "src/compiler/Generator.pv"
                fprintf(file, "(struct Fn) { .vtable = &");

                #line 566 "src/compiler/Generator.pv"
                switch (func_info->parent.type) {
                    #line 567 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 567 "src/compiler/Generator.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 568 "src/compiler/Generator.pv"
                        Generator__write_str_title(self, file, struct_info->name->value);
                        #line 569 "src/compiler/Generator.pv"
                        fprintf(file, "__");
                    } break;
                    #line 571 "src/compiler/Generator.pv"
                    default: {
                    } break;
                }

                #line 574 "src/compiler/Generator.pv"
                Generator__write_str_title(self, file, func_info->name->value);
                #line 575 "src/compiler/Generator.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 576 "src/compiler/Generator.pv"
                Generator__write_function_name(self, file, func_info, func_generics);
                #line 577 "src/compiler/Generator.pv"
                fprintf(file, "__Fn__Instance) {}");

                #line 579 "src/compiler/Generator.pv"
                fprintf(file, " }");
            }

            #line 582 "src/compiler/Generator.pv"
            return;
        } break;
        #line 584 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 587 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 588 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 588 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 589 "src/compiler/Generator.pv"
            fprintf(file, "(");
            #line 590 "src/compiler/Generator.pv"
            Generator__write_type(self, file, type, generics);
            #line 591 "src/compiler/Generator.pv"
            fprintf(file, ") { .vtable = &");

            #line 593 "src/compiler/Generator.pv"
            struct Type* inner_type = Context__resolve_type(self->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 594 "src/compiler/Generator.pv"
            struct String inner_type_name = Naming__get_type_name(&self->naming_ident, inner_type, generics->array.data, generics);
            #line 595 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, String__as_str(&inner_type_name));

            #line 597 "src/compiler/Generator.pv"
            fprintf(file, "__VTABLE__");
            #line 598 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, trait_info->name->value);
            #line 599 "src/compiler/Generator.pv"
            fprintf(file, ", .instance = ");
            #line 600 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, inner_expr, generics);
            #line 601 "src/compiler/Generator.pv"
            fprintf(file, " }");
        } break;
        #line 603 "src/compiler/Generator.pv"
        default: {
            #line 603 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 607 "src/compiler/Generator.pv"
void Generator__write_sequence_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 608 "src/compiler/Generator.pv"
    struct Sequence* inner_sequence = 0;

    #line 610 "src/compiler/Generator.pv"
    switch (inner_expr->return_type.type) {
        #line 611 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 611 "src/compiler/Generator.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 612 "src/compiler/Generator.pv"
            switch (indirect->to.type) {
                #line 613 "src/compiler/Generator.pv"
                case TYPE__SEQUENCE: {
                    #line 613 "src/compiler/Generator.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 613 "src/compiler/Generator.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 614 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 617 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 620 "src/compiler/Generator.pv"
    if (inner_sequence == 0) {
        #line 621 "src/compiler/Generator.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 622 "src/compiler/Generator.pv"
        return;
    }

    #line 625 "src/compiler/Generator.pv"
    uintptr_t length = 0;
    #line 626 "src/compiler/Generator.pv"
    switch (inner_sequence->type.type) {
        #line 627 "src/compiler/Generator.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 627 "src/compiler/Generator.pv"
            uintptr_t seq_length = inner_sequence->type.fixedarray_value;
            #line 627 "src/compiler/Generator.pv"
            length = seq_length;
        } break;
        #line 628 "src/compiler/Generator.pv"
        default: {
            #line 629 "src/compiler/Generator.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 630 "src/compiler/Generator.pv"
            return;
        } break;
    }

    #line 634 "src/compiler/Generator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

    #line 636 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_c99, &sequence_type, &sequence_type, generics);
    #line 637 "src/compiler/Generator.pv"
    struct Expression* unary_inner = 0;

    #line 639 "src/compiler/Generator.pv"
    switch (inner_expr->data.type) {
        #line 640 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 640 "src/compiler/Generator.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 640 "src/compiler/Generator.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 641 "src/compiler/Generator.pv"
            if (str__eq(expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 642 "src/compiler/Generator.pv"
                unary_inner = inner;
            }
        } break;
        #line 645 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 648 "src/compiler/Generator.pv"
    fprintf(file, "(");
    #line 649 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &name);
    #line 650 "src/compiler/Generator.pv"
    fprintf(file, ") { .data = ");

    #line 652 "src/compiler/Generator.pv"
    if (unary_inner != 0) {
        #line 653 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, unary_inner, generics);
    } else {
        #line 655 "src/compiler/Generator.pv"
        fprintf(file, "*");
        #line 656 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, inner_expr, generics);
    }

    #line 659 "src/compiler/Generator.pv"
    fprintf(file, ", .length = %zu }", length);
}

#line 662 "src/compiler/Generator.pv"
bool Generator__write_struct_construction(struct Generator* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 663 "src/compiler/Generator.pv"
    if (Generator__is_type_single_value_struct(self, type, generics)) {
        #line 664 "src/compiler/Generator.pv"
        if (fields->length > 1) {
            #line 665 "src/compiler/Generator.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 667 "src/compiler/Generator.pv"
            struct InvokeArgument* field = fields->data;
            #line 668 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, field->value, generics);
        } else {
            #line 670 "src/compiler/Generator.pv"
            fprintf(file, "0");
        }
    } else {
        #line 673 "src/compiler/Generator.pv"
        bool compact = fields->length <= 1 || fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line;

        #line 675 "src/compiler/Generator.pv"
        fprintf(file, "(");
        #line 676 "src/compiler/Generator.pv"
        Generator__write_type(self, file, type, generics);

        #line 678 "src/compiler/Generator.pv"
        if (fields->length == 0) {
            #line 679 "src/compiler/Generator.pv"
            fprintf(file, ") {}");
        } else {
            #line 681 "src/compiler/Generator.pv"
            fprintf(file, ") {");
            #line 682 "src/compiler/Generator.pv"
            if (!compact) {
                #line 682 "src/compiler/Generator.pv"
                fprintf(file, "\n");
            }
        }

        #line 685 "src/compiler/Generator.pv"
        self->indent += 1;
        #line 686 "src/compiler/Generator.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = ArrayIter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 686 "src/compiler/Generator.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 686 "src/compiler/Generator.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 686 "src/compiler/Generator.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 687 "src/compiler/Generator.pv"
            if (compact) {
                #line 688 "src/compiler/Generator.pv"
                if (i > 0) {
                    #line 688 "src/compiler/Generator.pv"
                    fprintf(file, ", .");
                } else {
                    #line 689 "src/compiler/Generator.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 691 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 692 "src/compiler/Generator.pv"
                fprintf(file, ".");
            }

            #line 695 "src/compiler/Generator.pv"
            Generator__write_token(self, file, field->name);
            #line 696 "src/compiler/Generator.pv"
            fprintf(file, " = ");
            #line 697 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, field->value, generics);
            #line 698 "src/compiler/Generator.pv"
            if (!compact) {
                #line 698 "src/compiler/Generator.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 701 "src/compiler/Generator.pv"
        self->indent -= 1;

        #line 703 "src/compiler/Generator.pv"
        if (fields->length != 0) {
            #line 704 "src/compiler/Generator.pv"
            if (compact) {
                #line 705 "src/compiler/Generator.pv"
                fprintf(file, " }");
            } else {
                #line 707 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 708 "src/compiler/Generator.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 713 "src/compiler/Generator.pv"
    return true;
}

#line 716 "src/compiler/Generator.pv"
bool Generator__write_enum_variant(struct Generator* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 717 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;

    #line 719 "src/compiler/Generator.pv"
    if (Generator__is_discriminated_union(parent) == 0) {
        #line 720 "src/compiler/Generator.pv"
        Generator__write_enum_variant_name(self, file, type, variant);
        #line 721 "src/compiler/Generator.pv"
        return true;
    }

    #line 724 "src/compiler/Generator.pv"
    fprintf(file, "(");
    #line 725 "src/compiler/Generator.pv"
    Generator__write_type(self, file, type, generics);
    #line 726 "src/compiler/Generator.pv"
    fprintf(file, ") { .type = ");
    #line 727 "src/compiler/Generator.pv"
    Generator__write_enum_variant_name(self, file, type, variant);

    #line 729 "src/compiler/Generator.pv"
    if (arguments == 0) {
        #line 730 "src/compiler/Generator.pv"
        fprintf(file, " }");
        #line 731 "src/compiler/Generator.pv"
        return true;
    }

    #line 734 "src/compiler/Generator.pv"
    if (arguments->length > 0) {
        #line 735 "src/compiler/Generator.pv"
        fprintf(file, ", .");
        #line 736 "src/compiler/Generator.pv"
        struct Token* name = variant->name;
        #line 737 "src/compiler/Generator.pv"
        Generator__write_str_lowercase(self, file, name->value);
        #line 738 "src/compiler/Generator.pv"
        fprintf(file, "_value = ");
    }

    #line 741 "src/compiler/Generator.pv"
    if (arguments->length == 1) {
        #line 742 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 744 "src/compiler/Generator.pv"
        fprintf(file, "{ ");

        #line 746 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 747 "src/compiler/Generator.pv"
        { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 747 "src/compiler/Generator.pv"
        while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
            #line 747 "src/compiler/Generator.pv"
            struct InvokeArgument arg = *ArrayIter_ref_InvokeArgument__value(&__iter);

            #line 748 "src/compiler/Generator.pv"
            if (i > 0) {
                #line 749 "src/compiler/Generator.pv"
                fprintf(file, ", ");
            }

            #line 752 "src/compiler/Generator.pv"
            fprintf(file, "._%zu = ", i);

            #line 754 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, arg.value, generics);
            #line 755 "src/compiler/Generator.pv"
            i += 1;
        } }

        #line 758 "src/compiler/Generator.pv"
        fprintf(file, "}");
    }

    #line 761 "src/compiler/Generator.pv"
    fprintf(file, " }");

    #line 763 "src/compiler/Generator.pv"
    return true;
}

#line 766 "src/compiler/Generator.pv"
bool Generator__write_coroutine_invoke(struct Generator* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 767 "src/compiler/Generator.pv"
    struct ExpressionData* data = &expression->data;

    #line 769 "src/compiler/Generator.pv"
    switch (data->type) {
        #line 770 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 770 "src/compiler/Generator.pv"
            struct Type* type = data->type_value;
            #line 771 "src/compiler/Generator.pv"
            switch (type->type) {
                #line 772 "src/compiler/Generator.pv"
                case TYPE__FUNCTION: {
                    #line 772 "src/compiler/Generator.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 772 "src/compiler/Generator.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 773 "src/compiler/Generator.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, self->allocator, generics);

                    #line 775 "src/compiler/Generator.pv"
                    fprintf(file, "(struct ");
                    #line 776 "src/compiler/Generator.pv"
                    Generator__write_function_name(self, file, func_info, &resolved_generics);
                    #line 777 "src/compiler/Generator.pv"
                    fprintf(file, ") {");

                    #line 779 "src/compiler/Generator.pv"
                    uintptr_t i = 0;
                    #line 780 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 780 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_Parameter__next(&__iter)) {
                        #line 780 "src/compiler/Generator.pv"
                        struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                        #line 781 "src/compiler/Generator.pv"
                        if (i == 0) {
                            #line 782 "src/compiler/Generator.pv"
                            fprintf(file, " .");
                        } else {
                            #line 784 "src/compiler/Generator.pv"
                            fprintf(file, ", .");
                        }

                        #line 787 "src/compiler/Generator.pv"
                        Generator__write_token(self, file, param->name);
                        #line 788 "src/compiler/Generator.pv"
                        fprintf(file, " = ");

                        #line 790 "src/compiler/Generator.pv"
                        if (i < arguments->length) {
                            #line 791 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 793 "src/compiler/Generator.pv"
                            fprintf(file, "0");
                        }

                        #line 796 "src/compiler/Generator.pv"
                        i += 1;
                    } }

                    #line 799 "src/compiler/Generator.pv"
                    fprintf(file, " }");
                    #line 800 "src/compiler/Generator.pv"
                    return true;
                } break;
                #line 802 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 805 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 808 "src/compiler/Generator.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 809 "src/compiler/Generator.pv"
    return false;
}

#line 812 "src/compiler/Generator.pv"
bool Generator__write_builtin_function_invoke(struct Generator* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 813 "src/compiler/Generator.pv"
    struct str name = func_info->name->value;

    #line 815 "src/compiler/Generator.pv"
    if (str__eq(name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 816 "src/compiler/Generator.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, self->allocator, generics);

        #line 818 "src/compiler/Generator.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 819 "src/compiler/Generator.pv"
        if (type == 0) {
            #line 819 "src/compiler/Generator.pv"
            return false;
        }

        #line 821 "src/compiler/Generator.pv"
        return Generator__write_typeid(self, file, type, generics);
    }

    #line 824 "src/compiler/Generator.pv"
    if (str__eq(name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 825 "src/compiler/Generator.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, self->allocator, generics);

        #line 827 "src/compiler/Generator.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 828 "src/compiler/Generator.pv"
        if (arg == 0) {
            #line 828 "src/compiler/Generator.pv"
            return false;
        }

        #line 830 "src/compiler/Generator.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 831 "src/compiler/Generator.pv"
        if (type == 0) {
            #line 831 "src/compiler/Generator.pv"
            return false;
        }

        #line 833 "src/compiler/Generator.pv"
        fprintf(file, "(");
        #line 834 "src/compiler/Generator.pv"
        Generator__write_type(self, file, type, generics);
        #line 835 "src/compiler/Generator.pv"
        fprintf(file, ")(");
        #line 836 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, arg->value, generics);
        #line 837 "src/compiler/Generator.pv"
        fprintf(file, ")");
        #line 838 "src/compiler/Generator.pv"
        return true;
    }

    #line 841 "src/compiler/Generator.pv"
    Generator__write_token(self, file, func_info->name);

    #line 843 "src/compiler/Generator.pv"
    fprintf(file, "(");
    #line 844 "src/compiler/Generator.pv"
    bool first = true;
    #line 845 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 845 "src/compiler/Generator.pv"
    while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
        #line 845 "src/compiler/Generator.pv"
        struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

        #line 846 "src/compiler/Generator.pv"
        if (first) {
            #line 846 "src/compiler/Generator.pv"
            first = false;
        } else {
            #line 846 "src/compiler/Generator.pv"
            fprintf(file, ", ");
        }
        #line 847 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, arg->value, generics);
    } }

    #line 850 "src/compiler/Generator.pv"
    fprintf(file, ")");

    #line 852 "src/compiler/Generator.pv"
    return true;
}

#line 855 "src/compiler/Generator.pv"
bool Generator__write_invoke(struct Generator* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 856 "src/compiler/Generator.pv"
    struct ExpressionData* data = &expression->data;
    #line 857 "src/compiler/Generator.pv"
    switch (data->type) {
        #line 858 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 858 "src/compiler/Generator.pv"
            struct str name = data->variable_value;
            #line 859 "src/compiler/Generator.pv"
            bool success = Generator__write_str(self, file, name);
            #line 860 "src/compiler/Generator.pv"
            fprintf(file, "(");

            #line 862 "src/compiler/Generator.pv"
            bool first = true;
            #line 863 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 863 "src/compiler/Generator.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 863 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 864 "src/compiler/Generator.pv"
                if (first) {
                    #line 864 "src/compiler/Generator.pv"
                    first = false;
                } else {
                    #line 864 "src/compiler/Generator.pv"
                    fprintf(file, ", ");
                }
                #line 865 "src/compiler/Generator.pv"
                success = Generator__write_expression(self, file, arg->value, generics) && success;
            } }

            #line 868 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 870 "src/compiler/Generator.pv"
            return success;
        } break;
        #line 872 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 873 "src/compiler/Generator.pv"
            bool success = Generator__write_expression(self, file, expression, generics);
            #line 874 "src/compiler/Generator.pv"
            fprintf(file, "(");

            #line 876 "src/compiler/Generator.pv"
            bool first = true;
            #line 877 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 877 "src/compiler/Generator.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 877 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 878 "src/compiler/Generator.pv"
                if (first) {
                    #line 878 "src/compiler/Generator.pv"
                    first = false;
                } else {
                    #line 878 "src/compiler/Generator.pv"
                    fprintf(file, ", ");
                }
                #line 879 "src/compiler/Generator.pv"
                success = Generator__write_expression(self, file, arg->value, generics) && success;
            } }

            #line 882 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 884 "src/compiler/Generator.pv"
            return success;
        } break;
        #line 886 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 887 "src/compiler/Generator.pv"
            bool success = Generator__write_expression(self, file, expression, generics);
            #line 888 "src/compiler/Generator.pv"
            fprintf(file, "(");

            #line 890 "src/compiler/Generator.pv"
            bool first = true;
            #line 891 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 891 "src/compiler/Generator.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 891 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 892 "src/compiler/Generator.pv"
                if (first) {
                    #line 892 "src/compiler/Generator.pv"
                    first = false;
                } else {
                    #line 892 "src/compiler/Generator.pv"
                    fprintf(file, ", ");
                }
                #line 893 "src/compiler/Generator.pv"
                success = Generator__write_expression(self, file, arg->value, generics) && success;
            } }

            #line 896 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 898 "src/compiler/Generator.pv"
            return success;
        } break;
        #line 900 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 900 "src/compiler/Generator.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 901 "src/compiler/Generator.pv"
            return Generator__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 903 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 903 "src/compiler/Generator.pv"
            struct Type* type = data->type_value;
            #line 904 "src/compiler/Generator.pv"
            switch (type->type) {
                #line 905 "src/compiler/Generator.pv"
                case TYPE__SELF: {
                    #line 905 "src/compiler/Generator.pv"
                    type = generics->self_type;
                } break;
                #line 906 "src/compiler/Generator.pv"
                default: {
                } break;
            }

            #line 909 "src/compiler/Generator.pv"
            switch (Type__resolve_typedef(type)->type) {
                #line 910 "src/compiler/Generator.pv"
                case TYPE__STRUCT: {
                    #line 911 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 913 "src/compiler/Generator.pv"
                case TYPE__STRUCT_C: {
                    #line 914 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 916 "src/compiler/Generator.pv"
                case TYPE__UNION_C: {
                    #line 917 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 919 "src/compiler/Generator.pv"
                case TYPE__TUPLE: {
                    #line 922 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 927 "src/compiler/Generator.pv"
                case TYPE__FUNCTION: {
                    #line 927 "src/compiler/Generator.pv"
                    struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                    #line 927 "src/compiler/Generator.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
                    #line 928 "src/compiler/Generator.pv"
                    switch (func_info->type) {
                        #line 929 "src/compiler/Generator.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 930 "src/compiler/Generator.pv"
                            return Generator__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 932 "src/compiler/Generator.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 933 "src/compiler/Generator.pv"
                            return Generator__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 935 "src/compiler/Generator.pv"
                        default: {
                        } break;
                    }

                    #line 938 "src/compiler/Generator.pv"
                    struct str name = func_info->name->value;
                    #line 939 "src/compiler/Generator.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, self->allocator, generics);

                    #line 941 "src/compiler/Generator.pv"
                    struct ArrayIter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 942 "src/compiler/Generator.pv"
                    bool success = true;
                    #line 943 "src/compiler/Generator.pv"
                    bool first = true;

                    #line 945 "src/compiler/Generator.pv"
                    switch (func_info->parent.type) {
                        #line 946 "src/compiler/Generator.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 946 "src/compiler/Generator.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 947 "src/compiler/Generator.pv"
                            if (!ArrayIter_ref_InvokeArgument__next(&args)) {
                                #line 948 "src/compiler/Generator.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 949 "src/compiler/Generator.pv"
                                return false;
                            }

                            #line 952 "src/compiler/Generator.pv"
                            struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&args);

                            #line 954 "src/compiler/Generator.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 955 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                                #line 956 "src/compiler/Generator.pv"
                                fprintf(file, ".vtable->");
                                #line 957 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, name) && success;
                                #line 958 "src/compiler/Generator.pv"
                                fprintf(file, "(");
                                #line 959 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                                #line 960 "src/compiler/Generator.pv"
                                fprintf(file, ".instance");

                                #line 962 "src/compiler/Generator.pv"
                                first = false;
                            } else {
                                #line 964 "src/compiler/Generator.pv"
                                struct String parent_name = Naming__get_type_name(&self->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 965 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, String__as_str(&parent_name)) && success;
                                #line 966 "src/compiler/Generator.pv"
                                fprintf(file, "__");

                                #line 968 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, trait_info->name->value) && success;
                                #line 969 "src/compiler/Generator.pv"
                                fprintf(file, "__");

                                #line 971 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, func_info->name->value) && success;
                                #line 972 "src/compiler/Generator.pv"
                                fprintf(file, "(");

                                #line 974 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;

                                #line 976 "src/compiler/Generator.pv"
                                first = false;
                            }
                        } break;
                        #line 980 "src/compiler/Generator.pv"
                        default: {
                            #line 981 "src/compiler/Generator.pv"
                            success = Generator__write_function_name(self, file, func_info, &resolved_generics) && success;
                            #line 982 "src/compiler/Generator.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 986 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_InvokeArgument __iter = args;
                    #line 986 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                        #line 986 "src/compiler/Generator.pv"
                        struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                        #line 987 "src/compiler/Generator.pv"
                        if (first) {
                            #line 987 "src/compiler/Generator.pv"
                            first = false;
                        } else {
                            #line 987 "src/compiler/Generator.pv"
                            fprintf(file, ", ");
                        }
                        #line 988 "src/compiler/Generator.pv"
                        success = Generator__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 991 "src/compiler/Generator.pv"
                    fprintf(file, ")");

                    #line 993 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 995 "src/compiler/Generator.pv"
                case TYPE__FUNCTION_C: {
                    #line 995 "src/compiler/Generator.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
                    #line 996 "src/compiler/Generator.pv"
                    struct str name = func_info->name;

                    #line 998 "src/compiler/Generator.pv"
                    bool success = Generator__write_str(self, file, name);
                    #line 999 "src/compiler/Generator.pv"
                    fprintf(file, "(");

                    #line 1001 "src/compiler/Generator.pv"
                    bool first = true;
                    #line 1002 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 1002 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                        #line 1002 "src/compiler/Generator.pv"
                        struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                        #line 1003 "src/compiler/Generator.pv"
                        if (first) {
                            #line 1003 "src/compiler/Generator.pv"
                            first = false;
                        } else {
                            #line 1003 "src/compiler/Generator.pv"
                            fprintf(file, ", ");
                        }
                        #line 1004 "src/compiler/Generator.pv"
                        success = Generator__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 1007 "src/compiler/Generator.pv"
                    fprintf(file, ")");

                    #line 1009 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 1011 "src/compiler/Generator.pv"
                case TYPE__SEQUENCE: {
                    #line 1011 "src/compiler/Generator.pv"
                    struct Sequence* sequence = Type__resolve_typedef(type)->sequence_value;
                    #line 1012 "src/compiler/Generator.pv"
                    bool success = true;

                    #line 1014 "src/compiler/Generator.pv"
                    switch (sequence->type.type) {
                        #line 1015 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1016 "src/compiler/Generator.pv"
                            fprintf(file, "{");

                            #line 1018 "src/compiler/Generator.pv"
                            bool first = true;
                            #line 1019 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 1019 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                                #line 1019 "src/compiler/Generator.pv"
                                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                                #line 1020 "src/compiler/Generator.pv"
                                if (first) {
                                    #line 1020 "src/compiler/Generator.pv"
                                    first = false;
                                } else {
                                    #line 1020 "src/compiler/Generator.pv"
                                    fprintf(file, ", ");
                                }
                                #line 1021 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                            } }

                            #line 1024 "src/compiler/Generator.pv"
                            fprintf(file, "}");
                        } break;
                        #line 1026 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1027 "src/compiler/Generator.pv"
                            fprintf(file, "(");
                            #line 1028 "src/compiler/Generator.pv"
                            Generator__write_type(self, file, &expression->return_type, generics);
                            #line 1029 "src/compiler/Generator.pv"
                            fprintf(file, ") {");

                            #line 1031 "src/compiler/Generator.pv"
                            bool first = true;
                            #line 1032 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 1032 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                                #line 1032 "src/compiler/Generator.pv"
                                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                                #line 1033 "src/compiler/Generator.pv"
                                if (first) {
                                    #line 1033 "src/compiler/Generator.pv"
                                    first = false;
                                    #line 1033 "src/compiler/Generator.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 1033 "src/compiler/Generator.pv"
                                    fprintf(file, ", .");
                                }
                                #line 1034 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, arg->name->value) && success;
                                #line 1035 "src/compiler/Generator.pv"
                                fprintf(file, " = ");
                                #line 1036 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                            } }

                            #line 1039 "src/compiler/Generator.pv"
                            fprintf(file, " }");
                        } break;
                    }

                    #line 1044 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 1046 "src/compiler/Generator.pv"
                case TYPE__CLASS_CPP: {
                    #line 1046 "src/compiler/Generator.pv"
                    struct ClassCpp* class_info = Type__resolve_typedef(type)->classcpp_value;
                    #line 1047 "src/compiler/Generator.pv"
                    struct str name = class_info->name;

                    #line 1049 "src/compiler/Generator.pv"
                    bool success = Generator__write_str(self, file, name);
                    #line 1050 "src/compiler/Generator.pv"
                    bool function_mode = arguments->length > 0 && arguments->data[0].name == 0;

                    #line 1052 "src/compiler/Generator.pv"
                    if (function_mode) {
                        #line 1053 "src/compiler/Generator.pv"
                        fprintf(file, "(");

                        #line 1055 "src/compiler/Generator.pv"
                        bool first = true;
                        #line 1056 "src/compiler/Generator.pv"
                        { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 1056 "src/compiler/Generator.pv"
                        while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                            #line 1056 "src/compiler/Generator.pv"
                            struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                            #line 1057 "src/compiler/Generator.pv"
                            if (first) {
                                #line 1057 "src/compiler/Generator.pv"
                                first = false;
                            } else {
                                #line 1057 "src/compiler/Generator.pv"
                                fprintf(file, ", ");
                            }
                            #line 1058 "src/compiler/Generator.pv"
                            success = Generator__write_expression(self, file, arg->value, generics) && success;
                        } }

                        #line 1061 "src/compiler/Generator.pv"
                        fprintf(file, ")");
                    } else {
                        #line 1063 "src/compiler/Generator.pv"
                        fprintf(file, " {");

                        #line 1065 "src/compiler/Generator.pv"
                        bool first = true;
                        #line 1066 "src/compiler/Generator.pv"
                        { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 1066 "src/compiler/Generator.pv"
                        while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                            #line 1066 "src/compiler/Generator.pv"
                            struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                            #line 1067 "src/compiler/Generator.pv"
                            if (first) {
                                #line 1067 "src/compiler/Generator.pv"
                                first = false;
                                #line 1067 "src/compiler/Generator.pv"
                                fprintf(file, " .");
                            } else {
                                #line 1067 "src/compiler/Generator.pv"
                                fprintf(file, ", .");
                            }
                            #line 1068 "src/compiler/Generator.pv"
                            success = Generator__write_str(self, file, arg->name->value) && success;
                            #line 1069 "src/compiler/Generator.pv"
                            fprintf(file, " = ");
                            #line 1070 "src/compiler/Generator.pv"
                            success = Generator__write_expression(self, file, arg->value, generics) && success;
                        } }

                        #line 1073 "src/compiler/Generator.pv"
                        fprintf(file, " }");
                    }

                    #line 1076 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 1078 "src/compiler/Generator.pv"
                default: {
                    #line 1079 "src/compiler/Generator.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 1080 "src/compiler/Generator.pv"
                    return false;
                } break;
            }
        } break;
        #line 1084 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 1087 "src/compiler/Generator.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 1088 "src/compiler/Generator.pv"
    return false;
}

#line 1091 "src/compiler/Generator.pv"
bool Generator__write_expression(struct Generator* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 1092 "src/compiler/Generator.pv"
    struct ExpressionData* data = &expression->data;

    #line 1094 "src/compiler/Generator.pv"
    switch (data->type) {
        #line 1095 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 1095 "src/compiler/Generator.pv"
            struct str name = data->variable_value;
            #line 1096 "src/compiler/Generator.pv"
            Generator__write_variable(self, file, name);
            #line 1097 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1099 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1099 "src/compiler/Generator.pv"
            struct str value = data->literal_value;
            #line 1100 "src/compiler/Generator.pv"
            Generator__write_literal(self, file, &expression->return_type, value);
            #line 1101 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1103 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1103 "src/compiler/Generator.pv"
            struct Expression* target = data->invoke_value._0;
            #line 1103 "src/compiler/Generator.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 1104 "src/compiler/Generator.pv"
            return Generator__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 1106 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 1106 "src/compiler/Generator.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 1107 "src/compiler/Generator.pv"
            return Generator__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 1109 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 1109 "src/compiler/Generator.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 1109 "src/compiler/Generator.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 1110 "src/compiler/Generator.pv"
            bool skip_operator = str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 1111 "src/compiler/Generator.pv"
            if (!skip_operator) {
                #line 1111 "src/compiler/Generator.pv"
                Generator__write_str(self, file, operator);
            }
            #line 1112 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, inner, generics);
            #line 1113 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1115 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 1115 "src/compiler/Generator.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 1115 "src/compiler/Generator.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 1115 "src/compiler/Generator.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 1116 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, left, generics);
            #line 1117 "src/compiler/Generator.pv"
            fprintf(file, " ");
            #line 1118 "src/compiler/Generator.pv"
            Generator__write_str(self, file, operator);
            #line 1119 "src/compiler/Generator.pv"
            fprintf(file, " ");
            #line 1120 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, right, generics);
            #line 1121 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1123 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 1123 "src/compiler/Generator.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 1123 "src/compiler/Generator.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 1124 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, parent, generics);
            #line 1125 "src/compiler/Generator.pv"
            Generator__write_static_member_accessor(self, file, generics);
            #line 1126 "src/compiler/Generator.pv"
            Generator__write_str(self, file, member);

            #line 1128 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1130 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1130 "src/compiler/Generator.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 1130 "src/compiler/Generator.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 1131 "src/compiler/Generator.pv"
            struct Type* parent_type = &parent->return_type;

            #line 1133 "src/compiler/Generator.pv"
            if (Generator__is_type_single_value_struct(self, parent_type, generics)) {
                #line 1134 "src/compiler/Generator.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 1135 "src/compiler/Generator.pv"
                if ((is_ref)) {
                    #line 1135 "src/compiler/Generator.pv"
                    fprintf(file, "(*");
                }
                #line 1136 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, parent, generics);
                #line 1137 "src/compiler/Generator.pv"
                if ((is_ref)) {
                    #line 1137 "src/compiler/Generator.pv"
                    fprintf(file, ")");
                }
                #line 1138 "src/compiler/Generator.pv"
                return true;
            }

            #line 1141 "src/compiler/Generator.pv"
            switch (parent_type->type) {
                #line 1142 "src/compiler/Generator.pv"
                case TYPE__SEQUENCE: {
                    #line 1142 "src/compiler/Generator.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 1143 "src/compiler/Generator.pv"
                    switch (sequence->type.type) {
                        #line 1144 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1144 "src/compiler/Generator.pv"
                            uintptr_t length = sequence->type.fixedarray_value;
                            #line 1145 "src/compiler/Generator.pv"
                            if (str__eq(member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 1146 "src/compiler/Generator.pv"
                                fprintf(file, "%zu", length);
                            } else {
                                #line 1148 "src/compiler/Generator.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 1149 "src/compiler/Generator.pv"
                                Generator__write_str(self, file, member);
                                #line 1150 "src/compiler/Generator.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 1153 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1154 "src/compiler/Generator.pv"
                            fprintf(file, "!!ERROR TODO MEMBERS FOR DYNAMIC SEQUENCES!!");
                        } break;
                    }
                } break;
                #line 1158 "src/compiler/Generator.pv"
                default: {
                    #line 1159 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, parent, generics);
                    #line 1160 "src/compiler/Generator.pv"
                    Generator__write_instance_member_accessor(self, file, &parent->return_type, generics);
                    #line 1161 "src/compiler/Generator.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 1161 "src/compiler/Generator.pv"
                        fprintf(file, "_");
                    }
                    #line 1162 "src/compiler/Generator.pv"
                    Generator__write_str(self, file, member);
                } break;
            }

            #line 1166 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1168 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1168 "src/compiler/Generator.pv"
            struct Type* type = data->type_value;
            #line 1169 "src/compiler/Generator.pv"
            Generator__write_type(self, file, type, generics);
            #line 1170 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1172 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1172 "src/compiler/Generator.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 1172 "src/compiler/Generator.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 1173 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, array_expr, generics);

            #line 1175 "src/compiler/Generator.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 1176 "src/compiler/Generator.pv"
                fprintf(file, ".data");
            }

            #line 1179 "src/compiler/Generator.pv"
            fprintf(file, "[");
            #line 1180 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, index_expr, generics);
            #line 1181 "src/compiler/Generator.pv"
            fprintf(file, "]");

            #line 1183 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1185 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1185 "src/compiler/Generator.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 1186 "src/compiler/Generator.pv"
            fprintf(file, "(");
            #line 1187 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, expr, generics);
            #line 1188 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 1190 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1192 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1192 "src/compiler/Generator.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 1193 "src/compiler/Generator.pv"
            switch (cpp_expression.type) {
                #line 1194 "src/compiler/Generator.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1194 "src/compiler/Generator.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 1194 "src/compiler/Generator.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 1195 "src/compiler/Generator.pv"
                    if (placement != 0) {
                        #line 1196 "src/compiler/Generator.pv"
                        fprintf(file, "new(");
                        #line 1197 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, placement, generics);
                        #line 1198 "src/compiler/Generator.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 1200 "src/compiler/Generator.pv"
                        fprintf(file, "new ");
                    }

                    #line 1203 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, new_expression, generics);
                } break;
                #line 1205 "src/compiler/Generator.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1205 "src/compiler/Generator.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1206 "src/compiler/Generator.pv"
                    fprintf(file, "delete ");
                    #line 1207 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, delete_expression, generics);
                } break;
            }

            #line 1211 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1213 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1213 "src/compiler/Generator.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 1214 "src/compiler/Generator.pv"
            switch (expression->return_type.type) {
                #line 1215 "src/compiler/Generator.pv"
                case TYPE__STRUCT: {
                    #line 1215 "src/compiler/Generator.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1216 "src/compiler/Generator.pv"
                    if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1217 "src/compiler/Generator.pv"
                        Generator__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 1220 "src/compiler/Generator.pv"
                case TYPE__INDIRECT: {
                    #line 1220 "src/compiler/Generator.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 1221 "src/compiler/Generator.pv"
                    switch (indirect->to.type) {
                        #line 1222 "src/compiler/Generator.pv"
                        case TYPE__STRUCT: {
                            #line 1222 "src/compiler/Generator.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 1223 "src/compiler/Generator.pv"
                            if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 1224 "src/compiler/Generator.pv"
                                Generator__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 1226 "src/compiler/Generator.pv"
                                Generator__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 1229 "src/compiler/Generator.pv"
                        case TYPE__SEQUENCE: {
                            #line 1229 "src/compiler/Generator.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 1229 "src/compiler/Generator.pv"
                            Generator__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 1230 "src/compiler/Generator.pv"
                        default: {
                            #line 1230 "src/compiler/Generator.pv"
                            Generator__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 1233 "src/compiler/Generator.pv"
                default: {
                    #line 1233 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 1238 "src/compiler/Generator.pv"
    return 0;
}

#line 1241 "src/compiler/Generator.pv"
bool Generator__write_defer_statements(struct Generator* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics) {
    #line 1242 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_DeferStatement __iter = Array_DeferStatement__iter(defer_statements);
    #line 1242 "src/compiler/Generator.pv"
    while (ArrayIter_ref_DeferStatement__next(&__iter)) {
        #line 1242 "src/compiler/Generator.pv"
        struct DeferStatement* defer_info = ArrayIter_ref_DeferStatement__value(&__iter);

        #line 1243 "src/compiler/Generator.pv"
        switch (defer_info->type) {
            #line 1244 "src/compiler/Generator.pv"
            case DEFER_STATEMENT__EXPRESSION: {
                #line 1244 "src/compiler/Generator.pv"
                struct Expression* expression = defer_info->expression_value;
                #line 1245 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1246 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);
                #line 1247 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1249 "src/compiler/Generator.pv"
            case DEFER_STATEMENT__BLOCK: {
                #line 1249 "src/compiler/Generator.pv"
                struct Block* block = defer_info->block_value;
                #line 1250 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1251 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, false, false);
                #line 1252 "src/compiler/Generator.pv"
                Generator__write_block(self, file, return_type, block, generics, 0, 0);
                #line 1253 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);
            } break;
        }
    } }

    #line 1258 "src/compiler/Generator.pv"
    return true;
}

#line 1261 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self) {
    #line 1262 "src/compiler/Generator.pv"
    return self->function_context->func_info->type == FUNCTION_TYPE__COROUTINE;
}

#line 1265 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name) {
    #line 1266 "src/compiler/Generator.pv"
    name = FunctionContext__get_variable_replacement(self->function_context, name);
    #line 1267 "src/compiler/Generator.pv"
    Generator__write_str(self, file, name);
}

#line 1270 "src/compiler/Generator.pv"
bool Generator__write_block(struct Generator* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets) {
    #line 1271 "src/compiler/Generator.pv"
    if (block == 0) {
        #line 1272 "src/compiler/Generator.pv"
        fprintf(file, "{}\n");
        #line 1273 "src/compiler/Generator.pv"
        return 0;
    }

    #line 1276 "src/compiler/Generator.pv"
    if (no_brackets == 0) {
        #line 1277 "src/compiler/Generator.pv"
        fprintf(file, "{\n");
        #line 1278 "src/compiler/Generator.pv"
        self->indent += 1;
    }

    #line 1281 "src/compiler/Generator.pv"
    if (block->is_top_level_and_has_defer_statements_inside && !Type__is_void(return_type)) {
        #line 1282 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 1283 "src/compiler/Generator.pv"
        Generator__write_type(self, file, return_type, generics);
        #line 1284 "src/compiler/Generator.pv"
        fprintf(file, " __result;\n\n");
    }

    #line 1287 "src/compiler/Generator.pv"
    bool last_statement_is_return = false;

    #line 1289 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 1289 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Statement__next(&__iter)) {
        #line 1289 "src/compiler/Generator.pv"
        struct Statement* statement = ArrayIter_ref_Statement__value(&__iter);

        #line 1290 "src/compiler/Generator.pv"
        if (statement > block->statements.data) {
            #line 1291 "src/compiler/Generator.pv"
            struct Statement* prev_statement = statement - 1;

            #line 1293 "src/compiler/Generator.pv"
            if (prev_statement->last_token->end_line < statement->first_token->start_line - 1) {
                #line 1294 "src/compiler/Generator.pv"
                fprintf(file, "\n");
            }
        }

        #line 1298 "src/compiler/Generator.pv"
        Generator__write_line_directive(self, file, block->context, statement->first_token);

        #line 1300 "src/compiler/Generator.pv"
        last_statement_is_return = false;

        #line 1302 "src/compiler/Generator.pv"
        switch (statement->data.type) {
            #line 1303 "src/compiler/Generator.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 1303 "src/compiler/Generator.pv"
                struct Block* child_block = statement->data.blockstatement_value;
                #line 1304 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1305 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, false, false);
                #line 1306 "src/compiler/Generator.pv"
                if (Generator__write_block(self, file, return_type, child_block, generics, 0, 0) == 0) {
                    #line 1307 "src/compiler/Generator.pv"
                    return 0;
                }
                #line 1309 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);
            } break;
            #line 1311 "src/compiler/Generator.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 1311 "src/compiler/Generator.pv"
                struct LetStatement* let_statement = statement->data.letstatement_value;
                #line 1312 "src/compiler/Generator.pv"
                struct Token* name = let_statement->name;
                #line 1313 "src/compiler/Generator.pv"
                struct Type* type = let_statement->type;
                #line 1314 "src/compiler/Generator.pv"
                struct Expression* value = let_statement->value;

                #line 1316 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);

                #line 1318 "src/compiler/Generator.pv"
                if (!let_statement->is_static) {
                    #line 1319 "src/compiler/Generator.pv"
                    FunctionContext__add_variable(self->function_context, name->value, type);
                }

                #line 1322 "src/compiler/Generator.pv"
                if (let_statement->is_static) {
                    #line 1323 "src/compiler/Generator.pv"
                    fprintf(file, "static ");
                }

                #line 1326 "src/compiler/Generator.pv"
                if (Generator__is_coroutine(self)) {
                    #line 1327 "src/compiler/Generator.pv"
                    Generator__write_variable(self, file, name->value);
                } else {
                    #line 1329 "src/compiler/Generator.pv"
                    Generator__write_variable_decl(self, file, name->value, type, generics);
                }

                #line 1332 "src/compiler/Generator.pv"
                if (value != 0) {
                    #line 1333 "src/compiler/Generator.pv"
                    fprintf(file, " = ");
                    #line 1334 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, value, generics);
                }

                #line 1337 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1340 "src/compiler/Generator.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 1340 "src/compiler/Generator.pv"
                struct Expression* value = statement->data.yieldstatement_value;
                #line 1341 "src/compiler/Generator.pv"
                self->function_context->coroutine.yield_count += 1;

                #line 1343 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1344 "src/compiler/Generator.pv"
                uintptr_t yield_number = self->function_context->coroutine.yield_count;
                #line 1345 "src/compiler/Generator.pv"
                fprintf(file, "ctx->_value = ");
                #line 1346 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, value, generics);
                #line 1347 "src/compiler/Generator.pv"
                fprintf(file, "; ctx->_state = %zu; return true; yield_%zu:\n", yield_number, yield_number);
            } break;
            #line 1349 "src/compiler/Generator.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 1349 "src/compiler/Generator.pv"
                struct Expression* value = statement->data.returnstatement_value._0;
                #line 1349 "src/compiler/Generator.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.returnstatement_value._1;
                #line 1350 "src/compiler/Generator.pv"
                if (value == 0) {
                    #line 1351 "src/compiler/Generator.pv"
                    Generator__write_defer_statements(self, file, return_type, defer_statements, generics);
                    #line 1352 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1353 "src/compiler/Generator.pv"
                    fprintf(file, "return;\n");
                } else if (defer_statements->length > 0) {
                    #line 1355 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1356 "src/compiler/Generator.pv"
                    fprintf(file, "__result = ");
                    #line 1357 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, value, generics);
                    #line 1358 "src/compiler/Generator.pv"
                    fprintf(file, ";\n");

                    #line 1360 "src/compiler/Generator.pv"
                    Generator__write_defer_statements(self, file, return_type, defer_statements, generics);

                    #line 1362 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1363 "src/compiler/Generator.pv"
                    fprintf(file, "return __result;\n");
                } else {
                    #line 1365 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1366 "src/compiler/Generator.pv"
                    fprintf(file, "return ");
                    #line 1367 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, value, generics);
                    #line 1368 "src/compiler/Generator.pv"
                    fprintf(file, ";\n");
                }

                #line 1371 "src/compiler/Generator.pv"
                last_statement_is_return = true;
            } break;
            #line 1373 "src/compiler/Generator.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 1373 "src/compiler/Generator.pv"
                struct Expression* expression = statement->data.ifstatement_value._0;
                #line 1373 "src/compiler/Generator.pv"
                struct Block* if_block = statement->data.ifstatement_value._1;
                #line 1373 "src/compiler/Generator.pv"
                struct Array_ElseStatement* else_statements = &statement->data.ifstatement_value._2;
                #line 1374 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1375 "src/compiler/Generator.pv"
                fprintf(file, "if (");
                #line 1376 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);
                #line 1377 "src/compiler/Generator.pv"
                fprintf(file, ") ");
                #line 1378 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, false, false);
                #line 1379 "src/compiler/Generator.pv"
                if (Generator__write_block(self, file, return_type, if_block, generics, 1, 0) == 0) {
                    #line 1379 "src/compiler/Generator.pv"
                    return 0;
                }
                #line 1380 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);

                #line 1382 "src/compiler/Generator.pv"
                { struct ArrayIter_ref_ElseStatement __iter = Array_ElseStatement__iter(else_statements);
                #line 1382 "src/compiler/Generator.pv"
                while (ArrayIter_ref_ElseStatement__next(&__iter)) {
                    #line 1382 "src/compiler/Generator.pv"
                    struct ElseStatement* else_statement = ArrayIter_ref_ElseStatement__value(&__iter);

                    #line 1383 "src/compiler/Generator.pv"
                    fprintf(file, " else ");

                    #line 1385 "src/compiler/Generator.pv"
                    if (else_statement->expression != 0) {
                        #line 1386 "src/compiler/Generator.pv"
                        fprintf(file, "if (");
                        #line 1387 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, else_statement->expression, generics);
                        #line 1388 "src/compiler/Generator.pv"
                        fprintf(file, ") ");
                    }

                    #line 1391 "src/compiler/Generator.pv"
                    FunctionContext__push_scope(self->function_context, false, false);
                    #line 1392 "src/compiler/Generator.pv"
                    if (Generator__write_block(self, file, return_type, else_statement->block, generics, 1, 0) == 0) {
                        #line 1392 "src/compiler/Generator.pv"
                        return 0;
                    }
                    #line 1393 "src/compiler/Generator.pv"
                    FunctionContext__pop_scope(self->function_context);
                } }

                #line 1396 "src/compiler/Generator.pv"
                fprintf(file, "\n");
            } break;
            #line 1398 "src/compiler/Generator.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 1398 "src/compiler/Generator.pv"
                struct Expression* expression = statement->data.matchstatement_value._0;
                #line 1398 "src/compiler/Generator.pv"
                struct Array_MatchCase* cases = &statement->data.matchstatement_value._1;
                #line 1399 "src/compiler/Generator.pv"
                struct Type* return_type = &expression->return_type;
                #line 1400 "src/compiler/Generator.pv"
                bool is_discriminated_union = Generator__type_is_discriminated_union(self, return_type, generics);

                #line 1402 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1403 "src/compiler/Generator.pv"
                fprintf(file, "switch (");

                #line 1405 "src/compiler/Generator.pv"
                if (is_discriminated_union == 0) {
                    #line 1406 "src/compiler/Generator.pv"
                    Generator__write_deref_if_needed(self, file, return_type, generics);
                }

                #line 1409 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);

                #line 1411 "src/compiler/Generator.pv"
                if (is_discriminated_union) {
                    #line 1412 "src/compiler/Generator.pv"
                    Generator__write_instance_member_accessor(self, file, return_type, generics);
                    #line 1413 "src/compiler/Generator.pv"
                    fprintf(file, "type");
                }

                #line 1416 "src/compiler/Generator.pv"
                fprintf(file, ") {\n");
                #line 1417 "src/compiler/Generator.pv"
                self->indent += 1;

                #line 1419 "src/compiler/Generator.pv"
                { struct ArrayIter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 1419 "src/compiler/Generator.pv"
                while (ArrayIter_ref_MatchCase__next(&__iter)) {
                    #line 1419 "src/compiler/Generator.pv"
                    struct MatchCase* case_info = ArrayIter_ref_MatchCase__value(&__iter);

                    #line 1420 "src/compiler/Generator.pv"
                    Generator__write_line_directive(self, file, block->context, case_info->first_token);

                    #line 1422 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);

                    #line 1424 "src/compiler/Generator.pv"
                    struct MatchPattern* pattern = &case_info->pattern;

                    #line 1426 "src/compiler/Generator.pv"
                    switch (pattern->type) {
                        #line 1427 "src/compiler/Generator.pv"
                        case MATCH_PATTERN__ENUM_CVALUE: {
                            #line 1427 "src/compiler/Generator.pv"
                            struct Token* name = pattern->enumcvalue_value;
                            #line 1428 "src/compiler/Generator.pv"
                            fprintf(file, "case ");
                            #line 1429 "src/compiler/Generator.pv"
                            Generator__write_token(self, file, name);
                            #line 1430 "src/compiler/Generator.pv"
                            fprintf(file, ": {\n");
                            #line 1431 "src/compiler/Generator.pv"
                            self->indent += 1;
                        } break;
                        #line 1433 "src/compiler/Generator.pv"
                        case MATCH_PATTERN__ENUM_VARIANT: {
                            #line 1433 "src/compiler/Generator.pv"
                            struct EnumVariant* enum_variant = pattern->enumvariant_value._0;
                            #line 1433 "src/compiler/Generator.pv"
                            struct Array_EnumVariantParameter* parameters = &pattern->enumvariant_value._1;
                            #line 1434 "src/compiler/Generator.pv"
                            fprintf(file, "case ");
                            #line 1435 "src/compiler/Generator.pv"
                            Generator__write_enum_variant_name(self, file, generics->self_type, enum_variant);
                            #line 1436 "src/compiler/Generator.pv"
                            fprintf(file, ": {\n");
                            #line 1437 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 1439 "src/compiler/Generator.pv"
                            struct Array_Type* types = &enum_variant->types;

                            #line 1441 "src/compiler/Generator.pv"
                            uintptr_t param_i = 0;
                            #line 1442 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_EnumVariantParameter __iter = Array_EnumVariantParameter__iter(parameters);
                            #line 1442 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_EnumVariantParameter__next(&__iter)) {
                                #line 1442 "src/compiler/Generator.pv"
                                struct EnumVariantParameter* param_iter = ArrayIter_ref_EnumVariantParameter__value(&__iter);

                                #line 1443 "src/compiler/Generator.pv"
                                if (Token__eq(param_iter->variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                                    #line 1444 "src/compiler/Generator.pv"
                                    param_i += 1;
                                    #line 1445 "src/compiler/Generator.pv"
                                    continue;
                                }

                                #line 1448 "src/compiler/Generator.pv"
                                struct Type* param_type = types->data + param_i;
                                #line 1449 "src/compiler/Generator.pv"
                                struct Expression* variable_expression = expression;
                                #line 1450 "src/compiler/Generator.pv"
                                struct String accessor = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

                                #line 1452 "src/compiler/Generator.pv"
                                String__append_str_lowercase(&accessor, enum_variant->name->value);
                                #line 1453 "src/compiler/Generator.pv"
                                String__append(&accessor, (struct str){ .ptr = "_value", .length = strlen("_value") });

                                #line 1455 "src/compiler/Generator.pv"
                                if (types->length > 1) {
                                    #line 1456 "src/compiler/Generator.pv"
                                    String__append(&accessor, (struct str){ .ptr = "._", .length = strlen("._") });
                                    #line 1457 "src/compiler/Generator.pv"
                                    String__append_usize(&accessor, param_i);
                                }

                                #line 1460 "src/compiler/Generator.pv"
                                variable_expression = Expression__make(self->allocator, param_iter->variable, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = variable_expression, ._1 = String__as_str(&accessor)} }, param_type);

                                #line 1462 "src/compiler/Generator.pv"
                                struct Token* name = param_iter->variable;

                                #line 1464 "src/compiler/Generator.pv"
                                Generator__write_line_directive(self, file, block->context, name);

                                #line 1466 "src/compiler/Generator.pv"
                                Generator__write_indent(self, file);
                                #line 1467 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, param_type, generics);
                                #line 1468 "src/compiler/Generator.pv"
                                if (param_iter->ref) {
                                    #line 1468 "src/compiler/Generator.pv"
                                    fprintf(file, "*");
                                }

                                #line 1470 "src/compiler/Generator.pv"
                                fprintf(file, " ");

                                #line 1472 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, name);
                                #line 1473 "src/compiler/Generator.pv"
                                fprintf(file, " = ");

                                #line 1475 "src/compiler/Generator.pv"
                                if (param_iter->ref) {
                                    #line 1475 "src/compiler/Generator.pv"
                                    fprintf(file, "&");
                                }
                                #line 1476 "src/compiler/Generator.pv"
                                Generator__write_expression(self, file, variable_expression, generics);

                                #line 1478 "src/compiler/Generator.pv"
                                fprintf(file, ";\n");

                                #line 1480 "src/compiler/Generator.pv"
                                param_i += 1;
                            } }
                        } break;
                        #line 1483 "src/compiler/Generator.pv"
                        case MATCH_PATTERN__DEFAULT: {
                            #line 1484 "src/compiler/Generator.pv"
                            fprintf(file, "default: {\n");
                            #line 1485 "src/compiler/Generator.pv"
                            self->indent += 1;
                        } break;
                    }

                    #line 1489 "src/compiler/Generator.pv"
                    FunctionContext__push_scope(self->function_context, true, false);
                    #line 1490 "src/compiler/Generator.pv"
                    if (Generator__write_block(self, file, return_type, case_info->body, generics, 1, 1) == 0) {
                        #line 1490 "src/compiler/Generator.pv"
                        return 0;
                    }
                    #line 1491 "src/compiler/Generator.pv"
                    FunctionContext__pop_scope(self->function_context);

                    #line 1493 "src/compiler/Generator.pv"
                    self->indent -= 1;
                    #line 1494 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1495 "src/compiler/Generator.pv"
                    fprintf(file, "} break;\n");
                } }

                #line 1498 "src/compiler/Generator.pv"
                self->indent -= 1;
                #line 1499 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1500 "src/compiler/Generator.pv"
                fprintf(file, "}\n");
            } break;
            #line 1502 "src/compiler/Generator.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 1502 "src/compiler/Generator.pv"
                struct Expression* expression = statement->data.whilestatement_value._0;
                #line 1502 "src/compiler/Generator.pv"
                struct Block* while_block = statement->data.whilestatement_value._1;
                #line 1503 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1504 "src/compiler/Generator.pv"
                fprintf(file, "while (");
                #line 1505 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);
                #line 1506 "src/compiler/Generator.pv"
                fprintf(file, ") ");
                #line 1507 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, true, true);
                #line 1508 "src/compiler/Generator.pv"
                if (Generator__write_block(self, file, return_type, while_block, generics, 0, 0) == 0) {
                    #line 1508 "src/compiler/Generator.pv"
                    return 0;
                }
                #line 1509 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);
            } break;
            #line 1511 "src/compiler/Generator.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 1511 "src/compiler/Generator.pv"
                struct ForStatement* for_statement = statement->data.forstatement_value;
                #line 1512 "src/compiler/Generator.pv"
                bool is_iterator = false;

                #line 1514 "src/compiler/Generator.pv"
                switch (for_statement->type.type) {
                    #line 1515 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 1515 "src/compiler/Generator.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 1515 "src/compiler/Generator.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 1516 "src/compiler/Generator.pv"
                        is_iterator = true;
                        #line 1517 "src/compiler/Generator.pv"
                        struct ForVariable* variable = &for_statement->variables.data[0];
                        #line 1518 "src/compiler/Generator.pv"
                        struct str variable_name = variable->name->value;

                        #line 1520 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 1521 "src/compiler/Generator.pv"
                        fprintf(file, "for (");

                        #line 1523 "src/compiler/Generator.pv"
                        FunctionContext__add_variable(self->function_context, variable_name, variable->type);

                        #line 1525 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 1526 "src/compiler/Generator.pv"
                            Generator__write_variable(self, file, variable_name);
                        } else {
                            #line 1528 "src/compiler/Generator.pv"
                            Generator__write_variable_decl(self, file, variable_name, variable->type, generics);
                        }

                        #line 1531 "src/compiler/Generator.pv"
                        fprintf(file, " = ");
                        #line 1532 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, start, generics);
                        #line 1533 "src/compiler/Generator.pv"
                        fprintf(file, "; ");
                        #line 1534 "src/compiler/Generator.pv"
                        Generator__write_variable(self, file, variable_name);
                        #line 1535 "src/compiler/Generator.pv"
                        fprintf(file, " < ");
                        #line 1536 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, end, generics);
                        #line 1537 "src/compiler/Generator.pv"
                        fprintf(file, "; ");
                        #line 1538 "src/compiler/Generator.pv"
                        Generator__write_variable(self, file, variable_name);
                        #line 1539 "src/compiler/Generator.pv"
                        fprintf(file, "++) {");
                        #line 1540 "src/compiler/Generator.pv"
                        self->indent += 1;
                    } break;
                    #line 1542 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 1542 "src/compiler/Generator.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 1543 "src/compiler/Generator.pv"
                        is_iterator = Type__is_iterator(Type__deref(for_statement->iter_type));
                        #line 1544 "src/compiler/Generator.pv"
                        if (is_iterator) {
                            #line 1545 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 1546 "src/compiler/Generator.pv"
                            fprintf(file, "while (");
                            #line 1547 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, iter_expression, generics);
                            #line 1548 "src/compiler/Generator.pv"
                            fprintf(file, ".vtable->next(");
                            #line 1549 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, iter_expression, generics);
                            #line 1550 "src/compiler/Generator.pv"
                            fprintf(file, ".instance)) {");

                            #line 1552 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 1554 "src/compiler/Generator.pv"
                            uintptr_t i = 0;
                            #line 1555 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 1555 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_ForVariable__next(&__iter)) {
                                #line 1555 "src/compiler/Generator.pv"
                                struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

                                #line 1556 "src/compiler/Generator.pv"
                                if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 1557 "src/compiler/Generator.pv"
                                    Generator__write_line_directive(self, file, block->context, variable->name);

                                    #line 1559 "src/compiler/Generator.pv"
                                    Generator__write_indent(self, file);
                                    #line 1560 "src/compiler/Generator.pv"
                                    Generator__write_type(self, file, variable->type, generics);
                                    #line 1561 "src/compiler/Generator.pv"
                                    fprintf(file, " ");
                                    #line 1562 "src/compiler/Generator.pv"
                                    Generator__write_token(self, file, variable->name);
                                    #line 1563 "src/compiler/Generator.pv"
                                    fprintf(file, " = ");
                                    #line 1564 "src/compiler/Generator.pv"
                                    if (variable->ref) {
                                        #line 1564 "src/compiler/Generator.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 1565 "src/compiler/Generator.pv"
                                    if (variable->deref) {
                                        #line 1565 "src/compiler/Generator.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 1566 "src/compiler/Generator.pv"
                                    Generator__write_expression(self, file, iter_expression, generics);
                                    #line 1567 "src/compiler/Generator.pv"
                                    fprintf(file, ".vtable->value");
                                    #line 1568 "src/compiler/Generator.pv"
                                    if (for_statement->variables.length > 1) {
                                        #line 1568 "src/compiler/Generator.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 1569 "src/compiler/Generator.pv"
                                    fprintf(file, "(");
                                    #line 1570 "src/compiler/Generator.pv"
                                    Generator__write_expression(self, file, iter_expression, generics);
                                    #line 1571 "src/compiler/Generator.pv"
                                    fprintf(file, ".instance);\n");
                                }

                                #line 1574 "src/compiler/Generator.pv"
                                i += 1;
                            } }
                        } else {
                            #line 1577 "src/compiler/Generator.pv"
                            struct String iter_type_name = Naming__get_type_name(&self->naming_ident, for_statement->iter_type, generics->self_type, generics);

                            #line 1579 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 1580 "src/compiler/Generator.pv"
                            fprintf(file, "{ ");
                            #line 1581 "src/compiler/Generator.pv"
                            Generator__write_type(self, file, for_statement->iter_type, generics);
                            #line 1582 "src/compiler/Generator.pv"
                            fprintf(file, " __iter = ");
                            #line 1583 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, iter_expression, generics);
                            #line 1584 "src/compiler/Generator.pv"
                            fprintf(file, ";\n");

                            #line 1586 "src/compiler/Generator.pv"
                            Generator__write_line_directive(self, file, block->context, iter_expression->token);

                            #line 1588 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 1589 "src/compiler/Generator.pv"
                            fprintf(file, "while (");
                            #line 1590 "src/compiler/Generator.pv"
                            Generator__write_string(self, file, &iter_type_name);
                            #line 1591 "src/compiler/Generator.pv"
                            fprintf(file, "__next(&__iter)) {\n");

                            #line 1593 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 1595 "src/compiler/Generator.pv"
                            uintptr_t i = 0;
                            #line 1596 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 1596 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_ForVariable__next(&__iter)) {
                                #line 1596 "src/compiler/Generator.pv"
                                struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

                                #line 1597 "src/compiler/Generator.pv"
                                if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 1598 "src/compiler/Generator.pv"
                                    Generator__write_line_directive(self, file, block->context, variable->name);

                                    #line 1600 "src/compiler/Generator.pv"
                                    Generator__write_indent(self, file);
                                    #line 1601 "src/compiler/Generator.pv"
                                    Generator__write_type(self, file, variable->type, generics);
                                    #line 1602 "src/compiler/Generator.pv"
                                    fprintf(file, " ");
                                    #line 1603 "src/compiler/Generator.pv"
                                    Generator__write_token(self, file, variable->name);
                                    #line 1604 "src/compiler/Generator.pv"
                                    fprintf(file, " = ");
                                    #line 1605 "src/compiler/Generator.pv"
                                    if (variable->ref) {
                                        #line 1605 "src/compiler/Generator.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 1606 "src/compiler/Generator.pv"
                                    if (variable->deref) {
                                        #line 1606 "src/compiler/Generator.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 1607 "src/compiler/Generator.pv"
                                    Generator__write_string(self, file, &iter_type_name);
                                    #line 1608 "src/compiler/Generator.pv"
                                    fprintf(file, "__value");
                                    #line 1609 "src/compiler/Generator.pv"
                                    if (!Type__is_tuple(Type__deref(for_statement->value_type)) && for_statement->variables.length > 1) {
                                        #line 1610 "src/compiler/Generator.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 1612 "src/compiler/Generator.pv"
                                    fprintf(file, "(&__iter)");

                                    #line 1614 "src/compiler/Generator.pv"
                                    if (Type__is_tuple(Type__deref(for_statement->value_type)) && for_statement->variables.length > 1) {
                                        #line 1615 "src/compiler/Generator.pv"
                                        Generator__write_instance_member_accessor(self, file, for_statement->value_type, generics);
                                        #line 1616 "src/compiler/Generator.pv"
                                        fprintf(file, "_%zu", i);
                                    }

                                    #line 1619 "src/compiler/Generator.pv"
                                    fprintf(file, ";\n");
                                }

                                #line 1622 "src/compiler/Generator.pv"
                                i += 1;
                            } }
                        }
                    } break;
                }

                #line 1628 "src/compiler/Generator.pv"
                fprintf(file, "\n");

                #line 1630 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, true, true);
                #line 1631 "src/compiler/Generator.pv"
                if (Generator__write_block(self, file, return_type, for_statement->block, generics, 0, 1) == 0) {
                    #line 1631 "src/compiler/Generator.pv"
                    return 0;
                }
                #line 1632 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);

                #line 1634 "src/compiler/Generator.pv"
                self->indent -= 1;
                #line 1635 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1636 "src/compiler/Generator.pv"
                if (is_iterator) {
                    #line 1637 "src/compiler/Generator.pv"
                    fprintf(file, "}\n");
                } else {
                    #line 1639 "src/compiler/Generator.pv"
                    fprintf(file, "} }\n");
                }
            } break;
            #line 1642 "src/compiler/Generator.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 1642 "src/compiler/Generator.pv"
                struct Expression* left = statement->data.assignmentstatement_value._0;
                #line 1642 "src/compiler/Generator.pv"
                struct Token* operator = statement->data.assignmentstatement_value._1;
                #line 1642 "src/compiler/Generator.pv"
                struct Expression* right = statement->data.assignmentstatement_value._2;
                #line 1643 "src/compiler/Generator.pv"
                struct Token* op = operator;

                #line 1645 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1646 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, left, generics);
                #line 1647 "src/compiler/Generator.pv"
                fprintf(file, " ");
                #line 1648 "src/compiler/Generator.pv"
                Generator__write_str(self, file, op->value);
                #line 1649 "src/compiler/Generator.pv"
                fprintf(file, " ");
                #line 1650 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, right, generics);
                #line 1651 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1653 "src/compiler/Generator.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 1653 "src/compiler/Generator.pv"
                struct Expression* expr = statement->data.expressionstatement_value;
                #line 1654 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1655 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expr, generics);
                #line 1656 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1658 "src/compiler/Generator.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
                #line 1658 "src/compiler/Generator.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.continuestatement_value;
                #line 1659 "src/compiler/Generator.pv"
                Generator__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 1660 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1661 "src/compiler/Generator.pv"
                fprintf(file, "continue;\n");
            } break;
            #line 1663 "src/compiler/Generator.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
                #line 1663 "src/compiler/Generator.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.breakstatement_value;
                #line 1664 "src/compiler/Generator.pv"
                Generator__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 1665 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1666 "src/compiler/Generator.pv"
                fprintf(file, "break;\n");
            } break;
        }
    } }

    #line 1671 "src/compiler/Generator.pv"
    if (!last_statement_is_return) {
        #line 1672 "src/compiler/Generator.pv"
        Generator__write_defer_statements(self, file, return_type, &block->defer_statements, generics);
    }

    #line 1675 "src/compiler/Generator.pv"
    if (no_brackets == 0) {
        #line 1676 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 1677 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);

        #line 1679 "src/compiler/Generator.pv"
        if ((inline_)) {
            #line 1680 "src/compiler/Generator.pv"
            fprintf(file, "}");
        } else {
            #line 1682 "src/compiler/Generator.pv"
            fprintf(file, "}\n");
        }
    }

    #line 1686 "src/compiler/Generator.pv"
    return true;
}

#line 1689 "src/compiler/Generator.pv"
bool Generator__add_primitive_type_include(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct str name) {
    #line 1690 "src/compiler/Generator.pv"
    struct str* include = HashMap_str_str__find(&self->primitive_includes, &name);
    #line 1691 "src/compiler/Generator.pv"
    if (include == 0) {
        #line 1691 "src/compiler/Generator.pv"
        return false;
    }

    #line 1693 "src/compiler/Generator.pv"
    struct String include_string = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 1694 "src/compiler/Generator.pv"
    String__append(&include_string, *include);

    #line 1696 "src/compiler/Generator.pv"
    HashMap_str_GeneratorInclude__insert(includes, *include, (struct GeneratorInclude) { .type = 0, .name = String__as_str(&include_string) });

    #line 1698 "src/compiler/Generator.pv"
    return true;
}

#line 1701 "src/compiler/Generator.pv"
bool Generator__add_type_include_inner(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct HashMap_str_GeneratorInclude* includes_primitives, struct Type* type, struct GenericMap* generics) {
    #line 1702 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, type, generics->array.data, generics);
    #line 1703 "src/compiler/Generator.pv"
    struct str name_str = String__as_str(&name);

    #line 1705 "src/compiler/Generator.pv"
    if (HashMap_str_GeneratorInclude__find(includes, &name_str) == 0) {
        #line 1706 "src/compiler/Generator.pv"
        HashMap_str_GeneratorInclude__insert(includes, name_str, (struct GeneratorInclude) { .type = type, .name = name_str });
    }

    #line 1709 "src/compiler/Generator.pv"
    return true;
}

#line 1712 "src/compiler/Generator.pv"
bool Generator__add_type_include(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct HashMap_str_GeneratorInclude* includes_primitives, struct Type* type, struct GenericMap* generics) {
    #line 1713 "src/compiler/Generator.pv"
    if (type == 0) {
        #line 1713 "src/compiler/Generator.pv"
        return true;
    }

    #line 1715 "src/compiler/Generator.pv"
    struct Array_Type* children = 0;

    #line 1717 "src/compiler/Generator.pv"
    if (Type__is_fat_pointer(type)) {
        #line 1718 "src/compiler/Generator.pv"
        return Generator__add_type_include(self, includes, refs, includes_primitives, Type__deref_1(type), generics);
    }

    #line 1721 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 1722 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 1722 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 1723 "src/compiler/Generator.pv"
            if (refs != 0) {
                #line 1724 "src/compiler/Generator.pv"
                return Generator__add_type_include(self, refs, 0, includes_primitives, &indirect->to, generics);
            }

            #line 1727 "src/compiler/Generator.pv"
            return Generator__add_type_include(self, includes, refs, includes_primitives, &indirect->to, generics);
        } break;
        #line 1729 "src/compiler/Generator.pv"
        case TYPE__SEQUENCE: {
            #line 1729 "src/compiler/Generator.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 1730 "src/compiler/Generator.pv"
            if (Sequence__is_fixed_array(sequence)) {
                #line 1731 "src/compiler/Generator.pv"
                return Generator__add_type_include(self, includes, refs, includes_primitives, &sequence->element, generics);
            }
        } break;
        #line 1734 "src/compiler/Generator.pv"
        case TYPE__TUPLE: {
            #line 1734 "src/compiler/Generator.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 1735 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&tuple->elements);
            #line 1735 "src/compiler/Generator.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 1735 "src/compiler/Generator.pv"
                struct Type* element = ArrayIter_ref_Type__value(&__iter);

                #line 1736 "src/compiler/Generator.pv"
                Generator__add_type_include(self, includes, refs, includes_primitives, element, generics);
            } }
        } break;
        #line 1739 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 1739 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 1740 "src/compiler/Generator.pv"
            if (primitive_info != 0) {
                #line 1741 "src/compiler/Generator.pv"
                struct str name = primitive_info->name;
                #line 1742 "src/compiler/Generator.pv"
                return Generator__add_primitive_type_include(self, includes_primitives, name);
            }

            #line 1745 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1747 "src/compiler/Generator.pv"
        case TYPE__FUNCTION: {
            #line 1747 "src/compiler/Generator.pv"
            struct Function* func_info = type->function_value._0;
            #line 1747 "src/compiler/Generator.pv"
            struct GenericMap* child_types = type->function_value._1;
            #line 1748 "src/compiler/Generator.pv"
            if (func_info->type == FUNCTION_TYPE__METHOD_CPP) {
                #line 1748 "src/compiler/Generator.pv"
                return true;
            }

            #line 1750 "src/compiler/Generator.pv"
            struct GenericMap resolved_generics = GenericMap__resolve_types(child_types, self->allocator, generics);

            #line 1752 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
            #line 1752 "src/compiler/Generator.pv"
            while (ArrayIter_ref_Parameter__next(&__iter)) {
                #line 1752 "src/compiler/Generator.pv"
                struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                #line 1753 "src/compiler/Generator.pv"
                Generator__add_type_include(self, includes, refs, includes_primitives, &param->type, &resolved_generics);
            } }

            #line 1756 "src/compiler/Generator.pv"
            Generator__add_type_include(self, includes, refs, includes_primitives, &func_info->return_type, &resolved_generics);

            #line 1758 "src/compiler/Generator.pv"
            if (func_info->type == FUNCTION_TYPE__BUILTIN || func_info->name == 0) {
                #line 1758 "src/compiler/Generator.pv"
                return true;
            }

            #line 1760 "src/compiler/Generator.pv"
            switch (func_info->parent.type) {
                #line 1761 "src/compiler/Generator.pv"
                case FUNCTION_PARENT__NONE: {
                    #line 1762 "src/compiler/Generator.pv"
                    children = &child_types->array;
                } break;
                #line 1764 "src/compiler/Generator.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 1765 "src/compiler/Generator.pv"
                    return true;
                } break;
                #line 1767 "src/compiler/Generator.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 1767 "src/compiler/Generator.pv"
                    return true;
                } break;
                #line 1768 "src/compiler/Generator.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 1768 "src/compiler/Generator.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 1769 "src/compiler/Generator.pv"
                    if (child_types->array.length == 0) {
                        #line 1770 "src/compiler/Generator.pv"
                        struct Type* parent_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} });
                        #line 1771 "src/compiler/Generator.pv"
                        return Generator__add_type_include(self, includes, refs, includes_primitives, parent_type, generics);
                    } else {
                        #line 1773 "src/compiler/Generator.pv"
                        struct Type* parent_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = child_types} });
                        #line 1774 "src/compiler/Generator.pv"
                        return Generator__add_type_include(self, includes, refs, includes_primitives, parent_type, generics);
                    }
                } break;
                #line 1777 "src/compiler/Generator.pv"
                case FUNCTION_PARENT__TRAIT: {
                    #line 1777 "src/compiler/Generator.pv"
                    return true;
                } break;
                #line 1778 "src/compiler/Generator.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 1778 "src/compiler/Generator.pv"
                    return true;
                } break;
            }
        } break;
        #line 1781 "src/compiler/Generator.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 1781 "src/compiler/Generator.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 1781 "src/compiler/Generator.pv"
            struct GenericMap* child_types = type->coroutineinstance_value._1;
            #line 1782 "src/compiler/Generator.pv"
            struct Type* func_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = child_types} });
            #line 1783 "src/compiler/Generator.pv"
            return Generator__add_type_include(self, includes, refs, includes_primitives, func_type, generics);
        } break;
        #line 1785 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 1785 "src/compiler/Generator.pv"
            struct GenericMap* child_types = type->enum_value._1;
            #line 1786 "src/compiler/Generator.pv"
            children = &child_types->array;
        } break;
        #line 1788 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 1788 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 1788 "src/compiler/Generator.pv"
            struct GenericMap* child_types = type->struct_value._1;
            #line 1789 "src/compiler/Generator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 1790 "src/compiler/Generator.pv"
                Generator__add_type_include(self, includes, refs, includes_primitives, &struct_info->fields.data->value.type, generics);
            }

            #line 1793 "src/compiler/Generator.pv"
            children = &child_types->array;
        } break;
        #line 1795 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 1795 "src/compiler/Generator.pv"
            struct GenericMap* child_types = type->trait_value._1;
            #line 1796 "src/compiler/Generator.pv"
            children = &child_types->array;
        } break;
        #line 1798 "src/compiler/Generator.pv"
        case TYPE__GENERIC: {
            #line 1798 "src/compiler/Generator.pv"
            struct Generic* generic = type->generic_value;
            #line 1799 "src/compiler/Generator.pv"
            struct str name = generic->name->value;
            #line 1800 "src/compiler/Generator.pv"
            struct Type* resolved_type = GenericMap__get(generics, name);

            #line 1802 "src/compiler/Generator.pv"
            if (resolved_type != 0) {
                #line 1803 "src/compiler/Generator.pv"
                return Generator__add_type_include(self, includes, refs, includes_primitives, resolved_type, generics);
            }

            #line 1806 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1808 "src/compiler/Generator.pv"
        case TYPE__UNKNOWN: {
            #line 1808 "src/compiler/Generator.pv"
            struct Array_Type* child_types = &type->unknown_value._1;
            #line 1809 "src/compiler/Generator.pv"
            children = child_types;
        } break;
        #line 1811 "src/compiler/Generator.pv"
        default: {
            #line 1811 "src/compiler/Generator.pv"
            return true;
        } break;
    }

    #line 1814 "src/compiler/Generator.pv"
    Generator__add_type_include_inner(self, includes, refs, includes_primitives, type, generics);

    #line 1816 "src/compiler/Generator.pv"
    if (children == 0) {
        #line 1816 "src/compiler/Generator.pv"
        return true;
    }

    #line 1818 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(children);
    #line 1818 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 1818 "src/compiler/Generator.pv"
        struct Type* child = ArrayIter_ref_Type__value(&__iter);

        #line 1819 "src/compiler/Generator.pv"
        Generator__add_type_include(self, includes, refs, includes_primitives, child, generics);
    } }

    #line 1822 "src/compiler/Generator.pv"
    return true;
}

#line 1825 "src/compiler/Generator.pv"
bool Generator__add_function_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct Function* func_info, struct GenericMap* generics) {
    #line 1826 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 1827 "src/compiler/Generator.pv"
        Generator__add_type_include(self, includes, refs, includes, &func_info->return_type, generics);
    } else if (refs != 0) {
        #line 1829 "src/compiler/Generator.pv"
        Generator__add_type_include(self, refs, 0, includes, &func_info->return_type, generics);
    } else {
        #line 1831 "src/compiler/Generator.pv"
        Generator__add_type_include(self, includes, 0, includes, &func_info->return_type, generics);
    }

    #line 1834 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 1834 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Parameter__next(&__iter)) {
        #line 1834 "src/compiler/Generator.pv"
        struct Parameter* parameter_iter = ArrayIter_ref_Parameter__value(&__iter);

        #line 1835 "src/compiler/Generator.pv"
        if (func_info->type == FUNCTION_TYPE__COROUTINE || Type__is_fat_pointer(&parameter_iter->type)) {
            #line 1836 "src/compiler/Generator.pv"
            Generator__add_type_include(self, includes, refs, includes, &parameter_iter->type, generics);
        } else if (refs != 0) {
            #line 1838 "src/compiler/Generator.pv"
            Generator__add_type_include(self, refs, 0, includes, &parameter_iter->type, generics);
        } else {
            #line 1840 "src/compiler/Generator.pv"
            Generator__add_type_include(self, includes, 0, includes, &parameter_iter->type, generics);
        }
    } }

    #line 1844 "src/compiler/Generator.pv"
    return true;
}

#line 1847 "src/compiler/Generator.pv"
bool Generator__add_block_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct Block* block, struct GenericMap* generics) {
    #line 1848 "src/compiler/Generator.pv"
    if (block == 0) {
        #line 1848 "src/compiler/Generator.pv"
        return false;
    }

    #line 1850 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 1850 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Statement__next(&__iter)) {
        #line 1850 "src/compiler/Generator.pv"
        struct Statement* statement_iter = ArrayIter_ref_Statement__value(&__iter);

        #line 1851 "src/compiler/Generator.pv"
        switch (statement_iter->data.type) {
            #line 1852 "src/compiler/Generator.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 1852 "src/compiler/Generator.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 1853 "src/compiler/Generator.pv"
                Generator__add_block_includes(self, includes, child_block, generics);
            } break;
            #line 1855 "src/compiler/Generator.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 1855 "src/compiler/Generator.pv"
                struct LetStatement* let_statement = statement_iter->data.letstatement_value;
                #line 1856 "src/compiler/Generator.pv"
                struct Type* type = let_statement->type;
                #line 1857 "src/compiler/Generator.pv"
                struct Expression* value = let_statement->value;

                #line 1859 "src/compiler/Generator.pv"
                Generator__add_type_include(self, includes, 0, includes, type, generics);

                #line 1861 "src/compiler/Generator.pv"
                if (value != 0) {
                    #line 1862 "src/compiler/Generator.pv"
                    Generator__add_expression_includes(self, includes, value, generics);
                }
            } break;
            #line 1865 "src/compiler/Generator.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 1865 "src/compiler/Generator.pv"
                struct Expression* expression = statement_iter->data.returnstatement_value._0;
                #line 1866 "src/compiler/Generator.pv"
                if (expression) {
                    #line 1867 "src/compiler/Generator.pv"
                    Generator__add_expression_includes(self, includes, expression, generics);
                }
            } break;
            #line 1870 "src/compiler/Generator.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 1870 "src/compiler/Generator.pv"
                struct Expression* expression = statement_iter->data.yieldstatement_value;
                #line 1871 "src/compiler/Generator.pv"
                if (self->function_context != 0) {
                    #line 1872 "src/compiler/Generator.pv"
                    self->function_context->coroutine.yield_count += 1;
                }

                #line 1875 "src/compiler/Generator.pv"
                if (expression) {
                    #line 1876 "src/compiler/Generator.pv"
                    Generator__add_expression_includes(self, includes, expression, generics);
                }
            } break;
            #line 1879 "src/compiler/Generator.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 1879 "src/compiler/Generator.pv"
                struct Expression* condition = statement_iter->data.ifstatement_value._0;
                #line 1879 "src/compiler/Generator.pv"
                struct Block* if_block = statement_iter->data.ifstatement_value._1;
                #line 1879 "src/compiler/Generator.pv"
                struct Array_ElseStatement* else_statements = &statement_iter->data.ifstatement_value._2;
                #line 1880 "src/compiler/Generator.pv"
                Generator__add_block_includes(self, includes, if_block, generics);
                #line 1881 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, condition, generics);

                #line 1883 "src/compiler/Generator.pv"
                { struct ArrayIter_ref_ElseStatement __iter = Array_ElseStatement__iter(else_statements);
                #line 1883 "src/compiler/Generator.pv"
                while (ArrayIter_ref_ElseStatement__next(&__iter)) {
                    #line 1883 "src/compiler/Generator.pv"
                    struct ElseStatement* else_statement = ArrayIter_ref_ElseStatement__value(&__iter);

                    #line 1884 "src/compiler/Generator.pv"
                    Generator__add_block_includes(self, includes, else_statement->block, generics);
                } }
            } break;
            #line 1887 "src/compiler/Generator.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 1887 "src/compiler/Generator.pv"
                struct Expression* condition = statement_iter->data.matchstatement_value._0;
                #line 1887 "src/compiler/Generator.pv"
                struct Array_MatchCase* cases = &statement_iter->data.matchstatement_value._1;
                #line 1888 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, condition, generics);

                #line 1890 "src/compiler/Generator.pv"
                { struct ArrayIter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 1890 "src/compiler/Generator.pv"
                while (ArrayIter_ref_MatchCase__next(&__iter)) {
                    #line 1890 "src/compiler/Generator.pv"
                    struct MatchCase* case_info = ArrayIter_ref_MatchCase__value(&__iter);

                    #line 1891 "src/compiler/Generator.pv"
                    if (case_info->type != 0 && (&condition->return_type) != case_info->type) {
                        #line 1892 "src/compiler/Generator.pv"
                        Generator__add_type_include(self, includes, 0, includes, case_info->type, generics);
                    }

                    #line 1895 "src/compiler/Generator.pv"
                    Generator__add_block_includes(self, includes, case_info->body, generics);
                } }
            } break;
            #line 1898 "src/compiler/Generator.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 1898 "src/compiler/Generator.pv"
                struct Expression* condition = statement_iter->data.whilestatement_value._0;
                #line 1898 "src/compiler/Generator.pv"
                struct Block* while_block = statement_iter->data.whilestatement_value._1;
                #line 1899 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, condition, generics);
                #line 1900 "src/compiler/Generator.pv"
                Generator__add_block_includes(self, includes, while_block, generics);
            } break;
            #line 1902 "src/compiler/Generator.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 1902 "src/compiler/Generator.pv"
                struct ForStatement* for_statement = statement_iter->data.forstatement_value;
                #line 1903 "src/compiler/Generator.pv"
                Generator__add_type_include(self, includes, 0, includes, for_statement->value_type, generics);

                #line 1905 "src/compiler/Generator.pv"
                switch (for_statement->type.type) {
                    #line 1906 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 1906 "src/compiler/Generator.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 1906 "src/compiler/Generator.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 1907 "src/compiler/Generator.pv"
                        Generator__add_expression_includes(self, includes, start, generics);
                        #line 1908 "src/compiler/Generator.pv"
                        Generator__add_expression_includes(self, includes, end, generics);
                    } break;
                    #line 1910 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 1910 "src/compiler/Generator.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 1911 "src/compiler/Generator.pv"
                        Generator__add_expression_includes(self, includes, iter_expression, generics);
                    } break;
                }

                #line 1915 "src/compiler/Generator.pv"
                Generator__add_block_includes(self, includes, for_statement->block, generics);
            } break;
            #line 1917 "src/compiler/Generator.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 1917 "src/compiler/Generator.pv"
                struct Expression* left = statement_iter->data.assignmentstatement_value._0;
                #line 1917 "src/compiler/Generator.pv"
                struct Expression* right = statement_iter->data.assignmentstatement_value._2;
                #line 1918 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, left, generics);
                #line 1919 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, right, generics);
            } break;
            #line 1921 "src/compiler/Generator.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 1921 "src/compiler/Generator.pv"
                struct Expression* expression = statement_iter->data.expressionstatement_value;
                #line 1922 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, expression, generics);
            } break;
            #line 1924 "src/compiler/Generator.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 1925 "src/compiler/Generator.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }

    #line 1929 "src/compiler/Generator.pv"
    return true;
}

#line 1932 "src/compiler/Generator.pv"
bool Generator__add_expression_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct Expression* expression, struct GenericMap* generics) {
    #line 1933 "src/compiler/Generator.pv"
    Generator__add_type_include(self, includes, 0, includes, &expression->return_type, generics);

    #line 1935 "src/compiler/Generator.pv"
    switch (expression->data.type) {
        #line 1936 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1936 "src/compiler/Generator.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 1936 "src/compiler/Generator.pv"
            struct Array_InvokeArgument* arguments = &expression->data.invoke_value._1;
            #line 1937 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, target, generics);
            #line 1938 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 1938 "src/compiler/Generator.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 1938 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 1939 "src/compiler/Generator.pv"
                Generator__add_expression_includes(self, includes, arg->value, generics);
            } }
            #line 1943 "src/compiler/Generator.pv"
            switch (target->return_type.type) {
                #line 1944 "src/compiler/Generator.pv"
                case TYPE__FUNCTION: {
                    #line 1944 "src/compiler/Generator.pv"
                    struct Function* func_info = target->return_type.function_value._0;
                    #line 1945 "src/compiler/Generator.pv"
                    switch (func_info->parent.type) {
                        #line 1946 "src/compiler/Generator.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 1947 "src/compiler/Generator.pv"
                            if (arguments->length > 0) {
                                #line 1948 "src/compiler/Generator.pv"
                                struct Type* type = Type__deref(&arguments->data[0].value->return_type);

                                #line 1950 "src/compiler/Generator.pv"
                                switch (type->type) {
                                    #line 1951 "src/compiler/Generator.pv"
                                    case TYPE__GENERIC: {
                                        #line 1951 "src/compiler/Generator.pv"
                                        struct Generic* generic = type->generic_value;
                                        #line 1952 "src/compiler/Generator.pv"
                                        struct str name = generic->name->value;
                                        #line 1953 "src/compiler/Generator.pv"
                                        struct Type* resolved_type = GenericMap__get(generics, name);
                                        #line 1954 "src/compiler/Generator.pv"
                                        if (resolved_type != 0) {
                                            #line 1954 "src/compiler/Generator.pv"
                                            type = resolved_type;
                                        }
                                    } break;
                                    #line 1956 "src/compiler/Generator.pv"
                                    default: {
                                    } break;
                                }

                                #line 1959 "src/compiler/Generator.pv"
                                if (Type__is_primitive_or_c_type(type)) {
                                    #line 1960 "src/compiler/Generator.pv"
                                    Generator__add_type_include_inner(self, includes, 0, includes, type, generics);
                                }
                            }
                        } break;
                        #line 1964 "src/compiler/Generator.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1967 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 1970 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 1971 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1971 "src/compiler/Generator.pv"
            struct Type* type = expression->data.type_value;
            #line 1971 "src/compiler/Generator.pv"
            Generator__add_type_include(self, includes, 0, includes, type, generics);
        } break;
        #line 1972 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 1973 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 1974 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 1974 "src/compiler/Generator.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 1975 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, inner, generics);
        } break;
        #line 1977 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 1977 "src/compiler/Generator.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 1977 "src/compiler/Generator.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 1978 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, left, generics);
            #line 1979 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, right, generics);
        } break;
        #line 1981 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 1981 "src/compiler/Generator.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 1982 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, inner, generics);
        } break;
        #line 1984 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1984 "src/compiler/Generator.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 1985 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, inner, generics);
        } break;
        #line 1987 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1987 "src/compiler/Generator.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 1987 "src/compiler/Generator.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 1988 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, inner, generics);
            #line 1989 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, index, generics);
        } break;
        #line 1991 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1991 "src/compiler/Generator.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 1992 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, inner, generics);
        } break;
        #line 1994 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1994 "src/compiler/Generator.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 1995 "src/compiler/Generator.pv"
            switch (cpp_expression.type) {
                #line 1996 "src/compiler/Generator.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1996 "src/compiler/Generator.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 1996 "src/compiler/Generator.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 1997 "src/compiler/Generator.pv"
                    if (placement != 0) {
                        #line 1997 "src/compiler/Generator.pv"
                        Generator__add_expression_includes(self, includes, placement, generics);
                    }
                    #line 1998 "src/compiler/Generator.pv"
                    Generator__add_expression_includes(self, includes, new_expression, generics);
                } break;
                #line 2000 "src/compiler/Generator.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 2000 "src/compiler/Generator.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 2001 "src/compiler/Generator.pv"
                    Generator__add_expression_includes(self, includes, delete_expression, generics);
                } break;
            }
        } break;
        #line 2005 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 2005 "src/compiler/Generator.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 2006 "src/compiler/Generator.pv"
            Generator__add_expression_includes(self, includes, inner, generics);
        } break;
    }

    #line 2010 "src/compiler/Generator.pv"
    return 1;
}

#line 2014 "src/compiler/Generator.pv"
void Generator__write_c_type_include(struct Generator* self, FILE* file, struct Type* type) {
    #line 2015 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 2016 "src/compiler/Generator.pv"
        case TYPE__ENUM_C: {
            #line 2016 "src/compiler/Generator.pv"
            struct EnumC* info = type->enumc_value;
            #line 2017 "src/compiler/Generator.pv"
            struct str path = info->include->path;

            #line 2019 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 2020 "src/compiler/Generator.pv"
            Generator__write_str(self, file, path);
            #line 2021 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } break;
        #line 2023 "src/compiler/Generator.pv"
        case TYPE__STRUCT_C: {
            #line 2023 "src/compiler/Generator.pv"
            struct StructC* info = type->structc_value;
            #line 2024 "src/compiler/Generator.pv"
            struct str path = info->include->path;

            #line 2026 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 2027 "src/compiler/Generator.pv"
            Generator__write_str(self, file, path);
            #line 2028 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } break;
        #line 2030 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 2030 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 2031 "src/compiler/Generator.pv"
            struct str path = info->include->path;

            #line 2033 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 2034 "src/compiler/Generator.pv"
            Generator__write_str(self, file, path);
            #line 2035 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } break;
        #line 2037 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 2041 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes) {
    #line 2042 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(includes);
    #line 2042 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 2042 "src/compiler/Generator.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 2043 "src/compiler/Generator.pv"
        struct str path = include->path;
        #line 2044 "src/compiler/Generator.pv"
        if (path.length > 0) {
            #line 2045 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s>\n", (int32_t)(path.length - 2), path.ptr + 1);
        }
    } }

    #line 2049 "src/compiler/Generator.pv"
    if (includes->length > 0) {
        #line 2050 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 2054 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls) {
    #line 2055 "src/compiler/Generator.pv"
    struct HashSet_str written = HashSet_str__new(self->allocator);

    #line 2058 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 2058 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_Impl__next(&__iter)) {
        #line 2058 "src/compiler/Generator.pv"
        struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

        #line 2059 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&impl_info->context->module->includes);
        #line 2059 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Include__next(&__iter)) {
            #line 2059 "src/compiler/Generator.pv"
            struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

            #line 2060 "src/compiler/Generator.pv"
            if (!HashSet_str__insert(&written, include->path)) {
                #line 2060 "src/compiler/Generator.pv"
                continue;
            }
            #line 2061 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 2062 "src/compiler/Generator.pv"
            Generator__write_str(self, file, include->path);
            #line 2063 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } }
    } }
    HashSet_str__release(&written);
}

#line 2068 "src/compiler/Generator.pv"
void Generator__write_includes(struct Generator* self, FILE* file, struct HashMap_str_GeneratorInclude* includes) {
    #line 2069 "src/compiler/Generator.pv"
    { struct HashMapIter_str_GeneratorInclude __iter = HashMap_str_GeneratorInclude__iter(includes);
    #line 2069 "src/compiler/Generator.pv"
    while (HashMapIter_str_GeneratorInclude__next(&__iter)) {
        #line 2069 "src/compiler/Generator.pv"
        struct GeneratorInclude* include = &HashMapIter_str_GeneratorInclude__value(&__iter)->_1;

        #line 2070 "src/compiler/Generator.pv"
        if (include->type == 0) {
            #line 2071 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s.h>\n", (int32_t)(include->name.length), include->name.ptr);
        } else {
            #line 2073 "src/compiler/Generator.pv"
            struct Module* module = Type__get_module(include->type);
            #line 2074 "src/compiler/Generator.pv"
            struct String path = Generator__make_rel_path(self, module, include->name, (struct str){ .ptr = ".h", .length = strlen(".h") });

            #line 2076 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s>\n", String__len_i32(&path), path.array.data);
        }
    } }

    #line 2080 "src/compiler/Generator.pv"
    if (includes->length > 0) {
        #line 2081 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 2085 "src/compiler/Generator.pv"
void Generator__write_refs(struct Generator* self, FILE* file, struct HashMap_str_GeneratorInclude* refs) {
    #line 2086 "src/compiler/Generator.pv"
    { struct HashMapIter_str_GeneratorInclude __iter = HashMap_str_GeneratorInclude__iter(refs);
    #line 2086 "src/compiler/Generator.pv"
    while (HashMapIter_str_GeneratorInclude__next(&__iter)) {
        #line 2086 "src/compiler/Generator.pv"
        struct GeneratorInclude* ref_info = &HashMapIter_str_GeneratorInclude__value(&__iter)->_1;

        #line 2087 "src/compiler/Generator.pv"
        struct Type* type = ref_info->type;
        #line 2088 "src/compiler/Generator.pv"
        struct str name = ref_info->name;

        #line 2090 "src/compiler/Generator.pv"
        switch (type->type) {
            #line 2091 "src/compiler/Generator.pv"
            case TYPE__STRUCT: {
                #line 2091 "src/compiler/Generator.pv"
                struct Struct* struct_info = type->struct_value._0;
                #line 2091 "src/compiler/Generator.pv"
                struct GenericMap* generics = type->struct_value._1;
                #line 2092 "src/compiler/Generator.pv"
                if (Struct__is_newtype(struct_info)) {
                    #line 2093 "src/compiler/Generator.pv"
                    struct StructField* field = &struct_info->fields.data->value;

                    #line 2095 "src/compiler/Generator.pv"
                    fprintf(file, "typedef ");
                    #line 2096 "src/compiler/Generator.pv"
                    Generator__write_type(self, file, &field->type, generics);
                    #line 2097 "src/compiler/Generator.pv"
                    fprintf(file, " %.*s;\n", (int32_t)(name.length), name.ptr);
                } else {
                    #line 2099 "src/compiler/Generator.pv"
                    fprintf(file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                }
            } break;
            #line 2102 "src/compiler/Generator.pv"
            case TYPE__ENUM: {
                #line 2102 "src/compiler/Generator.pv"
                struct Enum* enum_info = type->enum_value._0;
                #line 2103 "src/compiler/Generator.pv"
                if (Generator__is_discriminated_union(enum_info) == 0) {
                    #line 2104 "src/compiler/Generator.pv"
                    struct String path = Generator__make_rel_path(self, enum_info->context->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
                    #line 2105 "src/compiler/Generator.pv"
                    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);
                } else {
                    #line 2107 "src/compiler/Generator.pv"
                    fprintf(file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                }
            } break;
            #line 2110 "src/compiler/Generator.pv"
            case TYPE__TRAIT: {
                #line 2111 "src/compiler/Generator.pv"
                fprintf(file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
            } break;
            #line 2113 "src/compiler/Generator.pv"
            default: {
            } break;
        }
    } }

    #line 2117 "src/compiler/Generator.pv"
    if (refs->length > 0) {
        #line 2118 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 2122 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics) {
    #line 2123 "src/compiler/Generator.pv"
    if (generics == 0 || generics->self_type == 0) {
        #line 2123 "src/compiler/Generator.pv"
        return false;
    }

    #line 2125 "src/compiler/Generator.pv"
    switch (generics->self_type->type) {
        #line 2126 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 2126 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = generics->self_type->primitive_value;
            #line 2127 "src/compiler/Generator.pv"
            if (primitive_info != 0 && !str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 2128 "src/compiler/Generator.pv"
                return false;
            }
        } break;
        #line 2131 "src/compiler/Generator.pv"
        default: {
            #line 2131 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 2134 "src/compiler/Generator.pv"
    struct Type* ref = 0;

    #line 2136 "src/compiler/Generator.pv"
    switch (parameter->type.type) {
        #line 2137 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 2137 "src/compiler/Generator.pv"
            struct Indirect* indirect = parameter->type.indirect_value;
            #line 2138 "src/compiler/Generator.pv"
            ref = &indirect->to;
        } break;
        #line 2140 "src/compiler/Generator.pv"
        default: {
            #line 2140 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 2143 "src/compiler/Generator.pv"
    if (ref == 0) {
        #line 2143 "src/compiler/Generator.pv"
        return false;
    }

    #line 2145 "src/compiler/Generator.pv"
    switch (ref->type) {
        #line 2146 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 2146 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 2147 "src/compiler/Generator.pv"
        default: {
            #line 2147 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 2151 "src/compiler/Generator.pv"
bool Generator__write_function_definition(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 2152 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, func_info->context, func_info->name);

    #line 2154 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 2155 "src/compiler/Generator.pv"
        fprintf(file, "bool");
    } else {
        #line 2157 "src/compiler/Generator.pv"
        if (Generator__write_type(self, file, &func_info->return_type, generics) == 0) {
            #line 2157 "src/compiler/Generator.pv"
            return 0;
        }
    }

    #line 2160 "src/compiler/Generator.pv"
    fprintf(file, " ");
    #line 2161 "src/compiler/Generator.pv"
    if (custom_name != 0) {
        #line 2162 "src/compiler/Generator.pv"
        Generator__write_string(self, file, custom_name);
    } else {
        #line 2164 "src/compiler/Generator.pv"
        if (func_info->generics.map.length > 0) {
            #line 2165 "src/compiler/Generator.pv"
            struct String name = Naming__get_type_name(&self->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);
            #line 2166 "src/compiler/Generator.pv"
            Generator__write_string(self, file, &name);
        } else {
            #line 2168 "src/compiler/Generator.pv"
            if (Generator__write_function_name(self, file, func_info, generics) == 0) {
                #line 2168 "src/compiler/Generator.pv"
                return 0;
            }
        }
    }

    #line 2172 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 2173 "src/compiler/Generator.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 2174 "src/compiler/Generator.pv"
        return true;
    }

    #line 2177 "src/compiler/Generator.pv"
    fprintf(file, "(");

    #line 2179 "src/compiler/Generator.pv"
    bool success = true;
    #line 2180 "src/compiler/Generator.pv"
    bool first = true;

    #line 2182 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 2182 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Parameter__next(&__iter)) {
        #line 2182 "src/compiler/Generator.pv"
        struct Parameter* parameter_iter = ArrayIter_ref_Parameter__value(&__iter);

        #line 2183 "src/compiler/Generator.pv"
        if (first) {
            #line 2183 "src/compiler/Generator.pv"
            first = false;
        } else {
            #line 2183 "src/compiler/Generator.pv"
            fprintf(file, ", ");
        }

        #line 2185 "src/compiler/Generator.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 2186 "src/compiler/Generator.pv"
            success = Generator__write_variable_decl(self, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 2188 "src/compiler/Generator.pv"
            success = Generator__write_variable_decl(self, file, parameter_iter->name->value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 2192 "src/compiler/Generator.pv"
    fprintf(file, ")");

    #line 2194 "src/compiler/Generator.pv"
    return success;
}

#line 2197 "src/compiler/Generator.pv"
bool Generator__generate_function_loop(struct Generator* self, struct TypeFunctionUsage* usage) {
    #line 2198 "src/compiler/Generator.pv"
    bool success = true;
    #line 2199 "src/compiler/Generator.pv"
    struct Function* function_info = usage->type;

    #line 2201 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&usage->generic_maps);
    #line 2201 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
        #line 2201 "src/compiler/Generator.pv"
        struct GenericMap* generics = *ArrayIter_ref_ref_GenericMap__value(&__iter);

        #line 2202 "src/compiler/Generator.pv"
        success = Generator__generate_function(self, function_info, generics) && success;
    } }

    #line 2205 "src/compiler/Generator.pv"
    return success;
}

#line 2208 "src/compiler/Generator.pv"
bool Generator__write_function_block(struct Generator* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics) {
    #line 2209 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 2210 "src/compiler/Generator.pv"
        fprintf(file, " {\n");
        #line 2211 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2213 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2214 "src/compiler/Generator.pv"
        fprintf(file, "struct ");
        #line 2215 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2216 "src/compiler/Generator.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 2218 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2219 "src/compiler/Generator.pv"
        fprintf(file, "switch (ctx->_state) {\n");
        #line 2220 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2222 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2223 "src/compiler/Generator.pv"
        fprintf(file, "case -1: return false;\n");

        #line 2225 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 2226 "src/compiler/Generator.pv"
        while (i < self->function_context->coroutine.yield_count) {
            #line 2227 "src/compiler/Generator.pv"
            i += 1;

            #line 2229 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2230 "src/compiler/Generator.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 2233 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2234 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2235 "src/compiler/Generator.pv"
        fprintf(file, "}\n\n");

        #line 2237 "src/compiler/Generator.pv"
        self->function_context->coroutine.yield_count = 0;
        #line 2238 "src/compiler/Generator.pv"
        if (Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, false, true) == 0) {
            #line 2239 "src/compiler/Generator.pv"
            uint32_t name_length = name.length;
            #line 2240 "src/compiler/Generator.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 2241 "src/compiler/Generator.pv"
            fclose(file);
            #line 2242 "src/compiler/Generator.pv"
            return false;
        }

        #line 2245 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2246 "src/compiler/Generator.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 2248 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2249 "src/compiler/Generator.pv"
        fprintf(file, "}\n");

        #line 2251 "src/compiler/Generator.pv"
        Generator__write_type(self, file, &func_info->return_type, generics);
        #line 2252 "src/compiler/Generator.pv"
        fprintf(file, " ");
        #line 2253 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2254 "src/compiler/Generator.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 2255 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2256 "src/compiler/Generator.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 2258 "src/compiler/Generator.pv"
        fprintf(file, "struct Iter_");

        #line 2260 "src/compiler/Generator.pv"
        struct String name = Naming__get_type_name(&self->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 2261 "src/compiler/Generator.pv"
        Generator__write_string(self, file, &name);
        #line 2262 "src/compiler/Generator.pv"
        String__release(&name);

        #line 2264 "src/compiler/Generator.pv"
        fprintf(file, "VTable ");

        #line 2266 "src/compiler/Generator.pv"
        switch (func_info->parent.type) {
            #line 2267 "src/compiler/Generator.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 2267 "src/compiler/Generator.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 2268 "src/compiler/Generator.pv"
                Generator__write_str_title(self, file, struct_info->name->value);
                #line 2269 "src/compiler/Generator.pv"
                fprintf(file, "__");
            } break;
            #line 2271 "src/compiler/Generator.pv"
            default: {
            } break;
        }

        #line 2274 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, func_info->name->value);

        #line 2276 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__ITER = { .next = ");
        #line 2277 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2278 "src/compiler/Generator.pv"
        fprintf(file, "__next, .value = ");
        #line 2279 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2280 "src/compiler/Generator.pv"
        fprintf(file, "__value };\n\n");

        #line 2282 "src/compiler/Generator.pv"
        return true;
    }

    #line 2285 "src/compiler/Generator.pv"
    fprintf(file, " ");
    #line 2286 "src/compiler/Generator.pv"
    if (Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, 0, 0) == 0) {
        #line 2287 "src/compiler/Generator.pv"
        uint32_t name_length = name.length;
        #line 2288 "src/compiler/Generator.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 2289 "src/compiler/Generator.pv"
        fclose(file);
        #line 2290 "src/compiler/Generator.pv"
        return false;
    }

    #line 2293 "src/compiler/Generator.pv"
    return true;
}

#line 2296 "src/compiler/Generator.pv"
bool Generator__write_function_coroutine(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 2297 "src/compiler/Generator.pv"
    fprintf(file, "struct ");
    #line 2298 "src/compiler/Generator.pv"
    Generator__write_function_name(self, file, func_info, generics);
    #line 2299 "src/compiler/Generator.pv"
    fprintf(file, " {\n");
    #line 2300 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 2302 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2303 "src/compiler/Generator.pv"
    fprintf(file, "int32_t _state;\n");

    #line 2305 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2306 "src/compiler/Generator.pv"
    Generator__write_type(self, file, &func_info->return_type, generics);
    #line 2307 "src/compiler/Generator.pv"
    fprintf(file, " _value;\n\n");

    #line 2309 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&self->function_context->coroutine.variables);
    #line 2309 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 2309 "src/compiler/Generator.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 2309 "src/compiler/Generator.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 2310 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2311 "src/compiler/Generator.pv"
        Generator__write_type(self, file, type, generics);
        #line 2312 "src/compiler/Generator.pv"
        fprintf(file, " ");
        #line 2313 "src/compiler/Generator.pv"
        Generator__write_str(self, file, name);
        #line 2314 "src/compiler/Generator.pv"
        fprintf(file, ";\n");
    } }

    #line 2317 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 2318 "src/compiler/Generator.pv"
    fprintf(file, "};\n\n");

    #line 2320 "src/compiler/Generator.pv"
    fprintf(file, "#include <std/Iter_");

    #line 2322 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 2323 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &name);

    #line 2325 "src/compiler/Generator.pv"
    fprintf(file, ".h>\n");

    #line 2327 "src/compiler/Generator.pv"
    Generator__write_type(self, file, &func_info->return_type, generics);
    #line 2328 "src/compiler/Generator.pv"
    fprintf(file, " ");
    #line 2329 "src/compiler/Generator.pv"
    Generator__write_function_name(self, file, func_info, generics);
    #line 2330 "src/compiler/Generator.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 2332 "src/compiler/Generator.pv"
    fprintf(file, "extern struct Iter_");
    #line 2333 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &name);
    #line 2334 "src/compiler/Generator.pv"
    String__release(&name);

    #line 2336 "src/compiler/Generator.pv"
    fprintf(file, "VTable ");

    #line 2338 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, func_info->name->value);
    #line 2339 "src/compiler/Generator.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 2341 "src/compiler/Generator.pv"
    return 1;
}

#line 2344 "src/compiler/Generator.pv"
bool Generator__generate_function(struct Generator* self, struct Function* func_info, struct GenericMap* generics) {
    #line 2345 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 2345 "src/compiler/Generator.pv"
        return true;
    }

    #line 2347 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2348 "src/compiler/Generator.pv"
    struct str name_str = String__as_str(&name);
    #line 2349 "src/compiler/Generator.pv"
    struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
    #line 2350 "src/compiler/Generator.pv"
    self->function_context = &func_context;

    #line 2352 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, func_info->context->module, name_str, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 2353 "src/compiler/Generator.pv"
    FILE* code_file = 0;
    #line 2354 "src/compiler/Generator.pv"
    char const* code_tmp = 0;

    #line 2356 "src/compiler/Generator.pv"
    code_tmp = tmpnam(0);
    #line 2357 "src/compiler/Generator.pv"
    code_file = fopen(code_tmp, "w+");

    #line 2359 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 2361 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 2361 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 2361 "src/compiler/Generator.pv"
        return 0;
    }

    #line 2363 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 2364 "src/compiler/Generator.pv"
    if (Generator__add_block_includes(self, &includes, func_info->body, generics) == 0) {
        #line 2364 "src/compiler/Generator.pv"
        return 0;
    }
    #line 2365 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, code_file, &func_info->context->module->includes);
    #line 2366 "src/compiler/Generator.pv"
    Generator__write_includes(self, code_file, &includes);

    #line 2368 "src/compiler/Generator.pv"
    struct String header_rel = Generator__make_rel_path(self, func_info->context->module, name_str, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2369 "src/compiler/Generator.pv"
    fprintf(code_file, "#include <");
    #line 2370 "src/compiler/Generator.pv"
    Generator__write_str(self, code_file, String__as_str(&header_rel));
    #line 2371 "src/compiler/Generator.pv"
    fprintf(code_file, ">\n\n");

    #line 2373 "src/compiler/Generator.pv"
    if (Generator__write_function_definition(self, code_file, func_info, generics, 0) == 0) {
        #line 2373 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 2373 "src/compiler/Generator.pv"
        return 0;
    }

    #line 2375 "src/compiler/Generator.pv"
    Generator__write_function_block(self, code_file, name_str, func_info, generics);

    #line 2377 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 2378 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 2379 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 2381 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, func_info->context->module, name_str, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2382 "src/compiler/Generator.pv"
    FILE* header_file = 0;
    #line 2383 "src/compiler/Generator.pv"
    char const* header_tmp = 0;
    #line 2384 "src/compiler/Generator.pv"
    header_tmp = tmpnam(0);
    #line 2385 "src/compiler/Generator.pv"
    header_file = fopen(header_tmp, "w+");

    #line 2387 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 2387 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 2387 "src/compiler/Generator.pv"
        return 0;
    }

    #line 2389 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 2390 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name_str);
    #line 2391 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 2392 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name_str);
    #line 2393 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 2395 "src/compiler/Generator.pv"
    includes = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 2396 "src/compiler/Generator.pv"
    if (Generator__add_function_includes(self, &includes, 0, func_info, generics) == 0) {
        #line 2396 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2396 "src/compiler/Generator.pv"
        return 0;
    }
    #line 2397 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, header_file, &func_info->context->module->includes);
    #line 2398 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes);

    #line 2400 "src/compiler/Generator.pv"
    if (Generator__is_coroutine(self)) {
        #line 2401 "src/compiler/Generator.pv"
        Generator__write_function_coroutine(self, header_file, func_info, generics);
    }

    #line 2404 "src/compiler/Generator.pv"
    if (Generator__write_function_definition(self, header_file, func_info, generics, 0) == 0) {
        #line 2404 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2404 "src/compiler/Generator.pv"
        return 0;
    }
    #line 2405 "src/compiler/Generator.pv"
    fprintf(header_file, ";\n");

    #line 2407 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 2409 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 2410 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 2411 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 2413 "src/compiler/Generator.pv"
    self->function_context = 0;

    #line 2415 "src/compiler/Generator.pv"
    return 1;
}

#line 2418 "src/compiler/Generator.pv"
bool Generator__add_enum_definition_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct Enum* enum_info, struct GenericMap* generics) {
    #line 2419 "src/compiler/Generator.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 2419 "src/compiler/Generator.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 2419 "src/compiler/Generator.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 2420 "src/compiler/Generator.pv"
        if (variant->types.length > 0) {
            #line 2421 "src/compiler/Generator.pv"
            { struct ArrayIter_ref_Type __iter = Array_Type__iter(&variant->types);
            #line 2421 "src/compiler/Generator.pv"
            while (ArrayIter_ref_Type__next(&__iter)) {
                #line 2421 "src/compiler/Generator.pv"
                struct Type* type = ArrayIter_ref_Type__value(&__iter);

                #line 2422 "src/compiler/Generator.pv"
                Generator__add_type_include(self, includes, refs, includes, type, generics);
            } }
        }
    } }

    #line 2427 "src/compiler/Generator.pv"
    return 1;
}

#line 2430 "src/compiler/Generator.pv"
bool Generator__write_enum_definition(struct Generator* self, FILE* file, struct Enum* enum_info, struct GenericMap* generics) {
    #line 2431 "src/compiler/Generator.pv"
    struct Token* enum_name = enum_info->name;
    #line 2432 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2433 "src/compiler/Generator.pv"
    uint32_t name_length = name.array.length;
    #line 2434 "src/compiler/Generator.pv"
    bool is_discriminated_union = Generator__is_discriminated_union(enum_info);

    #line 2436 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, enum_info->context, enum_info->name);

    #line 2438 "src/compiler/Generator.pv"
    if (!is_discriminated_union) {
        #line 2439 "src/compiler/Generator.pv"
        fprintf(file, "enum ");
        #line 2440 "src/compiler/Generator.pv"
        Generator__write_str(self, file, enum_name->value);
        #line 2441 "src/compiler/Generator.pv"
        fprintf(file, " {\n");
        #line 2442 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2444 "src/compiler/Generator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 2444 "src/compiler/Generator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 2444 "src/compiler/Generator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 2445 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2446 "src/compiler/Generator.pv"
            Generator__write_enum_variant_name(self, file, generics->self_type, variant);

            #line 2448 "src/compiler/Generator.pv"
            if (variant->value != 0) {
                #line 2449 "src/compiler/Generator.pv"
                fprintf(file, " = ");
                #line 2450 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, variant->value, generics);
            }

            #line 2453 "src/compiler/Generator.pv"
            fprintf(file, ",\n");
        } }

        #line 2456 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2457 "src/compiler/Generator.pv"
        fprintf(file, "};\n");
    } else {
        #line 2459 "src/compiler/Generator.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 2461 "src/compiler/Generator.pv"
        if (has_generics) {
            #line 2462 "src/compiler/Generator.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 2463 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, enum_info->name->value);
            #line 2464 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2465 "src/compiler/Generator.pv"
            fprintf(file, "\n#define PAVE_");
            #line 2466 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, enum_info->name->value);
            #line 2467 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2468 "src/compiler/Generator.pv"
            fprintf(file, "\n");

            #line 2470 "src/compiler/Generator.pv"
            fprintf(file, "enum ");
            #line 2471 "src/compiler/Generator.pv"
            Generator__write_token(self, file, enum_info->name);
            #line 2472 "src/compiler/Generator.pv"
            Generator__write_str(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2473 "src/compiler/Generator.pv"
            fprintf(file, " {\n");

            #line 2475 "src/compiler/Generator.pv"
            self->indent += 1;

            #line 2477 "src/compiler/Generator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 2477 "src/compiler/Generator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 2477 "src/compiler/Generator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 2478 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2479 "src/compiler/Generator.pv"
                Generator__write_enum_variant_name(self, file, generics->self_type, variant);

                #line 2481 "src/compiler/Generator.pv"
                if (variant->value != 0) {
                    #line 2482 "src/compiler/Generator.pv"
                    fprintf(file, " = ");
                    #line 2483 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, variant->value, generics);
                }

                #line 2486 "src/compiler/Generator.pv"
                fprintf(file, ",\n");
            } }

            #line 2489 "src/compiler/Generator.pv"
            self->indent -= 1;
            #line 2490 "src/compiler/Generator.pv"
            fprintf(file, "};\n");
            #line 2491 "src/compiler/Generator.pv"
            fprintf(file, "#endif\n");
            #line 2492 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        }

        #line 2495 "src/compiler/Generator.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 2496 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2498 "src/compiler/Generator.pv"
        if (!has_generics) {
            #line 2499 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2500 "src/compiler/Generator.pv"
            fprintf(file, "enum {\n");
            #line 2501 "src/compiler/Generator.pv"
            self->indent += 1;

            #line 2503 "src/compiler/Generator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 2503 "src/compiler/Generator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 2503 "src/compiler/Generator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 2504 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2505 "src/compiler/Generator.pv"
                Generator__write_enum_variant_name(self, file, generics->self_type, variant);
                #line 2506 "src/compiler/Generator.pv"
                fprintf(file, ",\n");
            } }

            #line 2509 "src/compiler/Generator.pv"
            self->indent -= 1;
            #line 2510 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2511 "src/compiler/Generator.pv"
            fprintf(file, "} type;\n");
            #line 2512 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } else {
            #line 2514 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2515 "src/compiler/Generator.pv"
            fprintf(file, "enum ");
            #line 2516 "src/compiler/Generator.pv"
            Generator__write_token(self, file, enum_info->name);
            #line 2517 "src/compiler/Generator.pv"
            Generator__write_str(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2518 "src/compiler/Generator.pv"
            fprintf(file, " type;\n");
        }

        #line 2521 "src/compiler/Generator.pv"
        uintptr_t variants_with_data = 0;
        #line 2522 "src/compiler/Generator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 2522 "src/compiler/Generator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 2522 "src/compiler/Generator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 2523 "src/compiler/Generator.pv"
            variants_with_data += variant->types.length > 0;
        } }

        #line 2526 "src/compiler/Generator.pv"
        if (variants_with_data > 1) {
            #line 2527 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2528 "src/compiler/Generator.pv"
            fprintf(file, "union {\n");
            #line 2529 "src/compiler/Generator.pv"
            self->indent += 1;
        }

        #line 2532 "src/compiler/Generator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 2532 "src/compiler/Generator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 2532 "src/compiler/Generator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 2533 "src/compiler/Generator.pv"
            if (variant->types.length == 1) {
                #line 2534 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2535 "src/compiler/Generator.pv"
                Generator__write_type(self, file, variant->types.data, generics);
                #line 2536 "src/compiler/Generator.pv"
                fprintf(file, " ");

                #line 2538 "src/compiler/Generator.pv"
                struct Token* name = variant->name;
                #line 2539 "src/compiler/Generator.pv"
                Generator__write_str_lowercase(self, file, name->value);
                #line 2540 "src/compiler/Generator.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 2542 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2543 "src/compiler/Generator.pv"
                fprintf(file, "struct { ");

                #line 2545 "src/compiler/Generator.pv"
                { struct ArrayIter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 2545 "src/compiler/Generator.pv"
                while (ArrayIter_ref_Type__next(&__iter)) {
                    #line 2545 "src/compiler/Generator.pv"
                    struct Type* type = ArrayIter_ref_Type__value(&__iter);

                    #line 2546 "src/compiler/Generator.pv"
                    Generator__write_type(self, file, type, generics);
                    #line 2547 "src/compiler/Generator.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 2550 "src/compiler/Generator.pv"
                fprintf(file, "} ");
                #line 2551 "src/compiler/Generator.pv"
                struct Token* name = variant->name;
                #line 2552 "src/compiler/Generator.pv"
                Generator__write_str_lowercase(self, file, name->value);
                #line 2553 "src/compiler/Generator.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 2557 "src/compiler/Generator.pv"
        if (variants_with_data > 1) {
            #line 2558 "src/compiler/Generator.pv"
            self->indent -= 1;
            #line 2559 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2560 "src/compiler/Generator.pv"
            fprintf(file, "};\n");
        }

        #line 2563 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2564 "src/compiler/Generator.pv"
        fprintf(file, "};\n");
    }

    #line 2567 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
    #line 2567 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_Impl__next(&__iter)) {
        #line 2567 "src/compiler/Generator.pv"
        struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

        #line 2568 "src/compiler/Generator.pv"
        fprintf(file, "\n");

        #line 2570 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2570 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2570 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2571 "src/compiler/Generator.pv"
            if (Generator__write_function_definition(self, file, func_info, generics, 0) == 0) {
                #line 2571 "src/compiler/Generator.pv"
                return 0;
            }
            #line 2572 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 2576 "src/compiler/Generator.pv"
    return 1;
}

#line 2579 "src/compiler/Generator.pv"
bool Generator__generate_enum_loop(struct Generator* self, struct TypeUsage_Enum* usage) {
    #line 2580 "src/compiler/Generator.pv"
    bool success = true;
    #line 2581 "src/compiler/Generator.pv"
    struct Enum* enum_info = usage->type;

    #line 2583 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&usage->generic_maps);
    #line 2583 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
        #line 2583 "src/compiler/Generator.pv"
        struct GenericMap* generics = *ArrayIter_ref_ref_GenericMap__value(&__iter);

        #line 2584 "src/compiler/Generator.pv"
        success = Generator__generate_enum(self, enum_info, generics) && success;
    } }

    #line 2587 "src/compiler/Generator.pv"
    return success;
}

#line 2590 "src/compiler/Generator.pv"
bool Generator__generate_enum(struct Generator* self, struct Enum* enum_info, struct GenericMap* generics) {
    #line 2591 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2592 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, enum_info->context->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2593 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 2594 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 2595 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 2595 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 2595 "src/compiler/Generator.pv"
        return false;
    }

    #line 2597 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 2598 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 2599 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 2600 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 2601 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 2603 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 2604 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude refs_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 2605 "src/compiler/Generator.pv"
    if (Generator__add_enum_definition_includes(self, &includes_definition, &refs_definition, enum_info, generics) == 0) {
        #line 2605 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2605 "src/compiler/Generator.pv"
        return 0;
    }
    #line 2606 "src/compiler/Generator.pv"
    if (Generator__add_impl_definition_includes(self, &includes_definition, &refs_definition, &enum_info->impls, 0, generics) == 0) {
        #line 2606 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2606 "src/compiler/Generator.pv"
        return 0;
    }
    #line 2607 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, header_file, &enum_info->context->module->includes);
    #line 2608 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes_definition);
    #line 2609 "src/compiler/Generator.pv"
    Generator__write_refs(self, header_file, &refs_definition);

    #line 2611 "src/compiler/Generator.pv"
    if (Generator__write_enum_definition(self, header_file, enum_info, generics) == 0) {
        #line 2611 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2611 "src/compiler/Generator.pv"
        return 0;
    }

    #line 2613 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 2615 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 2616 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 2617 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 2619 "src/compiler/Generator.pv"
    if (enum_info->impls.length == 0) {
        #line 2619 "src/compiler/Generator.pv"
        return true;
    }

    #line 2621 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, enum_info->context->module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 2622 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 2624 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 2625 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 2626 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 2626 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 2626 "src/compiler/Generator.pv"
        return false;
    }

    #line 2628 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_code = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 2629 "src/compiler/Generator.pv"
    if (Generator__add_impl_includes(self, &includes_code, &enum_info->impls, 0, generics) == 0) {
        #line 2629 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 2629 "src/compiler/Generator.pv"
        return 0;
    }
    #line 2630 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, code_file, &enum_info->context->module->includes);
    #line 2631 "src/compiler/Generator.pv"
    Generator__write_includes(self, code_file, &includes_code);

    #line 2633 "src/compiler/Generator.pv"
    if (Generator__write_impls(self, code_file, enum_info->context->module, &enum_info->impls, 0, generics) == 0) {
        #line 2633 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 2633 "src/compiler/Generator.pv"
        return 0;
    }

    #line 2635 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 2636 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 2637 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 2639 "src/compiler/Generator.pv"
    return 1;
}

#line 2642 "src/compiler/Generator.pv"
bool Generator__add_impl_definition_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics) {
    #line 2643 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 2643 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 2643 "src/compiler/Generator.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 2643 "src/compiler/Generator.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 2644 "src/compiler/Generator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 2645 "src/compiler/Generator.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 2646 "src/compiler/Generator.pv"
        if (impl_functions != 0) {
            #line 2646 "src/compiler/Generator.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 2648 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 2649 "src/compiler/Generator.pv"
            struct Type* type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generics} });
            #line 2650 "src/compiler/Generator.pv"
            Generator__add_type_include(self, includes, refs, includes, type, generics);
        }

        #line 2653 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2653 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2653 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2654 "src/compiler/Generator.pv"
            if (func_info->generics.array.length > 0 && impl_functions_for_impl != 0) {
                #line 2655 "src/compiler/Generator.pv"
                uintptr_t func_ptr = (uintptr_t)(func_info);
                #line 2656 "src/compiler/Generator.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 2657 "src/compiler/Generator.pv"
                if (function_usage != 0) {
                    #line 2658 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&function_usage->generic_maps);
                    #line 2658 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
                        #line 2658 "src/compiler/Generator.pv"
                        struct GenericMap* generics_impl = *ArrayIter_ref_ref_GenericMap__value(&__iter);

                        #line 2659 "src/compiler/Generator.pv"
                        Generator__add_function_includes(self, includes, refs, func_info, generics_impl);
                    } }
                }
                #line 2662 "src/compiler/Generator.pv"
                continue;
            }

            #line 2665 "src/compiler/Generator.pv"
            Generator__add_function_includes(self, includes, refs, func_info, generics);
        } }

        #line 2668 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 2669 "src/compiler/Generator.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 2669 "src/compiler/Generator.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 2669 "src/compiler/Generator.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 2669 "src/compiler/Generator.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 2670 "src/compiler/Generator.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 2670 "src/compiler/Generator.pv"
                    continue;
                }

                #line 2672 "src/compiler/Generator.pv"
                Generator__add_function_includes(self, includes, refs, func_info, generics);
            } }
        }
    } }

    #line 2677 "src/compiler/Generator.pv"
    return true;
}

#line 2680 "src/compiler/Generator.pv"
bool Generator__add_struct_definition_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct Struct* struct_info, struct GenericMap* generics) {
    #line 2681 "src/compiler/Generator.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 2681 "src/compiler/Generator.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 2681 "src/compiler/Generator.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 2682 "src/compiler/Generator.pv"
        Generator__add_type_include(self, includes, refs, includes, &field->type, generics);
    } }

    #line 2685 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&struct_info->traits);
    #line 2685 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 2685 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 2686 "src/compiler/Generator.pv"
        struct GenericMap* trait_generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
        #line 2687 "src/compiler/Generator.pv"
        struct Type* trait_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = trait_generic_map} });
        #line 2688 "src/compiler/Generator.pv"
        trait_generic_map->self_type = trait_type;

        #line 2690 "src/compiler/Generator.pv"
        Generator__add_type_include(self, includes, refs, includes, trait_type, trait_generic_map);
    } }

    #line 2693 "src/compiler/Generator.pv"
    return 1;
}

#line 2696 "src/compiler/Generator.pv"
bool Generator__add_impl_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics) {
    #line 2697 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 2697 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 2697 "src/compiler/Generator.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 2697 "src/compiler/Generator.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 2698 "src/compiler/Generator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 2699 "src/compiler/Generator.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 2700 "src/compiler/Generator.pv"
        if (impl_functions != 0) {
            #line 2700 "src/compiler/Generator.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 2702 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2702 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2702 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2703 "src/compiler/Generator.pv"
            if (func_info->generics.array.length == 0) {
                #line 2704 "src/compiler/Generator.pv"
                Generator__add_function_includes(self, includes, 0, func_info, generics);
                #line 2705 "src/compiler/Generator.pv"
                Generator__add_block_includes(self, includes, func_info->body, generics);
            } else if (impl_functions_for_impl != 0) {
                #line 2707 "src/compiler/Generator.pv"
                uintptr_t func_ptr = (uintptr_t)(func_info);
                #line 2708 "src/compiler/Generator.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 2709 "src/compiler/Generator.pv"
                if (function_usage != 0) {
                    #line 2710 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&function_usage->generic_maps);
                    #line 2710 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
                        #line 2710 "src/compiler/Generator.pv"
                        struct GenericMap* generics3 = *ArrayIter_ref_ref_GenericMap__value(&__iter);

                        #line 2711 "src/compiler/Generator.pv"
                        Generator__add_function_includes(self, includes, 0, func_info, generics3);
                        #line 2712 "src/compiler/Generator.pv"
                        Generator__add_block_includes(self, includes, func_info->body, generics3);
                    } }
                }
            }
        } }
        #line 2719 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 2720 "src/compiler/Generator.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 2720 "src/compiler/Generator.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 2720 "src/compiler/Generator.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 2720 "src/compiler/Generator.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 2721 "src/compiler/Generator.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 2721 "src/compiler/Generator.pv"
                    continue;
                }

                #line 2723 "src/compiler/Generator.pv"
                Generator__add_function_includes(self, includes, 0, func_info, generics);
                #line 2724 "src/compiler/Generator.pv"
                Generator__add_block_includes(self, includes, func_info->body, generics);
            } }
        }
    } }

    #line 2729 "src/compiler/Generator.pv"
    return 1;
}

#line 2732 "src/compiler/Generator.pv"
bool Generator__add_trait_definition_includes(struct Generator* self, struct HashMap_str_GeneratorInclude* includes, struct HashMap_str_GeneratorInclude* refs, struct Trait* trait_info, struct GenericMap* generics) {
    #line 2733 "src/compiler/Generator.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 2733 "src/compiler/Generator.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 2733 "src/compiler/Generator.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 2734 "src/compiler/Generator.pv"
        Generator__add_function_includes(self, includes, refs, func_info, generics);
    } }

    #line 2737 "src/compiler/Generator.pv"
    return 1;
}

#line 2740 "src/compiler/Generator.pv"
bool Generator__write_struct_definition(struct Generator* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct GenericMap* generics) {
    #line 2741 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2742 "src/compiler/Generator.pv"
    int32_t name_length = name.array.length;
    #line 2743 "src/compiler/Generator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage->impl_functions;

    #line 2745 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, &struct_info->module->context, struct_info->name);

    #line 2747 "src/compiler/Generator.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 2748 "src/compiler/Generator.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 2750 "src/compiler/Generator.pv"
        struct StructField* field = &struct_info->fields.data[0].value;

        #line 2752 "src/compiler/Generator.pv"
        fprintf(file, "typedef ");
        #line 2753 "src/compiler/Generator.pv"
        Generator__write_type(self, file, &field->type, generics);
        #line 2754 "src/compiler/Generator.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 2756 "src/compiler/Generator.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 2757 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2759 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 2759 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 2759 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 2760 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2761 "src/compiler/Generator.pv"
            Generator__write_variable_decl(self, file, field->name->value, &field->type, generics);
            #line 2762 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        } }

        #line 2765 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2766 "src/compiler/Generator.pv"
        fprintf(file, "};\n");
    }

    #line 2769 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 2769 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 2769 "src/compiler/Generator.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 2769 "src/compiler/Generator.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 2770 "src/compiler/Generator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 2771 "src/compiler/Generator.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 2772 "src/compiler/Generator.pv"
        if (impl_functions != 0) {
            #line 2772 "src/compiler/Generator.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 2774 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2774 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2774 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2775 "src/compiler/Generator.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 2776 "src/compiler/Generator.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 2777 "src/compiler/Generator.pv"
            if (impl_functions_for_impl != 0) {
                #line 2777 "src/compiler/Generator.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 2779 "src/compiler/Generator.pv"
            if (func_info->generics.array.length == 0) {
                #line 2780 "src/compiler/Generator.pv"
                if (trait_info == 0) {
                    #line 2781 "src/compiler/Generator.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0) {
                        #line 2782 "src/compiler/Generator.pv"
                        self->function_context = &function_usage->function_context;
                        #line 2783 "src/compiler/Generator.pv"
                        Generator__write_function_coroutine(self, file, func_info, generics);
                        #line 2784 "src/compiler/Generator.pv"
                        self->function_context = 0;
                    }

                    #line 2787 "src/compiler/Generator.pv"
                    fprintf(file, "\n");
                    #line 2788 "src/compiler/Generator.pv"
                    if (Generator__write_function_definition(self, file, func_info, generics, 0) == 0) {
                        #line 2788 "src/compiler/Generator.pv"
                        return 0;
                    }
                } else {
                    #line 2790 "src/compiler/Generator.pv"
                    struct GenericMap generics_void = *generics;
                    #line 2791 "src/compiler/Generator.pv"
                    generics_void.self_type = &self->root->type_void;

                    #line 2793 "src/compiler/Generator.pv"
                    struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                    #line 2794 "src/compiler/Generator.pv"
                    fprintf(file, "\n");
                    #line 2795 "src/compiler/Generator.pv"
                    if (Generator__write_function_definition(self, file, func_info, &generics_void, &func_name) == 0) {
                        #line 2795 "src/compiler/Generator.pv"
                        return 0;
                    }
                }

                #line 2798 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            }

            #line 2801 "src/compiler/Generator.pv"
            if (impl_functions_for_impl != 0) {
                #line 2802 "src/compiler/Generator.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 2803 "src/compiler/Generator.pv"
                if (function_usage != 0) {
                    #line 2804 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&function_usage->generic_maps);
                    #line 2804 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
                        #line 2804 "src/compiler/Generator.pv"
                        struct GenericMap* generics3 = *ArrayIter_ref_ref_GenericMap__value(&__iter);

                        #line 2805 "src/compiler/Generator.pv"
                        generics3->self_type = generics->self_type;
                        #line 2806 "src/compiler/Generator.pv"
                        fprintf(file, "\n");
                        #line 2807 "src/compiler/Generator.pv"
                        if (Generator__write_function_definition(self, file, func_info, generics3, 0) == 0) {
                            #line 2807 "src/compiler/Generator.pv"
                            return 0;
                        }
                        #line 2808 "src/compiler/Generator.pv"
                        fprintf(file, ";\n");
                    } }

                    #line 2811 "src/compiler/Generator.pv"
                    if (function_usage->impl_dynamic_function) {
                        #line 2812 "src/compiler/Generator.pv"
                        if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                            #line 2813 "src/compiler/Generator.pv"
                            fprintf(file, "#include <std/Co_CoroutineStatus.h>\n");
                            #line 2814 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 2815 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2816 "src/compiler/Generator.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance { ");
                            #line 2817 "src/compiler/Generator.pv"
                            self->indent += 1;
                            #line 2818 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 2818 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_Parameter__next(&__iter)) {
                                #line 2818 "src/compiler/Generator.pv"
                                struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                                #line 2819 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, &param->type, generics);
                                #line 2820 "src/compiler/Generator.pv"
                                fprintf(file, " ");
                                #line 2821 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 2822 "src/compiler/Generator.pv"
                                fprintf(file, "; ");
                            } }
                            #line 2824 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 2825 "src/compiler/Generator.pv"
                            fprintf(file, "};\n");

                            #line 2827 "src/compiler/Generator.pv"
                            fprintf(file, "extern struct Co_CoroutineStatusVTable ");
                            #line 2828 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, struct_info->name->value);
                            #line 2829 "src/compiler/Generator.pv"
                            fprintf(file, "__");
                            #line 2830 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, func_info->name->value);
                            #line 2831 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__DYN_CO;\n");
                        } else {
                            #line 2833 "src/compiler/Generator.pv"
                            fprintf(file, "#include <std/Fn.h>\n");
                            #line 2834 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 2835 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2836 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__Instance { ");
                            #line 2837 "src/compiler/Generator.pv"
                            self->indent += 1;
                            #line 2838 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 2838 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_Parameter__next(&__iter)) {
                                #line 2838 "src/compiler/Generator.pv"
                                struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                                #line 2839 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, &param->type, generics);
                                #line 2840 "src/compiler/Generator.pv"
                                fprintf(file, " ");
                                #line 2841 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 2842 "src/compiler/Generator.pv"
                                fprintf(file, "; ");
                            } }
                            #line 2844 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 2845 "src/compiler/Generator.pv"
                            fprintf(file, "};\n");

                            #line 2847 "src/compiler/Generator.pv"
                            fprintf(file, "extern struct FnVTable ");
                            #line 2848 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, struct_info->name->value);
                            #line 2849 "src/compiler/Generator.pv"
                            fprintf(file, "__");
                            #line 2850 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, func_info->name->value);
                            #line 2851 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__DYN_FN;\n");
                        }
                    }
                }
            }
        } }

        #line 2858 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 2859 "src/compiler/Generator.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 2859 "src/compiler/Generator.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 2859 "src/compiler/Generator.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 2859 "src/compiler/Generator.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 2860 "src/compiler/Generator.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 2860 "src/compiler/Generator.pv"
                    continue;
                }

                #line 2862 "src/compiler/Generator.pv"
                fprintf(file, "\n");
                #line 2863 "src/compiler/Generator.pv"
                struct GenericMap generics_void = *generics;
                #line 2864 "src/compiler/Generator.pv"
                generics_void.self_type = &self->root->type_void;

                #line 2866 "src/compiler/Generator.pv"
                struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                #line 2867 "src/compiler/Generator.pv"
                if (Generator__write_function_definition(self, file, func_info, &generics_void, &func_name) == 0) {
                    #line 2867 "src/compiler/Generator.pv"
                    return 0;
                }
                #line 2868 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } }
        }
    } }

    #line 2873 "src/compiler/Generator.pv"
    if (struct_info->traits.length > 0) {
        #line 2873 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }

    #line 2875 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&struct_info->traits);
    #line 2875 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 2875 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 2876 "src/compiler/Generator.pv"
        fprintf(file, "extern struct ");
        #line 2877 "src/compiler/Generator.pv"
        Generator__write_token(self, file, trait_info->name);
        #line 2878 "src/compiler/Generator.pv"
        fprintf(file, "VTable ");
        #line 2879 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, String__as_str(&name));
        #line 2880 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__");
        #line 2881 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, trait_info->name->value);
        #line 2882 "src/compiler/Generator.pv"
        fprintf(file, ";\n");
    } }

    #line 2885 "src/compiler/Generator.pv"
    if (usage->impl_dynamic_usage) {
        #line 2886 "src/compiler/Generator.pv"
        fprintf(file, "#include <std/Struct.h>\n");
        #line 2887 "src/compiler/Generator.pv"
        fprintf(file, "extern struct StructVTable ");
        #line 2888 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, String__as_str(&name));
        #line 2889 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__DYN_STRUCT;\n");
    }

    #line 2892 "src/compiler/Generator.pv"
    return 1;
}

#line 2895 "src/compiler/Generator.pv"
bool Generator__write_impl_definition(struct Generator* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 2896 "src/compiler/Generator.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 2898 "src/compiler/Generator.pv"
    fprintf(file, "\n");

    #line 2900 "src/compiler/Generator.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 2900 "src/compiler/Generator.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 2900 "src/compiler/Generator.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 2901 "src/compiler/Generator.pv"
        if (func_info->generics.array.length == 0) {
            #line 2902 "src/compiler/Generator.pv"
            if (trait_info == 0) {
                #line 2903 "src/compiler/Generator.pv"
                if (Generator__write_function_definition(self, file, func_info, generics, 0) == 0) {
                    #line 2903 "src/compiler/Generator.pv"
                    return 0;
                }
            } else {
                #line 2905 "src/compiler/Generator.pv"
                struct GenericMap generics_void = *generics;
                #line 2906 "src/compiler/Generator.pv"
                generics_void.self_type = &self->root->type_void;

                #line 2908 "src/compiler/Generator.pv"
                struct String func_name = Generator__get_trait_function_name(self, name, trait_info, func_info, generics);
                #line 2909 "src/compiler/Generator.pv"
                if (Generator__write_function_definition(self, file, func_info, &generics_void, &func_name) == 0) {
                    #line 2909 "src/compiler/Generator.pv"
                    return 0;
                }
            }

            #line 2912 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        }
    } }
    #line 2917 "src/compiler/Generator.pv"
    if (trait_info != 0) {
        #line 2918 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 2918 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2918 "src/compiler/Generator.pv"
            struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
            #line 2918 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2919 "src/compiler/Generator.pv"
            if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                #line 2919 "src/compiler/Generator.pv"
                continue;
            }

            #line 2921 "src/compiler/Generator.pv"
            fprintf(file, "\n");
            #line 2922 "src/compiler/Generator.pv"
            struct GenericMap generics_void = *generics;
            #line 2923 "src/compiler/Generator.pv"
            generics_void.self_type = &self->root->type_void;

            #line 2925 "src/compiler/Generator.pv"
            struct String func_name = Generator__get_trait_function_name(self, name, trait_info, func_info, generics);
            #line 2926 "src/compiler/Generator.pv"
            if (Generator__write_function_definition(self, file, func_info, &generics_void, &func_name) == 0) {
                #line 2926 "src/compiler/Generator.pv"
                return 0;
            }
            #line 2927 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        } }
    }

    #line 2931 "src/compiler/Generator.pv"
    return true;
}

#line 2934 "src/compiler/Generator.pv"
bool Generator__write_primitive_definition(struct Generator* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 2935 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);

    #line 2937 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 2937 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_Impl__next(&__iter)) {
        #line 2937 "src/compiler/Generator.pv"
        struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

        #line 2938 "src/compiler/Generator.pv"
        Generator__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 2941 "src/compiler/Generator.pv"
    if (primitive_info->traits.length > 0) {
        #line 2941 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }

    #line 2943 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 2943 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 2943 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 2944 "src/compiler/Generator.pv"
        fprintf(file, "extern struct ");
        #line 2945 "src/compiler/Generator.pv"
        Generator__write_token(self, file, trait_info->name);
        #line 2946 "src/compiler/Generator.pv"
        fprintf(file, "VTable ");
        #line 2947 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, String__as_str(&name));
        #line 2948 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__");
        #line 2949 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, trait_info->name->value);
        #line 2950 "src/compiler/Generator.pv"
        fprintf(file, ";\n");
    } }

    #line 2953 "src/compiler/Generator.pv"
    return 1;
}

#line 2956 "src/compiler/Generator.pv"
bool Generator__write_trait_definition(struct Generator* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 2957 "src/compiler/Generator.pv"
    struct GenericMap void_self_generics = *generics;
    #line 2958 "src/compiler/Generator.pv"
    void_self_generics.self_type = &self->root->type_void;

    #line 2960 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2961 "src/compiler/Generator.pv"
    int32_t name_length = name.array.length;

    #line 2963 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, &trait_info->module->context, trait_info->name);

    #line 2965 "src/compiler/Generator.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 2966 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 2968 "src/compiler/Generator.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 2968 "src/compiler/Generator.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 2968 "src/compiler/Generator.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 2969 "src/compiler/Generator.pv"
        if (func_info->generics.array.length == 0) {
            #line 2970 "src/compiler/Generator.pv"
            struct String func_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
            #line 2971 "src/compiler/Generator.pv"
            String__append(&func_name, (struct str){ .ptr = "(*", .length = strlen("(*") });
            #line 2972 "src/compiler/Generator.pv"
            String__append(&func_name, func_info->name->value);
            #line 2973 "src/compiler/Generator.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });
            #line 2974 "src/compiler/Generator.pv"
            if (Generator__write_function_definition(self, file, func_info, &void_self_generics, &func_name) == 0) {
                #line 2974 "src/compiler/Generator.pv"
                return 0;
            }
            #line 2975 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 2979 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 2980 "src/compiler/Generator.pv"
    fprintf(file, "};\n\n");

    #line 2982 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, &trait_info->module->context, trait_info->name);

    #line 2984 "src/compiler/Generator.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 2985 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 2987 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2988 "src/compiler/Generator.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 2989 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2990 "src/compiler/Generator.pv"
    fprintf(file, "void* instance;\n");

    #line 2992 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 2993 "src/compiler/Generator.pv"
    fprintf(file, "};\n");

    #line 2995 "src/compiler/Generator.pv"
    return 1;
}

#line 2998 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Function* func_info, struct GenericMap* generics) {
    #line 2999 "src/compiler/Generator.pv"
    struct String trait_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 3001 "src/compiler/Generator.pv"
    String__append(&trait_name, struct_name);
    #line 3002 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 3003 "src/compiler/Generator.pv"
    String__append(&trait_name, trait_info->name->value);
    #line 3004 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 3005 "src/compiler/Generator.pv"
    String__append(&trait_name, func_info->name->value);

    #line 3007 "src/compiler/Generator.pv"
    return trait_name;
}

#line 3010 "src/compiler/Generator.pv"
bool Generator__write_impls(struct Generator* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics) {
    #line 3012 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 3013 "src/compiler/Generator.pv"
    int32_t name_length = name.array.length;
    #line 3014 "src/compiler/Generator.pv"
    struct String path = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 3016 "src/compiler/Generator.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 3018 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 3018 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 3018 "src/compiler/Generator.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 3018 "src/compiler/Generator.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 3019 "src/compiler/Generator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 3020 "src/compiler/Generator.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 3021 "src/compiler/Generator.pv"
        if (impl_functions != 0) {
            #line 3021 "src/compiler/Generator.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 3023 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 3023 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 3023 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 3024 "src/compiler/Generator.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 3025 "src/compiler/Generator.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 3026 "src/compiler/Generator.pv"
            if (impl_functions_for_impl != 0) {
                #line 3026 "src/compiler/Generator.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 3028 "src/compiler/Generator.pv"
            if (func_info->generics.array.length == 0) {
                #line 3029 "src/compiler/Generator.pv"
                fprintf(file, "\n");
                #line 3030 "src/compiler/Generator.pv"
                if (trait_info != 0) {
                    #line 3031 "src/compiler/Generator.pv"
                    struct GenericMap generics_void = *generics;
                    #line 3032 "src/compiler/Generator.pv"
                    generics_void.self_type = &self->root->type_void;

                    #line 3034 "src/compiler/Generator.pv"
                    struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                    #line 3035 "src/compiler/Generator.pv"
                    if (Generator__write_function_definition(self, file, func_info, &generics_void, &func_name) == 0) {
                        #line 3036 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 3037 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 3038 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 3041 "src/compiler/Generator.pv"
                    fprintf(file, " {\n");
                    #line 3042 "src/compiler/Generator.pv"
                    self->indent += 1;

                    #line 3044 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 3045 "src/compiler/Generator.pv"
                    Generator__write_type(self, file, generics->self_type, generics);
                    #line 3046 "src/compiler/Generator.pv"
                    fprintf(file, "* self = __self; (void)self;\n");

                    #line 3048 "src/compiler/Generator.pv"
                    struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                    #line 3049 "src/compiler/Generator.pv"
                    if (function_usage != 0) {
                        #line 3049 "src/compiler/Generator.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 3050 "src/compiler/Generator.pv"
                    self->function_context = &func_context;

                    #line 3052 "src/compiler/Generator.pv"
                    if (Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, 0, 1) == 0) {
                        #line 3053 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 3054 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 3055 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 3058 "src/compiler/Generator.pv"
                    self->indent -= 1;
                    #line 3059 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 3060 "src/compiler/Generator.pv"
                    fprintf(file, "}\n");

                    #line 3062 "src/compiler/Generator.pv"
                    self->function_context = 0;
                } else {
                    #line 3064 "src/compiler/Generator.pv"
                    if (Generator__write_function_definition(self, file, func_info, generics, 0) == 0) {
                        #line 3065 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 3066 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 3067 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 3070 "src/compiler/Generator.pv"
                    struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                    #line 3071 "src/compiler/Generator.pv"
                    if (function_usage != 0) {
                        #line 3071 "src/compiler/Generator.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 3072 "src/compiler/Generator.pv"
                    self->function_context = &func_context;

                    #line 3074 "src/compiler/Generator.pv"
                    if (!Generator__write_function_block(self, file, String__as_str(&name), func_info, generics)) {
                        #line 3075 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 3076 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 3077 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 3080 "src/compiler/Generator.pv"
                    struct TypeFunctionUsage* function_usage = 0;
                    #line 3081 "src/compiler/Generator.pv"
                    if (impl_functions_for_impl != 0) {
                        #line 3081 "src/compiler/Generator.pv"
                        function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                    }

                    #line 3083 "src/compiler/Generator.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 3084 "src/compiler/Generator.pv"
                        fprintf(file, "\n");
                        #line 3085 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3086 "src/compiler/Generator.pv"
                            fprintf(file, "#include <std/Allocator.h>\n");
                        }

                        #line 3089 "src/compiler/Generator.pv"
                        fprintf(file, "#include <std/Array_TypeId.h>\n");
                        #line 3090 "src/compiler/Generator.pv"
                        fprintf(file, "struct Array_TypeId* ");
                        #line 3091 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 3093 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3094 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__get_params(void* __self) {\n");
                        } else {
                            #line 3096 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__get_params(void* __self) {\n");
                        }

                        #line 3099 "src/compiler/Generator.pv"
                        self->indent += 1;
                        #line 3100 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3101 "src/compiler/Generator.pv"
                        fprintf(file, "static TypeId type_ids[] = { ");

                        #line 3103 "src/compiler/Generator.pv"
                        bool first = true;
                        #line 3104 "src/compiler/Generator.pv"
                        { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 3104 "src/compiler/Generator.pv"
                        while (ArrayIter_ref_Parameter__next(&__iter)) {
                            #line 3104 "src/compiler/Generator.pv"
                            struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                            #line 3105 "src/compiler/Generator.pv"
                            if (first) {
                                #line 3105 "src/compiler/Generator.pv"
                                first = false;
                            } else {
                                #line 3105 "src/compiler/Generator.pv"
                                fprintf(file, ", ");
                            }
                            #line 3106 "src/compiler/Generator.pv"
                            Generator__write_typeid(self, file, &param->type, generics);
                        } }

                        #line 3109 "src/compiler/Generator.pv"
                        fprintf(file, " };\n");
                        #line 3110 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3111 "src/compiler/Generator.pv"
                        fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
                        #line 3112 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3113 "src/compiler/Generator.pv"
                        fprintf(file, "return &result;\n");
                        #line 3114 "src/compiler/Generator.pv"
                        self->indent -= 1;
                        #line 3115 "src/compiler/Generator.pv"
                        fprintf(file, "}\n");

                        #line 3117 "src/compiler/Generator.pv"
                        fprintf(file, "bool ");
                        #line 3118 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 3120 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3121 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        } else {
                            #line 3123 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        }

                        #line 3126 "src/compiler/Generator.pv"
                        self->indent += 1;

                        #line 3128 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3129 "src/compiler/Generator.pv"
                        fprintf(file, "struct ");
                        #line 3130 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 3132 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3133 "src/compiler/Generator.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
                        } else {
                            #line 3135 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__Instance* self = __self;\n");
                        }

                        #line 3138 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3139 "src/compiler/Generator.pv"
                        fprintf(file, "switch (index) {\n");
                        #line 3140 "src/compiler/Generator.pv"
                        self->indent += 1;

                        #line 3142 "src/compiler/Generator.pv"
                        uintptr_t i = 0;
                        #line 3143 "src/compiler/Generator.pv"
                        { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 3143 "src/compiler/Generator.pv"
                        while (ArrayIter_ref_Parameter__next(&__iter)) {
                            #line 3143 "src/compiler/Generator.pv"
                            struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                            #line 3144 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3145 "src/compiler/Generator.pv"
                            fprintf(file, "case %zu: self->", i);
                            #line 3146 "src/compiler/Generator.pv"
                            Generator__write_token(self, file, param->name);
                            #line 3147 "src/compiler/Generator.pv"
                            fprintf(file, " = ");

                            #line 3149 "src/compiler/Generator.pv"
                            if (!Generator__is_reference(&param->type)) {
                                #line 3150 "src/compiler/Generator.pv"
                                fprintf(file, "*(");
                                #line 3151 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, &param->type, generics);
                                #line 3152 "src/compiler/Generator.pv"
                                fprintf(file, "*)");
                            }

                            #line 3155 "src/compiler/Generator.pv"
                            fprintf(file, "value; return true;\n");
                            #line 3156 "src/compiler/Generator.pv"
                            i += 1;
                        } }

                        #line 3159 "src/compiler/Generator.pv"
                        self->indent -= 1;
                        #line 3160 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3161 "src/compiler/Generator.pv"
                        fprintf(file, "}\n");

                        #line 3163 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 3164 "src/compiler/Generator.pv"
                        fprintf(file, "return false;\n");

                        #line 3166 "src/compiler/Generator.pv"
                        self->indent -= 1;
                        #line 3167 "src/compiler/Generator.pv"
                        fprintf(file, "}\n");

                        #line 3169 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3170 "src/compiler/Generator.pv"
                            fprintf(file, "struct Iter_CoroutineStatus ");
                            #line 3171 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3172 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

                            #line 3174 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 3176 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3177 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 3178 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3179 "src/compiler/Generator.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

                            #line 3181 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3182 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 3183 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3184 "src/compiler/Generator.pv"
                            fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
                            #line 3185 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3186 "src/compiler/Generator.pv"
                            fprintf(file, "));\n");

                            #line 3188 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 3188 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_Parameter__next(&__iter)) {
                                #line 3188 "src/compiler/Generator.pv"
                                struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                                #line 3189 "src/compiler/Generator.pv"
                                Generator__write_indent(self, file);
                                #line 3190 "src/compiler/Generator.pv"
                                fprintf(file, "instance->");
                                #line 3191 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 3192 "src/compiler/Generator.pv"
                                fprintf(file, " = ");
                                #line 3193 "src/compiler/Generator.pv"
                                fprintf(file, "self->");
                                #line 3194 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 3195 "src/compiler/Generator.pv"
                                fprintf(file, ";\n");
                            } }

                            #line 3198 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3199 "src/compiler/Generator.pv"
                            fprintf(file, "return (struct Iter_CoroutineStatus) { .vtable = &");

                            #line 3201 "src/compiler/Generator.pv"
                            switch (func_info->parent.type) {
                                #line 3202 "src/compiler/Generator.pv"
                                case FUNCTION_PARENT__STRUCT: {
                                    #line 3202 "src/compiler/Generator.pv"
                                    struct Struct* struct_info = func_info->parent.struct_value._0;
                                    #line 3203 "src/compiler/Generator.pv"
                                    Generator__write_str_title(self, file, struct_info->name->value);
                                    #line 3204 "src/compiler/Generator.pv"
                                    fprintf(file, "__");
                                } break;
                                #line 3206 "src/compiler/Generator.pv"
                                default: {
                                } break;
                            }
                            #line 3208 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, func_info->name->value);

                            #line 3210 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

                            #line 3212 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 3213 "src/compiler/Generator.pv"
                            fprintf(file, "}\n");
                        } else {
                            #line 3215 "src/compiler/Generator.pv"
                            fprintf(file, "void ");
                            #line 3216 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3217 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__execute(void* __self) {\n");

                            #line 3219 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 3221 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3222 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 3223 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3224 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__Instance* self = __self;\n");

                            #line 3226 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3227 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3228 "src/compiler/Generator.pv"
                            fprintf(file, "(");

                            #line 3230 "src/compiler/Generator.pv"
                            first = true;
                            #line 3231 "src/compiler/Generator.pv"
                            { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 3231 "src/compiler/Generator.pv"
                            while (ArrayIter_ref_Parameter__next(&__iter)) {
                                #line 3231 "src/compiler/Generator.pv"
                                struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                                #line 3232 "src/compiler/Generator.pv"
                                if (first) {
                                    #line 3232 "src/compiler/Generator.pv"
                                    first = false;
                                } else {
                                    #line 3232 "src/compiler/Generator.pv"
                                    fprintf(file, ", ");
                                }
                                #line 3233 "src/compiler/Generator.pv"
                                fprintf(file, "self->");
                                #line 3234 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                            } }

                            #line 3237 "src/compiler/Generator.pv"
                            fprintf(file, ");\n");

                            #line 3239 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 3240 "src/compiler/Generator.pv"
                            fprintf(file, "}\n");
                        }

                        #line 3243 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3244 "src/compiler/Generator.pv"
                            fprintf(file, "struct Co_CoroutineStatusVTable ");
                        } else {
                            #line 3246 "src/compiler/Generator.pv"
                            fprintf(file, "struct FnVTable ");
                        }

                        #line 3249 "src/compiler/Generator.pv"
                        switch (func_info->parent.type) {
                            #line 3250 "src/compiler/Generator.pv"
                            case FUNCTION_PARENT__STRUCT: {
                                #line 3250 "src/compiler/Generator.pv"
                                struct Struct* struct_info = func_info->parent.struct_value._0;
                                #line 3251 "src/compiler/Generator.pv"
                                Generator__write_str_title(self, file, struct_info->name->value);
                                #line 3252 "src/compiler/Generator.pv"
                                fprintf(file, "__");
                            } break;
                            #line 3254 "src/compiler/Generator.pv"
                            default: {
                            } break;
                        }
                        #line 3256 "src/compiler/Generator.pv"
                        Generator__write_str_title(self, file, func_info->name->value);

                        #line 3258 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3259 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__DYN_CO");
                        } else {
                            #line 3261 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__DYN_FN");
                        }

                        #line 3264 "src/compiler/Generator.pv"
                        fprintf(file, " = { .get_params = &");
                        #line 3265 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 3267 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3268 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__get_params, .set_arg = &");
                            #line 3269 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3270 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__set_arg, .init = &");
                            #line 3271 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3272 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__init };\n");
                        } else {
                            #line 3274 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__get_params, .set_arg = &");
                            #line 3275 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3276 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__set_arg, .execute = &");
                            #line 3277 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3278 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__execute };\n");
                        }
                    }

                    #line 3282 "src/compiler/Generator.pv"
                    self->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 3285 "src/compiler/Generator.pv"
                if (function_usage != 0) {
                    #line 3286 "src/compiler/Generator.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Function));
                    #line 3287 "src/compiler/Generator.pv"
                    *func2 = *func_info;

                    #line 3290 "src/compiler/Generator.pv"
                    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&function_usage->generic_maps);
                    #line 3290 "src/compiler/Generator.pv"
                    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
                        #line 3290 "src/compiler/Generator.pv"
                        struct GenericMap* generics3 = *ArrayIter_ref_ref_GenericMap__value(&__iter);

                        #line 3291 "src/compiler/Generator.pv"
                        generics3->self_type = generics->self_type;

                        #line 3293 "src/compiler/Generator.pv"
                        fprintf(file, "\n");
                        #line 3294 "src/compiler/Generator.pv"
                        if (Generator__write_function_definition(self, file, func_info, generics3, 0) == 0) {
                            #line 3295 "src/compiler/Generator.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 3296 "src/compiler/Generator.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 3297 "src/compiler/Generator.pv"
                            return false;
                        }

                        #line 3300 "src/compiler/Generator.pv"
                        struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                        #line 3301 "src/compiler/Generator.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                        #line 3302 "src/compiler/Generator.pv"
                        self->function_context = &func_context;

                        #line 3304 "src/compiler/Generator.pv"
                        Generator__write_function_block(self, file, String__as_str(&name), func_info, generics3);

                        #line 3306 "src/compiler/Generator.pv"
                        self->function_context = 0;
                    } }
                }
            }
        } }
        #line 3313 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 3314 "src/compiler/Generator.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 3314 "src/compiler/Generator.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 3314 "src/compiler/Generator.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 3314 "src/compiler/Generator.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 3315 "src/compiler/Generator.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 3315 "src/compiler/Generator.pv"
                    continue;
                }

                #line 3317 "src/compiler/Generator.pv"
                fprintf(file, "\n");
                #line 3318 "src/compiler/Generator.pv"
                struct GenericMap generics_void = *generics;
                #line 3319 "src/compiler/Generator.pv"
                generics_void.self_type = &self->root->type_void;

                #line 3321 "src/compiler/Generator.pv"
                struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                #line 3322 "src/compiler/Generator.pv"
                if (Generator__write_function_definition(self, file, func_info, &generics_void, &func_name) == 0) {
                    #line 3323 "src/compiler/Generator.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 3324 "src/compiler/Generator.pv"
                    fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 3325 "src/compiler/Generator.pv"
                    return false;
                }

                #line 3328 "src/compiler/Generator.pv"
                fprintf(file, " {\n");
                #line 3329 "src/compiler/Generator.pv"
                self->indent += 1;

                #line 3331 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 3332 "src/compiler/Generator.pv"
                Generator__write_type(self, file, generics->self_type, generics);
                #line 3333 "src/compiler/Generator.pv"
                fprintf(file, "* self = __self; (void)self;\n");

                #line 3335 "src/compiler/Generator.pv"
                struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                #line 3336 "src/compiler/Generator.pv"
                self->function_context = &func_context;

                #line 3338 "src/compiler/Generator.pv"
                if (Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, 0, 1) == 0) {
                    #line 3339 "src/compiler/Generator.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 3340 "src/compiler/Generator.pv"
                    fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 3341 "src/compiler/Generator.pv"
                    return false;
                }

                #line 3344 "src/compiler/Generator.pv"
                self->indent -= 1;
                #line 3345 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 3346 "src/compiler/Generator.pv"
                fprintf(file, "}\n");

                #line 3348 "src/compiler/Generator.pv"
                self->function_context = 0;
            } }
        }
    } }

    #line 3353 "src/compiler/Generator.pv"
    return true;
}

#line 3356 "src/compiler/Generator.pv"
bool Generator__generate_struct_loop(struct Generator* self, struct TypeUsage_Struct* usage) {
    #line 3357 "src/compiler/Generator.pv"
    bool success = true;
    #line 3358 "src/compiler/Generator.pv"
    struct Struct* struct_info = usage->type;

    #line 3360 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&usage->generic_maps);
    #line 3360 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
        #line 3360 "src/compiler/Generator.pv"
        struct GenericMap* generics = *ArrayIter_ref_ref_GenericMap__value(&__iter);

        #line 3361 "src/compiler/Generator.pv"
        success = Generator__generate_struct(self, struct_info, usage, generics) && success;
    } }

    #line 3364 "src/compiler/Generator.pv"
    return success;
}

#line 3367 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 3368 "src/compiler/Generator.pv"
    struct String result = Generator__make_rel_path(self, module, name, ext);
    #line 3369 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 3370 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = self->path, .length = strlen(self->path) });
    #line 3371 "src/compiler/Generator.pv"
    return result;
}

#line 3374 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 3375 "src/compiler/Generator.pv"
    struct String result = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3376 "src/compiler/Generator.pv"
    struct Namespace* namespace = 0;
    #line 3377 "src/compiler/Generator.pv"
    if (module != 0) {
        #line 3377 "src/compiler/Generator.pv"
        namespace = module->namespace;
    }

    #line 3379 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 3380 "src/compiler/Generator.pv"
        String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 3381 "src/compiler/Generator.pv"
        String__prepend(&result, namespace->name);
        #line 3382 "src/compiler/Generator.pv"
        namespace = namespace->parent;
    }

    #line 3385 "src/compiler/Generator.pv"
    String__append(&result, name);
    #line 3386 "src/compiler/Generator.pv"
    String__append(&result, ext);

    #line 3388 "src/compiler/Generator.pv"
    return result;
}

#line 3391 "src/compiler/Generator.pv"
bool Generator__generate_struct(struct Generator* self, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct GenericMap* generics) {
    #line 3392 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 3393 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3394 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3395 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3396 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3396 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3396 "src/compiler/Generator.pv"
        return false;
    }

    #line 3398 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3399 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3400 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3401 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3402 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3404 "src/compiler/Generator.pv"
    if (struct_info->module->mode_cpp || usage->usage_context.cpp_usages.length > 0) {
        #line 3405 "src/compiler/Generator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 3407 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&usage->usage_context.cpp_usages);
        #line 3407 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Type__next(&__iter)) {
            #line 3407 "src/compiler/Generator.pv"
            struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
            #line 3407 "src/compiler/Generator.pv"
            struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

            #line 3408 "src/compiler/Generator.pv"
            switch (type->type) {
                #line 3409 "src/compiler/Generator.pv"
                case TYPE__CLASS_CPP: {
                    #line 3409 "src/compiler/Generator.pv"
                    struct ClassCpp* class_info = type->classcpp_value;
                    #line 3410 "src/compiler/Generator.pv"
                    if (class_info->is_struct) {
                        #line 3411 "src/compiler/Generator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 3413 "src/compiler/Generator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 3416 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } }

        #line 3420 "src/compiler/Generator.pv"
        if (struct_info->module->mode_cpp) {
            #line 3421 "src/compiler/Generator.pv"
            if (usage->usage_context.cpp_usages.length > 0) {
                #line 3421 "src/compiler/Generator.pv"
                fprintf(header_file, "\n");
            }
            #line 3422 "src/compiler/Generator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 3425 "src/compiler/Generator.pv"
        fprintf(header_file, "#else\n");

        #line 3427 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&usage->usage_context.cpp_usages);
        #line 3427 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Type__next(&__iter)) {
            #line 3427 "src/compiler/Generator.pv"
            struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;

            #line 3428 "src/compiler/Generator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 3431 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 3434 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(&generics->array);
    #line 3434 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 3434 "src/compiler/Generator.pv"
        struct Type* type = ArrayIter_ref_Type__value(&__iter);

        #line 3435 "src/compiler/Generator.pv"
        Generator__write_c_type_include(self, header_file, Type__deref(type));
    } }

    #line 3438 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3439 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude refs_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3440 "src/compiler/Generator.pv"
    if (Generator__add_struct_definition_includes(self, &includes_definition, &refs_definition, struct_info, generics) == 0) {
        #line 3440 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3440 "src/compiler/Generator.pv"
        return false;
    }
    #line 3441 "src/compiler/Generator.pv"
    if (Generator__add_impl_definition_includes(self, &includes_definition, &refs_definition, &struct_info->impls, &usage->impl_functions, generics) == 0) {
        #line 3441 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3441 "src/compiler/Generator.pv"
        return false;
    }
    #line 3442 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes_definition);
    #line 3443 "src/compiler/Generator.pv"
    Generator__write_refs(self, header_file, &refs_definition);
    #line 3444 "src/compiler/Generator.pv"
    if (!struct_info->module->mode_cpp) {
        #line 3445 "src/compiler/Generator.pv"
        Generator__write_includes_raw(self, header_file, &struct_info->module->includes);
    }

    #line 3448 "src/compiler/Generator.pv"
    if (Generator__write_struct_definition(self, header_file, struct_info, usage, generics) == 0) {
        #line 3448 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3448 "src/compiler/Generator.pv"
        return false;
    }

    #line 3450 "src/compiler/Generator.pv"
    if (struct_info->module->mode_cpp) {
        #line 3451 "src/compiler/Generator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 3452 "src/compiler/Generator.pv"
        fprintf(header_file, "}\n");
        #line 3453 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 3456 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3458 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3459 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3460 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3462 "src/compiler/Generator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage) {
        #line 3463 "src/compiler/Generator.pv"
        return true;
    }

    #line 3466 "src/compiler/Generator.pv"
    struct str ext;
    #line 3467 "src/compiler/Generator.pv"
    if (struct_info->module->mode_cpp) {
        #line 3468 "src/compiler/Generator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 3470 "src/compiler/Generator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 3473 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, struct_info->module, String__as_str(&name), ext);
    #line 3474 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 3476 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 3477 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 3478 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 3478 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 3478 "src/compiler/Generator.pv"
        return false;
    }

    #line 3480 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_code = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3481 "src/compiler/Generator.pv"
    if (Generator__add_impl_includes(self, &includes_code, &struct_info->impls, &usage->impl_functions, generics) == 0) {
        #line 3481 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3481 "src/compiler/Generator.pv"
        return false;
    }
    #line 3482 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, code_file, &struct_info->module->includes);

    #line 3484 "src/compiler/Generator.pv"
    struct str name_str = String__as_str(&name);
    #line 3485 "src/compiler/Generator.pv"
    HashMap_str_GeneratorInclude__remove(&includes_code, &name_str);

    #line 3487 "src/compiler/Generator.pv"
    Generator__write_includes(self, code_file, &includes_code);

    #line 3489 "src/compiler/Generator.pv"
    if (Generator__write_impls(self, code_file, struct_info->module, &struct_info->impls, &usage->impl_functions, generics) == 0) {
        #line 3489 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3489 "src/compiler/Generator.pv"
        return false;
    }

    #line 3491 "src/compiler/Generator.pv"
    if (struct_info->traits.length > 0) {
        #line 3492 "src/compiler/Generator.pv"
        fprintf(code_file, "\n");
    }

    #line 3495 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&struct_info->traits);
    #line 3495 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 3495 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 3496 "src/compiler/Generator.pv"
        fprintf(code_file, "struct ");
        #line 3497 "src/compiler/Generator.pv"
        Generator__write_token(self, code_file, trait_info->name);
        #line 3498 "src/compiler/Generator.pv"
        fprintf(code_file, "VTable ");
        #line 3499 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, String__as_str(&name));
        #line 3500 "src/compiler/Generator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 3501 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, trait_info->name->value);
        #line 3502 "src/compiler/Generator.pv"
        fprintf(code_file, " = { ");

        #line 3504 "src/compiler/Generator.pv"
        bool first = true;
        #line 3505 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 3505 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 3505 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 3506 "src/compiler/Generator.pv"
            if (first) {
                #line 3506 "src/compiler/Generator.pv"
                first = false;
            } else {
                #line 3507 "src/compiler/Generator.pv"
                fprintf(code_file, ", ");
            }

            #line 3509 "src/compiler/Generator.pv"
            fprintf(code_file, ".");
            #line 3510 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, func_info->name);
            #line 3511 "src/compiler/Generator.pv"
            fprintf(code_file, " = &");
            #line 3512 "src/compiler/Generator.pv"
            struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
            #line 3513 "src/compiler/Generator.pv"
            Generator__write_string(self, code_file, &func_name);
        } }

        #line 3516 "src/compiler/Generator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 3519 "src/compiler/Generator.pv"
    if (usage->impl_dynamic_usage) {
        #line 3520 "src/compiler/Generator.pv"
        fprintf(code_file, "\n");

        #line 3522 "src/compiler/Generator.pv"
        fprintf(code_file, "#include <std/StructField.h>\n");
        #line 3523 "src/compiler/Generator.pv"
        fprintf(code_file, "#include <slice_StructField.h>\n");
        #line 3524 "src/compiler/Generator.pv"
        fprintf(code_file, "struct slice_StructField ");
        #line 3525 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3526 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 3528 "src/compiler/Generator.pv"
        self->indent += 1;
        #line 3529 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3530 "src/compiler/Generator.pv"
        fprintf(code_file, "static struct StructField fields[] = { ");

        #line 3532 "src/compiler/Generator.pv"
        bool first = true;
        #line 3533 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 3533 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 3533 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 3534 "src/compiler/Generator.pv"
            if (first) {
                #line 3534 "src/compiler/Generator.pv"
                first = false;
            } else {
                #line 3534 "src/compiler/Generator.pv"
                fprintf(code_file, ", ");
            }
            #line 3535 "src/compiler/Generator.pv"
            fprintf(code_file, "(struct StructField){ .name = (struct str){ .ptr = \"");
            #line 3536 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, field->name);
            #line 3537 "src/compiler/Generator.pv"
            fprintf(code_file, "\", .length = %zu }, .typeid = ", field->name->value.length);
            #line 3538 "src/compiler/Generator.pv"
            Generator__write_typeid(self, code_file, &field->type, generics);
            #line 3539 "src/compiler/Generator.pv"
            fprintf(code_file, " }");
        } }

        #line 3542 "src/compiler/Generator.pv"
        fprintf(code_file, " };\n");
        #line 3543 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3544 "src/compiler/Generator.pv"
        fprintf(code_file, "return (struct slice_StructField){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 3545 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3546 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3548 "src/compiler/Generator.pv"
        fprintf(code_file, "void* ");
        #line 3549 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);

        #line 3551 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 3553 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3555 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3556 "src/compiler/Generator.pv"
        fprintf(code_file, "struct ");
        #line 3557 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3558 "src/compiler/Generator.pv"
        fprintf(code_file, "* self = __self;\n");

        #line 3560 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3561 "src/compiler/Generator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 3562 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3564 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 3565 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 3565 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 3565 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 3566 "src/compiler/Generator.pv"
            Generator__write_indent(self, code_file);
            #line 3567 "src/compiler/Generator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 3569 "src/compiler/Generator.pv"
            if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                #line 3570 "src/compiler/Generator.pv"
                fprintf(code_file, "&");
            }

            #line 3573 "src/compiler/Generator.pv"
            fprintf(code_file, "self->");
            #line 3574 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, field->name);
            #line 3575 "src/compiler/Generator.pv"
            fprintf(code_file, ";\n");
            #line 3576 "src/compiler/Generator.pv"
            i += 1;
        } }

        #line 3579 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3580 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3581 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3583 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3584 "src/compiler/Generator.pv"
        fprintf(code_file, "return 0;\n");

        #line 3586 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3587 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3589 "src/compiler/Generator.pv"
        fprintf(code_file, "bool ");
        #line 3590 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);

        #line 3592 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 3594 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3596 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3597 "src/compiler/Generator.pv"
        fprintf(code_file, "struct ");
        #line 3598 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3599 "src/compiler/Generator.pv"
        fprintf(code_file, "* self = __self;\n");

        #line 3601 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3602 "src/compiler/Generator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 3603 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3605 "src/compiler/Generator.pv"
        i = 0;
        #line 3606 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 3606 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 3606 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 3607 "src/compiler/Generator.pv"
            Generator__write_indent(self, code_file);
            #line 3608 "src/compiler/Generator.pv"
            fprintf(code_file, "case %zu: self->", i);
            #line 3609 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, field->name);
            #line 3610 "src/compiler/Generator.pv"
            fprintf(code_file, " = ");

            #line 3612 "src/compiler/Generator.pv"
            if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                #line 3613 "src/compiler/Generator.pv"
                fprintf(code_file, "*(");
                #line 3614 "src/compiler/Generator.pv"
                Generator__write_type(self, code_file, &field->type, generics);
                #line 3615 "src/compiler/Generator.pv"
                fprintf(code_file, "*)");
            }

            #line 3618 "src/compiler/Generator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 3619 "src/compiler/Generator.pv"
            i += 1;
        } }

        #line 3622 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3623 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3624 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3626 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3627 "src/compiler/Generator.pv"
        fprintf(code_file, "return false;\n");

        #line 3629 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3630 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3632 "src/compiler/Generator.pv"
        fprintf(code_file, "struct StructVTable ");
        #line 3633 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, String__as_str(&name));
        #line 3634 "src/compiler/Generator.pv"
        fprintf(code_file, "__VTABLE__DYN_STRUCT");
        #line 3635 "src/compiler/Generator.pv"
        fprintf(code_file, " = { .get_fields = &");
        #line 3636 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);

        #line 3638 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_fields, .get_field = &");
        #line 3639 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3640 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_field, .set_field = &");
        #line 3641 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3642 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 3645 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 3646 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 3647 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 3649 "src/compiler/Generator.pv"
    return true;
}

#line 3652 "src/compiler/Generator.pv"
bool Generator__generate_primitive(struct Generator* self, struct TypeUsage_Primitive* usage) {
    #line 3653 "src/compiler/Generator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 3654 "src/compiler/Generator.pv"
    struct Type self_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info };
    #line 3655 "src/compiler/Generator.pv"
    struct GenericMap generics = (struct GenericMap) { .self_type = &self_type };
    #line 3656 "src/compiler/Generator.pv"
    struct str name = primitive_info->name;

    #line 3658 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3659 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3660 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3661 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3661 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3661 "src/compiler/Generator.pv"
        return false;
    }

    #line 3663 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3664 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name);
    #line 3665 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3666 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name);
    #line 3667 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3669 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3670 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude refs_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3671 "src/compiler/Generator.pv"
    if (Generator__add_impl_definition_includes(self, &includes_definition, &refs_definition, &primitive_info->impls, &usage->impl_functions, &generics) == 0) {
        #line 3671 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3671 "src/compiler/Generator.pv"
        return false;
    }

    #line 3673 "src/compiler/Generator.pv"
    Generator__write_impl_includes_raw(self, header_file, &primitive_info->impls);
    #line 3674 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes_definition);
    #line 3675 "src/compiler/Generator.pv"
    Generator__write_refs(self, header_file, &refs_definition);

    #line 3677 "src/compiler/Generator.pv"
    if (Generator__write_primitive_definition(self, header_file, primitive_info, &generics) == 0) {
        #line 3677 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3677 "src/compiler/Generator.pv"
        return false;
    }

    #line 3679 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3681 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3682 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3683 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3685 "src/compiler/Generator.pv"
    if (primitive_info->impls.length == 0) {
        #line 3686 "src/compiler/Generator.pv"
        return true;
    }

    #line 3689 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 3690 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 3692 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 3693 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 3694 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 3694 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 3694 "src/compiler/Generator.pv"
        return false;
    }

    #line 3696 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_code = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3697 "src/compiler/Generator.pv"
    if (Generator__add_impl_includes(self, &includes_code, &primitive_info->impls, &usage->impl_functions, &generics) == 0) {
        #line 3697 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3697 "src/compiler/Generator.pv"
        return false;
    }
    #line 3698 "src/compiler/Generator.pv"
    Generator__write_includes(self, code_file, &includes_code);

    #line 3700 "src/compiler/Generator.pv"
    if (Generator__write_impls(self, code_file, 0, &primitive_info->impls, &usage->impl_functions, &generics) == 0) {
        #line 3700 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3700 "src/compiler/Generator.pv"
        return false;
    }

    #line 3702 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 3702 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 3702 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 3703 "src/compiler/Generator.pv"
        fprintf(code_file, "\nstruct ");
        #line 3704 "src/compiler/Generator.pv"
        Generator__write_token(self, code_file, trait_info->name);
        #line 3705 "src/compiler/Generator.pv"
        fprintf(code_file, "VTable ");
        #line 3706 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, name);
        #line 3707 "src/compiler/Generator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 3708 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, trait_info->name->value);
        #line 3709 "src/compiler/Generator.pv"
        fprintf(code_file, " = { ");

        #line 3711 "src/compiler/Generator.pv"
        bool first = true;
        #line 3712 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 3712 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 3712 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 3713 "src/compiler/Generator.pv"
            if (first) {
                #line 3713 "src/compiler/Generator.pv"
                first = false;
            } else {
                #line 3714 "src/compiler/Generator.pv"
                fprintf(code_file, ", ");
            }

            #line 3716 "src/compiler/Generator.pv"
            fprintf(code_file, ".");
            #line 3717 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, func_info->name);
            #line 3718 "src/compiler/Generator.pv"
            fprintf(code_file, " = &");
            #line 3719 "src/compiler/Generator.pv"
            struct String func_name = Generator__get_trait_function_name(self, name, trait_info, func_info, &generics);
            #line 3720 "src/compiler/Generator.pv"
            Generator__write_string(self, code_file, &func_name);
        } }

        #line 3723 "src/compiler/Generator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 3726 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 3727 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 3728 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 3730 "src/compiler/Generator.pv"
    return true;
}

#line 3733 "src/compiler/Generator.pv"
bool Generator__generate_slice(struct Generator* self, struct Type* element_type) {
    #line 3734 "src/compiler/Generator.pv"
    struct GenericMap generics = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 3735 "src/compiler/Generator.pv"
    GenericMap__insert(&generics, (struct str){ .ptr = "T", .length = strlen("T") }, *element_type);

    #line 3737 "src/compiler/Generator.pv"
    struct Sequence sequence = (struct Sequence) { .type = (struct SequenceType) { .type = SEQUENCE_TYPE__SLICE }, .element = *element_type };
    #line 3738 "src/compiler/Generator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = &sequence };
    #line 3739 "src/compiler/Generator.pv"
    struct Indirect sequence_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type };

    #line 3741 "src/compiler/Generator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 3742 "src/compiler/Generator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 3744 "src/compiler/Generator.pv"
    generics.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &sequence_indirect });

    #line 3746 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &sequence_type, &sequence_type, &generics);

    #line 3748 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3749 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3750 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3751 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3751 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3751 "src/compiler/Generator.pv"
        return false;
    }

    #line 3753 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3754 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3755 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3756 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3757 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3759 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3760 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude refs_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 3762 "src/compiler/Generator.pv"
    Generator__write_c_type_include(self, header_file, element_type);

    #line 3764 "src/compiler/Generator.pv"
    Generator__add_type_include(self, &includes_definition, &refs_definition, &includes_definition, &element_reference_type, &generics);
    #line 3765 "src/compiler/Generator.pv"
    Generator__add_type_include(self, &includes_definition, &refs_definition, &includes_definition, &self->root->type_usize, &generics);

    #line 3767 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes_definition);
    #line 3768 "src/compiler/Generator.pv"
    Generator__write_refs(self, header_file, &refs_definition);

    #line 3770 "src/compiler/Generator.pv"
    fprintf(header_file, "struct ");
    #line 3771 "src/compiler/Generator.pv"
    Generator__write_string(self, header_file, &name);
    #line 3772 "src/compiler/Generator.pv"
    fprintf(header_file, " { ");

    #line 3774 "src/compiler/Generator.pv"
    Generator__write_variable_decl(self, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, &generics);
    #line 3775 "src/compiler/Generator.pv"
    fprintf(header_file, "; ");
    #line 3776 "src/compiler/Generator.pv"
    Generator__write_variable_decl(self, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &self->root->type_usize, &generics);

    #line 3778 "src/compiler/Generator.pv"
    fprintf(header_file, "; };\n");

    #line 3780 "src/compiler/Generator.pv"
    Generator__write_impl_definition(self, header_file, String__as_str(&name), self->root->hack_type_impl->impl_info, &generics);

    #line 3782 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3784 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3785 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3786 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3788 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 3789 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 3791 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 3792 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 3793 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 3793 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 3793 "src/compiler/Generator.pv"
        return false;
    }

    #line 3795 "src/compiler/Generator.pv"
    struct Impl* impls_base[1] = {self->root->hack_type_impl->impl_info};
    #line 3796 "src/compiler/Generator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1 };
    #line 3797 "src/compiler/Generator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0 };

    #line 3799 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_code = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3800 "src/compiler/Generator.pv"
    if (Generator__add_impl_includes(self, &includes_code, &impls, &impl_functions, &generics) == 0) {
        #line 3800 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3800 "src/compiler/Generator.pv"
        return false;
    }
    #line 3801 "src/compiler/Generator.pv"
    Generator__write_includes(self, code_file, &includes_code);

    #line 3803 "src/compiler/Generator.pv"
    if (Generator__write_impls(self, code_file, 0, &impls, &impl_functions, &generics) == 0) {
        #line 3803 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3803 "src/compiler/Generator.pv"
        return false;
    }

    #line 3805 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 3806 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 3807 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 3809 "src/compiler/Generator.pv"
    return true;
}

#line 3812 "src/compiler/Generator.pv"
bool Generator__generate_tuple(struct Generator* self, struct Tuple* tuple) {
    #line 3813 "src/compiler/Generator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 3814 "src/compiler/Generator.pv"
    struct GenericMap generics = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 3815 "src/compiler/Generator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 3817 "src/compiler/Generator.pv"
    generics.self_type = ArenaAllocator__store_Type(self->allocator, tuple_type);

    #line 3819 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &tuple_type, &tuple_type, &generics);

    #line 3821 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3822 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3823 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3824 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3824 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3824 "src/compiler/Generator.pv"
        return false;
    }

    #line 3826 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3827 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3828 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3829 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3830 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3832 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3833 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude refs_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 3835 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(element_types);
    #line 3835 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 3835 "src/compiler/Generator.pv"
        struct Type* type = ArrayIter_ref_Type__value(&__iter);

        #line 3836 "src/compiler/Generator.pv"
        Generator__write_c_type_include(self, header_file, type);
        #line 3837 "src/compiler/Generator.pv"
        Generator__add_type_include(self, &includes_definition, &refs_definition, &includes_definition, type, &generics);
    } }

    #line 3840 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes_definition);
    #line 3841 "src/compiler/Generator.pv"
    Generator__write_refs(self, header_file, &refs_definition);

    #line 3843 "src/compiler/Generator.pv"
    fprintf(header_file, "struct ");
    #line 3844 "src/compiler/Generator.pv"
    Generator__write_string(self, header_file, &name);
    #line 3845 "src/compiler/Generator.pv"
    fprintf(header_file, " {\n");
    #line 3846 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 3848 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_Type __iter = ArrayIter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 3848 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 3848 "src/compiler/Generator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 3848 "src/compiler/Generator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 3849 "src/compiler/Generator.pv"
        struct String element_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 3850 "src/compiler/Generator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 3851 "src/compiler/Generator.pv"
        String__append_usize(&element_name, i);

        #line 3853 "src/compiler/Generator.pv"
        Generator__write_indent(self, header_file);
        #line 3854 "src/compiler/Generator.pv"
        Generator__write_variable_decl(self, header_file, String__as_str(&element_name), element, &generics);

        #line 3856 "src/compiler/Generator.pv"
        fprintf(header_file, ";\n");

        #line 3858 "src/compiler/Generator.pv"
        String__release(&element_name);
    } }

    #line 3861 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 3862 "src/compiler/Generator.pv"
    fprintf(header_file, "};\n");

    #line 3864 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3866 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3867 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3868 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3870 "src/compiler/Generator.pv"
    return true;
}

#line 3873 "src/compiler/Generator.pv"
bool Generator__generate_trait_loop(struct Generator* self, struct TypeUsage_Trait* usage) {
    #line 3874 "src/compiler/Generator.pv"
    bool success = true;
    #line 3875 "src/compiler/Generator.pv"
    struct Trait* trait_info = usage->type;

    #line 3877 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_GenericMap __iter = Array_ref_GenericMap__iter(&usage->generic_maps);
    #line 3877 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_GenericMap__next(&__iter)) {
        #line 3877 "src/compiler/Generator.pv"
        struct GenericMap* generics = *ArrayIter_ref_ref_GenericMap__value(&__iter);

        #line 3878 "src/compiler/Generator.pv"
        success = Generator__generate_trait(self, trait_info, generics) && success;
    } }

    #line 3881 "src/compiler/Generator.pv"
    return success;
}

#line 3884 "src/compiler/Generator.pv"
bool Generator__generate_trait(struct Generator* self, struct Trait* trait_info, struct GenericMap* generics) {
    #line 3885 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 3886 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 3888 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3889 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3890 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3890 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3890 "src/compiler/Generator.pv"
        return false;
    }

    #line 3892 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3893 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3894 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3895 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3896 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3898 "src/compiler/Generator.pv"
    if (trait_info->module->mode_cpp) {
        #line 3899 "src/compiler/Generator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 3900 "src/compiler/Generator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 3901 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 3904 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude includes_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3905 "src/compiler/Generator.pv"
    struct HashMap_str_GeneratorInclude refs_definition = HashMap_str_GeneratorInclude__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3906 "src/compiler/Generator.pv"
    if (Generator__add_trait_definition_includes(self, &includes_definition, &refs_definition, trait_info, generics) == 0) {
        #line 3906 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3906 "src/compiler/Generator.pv"
        return 0;
    }
    #line 3907 "src/compiler/Generator.pv"
    Generator__write_includes(self, header_file, &includes_definition);
    #line 3908 "src/compiler/Generator.pv"
    Generator__write_refs(self, header_file, &refs_definition);
    #line 3909 "src/compiler/Generator.pv"
    if (!trait_info->module->mode_cpp) {
        #line 3910 "src/compiler/Generator.pv"
        Generator__write_includes_raw(self, header_file, &trait_info->module->includes);
    }

    #line 3913 "src/compiler/Generator.pv"
    if (Generator__write_trait_definition(self, header_file, trait_info, generics) == 0) {
        #line 3913 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3913 "src/compiler/Generator.pv"
        return 0;
    }

    #line 3915 "src/compiler/Generator.pv"
    if (trait_info->module->mode_cpp) {
        #line 3916 "src/compiler/Generator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 3917 "src/compiler/Generator.pv"
        fprintf(header_file, "}\n");
        #line 3918 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 3921 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3923 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3924 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3925 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3927 "src/compiler/Generator.pv"
    return 1;
}

#line 3930 "src/compiler/Generator.pv"
void Generator__create_directories(struct Generator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 3931 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 3931 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 3931 "src/compiler/Generator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 3931 "src/compiler/Generator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 3932 "src/compiler/Generator.pv"
        struct String path = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 3933 "src/compiler/Generator.pv"
        String__append(&path, base_path);
        #line 3934 "src/compiler/Generator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 3935 "src/compiler/Generator.pv"
        String__append(&path, name);
        #line 3936 "src/compiler/Generator.pv"
        create_directory(String__c_str(&path));

        #line 3938 "src/compiler/Generator.pv"
        Generator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}

#line 3942 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Root* root) {
    #line 3943 "src/compiler/Generator.pv"
    bool result = true;

    #line 3945 "src/compiler/Generator.pv"
    struct Generator self = (struct Generator) {
        .allocator = allocator,
        .path = path,
        .root = root,
        .primitives = HashMap_str_str__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitive_includes = HashMap_str_str__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .code_files = Array_String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .error = FileWriter__new(stderr),
        .output_line_directives = output_line_directives,
        .naming_decl = &root->naming_decl,
        .naming_ident = Naming__new_ident(allocator),
    };

    #line 3958 "src/compiler/Generator.pv"
    self.naming_c99 = Naming__new_c99(allocator, &self.naming_ident);

    #line 3960 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitives = &self.primitives;
    #line 3961 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 3962 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 3963 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 3964 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 3965 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 3966 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 3967 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 3968 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 3969 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 3970 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 3971 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 3972 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 3973 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 3974 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 3975 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 3977 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitive_includes = &self.primitive_includes;
    #line 3978 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3979 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3980 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3981 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3982 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3983 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3984 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3985 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3986 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3987 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3988 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "stdbool", .length = strlen("stdbool") });

    #line 3990 "src/compiler/Generator.pv"
    Generator__create_directories(&self, (struct str){ .ptr = path, .length = strlen(path) }, &root->children);

    #line 3992 "src/compiler/Generator.pv"
    struct Usages usages = Usages__new(&self);
    #line 3993 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Primitive __iter = HashMap_usize_TypeUsage_Primitive__iter(&usages.primitives);
    #line 3993 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Primitive__next(&__iter)) {
        #line 3993 "src/compiler/Generator.pv"
        struct TypeUsage_Primitive* usage = &HashMapIter_usize_TypeUsage_Primitive__value(&__iter)->_1;

        #line 3993 "src/compiler/Generator.pv"
        Generator__generate_primitive(&self, usage);
    } }
    #line 3994 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Struct __iter = HashMap_usize_TypeUsage_Struct__iter(&usages.structs);
    #line 3994 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Struct__next(&__iter)) {
        #line 3994 "src/compiler/Generator.pv"
        struct TypeUsage_Struct* usage = &HashMapIter_usize_TypeUsage_Struct__value(&__iter)->_1;

        #line 3994 "src/compiler/Generator.pv"
        Generator__generate_struct_loop(&self, usage);
    } }
    #line 3995 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Enum __iter = HashMap_usize_TypeUsage_Enum__iter(&usages.enums);
    #line 3995 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Enum__next(&__iter)) {
        #line 3995 "src/compiler/Generator.pv"
        struct TypeUsage_Enum* usage = &HashMapIter_usize_TypeUsage_Enum__value(&__iter)->_1;

        #line 3995 "src/compiler/Generator.pv"
        Generator__generate_enum_loop(&self, usage);
    } }
    #line 3996 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Trait __iter = HashMap_usize_TypeUsage_Trait__iter(&usages.traits);
    #line 3996 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Trait__next(&__iter)) {
        #line 3996 "src/compiler/Generator.pv"
        struct TypeUsage_Trait* usage = &HashMapIter_usize_TypeUsage_Trait__value(&__iter)->_1;

        #line 3996 "src/compiler/Generator.pv"
        Generator__generate_trait_loop(&self, usage);
    } }
    #line 3997 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeFunctionUsage __iter = HashMap_usize_TypeFunctionUsage__iter(&usages.functions);
    #line 3997 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeFunctionUsage__next(&__iter)) {
        #line 3997 "src/compiler/Generator.pv"
        struct TypeFunctionUsage* usage = &HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_1;

        #line 3997 "src/compiler/Generator.pv"
        Generator__generate_function_loop(&self, usage);
    } }
    #line 3998 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(&usages.sequences);
    #line 3998 "src/compiler/Generator.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 3998 "src/compiler/Generator.pv"
        struct Type* element = ArrayIter_ref_Type__value(&__iter);

        #line 3998 "src/compiler/Generator.pv"
        Generator__generate_slice(&self, element);
    } }
    #line 3999 "src/compiler/Generator.pv"
    { struct ArrayIter_ref_ref_Tuple __iter = Array_ref_Tuple__iter(&usages.tuples);
    #line 3999 "src/compiler/Generator.pv"
    while (ArrayIter_ref_ref_Tuple__next(&__iter)) {
        #line 3999 "src/compiler/Generator.pv"
        struct Tuple* tuple = *ArrayIter_ref_ref_Tuple__value(&__iter);

        #line 3999 "src/compiler/Generator.pv"
        Generator__generate_tuple(&self, tuple);
    } }

    #line 4001 "src/compiler/Generator.pv"
    if (self.code_files.length > 0) {
        #line 4002 "src/compiler/Generator.pv"
        struct String command = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self.allocator });

        #line 4004 "src/compiler/Generator.pv"
        { struct ArrayIter_ref_String __iter = Array_String__iter(&self.code_files);
        #line 4004 "src/compiler/Generator.pv"
        while (ArrayIter_ref_String__next(&__iter)) {
            #line 4004 "src/compiler/Generator.pv"
            struct String* code_file = ArrayIter_ref_String__value(&__iter);

            #line 4005 "src/compiler/Generator.pv"
            if (command.array.length > 0) {
                #line 4006 "src/compiler/Generator.pv"
                String__append(&command, (struct str){ .ptr = output_seperator, .length = strlen(output_seperator) });
            }

            #line 4009 "src/compiler/Generator.pv"
            String__append(&command, String__as_str(code_file));
        } }

        #line 4012 "src/compiler/Generator.pv"
        uint32_t length = command.array.length;
        #line 4013 "src/compiler/Generator.pv"
        printf("%.*s\n", length, command.array.data);
    }

    #line 4016 "src/compiler/Generator.pv"
    return result;
}
