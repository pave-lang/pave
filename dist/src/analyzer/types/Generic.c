#include <stdint.h>

#include <std/trait_Allocator.h>
#include <analyzer/Module.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Trait.h>
#include <std/str.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Generic.h>

#include <analyzer/types/Generic.h>

#line 10 "src/analyzer/types/Generics.pv"
struct Generic Generic__new(struct trait_Allocator allocator) {
    #line 11 "src/analyzer/types/Generics.pv"
    return (struct Generic) { .name = 0, .traits = Array_Type__new(allocator) };
}

#line 14 "src/analyzer/types/Generics.pv"
bool Generic__parse_traits(struct Generic* self, struct Context* context, struct Generics* generics) {
    #line 15 "src/analyzer/types/Generics.pv"
    struct Module* module = context->module;

    #line 17 "src/analyzer/types/Generics.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 18 "src/analyzer/types/Generics.pv"
        bool has_more = true;
        #line 19 "src/analyzer/types/Generics.pv"
        while (has_more) {
            #line 20 "src/analyzer/types/Generics.pv"
            struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 21 "src/analyzer/types/Generics.pv"
            if (name == 0) {
                #line 21 "src/analyzer/types/Generics.pv"
                return false;
            }

            #line 23 "src/analyzer/types/Generics.pv"
            struct Array_Type usage_types = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 24 "src/analyzer/types/Generics.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "<")) {
                #line 25 "src/analyzer/types/Generics.pv"
                while (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ">")) {
                    #line 26 "src/analyzer/types/Generics.pv"
                    struct Type usage_type;
                    #line 27 "src/analyzer/types/Generics.pv"
                    if (!Context__parse_type(context, &usage_type, generics)) {
                        #line 27 "src/analyzer/types/Generics.pv"
                        return false;
                    }
                    #line 28 "src/analyzer/types/Generics.pv"
                    Array_Type__append(&usage_types, usage_type);

                    #line 30 "src/analyzer/types/Generics.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ">")) {
                        #line 31 "src/analyzer/types/Generics.pv"
                        Context__error(context, "Expected , or >");
                        #line 32 "src/analyzer/types/Generics.pv"
                        return false;
                    }
                }
            }

            #line 37 "src/analyzer/types/Generics.pv"
            struct Trait* trait_info = Module__find_trait(module, name->value, usage_types.length);
            #line 38 "src/analyzer/types/Generics.pv"
            if (trait_info == 0) {
                #line 38 "src/analyzer/types/Generics.pv"
                Context__error_token(context, name, "Unable to find trait");
                #line 38 "src/analyzer/types/Generics.pv"
                return false;
            }
            #line 39 "src/analyzer/types/Generics.pv"
            struct GenericMap generic_map = GenericMap__new(context->allocator, &trait_info->generics, &usage_types);
            #line 40 "src/analyzer/types/Generics.pv"
            Array_Type__append(&self->traits, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(context->allocator, &generic_map)} });

            #line 42 "src/analyzer/types/Generics.pv"
            has_more = Context__check_next(context, TOKEN_TYPE__SYMBOL, "+");
        }
    }

    #line 46 "src/analyzer/types/Generics.pv"
    return true;
}
