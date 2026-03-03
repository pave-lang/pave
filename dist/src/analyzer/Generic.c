#include <std/Allocator.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/Trait.h>
#include <stdbool.h>
#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <std/str.h>

#include <analyzer/Generic.h>

#line 9 "src/analyzer/Generics.pv"
struct Generic Generic__new(struct Allocator allocator) {
    #line 10 "src/analyzer/Generics.pv"
    return (struct Generic) { .traits = Array_ref_Trait__new(allocator) };
}

#line 13 "src/analyzer/Generics.pv"
bool Generic__parse(struct Generic* self, struct Context* context) {
    #line 14 "src/analyzer/Generics.pv"
    struct Module* module = context->module;

    #line 16 "src/analyzer/Generics.pv"
    self->name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 17 "src/analyzer/Generics.pv"
    if (self->name == 0) {
        #line 17 "src/analyzer/Generics.pv"
        return false;
    }

    #line 19 "src/analyzer/Generics.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 20 "src/analyzer/Generics.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 21 "src/analyzer/Generics.pv"
        if (name == 0) {
            #line 21 "src/analyzer/Generics.pv"
            return false;
        }

        #line 23 "src/analyzer/Generics.pv"
        struct Trait* trait_info = Module__find_trait(module, name->value);
        #line 24 "src/analyzer/Generics.pv"
        if (trait_info == 0) {
            #line 24 "src/analyzer/Generics.pv"
            Context__error_token(context, name, "Unable to find trait");
            #line 24 "src/analyzer/Generics.pv"
            return false;
        }
        #line 25 "src/analyzer/Generics.pv"
        Array_ref_Trait__append(&self->traits, trait_info);

        #line 27 "src/analyzer/Generics.pv"
        while (Context__check_next(context, TOKEN_TYPE__SYMBOL, "+")) {
            #line 28 "src/analyzer/Generics.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 29 "src/analyzer/Generics.pv"
            if (name == 0) {
                #line 29 "src/analyzer/Generics.pv"
                return false;
            }

            #line 31 "src/analyzer/Generics.pv"
            struct Trait* trait_info = Module__find_trait(module, name->value);
            #line 32 "src/analyzer/Generics.pv"
            if (trait_info == 0) {
                #line 32 "src/analyzer/Generics.pv"
                Context__error_token(context, name, "Unable to find trait");
                #line 32 "src/analyzer/Generics.pv"
                return false;
            }
            #line 33 "src/analyzer/Generics.pv"
            Array_ref_Trait__append(&self->traits, trait_info);
        }
    }

    #line 37 "src/analyzer/Generics.pv"
    return true;
}
