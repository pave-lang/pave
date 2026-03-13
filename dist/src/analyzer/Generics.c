#include <std/Allocator.h>
#include <std/Array_Generic.h>
#include <analyzer/Generic.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <stdbool.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>

#include <analyzer/Generics.h>

#line 48 "src/analyzer/Generics.pv"
struct Generics Generics__new(struct Allocator allocator) {
    #line 49 "src/analyzer/Generics.pv"
    return (struct Generics) {
        .array = Array_Generic__new(allocator),
        .map = HashMap_str_usize__new(allocator),
    };
}

#line 55 "src/analyzer/Generics.pv"
bool Generics__has(struct Generics* self, struct str name) {
    #line 56 "src/analyzer/Generics.pv"
    if (HashMap_str_usize__find(&self->map, &name)) {
        #line 56 "src/analyzer/Generics.pv"
        return true;
    }
    #line 57 "src/analyzer/Generics.pv"
    if (self->parent != 0 && Generics__has(self->parent, name)) {
        #line 57 "src/analyzer/Generics.pv"
        return true;
    }

    #line 59 "src/analyzer/Generics.pv"
    return false;
}

#line 62 "src/analyzer/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name) {
    #line 63 "src/analyzer/Generics.pv"
    uintptr_t* index_ptr = HashMap_str_usize__find(&self->map, &name);
    #line 64 "src/analyzer/Generics.pv"
    if (index_ptr != 0) {
        #line 65 "src/analyzer/Generics.pv"
        uintptr_t index = *index_ptr;
        #line 66 "src/analyzer/Generics.pv"
        return self->array.data + index;
    }

    #line 69 "src/analyzer/Generics.pv"
    if (self->parent != 0) {
        #line 69 "src/analyzer/Generics.pv"
        return Generics__find(self->parent, name);
    }

    #line 71 "src/analyzer/Generics.pv"
    return 0;
}

#line 74 "src/analyzer/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context) {
    #line 75 "src/analyzer/Generics.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "<") == 0) {
        #line 75 "src/analyzer/Generics.pv"
        return false;
    }

    #line 77 "src/analyzer/Generics.pv"
    while (Context__check_next(context, TOKEN_TYPE__SYMBOL, ">") == 0) {
        #line 78 "src/analyzer/Generics.pv"
        struct Generic generic = Generic__new(self->array.allocator);
        #line 79 "src/analyzer/Generics.pv"
        if (!Generic__parse(&generic, context) || Generics__has(self, generic.name->value)) {
            #line 79 "src/analyzer/Generics.pv"
            return false;
        }

        #line 81 "src/analyzer/Generics.pv"
        uintptr_t index = Array_Generic__append(&self->array, generic);
        #line 82 "src/analyzer/Generics.pv"
        HashMap_str_usize__insert(&self->map, generic.name->value, index);

        #line 84 "src/analyzer/Generics.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0) {
            #line 85 "src/analyzer/Generics.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">");
        }
    }

    #line 89 "src/analyzer/Generics.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">") == 0) {
        #line 89 "src/analyzer/Generics.pv"
        return false;
    }

    #line 91 "src/analyzer/Generics.pv"
    return true;
}
