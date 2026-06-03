#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <stdio.h>
#include <analyzer/Root.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <analyzer/Analysis.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/Generics.h>
#include <std/Array_Generic.h>
#include <std/HashMap_str_usize.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/c/UnknownC.h>
#include <std/str.h>
#include <std/Array_Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/Generic.h>
#include <std/Array_ref_Trait.h>
#include <std/HashMapIter_str_Primitive.h>
#include <tuple_str_Primitive.h>
#include <std/Iter_ref_ptrc_char.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <analyzer/Namespace.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/Impl.h>
#include <std/IterEnumerate_ref_TypeImpl.h>
#include <std/Iter_ref_TypeImpl.h>
#include <tuple_usize_ref_TypeImpl.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>
#include <analyzer/Position.h>
#include <analyzer/Root.h>

#include <analyzer/Root.h>

#line 38 "src/analyzer/Root.pv"
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Array_ptrc_char* clang_args, struct Analysis* analysis) {
    #line 39 "src/analyzer/Root.pv"
    struct Root* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Root));

    #line 41 "src/analyzer/Root.pv"
    *self = (struct Root) {
        .allocator = allocator,
        .children = HashMap_str_ref_Namespace__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitives = HashMap_str_Primitive__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .ctypes = HashMap_str_TypedefC__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .clang_args = Array_ptrc_char__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .analysis = analysis,
        .naming_decl = Naming__new_decl(allocator),
        .includes_c = HashMap_str_ref_Include__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .includes_cpp = HashMap_str_ref_Include__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitive_bool = 0,
        .primitive_usize = 0,
        .primitive_void = 0,
        .type_void = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .type_bool = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .type_unknown = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .type_self = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .type_ref_self = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .type_usize = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .func_next = (struct Function) { .name = 0, .context = 0, .declaration_start = 0, .declaration_end = 0, .token_start = 0, .token_end = 0, .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE }, .type = FUNCTION_TYPE__STANDARD, .variadic = false, .typed_variadic = false, .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }, .parameters = (struct Array_Parameter) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 }, .body = 0 },
        .func_value = (struct Function) { .name = 0, .context = 0, .declaration_start = 0, .declaration_end = 0, .token_start = 0, .token_end = 0, .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE }, .type = FUNCTION_TYPE__STANDARD, .variadic = false, .typed_variadic = false, .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }, .parameters = (struct Array_Parameter) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 }, .body = 0 },
        .type_impls = Array_TypeImpl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .hack_type_impl = 0,
        .mode_cpp = false,
    };

    #line 70 "src/analyzer/Root.pv"
    self->primitive_bool = Root__add_primitive(self, "bool");
    #line 71 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i8");
    #line 72 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i16");
    #line 73 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i32");
    #line 74 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i64");
    #line 75 "src/analyzer/Root.pv"
    Root__add_primitive(self, "isize");
    #line 76 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u8");
    #line 77 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u16");
    #line 78 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u32");
    #line 79 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u64");
    #line 80 "src/analyzer/Root.pv"
    self->primitive_usize = Root__add_primitive(self, "usize");
    #line 81 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f32");
    #line 82 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f64");
    #line 83 "src/analyzer/Root.pv"
    Root__add_primitive(self, "char");
    #line 84 "src/analyzer/Root.pv"
    self->primitive_void = Root__add_primitive(self, "void");
    #line 85 "src/analyzer/Root.pv"
    self->type_void = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_void };
    #line 86 "src/analyzer/Root.pv"
    self->type_bool = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool };
    #line 87 "src/analyzer/Root.pv"
    struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "unknown", .length = strlen("unknown") }, .generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 } }});
    #line 88 "src/analyzer/Root.pv"
    self->type_unknown = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
    #line 89 "src/analyzer/Root.pv"
    self->type_self = (struct Type) { .type = TYPE__SELF };
    #line 90 "src/analyzer/Root.pv"
    self->type_ref_self = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, self->type_self) };
    #line 91 "src/analyzer/Root.pv"
    self->type_usize = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_usize };
    #line 92 "src/analyzer/Root.pv"
    self->func_next = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .variadic = false,
        .typed_variadic = false,
        .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "next", .length = strlen("next") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}),
        .parameters = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool },
        .context = 0,
        .declaration_start = 0,
        .declaration_end = 0,
        .token_start = 0,
        .token_end = 0,
        .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE },
        .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
        .body = 0,
    };
    #line 108 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_next.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "self", .length = strlen("self") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .type = self->type_ref_self });

    #line 110 "src/analyzer/Root.pv"
    self->func_value = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .variadic = false,
        .typed_variadic = false,
        .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "value", .length = strlen("value") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}),
        .parameters = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = ArenaAllocator__store_Generic(allocator, (struct Generic[]){(struct Generic) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .traits = (struct Array_ref_Trait) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 } }}) },
        .context = 0,
        .declaration_start = 0,
        .declaration_end = 0,
        .token_start = 0,
        .token_end = 0,
        .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE },
        .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
        .body = 0,
    };
    #line 126 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_value.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "self", .length = strlen("self") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .type = self->type_ref_self });

    #line 128 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 128 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 128 "src/analyzer/Root.pv"
        struct str key = HashMapIter_str_Primitive__value(&__iter)->_0;
        #line 128 "src/analyzer/Root.pv"
        struct Primitive* value = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 129 "src/analyzer/Root.pv"
        struct Array_Type arr = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 130 "src/analyzer/Root.pv"
        Array_Type__append(&arr, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = value });
        #line 131 "src/analyzer/Root.pv"
        HashMap_str_Array_Type__insert(&self->types, key, arr);
    } }

    #line 134 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(args);
    #line 134 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 134 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 135 "src/analyzer/Root.pv"
        char const* pos = strchr(arg, '=');

        #line 137 "src/analyzer/Root.pv"
        if (pos == 0) {
            #line 138 "src/analyzer/Root.pv"
            fprintf(stderr, "Unknown arg \"%s\"\n", arg);
        } else {
            #line 140 "src/analyzer/Root.pv"
            struct str arg_str = (struct str){ .ptr = arg, .length = strlen(arg) };
            #line 141 "src/analyzer/Root.pv"
            struct str name = str__slice(arg_str, 0, pos - arg);
            #line 142 "src/analyzer/Root.pv"
            char const* path = pos + 1;

            #line 144 "src/analyzer/Root.pv"
            Root__add_namespace(self, name, (struct str){ .ptr = path, .length = strlen(path) });
        }
    } }

    #line 148 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(clang_args);
    #line 148 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 148 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 149 "src/analyzer/Root.pv"
        Array_ptrc_char__append(&self->clang_args, arg);
    } }

    #line 152 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 152 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 152 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 153 "src/analyzer/Root.pv"
        Namespace__parse(child);
    } }

    #line 156 "src/analyzer/Root.pv"
    return self;
}

