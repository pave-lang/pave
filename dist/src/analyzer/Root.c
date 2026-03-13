#include <stdio.h>
#include <string.h>

#include <std/ArenaAllocator.h>
#include <std/Array_ptrc_char.h>
#include <analyzer/Analysis.h>
#include <stdint.h>
#include <analyzer/Position.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/str.h>
#include <analyzer/Namespace.h>
#include <std/Allocator.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/Primitive.h>
#include <std/HashMap_str_TypedefC.h>
#include <analyzer/TypedefC.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Trait.h>
#include <analyzer/Naming.h>
#include <std/HashMap_str_ref_Include.h>
#include <analyzer/Include.h>
#include <analyzer/Indirect.h>
#include <analyzer/Function.h>
#include <analyzer/FunctionType.h>
#include <analyzer/Token.h>
#include <std/Array_Parameter.h>
#include <analyzer/Parameter.h>
#include <analyzer/Generic.h>
#include <tuple_str_Primitive.h>
#include <std/HashMapIter_str_Primitive.h>
#include <std/ArrayIter_ref_ptrc_char.h>
#include <stdbool.h>
#include <tuple_str_ref_Namespace.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <analyzer/Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/ArrayIter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/FunctionParent.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/Generics.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <analyzer/Range.h>

#include <analyzer/Root.h>

#line 33 "src/analyzer/Root.pv"
struct Root* Root__new(struct ArenaAllocator* allocator, struct Array_ptrc_char* args, struct Array_ptrc_char* clang_args, struct Analysis* analysis) {
    #line 34 "src/analyzer/Root.pv"
    struct Root* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Root));

    #line 36 "src/analyzer/Root.pv"
    *self = (struct Root) {
        .allocator = allocator,
        .children = HashMap_str_ref_Namespace__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .primitives = HashMap_str_Primitive__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .ctypes = HashMap_str_TypedefC__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .clang_args = Array_ptrc_char__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .analysis = analysis,
        .naming_decl = Naming__new_decl(allocator),
        .includes_c = HashMap_str_ref_Include__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .includes_cpp = HashMap_str_ref_Include__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 51 "src/analyzer/Root.pv"
    self->primitive_bool = Root__add_primitive(self, "bool");
    #line 52 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i8");
    #line 53 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i16");
    #line 54 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i32");
    #line 55 "src/analyzer/Root.pv"
    Root__add_primitive(self, "i64");
    #line 56 "src/analyzer/Root.pv"
    Root__add_primitive(self, "isize");
    #line 57 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u8");
    #line 58 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u16");
    #line 59 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u32");
    #line 60 "src/analyzer/Root.pv"
    Root__add_primitive(self, "u64");
    #line 61 "src/analyzer/Root.pv"
    self->primitive_usize = Root__add_primitive(self, "usize");
    #line 62 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f32");
    #line 63 "src/analyzer/Root.pv"
    Root__add_primitive(self, "f64");
    #line 64 "src/analyzer/Root.pv"
    Root__add_primitive(self, "char");
    #line 65 "src/analyzer/Root.pv"
    self->primitive_void = Root__add_primitive(self, "void");
    #line 66 "src/analyzer/Root.pv"
    self->type_void = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_void };
    #line 67 "src/analyzer/Root.pv"
    self->type_self = (struct Type) { .type = TYPE__SELF };
    #line 68 "src/analyzer/Root.pv"
    self->type_ref_self = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, self->type_self) };
    #line 69 "src/analyzer/Root.pv"
    self->type_usize = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_usize };
    #line 70 "src/analyzer/Root.pv"
    self->func_next = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = "next", .length = strlen("next") } }),
        .parameters = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = self->primitive_bool },
    };
    #line 76 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_next.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = "self", .length = strlen("self") } }), .type = self->type_ref_self });

    #line 78 "src/analyzer/Root.pv"
    self->func_value = (struct Function) {
        .type = FUNCTION_TYPE__STANDARD,
        .name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = "value", .length = strlen("value") } }),
        .parameters = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .return_type = (struct Type) { .type = TYPE__GENERIC, .generic_value = ArenaAllocator__store_Generic(allocator, (struct Generic) { .name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = "T", .length = strlen("T") } }) }) },
    };
    #line 84 "src/analyzer/Root.pv"
    Array_Parameter__append(&self->func_value.parameters, (struct Parameter) { .name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = "self", .length = strlen("self") } }), .type = self->type_ref_self });

    #line 86 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 86 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 86 "src/analyzer/Root.pv"
        struct str key = HashMapIter_str_Primitive__value(&__iter)->_0;
        #line 86 "src/analyzer/Root.pv"
        struct Primitive* value = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 87 "src/analyzer/Root.pv"
        HashMap_str_Type__insert(&self->types, key, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = value });
    } }

    #line 90 "src/analyzer/Root.pv"
    { struct ArrayIter_ref_ptrc_char __iter = Array_ptrc_char__iter(args);
    #line 90 "src/analyzer/Root.pv"
    while (ArrayIter_ref_ptrc_char__next(&__iter)) {
        #line 90 "src/analyzer/Root.pv"
        char const* arg = *ArrayIter_ref_ptrc_char__value(&__iter);

        #line 91 "src/analyzer/Root.pv"
        char const* pos = strchr(arg, '=');

        #line 93 "src/analyzer/Root.pv"
        if (pos == 0) {
            #line 94 "src/analyzer/Root.pv"
            fprintf(stderr, "Unknown arg \"%s\"\n", arg);
        } else {
            #line 96 "src/analyzer/Root.pv"
            struct str arg_str = (struct str){ .ptr = arg, .length = strlen(arg) };
            #line 97 "src/analyzer/Root.pv"
            struct str name = str__slice(arg_str, 0, pos - arg);
            #line 98 "src/analyzer/Root.pv"
            char const* path = pos + 1;

            #line 100 "src/analyzer/Root.pv"
            Root__add_namespace(self, name, (struct str){ .ptr = path, .length = strlen(path) });
        }
    } }

    #line 104 "src/analyzer/Root.pv"
    { struct ArrayIter_ref_ptrc_char __iter = Array_ptrc_char__iter(clang_args);
    #line 104 "src/analyzer/Root.pv"
    while (ArrayIter_ref_ptrc_char__next(&__iter)) {
        #line 104 "src/analyzer/Root.pv"
        char const* arg = *ArrayIter_ref_ptrc_char__value(&__iter);

        #line 105 "src/analyzer/Root.pv"
        Array_ptrc_char__append(&self->clang_args, arg);
    } }

    #line 108 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 108 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 108 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 109 "src/analyzer/Root.pv"
        Namespace__parse(child);
    } }

    #line 112 "src/analyzer/Root.pv"
    return self;
}

