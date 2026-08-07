#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <stdio.h>
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
#include <std/HashMapIter_str_ref_Primitive.h>
#include <tuple_str_ref_Primitive.h>
#include <std/Iter_ref_ptrc_char.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <analyzer/Namespace.h>
#include <i32.h>
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
#include <usize.h>
#include <std/Array_ref_Trait.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>
#include <analyzer/Position.h>
#include <analyzer/Root.h>

#include <analyzer/Root.h>

#line 40 "src/analyzer/Root.pv"
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Analysis* analysis) {
    #line 41 "src/analyzer/Root.pv"
    struct Root* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Root));

    #line 43 "src/analyzer/Root.pv"
    *self = (struct Root) {
        .allocator = allocator,
        .children = HashMap_str_ref_Namespace__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitives = HashMap_str_ref_Primitive__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .ctypes = HashMap_str_TypedefC__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .clang_args = Array_ptrc_char__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .c_std_arg = 0,
        .cpp_std_arg = 0,
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

    #line 74 "src/analyzer/Root.pv"
    self->primitive_bool = Root__add_primitive(self, "bool");
    #line 75 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i8");
    #line 76 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i16");
    #line 77 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i32");
    #line 78 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i64");
    #line 79 "src/analyzer/Root.pv"
    Root__add_primitive(self, "isize");
    #line 80 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u8");
    #line 81 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u16");
    #line 82 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u32");
    #line 83 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u64");
    #line 84 "src/analyzer/Root.pv"
    self->primitive_usize = Root__add_primitive(self, "usize");
    #line 85 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f32");
    #line 86 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f64");
    #line 87 "src/analyzer/Root.pv"
    Root__add_primitive(self, "char");
    #line 88 "src/analyzer/Root.pv"
    self->primitive_void = Root__add_primitive(self, "void");
    #line 89 "src/analyzer/Root.pv"
    self->type_void = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_void };
    #line 90 "src/analyzer/Root.pv"
    self->type_bool = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool };
    #line 91 "src/analyzer/Root.pv"
    struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "unknown", .length = strlen("unknown") }, .generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 } }});
    #line 92 "src/analyzer/Root.pv"
    self->type_unknown = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
    #line 93 "src/analyzer/Root.pv"
    self->type_self = (struct Type) { .type = TYPE__SELF };
    #line 94 "src/analyzer/Root.pv"
    self->type_ref_self = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, self->type_self) };
    #line 95 "src/analyzer/Root.pv"
    self->type_usize = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_usize };
    #line 96 "src/analyzer/Root.pv"
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
    #line 112 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_next.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "self", .length = strlen("self") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .type = self->type_ref_self });

    #line 114 "src/analyzer/Root.pv"
    self->func_value = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .variadic = false,
        .typed_variadic = false,
        .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "value", .length = strlen("value") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}),
        .parameters = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = ArenaAllocator__store_Generic(allocator, (struct Generic[]){(struct Generic) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .traits = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .const_type = 0 }}) },
        .context = 0,
        .declaration_start = 0,
        .declaration_end = 0,
        .token_start = 0,
        .token_end = 0,
        .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE },
        .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } },
        .body = 0,
    };
    #line 130 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_value.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "self", .length = strlen("self") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .type = self->type_ref_self });

    #line 132 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Primitive __iter = HashMap_str_ref_Primitive__iter(&self->primitives);
    #line 132 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Primitive__next(&__iter)) {
        #line 132 "src/analyzer/Root.pv"
        struct str key = HashMapIter_str_ref_Primitive__value(&__iter)->_0;
        #line 132 "src/analyzer/Root.pv"
        struct Primitive* value = HashMapIter_str_ref_Primitive__value(&__iter)->_1;

        #line 133 "src/analyzer/Root.pv"
        struct Array_Type arr = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 134 "src/analyzer/Root.pv"
        Array_Type__append(&arr, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = value });
        #line 135 "src/analyzer/Root.pv"
        HashMap_str_Array_Type__insert(&self->types, key, arr);
    } }

    #line 138 "src/analyzer/Root.pv"
    bool in_clang_args = false;
    #line 139 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(args);
    #line 139 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 139 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 140 "src/analyzer/Root.pv"
        struct str arg_str = (struct str){ .ptr = arg, .length = strlen(arg) };

        #line 142 "src/analyzer/Root.pv"
        if (str__Eq_str__eq(arg_str, (struct str){ .ptr = "--", .length = strlen("--") })) {
            #line 143 "src/analyzer/Root.pv"
            in_clang_args = true;
            #line 144 "src/analyzer/Root.pv"
            continue;
        }

        #line 147 "src/analyzer/Root.pv"
        if (in_clang_args || str__starts_with(arg_str, (struct str){ .ptr = "-std=", .length = strlen("-std=") }) || str__starts_with(arg_str, (struct str){ .ptr = "-I", .length = strlen("-I") })) {
            #line 148 "src/analyzer/Root.pv"
            Root__add_clang_arg(self, arg);
            #line 149 "src/analyzer/Root.pv"
            continue;
        }

        #line 152 "src/analyzer/Root.pv"
        if (str__starts_with(arg_str, (struct str){ .ptr = "-", .length = strlen("-") })) {
            #line 152 "src/analyzer/Root.pv"
            continue;
        }

        #line 154 "src/analyzer/Root.pv"
        char const* pos = strchr(arg, '=');

        #line 156 "src/analyzer/Root.pv"
        if (pos == 0) {
            #line 157 "src/analyzer/Root.pv"
            fprintf(stderr, "Unknown arg \"%s\"\n", arg);
        } else {
            #line 159 "src/analyzer/Root.pv"
            struct str name = str__slice(arg_str, 0, pos - arg);
            #line 160 "src/analyzer/Root.pv"
            char const* path = pos + 1;

            #line 162 "src/analyzer/Root.pv"
            Root__add_namespace(self, name, (struct str){ .ptr = path, .length = strlen(path) });
        }
    } }

    #line 166 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 166 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 166 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 167 "src/analyzer/Root.pv"
        Namespace__parse(child);
    } }

    #line 170 "src/analyzer/Root.pv"
    return self;
}

