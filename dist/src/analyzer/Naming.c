#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <analyzer/Naming.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/String.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/EnumType.h>
#include <analyzer/types/Enum.h>
#include <analyzer/Token.h>
#include <analyzer/types/Struct.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/GenericTypedef.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_usize.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Function.h>
#include <std/HashMapIter_str_usize.h>
#include <tuple_str_usize.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/types/Global.h>
#include <std/Iter_ref_Type.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/IterEnumerate_ref_Parameter.h>
#include <tuple_usize_ref_Parameter.h>
#include <analyzer/Naming.h>

#include <analyzer/Naming.h>

#line 43 "src/analyzer/Naming.pv"
struct Naming Naming__new_decl(struct ArenaAllocator* allocator) {
    #line 44 "src/analyzer/Naming.pv"
    return (struct Naming) {
        .allocator = allocator,
        .type = NAMING_TYPE__DECL,
        .generic_start = (struct str){ .ptr = "<", .length = strlen("<") },
        .generic_seperator = (struct str){ .ptr = ", ", .length = strlen(", ") },
        .generic_end = (struct str){ .ptr = ">", .length = strlen(">") },
        .pointer_prefix = (struct str){ .ptr = "*", .length = strlen("*") },
        .pointer_const_prefix = (struct str){ .ptr = "*const ", .length = strlen("*const ") },
        .reference_prefix = (struct str){ .ptr = "&", .length = strlen("&") },
        .sequence_open = (struct str){ .ptr = "[", .length = strlen("[") },
        .sequence_fixed_delimiter = (struct str){ .ptr = "; ", .length = strlen("; ") },
        .sequence_close = (struct str){ .ptr = "]", .length = strlen("]") },
        .tuple_open = (struct str){ .ptr = "(", .length = strlen("(") },
        .tuple_close = (struct str){ .ptr = ")", .length = strlen(")") },
    };
}

#line 61 "src/analyzer/Naming.pv"
struct Naming Naming__new_ident(struct ArenaAllocator* allocator) {
    #line 62 "src/analyzer/Naming.pv"
    return (struct Naming) {
        .allocator = allocator,
        .type = NAMING_TYPE__IDENT,
        .generic_start = (struct str){ .ptr = "_", .length = strlen("_") },
        .generic_seperator = (struct str){ .ptr = "_", .length = strlen("_") },
        .pointer_prefix = (struct str){ .ptr = "ptr_", .length = strlen("ptr_") },
        .pointer_const_prefix = (struct str){ .ptr = "ptrc_", .length = strlen("ptrc_") },
        .reference_prefix = (struct str){ .ptr = "ref_", .length = strlen("ref_") },
        .sequence_slice_prefix = (struct str){ .ptr = "slice_", .length = strlen("slice_") },
        .enum_generic_type_suffix = (struct str){ .ptr = "__Type", .length = strlen("__Type") },
        .trait_prefix = (struct str){ .ptr = "trait_", .length = strlen("trait_") },
        .tuple_prefix = (struct str){ .ptr = "tuple_", .length = strlen("tuple_") },
    };
}

#line 77 "src/analyzer/Naming.pv"
struct Naming Naming__new_c99(struct ArenaAllocator* allocator, struct Naming* naming_ident) {
    #line 78 "src/analyzer/Naming.pv"
    struct HashMap_str_str primitives = HashMap_str_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 79 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 80 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 81 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 82 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 83 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 84 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 85 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 86 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 87 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 88 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 89 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 90 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 91 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 92 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 93 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 95 "src/analyzer/Naming.pv"
    return (struct Naming) {
        .allocator = allocator,
        .type = NAMING_TYPE__C99,
        .generic_start = (struct str){ .ptr = "_", .length = strlen("_") },
        .generic_seperator = (struct str){ .ptr = "_", .length = strlen("_") },
        .pointer_suffix = (struct str){ .ptr = "*", .length = strlen("*") },
        .pointer_const_suffix = (struct str){ .ptr = " const*", .length = strlen(" const*") },
        .reference_suffix = (struct str){ .ptr = "*", .length = strlen("*") },
        .sequence_slice_prefix = (struct str){ .ptr = "struct slice_", .length = strlen("struct slice_") },
        .sequence_open = (struct str){ .ptr = "[", .length = strlen("[") },
        .sequence_close = (struct str){ .ptr = "]", .length = strlen("]") },
        .tuple_prefix = (struct str){ .ptr = "struct tuple_", .length = strlen("struct tuple_") },
        .enum_prefix = (struct str){ .ptr = "enum ", .length = strlen("enum ") },
        .struct_prefix = (struct str){ .ptr = "struct ", .length = strlen("struct ") },
        .trait_prefix = (struct str){ .ptr = "struct trait_", .length = strlen("struct trait_") },
        .union_prefix = (struct str){ .ptr = "union ", .length = strlen("union ") },
        .coroutine_instance_prefix = (struct str){ .ptr = "struct ", .length = strlen("struct ") },
        .primitives = primitives,
        .naming_ident = naming_ident,
    };
}

