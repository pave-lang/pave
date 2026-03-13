#include <std/ArenaAllocator.h>
#include <analyzer/Generics.h>
#include <std/Array_Type.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <stdbool.h>
#include <std/Array_Generic.h>
#include <analyzer/Generic.h>
#include <analyzer/Token.h>
#include <std/ArrayIter_ref_Type.h>
#include <std/ArrayIter_ref_Generic.h>
#include <analyzer/Context.h>

#include <analyzer/GenericMap.h>

#line 10 "src/analyzer/GenericMap.pv"
struct GenericMap GenericMap__new(struct ArenaAllocator* allocator, struct Generics* generics, struct Array_Type* usage_types) {
    #line 11 "src/analyzer/GenericMap.pv"
    struct GenericMap self = (struct GenericMap) {
        .array = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 16 "src/analyzer/GenericMap.pv"
    uintptr_t i = 0;
    #line 17 "src/analyzer/GenericMap.pv"
    while ((i < generics->array.length) && (i < usage_types->length)) {
        #line 18 "src/analyzer/GenericMap.pv"
        struct Generic* generic = generics->array.data + i;
        #line 19 "src/analyzer/GenericMap.pv"
        struct Token* generic_name = generic->name;
        #line 20 "src/analyzer/GenericMap.pv"
        struct Type generic_type = usage_types->data[i];
        #line 21 "src/analyzer/GenericMap.pv"
        GenericMap__insert(&self, generic_name->value, generic_type);
        #line 22 "src/analyzer/GenericMap.pv"
        i += 1;
    }

    #line 25 "src/analyzer/GenericMap.pv"
    return self;
}

#line 28 "src/analyzer/GenericMap.pv"
struct GenericMap GenericMap__from_generics(struct ArenaAllocator* allocator, struct Generics* generics) {
    #line 29 "src/analyzer/GenericMap.pv"
    struct GenericMap self = (struct GenericMap) {
        .array = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 34 "src/analyzer/GenericMap.pv"
    { struct ArrayIter_ref_Generic __iter = Array_Generic__iter(&generics->array);
    #line 34 "src/analyzer/GenericMap.pv"
    while (ArrayIter_ref_Generic__next(&__iter)) {
        #line 34 "src/analyzer/GenericMap.pv"
        struct Generic* generic = ArrayIter_ref_Generic__value(&__iter);

        #line 35 "src/analyzer/GenericMap.pv"
        GenericMap__insert(&self, generic->name->value, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic });
    } }

    #line 38 "src/analyzer/GenericMap.pv"
    return self;
}

#line 41 "src/analyzer/GenericMap.pv"
struct GenericMap GenericMap__clone(struct GenericMap* self, struct ArenaAllocator* allocator) {
    #line 42 "src/analyzer/GenericMap.pv"
    return (struct GenericMap) {
        .array = Array_Type__clone(&self->array, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__clone(&self->map, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .self_type = self->self_type,
    };
}

#line 49 "src/analyzer/GenericMap.pv"
bool GenericMap__has(struct GenericMap* self, struct str name) {
    #line 50 "src/analyzer/GenericMap.pv"
    return HashMap_str_usize__find(&self->map, &name) != 0;
}

#line 53 "src/analyzer/GenericMap.pv"
bool GenericMap__insert(struct GenericMap* self, struct str name, struct Type type) {
    #line 54 "src/analyzer/GenericMap.pv"
    if (GenericMap__has(self, name)) {
        #line 54 "src/analyzer/GenericMap.pv"
        return false;
    }

    #line 56 "src/analyzer/GenericMap.pv"
    uintptr_t index = Array_Type__append(&self->array, type);
    #line 57 "src/analyzer/GenericMap.pv"
    HashMap_str_usize__insert(&self->map, name, index);

    #line 59 "src/analyzer/GenericMap.pv"
    return true;
}

#line 62 "src/analyzer/GenericMap.pv"
struct Type* GenericMap__get(struct GenericMap* self, struct str name) {
    #line 63 "src/analyzer/GenericMap.pv"
    if (self->map.length == 0) {
        #line 63 "src/analyzer/GenericMap.pv"
        return 0;
    }

    #line 65 "src/analyzer/GenericMap.pv"
    uintptr_t* index = HashMap_str_usize__find(&self->map, &name);
    #line 66 "src/analyzer/GenericMap.pv"
    if (index == 0) {
        #line 66 "src/analyzer/GenericMap.pv"
        return 0;
    }

    #line 68 "src/analyzer/GenericMap.pv"
    return self->array.data + *index;
}

#line 71 "src/analyzer/GenericMap.pv"
struct GenericMap GenericMap__resolve_types(struct GenericMap* self, struct ArenaAllocator* allocator, struct GenericMap* generics) {
    #line 72 "src/analyzer/GenericMap.pv"
    struct GenericMap result = (struct GenericMap) {
        .array = Array_Type__clone(&self->array, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__clone(&self->map, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .self_type = self->self_type,
    };

    #line 78 "src/analyzer/GenericMap.pv"
    if (generics != 0) {
        #line 79 "src/analyzer/GenericMap.pv"
        result.self_type = Context__resolve_type(allocator, generics->self_type, generics, 0);
    }

    #line 82 "src/analyzer/GenericMap.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(&result.array);
    #line 82 "src/analyzer/GenericMap.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 82 "src/analyzer/GenericMap.pv"
        struct Type* generic = ArrayIter_ref_Type__value(&__iter);

        #line 83 "src/analyzer/GenericMap.pv"
        *generic = *Context__resolve_type(allocator, generic, generics, 0);
    } }

    #line 86 "src/analyzer/GenericMap.pv"
    return result;
}
