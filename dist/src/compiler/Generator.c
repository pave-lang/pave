#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>
#include <compiler/Generator.h>
#include <std/str.h>
#include <std/String.h>
#include <analyzer/Token.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/Naming.h>
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
#include <std/HashMap_str_Function.h>
#include <analyzer/types/Trait.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>
#include <std/Array_char.h>
#include <analyzer/Context.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/FunctionType.h>
#include <std/Array_Type.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/expression/ExpressionData.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Array_DeferStatement.h>
#include <std/Iter_ref_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <compiler/FunctionContext.h>
#include <analyzer/Block.h>
#include <std/Array_Statement.h>
#include <std/Iter_ref_Statement.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/LetStatement.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/statement/YieldStatement.h>
#include <analyzer/statement/ReturnStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <std/Array_ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/MatchStatement.h>
#include <std/Array_MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <std/Array_MatchPattern.h>
#include <std/IterEnumerate_ref_MatchPattern.h>
#include <std/Iter_ref_MatchPattern.h>
#include <tuple_usize_ref_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/EnumCValue.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/TokenType.h>
#include <std/trait_Hash.h>
#include <f32.h>
#include <f64.h>
#include <u32.h>
#include <i32.h>
#include <std/Array_EnumVariantParameter.h>
#include <std/Iter_ref_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <std/trait_Allocator.h>
#include <analyzer/statement/WhileStatement.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/statement/ForVariable.h>
#include <std/Array_ForVariable.h>
#include <std/Iter_ref_ForVariable.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <analyzer/c/Include.h>
#include <std/HashSet_str.h>
#include <analyzer/Module.h>
#include <std/HashSetIter_str.h>
#include <std/HashMap_str_str.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/types/StructField.h>
#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/ClassCpp.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/Generics.h>
#include <std/Array_UsageContext.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/UsageContext.h>
#include <std/HashMap_str_ref_Type.h>
#include <std/HashMapIter_str_ref_Type.h>
#include <tuple_str_ref_Type.h>
#include <std/Array_String.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <std/Array_Generic.h>
#include <std/Iter_ref_Type.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeUsage_Struct.h>
#include <analyzer/types/StructType.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <analyzer/Root.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/HashMapIter_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Trait.h>
#include <tuple_str_ref_Trait.h>
#include <analyzer/Namespace.h>
#include <compiler/TypeUsage_Primitive.h>
#include <compiler/TypeUsage_Sequence.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/TypeImpl.h>
#include <compiler/TypeUsage_Tuple.h>
#include <analyzer/types/Tuple.h>
#include <std/IterEnumerate_ref_Type.h>
#include <tuple_usize_ref_Type.h>
#include <compiler/TypeUsage_Trait.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <compiler/FileWriter.h>
#include <compiler/Usages.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <std/HashMapIter_usize_TypeUsage_Primitive.h>
#include <tuple_usize_TypeUsage_Primitive.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>
#include <tuple_usize_TypeUsage_Struct.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <std/HashMapIter_usize_TypeUsage_Enum.h>
#include <tuple_usize_TypeUsage_Enum.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <std/HashMapIter_usize_TypeUsage_Trait.h>
#include <tuple_usize_TypeUsage_Trait.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>
#include <tuple_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>
#include <std/HashMapIter_usize_TypeUsage_Sequence.h>
#include <tuple_usize_TypeUsage_Sequence.h>
#include <std/HashMap_usize_TypeUsage_Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_Tuple.h>
#include <tuple_usize_TypeUsage_Tuple.h>
#include <std/Iter_ref_String.h>
#include <compiler/Generator.h>

#include <compiler/Generator.h>

#line 164 "src/compiler/Generator.pv"
bool Generator__overwrite_if_different(struct Generator* self, char const* file_name, FILE* source) {
    #line 165 "src/compiler/Generator.pv"
    FILE* orig = fopen(file_name, "r");
    #line 166 "src/compiler/Generator.pv"
    bool different = true;

    #line 168 "src/compiler/Generator.pv"
    if (orig != 0) {
        #line 169 "src/compiler/Generator.pv"
        rewind(source);
        #line 170 "src/compiler/Generator.pv"
        int32_t c1 = 0;
        #line 171 "src/compiler/Generator.pv"
        int32_t c2 = 0;
        #line 172 "src/compiler/Generator.pv"
        different = false;
        #line 173 "src/compiler/Generator.pv"
        while (!different && (c1 != (int32_t)(EOF)) && (c2 != (int32_t)(EOF))) {
            #line 174 "src/compiler/Generator.pv"
            c1 = fgetc(source);
            #line 175 "src/compiler/Generator.pv"
            c2 = fgetc(orig);
            #line 176 "src/compiler/Generator.pv"
            different = c1 != c2;
        }

        #line 179 "src/compiler/Generator.pv"
        fclose(orig);
    }

    #line 182 "src/compiler/Generator.pv"
    if (!different) {
        #line 182 "src/compiler/Generator.pv"
        return false;
    }

    #line 184 "src/compiler/Generator.pv"
    rewind(source);

    #line 186 "src/compiler/Generator.pv"
    FILE* out = fopen(file_name, "w");
    #line 187 "src/compiler/Generator.pv"
    if (!out) {
        #line 187 "src/compiler/Generator.pv"
        perror("fopen");
        #line 187 "src/compiler/Generator.pv"
        return false;
    }

    #line 189 "src/compiler/Generator.pv"
    int32_t c = fgetc(source);
    #line 190 "src/compiler/Generator.pv"
    while (c != (int32_t)(EOF)) {
        #line 191 "src/compiler/Generator.pv"
        fputc(c, out);
        #line 192 "src/compiler/Generator.pv"
        c = fgetc(source);
    }

    #line 195 "src/compiler/Generator.pv"
    fclose(out);
    #line 196 "src/compiler/Generator.pv"
    return true;
}

#line 199 "src/compiler/Generator.pv"
void Generator__write_indent(struct Generator* self, FILE* file) {
    #line 200 "src/compiler/Generator.pv"
    int16_t i = 0;

    #line 202 "src/compiler/Generator.pv"
    while (i < self->indent) {
        #line 203 "src/compiler/Generator.pv"
        fprintf(file, "    ");
        #line 204 "src/compiler/Generator.pv"
        i += 1;
    }
}

#line 208 "src/compiler/Generator.pv"
bool Generator__write_str(struct Generator* self, FILE* file, struct str s) {
    #line 209 "src/compiler/Generator.pv"
    int32_t length = s.length;
    #line 210 "src/compiler/Generator.pv"
    fprintf(file, "%.*s", length, s.ptr);
    #line 211 "src/compiler/Generator.pv"
    return true;
}

#line 214 "src/compiler/Generator.pv"
bool Generator__write_string(struct Generator* self, FILE* file, struct String* s) {
    #line 215 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, String__as_str(s));
}

#line 218 "src/compiler/Generator.pv"
bool Generator__write_str_title(struct Generator* self, FILE* file, struct str s) {
    #line 219 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 220 "src/compiler/Generator.pv"
    uintptr_t length = s.length;
    #line 221 "src/compiler/Generator.pv"
    bool was_lowercase = false;

    #line 223 "src/compiler/Generator.pv"
    while (i < length) {
        #line 224 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 226 "src/compiler/Generator.pv"
        if (c >= 'a' && c <= 'z') {
            #line 227 "src/compiler/Generator.pv"
            fprintf(file, "%c", c - 32);
            #line 228 "src/compiler/Generator.pv"
            was_lowercase = true;
        } else {
            #line 230 "src/compiler/Generator.pv"
            if (was_lowercase && (c >= 'A') && (c <= 'Z')) {
                #line 231 "src/compiler/Generator.pv"
                fprintf(file, "_");
            }

            #line 234 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
            #line 235 "src/compiler/Generator.pv"
            was_lowercase = false;
        }

        #line 238 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 241 "src/compiler/Generator.pv"
    return true;
}

#line 244 "src/compiler/Generator.pv"
bool Generator__write_str_lowercase(struct Generator* self, FILE* file, struct str s) {
    #line 245 "src/compiler/Generator.pv"
    uintptr_t i = 0;
    #line 246 "src/compiler/Generator.pv"
    uintptr_t length = s.length;

    #line 248 "src/compiler/Generator.pv"
    while (i < length) {
        #line 249 "src/compiler/Generator.pv"
        char c = s.ptr[i];

        #line 251 "src/compiler/Generator.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 252 "src/compiler/Generator.pv"
            fprintf(file, "%c", c + 32);
        } else {
            #line 254 "src/compiler/Generator.pv"
            fprintf(file, "%c", c);
        }

        #line 257 "src/compiler/Generator.pv"
        i += 1;
    }

    #line 260 "src/compiler/Generator.pv"
    return true;
}

#line 263 "src/compiler/Generator.pv"
bool Generator__write_token(struct Generator* self, FILE* file, struct Token* token) {
    #line 264 "src/compiler/Generator.pv"
    return Generator__write_str(self, file, token->value);
}

#line 267 "src/compiler/Generator.pv"
bool Generator__type_is_discriminated_union(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 268 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 269 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 269 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 269 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, &indirect->to, generics);
        } break;
        #line 270 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 270 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 270 "src/compiler/Generator.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 271 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 271 "src/compiler/Generator.pv"
            return Generator__type_is_discriminated_union(self, generics->self_type, generics);
        } break;
        #line 272 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 275 "src/compiler/Generator.pv"
    return false;
}

#line 278 "src/compiler/Generator.pv"
bool Generator__write_type(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 279 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_c99, type, generics->self_type, generics);
    #line 280 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 281 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 282 "src/compiler/Generator.pv"
    return true;
}

#line 285 "src/compiler/Generator.pv"
bool Generator__write_type_name(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 286 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_name(&self->naming_ident, type, generics->self_type, generics);
    #line 287 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&type_name));
    #line 288 "src/compiler/Generator.pv"
    String__release(&type_name);
    #line 289 "src/compiler/Generator.pv"
    return true;
}

#line 292 "src/compiler/Generator.pv"
bool Generator__write_variable_decl(struct Generator* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics) {
    #line 293 "src/compiler/Generator.pv"
    struct Type* self_type = type;
    #line 294 "src/compiler/Generator.pv"
    if (generics != 0) {
        #line 294 "src/compiler/Generator.pv"
        self_type = generics->self_type;
    }

    #line 296 "src/compiler/Generator.pv"
    struct String variable_decl = Naming__get_variable_decl(&self->naming_c99, name, type, self_type, generics);
    #line 297 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&variable_decl));
    #line 298 "src/compiler/Generator.pv"
    String__release(&variable_decl);
    #line 299 "src/compiler/Generator.pv"
    return true;
}

#line 302 "src/compiler/Generator.pv"
bool Generator__write_function_name(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    bool __result;

    #line 303 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);

    #line 306 "src/compiler/Generator.pv"
    Generator__write_str(self, file, String__as_str(&name));

    #line 308 "src/compiler/Generator.pv"
    __result = true;
    String__release(&name);
    return __result;
}

#line 311 "src/compiler/Generator.pv"
bool Generator__is_reference(struct Type* type) {
    #line 312 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 313 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 313 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 314 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 314 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 314 "src/compiler/Generator.pv"
            return Generator__is_reference(info->type);
        } break;
        #line 315 "src/compiler/Generator.pv"
        default: {
            #line 315 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 319 "src/compiler/Generator.pv"
bool Generator__is_type_single_value_struct(struct Generator* self, struct Type* type, struct GenericMap* generics) {
    #line 320 "src/compiler/Generator.pv"
    switch (Type__deref(type)->type) {
        #line 321 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 321 "src/compiler/Generator.pv"
            struct Struct* struct_info = Type__deref(type)->struct_value._0;
            #line 321 "src/compiler/Generator.pv"
            return Struct__is_newtype(struct_info);
        } break;
        #line 322 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 322 "src/compiler/Generator.pv"
            return Generator__is_type_single_value_struct(self, generics->self_type, generics);
        } break;
        #line 323 "src/compiler/Generator.pv"
        default: {
            #line 323 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 327 "src/compiler/Generator.pv"
struct Function* Generator__get_function(struct Generator* self, struct Type* type, struct str func_name, struct GenericMap* generic_map) {
    #line 328 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 329 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 329 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_map->self_type, func_name, generic_map);
        } break;
        #line 330 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 330 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 330 "src/compiler/Generator.pv"
            return Generator__get_function(self, &indirect->to, func_name, generic_map);
        } break;
        #line 331 "src/compiler/Generator.pv"
        case TYPE__GENERIC: {
            #line 331 "src/compiler/Generator.pv"
            struct Generic* generic = type->generic_value;
            #line 332 "src/compiler/Generator.pv"
            if (generic_map == 0) {
                #line 333 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, but no generic map input\n");
                #line 334 "src/compiler/Generator.pv"
                return 0;
            }

            #line 337 "src/compiler/Generator.pv"
            struct Type* generic_type = GenericMap__get(generic_map, generic->name->value);
            #line 338 "src/compiler/Generator.pv"
            if (generic_type == 0) {
                #line 339 "src/compiler/Generator.pv"
                fprintf(stderr, "Getting generic for function, no item in generic map found\n");
                #line 340 "src/compiler/Generator.pv"
                return 0;
            }

            #line 343 "src/compiler/Generator.pv"
            return Generator__get_function(self, generic_type, func_name, generic_map);
        } break;
        #line 345 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 345 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 346 "src/compiler/Generator.pv"
            if (primitive_info == 0) {
                #line 347 "src/compiler/Generator.pv"
                int32_t name_length = primitive_info->name.length;
                #line 348 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitive_info %.*s for get_function\n", name_length, primitive_info->name.ptr);
                #line 349 "src/compiler/Generator.pv"
                return 0;
            }

            #line 352 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 354 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&primitive_info->impls);
            #line 355 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 356 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 357 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 360 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 361 "src/compiler/Generator.pv"
                int32_t name_length = primitive_info->name.length;
                #line 362 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 363 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find primitives %.*s function %.*s for get_function\n", name_length, primitive_info->name.ptr, func_name_length, func_name.ptr);
            }

            #line 366 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 368 "src/compiler/Generator.pv"
        case TYPE__ENUM: {
            #line 368 "src/compiler/Generator.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 369 "src/compiler/Generator.pv"
            if (enum_info == 0) {
                #line 370 "src/compiler/Generator.pv"
                int32_t name_length = enum_info->name->value.length;
                #line 371 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enum %.*s for get_function\n", name_length, enum_info->name->value.ptr);
                #line 372 "src/compiler/Generator.pv"
                return 0;
            }

            #line 375 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 377 "src/compiler/Generator.pv"
            struct Iter_ref_ref_Impl impl_iter = Array_ref_Impl__iter(&enum_info->impls);
            #line 378 "src/compiler/Generator.pv"
            while (func_info == 0 && Iter_ref_ref_Impl__next(&impl_iter)) {
                #line 379 "src/compiler/Generator.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&impl_iter);
                #line 380 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);
            }

            #line 383 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 384 "src/compiler/Generator.pv"
                int32_t name_length = enum_info->name->value.length;
                #line 385 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 386 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find enums %.*s function %.*s for get_function\n", name_length, enum_info->name->value.ptr, func_name_length, func_name.ptr);
            }

            #line 389 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 391 "src/compiler/Generator.pv"
        case TYPE__STRUCT: {
            #line 391 "src/compiler/Generator.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 392 "src/compiler/Generator.pv"
            if (struct_info == 0) {
                #line 393 "src/compiler/Generator.pv"
                int32_t name_length = struct_info->name->value.length;
                #line 394 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find struct %.*s for get_function\n", name_length, struct_info->name->value.ptr);
                #line 395 "src/compiler/Generator.pv"
                return 0;
            }

            #line 398 "src/compiler/Generator.pv"
            struct Function* func_info = 0;

            #line 400 "src/compiler/Generator.pv"
            { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
            #line 400 "src/compiler/Generator.pv"
            while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
                #line 400 "src/compiler/Generator.pv"
                uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
                #line 400 "src/compiler/Generator.pv"
                struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

                #line 401 "src/compiler/Generator.pv"
                func_info = Impl__find_function(impl_info, func_name);

                #line 403 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 403 "src/compiler/Generator.pv"
                    break;
                }

                #line 405 "src/compiler/Generator.pv"
                func_info = HashMap_str_Function__find(&impl_info->trait_->functions, &func_name);

                #line 407 "src/compiler/Generator.pv"
                if (func_info != 0) {
                    #line 408 "src/compiler/Generator.pv"
                    func_info = ArenaAllocator__store_Function(self->allocator, *func_info);
                    #line 409 "src/compiler/Generator.pv"
                    func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                    #line 410 "src/compiler/Generator.pv"
                    break;
                }
            } }

            #line 414 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 415 "src/compiler/Generator.pv"
                int32_t name_length = struct_info->name->value.length;
                #line 416 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 417 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find structs %.*s function %.*s for get_function\n", name_length, struct_info->name->value.ptr, func_name_length, func_name.ptr);
            }

            #line 420 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 422 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 422 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 423 "src/compiler/Generator.pv"
            if (trait_info == 0) {
                #line 424 "src/compiler/Generator.pv"
                int32_t name_length = trait_info->name->value.length;
                #line 425 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find trait %.*s for get_function\n", name_length, trait_info->name->value.ptr);
                #line 426 "src/compiler/Generator.pv"
                return 0;
            }

            #line 429 "src/compiler/Generator.pv"
            struct Function* func_info = HashMap_str_Function__find(&trait_info->functions, &func_name);

            #line 431 "src/compiler/Generator.pv"
            if (func_info == 0) {
                #line 432 "src/compiler/Generator.pv"
                int32_t name_length = trait_info->name->value.length;
                #line 433 "src/compiler/Generator.pv"
                int32_t func_name_length = func_name.length;
                #line 434 "src/compiler/Generator.pv"
                fprintf(stderr, "Could not find traits %.*s function %.*s for get_function\n", name_length, trait_info->name->value.ptr, func_name_length, func_name.ptr);
            }

            #line 437 "src/compiler/Generator.pv"
            return func_info;
        } break;
        #line 439 "src/compiler/Generator.pv"
        default: {
            #line 440 "src/compiler/Generator.pv"
            fprintf(stderr, "Unhandled type for getting function %s\n", Type__name(type));
        } break;
    }

    #line 444 "src/compiler/Generator.pv"
    return 0;
}

#line 447 "src/compiler/Generator.pv"
bool Generator__write_enum_variant_name(struct Generator* self, FILE* file, struct Type* type, struct EnumVariant* variant) {
    #line 448 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;
    #line 449 "src/compiler/Generator.pv"
    struct Token* name = parent->name;
    #line 450 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, name->value);
    #line 451 "src/compiler/Generator.pv"
    fprintf(file, "__");
    #line 452 "src/compiler/Generator.pv"
    struct Token* variant_name = variant->name;
    #line 453 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, variant_name->value);

    #line 455 "src/compiler/Generator.pv"
    return true;
}

#line 458 "src/compiler/Generator.pv"
bool Generator__write_deref_if_needed(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 459 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 460 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 460 "src/compiler/Generator.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 461 "src/compiler/Generator.pv"
            fprintf(file, "*");
            #line 462 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, &indirect->to, generics);
        } break;
        #line 464 "src/compiler/Generator.pv"
        case TYPE__TYPEDEF_C: {
            #line 464 "src/compiler/Generator.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 465 "src/compiler/Generator.pv"
            return Generator__write_deref_if_needed(self, file, info->type, generics);
        } break;
        #line 467 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 470 "src/compiler/Generator.pv"
    return true;
}

#line 473 "src/compiler/Generator.pv"
bool Generator__write_static_member_accessor(struct Generator* self, FILE* file, struct GenericMap* generics) {
    #line 474 "src/compiler/Generator.pv"
    fprintf(file, "::");

    #line 476 "src/compiler/Generator.pv"
    return true;
}

#line 479 "src/compiler/Generator.pv"
bool Generator__write_instance_member_accessor(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    #line 480 "src/compiler/Generator.pv"
    if (Type__is_fat_pointer(type)) {
        #line 481 "src/compiler/Generator.pv"
        fprintf(file, ".");
        #line 482 "src/compiler/Generator.pv"
        return true;
    }

    #line 485 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 486 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 487 "src/compiler/Generator.pv"
            fprintf(file, "->");
        } break;
        #line 489 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 490 "src/compiler/Generator.pv"
            return Generator__write_instance_member_accessor(self, file, generics->self_type, generics);
        } break;
        #line 492 "src/compiler/Generator.pv"
        default: {
            #line 493 "src/compiler/Generator.pv"
            fprintf(file, ".");
        } break;
    }

    #line 497 "src/compiler/Generator.pv"
    return true;
}

#line 500 "src/compiler/Generator.pv"
bool Generator__write_literal(struct Generator* self, FILE* file, struct Type* type, struct str value) {
    #line 501 "src/compiler/Generator.pv"
    Generator__write_str(self, file, value);

    #line 503 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 504 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 504 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 505 "src/compiler/Generator.pv"
            if (str__eq(primitive_info->name, (struct str){ .ptr = "u64", .length = strlen("u64") })) {
                #line 506 "src/compiler/Generator.pv"
                fprintf(file, "ULL");
            }
        } break;
        #line 509 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 512 "src/compiler/Generator.pv"
    return true;
}

#line 515 "src/compiler/Generator.pv"
bool Generator__write_typeid(struct Generator* self, FILE* file, struct Type* type, struct GenericMap* generics) {
    bool __result;

    #line 516 "src/compiler/Generator.pv"
    struct String type_name = Naming__get_type_decl(self->naming_decl, type, generics->self_type, generics);

    #line 519 "src/compiler/Generator.pv"
    Hashed type_id = Fnv1a__hash(type_name.array.data, String__length(&type_name));

    #line 521 "src/compiler/Generator.pv"
    fprintf(file, "%zuULL", type_id);

    #line 523 "src/compiler/Generator.pv"
    __result = true;
    String__release(&type_name);
    return __result;
}

#line 526 "src/compiler/Generator.pv"
void Generator__write_line_directive(struct Generator* self, FILE* file, struct Context* context, struct Token* token) {
    #line 527 "src/compiler/Generator.pv"
    if (self->output_line_directives) {
        #line 528 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 529 "src/compiler/Generator.pv"
        fprintf(file, "#line %zu \"", token->start_line + 1);
        #line 530 "src/compiler/Generator.pv"
        Generator__write_str(self, file, context->path);
        #line 531 "src/compiler/Generator.pv"
        fprintf(file, "\"\n");
    }
}

#line 535 "src/compiler/Generator.pv"
void Generator__write_str_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 536 "src/compiler/Generator.pv"
    if (reference) {
        #line 536 "src/compiler/Generator.pv"
        fprintf(file, "&");
    }
    #line 537 "src/compiler/Generator.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 538 "src/compiler/Generator.pv"
    Generator__write_expression(self, file, inner_expr, generics);
    #line 539 "src/compiler/Generator.pv"
    fprintf(file, ", .length = strlen(");
    #line 540 "src/compiler/Generator.pv"
    Generator__write_expression(self, file, inner_expr, generics);
    #line 541 "src/compiler/Generator.pv"
    fprintf(file, ") }");
}