#line 173 "src/analyzer/Root.pv"
void Root__add_clang_arg(struct Root* self, char const* arg) {
    #line 174 "src/analyzer/Root.pv"
    if (i32__Eq_i32__eq(strncmp(arg, "-std=c++", 8), 0) || i32__Eq_i32__eq(strncmp(arg, "-std=gnu++", 10), 0)) {
        #line 175 "src/analyzer/Root.pv"
        self->cpp_std_arg = arg;
    } else if (i32__Eq_i32__eq(strncmp(arg, "-std=", 5), 0)) {
        #line 177 "src/analyzer/Root.pv"
        self->c_std_arg = arg;
    } else {
        #line 179 "src/analyzer/Root.pv"
        Array_ptrc_char__append(&self->clang_args, arg);
    }
}

#line 183 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name) {
    #line 184 "src/analyzer/Root.pv"
    struct Primitive* primitive = ArenaAllocator__store_Primitive(self->allocator, (struct Primitive[]){Primitive__new(self->allocator, name)});
    #line 185 "src/analyzer/Root.pv"
    HashMap_str_ref_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, primitive);
    #line 186 "src/analyzer/Root.pv"
    return primitive;
}

#line 189 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name) {
    #line 190 "src/analyzer/Root.pv"
    struct Primitive** existing = HashMap_str_ref_Primitive__find(&self->primitives, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 191 "src/analyzer/Root.pv"
    if (existing != 0) {
        #line 191 "src/analyzer/Root.pv"
        return *existing;
    }

    #line 193 "src/analyzer/Root.pv"
    struct Primitive* primitive = ArenaAllocator__store_Primitive(self->allocator, (struct Primitive[]){Primitive__new(self->allocator, name)});
    #line 194 "src/analyzer/Root.pv"
    HashMap_str_ref_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, primitive);
    #line 195 "src/analyzer/Root.pv"
    return primitive;
}

