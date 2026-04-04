#include <std/ArenaAllocator.h>
#include <analyzer/types/Generics.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <stdbool.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generic.h>
#include <analyzer/Token.h>
#include <std/ArrayIter_ref_Type.h>
#include <std/ArrayIter_ref_Generic.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Root.h>
#include <analyzer/Module.h>

#include <analyzer/types/GenericMap.h>

#line 11 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__new(struct ArenaAllocator* allocator, struct Generics* generics, struct Array_Type* usage_types) {
    #line 12 "src/analyzer/types/GenericMap.pv"
    struct GenericMap self = (struct GenericMap) {
        .array = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 17 "src/analyzer/types/GenericMap.pv"
    uintptr_t i = 0;
    #line 18 "src/analyzer/types/GenericMap.pv"
    while (i < generics->array.length && i < usage_types->length) {
        #line 19 "src/analyzer/types/GenericMap.pv"
        struct Generic* generic = generics->array.data + i;
        #line 20 "src/analyzer/types/GenericMap.pv"
        struct Token* generic_name = generic->name;
        #line 21 "src/analyzer/types/GenericMap.pv"
        struct Type generic_type = usage_types->data[i];
        #line 22 "src/analyzer/types/GenericMap.pv"
        GenericMap__insert(&self, generic_name->value, generic_type);
        #line 23 "src/analyzer/types/GenericMap.pv"
        i += 1;
    }

    #line 26 "src/analyzer/types/GenericMap.pv"
    return self;
}

#line 29 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__from_generics(struct ArenaAllocator* allocator, struct Generics* generics) {
    #line 30 "src/analyzer/types/GenericMap.pv"
    struct GenericMap self = (struct GenericMap) {
        .array = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 35 "src/analyzer/types/GenericMap.pv"
    { struct ArrayIter_ref_Generic __iter = Array_Generic__iter(&generics->array);
    #line 35 "src/analyzer/types/GenericMap.pv"
    while (ArrayIter_ref_Generic__next(&__iter)) {
        #line 35 "src/analyzer/types/GenericMap.pv"
        struct Generic* generic = ArrayIter_ref_Generic__value(&__iter);

        #line 36 "src/analyzer/types/GenericMap.pv"
        GenericMap__insert(&self, generic->name->value, (struct Type) { .type = TYPE__GENERIC, .generic_value = generic });
    } }

    #line 39 "src/analyzer/types/GenericMap.pv"
    return self;
}

#line 42 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__clone(struct GenericMap* self, struct ArenaAllocator* allocator) {
    #line 43 "src/analyzer/types/GenericMap.pv"
    return (struct GenericMap) {
        .array = Array_Type__clone(&self->array, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__clone(&self->map, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .self_type = self->self_type,
    };
}

#line 50 "src/analyzer/types/GenericMap.pv"
bool GenericMap__has(struct GenericMap* self, struct str name) {
    #line 51 "src/analyzer/types/GenericMap.pv"
    return HashMap_str_usize__find(&self->map, &name) != 0;
}

#line 54 "src/analyzer/types/GenericMap.pv"
bool GenericMap__insert(struct GenericMap* self, struct str name, struct Type type) {
    #line 55 "src/analyzer/types/GenericMap.pv"
    if (GenericMap__has(self, name)) {
        #line 55 "src/analyzer/types/GenericMap.pv"
        return false;
    }

    #line 57 "src/analyzer/types/GenericMap.pv"
    uintptr_t index = Array_Type__append(&self->array, type);
    #line 58 "src/analyzer/types/GenericMap.pv"
    HashMap_str_usize__insert(&self->map, name, index);

    #line 60 "src/analyzer/types/GenericMap.pv"
    return true;
}

#line 63 "src/analyzer/types/GenericMap.pv"
struct Type* GenericMap__get(struct GenericMap* self, struct str name) {
    #line 64 "src/analyzer/types/GenericMap.pv"
    if (self->map.length == 0) {
        #line 64 "src/analyzer/types/GenericMap.pv"
        return 0;
    }

    #line 66 "src/analyzer/types/GenericMap.pv"
    uintptr_t* index = HashMap_str_usize__find(&self->map, &name);
    #line 67 "src/analyzer/types/GenericMap.pv"
    if (index == 0) {
        #line 67 "src/analyzer/types/GenericMap.pv"
        return 0;
    }

    #line 69 "src/analyzer/types/GenericMap.pv"
    return self->array.data + *index;
}

#line 72 "src/analyzer/types/GenericMap.pv"
bool GenericMap__parse(struct GenericMap* self, struct Context* context, struct Generics* target_generics, struct Generics* generics) {
    #line 73 "src/analyzer/types/GenericMap.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 73 "src/analyzer/types/GenericMap.pv"
        return false;
    }

    #line 75 "src/analyzer/types/GenericMap.pv"
    uintptr_t i = 0;
    #line 76 "src/analyzer/types/GenericMap.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 77 "src/analyzer/types/GenericMap.pv"
        if (i >= target_generics->array.length) {
            #line 77 "src/analyzer/types/GenericMap.pv"
            Context__error(context, "Too many generic arguments");
            #line 77 "src/analyzer/types/GenericMap.pv"
            return false;
        }

        #line 79 "src/analyzer/types/GenericMap.pv"
        struct Generic* generic = target_generics->array.data + i;
        #line 80 "src/analyzer/types/GenericMap.pv"
        struct Type type = context->module->root->type_void;
        #line 81 "src/analyzer/types/GenericMap.pv"
        if (!Context__parse_type(context, &type, generics)) {
            #line 81 "src/analyzer/types/GenericMap.pv"
            return false;
        }

        #line 83 "src/analyzer/types/GenericMap.pv"
        GenericMap__insert(self, generic->name->value, type);

        #line 85 "src/analyzer/types/GenericMap.pv"
        i += 1;

        #line 87 "src/analyzer/types/GenericMap.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 88 "src/analyzer/types/GenericMap.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">");
        }
    }

    #line 92 "src/analyzer/types/GenericMap.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 92 "src/analyzer/types/GenericMap.pv"
        return false;
    }

    #line 94 "src/analyzer/types/GenericMap.pv"
    return true;
}

#line 97 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__resolve_types(struct GenericMap* self, struct ArenaAllocator* allocator, struct GenericMap* generics) {
    #line 98 "src/analyzer/types/GenericMap.pv"
    struct GenericMap result = (struct GenericMap) {
        .array = Array_Type__clone(&self->array, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .map = HashMap_str_usize__clone(&self->map, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .self_type = self->self_type,
    };

    #line 104 "src/analyzer/types/GenericMap.pv"
    if (generics != 0) {
        #line 105 "src/analyzer/types/GenericMap.pv"
        result.self_type = Context__resolve_type(allocator, generics->self_type, generics, 0);
    }

    #line 108 "src/analyzer/types/GenericMap.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(&result.array);
    #line 108 "src/analyzer/types/GenericMap.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 108 "src/analyzer/types/GenericMap.pv"
        struct Type* generic = ArrayIter_ref_Type__value(&__iter);

        #line 109 "src/analyzer/types/GenericMap.pv"
        *generic = *Context__resolve_type(allocator, generic, generics, 0);
    } }

    #line 112 "src/analyzer/types/GenericMap.pv"
    return result;
}