#line 544 "src/compiler/Generator.pv"
void Generator__write_trait_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 545 "src/compiler/Generator.pv"
    switch (Type__deref(&inner_expr->return_type)->type) {
        #line 546 "src/compiler/Generator.pv"
        case TYPE__FUNCTION: {
            #line 546 "src/compiler/Generator.pv"
            struct Function* func_info = Type__deref(&inner_expr->return_type)->function_value._0;
            #line 546 "src/compiler/Generator.pv"
            struct GenericMap* func_generics = Type__deref(&inner_expr->return_type)->function_value._1;
            #line 547 "src/compiler/Generator.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 548 "src/compiler/Generator.pv"
                fprintf(file, "(struct trait_Co_CoroutineStatus) { .vtable = &");

                #line 550 "src/compiler/Generator.pv"
                switch (func_info->parent.type) {
                    #line 551 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 551 "src/compiler/Generator.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 552 "src/compiler/Generator.pv"
                        Generator__write_str_title(self, file, struct_info->name->value);
                        #line 553 "src/compiler/Generator.pv"
                        fprintf(file, "__");
                    } break;
                    #line 555 "src/compiler/Generator.pv"
                    default: {
                    } break;
                }

                #line 558 "src/compiler/Generator.pv"
                Generator__write_str_title(self, file, func_info->name->value);
                #line 559 "src/compiler/Generator.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 560 "src/compiler/Generator.pv"
                Generator__write_function_name(self, file, func_info, func_generics);
                #line 561 "src/compiler/Generator.pv"
                fprintf(file, "__Co_CoroutineStatus__Instance) {}");

                #line 563 "src/compiler/Generator.pv"
                fprintf(file, " }");
            } else {
                #line 565 "src/compiler/Generator.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");

                #line 567 "src/compiler/Generator.pv"
                switch (func_info->parent.type) {
                    #line 568 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 568 "src/compiler/Generator.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 569 "src/compiler/Generator.pv"
                        Generator__write_str_title(self, file, struct_info->name->value);
                        #line 570 "src/compiler/Generator.pv"
                        fprintf(file, "__");
                    } break;
                    #line 572 "src/compiler/Generator.pv"
                    default: {
                    } break;
                }

                #line 575 "src/compiler/Generator.pv"
                Generator__write_str_title(self, file, func_info->name->value);
                #line 576 "src/compiler/Generator.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 577 "src/compiler/Generator.pv"
                Generator__write_function_name(self, file, func_info, func_generics);
                #line 578 "src/compiler/Generator.pv"
                fprintf(file, "__Fn__Instance) {}");

                #line 580 "src/compiler/Generator.pv"
                fprintf(file, " }");
            }

            #line 583 "src/compiler/Generator.pv"
            return;
        } break;
        #line 585 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 588 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 589 "src/compiler/Generator.pv"
        case TYPE__TRAIT: {
            #line 589 "src/compiler/Generator.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 590 "src/compiler/Generator.pv"
            fprintf(file, "(");
            #line 591 "src/compiler/Generator.pv"
            Generator__write_type(self, file, type, generics);
            #line 592 "src/compiler/Generator.pv"
            fprintf(file, ") { .vtable = &");

            #line 594 "src/compiler/Generator.pv"
            struct Type* inner_type = Context__resolve_type(self->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 595 "src/compiler/Generator.pv"
            struct String inner_type_name = Naming__get_type_name(&self->naming_ident, inner_type, generics->array.data, generics);
            #line 596 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, String__as_str(&inner_type_name));

            #line 598 "src/compiler/Generator.pv"
            fprintf(file, "__VTABLE__");
            #line 599 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, trait_info->name->value);
            #line 600 "src/compiler/Generator.pv"
            fprintf(file, ", .instance = ");
            #line 601 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, inner_expr, generics);
            #line 602 "src/compiler/Generator.pv"
            fprintf(file, " }");
        } break;
        #line 604 "src/compiler/Generator.pv"
        default: {
            #line 604 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 608 "src/compiler/Generator.pv"
void Generator__write_sequence_cast(struct Generator* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 609 "src/compiler/Generator.pv"
    struct Sequence* inner_sequence = 0;

    #line 611 "src/compiler/Generator.pv"
    switch (inner_expr->return_type.type) {
        #line 612 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 612 "src/compiler/Generator.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 613 "src/compiler/Generator.pv"
            switch (indirect->to.type) {
                #line 614 "src/compiler/Generator.pv"
                case TYPE__SEQUENCE: {
                    #line 614 "src/compiler/Generator.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 614 "src/compiler/Generator.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 615 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 618 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 621 "src/compiler/Generator.pv"
    if (inner_sequence == 0) {
        #line 622 "src/compiler/Generator.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 623 "src/compiler/Generator.pv"
        return;
    }

    #line 626 "src/compiler/Generator.pv"
    uintptr_t length = 0;
    #line 627 "src/compiler/Generator.pv"
    switch (inner_sequence->type.type) {
        #line 628 "src/compiler/Generator.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 628 "src/compiler/Generator.pv"
            uintptr_t seq_length = inner_sequence->type.fixedarray_value;
            #line 628 "src/compiler/Generator.pv"
            length = seq_length;
        } break;
        #line 629 "src/compiler/Generator.pv"
        default: {
            #line 630 "src/compiler/Generator.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 631 "src/compiler/Generator.pv"
            return;
        } break;
    }

    #line 635 "src/compiler/Generator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };

    #line 637 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_c99, &sequence_type, &sequence_type, generics);
    #line 638 "src/compiler/Generator.pv"
    struct Expression* unary_inner = 0;

    #line 640 "src/compiler/Generator.pv"
    switch (inner_expr->data.type) {
        #line 641 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 641 "src/compiler/Generator.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 641 "src/compiler/Generator.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 642 "src/compiler/Generator.pv"
            if (str__eq(expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 643 "src/compiler/Generator.pv"
                unary_inner = inner;
            }
        } break;
        #line 646 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 649 "src/compiler/Generator.pv"
    fprintf(file, "(");
    #line 650 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &name);
    #line 651 "src/compiler/Generator.pv"
    fprintf(file, ") { .data = ");

    #line 653 "src/compiler/Generator.pv"
    if (unary_inner != 0) {
        #line 654 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, unary_inner, generics);
    } else {
        #line 656 "src/compiler/Generator.pv"
        fprintf(file, "*");
        #line 657 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, inner_expr, generics);
    }

    #line 660 "src/compiler/Generator.pv"
    fprintf(file, ", .length = %zu }", length);
}

#line 663 "src/compiler/Generator.pv"
bool Generator__write_struct_construction(struct Generator* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 664 "src/compiler/Generator.pv"
    if (Generator__is_type_single_value_struct(self, type, generics)) {
        #line 665 "src/compiler/Generator.pv"
        if (fields->length > 1) {
            #line 666 "src/compiler/Generator.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 668 "src/compiler/Generator.pv"
            struct InvokeArgument* field = fields->data;
            #line 669 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, field->value, generics);
        } else {
            #line 671 "src/compiler/Generator.pv"
            fprintf(file, "0");
        }
    } else {
        #line 674 "src/compiler/Generator.pv"
        bool compact = (fields->length <= 1) || (fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line);

        #line 676 "src/compiler/Generator.pv"
        fprintf(file, "(");
        #line 677 "src/compiler/Generator.pv"
        Generator__write_type(self, file, type, generics);

        #line 679 "src/compiler/Generator.pv"
        if (fields->length == 0) {
            #line 680 "src/compiler/Generator.pv"
            fprintf(file, ") {}");
        } else {
            #line 682 "src/compiler/Generator.pv"
            fprintf(file, ") {");
            #line 683 "src/compiler/Generator.pv"
            if (!compact) {
                #line 683 "src/compiler/Generator.pv"
                fprintf(file, "\n");
            }
        }

        #line 686 "src/compiler/Generator.pv"
        self->indent += 1;
        #line 687 "src/compiler/Generator.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 687 "src/compiler/Generator.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 687 "src/compiler/Generator.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 687 "src/compiler/Generator.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 688 "src/compiler/Generator.pv"
            if (compact) {
                #line 689 "src/compiler/Generator.pv"
                if (i > 0) {
                    #line 689 "src/compiler/Generator.pv"
                    fprintf(file, ", .");
                } else {
                    #line 690 "src/compiler/Generator.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 692 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 693 "src/compiler/Generator.pv"
                fprintf(file, ".");
            }

            #line 696 "src/compiler/Generator.pv"
            Generator__write_token(self, file, field->name);
            #line 697 "src/compiler/Generator.pv"
            fprintf(file, " = ");
            #line 698 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, field->value, generics);
            #line 699 "src/compiler/Generator.pv"
            if (!compact) {
                #line 699 "src/compiler/Generator.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 702 "src/compiler/Generator.pv"
        self->indent -= 1;

        #line 704 "src/compiler/Generator.pv"
        if (fields->length != 0) {
            #line 705 "src/compiler/Generator.pv"
            if (compact) {
                #line 706 "src/compiler/Generator.pv"
                fprintf(file, " }");
            } else {
                #line 708 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 709 "src/compiler/Generator.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 714 "src/compiler/Generator.pv"
    return true;
}

#line 717 "src/compiler/Generator.pv"
bool Generator__write_enum_variant(struct Generator* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 718 "src/compiler/Generator.pv"
    struct Enum* parent = variant->parent;

    #line 720 "src/compiler/Generator.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 721 "src/compiler/Generator.pv"
        Generator__write_enum_variant_name(self, file, type, variant);
        #line 722 "src/compiler/Generator.pv"
        return true;
    }

    #line 725 "src/compiler/Generator.pv"
    fprintf(file, "(");
    #line 726 "src/compiler/Generator.pv"
    Generator__write_type(self, file, type, generics);
    #line 727 "src/compiler/Generator.pv"
    fprintf(file, ") { .type = ");
    #line 728 "src/compiler/Generator.pv"
    Generator__write_enum_variant_name(self, file, type, variant);

    #line 730 "src/compiler/Generator.pv"
    if (arguments == 0) {
        #line 731 "src/compiler/Generator.pv"
        fprintf(file, " }");
        #line 732 "src/compiler/Generator.pv"
        return true;
    }

    #line 735 "src/compiler/Generator.pv"
    if (arguments->length > 0) {
        #line 736 "src/compiler/Generator.pv"
        fprintf(file, ", .");
        #line 737 "src/compiler/Generator.pv"
        struct Token* name = variant->name;
        #line 738 "src/compiler/Generator.pv"
        Generator__write_str_lowercase(self, file, name->value);
        #line 739 "src/compiler/Generator.pv"
        fprintf(file, "_value = ");
    }

    #line 742 "src/compiler/Generator.pv"
    if (arguments->length == 1) {
        #line 743 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 745 "src/compiler/Generator.pv"
        fprintf(file, "{ ");

        #line 747 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 748 "src/compiler/Generator.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 748 "src/compiler/Generator.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 748 "src/compiler/Generator.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 749 "src/compiler/Generator.pv"
            if (i > 0) {
                #line 750 "src/compiler/Generator.pv"
                fprintf(file, ", ");
            }

            #line 753 "src/compiler/Generator.pv"
            fprintf(file, "._%zu = ", i);

            #line 755 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, arg.value, generics);
            #line 756 "src/compiler/Generator.pv"
            i += 1;
        } }

        #line 759 "src/compiler/Generator.pv"
        fprintf(file, "}");
    }

    #line 762 "src/compiler/Generator.pv"
    fprintf(file, " }");

    #line 764 "src/compiler/Generator.pv"
    return true;
}

#line 767 "src/compiler/Generator.pv"
bool Generator__write_coroutine_invoke(struct Generator* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 768 "src/compiler/Generator.pv"
    struct ExpressionData* data = &expression->data;

    #line 770 "src/compiler/Generator.pv"
    switch (data->type) {
        #line 771 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 771 "src/compiler/Generator.pv"
            struct Type* type = data->type_value;
            #line 772 "src/compiler/Generator.pv"
            switch (type->type) {
                #line 773 "src/compiler/Generator.pv"
                case TYPE__FUNCTION: {
                    #line 773 "src/compiler/Generator.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 773 "src/compiler/Generator.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 774 "src/compiler/Generator.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, self->allocator, generics);

                    #line 776 "src/compiler/Generator.pv"
                    fprintf(file, "(struct ");
                    #line 777 "src/compiler/Generator.pv"
                    Generator__write_function_name(self, file, func_info, &resolved_generics);
                    #line 778 "src/compiler/Generator.pv"
                    fprintf(file, ") {");

                    #line 780 "src/compiler/Generator.pv"
                    uintptr_t i = 0;
                    #line 781 "src/compiler/Generator.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 781 "src/compiler/Generator.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 781 "src/compiler/Generator.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 782 "src/compiler/Generator.pv"
                        if (i == 0) {
                            #line 783 "src/compiler/Generator.pv"
                            fprintf(file, " .");
                        } else {
                            #line 785 "src/compiler/Generator.pv"
                            fprintf(file, ", .");
                        }

                        #line 788 "src/compiler/Generator.pv"
                        Generator__write_token(self, file, param->name);
                        #line 789 "src/compiler/Generator.pv"
                        fprintf(file, " = ");

                        #line 791 "src/compiler/Generator.pv"
                        if (i < arguments->length) {
                            #line 792 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 794 "src/compiler/Generator.pv"
                            fprintf(file, "0");
                        }

                        #line 797 "src/compiler/Generator.pv"
                        i += 1;
                    } }

                    #line 800 "src/compiler/Generator.pv"
                    fprintf(file, " }");
                    #line 801 "src/compiler/Generator.pv"
                    return true;
                } break;
                #line 803 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } break;
        #line 806 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 809 "src/compiler/Generator.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 810 "src/compiler/Generator.pv"
    return false;
}

#line 813 "src/compiler/Generator.pv"
bool Generator__write_builtin_function_invoke(struct Generator* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 814 "src/compiler/Generator.pv"
    struct str name = func_info->name->value;

    #line 816 "src/compiler/Generator.pv"
    if (str__eq(name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 817 "src/compiler/Generator.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, self->allocator, generics);

        #line 819 "src/compiler/Generator.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 820 "src/compiler/Generator.pv"
        if (type == 0) {
            #line 820 "src/compiler/Generator.pv"
            return false;
        }

        #line 822 "src/compiler/Generator.pv"
        return Generator__write_typeid(self, file, type, generics);
    }

    #line 825 "src/compiler/Generator.pv"
    if (str__eq(name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 826 "src/compiler/Generator.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, self->allocator, generics);

        #line 828 "src/compiler/Generator.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 829 "src/compiler/Generator.pv"
        if (arg == 0) {
            #line 829 "src/compiler/Generator.pv"
            return false;
        }

        #line 831 "src/compiler/Generator.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 832 "src/compiler/Generator.pv"
        if (type == 0) {
            #line 832 "src/compiler/Generator.pv"
            return false;
        }

        #line 834 "src/compiler/Generator.pv"
        fprintf(file, "(");
        #line 835 "src/compiler/Generator.pv"
        Generator__write_type(self, file, type, generics);
        #line 836 "src/compiler/Generator.pv"
        fprintf(file, ")(");
        #line 837 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, arg->value, generics);
        #line 838 "src/compiler/Generator.pv"
        fprintf(file, ")");
        #line 839 "src/compiler/Generator.pv"
        return true;
    }

    #line 842 "src/compiler/Generator.pv"
    Generator__write_token(self, file, func_info->name);

    #line 844 "src/compiler/Generator.pv"
    fprintf(file, "(");
    #line 845 "src/compiler/Generator.pv"
    bool first = true;
    #line 846 "src/compiler/Generator.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 846 "src/compiler/Generator.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 846 "src/compiler/Generator.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 847 "src/compiler/Generator.pv"
        if (first) {
            #line 847 "src/compiler/Generator.pv"
            first = false;
        } else {
            #line 847 "src/compiler/Generator.pv"
            fprintf(file, ", ");
        }
        #line 848 "src/compiler/Generator.pv"
        Generator__write_expression(self, file, arg->value, generics);
    } }

    #line 851 "src/compiler/Generator.pv"
    fprintf(file, ")");

    #line 853 "src/compiler/Generator.pv"
    return true;
}

#line 856 "src/compiler/Generator.pv"
bool Generator__write_invoke(struct Generator* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 857 "src/compiler/Generator.pv"
    struct ExpressionData* data = &expression->data;
    #line 858 "src/compiler/Generator.pv"
    switch (data->type) {
        #line 859 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 859 "src/compiler/Generator.pv"
            struct str name = data->variable_value;
            #line 860 "src/compiler/Generator.pv"
            bool success = Generator__write_str(self, file, name);
            #line 861 "src/compiler/Generator.pv"
            fprintf(file, "(");

            #line 863 "src/compiler/Generator.pv"
            bool first = true;
            #line 864 "src/compiler/Generator.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 864 "src/compiler/Generator.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 864 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 865 "src/compiler/Generator.pv"
                if (first) {
                    #line 865 "src/compiler/Generator.pv"
                    first = false;
                } else {
                    #line 865 "src/compiler/Generator.pv"
                    fprintf(file, ", ");
                }
                #line 866 "src/compiler/Generator.pv"
                success = Generator__write_expression(self, file, arg->value, generics) && success;
            } }

            #line 869 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 871 "src/compiler/Generator.pv"
            return success;
        } break;
        #line 873 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 874 "src/compiler/Generator.pv"
            bool success = Generator__write_expression(self, file, expression, generics);
            #line 875 "src/compiler/Generator.pv"
            fprintf(file, "(");

            #line 877 "src/compiler/Generator.pv"
            bool first = true;
            #line 878 "src/compiler/Generator.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 878 "src/compiler/Generator.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 878 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 879 "src/compiler/Generator.pv"
                if (first) {
                    #line 879 "src/compiler/Generator.pv"
                    first = false;
                } else {
                    #line 879 "src/compiler/Generator.pv"
                    fprintf(file, ", ");
                }
                #line 880 "src/compiler/Generator.pv"
                success = Generator__write_expression(self, file, arg->value, generics) && success;
            } }

            #line 883 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 885 "src/compiler/Generator.pv"
            return success;
        } break;
        #line 887 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 888 "src/compiler/Generator.pv"
            bool success = Generator__write_expression(self, file, expression, generics);
            #line 889 "src/compiler/Generator.pv"
            fprintf(file, "(");

            #line 891 "src/compiler/Generator.pv"
            bool first = true;
            #line 892 "src/compiler/Generator.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 892 "src/compiler/Generator.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 892 "src/compiler/Generator.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 893 "src/compiler/Generator.pv"
                if (first) {
                    #line 893 "src/compiler/Generator.pv"
                    first = false;
                } else {
                    #line 893 "src/compiler/Generator.pv"
                    fprintf(file, ", ");
                }
                #line 894 "src/compiler/Generator.pv"
                success = Generator__write_expression(self, file, arg->value, generics) && success;
            } }

            #line 897 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 899 "src/compiler/Generator.pv"
            return success;
        } break;
        #line 901 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 901 "src/compiler/Generator.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 902 "src/compiler/Generator.pv"
            return Generator__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 904 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 904 "src/compiler/Generator.pv"
            struct Type* type = data->type_value;
            #line 905 "src/compiler/Generator.pv"
            switch (type->type) {
                #line 906 "src/compiler/Generator.pv"
                case TYPE__SELF: {
                    #line 906 "src/compiler/Generator.pv"
                    type = generics->self_type;
                } break;
                #line 907 "src/compiler/Generator.pv"
                default: {
                } break;
            }

            #line 910 "src/compiler/Generator.pv"
            switch (Type__resolve_typedef(type)->type) {
                #line 911 "src/compiler/Generator.pv"
                case TYPE__STRUCT: {
                    #line 912 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 914 "src/compiler/Generator.pv"
                case TYPE__STRUCT_C: {
                    #line 915 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 917 "src/compiler/Generator.pv"
                case TYPE__UNION_C: {
                    #line 918 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 920 "src/compiler/Generator.pv"
                case TYPE__TUPLE: {
                    #line 921 "src/compiler/Generator.pv"
                    return Generator__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 923 "src/compiler/Generator.pv"
                case TYPE__FUNCTION: {
                    #line 923 "src/compiler/Generator.pv"
                    struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                    #line 923 "src/compiler/Generator.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
                    #line 924 "src/compiler/Generator.pv"
                    switch (func_info->type) {
                        #line 925 "src/compiler/Generator.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 926 "src/compiler/Generator.pv"
                            return Generator__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 928 "src/compiler/Generator.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 929 "src/compiler/Generator.pv"
                            return Generator__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 931 "src/compiler/Generator.pv"
                        default: {
                        } break;
                    }

                    #line 934 "src/compiler/Generator.pv"
                    struct str name = func_info->name->value;
                    #line 935 "src/compiler/Generator.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, self->allocator, generics);

                    #line 937 "src/compiler/Generator.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 938 "src/compiler/Generator.pv"
                    bool success = true;
                    #line 939 "src/compiler/Generator.pv"
                    bool first = true;

                    #line 941 "src/compiler/Generator.pv"
                    switch (func_info->parent.type) {
                        #line 942 "src/compiler/Generator.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 942 "src/compiler/Generator.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 943 "src/compiler/Generator.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 944 "src/compiler/Generator.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 945 "src/compiler/Generator.pv"
                                return false;
                            }

                            #line 948 "src/compiler/Generator.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 950 "src/compiler/Generator.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 951 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                                #line 952 "src/compiler/Generator.pv"
                                fprintf(file, ".vtable->");
                                #line 953 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, name) && success;
                                #line 954 "src/compiler/Generator.pv"
                                fprintf(file, "(");
                                #line 955 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                                #line 956 "src/compiler/Generator.pv"
                                fprintf(file, ".instance");

                                #line 958 "src/compiler/Generator.pv"
                                first = false;
                            } else {
                                #line 960 "src/compiler/Generator.pv"
                                struct String parent_name = Naming__get_type_name(&self->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 961 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, String__as_str(&parent_name)) && success;
                                #line 962 "src/compiler/Generator.pv"
                                fprintf(file, "__");

                                #line 964 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, trait_info->name->value) && success;
                                #line 965 "src/compiler/Generator.pv"
                                fprintf(file, "__");

                                #line 967 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, func_info->name->value) && success;
                                #line 968 "src/compiler/Generator.pv"
                                fprintf(file, "(");

                                #line 970 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;

                                #line 972 "src/compiler/Generator.pv"
                                first = false;
                            }
                        } break;
                        #line 976 "src/compiler/Generator.pv"
                        default: {
                            #line 977 "src/compiler/Generator.pv"
                            success = Generator__write_function_name(self, file, func_info, &resolved_generics) && success;
                            #line 978 "src/compiler/Generator.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 982 "src/compiler/Generator.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 982 "src/compiler/Generator.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 982 "src/compiler/Generator.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 983 "src/compiler/Generator.pv"
                        if (first) {
                            #line 983 "src/compiler/Generator.pv"
                            first = false;
                        } else {
                            #line 983 "src/compiler/Generator.pv"
                            fprintf(file, ", ");
                        }
                        #line 984 "src/compiler/Generator.pv"
                        success = Generator__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 987 "src/compiler/Generator.pv"
                    fprintf(file, ")");

                    #line 989 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 991 "src/compiler/Generator.pv"
                case TYPE__FUNCTION_C: {
                    #line 991 "src/compiler/Generator.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
                    #line 992 "src/compiler/Generator.pv"
                    struct str name = func_info->name;

                    #line 994 "src/compiler/Generator.pv"
                    bool success = Generator__write_str(self, file, name);
                    #line 995 "src/compiler/Generator.pv"
                    fprintf(file, "(");

                    #line 997 "src/compiler/Generator.pv"
                    bool first = true;
                    #line 998 "src/compiler/Generator.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 998 "src/compiler/Generator.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 998 "src/compiler/Generator.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 999 "src/compiler/Generator.pv"
                        if (first) {
                            #line 999 "src/compiler/Generator.pv"
                            first = false;
                        } else {
                            #line 999 "src/compiler/Generator.pv"
                            fprintf(file, ", ");
                        }
                        #line 1000 "src/compiler/Generator.pv"
                        success = Generator__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 1003 "src/compiler/Generator.pv"
                    fprintf(file, ")");

                    #line 1005 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 1007 "src/compiler/Generator.pv"
                case TYPE__SEQUENCE: {
                    #line 1007 "src/compiler/Generator.pv"
                    struct Sequence* sequence = Type__resolve_typedef(type)->sequence_value;
                    #line 1008 "src/compiler/Generator.pv"
                    bool success = true;

                    #line 1010 "src/compiler/Generator.pv"
                    switch (sequence->type.type) {
                        #line 1011 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1012 "src/compiler/Generator.pv"
                            fprintf(file, "{");

                            #line 1014 "src/compiler/Generator.pv"
                            bool first = true;
                            #line 1015 "src/compiler/Generator.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 1015 "src/compiler/Generator.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 1015 "src/compiler/Generator.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 1016 "src/compiler/Generator.pv"
                                if (first) {
                                    #line 1016 "src/compiler/Generator.pv"
                                    first = false;
                                } else {
                                    #line 1016 "src/compiler/Generator.pv"
                                    fprintf(file, ", ");
                                }
                                #line 1017 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                            } }

                            #line 1020 "src/compiler/Generator.pv"
                            fprintf(file, "}");
                        } break;
                        #line 1022 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1023 "src/compiler/Generator.pv"
                            fprintf(file, "(");
                            #line 1024 "src/compiler/Generator.pv"
                            Generator__write_type(self, file, &expression->return_type, generics);
                            #line 1025 "src/compiler/Generator.pv"
                            fprintf(file, ") {");

                            #line 1027 "src/compiler/Generator.pv"
                            bool first = true;
                            #line 1028 "src/compiler/Generator.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 1028 "src/compiler/Generator.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 1028 "src/compiler/Generator.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 1029 "src/compiler/Generator.pv"
                                if (first) {
                                    #line 1029 "src/compiler/Generator.pv"
                                    first = false;
                                    #line 1029 "src/compiler/Generator.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 1029 "src/compiler/Generator.pv"
                                    fprintf(file, ", .");
                                }
                                #line 1030 "src/compiler/Generator.pv"
                                success = Generator__write_str(self, file, arg->name->value) && success;
                                #line 1031 "src/compiler/Generator.pv"
                                fprintf(file, " = ");
                                #line 1032 "src/compiler/Generator.pv"
                                success = Generator__write_expression(self, file, arg->value, generics) && success;
                            } }

                            #line 1035 "src/compiler/Generator.pv"
                            fprintf(file, " }");
                        } break;
                    }

                    #line 1040 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 1042 "src/compiler/Generator.pv"
                case TYPE__CLASS_CPP: {
                    #line 1043 "src/compiler/Generator.pv"
                    bool success = Generator__write_type(self, file, type, generics);
                    #line 1044 "src/compiler/Generator.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 1046 "src/compiler/Generator.pv"
                    if (function_mode) {
                        #line 1047 "src/compiler/Generator.pv"
                        fprintf(file, "(");

                        #line 1049 "src/compiler/Generator.pv"
                        bool first = true;
                        #line 1050 "src/compiler/Generator.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 1050 "src/compiler/Generator.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 1050 "src/compiler/Generator.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 1051 "src/compiler/Generator.pv"
                            if (first) {
                                #line 1051 "src/compiler/Generator.pv"
                                first = false;
                            } else {
                                #line 1051 "src/compiler/Generator.pv"
                                fprintf(file, ", ");
                            }
                            #line 1052 "src/compiler/Generator.pv"
                            success = Generator__write_expression(self, file, arg->value, generics) && success;
                        } }

                        #line 1055 "src/compiler/Generator.pv"
                        fprintf(file, ")");
                    } else {
                        #line 1057 "src/compiler/Generator.pv"
                        fprintf(file, " {");

                        #line 1059 "src/compiler/Generator.pv"
                        bool first = true;
                        #line 1060 "src/compiler/Generator.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 1060 "src/compiler/Generator.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 1060 "src/compiler/Generator.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 1061 "src/compiler/Generator.pv"
                            if (first) {
                                #line 1061 "src/compiler/Generator.pv"
                                first = false;
                                #line 1061 "src/compiler/Generator.pv"
                                fprintf(file, " .");
                            } else {
                                #line 1061 "src/compiler/Generator.pv"
                                fprintf(file, ", .");
                            }
                            #line 1062 "src/compiler/Generator.pv"
                            success = Generator__write_str(self, file, arg->name->value) && success;
                            #line 1063 "src/compiler/Generator.pv"
                            fprintf(file, " = ");
                            #line 1064 "src/compiler/Generator.pv"
                            success = Generator__write_expression(self, file, arg->value, generics) && success;
                        } }

                        #line 1067 "src/compiler/Generator.pv"
                        fprintf(file, " }");
                    }

                    #line 1070 "src/compiler/Generator.pv"
                    return success;
                } break;
                #line 1072 "src/compiler/Generator.pv"
                default: {
                    #line 1073 "src/compiler/Generator.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 1074 "src/compiler/Generator.pv"
                    return false;
                } break;
            }
        } break;
        #line 1078 "src/compiler/Generator.pv"
        default: {
        } break;
    }

    #line 1081 "src/compiler/Generator.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 1082 "src/compiler/Generator.pv"
    return false;
}

