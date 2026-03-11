#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <analyzer/NamingType.h>
#include <std/str.h>
#include <std/IterEnumerate_ref_Parameter.h>
#include <std/HashMap_str_str.h>
#include <std/Allocator.h>
#include <std/String.h>
#include <analyzer/Type.h>
#include <analyzer/GenericMap.h>
#include <std/Array_Type.h>
#include <analyzer/IndirectType.h>
#include <analyzer/Indirect.h>
#include <stdbool.h>
#include <analyzer/Sequence.h>
#include <analyzer/SequenceType.h>
#include <stdint.h>
#include <analyzer/Tuple.h>
#include <analyzer/Primitive.h>
#include <analyzer/EnumType.h>
#include <analyzer/Enum.h>
#include <analyzer/Token.h>
#include <analyzer/Struct.h>
#include <std/Array_Generic.h>
#include <analyzer/Generic.h>
#include <analyzer/Generics.h>
#include <analyzer/Trait.h>
#include <analyzer/FunctionParent.h>
#include <analyzer/Function.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/TypedefC.h>
#include <analyzer/ParentCpp.h>
#include <analyzer/EnumC.h>
#include <analyzer/StructC.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/FunctionC.h>
#include <analyzer/NamespaceCpp.h>
#include <std/ArrayIter_ref_Type.h>
#include <analyzer/Parameter.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <tuple_usize_ref_Parameter.h>

#include <analyzer/Naming.h>

#line 41 "src/analyzer/Naming.pv"
struct Naming Naming__new_decl(struct ArenaAllocator* allocator) {
    #line 42 "src/analyzer/Naming.pv"
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
    };
}

#line 58 "src/analyzer/Naming.pv"
struct Naming Naming__new_ident(struct ArenaAllocator* allocator) {
    #line 59 "src/analyzer/Naming.pv"
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
        .tuple_prefix = (struct str){ .ptr = "tuple_", .length = strlen("tuple_") },
    };
}

#line 73 "src/analyzer/Naming.pv"
struct Naming Naming__new_c99(struct ArenaAllocator* allocator, struct Naming* naming_ident) {
    #line 74 "src/analyzer/Naming.pv"
    struct HashMap_str_str primitives = HashMap_str_str__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 75 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "bool", .length = strlen("bool") }, (struct str){ .ptr = "bool", .length = strlen("bool") });
    #line 76 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i8", .length = strlen("i8") }, (struct str){ .ptr = "int8_t", .length = strlen("int8_t") });
    #line 77 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i16", .length = strlen("i16") }, (struct str){ .ptr = "int16_t", .length = strlen("int16_t") });
    #line 78 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i32", .length = strlen("i32") }, (struct str){ .ptr = "int32_t", .length = strlen("int32_t") });
    #line 79 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "i64", .length = strlen("i64") }, (struct str){ .ptr = "int64_t", .length = strlen("int64_t") });
    #line 80 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "isize", .length = strlen("isize") }, (struct str){ .ptr = "intptr_t", .length = strlen("intptr_t") });
    #line 81 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u8", .length = strlen("u8") }, (struct str){ .ptr = "uint8_t", .length = strlen("uint8_t") });
    #line 82 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u16", .length = strlen("u16") }, (struct str){ .ptr = "uint16_t", .length = strlen("uint16_t") });
    #line 83 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u32", .length = strlen("u32") }, (struct str){ .ptr = "uint32_t", .length = strlen("uint32_t") });
    #line 84 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "u64", .length = strlen("u64") }, (struct str){ .ptr = "uint64_t", .length = strlen("uint64_t") });
    #line 85 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "usize", .length = strlen("usize") }, (struct str){ .ptr = "uintptr_t", .length = strlen("uintptr_t") });
    #line 86 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "f32", .length = strlen("f32") }, (struct str){ .ptr = "float", .length = strlen("float") });
    #line 87 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "f64", .length = strlen("f64") }, (struct str){ .ptr = "double", .length = strlen("double") });
    #line 88 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "char", .length = strlen("char") }, (struct str){ .ptr = "char", .length = strlen("char") });
    #line 89 "src/analyzer/Naming.pv"
    HashMap_str_str__insert(&primitives, (struct str){ .ptr = "void", .length = strlen("void") }, (struct str){ .ptr = "void", .length = strlen("void") });

    #line 91 "src/analyzer/Naming.pv"
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
        .trait_prefix = (struct str){ .ptr = "struct ", .length = strlen("struct ") },
        .union_prefix = (struct str){ .ptr = "union ", .length = strlen("union ") },
        .coroutine_instance_prefix = (struct str){ .ptr = "struct ", .length = strlen("struct ") },
        .primitives = primitives,
        .naming_ident = naming_ident,
    };
}