#line 117 "src/analyzer/Naming.pv"
struct String Naming__get_type_name(struct Naming* self, struct Type* type, struct Type* type_self, struct GenericMap* generics_map) {
    #line 118 "src/analyzer/Naming.pv"
    struct String result = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 119 "src/analyzer/Naming.pv"
    struct Array_Type generics = (struct Array_Type) {};
    #line 120 "src/analyzer/Naming.pv"
    struct str generic_start = self->generic_start;
    #line 121 "src/analyzer/Naming.pv"
    struct str generic_end = self->generic_end;

    #line 123 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 124 "src/analyzer/Naming.pv"
        case TYPE__INDIRECT: {
            #line 124 "src/analyzer/Naming.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 125 "src/analyzer/Naming.pv"
            switch (indirect->type) {
                #line 126 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__POINTER: {
                    #line 126 "src/analyzer/Naming.pv"
                    String__append(&result, self->pointer_prefix);
                } break;
                #line 127 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__CONST_POINTER: {
                    #line 127 "src/analyzer/Naming.pv"
                    String__append(&result, self->pointer_const_prefix);
                } break;
                #line 128 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__REFERENCE: {
                    #line 128 "src/analyzer/Naming.pv"
                    String__append(&result, self->reference_prefix);
                } break;
                #line 129 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__DYNAMIC_DISPATCH: {
                    #line 129 "src/analyzer/Naming.pv"
                    String__append(&result, self->reference_prefix);
                } break;
            }

            #line 132 "src/analyzer/Naming.pv"
            struct String child_name = Naming__get_type_name(self, &indirect->to, type_self, generics_map);
            #line 133 "src/analyzer/Naming.pv"
            String__append(&result, String__as_str(&child_name));

            #line 135 "src/analyzer/Naming.pv"
            switch (indirect->to.type) {
                #line 136 "src/analyzer/Naming.pv"
                case TYPE__TRAIT: {
                } break;
                #line 137 "src/analyzer/Naming.pv"
                case TYPE__SEQUENCE: {
                    #line 137 "src/analyzer/Naming.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 138 "src/analyzer/Naming.pv"
                    if (!Sequence__is_slice(sequence)) {
                        #line 138 "src/analyzer/Naming.pv"
                        String__append(&result, self->reference_suffix);
                    }
                } break;
                #line 140 "src/analyzer/Naming.pv"
                default: {
                    #line 141 "src/analyzer/Naming.pv"
                    switch (indirect->type) {
                        #line 142 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__POINTER: {
                            #line 142 "src/analyzer/Naming.pv"
                            String__append(&result, self->pointer_suffix);
                        } break;
                        #line 143 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__CONST_POINTER: {
                            #line 143 "src/analyzer/Naming.pv"
                            String__append(&result, self->pointer_const_suffix);
                        } break;
                        #line 144 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__REFERENCE: {
                            #line 144 "src/analyzer/Naming.pv"
                            String__append(&result, self->reference_suffix);
                        } break;
                        #line 145 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__DYNAMIC_DISPATCH: {
                            #line 145 "src/analyzer/Naming.pv"
                            String__append(&result, self->reference_suffix);
                        } break;
                    }
                } break;
            }
        } break;
        #line 150 "src/analyzer/Naming.pv"
        case TYPE__SEQUENCE: {
            #line 150 "src/analyzer/Naming.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 151 "src/analyzer/Naming.pv"
            struct String element_name = Naming__get_type_name(self, &sequence->element, type_self, generics_map);

            #line 153 "src/analyzer/Naming.pv"
            switch (sequence->type.type) {
                #line 154 "src/analyzer/Naming.pv"
                case SEQUENCE_TYPE__SLICE: {
                    #line 155 "src/analyzer/Naming.pv"
                    if (self->naming_ident != 0) {
                        #line 156 "src/analyzer/Naming.pv"
                        String__release(&element_name);
                        #line 157 "src/analyzer/Naming.pv"
                        element_name = Naming__get_type_name(self->naming_ident, &sequence->element, type_self, generics_map);
                    }

                    #line 160 "src/analyzer/Naming.pv"
                    String__append(&result, self->sequence_slice_prefix);
                } break;
                #line 162 "src/analyzer/Naming.pv"
                default: {
                } break;
            }

            #line 165 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 166 "src/analyzer/Naming.pv"
                String__append(&result, String__as_str(&element_name));
            } else {
                #line 168 "src/analyzer/Naming.pv"
                switch (sequence->type.type) {
                    #line 169 "src/analyzer/Naming.pv"
                    case SEQUENCE_TYPE__FIXED_ARRAY: {
                        #line 169 "src/analyzer/Naming.pv"
                        uintptr_t length = sequence->type.fixedarray_value;
                        #line 170 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_open);
                        #line 171 "src/analyzer/Naming.pv"
                        String__append(&result, String__as_str(&element_name));
                        #line 172 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_fixed_delimiter);
                        #line 173 "src/analyzer/Naming.pv"
                        String__append_usize(&result, length);
                        #line 174 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_close);
                    } break;
                    #line 176 "src/analyzer/Naming.pv"
                    case SEQUENCE_TYPE__SLICE: {
                        #line 177 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_open);
                        #line 178 "src/analyzer/Naming.pv"
                        String__append(&result, String__as_str(&element_name));
                        #line 179 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_close);
                    } break;
                }
            }
        } break;
        #line 184 "src/analyzer/Naming.pv"
        case TYPE__TUPLE: {
            #line 184 "src/analyzer/Naming.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 185 "src/analyzer/Naming.pv"
            String__append(&result, self->tuple_prefix);
            #line 186 "src/analyzer/Naming.pv"
            generic_start = self->tuple_open;
            #line 187 "src/analyzer/Naming.pv"
            generic_end = self->tuple_close;
            #line 188 "src/analyzer/Naming.pv"
            generics = tuple->elements;
        } break;
        #line 190 "src/analyzer/Naming.pv"
        case TYPE__PRIMITIVE: {
            #line 190 "src/analyzer/Naming.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 191 "src/analyzer/Naming.pv"
            if (primitive_info == 0) {
                #line 192 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "void", .length = strlen("void") });
            } else {
                #line 194 "src/analyzer/Naming.pv"
                struct str* translation = HashMap_str_str__find(&self->primitives, &primitive_info->name);

                #line 196 "src/analyzer/Naming.pv"
                if (translation != 0) {
                    #line 197 "src/analyzer/Naming.pv"
                    String__append(&result, *translation);
                } else {
                    #line 199 "src/analyzer/Naming.pv"
                    String__append(&result, primitive_info->name);
                }
            }
        } break;
        #line 203 "src/analyzer/Naming.pv"
        case TYPE__ENUM: {
            #line 203 "src/analyzer/Naming.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 203 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->enum_value._1;
            #line 204 "src/analyzer/Naming.pv"
            switch (enum_info->type) {
                #line 205 "src/analyzer/Naming.pv"
                case ENUM_TYPE__STANDARD: {
                    #line 205 "src/analyzer/Naming.pv"
                    String__append(&result, self->enum_prefix);
                } break;
                #line 206 "src/analyzer/Naming.pv"
                case ENUM_TYPE__DISCRIMINATED_UNION: {
                    #line 206 "src/analyzer/Naming.pv"
                    String__append(&result, self->struct_prefix);
                } break;
            }

            #line 209 "src/analyzer/Naming.pv"
            String__append(&result, enum_info->name->value);
            #line 210 "src/analyzer/Naming.pv"
            generics = generics2->array;
        } break;
        #line 212 "src/analyzer/Naming.pv"
        case TYPE__STRUCT: {
            #line 212 "src/analyzer/Naming.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 212 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->struct_value._1;
            #line 213 "src/analyzer/Naming.pv"
            if (!Struct__is_newtype(struct_info)) {
                #line 214 "src/analyzer/Naming.pv"
                String__append(&result, self->struct_prefix);
            }

            #line 217 "src/analyzer/Naming.pv"
            String__append(&result, struct_info->name->value);

            #line 219 "src/analyzer/Naming.pv"
            if (struct_info->generics.array.length > 0) {
                #line 220 "src/analyzer/Naming.pv"
                generics = generics2->array;
            }
        } break;
        #line 223 "src/analyzer/Naming.pv"
        case TYPE__TRAIT: {
            #line 223 "src/analyzer/Naming.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 223 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->trait_value._1;
            #line 224 "src/analyzer/Naming.pv"
            String__append(&result, self->trait_prefix);
            #line 225 "src/analyzer/Naming.pv"
            String__append(&result, trait_info->name->value);
            #line 226 "src/analyzer/Naming.pv"
            generics = generics2->array;
        } break;
        #line 228 "src/analyzer/Naming.pv"
        case TYPE__GENERIC: {
            #line 228 "src/analyzer/Naming.pv"
            struct Generic* generic = type->generic_value;
            #line 229 "src/analyzer/Naming.pv"
            struct str name = generic->name->value;

            #line 231 "src/analyzer/Naming.pv"
            if (generics_map == 0) {
                #line 232 "src/analyzer/Naming.pv"
                String__append(&result, name);
                #line 233 "src/analyzer/Naming.pv"
                return result;
            }

            #line 236 "src/analyzer/Naming.pv"
            struct Type* generic_type = GenericMap__get(generics_map, name);
            #line 237 "src/analyzer/Naming.pv"
            if (generic_type == 0) {
                #line 238 "src/analyzer/Naming.pv"
                uint32_t len = name.length;
                #line 239 "src/analyzer/Naming.pv"
                fprintf(stderr, "Naming.get_type_name: Attempt to retrieve generic %.*s but it does not exist in generics\n", len, name.ptr);
            }

            #line 242 "src/analyzer/Naming.pv"
            return Naming__get_type_name(self, generic_type, type_self, generics_map);
        } break;
        #line 244 "src/analyzer/Naming.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 244 "src/analyzer/Naming.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 245 "src/analyzer/Naming.pv"
            if (generics_map != 0) {
                #line 246 "src/analyzer/Naming.pv"
                struct Type* direct_type = GenericMap__get(generics_map, gt->typedef_name);
                #line 247 "src/analyzer/Naming.pv"
                if (direct_type != 0) {
                    #line 248 "src/analyzer/Naming.pv"
                    return Naming__get_type_name(self, direct_type, type_self, generics_map);
                }

                #line 251 "src/analyzer/Naming.pv"
                struct Type* concrete_type = GenericMap__get(generics_map, gt->generic->name->value);
                #line 252 "src/analyzer/Naming.pv"
                if (concrete_type != 0) {
                    #line 253 "src/analyzer/Naming.pv"
                    switch (concrete_type->type) {
                        #line 254 "src/analyzer/Naming.pv"
                        case TYPE__STRUCT: {
                            #line 254 "src/analyzer/Naming.pv"
                            struct Struct* struct_info = concrete_type->struct_value._0;
                            #line 255 "src/analyzer/Naming.pv"
                            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                            #line 255 "src/analyzer/Naming.pv"
                            while (Iter_ref_ref_Impl__next(&__iter)) {
                                #line 255 "src/analyzer/Naming.pv"
                                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                                #line 256 "src/analyzer/Naming.pv"
                                if (impl_info->trait_ == 0) {
                                    #line 256 "src/analyzer/Naming.pv"
                                    continue;
                                }
                                #line 257 "src/analyzer/Naming.pv"
                                if (HashMap_str_usize__find(&impl_info->trait_->typedefs, &gt->typedef_name) == 0) {
                                    #line 257 "src/analyzer/Naming.pv"
                                    continue;
                                }
                                #line 258 "src/analyzer/Naming.pv"
                                struct Type* typedef_type = HashMap_str_Type__find(&impl_info->typedefs, &gt->typedef_name);
                                #line 259 "src/analyzer/Naming.pv"
                                if (typedef_type != 0) {
                                    #line 260 "src/analyzer/Naming.pv"
                                    return Naming__get_type_name(self, typedef_type, type_self, generics_map);
                                }
                            } }
                        } break;
                        #line 264 "src/analyzer/Naming.pv"
                        default: {
                        } break;
                    }
                }
            }

            #line 269 "src/analyzer/Naming.pv"
            String__append(&result, gt->typedef_name);
            #line 270 "src/analyzer/Naming.pv"
            return result;
        } break;
        #line 272 "src/analyzer/Naming.pv"
        case TYPE__UNKNOWN_C: {
            #line 272 "src/analyzer/Naming.pv"
            struct UnknownC* info = type->unknownc_value;
            #line 273 "src/analyzer/Naming.pv"
            String__append(&result, info->name);
            #line 274 "src/analyzer/Naming.pv"
            generics = info->generics;
        } break;
        #line 276 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION: {
            #line 276 "src/analyzer/Naming.pv"
            struct Function* func_info = type->function_value._0;
            #line 276 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->function_value._1;
            #line 277 "src/analyzer/Naming.pv"
            bool has_parent = false;
            #line 278 "src/analyzer/Naming.pv"
            struct Type parent_type;
            #line 279 "src/analyzer/Naming.pv"
            struct Trait* trait_info = 0;
            #line 280 "src/analyzer/Naming.pv"
            struct Impl* trait_impl_info = 0;

            #line 282 "src/analyzer/Naming.pv"
            switch (func_info->parent.type) {
                #line 283 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__NONE: {
                } break;
                #line 284 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 284 "src/analyzer/Naming.pv"
                    struct Primitive* primitive = func_info->parent.primitive_value._0;
                    #line 284 "src/analyzer/Naming.pv"
                    uintptr_t impl_index = func_info->parent.primitive_value._1;
                    #line 284 "src/analyzer/Naming.pv"
                    struct Trait* trait_info2 = func_info->parent.primitive_value._2;
                    #line 285 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive };
                    #line 286 "src/analyzer/Naming.pv"
                    trait_info = trait_info2;
                    #line 287 "src/analyzer/Naming.pv"
                    has_parent = true;
                    #line 288 "src/analyzer/Naming.pv"
                    if (primitive->impls.length > impl_index) {
                        #line 289 "src/analyzer/Naming.pv"
                        trait_impl_info = primitive->impls.data[impl_index];
                    }
                } break;
                #line 292 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 292 "src/analyzer/Naming.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 292 "src/analyzer/Naming.pv"
                    uintptr_t impl_index = func_info->parent.enum_value._1;
                    #line 292 "src/analyzer/Naming.pv"
                    struct Trait* trait_info2 = func_info->parent.enum_value._2;
                    #line 293 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generics2} };
                    #line 294 "src/analyzer/Naming.pv"
                    trait_info = trait_info2;
                    #line 295 "src/analyzer/Naming.pv"
                    has_parent = true;
                    #line 296 "src/analyzer/Naming.pv"
                    if (enum_info->impls.length > impl_index) {
                        #line 297 "src/analyzer/Naming.pv"
                        trait_impl_info = enum_info->impls.data[impl_index];
                    }
                } break;
                #line 300 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 300 "src/analyzer/Naming.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 300 "src/analyzer/Naming.pv"
                    uintptr_t impl_index = func_info->parent.struct_value._1;
                    #line 300 "src/analyzer/Naming.pv"
                    struct Trait* trait_info2 = func_info->parent.struct_value._2;
                    #line 301 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics2} };
                    #line 302 "src/analyzer/Naming.pv"
                    trait_info = trait_info2;
                    #line 303 "src/analyzer/Naming.pv"
                    has_parent = true;
                    #line 304 "src/analyzer/Naming.pv"
                    if (struct_info->impls.length > impl_index) {
                        #line 305 "src/analyzer/Naming.pv"
                        trait_impl_info = struct_info->impls.data[impl_index];
                    }
                } break;
                #line 308 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__TRAIT: {
                } break;
                #line 309 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 309 "src/analyzer/Naming.pv"
                    struct Type* type = func_info->parent.type_value._0;
                    #line 310 "src/analyzer/Naming.pv"
                    if (Type__is_fat_pointer(type)) {
                        #line 311 "src/analyzer/Naming.pv"
                        parent_type = *Type__deref_1(type);
                    } else {
                        #line 313 "src/analyzer/Naming.pv"
                        parent_type = *type;
                    }

                    #line 316 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
            }

            #line 320 "src/analyzer/Naming.pv"
            if (has_parent) {
                #line 321 "src/analyzer/Naming.pv"
                if (self->naming_ident != 0) {
                    #line 322 "src/analyzer/Naming.pv"
                    struct String parent_type_name = Naming__get_type_name(self->naming_ident, &parent_type, type_self, generics_map);
                    #line 323 "src/analyzer/Naming.pv"
                    String__append_string(&result, &parent_type_name);
                    #line 324 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
                } else {
                    #line 326 "src/analyzer/Naming.pv"
                    struct String parent_type_name = Naming__get_type_name(self, &parent_type, type_self, generics_map);
                    #line 327 "src/analyzer/Naming.pv"
                    String__append_string(&result, &parent_type_name);
                    #line 328 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
                }
            }

            #line 332 "src/analyzer/Naming.pv"
            if (trait_info != 0) {
                #line 333 "src/analyzer/Naming.pv"
                String__append(&result, trait_info->name->value);
                #line 334 "src/analyzer/Naming.pv"
                if (trait_impl_info != 0) {
                    #line 335 "src/analyzer/Naming.pv"
                    switch (trait_impl_info->trait_type.type) {
                        #line 336 "src/analyzer/Naming.pv"
                        case TYPE__TRAIT: {
                            #line 336 "src/analyzer/Naming.pv"
                            struct Trait* ti = trait_impl_info->trait_type.trait_value._0;
                            #line 336 "src/analyzer/Naming.pv"
                            struct GenericMap* tmap = trait_impl_info->trait_type.trait_value._1;
                            #line 337 "src/analyzer/Naming.pv"
                            { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&ti->generics.map);
                            #line 337 "src/analyzer/Naming.pv"
                            while (HashMapIter_str_usize__next(&__iter)) {
                                #line 337 "src/analyzer/Naming.pv"
                                struct str gname = HashMapIter_str_usize__value(&__iter)->_0;

                                #line 338 "src/analyzer/Naming.pv"
                                if (HashMap_str_usize__find(&ti->typedefs, &gname) == 0) {
                                    #line 339 "src/analyzer/Naming.pv"
                                    struct Type* gtype = GenericMap__get(tmap, gname);
                                    #line 340 "src/analyzer/Naming.pv"
                                    if (gtype != 0) {
                                        #line 341 "src/analyzer/Naming.pv"
                                        String__append(&result, (struct str){ .ptr = "_", .length = strlen("_") });
                                        #line 342 "src/analyzer/Naming.pv"
                                        struct String gtype_name = Naming__get_type_name(self, gtype, type_self, generics_map);
                                        #line 343 "src/analyzer/Naming.pv"
                                        String__append_string(&result, &gtype_name);
                                    }
                                }
                            } }
                        } break;
                        #line 348 "src/analyzer/Naming.pv"
                        default: {
                        } break;
                    }
                }
                #line 351 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
            }

            #line 354 "src/analyzer/Naming.pv"
            String__append(&result, func_info->name->value);
            #line 355 "src/analyzer/Naming.pv"
            if (func_info->generics.map.length > 0) {
                #line 356 "src/analyzer/Naming.pv"
                generics = generics2->array;
            }
        } break;
        #line 359 "src/analyzer/Naming.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 359 "src/analyzer/Naming.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 359 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->coroutineinstance_value._1;
            #line 360 "src/analyzer/Naming.pv"
            String__append(&result, self->coroutine_instance_prefix);

            #line 362 "src/analyzer/Naming.pv"
            bool has_parent = false;
            #line 363 "src/analyzer/Naming.pv"
            struct Type parent_type;

            #line 365 "src/analyzer/Naming.pv"
            switch (func_info->parent.type) {
                #line 366 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 366 "src/analyzer/Naming.pv"
                    struct Primitive* primitive = func_info->parent.primitive_value._0;
                    #line 367 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive };
                    #line 368 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 370 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 370 "src/analyzer/Naming.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 371 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generics2} };
                    #line 372 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 374 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 374 "src/analyzer/Naming.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 375 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics2} };
                    #line 376 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 378 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 378 "src/analyzer/Naming.pv"
                    struct Type* type = func_info->parent.type_value._0;
                    #line 379 "src/analyzer/Naming.pv"
                    if (Type__is_fat_pointer(type)) {
                        #line 380 "src/analyzer/Naming.pv"
                        parent_type = *Type__deref_1(type);
                    } else {
                        #line 382 "src/analyzer/Naming.pv"
                        parent_type = *type;
                    }
                    #line 384 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 386 "src/analyzer/Naming.pv"
                default: {
                } break;
            }

            #line 389 "src/analyzer/Naming.pv"
            if (has_parent) {
                #line 390 "src/analyzer/Naming.pv"
                if (self->naming_ident != 0) {
                    #line 391 "src/analyzer/Naming.pv"
                    struct String parent_type_name = Naming__get_type_name(self->naming_ident, &parent_type, type_self, generics_map);
                    #line 392 "src/analyzer/Naming.pv"
                    String__append_string(&result, &parent_type_name);
                    #line 393 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
                } else {
                    #line 395 "src/analyzer/Naming.pv"
                    struct String parent_type_name = Naming__get_type_name(self, &parent_type, type_self, generics_map);
                    #line 396 "src/analyzer/Naming.pv"
                    String__append_string(&result, &parent_type_name);
                    #line 397 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
                }
            }

            #line 401 "src/analyzer/Naming.pv"
            String__append(&result, func_info->name->value);
        } break;
        #line 403 "src/analyzer/Naming.pv"
        case TYPE__SELF: {
            #line 404 "src/analyzer/Naming.pv"
            return Naming__get_type_name(self, type_self, type_self, generics_map);
        } break;
        #line 406 "src/analyzer/Naming.pv"
        case TYPE__TYPEDEF_C: {
            #line 406 "src/analyzer/Naming.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 407 "src/analyzer/Naming.pv"
            String__append(&result, info->name);
        } break;
        #line 409 "src/analyzer/Naming.pv"
        case TYPE__ENUM_C: {
            #line 409 "src/analyzer/Naming.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 410 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 410 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "enum ", .length = strlen("enum ") });
            }
            #line 411 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, &result, enum_info->parent);
            #line 412 "src/analyzer/Naming.pv"
            String__append(&result, enum_info->name);
        } break;
        #line 414 "src/analyzer/Naming.pv"
        case TYPE__STRUCT_C: {
            #line 414 "src/analyzer/Naming.pv"
            struct StructC* struct_info = type->structc_value;
            #line 415 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 415 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "struct ", .length = strlen("struct ") });
            }
            #line 416 "src/analyzer/Naming.pv"
            String__append(&result, struct_info->name);
        } break;
        #line 418 "src/analyzer/Naming.pv"
        case TYPE__UNION_C: {
            #line 418 "src/analyzer/Naming.pv"
            struct StructC* union_info = type->unionc_value;
            #line 419 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 419 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "union ", .length = strlen("union ") });
            }
            #line 420 "src/analyzer/Naming.pv"
            String__append(&result, union_info->name);
        } break;
        #line 422 "src/analyzer/Naming.pv"
        case TYPE__CLASS_CPP: {
            #line 422 "src/analyzer/Naming.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 423 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, &result, class_info->parent);
            #line 424 "src/analyzer/Naming.pv"
            String__append(&result, class_info->name);
        } break;
        #line 426 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION_C: {
            #line 426 "src/analyzer/Naming.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 427 "src/analyzer/Naming.pv"
            String__append(&result, func_info->name);
        } break;
        #line 429 "src/analyzer/Naming.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 429 "src/analyzer/Naming.pv"
            struct NamespaceCpp* namespace_info = type->namespacecpp_value;
            #line 430 "src/analyzer/Naming.pv"
            String__append(&result, namespace_info->name);
        } break;
        #line 432 "src/analyzer/Naming.pv"
        case TYPE__GLOBAL: {
            #line 432 "src/analyzer/Naming.pv"
            struct Global* g = type->global_value;
            #line 433 "src/analyzer/Naming.pv"
            String__release(&result);
            #line 434 "src/analyzer/Naming.pv"
            return Naming__get_type_name(self, &g->type, type_self, generics_map);
        } break;
    }

    #line 438 "src/analyzer/Naming.pv"
    if (generics.length > 0) {
        #line 439 "src/analyzer/Naming.pv"
        String__append(&result, generic_start);

        #line 441 "src/analyzer/Naming.pv"
        bool first = true;
        #line 442 "src/analyzer/Naming.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&generics);
        #line 442 "src/analyzer/Naming.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 442 "src/analyzer/Naming.pv"
            struct Type* generic = Iter_ref_Type__value(&__iter);

            #line 443 "src/analyzer/Naming.pv"
            if (first) {
                #line 443 "src/analyzer/Naming.pv"
                first = false;
            } else {
                #line 443 "src/analyzer/Naming.pv"
                String__append(&result, self->generic_seperator);
            }

            #line 445 "src/analyzer/Naming.pv"
            if (self->naming_ident != 0) {
                #line 446 "src/analyzer/Naming.pv"
                struct String generic_name = Naming__get_type_name(self->naming_ident, generic, type_self, generics_map);
                #line 447 "src/analyzer/Naming.pv"
                String__append(&result, String__as_str(&generic_name));
            } else {
                #line 449 "src/analyzer/Naming.pv"
                struct String generic_name = Naming__get_type_name(self, generic, type_self, generics_map);
                #line 450 "src/analyzer/Naming.pv"
                String__append(&result, String__as_str(&generic_name));
            }
        } }

        #line 454 "src/analyzer/Naming.pv"
        String__append(&result, generic_end);
    }

    #line 457 "src/analyzer/Naming.pv"
    return result;
}

