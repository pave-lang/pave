#include <stdint.h>
#include <string.h>

#include <string.h>
#include <stdio.h>
#include <analyzer/Root.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <analyzer/Analysis.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/c/UnknownC.h>
#include <std/str.h>
#include <std/Array_Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/Token.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/Generic.h>
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
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Trait.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/types/Generics.h>
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
    };

    #line 55 "src/analyzer/Root.pv"
    self->primitive_bool = Root__add_primitive(self, "bool");
    #line 56 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i8");
    #line 57 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i16");
    #line 58 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i32");
    #line 59 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i64");
    #line 60 "src/analyzer/Root.pv"
    Root__add_primitive(self, "isize");
    #line 61 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u8");
    #line 62 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u16");
    #line 63 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u32");
    #line 64 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u64");
    #line 65 "src/analyzer/Root.pv"
    self->primitive_usize = Root__add_primitive(self, "usize");
    #line 66 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f32");
    #line 67 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f64");
    #line 68 "src/analyzer/Root.pv"
    Root__add_primitive(self, "char");
    #line 69 "src/analyzer/Root.pv"
    self->primitive_void = Root__add_primitive(self, "void");
    #line 70 "src/analyzer/Root.pv"
    self->type_void = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_void };
    #line 71 "src/analyzer/Root.pv"
    self->type_bool = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool };
    #line 72 "src/analyzer/Root.pv"
    struct UnknownC* unknown_c = ArenaAllocator__store_UnknownC(allocator, &(struct UnknownC) { .include = 0, .name = (struct str){ .ptr = "unknown", .length = strlen("unknown") }, .generics = (struct Array_Type) {} });
    #line 73 "src/analyzer/Root.pv"
    self->type_unknown = (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = unknown_c };
    #line 74 "src/analyzer/Root.pv"
    self->type_self = (struct Type) { .type = TYPE__SELF };
    #line 75 "src/analyzer/Root.pv"
    self->type_ref_self = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, self->type_self) };
    #line 76 "src/analyzer/Root.pv"
    self->type_usize = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_usize };
    #line 77 "src/analyzer/Root.pv"
    self->func_next = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .name = ArenaAllocator__store_Token(allocator, &(struct Token) { .value = (struct str){ .ptr = "next", .length = strlen("next") } }),
        .parameters = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool },
    };
    #line 83 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_next.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, &(struct Token) { .value = (struct str){ .ptr = "self", .length = strlen("self") } }), .type = self->type_ref_self });

    #line 85 "src/analyzer/Root.pv"
    self->func_value = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .name = ArenaAllocator__store_Token(allocator, &(struct Token) { .value = (struct str){ .ptr = "value", .length = strlen("value") } }),
        .parameters = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = ArenaAllocator__store_Generic(allocator, &(struct Generic) { .name = ArenaAllocator__store_Token(allocator, &(struct Token) { .value = (struct str){ .ptr = "T", .length = strlen("T") } }) }) },
    };
    #line 91 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_value.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, &(struct Token) { .value = (struct str){ .ptr = "self", .length = strlen("self") } }), .type = self->type_ref_self });

    #line 93 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 93 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 93 "src/analyzer/Root.pv"
        struct str key = HashMapIter_str_Primitive__value(&__iter)->_0;
        #line 93 "src/analyzer/Root.pv"
        struct Primitive* value = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 94 "src/analyzer/Root.pv"
        HashMap_str_Type__insert(&self->types, key, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = value });
    } }

    #line 97 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(args);
    #line 97 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 97 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 98 "src/analyzer/Root.pv"
        char const* pos = strchr(arg, '=');

        #line 100 "src/analyzer/Root.pv"
        if (pos == 0) {
            #line 101 "src/analyzer/Root.pv"
            fprintf(stderr, "Unknown arg \"%s\"\n", arg);
        } else {
            #line 103 "src/analyzer/Root.pv"
            struct str arg_str = (struct str){ .ptr = arg, .length = strlen(arg) };
            #line 104 "src/analyzer/Root.pv"
            struct str name = str__slice(arg_str, 0, pos - arg);
            #line 105 "src/analyzer/Root.pv"
            char const* path = pos + 1;

            #line 107 "src/analyzer/Root.pv"
            Root__add_namespace(self, name, (struct str){ .ptr = path, .length = strlen(path) });
        }
    } }

    #line 111 "src/analyzer/Root.pv"
    { struct Iter_ref_ptrc_char __iter = Array_ptrc_char__iter(clang_args);
    #line 111 "src/analyzer/Root.pv"
    while (Iter_ref_ptrc_char__next(&__iter)) {
        #line 111 "src/analyzer/Root.pv"
        char const* arg = *Iter_ref_ptrc_char__value(&__iter);

        #line 112 "src/analyzer/Root.pv"
        Array_ptrc_char__append(&self->clang_args, arg);
    } }

    #line 115 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 115 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 115 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 116 "src/analyzer/Root.pv"
        Namespace__parse(child);
    } }

    #line 119 "src/analyzer/Root.pv"
    return self;
}