#line 1085 "src/compiler/Generator.pv"
bool Generator__write_expression(struct Generator* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 1086 "src/compiler/Generator.pv"
    struct ExpressionData* data = &expression->data;

    #line 1088 "src/compiler/Generator.pv"
    switch (data->type) {
        #line 1089 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 1089 "src/compiler/Generator.pv"
            struct str name = data->variable_value;
            #line 1090 "src/compiler/Generator.pv"
            Generator__write_variable(self, file, name);
            #line 1091 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1093 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 1093 "src/compiler/Generator.pv"
            struct str value = data->literal_value;
            #line 1094 "src/compiler/Generator.pv"
            Generator__write_literal(self, file, &expression->return_type, value);
            #line 1095 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1097 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 1097 "src/compiler/Generator.pv"
            struct Expression* target = data->invoke_value._0;
            #line 1097 "src/compiler/Generator.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 1098 "src/compiler/Generator.pv"
            return Generator__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 1100 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 1100 "src/compiler/Generator.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 1101 "src/compiler/Generator.pv"
            return Generator__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 1103 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 1103 "src/compiler/Generator.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 1103 "src/compiler/Generator.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 1104 "src/compiler/Generator.pv"
            bool skip_operator = str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 1105 "src/compiler/Generator.pv"
            if (!skip_operator) {
                #line 1105 "src/compiler/Generator.pv"
                Generator__write_str(self, file, operator);
            }
            #line 1106 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, inner, generics);
            #line 1107 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1109 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 1109 "src/compiler/Generator.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 1109 "src/compiler/Generator.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 1109 "src/compiler/Generator.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 1110 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, left, generics);
            #line 1111 "src/compiler/Generator.pv"
            fprintf(file, " ");
            #line 1112 "src/compiler/Generator.pv"
            Generator__write_str(self, file, operator);
            #line 1113 "src/compiler/Generator.pv"
            fprintf(file, " ");
            #line 1114 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, right, generics);
            #line 1115 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1117 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 1117 "src/compiler/Generator.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 1117 "src/compiler/Generator.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 1117 "src/compiler/Generator.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 1118 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, cond, generics);
            #line 1119 "src/compiler/Generator.pv"
            fprintf(file, " ? ");
            #line 1120 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, a, generics);
            #line 1121 "src/compiler/Generator.pv"
            fprintf(file, " : ");
            #line 1122 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, b, generics);
            #line 1123 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1125 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 1125 "src/compiler/Generator.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 1125 "src/compiler/Generator.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 1126 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, parent, generics);
            #line 1127 "src/compiler/Generator.pv"
            Generator__write_static_member_accessor(self, file, generics);
            #line 1128 "src/compiler/Generator.pv"
            Generator__write_str(self, file, member);

            #line 1130 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1132 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1132 "src/compiler/Generator.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 1132 "src/compiler/Generator.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 1133 "src/compiler/Generator.pv"
            struct Type* parent_type = &parent->return_type;

            #line 1135 "src/compiler/Generator.pv"
            if (Generator__is_type_single_value_struct(self, parent_type, generics)) {
                #line 1136 "src/compiler/Generator.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 1137 "src/compiler/Generator.pv"
                if (is_ref) {
                    #line 1137 "src/compiler/Generator.pv"
                    fprintf(file, "(*");
                }
                #line 1138 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, parent, generics);
                #line 1139 "src/compiler/Generator.pv"
                if (is_ref) {
                    #line 1139 "src/compiler/Generator.pv"
                    fprintf(file, ")");
                }
                #line 1140 "src/compiler/Generator.pv"
                return true;
            }

            #line 1143 "src/compiler/Generator.pv"
            switch (parent_type->type) {
                #line 1144 "src/compiler/Generator.pv"
                case TYPE__SEQUENCE: {
                    #line 1144 "src/compiler/Generator.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 1145 "src/compiler/Generator.pv"
                    switch (sequence->type.type) {
                        #line 1146 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 1146 "src/compiler/Generator.pv"
                            uintptr_t length = sequence->type.fixedarray_value;
                            #line 1147 "src/compiler/Generator.pv"
                            if (str__eq(member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 1148 "src/compiler/Generator.pv"
                                fprintf(file, "%zu", length);
                            } else {
                                #line 1150 "src/compiler/Generator.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 1151 "src/compiler/Generator.pv"
                                Generator__write_str(self, file, member);
                                #line 1152 "src/compiler/Generator.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 1155 "src/compiler/Generator.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 1156 "src/compiler/Generator.pv"
                            fprintf(file, "!!ERROR TODO MEMBERS FOR DYNAMIC SEQUENCES!!");
                        } break;
                    }
                } break;
                #line 1160 "src/compiler/Generator.pv"
                default: {
                    #line 1161 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, parent, generics);
                    #line 1162 "src/compiler/Generator.pv"
                    Generator__write_instance_member_accessor(self, file, &parent->return_type, generics);
                    #line 1163 "src/compiler/Generator.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 1163 "src/compiler/Generator.pv"
                        fprintf(file, "_");
                    }
                    #line 1164 "src/compiler/Generator.pv"
                    Generator__write_str(self, file, member);
                } break;
            }

            #line 1168 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1170 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1170 "src/compiler/Generator.pv"
            struct Type* type = data->type_value;
            #line 1171 "src/compiler/Generator.pv"
            Generator__write_type(self, file, type, generics);
            #line 1172 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1174 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1174 "src/compiler/Generator.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 1174 "src/compiler/Generator.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 1175 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, array_expr, generics);

            #line 1177 "src/compiler/Generator.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 1178 "src/compiler/Generator.pv"
                fprintf(file, ".data");
            }

            #line 1181 "src/compiler/Generator.pv"
            fprintf(file, "[");
            #line 1182 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, index_expr, generics);
            #line 1183 "src/compiler/Generator.pv"
            fprintf(file, "]");

            #line 1185 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1187 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1187 "src/compiler/Generator.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 1188 "src/compiler/Generator.pv"
            fprintf(file, "(");
            #line 1189 "src/compiler/Generator.pv"
            Generator__write_expression(self, file, expr, generics);
            #line 1190 "src/compiler/Generator.pv"
            fprintf(file, ")");

            #line 1192 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1194 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1194 "src/compiler/Generator.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 1195 "src/compiler/Generator.pv"
            switch (cpp_expression.type) {
                #line 1196 "src/compiler/Generator.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1196 "src/compiler/Generator.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 1196 "src/compiler/Generator.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 1197 "src/compiler/Generator.pv"
                    if (placement != 0) {
                        #line 1198 "src/compiler/Generator.pv"
                        fprintf(file, "new(");
                        #line 1199 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, placement, generics);
                        #line 1200 "src/compiler/Generator.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 1202 "src/compiler/Generator.pv"
                        fprintf(file, "new ");
                    }

                    #line 1205 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, new_expression, generics);
                } break;
                #line 1207 "src/compiler/Generator.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1207 "src/compiler/Generator.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1208 "src/compiler/Generator.pv"
                    fprintf(file, "delete ");
                    #line 1209 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, delete_expression, generics);
                } break;
            }

            #line 1213 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 1215 "src/compiler/Generator.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1215 "src/compiler/Generator.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 1216 "src/compiler/Generator.pv"
            switch (expression->return_type.type) {
                #line 1217 "src/compiler/Generator.pv"
                case TYPE__STRUCT: {
                    #line 1217 "src/compiler/Generator.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1218 "src/compiler/Generator.pv"
                    if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1219 "src/compiler/Generator.pv"
                        Generator__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 1222 "src/compiler/Generator.pv"
                case TYPE__INDIRECT: {
                    #line 1222 "src/compiler/Generator.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 1223 "src/compiler/Generator.pv"
                    switch (indirect->to.type) {
                        #line 1224 "src/compiler/Generator.pv"
                        case TYPE__STRUCT: {
                            #line 1224 "src/compiler/Generator.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 1225 "src/compiler/Generator.pv"
                            if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 1226 "src/compiler/Generator.pv"
                                Generator__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 1228 "src/compiler/Generator.pv"
                                Generator__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 1231 "src/compiler/Generator.pv"
                        case TYPE__SEQUENCE: {
                            #line 1231 "src/compiler/Generator.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 1231 "src/compiler/Generator.pv"
                            Generator__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 1232 "src/compiler/Generator.pv"
                        default: {
                            #line 1232 "src/compiler/Generator.pv"
                            Generator__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 1235 "src/compiler/Generator.pv"
                default: {
                    #line 1235 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 1240 "src/compiler/Generator.pv"
    return false;
}

#line 1243 "src/compiler/Generator.pv"
bool Generator__write_defer_statements(struct Generator* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics) {
    #line 1244 "src/compiler/Generator.pv"
    { struct Iter_ref_DeferStatement __iter = Array_DeferStatement__iter(defer_statements);
    #line 1244 "src/compiler/Generator.pv"
    while (Iter_ref_DeferStatement__next(&__iter)) {
        #line 1244 "src/compiler/Generator.pv"
        struct DeferStatement* defer_info = Iter_ref_DeferStatement__value(&__iter);

        #line 1245 "src/compiler/Generator.pv"
        switch (defer_info->type) {
            #line 1246 "src/compiler/Generator.pv"
            case DEFER_STATEMENT__EXPRESSION: {
                #line 1246 "src/compiler/Generator.pv"
                struct Expression* expression = defer_info->expression_value;
                #line 1247 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1248 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);
                #line 1249 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1251 "src/compiler/Generator.pv"
            case DEFER_STATEMENT__BLOCK: {
                #line 1251 "src/compiler/Generator.pv"
                struct Block* block = defer_info->block_value;
                #line 1252 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1253 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, false, false);
                #line 1254 "src/compiler/Generator.pv"
                Generator__write_block(self, file, return_type, block, generics, false, false);
                #line 1255 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);
            } break;
        }
    } }

    #line 1260 "src/compiler/Generator.pv"
    return true;
}

#line 1263 "src/compiler/Generator.pv"
bool Generator__is_coroutine(struct Generator* self) {
    #line 1264 "src/compiler/Generator.pv"
    return self->function_context->func_info->type == FUNCTION_TYPE__COROUTINE;
}

#line 1267 "src/compiler/Generator.pv"
void Generator__write_variable(struct Generator* self, FILE* file, struct str name) {
    #line 1268 "src/compiler/Generator.pv"
    name = FunctionContext__get_variable_replacement(self->function_context, name);
    #line 1269 "src/compiler/Generator.pv"
    Generator__write_str(self, file, name);
}

#line 1272 "src/compiler/Generator.pv"
bool Generator__write_block(struct Generator* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets) {
    #line 1273 "src/compiler/Generator.pv"
    if (block == 0) {
        #line 1274 "src/compiler/Generator.pv"
        fprintf(file, "{}\n");
        #line 1275 "src/compiler/Generator.pv"
        return false;
    }

    #line 1278 "src/compiler/Generator.pv"
    if (!no_brackets) {
        #line 1279 "src/compiler/Generator.pv"
        fprintf(file, "{\n");
        #line 1280 "src/compiler/Generator.pv"
        self->indent += 1;
    }

    #line 1283 "src/compiler/Generator.pv"
    if (block->is_top_level_and_has_defer_statements_inside && !Type__is_void(return_type)) {
        #line 1284 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 1285 "src/compiler/Generator.pv"
        Generator__write_type(self, file, return_type, generics);
        #line 1286 "src/compiler/Generator.pv"
        fprintf(file, " __result;\n\n");
    }

    #line 1289 "src/compiler/Generator.pv"
    bool last_statement_is_return = false;

    #line 1291 "src/compiler/Generator.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 1291 "src/compiler/Generator.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 1291 "src/compiler/Generator.pv"
        struct Statement* statement = Iter_ref_Statement__value(&__iter);

        #line 1292 "src/compiler/Generator.pv"
        if (statement > block->statements.data) {
            #line 1293 "src/compiler/Generator.pv"
            struct Statement* prev_statement = statement - 1;

            #line 1295 "src/compiler/Generator.pv"
            if (prev_statement->last_token->end_line < statement->first_token->start_line - 1) {
                #line 1296 "src/compiler/Generator.pv"
                fprintf(file, "\n");
            }
        }

        #line 1300 "src/compiler/Generator.pv"
        Generator__write_line_directive(self, file, block->context, statement->first_token);

        #line 1302 "src/compiler/Generator.pv"
        last_statement_is_return = false;

        #line 1304 "src/compiler/Generator.pv"
        switch (statement->data.type) {
            #line 1305 "src/compiler/Generator.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 1305 "src/compiler/Generator.pv"
                struct Block* child_block = statement->data.blockstatement_value;
                #line 1306 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1307 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, false, false);
                #line 1308 "src/compiler/Generator.pv"
                if (!Generator__write_block(self, file, return_type, child_block, generics, false, false)) {
                    #line 1309 "src/compiler/Generator.pv"
                    return false;
                }
                #line 1311 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);
            } break;
            #line 1313 "src/compiler/Generator.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 1313 "src/compiler/Generator.pv"
                struct LetStatement* let_statement = statement->data.letstatement_value;
                #line 1314 "src/compiler/Generator.pv"
                struct Token* name = let_statement->name;
                #line 1315 "src/compiler/Generator.pv"
                struct Type* type = let_statement->type;
                #line 1316 "src/compiler/Generator.pv"
                struct Expression* value = let_statement->value;

                #line 1318 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);

                #line 1320 "src/compiler/Generator.pv"
                if (!let_statement->is_static) {
                    #line 1321 "src/compiler/Generator.pv"
                    FunctionContext__add_variable(self->function_context, name->value, type);
                }

                #line 1324 "src/compiler/Generator.pv"
                if (let_statement->is_static) {
                    #line 1325 "src/compiler/Generator.pv"
                    fprintf(file, "static ");
                }

                #line 1328 "src/compiler/Generator.pv"
                if (Generator__is_coroutine(self)) {
                    #line 1329 "src/compiler/Generator.pv"
                    Generator__write_variable(self, file, name->value);
                } else {
                    #line 1331 "src/compiler/Generator.pv"
                    Generator__write_variable_decl(self, file, name->value, type, generics);
                }

                #line 1334 "src/compiler/Generator.pv"
                if (value != 0) {
                    #line 1335 "src/compiler/Generator.pv"
                    fprintf(file, " = ");
                    #line 1336 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, value, generics);
                }

                #line 1339 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1342 "src/compiler/Generator.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 1342 "src/compiler/Generator.pv"
                struct YieldStatement* yield_stmt = statement->data.yieldstatement_value;
                #line 1343 "src/compiler/Generator.pv"
                self->function_context->coroutine.yield_count += 1;

                #line 1345 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1346 "src/compiler/Generator.pv"
                uintptr_t yield_number = self->function_context->coroutine.yield_count;
                #line 1347 "src/compiler/Generator.pv"
                fprintf(file, "ctx->_value = ");
                #line 1348 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, yield_stmt->expression, generics);
                #line 1349 "src/compiler/Generator.pv"
                fprintf(file, "; ctx->_state = %zu; return true; yield_%zu:\n", yield_number, yield_number);
            } break;
            #line 1351 "src/compiler/Generator.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 1351 "src/compiler/Generator.pv"
                struct ReturnStatement* ret = statement->data.returnstatement_value;
                #line 1352 "src/compiler/Generator.pv"
                struct Expression* value = ret->expression;
                #line 1353 "src/compiler/Generator.pv"
                struct Array_DeferStatement* defer_statements = &ret->defer_statements;
                #line 1354 "src/compiler/Generator.pv"
                if (value == 0) {
                    #line 1355 "src/compiler/Generator.pv"
                    Generator__write_defer_statements(self, file, return_type, defer_statements, generics);
                    #line 1356 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1357 "src/compiler/Generator.pv"
                    fprintf(file, "return;\n");
                } else if (defer_statements->length > 0) {
                    #line 1359 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1360 "src/compiler/Generator.pv"
                    fprintf(file, "__result = ");
                    #line 1361 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, value, generics);
                    #line 1362 "src/compiler/Generator.pv"
                    fprintf(file, ";\n");

                    #line 1364 "src/compiler/Generator.pv"
                    Generator__write_defer_statements(self, file, return_type, defer_statements, generics);

                    #line 1366 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1367 "src/compiler/Generator.pv"
                    fprintf(file, "return __result;\n");
                } else {
                    #line 1369 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1370 "src/compiler/Generator.pv"
                    fprintf(file, "return ");
                    #line 1371 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, value, generics);
                    #line 1372 "src/compiler/Generator.pv"
                    fprintf(file, ";\n");
                }

                #line 1375 "src/compiler/Generator.pv"
                last_statement_is_return = true;
            } break;
            #line 1377 "src/compiler/Generator.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 1377 "src/compiler/Generator.pv"
                struct IfStatement* if_stmt = statement->data.ifstatement_value;
                #line 1378 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1379 "src/compiler/Generator.pv"
                fprintf(file, "if (");
                #line 1380 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, if_stmt->expression, generics);
                #line 1381 "src/compiler/Generator.pv"
                fprintf(file, ") ");
                #line 1382 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, false, false);
                #line 1383 "src/compiler/Generator.pv"
                if (!Generator__write_block(self, file, return_type, if_stmt->block, generics, true, false)) {
                    #line 1383 "src/compiler/Generator.pv"
                    return false;
                }
                #line 1384 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);

                #line 1386 "src/compiler/Generator.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&if_stmt->else_statements);
                #line 1386 "src/compiler/Generator.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 1386 "src/compiler/Generator.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 1387 "src/compiler/Generator.pv"
                    fprintf(file, " else ");

                    #line 1389 "src/compiler/Generator.pv"
                    if (else_statement->expression != 0) {
                        #line 1390 "src/compiler/Generator.pv"
                        fprintf(file, "if (");
                        #line 1391 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, else_statement->expression, generics);
                        #line 1392 "src/compiler/Generator.pv"
                        fprintf(file, ") ");
                    }

                    #line 1395 "src/compiler/Generator.pv"
                    FunctionContext__push_scope(self->function_context, false, false);
                    #line 1396 "src/compiler/Generator.pv"
                    if (!Generator__write_block(self, file, return_type, else_statement->block, generics, true, false)) {
                        #line 1396 "src/compiler/Generator.pv"
                        return false;
                    }
                    #line 1397 "src/compiler/Generator.pv"
                    FunctionContext__pop_scope(self->function_context);
                } }

                #line 1400 "src/compiler/Generator.pv"
                fprintf(file, "\n");
            } break;
            #line 1402 "src/compiler/Generator.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 1402 "src/compiler/Generator.pv"
                struct MatchStatement* match_stmt = statement->data.matchstatement_value;
                #line 1403 "src/compiler/Generator.pv"
                struct Expression* expression = match_stmt->expression;
                #line 1404 "src/compiler/Generator.pv"
                struct Array_MatchCase* cases = &match_stmt->cases;
                #line 1405 "src/compiler/Generator.pv"
                struct Type* return_type = &expression->return_type;
                #line 1406 "src/compiler/Generator.pv"
                bool is_discriminated_union = Generator__type_is_discriminated_union(self, return_type, generics);

                #line 1408 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1409 "src/compiler/Generator.pv"
                fprintf(file, "switch (");

                #line 1411 "src/compiler/Generator.pv"
                if (!is_discriminated_union) {
                    #line 1412 "src/compiler/Generator.pv"
                    Generator__write_deref_if_needed(self, file, return_type, generics);
                }

                #line 1415 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);

                #line 1417 "src/compiler/Generator.pv"
                if (is_discriminated_union) {
                    #line 1418 "src/compiler/Generator.pv"
                    Generator__write_instance_member_accessor(self, file, return_type, generics);
                    #line 1419 "src/compiler/Generator.pv"
                    fprintf(file, "type");
                }

                #line 1422 "src/compiler/Generator.pv"
                fprintf(file, ") {\n");
                #line 1423 "src/compiler/Generator.pv"
                self->indent += 1;

                #line 1425 "src/compiler/Generator.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 1425 "src/compiler/Generator.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 1425 "src/compiler/Generator.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 1426 "src/compiler/Generator.pv"
                    Generator__write_line_directive(self, file, block->context, case_info->first_token);

                    #line 1428 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);

                    #line 1430 "src/compiler/Generator.pv"
                    struct Array_MatchPattern* patterns = &case_info->patterns;
                    #line 1431 "src/compiler/Generator.pv"
                    { struct IterEnumerate_ref_MatchPattern __iter = Iter_ref_MatchPattern__enumerate(Array_MatchPattern__iter(patterns));
                    #line 1431 "src/compiler/Generator.pv"
                    while (IterEnumerate_ref_MatchPattern__next(&__iter)) {
                        #line 1431 "src/compiler/Generator.pv"
                        uintptr_t i = IterEnumerate_ref_MatchPattern__value(&__iter)._0;
                        #line 1431 "src/compiler/Generator.pv"
                        struct MatchPattern* pattern = IterEnumerate_ref_MatchPattern__value(&__iter)._1;

                        #line 1432 "src/compiler/Generator.pv"
                        if (i > 0) {
                            #line 1432 "src/compiler/Generator.pv"
                            fprintf(file, "\n");
                        }

                        #line 1434 "src/compiler/Generator.pv"
                        switch (pattern->type) {
                            #line 1435 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__STATIC_VALUE: {
                                #line 1435 "src/compiler/Generator.pv"
                                struct Expression* expr = pattern->staticvalue_value;
                                #line 1436 "src/compiler/Generator.pv"
                                fprintf(file, "case ");
                                #line 1437 "src/compiler/Generator.pv"
                                Generator__write_expression(self, file, expr, generics);
                                #line 1438 "src/compiler/Generator.pv"
                                fprintf(file, ":");
                            } break;
                            #line 1440 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 1440 "src/compiler/Generator.pv"
                                struct Type* type = pattern->enumvariant_value._0;
                                #line 1440 "src/compiler/Generator.pv"
                                struct EnumVariant* enum_variant = pattern->enumvariant_value._1;
                                #line 1441 "src/compiler/Generator.pv"
                                fprintf(file, "case ");
                                #line 1442 "src/compiler/Generator.pv"
                                Generator__write_enum_variant_name(self, file, type, enum_variant);
                                #line 1443 "src/compiler/Generator.pv"
                                fprintf(file, ":");
                            } break;
                            #line 1445 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__ENUM_CVALUE: {
                                #line 1445 "src/compiler/Generator.pv"
                                struct EnumCValue* enum_variant = pattern->enumcvalue_value;
                                #line 1446 "src/compiler/Generator.pv"
                                fprintf(file, "case ");

                                #line 1448 "src/compiler/Generator.pv"
                                struct EnumC* enum_info = enum_variant->parent;
                                #line 1449 "src/compiler/Generator.pv"
                                if (!ParentCpp__is_none(&enum_info->parent)) {
                                    #line 1450 "src/compiler/Generator.pv"
                                    struct String type_name = Naming__get_type_name(self->naming_decl, &(struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info }, generics->self_type, generics);
                                    #line 1451 "src/compiler/Generator.pv"
                                    Generator__write_str(self, file, String__as_str(&type_name));
                                    #line 1452 "src/compiler/Generator.pv"
                                    String__release(&type_name);
                                    #line 1453 "src/compiler/Generator.pv"
                                    fprintf(file, "::");
                                }

                                #line 1456 "src/compiler/Generator.pv"
                                Generator__write_str(self, file, enum_variant->name);
                                #line 1457 "src/compiler/Generator.pv"
                                fprintf(file, ":");
                            } break;
                            #line 1459 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__TYPE_ID: {
                                #line 1459 "src/compiler/Generator.pv"
                                struct Type* type = &pattern->typeid_value;
                                #line 1460 "src/compiler/Generator.pv"
                                fprintf(file, "case ");
                                #line 1461 "src/compiler/Generator.pv"
                                Generator__write_typeid(self, file, type, generics);
                                #line 1462 "src/compiler/Generator.pv"
                                fprintf(file, ":");
                            } break;
                            #line 1464 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__HASH: {
                                #line 1464 "src/compiler/Generator.pv"
                                struct Token* token = pattern->hash_value;
                                #line 1465 "src/compiler/Generator.pv"
                                fprintf(file, "case ");
                                #line 1466 "src/compiler/Generator.pv"
                                Hashed hash;

                                #line 1468 "src/compiler/Generator.pv"
                                switch (token->type) {
                                    #line 1469 "src/compiler/Generator.pv"
                                    case TOKEN_TYPE__STRING: {
                                        #line 1470 "src/compiler/Generator.pv"
                                        struct str value = str__slice(token->value, 1, token->value.length - 1);
                                        #line 1471 "src/compiler/Generator.pv"
                                        hash = str__Hash__hash(&value);
                                    } break;
                                    #line 1473 "src/compiler/Generator.pv"
                                    case TOKEN_TYPE__NUMBER: {
                                        #line 1474 "src/compiler/Generator.pv"
                                        struct str primitive = Expression__number_primitive(token->value);
                                        #line 1475 "src/compiler/Generator.pv"
                                        switch (str__Hash__hash(&primitive)) {
                                            #line 1476 "src/compiler/Generator.pv"
                                            case 15952682373371409732ULL: {
                                                #line 1477 "src/compiler/Generator.pv"
                                                float value = strtof(token->value.ptr, 0);
                                                #line 1478 "src/compiler/Generator.pv"
                                                hash = f32__Hash__hash(&value);
                                            } break;
                                            #line 1480 "src/compiler/Generator.pv"
                                            case 15957463049929925035ULL: {
                                                #line 1481 "src/compiler/Generator.pv"
                                                double value = strtod(token->value.ptr, 0);
                                                #line 1482 "src/compiler/Generator.pv"
                                                hash = f64__Hash__hash(&value);
                                            } break;
                                            #line 1484 "src/compiler/Generator.pv"
                                            case 5560783464435099345ULL: {
                                                #line 1485 "src/compiler/Generator.pv"
                                                uint32_t value = strtoul(token->value.ptr, 0, 10);
                                                #line 1486 "src/compiler/Generator.pv"
                                                hash = u32__Hash__hash(&value);
                                            } break;
                                            #line 1488 "src/compiler/Generator.pv"
                                            case 3094732814638223685ULL: {
                                                #line 1489 "src/compiler/Generator.pv"
                                                int32_t value = strtol(token->value.ptr, 0, 10);
                                                #line 1490 "src/compiler/Generator.pv"
                                                hash = i32__Hash__hash(&value);
                                            } break;
                                            #line 1492 "src/compiler/Generator.pv"
                                            default: {
                                                #line 1493 "src/compiler/Generator.pv"
                                                fprintf(stderr, "Hash match pattern on unsupported number literal type\n");
                                                #line 1494 "src/compiler/Generator.pv"
                                                hash = 0;
                                            } break;
                                        }
                                    } break;
                                    #line 1498 "src/compiler/Generator.pv"
                                    default: {
                                        #line 1499 "src/compiler/Generator.pv"
                                        fprintf(stderr, "Hash match pattern on unsupported token type\n");
                                        #line 1500 "src/compiler/Generator.pv"
                                        hash = 0;
                                    } break;
                                }

                                #line 1504 "src/compiler/Generator.pv"
                                fprintf(file, "%lluULL:", hash);
                            } break;
                            #line 1506 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__DEFAULT: {
                                #line 1507 "src/compiler/Generator.pv"
                                fprintf(file, "default:");
                            } break;
                        }
                    } }

                    #line 1512 "src/compiler/Generator.pv"
                    fprintf(file, " {\n");
                    #line 1513 "src/compiler/Generator.pv"
                    self->indent += 1;

                    #line 1515 "src/compiler/Generator.pv"
                    { struct Iter_ref_MatchPattern __iter = Array_MatchPattern__iter(patterns);
                    #line 1515 "src/compiler/Generator.pv"
                    while (Iter_ref_MatchPattern__next(&__iter)) {
                        #line 1515 "src/compiler/Generator.pv"
                        struct MatchPattern* pattern = Iter_ref_MatchPattern__value(&__iter);

                        #line 1516 "src/compiler/Generator.pv"
                        switch (pattern->type) {
                            #line 1517 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__STATIC_VALUE: {
                            } break;
                            #line 1518 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 1518 "src/compiler/Generator.pv"
                                struct EnumVariant* enum_variant = pattern->enumvariant_value._1;
                                #line 1518 "src/compiler/Generator.pv"
                                struct Array_EnumVariantParameter* parameters = &pattern->enumvariant_value._2;
                                #line 1519 "src/compiler/Generator.pv"
                                struct Array_Type* types = &enum_variant->types;

                                #line 1521 "src/compiler/Generator.pv"
                                uintptr_t param_i = 0;
                                #line 1522 "src/compiler/Generator.pv"
                                { struct Iter_ref_EnumVariantParameter __iter = Array_EnumVariantParameter__iter(parameters);
                                #line 1522 "src/compiler/Generator.pv"
                                while (Iter_ref_EnumVariantParameter__next(&__iter)) {
                                    #line 1522 "src/compiler/Generator.pv"
                                    struct EnumVariantParameter* param_iter = Iter_ref_EnumVariantParameter__value(&__iter);

                                    #line 1523 "src/compiler/Generator.pv"
                                    if (Token__eq(param_iter->variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                                        #line 1524 "src/compiler/Generator.pv"
                                        param_i += 1;
                                        #line 1525 "src/compiler/Generator.pv"
                                        continue;
                                    }

                                    #line 1528 "src/compiler/Generator.pv"
                                    struct Type* param_type = types->data + param_i;
                                    #line 1529 "src/compiler/Generator.pv"
                                    struct Expression* variable_expression = expression;
                                    #line 1530 "src/compiler/Generator.pv"
                                    struct String accessor = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

                                    #line 1532 "src/compiler/Generator.pv"
                                    String__append_str_lowercase(&accessor, enum_variant->name->value);
                                    #line 1533 "src/compiler/Generator.pv"
                                    String__append(&accessor, (struct str){ .ptr = "_value", .length = strlen("_value") });

                                    #line 1535 "src/compiler/Generator.pv"
                                    if (types->length > 1) {
                                        #line 1536 "src/compiler/Generator.pv"
                                        String__append(&accessor, (struct str){ .ptr = "._", .length = strlen("._") });
                                        #line 1537 "src/compiler/Generator.pv"
                                        String__append_usize(&accessor, param_i);
                                    }

                                    #line 1540 "src/compiler/Generator.pv"
                                    variable_expression = Expression__make(self->allocator, param_iter->variable, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = variable_expression, ._1 = String__as_str(&accessor)} }, param_type);

                                    #line 1542 "src/compiler/Generator.pv"
                                    struct Token* name = param_iter->variable;

                                    #line 1544 "src/compiler/Generator.pv"
                                    Generator__write_line_directive(self, file, block->context, name);

                                    #line 1546 "src/compiler/Generator.pv"
                                    Generator__write_indent(self, file);
                                    #line 1547 "src/compiler/Generator.pv"
                                    Generator__write_type(self, file, param_type, generics);
                                    #line 1548 "src/compiler/Generator.pv"
                                    if (param_iter->ref) {
                                        #line 1548 "src/compiler/Generator.pv"
                                        fprintf(file, "*");
                                    }

                                    #line 1550 "src/compiler/Generator.pv"
                                    fprintf(file, " ");

                                    #line 1552 "src/compiler/Generator.pv"
                                    Generator__write_token(self, file, name);
                                    #line 1553 "src/compiler/Generator.pv"
                                    fprintf(file, " = ");

                                    #line 1555 "src/compiler/Generator.pv"
                                    if (param_iter->ref) {
                                        #line 1555 "src/compiler/Generator.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 1556 "src/compiler/Generator.pv"
                                    Generator__write_expression(self, file, variable_expression, generics);

                                    #line 1558 "src/compiler/Generator.pv"
                                    fprintf(file, ";\n");

                                    #line 1560 "src/compiler/Generator.pv"
                                    param_i += 1;
                                } }
                            } break;
                            #line 1563 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__ENUM_CVALUE: {
                            } break;
                            #line 1564 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__TYPE_ID: {
                            } break;
                            #line 1565 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__HASH: {
                            } break;
                            #line 1566 "src/compiler/Generator.pv"
                            case MATCH_PATTERN__DEFAULT: {
                            } break;
                        }
                    } }

                    #line 1570 "src/compiler/Generator.pv"
                    FunctionContext__push_scope(self->function_context, true, false);
                    #line 1571 "src/compiler/Generator.pv"
                    if (!Generator__write_block(self, file, return_type, case_info->body, generics, true, true)) {
                        #line 1571 "src/compiler/Generator.pv"
                        return false;
                    }
                    #line 1572 "src/compiler/Generator.pv"
                    FunctionContext__pop_scope(self->function_context);

                    #line 1574 "src/compiler/Generator.pv"
                    self->indent -= 1;
                    #line 1575 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 1576 "src/compiler/Generator.pv"
                    fprintf(file, "} break;\n");
                } }

                #line 1579 "src/compiler/Generator.pv"
                self->indent -= 1;
                #line 1580 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1581 "src/compiler/Generator.pv"
                fprintf(file, "}\n");
            } break;
            #line 1583 "src/compiler/Generator.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 1583 "src/compiler/Generator.pv"
                struct WhileStatement* while_stmt = statement->data.whilestatement_value;
                #line 1584 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1585 "src/compiler/Generator.pv"
                fprintf(file, "while (");
                #line 1586 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, while_stmt->expression, generics);
                #line 1587 "src/compiler/Generator.pv"
                fprintf(file, ") ");
                #line 1588 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, true, true);
                #line 1589 "src/compiler/Generator.pv"
                if (!Generator__write_block(self, file, return_type, while_stmt->block, generics, false, false)) {
                    #line 1589 "src/compiler/Generator.pv"
                    return false;
                }
                #line 1590 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);
            } break;
            #line 1592 "src/compiler/Generator.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 1592 "src/compiler/Generator.pv"
                struct ForStatement* for_statement = statement->data.forstatement_value;
                #line 1593 "src/compiler/Generator.pv"
                bool is_iterator = false;

                #line 1595 "src/compiler/Generator.pv"
                switch (for_statement->type.type) {
                    #line 1596 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 1596 "src/compiler/Generator.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 1596 "src/compiler/Generator.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 1597 "src/compiler/Generator.pv"
                        is_iterator = true;
                        #line 1598 "src/compiler/Generator.pv"
                        struct ForVariable* variable = &for_statement->variables.data[0];
                        #line 1599 "src/compiler/Generator.pv"
                        struct str variable_name = variable->name->value;

                        #line 1601 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 1602 "src/compiler/Generator.pv"
                        fprintf(file, "for (");

                        #line 1604 "src/compiler/Generator.pv"
                        FunctionContext__add_variable(self->function_context, variable_name, variable->type);

                        #line 1606 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 1607 "src/compiler/Generator.pv"
                            Generator__write_variable(self, file, variable_name);
                        } else {
                            #line 1609 "src/compiler/Generator.pv"
                            Generator__write_variable_decl(self, file, variable_name, variable->type, generics);
                        }

                        #line 1612 "src/compiler/Generator.pv"
                        fprintf(file, " = ");
                        #line 1613 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, start, generics);
                        #line 1614 "src/compiler/Generator.pv"
                        fprintf(file, "; ");
                        #line 1615 "src/compiler/Generator.pv"
                        Generator__write_variable(self, file, variable_name);
                        #line 1616 "src/compiler/Generator.pv"
                        fprintf(file, " < ");
                        #line 1617 "src/compiler/Generator.pv"
                        Generator__write_expression(self, file, end, generics);
                        #line 1618 "src/compiler/Generator.pv"
                        fprintf(file, "; ");
                        #line 1619 "src/compiler/Generator.pv"
                        Generator__write_variable(self, file, variable_name);
                        #line 1620 "src/compiler/Generator.pv"
                        fprintf(file, "++) {");
                        #line 1621 "src/compiler/Generator.pv"
                        self->indent += 1;
                    } break;
                    #line 1623 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 1623 "src/compiler/Generator.pv"
                        struct Expression* iter_expression = for_statement->type.sequence_value;
                        #line 1624 "src/compiler/Generator.pv"
                        is_iterator = true;
                        #line 1625 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 1626 "src/compiler/Generator.pv"
                        switch (Type__deref(for_statement->iter_type)->type) {
                            #line 1627 "src/compiler/Generator.pv"
                            case TYPE__SEQUENCE: {
                                #line 1627 "src/compiler/Generator.pv"
                                struct Sequence* sequence = Type__deref(for_statement->iter_type)->sequence_value;
                                #line 1628 "src/compiler/Generator.pv"
                                switch (sequence->type.type) {
                                    #line 1629 "src/compiler/Generator.pv"
                                    case SEQUENCE_TYPE__FIXED_ARRAY: {
                                        #line 1629 "src/compiler/Generator.pv"
                                        uintptr_t size = sequence->type.fixedarray_value;
                                        #line 1630 "src/compiler/Generator.pv"
                                        fprintf(file, "for (size_t __iter = 0; __iter < %zu; __iter++) {\n", size);
                                    } break;
                                    #line 1632 "src/compiler/Generator.pv"
                                    case SEQUENCE_TYPE__SLICE: {
                                        #line 1633 "src/compiler/Generator.pv"
                                        fprintf(file, "for (size_t __iter = 0; __iter < ");
                                        #line 1634 "src/compiler/Generator.pv"
                                        Generator__write_expression(self, file, iter_expression, generics);
                                        #line 1635 "src/compiler/Generator.pv"
                                        fprintf(file, ".length; __iter++) {\n");
                                    } break;
                                }
                            } break;
                            #line 1639 "src/compiler/Generator.pv"
                            default: {
                                #line 1639 "src/compiler/Generator.pv"
                                fprintf(file, "/* ERROR: Sequence for loop on non-sequence type */");
                            } break;
                        }

                        #line 1642 "src/compiler/Generator.pv"
                        self->indent += 1;

                        #line 1644 "src/compiler/Generator.pv"
                        uintptr_t i = 0;
                        #line 1645 "src/compiler/Generator.pv"
                        { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                        #line 1645 "src/compiler/Generator.pv"
                        while (Iter_ref_ForVariable__next(&__iter)) {
                            #line 1645 "src/compiler/Generator.pv"
                            struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                            #line 1646 "src/compiler/Generator.pv"
                            if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                #line 1647 "src/compiler/Generator.pv"
                                Generator__write_line_directive(self, file, block->context, variable->name);

                                #line 1649 "src/compiler/Generator.pv"
                                Generator__write_indent(self, file);
                                #line 1650 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, variable->type, generics);
                                #line 1651 "src/compiler/Generator.pv"
                                fprintf(file, " ");
                                #line 1652 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, variable->name);
                                #line 1653 "src/compiler/Generator.pv"
                                fprintf(file, " = ");
                                #line 1654 "src/compiler/Generator.pv"
                                if (variable->ref) {
                                    #line 1654 "src/compiler/Generator.pv"
                                    fprintf(file, "&");
                                }
                                #line 1655 "src/compiler/Generator.pv"
                                if (variable->deref) {
                                    #line 1655 "src/compiler/Generator.pv"
                                    fprintf(file, "*");
                                }
                                #line 1656 "src/compiler/Generator.pv"
                                switch (Type__deref(for_statement->iter_type)->type) {
                                    #line 1657 "src/compiler/Generator.pv"
                                    case TYPE__SEQUENCE: {
                                        #line 1657 "src/compiler/Generator.pv"
                                        struct Sequence* sequence = Type__deref(for_statement->iter_type)->sequence_value;
                                        #line 1658 "src/compiler/Generator.pv"
                                        switch (sequence->type.type) {
                                            #line 1659 "src/compiler/Generator.pv"
                                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                                #line 1660 "src/compiler/Generator.pv"
                                                Generator__write_expression(self, file, iter_expression, generics);
                                                #line 1661 "src/compiler/Generator.pv"
                                                fprintf(file, "[__iter]");
                                            } break;
                                            #line 1663 "src/compiler/Generator.pv"
                                            case SEQUENCE_TYPE__SLICE: {
                                                #line 1664 "src/compiler/Generator.pv"
                                                Generator__write_expression(self, file, iter_expression, generics);
                                                #line 1665 "src/compiler/Generator.pv"
                                                fprintf(file, ".data[__iter]");
                                            } break;
                                        }
                                    } break;
                                    #line 1669 "src/compiler/Generator.pv"
                                    default: {
                                        #line 1669 "src/compiler/Generator.pv"
                                        fprintf(file, "/* ERROR */");
                                    } break;
                                }

                                #line 1672 "src/compiler/Generator.pv"
                                if (for_statement->variables.length > 1) {
                                    #line 1673 "src/compiler/Generator.pv"
                                    Generator__write_instance_member_accessor(self, file, for_statement->value_type, generics);
                                    #line 1674 "src/compiler/Generator.pv"
                                    fprintf(file, "_%zu", i);
                                }

                                #line 1677 "src/compiler/Generator.pv"
                                fprintf(file, ";\n");
                            }

                            #line 1680 "src/compiler/Generator.pv"
                            i += 1;
                        } }
                    } break;
                    #line 1683 "src/compiler/Generator.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 1683 "src/compiler/Generator.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 1684 "src/compiler/Generator.pv"
                        is_iterator = Type__is_iterator(Type__deref(for_statement->iter_type));
                        #line 1685 "src/compiler/Generator.pv"
                        if (is_iterator) {
                            #line 1686 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 1687 "src/compiler/Generator.pv"
                            fprintf(file, "while (");
                            #line 1688 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, iter_expression, generics);
                            #line 1689 "src/compiler/Generator.pv"
                            fprintf(file, ".vtable->next(");
                            #line 1690 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, iter_expression, generics);
                            #line 1691 "src/compiler/Generator.pv"
                            fprintf(file, ".instance)) {");

                            #line 1693 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 1695 "src/compiler/Generator.pv"
                            uintptr_t i = 0;
                            #line 1696 "src/compiler/Generator.pv"
                            { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 1696 "src/compiler/Generator.pv"
                            while (Iter_ref_ForVariable__next(&__iter)) {
                                #line 1696 "src/compiler/Generator.pv"
                                struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                                #line 1697 "src/compiler/Generator.pv"
                                if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 1698 "src/compiler/Generator.pv"
                                    Generator__write_line_directive(self, file, block->context, variable->name);

                                    #line 1700 "src/compiler/Generator.pv"
                                    Generator__write_indent(self, file);
                                    #line 1701 "src/compiler/Generator.pv"
                                    Generator__write_type(self, file, variable->type, generics);
                                    #line 1702 "src/compiler/Generator.pv"
                                    fprintf(file, " ");
                                    #line 1703 "src/compiler/Generator.pv"
                                    Generator__write_token(self, file, variable->name);
                                    #line 1704 "src/compiler/Generator.pv"
                                    fprintf(file, " = ");
                                    #line 1705 "src/compiler/Generator.pv"
                                    if (variable->ref) {
                                        #line 1705 "src/compiler/Generator.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 1706 "src/compiler/Generator.pv"
                                    if (variable->deref) {
                                        #line 1706 "src/compiler/Generator.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 1707 "src/compiler/Generator.pv"
                                    Generator__write_expression(self, file, iter_expression, generics);
                                    #line 1708 "src/compiler/Generator.pv"
                                    fprintf(file, ".vtable->value");
                                    #line 1709 "src/compiler/Generator.pv"
                                    if (for_statement->variables.length > 1) {
                                        #line 1709 "src/compiler/Generator.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 1710 "src/compiler/Generator.pv"
                                    fprintf(file, "(");
                                    #line 1711 "src/compiler/Generator.pv"
                                    Generator__write_expression(self, file, iter_expression, generics);
                                    #line 1712 "src/compiler/Generator.pv"
                                    fprintf(file, ".instance);\n");
                                }

                                #line 1715 "src/compiler/Generator.pv"
                                i += 1;
                            } }
                        } else {
                            #line 1718 "src/compiler/Generator.pv"
                            struct String iter_type_name = Naming__get_type_name(&self->naming_ident, for_statement->iter_type, generics->self_type, generics);

                            #line 1720 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 1721 "src/compiler/Generator.pv"
                            fprintf(file, "{ ");
                            #line 1722 "src/compiler/Generator.pv"
                            Generator__write_type(self, file, for_statement->iter_type, generics);
                            #line 1723 "src/compiler/Generator.pv"
                            fprintf(file, " __iter = ");
                            #line 1724 "src/compiler/Generator.pv"
                            Generator__write_expression(self, file, iter_expression, generics);
                            #line 1725 "src/compiler/Generator.pv"
                            fprintf(file, ";\n");

                            #line 1727 "src/compiler/Generator.pv"
                            Generator__write_line_directive(self, file, block->context, iter_expression->token);

                            #line 1729 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 1730 "src/compiler/Generator.pv"
                            fprintf(file, "while (");
                            #line 1731 "src/compiler/Generator.pv"
                            Generator__write_string(self, file, &iter_type_name);
                            #line 1732 "src/compiler/Generator.pv"
                            fprintf(file, "__next(&__iter)) {\n");

                            #line 1734 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 1736 "src/compiler/Generator.pv"
                            uintptr_t i = 0;
                            #line 1737 "src/compiler/Generator.pv"
                            { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 1737 "src/compiler/Generator.pv"
                            while (Iter_ref_ForVariable__next(&__iter)) {
                                #line 1737 "src/compiler/Generator.pv"
                                struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                                #line 1738 "src/compiler/Generator.pv"
                                if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 1739 "src/compiler/Generator.pv"
                                    Generator__write_line_directive(self, file, block->context, variable->name);

                                    #line 1741 "src/compiler/Generator.pv"
                                    Generator__write_indent(self, file);
                                    #line 1742 "src/compiler/Generator.pv"
                                    Generator__write_type(self, file, variable->type, generics);
                                    #line 1743 "src/compiler/Generator.pv"
                                    fprintf(file, " ");
                                    #line 1744 "src/compiler/Generator.pv"
                                    Generator__write_token(self, file, variable->name);
                                    #line 1745 "src/compiler/Generator.pv"
                                    fprintf(file, " = ");
                                    #line 1746 "src/compiler/Generator.pv"
                                    if (variable->ref) {
                                        #line 1746 "src/compiler/Generator.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 1747 "src/compiler/Generator.pv"
                                    if (variable->deref) {
                                        #line 1747 "src/compiler/Generator.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 1748 "src/compiler/Generator.pv"
                                    Generator__write_string(self, file, &iter_type_name);
                                    #line 1749 "src/compiler/Generator.pv"
                                    fprintf(file, "__value");
                                    #line 1750 "src/compiler/Generator.pv"
                                    if (!Type__is_tuple(Type__deref(for_statement->value_type)) && for_statement->variables.length > 1) {
                                        #line 1751 "src/compiler/Generator.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 1753 "src/compiler/Generator.pv"
                                    fprintf(file, "(&__iter)");

                                    #line 1755 "src/compiler/Generator.pv"
                                    if (Type__is_tuple(Type__deref(for_statement->value_type)) && for_statement->variables.length > 1) {
                                        #line 1756 "src/compiler/Generator.pv"
                                        Generator__write_instance_member_accessor(self, file, for_statement->value_type, generics);
                                        #line 1757 "src/compiler/Generator.pv"
                                        fprintf(file, "_%zu", i);
                                    }

                                    #line 1760 "src/compiler/Generator.pv"
                                    fprintf(file, ";\n");
                                }

                                #line 1763 "src/compiler/Generator.pv"
                                i += 1;
                            } }
                        }
                    } break;
                }

                #line 1769 "src/compiler/Generator.pv"
                fprintf(file, "\n");

                #line 1771 "src/compiler/Generator.pv"
                FunctionContext__push_scope(self->function_context, true, true);
                #line 1772 "src/compiler/Generator.pv"
                if (!Generator__write_block(self, file, return_type, for_statement->block, generics, false, true)) {
                    #line 1772 "src/compiler/Generator.pv"
                    return false;
                }
                #line 1773 "src/compiler/Generator.pv"
                FunctionContext__pop_scope(self->function_context);

                #line 1775 "src/compiler/Generator.pv"
                self->indent -= 1;
                #line 1776 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1777 "src/compiler/Generator.pv"
                if (is_iterator) {
                    #line 1778 "src/compiler/Generator.pv"
                    fprintf(file, "}\n");
                } else {
                    #line 1780 "src/compiler/Generator.pv"
                    fprintf(file, "} }\n");
                }
            } break;
            #line 1783 "src/compiler/Generator.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 1783 "src/compiler/Generator.pv"
                struct AssignmentStatement* assignment = statement->data.assignmentstatement_value;
                #line 1784 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1785 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, assignment->left, generics);
                #line 1786 "src/compiler/Generator.pv"
                fprintf(file, " ");
                #line 1787 "src/compiler/Generator.pv"
                Generator__write_str(self, file, assignment->operator->value);
                #line 1788 "src/compiler/Generator.pv"
                fprintf(file, " ");
                #line 1789 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, assignment->right, generics);
                #line 1790 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1792 "src/compiler/Generator.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 1792 "src/compiler/Generator.pv"
                struct Expression* expression = statement->data.expressionstatement_value;
                #line 1793 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1794 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, expression, generics);
                #line 1795 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } break;
            #line 1797 "src/compiler/Generator.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
                #line 1797 "src/compiler/Generator.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.continuestatement_value;
                #line 1798 "src/compiler/Generator.pv"
                Generator__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 1799 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1800 "src/compiler/Generator.pv"
                fprintf(file, "continue;\n");
            } break;
            #line 1802 "src/compiler/Generator.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
                #line 1802 "src/compiler/Generator.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.breakstatement_value;
                #line 1803 "src/compiler/Generator.pv"
                Generator__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 1804 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 1805 "src/compiler/Generator.pv"
                fprintf(file, "break;\n");
            } break;
        }
    } }

    #line 1810 "src/compiler/Generator.pv"
    if (!last_statement_is_return) {
        #line 1811 "src/compiler/Generator.pv"
        Generator__write_defer_statements(self, file, return_type, &block->defer_statements, generics);
    }

    #line 1814 "src/compiler/Generator.pv"
    if (!no_brackets) {
        #line 1815 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 1816 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);

        #line 1818 "src/compiler/Generator.pv"
        if (inline_) {
            #line 1819 "src/compiler/Generator.pv"
            fprintf(file, "}");
        } else {
            #line 1821 "src/compiler/Generator.pv"
            fprintf(file, "}\n");
        }
    }

    #line 1825 "src/compiler/Generator.pv"
    return true;
}

