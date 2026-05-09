#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/types/Global.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Generics.h>
#include <std/trait_Allocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/Token.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/types/Global.h>

#include <analyzer/types/Global.h>

#line 16 "src/analyzer/types/Global.pv"
bool Global__parse_types(struct Global* self) {
    #line 17 "src/analyzer/types/Global.pv"
    struct Context* context = &self->module->context;
    #line 18 "src/analyzer/types/Global.pv"
    struct ArenaAllocator* allocator = context->allocator;
    #line 19 "src/analyzer/types/Global.pv"
    context->pos = self->token_start;

    #line 21 "src/analyzer/types/Global.pv"
    struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 22 "src/analyzer/types/Global.pv"
    struct Type* type = 0;

    #line 24 "src/analyzer/types/Global.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 25 "src/analyzer/types/Global.pv"
        type = Context__parse_type2(context, &generics);
        #line 26 "src/analyzer/types/Global.pv"
        if (type == 0) {
            #line 26 "src/analyzer/types/Global.pv"
            return false;
        }
    }

    #line 29 "src/analyzer/types/Global.pv"
    struct Expression* expression = 0;

    #line 31 "src/analyzer/types/Global.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 32 "src/analyzer/types/Global.pv"
        expression = Expression__parse(context, &generics);
        #line 33 "src/analyzer/types/Global.pv"
        if (expression == 0) {
            #line 33 "src/analyzer/types/Global.pv"
            return false;
        }

        #line 35 "src/analyzer/types/Global.pv"
        if (type == 0) {
            #line 36 "src/analyzer/types/Global.pv"
            type = &expression->return_type;

            #line 38 "src/analyzer/types/Global.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 39 "src/analyzer/types/Global.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 40 "src/analyzer/types/Global.pv"
            Context__inlay_hint(context, self->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 42 "src/analyzer/types/Global.pv"
            Expression__validate_type(expression, context, type, true);
        }
    } else if (self->is_const) {
        #line 45 "src/analyzer/types/Global.pv"
        Context__error_token(context, self->name, "Const declaration requires an initializer");
        #line 46 "src/analyzer/types/Global.pv"
        return false;
    }

    #line 49 "src/analyzer/types/Global.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 49 "src/analyzer/types/Global.pv"
        return false;
    }

    #line 51 "src/analyzer/types/Global.pv"
    if (type == 0) {
        #line 52 "src/analyzer/types/Global.pv"
        Context__error_token(context, self->name, "Global variable requires a type annotation or initializer");
        #line 53 "src/analyzer/types/Global.pv"
        return false;
    }

    #line 56 "src/analyzer/types/Global.pv"
    if (Type__is_unknown(type)) {
        #line 57 "src/analyzer/types/Global.pv"
        Context__error_token(context, self->name, "Global variable is unable to determine its type, manually specify it");
    }

    #line 60 "src/analyzer/types/Global.pv"
    if (Type__is_void(type)) {
        #line 61 "src/analyzer/types/Global.pv"
        Context__error_token(context, self->name, "Global variable cannot have void type");
    }

    #line 64 "src/analyzer/types/Global.pv"
    self->type = *type;
    #line 65 "src/analyzer/types/Global.pv"
    self->value = expression;

    #line 67 "src/analyzer/types/Global.pv"
    return context->pos == self->token_end;
}
