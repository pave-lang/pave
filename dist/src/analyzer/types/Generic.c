#include <std/Allocator.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <stdbool.h>
#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <std/str.h>

#include <analyzer/types/Generic.h>

#line 10 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct Allocator allocator) {
    #line 11 "src/analyzer/types/Generics.pv"
    return (struct Generic) { .traits = Array_ref_Trait__new(allocator) };
}

#line 14 "src/analyzer/types/Generics.pv"
bool Generic__parse(struct Generic* self, struct Context* context) {
    #line 15 "src/analyzer/types/Generics.pv"
    struct Module* module = context->module;

    #line 17 "src/analyzer/types/Generics.pv"
    self->name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 18 "src/analyzer/types/Generics.pv"
    if (self->name == 0) {
        #line 18 "src/analyzer/types/Generics.pv"
        return false;
    }

    #line 20 "src/analyzer/types/Generics.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 21 "src/analyzer/types/Generics.pv"
        struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 22 "src/analyzer/types/Generics.pv"
        if (name == 0) {
            #line 22 "src/analyzer/types/Generics.pv"
            return false;
        }

        #line 24 "src/analyzer/types/Generics.pv"
        struct Trait* trait_info = Module__find_trait(module, name->value);
        #line 25 "src/analyzer/types/Generics.pv"
        if (trait_info == 0) {
            #line 25 "src/analyzer/types/Generics.pv"
            Context__error_token(context, name, "Unable to find trait");
            #line 25 "src/analyzer/types/Generics.pv"
            return false;
        }
        #line 26 "src/analyzer/types/Generics.pv"
        Array_ref_Trait__append(&self->traits, trait_info);

        #line 28 "src/analyzer/types/Generics.pv"
        while (Context__check_next(context, TOKEN_TYPE__SYMBOL, "+")) {
            #line 29 "src/analyzer/types/Generics.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 30 "src/analyzer/types/Generics.pv"
            if (name == 0) {
                #line 30 "src/analyzer/types/Generics.pv"
                return false;
            }

            #line 32 "src/analyzer/types/Generics.pv"
            struct Trait* trait_info = Module__find_trait(module, name->value);
            #line 33 "src/analyzer/types/Generics.pv"
            if (trait_info == 0) {
                #line 33 "src/analyzer/types/Generics.pv"
                Context__error_token(context, name, "Unable to find trait");
                #line 33 "src/analyzer/types/Generics.pv"
                return false;
            }
            #line 34 "src/analyzer/types/Generics.pv"
            Array_ref_Trait__append(&self->traits, trait_info);
        }
    }

    #line 38 "src/analyzer/types/Generics.pv"
    return true;
}