#line 460 "src/analyzer/Naming.pv"
struct String Naming__get_type_decl(struct Naming* self, struct Type* type, struct Type* type_self, struct GenericMap* generics_map) {
    #line 461 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 462 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION: {
            #line 462 "src/analyzer/Naming.pv"
            struct Function* func_info = type->function_value._0;
            #line 463 "src/analyzer/Naming.pv"
            struct String result = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
            #line 464 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = "fn(", .length = strlen("fn(") });

            #line 466 "src/analyzer/Naming.pv"
            bool first = true;
            #line 467 "src/analyzer/Naming.pv"
            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
            #line 467 "src/analyzer/Naming.pv"
            while (Iter_ref_Parameter__next(&__iter)) {
                #line 467 "src/analyzer/Naming.pv"
                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                #line 468 "src/analyzer/Naming.pv"
                if (first) {
                    #line 468 "src/analyzer/Naming.pv"
                    first = false;
                } else {
                    #line 468 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = ", ", .length = strlen(", ") });
                }
                #line 469 "src/analyzer/Naming.pv"
                struct String param_name = Naming__get_type_decl(self, &param->type, type_self, generics_map);
                #line 470 "src/analyzer/Naming.pv"
                String__append_string(&result, &param_name);
            } }
            #line 472 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 474 "src/analyzer/Naming.pv"
            struct String return_name = Naming__get_type_decl(self, &func_info->return_type, type_self, generics_map);
            #line 475 "src/analyzer/Naming.pv"
            if (!str__eq(String__as_str(&return_name), (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 476 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = ") -> ", .length = strlen(") -> ") });
                #line 477 "src/analyzer/Naming.pv"
                String__append_string(&result, &return_name);
            }

            #line 480 "src/analyzer/Naming.pv"
            return result;
        } break;
        #line 482 "src/analyzer/Naming.pv"
        case TYPE__TYPEDEF_C: {
            #line 482 "src/analyzer/Naming.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 483 "src/analyzer/Naming.pv"
            struct String result = Naming__get_variable_decl(self, typedef_info->name, typedef_info->type, type_self, generics_map);
            #line 484 "src/analyzer/Naming.pv"
            String__prepend(&result, (struct str){ .ptr = "typedef ", .length = strlen("typedef ") });
            #line 485 "src/analyzer/Naming.pv"
            return result;
        } break;
        #line 487 "src/analyzer/Naming.pv"
        default: {
        } break;
    }

    #line 490 "src/analyzer/Naming.pv"
    return Naming__get_type_name(self, type, type_self, generics_map);
}

