#include <stdint.h>
#include <string.h>

#include <fs.h>

#include <fs.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/Namespace.h>
#include <std/trait_Allocator.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <usize.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <std/String.h>
#include <i32.h>
#include <std/Array_char.h>
#include <analyzer/Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
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
        .types = HashMap_str_Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 35 "src/analyzer/Namespace.pv"
    return self;
}

#line 38 "src/analyzer/Namespace.pv"
bool Namespace__add_type(struct Namespace* self, struct str name, struct Type type) {
    #line 39 "src/analyzer/Namespace.pv"
    struct Array_Type* arr = HashMap_str_Array_Type__find(&self->types, &name);
    #line 40 "src/analyzer/Namespace.pv"
    if (arr == 0) {
        #line 41 "src/analyzer/Namespace.pv"
        struct Array_Type new_arr = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
        #line 42 "src/analyzer/Namespace.pv"
        Array_Type__append(&new_arr, type);
        #line 43 "src/analyzer/Namespace.pv"
        HashMap_str_Array_Type__insert(&self->types, name, new_arr);
    } else {
        #line 45 "src/analyzer/Namespace.pv"
        uintptr_t arity = Type__get_arity(&type);
        #line 46 "src/analyzer/Namespace.pv"
        uintptr_t i = 0;
        #line 47 "src/analyzer/Namespace.pv"
        while (i < arr->length) {
            #line 48 "src/analyzer/Namespace.pv"
            if (usize__Eq_usize__eq(Type__get_arity(&arr->data[i]), arity)) {
                #line 48 "src/analyzer/Namespace.pv"
                return false;
            }
            #line 49 "src/analyzer/Namespace.pv"
            i += 1;
        }
        #line 51 "src/analyzer/Namespace.pv"
        Array_Type__append(arr, type);
    }
    #line 53 "src/analyzer/Namespace.pv"
    return true;
}

#line 56 "src/analyzer/Namespace.pv"
bool Namespace__add_trait(struct Namespace* self, struct str name, struct Trait* trait_info) {
    #line 57 "src/analyzer/Namespace.pv"
    struct Array_ref_Trait* arr = HashMap_str_Array_ref_Trait__find(&self->traits, &name);
    #line 58 "src/analyzer/Namespace.pv"
    if (arr == 0) {
        #line 59 "src/analyzer/Namespace.pv"
        struct Array_ref_Trait new_arr = Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
        #line 60 "src/analyzer/Namespace.pv"
        Array_ref_Trait__append(&new_arr, trait_info);
        #line 61 "src/analyzer/Namespace.pv"
        HashMap_str_Array_ref_Trait__insert(&self->traits, name, new_arr);
    } else {
        #line 63 "src/analyzer/Namespace.pv"
        uintptr_t i = 0;
        #line 64 "src/analyzer/Namespace.pv"
        while (i < arr->length) {
            #line 65 "src/analyzer/Namespace.pv"
            if (usize__Eq_usize__eq(arr->data[i]->generic_arity, trait_info->generic_arity)) {
                #line 65 "src/analyzer/Namespace.pv"
                return false;
            }
            #line 66 "src/analyzer/Namespace.pv"
            i += 1;
        }
        #line 68 "src/analyzer/Namespace.pv"
        Array_ref_Trait__append(arr, trait_info);
    }
    #line 70 "src/analyzer/Namespace.pv"
    return true;
}

#line 73 "src/analyzer/Namespace.pv"
bool Namespace__parse(struct Namespace* self) {
    #line 74 "src/analyzer/Namespace.pv"
    return Namespace__add_module(self, (struct str){ .ptr = "ns", .length = strlen("ns") });
}

#line 77 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace(struct Namespace* self, struct str name, struct str path) {
    #line 78 "src/analyzer/Namespace.pv"
    struct Namespace* child = Namespace__new(self->root, self, name, path);
    #line 79 "src/analyzer/Namespace.pv"
    HashMap_str_ref_Namespace__insert(&self->children, name, child);
    #line 80 "src/analyzer/Namespace.pv"
    return Namespace__parse(child);
}