#line 1828 "src/compiler/Generator.pv"
void Generator__write_c_type_include(struct Generator* self, FILE* file, struct Type* type) {
    #line 1829 "src/compiler/Generator.pv"
    switch (type->type) {
        #line 1851 "src/compiler/Generator.pv"
        default: {
        } break;
    }
}

#line 1855 "src/compiler/Generator.pv"
void Generator__write_includes_raw(struct Generator* self, FILE* file, struct HashMap_str_ref_Include* includes) {
    #line 1856 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(includes);
    #line 1856 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 1856 "src/compiler/Generator.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 1857 "src/compiler/Generator.pv"
        struct str path = include->path;
        #line 1858 "src/compiler/Generator.pv"
        if (path.length > 0) {
            #line 1859 "src/compiler/Generator.pv"
            fprintf(file, "#include <%.*s>\n", (int32_t)(path.length - 2), path.ptr + 1);
        }
    } }

    #line 1863 "src/compiler/Generator.pv"
    if (includes->length > 0) {
        #line 1864 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 1868 "src/compiler/Generator.pv"
void Generator__write_impl_includes_raw(struct Generator* self, FILE* file, struct Array_ref_Impl* impls) {
    #line 1869 "src/compiler/Generator.pv"
    struct HashSet_str written = HashSet_str__new(self->allocator);

    #line 1872 "src/compiler/Generator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 1872 "src/compiler/Generator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 1872 "src/compiler/Generator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 1873 "src/compiler/Generator.pv"
        { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&impl_info->context->module->includes);
        #line 1873 "src/compiler/Generator.pv"
        while (HashMapIter_str_ref_Include__next(&__iter)) {
            #line 1873 "src/compiler/Generator.pv"
            struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

            #line 1874 "src/compiler/Generator.pv"
            if (!HashSet_str__insert(&written, include->path)) {
                #line 1874 "src/compiler/Generator.pv"
                continue;
            }
            #line 1875 "src/compiler/Generator.pv"
            fprintf(file, "#include ");
            #line 1876 "src/compiler/Generator.pv"
            Generator__write_str(self, file, include->path);
            #line 1877 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } }
    } }
    HashSet_str__release(&written);
}

#line 1882 "src/compiler/Generator.pv"
void Generator__write_context_primitives(struct Generator* self, FILE* file, struct HashSet_str* primitives, struct HashSet_str* exclude_primitives) {
    #line 1883 "src/compiler/Generator.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);

    #line 1885 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(primitives);
    #line 1885 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1885 "src/compiler/Generator.pv"
        struct str* primitive = HashSetIter_str__value(&__iter);

        #line 1886 "src/compiler/Generator.pv"
        if (exclude_primitives && HashSet_str__has(exclude_primitives, primitive)) {
            #line 1886 "src/compiler/Generator.pv"
            continue;
        }
        #line 1887 "src/compiler/Generator.pv"
        struct str* include = HashMap_str_str__find(&self->primitive_includes, primitive);
        #line 1888 "src/compiler/Generator.pv"
        if (include == 0) {
            #line 1888 "src/compiler/Generator.pv"
            continue;
        }
        #line 1889 "src/compiler/Generator.pv"
        HashSet_str__insert(&includes, *include);
    } }

    #line 1892 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 1892 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1892 "src/compiler/Generator.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 1893 "src/compiler/Generator.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 1896 "src/compiler/Generator.pv"
    if (includes.length > 0) {
        #line 1897 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
}