#line 198 "src/analyzer/Root.pv"
uintptr_t Root__add_type_impl(struct Root* self, struct Type type, struct Impl* impl_info) {
    #line 199 "src/analyzer/Root.pv"
    uintptr_t index = self->type_impls.length;
    #line 200 "src/analyzer/Root.pv"
    Array_TypeImpl__append(&self->type_impls, TypeImpl__new(self->allocator, type, impl_info, index));
    #line 201 "src/analyzer/Root.pv"
    return index;
}

#line 204 "src/analyzer/Root.pv"
struct TypeImpl* Root__get_type_impl(struct Root* self, struct Type* type, uintptr_t impl_index) {
    #line 205 "src/analyzer/Root.pv"
    struct TypeImpl* type_impl = Array_TypeImpl__get(&self->type_impls, impl_index);
    #line 206 "src/analyzer/Root.pv"
    if (type_impl == 0) {
        #line 206 "src/analyzer/Root.pv"
        return 0;
    }
    #line 207 "src/analyzer/Root.pv"
    if (Root__type_impl_target_eq(self, &type_impl->type, type)) {
        #line 207 "src/analyzer/Root.pv"
        return type_impl;
    }

    #line 209 "src/analyzer/Root.pv"
    return 0;
}

#line 212 "src/analyzer/Root.pv"
struct Function* Root__find_type_impl_function(struct Root* self, struct Type* type, struct str name, struct GenericMap* generic_map) {
    #line 213 "src/analyzer/Root.pv"
    { struct IterEnumerate_ref_TypeImpl __iter = Iter_ref_TypeImpl__enumerate(Array_TypeImpl__iter(&self->type_impls));
    #line 213 "src/analyzer/Root.pv"
    while (IterEnumerate_ref_TypeImpl__next(&__iter)) {
        #line 213 "src/analyzer/Root.pv"
        uintptr_t impl_index = IterEnumerate_ref_TypeImpl__value(&__iter)._0;
        #line 213 "src/analyzer/Root.pv"
        struct TypeImpl type_impl = *IterEnumerate_ref_TypeImpl__value(&__iter)._1;

        #line 214 "src/analyzer/Root.pv"
        if (type_impl.impl_info->generics.array.length != 0) {
            #line 214 "src/analyzer/Root.pv"
            continue;
        }
        #line 215 "src/analyzer/Root.pv"
        if (!Root__type_impl_target_eq(self, &type_impl.type, type)) {
            #line 215 "src/analyzer/Root.pv"
            continue;
        }

        #line 217 "src/analyzer/Root.pv"
        struct Function* function = Impl__find_function(type_impl.impl_info, name);
        #line 218 "src/analyzer/Root.pv"
        if (function == 0) {
            #line 218 "src/analyzer/Root.pv"
            continue;
        }

        #line 220 "src/analyzer/Root.pv"
        struct Function* stored_func_info = ArenaAllocator__store_Function(self->allocator, function);
        #line 221 "src/analyzer/Root.pv"
        if (stored_func_info == 0) {
            #line 221 "src/analyzer/Root.pv"
            return function;
        }
        #line 222 "src/analyzer/Root.pv"
        stored_func_info->parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl.type, ._1 = impl_index, ._2 = type_impl.impl_info->trait_} };
        #line 223 "src/analyzer/Root.pv"
        return stored_func_info;
    } }

    #line 226 "src/analyzer/Root.pv"
    return 0;
}