#line 83 "src/analyzer/Namespace.pv"
bool Namespace__add_namespace_subfolder(struct Namespace* self, struct str name) {
    #line 84 "src/analyzer/Namespace.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
    #line 85 "src/analyzer/Namespace.pv"
    String__append(&path, self->path);
    #line 86 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 87 "src/analyzer/Namespace.pv"
    String__append(&path, name);
    #line 88 "src/analyzer/Namespace.pv"
    return Namespace__add_namespace(self, name, String__as_str(&path));
}

#line 91 "src/analyzer/Namespace.pv"
struct Namespace* Namespace__find_namespace(struct Namespace* self, struct str name) {
    #line 92 "src/analyzer/Namespace.pv"
    struct Namespace* current = self;
    #line 93 "src/analyzer/Namespace.pv"
    struct Namespace* slow = self;
    #line 94 "src/analyzer/Namespace.pv"
    struct Namespace* fast = self;
    #line 95 "src/analyzer/Namespace.pv"
    uintptr_t depth = 0;

    #line 97 "src/analyzer/Namespace.pv"
    while (current != 0) {
        #line 98 "src/analyzer/Namespace.pv"
        if (depth >= 1024) {
            #line 99 "src/analyzer/Namespace.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "Namespace lookup exceeded maximum depth");
            #line 100 "src/analyzer/Namespace.pv"
            return 0;
        }

        #line 103 "src/analyzer/Namespace.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&current->children, &name);
        #line 104 "src/analyzer/Namespace.pv"
        if (child != 0) {
            #line 104 "src/analyzer/Namespace.pv"
            return *child;
        }

        #line 106 "src/analyzer/Namespace.pv"
        current = current->parent;
        #line 107 "src/analyzer/Namespace.pv"
        depth += 1;

        #line 109 "src/analyzer/Namespace.pv"
        struct Namespace* slow_next = 0;
        #line 110 "src/analyzer/Namespace.pv"
        if (slow != 0) {
            #line 110 "src/analyzer/Namespace.pv"
            slow_next = slow->parent;
        }
        #line 111 "src/analyzer/Namespace.pv"
        slow = slow_next;

        #line 113 "src/analyzer/Namespace.pv"
        struct Namespace* fast_next = 0;
        #line 114 "src/analyzer/Namespace.pv"
        if (fast != 0) {
            #line 114 "src/analyzer/Namespace.pv"
            fast_next = fast->parent;
        }
        #line 115 "src/analyzer/Namespace.pv"
        if (fast_next != 0) {
            #line 115 "src/analyzer/Namespace.pv"
            fast_next = fast_next->parent;
        }
        #line 116 "src/analyzer/Namespace.pv"
        fast = fast_next;

        #line 118 "src/analyzer/Namespace.pv"
        if (slow != 0 && slow == fast) {
            #line 119 "src/analyzer/Namespace.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "Namespace cycle detected during lookup");
            #line 120 "src/analyzer/Namespace.pv"
            return 0;
        }
    }

    #line 124 "src/analyzer/Namespace.pv"
    return Root__find_namespace(self->root, name);
}

#line 127 "src/analyzer/Namespace.pv"
bool Namespace__add_module(struct Namespace* self, struct str name) {
    #line 128 "src/analyzer/Namespace.pv"
    if (HashMap_str_ref_Module__find(&self->modules, &name) != 0) {
        #line 129 "src/analyzer/Namespace.pv"
        return true;
    }

    #line 132 "src/analyzer/Namespace.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
    #line 133 "src/analyzer/Namespace.pv"
    String__append(&path, self->path);
    #line 134 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
    #line 135 "src/analyzer/Namespace.pv"
    String__append(&path, name);
    #line 136 "src/analyzer/Namespace.pv"
    String__append(&path, (struct str){ .ptr = ".pave", .length = strlen(".pave") });

    #line 138 "src/analyzer/Namespace.pv"
    if (i32__Eq_i32__eq(path_exists(String__c_str(&path)), 0)) {
        #line 139 "src/analyzer/Namespace.pv"
        path.array.length -= 5;
        #line 140 "src/analyzer/Namespace.pv"
        String__append(&path, (struct str){ .ptr = ".pv", .length = strlen(".pv") });
    }

    #line 143 "src/analyzer/Namespace.pv"
    struct Module* module = Module__new(self, String__as_str(&path));
    #line 144 "src/analyzer/Namespace.pv"
    HashMap_str_ref_Module__insert(&self->modules, name, module);
    #line 145 "src/analyzer/Namespace.pv"
    return Module__parse(module);
}