#line 113 "src/analyzer/Naming.pv"
struct String Naming__get_type_name(struct Naming* self, struct Type* type, struct Type* type_self, struct GenericMap* generics_map) {
    #line 114 "src/analyzer/Naming.pv"
    struct String result = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
    #line 115 "src/analyzer/Naming.pv"
    struct Array_Type generics = (struct Array_Type) {};
    #line 116 "src/analyzer/Naming.pv"
    struct str generic_start = self->generic_start;
    #line 117 "src/analyzer/Naming.pv"
    struct str generic_end = self->generic_end;

    #line 119 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 120 "src/analyzer/Naming.pv"
        case TYPE__INDIRECT: {
            #line 120 "src/analyzer/Naming.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 121 "src/analyzer/Naming.pv"
            switch (indirect->type) {
                #line 122 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__POINTER: {
                    #line 122 "src/analyzer/Naming.pv"
                    String__append(&result, self->pointer_prefix);
                } break;
                #line 123 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__CONST_POINTER: {
                    #line 123 "src/analyzer/Naming.pv"
                    String__append(&result, self->pointer_const_prefix);
                } break;
                #line 124 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__REFERENCE: {
                    #line 124 "src/analyzer/Naming.pv"
                    String__append(&result, self->reference_prefix);
                } break;
                #line 125 "src/analyzer/Naming.pv"
                case INDIRECT_TYPE__DYNAMIC_DISPATCH: {
                    #line 125 "src/analyzer/Naming.pv"
                    String__append(&result, self->reference_prefix);
                } break;
            }

            #line 128 "src/analyzer/Naming.pv"
            struct String child_name = Naming__get_type_name(self, &indirect->to, type_self, generics_map);
            #line 129 "src/analyzer/Naming.pv"
            String__append(&result, String__as_str(&child_name));

            #line 131 "src/analyzer/Naming.pv"
            switch (indirect->to.type) {
                #line 132 "src/analyzer/Naming.pv"
                case TYPE__TRAIT: {
                } break;
                #line 133 "src/analyzer/Naming.pv"
                case TYPE__SEQUENCE: {
                    #line 133 "src/analyzer/Naming.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 134 "src/analyzer/Naming.pv"
                    if (!Sequence__is_slice(sequence)) {
                        #line 134 "src/analyzer/Naming.pv"
                        String__append(&result, self->reference_suffix);
                    }
                } break;
                #line 136 "src/analyzer/Naming.pv"
                default: {
                    #line 137 "src/analyzer/Naming.pv"
                    switch (indirect->type) {
                        #line 138 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__POINTER: {
                            #line 138 "src/analyzer/Naming.pv"
                            String__append(&result, self->pointer_suffix);
                        } break;
                        #line 139 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__CONST_POINTER: {
                            #line 139 "src/analyzer/Naming.pv"
                            String__append(&result, self->pointer_const_suffix);
                        } break;
                        #line 140 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__REFERENCE: {
                            #line 140 "src/analyzer/Naming.pv"
                            String__append(&result, self->reference_suffix);
                        } break;
                        #line 141 "src/analyzer/Naming.pv"
                        case INDIRECT_TYPE__DYNAMIC_DISPATCH: {
                            #line 141 "src/analyzer/Naming.pv"
                            String__append(&result, self->reference_suffix);
                        } break;
                    }
                } break;
            }
        } break;
        #line 146 "src/analyzer/Naming.pv"
        case TYPE__SEQUENCE: {
            #line 146 "src/analyzer/Naming.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 147 "src/analyzer/Naming.pv"
            struct String element_name = Naming__get_type_name(self, &sequence->element, type_self, generics_map);

            #line 149 "src/analyzer/Naming.pv"
            switch (sequence->type.type) {
                #line 150 "src/analyzer/Naming.pv"
                case SEQUENCE_TYPE__SLICE: {
                    #line 151 "src/analyzer/Naming.pv"
                    if (self->naming_ident != 0) {
                        #line 152 "src/analyzer/Naming.pv"
                        String__release(&element_name);
                        #line 153 "src/analyzer/Naming.pv"
                        element_name = Naming__get_type_name(self->naming_ident, &sequence->element, type_self, generics_map);
                    }

                    #line 156 "src/analyzer/Naming.pv"
                    String__append(&result, self->sequence_slice_prefix);
                } break;
                #line 158 "src/analyzer/Naming.pv"
                default: {
                } break;
            }

            #line 161 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 162 "src/analyzer/Naming.pv"
                String__append(&result, String__as_str(&element_name));
            } else {
                #line 164 "src/analyzer/Naming.pv"
                switch (sequence->type.type) {
                    #line 165 "src/analyzer/Naming.pv"
                    case SEQUENCE_TYPE__FIXED_ARRAY: {
                        #line 165 "src/analyzer/Naming.pv"
                        uintptr_t length = sequence->type.fixedarray_value;
                        #line 166 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_open);
                        #line 167 "src/analyzer/Naming.pv"
                        String__append(&result, String__as_str(&element_name));
                        #line 168 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_fixed_delimiter);
                        #line 169 "src/analyzer/Naming.pv"
                        String__append_usize(&result, length);
                        #line 170 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_close);
                    } break;
                    #line 172 "src/analyzer/Naming.pv"
                    case SEQUENCE_TYPE__SLICE: {
                        #line 173 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_open);
                        #line 174 "src/analyzer/Naming.pv"
                        String__append(&result, String__as_str(&element_name));
                        #line 175 "src/analyzer/Naming.pv"
                        String__append(&result, self->sequence_close);
                    } break;
                }
            }
        } break;
        #line 180 "src/analyzer/Naming.pv"
        case TYPE__TUPLE: {
            #line 180 "src/analyzer/Naming.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 181 "src/analyzer/Naming.pv"
            String__append(&result, self->tuple_prefix);
            #line 182 "src/analyzer/Naming.pv"
            generic_start = self->tuple_open;
            #line 183 "src/analyzer/Naming.pv"
            generic_end = self->tuple_close;
            #line 184 "src/analyzer/Naming.pv"
            generics = tuple->elements;
        } break;
        #line 186 "src/analyzer/Naming.pv"
        case TYPE__PRIMITIVE: {
            #line 186 "src/analyzer/Naming.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 187 "src/analyzer/Naming.pv"
            if (primitive_info == 0) {
                #line 188 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "void", .length = strlen("void") });
            } else {
                #line 190 "src/analyzer/Naming.pv"
                struct str* translation = HashMap_str_str__find(&self->primitives, &primitive_info->name);

                #line 192 "src/analyzer/Naming.pv"
                if (translation != 0) {
                    #line 193 "src/analyzer/Naming.pv"
                    String__append(&result, *translation);
                } else {
                    #line 195 "src/analyzer/Naming.pv"
                    String__append(&result, primitive_info->name);
                }
            }
        } break;
        #line 199 "src/analyzer/Naming.pv"
        case TYPE__ENUM: {
            #line 199 "src/analyzer/Naming.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 199 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->enum_value._1;
            #line 200 "src/analyzer/Naming.pv"
            switch (enum_info->type) {
                #line 201 "src/analyzer/Naming.pv"
                case ENUM_TYPE__STANDARD: {
                    #line 201 "src/analyzer/Naming.pv"
                    String__append(&result, self->enum_prefix);
                } break;
                #line 202 "src/analyzer/Naming.pv"
                case ENUM_TYPE__DISCRIMINATED_UNION: {
                    #line 202 "src/analyzer/Naming.pv"
                    String__append(&result, self->struct_prefix);
                } break;
            }

            #line 205 "src/analyzer/Naming.pv"
            String__append(&result, enum_info->name->value);
            #line 206 "src/analyzer/Naming.pv"
            generics = generics2->array;
        } break;
        #line 208 "src/analyzer/Naming.pv"
        case TYPE__STRUCT: {
            #line 208 "src/analyzer/Naming.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 208 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->struct_value._1;
            #line 209 "src/analyzer/Naming.pv"
            if (!Struct__is_newtype(struct_info)) {
                #line 210 "src/analyzer/Naming.pv"
                String__append(&result, self->struct_prefix);
            }

            #line 213 "src/analyzer/Naming.pv"
            String__append(&result, struct_info->name->value);

            #line 215 "src/analyzer/Naming.pv"
            if ((struct_info->generics.array.length > 0)) {
                #line 216 "src/analyzer/Naming.pv"
                generics = generics2->array;
            }
        } break;
        #line 219 "src/analyzer/Naming.pv"
        case TYPE__TRAIT: {
            #line 219 "src/analyzer/Naming.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 219 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->trait_value._1;
            #line 220 "src/analyzer/Naming.pv"
            String__append(&result, self->trait_prefix);
            #line 221 "src/analyzer/Naming.pv"
            String__append(&result, trait_info->name->value);
            #line 222 "src/analyzer/Naming.pv"
            generics = generics2->array;
        } break;
        #line 224 "src/analyzer/Naming.pv"
        case TYPE__GENERIC: {
            #line 224 "src/analyzer/Naming.pv"
            struct Generic* generic = type->generic_value;
            #line 225 "src/analyzer/Naming.pv"
            struct str name = generic->name->value;

            #line 227 "src/analyzer/Naming.pv"
            if (generics_map == 0) {
                #line 228 "src/analyzer/Naming.pv"
                String__append(&result, name);
                #line 229 "src/analyzer/Naming.pv"
                return result;
            }

            #line 232 "src/analyzer/Naming.pv"
            struct Type* generic_type = GenericMap__get(generics_map, name);
            #line 233 "src/analyzer/Naming.pv"
            if (generic_type == 0) {
                #line 234 "src/analyzer/Naming.pv"
                uint32_t len = name.length;
                #line 235 "src/analyzer/Naming.pv"
                fprintf(stderr, "Naming.get_type_name: Attempt to retrieve generic %.*s but it does not exist in generics\n", len, name.ptr);
            }

            #line 238 "src/analyzer/Naming.pv"
            return Naming__get_type_name(self, generic_type, type_self, generics_map);
        } break;
        #line 240 "src/analyzer/Naming.pv"
        case TYPE__UNKNOWN: {
            #line 240 "src/analyzer/Naming.pv"
            struct str name = type->unknown_value._0;
            #line 240 "src/analyzer/Naming.pv"
            struct Array_Type generics2 = type->unknown_value._1;
            #line 241 "src/analyzer/Naming.pv"
            String__append(&result, name);
            #line 242 "src/analyzer/Naming.pv"
            generics = generics2;
        } break;
        #line 244 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION: {
            #line 244 "src/analyzer/Naming.pv"
            struct Function* func_info = type->function_value._0;
            #line 244 "src/analyzer/Naming.pv"
            struct GenericMap* generics2 = type->function_value._1;
            #line 245 "src/analyzer/Naming.pv"
            bool has_parent = false;
            #line 246 "src/analyzer/Naming.pv"
            struct Type parent_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 };
            #line 247 "src/analyzer/Naming.pv"
            struct Trait* trait_info = 0;

            #line 249 "src/analyzer/Naming.pv"
            switch (func_info->parent.type) {
                #line 250 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__NONE: {
                } break;
                #line 251 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 251 "src/analyzer/Naming.pv"
                    struct Primitive* primitive = func_info->parent.primitive_value._0;
                    #line 251 "src/analyzer/Naming.pv"
                    struct Trait* trait_info2 = func_info->parent.primitive_value._2;
                    #line 252 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive };
                    #line 253 "src/analyzer/Naming.pv"
                    trait_info = trait_info2;
                    #line 254 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 256 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 256 "src/analyzer/Naming.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 256 "src/analyzer/Naming.pv"
                    struct Trait* trait_info2 = func_info->parent.enum_value._2;
                    #line 257 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generics2} };
                    #line 258 "src/analyzer/Naming.pv"
                    trait_info = trait_info2;
                    #line 259 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 261 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 261 "src/analyzer/Naming.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 261 "src/analyzer/Naming.pv"
                    struct Trait* trait_info2 = func_info->parent.struct_value._2;
                    #line 262 "src/analyzer/Naming.pv"
                    parent_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics2} };
                    #line 263 "src/analyzer/Naming.pv"
                    trait_info = trait_info2;
                    #line 264 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
                #line 266 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__TRAIT: {
                } break;
                #line 267 "src/analyzer/Naming.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 267 "src/analyzer/Naming.pv"
                    struct Type* type = func_info->parent.type_value._0;
                    #line 268 "src/analyzer/Naming.pv"
                    if (Type__is_fat_pointer(type)) {
                        #line 269 "src/analyzer/Naming.pv"
                        parent_type = *Type__deref_1(type);
                    } else {
                        #line 271 "src/analyzer/Naming.pv"
                        parent_type = *type;
                    }

                    #line 274 "src/analyzer/Naming.pv"
                    has_parent = true;
                } break;
            }

            #line 278 "src/analyzer/Naming.pv"
            if (has_parent) {
                #line 279 "src/analyzer/Naming.pv"
                if (self->naming_ident != 0) {
                    #line 280 "src/analyzer/Naming.pv"
                    struct String parent_type_name = Naming__get_type_name(self->naming_ident, &parent_type, type_self, generics_map);
                    #line 281 "src/analyzer/Naming.pv"
                    String__append_string(&result, &parent_type_name);
                    #line 282 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
                } else {
                    #line 284 "src/analyzer/Naming.pv"
                    struct String parent_type_name = Naming__get_type_name(self, &parent_type, type_self, generics_map);
                    #line 285 "src/analyzer/Naming.pv"
                    String__append_string(&result, &parent_type_name);
                    #line 286 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
                }
            }

            #line 290 "src/analyzer/Naming.pv"
            if (trait_info != 0) {
                #line 291 "src/analyzer/Naming.pv"
                String__append(&result, trait_info->name->value);
                #line 292 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "__", .length = strlen("__") });
            }

            #line 295 "src/analyzer/Naming.pv"
            String__append(&result, func_info->name->value);
            #line 296 "src/analyzer/Naming.pv"
            if (func_info->generics.map.length > 0) {
                #line 297 "src/analyzer/Naming.pv"
                generics = generics2->array;
            }
        } break;
        #line 300 "src/analyzer/Naming.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 300 "src/analyzer/Naming.pv"
            struct Function* func_info = type->coroutineinstance_value._0;
            #line 301 "src/analyzer/Naming.pv"
            String__append(&result, self->coroutine_instance_prefix);
            #line 302 "src/analyzer/Naming.pv"
            String__append(&result, func_info->name->value);
        } break;
        #line 304 "src/analyzer/Naming.pv"
        case TYPE__SELF: {
            #line 305 "src/analyzer/Naming.pv"
            return Naming__get_type_name(self, type_self, type_self, generics_map);
        } break;
        #line 307 "src/analyzer/Naming.pv"
        case TYPE__TYPEDEF_C: {
            #line 307 "src/analyzer/Naming.pv"
            struct TypedefC* info = type->typedefc_value;
            #line 308 "src/analyzer/Naming.pv"
            String__append(&result, info->name);
        } break;
        #line 310 "src/analyzer/Naming.pv"
        case TYPE__ENUM_C: {
            #line 310 "src/analyzer/Naming.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 311 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 311 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "enum ", .length = strlen("enum ") });
            }
            #line 312 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, &result, enum_info->parent);
            #line 313 "src/analyzer/Naming.pv"
            String__append(&result, enum_info->name);
        } break;
        #line 315 "src/analyzer/Naming.pv"
        case TYPE__STRUCT_C: {
            #line 315 "src/analyzer/Naming.pv"
            struct StructC* struct_info = type->structc_value;
            #line 316 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 316 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "struct ", .length = strlen("struct ") });
            }
            #line 317 "src/analyzer/Naming.pv"
            String__append(&result, struct_info->name);
        } break;
        #line 319 "src/analyzer/Naming.pv"
        case TYPE__UNION_C: {
            #line 319 "src/analyzer/Naming.pv"
            struct StructC* union_info = type->unionc_value;
            #line 320 "src/analyzer/Naming.pv"
            if (self->type == NAMING_TYPE__C99) {
                #line 320 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = "union ", .length = strlen("union ") });
            }
            #line 321 "src/analyzer/Naming.pv"
            String__append(&result, union_info->name);
        } break;
        #line 323 "src/analyzer/Naming.pv"
        case TYPE__CLASS_CPP: {
            #line 323 "src/analyzer/Naming.pv"
            struct ClassCpp* class_info = type->classcpp_value;
            #line 324 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, &result, class_info->parent);
            #line 325 "src/analyzer/Naming.pv"
            String__append(&result, class_info->name);
        } break;
        #line 327 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION_C: {
            #line 327 "src/analyzer/Naming.pv"
            struct FunctionC* func_info = type->functionc_value;
            #line 328 "src/analyzer/Naming.pv"
            String__append(&result, func_info->name);
        } break;
        #line 330 "src/analyzer/Naming.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 330 "src/analyzer/Naming.pv"
            struct NamespaceCpp* namespace_info = type->namespacecpp_value;
            #line 331 "src/analyzer/Naming.pv"
            String__append(&result, namespace_info->name);
        } break;
    }

    #line 335 "src/analyzer/Naming.pv"
    if (generics.length > 0) {
        #line 336 "src/analyzer/Naming.pv"
        String__append(&result, generic_start);

        #line 338 "src/analyzer/Naming.pv"
        bool first = true;
        #line 339 "src/analyzer/Naming.pv"
        { struct ArrayIter_ref_Type __iter = Array_Type__iter(&generics);
        #line 339 "src/analyzer/Naming.pv"
        while (ArrayIter_ref_Type__next(&__iter)) {
            #line 339 "src/analyzer/Naming.pv"
            struct Type* generic = ArrayIter_ref_Type__value(&__iter);

            #line 340 "src/analyzer/Naming.pv"
            if (first) {
                #line 340 "src/analyzer/Naming.pv"
                first = false;
            } else {
                #line 340 "src/analyzer/Naming.pv"
                String__append(&result, self->generic_seperator);
            }

            #line 342 "src/analyzer/Naming.pv"
            if (self->naming_ident != 0) {
                #line 343 "src/analyzer/Naming.pv"
                struct String generic_name = Naming__get_type_name(self->naming_ident, generic, type_self, generics_map);
                #line 344 "src/analyzer/Naming.pv"
                String__append(&result, String__as_str(&generic_name));
            } else {
                #line 346 "src/analyzer/Naming.pv"
                struct String generic_name = Naming__get_type_name(self, generic, type_self, generics_map);
                #line 347 "src/analyzer/Naming.pv"
                String__append(&result, String__as_str(&generic_name));
            }
        } }

        #line 351 "src/analyzer/Naming.pv"
        String__append(&result, generic_end);
    }

    #line 354 "src/analyzer/Naming.pv"
    return result;
}