#line 493 "src/analyzer/Naming.pv"
struct String Naming__get_variable_decl(struct Naming* self, struct str variable_name, struct Type* type, struct Type* type_self, struct GenericMap* generics_map) {
    #line 494 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 495 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION: {
            #line 495 "src/analyzer/Naming.pv"
            struct Function* func_info = type->function_value._0;
            #line 496 "src/analyzer/Naming.pv"
            struct String result = Naming__get_type_name(self, &func_info->return_type, type_self, generics_map);
            #line 497 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = " (*", .length = strlen(" (*") });
            #line 498 "src/analyzer/Naming.pv"
            String__append(&result, variable_name);
            #line 499 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = ")(", .length = strlen(")(") });

            #line 501 "src/analyzer/Naming.pv"
            { struct IterEnumerate_ref_Parameter __iter = Iter_ref_Parameter__enumerate(Array_Parameter__iter(&func_info->parameters));
            #line 501 "src/analyzer/Naming.pv"
            while (IterEnumerate_ref_Parameter__next(&__iter)) {
                #line 501 "src/analyzer/Naming.pv"
                uintptr_t i = IterEnumerate_ref_Parameter__value(&__iter)._0;
                #line 501 "src/analyzer/Naming.pv"
                struct Parameter* param = IterEnumerate_ref_Parameter__value(&__iter)._1;

                #line 502 "src/analyzer/Naming.pv"
                if (i > 0) {
                    #line 502 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = ", ", .length = strlen(", ") });
                }

                #line 504 "src/analyzer/Naming.pv"
                struct String param_type_name = Naming__get_type_name(self, &param->type, type_self, generics_map);
                #line 505 "src/analyzer/Naming.pv"
                String__append_string(&result, &param_type_name);
                #line 506 "src/analyzer/Naming.pv"
                String__release(&param_type_name);
            } }

