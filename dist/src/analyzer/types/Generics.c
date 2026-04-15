#include <stdint.h>

#include <analyzer/types/Generics.h>
#include <std/Array_Generic.h>
#include <std/trait_Allocator.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <analyzer/types/Generic.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <analyzer/types/Generics.h>

#include <analyzer/types/Generics.h>

#line 49 "src/analyzer/types/Generics.pv"
struct Generics Generics__new(struct trait_Allocator allocator) {
    #line 50 "src/analyzer/types/Generics.pv"
    return (struct Generics) {
        .array = Array_Generic__new(allocator),
        .map = HashMap_str_usize__new(allocator),
    };
}

#line 56 "src/analyzer/types/Generics.pv"
bool Generics__has(struct Generics* self, struct str name) {
    #line 57 "src/analyzer/types/Generics.pv"
    if (HashMap_str_usize__find(&self->map, &name)) {
        #line 57 "src/analyzer/types/Generics.pv"
        return true;
    }
    #line 58 "src/analyzer/types/Generics.pv"
    if (self->parent != 0 && Generics__has(self->parent, name)) {
        #line 58 "src/analyzer/types/Generics.pv"
        return true;
    }

    #line 60 "src/analyzer/types/Generics.pv"
    return false;
}

#line 63 "src/analyzer/types/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name) {
    #line 64 "src/analyzer/types/Generics.pv"
    uintptr_t* index_ptr = HashMap_str_usize__find(&self->map, &name);
    #line 65 "src/analyzer/types/Generics.pv"
    if (index_ptr != 0) {
        #line 66 "src/analyzer/types/Generics.pv"
        uintptr_t index = *index_ptr;
        #line 67 "src/analyzer/types/Generics.pv"
        return self->array.data + index;
    }

    #line 70 "src/analyzer/types/Generics.pv"
    if (self->parent != 0) {
        #line 70 "src/analyzer/types/Generics.pv"
        return Generics__find(self->parent, name);
    }

    #line 72 "src/analyzer/types/Generics.pv"
    return 0;
}

#line 75 "src/analyzer/types/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context) {
    #line 76 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 76 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 78 "src/analyzer/types/Generics.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 79 "src/analyzer/types/Generics.pv"
        struct Generic generic = Generic__new(self->array.allocator);
        #line 80 "src/analyzer/types/Generics.pv"
        if (!Generic__parse(&generic, context) || Generics__has(self, generic.name->value)) {
            #line 80 "src/analyzer/types/Generics.pv"
            return false;
        }

        #line 82 "src/analyzer/types/Generics.pv"
        uintptr_t index = Array_Generic__append(&self->array, generic);
        #line 83 "src/analyzer/types/Generics.pv"
        HashMap_str_usize__insert(&self->map, generic.name->value, index);

        #line 85 "src/analyzer/types/Generics.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 86 "src/analyzer/types/Generics.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">");
        }
    }

    #line 90 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 90 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 92 "src/analyzer/types/Generics.pv"
    return true;
}