#line 1901 "src/compiler/Generator.pv"
void Generator__write_context_includes(struct Generator* self, FILE* file, struct HashMap_str_Type* types, struct GenericMap* generics, bool deref) {
    #line 1902 "src/compiler/Generator.pv"
    struct HashSet_str c_includes = HashSet_str__new(self->allocator);
    #line 1903 "src/compiler/Generator.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);

    #line 1905 "src/compiler/Generator.pv"
    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(types);
    #line 1905 "src/compiler/Generator.pv"
    while (HashMapIter_str_Type__next(&__iter)) {
        #line 1905 "src/compiler/Generator.pv"
        struct Type* type = &HashMapIter_str_Type__value(&__iter)->_1;

        #line 1906 "src/compiler/Generator.pv"
        struct Type* resolved = Context__resolve_type(self->allocator, type, generics, 0);
        #line 1907 "src/compiler/Generator.pv"
        if (deref) {
            #line 1907 "src/compiler/Generator.pv"
            resolved = Type__deref_all(resolved);
        }

        #line 1909 "src/compiler/Generator.pv"
        switch (resolved->type) {
            #line 1910 "src/compiler/Generator.pv"
            case TYPE__INDIRECT: {
                #line 1911 "src/compiler/Generator.pv"
                struct Type* type_deref = Type__deref_all(resolved);

                #line 1913 "src/compiler/Generator.pv"
                switch (type_deref->type) {
                    #line 1914 "src/compiler/Generator.pv"
                    case TYPE__TRAIT: {
                        #line 1915 "src/compiler/Generator.pv"
                        struct String name = Naming__get_type_name(&self->naming_ident, type_deref, generics->self_type, generics);
                        #line 1916 "src/compiler/Generator.pv"
                        struct Module* module = Type__get_module(type_deref);
                        #line 1917 "src/compiler/Generator.pv"
                        struct String path = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 1918 "src/compiler/Generator.pv"
                        if (!HashSet_str__insert(&includes, String__as_str(&path))) {
                            #line 1918 "src/compiler/Generator.pv"
                            String__release(&path);
                            #line 1918 "src/compiler/Generator.pv"
                            String__release(&name);
                            #line 1918 "src/compiler/Generator.pv"
                            continue;
                        }
                    } break;
                    #line 1920 "src/compiler/Generator.pv"
                    case TYPE__STRUCT: {
                        #line 1920 "src/compiler/Generator.pv"
                        struct Struct* struct_info = type_deref->struct_value._0;
                        #line 1921 "src/compiler/Generator.pv"
                        struct String name = Naming__get_type_name(&self->naming_c99, type_deref, generics->self_type, generics);

                        #line 1923 "src/compiler/Generator.pv"
                        if (Struct__is_newtype(struct_info)) {
                            #line 1924 "src/compiler/Generator.pv"
                            struct StructField* field = &struct_info->fields.data->value;

                            #line 1926 "src/compiler/Generator.pv"
                            fprintf(file, "typedef ");
                            #line 1927 "src/compiler/Generator.pv"
                            Generator__write_type(self, file, &field->type, generics);
                            #line 1928 "src/compiler/Generator.pv"
                            fprintf(file, " %.*s;\n", (int32_t)(String__length(&name)), name.array.data);
                        } else {
                            #line 1930 "src/compiler/Generator.pv"
                            fprintf(file, "%.*s;\n", (int32_t)(String__length(&name)), name.array.data);
                        }
                    } break;
                    #line 1934 "src/compiler/Generator.pv"
                    case TYPE__ENUM: {
                        #line 1934 "src/compiler/Generator.pv"
                        struct Enum* enum_info = type_deref->enum_value._0;
                        #line 1935 "src/compiler/Generator.pv"
                        if (Enum__is_discriminated_union(enum_info)) {
                            #line 1936 "src/compiler/Generator.pv"
                            struct String name = Naming__get_type_name(&self->naming_c99, type_deref, generics->self_type, generics);
                            #line 1937 "src/compiler/Generator.pv"
                            fprintf(file, "%.*s;\n", (int32_t)(String__length(&name)), name.array.data);
                        } else {
                            #line 1939 "src/compiler/Generator.pv"
                            struct String name = Naming__get_type_name(&self->naming_ident, type_deref, generics->self_type, generics);
                            #line 1940 "src/compiler/Generator.pv"
                            struct Module* module = Type__get_module(type_deref);
                            #line 1941 "src/compiler/Generator.pv"
                            struct String path = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                            #line 1942 "src/compiler/Generator.pv"
                            if (!HashSet_str__insert(&includes, String__as_str(&path))) {
                                #line 1942 "src/compiler/Generator.pv"
                                String__release(&path);
                                #line 1942 "src/compiler/Generator.pv"
                                String__release(&name);
                                #line 1942 "src/compiler/Generator.pv"
                                continue;
                            }
                        }
                    } break;
                    #line 1945 "src/compiler/Generator.pv"
                    default: {
                    } break;
                }
            } break;
            #line 1948 "src/compiler/Generator.pv"
            case TYPE__FUNCTION: {
                #line 1948 "src/compiler/Generator.pv"
                struct Function* func_info = resolved->function_value._0;
                #line 1949 "src/compiler/Generator.pv"
                switch (func_info->parent.type) {
                    #line 1950 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 1951 "src/compiler/Generator.pv"
                        struct String name = Naming__get_type_name(&self->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);
                        #line 1952 "src/compiler/Generator.pv"
                        struct Module* module = func_info->context->module;
                        #line 1953 "src/compiler/Generator.pv"
                        struct String path = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 1954 "src/compiler/Generator.pv"
                        if (!HashSet_str__insert(&includes, String__as_str(&path))) {
                            #line 1954 "src/compiler/Generator.pv"
                            String__release(&path);
                            #line 1954 "src/compiler/Generator.pv"
                            String__release(&name);
                            #line 1954 "src/compiler/Generator.pv"
                            continue;
                        }
                    } break;
                    #line 1956 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__PRIMITIVE: {
                        #line 1956 "src/compiler/Generator.pv"
                        struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                        #line 1957 "src/compiler/Generator.pv"
                        struct str name = primitive_info->name;
                        #line 1958 "src/compiler/Generator.pv"
                        struct String path = Generator__make_rel_path(self, 0, name, (struct str){ .ptr = "", .length = strlen("") });
                        #line 1959 "src/compiler/Generator.pv"
                        if (!HashSet_str__insert(&includes, String__as_str(&path))) {
                            #line 1959 "src/compiler/Generator.pv"
                            String__release(&path);
                            #line 1959 "src/compiler/Generator.pv"
                            continue;
                        }
                    } break;
                    #line 1961 "src/compiler/Generator.pv"
                    case FUNCTION_PARENT__TRAIT: {
                    } break;
                    #line 1962 "src/compiler/Generator.pv"
                    default: {
                    } break;
                }
            } break;
            #line 1966 "src/compiler/Generator.pv"
            case TYPE__ENUM_C: {
                #line 1966 "src/compiler/Generator.pv"
                struct EnumC* info = resolved->enumc_value;
                #line 1967 "src/compiler/Generator.pv"
                HashSet_str__insert(&c_includes, info->include->path);
            } break;
            #line 1969 "src/compiler/Generator.pv"
            case TYPE__STRUCT_C: {
                #line 1969 "src/compiler/Generator.pv"
                struct StructC* info = resolved->structc_value;
                #line 1970 "src/compiler/Generator.pv"
                HashSet_str__insert(&c_includes, info->include->path);
            } break;
            #line 1972 "src/compiler/Generator.pv"
            case TYPE__UNION_C: {
                #line 1972 "src/compiler/Generator.pv"
                struct StructC* info = resolved->unionc_value;
                #line 1973 "src/compiler/Generator.pv"
                HashSet_str__insert(&c_includes, info->include->path);
            } break;
            #line 1975 "src/compiler/Generator.pv"
            case TYPE__TYPEDEF_C: {
                #line 1975 "src/compiler/Generator.pv"
                struct TypedefC* info = resolved->typedefc_value;
                #line 1976 "src/compiler/Generator.pv"
                HashSet_str__insert(&c_includes, info->include->path);
            } break;
            #line 1978 "src/compiler/Generator.pv"
            case TYPE__FUNCTION_C: {
                #line 1978 "src/compiler/Generator.pv"
                struct FunctionC* info = resolved->functionc_value;
                #line 1979 "src/compiler/Generator.pv"
                HashSet_str__insert(&c_includes, info->include->path);
            } break;
            #line 1981 "src/compiler/Generator.pv"
            case TYPE__CLASS_CPP: {
                #line 1981 "src/compiler/Generator.pv"
                struct ClassCpp* info = resolved->classcpp_value;
                #line 1982 "src/compiler/Generator.pv"
                HashSet_str__insert(&c_includes, info->include->path);
            } break;
            #line 1984 "src/compiler/Generator.pv"
            default: {
                #line 1985 "src/compiler/Generator.pv"
                struct String name = Naming__get_type_name(&self->naming_ident, resolved, generics->self_type, generics);
                #line 1986 "src/compiler/Generator.pv"
                struct Module* module = Type__get_module(resolved);

                #line 1988 "src/compiler/Generator.pv"
                struct String path = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                #line 1989 "src/compiler/Generator.pv"
                if (!HashSet_str__insert(&includes, String__as_str(&path))) {
                    #line 1989 "src/compiler/Generator.pv"
                    String__release(&name);
                    #line 1989 "src/compiler/Generator.pv"
                    continue;
                }
            } break;
        }
    } }

    #line 1994 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&c_includes);
    #line 1994 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1994 "src/compiler/Generator.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 1995 "src/compiler/Generator.pv"
        fprintf(file, "#include <%.*s>\n", (int32_t)(include.length - 2), include.ptr + 1);
    } }

    #line 1998 "src/compiler/Generator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 1998 "src/compiler/Generator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1998 "src/compiler/Generator.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 1999 "src/compiler/Generator.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }
    HashSet_str__release(&includes);
}

#line 2005 "src/compiler/Generator.pv"
bool Generator__has_void_self_replacement(struct Parameter* parameter, struct GenericMap* generics) {
    #line 2006 "src/compiler/Generator.pv"
    if (generics == 0 || generics->self_type == 0) {
        #line 2006 "src/compiler/Generator.pv"
        return false;
    }

    #line 2008 "src/compiler/Generator.pv"
    switch (generics->self_type->type) {
        #line 2009 "src/compiler/Generator.pv"
        case TYPE__PRIMITIVE: {
            #line 2009 "src/compiler/Generator.pv"
            struct Primitive* primitive_info = generics->self_type->primitive_value;
            #line 2010 "src/compiler/Generator.pv"
            if (primitive_info != 0 && !str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 2011 "src/compiler/Generator.pv"
                return false;
            }
        } break;
        #line 2014 "src/compiler/Generator.pv"
        default: {
            #line 2014 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 2017 "src/compiler/Generator.pv"
    struct Type* ref = 0;

    #line 2019 "src/compiler/Generator.pv"
    switch (parameter->type.type) {
        #line 2020 "src/compiler/Generator.pv"
        case TYPE__INDIRECT: {
            #line 2020 "src/compiler/Generator.pv"
            struct Indirect* indirect = parameter->type.indirect_value;
            #line 2021 "src/compiler/Generator.pv"
            ref = &indirect->to;
        } break;
        #line 2023 "src/compiler/Generator.pv"
        default: {
            #line 2023 "src/compiler/Generator.pv"
            return false;
        } break;
    }

    #line 2026 "src/compiler/Generator.pv"
    if (ref == 0) {
        #line 2026 "src/compiler/Generator.pv"
        return false;
    }

    #line 2028 "src/compiler/Generator.pv"
    switch (ref->type) {
        #line 2029 "src/compiler/Generator.pv"
        case TYPE__SELF: {
            #line 2029 "src/compiler/Generator.pv"
            return true;
        } break;
        #line 2030 "src/compiler/Generator.pv"
        default: {
            #line 2030 "src/compiler/Generator.pv"
            return false;
        } break;
    }
}

#line 2034 "src/compiler/Generator.pv"
bool Generator__write_function_definition(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 2035 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, func_info->context, func_info->name);

    #line 2037 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 2038 "src/compiler/Generator.pv"
        fprintf(file, "bool");
    } else {
        #line 2040 "src/compiler/Generator.pv"
        if (!Generator__write_type(self, file, &func_info->return_type, generics)) {
            #line 2040 "src/compiler/Generator.pv"
            return false;
        }
    }

    #line 2043 "src/compiler/Generator.pv"
    fprintf(file, " ");
    #line 2044 "src/compiler/Generator.pv"
    if (custom_name != 0) {
        #line 2045 "src/compiler/Generator.pv"
        Generator__write_string(self, file, custom_name);
    } else {
        #line 2047 "src/compiler/Generator.pv"
        if (func_info->generics.map.length > 0) {
            #line 2048 "src/compiler/Generator.pv"
            struct String name = Naming__get_type_name(&self->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);
            #line 2049 "src/compiler/Generator.pv"
            Generator__write_string(self, file, &name);
        } else {
            #line 2051 "src/compiler/Generator.pv"
            if (!Generator__write_function_name(self, file, func_info, generics)) {
                #line 2051 "src/compiler/Generator.pv"
                return false;
            }
        }
    }

    #line 2055 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 2056 "src/compiler/Generator.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 2057 "src/compiler/Generator.pv"
        return true;
    }

    #line 2060 "src/compiler/Generator.pv"
    fprintf(file, "(");

    #line 2062 "src/compiler/Generator.pv"
    bool success = true;
    #line 2063 "src/compiler/Generator.pv"
    bool first = true;

    #line 2065 "src/compiler/Generator.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 2065 "src/compiler/Generator.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 2065 "src/compiler/Generator.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 2066 "src/compiler/Generator.pv"
        if (first) {
            #line 2066 "src/compiler/Generator.pv"
            first = false;
        } else {
            #line 2066 "src/compiler/Generator.pv"
            fprintf(file, ", ");
        }

        #line 2068 "src/compiler/Generator.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 2069 "src/compiler/Generator.pv"
            success = Generator__write_variable_decl(self, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 2071 "src/compiler/Generator.pv"
            success = Generator__write_variable_decl(self, file, parameter_iter->name->value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 2075 "src/compiler/Generator.pv"
    fprintf(file, ")");

    #line 2077 "src/compiler/Generator.pv"
    return success;
}

#line 2080 "src/compiler/Generator.pv"
bool Generator__generate_function_loop(struct Generator* self, struct TypeFunctionUsage* usage) {
    #line 2081 "src/compiler/Generator.pv"
    bool success = true;

    #line 2083 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 2083 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 2083 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 2084 "src/compiler/Generator.pv"
        success = Generator__generate_function(self, usage, usage_context) && success;
    } }

    #line 2087 "src/compiler/Generator.pv"
    return success;
}

#line 2090 "src/compiler/Generator.pv"
bool Generator__write_function_block(struct Generator* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics) {
    #line 2091 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 2092 "src/compiler/Generator.pv"
        fprintf(file, " {\n");
        #line 2093 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2095 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2096 "src/compiler/Generator.pv"
        fprintf(file, "struct ");
        #line 2097 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2098 "src/compiler/Generator.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 2100 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2101 "src/compiler/Generator.pv"
        fprintf(file, "switch (ctx->_state) {\n");
        #line 2102 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2104 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2105 "src/compiler/Generator.pv"
        fprintf(file, "case -1: return false;\n");

        #line 2107 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 2108 "src/compiler/Generator.pv"
        while (i < self->function_context->coroutine.yield_count) {
            #line 2109 "src/compiler/Generator.pv"
            i += 1;

            #line 2111 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2112 "src/compiler/Generator.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 2115 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2116 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2117 "src/compiler/Generator.pv"
        fprintf(file, "}\n\n");

        #line 2119 "src/compiler/Generator.pv"
        self->function_context->coroutine.yield_count = 0;
        #line 2120 "src/compiler/Generator.pv"
        if (!Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 2121 "src/compiler/Generator.pv"
            uint32_t name_length = name.length;
            #line 2122 "src/compiler/Generator.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 2123 "src/compiler/Generator.pv"
            fclose(file);
            #line 2124 "src/compiler/Generator.pv"
            return false;
        }

        #line 2127 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2128 "src/compiler/Generator.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 2130 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2131 "src/compiler/Generator.pv"
        fprintf(file, "}\n");

        #line 2133 "src/compiler/Generator.pv"
        Generator__write_type(self, file, &func_info->return_type, generics);
        #line 2134 "src/compiler/Generator.pv"
        fprintf(file, " ");
        #line 2135 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2136 "src/compiler/Generator.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 2137 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2138 "src/compiler/Generator.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 2140 "src/compiler/Generator.pv"
        fprintf(file, "struct trait_Iter_");

        #line 2142 "src/compiler/Generator.pv"
        struct String name = Naming__get_type_name(&self->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 2143 "src/compiler/Generator.pv"
        Generator__write_string(self, file, &name);
        #line 2144 "src/compiler/Generator.pv"
        String__release(&name);

        #line 2146 "src/compiler/Generator.pv"
        fprintf(file, "VTable ");

        #line 2148 "src/compiler/Generator.pv"
        switch (func_info->parent.type) {
            #line 2149 "src/compiler/Generator.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 2149 "src/compiler/Generator.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 2150 "src/compiler/Generator.pv"
                Generator__write_str_title(self, file, struct_info->name->value);
                #line 2151 "src/compiler/Generator.pv"
                fprintf(file, "__");
            } break;
            #line 2153 "src/compiler/Generator.pv"
            default: {
            } break;
        }

        #line 2156 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, func_info->name->value);

        #line 2158 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__ITER = { .next = ");
        #line 2159 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2160 "src/compiler/Generator.pv"
        fprintf(file, "__next, .value = ");
        #line 2161 "src/compiler/Generator.pv"
        Generator__write_function_name(self, file, func_info, generics);
        #line 2162 "src/compiler/Generator.pv"
        fprintf(file, "__value };\n\n");

        #line 2164 "src/compiler/Generator.pv"
        return true;
    }

    #line 2167 "src/compiler/Generator.pv"
    fprintf(file, " ");
    #line 2168 "src/compiler/Generator.pv"
    if (!Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 2169 "src/compiler/Generator.pv"
        uint32_t name_length = name.length;
        #line 2170 "src/compiler/Generator.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 2171 "src/compiler/Generator.pv"
        fclose(file);
        #line 2172 "src/compiler/Generator.pv"
        return false;
    }

    #line 2175 "src/compiler/Generator.pv"
    return true;
}

#line 2178 "src/compiler/Generator.pv"
bool Generator__write_function_coroutine(struct Generator* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 2179 "src/compiler/Generator.pv"
    fprintf(file, "struct ");
    #line 2180 "src/compiler/Generator.pv"
    Generator__write_function_name(self, file, func_info, generics);
    #line 2181 "src/compiler/Generator.pv"
    fprintf(file, " {\n");
    #line 2182 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 2184 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2185 "src/compiler/Generator.pv"
    fprintf(file, "int32_t _state;\n");

    #line 2187 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2188 "src/compiler/Generator.pv"
    Generator__write_type(self, file, &func_info->return_type, generics);
    #line 2189 "src/compiler/Generator.pv"
    fprintf(file, " _value;\n\n");

    #line 2191 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&self->function_context->coroutine.variables);
    #line 2191 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 2191 "src/compiler/Generator.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 2191 "src/compiler/Generator.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 2192 "src/compiler/Generator.pv"
        Generator__write_indent(self, file);
        #line 2193 "src/compiler/Generator.pv"
        Generator__write_type(self, file, type, generics);
        #line 2194 "src/compiler/Generator.pv"
        fprintf(file, " ");
        #line 2195 "src/compiler/Generator.pv"
        Generator__write_str(self, file, name);
        #line 2196 "src/compiler/Generator.pv"
        fprintf(file, ";\n");
    } }

    #line 2199 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 2200 "src/compiler/Generator.pv"
    fprintf(file, "};\n\n");

    #line 2202 "src/compiler/Generator.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 2204 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 2205 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &name);

    #line 2207 "src/compiler/Generator.pv"
    fprintf(file, ".h>\n");

    #line 2209 "src/compiler/Generator.pv"
    Generator__write_type(self, file, &func_info->return_type, generics);
    #line 2210 "src/compiler/Generator.pv"
    fprintf(file, " ");
    #line 2211 "src/compiler/Generator.pv"
    Generator__write_function_name(self, file, func_info, generics);
    #line 2212 "src/compiler/Generator.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 2214 "src/compiler/Generator.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 2215 "src/compiler/Generator.pv"
    Generator__write_string(self, file, &name);
    #line 2216 "src/compiler/Generator.pv"
    String__release(&name);

    #line 2218 "src/compiler/Generator.pv"
    fprintf(file, "VTable ");

    #line 2220 "src/compiler/Generator.pv"
    Generator__write_str_title(self, file, func_info->name->value);
    #line 2221 "src/compiler/Generator.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 2223 "src/compiler/Generator.pv"
    return true;
}

#line 2226 "src/compiler/Generator.pv"
bool Generator__generate_function(struct Generator* self, struct TypeFunctionUsage* usage, struct UsageContext* usage_context) {
    #line 2227 "src/compiler/Generator.pv"
    struct Function* func_info = usage->type;
    #line 2228 "src/compiler/Generator.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 2228 "src/compiler/Generator.pv"
        return true;
    }

    #line 2230 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;

    #line 2232 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2233 "src/compiler/Generator.pv"
    struct str name_str = String__as_str(&name);
    #line 2234 "src/compiler/Generator.pv"
    struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
    #line 2235 "src/compiler/Generator.pv"
    self->function_context = &func_context;

    #line 2237 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, func_info->context->module, name_str, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 2238 "src/compiler/Generator.pv"
    FILE* code_file = 0;
    #line 2239 "src/compiler/Generator.pv"
    char const* code_tmp = 0;

    #line 2241 "src/compiler/Generator.pv"
    code_tmp = tmpnam(0);
    #line 2242 "src/compiler/Generator.pv"
    code_file = fopen(code_tmp, "w+");

    #line 2244 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 2246 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 2246 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 2246 "src/compiler/Generator.pv"
        return false;
    }

    #line 2248 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 2249 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, code_file, &func_info->context->module->includes);
    #line 2250 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, code_file, &usage_context->body, generics, true);

    #line 2252 "src/compiler/Generator.pv"
    struct String header_rel = Generator__make_rel_path(self, func_info->context->module, name_str, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2253 "src/compiler/Generator.pv"
    fprintf(code_file, "#include <");
    #line 2254 "src/compiler/Generator.pv"
    Generator__write_str(self, code_file, String__as_str(&header_rel));
    #line 2255 "src/compiler/Generator.pv"
    fprintf(code_file, ">\n\n");

    #line 2257 "src/compiler/Generator.pv"
    if (!Generator__write_function_definition(self, code_file, func_info, generics, 0)) {
        #line 2257 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 2257 "src/compiler/Generator.pv"
        return false;
    }

    #line 2259 "src/compiler/Generator.pv"
    Generator__write_function_block(self, code_file, name_str, func_info, generics);

    #line 2261 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 2262 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 2263 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 2265 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, func_info->context->module, name_str, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2266 "src/compiler/Generator.pv"
    FILE* header_file = 0;
    #line 2267 "src/compiler/Generator.pv"
    char const* header_tmp = 0;
    #line 2268 "src/compiler/Generator.pv"
    header_tmp = tmpnam(0);
    #line 2269 "src/compiler/Generator.pv"
    header_file = fopen(header_tmp, "w+");

    #line 2271 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 2271 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 2271 "src/compiler/Generator.pv"
        return false;
    }

    #line 2273 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 2274 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name_str);
    #line 2275 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 2276 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name_str);
    #line 2277 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 2279 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_code, 0);
    #line 2280 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, header_file, &func_info->context->module->includes);
    #line 2281 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->signature, generics, false);

    #line 2283 "src/compiler/Generator.pv"
    if (Generator__is_coroutine(self)) {
        #line 2284 "src/compiler/Generator.pv"
        Generator__write_function_coroutine(self, header_file, func_info, generics);
    }

    #line 2287 "src/compiler/Generator.pv"
    if (!Generator__write_function_definition(self, header_file, func_info, generics, 0)) {
        #line 2287 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2287 "src/compiler/Generator.pv"
        return false;
    }
    #line 2288 "src/compiler/Generator.pv"
    fprintf(header_file, ";\n");

    #line 2290 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 2292 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 2293 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 2294 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 2296 "src/compiler/Generator.pv"
    self->function_context = 0;

    #line 2298 "src/compiler/Generator.pv"
    return true;
}