#line 115 "src/analyzer/Root.pv"
struct Primitive* Root__add_primitive(struct Root* self, char const* name) {
    #line 116 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 119 "src/analyzer/Root.pv"
struct Primitive* Root__add_ctype(struct Root* self, char const* name) {
    #line 120 "src/analyzer/Root.pv"
    struct Primitive* existing = HashMap_str_Primitive__find(&self->primitives, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 121 "src/analyzer/Root.pv"
    if (existing != 0) {
        #line 121 "src/analyzer/Root.pv"
        return existing;
    }

    #line 123 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__insert(&self->primitives, (struct str){ .ptr = name, .length = strlen(name) }, Primitive__new(self->allocator, name));
}

#line 126 "src/analyzer/Root.pv"
bool Root__add_namespace(struct Root* self, struct str name, struct str path) {
    #line 127 "src/analyzer/Root.pv"
    struct Namespace* child = Namespace__new(self, 0, name, path);

    #line 129 "src/analyzer/Root.pv"
    if (HashMap_str_ref_Namespace__find(&self->children, &name) != 0) {
        #line 130 "src/analyzer/Root.pv"
        uint32_t name_length = name.length;
        #line 131 "src/analyzer/Root.pv"
        fprintf(stderr, "Duplicate namespace %.*s\n", name_length, name.ptr);

        #line 133 "src/analyzer/Root.pv"
        return false;
    }

    #line 136 "src/analyzer/Root.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 137 "src/analyzer/Root.pv"
    return true;
}

#line 140 "src/analyzer/Root.pv"
struct Namespace* Root__find_namespace(struct Root* self, struct str name) {
    #line 141 "src/analyzer/Root.pv"
    struct Namespace** result = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 142 "src/analyzer/Root.pv"
    if (result == 0) {
        #line 142 "src/analyzer/Root.pv"
        return 0;
    }

    #line 144 "src/analyzer/Root.pv"
    return *result;
}

#line 147 "src/analyzer/Root.pv"
bool Root__add_use_namespaces(struct Root* self) {
    #line 148 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 148 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 148 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 149 "src/analyzer/Root.pv"
        Namespace__add_use_namespaces(child);
    } }

    #line 152 "src/analyzer/Root.pv"
    return true;
}