#line 357 "src/analyzer/Naming.pv"
struct String Naming__get_type_decl(struct Naming* self, struct Type* type, struct Type* type_self, struct GenericMap* generics_map) {
    #line 358 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 359 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION: {
            #line 359 "src/analyzer/Naming.pv"
            struct Function* func_info = type->function_value._0;
            #line 360 "src/analyzer/Naming.pv"
            struct String result = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator });
            #line 361 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = "fn(", .length = strlen("fn(") });

            #line 363 "src/analyzer/Naming.pv"
            bool first = true;
            #line 364 "src/analyzer/Naming.pv"
            { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
            #line 364 "src/analyzer/Naming.pv"
            while (ArrayIter_ref_Parameter__next(&__iter)) {
                #line 364 "src/analyzer/Naming.pv"
                struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

                #line 365 "src/analyzer/Naming.pv"
                if (first) {
                    #line 365 "src/analyzer/Naming.pv"
                    first = false;
                } else {
                    #line 365 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = ", ", .length = strlen(", ") });
                }
                #line 366 "src/analyzer/Naming.pv"
                struct String param_name = Naming__get_type_decl(self, &param->type, type_self, generics_map);
                #line 367 "src/analyzer/Naming.pv"
                String__append_string(&result, &param_name);
            } }
            #line 369 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 371 "src/analyzer/Naming.pv"
            struct String return_name = Naming__get_type_decl(self, &func_info->return_type, type_self, generics_map);
            #line 372 "src/analyzer/Naming.pv"
            if (!str__eq(String__as_str(&return_name), (struct str){ .ptr = "void", .length = strlen("void") })) {
                #line 373 "src/analyzer/Naming.pv"
                String__append(&result, (struct str){ .ptr = ") -> ", .length = strlen(") -> ") });
                #line 374 "src/analyzer/Naming.pv"
                String__append_string(&result, &return_name);
            }

            #line 377 "src/analyzer/Naming.pv"
            return result;
        } break;
        #line 379 "src/analyzer/Naming.pv"
        default: {
        } break;
    }

    #line 382 "src/analyzer/Naming.pv"
    return Naming__get_type_name(self, type, type_self, generics_map);
}