#line 122 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name) {
    #line 123 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 126 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name) {
    #line 127 "src/analyzer/Root.pv"
    struct Primitive* existing = HashMap_str_Primitive__find(&self->primitives, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 128 "src/analyzer/Root.pv"
    if (existing != 0) {
        #line 128 "src/analyzer/Root.pv"
        return existing;
    }

    #line 130 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 133 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path) {
    #line 134 "src/analyzer/Root.pv"
    struct Namespace* child = Namespace__new(self, 0, name, path);

    #line 136 "src/analyzer/Root.pv"
    if (HashMap_str_ref_Namespace__find(&self->children, &name) != 0) {
        #line 137 "src/analyzer/Root.pv"
        uint32_t name_length = name.length;
        #line 138 "src/analyzer/Root.pv"
        fprintf(stderr, "Duplicate namespace %.*s\n", name_length, name.ptr);

        #line 140 "src/analyzer/Root.pv"
        return false;
    }

    #line 143 "src/analyzer/Root.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 144 "src/analyzer/Root.pv"
    return true;
}

#line 147 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name) {
    #line 148 "src/analyzer/Root.pv"
    struct Namespace** result = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 149 "src/analyzer/Root.pv"
    if (result == 0) {
        #line 149 "src/analyzer/Root.pv"
        return 0;
    }

    #line 151 "src/analyzer/Root.pv"
    return *result;
}

#line 154 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self) {
    #line 155 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 155 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 155 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 156 "src/analyzer/Root.pv"
        Namespace__add_use_namespaces(child);
    } }

    #line 159 "src/analyzer/Root.pv"
    return true;
}

#line 162 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self) {
    #line 163 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 163 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 163 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 164 "src/analyzer/Root.pv"
        Namespace__fill_namespace(child);
    } }

    #line 167 "src/analyzer/Root.pv"
    return true;
}

#line 170 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self) {
    #line 171 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 171 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 171 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 172 "src/analyzer/Root.pv"
        Namespace__prefill_types(child);
    } }

    #line 175 "src/analyzer/Root.pv"
    return true;
}

#line 178 "src/analyzer/Root.pv"
bool Root__prefill_types_impl(struct Root* self) {
    #line 179 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 179 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 179 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 180 "src/analyzer/Root.pv"
        Namespace__prefill_types_impl(child);
    } }

    #line 183 "src/analyzer/Root.pv"
    return true;
}

