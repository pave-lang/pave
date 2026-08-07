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

#line 93 "src/analyzer/types/Generics.pv"
struct Generics Generics__new(struct trait_Allocator allocator) {
    #line 94 "src/analyzer/types/Generics.pv"
    return (struct Generics) {
        .parent = 0,
        .array = Array_Generic__new(allocator),
        .map = HashMap_str_usize__new(allocator),
    };
}

#line 101 "src/analyzer/types/Generics.pv"
bool Generics__has(struct Generics* self, struct str name) {
    #line 102 "src/analyzer/types/Generics.pv"
    if (HashMap_str_usize__find(&self->map, &name) != 0) {
        #line 102 "src/analyzer/types/Generics.pv"
        return true;
    }
    #line 103 "src/analyzer/types/Generics.pv"
    if (self->parent != 0 && Generics__has(self->parent, name)) {
        #line 103 "src/analyzer/types/Generics.pv"
        return true;
    }

    #line 105 "src/analyzer/types/Generics.pv"
    return false;
}

#line 108 "src/analyzer/types/Generics.pv"
struct Generic* Generics__find(struct Generics* self, struct str name) {
    #line 109 "src/analyzer/types/Generics.pv"
    uintptr_t* index_ptr = HashMap_str_usize__find(&self->map, &name);
    #line 110 "src/analyzer/types/Generics.pv"
    if (index_ptr != 0) {
        #line 111 "src/analyzer/types/Generics.pv"
        uintptr_t index = *index_ptr;
        #line 112 "src/analyzer/types/Generics.pv"
        return self->array.data + index;
    }

    #line 115 "src/analyzer/types/Generics.pv"
    if (self->parent != 0) {
        #line 115 "src/analyzer/types/Generics.pv"
        return Generics__find(self->parent, name);
    }

    #line 117 "src/analyzer/types/Generics.pv"
    return 0;
}

#line 120 "src/analyzer/types/Generics.pv"
bool Generics__parse(struct Generics* self, struct Context* context) {
    #line 121 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "<")) {
        #line 121 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 123 "src/analyzer/types/Generics.pv"
    while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 124 "src/analyzer/types/Generics.pv"
        struct Generic generic = Generic__new(self->array.allocator);
        #line 125 "src/analyzer/types/Generics.pv"
        bool is_const = Context__check_next(context, TOKEN_TYPE__KEYWORD, "const");
        #line 126 "src/analyzer/types/Generics.pv"
        generic.name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 127 "src/analyzer/types/Generics.pv"
        struct Token* generic_name = generic.name;
        #line 128 "src/analyzer/types/Generics.pv"
        if (generic_name == 0 || Generics__has(self, generic_name->value)) {
            #line 128 "src/analyzer/types/Generics.pv"
            return false;
        }

        #line 130 "src/analyzer/types/Generics.pv"
        uintptr_t index = Array_Generic__append(&self->array, generic);
        #line 131 "src/analyzer/types/Generics.pv"
        HashMap_str_usize__insert(&self->map, generic_name->value, index);
        #line 132 "src/analyzer/types/Generics.pv"
        struct Generic* stored_generic = Array_Generic__get(&self->array, index);
        #line 133 "src/analyzer/types/Generics.pv"
        if (stored_generic == 0) {
            #line 133 "src/analyzer/types/Generics.pv"
            return false;
        }

        #line 135 "src/analyzer/types/Generics.pv"
        if (is_const) {
            #line 136 "src/analyzer/types/Generics.pv"
            if (!Generic__parse_const_type(stored_generic, context, self)) {
                #line 136 "src/analyzer/types/Generics.pv"
                return false;
            }
        } else {
            #line 138 "src/analyzer/types/Generics.pv"
            if (!Generic__parse_traits(stored_generic, context, self)) {
                #line 138 "src/analyzer/types/Generics.pv"
                return false;
            }
        }

        #line 141 "src/analyzer/types/Generics.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",")) {
            #line 142 "src/analyzer/types/Generics.pv"
            return Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">");
        }
    }

    #line 146 "src/analyzer/types/Generics.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ">")) {
        #line 146 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 148 "src/analyzer/types/Generics.pv"
    return true;
}

#line 151 "src/analyzer/types/Generics.pv"
bool Generics__is_empty(struct Generics* self) {
    #line 152 "src/analyzer/types/Generics.pv"
    return usize__Eq_usize__eq(self->array.length, 0);
}