            #line 509 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 511 "src/analyzer/Naming.pv"
            return result;
        } break;
        #line 513 "src/analyzer/Naming.pv"
        default: {
        } break;
    }

    #line 516 "src/analyzer/Naming.pv"
    struct String result = Naming__get_type_name(self, type, type_self, generics_map);
    #line 517 "src/analyzer/Naming.pv"
    String__append(&result, (struct str){ .ptr = " ", .length = strlen(" ") });
    #line 518 "src/analyzer/Naming.pv"
    String__append(&result, variable_name);

    #line 520 "src/analyzer/Naming.pv"
    Naming__append_decl_suffix(self, &result, type);

    #line 522 "src/analyzer/Naming.pv"
    return result;
}

#line 525 "src/analyzer/Naming.pv"
void Naming__append_decl_suffix(struct Naming* self, struct String* result, struct Type* type) {
    #line 526 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 527 "src/analyzer/Naming.pv"
        case TYPE__SEQUENCE: {
            #line 527 "src/analyzer/Naming.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 528 "src/analyzer/Naming.pv"
            switch (sequence->type.type) {
                #line 529 "src/analyzer/Naming.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 529 "src/analyzer/Naming.pv"
                    uintptr_t length = sequence->type.fixedarray_value;
                    #line 530 "src/analyzer/Naming.pv"
                    String__append(result, self->sequence_open);
                    #line 531 "src/analyzer/Naming.pv"
                    String__append_usize(result, length);
                    #line 532 "src/analyzer/Naming.pv"
                    String__append(result, self->sequence_close);

                    #line 534 "src/analyzer/Naming.pv"
                    Naming__append_decl_suffix(self, result, &sequence->element);
                } break;
                #line 536 "src/analyzer/Naming.pv"
                default: {
                } break;
            }
        } break;
        #line 539 "src/analyzer/Naming.pv"
        default: {
        } break;
    }
}