#line 159 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name) {
    #line 160 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 163 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name) {
    #line 164 "src/analyzer/Root.pv"
    struct Primitive* existing = HashMap_str_Primitive__find(&self->primitives, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 165 "src/analyzer/Root.pv"
    if (existing != 0) {
        #line 165 "src/analyzer/Root.pv"
        return existing;
    }

    #line 167 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 170 "src/analyzer/Root.pv"
uintptr_t Root__add_type_impl(struct Root* self, struct Type type, struct Impl* impl_info) {
    #line 171 "src/analyzer/Root.pv"
    uintptr_t index = self->type_impls.length;
    #line 172 "src/analyzer/Root.pv"
    Array_TypeImpl__append(&self->type_impls, TypeImpl__new(self->allocator, type, impl_info, index));
    #line 173 "src/analyzer/Root.pv"
    return index;
}

#line 176 "src/analyzer/Root.pv"
struct TypeImpl* Root__get_type_impl(struct Root* self, struct Type* type, uintptr_t impl_index) {
    #line 177 "src/analyzer/Root.pv"
    struct TypeImpl* type_impl = Array_TypeImpl__get(&self->type_impls, impl_index);
    #line 178 "src/analyzer/Root.pv"
    if (type_impl == 0) {
        #line 178 "src/analyzer/Root.pv"
        return 0;
    }
    #line 179 "src/analyzer/Root.pv"
    if (Root__type_impl_target_eq(self, &type_impl->type, type)) {
        #line 179 "src/analyzer/Root.pv"
        return type_impl;
    }

    #line 181 "src/analyzer/Root.pv"
    return 0;
}

#line 184 "src/analyzer/Root.pv"
struct Function* Root__find_type_impl_function(struct Root* self, struct Type* type, struct str name, struct GenericMap* generic_map) {
    #line 185 "src/analyzer/Root.pv"
    { struct IterEnumerate_ref_TypeImpl __iter = Iter_ref_TypeImpl__enumerate(Array_TypeImpl__iter(&self->type_impls));
    #line 185 "src/analyzer/Root.pv"
    while (IterEnumerate_ref_TypeImpl__next(&__iter)) {
        #line 185 "src/analyzer/Root.pv"
        uintptr_t impl_index = IterEnumerate_ref_TypeImpl__value(&__iter)._0;
        #line 185 "src/analyzer/Root.pv"
        struct TypeImpl type_impl = *IterEnumerate_ref_TypeImpl__value(&__iter)._1;

        #line 186 "src/analyzer/Root.pv"
        if (type_impl.impl_info->generics.array.length != 0) {
            #line 186 "src/analyzer/Root.pv"
            continue;
        }
        #line 187 "src/analyzer/Root.pv"
        if (!Root__type_impl_target_eq(self, &type_impl.type, type)) {
            #line 187 "src/analyzer/Root.pv"
            continue;
        }

        #line 189 "src/analyzer/Root.pv"
        struct Function* function = Impl__find_function(type_impl.impl_info, name);
        #line 190 "src/analyzer/Root.pv"
        if (function == 0) {
            #line 190 "src/analyzer/Root.pv"
            continue;
        }

        #line 192 "src/analyzer/Root.pv"
        struct Function* stored_func_info = ArenaAllocator__store_Function(self->allocator, function);
        #line 193 "src/analyzer/Root.pv"
        if (stored_func_info == 0) {
            #line 193 "src/analyzer/Root.pv"
            return function;
        }
        #line 194 "src/analyzer/Root.pv"
        stored_func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl.type, ._1 = impl_index, ._2 = type_impl.impl_info->trait_} };
        #line 195 "src/analyzer/Root.pv"
        return stored_func_info;
    } }

    #line 198 "src/analyzer/Root.pv"
    return 0;
}

