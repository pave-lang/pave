#include <stdint.h>

#include <std/trait_Allocator.h>
#include <std/str.h>
#include <analyzer/types/Generic.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <usize.h>
#include <analyzer/types/Generics.h>

#include <analyzer/types/Generics.h>

#line 57 "src/analyzer/types/Generics.pv"
struct Generics Generics__new(struct trait_Allocator allocator) {
    #line 58 "src/analyzer/types/Generics.pv"
    return (struct Generics) {
        .parent = 0,
        .array = Array_Generic__new(allocator),
        .map = HashMap_str_usize__new(allocator),
    };
}

#line 65 "src/analyzer/types/Generics.pv"
bool Generics__has(struct Generics* self, struct str name) {
    #line 66 "src/analyzer/types/Generics.pv"
    if (HashMap_str_usize__find(&self->map, &name) != 0) {
        #line 66 "src/analyzer/types/Generics.pv"
        return true;
    }
    #line 67 "src/analyzer/types/Generics.pv"
    if (self->parent != 0 && Generics__has(self->parent, name)) {
        #line 67 "src/analyzer/types/Generics.pv"
        return true;
    }

    #line 69 "src/analyzer/types/Generics.pv"
    return false;
}

#line 72 "src/analyzer/types/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name) {
    #line 73 "src/analyzer/types/Generics.pv"
    uintptr_t* index_ptr = HashMap_str_usize__find(&self->map, &name);
    #line 74 "src/analyzer/types/Generics.pv"
    if (index_ptr != 0) {
        #line 75 "src/analyzer/types/Generics.pv"
        uintptr_t index = *index_ptr;
        #line 76 "src/analyzer/types/Generics.pv"
        return self->array.data + index;
    }

    #line 79 "src/analyzer/types/Generics.pv"
    if (self->parent != 0) {
        #line 79 "src/analyzer/types/Generics.pv"
        return Generics__find(self->parent, name);
    }

    #line 81 "src/analyzer/types/Generics.pv"
    return 0;
}

#line 84 "src/analyzer/types/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context) {
    #line 85 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 85 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 87 "src/analyzer/types/Generics.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 88 "src/analyzer/types/Generics.pv"
        struct Generic generic = Generic__new(self->array.allocator);
        #line 89 "src/analyzer/types/Generics.pv"
        generic.name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 90 "src/analyzer/types/Generics.pv"
        struct Token* generic_name = generic.name;
        #line 91 "src/analyzer/types/Generics.pv"
        if (generic_name == 0 || Generics__has(self, generic_name->value)) {
            #line 91 "src/analyzer/types/Generics.pv"
            return false;
        }

        #line 93 "src/analyzer/types/Generics.pv"
        uintptr_t index = Array_Generic__append(&self->array, generic);
        #line 94 "src/analyzer/types/Generics.pv"
        HashMap_str_usize__insert(&self->map, generic_name->value, index);
        #line 95 "src/analyzer/types/Generics.pv"
        struct Generic* stored_generic = Array_Generic__get(&self->array, index);
        #line 96 "src/analyzer/types/Generics.pv"
        if (stored_generic == 0 || !Generic__parse_traits(stored_generic, context, self)) {
            #line 96 "src/analyzer/types/Generics.pv"
            return false;
        }

        #line 98 "src/analyzer/types/Generics.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 99 "src/analyzer/types/Generics.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">");
        }
    }

    #line 103 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 103 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 105 "src/analyzer/types/Generics.pv"
    return true;
}

#line 108 "src/analyzer/types/Generics.pv"
bool Generics__is_empty(struct Generics* self) {
    #line 109 "src/analyzer/types/Generics.pv"
    return usize__Eq_usize__eq(self->array.length, 0);
}
