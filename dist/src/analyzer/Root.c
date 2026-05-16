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
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <analyzer/types/Trait.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>
#include <analyzer/Position.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Struct.h>
#include <analyzer/Root.h>

#include <analyzer/Root.h>

#line 37 "src/analyzer/Root.pv"
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Array_ptrc_char* clang_args, struct Analysis* analysis) {
    #line 38 "src/analyzer/Root.pv"
    struct Root* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Root));

    #line 40 "src/analyzer/Root.pv"
    *self = (struct Root) {
        .allocator = allocator,
        .children = HashMap_str_ref_Namespace__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitives = HashMap_str_Primitive__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .ctypes = HashMap_str_TypedefC__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
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
        .func_next = (struct Function) { .name = 0, .context = 0, .declaration_start = 0, .declaration_end = 0, .token_start = 0, .token_end = 0, .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE }, .type = FUNCTION_TYPE__STANDARD, .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }, .parameters = (struct Array_Parameter) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 }, .body = 0 },
        .func_value = (struct Function) { .name = 0, .context = 0, .declaration_start = 0, .declaration_end = 0, .token_start = 0, .token_end = 0, .parent = (struct FunctionParent) { .type = FUNCTION_PARENT__NONE }, .type = FUNCTION_TYPE__STANDARD, .generics = (struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }, .parameters = (struct Array_Parameter) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 }, .body = 0 },
        .hack_type_impl = 0,
        .mode_cpp = false,
    };

    #line 68 "src/analyzer/Root.pv"
    self->primitive_bool = Root__add_primitive(self, "bool");
    #line 69 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i8");
    #line 70 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i16");
    #line 71 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i32");
    #line 72 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i64");
    #line 73 "src/analyzer/Root.pv"
    Root__add_primitive(self, "isize");
    #line 74 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u8");
    #line 75 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u16");
    #line 76 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u32");
    #line 77 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u64");
    #line 78 "src/analyzer/Root.pv"
    self->primitive_usize = Root__add_primitive(self, "usize");
    #line 79 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f32");
    #line 80 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f64");
    #line 81 "src/analyzer/Root.pv"
    Root__add_primitive(self, "char");
    #line 82 "src/analyzer/Root.pv"
    self->primitive_void = Root__add_primitive(self, "void");
    #line 83 "src/analyzer/Root.pv"
    self->type_void = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_void };
    #line 84 "src/analyzer/Root.pv"
    self->type_bool = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool };
    #line 85 "src/analyzer/Root.pv"
    struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(allocator, (struct UnknownC[]){(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "unknown", .length = strlen("unknown") }, .generics = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 } }});
    #line 86 "src/analyzer/Root.pv"
    self->type_unknown = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
    #line 87 "src/analyzer/Root.pv"
    self->type_self = (struct Type) { .type = TYPE__SELF };
    #line 88 "src/analyzer/Root.pv"
    self->type_ref_self = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, self->type_self) };
    #line 89 "src/analyzer/Root.pv"
    self->type_usize = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_usize };
    #line 90 "src/analyzer/Root.pv"
    self->func_next = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
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
    #line 104 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_next.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "self", .length = strlen("self") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .type = self->type_ref_self });

    #line 106 "src/analyzer/Root.pv"
    self->func_value = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
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
    #line 120 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_value.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__IDENTIFIER, .value = (struct str){ .ptr = "self", .length = strlen("self") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }}), .type = self->type_ref_self });

    #line 122 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 122 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 122 "src/analyzer/Root.pv"
        struct str key = HashMapIter_str_Primitive__value(&__iter)->_0;
        #line 122 "src/analyzer/Root.pv"
        struct Primitive* value = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 123 "src/analyzer/Root.pv"
        HashMap_str_Type__insert(&self->types, key, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = value });
    } }

    #line 126 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(args);
    #line 126 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 126 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 127 "src/analyzer/Root.pv"
        char const* pos = strchr(arg, '=');

        #line 129 "src/analyzer/Root.pv"
        if (pos == 0) {
            #line 130 "src/analyzer/Root.pv"
            fprintf(stderr, "Unknown arg \"%s\"\n", arg);
        } else {
            #line 132 "src/analyzer/Root.pv"
            struct str arg_str = (struct str){ .ptr = arg, .length = strlen(arg) };
            #line 133 "src/analyzer/Root.pv"
            struct str name = str__slice(arg_str, 0, pos - arg);
            #line 134 "src/analyzer/Root.pv"
            char const* path = pos + 1;

            #line 136 "src/analyzer/Root.pv"
            Root__add_namespace(self, name, (struct str){ .ptr = path, .length = strlen(path) });
        }
    } }

    #line 140 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(clang_args);
    #line 140 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 140 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 141 "src/analyzer/Root.pv"
        Array_ptrc_char__append(&self->clang_args, arg);
    } }

    #line 144 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 144 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 144 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 145 "src/analyzer/Root.pv"
        Namespace__parse(child);
    } }

    #line 148 "src/analyzer/Root.pv"
    return self;
}

#line 151 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name) {
    #line 152 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 155 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name) {
    #line 156 "src/analyzer/Root.pv"
    struct Primitive* existing = HashMap_str_Primitive__find(&self->primitives, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 157 "src/analyzer/Root.pv"
    if (existing != 0) {
        #line 157 "src/analyzer/Root.pv"
        return existing;
    }

    #line 159 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 162 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path) {
    #line 163 "src/analyzer/Root.pv"
    struct Namespace* child = Namespace__new(self, 0, name, path);

    #line 165 "src/analyzer/Root.pv"
    if (HashMap_str_ref_Namespace__find(&self->children, &name) != 0) {
        #line 166 "src/analyzer/Root.pv"
        uint32_t name_length = name.length;
        #line 167 "src/analyzer/Root.pv"
        fprintf(stderr, "Duplicate namespace %.*s\n", name_length, name.ptr);

        #line 169 "src/analyzer/Root.pv"
        return false;
    }

    #line 172 "src/analyzer/Root.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 173 "src/analyzer/Root.pv"
    return true;
}