#line 2301 "src/compiler/Generator.pv"
bool Generator__write_enum_definition(struct Generator* self, FILE* file, struct Enum* enum_info, struct UsageContext* usage_context) {
    #line 2302 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 2303 "src/compiler/Generator.pv"
    struct Token* enum_name = enum_info->name;
    #line 2304 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2305 "src/compiler/Generator.pv"
    uint32_t name_length = name.array.length;
    #line 2306 "src/compiler/Generator.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 2308 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, enum_info->context, enum_info->name);

    #line 2310 "src/compiler/Generator.pv"
    if (!is_discriminated_union) {
        #line 2311 "src/compiler/Generator.pv"
        fprintf(file, "enum ");
        #line 2312 "src/compiler/Generator.pv"
        Generator__write_str(self, file, enum_name->value);
        #line 2313 "src/compiler/Generator.pv"
        fprintf(file, " {\n");
        #line 2314 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2316 "src/compiler/Generator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 2316 "src/compiler/Generator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 2316 "src/compiler/Generator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 2317 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2318 "src/compiler/Generator.pv"
            Generator__write_enum_variant_name(self, file, generics->self_type, variant);

            #line 2320 "src/compiler/Generator.pv"
            if (variant->value != 0) {
                #line 2321 "src/compiler/Generator.pv"
                fprintf(file, " = ");
                #line 2322 "src/compiler/Generator.pv"
                Generator__write_expression(self, file, variant->value, generics);
            }

            #line 2325 "src/compiler/Generator.pv"
            fprintf(file, ",\n");
        } }

        #line 2328 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2329 "src/compiler/Generator.pv"
        fprintf(file, "};\n");
    } else {
        #line 2331 "src/compiler/Generator.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 2333 "src/compiler/Generator.pv"
        if (has_generics) {
            #line 2334 "src/compiler/Generator.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 2335 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, enum_info->name->value);
            #line 2336 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2337 "src/compiler/Generator.pv"
            fprintf(file, "\n#define PAVE_");
            #line 2338 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, enum_info->name->value);
            #line 2339 "src/compiler/Generator.pv"
            Generator__write_str_title(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2340 "src/compiler/Generator.pv"
            fprintf(file, "\n");

            #line 2342 "src/compiler/Generator.pv"
            fprintf(file, "enum ");
            #line 2343 "src/compiler/Generator.pv"
            Generator__write_token(self, file, enum_info->name);
            #line 2344 "src/compiler/Generator.pv"
            Generator__write_str(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2345 "src/compiler/Generator.pv"
            fprintf(file, " {\n");

            #line 2347 "src/compiler/Generator.pv"
            self->indent += 1;

            #line 2349 "src/compiler/Generator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 2349 "src/compiler/Generator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 2349 "src/compiler/Generator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 2350 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2351 "src/compiler/Generator.pv"
                Generator__write_enum_variant_name(self, file, generics->self_type, variant);

                #line 2353 "src/compiler/Generator.pv"
                if (variant->value != 0) {
                    #line 2354 "src/compiler/Generator.pv"
                    fprintf(file, " = ");
                    #line 2355 "src/compiler/Generator.pv"
                    Generator__write_expression(self, file, variant->value, generics);
                }

                #line 2358 "src/compiler/Generator.pv"
                fprintf(file, ",\n");
            } }

            #line 2361 "src/compiler/Generator.pv"
            self->indent -= 1;
            #line 2362 "src/compiler/Generator.pv"
            fprintf(file, "};\n");
            #line 2363 "src/compiler/Generator.pv"
            fprintf(file, "#endif\n");
            #line 2364 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        }

        #line 2367 "src/compiler/Generator.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 2368 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2370 "src/compiler/Generator.pv"
        if (!has_generics) {
            #line 2371 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2372 "src/compiler/Generator.pv"
            fprintf(file, "enum {\n");
            #line 2373 "src/compiler/Generator.pv"
            self->indent += 1;

            #line 2375 "src/compiler/Generator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 2375 "src/compiler/Generator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 2375 "src/compiler/Generator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 2376 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2377 "src/compiler/Generator.pv"
                Generator__write_enum_variant_name(self, file, generics->self_type, variant);
                #line 2378 "src/compiler/Generator.pv"
                fprintf(file, ",\n");
            } }

            #line 2381 "src/compiler/Generator.pv"
            self->indent -= 1;
            #line 2382 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2383 "src/compiler/Generator.pv"
            fprintf(file, "} type;\n");
            #line 2384 "src/compiler/Generator.pv"
            fprintf(file, "\n");
        } else {
            #line 2386 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2387 "src/compiler/Generator.pv"
            fprintf(file, "enum ");
            #line 2388 "src/compiler/Generator.pv"
            Generator__write_token(self, file, enum_info->name);
            #line 2389 "src/compiler/Generator.pv"
            Generator__write_str(self, file, self->naming_ident.enum_generic_type_suffix);
            #line 2390 "src/compiler/Generator.pv"
            fprintf(file, " type;\n");
        }

        #line 2393 "src/compiler/Generator.pv"
        uintptr_t variants_with_data = 0;
        #line 2394 "src/compiler/Generator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 2394 "src/compiler/Generator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 2394 "src/compiler/Generator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 2395 "src/compiler/Generator.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 2398 "src/compiler/Generator.pv"
        if (variants_with_data > 1) {
            #line 2399 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2400 "src/compiler/Generator.pv"
            fprintf(file, "union {\n");
            #line 2401 "src/compiler/Generator.pv"
            self->indent += 1;
        }

        #line 2404 "src/compiler/Generator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 2404 "src/compiler/Generator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 2404 "src/compiler/Generator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 2405 "src/compiler/Generator.pv"
            if (variant->types.length == 1) {
                #line 2406 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2407 "src/compiler/Generator.pv"
                Generator__write_type(self, file, variant->types.data, generics);
                #line 2408 "src/compiler/Generator.pv"
                fprintf(file, " ");

                #line 2410 "src/compiler/Generator.pv"
                struct Token* name = variant->name;
                #line 2411 "src/compiler/Generator.pv"
                Generator__write_str_lowercase(self, file, name->value);
                #line 2412 "src/compiler/Generator.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 2414 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 2415 "src/compiler/Generator.pv"
                fprintf(file, "struct { ");

                #line 2417 "src/compiler/Generator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 2417 "src/compiler/Generator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 2417 "src/compiler/Generator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 2418 "src/compiler/Generator.pv"
                    Generator__write_type(self, file, type, generics);
                    #line 2419 "src/compiler/Generator.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 2422 "src/compiler/Generator.pv"
                fprintf(file, "} ");
                #line 2423 "src/compiler/Generator.pv"
                struct Token* name = variant->name;
                #line 2424 "src/compiler/Generator.pv"
                Generator__write_str_lowercase(self, file, name->value);
                #line 2425 "src/compiler/Generator.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 2429 "src/compiler/Generator.pv"
        if (variants_with_data > 1) {
            #line 2430 "src/compiler/Generator.pv"
            self->indent -= 1;
            #line 2431 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2432 "src/compiler/Generator.pv"
            fprintf(file, "};\n");
        }

        #line 2435 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2436 "src/compiler/Generator.pv"
        fprintf(file, "};\n");
    }

    #line 2439 "src/compiler/Generator.pv"
    fprintf(file, "\n");
    #line 2440 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, file, &usage_context->signature, generics, false);

    #line 2442 "src/compiler/Generator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
    #line 2442 "src/compiler/Generator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 2442 "src/compiler/Generator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 2443 "src/compiler/Generator.pv"
        fprintf(file, "\n");

        #line 2445 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2445 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2445 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2446 "src/compiler/Generator.pv"
            if (!Generator__write_function_definition(self, file, func_info, generics, 0)) {
                #line 2446 "src/compiler/Generator.pv"
                return false;
            }
            #line 2447 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 2451 "src/compiler/Generator.pv"
    return true;
}

#line 2454 "src/compiler/Generator.pv"
bool Generator__generate_enum_loop(struct Generator* self, struct TypeUsage_Enum* usage) {
    #line 2455 "src/compiler/Generator.pv"
    bool success = true;

    #line 2457 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 2457 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 2457 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 2458 "src/compiler/Generator.pv"
        success = Generator__generate_enum(self, usage, usage_context) && success;
    } }

    #line 2461 "src/compiler/Generator.pv"
    return success;
}

#line 2464 "src/compiler/Generator.pv"
bool Generator__generate_enum(struct Generator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 2465 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 2466 "src/compiler/Generator.pv"
    struct Enum* enum_info = usage->type;
    #line 2467 "src/compiler/Generator.pv"
    struct Module* module = enum_info->context->module;

    #line 2469 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2470 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2471 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 2472 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 2473 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 2473 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 2473 "src/compiler/Generator.pv"
        return false;
    }

    #line 2475 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 2476 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 2477 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 2478 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 2479 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 2481 "src/compiler/Generator.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
    #line 2481 "src/compiler/Generator.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 2481 "src/compiler/Generator.pv"
        struct Type* type = Iter_ref_Type__value(&__iter);

        #line 2482 "src/compiler/Generator.pv"
        Generator__write_c_type_include(self, header_file, Type__deref(type));
    } }

    #line 2485 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_header, 0);
    #line 2486 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, header_file, &module->includes);
    #line 2487 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->layout, generics, false);

    #line 2489 "src/compiler/Generator.pv"
    if (!Generator__write_enum_definition(self, header_file, enum_info, usage_context)) {
        #line 2489 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 2489 "src/compiler/Generator.pv"
        return false;
    }

    #line 2491 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 2493 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 2494 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 2495 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 2497 "src/compiler/Generator.pv"
    if (enum_info->impls.length == 0) {
        #line 2497 "src/compiler/Generator.pv"
        return true;
    }

    #line 2499 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 2500 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 2502 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 2503 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 2504 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 2504 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 2504 "src/compiler/Generator.pv"
        return false;
    }

    #line 2506 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 2507 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, code_file, &module->includes);
    #line 2508 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, code_file, &usage_context->body, generics, true);

    #line 2510 "src/compiler/Generator.pv"
    struct String header_rel = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 2511 "src/compiler/Generator.pv"
    fprintf(code_file, "#include <");
    #line 2512 "src/compiler/Generator.pv"
    Generator__write_str(self, code_file, String__as_str(&header_rel));
    #line 2513 "src/compiler/Generator.pv"
    fprintf(code_file, ">\n\n");

    #line 2515 "src/compiler/Generator.pv"
    if (!Generator__write_impls(self, code_file, module, &enum_info->impls, &usage->impl_functions, generics)) {
        #line 2515 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 2515 "src/compiler/Generator.pv"
        return false;
    }

    #line 2517 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 2518 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 2519 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 2521 "src/compiler/Generator.pv"
    return true;
}

#line 2524 "src/compiler/Generator.pv"
bool Generator__write_struct_definition(struct Generator* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 2525 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 2526 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2527 "src/compiler/Generator.pv"
    int32_t name_length = name.array.length;
    #line 2528 "src/compiler/Generator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage->impl_functions;

    #line 2530 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, &struct_info->module->context, struct_info->name);

    #line 2532 "src/compiler/Generator.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 2533 "src/compiler/Generator.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 2535 "src/compiler/Generator.pv"
        struct StructField* field = &struct_info->fields.data[0].value;

        #line 2537 "src/compiler/Generator.pv"
        fprintf(file, "typedef ");
        #line 2538 "src/compiler/Generator.pv"
        Generator__write_type(self, file, &field->type, generics);
        #line 2539 "src/compiler/Generator.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 2541 "src/compiler/Generator.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 2542 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 2544 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 2544 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 2544 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 2545 "src/compiler/Generator.pv"
            Generator__write_indent(self, file);
            #line 2546 "src/compiler/Generator.pv"
            Generator__write_variable_decl(self, file, field->name->value, &field->type, generics);
            #line 2547 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        } }

        #line 2550 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 2551 "src/compiler/Generator.pv"
        fprintf(file, "};\n");
    }

    #line 2554 "src/compiler/Generator.pv"
    if (usage_context->signature.length > 0) {
        #line 2554 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }
    #line 2555 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, file, &usage_context->signature, generics, false);

    #line 2557 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 2557 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 2557 "src/compiler/Generator.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 2557 "src/compiler/Generator.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 2558 "src/compiler/Generator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 2559 "src/compiler/Generator.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 2560 "src/compiler/Generator.pv"
        if (impl_functions != 0) {
            #line 2560 "src/compiler/Generator.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 2562 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2562 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2562 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2563 "src/compiler/Generator.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 2564 "src/compiler/Generator.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 2565 "src/compiler/Generator.pv"
            if (impl_functions_for_impl != 0) {
                #line 2565 "src/compiler/Generator.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 2567 "src/compiler/Generator.pv"
            if (func_info->generics.array.length == 0) {
                #line 2568 "src/compiler/Generator.pv"
                if (trait_info == 0) {
                    #line 2569 "src/compiler/Generator.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0) {
                        #line 2570 "src/compiler/Generator.pv"
                        self->function_context = &function_usage->function_context;
                        #line 2571 "src/compiler/Generator.pv"
                        Generator__write_function_coroutine(self, file, func_info, generics);
                        #line 2572 "src/compiler/Generator.pv"
                        self->function_context = 0;
                    }

                    #line 2575 "src/compiler/Generator.pv"
                    fprintf(file, "\n");
                    #line 2576 "src/compiler/Generator.pv"
                    if (!Generator__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 2576 "src/compiler/Generator.pv"
                        return false;
                    }
                } else {
                    #line 2578 "src/compiler/Generator.pv"
                    struct GenericMap generics_void = *generics;
                    #line 2579 "src/compiler/Generator.pv"
                    generics_void.self_type = &self->root->type_void;

                    #line 2581 "src/compiler/Generator.pv"
                    struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                    #line 2582 "src/compiler/Generator.pv"
                    fprintf(file, "\n");
                    #line 2583 "src/compiler/Generator.pv"
                    if (!Generator__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                        #line 2583 "src/compiler/Generator.pv"
                        return false;
                    }
                }

                #line 2586 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            }

            #line 2589 "src/compiler/Generator.pv"
            if (impl_functions_for_impl != 0) {
                #line 2590 "src/compiler/Generator.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 2591 "src/compiler/Generator.pv"
                if (function_usage != 0) {
                    #line 2592 "src/compiler/Generator.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 2592 "src/compiler/Generator.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 2592 "src/compiler/Generator.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 2593 "src/compiler/Generator.pv"
                        Generator__write_context_includes(self, file, &usage_context->signature, usage_context->generic_map, false);
                        #line 2596 "src/compiler/Generator.pv"
                        usage_context->generic_map->self_type = generics->self_type;
                        #line 2597 "src/compiler/Generator.pv"
                        fprintf(file, "\n");
                        #line 2598 "src/compiler/Generator.pv"
                        if (!Generator__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                            #line 2598 "src/compiler/Generator.pv"
                            return false;
                        }
                        #line 2599 "src/compiler/Generator.pv"
                        fprintf(file, ";\n");
                    } }

                    #line 2602 "src/compiler/Generator.pv"
                    if (function_usage->impl_dynamic_function) {
                        #line 2603 "src/compiler/Generator.pv"
                        if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                            #line 2604 "src/compiler/Generator.pv"
                            fprintf(file, "#include <std/trait_Co_CoroutineStatus.h>\n");
                            #line 2605 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 2606 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2607 "src/compiler/Generator.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance { ");
                            #line 2608 "src/compiler/Generator.pv"
                            self->indent += 1;
                            #line 2609 "src/compiler/Generator.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 2609 "src/compiler/Generator.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 2609 "src/compiler/Generator.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 2610 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, &param->type, generics);
                                #line 2611 "src/compiler/Generator.pv"
                                fprintf(file, " ");
                                #line 2612 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 2613 "src/compiler/Generator.pv"
                                fprintf(file, "; ");
                            } }
                            #line 2615 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 2616 "src/compiler/Generator.pv"
                            fprintf(file, "};\n");

                            #line 2618 "src/compiler/Generator.pv"
                            fprintf(file, "extern struct trait_Co_CoroutineStatusVTable ");
                            #line 2619 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, struct_info->name->value);
                            #line 2620 "src/compiler/Generator.pv"
                            fprintf(file, "__");
                            #line 2621 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, func_info->name->value);
                            #line 2622 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__CO;\n");
                        } else {
                            #line 2624 "src/compiler/Generator.pv"
                            fprintf(file, "#include <std/trait_Fn.h>\n");
                            #line 2625 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 2626 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2627 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__Instance { ");
                            #line 2628 "src/compiler/Generator.pv"
                            self->indent += 1;
                            #line 2629 "src/compiler/Generator.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 2629 "src/compiler/Generator.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 2629 "src/compiler/Generator.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 2630 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, &param->type, generics);
                                #line 2631 "src/compiler/Generator.pv"
                                fprintf(file, " ");
                                #line 2632 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 2633 "src/compiler/Generator.pv"
                                fprintf(file, "; ");
                            } }
                            #line 2635 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 2636 "src/compiler/Generator.pv"
                            fprintf(file, "};\n");

                            #line 2638 "src/compiler/Generator.pv"
                            fprintf(file, "extern struct trait_FnVTable ");
                            #line 2639 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, struct_info->name->value);
                            #line 2640 "src/compiler/Generator.pv"
                            fprintf(file, "__");
                            #line 2641 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, func_info->name->value);
                            #line 2642 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__DYN_FN;\n");
                        }
                    }
                }
            }
        } }

        #line 2649 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 2650 "src/compiler/Generator.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 2650 "src/compiler/Generator.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 2650 "src/compiler/Generator.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 2650 "src/compiler/Generator.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 2651 "src/compiler/Generator.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 2651 "src/compiler/Generator.pv"
                    continue;
                }

                #line 2653 "src/compiler/Generator.pv"
                fprintf(file, "\n");
                #line 2654 "src/compiler/Generator.pv"
                struct GenericMap generics_void = *generics;
                #line 2655 "src/compiler/Generator.pv"
                generics_void.self_type = &self->root->type_void;

                #line 2657 "src/compiler/Generator.pv"
                struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                #line 2658 "src/compiler/Generator.pv"
                if (!Generator__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                    #line 2658 "src/compiler/Generator.pv"
                    return false;
                }
                #line 2659 "src/compiler/Generator.pv"
                fprintf(file, ";\n");
            } }
        }
    } }

    #line 2664 "src/compiler/Generator.pv"
    if (struct_info->traits.length > 0) {
        #line 2664 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }

    #line 2666 "src/compiler/Generator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 2666 "src/compiler/Generator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 2666 "src/compiler/Generator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 2667 "src/compiler/Generator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 2668 "src/compiler/Generator.pv"
        fprintf(file, "extern struct ");
        #line 2669 "src/compiler/Generator.pv"
        Generator__write_type_name(self, file, trait_entry._1, generics);
        #line 2670 "src/compiler/Generator.pv"
        fprintf(file, "VTable ");
        #line 2671 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, String__as_str(&name));
        #line 2672 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__");
        #line 2673 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, trait_info->name->value);
        #line 2674 "src/compiler/Generator.pv"
        fprintf(file, ";\n");
    } }

    #line 2677 "src/compiler/Generator.pv"
    if (usage->impl_dynamic_usage) {
        #line 2678 "src/compiler/Generator.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 2679 "src/compiler/Generator.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 2680 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, String__as_str(&name));
        #line 2681 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 2684 "src/compiler/Generator.pv"
    return true;
}

#line 2687 "src/compiler/Generator.pv"
bool Generator__write_impl_definition(struct Generator* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 2688 "src/compiler/Generator.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 2690 "src/compiler/Generator.pv"
    fprintf(file, "\n");

    #line 2692 "src/compiler/Generator.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 2692 "src/compiler/Generator.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 2692 "src/compiler/Generator.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 2693 "src/compiler/Generator.pv"
        if (func_info->generics.array.length == 0) {
            #line 2694 "src/compiler/Generator.pv"
            if (trait_info == 0) {
                #line 2695 "src/compiler/Generator.pv"
                if (!Generator__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 2695 "src/compiler/Generator.pv"
                    return false;
                }
            } else {
                #line 2697 "src/compiler/Generator.pv"
                struct GenericMap generics_void = *generics;
                #line 2698 "src/compiler/Generator.pv"
                generics_void.self_type = &self->root->type_void;

                #line 2700 "src/compiler/Generator.pv"
                struct String func_name = Generator__get_trait_function_name(self, name, trait_info, func_info, generics);
                #line 2701 "src/compiler/Generator.pv"
                if (!Generator__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                    #line 2701 "src/compiler/Generator.pv"
                    return false;
                }
            }

            #line 2704 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        }
    } }
    #line 2709 "src/compiler/Generator.pv"
    if (trait_info != 0) {
        #line 2710 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 2710 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2710 "src/compiler/Generator.pv"
            struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
            #line 2710 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2711 "src/compiler/Generator.pv"
            if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                #line 2711 "src/compiler/Generator.pv"
                continue;
            }

            #line 2713 "src/compiler/Generator.pv"
            fprintf(file, "\n");
            #line 2714 "src/compiler/Generator.pv"
            struct GenericMap generics_void = *generics;
            #line 2715 "src/compiler/Generator.pv"
            generics_void.self_type = &self->root->type_void;

            #line 2717 "src/compiler/Generator.pv"
            struct String func_name = Generator__get_trait_function_name(self, name, trait_info, func_info, generics);
            #line 2718 "src/compiler/Generator.pv"
            if (!Generator__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                #line 2718 "src/compiler/Generator.pv"
                return false;
            }
            #line 2719 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        } }
    }

    #line 2723 "src/compiler/Generator.pv"
    return true;
}

#line 2726 "src/compiler/Generator.pv"
bool Generator__write_primitive_definition(struct Generator* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 2727 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);

    #line 2729 "src/compiler/Generator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 2729 "src/compiler/Generator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 2729 "src/compiler/Generator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 2730 "src/compiler/Generator.pv"
        Generator__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 2733 "src/compiler/Generator.pv"
    if (primitive_info->traits.length > 0) {
        #line 2733 "src/compiler/Generator.pv"
        fprintf(file, "\n");
    }

    #line 2735 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 2735 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 2735 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 2736 "src/compiler/Generator.pv"
        fprintf(file, "extern struct trait_");
        #line 2737 "src/compiler/Generator.pv"
        Generator__write_token(self, file, trait_info->name);
        #line 2738 "src/compiler/Generator.pv"
        fprintf(file, "VTable ");
        #line 2739 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, String__as_str(&name));
        #line 2740 "src/compiler/Generator.pv"
        fprintf(file, "__VTABLE__");
        #line 2741 "src/compiler/Generator.pv"
        Generator__write_str_title(self, file, trait_info->name->value);
        #line 2742 "src/compiler/Generator.pv"
        fprintf(file, ";\n");
    } }

    #line 2745 "src/compiler/Generator.pv"
    return true;
}

#line 2748 "src/compiler/Generator.pv"
bool Generator__write_trait_definition(struct Generator* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 2749 "src/compiler/Generator.pv"
    struct GenericMap void_self_generics = *generics;
    #line 2750 "src/compiler/Generator.pv"
    void_self_generics.self_type = &self->root->type_void;

    #line 2752 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 2753 "src/compiler/Generator.pv"
    int32_t name_length = name.array.length;

    #line 2755 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, &trait_info->module->context, trait_info->name);

    #line 2757 "src/compiler/Generator.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 2758 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 2760 "src/compiler/Generator.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 2760 "src/compiler/Generator.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 2760 "src/compiler/Generator.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 2761 "src/compiler/Generator.pv"
        if (func_info->generics.array.length == 0) {
            #line 2762 "src/compiler/Generator.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
            #line 2763 "src/compiler/Generator.pv"
            String__append(&func_name, (struct str){ .ptr = "(*", .length = strlen("(*") });
            #line 2764 "src/compiler/Generator.pv"
            String__append(&func_name, func_info->name->value);
            #line 2765 "src/compiler/Generator.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });
            #line 2766 "src/compiler/Generator.pv"
            if (!Generator__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 2766 "src/compiler/Generator.pv"
                return false;
            }
            #line 2767 "src/compiler/Generator.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 2771 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 2772 "src/compiler/Generator.pv"
    fprintf(file, "};\n\n");

    #line 2774 "src/compiler/Generator.pv"
    Generator__write_line_directive(self, file, &trait_info->module->context, trait_info->name);

    #line 2776 "src/compiler/Generator.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 2777 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 2779 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2780 "src/compiler/Generator.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 2781 "src/compiler/Generator.pv"
    Generator__write_indent(self, file);
    #line 2782 "src/compiler/Generator.pv"
    fprintf(file, "void* instance;\n");

    #line 2784 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 2785 "src/compiler/Generator.pv"
    fprintf(file, "};\n");

    #line 2787 "src/compiler/Generator.pv"
    return true;
}

#line 2790 "src/compiler/Generator.pv"
struct String Generator__get_trait_function_name(struct Generator* self, struct str struct_name, struct Trait* trait_info, struct Function* func_info, struct GenericMap* generics) {
    #line 2791 "src/compiler/Generator.pv"
    struct String trait_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });

    #line 2793 "src/compiler/Generator.pv"
    String__append(&trait_name, struct_name);
    #line 2794 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 2795 "src/compiler/Generator.pv"
    String__append(&trait_name, trait_info->name->value);
    #line 2796 "src/compiler/Generator.pv"
    String__append(&trait_name, (struct str){ .ptr = "__", .length = strlen("__") });
    #line 2797 "src/compiler/Generator.pv"
    String__append(&trait_name, func_info->name->value);

    #line 2799 "src/compiler/Generator.pv"
    return trait_name;
}