#line 229 "src/analyzer/Root.pv"
bool Root__type_impl_target_eq(struct Root* self, struct Type* left, struct Type* right) {
    #line 230 "src/analyzer/Root.pv"
    switch (left->type) {
        #line 231 "src/analyzer/Root.pv"
        case TYPE__PRIMITIVE: {
            #line 231 "src/analyzer/Root.pv"
            struct Primitive* left_primitive = left->primitive_value;
            #line 232 "src/analyzer/Root.pv"
            if (left_primitive == 0) {
                #line 232 "src/analyzer/Root.pv"
                return false;
            }
            #line 233 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 234 "src/analyzer/Root.pv"
                case TYPE__PRIMITIVE: {
                    #line 234 "src/analyzer/Root.pv"
                    struct Primitive* right_primitive = right->primitive_value;
                    #line 235 "src/analyzer/Root.pv"
                    if (right_primitive == 0) {
                        #line 235 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 236 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(left_primitive->name, right_primitive->name);
                } break;
                #line 238 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 241 "src/analyzer/Root.pv"
        case TYPE__INDIRECT: {
            #line 241 "src/analyzer/Root.pv"
            struct Indirect* left_indirect = left->indirect_value;
            #line 242 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 243 "src/analyzer/Root.pv"
                case TYPE__INDIRECT: {
                    #line 243 "src/analyzer/Root.pv"
                    struct Indirect* right_indirect = right->indirect_value;
                    #line 244 "src/analyzer/Root.pv"
                    if (left_indirect->type != right_indirect->type) {
                        #line 244 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 245 "src/analyzer/Root.pv"
                    return Root__type_impl_target_eq(self, &left_indirect->to, &right_indirect->to);
                } break;
                #line 247 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 250 "src/analyzer/Root.pv"
        case TYPE__SEQUENCE: {
            #line 250 "src/analyzer/Root.pv"
            struct Sequence* left_sequence = left->sequence_value;
            #line 251 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 252 "src/analyzer/Root.pv"
                case TYPE__SEQUENCE: {
                    #line 252 "src/analyzer/Root.pv"
                    struct Sequence* right_sequence = right->sequence_value;
                    #line 253 "src/analyzer/Root.pv"
                    switch (left_sequence->type.type) {
                        #line 254 "src/analyzer/Root.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 255 "src/analyzer/Root.pv"
                            switch (right_sequence->type.type) {
                                #line 256 "src/analyzer/Root.pv"
                                case SEQUENCE_TYPE__SLICE: {
                                } break;
                                #line 257 "src/analyzer/Root.pv"
                                default: {
                                    #line 257 "src/analyzer/Root.pv"
                                    return false;
                                } break;
                            }
                        } break;
                        #line 260 "src/analyzer/Root.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 261 "src/analyzer/Root.pv"
                            switch (right_sequence->type.type) {
                                #line 262 "src/analyzer/Root.pv"
                                case SEQUENCE_TYPE__FIXED_ARRAY: {
                                } break;
                                #line 263 "src/analyzer/Root.pv"
                                default: {
                                    #line 263 "src/analyzer/Root.pv"
                                    return false;
                                } break;
                            }
                        } break;
                    }
                    #line 267 "src/analyzer/Root.pv"
                    return Root__type_impl_target_eq(self, &left_sequence->element, &right_sequence->element);
                } break;
                #line 269 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 272 "src/analyzer/Root.pv"
        case TYPE__STRUCT: {
            #line 272 "src/analyzer/Root.pv"
            struct Struct* left_struct = left->struct_value._0;
            #line 272 "src/analyzer/Root.pv"
            struct GenericMap* left_generics = left->struct_value._1;
            #line 273 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 274 "src/analyzer/Root.pv"
                case TYPE__STRUCT: {
                    #line 274 "src/analyzer/Root.pv"
                    struct Struct* right_struct = right->struct_value._0;
                    #line 274 "src/analyzer/Root.pv"
                    struct GenericMap* right_generics = right->struct_value._1;
                    #line 275 "src/analyzer/Root.pv"
                    if (left_struct != right_struct) {
                        #line 275 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 276 "src/analyzer/Root.pv"
                    return Root__type_impl_generics_eq(self, left_generics, right_generics);
                } break;
                #line 278 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 281 "src/analyzer/Root.pv"
        case TYPE__ENUM: {
            #line 281 "src/analyzer/Root.pv"
            struct Enum* left_enum = left->enum_value._0;
            #line 281 "src/analyzer/Root.pv"
            struct GenericMap* left_generics = left->enum_value._1;
            #line 282 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 283 "src/analyzer/Root.pv"
                case TYPE__ENUM: {
                    #line 283 "src/analyzer/Root.pv"
                    struct Enum* right_enum = right->enum_value._0;
                    #line 283 "src/analyzer/Root.pv"
                    struct GenericMap* right_generics = right->enum_value._1;
                    #line 284 "src/analyzer/Root.pv"
                    if (left_enum != right_enum) {
                        #line 284 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 285 "src/analyzer/Root.pv"
                    return Root__type_impl_generics_eq(self, left_generics, right_generics);
                } break;
                #line 287 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 290 "src/analyzer/Root.pv"
        case TYPE__TRAIT: {
            #line 290 "src/analyzer/Root.pv"
            struct Trait* left_trait = left->trait_value._0;
            #line 290 "src/analyzer/Root.pv"
            struct GenericMap* left_generics = left->trait_value._1;
            #line 291 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 292 "src/analyzer/Root.pv"
                case TYPE__TRAIT: {
                    #line 292 "src/analyzer/Root.pv"
                    struct Trait* right_trait = right->trait_value._0;
                    #line 292 "src/analyzer/Root.pv"
                    struct GenericMap* right_generics = right->trait_value._1;
                    #line 293 "src/analyzer/Root.pv"
                    if (left_trait != right_trait) {
                        #line 293 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 294 "src/analyzer/Root.pv"
                    return Root__type_impl_generics_eq(self, left_generics, right_generics);
                } break;
                #line 296 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 299 "src/analyzer/Root.pv"
        case TYPE__TUPLE: {
            #line 299 "src/analyzer/Root.pv"
            struct Tuple* left_tuple = left->tuple_value;
            #line 300 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 301 "src/analyzer/Root.pv"
                case TYPE__TUPLE: {
                    #line 301 "src/analyzer/Root.pv"
                    struct Tuple* right_tuple = right->tuple_value;
                    #line 302 "src/analyzer/Root.pv"
                    if (left_tuple->elements.length != right_tuple->elements.length) {
                        #line 302 "src/analyzer/Root.pv"
                        return false;
                    }
                    #line 303 "src/analyzer/Root.pv"
                    uintptr_t i = 0;
                    #line 304 "src/analyzer/Root.pv"
                    while (i < left_tuple->elements.length) {
                        #line 305 "src/analyzer/Root.pv"
                        if (!Root__type_impl_target_eq(self, &left_tuple->elements.data[i], &right_tuple->elements.data[i])) {
                            #line 305 "src/analyzer/Root.pv"
                            return false;
                        }
                        #line 306 "src/analyzer/Root.pv"
                        i += 1;
                    }
                    #line 308 "src/analyzer/Root.pv"
                    return true;
                } break;
                #line 310 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 313 "src/analyzer/Root.pv"
        case TYPE__TYPEDEF_C: {
            #line 313 "src/analyzer/Root.pv"
            struct TypedefC* left_typedef = left->typedefc_value;
            #line 314 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 315 "src/analyzer/Root.pv"
                case TYPE__TYPEDEF_C: {
                    #line 315 "src/analyzer/Root.pv"
                    struct TypedefC* right_typedef = right->typedefc_value;
                    #line 315 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(left_typedef->name, right_typedef->name);
                } break;
                #line 316 "src/analyzer/Root.pv"
                default: {
                    #line 316 "src/analyzer/Root.pv"
                    return Root__type_impl_target_eq(self, left_typedef->type, right);
                } break;
            }
        } break;
        #line 319 "src/analyzer/Root.pv"
        case TYPE__ENUM_C: {
            #line 319 "src/analyzer/Root.pv"
            struct EnumC* left_enum = left->enumc_value;
            #line 320 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 321 "src/analyzer/Root.pv"
                case TYPE__ENUM_C: {
                    #line 321 "src/analyzer/Root.pv"
                    struct EnumC* right_enum = right->enumc_value;
                    #line 321 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(left_enum->name, right_enum->name);
                } break;
                #line 322 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 325 "src/analyzer/Root.pv"
        case TYPE__STRUCT_C: {
            #line 325 "src/analyzer/Root.pv"
            struct StructC* left_struct = left->structc_value;
            #line 326 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 327 "src/analyzer/Root.pv"
                case TYPE__STRUCT_C: {
                    #line 327 "src/analyzer/Root.pv"
                    struct StructC* right_struct = right->structc_value;
                    #line 327 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(left_struct->name, right_struct->name);
                } break;
                #line 328 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 331 "src/analyzer/Root.pv"
        case TYPE__UNION_C: {
            #line 331 "src/analyzer/Root.pv"
            struct StructC* left_union = left->unionc_value;
            #line 332 "src/analyzer/Root.pv"
            switch (right->type) {
                #line 333 "src/analyzer/Root.pv"
                case TYPE__UNION_C: {
                    #line 333 "src/analyzer/Root.pv"
                    struct StructC* right_union = right->unionc_value;
                    #line 333 "src/analyzer/Root.pv"
                    return str__Eq_str__eq(left_union->name, right_union->name);
                } break;
                #line 334 "src/analyzer/Root.pv"
                default: {
                } break;
            }
        } break;
        #line 337 "src/analyzer/Root.pv"
        default: {
        } break;
    }

    #line 340 "src/analyzer/Root.pv"
    return false;
}

#line 343 "src/analyzer/Root.pv"
bool Root__type_impl_generics_eq(struct Root* self, struct GenericMap* left, struct GenericMap* right) {
    #line 344 "src/analyzer/Root.pv"
    if (left == 0 || right == 0) {
        #line 344 "src/analyzer/Root.pv"
        return left == right;
    }
    #line 345 "src/analyzer/Root.pv"
    if (left->array.length != right->array.length) {
        #line 345 "src/analyzer/Root.pv"
        return false;
    }
    #line 346 "src/analyzer/Root.pv"
    uintptr_t i = 0;
    #line 347 "src/analyzer/Root.pv"
    while (i < left->array.length) {
        #line 348 "src/analyzer/Root.pv"
        if (!Root__type_impl_target_eq(self, &left->array.data[i], &right->array.data[i])) {
            #line 348 "src/analyzer/Root.pv"
            return false;
        }
        #line 349 "src/analyzer/Root.pv"
        i += 1;
    }
    #line 351 "src/analyzer/Root.pv"
    return true;
}

#line 354 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path) {
    #line 355 "src/analyzer/Root.pv"
    struct Namespace* child = Namespace__new(self, 0, name, path);

    #line 357 "src/analyzer/Root.pv"
    if (HashMap_str_ref_Namespace__find(&self->children, &name) != 0) {
        #line 358 "src/analyzer/Root.pv"
        uint32_t name_length = name.length;
        #line 359 "src/analyzer/Root.pv"
        fprintf(stderr, "Duplicate namespace %.*s\n", name_length, name.ptr);

        #line 361 "src/analyzer/Root.pv"
        return false;
    }

    #line 364 "src/analyzer/Root.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 365 "src/analyzer/Root.pv"
    return true;
}

#line 368 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name) {
    #line 369 "src/analyzer/Root.pv"
    struct Namespace** result = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 370 "src/analyzer/Root.pv"
    if (result == 0) {
        #line 370 "src/analyzer/Root.pv"
        return 0;
    }

    #line 372 "src/analyzer/Root.pv"
    return *result;
}

#line 375 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self) {
    #line 376 "src/analyzer/Root.pv"
    bool success = true;

    #line 378 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 378 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 378 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 379 "src/analyzer/Root.pv"
        success = Namespace__add_use_namespaces(child) && success;
    } }

    #line 382 "src/analyzer/Root.pv"
    return success;
}

#line 385 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self) {
    #line 386 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 386 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 386 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 387 "src/analyzer/Root.pv"
        Namespace__fill_namespace(child);
    } }

    #line 390 "src/analyzer/Root.pv"
    return true;
}

#line 393 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self) {
    #line 394 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 394 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 394 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 395 "src/analyzer/Root.pv"
        Namespace__prefill_types(child);
    } }

    #line 398 "src/analyzer/Root.pv"
    return true;
}

