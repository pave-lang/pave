#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/ImplConst.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Generics.h>
#include <std/trait_Allocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/Token.h>
#include <analyzer/ImplConst.h>

#include <analyzer/ImplConst.h>

#line 15 "src/analyzer/Impl.pv"
bool ImplConst__parse_types(struct ImplConst* self) {
    #line 16 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 17 "src/analyzer/Impl.pv"
    struct ArenaAllocator* allocator = context->allocator;
    #line 18 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 20 "src/analyzer/Impl.pv"
    struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 21 "src/analyzer/Impl.pv"
    struct Type* type = 0;

    #line 23 "src/analyzer/Impl.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 24 "src/analyzer/Impl.pv"
        type = Context__parse_type2(context, &generics);
        #line 25 "src/analyzer/Impl.pv"
        if (type == 0) {
            #line 25 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 28 "src/analyzer/Impl.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 29 "src/analyzer/Impl.pv"
        struct Expression* expression = Expression__parse(context, &generics);
        #line 30 "src/analyzer/Impl.pv"
        if (expression == 0) {
            #line 30 "src/analyzer/Impl.pv"
            return false;
        }

        #line 32 "src/analyzer/Impl.pv"
        if (type == 0) {
            #line 33 "src/analyzer/Impl.pv"
            type = &expression->return_type;
        } else {
            #line 35 "src/analyzer/Impl.pv"
            Expression__validate_type(expression, context, type, true);
        }
        #line 37 "src/analyzer/Impl.pv"
        self->value = expression;
    } else {
        #line 39 "src/analyzer/Impl.pv"
        Context__error_token(context, self->name, "Impl const declaration requires an initializer");
        #line 40 "src/analyzer/Impl.pv"
        return false;
    }

    #line 43 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 43 "src/analyzer/Impl.pv"
        return false;
    }

    #line 45 "src/analyzer/Impl.pv"
    if (type == 0) {
        #line 46 "src/analyzer/Impl.pv"
        Context__error_token(context, self->name, "Impl const requires a type annotation or initializer");
        #line 47 "src/analyzer/Impl.pv"
        return false;
    }

    #line 50 "src/analyzer/Impl.pv"
    self->type = *type;
    #line 51 "src/analyzer/Impl.pv"
    return context->pos == self->token_end;
}
