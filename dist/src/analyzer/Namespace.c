#include <fs.h>

#include <analyzer/Root.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <std/str.h>
#include <std/ArenaAllocator.h>
#include <stdint.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/Allocator.h>
#include <std/HashMap_str_ref_Module.h>
#include <analyzer/Module.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Trait.h>
#include <stdbool.h>
#include <std/String.h>
#include <std/Array_char.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Namespace.h>

#include <analyzer/Namespace.h>

#line 18 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__new(struct Root* root, struct Namespace* parent, struct str name, struct str path) {
    #line 19 "src/analyzer/Namespace.pv"
    struct ArenaAllocator* allocator = root->allocator;
    #line 20 "src/analyzer/Namespace.pv"
    struct Namespace* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Namespace));

    #line 22 "src/analyzer/Namespace.pv"
    *self = (struct Namespace) {
        .root = root,
        .parent = parent,
        .name = name,
        .path = path,
        .children = HashMap_str_ref_Namespace__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .modules = HashMap_str_ref_Module__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 34 "src/analyzer/Namespace.pv"
    return self;
}

#line 37 "src/analyzer/Namespace.pv"
bool Namespace__parse(struct Namespace* self) {
    #line 38 "src/analyzer/Namespace.pv"
    return Namespace__add_module(self, (struct str){ .ptr = "ns", .length = strlen("ns") });
}

#line 41 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace(struct Namespace* self, struct str name, struct str path) {
    #line 42 "src/analyzer/Namespace.pv"
    struct Namespace* child = Namespace__new(self->root, self, name, path);
    #line 43 "src/analyzer/Namespace.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 44 "src/analyzer/Namespace.pv"
    return Namespace__parse(child);
}

#line 47 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace_subfolder(struct Namespace* self, struct str name) {
    #line 48 "src/analyzer/Namespace.pv"
    struct String path = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
    #line 49 "src/analyzer/Namespace.pv"
    String__append(&path, self->path);
    #line 50 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 51 "src/analyzer/Namespace.pv"
    String__append(&path, name);
    #line 52 "src/analyzer/Namespace.pv"
    return Namespace__add_namespace(self, name, String__as_str(&path));
}

#line 55 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__find_namespace(struct Namespace* self, struct str name) {
    #line 56 "src/analyzer/Namespace.pv"
    struct Namespace** child = HashMap_str_ref_Namespace__find(&self->children, &name);
    #line 57 "src/analyzer/Namespace.pv"
    if (child != 0) {
        #line 57 "src/analyzer/Namespace.pv"
        return *child;
    }

    #line 59 "src/analyzer/Namespace.pv"
    if (self->parent != 0) {
        #line 60 "src/analyzer/Namespace.pv"
        return Namespace__find_namespace(self->parent, name);
    } else {
        #line 62 "src/analyzer/Namespace.pv"
        return Root__find_namespace(self->root, name);
    }
}

#line 66 "src/analyzer/Namespace.pv"
bool Namespace__add_module(struct Namespace* self, struct str name) {
    #line 67 "src/analyzer/Namespace.pv"
    if (HashMap_str_ref_Module__find(&self->modules, &name) != 0) {
        #line 68 "src/analyzer/Namespace.pv"
        return true;
    }

    #line 71 "src/analyzer/Namespace.pv"
    struct String path = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
    #line 72 "src/analyzer/Namespace.pv"
    String__append(&path, self->path);
    #line 73 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 74 "src/analyzer/Namespace.pv"
    String__append(&path, name);
    #line 75 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = ".pave", .length = strlen(".pave") });

    #line 77 "src/analyzer/Namespace.pv"
    if (!path_exists(String__c_str(&path))) {
        #line 78 "src/analyzer/Namespace.pv"
        path.array.length -= 5;
        #line 79 "src/analyzer/Namespace.pv"
        String__append(&path, (struct str){ .ptr = ".pv", .length = strlen(".pv") });
    }

    #line 82 "src/analyzer/Namespace.pv"
    struct Module* module = Module__new(self, String__as_str(&path));
    #line 83 "src/analyzer/Namespace.pv"
    HashMap_str_ref_Module__insert(&self->modules, name, module);
    #line 84 "src/analyzer/Namespace.pv"
    return Module__parse(module);
}

#line 87 "src/analyzer/Namespace.pv"
bool Namespace__add_use_namespaces(struct Namespace* self) {
    #line 88 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 88 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 88 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 89 "src/analyzer/Namespace.pv"
        Module__add_use_namespaces(module);
    } }

    #line 92 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 92 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 92 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 93 "src/analyzer/Namespace.pv"
        Namespace__add_use_namespaces(child);
    } }

    #line 96 "src/analyzer/Namespace.pv"
    return 1;
}

#line 99 "src/analyzer/Namespace.pv"
bool Namespace__fill_namespace(struct Namespace* self) {
    #line 100 "src/analyzer/Namespace.pv"
    bool success = true;

    #line 102 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 102 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 102 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 103 "src/analyzer/Namespace.pv"
        success = Namespace__fill_namespace(child) && success;
    } }

    #line 106 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 106 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 106 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 107 "src/analyzer/Namespace.pv"
        success = Module__fill_namespace(module) && success;
    } }

    #line 110 "src/analyzer/Namespace.pv"
    return success;
}

#line 113 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types(struct Namespace* self) {
    #line 114 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 114 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 114 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 115 "src/analyzer/Namespace.pv"
        Namespace__prefill_types(child);
    } }

    #line 118 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 118 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 118 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 119 "src/analyzer/Namespace.pv"
        Module__prefill_types(module);
    } }

    #line 122 "src/analyzer/Namespace.pv"
    return true;
}

#line 125 "src/analyzer/Namespace.pv"
bool Namespace__parse_declarations(struct Namespace* self) {
    #line 126 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 126 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 126 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 127 "src/analyzer/Namespace.pv"
        Module__parse_declarations(module);
    } }

    #line 130 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 130 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 130 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 131 "src/analyzer/Namespace.pv"
        Namespace__parse_declarations(child);
    } }

    #line 134 "src/analyzer/Namespace.pv"
    return 1;
}

#line 137 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions(struct Namespace* self) {
    #line 138 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 138 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 138 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 139 "src/analyzer/Namespace.pv"
        Module__parse_functions(module);
    } }

    #line 142 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 142 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 142 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 143 "src/analyzer/Namespace.pv"
        Namespace__parse_functions(child);
    } }

    #line 146 "src/analyzer/Namespace.pv"
    return 1;
}

#line 149 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_type(struct Namespace* self, struct str name) {
    #line 150 "src/analyzer/Namespace.pv"
    return HashMap_str_Type__find(&self->types, &name);
}

#line 153 "src/analyzer/Namespace.pv"
struct Trait* Namespace__find_trait(struct Namespace* self, struct str name) {
    #line 154 "src/analyzer/Namespace.pv"
    struct Trait** trait_info = HashMap_str_ref_Trait__find(&self->traits, &name);
    #line 155 "src/analyzer/Namespace.pv"
    if (trait_info == 0) {
        #line 155 "src/analyzer/Namespace.pv"
        return 0;
    }
    #line 156 "src/analyzer/Namespace.pv"
    return *trait_info;
}

#line 159 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_function(struct Namespace* self, struct str name) {
    #line 160 "src/analyzer/Namespace.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}