#line 401 "src/analyzer/Root.pv"
bool Root__prefill_types_impl(struct Root* self) {
    #line 402 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 402 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 402 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 403 "src/analyzer/Root.pv"
        Namespace__prefill_types_impl(child);
    } }

    #line 406 "src/analyzer/Root.pv"
    return true;
}

#line 409 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self) {
    #line 410 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Primitive __iter = HashMap_str_ref_Primitive__iter(&self->primitives);
    #line 410 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Primitive__next(&__iter)) {
        #line 410 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = HashMapIter_str_ref_Primitive__value(&__iter)->_1;

        #line 411 "src/analyzer/Root.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&primitive_info->impls));
        #line 411 "src/analyzer/Root.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 411 "src/analyzer/Root.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 411 "src/analyzer/Root.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 412 "src/analyzer/Root.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__PRIMITIVE, .primitive_value = { ._0 = primitive_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 413 "src/analyzer/Root.pv"
            Impl__fill_types(impl_info, parent);

            #line 415 "src/analyzer/Root.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 415 "src/analyzer/Root.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 415 "src/analyzer/Root.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 416 "src/analyzer/Root.pv"
                Function__fill_types(func_info, &impl_info->generics);
            } }
        } }
    } }

    #line 421 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 421 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 421 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 422 "src/analyzer/Root.pv"
        Namespace__parse_declarations(child);
    } }

    #line 425 "src/analyzer/Root.pv"
    return true;
}