#line 201 "src/analyzer/Root.pv"
bool Root__type_impl_target_eq(struct Root* self, struct Type* left, struct Type* right) {
    #line 202 "src/analyzer/Root.pv"
    switch (left->type) {
        #line 203 "src/analyzer/Root.pv"
        case TYPE__PRIMITIVE: {
            #line 203 "src/analyzer/Root.pv"
            struct Primitive* left_primitive = left->primitive_value;
            #line 204 "src/analyzer/Root.pv"
            if (left_primitive == 0) {
                #line 204 "src/analyzer/Root.pv"
                return false;
            }
            #line 205 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 206 "src/analyzer/Root.pv"
                case TYPE__PRIMITIVE: {
                    #line 206 "src/analyzer/Root.pv"
                    struct Primitive* right_primitive = right->primitive_value;
                    #line 207 "src/analyzer/Root.pv"
                    if (right_primitive == 0) {
                        #line 207 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 208 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(&left_primitive->name, right_primitive->name);
                } break;
                #line 210 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 213 "src/analyzer/Root.pv"
        case TYPE__INDIRECT: {
            #line 213 "src/analyzer/Root.pv"
            struct Indirect* left_indirect = left->indirect_value;
            #line 214 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 215 "src/analyzer/Root.pv"
                case TYPE__INDIRECT: {
                    #line 215 "src/analyzer/Root.pv"
                    struct Indirect* right_indirect = right->indirect_value;
                    #line 216 "src/analyzer/Root.pv"
                    if (left_indirect->type != right_indirect->type) {
                        #line 216 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 217 "src/analyzer/Root.pv"
                    return Root__type_impl_target_eq(self, &left_indirect->to, &right_indirect->to);
                } break;
                #line 219 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 222 "src/analyzer/Root.pv"
        case TYPE__SEQUENCE: {
            #line 222 "src/analyzer/Root.pv"
            struct Sequence* left_sequence = left->sequence_value;
            #line 223 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 224 "src/analyzer/Root.pv"
                case TYPE__SEQUENCE: {
                    #line 224 "src/analyzer/Root.pv"
                    struct Sequence* right_sequence = right->sequence_value;
                    #line 225 "src/analyzer/Root.pv"
                    switch (left_sequence->type.type) {
                        #line 226 "src/analyzer/Root.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 227 "src/analyzer/Root.pv"
                            switch (right_sequence->type.type) {
                                #line 228 "src/analyzer/Root.pv"
                                case SEQUENCE_TYPE__SLICE: {
                                } break;
                                #line 229 "src/analyzer/Root.pv"
                                default: {
                                    #line 229 "src/analyzer/Root.pv"
                                    return false;
                                } break;
                            }
                        } break;
                        #line 232 "src/analyzer/Root.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 233 "src/analyzer/Root.pv"
                            switch (right_sequence->type.type) {
                                #line 234 "src/analyzer/Root.pv"
                                case SEQUENCE_TYPE__FIXED_ARRAY: {
                                } break;
                                #line 235 "src/analyzer/Root.pv"
                                default: {
                                    #line 235 "src/analyzer/Root.pv"
                                    return false;
                                } break;
                            }
                        } break;
                    }
                    #line 239 "src/analyzer/Root.pv"
                    return Root__type_impl_target_eq(self, &left_sequence->element, &right_sequence->element);
                } break;
                #line 241 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 244 "src/analyzer/Root.pv"
        case TYPE__STRUCT: {
            #line 244 "src/analyzer/Root.pv"
            struct Struct* left_struct = left->struct_value._0;
            #line 244 "src/analyzer/Root.pv"
            struct GenericMap* left_generics = left->struct_value._1;
            #line 245 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 246 "src/analyzer/Root.pv"
                case TYPE__STRUCT: {
                    #line 246 "src/analyzer/Root.pv"
                    struct Struct* right_struct = right->struct_value._0;
                    #line 246 "src/analyzer/Root.pv"
                    struct GenericMap* right_generics = right->struct_value._1;
                    #line 247 "src/analyzer/Root.pv"
                    if (left_struct != right_struct) {
                        #line 247 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 248 "src/analyzer/Root.pv"
                    return Root__type_impl_generics_eq(self, left_generics, right_generics);
                } break;
                #line 250 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 253 "src/analyzer/Root.pv"
        case TYPE__ENUM: {
            #line 253 "src/analyzer/Root.pv"
            struct Enum* left_enum = left->enum_value._0;
            #line 253 "src/analyzer/Root.pv"
            struct GenericMap* left_generics = left->enum_value._1;
            #line 254 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 255 "src/analyzer/Root.pv"
                case TYPE__ENUM: {
                    #line 255 "src/analyzer/Root.pv"
                    struct Enum* right_enum = right->enum_value._0;
                    #line 255 "src/analyzer/Root.pv"
                    struct GenericMap* right_generics = right->enum_value._1;
                    #line 256 "src/analyzer/Root.pv"
                    if (left_enum != right_enum) {
                        #line 256 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 257 "src/analyzer/Root.pv"
                    return Root__type_impl_generics_eq(self, left_generics, right_generics);
                } break;
                #line 259 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 262 "src/analyzer/Root.pv"
        case TYPE__TRAIT: {
            #line 262 "src/analyzer/Root.pv"
            struct Trait* left_trait = left->trait_value._0;
            #line 262 "src/analyzer/Root.pv"
            struct GenericMap* left_generics = left->trait_value._1;
            #line 263 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 264 "src/analyzer/Root.pv"
                case TYPE__TRAIT: {
                    #line 264 "src/analyzer/Root.pv"
                    struct Trait* right_trait = right->trait_value._0;
                    #line 264 "src/analyzer/Root.pv"
                    struct GenericMap* right_generics = right->trait_value._1;
                    #line 265 "src/analyzer/Root.pv"
                    if (left_trait != right_trait) {
                        #line 265 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 266 "src/analyzer/Root.pv"
                    return Root__type_impl_generics_eq(self, left_generics, right_generics);
                } break;
                #line 268 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 271 "src/analyzer/Root.pv"
        case TYPE__TUPLE: {
            #line 271 "src/analyzer/Root.pv"
            struct Tuple* left_tuple = left->tuple_value;
            #line 272 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 273 "src/analyzer/Root.pv"
                case TYPE__TUPLE: {
                    #line 273 "src/analyzer/Root.pv"
                    struct Tuple* right_tuple = right->tuple_value;
                    #line 274 "src/analyzer/Root.pv"
                    if (left_tuple->elements.length != right_tuple->elements.length) {
                        #line 274 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 275 "src/analyzer/Root.pv"
                    uintptr_t i = 0;
                    #line 276 "src/analyzer/Root.pv"
                    while (i < left_tuple->elements.length) {
                        #line 277 "src/analyzer/Root.pv"
                        if (!Root__type_impl_target_eq(self, &left_tuple->elements.data[i], &right_tuple->elements.data[i])) {
                            #line 277 "src/analyzer/Root.pv"
                            return false;
                        }
                        #line 278 "src/analyzer/Root.pv"
                        i += 1;
                    }
                    #line 280 "src/analyzer/Root.pv"
                    return true;
                } break;
                #line 282 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 285 "src/analyzer/Root.pv"
        case TYPE__TYPEDEF_C: {
            #line 285 "src/analyzer/Root.pv"
            struct TypedefC* left_typedef = left->typedefc_value;
            #line 286 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 287 "src/analyzer/Root.pv"
                case TYPE__TYPEDEF_C: {
                    #line 287 "src/analyzer/Root.pv"
                    struct TypedefC* right_typedef = right->typedefc_value;
                    #line 287 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(&left_typedef->name, right_typedef->name);
                } break;
                #line 288 "src/analyzer/Root.pv"
                default: {
                    #line 288 "src/analyzer/Root.pv"
                    return Root__type_impl_target_eq(self, left_typedef->type, right);
                } break;
            }
        } break;
        #line 291 "src/analyzer/Root.pv"
        case TYPE__ENUM_C: {
            #line 291 "src/analyzer/Root.pv"
            struct EnumC* left_enum = left->enumc_value;
            #line 292 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 293 "src/analyzer/Root.pv"
                case TYPE__ENUM_C: {
                    #line 293 "src/analyzer/Root.pv"
                    struct EnumC* right_enum = right->enumc_value;
                    #line 293 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(&left_enum->name, right_enum->name);
                } break;
                #line 294 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 297 "src/analyzer/Root.pv"
        case TYPE__STRUCT_C: {
            #line 297 "src/analyzer/Root.pv"
            struct StructC* left_struct = left->structc_value;
            #line 298 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 299 "src/analyzer/Root.pv"
                case TYPE__STRUCT_C: {
                    #line 299 "src/analyzer/Root.pv"
                    struct StructC* right_struct = right->structc_value;
                    #line 299 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(&left_struct->name, right_struct->name);
                } break;
                #line 300 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 303 "src/analyzer/Root.pv"
        case TYPE__UNION_C: {
            #line 303 "src/analyzer/Root.pv"
            struct StructC* left_union = left->unionc_value;
            #line 304 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 305 "src/analyzer/Root.pv"
                case TYPE__UNION_C: {
                    #line 305 "src/analyzer/Root.pv"
                    struct StructC* right_union = right->unionc_value;
                    #line 305 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(&left_union->name, right_union->name);
                } break;
                #line 306 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 309 "src/analyzer/Root.pv"
        default: {
        } break;
    }

    #line 312 "src/analyzer/Root.pv"
    return false;
}

#line 315 "src/analyzer/Root.pv"
bool Root__type_impl_generics_eq(struct Root* self, struct GenericMap* left, struct GenericMap* right) {
    #line 316 "src/analyzer/Root.pv"
    if (left == 0 || right == 0) {
        #line 316 "src/analyzer/Root.pv"
        return left == right;
    }
    #line 317 "src/analyzer/Root.pv"
    if (left->array.length != right->array.length) {
        #line 317 "src/analyzer/Root.pv"
        return false;
    }
    #line 318 "src/analyzer/Root.pv"
    uintptr_t i = 0;
    #line 319 "src/analyzer/Root.pv"
    while (i < left->array.length) {
        #line 320 "src/analyzer/Root.pv"
        if (!Root__type_impl_target_eq(self, &left->array.data[i], &right->array.data[i])) {
            #line 320 "src/analyzer/Root.pv"
            return false;
        }
        #line 321 "src/analyzer/Root.pv"
        i += 1;
    }
    #line 323 "src/analyzer/Root.pv"
    return true;
}

#line 326 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path) {
    #line 327 "src/analyzer/Root.pv"
    struct Namespace* child = Namespace__new(self, 0, name, path);

    #line 329 "src/analyzer/Root.pv"
    if (HashMap_str_ref_Namespace__find(&self->children, &name) != 0) {
        #line 330 "src/analyzer/Root.pv"
        uint32_t name_length = name.length;
        #line 331 "src/analyzer/Root.pv"
        fprintf(stderr, "Duplicate namespace %.*s\n", name_length, name.ptr);

        #line 333 "src/analyzer/Root.pv"
        return false;
    }

    #line 336 "src/analyzer/Root.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 337 "src/analyzer/Root.pv"
    return true;
}

#line 340 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name) {
    #line 341 "src/analyzer/Root.pv"
    struct Namespace** result = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 342 "src/analyzer/Root.pv"
    if (result == 0) {
        #line 342 "src/analyzer/Root.pv"
        return 0;
    }

    #line 344 "src/analyzer/Root.pv"
    return *result;
}

#line 347 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self) {
    #line 348 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 348 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 348 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 349 "src/analyzer/Root.pv"
        Namespace__add_use_namespaces(child);
    } }

    #line 352 "src/analyzer/Root.pv"
    return true;
}

#line 355 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self) {
    #line 356 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 356 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 356 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 357 "src/analyzer/Root.pv"
        Namespace__fill_namespace(child);
    } }

    #line 360 "src/analyzer/Root.pv"
    return true;
}

#line 363 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self) {
    #line 364 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 364 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 364 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 365 "src/analyzer/Root.pv"
        Namespace__prefill_types(child);
    } }

    #line 368 "src/analyzer/Root.pv"
    return true;
}

#line 371 "src/analyzer/Root.pv"
bool Root__prefill_types_impl(struct Root* self) {
    #line 372 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 372 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 372 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 373 "src/analyzer/Root.pv"
        Namespace__prefill_types_impl(child);
    } }

    #line 376 "src/analyzer/Root.pv"
    return true;
}