#line 176 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name) {
    #line 177 "src/analyzer/Root.pv"
    struct Namespace** result = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 178 "src/analyzer/Root.pv"
    if (result == 0) {
        #line 178 "src/analyzer/Root.pv"
        return 0;
    }

    #line 180 "src/analyzer/Root.pv"
    return *result;
}

#line 183 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self) {
    #line 184 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 184 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 184 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 185 "src/analyzer/Root.pv"
        Namespace__add_use_namespaces(child);
    } }

    #line 188 "src/analyzer/Root.pv"
    return true;
}

#line 191 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self) {
    #line 192 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 192 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 192 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 193 "src/analyzer/Root.pv"
        Namespace__fill_namespace(child);
    } }

    #line 196 "src/analyzer/Root.pv"
    return true;
}

#line 199 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self) {
    #line 200 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 200 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 200 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 201 "src/analyzer/Root.pv"
        Namespace__prefill_types(child);
    } }

    #line 204 "src/analyzer/Root.pv"
    return true;
}

#line 207 "src/analyzer/Root.pv"
bool Root__prefill_types_impl(struct Root* self) {
    #line 208 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 208 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 208 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 209 "src/analyzer/Root.pv"
        Namespace__prefill_types_impl(child);
    } }

    #line 212 "src/analyzer/Root.pv"
    return true;
}

#line 215 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self) {
    #line 216 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 216 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 216 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 217 "src/analyzer/Root.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&primitive_info->impls));
        #line 217 "src/analyzer/Root.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 217 "src/analyzer/Root.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 217 "src/analyzer/Root.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 218 "src/analyzer/Root.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__PRIMITIVE, .primitive_value = { ._0 = primitive_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 219 "src/analyzer/Root.pv"
            Impl__fill_types(impl_info, parent);

            #line 221 "src/analyzer/Root.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 221 "src/analyzer/Root.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 221 "src/analyzer/Root.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 222 "src/analyzer/Root.pv"
                Function__fill_types(func_info, &impl_info->generics);
            } }
        } }
    } }

    #line 227 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 227 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 227 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 228 "src/analyzer/Root.pv"
        Namespace__parse_declarations(child);
    } }

    #line 231 "src/analyzer/Root.pv"
    return true;
}

#line 234 "src/analyzer/Root.pv"
bool Root__parse_globals(struct Root* self) {
    #line 235 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 235 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 235 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 236 "src/analyzer/Root.pv"
        Namespace__parse_globals(child);
    } }

    #line 239 "src/analyzer/Root.pv"
    return true;
}

#line 242 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self) {
    #line 243 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 243 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 243 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 244 "src/analyzer/Root.pv"
        Namespace__parse_functions(child);
    } }

    #line 247 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 247 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 247 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 248 "src/analyzer/Root.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 248 "src/analyzer/Root.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 248 "src/analyzer/Root.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 249 "src/analyzer/Root.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 253 "src/analyzer/Root.pv"
    return true;
}

#line 256 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name) {
    #line 257 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->types, &name);
}

#line 260 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name) {
    #line 261 "src/analyzer/Root.pv"
    struct Trait** trait_info = HashMap_str_ref_Trait__find(&self->traits, &name);
    #line 262 "src/analyzer/Root.pv"
    if (trait_info == 0) {
        #line 262 "src/analyzer/Root.pv"
        return 0;
    }
    #line 263 "src/analyzer/Root.pv"
    return *trait_info;
}

#line 266 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name) {
    #line 267 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}

#line 270 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, struct str name) {
    #line 271 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__find(&self->primitives, &name);
}

#line 274 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message) {
    #line 275 "src/analyzer/Root.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 276 "src/analyzer/Root.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &path);
    #line 277 "src/analyzer/Root.pv"
    if (file_diagnostics == 0) {
        #line 277 "src/analyzer/Root.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 279 "src/analyzer/Root.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
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
    });
}

#line 295 "src/analyzer/Root.pv"
struct Type* Root__make_type_usage(struct Root* self, struct Type* type, struct Array_Type* usage_types) {
    #line 296 "src/analyzer/Root.pv"
    if (type == 0) {
        #line 296 "src/analyzer/Root.pv"
        return 0;
    }
    #line 297 "src/analyzer/Root.pv"
    struct ArenaAllocator* allocator = self->allocator;

    #line 299 "src/analyzer/Root.pv"
    switch (type->type) {
        #line 300 "src/analyzer/Root.pv"
        case TYPE__ENUM: {
            #line 300 "src/analyzer/Root.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 301 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &enum_info->generics, usage_types);
            #line 302 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 303 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 304 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 305 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 307 "src/analyzer/Root.pv"
        case TYPE__STRUCT: {
            #line 307 "src/analyzer/Root.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 308 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &struct_info->generics, usage_types);
            #line 309 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 310 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 311 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 312 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 314 "src/analyzer/Root.pv"
        case TYPE__TRAIT: {
            #line 314 "src/analyzer/Root.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 315 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &trait_info->generics, usage_types);
            #line 316 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 317 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 318 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 319 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 321 "src/analyzer/Root.pv"
        case TYPE__FUNCTION: {
            #line 321 "src/analyzer/Root.pv"
            struct Function* function_info = type->function_value._0;
            #line 322 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &function_info->generics, usage_types);
            #line 323 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 324 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 325 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 326 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 328 "src/analyzer/Root.pv"
        default: {
            #line 328 "src/analyzer/Root.pv"
            return type;
        } break;
    }
}