#line 428 "src/analyzer/Root.pv"
bool Root__parse_globals(struct Root* self) {
    #line 429 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 429 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 429 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 430 "src/analyzer/Root.pv"
        Namespace__parse_globals(child);
    } }

    #line 433 "src/analyzer/Root.pv"
    return true;
}

#line 436 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self) {
    #line 437 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 437 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 437 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 438 "src/analyzer/Root.pv"
        Namespace__parse_functions(child);
    } }

    #line 441 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Primitive __iter = HashMap_str_ref_Primitive__iter(&self->primitives);
    #line 441 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Primitive__next(&__iter)) {
        #line 441 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = HashMapIter_str_ref_Primitive__value(&__iter)->_1;

        #line 442 "src/analyzer/Root.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 442 "src/analyzer/Root.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 442 "src/analyzer/Root.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 443 "src/analyzer/Root.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 447 "src/analyzer/Root.pv"
    return true;
}

#line 450 "src/analyzer/Root.pv"
bool Root__parse_functions_if_path(struct Root* self, struct str path) {
    #line 451 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 451 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 451 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 452 "src/analyzer/Root.pv"
        if (Namespace__parse_functions_if_path(child, path)) {
            #line 452 "src/analyzer/Root.pv"
            return true;
        }
    } }

    #line 455 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Primitive __iter = HashMap_str_ref_Primitive__iter(&self->primitives);
    #line 455 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Primitive__next(&__iter)) {
        #line 455 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = HashMapIter_str_ref_Primitive__value(&__iter)->_1;

        #line 456 "src/analyzer/Root.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 456 "src/analyzer/Root.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 456 "src/analyzer/Root.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 457 "src/analyzer/Root.pv"
            if (str__Eq_str__eq(impl_info->context->path, path)) {
                #line 458 "src/analyzer/Root.pv"
                Impl__parse_functions(impl_info);
                #line 459 "src/analyzer/Root.pv"
                return true;
            }
        } }
    } }

    #line 464 "src/analyzer/Root.pv"
    return false;
}