#line 379 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self) {
    #line 380 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 380 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 380 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 381 "src/analyzer/Root.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&primitive_info->impls));
        #line 381 "src/analyzer/Root.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 381 "src/analyzer/Root.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 381 "src/analyzer/Root.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 382 "src/analyzer/Root.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__PRIMITIVE, .primitive_value = { ._0 = primitive_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 383 "src/analyzer/Root.pv"
            Impl__fill_types(impl_info, parent);

            #line 385 "src/analyzer/Root.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 385 "src/analyzer/Root.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 385 "src/analyzer/Root.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 386 "src/analyzer/Root.pv"
                Function__fill_types(func_info, &impl_info->generics);
            } }
        } }
    } }

    #line 391 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 391 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 391 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 392 "src/analyzer/Root.pv"
        Namespace__parse_declarations(child);
    } }

    #line 395 "src/analyzer/Root.pv"
    return true;
}

#line 398 "src/analyzer/Root.pv"
bool Root__parse_globals(struct Root* self) {
    #line 399 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 399 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 399 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 400 "src/analyzer/Root.pv"
        Namespace__parse_globals(child);
    } }

    #line 403 "src/analyzer/Root.pv"
    return true;
}

#line 406 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self) {
    #line 407 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 407 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 407 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 408 "src/analyzer/Root.pv"
        Namespace__parse_functions(child);
    } }

    #line 411 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 411 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 411 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 412 "src/analyzer/Root.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 412 "src/analyzer/Root.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 412 "src/analyzer/Root.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 413 "src/analyzer/Root.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 417 "src/analyzer/Root.pv"
    return true;
}

