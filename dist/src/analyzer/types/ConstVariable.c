#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/types/ConstVariable.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Generics.h>
#include <std/trait_Allocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/Token.h>
#include <analyzer/types/ConstVariable.h>

#include <analyzer/types/ConstVariable.h>

#line 15 "src/analyzer/types/ConstVariable.pv"
bool ConstVariable__parse_types(struct ConstVariable* self) {
    #line 16 "src/analyzer/types/ConstVariable.pv"
    struct Context* context = &self->module->context;
    #line 17 "src/analyzer/types/ConstVariable.pv"
    struct ArenaAllocator* allocator = context->allocator;
    #line 18 "src/analyzer/types/ConstVariable.pv"
    context->pos = self->token_start;

    #line 20 "src/analyzer/types/ConstVariable.pv"
    struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 21 "src/analyzer/types/ConstVariable.pv"
    struct Type* type = 0;

    #line 23 "src/analyzer/types/ConstVariable.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 24 "src/analyzer/types/ConstVariable.pv"
        type = Context__parse_type2(context, &generics);
        #line 25 "src/analyzer/types/ConstVariable.pv"
        if (type == 0) {
            #line 25 "src/analyzer/types/ConstVariable.pv"
            return false;
        }
    }

    #line 28 "src/analyzer/types/ConstVariable.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 28 "src/analyzer/types/ConstVariable.pv"
        return false;
    }

    #line 30 "src/analyzer/types/ConstVariable.pv"
    struct Expression* expression = Expression__parse(context, &generics);
    #line 31 "src/analyzer/types/ConstVariable.pv"
    if (expression == 0) {
        #line 31 "src/analyzer/types/ConstVariable.pv"
        return false;
    }

    #line 33 "src/analyzer/types/ConstVariable.pv"
    if (type == 0) {
        #line 34 "src/analyzer/types/ConstVariable.pv"
        type = &expression->return_type;
    } else {
        #line 36 "src/analyzer/types/ConstVariable.pv"
        Expression__validate_type(expression, context, type, true);
    }

    #line 39 "src/analyzer/types/ConstVariable.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 39 "src/analyzer/types/ConstVariable.pv"
        return false;
    }

    #line 41 "src/analyzer/types/ConstVariable.pv"
    if (Type__is_unknown(type)) {
        #line 42 "src/analyzer/types/ConstVariable.pv"
        Context__error_token(context, self->name, "Const variable is unable to determine its type, manually specify it");
    }

    #line 45 "src/analyzer/types/ConstVariable.pv"
    if (Type__is_void(type)) {
        #line 46 "src/analyzer/types/ConstVariable.pv"
        Context__error_token(context, self->name, "Const variable cannot have void type");
    }

    #line 49 "src/analyzer/types/ConstVariable.pv"
    self->type = *type;
    #line 50 "src/analyzer/types/ConstVariable.pv"
    self->value = expression;

    #line 52 "src/analyzer/types/ConstVariable.pv"
    return context->pos == self->token_end;
}