#line 148 "src/analyzer/Namespace.pv"
bool Namespace__add_use_namespaces(struct Namespace* self) {
    #line 149 "src/analyzer/Namespace.pv"
    bool success = true;

    #line 151 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 151 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 151 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 152 "src/analyzer/Namespace.pv"
        success = Module__add_use_namespaces(module) && success;
    } }

    #line 155 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 155 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 155 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 156 "src/analyzer/Namespace.pv"
        success = Namespace__add_use_namespaces(child) && success;
    } }

    #line 159 "src/analyzer/Namespace.pv"
    return success;
}

#line 162 "src/analyzer/Namespace.pv"
bool Namespace__fill_namespace(struct Namespace* self) {
    #line 163 "src/analyzer/Namespace.pv"
    bool success = true;

    #line 165 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 165 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 165 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 166 "src/analyzer/Namespace.pv"
        success = Namespace__fill_namespace(child) && success;
    } }

    #line 169 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 169 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 169 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 170 "src/analyzer/Namespace.pv"
        success = Module__fill_namespace(module) && success;
    } }

    #line 173 "src/analyzer/Namespace.pv"
    return success;
}

#line 176 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types(struct Namespace* self) {
    #line 177 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 177 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 177 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 178 "src/analyzer/Namespace.pv"
        Namespace__prefill_types(child);
    } }

    #line 181 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 181 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 181 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 182 "src/analyzer/Namespace.pv"
        Module__prefill_types(module);
    } }

    #line 185 "src/analyzer/Namespace.pv"
    return true;
}

#line 188 "src/analyzer/Namespace.pv"
bool Namespace__prefill_types_impl(struct Namespace* self) {
    #line 189 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 189 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 189 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 190 "src/analyzer/Namespace.pv"
        Namespace__prefill_types_impl(child);
    } }

    #line 193 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 193 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 193 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 194 "src/analyzer/Namespace.pv"
        Module__prefill_types_impl(module);
    } }

    #line 197 "src/analyzer/Namespace.pv"
    return true;
}

#line 200 "src/analyzer/Namespace.pv"
bool Namespace__parse_declarations(struct Namespace* self) {
    #line 201 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 201 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 201 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 202 "src/analyzer/Namespace.pv"
        Module__parse_declarations(module);
    } }

    #line 205 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 205 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 205 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 206 "src/analyzer/Namespace.pv"
        Namespace__parse_declarations(child);
    } }

    #line 209 "src/analyzer/Namespace.pv"
    return true;
}

#line 212 "src/analyzer/Namespace.pv"
bool Namespace__parse_globals(struct Namespace* self) {
    #line 213 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 213 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 213 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 214 "src/analyzer/Namespace.pv"
        Module__parse_globals(module);
    } }

    #line 217 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 217 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 217 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 218 "src/analyzer/Namespace.pv"
        Namespace__parse_globals(child);
    } }

    #line 221 "src/analyzer/Namespace.pv"
    return true;
}

#line 224 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions(struct Namespace* self) {
    #line 225 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 225 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 225 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 226 "src/analyzer/Namespace.pv"
        Module__parse_functions(module);
    } }

    #line 229 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 229 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 229 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 230 "src/analyzer/Namespace.pv"
        Namespace__parse_functions(child);
    } }

    #line 233 "src/analyzer/Namespace.pv"
    return true;
}