#line 420 "src/analyzer/Root.pv"
bool Root__parse_functions_if_path(struct Root* self, struct str path) {
    #line 421 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 421 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 421 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 422 "src/analyzer/Root.pv"
        Namespace__parse_functions_if_path(child, path);
    } }

    #line 425 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 425 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 425 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 426 "src/analyzer/Root.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 426 "src/analyzer/Root.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 426 "src/analyzer/Root.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 427 "src/analyzer/Root.pv"
            if (str__Eq_str__eq(&impl_info->context->path, path)) {
                #line 428 "src/analyzer/Root.pv"
                Impl__parse_functions(impl_info);
            }
        } }
    } }

    #line 433 "src/analyzer/Root.pv"
    return true;
}

#line 436 "src/analyzer/Root.pv"
struct Module* Root__find_module_by_path(struct Root* self, struct str path) {
    #line 437 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 437 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 437 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 438 "src/analyzer/Root.pv"
        struct Module* result = Namespace__find_module_by_path(child, path);
        #line 439 "src/analyzer/Root.pv"
        if (result != 0) {
            #line 439 "src/analyzer/Root.pv"
            return result;
        }
    } }
    #line 441 "src/analyzer/Root.pv"
    return 0;
}

#line 444 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name, uintptr_t arity) {
    #line 445 "src/analyzer/Root.pv"
    struct Array_Type* arr = HashMap_str_Array_Type__find(&self->types, &name);
    #line 446 "src/analyzer/Root.pv"
    if (arr == 0) {
        #line 446 "src/analyzer/Root.pv"
        return 0;
    }
    #line 447 "src/analyzer/Root.pv"
    uintptr_t i = 0;
    #line 448 "src/analyzer/Root.pv"
    while (i < arr->length) {
        #line 449 "src/analyzer/Root.pv"
        if (Type__get_arity(&arr->data[i]) == arity) {
            #line 449 "src/analyzer/Root.pv"
            return &arr->data[i];
        }
        #line 450 "src/analyzer/Root.pv"
        i += 1;
    }
    #line 452 "src/analyzer/Root.pv"
    return 0;
}