#line 467 "src/analyzer/Root.pv"
struct Module* Root__find_module_by_path(struct Root* self, struct str path) {
    #line 468 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 468 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 468 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 469 "src/analyzer/Root.pv"
        struct Module* result = Namespace__find_module_by_path(child, path);
        #line 470 "src/analyzer/Root.pv"
        if (result != 0) {
            #line 470 "src/analyzer/Root.pv"
            return result;
        }
    } }
    #line 472 "src/analyzer/Root.pv"
    return 0;
}

#line 475 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name, uintptr_t arity) {
    #line 476 "src/analyzer/Root.pv"
    struct Array_Type* arr = HashMap_str_Array_Type__find(&self->types, &name);
    #line 477 "src/analyzer/Root.pv"
    if (arr == 0) {
        #line 477 "src/analyzer/Root.pv"
        return 0;
    }
    #line 478 "src/analyzer/Root.pv"
    uintptr_t i = 0;
    #line 479 "src/analyzer/Root.pv"
    while (i < arr->length) {
        #line 480 "src/analyzer/Root.pv"
        if (usize__Eq_usize__eq(Type__get_arity(&arr->data[i]), arity)) {
            #line 480 "src/analyzer/Root.pv"
            return &arr->data[i];
        }
        #line 481 "src/analyzer/Root.pv"
        i += 1;
    }
    #line 483 "src/analyzer/Root.pv"
    return 0;
}