#line 385 "src/analyzer/Naming.pv"
struct String Naming__get_variable_decl(struct Naming* self, struct str variable_name, struct Type* type, struct Type* type_self, struct GenericMap* generics_map) {
    #line 386 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 387 "src/analyzer/Naming.pv"
        case TYPE__FUNCTION: {
            #line 387 "src/analyzer/Naming.pv"
            struct Function* func_info = type->function_value._0;
            #line 388 "src/analyzer/Naming.pv"
            struct String result = Naming__get_type_name(self, &func_info->return_type, type_self, generics_map);
            #line 389 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = " (*", .length = strlen(" (*") });
            #line 390 "src/analyzer/Naming.pv"
            String__append(&result, variable_name);
            #line 391 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = ")(", .length = strlen(")(") });

            #line 393 "src/analyzer/Naming.pv"
            { struct IterEnumerate_ref_Parameter __iter = ArrayIter_ref_Parameter__enumerate(Array_Parameter__iter(&func_info->parameters));
            #line 393 "src/analyzer/Naming.pv"
            while (IterEnumerate_ref_Parameter__next(&__iter)) {
                #line 393 "src/analyzer/Naming.pv"
                uintptr_t i = IterEnumerate_ref_Parameter__value(&__iter)._0;
                #line 393 "src/analyzer/Naming.pv"
                struct Parameter* param = IterEnumerate_ref_Parameter__value(&__iter)._1;

                #line 394 "src/analyzer/Naming.pv"
                if (i > 0) {
                    #line 394 "src/analyzer/Naming.pv"
                    String__append(&result, (struct str){ .ptr = ", ", .length = strlen(", ") });
                }

                #line 396 "src/analyzer/Naming.pv"
                struct String param_type_name = Naming__get_type_name(self, &param->type, type_self, generics_map);
                #line 397 "src/analyzer/Naming.pv"
                String__append_string(&result, &param_type_name);
                #line 398 "src/analyzer/Naming.pv"
                String__release(&param_type_name);
            } }

            #line 401 "src/analyzer/Naming.pv"
            String__append(&result, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 403 "src/analyzer/Naming.pv"
            return result;
        } break;
        #line 405 "src/analyzer/Naming.pv"
        default: {
        } break;
    }
    #line 409 "src/analyzer/Naming.pv"
    struct String result = Naming__get_type_name(self, type, type_self, generics_map);
    #line 410 "src/analyzer/Naming.pv"
    String__append(&result, (struct str){ .ptr = " ", .length = strlen(" ") });
    #line 411 "src/analyzer/Naming.pv"
    String__append(&result, variable_name);