#line 455 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name, uintptr_t arity) {
    #line 456 "src/analyzer/Root.pv"
    struct Array_ref_Trait* arr = HashMap_str_Array_ref_Trait__find(&self->traits, &name);
    #line 457 "src/analyzer/Root.pv"
    if (arr == 0) {
        #line 457 "src/analyzer/Root.pv"
        return 0;
    }
    #line 458 "src/analyzer/Root.pv"
    uintptr_t i = 0;
    #line 459 "src/analyzer/Root.pv"
    while (i < arr->length) {
        #line 460 "src/analyzer/Root.pv"
        struct Trait* trait_info = arr->data[i];
        #line 461 "src/analyzer/Root.pv"
        if (trait_info->generic_arity == arity) {
            #line 461 "src/analyzer/Root.pv"
            return trait_info;
        }
        #line 462 "src/analyzer/Root.pv"
        i += 1;
    }
    #line 464 "src/analyzer/Root.pv"
    return 0;
}

#line 467 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name) {
    #line 468 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}

#line 471 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, struct str name) {
    #line 472 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__find(&self->primitives, &name);
}

#line 475 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message) {
    #line 476 "src/analyzer/Root.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 477 "src/analyzer/Root.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &path);

    #line 479 "src/analyzer/Root.pv"
    struct Diagnostic diagnostic = (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
        .code = (struct str) { .ptr = 0, .length = 0 },
        .range = (struct Range) {
            .start = (struct Position) {
                .line = start_line,
                .character = start_column,
            },
            .end = (struct Position) {
                .line = end_line,
                .character = end_column,
            },
        },
    };

    #line 494 "src/analyzer/Root.pv"
    if (file_diagnostics == 0) {
        #line 495 "src/analyzer/Root.pv"
        Array_Diagnostic__append(HashMap_str_Array_Diagnostic__insert(diagnostics, path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator })), diagnostic);
        #line 496 "src/analyzer/Root.pv"
        return;
    }

    #line 499 "src/analyzer/Root.pv"
    Array_Diagnostic__append(file_diagnostics, diagnostic);
}