#line 155 "src/analyzer/Root.pv"
bool Root__fill_namespace(struct Root* self) {
    #line 156 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 156 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 156 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 157 "src/analyzer/Root.pv"
        Namespace__fill_namespace(child);
    } }

    #line 160 "src/analyzer/Root.pv"
    return true;
}

#line 163 "src/analyzer/Root.pv"
bool Root__prefill_types(struct Root* self) {
    #line 164 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 164 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 164 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 165 "src/analyzer/Root.pv"
        Namespace__prefill_types(child);
    } }

    #line 168 "src/analyzer/Root.pv"
    return true;
}

#line 171 "src/analyzer/Root.pv"
bool Root__parse_declarations(struct Root* self) {
    #line 172 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 172 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 172 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 173 "src/analyzer/Root.pv"
        Namespace__parse_declarations(child);
    } }

    #line 176 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 176 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 176 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 177 "src/analyzer/Root.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&primitive_info->impls));
        #line 177 "src/analyzer/Root.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 177 "src/analyzer/Root.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 177 "src/analyzer/Root.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 178 "src/analyzer/Root.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__PRIMITIVE, .primitive_value = { ._0 = primitive_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 179 "src/analyzer/Root.pv"
            Impl__fill_types(impl_info, parent);

            #line 181 "src/analyzer/Root.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 181 "src/analyzer/Root.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 181 "src/analyzer/Root.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 182 "src/analyzer/Root.pv"
                Function__fill_types(func_info, &impl_info->impl_generics);
            } }
        } }
    } }

    #line 187 "src/analyzer/Root.pv"
    return true;
}

#line 190 "src/analyzer/Root.pv"
bool Root__parse_functions(struct Root* self) {
    #line 191 "src/analyzer/Root.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 191 "src/analyzer/Root.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 191 "src/analyzer/Root.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 192 "src/analyzer/Root.pv"
        Namespace__parse_functions(child);
    } }

    #line 195 "src/analyzer/Root.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self->primitives);
    #line 195 "src/analyzer/Root.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 195 "src/analyzer/Root.pv"
        struct Primitive* primitive_info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 196 "src/analyzer/Root.pv"
        { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
        #line 196 "src/analyzer/Root.pv"
        while (ArrayIter_ref_ref_Impl__next(&__iter)) {
            #line 196 "src/analyzer/Root.pv"
            struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

            #line 197 "src/analyzer/Root.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 201 "src/analyzer/Root.pv"
    return true;
}

#line 204 "src/analyzer/Root.pv"
struct Type* Root__find_type(struct Root* self, struct str name) {
    #line 205 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->types, &name);
}

#line 208 "src/analyzer/Root.pv"
struct Trait* Root__find_trait(struct Root* self, struct str name) {
    #line 209 "src/analyzer/Root.pv"
    struct Trait** trait_info = HashMap_str_ref_Trait__find(&self->traits, &name);
    #line 210 "src/analyzer/Root.pv"
    if (trait_info == 0) {
        #line 210 "src/analyzer/Root.pv"
        return 0;
    }
    #line 211 "src/analyzer/Root.pv"
    return *trait_info;
}

#line 214 "src/analyzer/Root.pv"
struct Type* Root__find_function(struct Root* self, struct str name) {
    #line 215 "src/analyzer/Root.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}

#line 218 "src/analyzer/Root.pv"
struct Primitive* Root__find_primitive(struct Root* self, char const* name) {
    #line 219 "src/analyzer/Root.pv"
    return HashMap_str_Primitive__find(&self->primitives, &(struct str){ .ptr = name, .length = strlen(name) });
}

#line 222 "src/analyzer/Root.pv"
void Root__error(struct Root* self, struct str path, uintptr_t start_line, uintptr_t start_column, uintptr_t end_line, uintptr_t end_column, char const* message) {
    #line 223 "src/analyzer/Root.pv"
    struct HashMap_str_Array_Diagnostic* diagnostics = &self->analysis->diagnostics;
    #line 224 "src/analyzer/Root.pv"
    struct Array_Diagnostic* file_diagnostics = HashMap_str_Array_Diagnostic__find(diagnostics, &path);
    #line 225 "src/analyzer/Root.pv"
    if (file_diagnostics == 0) {
        #line 225 "src/analyzer/Root.pv"
        file_diagnostics = HashMap_str_Array_Diagnostic__insert(diagnostics, path, Array_Diagnostic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }));
    }

    #line 227 "src/analyzer/Root.pv"
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