    #line 413 "src/analyzer/Naming.pv"
    switch (type->type) {
        #line 414 "src/analyzer/Naming.pv"
        case TYPE__SEQUENCE: {
            #line 414 "src/analyzer/Naming.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 415 "src/analyzer/Naming.pv"
            switch (sequence->type.type) {
                #line 416 "src/analyzer/Naming.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 416 "src/analyzer/Naming.pv"
                    uintptr_t length = sequence->type.fixedarray_value;
                    #line 417 "src/analyzer/Naming.pv"
                    String__append(&result, self->sequence_open);
                    #line 418 "src/analyzer/Naming.pv"
                    String__append_usize(&result, length);
                    #line 419 "src/analyzer/Naming.pv"
                    String__append(&result, self->sequence_close);
                } break;
                #line 421 "src/analyzer/Naming.pv"
                default: {
                } break;
            }
        } break;
        #line 424 "src/analyzer/Naming.pv"
        default: {
        } break;
    }

    #line 427 "src/analyzer/Naming.pv"
    return result;
}

#line 430 "src/analyzer/Naming.pv"
void Naming__append_cpp_path(struct Naming* self, struct String* result, struct ParentCpp parent) {
    #line 431 "src/analyzer/Naming.pv"
    switch (parent.type) {
        #line 432 "src/analyzer/Naming.pv"
        case PARENT_CPP__NONE: {
            #line 432 "src/analyzer/Naming.pv"
            return;
        } break;
        #line 433 "src/analyzer/Naming.pv"
        case PARENT_CPP__NAMESPACE: {
            #line 433 "src/analyzer/Naming.pv"
            struct NamespaceCpp* ns_info = parent.namespace_value;
            #line 434 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, result, ns_info->parent);
            #line 435 "src/analyzer/Naming.pv"
            String__append(result, ns_info->name);
            #line 436 "src/analyzer/Naming.pv"
            String__append(result, (struct str){ .ptr = "::", .length = strlen("::") });
        } break;
        #line 438 "src/analyzer/Naming.pv"
        case PARENT_CPP__CLASS: {
            #line 438 "src/analyzer/Naming.pv"
            struct ClassCpp* class_info = parent.class_value;
            #line 439 "src/analyzer/Naming.pv"
            Naming__append_cpp_path(self, result, class_info->parent);
            #line 440 "src/analyzer/Naming.pv"
            String__append(result, class_info->name);
            #line 441 "src/analyzer/Naming.pv"
            String__append(result, (struct str){ .ptr = "::", .length = strlen("::") });
        } break;
    }
}