#line 543 "src/analyzer/Naming.pv"
void Naming__append_cpp_path(struct Naming* self, struct String* result, struct ParentCpp parent) {
    #line 544 "src/analyzer/Naming.pv"
    switch (parent.type) {
        #line 545 "src/analyzer/Naming.pv"
        case PARENT_CPP__NONE: {
            #line 545 "src/analyzer/Naming.pv"
            return;
        } break;
        #line 546 "src/analyzer/Naming.pv"
        case PARENT_CPP__NAMESPACE: {
            #line 546 "src/analyzer/Naming.pv"
            struct NamespaceCpp* ns_info = parent.namespace_value;
            #line 547 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, result, ns_info->parent);
            #line 548 "src/analyzer/Naming.pv"
            String__append(result, ns_info->name);
            #line 549 "src/analyzer/Naming.pv"
            String__append(result, (struct str){ .ptr = "::", .length = strlen("::") });
        } break;
        #line 551 "src/analyzer/Naming.pv"
        case PARENT_CPP__CLASS: {
            #line 551 "src/analyzer/Naming.pv"
            struct ClassCpp* class_info = parent.class_value;
            #line 552 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, result, class_info->parent);
            #line 553 "src/analyzer/Naming.pv"
            String__append(result, class_info->name);
            #line 554 "src/analyzer/Naming.pv"
            String__append(result, (struct str){ .ptr = "::", .length = strlen("::") });
        } break;
    }
}