#line 236 "src/analyzer/Namespace.pv"
bool Namespace__parse_functions_if_path(struct Namespace* self, struct str path) {
    #line 237 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 237 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 237 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 238 "src/analyzer/Namespace.pv"
        if (Module__parse_functions_if_path(module, path)) {
            #line 238 "src/analyzer/Namespace.pv"
            return true;
        }
    } }

    #line 241 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 241 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 241 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 242 "src/analyzer/Namespace.pv"
        if (Namespace__parse_functions_if_path(child, path)) {
            #line 242 "src/analyzer/Namespace.pv"
            return true;
        }
    } }

    #line 245 "src/analyzer/Namespace.pv"
    return false;
}

#line 248 "src/analyzer/Namespace.pv"
struct Module* Namespace__find_module_by_path(struct Namespace* self, struct str path) {
    #line 249 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&self->modules);
    #line 249 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Module__next(&__iter)) {
        #line 249 "src/analyzer/Namespace.pv"
        struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

        #line 250 "src/analyzer/Namespace.pv"
        if (str__Eq_str__eq(module->path, path)) {
            #line 250 "src/analyzer/Namespace.pv"
            return module;
        }
    } }
    #line 252 "src/analyzer/Namespace.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(&self->children);
    #line 252 "src/analyzer/Namespace.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 252 "src/analyzer/Namespace.pv"
        struct Namespace* child = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 253 "src/analyzer/Namespace.pv"
        struct Module* result = Namespace__find_module_by_path(child, path);
        #line 254 "src/analyzer/Namespace.pv"
        if (result != 0) {
            #line 254 "src/analyzer/Namespace.pv"
            return result;
        }
    } }
    #line 256 "src/analyzer/Namespace.pv"
    return 0;
}

#line 259 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_type(struct Namespace* self, struct str name, uintptr_t arity) {
    #line 260 "src/analyzer/Namespace.pv"
    struct Array_Type* arr = HashMap_str_Array_Type__find(&self->types, &name);
    #line 261 "src/analyzer/Namespace.pv"
    if (arr == 0) {
        #line 261 "src/analyzer/Namespace.pv"
        return 0;
    }
    #line 262 "src/analyzer/Namespace.pv"
    uintptr_t i = 0;
    #line 263 "src/analyzer/Namespace.pv"
    while (i < arr->length) {
        #line 264 "src/analyzer/Namespace.pv"
        if (usize__Eq_usize__eq(Type__get_arity(&arr->data[i]), arity)) {
            #line 264 "src/analyzer/Namespace.pv"
            return &arr->data[i];
        }
        #line 265 "src/analyzer/Namespace.pv"
        i += 1;
    }
    #line 267 "src/analyzer/Namespace.pv"
    return 0;
}

#line 270 "src/analyzer/Namespace.pv"
struct Trait* Namespace__find_trait(struct Namespace* self, struct str name, uintptr_t arity) {
    #line 271 "src/analyzer/Namespace.pv"
    struct Array_ref_Trait* arr = HashMap_str_Array_ref_Trait__find(&self->traits, &name);
    #line 272 "src/analyzer/Namespace.pv"
    if (arr == 0) {
        #line 272 "src/analyzer/Namespace.pv"
        return 0;
    }
    #line 273 "src/analyzer/Namespace.pv"
    uintptr_t i = 0;
    #line 274 "src/analyzer/Namespace.pv"
    while (i < arr->length) {
        #line 275 "src/analyzer/Namespace.pv"
        struct Trait* trait_info = arr->data[i];
        #line 276 "src/analyzer/Namespace.pv"
        if (usize__Eq_usize__eq(trait_info->generic_arity, arity)) {
            #line 276 "src/analyzer/Namespace.pv"
            return trait_info;
        }
        #line 277 "src/analyzer/Namespace.pv"
        i += 1;
    }
    #line 279 "src/analyzer/Namespace.pv"
    return 0;
}

#line 282 "src/analyzer/Namespace.pv"
struct Type* Namespace__find_function(struct Namespace* self, struct str name) {
    #line 283 "src/analyzer/Namespace.pv"
    return HashMap_str_Type__find(&self->functions, &name);
}