#line 186 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self) {
    #line 187 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 187 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 187 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 188 "src/analyzer/Root.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&primitive_info->impls));
        #line 188 "src/analyzer/Root.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 188 "src/analyzer/Root.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 188 "src/analyzer/Root.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 189 "src/analyzer/Root.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__PRIMITIVE, .primitive_value = { ._0 = primitive_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 190 "src/analyzer/Root.pv"
            Impl__fill_types(impl_info, parent);

            #line 192 "src/analyzer/Root.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 192 "src/analyzer/Root.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 192 "src/analyzer/Root.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 193 "src/analyzer/Root.pv"
                Function__fill_types(func_info, &impl_info->generics);
            } }
        } }
    } }

    #line 198 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 198 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 198 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 199 "src/analyzer/Root.pv"
        Namespace__parse_declarations(child);
    } }

    #line 202 "src/analyzer/Root.pv"
    return true;
}

#line 205 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self) {
    #line 206 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 206 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 206 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 207 "src/analyzer/Root.pv"
        Namespace__parse_functions(child);
    } }

    #line 210 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 210 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 210 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 211 "src/analyzer/Root.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 211 "src/analyzer/Root.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 211 "src/analyzer/Root.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 212 "src/analyzer/Root.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 216 "src/analyzer/Root.pv"
    return true;
}

#line 219 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name) {
    #line 220 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->types, &name);
}

#line 223 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name) {
    #line 224 "src/analyzer/Root.pv"
    struct Trait** trait_info = HashMap_str_ref_Trait__find(&self->traits, &name);
    #line 225 "src/analyzer/Root.pv"
    if (trait_info == 0) {
        #line 225 "src/analyzer/Root.pv"
        return 0;
    }
    #line 226 "src/analyzer/Root.pv"
    return *trait_info;
}

#line 229 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name) {
    #line 230 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}

#line 233 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, struct str name) {
    #line 234 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__find(&self->primitives, &name);
}

#line 237 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message) {
    #line 238 "src/analyzer/Root.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 239 "src/analyzer/Root.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &path);
    #line 240 "src/analyzer/Root.pv"
    if (file_diagnostics == 0) {
        #line 240 "src/analyzer/Root.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, path, Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 242 "src/analyzer/Root.pv"
    Array_Diagnostic__append(file_diagnostics, (struct Diagnostic) {
        .message = (struct str){ .ptr = message, .length = strlen(message) },
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

#line 257 "src/analyzer/Root.pv"
struct Type* Root__make_type_usage(struct Root* self, struct Type* type, struct Array_Type* usage_types) {
    #line 258 "src/analyzer/Root.pv"
    if (type == 0) {
        #line 258 "src/analyzer/Root.pv"
        return 0;
    }
    #line 259 "src/analyzer/Root.pv"
    struct ArenaAllocator* allocator = self->allocator;

    #line 261 "src/analyzer/Root.pv"
    switch (type->type) {
        #line 262 "src/analyzer/Root.pv"
        case TYPE__ENUM: {
            #line 262 "src/analyzer/Root.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 263 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &enum_info->generics, usage_types);
            #line 264 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 265 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 266 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 267 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 269 "src/analyzer/Root.pv"
        case TYPE__STRUCT: {
            #line 269 "src/analyzer/Root.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 270 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &struct_info->generics, usage_types);
            #line 271 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 272 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 273 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 274 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 276 "src/analyzer/Root.pv"
        case TYPE__TRAIT: {
            #line 276 "src/analyzer/Root.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 277 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &trait_info->generics, usage_types);
            #line 278 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 279 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 280 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 281 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 283 "src/analyzer/Root.pv"
        case TYPE__FUNCTION: {
            #line 283 "src/analyzer/Root.pv"
            struct Function* function_info = type->function_value._0;
            #line 284 "src/analyzer/Root.pv"
            struct GenericMap generics = GenericMap__new(allocator, &function_info->generics, usage_types);
            #line 285 "src/analyzer/Root.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 286 "src/analyzer/Root.pv"
            generics.self_type = self_type;
            #line 287 "src/analyzer/Root.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = ArenaAllocator__store_GenericMap(allocator, &generics)} };
            #line 288 "src/analyzer/Root.pv"
            return self_type;
        } break;
        #line 290 "src/analyzer/Root.pv"
        default: {
            #line 290 "src/analyzer/Root.pv"
            return type;
        } break;
    }
}