#line 2802 "src/compiler/Generator.pv"
bool Generator__write_impls(struct Generator* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics) {
    #line 2804 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 2805 "src/compiler/Generator.pv"
    int32_t name_length = name.array.length;
    #line 2806 "src/compiler/Generator.pv"
    struct String path = Generator__make_rel_path(self, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 2808 "src/compiler/Generator.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 2810 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 2810 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 2810 "src/compiler/Generator.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 2810 "src/compiler/Generator.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 2811 "src/compiler/Generator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 2812 "src/compiler/Generator.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 2813 "src/compiler/Generator.pv"
        if (impl_functions != 0) {
            #line 2813 "src/compiler/Generator.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 2815 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 2815 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 2815 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 2816 "src/compiler/Generator.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 2817 "src/compiler/Generator.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 2818 "src/compiler/Generator.pv"
            if (impl_functions_for_impl != 0) {
                #line 2818 "src/compiler/Generator.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 2820 "src/compiler/Generator.pv"
            if (func_info->generics.array.length == 0) {
                #line 2821 "src/compiler/Generator.pv"
                fprintf(file, "\n");
                #line 2822 "src/compiler/Generator.pv"
                if (trait_info != 0) {
                    #line 2823 "src/compiler/Generator.pv"
                    struct GenericMap generics_void = *generics;
                    #line 2824 "src/compiler/Generator.pv"
                    generics_void.self_type = &self->root->type_void;

                    #line 2826 "src/compiler/Generator.pv"
                    struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                    #line 2827 "src/compiler/Generator.pv"
                    if (!Generator__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                        #line 2828 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 2829 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 2830 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 2833 "src/compiler/Generator.pv"
                    fprintf(file, " {\n");
                    #line 2834 "src/compiler/Generator.pv"
                    self->indent += 1;

                    #line 2836 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 2837 "src/compiler/Generator.pv"
                    Generator__write_type(self, file, generics->self_type, generics);
                    #line 2838 "src/compiler/Generator.pv"
                    fprintf(file, "* self = ");

                    #line 2840 "src/compiler/Generator.pv"
                    if (module != 0 && module->mode_cpp) {
                        #line 2841 "src/compiler/Generator.pv"
                        fprintf(file, "(");
                        #line 2842 "src/compiler/Generator.pv"
                        Generator__write_type(self, file, generics->self_type, generics);
                        #line 2843 "src/compiler/Generator.pv"
                        fprintf(file, "*)");
                    }

                    #line 2846 "src/compiler/Generator.pv"
                    fprintf(file, "__self");
                    #line 2847 "src/compiler/Generator.pv"
                    fprintf(file, "; (void)self;\n");

                    #line 2849 "src/compiler/Generator.pv"
                    struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                    #line 2850 "src/compiler/Generator.pv"
                    if (function_usage != 0) {
                        #line 2850 "src/compiler/Generator.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 2851 "src/compiler/Generator.pv"
                    self->function_context = &func_context;

                    #line 2853 "src/compiler/Generator.pv"
                    if (!Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, false, true)) {
                        #line 2854 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 2855 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 2856 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 2859 "src/compiler/Generator.pv"
                    self->indent -= 1;
                    #line 2860 "src/compiler/Generator.pv"
                    Generator__write_indent(self, file);
                    #line 2861 "src/compiler/Generator.pv"
                    fprintf(file, "}\n");

                    #line 2863 "src/compiler/Generator.pv"
                    self->function_context = 0;
                } else {
                    #line 2865 "src/compiler/Generator.pv"
                    if (!Generator__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 2866 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 2867 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 2868 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 2871 "src/compiler/Generator.pv"
                    struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                    #line 2872 "src/compiler/Generator.pv"
                    if (function_usage != 0) {
                        #line 2872 "src/compiler/Generator.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 2873 "src/compiler/Generator.pv"
                    self->function_context = &func_context;

                    #line 2875 "src/compiler/Generator.pv"
                    if (!Generator__write_function_block(self, file, String__as_str(&name), func_info, generics)) {
                        #line 2876 "src/compiler/Generator.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 2877 "src/compiler/Generator.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 2878 "src/compiler/Generator.pv"
                        return false;
                    }

                    #line 2881 "src/compiler/Generator.pv"
                    struct TypeFunctionUsage* function_usage = 0;
                    #line 2882 "src/compiler/Generator.pv"
                    if (impl_functions_for_impl != 0) {
                        #line 2882 "src/compiler/Generator.pv"
                        function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                    }

                    #line 2884 "src/compiler/Generator.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 2885 "src/compiler/Generator.pv"
                        fprintf(file, "\n");
                        #line 2886 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 2887 "src/compiler/Generator.pv"
                            fprintf(file, "#include <std/trait_Allocator.h>\n");
                        }

                        #line 2890 "src/compiler/Generator.pv"
                        fprintf(file, "#include <std/Array_TypeId.h>\n");
                        #line 2891 "src/compiler/Generator.pv"
                        fprintf(file, "struct Array_TypeId* ");
                        #line 2892 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 2894 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 2895 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__get_params(void* __self) {\n");
                        } else {
                            #line 2897 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__get_params(void* __self) {\n");
                        }

                        #line 2900 "src/compiler/Generator.pv"
                        self->indent += 1;
                        #line 2901 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2902 "src/compiler/Generator.pv"
                        fprintf(file, "static TypeId type_ids[] = { ");

                        #line 2904 "src/compiler/Generator.pv"
                        bool first = true;
                        #line 2905 "src/compiler/Generator.pv"
                        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 2905 "src/compiler/Generator.pv"
                        while (Iter_ref_Parameter__next(&__iter)) {
                            #line 2905 "src/compiler/Generator.pv"
                            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                            #line 2906 "src/compiler/Generator.pv"
                            if (first) {
                                #line 2906 "src/compiler/Generator.pv"
                                first = false;
                            } else {
                                #line 2906 "src/compiler/Generator.pv"
                                fprintf(file, ", ");
                            }
                            #line 2907 "src/compiler/Generator.pv"
                            Generator__write_typeid(self, file, &param->type, generics);
                        } }

                        #line 2910 "src/compiler/Generator.pv"
                        fprintf(file, " };\n");
                        #line 2911 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2912 "src/compiler/Generator.pv"
                        fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
                        #line 2913 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2914 "src/compiler/Generator.pv"
                        fprintf(file, "return &result;\n");
                        #line 2915 "src/compiler/Generator.pv"
                        self->indent -= 1;
                        #line 2916 "src/compiler/Generator.pv"
                        fprintf(file, "}\n");

                        #line 2918 "src/compiler/Generator.pv"
                        fprintf(file, "bool ");
                        #line 2919 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 2921 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 2922 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        } else {
                            #line 2924 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        }

                        #line 2927 "src/compiler/Generator.pv"
                        self->indent += 1;

                        #line 2929 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2930 "src/compiler/Generator.pv"
                        fprintf(file, "struct ");
                        #line 2931 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 2933 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 2934 "src/compiler/Generator.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
                        } else {
                            #line 2936 "src/compiler/Generator.pv"
                            if (module->mode_cpp) {
                                #line 2937 "src/compiler/Generator.pv"
                                fprintf(file, "__Fn__Instance* self = (struct ");
                                #line 2938 "src/compiler/Generator.pv"
                                Generator__write_function_name(self, file, func_info, generics);
                                #line 2939 "src/compiler/Generator.pv"
                                fprintf(file, "__Fn__Instance*)__self;\n");
                            } else {
                                #line 2942 "src/compiler/Generator.pv"
                                fprintf(file, "__Fn__Instance* self = __self;\n");
                            }
                        }

                        #line 2946 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2947 "src/compiler/Generator.pv"
                        fprintf(file, "switch (index) {\n");
                        #line 2948 "src/compiler/Generator.pv"
                        self->indent += 1;

                        #line 2950 "src/compiler/Generator.pv"
                        uintptr_t i = 0;
                        #line 2951 "src/compiler/Generator.pv"
                        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 2951 "src/compiler/Generator.pv"
                        while (Iter_ref_Parameter__next(&__iter)) {
                            #line 2951 "src/compiler/Generator.pv"
                            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                            #line 2952 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 2953 "src/compiler/Generator.pv"
                            fprintf(file, "case %zu: self->", i);
                            #line 2954 "src/compiler/Generator.pv"
                            Generator__write_token(self, file, param->name);
                            #line 2955 "src/compiler/Generator.pv"
                            fprintf(file, " = ");

                            #line 2957 "src/compiler/Generator.pv"
                            if (!Generator__is_reference(&param->type)) {
                                #line 2958 "src/compiler/Generator.pv"
                                fprintf(file, "*(");
                                #line 2959 "src/compiler/Generator.pv"
                                Generator__write_type(self, file, &param->type, generics);
                                #line 2960 "src/compiler/Generator.pv"
                                fprintf(file, "*)");
                            } else {
                                #line 2962 "src/compiler/Generator.pv"
                                if (module->mode_cpp) {
                                    #line 2963 "src/compiler/Generator.pv"
                                    fprintf(file, "(");
                                    #line 2964 "src/compiler/Generator.pv"
                                    Generator__write_type(self, file, &param->type, generics);
                                    #line 2965 "src/compiler/Generator.pv"
                                    fprintf(file, ")");
                                }
                            }

                            #line 2969 "src/compiler/Generator.pv"
                            fprintf(file, "value; return true;\n");
                            #line 2970 "src/compiler/Generator.pv"
                            i += 1;
                        } }

                        #line 2973 "src/compiler/Generator.pv"
                        self->indent -= 1;
                        #line 2974 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2975 "src/compiler/Generator.pv"
                        fprintf(file, "}\n");

                        #line 2977 "src/compiler/Generator.pv"
                        Generator__write_indent(self, file);
                        #line 2978 "src/compiler/Generator.pv"
                        fprintf(file, "return false;\n");

                        #line 2980 "src/compiler/Generator.pv"
                        self->indent -= 1;
                        #line 2981 "src/compiler/Generator.pv"
                        fprintf(file, "}\n");

                        #line 2983 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 2984 "src/compiler/Generator.pv"
                            fprintf(file, "struct Iter_CoroutineStatus ");
                            #line 2985 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2986 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

                            #line 2988 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 2990 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 2991 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 2992 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2993 "src/compiler/Generator.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

                            #line 2995 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 2996 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 2997 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 2998 "src/compiler/Generator.pv"
                            fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
                            #line 2999 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3000 "src/compiler/Generator.pv"
                            fprintf(file, "));\n");

                            #line 3002 "src/compiler/Generator.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 3002 "src/compiler/Generator.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 3002 "src/compiler/Generator.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 3003 "src/compiler/Generator.pv"
                                Generator__write_indent(self, file);
                                #line 3004 "src/compiler/Generator.pv"
                                fprintf(file, "instance->");
                                #line 3005 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 3006 "src/compiler/Generator.pv"
                                fprintf(file, " = ");
                                #line 3007 "src/compiler/Generator.pv"
                                fprintf(file, "self->");
                                #line 3008 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                                #line 3009 "src/compiler/Generator.pv"
                                fprintf(file, ";\n");
                            } }

                            #line 3012 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3013 "src/compiler/Generator.pv"
                            fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");

                            #line 3015 "src/compiler/Generator.pv"
                            switch (func_info->parent.type) {
                                #line 3016 "src/compiler/Generator.pv"
                                case FUNCTION_PARENT__STRUCT: {
                                    #line 3016 "src/compiler/Generator.pv"
                                    struct Struct* struct_info = func_info->parent.struct_value._0;
                                    #line 3017 "src/compiler/Generator.pv"
                                    Generator__write_str_title(self, file, struct_info->name->value);
                                    #line 3018 "src/compiler/Generator.pv"
                                    fprintf(file, "__");
                                } break;
                                #line 3020 "src/compiler/Generator.pv"
                                default: {
                                } break;
                            }
                            #line 3022 "src/compiler/Generator.pv"
                            Generator__write_str_title(self, file, func_info->name->value);

                            #line 3024 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

                            #line 3026 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 3027 "src/compiler/Generator.pv"
                            fprintf(file, "}\n");
                        } else {
                            #line 3029 "src/compiler/Generator.pv"
                            fprintf(file, "void ");
                            #line 3030 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3031 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__execute(void* __self) {\n");

                            #line 3033 "src/compiler/Generator.pv"
                            self->indent += 1;

                            #line 3035 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3036 "src/compiler/Generator.pv"
                            fprintf(file, "struct ");
                            #line 3037 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3038 "src/compiler/Generator.pv"
                            if (module->mode_cpp) {
                                #line 3039 "src/compiler/Generator.pv"
                                fprintf(file, "__Fn__Instance* self = (struct ");
                                #line 3040 "src/compiler/Generator.pv"
                                Generator__write_function_name(self, file, func_info, generics);
                                #line 3041 "src/compiler/Generator.pv"
                                fprintf(file, "__Fn__Instance*)__self;\n");
                            } else {
                                #line 3044 "src/compiler/Generator.pv"
                                fprintf(file, "__Fn__Instance* self = __self;\n");
                            }

                            #line 3047 "src/compiler/Generator.pv"
                            Generator__write_indent(self, file);
                            #line 3048 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3049 "src/compiler/Generator.pv"
                            fprintf(file, "(");

                            #line 3051 "src/compiler/Generator.pv"
                            first = true;
                            #line 3052 "src/compiler/Generator.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 3052 "src/compiler/Generator.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 3052 "src/compiler/Generator.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 3053 "src/compiler/Generator.pv"
                                if (first) {
                                    #line 3053 "src/compiler/Generator.pv"
                                    first = false;
                                } else {
                                    #line 3053 "src/compiler/Generator.pv"
                                    fprintf(file, ", ");
                                }
                                #line 3054 "src/compiler/Generator.pv"
                                fprintf(file, "self->");
                                #line 3055 "src/compiler/Generator.pv"
                                Generator__write_token(self, file, param->name);
                            } }

                            #line 3058 "src/compiler/Generator.pv"
                            fprintf(file, ");\n");

                            #line 3060 "src/compiler/Generator.pv"
                            self->indent -= 1;
                            #line 3061 "src/compiler/Generator.pv"
                            fprintf(file, "}\n");
                        }

                        #line 3064 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3065 "src/compiler/Generator.pv"
                            fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
                        } else {
                            #line 3067 "src/compiler/Generator.pv"
                            fprintf(file, "struct trait_FnVTable ");
                        }

                        #line 3070 "src/compiler/Generator.pv"
                        switch (func_info->parent.type) {
                            #line 3071 "src/compiler/Generator.pv"
                            case FUNCTION_PARENT__STRUCT: {
                                #line 3071 "src/compiler/Generator.pv"
                                struct Struct* struct_info = func_info->parent.struct_value._0;
                                #line 3072 "src/compiler/Generator.pv"
                                Generator__write_str_title(self, file, struct_info->name->value);
                                #line 3073 "src/compiler/Generator.pv"
                                fprintf(file, "__");
                            } break;
                            #line 3075 "src/compiler/Generator.pv"
                            default: {
                            } break;
                        }
                        #line 3077 "src/compiler/Generator.pv"
                        Generator__write_str_title(self, file, func_info->name->value);

                        #line 3079 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3080 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__CO");
                        } else {
                            #line 3082 "src/compiler/Generator.pv"
                            fprintf(file, "__VTABLE__DYN_FN");
                        }

                        #line 3085 "src/compiler/Generator.pv"
                        fprintf(file, " = { .get_params = &");
                        #line 3086 "src/compiler/Generator.pv"
                        Generator__write_function_name(self, file, func_info, generics);

                        #line 3088 "src/compiler/Generator.pv"
                        if (Generator__is_coroutine(self)) {
                            #line 3089 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__get_params, .set_arg = &");
                            #line 3090 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3091 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__set_arg, .init = &");
                            #line 3092 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3093 "src/compiler/Generator.pv"
                            fprintf(file, "__Co__init };\n");
                        } else {
                            #line 3095 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__get_params, .set_arg = &");
                            #line 3096 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3097 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__set_arg, .execute = &");
                            #line 3098 "src/compiler/Generator.pv"
                            Generator__write_function_name(self, file, func_info, generics);
                            #line 3099 "src/compiler/Generator.pv"
                            fprintf(file, "__Fn__execute };\n");
                        }
                    }

                    #line 3103 "src/compiler/Generator.pv"
                    self->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 3106 "src/compiler/Generator.pv"
                if (function_usage != 0) {
                    #line 3107 "src/compiler/Generator.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(self->allocator, sizeof(struct Function));
                    #line 3108 "src/compiler/Generator.pv"
                    *func2 = *func_info;

                    #line 3110 "src/compiler/Generator.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 3110 "src/compiler/Generator.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 3110 "src/compiler/Generator.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 3111 "src/compiler/Generator.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 3114 "src/compiler/Generator.pv"
                        generics3->self_type = generics->self_type;

                        #line 3116 "src/compiler/Generator.pv"
                        fprintf(file, "\n");
                        #line 3117 "src/compiler/Generator.pv"
                        if (!Generator__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 3118 "src/compiler/Generator.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 3119 "src/compiler/Generator.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 3120 "src/compiler/Generator.pv"
                            return false;
                        }

                        #line 3123 "src/compiler/Generator.pv"
                        struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                        #line 3124 "src/compiler/Generator.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                        #line 3125 "src/compiler/Generator.pv"
                        self->function_context = &func_context;

                        #line 3127 "src/compiler/Generator.pv"
                        Generator__write_function_block(self, file, String__as_str(&name), func_info, generics3);

                        #line 3129 "src/compiler/Generator.pv"
                        self->function_context = 0;
                    } }
                }
            }
        } }
        #line 3136 "src/compiler/Generator.pv"
        if (trait_info != 0) {
            #line 3137 "src/compiler/Generator.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 3137 "src/compiler/Generator.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 3137 "src/compiler/Generator.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 3137 "src/compiler/Generator.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 3138 "src/compiler/Generator.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 3138 "src/compiler/Generator.pv"
                    continue;
                }

                #line 3140 "src/compiler/Generator.pv"
                fprintf(file, "\n");
                #line 3141 "src/compiler/Generator.pv"
                struct GenericMap generics_void = *generics;
                #line 3142 "src/compiler/Generator.pv"
                generics_void.self_type = &self->root->type_void;

                #line 3144 "src/compiler/Generator.pv"
                struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
                #line 3145 "src/compiler/Generator.pv"
                if (!Generator__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                    #line 3146 "src/compiler/Generator.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 3147 "src/compiler/Generator.pv"
                    fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 3148 "src/compiler/Generator.pv"
                    return false;
                }

                #line 3151 "src/compiler/Generator.pv"
                fprintf(file, " {\n");
                #line 3152 "src/compiler/Generator.pv"
                self->indent += 1;

                #line 3154 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 3155 "src/compiler/Generator.pv"
                Generator__write_type(self, file, generics->self_type, generics);

                #line 3157 "src/compiler/Generator.pv"
                fprintf(file, "* self = ");

                #line 3159 "src/compiler/Generator.pv"
                if (module != 0 && module->mode_cpp) {
                    #line 3160 "src/compiler/Generator.pv"
                    fprintf(file, "(");
                    #line 3161 "src/compiler/Generator.pv"
                    Generator__write_type(self, file, generics->self_type, generics);
                    #line 3162 "src/compiler/Generator.pv"
                    fprintf(file, "*)");
                }

                #line 3165 "src/compiler/Generator.pv"
                fprintf(file, "__self; (void)self;\n");

                #line 3167 "src/compiler/Generator.pv"
                struct FunctionContext func_context = FunctionContext__new(self->allocator, func_info, true);
                #line 3168 "src/compiler/Generator.pv"
                self->function_context = &func_context;

                #line 3170 "src/compiler/Generator.pv"
                if (!Generator__write_block(self, file, &func_info->return_type, func_info->body, generics, false, true)) {
                    #line 3171 "src/compiler/Generator.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 3172 "src/compiler/Generator.pv"
                    fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 3173 "src/compiler/Generator.pv"
                    return false;
                }

                #line 3176 "src/compiler/Generator.pv"
                self->indent -= 1;
                #line 3177 "src/compiler/Generator.pv"
                Generator__write_indent(self, file);
                #line 3178 "src/compiler/Generator.pv"
                fprintf(file, "}\n");

                #line 3180 "src/compiler/Generator.pv"
                self->function_context = 0;
            } }
        }
    } }

    #line 3185 "src/compiler/Generator.pv"
    return true;
}

#line 3188 "src/compiler/Generator.pv"
bool Generator__generate_struct_loop(struct Generator* self, struct TypeUsage_Struct* usage) {
    #line 3189 "src/compiler/Generator.pv"
    bool success = true;

    #line 3191 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 3191 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 3191 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 3192 "src/compiler/Generator.pv"
        success = Generator__generate_struct(self, usage, usage_context) && success;
    } }

    #line 3195 "src/compiler/Generator.pv"
    return success;
}

#line 3198 "src/compiler/Generator.pv"
struct String Generator__make_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 3199 "src/compiler/Generator.pv"
    struct String result = Generator__make_rel_path(self, module, name, ext);
    #line 3200 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 3201 "src/compiler/Generator.pv"
    String__prepend(&result, (struct str){ .ptr = self->path, .length = strlen(self->path) });
    #line 3202 "src/compiler/Generator.pv"
    return result;
}

#line 3205 "src/compiler/Generator.pv"
struct String Generator__make_rel_path(struct Generator* self, struct Module* module, struct str name, struct str ext) {
    #line 3206 "src/compiler/Generator.pv"
    struct String result = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 3207 "src/compiler/Generator.pv"
    struct Namespace* namespace = 0;
    #line 3208 "src/compiler/Generator.pv"
    if (module != 0) {
        #line 3208 "src/compiler/Generator.pv"
        namespace = module->namespace;
    }

    #line 3210 "src/compiler/Generator.pv"
    while (namespace != 0) {
        #line 3211 "src/compiler/Generator.pv"
        String__prepend(&result, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 3212 "src/compiler/Generator.pv"
        String__prepend(&result, namespace->name);
        #line 3213 "src/compiler/Generator.pv"
        namespace = namespace->parent;
    }

    #line 3216 "src/compiler/Generator.pv"
    String__append(&result, name);
    #line 3217 "src/compiler/Generator.pv"
    String__append(&result, ext);

    #line 3219 "src/compiler/Generator.pv"
    return result;
}

#line 3222 "src/compiler/Generator.pv"
bool Generator__generate_struct(struct Generator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 3223 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 3224 "src/compiler/Generator.pv"
    struct Struct* struct_info = usage->type;
    #line 3225 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 3226 "src/compiler/Generator.pv"
    struct Module* module = struct_info->module;
    #line 3227 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3228 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3229 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3230 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3230 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3230 "src/compiler/Generator.pv"
        return false;
    }

    #line 3232 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3233 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3234 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3235 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3236 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3238 "src/compiler/Generator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 3239 "src/compiler/Generator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 3241 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 3241 "src/compiler/Generator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 3241 "src/compiler/Generator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 3241 "src/compiler/Generator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 3242 "src/compiler/Generator.pv"
            switch (type.type) {
                #line 3243 "src/compiler/Generator.pv"
                case TYPE__CLASS_CPP: {
                    #line 3243 "src/compiler/Generator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 3244 "src/compiler/Generator.pv"
                    if (class_info->is_struct) {
                        #line 3245 "src/compiler/Generator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 3247 "src/compiler/Generator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 3250 "src/compiler/Generator.pv"
                default: {
                } break;
            }
        } }

        #line 3254 "src/compiler/Generator.pv"
        if (struct_info->module->mode_cpp) {
            #line 3255 "src/compiler/Generator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 3255 "src/compiler/Generator.pv"
                fprintf(header_file, "\n");
            }
            #line 3256 "src/compiler/Generator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 3259 "src/compiler/Generator.pv"
        fprintf(header_file, "#else\n");

        #line 3261 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 3261 "src/compiler/Generator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 3261 "src/compiler/Generator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 3262 "src/compiler/Generator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 3265 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (self->root->mode_cpp) {
        #line 3267 "src/compiler/Generator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 3268 "src/compiler/Generator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 3269 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 3272 "src/compiler/Generator.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
    #line 3272 "src/compiler/Generator.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 3272 "src/compiler/Generator.pv"
        struct Type* type = Iter_ref_Type__value(&__iter);

        #line 3273 "src/compiler/Generator.pv"
        Generator__write_c_type_include(self, header_file, Type__deref(type));
    } }

    #line 3276 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_header, 0);
    #line 3277 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, header_file, &struct_info->module->includes);
    #line 3278 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->layout, generics, false);
    #line 3279 "src/compiler/Generator.pv"
    if (usage_context->layout.length > 0) {
        #line 3279 "src/compiler/Generator.pv"
        fprintf(header_file, "\n");
    }

    #line 3281 "src/compiler/Generator.pv"
    if (!Generator__write_struct_definition(self, header_file, struct_info, usage, usage_context)) {
        #line 3281 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3281 "src/compiler/Generator.pv"
        return false;
    }

    #line 3283 "src/compiler/Generator.pv"
    if (struct_info->module->mode_cpp || self->root->mode_cpp) {
        #line 3284 "src/compiler/Generator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 3285 "src/compiler/Generator.pv"
        fprintf(header_file, "}\n");
        #line 3286 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 3289 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3291 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3292 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3293 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3295 "src/compiler/Generator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage) {
        #line 3296 "src/compiler/Generator.pv"
        return true;
    }

    #line 3299 "src/compiler/Generator.pv"
    struct str ext;
    #line 3300 "src/compiler/Generator.pv"
    if (struct_info->module->mode_cpp) {
        #line 3301 "src/compiler/Generator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 3303 "src/compiler/Generator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 3306 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, struct_info->module, String__as_str(&name), ext);
    #line 3307 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 3309 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 3310 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 3311 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 3311 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 3311 "src/compiler/Generator.pv"
        return false;
    }

    #line 3313 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 3314 "src/compiler/Generator.pv"
    Generator__write_includes_raw(self, code_file, &struct_info->module->includes);
    #line 3315 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, code_file, &usage_context->body, generics, true);

    #line 3317 "src/compiler/Generator.pv"
    struct String header_rel = Generator__make_rel_path(self, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3318 "src/compiler/Generator.pv"
    fprintf(code_file, "#include <");
    #line 3319 "src/compiler/Generator.pv"
    Generator__write_str(self, code_file, String__as_str(&header_rel));
    #line 3320 "src/compiler/Generator.pv"
    fprintf(code_file, ">\n\n");

    #line 3322 "src/compiler/Generator.pv"
    if (!Generator__write_impls(self, code_file, struct_info->module, &struct_info->impls, &usage->impl_functions, generics)) {
        #line 3322 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3322 "src/compiler/Generator.pv"
        return false;
    }

    #line 3324 "src/compiler/Generator.pv"
    if (struct_info->traits.length > 0) {
        #line 3325 "src/compiler/Generator.pv"
        fprintf(code_file, "\n");
    }

    #line 3328 "src/compiler/Generator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 3328 "src/compiler/Generator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 3328 "src/compiler/Generator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 3329 "src/compiler/Generator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 3330 "src/compiler/Generator.pv"
        fprintf(code_file, "struct ");
        #line 3331 "src/compiler/Generator.pv"
        Generator__write_type_name(self, code_file, trait_entry._1, generics);
        #line 3332 "src/compiler/Generator.pv"
        fprintf(code_file, "VTable ");
        #line 3333 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, String__as_str(&name));
        #line 3334 "src/compiler/Generator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 3335 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, trait_info->name->value);
        #line 3336 "src/compiler/Generator.pv"
        fprintf(code_file, " = { ");

        #line 3338 "src/compiler/Generator.pv"
        bool first = true;
        #line 3339 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 3339 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 3339 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 3340 "src/compiler/Generator.pv"
            if (first) {
                #line 3340 "src/compiler/Generator.pv"
                first = false;
            } else {
                #line 3341 "src/compiler/Generator.pv"
                fprintf(code_file, ", ");
            }

            #line 3343 "src/compiler/Generator.pv"
            fprintf(code_file, ".");
            #line 3344 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, func_info->name);
            #line 3345 "src/compiler/Generator.pv"
            fprintf(code_file, " = &");
            #line 3346 "src/compiler/Generator.pv"
            struct String func_name = Generator__get_trait_function_name(self, String__as_str(&name), trait_info, func_info, generics);
            #line 3347 "src/compiler/Generator.pv"
            Generator__write_string(self, code_file, &func_name);
        } }

        #line 3350 "src/compiler/Generator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 3353 "src/compiler/Generator.pv"
    if (usage->impl_dynamic_usage) {
        #line 3354 "src/compiler/Generator.pv"
        fprintf(code_file, "\n");

        #line 3356 "src/compiler/Generator.pv"
        fprintf(code_file, "#include <tuple_usize_str_TypeId.h>\n");
        #line 3357 "src/compiler/Generator.pv"
        fprintf(code_file, "#include <slice_tuple_usize_str_TypeId.h>\n");
        #line 3358 "src/compiler/Generator.pv"
        fprintf(code_file, "struct slice_tuple_usize_str_TypeId ");
        #line 3359 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3360 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 3362 "src/compiler/Generator.pv"
        self->indent += 1;
        #line 3363 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3364 "src/compiler/Generator.pv"
        fprintf(code_file, "static struct tuple_usize_str_TypeId fields[] = { ");

        #line 3366 "src/compiler/Generator.pv"
        uintptr_t field_index = 0;
        #line 3367 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 3367 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 3367 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 3368 "src/compiler/Generator.pv"
            if (field_index > 0) {
                #line 3368 "src/compiler/Generator.pv"
                fprintf(code_file, ", ");
            }
            #line 3369 "src/compiler/Generator.pv"
            fprintf(code_file, "(struct tuple_usize_str_TypeId){ ._0 = %zu, ._1 = (struct str){ .ptr = \"", field_index);
            #line 3370 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, field->name);
            #line 3371 "src/compiler/Generator.pv"
            fprintf(code_file, "\", .length = %zu }, ._2 = ", field->name->value.length);
            #line 3372 "src/compiler/Generator.pv"
            Generator__write_typeid(self, code_file, &field->type, generics);
            #line 3373 "src/compiler/Generator.pv"
            fprintf(code_file, " }");
            #line 3374 "src/compiler/Generator.pv"
            field_index += 1;
        } }

        #line 3377 "src/compiler/Generator.pv"
        fprintf(code_file, " };\n");
        #line 3378 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3379 "src/compiler/Generator.pv"
        fprintf(code_file, "return (struct slice_tuple_usize_str_TypeId){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 3380 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3381 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3383 "src/compiler/Generator.pv"
        fprintf(code_file, "void* ");
        #line 3384 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);

        #line 3386 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 3388 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3390 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3391 "src/compiler/Generator.pv"
        Generator__write_type(self, code_file, &(struct Type) { .type = TYPE__SELF }, generics);

        #line 3393 "src/compiler/Generator.pv"
        if (module->mode_cpp) {
            #line 3394 "src/compiler/Generator.pv"
            fprintf(code_file, "* self = (");
            #line 3395 "src/compiler/Generator.pv"
            Generator__write_type(self, code_file, &(struct Type) { .type = TYPE__SELF }, generics);
            #line 3396 "src/compiler/Generator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 3398 "src/compiler/Generator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 3401 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3402 "src/compiler/Generator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 3403 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3405 "src/compiler/Generator.pv"
        uintptr_t i = 0;
        #line 3406 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 3406 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 3406 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 3407 "src/compiler/Generator.pv"
            Generator__write_indent(self, code_file);
            #line 3408 "src/compiler/Generator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 3410 "src/compiler/Generator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 3411 "src/compiler/Generator.pv"
                fprintf(code_file, "self");
            } else {
                #line 3413 "src/compiler/Generator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 3414 "src/compiler/Generator.pv"
                    fprintf(code_file, "&");
                }

                #line 3417 "src/compiler/Generator.pv"
                fprintf(code_file, "self->");
                #line 3418 "src/compiler/Generator.pv"
                Generator__write_token(self, code_file, field->name);
            }

            #line 3421 "src/compiler/Generator.pv"
            fprintf(code_file, ";\n");

            #line 3423 "src/compiler/Generator.pv"
            i += 1;
        } }

        #line 3426 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3427 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3428 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3430 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3431 "src/compiler/Generator.pv"
        fprintf(code_file, "return 0;\n");

        #line 3433 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3434 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3436 "src/compiler/Generator.pv"
        fprintf(code_file, "bool ");
        #line 3437 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);

        #line 3439 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 3441 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3443 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3444 "src/compiler/Generator.pv"
        Generator__write_type(self, code_file, &(struct Type) { .type = TYPE__SELF }, generics);

        #line 3446 "src/compiler/Generator.pv"
        if (module->mode_cpp) {
            #line 3447 "src/compiler/Generator.pv"
            fprintf(code_file, "* self = (");
            #line 3448 "src/compiler/Generator.pv"
            Generator__write_type(self, code_file, &(struct Type) { .type = TYPE__SELF }, generics);
            #line 3449 "src/compiler/Generator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 3451 "src/compiler/Generator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 3454 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3455 "src/compiler/Generator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 3456 "src/compiler/Generator.pv"
        self->indent += 1;

        #line 3458 "src/compiler/Generator.pv"
        i = 0;
        #line 3459 "src/compiler/Generator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 3459 "src/compiler/Generator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 3459 "src/compiler/Generator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 3460 "src/compiler/Generator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 3460 "src/compiler/Generator.pv"
                continue;
            }

            #line 3462 "src/compiler/Generator.pv"
            Generator__write_indent(self, code_file);

            #line 3464 "src/compiler/Generator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 3465 "src/compiler/Generator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 3466 "src/compiler/Generator.pv"
                Generator__write_type(self, code_file, &field->type, generics);
                #line 3467 "src/compiler/Generator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 3469 "src/compiler/Generator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 3470 "src/compiler/Generator.pv"
                Generator__write_token(self, code_file, field->name);
                #line 3471 "src/compiler/Generator.pv"
                fprintf(code_file, " = ");

                #line 3473 "src/compiler/Generator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 3474 "src/compiler/Generator.pv"
                    fprintf(code_file, "*(");
                    #line 3475 "src/compiler/Generator.pv"
                    Generator__write_type(self, code_file, &field->type, generics);
                    #line 3476 "src/compiler/Generator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 3478 "src/compiler/Generator.pv"
                    fprintf(code_file, "(");
                    #line 3479 "src/compiler/Generator.pv"
                    Generator__write_type(self, code_file, &field->type, generics);
                    #line 3480 "src/compiler/Generator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 3484 "src/compiler/Generator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 3485 "src/compiler/Generator.pv"
            i += 1;
        } }

        #line 3488 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3489 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3490 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3492 "src/compiler/Generator.pv"
        Generator__write_indent(self, code_file);
        #line 3493 "src/compiler/Generator.pv"
        fprintf(code_file, "return false;\n");

        #line 3495 "src/compiler/Generator.pv"
        self->indent -= 1;
        #line 3496 "src/compiler/Generator.pv"
        fprintf(code_file, "}\n");

        #line 3498 "src/compiler/Generator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 3499 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, String__as_str(&name));
        #line 3500 "src/compiler/Generator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 3501 "src/compiler/Generator.pv"
        fprintf(code_file, " = { .get_fields = &");
        #line 3502 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);

        #line 3504 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_fields, .get_field = &");
        #line 3505 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3506 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__get_field, .set_field = &");
        #line 3507 "src/compiler/Generator.pv"
        Generator__write_string(self, code_file, &name);
        #line 3508 "src/compiler/Generator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 3511 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 3512 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 3513 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 3515 "src/compiler/Generator.pv"
    return true;
}