#line 502 "src/analyzer/Root.pv"
struct Type* Root__make_type_usage(struct Root* self, struct Type* type, struct Array_Type* usage_types) {
    #line 503 "src/analyzer/Root.pv"
    if (type == 0) {
        #line 503 "src/analyzer/Root.pv"
        return 0;
    }
    #line 504 "src/analyzer/Root.pv"
    struct ArenaAllocator* allocator = self->allocator;

    #line 506 "src/analyzer/Root.pv"
    switch (type->type) {
        #line 507 "src/analyzer/Root.pv"
        case TYPE__ENUM: {
            #line 507 "src/analyzer/Root.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 508 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &enum_info->generics, usage_types);
            #line 509 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 510 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 511 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 512 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 514 "src/analyzer/Root.pv"
        case TYPE__STRUCT: {
            #line 514 "src/analyzer/Root.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 515 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &struct_info->generics, usage_types);
            #line 516 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 517 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 518 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 519 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 521 "src/analyzer/Root.pv"
        case TYPE__TRAIT: {
            #line 521 "src/analyzer/Root.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 522 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &trait_info->generics, usage_types);
            #line 523 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 524 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 525 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 526 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 528 "src/analyzer/Root.pv"
        case TYPE__FUNCTION: {
            #line 528 "src/analyzer/Root.pv"
            struct Function* function_info = type->function_value._0;
            #line 529 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &function_info->generics, usage_types);
            #line 530 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 531 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 532 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 533 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 535 "src/analyzer/Root.pv"
        default: {
            #line 535 "src/analyzer/Root.pv"
            return type;
        } break;
    }
}