#line 486 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name, uintptr_t arity) {
    #line 487 "src/analyzer/Root.pv"
    struct Array_ref_Trait* arr = HashMap_str_Array_ref_Trait__find(&self->traits, &name);
    #line 488 "src/analyzer/Root.pv"
    if (arr == 0) {
        #line 488 "src/analyzer/Root.pv"
        return 0;
    }
    #line 489 "src/analyzer/Root.pv"
    uintptr_t i = 0;
    #line 490 "src/analyzer/Root.pv"
    while (i < arr->length) {
        #line 491 "src/analyzer/Root.pv"
        struct Trait* trait_info = arr->data[i];
        #line 492 "src/analyzer/Root.pv"
        if (usize__Eq_usize__eq(trait_info->generic_arity, arity)) {
            #line 492 "src/analyzer/Root.pv"
            return trait_info;
        }
        #line 493 "src/analyzer/Root.pv"
        i += 1;
    }
    #line 495 "src/analyzer/Root.pv"
    return 0;
}

#line 498 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name) {
    #line 499 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}

#line 502 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, struct str name) {
    #line 503 "src/analyzer/Root.pv"
    struct Primitive** primitive = HashMap_str_ref_Primitive__find(&self->primitives, &name);
    #line 504 "src/analyzer/Root.pv"
    if (primitive == 0) {
        #line 504 "src/analyzer/Root.pv"
        return 0;
    }
    #line 505 "src/analyzer/Root.pv"
    return *primitive;
}

#line 508 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message) {
    #line 509 "src/analyzer/Root.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 510 "src/analyzer/Root.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &path);

    #line 512 "src/analyzer/Root.pv"
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

    #line 527 "src/analyzer/Root.pv"
    if (file_diagnostics == 0) {
        #line 528 "src/analyzer/Root.pv"
        struct Array_Diagnostic* new_file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
        #line 529 "src/analyzer/Root.pv"
        if (new_file_diagnostics == 0) {
            #line 529 "src/analyzer/Root.pv"
            return;
        }
        #line 530 "src/analyzer/Root.pv"
        Array_Diagnostic__append(new_file_diagnostics, diagnostic);
        #line 531 "src/analyzer/Root.pv"
        return;
    }

    #line 534 "src/analyzer/Root.pv"
    Array_Diagnostic__append(file_diagnostics, diagnostic);
}

#line 537 "src/analyzer/Root.pv"
struct Type* Root__make_type_usage(struct Root* self, struct Type* type, struct Array_Type* usage_types) {
    #line 538 "src/analyzer/Root.pv"
    if (type == 0) {
        #line 538 "src/analyzer/Root.pv"
        return 0;
    }
    #line 539 "src/analyzer/Root.pv"
    struct ArenaAllocator* allocator = self->allocator;

    #line 541 "src/analyzer/Root.pv"
    switch (type->type) {
        #line 542 "src/analyzer/Root.pv"
        case TYPE__ENUM: {
            #line 542 "src/analyzer/Root.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 543 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &enum_info->generics, usage_types);
            #line 544 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 545 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 546 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 547 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 549 "src/analyzer/Root.pv"
        case TYPE__STRUCT: {
            #line 549 "src/analyzer/Root.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 550 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &struct_info->generics, usage_types);
            #line 551 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 552 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 553 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 554 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 556 "src/analyzer/Root.pv"
        case TYPE__TRAIT: {
            #line 556 "src/analyzer/Root.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 557 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &trait_info->generics, usage_types);
            #line 558 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 559 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 560 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 561 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 563 "src/analyzer/Root.pv"
        case TYPE__FUNCTION: {
            #line 563 "src/analyzer/Root.pv"
            struct Function* function_info = type->function_value._0;
            #line 564 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &function_info->generics, usage_types);
            #line 565 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 566 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 567 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 568 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 570 "src/analyzer/Root.pv"
        default: {
            #line 570 "src/analyzer/Root.pv"
            return type;
        } break;
    }
}