#line 3518 "src/compiler/Generator.pv"
bool Generator__generate_primitive_loop(struct Generator* self, struct TypeUsage_Primitive* usage) {
    #line 3519 "src/compiler/Generator.pv"
    bool success = true;

    #line 3521 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 3521 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 3521 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 3522 "src/compiler/Generator.pv"
        success = Generator__generate_primitive(self, usage, usage_context) && success;
    } }

    #line 3525 "src/compiler/Generator.pv"
    return success;
}

#line 3528 "src/compiler/Generator.pv"
bool Generator__generate_primitive(struct Generator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 3529 "src/compiler/Generator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 3530 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 3531 "src/compiler/Generator.pv"
    struct str name = primitive_info->name;

    #line 3533 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3534 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3535 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3536 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3536 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3536 "src/compiler/Generator.pv"
        return false;
    }

    #line 3538 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3539 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name);
    #line 3540 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3541 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, name);
    #line 3542 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3544 "src/compiler/Generator.pv"
    Generator__write_impl_includes_raw(self, header_file, &primitive_info->impls);
    #line 3545 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_header, 0);
    #line 3546 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->signature, generics, false);

    #line 3548 "src/compiler/Generator.pv"
    if (!Generator__write_primitive_definition(self, header_file, primitive_info, generics)) {
        #line 3548 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3548 "src/compiler/Generator.pv"
        return false;
    }

    #line 3550 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3552 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3553 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3554 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3556 "src/compiler/Generator.pv"
    if (primitive_info->impls.length == 0) {
        #line 3557 "src/compiler/Generator.pv"
        return true;
    }

    #line 3560 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 3561 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 3563 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 3564 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 3565 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 3565 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 3565 "src/compiler/Generator.pv"
        return false;
    }

    #line 3567 "src/compiler/Generator.pv"
    Generator__write_impl_includes_raw(self, code_file, &primitive_info->impls);
    #line 3568 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 3569 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, code_file, &usage_context->body, generics, true);

    #line 3571 "src/compiler/Generator.pv"
    struct String header_rel = Generator__make_rel_path(self, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3572 "src/compiler/Generator.pv"
    fprintf(code_file, "#include <");
    #line 3573 "src/compiler/Generator.pv"
    Generator__write_str(self, code_file, String__as_str(&header_rel));
    #line 3574 "src/compiler/Generator.pv"
    fprintf(code_file, ">\n\n");

    #line 3576 "src/compiler/Generator.pv"
    if (!Generator__write_impls(self, code_file, 0, &primitive_info->impls, &usage->impl_functions, generics)) {
        #line 3576 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3576 "src/compiler/Generator.pv"
        return false;
    }

    #line 3578 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 3578 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 3578 "src/compiler/Generator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 3579 "src/compiler/Generator.pv"
        fprintf(code_file, "\nstruct trait_");
        #line 3580 "src/compiler/Generator.pv"
        Generator__write_token(self, code_file, trait_info->name);
        #line 3581 "src/compiler/Generator.pv"
        fprintf(code_file, "VTable ");
        #line 3582 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, name);
        #line 3583 "src/compiler/Generator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 3584 "src/compiler/Generator.pv"
        Generator__write_str_title(self, code_file, trait_info->name->value);
        #line 3585 "src/compiler/Generator.pv"
        fprintf(code_file, " = { ");

        #line 3587 "src/compiler/Generator.pv"
        bool first = true;
        #line 3588 "src/compiler/Generator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 3588 "src/compiler/Generator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 3588 "src/compiler/Generator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 3589 "src/compiler/Generator.pv"
            if (first) {
                #line 3589 "src/compiler/Generator.pv"
                first = false;
            } else {
                #line 3590 "src/compiler/Generator.pv"
                fprintf(code_file, ", ");
            }

            #line 3592 "src/compiler/Generator.pv"
            fprintf(code_file, ".");
            #line 3593 "src/compiler/Generator.pv"
            Generator__write_token(self, code_file, func_info->name);
            #line 3594 "src/compiler/Generator.pv"
            fprintf(code_file, " = &");
            #line 3595 "src/compiler/Generator.pv"
            struct String func_name = Generator__get_trait_function_name(self, name, trait_info, func_info, generics);
            #line 3596 "src/compiler/Generator.pv"
            Generator__write_string(self, code_file, &func_name);
        } }

        #line 3599 "src/compiler/Generator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 3602 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 3603 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 3604 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 3606 "src/compiler/Generator.pv"
    return true;
}

#line 3609 "src/compiler/Generator.pv"
bool Generator__generate_sequence(struct Generator* self, struct TypeUsage_Sequence* usage) {
    #line 3610 "src/compiler/Generator.pv"
    bool success = true;

    #line 3612 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 3612 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 3612 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 3613 "src/compiler/Generator.pv"
        switch (usage->type->type.type) {
            #line 3614 "src/compiler/Generator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 3615 "src/compiler/Generator.pv"
                success = Generator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 3617 "src/compiler/Generator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }

    #line 3621 "src/compiler/Generator.pv"
    return success;
}

#line 3624 "src/compiler/Generator.pv"
bool Generator__generate_slice(struct Generator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 3625 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 3626 "src/compiler/Generator.pv"
    struct Type* element_type = &usage->type->element;

    #line 3628 "src/compiler/Generator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 3629 "src/compiler/Generator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 3631 "src/compiler/Generator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 3632 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &sequence_type, &sequence_type, generics);

    #line 3634 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3635 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3636 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3637 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3637 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3637 "src/compiler/Generator.pv"
        return false;
    }

    #line 3639 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3640 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3641 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3642 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3643 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3645 "src/compiler/Generator.pv"
    Generator__write_c_type_include(self, header_file, element_type);
    #line 3646 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_header, 0);
    #line 3647 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->layout, generics, false);

    #line 3649 "src/compiler/Generator.pv"
    fprintf(header_file, "struct ");
    #line 3650 "src/compiler/Generator.pv"
    Generator__write_string(self, header_file, &name);
    #line 3651 "src/compiler/Generator.pv"
    fprintf(header_file, " { ");

    #line 3653 "src/compiler/Generator.pv"
    Generator__write_variable_decl(self, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 3654 "src/compiler/Generator.pv"
    fprintf(header_file, "; ");
    #line 3655 "src/compiler/Generator.pv"
    Generator__write_variable_decl(self, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &self->root->type_usize, generics);

    #line 3657 "src/compiler/Generator.pv"
    fprintf(header_file, "; };\n");

    #line 3659 "src/compiler/Generator.pv"
    Generator__write_impl_definition(self, header_file, String__as_str(&name), self->root->hack_type_impl->impl_info, generics);

    #line 3661 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3663 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3664 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3665 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3667 "src/compiler/Generator.pv"
    struct String code = Generator__make_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 3668 "src/compiler/Generator.pv"
    Array_String__append(&self->code_files, code);

    #line 3670 "src/compiler/Generator.pv"
    char const* code_tmp = tmpnam(0);
    #line 3671 "src/compiler/Generator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 3672 "src/compiler/Generator.pv"
    if (code_file == 0) {
        #line 3672 "src/compiler/Generator.pv"
        perror(String__c_str(&code));
        #line 3672 "src/compiler/Generator.pv"
        return false;
    }

    #line 3674 "src/compiler/Generator.pv"
    struct String header_rel = Generator__make_rel_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3675 "src/compiler/Generator.pv"
    fprintf(code_file, "#include <");
    #line 3676 "src/compiler/Generator.pv"
    Generator__write_str(self, code_file, String__as_str(&header_rel));
    #line 3677 "src/compiler/Generator.pv"
    fprintf(code_file, ">\n\n");

    #line 3679 "src/compiler/Generator.pv"
    struct Impl* impls_base[1] = {self->root->hack_type_impl->impl_info};
    #line 3680 "src/compiler/Generator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1 };
    #line 3681 "src/compiler/Generator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0 };

    #line 3683 "src/compiler/Generator.pv"
    if (!Generator__write_impls(self, code_file, 0, &impls, &impl_functions, generics)) {
        #line 3683 "src/compiler/Generator.pv"
        fclose(code_file);
        #line 3683 "src/compiler/Generator.pv"
        return false;
    }

    #line 3685 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&code), code_file);
    #line 3686 "src/compiler/Generator.pv"
    fclose(code_file);
    #line 3687 "src/compiler/Generator.pv"
    remove(code_tmp);

    #line 3689 "src/compiler/Generator.pv"
    return true;
}

#line 3692 "src/compiler/Generator.pv"
bool Generator__generate_tuple_loop(struct Generator* self, struct TypeUsage_Tuple* usage) {
    #line 3693 "src/compiler/Generator.pv"
    bool success = true;

    #line 3695 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 3695 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 3695 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 3696 "src/compiler/Generator.pv"
        success = Generator__generate_tuple(self, usage, usage_context) && success;
    } }

    #line 3699 "src/compiler/Generator.pv"
    return success;
}

#line 3702 "src/compiler/Generator.pv"
bool Generator__generate_tuple(struct Generator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 3703 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 3704 "src/compiler/Generator.pv"
    struct Tuple* tuple = usage->type;
    #line 3705 "src/compiler/Generator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 3706 "src/compiler/Generator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 3708 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, &tuple_type, &tuple_type, generics);

    #line 3710 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 3711 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3712 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3713 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3713 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3713 "src/compiler/Generator.pv"
        return false;
    }

    #line 3715 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3716 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3717 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3718 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3719 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3721 "src/compiler/Generator.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(element_types);
    #line 3721 "src/compiler/Generator.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 3721 "src/compiler/Generator.pv"
        struct Type* type = Iter_ref_Type__value(&__iter);

        #line 3722 "src/compiler/Generator.pv"
        Generator__write_c_type_include(self, header_file, type);
    } }

    #line 3725 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_header, 0);
    #line 3726 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->layout, generics, false);

    #line 3728 "src/compiler/Generator.pv"
    fprintf(header_file, "struct ");
    #line 3729 "src/compiler/Generator.pv"
    Generator__write_string(self, header_file, &name);
    #line 3730 "src/compiler/Generator.pv"
    fprintf(header_file, " {\n");
    #line 3731 "src/compiler/Generator.pv"
    self->indent += 1;

    #line 3733 "src/compiler/Generator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 3733 "src/compiler/Generator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 3733 "src/compiler/Generator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 3733 "src/compiler/Generator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 3734 "src/compiler/Generator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 3735 "src/compiler/Generator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 3736 "src/compiler/Generator.pv"
        String__append_usize(&element_name, i);

        #line 3738 "src/compiler/Generator.pv"
        Generator__write_indent(self, header_file);
        #line 3739 "src/compiler/Generator.pv"
        Generator__write_variable_decl(self, header_file, String__as_str(&element_name), element, generics);

        #line 3741 "src/compiler/Generator.pv"
        fprintf(header_file, ";\n");

        #line 3743 "src/compiler/Generator.pv"
        String__release(&element_name);
    } }

    #line 3746 "src/compiler/Generator.pv"
    self->indent -= 1;
    #line 3747 "src/compiler/Generator.pv"
    fprintf(header_file, "};\n");

    #line 3749 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3751 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3752 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3753 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3755 "src/compiler/Generator.pv"
    return true;
}

#line 3758 "src/compiler/Generator.pv"
bool Generator__generate_trait_loop(struct Generator* self, struct TypeUsage_Trait* usage) {
    #line 3759 "src/compiler/Generator.pv"
    bool success = true;

    #line 3761 "src/compiler/Generator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 3761 "src/compiler/Generator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 3761 "src/compiler/Generator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 3762 "src/compiler/Generator.pv"
        success = Generator__generate_trait(self, usage, usage_context) && success;
    } }

    #line 3765 "src/compiler/Generator.pv"
    return success;
}

#line 3768 "src/compiler/Generator.pv"
bool Generator__generate_trait(struct Generator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 3769 "src/compiler/Generator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 3770 "src/compiler/Generator.pv"
    struct Trait* trait_info = usage->type;

    #line 3772 "src/compiler/Generator.pv"
    struct String name = Naming__get_type_name(&self->naming_ident, generics->self_type, generics->self_type, generics);
    #line 3773 "src/compiler/Generator.pv"
    struct String header = Generator__make_path(self, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 3775 "src/compiler/Generator.pv"
    char const* header_tmp = tmpnam(0);
    #line 3776 "src/compiler/Generator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 3777 "src/compiler/Generator.pv"
    if (header_file == 0) {
        #line 3777 "src/compiler/Generator.pv"
        perror(String__c_str(&header));
        #line 3777 "src/compiler/Generator.pv"
        return false;
    }

    #line 3779 "src/compiler/Generator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 3780 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3781 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 3782 "src/compiler/Generator.pv"
    Generator__write_str_title(self, header_file, String__as_str(&name));
    #line 3783 "src/compiler/Generator.pv"
    fprintf(header_file, "\n\n");

    #line 3785 "src/compiler/Generator.pv"
    if (trait_info->module->mode_cpp) {
        #line 3786 "src/compiler/Generator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 3787 "src/compiler/Generator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 3788 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 3791 "src/compiler/Generator.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
    #line 3791 "src/compiler/Generator.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 3791 "src/compiler/Generator.pv"
        struct Type* type = Iter_ref_Type__value(&__iter);

        #line 3792 "src/compiler/Generator.pv"
        Generator__write_c_type_include(self, header_file, Type__deref(type));
    } }

    #line 3795 "src/compiler/Generator.pv"
    Generator__write_context_primitives(self, header_file, &usage_context->primitive_header, 0);

    #line 3797 "src/compiler/Generator.pv"
    if (!trait_info->module->mode_cpp) {
        #line 3798 "src/compiler/Generator.pv"
        Generator__write_includes_raw(self, header_file, &trait_info->module->includes);
    }

    #line 3801 "src/compiler/Generator.pv"
    Generator__write_context_includes(self, header_file, &usage_context->signature, generics, false);

    #line 3803 "src/compiler/Generator.pv"
    if (!Generator__write_trait_definition(self, header_file, trait_info, generics)) {
        #line 3803 "src/compiler/Generator.pv"
        fclose(header_file);
        #line 3803 "src/compiler/Generator.pv"
        return false;
    }

    #line 3805 "src/compiler/Generator.pv"
    if (trait_info->module->mode_cpp) {
        #line 3806 "src/compiler/Generator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 3807 "src/compiler/Generator.pv"
        fprintf(header_file, "}\n");
        #line 3808 "src/compiler/Generator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 3811 "src/compiler/Generator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 3813 "src/compiler/Generator.pv"
    Generator__overwrite_if_different(self, String__c_str(&header), header_file);
    #line 3814 "src/compiler/Generator.pv"
    fclose(header_file);
    #line 3815 "src/compiler/Generator.pv"
    remove(header_tmp);

    #line 3817 "src/compiler/Generator.pv"
    return true;
}

#line 3820 "src/compiler/Generator.pv"
void Generator__create_directories(struct Generator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 3821 "src/compiler/Generator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 3821 "src/compiler/Generator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 3821 "src/compiler/Generator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 3821 "src/compiler/Generator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 3822 "src/compiler/Generator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
        #line 3823 "src/compiler/Generator.pv"
        String__append(&path, base_path);
        #line 3824 "src/compiler/Generator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 3825 "src/compiler/Generator.pv"
        String__append(&path, name);
        #line 3826 "src/compiler/Generator.pv"
        create_directory(String__c_str(&path));

        #line 3828 "src/compiler/Generator.pv"
        Generator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}

#line 3832 "src/compiler/Generator.pv"
bool Generator__generate(struct ArenaAllocator* allocator, char const* path, bool output_line_directives, char const* output_seperator, struct Root* root) {
    #line 3833 "src/compiler/Generator.pv"
    bool result = true;

    #line 3835 "src/compiler/Generator.pv"
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
    };

    #line 3848 "src/compiler/Generator.pv"
    self.naming_c99 = Naming__new_c99(allocator, &self.naming_ident);

    #line 3850 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitives = &self.primitives;
    #line 3851 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 3852 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 3853 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 3854 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 3855 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 3856 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 3857 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 3858 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 3859 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 3860 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 3861 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 3862 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 3863 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 3864 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 3865 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 3867 "src/compiler/Generator.pv"
    struct HashMap_str_str* primitive_includes = &self.primitive_includes;
    #line 3868 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3869 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3870 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3871 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3872 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3873 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3874 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3875 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3876 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3877 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "stdint", .length = strlen("stdint") });
    #line 3878 "src/compiler/Generator.pv"
    HashMap_str_str__insert(primitive_includes, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "stdbool", .length = strlen("stdbool") });

    #line 3880 "src/compiler/Generator.pv"
    Generator__create_directories(&self, (struct str){ .ptr = path, .length = strlen(path) }, &root->children);

    #line 3882 "src/compiler/Generator.pv"
    struct Usages usages = Usages__new(&self);
    #line 3883 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Primitive __iter = HashMap_usize_TypeUsage_Primitive__iter(&usages.primitives);
    #line 3883 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Primitive__next(&__iter)) {
        #line 3883 "src/compiler/Generator.pv"
        struct TypeUsage_Primitive* usage = &HashMapIter_usize_TypeUsage_Primitive__value(&__iter)->_1;

        #line 3883 "src/compiler/Generator.pv"
        Generator__generate_primitive_loop(&self, usage);
    } }
    #line 3884 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Struct __iter = HashMap_usize_TypeUsage_Struct__iter(&usages.structs);
    #line 3884 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Struct__next(&__iter)) {
        #line 3884 "src/compiler/Generator.pv"
        struct TypeUsage_Struct* usage = &HashMapIter_usize_TypeUsage_Struct__value(&__iter)->_1;

        #line 3884 "src/compiler/Generator.pv"
        Generator__generate_struct_loop(&self, usage);
    } }
    #line 3885 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Enum __iter = HashMap_usize_TypeUsage_Enum__iter(&usages.enums);
    #line 3885 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Enum__next(&__iter)) {
        #line 3885 "src/compiler/Generator.pv"
        struct TypeUsage_Enum* usage = &HashMapIter_usize_TypeUsage_Enum__value(&__iter)->_1;

        #line 3885 "src/compiler/Generator.pv"
        Generator__generate_enum_loop(&self, usage);
    } }
    #line 3886 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Trait __iter = HashMap_usize_TypeUsage_Trait__iter(&usages.traits);
    #line 3886 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Trait__next(&__iter)) {
        #line 3886 "src/compiler/Generator.pv"
        struct TypeUsage_Trait* usage = &HashMapIter_usize_TypeUsage_Trait__value(&__iter)->_1;

        #line 3886 "src/compiler/Generator.pv"
        Generator__generate_trait_loop(&self, usage);
    } }
    #line 3887 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeFunctionUsage __iter = HashMap_usize_TypeFunctionUsage__iter(&usages.functions);
    #line 3887 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeFunctionUsage__next(&__iter)) {
        #line 3887 "src/compiler/Generator.pv"
        struct TypeFunctionUsage* usage = &HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_1;

        #line 3887 "src/compiler/Generator.pv"
        Generator__generate_function_loop(&self, usage);
    } }
    #line 3888 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Sequence __iter = HashMap_usize_TypeUsage_Sequence__iter(&usages.sequences);
    #line 3888 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Sequence__next(&__iter)) {
        #line 3888 "src/compiler/Generator.pv"
        struct TypeUsage_Sequence* usage = &HashMapIter_usize_TypeUsage_Sequence__value(&__iter)->_1;

        #line 3888 "src/compiler/Generator.pv"
        Generator__generate_sequence(&self, usage);
    } }
    #line 3889 "src/compiler/Generator.pv"
    { struct HashMapIter_usize_TypeUsage_Tuple __iter = HashMap_usize_TypeUsage_Tuple__iter(&usages.tuples);
    #line 3889 "src/compiler/Generator.pv"
    while (HashMapIter_usize_TypeUsage_Tuple__next(&__iter)) {
        #line 3889 "src/compiler/Generator.pv"
        struct TypeUsage_Tuple* usage = &HashMapIter_usize_TypeUsage_Tuple__value(&__iter)->_1;

        #line 3889 "src/compiler/Generator.pv"
        Generator__generate_tuple_loop(&self, usage);
    } }

    #line 3891 "src/compiler/Generator.pv"
    if (self.code_files.length > 0) {
        #line 3892 "src/compiler/Generator.pv"
        struct String command = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self.allocator });

        #line 3894 "src/compiler/Generator.pv"
        { struct Iter_ref_String __iter = Array_String__iter(&self.code_files);
        #line 3894 "src/compiler/Generator.pv"
        while (Iter_ref_String__next(&__iter)) {
            #line 3894 "src/compiler/Generator.pv"
            struct String* code_file = Iter_ref_String__value(&__iter);

            #line 3895 "src/compiler/Generator.pv"
            if (command.array.length > 0) {
                #line 3896 "src/compiler/Generator.pv"
                String__append(&command, (struct str){ .ptr = output_seperator, .length = strlen(output_seperator) });
            }

            #line 3899 "src/compiler/Generator.pv"
            String__append(&command, String__as_str(code_file));
        } }

        #line 3902 "src/compiler/Generator.pv"
        uint32_t length = command.array.length;
        #line 3903 "src/compiler/Generator.pv"
        printf("%.*s\n", length, command.array.data);
    }

    #line 3906 "src/compiler/Generator.pv"
    return result;
}
