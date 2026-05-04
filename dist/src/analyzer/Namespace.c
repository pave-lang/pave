#include <stdint.h>
#include <string.h>

#include <fs.h>

#include <fs.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/Namespace.h>
#include <std/trait_Allocator.h>
#include <std/String.h>
#include <std/Array_char.h>
#include <analyzer/Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Trait.h>
#include <analyzer/Namespace.h>

#include <analyzer/Namespace.h>

#line 19 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__new(struct Root* root, struct Namespace* parent, struct str name, struct str path) {
    #line 20 "src/analyzer/Namespace.pv"
    struct ArenaAllocator* allocator = root->allocator;
    #line 21 "src/analyzer/Namespace.pv"
    struct Namespace* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Namespace));

    #line 23 "src/analyzer/Namespace.pv"
    *self = (struct Namespace) {
        .root = root,
        .parent = parent,
        .name = name,
        .path = path,
        .children = HashMap_str_ref_Namespace__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .modules = HashMap_str_ref_Module__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 35 "src/analyzer/Namespace.pv"
    return self;
}

#line 38 "src/analyzer/Namespace.pv"
bool Namespace__parse(struct Namespace* self) {
    #line 39 "src/analyzer/Namespace.pv"
    return Namespace__add_module(self, (struct str){ .ptr = "ns", .length = strlen("ns") });
}

#line 42 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace(struct Namespace* self, struct str name, struct str path) {
    #line 43 "src/analyzer/Namespace.pv"
    struct Namespace* child = Namespace__new(self->root, self, name, path);
    #line 44 "src/analyzer/Namespace.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 45 "src/analyzer/Namespace.pv"
    return Namespace__parse(child);
}

#line 48 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace_subfolder(struct Namespace* self, struct str name) {
    #line 49 "src/analyzer/Namespace.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
    #line 50 "src/analyzer/Namespace.pv"
    String__append(&path, self->path);
    #line 51 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 52 "src/analyzer/Namespace.pv"
    String__append(&path, name);
    #line 53 "src/analyzer/Namespace.pv"
    return Namespace__add_namespace(self, name, String__as_str(&path));
}

#line 56 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__find_namespace(struct Namespace* self, struct str name) {
    #line 57 "src/analyzer/Namespace.pv"
    struct Namespace** child = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 58 "src/analyzer/Namespace.pv"
    if (child != 0) {
        #line 58 "src/analyzer/Namespace.pv"
        return *child;
    }

    #line 60 "src/analyzer/Namespace.pv"
    if (self->parent != 0) {
        #line 61 "src/analyzer/Namespace.pv"
        return Namespace__find_namespace(self->parent, name);
    } else {
        #line 63 "src/analyzer/Namespace.pv"
        return Root__find_namespace(self->root, name);
    }
}

#line 67 "src/analyzer/Namespace.pv"
bool Namespace__add_module(struct Namespace* self, struct str name) {
    #line 68 "src/analyzer/Namespace.pv"
    if (HashMap_str_ref_Module__find(&self->modules, &name) != 0) {
        #line 69 "src/analyzer/Namespace.pv"
        return true;
    }

    #line 72 "src/analyzer/Namespace.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
    #line 73 "src/analyzer/Namespace.pv"
    String__append(&path, self->path);
    #line 74 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 75 "src/analyzer/Namespace.pv"
    String__append(&path, name);
    #line 76 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = ".pave", .length = strlen(".pave") });

    #line 78 "src/analyzer/Namespace.pv"
    if (!path_exists(String__c_str(&path))) {
        #line 79 "src/analyzer/Namespace.pv"
        path.array.length -= 5;
        #line 80 "src/analyzer/Namespace.pv"
        String__append(&path, (struct str){ .ptr = ".pv", .length = strlen(".pv") });
    }

    #line 83 "src/analyzer/Namespace.pv"
    struct Module* module = Module__new(self, String__as_str(&path));
    #line 84 "src/analyzer/Namespace.pv"
    HashMap_str_ref_Module__insert(&self->modules, name, module);
    #line 85 "src/analyzer/Namespace.pv"
    return Module__parse(module);
}

#line 88 "src/analyzer/Namespace.pv"
bool Namespace__add_use_namespaces(struct Namespace* self) {
    #line 89 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 89 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 89 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 90 "src/analyzer/Namespace.pv"
        Module__add_use_namespaces(module);
    } }

    #line 93 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 93 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 93 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 94 "src/analyzer/Namespace.pv"
        Namespace__add_use_namespaces(child);
    } }

    #line 97 "src/analyzer/Namespace.pv"
    return true;
}

#line 100 "src/analyzer/Namespace.pv"
bool Namespace__fill_namespace(struct Namespace* self) {
    #line 101 "src/analyzer/Namespace.pv"
    bool success = true;

    #line 103 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 103 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 103 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 104 "src/analyzer/Namespace.pv"
        success = Namespace__fill_namespace(child) && success;
    } }

    #line 107 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 107 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 107 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 108 "src/analyzer/Namespace.pv"
        success = Module__fill_namespace(module) && success;
    } }

    #line 111 "src/analyzer/Namespace.pv"
    return success;
}

#line 114 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types(struct Namespace* self) {
    #line 115 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 115 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 115 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 116 "src/analyzer/Namespace.pv"
        Namespace__prefill_types(child);
    } }

    #line 119 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 119 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 119 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 120 "src/analyzer/Namespace.pv"
        Module__prefill_types(module);
    } }

    #line 123 "src/analyzer/Namespace.pv"
    return true;
}

#line 126 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types_impl(struct Namespace* self) {
    #line 127 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 127 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 127 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 128 "src/analyzer/Namespace.pv"
        Namespace__prefill_types_impl(child);
    } }

    #line 131 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 131 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 131 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 132 "src/analyzer/Namespace.pv"
        Module__prefill_types_impl(module);
    } }

    #line 135 "src/analyzer/Namespace.pv"
    return true;
}

#line 138 "src/analyzer/Namespace.pv"
bool Namespace__parse_declarations(struct Namespace* self) {
    #line 139 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 139 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 139 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 140 "src/analyzer/Namespace.pv"
        Module__parse_declarations(module);
    } }

    #line 143 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 143 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 143 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 144 "src/analyzer/Namespace.pv"
        Namespace__parse_declarations(child);
    } }

    #line 147 "src/analyzer/Namespace.pv"
    return true;
}

#line 150 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions(struct Namespace* self) {
    #line 151 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 151 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 151 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 152 "src/analyzer/Namespace.pv"
        Module__parse_functions(module);
    } }

    #line 155 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 155 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 155 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 156 "src/analyzer/Namespace.pv"
        Namespace__parse_functions(child);
    } }

    #line 159 "src/analyzer/Namespace.pv"
    return true;
}

#line 162 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_type(struct Namespace* self, struct str name) {
    #line 163 "src/analyzer/Namespace.pv"
    return HashMap_str_Type__find(&self->types, &name);
}

#line 166 "src/analyzer/Namespace.pv"
struct Trait* Namespace__find_trait(struct Namespace* self, struct str name) {
    #line 167 "src/analyzer/Namespace.pv"
    struct Trait** trait_info = HashMap_str_ref_Trait__find(&self->traits, &name);
    #line 168 "src/analyzer/Namespace.pv"
    if (trait_info == 0) {
        #line 168 "src/analyzer/Namespace.pv"
        return 0;
    }
    #line 169 "src/analyzer/Namespace.pv"
    return *trait_info;
}

#line 172 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_function(struct Namespace* self, struct str name) {
    #line 173 "src/analyzer/Namespace.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}
